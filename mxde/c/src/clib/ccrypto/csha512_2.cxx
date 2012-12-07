/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: csha512.cxx
 *
 * Author: $author$
 *   Date: 11/21/2009
 **********************************************************************
 */
#include "csha512.hxx"

#undef U64
#undef LROTATE64
#undef RROTATE64
#undef ROTATE

#define U64(x) x##ULL

#define LROTATE64(a,n) (((a)<<(n&0x3f)) | (((a)&0xffffffffffffffff)>>(64-(n&0x3f))))
#define RROTATE64(a,n) (((a)<<(64-(n&0x3f))) | (((a)&0xffffffffffffffff)>>(n&0x3f)))
#define ROTATE LROTATE64
#define ROTR RROTATE64

#define UINTbits UINT64
#define UbitsMASK 0xffffffffffffffff
#define UbitsToMSB U64ToMSB
#define MSBToUbits MSBToU64

#if defined(ROTR) 
#define Sigma0(x)	(ROTR((x),28) ^ ROTR((x),34) ^ ROTR((x),39))
#define Sigma1(x)	(ROTR((x),14) ^ ROTR((x),18) ^ ROTR((x),41))
#define sigma0(x)	(ROTR((x),1)  ^ ROTR((x),8)  ^ ((x)>>7))
#define sigma1(x)	(ROTR((x),19) ^ ROTR((x),61) ^ ((x)>>6))

#define Ch(x,y,z)	(((x) & (y)) ^ ((~(x)) & (z)))
#define Maj(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define	ROUND_X_X(i,a,b,c,d,e,f,g,h)		do {	\
	T1 += h + Sigma1(e) + Ch(e,f,g) + K[i];	\
	h = Sigma0(a) + Maj(a,b,c);			\
	d += T1;	h += T1;		} while (0)

#define	ROUND_00_15(i,a,b,c,d,e,f,g,h)		do {	\
	T1 = X[i]; ROUND_X_X(i,a,b,c,d,e,f,g,h);		} while (0)

#define	ROUND_16_KONSTSIZE(i,a,b,c,d,e,f,g,h,X)	do {	\
	s0 = X[(i+1)&0x0f];	s0 = sigma0(s0);	\
	s1 = X[(i+14)&0x0f];	s1 = sigma1(s1);	\
	T1 = X[(i)&0x0f] += s0 + s1 + X[(i+9)&0x0f];	\
	ROUND_X_X(i,a,b,c,d,e,f,g,h);		} while (0)
#else /* defined(ROTR) */
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

#define	ROUND_16_KONSTSIZE(i,a,b,c,d,e,f,g,h,X) \
    s0 = X[(i+1)&0x0f];	s0 = sigma0(s0);	\
	s1 = X[(i+14)&0x0f];	s1 = sigma1(s1);	\
	T1 = X[(i)&0x0f] += s0 + s1 + X[(i+9)&0x0f];	\
	ROUND_X_X(i,a,b,c,d,e,f,g,h)
#endif /* defined(ROTR) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cSHA512
 *
 * Author: $author$
 *   Date: 11/21/2009
 **********************************************************************
 */
