﻿/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@cryptsoft.com).
 * The implementation was written so as to conform with Netscapes SSL.
 *
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 *
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@cryptsoft.com)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 *
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.] */

#include <openssl/bn.h>

#include <assert.h>
#include <limits.h>
#include <openssl/err.h>

#include "internal.h"


#if !defined(BN_ULLONG)
/* bn_div_words divides a double-width |h|,|l| by |d| and returns the result,
 * which must fit in a |BN_ULONG|. */
static BN_ULONG bn_div_words(BN_ULONG h, BN_ULONG l, BN_ULONG d) {
  BN_ULONG dh, dl, q, ret = 0, th, tl, t;
  int i, count = 2;

  if (d == 0) {
    return BN_MASK2;
  }

  i = BN_num_bits_word(d);
  assert((i == BN_BITS2) || (h <= (BN_ULONG)1 << i));

  i = BN_BITS2 - i;
  if (h >= d) {
    h -= d;
  }

  if (i) {
    d <<= i;
    h = (h << i) | (l >> (BN_BITS2 - i));
    l <<= i;
  }
  dh = (d & BN_MASK2h) >> BN_BITS4;
  dl = (d & BN_MASK2l);
  for (;;) {
    if ((h >> BN_BITS4) == dh) {
      q = BN_MASK2l;
    } else {
      q = h / dh;
    }

    th = q * dh;
    tl = dl * q;
    for (;;) {
      t = h - th;
      if ((t & BN_MASK2h) ||
          ((tl) <= ((t << BN_BITS4) | ((l & BN_MASK2h) >> BN_BITS4)))) {
        break;
      }
      q--;
      th -= dh;
      tl -= dl;
    }
    t = (tl >> BN_BITS4);
    tl = (tl << BN_BITS4) & BN_MASK2h;
    th += t;

    if (l < tl) {
      th++;
    }
    l -= tl;
    if (h < th) {
      h += d;
      q--;
    }
    h -= th;

    if (--count == 0) {
      break;
    }

    ret = q << BN_BITS4;
    h = ((h << BN_BITS4) | (l >> BN_BITS4)) & BN_MASK2;
    l = (l & BN_MASK2l) << BN_BITS4;
  }

  ret |= q;
  return ret;
}
#endif /* !defined(BN_ULLONG) */

static inline void bn_div_rem_words(BN_ULONG *quotient_out, BN_ULONG *rem_out,
                                    BN_ULONG n0, BN_ULONG n1, BN_ULONG d0) {
  /* GCC and Clang generate function calls to |__udivdi3| and |__umoddi3| when
   * the |BN_ULLONG|-based C code is used.
   *
   * GCC bugs:
   *   * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=14224
   *   * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=43721
   *   * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=54183
   *   * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=58897
   *   * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=65668
   *
   * Clang bugs:
   *   * https://llvm.org/bugs/show_bug.cgi?id=6397
   *   * https://llvm.org/bugs/show_bug.cgi?id=12418
   *
   * These issues aren't specific to x86 and x86_64, so it might be worthwhile
   * to add more assembly language implementations. */
#if !defined(OPENSSL_NO_ASM) && defined(OPENSSL_X86) && defined(__GNUC__)
  __asm__ volatile (
    "divl %4"
    : "=a"(*quotient_out), "=d"(*rem_out)
    : "a"(n1), "d"(n0), "rm"(d0)
    : "cc" );
#elif !defined(OPENSSL_NO_ASM) && defined(OPENSSL_X86_64) && defined(__GNUC__)
  __asm__ volatile (
    "divq %4"
    : "=a"(*quotient_out), "=d"(*rem_out)
    : "a"(n1), "d"(n0), "rm"(d0)
    : "cc" );
#else
#if defined(BN_ULLONG)
  BN_ULLONG n = (((BN_ULLONG)n0) << BN_BITS2) | n1;
  *quotient_out = (BN_ULONG)(n / d0);
#else
  *quotient_out = bn_div_words(n0, n1, d0);
#endif
  *rem_out = n1 - (*quotient_out * d0);
#endif
}

/* BN_div computes  dv := num / divisor,  rounding towards
 * zero, and sets up rm  such that  dv*divisor + rm = num  holds.
 * Thus:
 *     dv->neg == num->neg ^ divisor->neg  (unless the result is zero)
 *     rm->neg == num->neg                 (unless the remainder is zero)
 * If 'dv' or 'rm' is NULL, the respective value is not returned.
 *
 * This was specifically designed to contain fewer branches that may leak
 * sensitive information; see "New Branch Prediction Vulnerabilities in OpenSSL
 * and Necessary Software Countermeasures" by Onur Acıçmez, Shay Gueron, and
 * Jean-Pierre Seifert. */
