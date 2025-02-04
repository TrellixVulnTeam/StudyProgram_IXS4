﻿/* Copyright (c) 2014, Google Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */

#include <openssl/bytestring.h>

#include <assert.h>
#include <string.h>

#include <openssl/mem.h>

#include "../internal.h"


void CBB_zero(CBB *cbb) {
  OPENSSL_memset(cbb, 0, sizeof(CBB));
}

static int cbb_init(CBB *cbb, uint8_t *buf, size_t cap) {
  /* This assumes that |cbb| has already been zeroed. */
  struct cbb_buffer_st *base;

  base = OPENSSL_malloc(sizeof(struct cbb_buffer_st));
  if (base == NULL) {
    return 0;
  }

  base->buf = buf;
  base->len = 0;
  base->cap = cap;
  base->can_resize = 1;
  base->error = 0;

  cbb->base = base;
  cbb->is_top_level = 1;
  return 1;
}

int CBB_init(CBB *cbb, size_t initial_capacity) {
  CBB_zero(cbb);

  uint8_t *buf = OPENSSL_malloc(initial_capacity);
  if (initial_capacity > 0 && buf == NULL) {
    return 0;
  }

  if (!cbb_init(cbb, buf, initial_capacity)) {
    OPENSSL_free(buf);
    return 0;
  }

  return 1;
}

int CBB_init_fixed(CBB *cbb, uint8_t *buf, size_t len) {
  CBB_zero(cbb);

  if (!cbb_init(cbb, buf, len)) {
    return 0;
  }

  cbb->base->can_resize = 0;
  return 1;
}

void CBB_cleanup(CBB *cbb) {
  if (cbb->base) {
    /* Only top-level |CBB|s are cleaned up. Child |CBB|s are non-owning. They
     * are implicitly discarded when the parent is flushed or cleaned up. */
    assert(cbb->is_top_level);

    if (cbb->base->can_resize) {
      OPENSSL_free(cbb->base->buf);
    }
    OPENSSL_free(cbb->base);
  }
  cbb->base = NULL;
}

static int cbb_buffer_reserve(struct cbb_buffer_st *base, uint8_t **out,
                              size_t len) {
  size_t newlen;

  if (base == NULL) {
    return 0;
  }

  newlen = base->len + len;
  if (newlen < base->len) {
    /* Overflow */
    goto err;
  }

  if (newlen > base->cap) {
    size_t newcap = base->cap * 2;
    uint8_t *newbuf;

    if (!base->can_resize) {
      goto err;
    }

    if (newcap < base->cap || newcap < newlen) {
      newcap = newlen;
    }
    newbuf = OPENSSL_realloc(base->buf, newcap);
    if (newbuf == NULL) {
      goto err;
    }

    base->buf = newbuf;
    base->cap = newcap;
  }

  if (out) {
    *out = base->buf + base->len;
  }

  return 1;

err:
  base->error = 1;
  return 0;
}

static int cbb_buffer_add(struct cbb_buffer_st *base, uint8_t **out,
                          size_t len) {
  if (!cbb_buffer_reserve(base, out, len)) {
    return 0;
  }
  /* This will not overflow or |cbb_buffer_reserve| would have failed. */
  base->len += len;
  return 1;
}

static int cbb_buffer_add_u(struct cbb_buffer_st *base, uint32_t v,
                            size_t len_len) {
  if (len_len == 0) {
    return 1;
  }

  uint8_t *buf;
  if (!cbb_buffer_add(base, &buf, len_len)) {
    return 0;
  }

  for (size_t i = len_len - 1; i < len_len; i--) {
    buf[i] = v;
    v >>= 8;
  }

  if (v != 0) {
    base->error = 1;
    return 0;
  }

  return 1;
}

int CBB_finish(CBB *cbb, uint8_t **out_data, size_t *out_len) {
  if (!cbb->is_top_level) {
    return 0;
  }

  if (!CBB_flush(cbb)) {
    return 0;
  }

  if (cbb->base->can_resize && (out_data == NULL || out_len == NULL)) {
    /* |out_data| and |out_len| can only be NULL if the CBB is fixed. */
    return 0;
  }

  if (out_data != NULL) {
    *out_data = cbb->base->buf;
  }
  if (out_len != NULL) {
    *out_len = cbb->base->len;
  }
  cbb->base->buf = NULL;
  CBB_cleanup(cbb);
  return 1;
}

