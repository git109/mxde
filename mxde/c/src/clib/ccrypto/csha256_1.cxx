/**
 **********************************************************************
 * Copyright (c) 1998-2005 The OpenSSL Project.  All rights reserved.
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
 *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@openssl.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"
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
 * Hudson (tjh@cryptsoft.com).
 *
 * ====================================================================
 *
 *   File: csha256.cxx
 *
 * Author: $author$
 *   Date: 7/29/2009
 *
 * OpenSSL Project's implementation of SHA256 modified to be a C++ class
 * implementation.
 **********************************************************************
 */
#include "csha256.hxx"

#undef LROTATE32
#undef RROTATE32
#undef ROTATE

#define LROTATE32(a,n) (((a)<<(n&0x1f))|(((a)&0xffffffff)>>(32-(n&0x1f))))
#define RROTATE32(a,n) (((a)<<(32-(n&0x1f)))|(((a)&0xffffffff)>>(n&0x1f)))
#define ROTATE LROTATE32

/*
 * FIPS specification refers to right rotations, while our ROTATE macro
 * is left one. This is why you might notice that rotation coefficients
 * differ from those observed in FIPS document by 32-N...
 */
#define Sigma0(x)	(ROTATE((x),30) ^ ROTATE((x),19) ^ ROTATE((x),10))
#define Sigma1(x)	(ROTATE((x),26) ^ ROTATE((x),21) ^ ROTATE((x),7))
#define sigma0(x)	(ROTATE((x),25) ^ ROTATE((x),14) ^ ((x)>>3))
#define sigma1(x)	(ROTATE((x),15) ^ ROTATE((x),13) ^ ((x)>>10))

#define Ch(x,y,z)	(((x) & (y)) ^ ((~(x)) & (z)))
#define Maj(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define	ROUND_X_X(i,a,b,c,d,e,f,g,h) \
    T1 += h + Sigma1(e) + Ch(e,f,g) + K[i];	\
	h = Sigma0(a) + Maj(a,b,c);			\
	d += T1;	h += T1

#define	ROUND_00_15(i,a,b,c,d,e,f,g,h) \
    T1 = X[i]; ROUND_X_X(i,a,b,c,d,e,f,g,h)

#define	ROUND_16_63(i,a,b,c,d,e,f,g,h,X) \
    s0 = X[(i+1)&0x0f];	s0 = sigma0(s0);	\
	s1 = X[(i+14)&0x0f];	s1 = sigma1(s1);	\
	T1 = X[(i)&0x0f] += s0 + s1 + X[(i+9)&0x0f];	\
	ROUND_X_X(i,a,b,c,d,e,f,g,h)

/**
 **********************************************************************
 *  Class: cSHA256
 *
 * Author: $author$
 *   Date: 7/29/2009
 **********************************************************************
 */
UINT32 cSHA256::m_K[KONSTSIZE] = 
{
    0x428a2f98UL, 0x71374491UL, 0xb5c0fbcfUL, 0xe9b5dba5UL,
    0x3956c25bUL, 0x59f111f1UL, 0x923f82a4UL, 0xab1c5ed5UL,
    0xd807aa98UL, 0x12835b01UL, 0x243185beUL, 0x550c7dc3UL,
    0x72be5d74UL, 0x80deb1feUL, 0x9bdc06a7UL, 0xc19bf174UL,
    0xe49b69c1UL, 0xefbe4786UL, 0x0fc19dc6UL, 0x240ca1ccUL,
    0x2de92c6fUL, 0x4a7484aaUL, 0x5cb0a9dcUL, 0x76f988daUL,
    0x983e5152UL, 0xa831c66dUL, 0xb00327c8UL, 0xbf597fc7UL,
    0xc6e00bf3UL, 0xd5a79147UL, 0x06ca6351UL, 0x14292967UL,
    0x27b70a85UL, 0x2e1b2138UL, 0x4d2c6dfcUL, 0x53380d13UL,
    0x650a7354UL, 0x766a0abbUL, 0x81c2c92eUL, 0x92722c85UL,
    0xa2bfe8a1UL, 0xa81a664bUL, 0xc24b8b70UL, 0xc76c51a3UL,
    0xd192e819UL, 0xd6990624UL, 0xf40e3585UL, 0x106aa070UL,
    0x19a4c116UL, 0x1e376c08UL, 0x2748774cUL, 0x34b0bcb5UL,
    0x391c0cb3UL, 0x4ed8aa4aUL, 0x5b9cca4fUL, 0x682e6ff3UL,
    0x748f82eeUL, 0x78a5636fUL, 0x84c87814UL, 0x8cc70208UL,
    0x90befffaUL, 0xa4506cebUL, 0xbef9a3f7UL, 0xc67178f2UL
};

/**
 **********************************************************************
 * Function: cSHA256::Initial
 *
 *   Author: $author$
 *     Date: 7/29/2009
 *
 * Start SHA256 accumulation. Set bit count to 0 and buffer to mysterious
 * initialization constants.
 **********************************************************************
 */
void cSHA256::Initial() 
{
    m_A = 0x6a09e667UL;	
    m_B = 0xbb67ae85UL;
    m_C = 0x3c6ef372UL;	
    m_D = 0xa54ff53aUL;
    m_E = 0x510e527fUL;	
    m_F = 0x9b05688cUL;
    m_G = 0x1f83d9abUL;	
    m_H = 0x5be0cd19UL;
    m_l = 0;	
    m_h = 0;
}

/**
 **********************************************************************
 * Function: cSHA256::Final
 *
 *   Author: $author$
 *     Date: 7/29/2009
 *
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of bits processed, MSB-first)
 **********************************************************************
 */
