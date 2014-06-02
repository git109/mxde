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
///   File: Request.hpp
///
/// Author: $author$
///   Date: 5/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_INET_HTTP_SERVER_MEDUSA_REQUEST_HPP
#define _XOS_INET_HTTP_SERVER_MEDUSA_REQUEST_HPP

#include "xos/inet/http/server/medusa/request/HeadersReader.hpp"
#include "xos/inet/http/server/medusa/request/HeaderReader.hpp"
#include "xos/inet/http/server/medusa/request/LineReader.hpp"
#include "xos/inet/http/Request.hpp"
#include "xos/io/Reader2Reader.hpp"

namespace xos {
namespace http {
namespace server {
namespace medusa {

typedef http::RequestImplement RequestImplement;
typedef http::Request RequestExtend;
///////////////////////////////////////////////////////////////////////
///  Class: RequestT
///////////////////////////////////////////////////////////////////////
template <class TExtend = RequestExtend, class TImplement = RequestImplement>

class _EXPORT_CLASS RequestT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    RequestT(CharReader& messageReader): Extends(messageReader) {
    }
    virtual ~RequestT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef RequestT<> Request;

} // namespace medusa 
} // namespace server 
} // namespace http 
} // namespace xos 

#endif // _XOS_INET_HTTP_SERVER_MEDUSA_REQUEST_HPP 
