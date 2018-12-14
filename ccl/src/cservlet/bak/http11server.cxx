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
 *   File: http11server.cxx
 *
 * Author: $author$
 *   Date: 11/11/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <stdlib.h>
#include "cverboseinterface.hxx"
#include "chttpservlettcplistenerthread.hxx"
#include "cthreadedtcplistener.hxx"
#include "cpipehttpservlet.hxx"
#include "ctcpendpoint.hxx"
#include "csockets.hxx"
#include "cinetaddress.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cPipeRouterHttpServlet
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cPipeRouterHttpServlet
: public cPipeHttpServlet
{
public:
    typedef cPipeHttpServlet cIs;

    /**
     **********************************************************************
     * Constructor: cPipeRouterHttpServlet
     *
     *      Author: $author$
     *        Date: 11/11/2004
     **********************************************************************
     */
    cPipeRouterHttpServlet
    (cVerboseInterface *verbose=0) 
    : cIs("pipeservlet", "routerservlet", verbose) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cPipeHttpServletTcpListenerThread
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cPipeHttpServletTcpListenerThread
: public cHttpServletTcpListenerThreadT
         <cPipeRouterHttpServlet>
{
public:
    typedef cHttpServletTcpListenerThreadT
            <cPipeRouterHttpServlet> cIs;

    /**
     **********************************************************************
     * Constructor: cPipeHttpServletTcpListenerThread
     *
     *      Author: $author$
     *        Date: 11/11/2004
     **********************************************************************
     */
    cPipeHttpServletTcpListenerThread
    (cTcpListenerInterface &tcp_listener, 
     int id=-1, cVerboseInterface *verbose=0)
    : cIs(tcp_listener, id, verbose)
    {
    }
};

/**
 **********************************************************************
 *  Class: cPipeHttpServletTcpListenerThreadFactory
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cPipeHttpServletTcpListenerThreadFactory
: public cHttpServletTcpListenerThreadFactoryT
         <cPipeHttpServletTcpListenerThread>
{
public:
    typedef cHttpServletTcpListenerThreadFactoryT
            <cPipeHttpServletTcpListenerThread> cIs;
};

/**
 **********************************************************************
 *  Class: cHttp11ServerMain
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMain
: virtual public cVerboseImplement,
  public cMain
{
public:
    typedef cVerboseImplement cVerboseIs;
    typedef cMain cIs;

    bool m_usage;
    bool m_overwrite;
    int m_port;
    const char *m_host;
    const char *m_output;
    const char *m_input;
    int m_threads;

    cMutex m_verbose_mutex;

    cInetAddress m_host_address;
    cTcpEndpoint m_tcp_endpoint;
    cPipeHttpServletTcpListenerThreadFactory m_thread_factory;
    cThreadedTcpListener m_threaded_tcp_listener;

    /**
     **********************************************************************
     * Constructor: cHttp11ServerMain
     *
     *      Author: $author$
     *        Date: 11/11/2004
     **********************************************************************
     */
    cHttp11ServerMain
    (const char *host="localhost", int port=80)
    : m_usage(false),
      m_overwrite(false),
      m_host(host),
      m_port(port),
      m_output(0),
      m_input(0),
      m_threads(1),
      m_tcp_endpoint(port),
      m_threaded_tcp_listener
      (m_tcp_endpoint, m_thread_factory, m_threads)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        eError error;

        if (m_usage)
            return OnUsage(argc, argv);

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
                m_threaded_tcp_listener.m_threads = m_threads;
                m_threaded_tcp_listener.SetVerbose(m_verbose);
                m_tcp_endpoint.SetVerbose(m_verbose);
                m_tcp_endpoint.SetAddress(m_host_address);
                m_tcp_endpoint.SetPort(m_port);
                m_tcp_endpoint.SetListener(&m_threaded_tcp_listener);

                if (!(error = m_tcp_endpoint.InitEndpoint()))
                {
                    if (!(error = m_tcp_endpoint.StartEndpoint()))
                    {
                        m_tcp_endpoint.FinishEndpoint();
                    }
                    m_tcp_endpoint.FinalEndpoint();
                }
                m_verbose_mutex.Close();
            }
            cSockets::Finalize();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 11/11/2004
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
     *     Date: 11/11/2004
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
     *     Date: 11/11/2004
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
     *     Date: 11/13/2004
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
} g_http11server_main;

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArg
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHttp11ServerMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHttp11ServerMainArg
     *
     *      Author: $author$
     *        Date: 11/11/2004
     **********************************************************************
     */
    cHttp11ServerMainArg(cHttp11ServerMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgVerbose ("v")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgVerbose
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgVerbose
    (cHttp11ServerMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.SetVerbose(&m_main);
        return argn;
    }
} g_http11server_main_verbose(g_http11server_main, "v");

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgOverwrite ("w")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgOverwrite
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgOverwrite
    (cHttp11ServerMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_overwrite = true;
        return argn;
    }
} g_http11server_main_overwrite(g_http11server_main, "w");

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgHost ("h")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgHost
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgHost
    (cHttp11ServerMain &p_main, const char *name)
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
} g_http11server_main_host(g_http11server_main, "h");

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgPort ("p")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgPort
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgPort
    (cHttp11ServerMain &p_main, const char *name)
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
} g_http11server_main_port(g_http11server_main, "p");

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgThreads ("t")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgThreads
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgThreads
    (cHttp11ServerMain &p_main, const char *name)
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
} g_http11server_main_threads(g_http11server_main, "t");

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgInput ("i")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgInput
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgInput
    (cHttp11ServerMain &p_main, const char *name)
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
        if (argn<argc)
            m_main.m_input = argv[++argn];
        return argn;
    }
} g_http11server_main_input(g_http11server_main, "i");

/**
 **********************************************************************
 *  Class: cHttp11ServerMainArgOutput ("o")
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cHttp11ServerMainArgOutput
: public cHttp11ServerMainArg
{
public:
    typedef cHttp11ServerMainArg cIs;

    cHttp11ServerMainArgOutput
    (cHttp11ServerMain &p_main, const char *name)
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
        if (argn<argc)
            m_main.m_output = argv[++argn];
        return argn;
    }
} g_http11server_main_output(g_http11server_main, "o");
