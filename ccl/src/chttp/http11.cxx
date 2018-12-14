/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: http11.cxx
 *
 * Author: $author$
 *   Date: 12/31/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpmainservlet.hxx"
#include "chttp11processor.hxx"
#include "chttp11connectionhandler.hxx"
#include "ctcplistener.hxx"
#include "ctcpendpoint.hxx"
#include "cinetsocket.hxx"
#include "cinetaddress.hxx"
#include "csockets.hxx"
#include "cverboseinterface.hxx"
#include "cfileinputstream.hxx"
#include "cfileoutputstream.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cHttp11Main
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11Main
: virtual public cVerboseImplement,
  public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    bool m_server;
    int m_port;
    const char *m_class;
    const char *m_host;
    const char *m_input;
    const char *m_output;

    cInetAddress m_host_address;
    cInetSocketAddress m_socket_address;
    cInetSocket m_accept_socket;
    cTcpConnection m_connection;
    cHttpMainServlet m_servlet;
    cHttp11Processor m_processor;
    cHttp11ConnectionHandler m_connection_handler;
    cTcpEndpoint m_endpoint;
    cTcpListener m_listener;

    /**
     **********************************************************************
     * Constructor: cHttp11Main
     *
     *      Author: $author$
     *        Date: 12/31/2005
     **********************************************************************
     */
    cHttp11Main
    (const char *host=0, int port=80)
    : m_class("cHttp11Main"),
      m_usage(false),
      m_server(false),
      m_host(host),
      m_port(port),
      m_output(0),
      m_input(0),
      m_servlet("main",-1,true),
      m_connection(m_accept_socket),
      m_processor(m_connection, m_servlet),
      m_connection_handler(m_connection, m_processor),
      m_listener(m_endpoint, m_connection_handler)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 12/31/2005
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        int result = 0;
        eError error;
        FILE *in,*out;

        if (m_usage)
            return OnUsage(argc, argv);

        m_processor.SetVerbose(m_verbose);

        if (m_server)
            return OnServer(argc, argv);

        if ((error = m_servlet.Init()))
            return 1;

        if (m_input)
        if ((error = m_in.Open(m_input, "rb")))
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: Unable to open \"%s\"\n", m_class, m_input);
            return result = 1;
        }

        if (NULL != (in = m_in.GetHandle()))
        if (NULL != (out = m_out.GetHandle()))
        {
            cFileInputStream input(in);
            cFileOutputStream output(out);

            do
            {
                if ((error = m_processor.Process(input, output)))
                    break;
            }

            while (0 && m_connection.KeepAlive());
        }

        if (m_input)
            m_in.Close();

        if ((error = m_servlet.Final()))
        if (!result)
            result = 1;

        return result;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 12/31/2005
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
     * Function: OnServer
     *
     *   Author: $author$
     *     Date: 12/31/2005
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
            {
                m_listener.SetVerbose(m_verbose);

                m_endpoint.SetVerbose(m_verbose);
                m_endpoint.SetAddress(m_host_address);
                m_endpoint.SetPort(m_port);
                m_endpoint.SetListener(&m_listener);

                if (!(error = m_endpoint.InitEndpoint()))
                {
                    if (!(error = m_servlet.Init()))
                    {
                        if (!(error = m_endpoint.StartEndpoint()))
                        {
                            m_endpoint.FinishEndpoint();
                        }
                        m_servlet.Final();
                    }
                    m_endpoint.FinalEndpoint();
                }
            }
            cSockets::Finalize();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 12/31/2005
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
     *     Date: 12/31/2005
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
        int result = vprintf(format, va);
        return result;
    }
    /**
     **********************************************************************
     * Function: Verbose
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int Verbose
    (const char *buffer, int length=-1) 
    {
        int result;

        if (0 > length)
            length = strlen(buffer);

        result = fwrite(buffer, 1, length, stdout);
        return result;
    }
} g_http11_main;

/**
 **********************************************************************
 *  Class: cHttp11MainArg
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHttp11Main &m_main;

    /**
     **********************************************************************
     * Constructor: cHttp11MainArg
     *
     *      Author: $author$
     *        Date: 12/31/2005
     **********************************************************************
     */
    cHttp11MainArg(cHttp11Main &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttp11MainArgClient ("c")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgClient
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgClient
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_server = false;
        return argn;
    }
} g_http11_main_client(g_http11_main, "c");

/**
 **********************************************************************
 *  Class: cHttp11MainArgServer ("s")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgServer
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgServer
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_server = true;
        return argn;
    }
} g_http11_main_server(g_http11_main, "s");

/**
 **********************************************************************
 *  Class: cHttp11MainArgRead ("r")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgRead
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgRead
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_http11_main_read(g_http11_main, "r");

/**
 **********************************************************************
 *  Class: cHttp11MainArgWrite ("w")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgWrite
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgWrite
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_http11_main_write(g_http11_main, "w");

/**
 **********************************************************************
 *  Class: cHttp11MainArgInput ("i")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgInput
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgInput
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s filename", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc-1)
            m_main.m_input = argv[++argn];
        return argn;
    }
} g_http11_main_input(g_http11_main, "i");

/**
 **********************************************************************
 *  Class: cHttp11MainArgOutput ("o")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgOutput
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgOutput
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        printf(" -%s filename", m_name);
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc-1)
            m_main.m_output = argv[++argn];
        return argn;
    }
} g_http11_main_output(g_http11_main, "o");

/**
 **********************************************************************
 *  Class: cHttp11MainArgHost ("h")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgHost
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgHost
    (cHttp11Main &p_main, const char *name)
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
        if ((arg = argv[++argn]))
        if (strcmp("*", arg))
            m_main.m_host = arg;
        else m_main.m_host = 0;
        return argn;
    }
} g_http11_main_host(g_http11_main, "h");

/**
 **********************************************************************
 *  Class: cHttp11MainArgPort ("p")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgPort
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgPort
    (cHttp11Main &p_main, const char *name)
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
} g_http11_main_port(g_http11_main, "p");

/**
 **********************************************************************
 *  Class: cHttp11MainArgVerbose ("v")
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cHttp11MainArgVerbose
: public cHttp11MainArg
{
public:
    typedef cHttp11MainArg cIs;

    cHttp11MainArgVerbose
    (cHttp11Main &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.SetVerbose(&m_main);
        return argn;
    }
} g_http11_main_verbose(g_http11_main, "v");