int BN_div(BIGNUM *dv, BIGNUM *rm, const BIGNUM *num, const BIGNUM *divisor,
           BN_CTX *ctx) {
  int norm_shift, i, loop;
  BIGNUM *tmp, wnum, *snum, *sdiv, *res;
  BN_ULONG *resp, *wnump;
  BN_ULONG d0, d1;
  int num_n, div_n;

  /* Invalid zero-padding would have particularly bad consequences
   * so don't just rely on bn_check_top() here */
  if ((num->top > 0 && num->d[num->top - 1] == 0) ||
      (divisor->top > 0 && divisor->d[divisor->top - 1] == 0)) {
    OPENSSL_PUT_ERROR(BN, BN_R_NOT_INITIALIZED);
    return 0;
  }

  if (BN_is_zero(divisor)) {
    OPENSSL_PUT_ERROR(BN, BN_R_DIV_BY_ZERO);
    return 0;
  }

  BN_CTX_start(ctx);
  tmp = BN_CTX_get(ctx);
  snum = BN_CTX_get(ctx);
  sdiv = BN_CTX_get(ctx);
  if (dv == NULL) {
    res = BN_CTX_get(ctx);
  } else {
    res = dv;
  }
  if (sdiv == NULL || res == NULL || tmp == NULL || snum == NULL) {
    goto err;
  }

  /* First we normalise the numbers */
  norm_shift = BN_BITS2 - ((BN_num_bits(divisor)) % BN_BITS2);
  if (!(BN_lshift(sdiv, divisor, norm_shift))) {
    goto err;
  }
  sdiv->neg = 0;
  norm_shift += BN_BITS2;
  if (!(BN_lshift(snum, num, norm_shift))) {
    goto err;
  }
  snum->neg = 0;

  /* Since we don't want to have special-case logic for the case where snum is
   * larger than sdiv, we pad snum with enough zeroes without changing its
   * value. */
  if (snum->top <= sdiv->top + 1) {
    if (bn_wexpand(snum, sdiv->top + 2) == NULL) {
      goto err;
    }
    for (i = snum->top; i < sdiv->top + 2; i++) {
      snum->d[i] = 0;
    }
    snum->top = sdiv->top + 2;
  } else {
    if (bn_wexpand(snum, snum->top + 1) == NULL) {
      goto err;
    }
    snum->d[snum->top] = 0;
    snum->top++;
  }

  div_n = sdiv->top;
  num_n = snum->top;
  loop = num_n - div_n;
  /* Lets setup a 'window' into snum
   * This is the part that corresponds to the current
   * 'area' being divided */
  wnum.neg = 0;
  wnum.d = &(snum->d[loop]);
  wnum.top = div_n;
  /* only needed when BN_ucmp messes up the values between top and max */
  wnum.dmax = snum->dmax - loop; /* so we don't step out of bounds */

  /* Get the top 2 words of sdiv */
  /* div_n=sdiv->top; */
  d0 = sdiv->d[div_n - 1];
  d1 = (div_n == 1) ? 0 : sdiv->d[div_n - 2];

  /* pointer to the 'top' of snum */
  wnump = &(snum->d[num_n - 1]);

  /* Setup to 'res' */
  res->neg = (num->neg ^ divisor->neg);
  if (!bn_wexpand(res, (loop + 1))) {
    goto err;
  }
  res->top = loop - 1;
  resp = &(res->d[loop - 1]);

  /* space for temp */
  if (!bn_wexpand(tmp, (div_n + 1))) {
    goto err;
  }

  /* if res->top == 0 then clear the neg value otherwise decrease
   * the resp pointer */
  if (res->top == 0) {
    res->neg = 0;
  } else {
    resp--;
  }

  for (i = 0; i < loop - 1; i++, wnump--, resp--) {
    BN_ULONG q, l0;
    /* the first part of the loop uses the top two words of snum and sdiv to
     * calculate a BN_ULONG q such that | wnum - sdiv * q | < sdiv */
    BN_ULONG n0, n1, rem = 0;

    n0 = wnump[0];
    n1 = wnump[-1];
    if (n0 == d0) {
      q = BN_MASK2;
    } else {
      /* n0 < d0 */
      bn_div_rem_words(&q, &rem, n0, n1, d0);

#ifdef BN_ULLONG
      BN_ULLONG t2 = (BN_ULLONG)d1 * q;
      for (;;) {
        if (t2 <= ((((BN_ULLONG)rem) << BN_BITS2) | wnump[-2])) {
          break;
        }
        q--;
        rem += d0;
        if (rem < d0) {
          break; /* don't let rem overflow */
        }
        t2 -= d1;
      }
#else /* !BN_ULLONG */
      BN_ULONG t2l, t2h;
      BN_UMULT_LOHI(t2l, t2h, d1, q);
      for (;;) {
        if ((t2h < rem) || ((t2h == rem) && (t2l <= wnump[-2]))) {
          break;
        }
        q--;
        rem += d0;
        if (rem < d0) {
          break; /* don't let rem overflow */
        }
        if (t2l < d1) {
          t2h--;
        }
        t2l -= d1;
      }
#endif /* !BN_ULLONG */
    }

    l0 = bn_mul_words(tmp->d, sdiv->d, div_n, q);
    tmp->d[div_n] = l0;
    wnum.d--;
    /* ingore top values of the bignums just sub the two
     * BN_ULONG arrays with bn_sub_words */
    if (bn_sub_words(wnum.d, wnum.d, tmp->d, div_n + 1)) {
      /* Note: As we have considered only the leading
       * two BN_ULONGs in the calculation of q, sdiv * q
       * might be greater than wnum (but then (q-1) * sdiv
       * is less or equal than wnum)
       */
      q--;
      if (bn_add_words(wnum.d, wnum.d, sdiv->d, div_n)) {
        /* we can't have an overflow here (assuming
         * that q != 0, but if q == 0 then tmp is
         * zero anyway) */
        (*wnump)++;
      }
    }
    /* store part of the result */
    *resp = q;
  }
  bn_correct_top(snum);
  if (rm != NULL) {
    /* Keep a copy of the neg flag in num because if rm==num
     * BN_rshift() will overwrite it.
     */
    int neg = num->neg;
    if (!BN_rshift(rm, snum, norm_shift)) {
      goto err;
    }
    if (!BN_is_zero(rm)) {
      rm->neg = neg;
    }
  }
  bn_correct_top(res);
  BN_CTX_end(ctx);
  return 1;

err:
  BN_CTX_end(ctx);
  return 0;
}

