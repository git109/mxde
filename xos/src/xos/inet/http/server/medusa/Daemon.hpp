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
///   Date: 5/25/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_INET_HTTP_SERVER_MEDUSA_DAEMON_HPP
#define _XOS_INET_HTTP_SERVER_MEDUSA_DAEMON_HPP

#include "xos/inet/http/server/medusa/TcpServer.hpp"
#include "xos/inet/http/server/medusa/TcpConnection.hpp"
#include "xos/inet/http/server/Daemon.hpp"
#include "xos/inet/http/FormReader.hpp"
#include "xos/inet/http/Response.hpp"
#include "xos/inet/http/Request.hpp"

namespace xos {
namespace http {
namespace server {
namespace medusa {

typedef server::Daemon DaemonTExtend;
typedef server::DaemonImplement DaemonTImplement;
///////////////////////////////////////////////////////////////////////
///  Class: DaemonT
///////////////////////////////////////////////////////////////////////
template
<class TExtend = DaemonTExtend,
 class TImplement = DaemonTImplement>

class _EXPORT_CLASS DaemonT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DaemonT() {
    }
    virtual ~DaemonT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunServer(int argc, char** argv, char** env) {
        int err = 0;
        if (!(err = BeforeRunMedusaServer(argc, argv, env))) {
            int err2;

            err = RunMedusaServer(argc, argv, env);

            if ((err2 = AfterRunMedusaServer(argc, argv, env))) {
                if (!err)
                    err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunMedusaServer(int argc, char** argv, char** env) {
        int err = 0;
        TcpServer tcpServer(this->m_listenHost, this->m_listenPortNo);
        XOS_LOG_DEBUG("tcpServer.Start()...");
        if ((tcpServer.Start())) {
            XOS_LOG_DEBUG("tcpServer.Finish()...");
            if (!tcpServer.Finish()) {
                XOS_LOG_DEBUG("...failed on tcpServer.Finish()");
            }
        } else {
            XOS_LOG_DEBUG("...failed on tcpServer.Start()");
        }
        return err;
    }
    virtual int BeforeRunMedusaServer(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int AfterRunMedusaServer(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};
typedef DaemonT<> Daemon;

} // namespace medusa 
} // namespace server 
} // namespace http 
} // namespace xos 

#endif // _XOS_INET_HTTP_SERVER_MEDUSA_DAEMON_HPP 
