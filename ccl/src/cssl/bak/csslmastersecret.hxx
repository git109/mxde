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
 *   File: csslmastersecret.hxx
 *
 * Author: $author$
 *   Date: 2/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLMASTERSECRET_HXX
#define _CSSLMASTERSECRET_HXX

#include "platform.h"
#include "chashstream.hxx"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLMasterSecret
 *
 * Author: $author$
 *   Date: 2/11/2005
 **********************************************************************
 */
class cSSLMasterSecret
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/11/2005
     **********************************************************************
     */
    enum
    {
        e_SIZE  = 48,
    };

    BYTE m_data[e_SIZE];

    /**
     **********************************************************************
     * Constructor: cSSLMasterSecret
     *
     *      Author: $author$
     *        Date: 2/11/2005
     **********************************************************************
     */
    cSSLMasterSecret() 
    {
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int Copy(const cSSLMasterSecret &secret)
    {
        int size = sizeof(m_data);

        if (&secret == this)
            return size;

        memcpy(m_data, secret.m_data, sizeof(m_data));
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int Set
    (const cSSLPreMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello,
     cHash &md5, cHash &sha1)
    {
        cHashStream md5_stream(md5), sha1_stream(sha1);
        int count, length, md5_size, sha1_size, size = -e_ERROR_FAILED;
        BYTE data[e_SIZE];

        length = 0;

        if (0 < (md5_size = md5.GetHashSize()))
        if (0 < (sha1_size = sha1.GetHashSize()))
        if (md5_size*3 <= sizeof(m_data))
        if (0 < (count = SHA1
            (data, sha1_size, 'A', 1, secret, 
             client_hello, server_hello, sha1_stream, sha1)))
        if (0 < (count = MD5
            (m_data, md5_size, 
             data, sha1_size, secret, md5_stream, md5)))
        if (0 < (count = SHA1
            (data, sha1_size, 'B', 2, secret, 
             client_hello, server_hello, sha1_stream, sha1)))
        if (0 < (count = MD5
            (m_data+(length+=md5_size), md5_size, 
             data, sha1_size, secret, md5_stream, md5)))
        if (0 < (count = SHA1
            (data, sha1_size, 'C', 3, secret, 
             client_hello, server_hello, sha1_stream, sha1)))
        if (0 < (count = MD5
            (m_data+(length+=md5_size), md5_size, 
             data, sha1_size, secret, md5_stream, md5)))
             size = sizeof(m_data);

        return size;
    }
    /**
     **********************************************************************
     * Function: SHA1
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int SHA1
    (BYTE out[], int outsize,
     BYTE in, int inlen,
     const cSSLPreMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello,
     cBYTEStream &sha1_stream, cHash &sha1)
    {
        int count, size = -e_ERROR_FAILED;

        if (0 <= (count = sha1.Initialize()))
        if (0 < (count = sha1.HashFill(in, inlen)))
        if (0 < (count = secret.Write(sha1_stream)))
        if (0 < (count = client_hello.m_header.m_random.Write(sha1_stream)))
        if (0 < (count = server_hello.m_header.m_random.Write(sha1_stream)))
        if (0 < (count = sha1.Finalize(out, outsize)))
            size = outsize;

        return size;
    }
    /**
     **********************************************************************
     * Function: MD5
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int MD5
    (BYTE out[], int outsize,
     BYTE in[], int inlen,
     const cSSLPreMasterSecret &secret,
     cBYTEStream &md5_stream, cHash &md5)
    {
        int count, size = -e_ERROR_FAILED;

        if (0 <= (count = md5.Initialize()))
        if (0 < (count = secret.Write(md5_stream)))
        if (0 < (count = md5.Hash(in, inlen)))
        if (0 < (count = md5.Finalize(out, outsize)))
            size = outsize;

        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size = stream.Read(m_data, sizeof(m_data));
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size = stream.Write(m_data, sizeof(m_data));
        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_data);
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 2/11/2005
     **********************************************************************
     */
    int operator != (const cSSLMasterSecret &secret) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLMASTERSECRET_HXX */
