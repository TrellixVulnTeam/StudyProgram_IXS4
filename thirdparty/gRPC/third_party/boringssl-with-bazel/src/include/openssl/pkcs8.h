﻿/* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL
 * project 1999.
 */
/* ====================================================================
 * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com). */


#ifndef OPENSSL_HEADER_PKCS8_H
#define OPENSSL_HEADER_PKCS8_H

#include <openssl/base.h>
#include <openssl/x509.h>


#if defined(__cplusplus)
extern "C" {
#endif


/* PKCS8_encrypt_pbe serializes and encrypts a PKCS8_PRIV_KEY_INFO with PBES1 or
 * PBES2 as defined in PKCS #5. Only pbeWithSHAAnd128BitRC4,
 * pbeWithSHAAnd3-KeyTripleDES-CBC and pbeWithSHA1And40BitRC2, defined in PKCS
 * #12, and PBES2, are supported.  PBES2 is selected by setting |cipher| and
 * passing -1 for |pbe_nid|.  Otherwise, PBES1 is used and |cipher| is ignored.
 *
 * The |pass_raw_len| bytes pointed to by |pass_raw| are used as the password.
 * Note that any conversions from the password as supplied in a text string
 * (such as those specified in B.1 of PKCS #12) must be performed by the caller.
 *
 * If |salt| is NULL, a random salt of |salt_len| bytes is generated. If
 * |salt_len| is zero, a default salt length is used instead.
 *
 * The resulting structure is stored in an X509_SIG which must be freed by the
 * caller.
 *
 * TODO(davidben): Really? An X509_SIG? OpenSSL probably did that because it has
 * the same structure as EncryptedPrivateKeyInfo. */
OPENSSL_EXPORT X509_SIG *PKCS8_encrypt_pbe(int pbe_nid,
                                           const EVP_CIPHER *cipher,
                                           const uint8_t *pass_raw,
                                           size_t pass_raw_len,
                                           uint8_t *salt, size_t salt_len,
                                           int iterations,
                                           PKCS8_PRIV_KEY_INFO *p8inf);

/* PKCS8_decrypt_pbe decrypts and decodes a PKCS8_PRIV_KEY_INFO with PBES1 or
 * PBES2 as defined in PKCS #5. Only pbeWithSHAAnd128BitRC4,
 * pbeWithSHAAnd3-KeyTripleDES-CBC and pbeWithSHA1And40BitRC2, and PBES2,
 * defined in PKCS #12, are supported.
 *
 * The |pass_raw_len| bytes pointed to by |pass_raw| are used as the password.
 * Note that any conversions from the password as supplied in a text string
 * (such as those specified in B.1 of PKCS #12) must be performed by the caller.
 *
 * The resulting structure must be freed by the caller. */
OPENSSL_EXPORT PKCS8_PRIV_KEY_INFO *PKCS8_decrypt_pbe(X509_SIG *pkcs8,
                                                      const uint8_t *pass_raw,
                                                      size_t pass_raw_len);

/* PKCS12_get_key_and_certs parses a PKCS#12 structure from |in|, authenticates
 * and decrypts it using |password|, sets |*out_key| to the included private
 * key and appends the included certificates to |out_certs|. It returns one on
 * success and zero on error. The caller takes ownership of the outputs. */
OPENSSL_EXPORT int PKCS12_get_key_and_certs(EVP_PKEY **out_key,
                                            STACK_OF(X509) *out_certs,
                                            CBS *in, const char *password);


/* Deprecated functions. */

/* PKCS8_encrypt calls |PKCS8_encrypt_pbe| after (in the PKCS#12 case) treating
 * |pass| as an ASCII string, appending U+0000, and converting to UCS-2. (So the
 * empty password encodes as two NUL bytes.) In the PBES2 case, the password is
 * unchanged.  */
OPENSSL_EXPORT X509_SIG *PKCS8_encrypt(int pbe_nid, const EVP_CIPHER *cipher,
                                       const char *pass, int pass_len,
                                       uint8_t *salt, size_t salt_len,
                                       int iterations,
                                       PKCS8_PRIV_KEY_INFO *p8inf);

/* PKCS8_decrypt calls PKCS8_decrypt_pbe after (in the PKCS#12 case) treating
 * |pass| as an ASCII string, appending U+0000, and converting to UCS-2. (So the
 *  empty password encodes as two NUL bytes.) In the PBES2 case, the password is
 * unchanged. */
OPENSSL_EXPORT PKCS8_PRIV_KEY_INFO *PKCS8_decrypt(X509_SIG *pkcs8,
                                                  const char *pass,
                                                  int pass_len);

/* PKCS12_PBE_add does nothing. It exists for compatibility with OpenSSL. */
OPENSSL_EXPORT void PKCS12_PBE_add(void);

/* d2i_PKCS12 is a dummy function that copies |*ber_bytes| into a
 * |PKCS12| structure. The |out_p12| argument should be NULL(✝). On exit,
 * |*ber_bytes| will be advanced by |ber_len|. It returns a fresh |PKCS12|
 * structure or NULL on error.
 *
 * Note: unlike other d2i functions, |d2i_PKCS12| will always consume |ber_len|
 * bytes.
 *
 * (✝) If |out_p12| is not NULL and the function is successful, |*out_p12| will
 * be freed if not NULL itself and the result will be written to |*out_p12|.
 * New code should not depend on this. */
OPENSSL_EXPORT PKCS12 *d2i_PKCS12(PKCS12 **out_p12, const uint8_t **ber_bytes,
                                  size_t ber_len);

/* d2i_PKCS12_bio acts like |d2i_PKCS12| but reads from a |BIO|. */
OPENSSL_EXPORT PKCS12* d2i_PKCS12_bio(BIO *bio, PKCS12 **out_p12);

/* d2i_PKCS12_fp acts like |d2i_PKCS12| but reads from a |FILE|. */
OPENSSL_EXPORT PKCS12* d2i_PKCS12_fp(FILE *fp, PKCS12 **out_p12);

/* PKCS12_parse calls |PKCS12_get_key_and_certs| on the ASN.1 data stored in
 * |p12|. The |out_pkey| and |out_cert| arguments must not be NULL and, on
 * successful exit, the private key and first certificate will be stored in
 * them. The |out_ca_certs| argument may be NULL but, if not, then any extra
 * certificates will be appended to |*out_ca_certs|. If |*out_ca_certs| is NULL
 * then it will be set to a freshly allocated stack containing the extra certs.
 *
 * It returns one on success and zero on error. */
OPENSSL_EXPORT int PKCS12_parse(const PKCS12 *p12, const char *password,
                                EVP_PKEY **out_pkey, X509 **out_cert,
                                STACK_OF(X509) **out_ca_certs);

/* PKCS12_verify_mac returns one if |password| is a valid password for |p12|
 * and zero otherwise. Since |PKCS12_parse| doesn't take a length parameter,
 * it's not actually possible to use a non-NUL-terminated password to actually
 * get anything from a |PKCS12|. Thus |password| and |password_len| may be
 * |NULL| and zero, respectively, or else |password_len| may be -1, or else
 * |password[password_len]| must be zero and no other NUL bytes may appear in
 * |password|. If the |password_len| checks fail, zero is returned
 * immediately. */
OPENSSL_EXPORT int PKCS12_verify_mac(const PKCS12 *p12, const char *password,
                                     int password_len);

/* PKCS12_free frees |p12| and its contents. */
OPENSSL_EXPORT void PKCS12_free(PKCS12 *p12);


#if defined(__cplusplus)
}  /* extern C */

