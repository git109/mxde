/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: chttpurischeme.hxx
 *
 * Author: $author$
 *   Date: 6/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPURISCHEME_HXX
#define _CHTTPURISCHEME_HXX

#include "ccharreadwritefilet.hxx"
#include "csocket.hxx"
#include "curischeme.hxx"
#include "curiinterface.hxx"
#include "chttp.hxx"

/**
 **********************************************************************
 *  Class: cHTTPURL
 *
 * Author: $author$
 *   Date: 6/8/2004
 **********************************************************************
 */
class cHTTPURL
: virtual public cURLInterface,
  virtual public cURLImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    int m_port;
    cHTTPHeader::cField m_host;
    cHTTPHeader::cField m_query;
    cHTTPHeader::cField m_connection;

    cHTTPRequest m_http_request;
    cHTTPResponse m_http_response;

    cCharStream *m_content;

    /**
     **********************************************************************
     * Constructor: cHTTPURL
     *
     *      Author: $author$
     *        Date: 6/8/2004
     **********************************************************************
     */
    cHTTPURL
    (const char *host="localhost",
     const char *path="", const char *query="", int port=80,
     int connection=cHTTPHeader::cField::cType::cConnection::e_CLOSE) 
    : m_port(port),
      m_host(cHTTPHeader::cField::cType::e_HOST, host),
      m_query(cHTTPHeader::cField::cType::e_QUERY_STRING, query),
      m_connection(cHTTPHeader::cField::cType::e_CONNECTION, connection),
      m_http_request(path),
      m_content(0)
    {
        m_http_request.m_header.AddField(m_host);
        m_http_request.m_header.AddField(m_connection);
    }
    /**
     **********************************************************************
     *  Destructor: ~cHTTPURL
     *
     *      Author: $author$
     *        Date: 6/8/2004
     **********************************************************************
     */
    virtual ~cHTTPURL()
    {
        m_http_request.m_header.DeleteField(m_connection);
        m_http_request.m_header.DeleteField(m_host);
    }

    /**
     **********************************************************************
     * Function: OpenContent
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError OpenContent
    (cCharStream &stream, cHTTPChunkedContent &chunked_content)
    {
        eError error=e_ERROR_FAILED;
        int length;

        if (0 > (length = m_http_request.Send(stream)))
            error = -length;

        if ((m_content = m_http_response.Receive
            (stream, chunked_content)))
            error = e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: GetContent
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual cCharStream *GetContent
    (const char *&content_type, int &content_length) const
    {
        int length;

        content_type = m_http_response.m_header.GetContentType(length);

        if (0 > (content_length = m_http_response.m_header.GetContentLength()))
            content_length = m_content->GetLength();

        return m_content;
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cStdioHTTPURL
 *
 * Author: $author$
 *   Date: 6/9/2004
 **********************************************************************
 */
