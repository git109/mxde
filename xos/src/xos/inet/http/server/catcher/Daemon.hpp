///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: Daemon.hpp
///
/// Author: $author$
///   Date: 6/21/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_INET_HTTP_SERVER_CATCHER_DAEMON_HPP
#define _XOS_INET_HTTP_SERVER_CATCHER_DAEMON_HPP

#include "xos/inet/http/server/Daemon.hpp"
#include "xos/network/Sockets.hpp"

#define XOS_INET_HTTP_SERVER_CATCHER_DAEMON_REQUEST_FILENAME "httprequest.txt"
#define XOS_INET_HTTP_SERVER_CATCHER_DAEMON_IP_VERSION 4

namespace xos {
namespace http {
namespace server {
namespace catcher {

typedef server::DaemonImplement DaemonImplement;
typedef server::Daemon DaemonExtend;
///////////////////////////////////////////////////////////////////////
///  Class: Daemon
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Daemon: virtual public DaemonImplement, public DaemonExtend {
public:
    typedef DaemonImplement Implements;
    typedef DaemonExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Daemon()
    : m_requestFilename(XOS_INET_HTTP_SERVER_CATCHER_DAEMON_REQUEST_FILENAME),
      m_ipVersion(XOS_INET_HTTP_SERVER_CATCHER_DAEMON_IP_VERSION),
      m_done(true) {
    }
    virtual ~Daemon() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunServer(int argc, char** argv, char** env) {
        int err = 0;
        network::Endpoint* ep;
        network::Socket* ls;

        XOS_LOG_DEBUG("in...");
        if ((ep = Endpoint(m_listenHost, m_listenPortNo))) {
            XOS_LOG_DEBUG("...endpoint");

            if ((ls = Listen(*ep))) {
                XOS_LOG_DEBUG("...listen");

                Accept(*ls, *ep);
                network::Socket::Delete(ls);
            }
            network::Endpoint::Delete(ep);
        }
        XOS_LOG_DEBUG("...out");
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Accept(network::Socket& ls, network::Endpoint& ep) {
        network::Socket* sock = 0;
        XOS_LOG_DEBUG("in...");
        do {
            XOS_LOG_DEBUG("accept socket...");
            if ((sock = ls.Accept(ep.SocketAddress(), &ep.SocketAddressLen()))) {
                XOS_LOG_DEBUG("...accepted socket");

                network::Socket::Delete(sock);
                sock = 0;
            } else {
                XOS_LOG_DEBUG("...failed on accept socket");
                break;
            }
        } while (!(Done()));
        XOS_LOG_DEBUG("...out");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Socket* Listen(network::Endpoint& ep) {
        network::Socket* s = 0;
        if (s = (network::Socket::New(ep.GetFamily(), network::ip::tcp::Transport::Type, network::ip::tcp::Transport::Protocol))) {
            if ((s->Bind(ep.SocketAddress(), ep.SocketAddressLen()))) {
                if ((s->Listen())) {
                    return s;
                }
            }
            network::Socket::Delete(s);
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Endpoint* Endpoint(const String& host, unsigned port) {
        if (6 == (m_ipVersion))
            return Ipv6Endpoint(host, port);
        return Ipv4Endpoint(host, port);
    }
    virtual network::Endpoint* Ipv4Endpoint(const String& host, unsigned port) {
        network::Endpoint* ep = new network::ip::v4::Endpoint(host, port);
        return ep;
    }
    virtual network::Endpoint* Ipv6Endpoint(const String& host, unsigned port) {
        network::Endpoint* ep = new network::ip::v6::Endpoint(host, port);
        return ep;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDone(bool isTrue = true) {
        m_done = isTrue;
        return m_done;
    }
    virtual bool Done() {
        return m_done;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_requestFilename;
    int m_ipVersion;
    bool m_done;
};

} // namespace catcher
} // namespace server 
} // namespace http 
} // namespace xos 

#endif // _XOS_INET_HTTP_SERVER_CATCHER_DAEMON_HPP
