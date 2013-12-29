///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   Date: 11/23/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_HTTP_REQUEST_HPP
#define _XOS_HTTP_REQUEST_HPP

#include "xos/inet/http/Form.hpp"
#include "xos/base/Named.hpp"

#define XOS_HTTP_VERSION_PROTOCOL "HTTP"
#define XOS_HTTP_VERSION_MAJOR_NO 1
#define XOS_HTTP_VERSION_MAJOR XOS_STRING(XOS_HTTP_VERSION_MAJOR_NO)
#define XOS_HTTP_VERSION_MINOR_NO 1
#define XOS_HTTP_VERSION_MINOR XOS_STRING(XOS_HTTP_VERSION_MINOR_NO)

#define XOS_HTTP_CONTENT_TYPE_NAME "Content-Type"
#define XOS_HTTP_CONTENT_LENGTH_NAME "Content-Length"
#define XOS_HTTP_CONTENT_ENCODING_NAME "Content-Encoding"

#define XOS_HTTP_STATUS_OK_NO 200
#define XOS_HTTP_STATUS_OK XOS_STRING(XOS_HTTP_STATUS_OK_NO)
#define XOS_HTTP_STATUS_OK_REASON "OK"

#define XOS_HTTP_URI_QUERY_SEPARATOR "?"
#define XOS_HTTP_URI_FRAGMENT_SEPARATOR "#"

#define XOS_HTTP_REQUEST_METHOD_NAME_GET "GET"
#define XOS_HTTP_REQUEST_METHOD_NAME_POST "POST"
#define XOS_HTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define XOS_HTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define XOS_HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"
#define XOS_HTTP_REQUEST_METHOD_NAME_HEADERS "HEADERS"

