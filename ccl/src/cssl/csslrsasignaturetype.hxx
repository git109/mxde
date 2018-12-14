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
 *   File: csslrsasignaturetype.hxx
 *
 * Author: $author$
 *   Date: 1/24/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLRSASIGNATURETYPE_HXX
#define _CSSLRSASIGNATURETYPE_HXX


#include "csslalgorithm.hxx"
/**
 **********************************************************************
 *  Class: cSSLRSASignatureType
 *
 * Author: $author$
 *   Date: 1/24/2005
 **********************************************************************
 */
class cSSLRSASignatureType
: public cSSLSignatureType
{
public:
    typedef cSSLSignatureType cIs;
    /**
     **********************************************************************
     * Constructor: cSSLRSASignatureType
     *
     *      Author: $author$
     *        Date: 1/24/2005
     **********************************************************************
     */
    cSSLRSASignatureType() 
    {
    }
    /**
     **********************************************************************
     * Function: GetAlgorithm
     *
     *   Author: $author$
     *     Date: 1/24/2005
     **********************************************************************
     */
    virtual int GetAlgorithm() const 
    {
        int algorithm = cSSLSignatureAlgorithm::e_RSA;
        return algorithm;
    }
};

#endif /* _CSSLRSASIGNATURETYPE_HXX */