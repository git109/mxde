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
 *   File: csslserverkey.hxx
 *
 * Author: $author$
 *   Date: 2/26/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLSERVERKEY_HXX
#define _CSSLSERVERKEY_HXX

#include "csslkey.hxx"

/**
 **********************************************************************
 *  Class: cSSLServerKey
 *
 * Author: $author$
 *   Date: 2/26/2005
 **********************************************************************
 */
class cSSLServerKey
: public cSSLKey
{
public:
    typedef cSSLKey cIs;

    /**
     **********************************************************************
     * Constructor: cSSLServerKey
     *
     *      Author: $author$
     *        Date: 2/26/2005
     **********************************************************************
     */
    cSSLServerKey() 
    {
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/26/2005
     **********************************************************************
     */
    int Set
    (cSSLKeyBlock &keyblock,
     const cSSLMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello,
     const cSSLCipherType &cipher_type,
     cHash &md5) 
    {
        int size=-1;
        return size;
    }
};

#endif /* _CSSLSERVERKEY_HXX */