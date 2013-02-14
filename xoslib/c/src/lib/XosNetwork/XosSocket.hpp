///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosSocket.hpp
///
/// Author: $author$
///   Date: 3/2/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSSOCKET_HPP
#define _XOSSOCKET_HPP

#include "XosPlatform_socket.hpp"
#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#define DEFAULT_XOS_SOCKET_BACKLOG 10

#if defined(WINDOWS) 
// Windows 
#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosSocketImplement
///
///  Author: $author$
///    Date: 1/31/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosSocketImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosSocketExtend
///
///  Author: $author$
///    Date: 1/31/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosSocketExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosSocket
///
/// Author: $author$
///   Date: 1/31/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosSocket
: virtual public XosSocketImplement,
  public XosSocketExtend
{
public:
    typedef XosSocketImplement Implements;
    typedef XosSocketExtend Extends;

    SOCKET_ADDR_FAMILY m_family;
    SOCKET_TYPE m_type;
    SOCKET_PROTOCOL m_protocol;
    SOCKET_ADDR m_addr;
    SOCKET_PORT m_port;
    int m_backlog;
    SOCKET m_attached;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosSocket
    ///
    ///       Author: $author$
    ///         Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    XosSocket
    (SOCKET attached = INVALID_SOCKET, 
     SOCKET_PORT port = INVALID_SOCKET_PORT,
     SOCKET_ADDR addr = INADDR_ANY,
     SOCKET_ADDR_FAMILY family = AF_INET,
     SOCKET_TYPE type = SOCK_STREAM,
     SOCKET_PROTOCOL protocol = 0,
     int backlog = DEFAULT_XOS_SOCKET_BACKLOG) 
    : m_family(family),
      m_type(type),
      m_protocol(protocol),
      m_addr(addr),
      m_port(port),
      m_backlog(backlog),
      m_attached(attached)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosSocket
    ///
    ///      Author: $author$
    ///        Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosSocket()
    {
        XosError error;
        if (INVALID_SOCKET != m_attached)
        if ((error = Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
    {
        XosError error = XOS_ERROR_FAILED;

        if (INVALID_SOCKET != (m_attached = socket
            (m_family, m_type, m_protocol)))
        {
#if defined(WINDOWS) 
// Windows 
            int optval = 1;
            int err;

            if ((err = setsockopt
                (m_attached, IPPROTO_TCP, TCP_NODELAY, 
                (char*)&optval, sizeof(optval))))
            {
                XOS_DBE(("() failed on setsockopt\n"));
                closesocket(m_attached);
                m_attached = INVALID_SOCKET;
                return error;
            }
#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 
            return XOS_ERROR_NONE;
        }
        XOS_DBE(("() failed error = %d\n", GET_SOCKET_ERROR(0)));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close()
    {
        XosError error = XOS_ERROR_NONE;
        int err;

        if (INVALID_SOCKET != m_attached)
        if ((err = closesocket(m_attached)))
        {
            XOS_DBE(("() failed to close socket error = %d\n", GET_SOCKET_ERROR(err)));
            error = XOS_ERROR_FAILED;
        }
        m_attached = INVALID_SOCKET;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Connect
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Connect
    (const SOCKADDR_IN& sockAddrIn)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET != m_attached)
        if ((err = connect(m_attached, (SOCKADDR*)(&sockAddrIn), sizeof(sockAddrIn))))
        {
            XOS_DBE(("() failed to connect error = %d\n", GET_SOCKET_ERROR(err)));
            return error;
        }
        else
        {
            m_family = sockAddrIn.sin_family;
            m_addr = sockAddrIn.sin_addr.s_addr;
            m_port = sockAddrIn.sin_port;
            error = XOS_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Send
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send
    (const void* buffer, int length, int flags=0)
    {
        ssize_t count = -XOS_ERROR_FAILED;
        const char* chars = (const char*)(buffer);
        int sent;

        if (INVALID_SOCKET != m_attached)
        if (0 > (sent = send(m_attached, chars, length, 0)))
            XOS_DBE(("() failed error = %d\n", GET_SOCKET_ERROR(sent)));
        else
        count = sent;

        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetNoDelayOpt
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetNoDelayOpt(bool on=true)
    {
        XosError error = XOS_ERROR_FAILED;
        int optValue = IN_SOCKET_NODELAY_ON(on);
        error = SetOpt
        (IPPROTO_TCP, TCP_NODELAY,
         &optValue, ((SOCKET_OPT_LENGTH)sizeof(optValue)));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetLingerOpt
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetLingerOpt
    (bool on=true, int lingerSeconds=-1)
    {
        XosError error = XOS_ERROR_FAILED;
        SOCKET_LINGER linger;

        if (0 > lingerSeconds)
            lingerSeconds = DEFAULT_SOCKET_LINGER_SECONDS;

        SET_SOCKET_LINGER_ON(linger, on);
        SET_SOCKET_LINGER_SECONDS(linger, lingerSeconds);

        error = SetOpt
        (SOL_SOCKET, SO_LINGER, 
         &linger, ((SOCKET_OPT_LENGTH)sizeof(linger)));
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetOpt
    ///
    ///    Author: $author$
    ///      Date: 1/31/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SetOpt
    (SOCKET_OPT_LEVEL level,
     SOCKET_OPT_NAME name,
     const SOCKET_OPT_VALUE* value,
     SOCKET_OPT_LENGTH length)
    {
        XosError error = XOS_ERROR_FAILED;
        int err;

        if (INVALID_SOCKET != m_attached)
        if ((err = setsockopt
            (m_attached, level, name,
             (const char*)value, length)))
            XOS_DBE(("() failed to setsockopt error = %d\n", GET_SOCKET_ERROR(err)));
        else error = XOS_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSSOCKET_HPP 
        

