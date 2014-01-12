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
#ifndef _RESTAPP_SERVER_LIBWEBSOCKETS_MONGOOSE_DAEMON_HPP
#define _RESTAPP_SERVER_LIBWEBSOCKETS_MONGOOSE_DAEMON_HPP

#include "RestApp.hpp"
#include "server/libwebsockets/Daemon.hpp"
#include "xos/inet/http/server/libwebsockets/mongoose/Daemon.hpp"

namespace restapp {
namespace server {
namespace libwebsockets {
namespace mongoose {

typedef xos::http::server::libwebsockets::mongoose::DaemonImplement DaemonImplement;
typedef xos::http::server::libwebsockets::mongoose::Daemon DaemonExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TCallbackImplement>
class _EXPORT_CLASS DaemonT
: virtual public DaemonImplement, public libwebsockets::DaemonT
  <TCallbackImplement, DaemonImplement, DaemonExtend> {
public:
    typedef DaemonImplement Implements;
    typedef libwebsockets::DaemonT
    <TCallbackImplement, DaemonImplement, DaemonExtend> Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DaemonT(xos::http::server::Processor& delegatedToProcessor)
    : Extends(delegatedToProcessor) {
    }
    virtual ~DaemonT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace mongoose 
} // namespace libwebsockets 
} // namespace server 
} // namespace restapp 

#endif // _RESTAPP_SERVER_LIBWEBSOCKETS_MONGOOSE_DAEMON_HPP 
