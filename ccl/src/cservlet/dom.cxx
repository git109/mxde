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
 *   Date: 12/2/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include "cnamespacedomevent.hxx"
#include "cdomprocessor.hxx"
#include "cdomdocumentparserevent.hxx"
#include "cdom.hxx"
#include "cxmlwriter.hxx"

cDefaultDOMElementProcessor g_processor;

cString g_namespace_xsi("XMLSchema-instance");

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

    /**
     **********************************************************************
     * Constructor: cServletDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cServletDOMElementProcessor
    (const cStringInterface &namespace_uri, const char *name) 
    : cIs(namespace_uri, name)
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
        
        error = processor
        .Process(result, element, parameter);
        return error;
    }
} g_servlet_processor(g_namespace_xsi,"schema");

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 12/2/2004
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char *filename="c:/source/ccl/xml/hyde/hydas-config.xml";
    eError error,error2;
    cNamespaceDOMEvent event;
    cDOMNodeFactory factory(event);
    cDOMNodeList result(event, factory),param(event, factory);
    cDOMDocument doc(event, factory);
    cDOMDocumentParserEvent parser_event(event, factory, doc);
    cXMLWriter writer(parser_event);
    cDOMProcessor processor(factory);
    FILE *f;
    int c;

    if (1 < argc)
        filename = argv[1];

    if ((f = fopen(filename, "r")))
    {
        if (!(error = writer.Initialize()))
        {
            while(0 < (c = getc(f)))
                if ((0 > (c = writer.Put(c))))
                {
                    error = -c;
                    break;
                }

            if ((error2 = writer.Finalize()))
            if (!error)
                error = error2;
        }

        fclose(f);

        if (!error)
        if (!(error = processor.Initialize()))
        {
            error = processor.Process(result, doc, param);

            if ((error2 = processor.Finalize()))
            if (!error)
                error = error2;
        }
    }
    return 0;
}