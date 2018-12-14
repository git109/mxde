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
 *   File: dom.cxx
 *
 * Author: $author$
 *   Date: 11/28/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include "cdomdocumentparserevent.hxx"
#include "cdomprocessor.hxx"
#include "cdom.hxx"
#include "cdominterface.hxx"
#include "cxmlwriter.hxx"

/**
 **********************************************************************
 *  Class: cConfigDOMElementProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cConfigDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cConfigDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cConfigDOMElementProcessor(const char *name) 
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = processor
        .Process(result, element, parameter);
        return error;
    }
} g_config_processor("config");

/**
 **********************************************************************
 *  Class: cServletDOMElementProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cServletDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    cString m_servlet_name, m_name_attr_name;

    /**
     **********************************************************************
     * Constructor: cServletDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cServletDOMElementProcessor
    (const char *name, const char *servlet_name) 
    : cIs(name),
      m_servlet_name(servlet_name),
      m_name_attr_name("name")
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        const cStringInterface *a;
        
        if ((a = element.GetAttribute(m_name_attr_name)))
        if (!(a->Compare(m_servlet_name)))
        error = processor
        .Process(result, element, parameter);
        return error;
    }
} g_servlet_processor("servlet", "tservlet");

/**
 **********************************************************************
 *  Class: cDirectoryDOMElementProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDirectoryDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cDirectoryDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDirectoryDOMElementProcessor(const char *name) 
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = processor
        .Process(result, element, parameter);
        return error;
    }
} g_directory_processor("directory");

/**
 **********************************************************************
 *  Class: cLocationDOMElementProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cLocationDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cLocationDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cLocationDOMElementProcessor(const char *name) 
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = processor
        .Process(result, element, parameter);
        return error;
    }
} g_location_processor("location");

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 11/28/2004
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char *fn="c:/source/ccl/xml/hyde/hydas-config.xml";
    eError error;
    cDOMNodeFactory dnf;
    cDOMDocument d(dnf);
    cDOMDocumentParserEvent ev(d);
    cXMLWriter w(ev);
    cDOMProcessor p;
    FILE *f;
    int c;

    if ((f = fopen(fn, "r")))
    {

        w.Initialize();
        while(0 < (c = getc(f)))
            w.Put(c);
        w.Finalize();

        if (!(error = p.Initialize()))
        {
            cDOMNodeList r(d),par(d);

            p.Process(r, d, par);
            p.Finalize();
        }
        fclose(f);
    }
    return 0;
}