class cStdioHTTPURL
: public cHTTPURL
{
public:
    typedef cHTTPURL cIs;

    cCharReadWriteFile m_stdio;
    cHTTPChunkedContent m_chunked_content;

    /**
     **********************************************************************
     * Constructor: cStdioHTTPURL
     *
     *      Author: $author$
     *        Date: 6/9/2004
     **********************************************************************
     */
    cStdioHTTPURL
    (const char *host="localhost", 
     const char *path="", const char *query="", int port=80,
     int connection=cHTTPHeader::cField::cType::cConnection::e_CLOSE) 
    : cIs(host, path, query, port, connection),
      m_stdio(stdin, stdout),
      m_chunked_content(m_stdio)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cStdioHTTPURL
     *
     *     Author: $author$
     *       Date: 6/9/2004
     **********************************************************************
     */
    virtual ~cStdioHTTPURL()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError Open()
    {
        eError error;
        error = OpenContent(m_stdio, m_chunked_content);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cSocketHTTPURL
 *
 * Author: $author$
 *   Date: 6/10/2004
 **********************************************************************
 */
class cSocketHTTPURL
: public cHTTPURL
{
public:
    typedef cHTTPURL cIs;

    cSocket m_socket;
    cHTTPChunkedContent m_chunked_content;

    /**
     **********************************************************************
     * Constructor: cSocketHTTPURL
     *
     *      Author: $author$
     *        Date: 6/10/2004
     **********************************************************************
     */
    cSocketHTTPURL
    (const char *host="localhost", 
     const char *path="", const char *query="", int port=80,
     int connection=cHTTPHeader::cField::cType::cConnection::e_CLOSE) 
    : cIs(host, path, query, port, connection),
      m_chunked_content(m_socket) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cSocketHTTPURL
     *
     *     Author: $author$
     *       Date: 6/10/2004
     **********************************************************************
     */
    virtual ~cSocketHTTPURL()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError Open()
    {
        eError error;

        if (!(error = m_socket.Create()))
        if (!(error = m_socket.Connect(m_host, m_port)))
            error = OpenContent(m_socket, m_chunked_content);

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        return m_socket.Close();
    }
};

/**
 **********************************************************************
 *  Class: cHTTPURIScheme
 *
 * Author: $author$
 *   Date: 6/7/2004
 **********************************************************************
 */
class cHTTPURIScheme
: public cURIScheme
{
public:
    typedef cURIScheme cIs;

    /**
     **********************************************************************
     * Constructor: cHTTPURIScheme
     *
     *      Author: $author$
     *        Date: 6/7/2004
     **********************************************************************
     */
    cHTTPURIScheme(const char *name)
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cHTTPURIScheme
     *
     *     Author: $author$
     *       Date: 6/7/2004
     **********************************************************************
     */
    virtual ~cHTTPURIScheme()
    {
    }

    /**
     **********************************************************************
     * Function: OnURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 6/7/2004
     **********************************************************************
     */
    virtual eError OnURISchemeSpecific
    (cURIInterface &uri, const char *scheme, int scheme_length,
     const char *scheme_specific, int scheme_specific_length)
    {
        return uri.OnGenericURISchemeSpecific
        (scheme_specific, scheme_specific_length);
    }

    /**
     **********************************************************************
     * Function: OpenURL
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual cURLInterface *OpenURL(cURIInterface &uri)
    {
        int host_length,port_length,path_length,query_length;
        const char *host,*port,*path,*query;
        eError error;
        cHTTPURL *url=0;

        if ((host = uri.GetURIHost(host_length)))
        if ((port = uri.GetURIPort(port_length)))
        if ((path = uri.GetURIPath(path_length)))
        if ((query = uri.GetURIQuery(query_length)))
        {
            if (port_length > 0)
            {
                int port_value;

                port_value = atoi(port);
                url = new cSocketHTTPURL
                (host, path, query, port_value);
            }
            else url = new cSocketHTTPURL
                 (host, path, query);

            if (url)
            if ((error = url->Open()))
            {
                delete url;
                url = 0;
            }
        }
        return url;
    }
    /**
     **********************************************************************
     * Function: CloseURL
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError CloseURL(cURLInterface &url)
    {
        eError error,error2;

        error = url.Close();

        if ((error2 = url.FreeInstance()))
        if (!error)
            error = error2;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cStaticHTTPURIScheme
 *
 * Author: $author$
 *   Date: 6/7/2004
 **********************************************************************
 */
class cStaticHTTPURIScheme
: public cHTTPURIScheme
{
public:
    typedef cHTTPURIScheme cIs;

    static cStaticHTTPURIScheme m_instance;

    /**
     **********************************************************************
     * Constructor: cStaticHTTPURIScheme
     *
     *      Author: $author$
     *        Date: 6/7/2004
     **********************************************************************
     */
    cStaticHTTPURIScheme(const char *name)
    : cIs(name) 
    {
        cStaticURISchemeSet::m_instance.Add(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cStaticHTTPURIScheme
     *
     *     Author: $author$
     *       Date: 6/7/2004
     **********************************************************************
     */
    virtual ~cStaticHTTPURIScheme()
    {
        cStaticURISchemeSet::m_instance.Delete(this);
    }
};

#endif /* ndef _CHTTPURISCHEME_HXX */
