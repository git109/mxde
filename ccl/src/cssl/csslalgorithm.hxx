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
 *   File: csslalgorithm.hxx
 *
 * Author: $author$
 *   Date: 1/13/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLALGORITHM_HXX
#define _CSSLALGORITHM_HXX

/**
 **********************************************************************
 *  Class: cSSLSignatureAlgorithm
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
class cSSLSignatureAlgorithm
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/13/2005
     **********************************************************************
     */
    enum
    {
        e_NONE = -1,
        e_FIRST,

        e_ANONYMOUS = e_FIRST, 
        e_RSA, 
        e_DSA,

        e_ALL,
        e_LAST = e_ALL-1
    };
};

/**
 **********************************************************************
 *  Class: cSSLSignatureType
 *
 * Author: $author$
 *   Date: 1/23/2005
 **********************************************************************
 */
class cSSLSignatureType
{
public:
    /**
     **********************************************************************
     * Function: GetAlgorithm
     *
     *   Author: $author$
     *     Date: 1/23/2005
     **********************************************************************
     */
    virtual int GetAlgorithm() const 
    {
        int algorithm = cSSLSignatureAlgorithm::e_NONE;
        return algorithm;
    }
};

/**
 **********************************************************************
 *  Class: cSSLKeyExchangeAlgorithm
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
class cSSLKeyExchangeAlgorithm
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/13/2005
     **********************************************************************
     */
    enum
    {
        e_NONE = -1,
        e_FIRST,

        e_RSA = e_FIRST, 
        e_DH, 
        e_FORTEZZA,

        e_ALL,
        e_LAST = e_ALL-1
    };
};

/**
 **********************************************************************
 *  Class: cSSLCipherAlgorithm
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
class cSSLCipherAlgorithm
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/13/2005
     **********************************************************************
     */
    enum
    {
        e_NONE = -1,
        e_FIRST,

        e_RC4 = e_FIRST,
        e_RC2, 
        e_DES, 
        e_DES3, 
        e_DES40, 
        e_FORTEZZA,

        e_ALL,
        e_LAST = e_ALL-1
    };
};

/**
 **********************************************************************
 *  Class: cSSLHashAlgorithm
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
class cSSLHashAlgorithm
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/13/2005
     **********************************************************************
     */
    enum
    {
        e_NONE = -1,
        e_FIRST,

        e_MD5 = e_FIRST, 
        e_SHA1,

        e_ALL,
        e_LAST = e_ALL-1
    };
};

#endif /* _CSSLALGORITHM_HXX */