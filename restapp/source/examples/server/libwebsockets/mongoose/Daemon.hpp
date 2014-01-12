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
///   Date: 1/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _RESTAPP_EXAMPLES_SERVER_LIBWEBSOCKETS_MONGOOSE_DAEMON_HPP
#define _RESTAPP_EXAMPLES_SERVER_LIBWEBSOCKETS_MONGOOSE_DAEMON_HPP

#include "server/libwebsockets/mongoose/Daemon.hpp"
#include "examples/server/Callback.hpp"

namespace restapp {
namespace examples {
namespace server {
namespace libwebsockets {
namespace mongoose {

typedef restapp::server::libwebsockets::mongoose::DaemonImplement DaemonImplement;
typedef restapp::server::libwebsockets::mongoose::DaemonT
<examples::server::EventCallbackImplement> DaemonExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Daemon
: virtual public DaemonImplement, public DaemonExtend {
public:
    typedef DaemonImplement Implements;
    typedef DaemonExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Daemon(xos::http::server::Processor& delegatedToProcessor)
    : Extends(delegatedToProcessor) {
    }
    virtual ~Daemon() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual struct libwebsocket_protocols* LwsProtocols() const {
        static struct libwebsocket_protocols lwsProtocols[] = {
            RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOLS
        };
        return lwsProtocols;
    }
    virtual struct libwebsocket_protocols* LwsCallbackEventProtocol() const {
        return &LwsProtocols()[RESTAPP_SERVER_LIBWEBSOCKETS_DAEMON_LWS_PROTOCOL_EVENT_INDEX];
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace mongoose 
} // namespace libwebsockets 
} // namespace server 
} // namespace examples 
} // namespace restapp

#endif // _RESTAPP_EXAMPLES_SERVER_LIBWEBSOCKETS_MONGOOSE_DAEMON_HPP 