/* CBB_flush recurses and then writes out any pending length prefix. The
 * current length of the underlying base is taken to be the length of the
 * length-prefixed data. */
int CBB_flush(CBB *cbb) {
  size_t child_start, i, len;

  /* If |cbb->base| has hit an error, the buffer is in an undefined state, so
   * fail all following calls. In particular, |cbb->child| may point to invalid
   * memory. */
  if (cbb->base == NULL || cbb->base->error) {
    return 0;
  }

  if (cbb->child == NULL || cbb->child->pending_len_len == 0) {
    return 1;
  }

  child_start = cbb->child->offset + cbb->child->pending_len_len;

  if (!CBB_flush(cbb->child) ||
      child_start < cbb->child->offset ||
      cbb->base->len < child_start) {
    goto err;
  }

  len = cbb->base->len - child_start;

  if (cbb->child->pending_is_asn1) {
    /* For ASN.1 we assume that we'll only need a single byte for the length.
     * If that turned out to be incorrect, we have to move the contents along
     * in order to make space. */
    uint8_t len_len;
    uint8_t initial_length_byte;

    assert (cbb->child->pending_len_len == 1);

    if (len > 0xfffffffe) {
      /* Too large. */
      goto err;
    } else if (len > 0xffffff) {
      len_len = 5;
      initial_length_byte = 0x80 | 4;
    } else if (len > 0xffff) {
      len_len = 4;
      initial_length_byte = 0x80 | 3;
    } else if (len > 0xff) {
      len_len = 3;
      initial_length_byte = 0x80 | 2;
    } else if (len > 0x7f) {
      len_len = 2;
      initial_length_byte = 0x80 | 1;
    } else {
      len_len = 1;
      initial_length_byte = (uint8_t)len;
      len = 0;
    }

    if (len_len != 1) {
      /* We need to move the contents along in order to make space. */
      size_t extra_bytes = len_len - 1;
      if (!cbb_buffer_add(cbb->base, NULL, extra_bytes)) {
        goto err;
      }
      OPENSSL_memmove(cbb->base->buf + child_start + extra_bytes,
                      cbb->base->buf + child_start, len);
    }
    cbb->base->buf[cbb->child->offset++] = initial_length_byte;
    cbb->child->pending_len_len = len_len - 1;
  }

  for (i = cbb->child->pending_len_len - 1; i < cbb->child->pending_len_len;
       i--) {
    cbb->base->buf[cbb->child->offset + i] = (uint8_t)len;
    len >>= 8;
  }
  if (len != 0) {
    goto err;
  }

  cbb->child->base = NULL;
  cbb->child = NULL;

  return 1;

err:
  cbb->base->error = 1;
  return 0;
}

const uint8_t *CBB_data(const CBB *cbb) {
  assert(cbb->child == NULL);
  return cbb->base->buf + cbb->offset + cbb->pending_len_len;
}

size_t CBB_len(const CBB *cbb) {
  assert(cbb->child == NULL);
  assert(cbb->offset + cbb->pending_len_len <= cbb->base->len);

  return cbb->base->len - cbb->offset - cbb->pending_len_len;
}

static int cbb_add_length_prefixed(CBB *cbb, CBB *out_contents,
                                   uint8_t len_len) {
  uint8_t *prefix_bytes;

  if (!CBB_flush(cbb)) {
    return 0;
  }

  size_t offset = cbb->base->len;
  if (!cbb_buffer_add(cbb->base, &prefix_bytes, len_len)) {
    return 0;
  }

  OPENSSL_memset(prefix_bytes, 0, len_len);
  OPENSSL_memset(out_contents, 0, sizeof(CBB));
  out_contents->base = cbb->base;
  cbb->child = out_contents;
  cbb->child->offset = offset;
  cbb->child->pending_len_len = len_len;
  cbb->child->pending_is_asn1 = 0;

  return 1;
}

int CBB_add_u8_length_prefixed(CBB *cbb, CBB *out_contents) {
  return cbb_add_length_prefixed(cbb, out_contents, 1);
}

int CBB_add_u16_length_prefixed(CBB *cbb, CBB *out_contents) {
  return cbb_add_length_prefixed(cbb, out_contents, 2);
}

