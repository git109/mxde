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
///   File: Socket.hpp
///
/// Author: $author$
///   Date: 9/26/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_WINDOWS_SOCKET_HPP
#define _XOS_NETWORK_WINDOWS_SOCKET_HPP

#include "xos/network/Socket.hpp"
#include "xos/base/Opened.hpp"
#include "xos/os/Logger.hpp"
#include "sys/Socket.h"

namespace xos {
namespace network {
namespace windows {

typedef network::Socket SocketImplement;
typedef Attached<SOCKET, int, 0, ExportBase, SocketImplement> SocketAttached;
typedef Opened<SOCKET, int, 0, SocketAttached, SocketImplement> SocketExtend;

class _EXPORT_CLASS Socket
: virtual public SocketImplement,
  public SocketExtend
{
public:
    typedef SocketImplement Implements;
    typedef SocketExtend Extends;

    Socket(SOCKET detached = 0, bool isOpen = false)
    : Extends(detached, isOpen) {
    }
    virtual ~Socket() {
        if ((m_isOpen)) {
            if (!(Close())) {
                XOS_LOG_ERROR("failed on Close()");
            }
        }
    }

    virtual bool Close() { 
        bool isOpen = false;
        SOCKET detached = 0;
        if (Unattached  != (detached = Detach(isOpen))) {
            int err = 0;
            if (!(err = closesocket(detached))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on closesocket()");
            }
        }
        return false; }
    virtual bool Shutdown() { 
        return Shutdown(SD_BOTH); }
    virtual bool Shutdown(int how) { 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (!(err = shutdown(m_attachedTo, how))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on shutdown()");
            }
        }
        return false; }

    virtual bool Connect(const struct sockaddr* addr, socklen_t addrlen) { 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (!(err = connect(m_attachedTo, addr, addrlen))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on connect()");
            }
        }
        return false; }
    virtual bool Bind(const struct sockaddr* addr, socklen_t addrlen) { 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (!(err = bind(m_attachedTo, addr, addrlen))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on bind()");
            }
        }
        return false; }

    virtual bool Listen() { 
        return Listen(SOMAXCONN); }
    virtual bool Listen(int backlog) { 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (!(err = listen(m_attachedTo, backlog))) {
                return true;
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on listen()");
            }
        }
        return false; }
    virtual network::Socket* Accept(struct sockaddr* addr, socklen_t* addrlen) { 
        network::Socket* s = 0; 
        if (Unattached  != (m_attachedTo)) {
            SOCKET detached = 0;
            bool isOpen = false;
            if ((isOpen = (INVALID_SOCKET != (detached = accept(m_attachedTo, addr, addrlen))))) {
                s = new Socket(detached, isOpen);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on accept()");
            }
        }
        return s; }

    virtual ssize_t Send(const void* buf, size_t len, int flags) { 
        ssize_t count = -1; 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (SOCKET_ERROR != (err = send(m_attachedTo, (const char*)(buf), len, flags))) {
                count = (ssize_t)(err);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on send()");
            }
        }
        return count; }
    virtual ssize_t Recv(void* buf, size_t len, int flags) { 
        ssize_t count = -1; 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (SOCKET_ERROR != (err = recv(m_attachedTo, (char*)(buf), len, flags))) {
                count = (ssize_t)(err);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on recv()");
            }
        }
        return count; }

    virtual ssize_t SendTo
    (const void* buf, size_t len, int flags, 
     const struct sockaddr* addr, socklen_t addrlen) { 
        ssize_t count = -1; 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (SOCKET_ERROR != (err = sendto
                (m_attachedTo, (const char*)(buf), len, flags, addr, addrlen))) {
                count = (ssize_t)(err);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on sendto()");
            }
        }
        return count; }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, int flags, 
     struct sockaddr* addr, socklen_t* addrlen) { 
        ssize_t count = -1; 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (SOCKET_ERROR != (err = recvfrom
                (m_attachedTo, (char*)(buf), len, flags, addr, addrlen))) {
                count = (ssize_t)(err);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on recvfrom()");
            }
        }
        return count; }

    virtual ssize_t SendMsg(const struct msghdr* msg, int flags) { 
        ssize_t count = -1; 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (SOCKET_ERROR != (err = sendmsg(m_attachedTo, msg, flags))) {
                count = (ssize_t)(err);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on sendmsg()");
            }
        }
        return count; }
    virtual ssize_t RecvMsg(struct msghdr* msg, int flags) { 
        ssize_t count = -1; 
        if (Unattached  != (m_attachedTo)) {
            int err = 0;
            if (SOCKET_ERROR != (err = recvmsg(m_attachedTo, msg, flags))) {
                count = (ssize_t)(err);
            } else {
                XOS_LOG_ERROR("failed " << WSAGetLastError() << " on recvmsg()");
            }
        }
        return count; }
};

} // namespace xos 
} // namespace network 
} // namespace windows 


#endif // _XOS_NETWORK_WINDOWS_SOCKET_HPP 