namespace xos {
namespace http {

typedef String::Implements VersionImplement;
typedef String VersionExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Version: virtual public VersionImplement, public VersionExtend {
public:
    typedef VersionImplement Implements;
    typedef VersionExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Version(const String& value): Extends(value) {
    }
    Version()
    : m_protocol(XOS_HTTP_VERSION_PROTOCOL),
      m_major(XOS_HTTP_VERSION_MAJOR),
      m_minor(XOS_HTTP_VERSION_MINOR) {
        Combine();
    }
    virtual ~Version() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine(const String& protocol, const String& major, const String& minor) {
        m_protocol = protocol;
        m_major = major;
        m_minor = minor;
        return Combine();
    }
    virtual bool Combine() {
        if ((m_protocol.Length()) && (m_major.Length())) {
            Assign(m_protocol);
            Append("/");
            Append(m_major);
            Append(".");
            Append(m_minor);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool Separate(String& protocol, String& major, String& minor) {
        if ((Separate())) {
            protocol = m_protocol;
            major = m_major;
            minor = m_minor;
            return true;
        }
        return false;
    }
    virtual bool Separate() {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual String protocol() const {
        return (String&)(m_protocol);
    }
    virtual String major() const {
        return (String&)(m_major);
    }
    virtual String minor() const {
        return (String&)(m_minor);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_protocol;
    String m_major;
    String m_minor;
};

typedef Named Header;
typedef NamedVector HeadersExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Headers: public HeadersExtend {
public:
    typedef HeadersExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Headers(const Headers& copy): Extends(copy) {
    }
    Headers() {
    }
    virtual ~Headers() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine(String& value) {
        if ((size())) {
            const_iterator b = begin();
            const_iterator e = end();
            for (const_iterator i = b; i != e; ++i) {
                const Header& h = *i;
                value.Append(h.name());
                value.Append(":");
                value.Append(h.value());
                value.Append("\r\n");
            }
        }
        value.Append("\r\n");
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool Separate(const String& value) {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual String SetContentType(const String& to) {
        String value;
        const Header* h;
        if ((h = Set(XOS_HTTP_CONTENT_TYPE_NAME, to))) {
            value = h->GetValue();
        }
        return value;
    }
    virtual String GetContentType() const {
        String value;
        const Header* h;
        if ((h = Get(XOS_HTTP_CONTENT_TYPE_NAME))) {
            value = h->GetValue();
        }
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual String SetContentLength(const String& to) {
        String value;
        const Header* h;
        if ((h = Set(XOS_HTTP_CONTENT_LENGTH_NAME, to))) {
            value = h->GetValue();
        }
        return value;
    }
    virtual String GetContentLength() const {
        String value;
        const Header* h;
        if ((h = Get(XOS_HTTP_CONTENT_LENGTH_NAME))) {
            value = h->GetValue();
        }
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Header* Set(const String& name,const String& value) {
        const Header* header = 0;
        if (!(header = Get(name))) {
            push_back(Header(name, value));
            return Get(name);
        } else {
            iterator b = begin();
            iterator e = end();
            iterator i;
            for (i = b; i != e; ++i) {
                Header& h = *i;
                if (!(name.compare(h.GetName()))) {
                    h.SetValue(value);
                    return &h;
                }
            }
        }
        return 0;
    }
    virtual const Header* Get(const String& name) const {
        const_iterator b = begin();
        const_iterator e = end();
        const_iterator i;
        for (i = b; i != e; ++i) {
            const Header& h = *i;
            if (!(name.compare(h.GetName()))) {
                return &h;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef String::Implements MessageImplement;
typedef String MessageExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Message: virtual public MessageImplement, public MessageExtend {
public:
    typedef MessageImplement Implements;
    typedef MessageExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Message(const String& value): Extends(value) {
    }
    Message() {
    }
    virtual ~Message() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef InterfaceBase RequestImplement;
typedef Base RequestExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Request: virtual public RequestImplement, public RequestExtend {
public:
    typedef RequestImplement Implements;
    typedef RequestExtend Extends;

    typedef String::Implements MethodImplement;
    typedef String MethodExtend;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Method: virtual public MethodImplement, public MethodExtend {
    public:
        typedef MethodImplement Implements;
        typedef MethodExtend Extends;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Method(const String& value): Extends(value) {
        }
        Method() {
        }
        virtual ~Method() {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    };

    typedef String::Implements UriImplement;
    typedef String UriExtend;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Uri: virtual public UriImplement, public UriExtend {
    public:
        typedef UriImplement Implements;
        typedef UriExtend Extends;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Uri(const String& path, const String& query, const String& fragment)
        : m_path(path), m_query(query), m_fragment(fragment) {
            Combine();
        }
        Uri(const String& combined)
        : Extends(combined) {
            Separate();
        }
        Uri(const char* combined, ssize_t length)
        : Extends(combined, length) {
            Separate();
        }
        Uri(const Uri& copy)
        : Extends(copy), m_path(copy.m_path), m_query(copy.m_query), m_fragment(copy.m_fragment) {
        }
        Uri() {
        }
        virtual ~Uri() {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual bool Combine() {
            return false;
        }
        virtual bool Separate() {
            size_t query, fragment;
            m_path.Clear();
            m_query.Clear();
            m_fragment.Clear();
            if ((0 < (query = find(XOS_HTTP_URI_QUERY_SEPARATOR))) && (query < Length())) {
                m_path.Assign(c_str(), query);
                if ((query < (fragment = find(XOS_HTTP_URI_FRAGMENT_SEPARATOR))) && (fragment < Length())) {
                    m_query.Assign(c_str()+query+1, fragment-query);
                    m_fragment.Assign(c_str()+fragment+1);
                } else {
                    m_query.Assign(c_str()+query+1);
                }
            } else {
                if ((0 < (fragment = find(XOS_HTTP_URI_FRAGMENT_SEPARATOR))) && (fragment < Length())) {
                    m_fragment.Assign(c_str()+fragment+1);
                } else {
                }
            }
            return true;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetPath(const String& to) {
            m_path = to;
            return m_path;
        }
        virtual const String& GetPath() const {
            return m_path;
        }
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetQuery(const String& to) {
            m_query = to;
            return m_query;
        }
        virtual const String& GetQuery() const {
            return m_query;
        }
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetFragment(const String& to) {
            m_fragment = to;
            return m_fragment;
        }
        virtual const String& GetFragment() const {
            return m_fragment;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        String m_path, m_query, m_fragment;
    };

    typedef String::Implements LineImplement;
    typedef String LineExtend;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Line: virtual public LineImplement, public LineExtend {
    public:
        typedef LineImplement Implements;
        typedef LineExtend Extends;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Line(const Method& method, const Uri& uri, const Version& version)
        : m_method(method), m_uri(uri), m_version(version) {
        }
        Line(const Method& method, const Uri& uri)
        : m_method(method), m_uri(uri) {
        }
        Line() {
        }
        virtual ~Line() {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetMethod(const String& to) {
            m_method = to;
            return m_method;
        }
        virtual const String& GetMethod() const {
            return m_method;
        }
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetPath(const String& to) {
            m_uri.SetPath(to);
            return m_uri.GetPath();
        }
        virtual const String& GetPath() const {
            return m_uri.GetPath();
        }
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetQuery(const String& to) {
            m_uri.SetQuery(to);
            return m_uri.GetQuery();
        }
        virtual const String& GetQuery() const {
            return m_uri.GetQuery();
        }
        ///////////////////////////////////////////////////////////////////////
        virtual const String& SetFragment(const String& to) {
            m_uri.SetFragment(to);
            return m_uri.GetFragment();
        }
        virtual const String& GetFragment() const {
            return m_uri.GetFragment();
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        Method m_method;
        Uri m_uri;
        Version m_version;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Request(const Line& line, const Headers& headers, const Message& message)
    : m_line(line), m_headers(headers), m_message(message) {
    }
    Request(const Method& method, const Uri& uri, const Version& version)
    : m_line(method, uri, version) {
    }
    Request(const Method& method, const Uri& uri)
    : m_line(method, uri) {
    }
    Request(const Request& copy)
    : m_line(copy.m_line), m_headers(copy.m_headers), m_message(copy.m_message) {
    }
    Request() {
    }
    virtual ~Request() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const String& SetMethod(const String& to) {
        m_line.SetMethod(to);
        return m_line.GetMethod();
    }
    virtual const String& GetMethod() const {
        return m_line.GetMethod();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const String& SetPath(const String& to) {
        m_line.SetPath(to);
        return m_line.GetPath();
    }
    virtual const String& GetPath() const {
        return m_line.GetPath();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const String& SetQuery(const String& to) {
        m_line.SetQuery(to);
        return m_line.GetQuery();
    }
    virtual const String& GetQuery() const {
        return m_line.GetQuery();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const String& SetFragment(const String& to) {
        m_line.SetFragment(to);
        return m_line.GetFragment();
    }
    virtual const String& GetFragment() const {
        return m_line.GetFragment();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual String SetContentType(const String& to) {
        return m_headers.SetContentType(to);
    }
    virtual String GetContentType() const {
        return m_headers.GetContentType();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual String SetContentLength(const String& to) {
        return m_headers.SetContentLength(to);
    }
    virtual String GetContentLength() const {
        return m_headers.GetContentLength();
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int SetContentLengthNo(int toValue) {
        String to(toValue);
        to = SetContentLength(to);
        if ((to.Length()))
            return (to >> toValue);
        return -1;
    }
    virtual int GetContentLengthNo() const {
        String to = GetContentLength();
        int toValue;
        if ((to.Length()))
            return (to >> toValue);
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int SetContent(String& value) {
        int length = -1;
        return length;
    }
    virtual int GetContent(String& value) const {
        int length = -1;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual Form& SetForm(const Form& to) {
        m_form = to;
        return m_form;
    }
    virtual const Form& GetForm() const {
        return m_form;
    }
    virtual Form& form() const {
        return (Form&)(m_form);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Line m_line;
    Headers m_headers;
    Message m_message;
    Form m_form;
};

} // namespace http 
} // namespace xos 

#endif // _XOS_HTTP_REQUEST_HPP 
