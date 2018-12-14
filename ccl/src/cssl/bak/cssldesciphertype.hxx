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
 *   File: cssldesciphertype.hxx
 *
 * Author: $author$
 *   Date: 1/24/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLDESCIPHERTYPE_HXX
#define _CSSLDESCIPHERTYPE_HXX

#include "csslciphertype.hxx"
#include "cdes.hxx"

/**
 **********************************************************************
 *  Class: cSSLDES3CipherType
 *
 * Author: $author$
 *   Date: 1/24/2005
 **********************************************************************
 */
class cSSLDES3CipherType
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
        e_ALGORITHM = cCipherAlgorithm::e_DES3,
        e_KEYSIZE   = cDES3::e_KEYSIZE,
        e_IVSIZE    = cDES3::e_IVSIZE
    };

    cDES3 m_read_des3, m_write_des3;

    /**
     **********************************************************************
     * Constructor: cSSLDES3CipherType
     *
     *      Author: $author$
     *        Date: 1/24/2005
     **********************************************************************
     */
    cSSLDES3CipherType() 
    : cIs(e_ALGORITHM, e_KEYSIZE, e_IVSIZE)
    {
        m_read_cipher = &m_read_des3;
        m_write_cipher = &m_write_des3;
    }
};

/**
 **********************************************************************
 *  Class: cSSLDESCipherType
 *
 * Author: $author$
 *   Date: 2/13/2005
 **********************************************************************
 */
class cSSLDESCipherType
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
        e_ALGORITHM = cCipherAlgorithm::e_DES,
        e_KEYSIZE   = cDES::e_KEYSIZE,
        e_IVSIZE    = cDES::e_IVSIZE
    };

    cDES m_read_des, m_write_des;

    /**
     **********************************************************************
     * Constructor: cSSLDESCipherType
     *
     *      Author: $author$
     *        Date: 2/13/2005
     **********************************************************************
     */
    cSSLDESCipherType
    (int keysize=e_KEYSIZE, bool is_exportable=false) 
    : cIs(e_ALGORITHM, keysize, e_IVSIZE, is_exportable)
    {
        m_read_cipher = &m_read_des;
        m_write_cipher = &m_write_des;
    }
};

/**
 **********************************************************************
 *  Class: cSSLExportDESCipherType
 *
 * Author: $author$
 *   Date: 2/13/2005
 **********************************************************************
 */
class cSSLExportDESCipherType
: public cSSLDESCipherType
{
public:
    typedef cSSLDESCipherType cIs;

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
     * Constructor: cSSLExportDESCipherType
     *
     *      Author: $author$
     *        Date: 2/13/2005
     **********************************************************************
     */
    cSSLExportDESCipherType() 
    : cIs(e_KEYSIZE, true)
    {
    }
};

#endif /* _CSSLDESCIPHERTYPE_HXX */