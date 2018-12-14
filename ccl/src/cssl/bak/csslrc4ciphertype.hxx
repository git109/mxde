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
 *   File: csslrc4ciphertype.hxx
 *
 * Author: $author$
 *   Date: 1/24/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLRC4CIPHERTYPE_HXX
#define _CSSLRC4CIPHERTYPE_HXX

#include "csslciphertype.hxx"
#include "crc4.hxx"

/**
 **********************************************************************
 *  Class: cSSLRC4CipherType
 *
 * Author: $author$
 *   Date: 1/24/2005
 **********************************************************************
 */
class cSSLRC4CipherType
: public cSSLCipherType
{
public:
    typedef cSSLCipherType cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/13/2005
     **********************************************************************
     */
    enum
    {
        e_ALGORITHM = cCipherAlgorithm::e_RC4,
        e_KEYSIZE   = 16,
        e_IVSIZE    = 0
    };

    cRC4 m_read_rc4, m_write_rc4;

    /**
     **********************************************************************
     * Constructor: cSSLRC4CipherType
     *
     *      Author: $author$
     *        Date: 1/24/2005
     **********************************************************************
     */
    cSSLRC4CipherType
    (int keysize=e_KEYSIZE, bool is_exportable=false)
    : cIs(e_ALGORITHM, keysize, e_IVSIZE, is_exportable)
    {
        m_read_cipher = &m_read_rc4;
        m_write_cipher = &m_write_rc4;
    }
};

/**
 **********************************************************************
 *  Class: cSSLExportRC4CipherType
 *
 * Author: $author$
 *   Date: 2/13/2005
 **********************************************************************
 */
class cSSLExportRC4CipherType
: public cSSLRC4CipherType
{
public:
    typedef cSSLRC4CipherType cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/13/2005
     **********************************************************************
     */
    enum
    {
        e_KEYSIZE   = 5,
    };

    /**
     **********************************************************************
     * Constructor: cSSLExportRC4CipherType
     *
     *      Author: $author$
     *        Date: 2/13/2005
     **********************************************************************
     */
    cSSLExportRC4CipherType() 
    : cIs(e_KEYSIZE, true)
    {
    }
};

#endif /* _CSSLRC4CIPHERTYPE_HXX */