UINT64 cSHA512::m_K[KONSTSIZE] = 
{
    U64(0x428a2f98d728ae22),U64(0x7137449123ef65cd),
    U64(0xb5c0fbcfec4d3b2f),U64(0xe9b5dba58189dbbc),
    U64(0x3956c25bf348b538),U64(0x59f111f1b605d019),
    U64(0x923f82a4af194f9b),U64(0xab1c5ed5da6d8118),
    U64(0xd807aa98a3030242),U64(0x12835b0145706fbe),
    U64(0x243185be4ee4b28c),U64(0x550c7dc3d5ffb4e2),
    U64(0x72be5d74f27b896f),U64(0x80deb1fe3b1696b1),
    U64(0x9bdc06a725c71235),U64(0xc19bf174cf692694),
    U64(0xe49b69c19ef14ad2),U64(0xefbe4786384f25e3),
    U64(0x0fc19dc68b8cd5b5),U64(0x240ca1cc77ac9c65),
    U64(0x2de92c6f592b0275),U64(0x4a7484aa6ea6e483),
    U64(0x5cb0a9dcbd41fbd4),U64(0x76f988da831153b5),
    U64(0x983e5152ee66dfab),U64(0xa831c66d2db43210),
    U64(0xb00327c898fb213f),U64(0xbf597fc7beef0ee4),
    U64(0xc6e00bf33da88fc2),U64(0xd5a79147930aa725),
    U64(0x06ca6351e003826f),U64(0x142929670a0e6e70),
    U64(0x27b70a8546d22ffc),U64(0x2e1b21385c26c926),
    U64(0x4d2c6dfc5ac42aed),U64(0x53380d139d95b3df),
    U64(0x650a73548baf63de),U64(0x766a0abb3c77b2a8),
    U64(0x81c2c92e47edaee6),U64(0x92722c851482353b),
    U64(0xa2bfe8a14cf10364),U64(0xa81a664bbc423001),
    U64(0xc24b8b70d0f89791),U64(0xc76c51a30654be30),
    U64(0xd192e819d6ef5218),U64(0xd69906245565a910),
    U64(0xf40e35855771202a),U64(0x106aa07032bbd1b8),
    U64(0x19a4c116b8d2d0c8),U64(0x1e376c085141ab53),
    U64(0x2748774cdf8eeb99),U64(0x34b0bcb5e19b48a8),
    U64(0x391c0cb3c5c95a63),U64(0x4ed8aa4ae3418acb),
    U64(0x5b9cca4f7763e373),U64(0x682e6ff3d6b2b8a3),
    U64(0x748f82ee5defb2fc),U64(0x78a5636f43172f60),
    U64(0x84c87814a1f0ab72),U64(0x8cc702081a6439ec),
    U64(0x90befffa23631e28),U64(0xa4506cebde82bde9),
    U64(0xbef9a3f7b2c67915),U64(0xc67178f2e372532b),
    U64(0xca273eceea26619c),U64(0xd186b8c721c0c207),
    U64(0xeada7dd6cde0eb1e),U64(0xf57d4f7fee6ed178),
    U64(0x06f067aa72176fba),U64(0x0a637dc5a2c898a6),
    U64(0x113f9804bef90dae),U64(0x1b710b35131c471b),
    U64(0x28db77f523047d84),U64(0x32caab7b40c72493),
    U64(0x3c9ebe0a15c9bebc),U64(0x431d67c49c100d4c),
    U64(0x4cc5d4becb3e42b6),U64(0x597f299cfc657e2a),
    U64(0x5fcb6fab3ad6faec),U64(0x6c44198c4a475817),
};

/**
 **********************************************************************
 * Function: cSHA512::Initial
 *
 *   Author: $author$
 *     Date: 11/21/2009
 *
 * Start accumulation. Set bit count to 0 and buffer to mysterious
 * initialization constants.
 **********************************************************************
 */
void cSHA512::Initial() 
{
    m_A = U64(0x6a09e667f3bcc908);	
    m_B = U64(0xbb67ae8584caa73b);
    m_C = U64(0x3c6ef372fe94f82b);	
    m_D = U64(0xa54ff53a5f1d36f1);
    m_E = U64(0x510e527fade682d1);	
    m_F = U64(0x9b05688c2b3e6c1f);
    m_G = U64(0x1f83d9abfb41bd6b);	
    m_H = U64(0x5be0cd19137e2179);
    m_l = 0;	
    m_h = 0;
#if defined(ROTATE) 
#else /* defined(ROTATE) */
        m_num=0; m_md_len=HASHSIZE;
#endif /* defined(ROTATE) */
}
/**
 **********************************************************************
 * Function: cSHA512::Final
 *
 *   Author: $author$
 *     Date: 11/21/2009
 *
 * Final wrapup - pad to BLOCKSIZE-byte boundary with the bit pattern 
 * 1 0* (BLOCKSIZE-bit count of bits processed, MSB-first)
 **********************************************************************
 */
