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
 *   File: tx.cxx
 *
 * Author: $author$
 *   Date: 10/9/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cnamespacedocumentevent.hxx"
#include "cdocumentnamespace.hxx"
#include "cmakefilecommentstocharwriter.hxx"
#include "cdocumenttoxmlcharprinter.hxx"
#include "cxmltodocumentparser.hxx"
#include "cxmltodocumentparserevent.hxx"
#include "cdocument.hxx"
#include "cdocumentfactory.hxx"
#include "cdocumenttransformcgi.hxx"
#include "ccharstreamwriter.hxx"

/**
 **********************************************************************
 *  Class: cTxCGI
 *
 * Author: $author$
 *   Date: 10/9/2005
 **********************************************************************
 */
class cTxCGI
: public cDocumentTransformCGI
{
public:
    typedef cDocumentTransformCGI cIs;

    //cXMLToDocumentParser m_document_parser;
    //cMakefileCommentsToCharWriter m_makefile_parser_writer;
    cDocumentToXMLCharPrinter m_xml_printer;
    cXMLVersion m_xml_version;

    /**
     **********************************************************************
     * Constructor: cTxCGI
     *
     *      Author: $author$
     *        Date: 10/9/2005
     **********************************************************************
     */
    cTxCGI(const char *name="tx")
    : cIs(name)/*,
      m_makefile_parser_writer(m_document_parser.m_parser_writer)*/
    {
    }

    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
    virtual int OnCommandOrCGI()
    {
        int result = 0;
        eError error, document_error;
        cCharFile output_file;
        cCharFile input_file(stdin);
        cContentStream content(*this);
        cCharStreamWriter writer(content);
        cDocumentParserInterface* parser;
        cDocumentParserTypeInterface* parser_type;

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        if (!m_input_type)
            return OnMissingTemplateType();

        if (!(m_input_filename = GetInputFilename()))
            return OnMissingTemplateFilename();

        if ((error = cStaticDocumentParserTypeList::m_instance.Initialize()))
            return OnErrorMessage("Unable to initialize static document types");

        if (!(parser_type = cDocumentParserTypeTree::m_instance.Find(m_input_type)))
            return OnErrorMessageName("Unable to find document type", m_input_type);

        if (!(parser = parser_type->GetParser()))
            return OnErrorMessageName("Unable to get document type parser", m_input_type);

        if ((error = OpenTemplateFile
            (input_file, m_input_filename)))
            return 1;

        document_error = parser->ParseStream(input_file);
        //document_error = m_document_parser.
        //ParseStreamToWriter(m_makefile_parser_writer, input_file);

        if ((error = CloseInputFile
            (input_file, m_input_filename)))
            return 1;

        OutputContentType(m_output_content_type);

        if (!document_error)
            m_xml_printer.Print
            (writer, parser->GetDocument(), &m_xml_version);

        return result;
    }
} g_txcgi;
