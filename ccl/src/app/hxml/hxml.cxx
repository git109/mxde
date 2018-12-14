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
 *   File: hxml.cxx
 *
 * Author: $author$
 *   Date: 6/19/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdomtoxmlcharprinter.hxx"
#include "ccharstreamwriter.hxx"
#include "ccharfilewriter.hxx"
#include "cxmlwriter.hxx"
#include "cnamespacedomevent.hxx"
#include "cdomhtmldocumentparserevent.hxx"
#include "cdom.hxx"
#include "ccharwriterinterface.hxx"
#include "cdocumenttemplatecgi.hxx"

/**
 **********************************************************************
 *  Class: cHXMLCGI
 *
 * Author: $author$
 *   Date: 6/19/2005
 **********************************************************************
 */
class cHXMLCGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    cContentStream m_content_stream;

    /**
     **********************************************************************
     * Constructor: cHXMLCGI
     *
     *      Author: $author$
     *        Date: 6/19/2005
     **********************************************************************
     */
    cHXMLCGI(const char *name="hxml")
    : cIs(name),
      m_content_stream(*this)
    {
    }
    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 6/19/2005
     **********************************************************************
     */
    virtual int OnCommand()
    {
        m_error_content_type = m_content_type_none;
        m_output_content_type = m_content_type_none;
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 6/19/2005
     **********************************************************************
     */
    virtual int OnCGI()
    {
        m_error_content_type = m_content_type_html;
        m_output_content_type = m_content_type_text;
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 6/19/2005
     **********************************************************************
     */
    virtual int OnCommandOrCGI()
    {
        int result=0;

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        if (!m_document_filename)
            return OnMissingDocumentFilename();

        SetContentType(m_output_content_type);

        OnReadDocument(m_document_filename);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnReadDocument
     *
     *   Author: $author$
     *     Date: 6/2/2005
     **********************************************************************
     */
    virtual int OnReadDocument(const char *filename)
    {
        int result=0;
        eError error, error2;
        cNamespaceDOMEvent dom_event;
        cDOMNodeFactory dom_factory(dom_event);
        cDOMDocument dom_document(dom_event, dom_factory);
        cDOMHTMLDocumentParserEvent dom_parser_event
        (dom_event, dom_factory, dom_document);
        cXMLWriter xml_writer(dom_parser_event);
        cCharFileWriter xml_out1(m_out.GetHandle());
        cCharStreamWriter xml_out(m_content_stream);
        cDOMToXMLCharPrinter xml_printer;
        FILE *f;
        int c;

        if (!(error = xml_writer.Initialize()))
        {
            if ((f = fopen(filename, "r")))
            {
                while(0 < (c = getc(f)))
                {
                    if ((0 > (c = xml_writer.Putc(c))))
                    {
                        error = -c;
                        break;
                    }
                }

                fclose(f);
            }

            if ((error2 = xml_writer.Finalize()))
            if (!error)
                error = error2;

            if (!error)
                xml_printer.Print(xml_out, dom_document);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnWriteDocument
     *
     *   Author: $author$
     *     Date: 6/2/2005
     **********************************************************************
     */
    virtual int OnWriteDocument
    (cCharWriterInterface &writer, const char *filename)
    {
        int result=0;

        return result;
    }
} g_hxml_cgi;

