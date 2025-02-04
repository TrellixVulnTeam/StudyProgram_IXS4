﻿/* Copyright (c) 2015, Google Inc.
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

 /* This file was generated by err_data_generate.go. */

#include <openssl/base.h>
#include <openssl/err.h>
#include <openssl/type_check.h>


OPENSSL_COMPILE_ASSERT(ERR_LIB_NONE == 1, library_values_changed_1);
OPENSSL_COMPILE_ASSERT(ERR_LIB_SYS == 2, library_values_changed_2);
OPENSSL_COMPILE_ASSERT(ERR_LIB_BN == 3, library_values_changed_3);
OPENSSL_COMPILE_ASSERT(ERR_LIB_RSA == 4, library_values_changed_4);
OPENSSL_COMPILE_ASSERT(ERR_LIB_DH == 5, library_values_changed_5);
OPENSSL_COMPILE_ASSERT(ERR_LIB_EVP == 6, library_values_changed_6);
OPENSSL_COMPILE_ASSERT(ERR_LIB_BUF == 7, library_values_changed_7);
OPENSSL_COMPILE_ASSERT(ERR_LIB_OBJ == 8, library_values_changed_8);
OPENSSL_COMPILE_ASSERT(ERR_LIB_PEM == 9, library_values_changed_9);
OPENSSL_COMPILE_ASSERT(ERR_LIB_DSA == 10, library_values_changed_10);
OPENSSL_COMPILE_ASSERT(ERR_LIB_X509 == 11, library_values_changed_11);
OPENSSL_COMPILE_ASSERT(ERR_LIB_ASN1 == 12, library_values_changed_12);
OPENSSL_COMPILE_ASSERT(ERR_LIB_CONF == 13, library_values_changed_13);
OPENSSL_COMPILE_ASSERT(ERR_LIB_CRYPTO == 14, library_values_changed_14);
OPENSSL_COMPILE_ASSERT(ERR_LIB_EC == 15, library_values_changed_15);
OPENSSL_COMPILE_ASSERT(ERR_LIB_SSL == 16, library_values_changed_16);
OPENSSL_COMPILE_ASSERT(ERR_LIB_BIO == 17, library_values_changed_17);
OPENSSL_COMPILE_ASSERT(ERR_LIB_PKCS7 == 18, library_values_changed_18);
OPENSSL_COMPILE_ASSERT(ERR_LIB_PKCS8 == 19, library_values_changed_19);
OPENSSL_COMPILE_ASSERT(ERR_LIB_X509V3 == 20, library_values_changed_20);
OPENSSL_COMPILE_ASSERT(ERR_LIB_RAND == 21, library_values_changed_21);
OPENSSL_COMPILE_ASSERT(ERR_LIB_ENGINE == 22, library_values_changed_22);
OPENSSL_COMPILE_ASSERT(ERR_LIB_OCSP == 23, library_values_changed_23);
OPENSSL_COMPILE_ASSERT(ERR_LIB_UI == 24, library_values_changed_24);
OPENSSL_COMPILE_ASSERT(ERR_LIB_COMP == 25, library_values_changed_25);
OPENSSL_COMPILE_ASSERT(ERR_LIB_ECDSA == 26, library_values_changed_26);
OPENSSL_COMPILE_ASSERT(ERR_LIB_ECDH == 27, library_values_changed_27);
OPENSSL_COMPILE_ASSERT(ERR_LIB_HMAC == 28, library_values_changed_28);
OPENSSL_COMPILE_ASSERT(ERR_LIB_DIGEST == 29, library_values_changed_29);
OPENSSL_COMPILE_ASSERT(ERR_LIB_CIPHER == 30, library_values_changed_30);
OPENSSL_COMPILE_ASSERT(ERR_LIB_HKDF == 31, library_values_changed_31);
OPENSSL_COMPILE_ASSERT(ERR_LIB_USER == 32, library_values_changed_32);
OPENSSL_COMPILE_ASSERT(ERR_NUM_LIBS == 33, library_values_changed_num);