void cSHA512::Final() 
{
#if defined(ROTATE) 
    unsigned count;
    BYTE *p;

    /* Compute number of bytes mod BLOCKSIZE 
     */
    count = (unsigned)((m_l >> 3) & (BLOCKSIZE-1));

    /* Set the first char of padding to 0x80.  This is safe since there is
     * always at least one byte free 
     */
    p = m_in + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make BLOCKSIZE bytes 
     */
    count = (BLOCKSIZE-1) - count;

    /* Pad out to (BLOCKSIZE-LENGTHSIZE) mod BLOCKSIZE 
     */
    if (count < LENGTHSIZE) 
    {
	    /* Two lots of padding:  Pad the first block to BLOCKSIZE bytes 
         */
	    memset(p, 0, count);
	    Transform();

	    /* Now fill the next block with BLOCKSIZE-LENGTHSIZE bytes 
         */
	    memset(m_in, 0, (BLOCKSIZE-LENGTHSIZE));
    } 
    else 
    {
	    /* Pad block to BLOCKSIZE-LENGTHSIZE bytes 
         */
	    memset(p, 0, count - LENGTHSIZE);
    }

    /* Append length in bits and transform 
     */
    UbitsToMSB(m_in + (BLOCKSIZE-LENGTHSIZE), m_h);
    UbitsToMSB(m_in + (BLOCKSIZE-LENGTHSIZE)+WORDSIZE, m_l);
    Transform();

    UbitsToMSB(m_hash, m_A);
    UbitsToMSB(m_hash + WORDSIZE, m_B);
    UbitsToMSB(m_hash + WORDSIZE*2, m_C);
    UbitsToMSB(m_hash + WORDSIZE*3, m_D);
    UbitsToMSB(m_hash + WORDSIZE*4, m_E);
    UbitsToMSB(m_hash + WORDSIZE*5, m_F);
    UbitsToMSB(m_hash + WORDSIZE*6, m_G);
    UbitsToMSB(m_hash + WORDSIZE*7, m_H);
    Initial();
#else /* defined(ROTATE) */
    unsigned char *md=m_hash;
	unsigned char *p=m_in;
	size_t n=m_num;

	p[n]=0x80;	/* There always is a room for one */
	n++;
	if (n > (BLOCKSIZE-16))
		memset (p+n,0,BLOCKSIZE-n), n=0,
        Transform();

	memset (p+n,0,BLOCKSIZE-16-n);
	
    UbitsToMSB(p + (BLOCKSIZE-LENGTHSIZE), m_h);
    UbitsToMSB(p + (BLOCKSIZE-LENGTHSIZE)+WORDSIZE, m_l);
    Transform();

    UbitsToMSB(md, m_A);
    UbitsToMSB(md + WORDSIZE, m_B);
    UbitsToMSB(md + WORDSIZE*2, m_C);
    UbitsToMSB(md + WORDSIZE*3, m_D);
    UbitsToMSB(md + WORDSIZE*4, m_E);
    UbitsToMSB(md + WORDSIZE*5, m_F);
    UbitsToMSB(md + WORDSIZE*6, m_G);
    UbitsToMSB(md + WORDSIZE*7, m_H);
    Initial();
#endif /* defined(ROTATE) */
}
/**
 **********************************************************************
 * Function: cSHA512::Update
 *
 *   Author: $author$
 *     Date: 11/21/2009
 **********************************************************************
 */
void cSHA512::Update
(const BYTE* in, unsigned inlen) 
{
#if defined(ROTATE) 
    unsigned len;
    UINTbits t;
    BYTE *p;

    /* Update bitcount 
     */
    t = m_l;

    if ((m_l = (t + (inlen << 3)) & UbitsMASK) < t)
        /* Carry from low to high 
         */
	    m_h++;

    m_h += (((UINTbits)inlen) >> ((LENGTHSIZE<<2)-3));

    /* Bytes already in data 
     */
    len = (unsigned)((t >> 3) & (BLOCKSIZE-1));

    /* Handle any leading odd-sized chunks 
     */
    if (len) 
    {
        p = (m_in + len);
	    len = (BLOCKSIZE - len);

	    if (inlen < len) 
        {
	        memcpy(p, in, inlen);
	        return;
	    }

	    memcpy(p, in, len);
	    Transform();
	    in += len;
	    inlen -= len;
    }

    /* Process data in BLOCKSIZE-byte chunks 
     */
    while (inlen >= BLOCKSIZE) 
    {
	    memcpy(m_in, in, BLOCKSIZE);
	    Transform();
	    in += BLOCKSIZE;
	    inlen -= BLOCKSIZE;
    }

    /* Handle any remaining bytes of data. 
     */
    memcpy(m_in, in, inlen);
#else /* defined(ROTATE) */
    const void *_data = in;
    unsigned len = inlen;
	UINT64	l;
	unsigned char  *p=m_in;
	const unsigned char *data=(const unsigned char *)_data;

	if (len==0) return;

	l = (m_l+(((UINT64)len)<<3))&U64(0xffffffffffffffff);
	if (l < m_l)		m_h++;
	if (sizeof(len)>=8)	m_h+=(((UINT64)len)>>61);
	m_l=l;

	if (m_num != 0)
		{
		unsigned n = BLOCKSIZE - m_num;

		if (len < n)
			{
			memcpy (p+m_num,data,len), m_num += len;
			return;
			}
		else	{
			memcpy (p+m_num,data,n), m_num = 0;
			len-=n, data+=n;
			Transform();
			}
		}
		
    while (len >= BLOCKSIZE) 
    {
	    memcpy(p, data, BLOCKSIZE);
	    Transform();
	    len -= BLOCKSIZE;
	    data += BLOCKSIZE;
    }
    
	if (len != 0)	
	    memcpy (p,data,len), m_num = len;
	    
#endif /* defined(ROTATE) */
}
/**
 **********************************************************************
 * Function: cSHA512::Transform
 *
 *   Author: $author$
 *     Date: 11/21/2009
 *
 * The core of the algorithm, this alters an existing hash to
 * reflect the addition of 16 WORDSIZE words of new data. blocks
 * the data and converts bytes into WORDSIZE words for this routine.
 **********************************************************************
 */