int CBB_add_u24_length_prefixed(CBB *cbb, CBB *out_contents) {
  return cbb_add_length_prefixed(cbb, out_contents, 3);
}

int CBB_add_asn1(CBB *cbb, CBB *out_contents, unsigned tag) {
  if (tag > 0xff ||
      (tag & 0x1f) == 0x1f) {
    /* Long form identifier octets are not supported. Further, all current valid
     * tag serializations are 8 bits. */
    cbb->base->error = 1;
    return 0;
  }

  if (!CBB_flush(cbb) ||
      /* |tag|'s representation matches the DER encoding. */
      !CBB_add_u8(cbb, (uint8_t)tag)) {
    return 0;
  }

  size_t offset = cbb->base->len;
  if (!CBB_add_u8(cbb, 0)) {
    return 0;
  }

  OPENSSL_memset(out_contents, 0, sizeof(CBB));
  out_contents->base = cbb->base;
  cbb->child = out_contents;
  cbb->child->offset = offset;
  cbb->child->pending_len_len = 1;
  cbb->child->pending_is_asn1 = 1;

  return 1;
}

int CBB_add_bytes(CBB *cbb, const uint8_t *data, size_t len) {
  uint8_t *dest;

  if (!CBB_flush(cbb) ||
      !cbb_buffer_add(cbb->base, &dest, len)) {
    return 0;
  }
  OPENSSL_memcpy(dest, data, len);
  return 1;
}

int CBB_add_space(CBB *cbb, uint8_t **out_data, size_t len) {
  if (!CBB_flush(cbb) ||
      !cbb_buffer_add(cbb->base, out_data, len)) {
    return 0;
  }
  return 1;
}

int CBB_reserve(CBB *cbb, uint8_t **out_data, size_t len) {
  if (!CBB_flush(cbb) ||
      !cbb_buffer_reserve(cbb->base, out_data, len)) {
    return 0;
  }
  return 1;
}

int CBB_did_write(CBB *cbb, size_t len) {
  size_t newlen = cbb->base->len + len;
  if (cbb->child != NULL ||
      newlen < cbb->base->len ||
      newlen > cbb->base->cap) {
    return 0;
  }
  cbb->base->len = newlen;
  return 1;
}

int CBB_add_u8(CBB *cbb, uint8_t value) {
  if (!CBB_flush(cbb)) {
    return 0;
  }

  return cbb_buffer_add_u(cbb->base, value, 1);
}

int CBB_add_u16(CBB *cbb, uint16_t value) {
  if (!CBB_flush(cbb)) {
    return 0;
  }

  return cbb_buffer_add_u(cbb->base, value, 2);
}

int CBB_add_u24(CBB *cbb, uint32_t value) {
  if (!CBB_flush(cbb)) {
    return 0;
  }

  return cbb_buffer_add_u(cbb->base, value, 3);
}

int CBB_add_u32(CBB *cbb, uint32_t value) {
  if (!CBB_flush(cbb)) {
    return 0;
  }

  return cbb_buffer_add_u(cbb->base, value, 4);
}

void CBB_discard_child(CBB *cbb) {
  if (cbb->child == NULL) {
    return;
  }

  cbb->base->len = cbb->child->offset;

  cbb->child->base = NULL;
  cbb->child = NULL;
}

int CBB_add_asn1_uint64(CBB *cbb, uint64_t value) {
  CBB child;
  int started = 0;

  if (!CBB_add_asn1(cbb, &child, CBS_ASN1_INTEGER)) {
    return 0;
  }

  for (size_t i = 0; i < 8; i++) {
    uint8_t byte = (value >> 8*(7-i)) & 0xff;
    if (!started) {
      if (byte == 0) {
        /* Don't encode leading zeros. */
        continue;
      }
      /* If the high bit is set, add a padding byte to make it
       * unsigned. */
      if ((byte & 0x80) && !CBB_add_u8(&child, 0)) {
        return 0;
      }
      started = 1;
    }
    if (!CBB_add_u8(&child, byte)) {
      return 0;
    }
  }

  /* 0 is encoded as a single 0, not the empty string. */
  if (!started && !CBB_add_u8(&child, 0)) {
    return 0;
  }

  return CBB_flush(cbb);
}