const uint32_t kOpenSSLReasonValues[] = {
    0xc320838,
    0xc328852,
    0xc330861,
    0xc338871,
    0xc340880,
    0xc348899,
    0xc3508a5,
    0xc3588c2,
    0xc3608d4,
    0xc3688e2,
    0xc3708f2,
    0xc3788ff,
    0xc38090f,
    0xc38891a,
    0xc390930,
    0xc39893f,
    0xc3a0953,
    0xc3a8845,
    0xc3b00ea,
    0x10320845,
    0x103293ab,
    0x103313b7,
    0x103393d0,
    0x103413e3,
    0x10348e8b,
    0x10350c19,
    0x103593f6,
    0x1036140b,
    0x1036941e,
    0x1037143d,
    0x10379456,
    0x1038146b,
    0x10389489,
    0x10391498,
    0x103994b4,
    0x103a14cf,
    0x103a94de,
    0x103b14fa,
    0x103b9515,
    0x103c152c,
    0x103c80ea,
    0x103d153d,
    0x103d9551,
    0x103e1570,
    0x103e957f,
    0x103f1596,
    0x103f95a9,
    0x10400bea,
    0x104095bc,
    0x104115da,
    0x104195ed,
    0x10421607,
    0x10429617,
    0x1043162b,
    0x10439641,
    0x10441659,
    0x1044966e,
    0x10451682,
    0x10459694,
    0x104605fb,
    0x1046893f,
    0x104716a9,
    0x104796c0,
    0x104816d5,
    0x104896e3,
    0x14320bcd,
    0x14328bdb,
    0x14330bea,
    0x14338bfc,
    0x143400ac,
    0x143480ea,
    0x18320083,
    0x18328ee1,
    0x183300ac,
    0x18338ef7,
    0x18340f0b,
    0x183480ea,
    0x18350f20,
    0x18358f38,
    0x18360f4d,
    0x18368f61,
    0x18370f85,
    0x18378f9b,
    0x18380faf,
    0x18388fbf,
    0x18390a57,
    0x18398fcf,
    0x183a0fe4,
    0x183a8ff8,
    0x183b0c25,
    0x183b9005,
    0x183c1017,
    0x183c9022,
    0x183d1032,
    0x183d9043,
    0x183e1054,
    0x183e9066,
    0x183f108f,
    0x183f90a8,
    0x184010c0,
    0x184086d3,
    0x203210e7,
    0x243210f3,
    0x24328985,
    0x24331105,
    0x24339112,
    0x2434111f,
    0x24349131,
    0x24351140,
    0x2435915d,
    0x2436116a,
    0x24369178,
    0x24371186,
    0x24379194,
    0x2438119d,
    0x243891aa,
    0x243911bd,
    0x28320c0d,
    0x28328c25,
    0x28330bea,
    0x28338c38,
    0x28340c19,
    0x283480ac,
    0x283500ea,
    0x2c3229b1,
    0x2c32a9bf,
    0x2c3329d1,
    0x2c33a9e3,
    0x2c3429f7,
    0x2c34aa09,
    0x2c352a24,
    0x2c35aa36,
    0x2c362a49,
    0x2c36832d,
    0x2c372a56,
    0x2c37aa68,
    0x2c382a7b,
    0x2c38aa92,
    0x2c392aa0,
    0x2c39aab0,
    0x2c3a2ac2,
    0x2c3aaad6,
    0x2c3b2ae7,
    0x2c3bab06,
    0x2c3c2b1a,
    0x2c3cab30,
    0x2c3d2b49,
    0x2c3dab66,
    0x2c3e2b77,
    0x2c3eab85,
    0x2c3f2b9d,
    0x2c3fabb5,
    0x2c402bc2,
    0x2c4090e7,
    0x2c412bd3,
    0x2c41abe6,
    0x2c4210c0,
    0x2c42abf7,
    0x2c430720,
    0x2c43aaf8,
    0x30320000,
    0x30328015,
    0x3033001f,
    0x30338038,
    0x3034004a,
    0x30348064,
    0x3035006b,
    0x30358083,
    0x30360094,
    0x303680ac,
    0x303700b9,
    0x303780c8,
    0x303800ea,
    0x303880f7,
    0x3039010a,
    0x30398125,
    0x303a013a,
    0x303a814e,
    0x303b0162,
    0x303b8173,
    0x303c018c,
    0x303c81a9,
    0x303d01b7,
    0x303d81cb,
    0x303e01db,
    0x303e81f4,
    0x303f0204,
    0x303f8217,
    0x30400226,
    0x30408232,
    0x30410247,
    0x30418257,
    0x3042026e,
    0x3042827b,
    0x3043028e,
    0x3043829d,
    0x304402b2,
    0x304482d3,
    0x304502e6,
    0x304582f9,
    0x30460312,
    0x3046832d,
    0x3047034a,
    0x30478363,
    0x30480371,
    0x30488382,
    0x30490391,
    0x304983a9,
    0x304a03bb,
    0x304a83cf,
    0x304b03ee,
    0x304b8401,
    0x304c040c,
    0x304c841d,
    0x304d0429,
    0x304d843f,
    0x304e044d,
    0x304e8463,
    0x304f0475,
    0x304f8487,
    0x3050049a,
    0x305084ad,
    0x305104be,
    0x305184ce,
    0x305204e6,
    0x305284fb,
    0x30530513,
    0x30538527,
    0x3054053f,
    0x30548558,
    0x30550571,
    0x3055858e,
    0x30560599,
    0x305685b1,
    0x305705c1,
    0x305785d2,
    0x305805e5,
    0x305885fb,
    0x30590604,
    0x30598619,
    0x305a062c,
    0x305a863b,
    0x305b065b,
    0x305b866a,
    0x305c068b,
    0x305c86a7,
    0x305d06b3,
    0x305d86d3,
    0x305e06ef,
    0x305e8700,
    0x305f0716,
    0x305f8720,
    0x34320b47,
    0x34328b5b,
    0x34330b78,
    0x34338b8b,
    0x34340b9a,
    0x34348bb7,
    0x3c320083,
    0x3c328c62,
    0x3c330c7b,
    0x3c338c96,
    0x3c340cb3,
    0x3c348cdd,
    0x3c350cf8,
    0x3c358d1e,
    0x3c360d37,
    0x3c368d4f,
    0x3c370d60,
    0x3c378d6e,
    0x3c380d7b,
    0x3c388d8f,
    0x3c390c25,
    0x3c398da3,
    0x3c3a0db7,
    0x3c3a88ff,
    0x3c3b0dc7,
    0x3c3b8de2,
    0x3c3c0df4,
    0x3c3c8e0a,
    0x3c3d0e14,
    0x3c3d8e28,
    0x3c3e0e36,
    0x3c3e8e5b,
    0x3c3f0c4e,
    0x3c3f8e44,
    0x3c4000ac,
    0x3c4080ea,
    0x3c410cce,
    0x3c418d0d,
    0x403216fa,
    0x40329710,
    0x4033173e,
    0x40339748,
    0x4034175f,
    0x4034977d,
    0x4035178d,
    0x4035979f,
    0x403617ac,
    0x403697b8,
    0x403717cd,
    0x403797df,
    0x403817ea,
    0x403897fc,
    0x40390e8b,
    0x4039980c,
    0x403a181f,
    0x403a9840,
    0x403b1851,
    0x403b9861,
    0x403c0064,
    0x403c8083,
    0x403d18c1,
    0x403d98d7,
    0x403e18e6,
    0x403e98f9,
    0x403f1913,
    0x403f9921,
    0x40401936,
    0x4040994a,
    0x40411967,
    0x40419982,
    0x4042199b,
    0x404299ae,
    0x404319c2,
    0x404399da,
    0x404419f1,
    0x404480ac,
    0x40451a06,
    0x40459a18,
    0x40461a3c,
    0x40469a5c,
    0x40471a6a,
    0x40479a91,
    0x40481ace,
    0x40489ae7,
    0x40491afe,
    0x40499b18,
    0x404a1b2f,
    0x404a9b4d,
    0x404b1b65,
    0x404b9b7c,
    0x404c1b92,
    0x404c9ba4,
    0x404d1bc5,
    0x404d9be7,
    0x404e1bfb,
    0x404e9c08,
    0x404f1c35,
    0x404f9c5e,
    0x40501c99,
    0x40509cad,
    0x40511cc8,
    0x40519cd8,
    0x40521cef,
    0x40529d13,
    0x40531d2b,
    0x40539d3e,
    0x40541d53,
    0x40549d76,
    0x40551d84,
    0x40559da1,
    0x40561dae,
    0x40569dc7,
    0x40571ddf,
    0x40579df2,
    0x40581e07,
    0x40589e2e,
    0x40591e5d,
    0x40599e8a,
    0x405a1e9e,
    0x405a9eae,
    0x405b1ec6,
    0x405b9ed7,
    0x405c1eea,
    0x405c9f0b,
    0x405d1f18,
    0x405d9f2f,
    0x405e1f6d,
    0x405e8a95,
    0x405f1f8e,
    0x405f9f9b,
    0x40601fa9,
    0x40609fcb,
    0x4061200f,
    0x4061a047,
    0x4062205e,
    0x4062a06f,
    0x40632080,
    0x4063a095,
    0x406420ac,
    0x4064a0d8,
    0x406520f3,
    0x4065a10a,
    0x40662122,
    0x4066a14c,
    0x40672177,
    0x4067a198,
    0x406821ab,
    0x4068a1cc,
    0x406921fe,
    0x4069a22c,
    0x406a224d,
    0x406aa26d,
    0x406b23f5,
    0x406ba418,
    0x406c242e,
    0x406ca690,
    0x406d26bf,
    0x406da6e7,
    0x406e2715,
    0x406ea749,
    0x406f2768,
    0x406fa77d,
    0x40702790,
    0x4070a7ad,
    0x40710800,
    0x4071a7bf,
    0x407227d2,
    0x4072a7eb,
    0x40732803,
    0x4073936d,
    0x40742817,
    0x4074a831,
    0x40752842,
    0x4075a856,
    0x40762864,
    0x407691aa,
    0x40772889,
    0x4077a8ab,
    0x407828c6,
    0x4078a8ff,
    0x40792916,
    0x4079a92c,
    0x407a2938,
    0x407aa94b,
    0x407b2960,
    0x407ba972,
    0x407c2987,
    0x407ca990,
    0x407d21e7,
    0x407d9c6e,
    0x407e28db,
    0x407e9e3e,
    0x407f1a7e,
    0x407f9887,
    0x40801c45,
    0x40809aa6,
    0x40811d01,
    0x40819c1f,
    0x40822700,
    0x4082986d,
    0x40831e19,
    0x4083a0bd,
    0x40841aba,
    0x40849e76,
    0x40851efb,
    0x40859ff3,
    0x40861f4f,
    0x40869c88,
    0x4087272d,
    0x4087a024,
    0x408818aa,
    0x41f42320,
    0x41f923b2,
    0x41fe22a5,
    0x41fea481,
    0x41ff2572,
    0x42032339,
    0x4208235b,
    0x4208a397,
    0x42092289,
    0x4209a3d1,
    0x420a22e0,
    0x420aa2c0,
    0x420b2300,
    0x420ba379,
    0x420c258e,
    0x420ca44e,
    0x420d2468,
    0x420da49f,
    0x421224b9,
    0x42172555,
    0x4217a4fb,
    0x421c251d,
    0x421f24d8,
    0x422125a5,
    0x42262538,
    0x422b2674,
    0x422ba622,
    0x422c265c,
    0x422ca5e1,
    0x422d25c0,
    0x422da641,
    0x422e2607,
    0x4432072b,
    0x4432873a,
    0x44330746,
    0x44338754,
    0x44340767,
    0x44348778,
    0x4435077f,
    0x44358789,
    0x4436079c,
    0x443687b2,
    0x443707c4,
    0x443787d1,
    0x443807e0,
    0x443887e8,
    0x44390800,
    0x4439880e,
    0x443a0821,
    0x4c3211d4,
    0x4c3291e4,
    0x4c3311f7,
    0x4c339217,
    0x4c3400ac,
    0x4c3480ea,
    0x4c351223,
    0x4c359231,
    0x4c36124d,
    0x4c369260,
    0x4c37126f,
    0x4c37927d,
    0x4c381292,
    0x4c38929e,
    0x4c3912be,
    0x4c3992e8,
    0x4c3a1301,
    0x4c3a931a,
    0x4c3b05fb,
    0x4c3b9333,
    0x4c3c1345,
    0x4c3c9354,
    0x4c3d136d,
    0x4c3d937c,
    0x4c3e1389,
    0x50322c09,
    0x5032ac18,
    0x50332c23,
    0x5033ac33,
    0x50342c4c,
    0x5034ac66,
    0x50352c74,
    0x5035ac8a,
    0x50362c9c,
    0x5036acb2,
    0x50372ccb,
    0x5037acde,
    0x50382cf6,
    0x5038ad07,
    0x50392d1c,
    0x5039ad30,
    0x503a2d50,
    0x503aad66,
    0x503b2d7e,
    0x503bad90,
    0x503c2dac,
    0x503cadc3,
    0x503d2ddc,
    0x503dadf2,
    0x503e2dff,
    0x503eae15,
    0x503f2e27,
    0x503f8382,
    0x50402e3a,
    0x5040ae4a,
    0x50412e64,
    0x5041ae73,
    0x50422e8d,
    0x5042aeaa,
    0x50432eba,
    0x5043aeca,
    0x50442ed9,
    0x5044843f,
    0x50452eed,
    0x5045af0b,
    0x50462f1e,
    0x5046af34,
    0x50472f46,
    0x5047af5b,
    0x50482f81,
    0x5048af8f,
    0x50492fa2,
    0x5049afb7,
    0x504a2fcd,
    0x504aafdd,
    0x504b2ffd,
    0x504bb010,
    0x504c3033,
    0x504cb061,
    0x504d3073,
    0x504db090,
    0x504e30ab,
    0x504eb0c7,
    0x504f30d9,
    0x504fb0f0,
    0x505030ff,
    0x505086ef,
    0x50513112,
    0x58320ec9,
    0x68320e8b,
    0x68328c25,
    0x68330c38,
    0x68338e99,
    0x68340ea9,
    0x683480ea,
    0x6c320e67,
    0x6c328bfc,
    0x6c330e72,
    0x74320a0b,
    0x78320970,
    0x78328985,
    0x78330991,
    0x78338083,
    0x783409a0,
    0x783489b5,
    0x783509d4,
    0x783589f6,
    0x78360a0b,
    0x78368a21,
    0x78370a31,
    0x78378a44,
    0x78380a57,
    0x78388a69,
    0x78390a76,
    0x78398a95,
    0x783a0aaa,
    0x783a8ab8,
    0x783b0ac2,
    0x783b8ad6,
    0x783c0aed,
    0x783c8b02,
    0x783d0b19,
    0x783d8b2e,
    0x783e0a84,
    0x7c3210d6,
};