void cSHA512::Transform() 
{
#if defined(ROTATE) 
    UINTbits a,b,c,d,e,f,g,h,s0,s1,T1;
    UINTbits X[16];
    UINTbits* K;
    BYTE *p;
    unsigned i;
    
    for (p=m_in, i=0; i<16; i++, p+=WORDSIZE)
        X[i] = MSBToUbits(p);

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

    for (i=16; i<KONSTSIZE; i+=8)
    {
        ROUND_16_KONSTSIZE(i+0,a,b,c,d,e,f,g,h,X);
        ROUND_16_KONSTSIZE(i+1,h,a,b,c,d,e,f,g,X);
        ROUND_16_KONSTSIZE(i+2,g,h,a,b,c,d,e,f,X);
        ROUND_16_KONSTSIZE(i+3,f,g,h,a,b,c,d,e,X);
        ROUND_16_KONSTSIZE(i+4,e,f,g,h,a,b,c,d,X);
        ROUND_16_KONSTSIZE(i+5,d,e,f,g,h,a,b,c,X);
        ROUND_16_KONSTSIZE(i+6,c,d,e,f,g,h,a,b,X);
        ROUND_16_KONSTSIZE(i+7,b,c,d,e,f,g,h,a,X);
    }

    m_A += a;
    m_B += b;
    m_C += c;
    m_D += d;
    m_E += e;
    m_F += f;
    m_G += g;
    m_H += h;
#else /* defined(ROTATE) */
	UINT64 *K = m_K;
	BYTE *W = m_in;
	UINT64	a,b,c,d,e,f,g,h,s0,s1,T1;
	UINT64	X[16];
	unsigned i;

    a = m_A;
    b = m_B;
    c = m_C;
    d = m_D;
    e = m_E;
    f = m_F;
    g = m_G;
    h = m_H;
    
    for (i=0; i<16; i++, W+=WORDSIZE)
        X[i] = MSBToUbits(W);

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
	
	for (i=16;i<KONSTSIZE;i+=8)
		{
		ROUND_16_KONSTSIZE(i+0,a,b,c,d,e,f,g,h,X);
		ROUND_16_KONSTSIZE(i+1,h,a,b,c,d,e,f,g,X);
		ROUND_16_KONSTSIZE(i+2,g,h,a,b,c,d,e,f,X);
		ROUND_16_KONSTSIZE(i+3,f,g,h,a,b,c,d,e,X);
		ROUND_16_KONSTSIZE(i+4,e,f,g,h,a,b,c,d,X);
		ROUND_16_KONSTSIZE(i+5,d,e,f,g,h,a,b,c,X);
		ROUND_16_KONSTSIZE(i+6,c,d,e,f,g,h,a,b,X);
		ROUND_16_KONSTSIZE(i+7,b,c,d,e,f,g,h,a,X);
		}

    m_A += a;
    m_B += b;
    m_C += c;
    m_D += d;
    m_E += e;
    m_F += f;
    m_G += g;
    m_H += h;
#endif /* defined(ROTATE) */
}

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
