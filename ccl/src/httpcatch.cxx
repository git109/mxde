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
 *   File: httpcatch.cxx
 *
 * Author: $author$
 *   Date: 11/1/2004
 *
 *    $Id$
 **********************************************************************
 */
#include "csocket.hxx"
#include "chttpheaderparser.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cHTTPMain
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHTTPMain
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     * Function: OnHeaderField
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError OnHeaderField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPMainHeaderParser
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHTTPMainHeaderParser
: public cHTTPHeaderParser
{
public:
    typedef cHTTPHeaderParser cIs;

    cHTTPMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHTTPMainHeaderParser
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cHTTPMainHeaderParser(cHTTPMain &p_main) 
    : m_main(p_main) 
    {
    }
    /**
     **********************************************************************
     * Function: OnField
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError OnField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = m_main.OnHeaderField
        (name, namelen, value, valuelen);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPCatchMain
 *
 * Author: $author$
 *   Date: 11/1/2004
 **********************************************************************
 */
class cHTTPCatchMain
: public cHTTPMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    bool m_verbose;
    bool m_overwrite;
    int m_forward;
    int m_number;
    int m_port;
    const char *m_host;
    const char *m_output;
    const char *m_input;
    char m_verbose_char[8];

    int m_content_length;
    bool m_chunked_content;

    cSocket m_listen_socket;
    cSocket m_accept_socket;
    cHTTPMainHeaderParser m_parser;

    /**
     **********************************************************************
     * Constructor: cHTTPCatchMain
     *
     *      Author: $author$
     *        Date: 11/1/2004
     **********************************************************************
     */
    cHTTPCatchMain
    (const char *host="localhost", 
     int port=80, bool verbose=false)
    : m_parser(*this),
      m_verbose(verbose),
      m_overwrite(false),
      m_usage(false),
      m_host(host),
      m_port(port),
      m_number(-1),
      m_forward(-1),
      m_output(0),
      m_input(0),
      m_content_length(0),
      m_chunked_content(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/1/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        eError error;

        if (m_usage)
            return OnUsage(argc, argv);

        if (!(error = m_listen_socket.Create()))
        {

            m_listen_socket.SetKeepAlive(true);
            m_listen_socket.SetNoDelay(true);
            m_listen_socket.SetDontLinger(true);

            if (!(error = m_listen_socket.Bind(m_host, m_port)))
            {
                if (!(error = m_listen_socket.Listen()))
                {
                    do
                    {
                    if (m_verbose)
                    {
                        if (0 < m_number)
                            printf("Number = %d\n", m_number);

                        printf
                        ("Listening at host \"%s\" port %d...\n",
                         m_host, m_port);
                    }
                    if (!(error = m_listen_socket.Accept(m_accept_socket)))
                    {
                        if (m_verbose)
                            printf
                            ("...Accepted connection at host \"%s\" port %d\n",
                             m_host, m_port);
/*
                        m_accept_socket.SetNoDelay(true);
                        m_accept_socket.SetDontLinger(true);
*/
                        m_accept_socket.
                        UpdateAcceptContext(m_listen_socket);

                        if (0 < m_forward)
                            OnForward(m_accept_socket);
                        else OnAccept(m_accept_socket);

                        m_accept_socket.Shutdown(SD_BOTH);
                        m_accept_socket.Close();
                    }
                    else
                    {
                        printf
                        ("Unable to accept connection at host \"%s\" port %d\n",
                         m_host, m_port);
                    }
                    if (0 < m_number)
                    if (1 > --m_number)
                        m_number = -1;
                    }
                    while (m_number >= 0);
                }
                else
                {
                    printf
                    ("Unable to listen at host \"%s\" port %d\n",
                     m_host, m_port);
                }
            }
            else
            {
                printf
                ("Unable to bind to host \"%s\" port %d\n",
                 m_host, m_port);
            }
            m_listen_socket.Close();
        }
        else
        {
            printf
            ("Unable to create socket\n");
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnAccept
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual void OnAccept(cSocket &socket)
    {
        FILE *out = m_out.GetHandle();
        FILE *in = m_in.GetHandle();
        bool new_line = false;
        eError error;
        int length;
        int c;

        m_content_length = 0;
        m_chunked_content = false;

        if ((error = m_parser.Initialize()))
            return;

        if (m_output)
        {
            if (!(error = m_out.Open(m_output, "r")))
            {
                m_out.Close();

                if (!m_overwrite)
                {
                    m_out.Attach(out);
                    return;
                }
            }
            if ((error = m_out.Open(m_output, "wb")))
            {
                m_out.Attach(out);
                return;
            }
        }

        if (m_input)
        if ((error = m_in.Open(m_input, "rb")))
        {
            m_in.Attach(in);
            return;
        }

        while (0 <= (c = socket.Getc()))
        {
            if (m_verbose)
            {
                length = VerboseChar(c);

                if (m_output)
                    fwrite(m_verbose_char, 1, length, out);
                else m_out.Write(m_verbose_char, length);
            }
            else m_out.Putc(c);

            m_parser.Putc(c);

            if ('\n' == c)
            {
                if (new_line)
                    break;

                new_line = true;
            }
            else if ('\r' != c)
                    new_line = false;
        }

        if (0 < m_content_length)
        {
            for (length=0; length<m_content_length; length++)
            {
                if (0 > (c = socket.Getc()))
                    break;

                m_out.Putc(c);
            }
        }

        if (m_input)
        {
            while (0 <= (c = m_in.Getc()))
            {
                if (0 > (c = socket.Putc(c)))
                    break;

                if (m_verbose)
                {
                    length = VerboseChar(c);

                    if (m_output)
                        fwrite(m_verbose_char, 1, length, out);
                    else m_out.Write(m_verbose_char, length);
                }
            }
            m_in.Close();
            m_in.Attach(in);
        }

        if (m_output)
        {
            m_out.Close();
            m_out.Attach(out);
        }
    }
    /**
     **********************************************************************
     * Function: OnForward
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual void OnForward(cSocket &socket)
    {
        bool new_line = false;
        cSocket fsocket;
        eError error;
        int length;
        int c;

        m_content_length = 0;
        m_chunked_content = false;

        if ((error = m_parser.Initialize()))
            return;

        if (!(error = fsocket.Create()))
        {
/*
            fsocket.SetNoDelay(true);
            fsocket.SetDontLinger(true);
*/
            if (m_verbose)
                printf
                ("Connecting to host \"%s\" port %d...\n",
                 m_host, m_forward);

            if ((error = fsocket.Connect(m_host, m_forward)))
            {
                if (m_verbose)
                    printf
                    ("...Unable to Connect to host \"%s\" port %d\n",
                     m_host, m_forward);
            }
            else
            {
                if (m_verbose)
                {
                    printf
                    ("...Connected to host \"%s\" port %d\n",
                     m_host, m_forward);
                    printf("---->\n");
                }

                while (0 <= (c = socket.Getc()))
                {
                    if (m_verbose)
                    {
                        length = VerboseChar(c);
                        m_out.Write(m_verbose_char, length);
                    }

                    m_parser.Putc(c);

                    if (0 > (c = fsocket.Putc(c)))
                        break;

                    if ('\n' == c)
                    {
                        if (new_line)
                            break;

                        new_line = true;
                    }
                    else if ('\r' != c)
                            new_line = false;

                }

                if (m_verbose)
                    printf("<----\n");

                while (0 <= (c = fsocket.Getc()))
                {
                    if (0 > (c = socket.Putc(c)))
                        break;

                    if (m_verbose)
                    {
                        length = VerboseChar(c);
                        m_out.Write(m_verbose_char, length);
                    }
                }

                if (m_verbose)
                    printf
                    ("...Disconnecting from host \"%s\" port %d\n",
                     m_host, m_forward);
            }
            fsocket.Close();
        }
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
     * Function: OnHeaderField
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError OnHeaderField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        if (0 == strcmp("Content-Length",name))
        {
            m_content_length = atoi(value);
        }
        else if (0 == strcmp("Transfer-Encoding",name))
        {
            if (0 == strcmp("chunked", value))
                m_chunked_content = true;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 11/1/2004
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
     *     Date: 11/1/2004
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
} g_httpcatch_main;

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArg
 *
 * Author: $author$
 *   Date: 11/1/2004
 **********************************************************************
 */
class cHTTPCatchMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHTTPCatchMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHTTPCatchMainArg
     *
     *      Author: $author$
     *        Date: 11/1/2004
     **********************************************************************
     */
    cHTTPCatchMainArg(cHTTPCatchMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgVerbose ("v")
 *
 * Author: $author$
 *   Date: 11/1/2004
 **********************************************************************
 */
class cHTTPCatchMainArgVerbose
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgVerbose
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_verbose = true;
        return argn;
    }
} g_httpcatch_main_verbose(g_httpcatch_main, "v");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgHost ("h")
 *
 * Author: $author$
 *   Date: 11/1/2004
 **********************************************************************
 */
class cHTTPCatchMainArgHost
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgHost
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
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
        if ((m_main.m_host = argv[++argn]))
        if (!strcmp(m_main.m_host, "*"))
            m_main.m_host= "";

        return argn;
    }
} g_httpcatch_main_host(g_httpcatch_main, "h");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgPort ("p")
 *
 * Author: $author$
 *   Date: 11/1/2004
 **********************************************************************
 */
