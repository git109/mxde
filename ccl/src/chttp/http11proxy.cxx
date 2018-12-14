/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: http11proxy.cxx
 *
 * Author: $author$
 *   Date: 2/4/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpheaderfieldtype.hxx"
#include "chttprequestheaderserializer.hxx"
#include "chttprequestheader.hxx"
#include "chttprequestheadermethodserializer.hxx"
#include "chttprequestheadermethod.hxx"
#include "chttpheaderversionserializer.hxx"
#include "chttpheaderversion.hxx"
#include "chttpheaderintserializer.hxx"
#include "cfileinputstream.hxx"
#include "cfileoutputstream.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cHttp11ProxyMain
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttp11ProxyMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;

    /**
     **********************************************************************
     * Constructor: cHttp11ProxyMain
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttp11ProxyMain()
    : m_usage(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        cCharFile f("c:\\source\\ccl\\bin\\http.txt", "rb");
        cFileInputStream in(f.GetHandle());
        cHttpRequestHeader header;
        cHttpRequestHeaderDeserializer deserializer(header);
        cInputStreamDeserializer isd;

        deserializer.Deserialize(in);

        if (m_usage)
            return OnUsage(argc, argv);

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 2/5/2006
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
     *     Date: 2/5/2006
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
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_http11proxy_main;

/**
 **********************************************************************
 *  Class: cHttp11ProxyMainArg
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttp11ProxyMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cHttp11ProxyMain &m_main;

    /**
     **********************************************************************
     * Constructor: cHttp11ProxyMainArg
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttp11ProxyMainArg
    (cHttp11ProxyMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