void cSHA256::Final() 
{
    unsigned count;
    BYTE *p;

    /* Compute number of bytes mod 64 
     */
    count = (m_l >> 3) & 0x3F;

    /* Set the first char of padding to 0x80.  This is safe since there is
     * always at least one byte free 
     */
    p = m_in + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make 64 bytes 
     */
    count = 64 - 1 - count;

    /* Pad out to 56 mod 64 
     */
    if (count < 8) 
    {
	    /* Two lots of padding:  Pad the first block to 64 bytes 
         */
	    memset(p, 0, count);
	    Transform();

	    /* Now fill the next block with 56 bytes 
         */
	    memset(m_in, 0, 56);
    } 
    else 
    {
	    /* Pad block to 56 bytes 
         */
	    memset(p, 0, count - 8);
    }

    /* Append length in bits and transform 
     */
    U32ToMSB(m_in + 56, m_h);
    U32ToMSB(m_in + 60, m_l);
    Transform();

    U32ToMSB(m_hash, m_A);
    U32ToMSB(m_hash + 4, m_B);
    U32ToMSB(m_hash + 8, m_C);
    U32ToMSB(m_hash + 12, m_D);
    U32ToMSB(m_hash + 16, m_E);
    U32ToMSB(m_hash + 20, m_F);
    U32ToMSB(m_hash + 24, m_G);
    U32ToMSB(m_hash + 28, m_H);
    Initial();
}

/**
 **********************************************************************
 * Function: cSHA256::Update
 *
 *   Author: $author$
 *     Date: 7/29/2009
 *
 * Update context to reflect the concatenation of another buffer
 * of bytes.
 **********************************************************************
 */
void cSHA256::Update
(const BYTE* in, unsigned inlen) 
{
    UINT32 t;
    BYTE *p;

    /* Update bitcount 
     */
    t = m_l;

    if ((m_l = (t + (inlen << 3)) & 0xffffffff) < t)
        /* Carry from low to high 
         */
	    m_h++;

    m_h += (inlen >> 29);

    /* Bytes already in data 
     */
    t = ((t >> 3) & 0x3f);

    /* Handle any leading odd-sized chunks 
     */
    if (t) 
    {
        p = (m_in + t);
	    t = (64 - t);

	    if (inlen < t) 
        {
	        memcpy(p, in, inlen);
	        return;
	    }

	    memcpy(p, in, t);
	    Transform();
	    in += t;
	    inlen -= t;
    }

    /* Process data in 64-byte chunks 
     */
    while (inlen >= 64) 
    {
	    memcpy(m_in, in, 64);
	    Transform();
	    in += 64;
	    inlen -= 64;
    }

    /* Handle any remaining bytes of data. 
     */
    memcpy(m_in, in, inlen);
}

/**
 **********************************************************************
 * Function: cSHA256::Transform
 *
 *   Author: $author$
 *     Date: 7/29/2009
 *
 * The core of the SHA256 algorithm, this alters an existing hash to
 * reflect the addition of 16 longwords of new data. blocks
 * the data and converts bytes into longwords for this routine.
 **********************************************************************
 */
void cSHA256::Transform() 
{
    UINT32 a,b,c,d,e,f,g,h,s0,s1,T1;
    UINT32 X[16];
    UINT32* K;
    BYTE *p;
    unsigned i;
    
    for (p=m_in, i=0; i<16; i++, p+=4)
        X[i] = MSBToU32(p);

    K = m_K;
    a = m_A;
    b = m_B;
    c = m_C;
    d = m_D;
    e = m_E;
    f = m_F;
    g = m_G;
    h = m_H;
    s0 = s1 = T1 = 0;

    ROUND_00_15(0,a,b,c,d,e,f,g,h);
    ROUND_00_15(1,h,a,b,c,d,e,f,g);
    ROUND_00_15(2,g,h,a,b,c,d,e,f);
    ROUND_00_15(3,f,g,h,a,b,c,d,e);
    ROUND_00_15(4,e,f,g,h,a,b,c,d);
    ROUND_00_15(5,d,e,f,g,h,a,b,c);
    ROUND_00_15(6,c,d,e,f,g,h,a,b);
    ROUND_00_15(7,b,c,d,e,f,g,h,a);
    ROUND_00_15(8,a,b,c,d,e,f,g,h);
    ROUND_00_15(9,h,a,b,c,d,e,f,g);
    ROUND_00_15(10,g,h,a,b,c,d,e,f);
    ROUND_00_15(11,f,g,h,a,b,c,d,e);
    ROUND_00_15(12,e,f,g,h,a,b,c,d);
    ROUND_00_15(13,d,e,f,g,h,a,b,c);
    ROUND_00_15(14,c,d,e,f,g,h,a,b);
    ROUND_00_15(15,b,c,d,e,f,g,h,a);

    for (i=16; i<64; i+=8)
    {
        ROUND_16_63(i+0,a,b,c,d,e,f,g,h,X);
        ROUND_16_63(i+1,h,a,b,c,d,e,f,g,X);
        ROUND_16_63(i+2,g,h,a,b,c,d,e,f,X);
        ROUND_16_63(i+3,f,g,h,a,b,c,d,e,X);
        ROUND_16_63(i+4,e,f,g,h,a,b,c,d,X);
        ROUND_16_63(i+5,d,e,f,g,h,a,b,c,X);
        ROUND_16_63(i+6,c,d,e,f,g,h,a,b,X);
        ROUND_16_63(i+7,b,c,d,e,f,g,h,a,X);
    }

    m_A += a;
    m_B += b;
    m_C += c;
    m_D += d;
    m_E += e;
    m_F += f;
    m_G += g;
    m_H += h;
}