const size_t kOpenSSLReasonValuesLen = sizeof(kOpenSSLReasonValues) / sizeof(kOpenSSLReasonValues[0]);

const char kOpenSSLReasonStringData[] =
    "ASN1_LENGTH_MISMATCH\0"
    "AUX_ERROR\0"
    "BAD_GET_ASN1_OBJECT_CALL\0"
    "BAD_OBJECT_HEADER\0"
    "BMPSTRING_IS_WRONG_LENGTH\0"
    "BN_LIB\0"
    "BOOLEAN_IS_WRONG_LENGTH\0"
    "BUFFER_TOO_SMALL\0"
    "CONTEXT_NOT_INITIALISED\0"
    "DECODE_ERROR\0"
    "DEPTH_EXCEEDED\0"
    "DIGEST_AND_KEY_TYPE_NOT_SUPPORTED\0"
    "ENCODE_ERROR\0"
    "ERROR_GETTING_TIME\0"
    "EXPECTING_AN_ASN1_SEQUENCE\0"
    "EXPECTING_AN_INTEGER\0"
    "EXPECTING_AN_OBJECT\0"
    "EXPECTING_A_BOOLEAN\0"
    "EXPECTING_A_TIME\0"
    "EXPLICIT_LENGTH_MISMATCH\0"
    "EXPLICIT_TAG_NOT_CONSTRUCTED\0"
    "FIELD_MISSING\0"
    "FIRST_NUM_TOO_LARGE\0"
    "HEADER_TOO_LONG\0"
    "ILLEGAL_BITSTRING_FORMAT\0"
    "ILLEGAL_BOOLEAN\0"
    "ILLEGAL_CHARACTERS\0"
    "ILLEGAL_FORMAT\0"
    "ILLEGAL_HEX\0"
    "ILLEGAL_IMPLICIT_TAG\0"
    "ILLEGAL_INTEGER\0"
    "ILLEGAL_NESTED_TAGGING\0"
    "ILLEGAL_NULL\0"
    "ILLEGAL_NULL_VALUE\0"
    "ILLEGAL_OBJECT\0"
    "ILLEGAL_OPTIONAL_ANY\0"
    "ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE\0"
    "ILLEGAL_TAGGED_ANY\0"
    "ILLEGAL_TIME_VALUE\0"
    "INTEGER_NOT_ASCII_FORMAT\0"
    "INTEGER_TOO_LARGE_FOR_LONG\0"
    "INVALID_BIT_STRING_BITS_LEFT\0"
    "INVALID_BMPSTRING_LENGTH\0"
    "INVALID_DIGIT\0"
    "INVALID_MODIFIER\0"
    "INVALID_NUMBER\0"
    "INVALID_OBJECT_ENCODING\0"
    "INVALID_SEPARATOR\0"
    "INVALID_TIME_FORMAT\0"
    "INVALID_UNIVERSALSTRING_LENGTH\0"
    "INVALID_UTF8STRING\0"
    "LIST_ERROR\0"
    "MISSING_ASN1_EOS\0"
    "MISSING_EOC\0"
    "MISSING_SECOND_NUMBER\0"
    "MISSING_VALUE\0"
    "MSTRING_NOT_UNIVERSAL\0"
    "MSTRING_WRONG_TAG\0"
    "NESTED_ASN1_ERROR\0"
    "NESTED_ASN1_STRING\0"
    "NON_HEX_CHARACTERS\0"
    "NOT_ASCII_FORMAT\0"
    "NOT_ENOUGH_DATA\0"
    "NO_MATCHING_CHOICE_TYPE\0"
    "NULL_IS_WRONG_LENGTH\0"
    "OBJECT_NOT_ASCII_FORMAT\0"
    "ODD_NUMBER_OF_CHARS\0"
    "SECOND_NUMBER_TOO_LARGE\0"
    "SEQUENCE_LENGTH_MISMATCH\0"
    "SEQUENCE_NOT_CONSTRUCTED\0"
    "SEQUENCE_OR_SET_NEEDS_CONFIG\0"
    "SHORT_LINE\0"
    "STREAMING_NOT_SUPPORTED\0"
    "STRING_TOO_LONG\0"
    "STRING_TOO_SHORT\0"
    "TAG_VALUE_TOO_HIGH\0"
    "TIME_NOT_ASCII_FORMAT\0"
    "TOO_LONG\0"
    "TYPE_NOT_CONSTRUCTED\0"
    "TYPE_NOT_PRIMITIVE\0"
    "UNEXPECTED_EOC\0"
    "UNIVERSALSTRING_IS_WRONG_LENGTH\0"
    "UNKNOWN_FORMAT\0"
    "UNKNOWN_MESSAGE_DIGEST_ALGORITHM\0"
    "UNKNOWN_SIGNATURE_ALGORITHM\0"
    "UNKNOWN_TAG\0"
    "UNSUPPORTED_ANY_DEFINED_BY_TYPE\0"
    "UNSUPPORTED_PUBLIC_KEY_TYPE\0"
    "UNSUPPORTED_TYPE\0"
    "WRONG_PUBLIC_KEY_TYPE\0"
    "WRONG_TAG\0"
    "WRONG_TYPE\0"
    "BAD_FOPEN_MODE\0"
    "BROKEN_PIPE\0"
    "CONNECT_ERROR\0"
    "ERROR_SETTING_NBIO\0"
    "INVALID_ARGUMENT\0"
    "IN_USE\0"
    "KEEPALIVE\0"
    "NBIO_CONNECT_ERROR\0"
    "NO_HOSTNAME_SPECIFIED\0"
    "NO_PORT_SPECIFIED\0"
    "NO_SUCH_FILE\0"
    "NULL_PARAMETER\0"
    "SYS_LIB\0"
    "UNABLE_TO_CREATE_SOCKET\0"
    "UNINITIALIZED\0"
    "UNSUPPORTED_METHOD\0"
    "WRITE_TO_READ_ONLY_BIO\0"
    "ARG2_LT_ARG3\0"
    "BAD_ENCODING\0"
    "BAD_RECIPROCAL\0"
    "BIGNUM_TOO_LONG\0"
    "BITS_TOO_SMALL\0"
    "CALLED_WITH_EVEN_MODULUS\0"
    "DIV_BY_ZERO\0"
    "EXPAND_ON_STATIC_BIGNUM_DATA\0"
    "INPUT_NOT_REDUCED\0"
    "INVALID_RANGE\0"
    "NEGATIVE_NUMBER\0"
    "NOT_A_SQUARE\0"
    "NOT_INITIALIZED\0"
    "NO_INVERSE\0"
    "PRIVATE_KEY_TOO_LARGE\0"
    "P_IS_NOT_PRIME\0"
    "TOO_MANY_ITERATIONS\0"
    "TOO_MANY_TEMPORARY_VARIABLES\0"
    "AES_KEY_SETUP_FAILED\0"
    "BAD_DECRYPT\0"
    "BAD_KEY_LENGTH\0"
    "CTRL_NOT_IMPLEMENTED\0"
    "CTRL_OPERATION_NOT_IMPLEMENTED\0"
    "DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH\0"
    "INITIALIZATION_ERROR\0"
    "INPUT_NOT_INITIALIZED\0"
    "INVALID_AD_SIZE\0"
    "INVALID_KEY_LENGTH\0"
    "INVALID_NONCE_SIZE\0"
    "INVALID_OPERATION\0"
    "IV_TOO_LARGE\0"
    "NO_CIPHER_SET\0"
    "NO_DIRECTION_SET\0"
    "OUTPUT_ALIASES_INPUT\0"
    "TAG_TOO_LARGE\0"
    "TOO_LARGE\0"
    "UNSUPPORTED_AD_SIZE\0"
    "UNSUPPORTED_INPUT_SIZE\0"
    "UNSUPPORTED_KEY_SIZE\0"
    "UNSUPPORTED_NONCE_SIZE\0"
    "UNSUPPORTED_TAG_SIZE\0"
    "WRONG_FINAL_BLOCK_LENGTH\0"
    "LIST_CANNOT_BE_NULL\0"
    "MISSING_CLOSE_SQUARE_BRACKET\0"
    "MISSING_EQUAL_SIGN\0"
    "NO_CLOSE_BRACE\0"
    "UNABLE_TO_CREATE_NEW_SECTION\0"
    "VARIABLE_HAS_NO_VALUE\0"
    "BAD_GENERATOR\0"
    "INVALID_PUBKEY\0"
    "MODULUS_TOO_LARGE\0"
    "NO_PRIVATE_VALUE\0"
    "BAD_Q_VALUE\0"
    "BAD_VERSION\0"
    "MISSING_PARAMETERS\0"
    "NEED_NEW_SETUP_VALUES\0"
    "BIGNUM_OUT_OF_RANGE\0"
    "COORDINATES_OUT_OF_RANGE\0"
    "D2I_ECPKPARAMETERS_FAILURE\0"
    "EC_GROUP_NEW_BY_NAME_FAILURE\0"
    "GROUP2PKPARAMETERS_FAILURE\0"
    "GROUP_MISMATCH\0"
    "I2D_ECPKPARAMETERS_FAILURE\0"
    "INCOMPATIBLE_OBJECTS\0"
    "INVALID_COFACTOR\0"
    "INVALID_COMPRESSED_POINT\0"
    "INVALID_COMPRESSION_BIT\0"
    "INVALID_ENCODING\0"
    "INVALID_FIELD\0"
    "INVALID_FORM\0"
    "INVALID_GROUP_ORDER\0"
    "INVALID_PRIVATE_KEY\0"
    "MISSING_PRIVATE_KEY\0"
    "NON_NAMED_CURVE\0"
    "PKPARAMETERS2GROUP_FAILURE\0"
    "POINT_AT_INFINITY\0"
    "POINT_IS_NOT_ON_CURVE\0"
    "SLOT_FULL\0"
    "UNDEFINED_GENERATOR\0"
    "UNKNOWN_GROUP\0"
    "UNKNOWN_ORDER\0"
    "WRONG_CURVE_PARAMETERS\0"
    "WRONG_ORDER\0"
    "KDF_FAILED\0"
    "POINT_ARITHMETIC_FAILURE\0"
    "BAD_SIGNATURE\0"
    "NOT_IMPLEMENTED\0"
    "RANDOM_NUMBER_GENERATION_FAILED\0"
    "OPERATION_NOT_SUPPORTED\0"
    "COMMAND_NOT_SUPPORTED\0"
    "DIFFERENT_KEY_TYPES\0"
    "DIFFERENT_PARAMETERS\0"
    "EXPECTING_AN_EC_KEY_KEY\0"
    "EXPECTING_AN_RSA_KEY\0"
    "EXPECTING_A_DSA_KEY\0"
    "ILLEGAL_OR_UNSUPPORTED_PADDING_MODE\0"
    "INVALID_DIGEST_LENGTH\0"
    "INVALID_DIGEST_TYPE\0"
    "INVALID_KEYBITS\0"
    "INVALID_MGF1_MD\0"
    "INVALID_PADDING_MODE\0"
    "INVALID_PSS_SALTLEN\0"
    "KEYS_NOT_SET\0"
    "NO_DEFAULT_DIGEST\0"
    "NO_KEY_SET\0"
    "NO_MDC2_SUPPORT\0"
    "NO_NID_FOR_CURVE\0"
    "NO_OPERATION_SET\0"
    "NO_PARAMETERS_SET\0"
    "OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE\0"
    "OPERATON_NOT_INITIALIZED\0"
    "UNKNOWN_PUBLIC_KEY_TYPE\0"
    "UNSUPPORTED_ALGORITHM\0"
    "OUTPUT_TOO_LARGE\0"
    "UNKNOWN_NID\0"
    "BAD_BASE64_DECODE\0"
    "BAD_END_LINE\0"
    "BAD_IV_CHARS\0"
    "BAD_PASSWORD_READ\0"
    "CIPHER_IS_NULL\0"
    "ERROR_CONVERTING_PRIVATE_KEY\0"
    "NOT_DEK_INFO\0"
    "NOT_ENCRYPTED\0"
    "NOT_PROC_TYPE\0"
    "NO_START_LINE\0"
    "READ_KEY\0"
    "SHORT_HEADER\0"
    "UNSUPPORTED_CIPHER\0"
    "UNSUPPORTED_ENCRYPTION\0"
    "BAD_PKCS12_DATA\0"
    "BAD_PKCS12_VERSION\0"
    "CIPHER_HAS_NO_OBJECT_IDENTIFIER\0"
    "CRYPT_ERROR\0"
    "ENCRYPT_ERROR\0"
    "ERROR_SETTING_CIPHER_PARAMS\0"
    "INCORRECT_PASSWORD\0"
    "KEYGEN_FAILURE\0"
    "KEY_GEN_ERROR\0"
    "METHOD_NOT_SUPPORTED\0"
    "MISSING_MAC\0"
    "MULTIPLE_PRIVATE_KEYS_IN_PKCS12\0"
    "PKCS12_PUBLIC_KEY_INTEGRITY_NOT_SUPPORTED\0"
    "PKCS12_TOO_DEEPLY_NESTED\0"
    "PRIVATE_KEY_DECODE_ERROR\0"
    "PRIVATE_KEY_ENCODE_ERROR\0"
    "UNKNOWN_ALGORITHM\0"
    "UNKNOWN_CIPHER\0"
    "UNKNOWN_CIPHER_ALGORITHM\0"
    "UNKNOWN_DIGEST\0"
    "UNKNOWN_HASH\0"
    "UNSUPPORTED_PRIVATE_KEY_ALGORITHM\0"
    "BAD_E_VALUE\0"
    "BAD_FIXED_HEADER_DECRYPT\0"
    "BAD_PAD_BYTE_COUNT\0"
    "BAD_RSA_PARAMETERS\0"
    "BLOCK_TYPE_IS_NOT_01\0"
    "BN_NOT_INITIALIZED\0"
    "CANNOT_RECOVER_MULTI_PRIME_KEY\0"
    "CRT_PARAMS_ALREADY_GIVEN\0"
    "CRT_VALUES_INCORRECT\0"
    "DATA_LEN_NOT_EQUAL_TO_MOD_LEN\0"
    "DATA_TOO_LARGE\0"
    "DATA_TOO_LARGE_FOR_KEY_SIZE\0"
    "DATA_TOO_LARGE_FOR_MODULUS\0"
    "DATA_TOO_SMALL\0"
    "DATA_TOO_SMALL_FOR_KEY_SIZE\0"
    "DIGEST_TOO_BIG_FOR_RSA_KEY\0"
    "D_E_NOT_CONGRUENT_TO_1\0"
    "EMPTY_PUBLIC_KEY\0"
    "FIRST_OCTET_INVALID\0"
    "INCONSISTENT_SET_OF_CRT_VALUES\0"
    "INTERNAL_ERROR\0"
    "INVALID_MESSAGE_LENGTH\0"
    "KEY_SIZE_TOO_SMALL\0"
    "LAST_OCTET_INVALID\0"
    "MUST_HAVE_AT_LEAST_TWO_PRIMES\0"
    "NO_PUBLIC_EXPONENT\0"
    "NULL_BEFORE_BLOCK_MISSING\0"
    "N_NOT_EQUAL_P_Q\0"
    "OAEP_DECODING_ERROR\0"
    "ONLY_ONE_OF_P_Q_GIVEN\0"
    "OUTPUT_BUFFER_TOO_SMALL\0"
    "PADDING_CHECK_FAILED\0"
    "PKCS_DECODING_ERROR\0"
    "SLEN_CHECK_FAILED\0"
    "SLEN_RECOVERY_FAILED\0"
    "UNKNOWN_ALGORITHM_TYPE\0"
    "UNKNOWN_PADDING_TYPE\0"
    "VALUE_MISSING\0"
    "WRONG_SIGNATURE_LENGTH\0"
    "APP_DATA_IN_HANDSHAKE\0"
    "ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT\0"
    "BAD_ALERT\0"
    "BAD_CHANGE_CIPHER_SPEC\0"
    "BAD_DATA_RETURNED_BY_CALLBACK\0"
    "BAD_DH_P_LENGTH\0"
    "BAD_DIGEST_LENGTH\0"
    "BAD_ECC_CERT\0"
    "BAD_ECPOINT\0"
    "BAD_HANDSHAKE_RECORD\0"
    "BAD_HELLO_REQUEST\0"
    "BAD_LENGTH\0"
    "BAD_PACKET_LENGTH\0"
    "BAD_RSA_ENCRYPT\0"
    "BAD_SRTP_MKI_VALUE\0"
    "BAD_SRTP_PROTECTION_PROFILE_LIST\0"
    "BAD_SSL_FILETYPE\0"
    "BAD_WRITE_RETRY\0"
    "BIO_NOT_SET\0"
    "BLOCK_CIPHER_PAD_IS_WRONG\0"
    "BUFFERED_MESSAGES_ON_CIPHER_CHANGE\0"
    "CANNOT_PARSE_LEAF_CERT\0"
    "CA_DN_LENGTH_MISMATCH\0"
    "CA_DN_TOO_LONG\0"
    "CCS_RECEIVED_EARLY\0"
    "CERTIFICATE_VERIFY_FAILED\0"
    "CERT_CB_ERROR\0"
    "CERT_LENGTH_MISMATCH\0"
    "CHANNEL_ID_NOT_P256\0"
    "CHANNEL_ID_SIGNATURE_INVALID\0"
    "CIPHER_OR_HASH_UNAVAILABLE\0"
    "CLIENTHELLO_PARSE_FAILED\0"
    "CLIENTHELLO_TLSEXT\0"
    "CONNECTION_REJECTED\0"
    "CONNECTION_TYPE_NOT_SET\0"
    "CUSTOM_EXTENSION_ERROR\0"
    "DATA_LENGTH_TOO_LONG\0"
    "DECRYPTION_FAILED\0"
    "DECRYPTION_FAILED_OR_BAD_RECORD_MAC\0"
    "DH_PUBLIC_VALUE_LENGTH_IS_WRONG\0"
    "DH_P_TOO_LONG\0"
    "DIGEST_CHECK_FAILED\0"
    "DOWNGRADE_DETECTED\0"
    "DTLS_MESSAGE_TOO_BIG\0"
    "DUPLICATE_EXTENSION\0"
    "DUPLICATE_KEY_SHARE\0"
    "ECC_CERT_NOT_FOR_SIGNING\0"
    "EMS_STATE_INCONSISTENT\0"
    "ENCRYPTED_LENGTH_TOO_LONG\0"
    "ERROR_ADDING_EXTENSION\0"
    "ERROR_IN_RECEIVED_CIPHER_LIST\0"
    "ERROR_PARSING_EXTENSION\0"
    "EXCESSIVE_MESSAGE_SIZE\0"
    "EXTRA_DATA_IN_MESSAGE\0"
    "FRAGMENT_MISMATCH\0"
    "GOT_NEXT_PROTO_WITHOUT_EXTENSION\0"
    "HANDSHAKE_FAILURE_ON_CLIENT_HELLO\0"
    "HTTPS_PROXY_REQUEST\0"
    "HTTP_REQUEST\0"
    "INAPPROPRIATE_FALLBACK\0"
    "INVALID_ALPN_PROTOCOL\0"
    "INVALID_COMMAND\0"
    "INVALID_COMPRESSION_LIST\0"
    "INVALID_MESSAGE\0"
    "INVALID_OUTER_RECORD_TYPE\0"
    "INVALID_SCT_LIST\0"
    "INVALID_SSL_SESSION\0"
    "INVALID_TICKET_KEYS_LENGTH\0"
    "LENGTH_MISMATCH\0"
    "LIBRARY_HAS_NO_CIPHERS\0"
    "MISSING_EXTENSION\0"
    "MISSING_KEY_SHARE\0"
    "MISSING_RSA_CERTIFICATE\0"
    "MISSING_TMP_DH_KEY\0"
    "MISSING_TMP_ECDH_KEY\0"
    "MIXED_SPECIAL_OPERATOR_WITH_GROUPS\0"
    "MTU_TOO_SMALL\0"
    "NEGOTIATED_BOTH_NPN_AND_ALPN\0"
    "NESTED_GROUP\0"
    "NO_CERTIFICATES_RETURNED\0"
    "NO_CERTIFICATE_ASSIGNED\0"
    "NO_CERTIFICATE_SET\0"
    "NO_CIPHERS_AVAILABLE\0"
    "NO_CIPHERS_PASSED\0"
    "NO_CIPHERS_SPECIFIED\0"
    "NO_CIPHER_MATCH\0"
    "NO_COMMON_SIGNATURE_ALGORITHMS\0"
    "NO_COMPRESSION_SPECIFIED\0"
    "NO_GROUPS_SPECIFIED\0"
    "NO_METHOD_SPECIFIED\0"
    "NO_P256_SUPPORT\0"
    "NO_PRIVATE_KEY_ASSIGNED\0"
    "NO_RENEGOTIATION\0"
    "NO_REQUIRED_DIGEST\0"
    "NO_SHARED_CIPHER\0"
    "NO_SHARED_GROUP\0"
    "NULL_SSL_CTX\0"
    "NULL_SSL_METHOD_PASSED\0"
    "OLD_SESSION_CIPHER_NOT_RETURNED\0"
    "OLD_SESSION_PRF_HASH_MISMATCH\0"
    "OLD_SESSION_VERSION_NOT_RETURNED\0"
    "PARSE_TLSEXT\0"
    "PATH_TOO_LONG\0"
    "PEER_DID_NOT_RETURN_A_CERTIFICATE\0"
    "PEER_ERROR_UNSUPPORTED_CERTIFICATE_TYPE\0"
    "PRE_SHARED_KEY_MUST_BE_LAST\0"
    "PROTOCOL_IS_SHUTDOWN\0"
    "PSK_IDENTITY_BINDER_COUNT_MISMATCH\0"
    "PSK_IDENTITY_NOT_FOUND\0"
    "PSK_NO_CLIENT_CB\0"
    "PSK_NO_SERVER_CB\0"
    "READ_TIMEOUT_EXPIRED\0"
    "RECORD_LENGTH_MISMATCH\0"
    "RECORD_TOO_LARGE\0"
    "RENEGOTIATION_EMS_MISMATCH\0"
    "RENEGOTIATION_ENCODING_ERR\0"
    "RENEGOTIATION_MISMATCH\0"
    "REQUIRED_CIPHER_MISSING\0"
    "RESUMED_EMS_SESSION_WITHOUT_EMS_EXTENSION\0"
    "RESUMED_NON_EMS_SESSION_WITH_EMS_EXTENSION\0"
    "SCSV_RECEIVED_WHEN_RENEGOTIATING\0"
    "SERVERHELLO_TLSEXT\0"
    "SESSION_ID_CONTEXT_UNINITIALIZED\0"
    "SESSION_MAY_NOT_BE_CREATED\0"
    "SHUTDOWN_WHILE_IN_INIT\0"
    "SIGNATURE_ALGORITHMS_EXTENSION_SENT_BY_SERVER\0"
    "SRTP_COULD_NOT_ALLOCATE_PROFILES\0"
    "SRTP_UNKNOWN_PROTECTION_PROFILE\0"
    "SSL3_EXT_INVALID_SERVERNAME\0"
    "SSLV3_ALERT_BAD_CERTIFICATE\0"
    "SSLV3_ALERT_BAD_RECORD_MAC\0"
    "SSLV3_ALERT_CERTIFICATE_EXPIRED\0"
    "SSLV3_ALERT_CERTIFICATE_REVOKED\0"
    "SSLV3_ALERT_CERTIFICATE_UNKNOWN\0"
    "SSLV3_ALERT_CLOSE_NOTIFY\0"
    "SSLV3_ALERT_DECOMPRESSION_FAILURE\0"
    "SSLV3_ALERT_HANDSHAKE_FAILURE\0"
    "SSLV3_ALERT_ILLEGAL_PARAMETER\0"
    "SSLV3_ALERT_NO_CERTIFICATE\0"
    "SSLV3_ALERT_UNEXPECTED_MESSAGE\0"
    "SSLV3_ALERT_UNSUPPORTED_CERTIFICATE\0"
    "SSL_CTX_HAS_NO_DEFAULT_SSL_VERSION\0"
    "SSL_HANDSHAKE_FAILURE\0"
    "SSL_SESSION_ID_CONTEXT_TOO_LONG\0"
    "TLSV1_ALERT_ACCESS_DENIED\0"
    "TLSV1_ALERT_DECODE_ERROR\0"
    "TLSV1_ALERT_DECRYPTION_FAILED\0"
    "TLSV1_ALERT_DECRYPT_ERROR\0"
    "TLSV1_ALERT_EXPORT_RESTRICTION\0"
    "TLSV1_ALERT_INAPPROPRIATE_FALLBACK\0"
    "TLSV1_ALERT_INSUFFICIENT_SECURITY\0"
    "TLSV1_ALERT_INTERNAL_ERROR\0"
    "TLSV1_ALERT_NO_RENEGOTIATION\0"
    "TLSV1_ALERT_PROTOCOL_VERSION\0"
    "TLSV1_ALERT_RECORD_OVERFLOW\0"
    "TLSV1_ALERT_UNKNOWN_CA\0"
    "TLSV1_ALERT_USER_CANCELLED\0"
    "TLSV1_BAD_CERTIFICATE_HASH_VALUE\0"
    "TLSV1_BAD_CERTIFICATE_STATUS_RESPONSE\0"
    "TLSV1_CERTIFICATE_REQUIRED\0"
    "TLSV1_CERTIFICATE_UNOBTAINABLE\0"
    "TLSV1_UNKNOWN_PSK_IDENTITY\0"
    "TLSV1_UNRECOGNIZED_NAME\0"
    "TLSV1_UNSUPPORTED_EXTENSION\0"
    "TLS_PEER_DID_NOT_RESPOND_WITH_CERTIFICATE_LIST\0"
    "TLS_RSA_ENCRYPTED_VALUE_LENGTH_IS_WRONG\0"
    "TOO_MANY_EMPTY_FRAGMENTS\0"
    "TOO_MANY_KEY_UPDATES\0"
    "TOO_MANY_WARNING_ALERTS\0"
    "TOO_MUCH_SKIPPED_EARLY_DATA\0"
    "UNABLE_TO_FIND_ECDH_PARAMETERS\0"
    "UNEXPECTED_EXTENSION\0"
    "UNEXPECTED_MESSAGE\0"
    "UNEXPECTED_OPERATOR_IN_GROUP\0"
    "UNEXPECTED_RECORD\0"
    "UNKNOWN_ALERT_TYPE\0"
    "UNKNOWN_CERTIFICATE_TYPE\0"
    "UNKNOWN_CIPHER_RETURNED\0"
    "UNKNOWN_CIPHER_TYPE\0"
    "UNKNOWN_KEY_EXCHANGE_TYPE\0"
    "UNKNOWN_PROTOCOL\0"
    "UNKNOWN_SSL_VERSION\0"
    "UNKNOWN_STATE\0"
    "UNSAFE_LEGACY_RENEGOTIATION_DISABLED\0"
    "UNSUPPORTED_COMPRESSION_ALGORITHM\0"
    "UNSUPPORTED_ELLIPTIC_CURVE\0"
    "UNSUPPORTED_PROTOCOL\0"
    "UNSUPPORTED_PROTOCOL_FOR_CUSTOM_KEY\0"
    "WRONG_CERTIFICATE_TYPE\0"
    "WRONG_CIPHER_RETURNED\0"
    "WRONG_CURVE\0"
    "WRONG_MESSAGE_TYPE\0"
    "WRONG_SIGNATURE_TYPE\0"
    "WRONG_SSL_VERSION\0"
    "WRONG_VERSION_NUMBER\0"
    "X509_LIB\0"
    "X509_VERIFICATION_SETUP_PROBLEMS\0"
    "AKID_MISMATCH\0"
    "BAD_PKCS7_VERSION\0"
    "BAD_X509_FILETYPE\0"
    "BASE64_DECODE_ERROR\0"
    "CANT_CHECK_DH_KEY\0"
    "CERT_ALREADY_IN_HASH_TABLE\0"
    "CRL_ALREADY_DELTA\0"
    "CRL_VERIFY_FAILURE\0"
    "IDP_MISMATCH\0"
    "INVALID_DIRECTORY\0"
    "INVALID_FIELD_NAME\0"
    "INVALID_PSS_PARAMETERS\0"
    "INVALID_TRUST\0"
    "ISSUER_MISMATCH\0"
    "KEY_TYPE_MISMATCH\0"
    "KEY_VALUES_MISMATCH\0"
    "LOADING_CERT_DIR\0"
    "LOADING_DEFAULTS\0"
    "NAME_TOO_LONG\0"
    "NEWER_CRL_NOT_NEWER\0"
    "NOT_PKCS7_SIGNED_DATA\0"
    "NO_CERTIFICATES_INCLUDED\0"
    "NO_CERT_SET_FOR_US_TO_VERIFY\0"
    "NO_CRLS_INCLUDED\0"
    "NO_CRL_NUMBER\0"
    "PUBLIC_KEY_DECODE_ERROR\0"
    "PUBLIC_KEY_ENCODE_ERROR\0"
    "SHOULD_RETRY\0"
    "UNKNOWN_KEY_TYPE\0"
    "UNKNOWN_PURPOSE_ID\0"
    "UNKNOWN_TRUST_ID\0"
    "WRONG_LOOKUP_TYPE\0"
    "BAD_IP_ADDRESS\0"
    "BAD_OBJECT\0"
    "BN_DEC2BN_ERROR\0"
    "BN_TO_ASN1_INTEGER_ERROR\0"
    "CANNOT_FIND_FREE_FUNCTION\0"
    "DIRNAME_ERROR\0"
    "DISTPOINT_ALREADY_SET\0"
    "DUPLICATE_ZONE_ID\0"
    "ERROR_CONVERTING_ZONE\0"
    "ERROR_CREATING_EXTENSION\0"
    "ERROR_IN_EXTENSION\0"
    "EXPECTED_A_SECTION_NAME\0"
    "EXTENSION_EXISTS\0"
    "EXTENSION_NAME_ERROR\0"
    "EXTENSION_NOT_FOUND\0"
    "EXTENSION_SETTING_NOT_SUPPORTED\0"
    "EXTENSION_VALUE_ERROR\0"
    "ILLEGAL_EMPTY_EXTENSION\0"
    "ILLEGAL_HEX_DIGIT\0"
    "INCORRECT_POLICY_SYNTAX_TAG\0"
    "INVALID_BOOLEAN_STRING\0"
    "INVALID_EXTENSION_STRING\0"
    "INVALID_MULTIPLE_RDNS\0"
    "INVALID_NAME\0"
    "INVALID_NULL_ARGUMENT\0"
    "INVALID_NULL_NAME\0"
    "INVALID_NULL_VALUE\0"
    "INVALID_NUMBERS\0"
    "INVALID_OBJECT_IDENTIFIER\0"
    "INVALID_OPTION\0"
    "INVALID_POLICY_IDENTIFIER\0"
    "INVALID_PROXY_POLICY_SETTING\0"
    "INVALID_PURPOSE\0"
    "INVALID_SECTION\0"
    "INVALID_SYNTAX\0"
    "ISSUER_DECODE_ERROR\0"
    "NEED_ORGANIZATION_AND_NUMBERS\0"
    "NO_CONFIG_DATABASE\0"
    "NO_ISSUER_CERTIFICATE\0"
    "NO_ISSUER_DETAILS\0"
    "NO_POLICY_IDENTIFIER\0"
    "NO_PROXY_CERT_POLICY_LANGUAGE_DEFINED\0"
    "NO_PUBLIC_KEY\0"
    "NO_SUBJECT_DETAILS\0"
    "ODD_NUMBER_OF_DIGITS\0"
    "OPERATION_NOT_DEFINED\0"
    "OTHERNAME_ERROR\0"
    "POLICY_LANGUAGE_ALREADY_DEFINED\0"
    "POLICY_PATH_LENGTH\0"
    "POLICY_PATH_LENGTH_ALREADY_DEFINED\0"
    "POLICY_WHEN_PROXY_LANGUAGE_REQUIRES_NO_POLICY\0"
    "SECTION_NOT_FOUND\0"
    "UNABLE_TO_GET_ISSUER_DETAILS\0"
    "UNABLE_TO_GET_ISSUER_KEYID\0"
    "UNKNOWN_BIT_STRING_ARGUMENT\0"
    "UNKNOWN_EXTENSION\0"
    "UNKNOWN_EXTENSION_NAME\0"
    "UNKNOWN_OPTION\0"
    "UNSUPPORTED_OPTION\0"
    "USER_TOO_LONG\0"
    "";

