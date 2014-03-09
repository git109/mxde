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
#include "xos/inet/http/cgi/Arguments.hpp"

#define XOS_HTTP_HEADER_NAME_CONTENT_TYPE "Content-type"
#define XOS_HTTP_HEADER_VALUE_SEPARATOR ":"
#define XOS_HTTP_HEADER_END "\r\n"

#define XOS_HTTP_CONTENT_TYPE_NAME_TEXT "text/plain"
#define XOS_HTTP_CONTENT_TYPE_NAME_HTML "text/html"
#define XOS_HTTP_CONTENT_TYPE_NAME_XML "text/xml"

#define XOS_HTTP_CGI_CONTENT_TYPE_NAME \
    XOS_HTTP_CONTENT_TYPE_NAME_TEXT

#define XOS_HTTP_CGICATCH_ENV_NAME "cgienv.txt"
#define XOS_HTTP_CGICATCH_ARGV_NAME "cgiargv.txt"
#define XOS_HTTP_CGICATCH_STDIN_NAME "cgistdin.txt"
#define XOS_HTTP_CGICATCH_STDOUT_NAME "cgistdout.txt"

#define XOS_HTTP_CGI_MAIN_ENV_NAME XOS_HTTP_CGICATCH_ENV_NAME
#define XOS_HTTP_CGI_MAIN_ARGV_NAME XOS_HTTP_CGICATCH_ARGV_NAME
#define XOS_HTTP_CGI_MAIN_STDIN_NAME XOS_HTTP_CGICATCH_STDIN_NAME

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
    typedef cgi::Arguments Arguments;
    typedef cgi::Environment Environment;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main()
    : m_envFileName(XOS_HTTP_CGI_MAIN_ENV_NAME),
      m_argvFileName(XOS_HTTP_CGI_MAIN_ARGV_NAME),
      m_stdinFileName(XOS_HTTP_CGI_MAIN_ENV_NAME),
      m_outputContentType(0),
      m_contentType(XOS_HTTP_CGI_CONTENT_TYPE_NAME),
      m_eReader(m_e),
      m_aReader(m_a) {
    }
    virtual ~Main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunCgi(int argc, char** argv, char** env) {
        int err = 0;
        OutContentFlush();
        return err;
    }
    virtual int BeforeRunCgi(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int AfterRunCgi(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int CgiRun(int argc, char** argv, char** env) {
        int err = 0;
        if (!(err = BeforeRunCgi(argc, argv, env))) {
            int err2;
            err = RunCgi(argc, argv, env);
            if ((err2 = AfterRunCgi(argc, argv, env)) && (!err))
                err = err2;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int CgiMain(int argc, char** argv, char** env) {
        int err = 0;
        m_e.Get();
        err = CgiRun(argc, argv, env);
        return err;
    }
    virtual int ConsoleMain(int argc, char** argv, char** env) {
        int err = 0;
        m_eReader.Read(m_envFileName);
        err = CgiRun(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        Environment::Variable::Value e;
        if (0 < (e.Get(Environment::Variable::GATEWAY_INTERFACE).Length())) {
            XOS_LOG_TRACE("running as CGI");
            err = CgiMain(argc, argv, env);
        }
        else {
            XOS_LOG_TRACE("running on console");
            err = ConsoleMain(argc, argv, env);
        }
        return err;
    }
   virtual int operator()(int argc, char** argv, char** env) {
        xos::StreamStream loggerStream(*this);
        xos::Main::Logger logger(&loggerStream);
        int ac = 0; char** av = 0;
        XOS_SET_LOGGING_LEVELS_TO_DEFAULT_LOGGING_LEVELS_ID();
        m_aReader.NameValueRead(m_argvFileName);
        if ((0 < (ac = m_a.c())) && (0 != (av = m_a.v()))) {
            argc = ac; argv = av;
        }
        return Extends::operator()(argc, argv, env);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutContentFlush() {
        ssize_t count = OutContentType();
        ssize_t count2;
        if (0 > (count2 = Extends::OutFlush()))
            return count2;
        count += count2;
        return count;
    }
    virtual ssize_t OutContent(const char* chars, ssize_t length = -1) {
        ssize_t count = 0;
        ssize_t count2;
        if (0 > (count = OutContentType()))
            return count;
        if (0 > (count2 = Extends::Out(chars, length)))
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
                if (count = Extends::OutL
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
    virtual ssize_t OutFormattedV(const char* format, va_list va) {
        ssize_t count = 0;
        OutContentType();
        count = Extends::OutFormattedV(format, va);
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
    String m_envFileName;
    String m_argvFileName;
    String m_stdinFileName;
    const char* m_outputContentType;
    String m_contentType;
    Environment m_e;
    Environment::Reader m_eReader;
    Arguments m_a;
    Arguments::Reader m_aReader;
};

} // namespace cgi 
} // namespace http 
} // namespace xos 

#endif // _XOS_INET_HTTP_CGI_MAIN_HPP 
