﻿/*****************************************************************************
*                                                                            *
*  Copyright (c) 2012, Intel Corporation                                     *
*                                                                            *
*  All rights reserved.                                                      *
*                                                                            *
*  Redistribution and use in source and binary forms, with or without        *
*  modification, are permitted provided that the following conditions are    *
*  met:                                                                      *
*                                                                            *
*  *  Redistributions of source code must retain the above copyright         *
*     notice, this list of conditions and the following disclaimer.          *
*                                                                            *
*  *  Redistributions in binary form must reproduce the above copyright      *
*     notice, this list of conditions and the following disclaimer in the    *
*     documentation and/or other materials provided with the                 *
*     distribution.                                                          *
*                                                                            *
*  *  Neither the name of the Intel Corporation nor the names of its         *
*     contributors may be used to endorse or promote products derived from   *
*     this software without specific prior written permission.               *
*                                                                            *
*                                                                            *
*  THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION ""AS IS"" AND ANY          *
*  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE         *
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR        *
*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL CORPORATION OR            *
*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,     *
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       *
*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        *
*  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    *
*  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      *
*  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        *
*  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
*                                                                            *
******************************************************************************
* Developers and authors:                                                    *
* Shay Gueron (1, 2), and Vlad Krasnov (1)                                   *
* (1) Intel Corporation, Israel Development Center, Haifa, Israel            *
* (2) University of Haifa, Israel                                            *
*****************************************************************************/

#include <openssl/base.h>

#if !defined(OPENSSL_NO_ASM) && defined(OPENSSL_X86_64)

#include "rsaz_exp.h"

#include <openssl/mem.h>

#include "../../internal.h"


/*
 * See crypto/bn/asm/rsaz-avx2.pl for further details.
 */
void rsaz_1024_norm2red_avx2(void *red,const void *norm);
void rsaz_1024_mul_avx2(void *ret,const void *a,const void *b,const void *n,BN_ULONG k);
void rsaz_1024_sqr_avx2(void *ret,const void *a,const void *n,BN_ULONG k,int cnt);
void rsaz_1024_scatter5_avx2(void *tbl,const void *val,int i);
void rsaz_1024_gather5_avx2(void *val,const void *tbl,int i);
void rsaz_1024_red2norm_avx2(void *norm,const void *red);

alignas(64) static const BN_ULONG one[40] =
	{1,0,0,    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
alignas(64) static const BN_ULONG two80[40] =
	{0,0,1<<22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void RSAZ_1024_mod_exp_avx2(BN_ULONG result_norm[16],
	const BN_ULONG base_norm[16], const BN_ULONG exponent[16],
	const BN_ULONG m_norm[16], const BN_ULONG RR[16], BN_ULONG k0)
{
	alignas(64) uint8_t storage[(320 * 3) + (32 * 9 * 16)]; /* 5.5KB */
	unsigned char	*a_inv, *m, *result,
			*table_s = storage + (320 * 3),
			*R2      = table_s;	/* borrow */
	int index;
	int wvalue;

	if (((((uintptr_t)storage & 4095) + 320) >> 12) != 0) {
		result = storage;
		a_inv = storage + 320;
		m = storage + (320 * 2); /* should not cross page */
	} else {
		m = storage;		/* should not cross page */
		result = storage + 320;
		a_inv = storage + (320 * 2);
	}

	rsaz_1024_norm2red_avx2(m, m_norm);
	rsaz_1024_norm2red_avx2(a_inv, base_norm);
	rsaz_1024_norm2red_avx2(R2, RR);

	rsaz_1024_mul_avx2(R2, R2, R2, m, k0);
	rsaz_1024_mul_avx2(R2, R2, two80, m, k0);

	/* table[0] = 1 */
	rsaz_1024_mul_avx2(result, R2, one, m, k0);
	/* table[1] = a_inv^1 */
	rsaz_1024_mul_avx2(a_inv, a_inv, R2, m, k0);

	rsaz_1024_scatter5_avx2(table_s,result,0);
	rsaz_1024_scatter5_avx2(table_s,a_inv,1);

	/* table[2] = a_inv^2 */
	rsaz_1024_sqr_avx2(result, a_inv, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,2);
#if 0
	/* this is almost 2x smaller and less than 1% slower */
	for (index=3; index<32; index++) {
		rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
		rsaz_1024_scatter5_avx2(table_s,result,index);
	}
#else
	/* table[4] = a_inv^4 */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,4);
	/* table[8] = a_inv^8 */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,8);
	/* table[16] = a_inv^16 */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,16);
	/* table[17] = a_inv^17 */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,17);

	/* table[3] */
	rsaz_1024_gather5_avx2(result,table_s,2);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,3);
	/* table[6] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,6);
	/* table[12] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,12);
 	/* table[24] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,24);
	/* table[25] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,25);

	/* table[5] */
	rsaz_1024_gather5_avx2(result,table_s,4);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,5);
	/* table[10] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,10);
	/* table[20] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,20);
	/* table[21] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,21);

	/* table[7] */
	rsaz_1024_gather5_avx2(result,table_s,6);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,7);
	/* table[14] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,14);
	/* table[28] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,28);
	/* table[29] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,29);

	/* table[9] */
	rsaz_1024_gather5_avx2(result,table_s,8);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,9);
	/* table[18] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,18);
	/* table[19] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,19);

	/* table[11] */
	rsaz_1024_gather5_avx2(result,table_s,10);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,11);
	/* table[22] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,22);
	/* table[23] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,23);

	/* table[13] */
	rsaz_1024_gather5_avx2(result,table_s,12);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,13);
	/* table[26] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,26);
	/* table[27] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,27);

	/* table[15] */
	rsaz_1024_gather5_avx2(result,table_s,14);
	rsaz_1024_mul_avx2(result,result,a_inv,m,k0);
	rsaz_1024_scatter5_avx2(table_s,result,15);
	/* table[30] */
	rsaz_1024_sqr_avx2(result, result, m, k0, 1);
	rsaz_1024_scatter5_avx2(table_s,result,30);
	/* table[31] */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	rsaz_1024_scatter5_avx2(table_s,result,31);
#endif

	const uint8_t *p_str = (const uint8_t *)exponent;

	/* load first window */
	wvalue = p_str[127] >> 3;
	rsaz_1024_gather5_avx2(result,table_s,wvalue);

	index = 1014;

	while(index > -1) {	/* loop for the remaining 127 windows */

		rsaz_1024_sqr_avx2(result, result, m, k0, 5);

		wvalue = *((const unsigned short*)&p_str[index / 8]);
		wvalue = (wvalue>> (index%8)) & 31;
		index-=5;

		rsaz_1024_gather5_avx2(a_inv,table_s,wvalue);	/* borrow a_inv */
		rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
	}

	/* square four times */
	rsaz_1024_sqr_avx2(result, result, m, k0, 4);

	wvalue = p_str[0] & 15;

	rsaz_1024_gather5_avx2(a_inv,table_s,wvalue);	/* borrow a_inv */
	rsaz_1024_mul_avx2(result, result, a_inv, m, k0);

	/* from Montgomery */
	rsaz_1024_mul_avx2(result, result, one, m, k0);

	rsaz_1024_red2norm_avx2(result_norm, result);

	OPENSSL_cleanse(storage,sizeof(storage));
}

#endif  /* OPENSSL_X86_64 */
