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
 *   File: servlet.cxx
 *
 * Author: $author$
 *   Date: 11/4/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cverboseinterface.hxx"
#include "chttpmainservlet.hxx"
#include "chttp11processor.hxx"
#include "cfileinputstream.hxx"
#include "cfileoutputstream.hxx"
#include "chttpservlettcplistenerthread.hxx"
#include "cthreadedtcplistener.hxx"
#include "ctcpendpoint.hxx"
#include "csockets.hxx"
#include "cinetaddress.hxx"
#include "cmutex.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cHttpMainServlet
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
cHttpServletInterface *cHttpMainServlet::m_instance=0;

/**
 **********************************************************************
 *  Class: cHttpServletMain
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpServletMain
: virtual public cVerboseImplement,
  public cMain
{
public:
    typedef cMain cIs;

    const char *m_class;
    int m_number;
    bool m_usage;
    bool m_overwrite;
    bool m_server;
    int m_forward;
    int m_port;
    const char *m_host;
    const char *m_input;
    const char *m_output;
    int m_threads;

    cMutex m_verbose_mutex;
    cConnection m_connection;
    cHttpMainServlet m_servlet;
    cHttp11Processor m_processor;
    cInetAddress m_host_address;
    cInetSocketAddress m_socket_address;
    cInetSocket m_listen_socket;
    cInetSocket m_accept_socket;
    cTcpEndpoint m_endpoint;
    cHttpServletTcpListenerThreadFactory m_thread_factory;
    cThreadedTcpListener m_threaded_listener;

    /**
     **********************************************************************
     * Constructor: cHttpServletMain
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cHttpServletMain
    (const char *host="localhost", int port=80)
    : m_usage(false),
      m_overwrite(false),
      m_server(false),
      m_forward(-1),
      m_host(host),
      m_port(port),
      m_output(0),
      m_input(0),
      m_number(0),
      m_threads(1),
      m_servlet("main",-1,true),
      m_processor(m_connection, m_servlet),
      m_thread_factory(m_servlet),
      m_threaded_listener
      (m_endpoint, m_thread_factory, m_threads),
      m_class("cHttpServletMain")
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        int result = 0;
        eError error;
        FILE *in,*out;

        if (m_usage)
            return OnUsage(argc, argv);

        if (m_server)
            return OnServer(argc, argv);

        if (0 < m_forward)
            return OnForward(argc, argv);

        if ((error = m_servlet.Init()))
            return 1;

        do
        {
            if (m_input)
            if ((error = m_in.Open(m_input, "rb")))
            {
                result = 1;
                break;
            }

            if (NULL != (in = m_in.GetHandle()))
            if (NULL != (out = m_out.GetHandle()))
            {
                cFileInputStream input(in);
                cFileOutputStream output(out);

                do
                {
                    if ((error = m_processor
                        .Process(input, output)))
                        break;
                }
                while (0 && m_connection.KeepAlive());
            }

            if (m_input)
                m_in.Close();

            if (m_number > 0)
                --m_number;

        }
        while (m_number > 0);

        if ((error = m_servlet.Final()))
        if (!result)
            result = 1;

        return result;
    }
    /**
     **********************************************************************
     * Function: OnServer
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual int OnServer(int argc, char **argv)
    {
        int result = 0;
        eError error;

        if (!(error = cSockets::Initialize()))
        {
            m_host_address.SetByInAddrAny();

            if (m_host)
            if (m_host[0])
            if (m_host_address.GetNullAddress()
                == m_host_address.GetByName(m_host))
                error = e_ERROR_FAILED;

            if (!error)
            if (!(error = m_verbose_mutex.Create()))
            {
                m_thread_factory.SetVerbose(m_verbose);
                m_threaded_listener.m_threads = m_threads;
                m_threaded_listener.SetVerbose(m_verbose);
                m_endpoint.SetVerbose(m_verbose);
                m_endpoint.SetAddress(m_host_address);
                m_endpoint.SetPort(m_port);
                m_endpoint.SetListener(&m_threaded_listener);

                if (!(error = m_endpoint.InitEndpoint()))
                {
                    if (!(error = m_endpoint.StartEndpoint()))
                    {
                        m_endpoint.FinishEndpoint();
                    }
                    m_endpoint.FinalEndpoint();
                }
                m_verbose_mutex.Close();
            }
            cSockets::Finalize();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnForward
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual int OnForward(int argc, char **argv)
    {
        int len, result = 0;
        BYTE b;
        bool newline;
        bool keepalive;
        eError error;
        cInetSocket socket;

        if (!(error = cSockets::Initialize()))
        {
            m_host_address.SetByInAddrAny();

            if (m_host)
            if (m_host[0])
            if (m_host_address.GetNullAddress()
                == m_host_address.GetByName(m_host))
                error = e_ERROR_FAILED;

            if (!error)
            if (!(error = m_verbose_mutex.Create()))
            {
                if (!(error = m_listen_socket.Open()))
                {
                    m_listen_socket.SetKeepAlive(true);
                    m_listen_socket.SetNoDelay(true);
                    m_listen_socket.SetDontLinger(true);

                    m_socket_address.Set(m_host_address, m_port);

                    if (!(error = m_listen_socket.Bind(m_socket_address)))
                    if (!(error = m_listen_socket.Listen()))
                    {
                        if (m_verbose)
                            m_verbose->VerboseFormatted
                            ("%s: Listening at port %d...\n", m_class, m_port);

                        m_socket_address.Set
                        (m_host_address, m_forward);

                        do
                        {
                        if (!(error = m_listen_socket
                            .Accept(m_accept_socket)))
                        {
                            if (m_verbose)
                                m_verbose->VerboseFormatted
                                ("%s: ...Accepted connection at port %d\n", m_class, m_port);

                            m_accept_socket
                            .UpdateAcceptContext(m_listen_socket);

                            keepalive = false;

                            do
                            {
                                while (0 < (len = m_accept_socket.Receive(&b, 1)))
                                {
                                    if (m_verbose)
                                        m_verbose->VerboseFormatted
                                        ("%c", b);

                                    if ('\n' == b)
                                    if (newline)
                                    {
                                        keepalive = true;
                                        m_accept_socket.Send
                                        ((BYTE*)"HTTP/1.1 200\r\n"
                                         "Content-Type: text/plain\r\n"
                                         "Transfer-Encoding: chunked\r\n"
                                         "\r\n"
                                         "11\r\n"
                                         "123456789abcdef\r\n"
                                         "\r\n0\r\n");                                    
                                        break;
                                    }
                                    else newline = true;
                                    else if ('\r' != b)
                                            newline = false;
                                }
                            }
                            while (keepalive);
                            /*
                            if (!(error = socket.Open()))
                            {
                                if (!(error = socket.Connect
                                    (m_socket_address)))
                                {
                                    if (m_verbose)
                                        m_verbose->VerboseFormatted
                                        ("%s: ...Connted to port %d\n", m_class, m_forward);

                                    newline = false;
                                    while (0 < (len = m_accept_socket.Receive(&b, 1)))
                                    {
                                        if (m_verbose)
                                            m_verbose->VerboseFormatted
                                            ("%c", b);

                                        socket.Send(&b, 1);

                                        if ('\n' == b)
                                        if (newline)
                                            break;
                                        else newline = true;
                                        else if ('\r' != b)
                                                newline = false;
                                    }

                                    while (0 < (len = socket.Receive(&b, 1)))
                                    {
                                        if (m_verbose)
                                            m_verbose->VerboseFormatted
                                            ("%c", b);

                                        m_accept_socket.Send(&b, 1);
                                    }
                                    
                                }
                                socket.Close();
                                */
                            }
                            m_accept_socket.Close();
                        }
                        if (m_threads > 0)
                        if (1 > (--m_threads))
                            break;
                        }
                        while (m_threads >= 0);
                    }
                    m_listen_socket.Close();
                }
                m_verbose_mutex.Close();
            }
            cSockets::Finalize();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 11/4/2004
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
     *     Date: 11/4/2004
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
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
    /**
     **********************************************************************
     * Function: VVerboseFormatted
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual int VVerboseFormatted
    (const char *format, va_list va) 
    {
        int result;
        eError error;
        
        if ((error = m_verbose_mutex.Acquire()))
            result = -error;
        else
        {
            result = vprintf(format, va);
            m_verbose_mutex.Release();
        }
        return result;
    }
} g_httpservlet_main;

/**
 **********************************************************************
 *  Class: cHttpServletMainArg
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpServletMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHttpServletMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHttpServletMainArg
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cHttpServletMainArg
    (cHttpServletMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletMainArgVerbose ("v")
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpServletMainArgVerbose
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgVerbose
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.SetVerbose(&m_main);
        return argn;
    }
} g_servlet_verbose(g_httpservlet_main, "v");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgOverwrite ("w")
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpServletMainArgOverwrite
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgOverwrite
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_overwrite = true;
        return argn;
    }
} g_servlet_overwrite(g_httpservlet_main, "w");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgRepeat ("n")
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
class cHttpServletMainArgRepeat
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgRepeat
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s number", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc-1)
        if ((arg = argv[++argn]))
            m_main.m_number = atoi(arg);

        return argn;
    }
} g_httpservlet_repeat(g_httpservlet_main, "n");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgServer ("s")
 *
 * Author: $author$
 *   Date: 11/15/2004
 **********************************************************************
 */
