/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$.
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
 *   File: socket.cxx
 *
 * Author: $author$
 *   Date: 3/12/2006
 *
 *    $Id$
 **********************************************************************
 */
#include "cinetendpointinterface.hxx"
#include "cnetendpointinterface.hxx"
#include "cinetaddress.hxx"
#include "ccharstring.hxx"
#include "csockets.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cSocketMain
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    cCharString m_host;

    /**
     **********************************************************************
     * Constructor: cSocketMain
     *
     *      Author: $author$
     *        Date: 3/12/2006
     **********************************************************************
     */
    cSocketMain()
    : m_usage(false),
      m_host("localhost")
    {
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int result = 1;
        eError error;

        if (!(error = cSockets::Initialize()))
        {
            result = cIs::OnMain(argc, argv);
            cSockets::Finalize();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        cInetAddress addr(m_host, 0);

        if (m_usage)
            return OnUsage(argc, argv);

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 3/12/2006
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
     *     Date: 3/12/2006
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
     *     Date: 3/12/2006
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_socket_main;

/**
 **********************************************************************
 *  Class: cSocketMainArg
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cSocketMain &m_main;

    /**
     **********************************************************************
     * Constructor: cSocketMainArg
     *
     *      Author: $author$
     *        Date: 3/12/2006
     **********************************************************************
     */
    cSocketMainArg(cSocketMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cSocketMainArgHost ("h")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgHost
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgHost
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn+1 < argc)
            m_main.m_host.SetChars(argv[++argn]);
        return argn;
    }
} g_socket_main_host(g_socket_main, "h");

/**
 **********************************************************************
 *  Class: cSocketMainArgPort ("p")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgPort
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgPort
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_socket_main_port(g_socket_main, "p");

/**
 **********************************************************************
 *  Class: cSocketMainArgListen ("l")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgListen
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgListen
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_socket_main_listen(g_socket_main, "l");

/**
 **********************************************************************
 *  Class: cSocketMainArgConnect ("c")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgConnect
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgConnect
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_socket_main_connect(g_socket_main, "c");

/**
 **********************************************************************
 *  Class: cSocketMainArgInput ("i")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgInput
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgInput
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_socket_main_input(g_socket_main, "i");

/**
 **********************************************************************
 *  Class: cSocketMainArgOutput ("o")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgOutput
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgOutput
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_socket_main_output(g_socket_main, "o");

/**
 **********************************************************************
 *  Class: cSocketMainArgVerbose ("v")
 *
 * Author: $author$
 *   Date: 3/12/2006
 **********************************************************************
 */
class cSocketMainArgVerbose
: public cSocketMainArg
{
public:
    typedef cSocketMainArg cIs;

    cSocketMainArgVerbose
    (cSocketMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_socket_main_verbose(g_socket_main, "v");
