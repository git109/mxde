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
 *   File: csslkeyblock.hxx
 *
 * Author: $author$
 *   Date: 2/12/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLKEYBLOCK_HXX
#define _CSSLKEYBLOCK_HXX

#include "platform.h"
#include "csslmastersecret.hxx"
#include "chashstream.hxx"
#include "cmd5.hxx"
#include "csha1.hxx"

/**
 **********************************************************************
 *  Class: cSSLKeyBlock
 *
 * Author: $author$
 *   Date: 2/12/2005
 **********************************************************************
 */
class cSSLKeyBlock
{
public:
    cHash &m_md5, &m_sha1;
    cHashStream m_md5_stream, m_sha1_stream;

    int m_inlen, m_tell;
    BYTE m_in, m_hash[cSHA1::e_HASHSIZE], m_out[cMD5::e_HASHSIZE];

    /**
     **********************************************************************
     * Constructor: cSSLKeyBlock
     *
     *      Author: $author$
     *        Date: 2/12/2005
     **********************************************************************
     */
    cSSLKeyBlock(cHash &md5, cHash &sha1) 
    : m_md5(md5),
      m_sha1(sha1),
      m_md5_stream(md5),
      m_sha1_stream(sha1)
    {
        Initialize();
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Initialize()
    {
        m_tell = sizeof(m_out);
        m_inlen = 1;
        m_in = 'A';
        return 0;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Read
    (BYTE *buffer, int length,
     const cSSLMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello) 
    {
        int count, left, pos, size;

        for (pos=0, left=length; 
             left; left-=size, pos+=size, m_tell+=size)
        {
            if (sizeof(m_out) <= m_tell)
            {
                if (0 > (count = Fill
                    (secret, client_hello, server_hello)))
                    return count;

                m_tell = 0;
                m_inlen++;
                m_in++;
            }

            if (left < (size = sizeof(m_out)-m_tell))
                size = left;

            memcpy(buffer+pos, m_out+m_tell, size);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int Fill
    (const cSSLMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello)
    {
        int size;

        if (0 < (size = SHA1
            (m_hash, sizeof(m_hash), m_in, m_inlen, 
             secret, client_hello, server_hello)))
            size = MD5
            (m_out, sizeof(m_out), 
             m_hash, sizeof(m_hash), secret);

        return size;
    }
    /**
     **********************************************************************
     * Function: SHA1
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int SHA1
    (BYTE *out, int outsize, 
     BYTE in, int insize,
     const cSSLMasterSecret &secret,
     const cSSLClientHello &client_hello,
     const cSSLServerHello &server_hello)
    {
        int size;

        if (0 <= (size = m_sha1.Initialize()))
        if (0 < (size = m_sha1.HashFill(in, insize)))
        if (0 < (size = secret.Write(m_sha1_stream)))
        if (0 < (size = client_hello.m_header.m_random.Write(m_sha1_stream)))
        if (0 < (size = server_hello.m_header.m_random.Write(m_sha1_stream)))
            size = m_sha1.Finalize(out, outsize);

        return size;
    }
    /**
     **********************************************************************
     * Function: MD5
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    int MD5
    (BYTE *out, int outsize, 
     BYTE *in, int insize,
     const cSSLMasterSecret &secret)
    {
        int size;

        if (0 <= (size = m_md5.Initialize()))
        if (0 < (size = secret.Write(m_md5_stream)))
        if (0 < (size = m_md5.Hash(in, insize)))
            size = m_md5.Finalize(out, outsize);

        return size;
    }
};

#endif /* _CSSLKEYBLOCK_HXX */
