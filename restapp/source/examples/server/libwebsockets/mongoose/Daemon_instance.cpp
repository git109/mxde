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
///   File: Daemon_instance.cpp
///
/// Author: $author$
///   Date: 1/9/2014
///////////////////////////////////////////////////////////////////////
#include "examples/server/libwebsockets/mongoose/Daemon.hpp"

namespace restapp {
namespace examples {
namespace server {
namespace libwebsockets {
namespace mongoose {

static Daemon the_daemon
(xos::http::server::Processor::GetTheInstance());

} // namespace mongoose
} // namespace libwebsockets
} // namespace server
} // namespace examples
} // namespace restapp

namespace xos {

Daemon& Daemon::GetTheInstance() {
    return restapp::examples::server::libwebsockets::mongoose::the_daemon;
}

} // namespace xos
