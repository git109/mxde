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
 *   File: httpthrow.cxx
 *
 * Author: $author$
 *   Date: 11/8/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpstream.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"
#include "csocket.hxx"

/**
 **********************************************************************
 *  Class: cHTTPThrowMain
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    bool m_verbose;
    bool m_overwrite;
    bool m_raw;
    int m_port;
    const char *m_host;
    const char *m_output;
    const char *m_input;
    char m_verbose_char[8];

    cSocket m_socket;

    /**
     **********************************************************************
     * Constructor: cHTTPThrowMain
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cHTTPThrowMain
    (const char *host="localhost", 
     int port=80, bool verbose=false)
    : m_usage(false),
      m_verbose(verbose),
      m_overwrite(false),
      m_raw(false),
      m_host(host),
      m_port(port),
      m_output(0),
      m_input(0)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        FILE *in=0,*out=0;
        eError error;

        if (m_usage)
            return OnUsage(argc, argv);

        if (!(error = m_socket.Create()))
        {
            if (m_verbose)
                printf
                ("Connecting to host \"%s\" port %d...\n",
                 m_host, m_port);

            if ((error = m_socket.Connect(m_host, m_port)))
            {
                if (m_verbose)
                    printf
                    ("...Unable to Connect to host \"%s\" port %d\n",
                     m_host, m_port);
            }
            else
            {
                if (m_verbose)
                    printf
                    ("...Connected to host \"%s\" port %d\n",
                     m_host, m_port);

                if (m_input)
                {
                    in = m_in.GetHandle();

                    if ((error = m_in.Open(m_input, "rb")))
                    {
                        m_in.Attach(in);
                        in = 0;
                    }
                }

                if (m_output)
                {
                    out = m_out.GetHandle();

                    if (!(error = m_out.Open(m_output, "rb")))
                    {
                        m_out.Close();

                        if (!m_overwrite)
                        {
                            m_out.Attach(out);
                            out = 0;
                        }
                    }

                    if (out)
                    if ((error = m_out.Open(m_output, "wb")))
                    {
                        m_out.Attach(out);
                        out = 0;
                    }
                }

                OnConnected(m_socket);

                if (out)
                {
                    m_out.Close();
                    m_out.Attach(out);
                }

                if (in)
                {
                    m_in.Close();
                    m_in.Attach(in);
                }
            }
            m_socket.Close();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnConnected
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual void OnConnected(cSocket &socket)
    {
        cHTTPStream http(socket);
        int c, length;

        socket.WriteStream(m_in);

        if (m_raw)
            m_out.WriteStream(socket);

        else if (m_verbose)
        {
            while (0 <= (c = http.Getc()))
            {
                length = VerboseChar(c);
                m_out.Write(m_verbose_char, length);
            }
        }
        else m_out.WriteStream(http);
    }
    /**
     **********************************************************************
     * Function: VerboseChar
     *
     *   Author: $author$
     *     Date: 11/16/2004
     **********************************************************************
     */
    int VerboseChar(int c)
    {
        int length;

        switch(c)
        {
        case '\r':
            memcpy(m_verbose_char, "<CR>", length=4);
            break;

        case '\n':
            memcpy(m_verbose_char, "<LF>\n", length=5);
            break;

        default:
            m_verbose_char[(length=1)-1] = c;
        }

        m_verbose_char[length] = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 11/8/2004
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
     *     Date: 11/8/2004
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
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_httpthrow_main;

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArg
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHTTPThrowMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHTTPThrowMainArg
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cHTTPThrowMainArg(cHTTPThrowMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgVerbose ("v")
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArgVerbose
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgVerbose
    (cHTTPThrowMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_verbose = true;
        return argn;
    }
} g_httpthrow_main_verbose(g_httpthrow_main, "v");

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgRaw ("r")
 *
 * Author: $author$
 *   Date: 11/16/2004
 **********************************************************************
 */
class cHTTPThrowMainArgRaw
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgRaw
    (cHTTPThrowMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_raw = true;
        return argn;
    }
} g_httpthrow_main_raw(g_httpthrow_main, "r");

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgOverwrite ("w")
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArgOverwrite
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgOverwrite
    (cHTTPThrowMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_overwrite = true;
        return argn;
    }
} g_httpthrow_main_overwrite(g_httpthrow_main, "w");

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgHost ("h")
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArgHost
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgHost
    (cHTTPThrowMain &p_main, const char *name)
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
            m_main.m_host = argv[++argn];
        return argn;
    }
} g_httpthrow_main_host(g_httpthrow_main, "h");

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgPort ("p")
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArgPort
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgPort
    (cHTTPThrowMain &p_main, const char *name)
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
} g_httpthrow_main_port(g_httpthrow_main, "p");

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgInput ("i")
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArgInput
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgInput
    (cHTTPThrowMain &p_main, const char *name)
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
} g_httpthrow_main_input(g_httpthrow_main, "i");

/**
 **********************************************************************
 *  Class: cHTTPThrowMainArgOutput ("o")
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cHTTPThrowMainArgOutput
: public cHTTPThrowMainArg
{
public:
    typedef cHTTPThrowMainArg cIs;

    cHTTPThrowMainArgOutput
    (cHTTPThrowMain &p_main, const char *name)
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
} g_httpthrow_main_output(g_httpthrow_main, "o");
