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
 *   File: csslclientkey.hxx
 *
 * Author: $author$
 *   Date: 2/26/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCLIENTKEY_HXX
#define _CSSLCLIENTKEY_HXX

#include "csslkey.hxx"

/**
 **********************************************************************
 *  Class: cSSLClientKey
 *
 * Author: $author$
 *   Date: 2/26/2005
 **********************************************************************
 */
class cSSLClientKey
: public cSSLKey
{
public:
    typedef cSSLKey cIs;

    /**
     **********************************************************************
     * Constructor: cSSLClientKey
     *
     *      Author: $author$
     *        Date: 2/26/2005
     **********************************************************************
     */
    cSSLClientKey() 
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
        int length, keysize, size;

        if (0 < (keysize = (size = cIs::Set
            (keyblock, secret, 
             client_hello, server_hello, cipher_type))))

        if (cipher_type.GetIsExportable())
        {
            const cSSLHelloHeader &client_header = client_hello.m_header;
            const cSSLHelloHeader &server_header = server_hello.m_header;
            const cSSLRandom &client_random = client_header.m_random;
            const cSSLRandom &server_random = server_header.m_random;
            cHashStream md5_stream(md5);

            if (0 <= (length = md5_stream.Initialize()))
            if (0 < (length = Write(md5_stream)))
            if (0 < (length = client_random.Write(md5_stream)))
            if (0 < (length = server_random.Write(md5_stream)))
            if (0 < (length = Read(md5_stream)))
            {
            }
        }
        return size;
    }
};

#endif /* _CSSLCLIENTKEY_HXX */