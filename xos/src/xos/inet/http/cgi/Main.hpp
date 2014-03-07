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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 3/5/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_INET_HTTP_CGI_MAIN_HPP
#define _XOS_INET_HTTP_CGI_MAIN_HPP

#include "xos/os/Main.hpp"
#include "xos/base/FormattedStream.hpp"
#include "xos/base/StreamStream.hpp"
#include "xos/inet/http/cgi/Environment.hpp"

#define XOS_HTTP_HEADER_NAME_CONTENT_TYPE "Content-type"
#define XOS_HTTP_HEADER_VALUE_SEPARATOR ":"
#define XOS_HTTP_HEADER_END "\r\n"

#define XOS_HTTP_CONTENT_TYPE_NAME_TEXT "text/plain"
#define XOS_HTTP_CONTENT_TYPE_NAME_HTML "text/html"
#define XOS_HTTP_CONTENT_TYPE_NAME_XML "text/xml"

#define XOS_HTTP_CGI_CONTENT_TYPE_NAME \
    XOS_HTTP_CONTENT_TYPE_NAME_TEXT

namespace xos {
namespace http {
namespace cgi {

typedef xos::Main MainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: MainImplement
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainImplement
: virtual public FormattedStream,
  virtual public xos::MainImplement {
public:
};
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplement, public MainExtend {
public:
    typedef MainImplement Implements;
    typedef MainExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main()
    : m_outputContentType(0),
      m_contentType(XOS_HTTP_CGI_CONTENT_TYPE_NAME) {
    }
    virtual ~Main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int CgiMain(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int ConsoleMain(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        Environment::Variable::Value e;
        if (0 < (e.Get(Environment::Variable::GATEWAY_INTERFACE).Length()))
            err = CgiMain(argc, argv, env);
        else err = ConsoleMain(argc, argv, env);
        return err;
    }
   virtual int operator()(int argc, char** argv, char** env) {
        xos::StreamStream loggerStream(*this);
        xos::Main::Logger logger(&loggerStream);
        XOS_SET_LOGGING_LEVELS_TO_DEFAULT_LOGGING_LEVELS_ID();
        return Extends::operator()(argc, argv, env);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutContent(const char* chars, ssize_t length = -1) {
        ssize_t count = 0;
        ssize_t count2;
        if (0 > (count = OutContentType()))
            return count;
        if (0 > (count2 = Out(chars, length)))
            return count2;
        count += count2;
        return count;
    }
    virtual ssize_t OutContentType(const char* chars = 0, ssize_t length =- 1) {
        ssize_t count = 0;
        if (!(m_outputContentType)) {
            if (!(chars)) {
                chars = m_contentType.Chars();
                length = m_contentType.Length();
            }
            if ((chars) && (length)) {
                if (count = OutL
                    (XOS_HTTP_HEADER_NAME_CONTENT_TYPE,
                     XOS_HTTP_HEADER_VALUE_SEPARATOR,
                     chars, XOS_HTTP_HEADER_END,
                     XOS_HTTP_HEADER_END, (const char*)(0))) {
                    m_outputContentType = chars;
                }
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const char* what, ssize_t length = -1) {
        return OutContent((const char*)(what), length);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char* m_outputContentType;
    String m_contentType;
};

} // namespace cgi 
} // namespace http 
} // namespace xos 

#endif // _XOS_INET_HTTP_CGI_MAIN_HPP 
