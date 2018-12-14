/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: crc4.cxx
 *
 * Author: $author$
 *   Date: 1/11/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "crc4.hxx"

/**
 **********************************************************************
 *  Class: cRC4
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cRC4::Initialize
 *
 *   Author: $author$
 *     Date: 1/11/2005
 **********************************************************************
 */
int cRC4::Initialize
(const BYTE *key, int keylen,
 const BYTE *iv, int ivlen,
 BYTE padding) 
{
    int i;
	unsigned j,k;
	BYTE t;

    if (iv && ivlen)
        return -e_ERROR_INVALID_PARAMETER;

    if (0 > keylen)
        keylen = strlen((const char*)key);

	m_x=0;
	m_y=0;
	i=0;
	j=0;

	for (k=0; k<256; k++)
		m_data[k]=k;

	for (k=0; k<256; k++)
	{
		t = m_data[k];
		j = (key[i] + t + j) & 0xff;

		if (++i >= keylen) 
            i = 0;

		m_data[k] = m_data[j];
		m_data[j] = t;
	}
    return keylen;
}
/**
 **********************************************************************
 * Function: cRC4::Encrypt
 *
 *   Author: $author$
 *     Date: 1/11/2005
 **********************************************************************
 */
int cRC4::Encrypt
(BYTE *out, int outsize, const BYTE *in, int inlen) 
{
    int outlen;
    BYTE t;

    if (0 > inlen)
        inlen = strlen((const char*)in);

    for (outlen=0; outlen<inlen; outlen++)
    {
        m_y += (t = m_data[++m_x]);
        m_data[m_x] = m_data[m_y];
        m_data[m_y] = t;
        out[outlen] = in[outlen]^m_data[(m_data[m_x]+t)&255];
    }
    return outlen;
}
/**
 **********************************************************************
 * Function: cRC4::Decrypt
 *
 *   Author: $author$
 *     Date: 1/11/2005
 **********************************************************************
 */
int cRC4::Decrypt
(BYTE *out, int outsize, const BYTE *in, int inlen) 
{
    int outlen;
    BYTE t;

    for (outlen=0; outlen<inlen; outlen++)
    {
        m_y += (t = m_data[++m_x]);
        m_data[m_x] = m_data[m_y];
        m_data[m_y] = t;
        out[outlen] = in[outlen]^m_data[(m_data[m_x]+t)&255];
    }
    return outlen;
}