class cHttpServletMainArgServer
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgServer
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_server = true;
        return argn;
    }
} g_httpservlet_main_server(g_httpservlet_main, "s");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgHost ("h")
 *
 * Author: $author$
 *   Date: 11/15/2004
 **********************************************************************
 */
class cHttpServletMainArgHost
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgHost
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s host", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        {
            m_main.m_host = argv[++argn];
            if (!strcmp("*", m_main.m_host))
                m_main.m_host = "";
        }
        return argn;
    }
} g_httpservlet_main_host(g_httpservlet_main, "h");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgPort ("p")
 *
 * Author: $author$
 *   Date: 11/15/2004
 **********************************************************************
 */
class cHttpServletMainArgPort
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgPort
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s port", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_main.m_port = atoi(arg);
        return argn;
    }
} g_httpservlet_main_port(g_httpservlet_main, "p");
/**
 **********************************************************************
 *  Class: cHttpServletMainArgForward ("f")
 *
 * Author: $author$
 *   Date: 11/16/2004
 **********************************************************************
 */
class cHttpServletMainArgForward
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgForward
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s port", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_main.m_forward = atoi(arg);
        return argn;
    }
} g_httpservlet_main_forward(g_httpservlet_main, "f");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgthreads ("t")
 *
 * Author: $author$
 *   Date: 11/15/2004
 **********************************************************************
 */
class cHttpServletMainArgthreads
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgthreads
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s threads", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_main.m_threads = atoi(arg);
        return argn;
    }
} g_httpservlet_main_threads(g_httpservlet_main, "t");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgInput ("i")
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpServletMainArgInput
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgInput
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s file", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc-1)
            m_main.m_input = argv[++argn];
        return argn;
    }
} g_servlet_input(g_httpservlet_main, "i");

/**
 **********************************************************************
 *  Class: cHttpServletMainArgOutput ("o")
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpServletMainArgOutput
: public cHttpServletMainArg
{
public:
    typedef cHttpServletMainArg cIs;

    cHttpServletMainArgOutput
    (cHttpServletMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s file", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc-1)
            m_main.m_output = argv[++argn];
        return argn;
    }
} g_servlet_output(g_httpservlet_main, "o");
