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
 *   File: cdomparser.hxx
 *
 * Author: $author$
 *   Date: 12/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMPARSER_HXX
#define _CDOMPARSER_HXX

#include "cnamespacedomevent.hxx"
#include "cdomdocumentparserevent.hxx"
#include "cdom.hxx"
#include "cxmlwriter.hxx"

/**
 **********************************************************************
 *  Class: cDOMParser
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cDOMParser
{
public:
    cNamespaceDOMEvent m_dom_event;
    cDOMNodeFactory m_dom_factory;
    cDOMDocument m_dom_document;
    cDOMDocumentParserEvent m_dom_document_event;
    cXMLWriter m_dom_document_writer;

    /**
     **********************************************************************
     * Constructor: cDOMParser
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cDOMParser() 
    : m_dom_factory(m_dom_event),
      m_dom_document(m_dom_event, m_dom_factory),
      m_dom_document_event(m_dom_event, m_dom_factory, m_dom_document),
      m_dom_document_writer(m_dom_document_event)
    {
    }
    /**
     **********************************************************************
     * Function: ParseFile
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual eError ParseFile
    (const char* filename) 
    {
        eError error2, error = e_ERROR_NONE;
        FILE *f;
        int c;

        if ((f = fopen(filename, "r")))
        {
            if (!(error = m_dom_document_writer.Initialize()))
            {
                while(0 < (c = getc(f)))
                    if ((0 > (c = m_dom_document_writer.Putc(c))))
                    {
                        error = -c;
                        break;
                    }

                if ((error2 = m_dom_document_writer.Finalize()))
                if (!error)
                    error = error2;
            }

            fclose(f);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface* GetNamespace
    (const cStringInterface &namespace_uri) 
    {
        return m_dom_factory.GetNamespace(namespace_uri);
    }
    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual cDOMEventInterface& GetEvent() 
    {
        return m_dom_event;
    }
    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cDOMNodeFactoryInterface& GetNodeFactory() 
    {
        return m_dom_factory;
    }
    /**
     **********************************************************************
     * Function: GetNodeList
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cDOMNodeListInterface& GetNodeList() 
    {
        return m_dom_document;
    }
};

#endif /* _CDOMPARSER_HXX */