int BN_nnmod(BIGNUM *r, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx) {
  if (!(BN_mod(r, m, d, ctx))) {
    return 0;
  }
  if (!r->neg) {
    return 1;
  }

  /* now -|d| < r < 0, so we have to set r := r + |d|. */
  return (d->neg ? BN_sub : BN_add)(r, r, d);
}

int BN_mod_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx) {
  if (!BN_add(r, a, b)) {
    return 0;
  }
  return BN_nnmod(r, r, m, ctx);
}

int BN_mod_add_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                     const BIGNUM *m) {
  if (!BN_uadd(r, a, b)) {
    return 0;
  }
  if (BN_ucmp(r, m) >= 0) {
    return BN_usub(r, r, m);
  }
  return 1;
}

int BN_mod_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx) {
  if (!BN_sub(r, a, b)) {
    return 0;
  }
  return BN_nnmod(r, r, m, ctx);
}

/* BN_mod_sub variant that may be used if both  a  and  b  are non-negative
 * and less than  m */
int BN_mod_sub_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                     const BIGNUM *m) {
  if (!BN_sub(r, a, b)) {
    return 0;
  }
  if (r->neg) {
    return BN_add(r, r, m);
  }
  return 1;
}

int BN_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx) {
  BIGNUM *t;
  int ret = 0;

  BN_CTX_start(ctx);
  t = BN_CTX_get(ctx);
  if (t == NULL) {
    goto err;
  }

  if (a == b) {
    if (!BN_sqr(t, a, ctx)) {
      goto err;
    }
  } else {
    if (!BN_mul(t, a, b, ctx)) {
      goto err;
    }
  }

  if (!BN_nnmod(r, t, m, ctx)) {
    goto err;
  }

  ret = 1;

err:
  BN_CTX_end(ctx);
  return ret;
}

int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx) {
  if (!BN_sqr(r, a, ctx)) {
    return 0;
  }

  /* r->neg == 0,  thus we don't need BN_nnmod */
  return BN_mod(r, r, m, ctx);
}

