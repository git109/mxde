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
 *   File: crc4.hxx
 *
 * Author: $author$
 *   Date: 1/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CRC4_HXX
#define _CRC4_HXX

#include "ccipher.hxx"

/**
 **********************************************************************
 *  Class: cRC4
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */
class cRC4
: public cCipher
{
public:
    typedef cCipher cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/11/2005
     **********************************************************************
     */
    enum
    {
        e_BLOCKSIZE = 1,
        e_KEYMIN    = 8,
        e_KEYMAX    = 256,
        e_KEYSIZE   = 128,
        e_IVMIN     = 0,
        e_IVMAX     = 0,
        e_IVSIZE    = 0
    };

    /**
     **********************************************************************
     * Constructor: cRC4
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cRC4() 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     BYTE padding=0);
    /**
     **********************************************************************
     * Function: Encrypt
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int Encrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1);
    /**
     **********************************************************************
     * Function: Decrypt
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int Decrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1);

protected:

	BYTE m_x,m_y,m_data[256];
};

#endif /* _CRC4_HXX */