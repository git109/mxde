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
 *   File: uri.cxx
 *
 * Author: $author$
 *   Date: 6/19/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "curischeme.hxx"
#include "curi.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Main: cURIMain
 *
 * Author: $author$
 *   Date: 6/19/2004
 **********************************************************************
 */
class cURIMain
: public cMain
{
public:
    typedef cMain cIs;

    const char 
     *m_scheme,*m_user,
     *m_host,*m_port,
     *m_path,*m_query,
     *m_fragment,*m_location;

    cURLInterface *m_url;
    cURI m_uri;

    /**
     **********************************************************************
     * Constructor: cURIMain
     *
     *      Author: $author$
     *        Date: 6/19/2004
     **********************************************************************
     */
    cURIMain() 
    : m_scheme(0),
      m_user(0),
      m_host(0),
      m_port(0),
      m_path(0),
      m_query(0),
      m_fragment(0),
      m_location(0),
      m_url(0),
      m_uri(cStaticURISchemeSet::m_instance)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 6/19/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        eError error;

        if (m_url)
        if ((error = m_uri.CloseURL(*m_url)))
            return error;

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int result;

        if (argc < 2)
            return OnUsage(argc, argv);

        result =  cIs::OnMain(argc, argv);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 1/4/2005
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
     *     Date: 6/19/2004
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
} g_uri;

/**
 **********************************************************************
 *  Class: cURIMainArg
 *
 * Author: $author$
 *   Date: 6/19/2004
 **********************************************************************
 */
class cURIMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cURIMain &m_uri;

    cURIMainArg(cURIMain &uri, const char *name)
    : cIs(name),
      m_uri(uri)
    {
    }
};

/**
 **********************************************************************
 *    Arg: "l"
 *  Class: cURIMainArgLocation
 *
 * Author: $author$
 *   Date: 6/20/2004
 **********************************************************************
 */
class cURIMainArgLocation
: public cURIMainArg
{
public:
    typedef cURIMainArg cIs;

    cURIMainArgLocation(cURIMain &uri, const char *name)
    : cIs(uri, name)
    {
    }
    virtual void OnUsage()
    {
        cIs::OnUsage();
        printf(" location");
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        if (argn < argc)
        if ((arg = argv[++argn]))
            m_uri.m_location = arg;

        return argn;
    }
} g_uri_location(g_uri, "l");

/**
 **********************************************************************
 *    Arg: "o"
 *  Class: cURIMainArgOpen
 *
 * Author: $author$
 *   Date: 6/20/2004
 **********************************************************************
 */
class cURIMainArgOpen
: public cURIMainArg
{
public:
    typedef cURIMainArg cIs;

    cURIMainArgOpen(cURIMain &uri, const char *name)
    : cIs(uri, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        eError error;
        int length;

        if (m_uri.m_location)
        {
            if (0 < (length = m_uri.m_uri.SetURI(m_uri.m_location)))
            {
                if (m_uri.m_url)
                if ((error = m_uri.m_uri.CloseURL(*m_uri.m_url)))
                    return -error;

                m_uri.m_url = m_uri.m_uri.OpenURL();
            }
        }
        return argn;
    }
} g_uri_open(g_uri, "o");

/**
 **********************************************************************
 *    Arg: "r"
 *  Class: cURIMainArgRead
 *
 * Author: $author$
 *   Date: 6/23/2004
 **********************************************************************
 */
class cURIMainArgRead
: public cURIMainArg
{
public:
    typedef cURIMainArg cIs;

    cURIMainArgRead(cURIMain &uri, const char *name)
    : cIs(uri, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        cCharStream *content;
        const char *content_type;
        int c,content_length;

        if (m_uri.m_url)
        if ((content = m_uri.m_url->GetContent
            (content_type, content_length)))
        if (content_length >= 0)
        {
            for (; content_length > 0; content_length--)
                if (0 <= (c = content->Getc()))
                    m_uri.m_out.Putc(c);
        }
        else
        {
            while (0 <= (c = content->Getc()))
                m_uri.m_out.Putc(c);
        }
        return argn;
    }
} g_uri_read(g_uri, "r");
