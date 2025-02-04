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

#include <openssl/rsa.h>

#include <assert.h>

#include <openssl/bn.h>


RSA *RSA_generate_key(int bits, unsigned long e_value, void *callback,
                      void *cb_arg) {
  assert(callback == NULL);
  assert(cb_arg == NULL);

  RSA *rsa = RSA_new();
  BIGNUM *e = BN_new();

  if (rsa == NULL ||
      e == NULL ||
      !BN_set_word(e, e_value) ||
      !RSA_generate_key_ex(rsa, bits, e, NULL)) {
    goto err;
  }

  BN_free(e);
  return rsa;

err:
  BN_free(e);
  RSA_free(rsa);
  return NULL;
}

int RSA_padding_add_PKCS1_PSS(RSA *rsa, uint8_t *EM, const uint8_t *mHash,
                              const EVP_MD *Hash, int sLen) {
  return RSA_padding_add_PKCS1_PSS_mgf1(rsa, EM, mHash, Hash, NULL, sLen);
}

int RSA_verify_PKCS1_PSS(RSA *rsa, const uint8_t *mHash, const EVP_MD *Hash,
                         const uint8_t *EM, int sLen) {
  return RSA_verify_PKCS1_PSS_mgf1(rsa, mHash, Hash, NULL, EM, sLen);
}

int RSA_padding_add_PKCS1_OAEP(uint8_t *to, unsigned to_len,
                               const uint8_t *from, unsigned from_len,
                               const uint8_t *param, unsigned param_len) {
  return RSA_padding_add_PKCS1_OAEP_mgf1(to, to_len, from, from_len, param,
                                         param_len, NULL, NULL);
}