class cHTTPCatchMainArgPort
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgPort
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
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
            m_main.m_port = atoi(arg);

        return argn;
    }
} g_httpcatch_main_port(g_httpcatch_main, "p");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgForward ("f")
 *
 * Author: $author$
 *   Date: 11/16/2004
 **********************************************************************
 */
class cHTTPCatchMainArgForward
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgForward
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
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
            m_main.m_forward = atoi(arg);
        return argn;
    }
} g_httpcatch_main_forward(g_httpcatch_main, "f");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgOutput ("o")
 *
 * Author: $author$
 *   Date: 11/1/2004
 **********************************************************************
 */
class cHTTPCatchMainArgOutput
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgOutput
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" file");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn<argc)
            m_main.m_output = argv[++argn];
        return argn;
    }
} g_httpcatch_main_output(g_httpcatch_main, "o");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgInput ("i")
 *
 * Author: $author$
 *   Date: 11/16/2004
 **********************************************************************
 */
class cHTTPCatchMainArgInput
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgInput
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" file");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn<argc)
            m_main.m_input = argv[++argn];
        return argn;
    }
} g_httpcatch_main_input(g_httpcatch_main, "i");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgOverwrite ("w")
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHTTPCatchMainArgOverwrite
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgOverwrite
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.m_overwrite = true;
        return argn;
    }
} g_httpcatch_main_overwrite(g_httpcatch_main, "w");

/**
 **********************************************************************
 *  Class: cHTTPCatchMainArgRepeat ("n")
 *
 * Author: $author$
 *   Date: 11/16/2004
 **********************************************************************
 */
class cHTTPCatchMainArgRepeat
: public cHTTPCatchMainArg
{
public:
    typedef cHTTPCatchMainArg cIs;

    cHTTPCatchMainArgRepeat
    (cHTTPCatchMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" number");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_main.m_number = atoi(arg);
        return argn;
    }
} g_httpcatch_main_repeat(g_httpcatch_main, "n");
