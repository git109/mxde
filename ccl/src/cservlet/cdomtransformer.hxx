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
 *   File: cdomtransformer.hxx
 *
 * Author: $author$
 *   Date: 12/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMTRANSFORMER_HXX
#define _CDOMTRANSFORMER_HXX

#include "cnamespacedomevent.hxx"
#include "cdomprocessor.hxx"
#include "cdomdocumentparserevent.hxx"
#include "cdom.hxx"
#include "cxmlwriter.hxx"

/**
 **********************************************************************
 *  Class: cDOMTransformer
 *
 * Author: $author$
 *   Date: 12/14/2004
 **********************************************************************
 */
class cDOMTransformer
{
public:
    cNamespaceDOMEvent m_dom_event;
    cDOMNodeFactory m_dom_factory;
    cDOMNodeList m_dom_result,
                 m_dom_param;
    cDOMDocument m_dom_document,
                 m_dom_template;
    cDOMDocumentParserEvent m_dom_document_event,
                            m_dom_template_event;
    cXMLWriter m_dom_document_writer,
               m_dom_template_writer;
    cDOMProcessor m_dom_processor;

    /**
     **********************************************************************
     * Constructor: cDOMTransformer
     *
     *      Author: $author$
     *        Date: 12/14/2004
     **********************************************************************
     */
    cDOMTransformer() 
    : m_dom_factory(m_dom_event),
      m_dom_result(m_dom_event, m_dom_factory),
      m_dom_param(m_dom_event, m_dom_factory),
      m_dom_document(m_dom_event, m_dom_factory),
      m_dom_document_event(m_dom_event, m_dom_factory, m_dom_document),
      m_dom_document_writer(m_dom_document_event),
      m_dom_template(m_dom_event, m_dom_factory),
      m_dom_template_event(m_dom_event, m_dom_factory, m_dom_template),
      m_dom_template_writer(m_dom_template_event),
      m_dom_processor(m_dom_event, m_dom_factory)
    {
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 12/14/2004
     **********************************************************************
     */
    virtual eError Transform(const char* name) 
    {
        eError error2, error = e_ERROR_NONE;
        FILE *f;
        int c;

        if ((f = fopen(name, "r")))
        {
            if (!(error = m_dom_template_writer.Initialize()))
            {
                while(0 < (c = getc(f)))
                    if ((0 > (c = m_dom_template_writer.Put(c))))
                    {
                        error = -c;
                        break;
                    }

                if ((error2 = m_dom_template_writer.Finalize()))
                if (!error)
                    error = error2;
            }

            fclose(f);

            if (!error)
            if (!(error = m_dom_processor.Initialize()))
            {
                error = m_dom_processor.Process
                (m_dom_result, m_dom_template, m_dom_param);

                if ((error2 = m_dom_processor.Finalize()))
                if (!error)
                    error = error2;
            }
        }
        return error;
    }
};

#endif /* _CDOMTRANSFORMER_HXX */