int BN_mod_lshift(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m,
                  BN_CTX *ctx) {
  BIGNUM *abs_m = NULL;
  int ret;

  if (!BN_nnmod(r, a, m, ctx)) {
    return 0;
  }

  if (m->neg) {
    abs_m = BN_dup(m);
    if (abs_m == NULL) {
      return 0;
    }
    abs_m->neg = 0;
  }

  ret = BN_mod_lshift_quick(r, r, n, (abs_m ? abs_m : m));

  BN_free(abs_m);
  return ret;
}

int BN_mod_lshift_quick(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m) {
  if (r != a) {
    if (BN_copy(r, a) == NULL) {
      return 0;
    }
  }

  while (n > 0) {
    int max_shift;

    /* 0 < r < m */
    max_shift = BN_num_bits(m) - BN_num_bits(r);
    /* max_shift >= 0 */

    if (max_shift < 0) {
      OPENSSL_PUT_ERROR(BN, BN_R_INPUT_NOT_REDUCED);
      return 0;
    }

    if (max_shift > n) {
      max_shift = n;
    }

    if (max_shift) {
      if (!BN_lshift(r, r, max_shift)) {
        return 0;
      }
      n -= max_shift;
    } else {
      if (!BN_lshift1(r, r)) {
        return 0;
      }
      --n;
    }

    /* BN_num_bits(r) <= BN_num_bits(m) */
    if (BN_cmp(r, m) >= 0) {
      if (!BN_sub(r, r, m)) {
        return 0;
      }
    }
  }

  return 1;
}

int BN_mod_lshift1(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx) {
  if (!BN_lshift1(r, a)) {
    return 0;
  }

  return BN_nnmod(r, r, m, ctx);
}

int BN_mod_lshift1_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *m) {
  if (!BN_lshift1(r, a)) {
    return 0;
  }
  if (BN_cmp(r, m) >= 0) {
    return BN_sub(r, r, m);
  }

  return 1;
}

BN_ULONG BN_div_word(BIGNUM *a, BN_ULONG w) {
  BN_ULONG ret = 0;
  int i, j;

  w &= BN_MASK2;

  if (!w) {
    /* actually this an error (division by zero) */
    return (BN_ULONG) - 1;
  }

  if (a->top == 0) {
    return 0;
  }

  /* normalize input for |bn_div_rem_words|. */
  j = BN_BITS2 - BN_num_bits_word(w);
  w <<= j;
  if (!BN_lshift(a, a, j)) {
    return (BN_ULONG) - 1;
  }

  for (i = a->top - 1; i >= 0; i--) {
    BN_ULONG l = a->d[i];
    BN_ULONG d;
    BN_ULONG unused_rem;
    bn_div_rem_words(&d, &unused_rem, ret, l, w);
    ret = (l - ((d * w) & BN_MASK2)) & BN_MASK2;
    a->d[i] = d;
  }

  if ((a->top > 0) && (a->d[a->top - 1] == 0)) {
    a->top--;
  }

  if (a->top == 0) {
    a->neg = 0;
  }

  ret >>= j;
  return ret;
}

BN_ULONG BN_mod_word(const BIGNUM *a, BN_ULONG w) {
#ifndef BN_ULLONG
  BN_ULONG ret = 0;
#else
  BN_ULLONG ret = 0;
#endif
  int i;

  if (w == 0) {
    return (BN_ULONG) -1;
  }

#ifndef BN_ULLONG
  /* If |w| is too long and we don't have |BN_ULLONG| then we need to fall back
   * to using |BN_div_word|. */
  if (w > ((BN_ULONG)1 << BN_BITS4)) {
    BIGNUM *tmp = BN_dup(a);
    if (tmp == NULL) {
      return (BN_ULONG)-1;
    }
    ret = BN_div_word(tmp, w);
    BN_free(tmp);
    return ret;
  }
#endif

  w &= BN_MASK2;
  for (i = a->top - 1; i >= 0; i--) {
#ifndef BN_ULLONG
    ret = ((ret << BN_BITS4) | ((a->d[i] >> BN_BITS4) & BN_MASK2l)) % w;
    ret = ((ret << BN_BITS4) | (a->d[i] & BN_MASK2l)) % w;
#else
    ret = (BN_ULLONG)(((ret << (BN_ULLONG)BN_BITS2) | a->d[i]) % (BN_ULLONG)w);
#endif
  }
  return (BN_ULONG)ret;
}