extern "C++" {

namespace bssl {

BORINGSSL_MAKE_DELETER(PKCS12, PKCS12_free)
BORINGSSL_MAKE_DELETER(PKCS8_PRIV_KEY_INFO, PKCS8_PRIV_KEY_INFO_free)

}  // namespace bssl

}  /* extern C++ */

#endif

#define PKCS8_R_BAD_PKCS12_DATA 100
#define PKCS8_R_BAD_PKCS12_VERSION 101
#define PKCS8_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER 102
#define PKCS8_R_CRYPT_ERROR 103
#define PKCS8_R_DECODE_ERROR 104
#define PKCS8_R_ENCODE_ERROR 105
#define PKCS8_R_ENCRYPT_ERROR 106
#define PKCS8_R_ERROR_SETTING_CIPHER_PARAMS 107
#define PKCS8_R_INCORRECT_PASSWORD 108
#define PKCS8_R_KEYGEN_FAILURE 109
#define PKCS8_R_KEY_GEN_ERROR 110
#define PKCS8_R_METHOD_NOT_SUPPORTED 111
#define PKCS8_R_MISSING_MAC 112
#define PKCS8_R_MULTIPLE_PRIVATE_KEYS_IN_PKCS12 113
#define PKCS8_R_PKCS12_PUBLIC_KEY_INTEGRITY_NOT_SUPPORTED 114
#define PKCS8_R_PKCS12_TOO_DEEPLY_NESTED 115
#define PKCS8_R_PRIVATE_KEY_DECODE_ERROR 116
#define PKCS8_R_PRIVATE_KEY_ENCODE_ERROR 117
#define PKCS8_R_TOO_LONG 118
#define PKCS8_R_UNKNOWN_ALGORITHM 119
#define PKCS8_R_UNKNOWN_CIPHER 120
#define PKCS8_R_UNKNOWN_CIPHER_ALGORITHM 121
#define PKCS8_R_UNKNOWN_DIGEST 122
#define PKCS8_R_UNKNOWN_HASH 123
#define PKCS8_R_UNSUPPORTED_PRIVATE_KEY_ALGORITHM 124
#define PKCS8_R_UNSUPPORTED_KEYLENGTH 125
#define PKCS8_R_UNSUPPORTED_SALT_TYPE 126
#define PKCS8_R_UNSUPPORTED_CIPHER 127
#define PKCS8_R_UNSUPPORTED_KEY_DERIVATION_FUNCTION 128
#define PKCS8_R_BAD_ITERATION_COUNT 129
#define PKCS8_R_UNSUPPORTED_PRF 130

#endif  /* OPENSSL_HEADER_PKCS8_H */
