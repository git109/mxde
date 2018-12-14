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

    cHTTPMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHTTPMainArg
     *
     *      Author: $author$
     *        Date: 6/17/2004
     **********************************************************************
     */
    cHTTPMainArg(cHTTPMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
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

    cCharStream *m_input,*m_output,*m_send,*m_receive,*m_capture;

    const char *m_in_filename,*m_out_filename,*m_capture_filename;
    cCharFile m_in_file,m_out_file,m_capture_file;

    const char *m_host,*m_x_host;
    int m_port,m_x_port;
    cSocket m_socket;
    cSocket m_accept_socket;
    cSocket m_connect_socket;
    bool m_verbose,m_accept;

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
    : m_input(0),
      m_output(0),
      m_send(0), 
      m_receive(0),
      m_capture(0),
      m_host("localhost"),
      m_x_host(""),
      m_port(777),
      m_x_port(-1),
      m_verbose(false),
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
        m_send = m_output = &m_out;
        m_receive = m_input = &m_in;

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
        cMainArg *a;

        printf("usage: %s", argv[0]);

        if ((a = cMainArg::m_list.GetFirst()))
        do
        {
            a->OnUsage();
        }
        while ((a = a->GetNext()));

        printf("\n");
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
} g_http;

/**
 **********************************************************************
 *    Arg: "v"
 *
 *  Class: cHTTPMainArgVerbose
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgVerbose
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgVerbose(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_verbose = true;
        return argn;
    }
} g_http_verbose(g_http, "v");

/**
 **********************************************************************
 *    Arg: "h"
 *
 *  Class: cHTTPMainArgHost
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgHost
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgHost(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" host");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
            m_main.m_host = argv[++argn];
        return argn;
    }
} g_http_host(g_http, "h");

/**
 **********************************************************************
 *    Arg: "p"
 *
 *  Class: cHTTPMainArgPort
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgPort
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgPort(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" port");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_main.m_x_port = m_main.m_port = atoi(arg);
        return argn;
    }
} g_http_port(g_http, "p");

/**
 **********************************************************************
 *    Arg: "u"
 *
 *  Class: cHTTPMainArgURI
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgURI
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgURI(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" uri");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_main.m_http_request.SetURI(arg);

        return argn;
    }
} g_http_uri(g_http, "u");

/**
 **********************************************************************
 *    Arg: "c"
 *
 *  Class: cHTTPMainArgConnect
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgConnect
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgConnect(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        eError error;

        if (!(error = m_main.m_socket.Create()))
        if (!(error = m_main.m_socket.SetNoDelay()))
        if (!(error = m_main.m_socket.SetDontLinger()))
            error = m_main.m_socket.Connect
            (m_main.m_host, m_main.m_port);

        if (error)
        {
            printf
            ("Unable to connect to \"%s:%d\"\n", 
             m_main.m_host, m_main.m_port);
            return -error;
        }
        m_main.m_receive = m_main.m_send = &m_main.m_socket;
        return argn;
    }
} g_http_connect(g_http, "c");

/**
 **********************************************************************
 *    Arg: "l"
 *
 *  Class: cHTTPMainArgListen
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgListen
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgListen(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        eError error;

        if ((error = m_main.m_socket.Create()))
        {
            printf
            ("Unable to create socket\n");
            return -error;
        }
        if ((error = m_main.m_socket.Bind(m_main.m_host, m_main.m_port)))
        {
            printf
            ("Unable to bind to host \"%s\" port %d\n",
             m_main.m_host, m_main.m_port);
            return -error;
        }
        if ((error = m_main.m_socket.Listen()))
        {
            printf
            ("Unable to listen at host \"%s\" port %d\n",
             m_main.m_host, m_main.m_port);
            return -error;
        }
        if ((error = m_main.m_socket.Accept(m_main.m_accept_socket)))
        {
            printf
            ("Unable to accept connection at host \"%s\" port %d\n",
             m_main.m_host, m_main.m_port);
            return -error;
        }
        m_main.m_receive = m_main.m_send = &m_main.m_accept_socket;
        return argn;
    }
} g_http_listen(g_http, "l");

/**
 **********************************************************************
 *    Arg: "a"
 *
 *  Class: cHTTPMainArgAccept
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgAccept
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgAccept(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        int length;

        if (m_main.m_receive)
        if (0 < (length = m_main.m_http_request.Receive(*m_main.m_receive)))
        {
            cHTTPRequest::cLine &line=m_main.m_http_request.GetLine();
            cHTTPHeader &header=m_main.m_http_request.GetHeader();

            line.Put(m_main.m_out);
            header.Put(m_main.m_out);
        }
        return argn;
    }
} g_http_accept(g_http, "a");

/**
 **********************************************************************
 *    Arg: "s"
 *
 *  Class: cHTTPMainArgSend
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgSend
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgSend(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        int length;
        const char *buffer;

        if (m_main.m_send)
        if (0 < (length = m_main.m_buffer.CopyL(m_main.m_host,":",0)))
        if (0 < (length = m_main.m_buffer.WriteInt(m_main.m_port)))
        if ((buffer = m_main.m_buffer.GetBuffer(length)))
        {
            cHTTPHeader::cField host
            (cHTTPHeader::cField::cType::e_HOST, buffer);
            cHTTPHeader::cField connection
            (cHTTPHeader::cField::cType::e_CONNECTION,
             cHTTPHeader::cField::cType::cConnection::e_CLOSE);

            m_main.m_http_request.AddField(host);
            m_main.m_http_request.AddField(connection);
            m_main.m_http_request.Send(*m_main.m_send);
            m_main.m_http_request.DeleteField(connection);
            m_main.m_http_request.DeleteField(host);
        }
        return argn;
    }
} g_http_send(g_http, "s");

/**
 **********************************************************************
 *    Arg: "r"
 *
 *  Class: cHTTPMainArgReceive
 *
 * Author: $author$
 *   Date: 6/18/2004
 **********************************************************************
 */
class cHTTPMainArgReceive
: public cHTTPMainArg
{
public:
    typedef cHTTPMainArg cIs;

    cHTTPMainArgReceive(cHTTPMain &http_main, const char *name)
    : cIs(http_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (m_main.m_receive)
        {
            cCharStream &receive=*m_main.m_receive;
            cHTTPChunkedContent chunked_content(receive);
            cCharStream *content;

            if ((content = m_main.m_http_response.Receive
                (receive, chunked_content)))
            if (m_main.m_output)
            {
                int c,content_length;

                if (m_main.m_verbose)
                    m_main.m_http_response.Send(*m_main.m_output);

                if (0 > (content_length = m_main.m_http_response.GetContentLength()))
                {
                    while (0 <= (c = content->Getc()))
                        m_main.m_output->Putc(c);
                }
                else
                {
                    while (0 < content_length--)
                    {
                        if (0 > (c = content->Getc()))
                            break;
                        m_main.m_output->Putc(c);
                    }
                }
            }
        }
        return argn;
    }
} g_http_receive(g_http, "r");

