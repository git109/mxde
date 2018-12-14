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
 *   File: http.cxx
 *
 * Author: $author$
 *   Date: 3/9/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cmainarg.hxx"
#include "cmaint.hxx"
#include "cmain.hxx"
#include "chttp.hxx"
#include "csocket.hxx"

class cHTTPMain;

/**
 **********************************************************************
 *  Class: cHTTPMainArg
 *
 * Author: $author$
 *   Date: 6/17/2004
 **********************************************************************
 */
class cHTTPMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHTTPMain &m_http;

    /**
     **********************************************************************
     * Constructor: cHTTPMainArg
     *
     *      Author: $author$
     *        Date: 6/17/2004
     **********************************************************************
     */
    cHTTPMainArg(cHTTPMain &http, const char *name)
    : cIs(name),
      m_http(http)
    {
    }
};

/**
 **********************************************************************
 *  Main: cHTTPMain
 *
 * Author: $author$
 *   Date: 3/9/2004
 **********************************************************************
 */
class cHTTPMain
: public cMain
{
public:
    typedef cMain cIs;

    cCharBuffer m_buffer;

    cCharStream *m_send,*m_receive,*m_capture;

    const char *m_capture_filename;
    cCharFile m_capture_file;

    const char *m_host,*m_x_host;
    int m_port,m_x_port;
    cSocket m_socket;
    cSocket m_accept_socket;
    cSocket m_connect_socket;
    bool m_accept;

    cHTTPHeader m_http_header;
    cHTTPRequest m_http_request;
    cHTTPResponse m_http_response;

    /**
     **********************************************************************
     * Constructor: cHTTPMain
     *
     *      Author: $author$
     *        Date: 3/9/2004
     **********************************************************************
     */
    cHTTPMain()
    : m_send(0), 
      m_receive(0),
      m_capture(0),
      m_host("localhost"),
      m_x_host(""),
      m_port(777),
      m_x_port(-1),
      m_accept(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int result;
        m_send = &m_out;
        m_receive = &m_in;

        if (argc < 2)
            return OnUsage(argc, argv);

        result =  cIs::OnMain(argc, argv);

        if (m_socket.GetIsOpen())
            m_socket.Close();

        return result;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int OnUsage(int argc, char **argv)
    {
        int result=0;

        printf("usage: %s -h host -p port -f file -c -s -r -l\n", argv[0]);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        cMainArg *a;

        if ((a = cMainArg::m_list.FindFirstByName(arg)))
            return a->OnMainArgSwitch
            (args, argn, arg, argc, argv);

        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int xOnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        const char *buffer;
        int c,length;
        eError error;

        if (!strcmp(arg,"c"))
        {
            if (!(error = m_socket.Create()))
            if (!(error = m_socket.SetNoDelay()))
            if (!(error = m_socket.SetDontLinger()))
                error = m_socket.Connect(m_host, m_port);

            if (error)
            {
                printf("Unable to connect to \"%s:%d\"\n", m_host, m_port);
                return -error;
            }
            m_receive = m_send = &m_socket;
            m_accept = false;
        }
        else if (!strcmp(arg,"l"))
        {
            if ((error = m_socket.Create()))
            {
                printf
                ("Unable to create socket\n");
                return -error;
            }
            if ((error = m_socket.Bind(m_host, m_port)))
            {
                printf
                ("Unable to bind to host \"%s\" port %d\n",
                 m_host, m_port);
                return -error;
            }
            if ((error = m_socket.Listen()))
            {
                printf
                ("Unable to listen at host \"%s\" port %d\n",
                 m_host, m_port);
                return -error;
            }
            if ((error = m_socket.Accept(m_accept_socket)))
            {
                printf
                ("Unable to accept connection at host \"%s\" port %d\n",
                 m_host, m_port);
                return -error;
            }
            m_receive = m_send = &m_accept_socket;
            m_accept = true;
        }
        else if (!strcmp(arg,"s"))
        {
            if (m_send)
            if (0 < (length = m_buffer.CopyL(m_host,":",0)))
            if (0 < (length = m_buffer.WriteInt(m_port)))
            if ((buffer = m_buffer.GetBuffer(length)))
            {
                cHTTPHeader::cField host
                (cHTTPHeader::cField::cType::e_HOST, buffer);
                cHTTPHeader::cField connection
                (cHTTPHeader::cField::cType::e_CONNECTION,
                 cHTTPHeader::cField::cType::cConnection::e_CLOSE);

                m_http_request.m_header.AddField(host);
                m_http_request.m_header.AddField(connection);
                m_http_request.Send(*m_send);
                m_http_request.m_header.DeleteField(connection);
                m_http_request.m_header.DeleteField(host);
            }
        }
        else if (!strcmp(arg,"r"))
        {
            if (m_receive)
            if (m_accept)
            {
                if (0 < (length = m_http_request.Receive(*m_receive)))
                {
                    cHTTPRequest::cLine &line=m_http_request.GetLine();
                    cHTTPHeader &header=m_http_request.GetHeader();
                    cHTTPHeader::cField *field;
                    const char *name,*value;
                    int namelen,valuelen;

                    if (m_x_host)
                    if (m_x_host[0])
                    if ((name = cHTTPHeader::cField::cType::GetName
                        (cHTTPHeader::cField::cType::e_HOST)))
                    if ((field = header.GetFirstFieldByName(name)))
                        field->SetValue(m_x_host);

                    line.Put(m_out);
                    header.Put(m_out);

                    if ((field = header.GetFirstField()))
                    do
                    {

                        if ((name = field->GetName(namelen)))
                        if ((value = field->GetValue(valuelen)))
                        {
                            printf("field \"%s\" = \"%s\"\n", name, value);
                        }
                    }
                    while ((field = field->GetNext()));

                    if (m_x_host)
                    if (m_x_host[0])
                    if (!(error = m_connect_socket.Create()))
                    {
                        if (!(error = m_connect_socket.SetNoDelay()))
                        if (!(error = m_connect_socket.SetDontLinger()))
                        if (!(error = m_connect_socket.Connect(m_x_host, m_x_port)))
                        if (0 < (length = m_http_request.Send(m_connect_socket)))
                        {
                            cHTTPChunkedContent chunked_content(m_connect_socket);
                            cCharStream *content;
                            int content_length;

                            if ((content = m_http_response.Receive(m_connect_socket, chunked_content)))
                            {
                                cHTTPHeader &header=m_http_response.GetHeader();

                                if (m_capture)
                                if (0 > (content_length = header.GetContentLength()))
                                {
                                }
                                else
                                {
                                    for (int i=0; i<content_length; i++)
                                    {
                                        if (0 > (c = content->Getc()))
                                            break;

                                        m_capture->Putc(c);
                                    }
                                }
                            }
                        }
                        m_connect_socket.Close();
                    }
                }
            }
            else
            {
                cHTTPChunkedContent chunked_content(*m_receive);
                cCharStream *content;

                if ((content = m_http_response.Receive
                    (*m_receive, chunked_content)))
                while (0 <= (c = content->Getc()))
                    putc(c, stdout);
            }
        }
        else if (!strcmp(arg,"g"))
        {
            if (m_receive)
            {
                while (0 <= (c = m_receive->Getc()))
                    putc(c, stdout);
            }
        }
        else if (argn < argc)
        {
            if (!strcmp(arg,"f"))
            {
                if ((m_capture_filename = argv[++argn]))
                if (!strcmp("-", m_capture_filename))
                    m_capture = &m_out;
                else
                {
                    if ((error = m_capture_file.Open(m_capture_filename, "w")))
                        printf("Unable to open file \"%s\"\n", m_capture_filename);

                    else m_capture = &m_capture_file;
                }
            }
            else if (!strcmp(arg,"h"))
            {
                m_host = argv[++argn];
            }
            else if (!strcmp(arg,"x"))
            {
                m_x_host = argv[++argn];
            }
            else if (!strcmp(arg,"p"))
            {
                if ((arg = argv[++argn]))
                    m_x_port = m_port = atoi(arg);
            }
            else if (!strcmp(arg,"y"))
            {
                if ((arg = argv[++argn]))
                    m_x_port = atoi(arg);
            }
            else if (!strcmp(arg,"u"))
            {
                if ((arg = argv[++argn]))
                    m_http_request.SetURI(arg);
            }
        }
        return argn;
    }
} g_http;

class cHTTPMainArgHost
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgHost(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_http_host(g_http, "h");

class cHTTPMainArgPort
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgPort(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_http_port(g_http, "p");

