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
 *   File: csslhandshake.hxx
 *
 * Author: $author$
 *   Date: 1/16/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLHANDSHAKE_HXX
#define _CSSLHANDSHAKE_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "cbytebuffer.hxx"
#include "csslclientkeyexchange.hxx"
#include "csslclienthello.hxx"
#include "csslserverhello.hxx"
#include "csslserverhellodone.hxx"
#include "csslcertificate.hxx"
#include "csslcertificatechain.hxx"
#include "cssltofrom.hxx"

/**
 **********************************************************************
 *  Class: cSSLHandshake
 *
 * Author: $author$
 *   Date: 1/16/2005
 **********************************************************************
 */
class cSSLHandshake
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/16/2005
     **********************************************************************
     */
    enum
    {
        e_NONE                = -1,
        e_HELLO_REQUEST       = 0,
        e_CLIENT_HELLO        = 1,
        e_SERVER_HELLO        = 2,
        e_CERTIFICATE         = 11,
        e_SERVER_KEY_EXCHANGE = 12,
        e_CERTIFICATE_REQUEST = 13,
        e_SERVER_HELLO_DONE   = 14,
        e_CERTIFICATE_VERIFY  = 15,
        e_CLIENT_KEY_EXCHANGE = 16,
        e_FINISHED            = 20
    };

    uint8 m_type;
    uint24 m_sizeof;
    cBYTEBuffer m_buffer;
    cSSLClientHello m_client_hello;
    cSSLServerHello m_server_hello;
    cSSLServerHelloDone m_server_hello_done;
    cSSLCertificateChain m_certificate_chain;
    cSSLClientKeyExchange m_client_key_exchange;

    /**
     **********************************************************************
     * Constructor: cSSLHandshake
     *
     *      Author: $author$
     *        Date: 1/16/2005
     **********************************************************************
     */
    cSSLHandshake()
    : m_type(e_NONE)
    {
        fromint(m_sizeof, 0);
    }
    /**
     **********************************************************************
     * Constructor: cSSLHandshake
     *
     *      Author: $author$
     *        Date: 1/16/2005
     **********************************************************************
     */
    cSSLHandshake(const cSSLClientHello &client_hello)
    {
        eError error;
        int size;

        if (0 > (size = Set(client_hello)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/16/2005
     **********************************************************************
     */
    int Copy(const cSSLHandshake &handshake)
    {
        int size;

        if (&handshake == this)
            return size = Sizeof();

        m_type = handshake.m_type;
        fromint(m_sizeof, toint(handshake.m_sizeof));

        switch(m_type)
        {
        case e_CLIENT_HELLO:
            if (0 > (size = m_client_hello.Copy(handshake.m_client_hello)))
                return size;
            break;

        default:
            return size = -e_ERROR_INVALID_PARAMETER_TYPE;
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/16/2005
     **********************************************************************
     */
    int Set(const cSSLClientHello &client_hello)
    {
        int size;

        if (0 > (size = m_client_hello.Copy(client_hello)))
            return size;

        fromint(m_sizeof, size);
        m_type = e_CLIENT_HELLO;
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    int Set(const cSSLClientKeyExchange &key_exchange)
    {
        int size;

        if (0 > (size = m_client_key_exchange.Copy(key_exchange)))
            return size;

        fromint(m_sizeof, size);
        m_type = e_CLIENT_KEY_EXCHANGE;
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/16/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size,length;
        BYTE *buffer;

        if (0 > (size = stream.Getb()))
            return size;

        m_type = size;

        if (0 > (size = stream.ReadUInt24MSB(m_sizeof)))
            return size;

        if (0 > (size = m_buffer.SetLength(toint(m_sizeof))))
            return size;

        length = size;

        if (0 > (size = m_buffer.Seek(0)))
            return size;

        if (!(buffer = m_buffer.GetWriteBuffer()))
            return size = -e_ERROR_FAILED;

        if ((size = stream.Read(buffer, length)) < length)
        if (size > 0)
            return size = -e_ERROR_RETURN_SIZE_UNDER;
        else return size;

        switch(m_type)
        {
        case e_CLIENT_HELLO:
            if (0 > (size = m_client_hello.Read(m_buffer)))
                return size;
            break;

        case e_SERVER_HELLO:
            if (0 > (size = m_server_hello.Read(m_buffer)))
                return size;
            break;

        case e_SERVER_HELLO_DONE:
            if (0 > (size = m_server_hello_done.Read(m_buffer)))
                return size;
            break;

        case e_CERTIFICATE:
            if (0 > (size = m_certificate_chain.Read(m_buffer)))
                return size;
            break;

        default:
            return size = -e_ERROR_INVALID_RETURN_TYPE;
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/16/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;

        if (0 > (size = stream.Putb(m_type)))
            return size;

        if (0 > (size = stream.WriteUInt24MSB(m_sizeof)))
            return size;

        switch(m_type)
        {
        case e_CLIENT_HELLO:
            if (0 > (size = m_client_hello.Write(stream)))
                return size;
            break;

        case e_SERVER_HELLO:
            if (0 > (size = m_server_hello.Write(stream)))
                return size;
            break;

        case e_SERVER_HELLO_DONE:
            if (0 > (size = m_server_hello_done.Write(stream)))
                return size;
            break;

        case e_CERTIFICATE:
            if (0 > (size = m_certificate_chain.Write(stream)))
                return size;
            break;

        case e_CLIENT_KEY_EXCHANGE:
            if (0 > (size = m_client_key_exchange.Write(stream)))
                return size;
            break;

        default:
            return size = -e_ERROR_INVALID_PARAMETER_TYPE;
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/16/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_type)+sizeof(m_sizeof)+toint(m_sizeof);
        return size;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 1/20/2005
     **********************************************************************
     */
    inline uint8 GetType() const
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetClientHello
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    inline cSSLClientHello& GetClientHello() 
    {
        return m_client_hello;
    }
    /**
     **********************************************************************
     * Function: GetServerHello
     *
     *   Author: $author$
     *     Date: 1/19/2005
     **********************************************************************
     */
    inline cSSLServerHello& GetServerHello() 
    {
        return m_server_hello;
    }
    /**
     **********************************************************************
     * Function: GetCertificateChain
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    inline cSSLCertificateChain& GetCertificateChain() 
    {
        return m_certificate_chain;
    }
    /**
     **********************************************************************
     * Function: GetClientKeyExchange
     *
     *   Author: $author$
     *     Date: 2/8/2005
     **********************************************************************
     */
    inline cSSLClientKeyExchange& GetClientKeyExchange() 
    {
        return m_client_key_exchange;
    }
};

#endif /* _CSSLHANDSHAKE_HXX */
