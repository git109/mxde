/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: xtl.cxx
 *
 * Author: $author$
 *   Date: 11/17/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cxtlparser.hxx"
#include "cxtltodocumentlexer.hxx"
#include "cxtlparse.hxx"
#include "cxtltodocumenttoken.hxx"
#include "cdocumenttransformcgi.hxx"
#include "ccontentstream.hxx"
#include "ccharstreamwriter.hxx"
#include "cdocumenttoxmlcharprinter.hxx"

cXTLToDocumentTokenItem* cXTLToDocumentTokenList::cIs::m_first = 0;
cXTLToDocumentTokenItem* cXTLToDocumentTokenList::cIs::m_last = 0;
cXTLToDocumentTokenList cXTLToDocumentTokenList::m_instance;

cXTLToDocumentToken g_output_token("output", XX_OUTPUT);
cXTLToDocumentToken g_method_token("method", XX_METHOD);
cXTLToDocumentToken g_include_token("include", XX_INCLUDE);
cXTLToDocumentToken g_using_token("using", XX_USING);
cXTLToDocumentToken g_location_token("location", XX_LOCATION);
cXTLToDocumentToken g_file_token("file", XX_FILE);
cXTLToDocumentToken g_ftp_token("ftp", XX_FTP);
cXTLToDocumentToken g_http_token("http", XX_HTTP);

cXTLToDocumentToken g_transform_token("transform", XX_TRANSFORM);
cXTLToDocumentToken g_template_token("template", XX_TEMPLATE);
cXTLToDocumentToken g_variable_token("variable", XX_VARIABLE);
cXTLToDocumentToken g_parameter_token("parameter", XX_PARAMETER);

cXTLToDocumentToken g_to_token("to", XX_TO);
cXTLToDocumentToken g_with_token("with", XX_WITH);

cXTLToDocumentToken g_apply_token("apply", XX_APPLY);
cXTLToDocumentToken g_if_token("if", XX_IF);
cXTLToDocumentToken g_then_token("then", XX_THEN);
cXTLToDocumentToken g_else_token("else", XX_ELSE);
cXTLToDocumentToken g_elseif_token("else-if", XX_ELSE_IF);
cXTLToDocumentToken g_do_token("do", XX_DO);
cXTLToDocumentToken g_is_token("is", XX_IS);
cXTLToDocumentToken g_while_token("while", XX_WHILE);
cXTLToDocumentToken g_until_token("until", XX_UNTIL);
cXTLToDocumentToken g_repeat_token("repeat", XX_REPEAT);
cXTLToDocumentToken g_foreach_token("for-each", XX_FOR_EACH);
cXTLToDocumentToken g_switch_token("switch", XX_SWITCH);
cXTLToDocumentToken g_case_token("case", XX_CASE);
cXTLToDocumentToken g_default_token("default", XX_DEFAULT);

cXTLToDocumentToken g_match_token("match", XX_MATCH);
cXTLToDocumentToken g_name_token("name", XX_NAME);
cXTLToDocumentToken g_select_token("select", XX_SELECT);
cXTLToDocumentToken g_test_token("test", XX_TEST);

/**
 **********************************************************************
 *  Class: cXTLCGI
 *
 * Author: $author$
 *   Date: 11/17/2005
 **********************************************************************
 */
class cXTLCGI
: public cDocumentTransformCGI
{
public:
    typedef cDocumentTransformCGI cIs;

    cContentStream m_content_stream;
    cCharStreamWriter m_content_writer;
    cDocumentToXMLCharPrinter m_xml_printer;
    cXMLVersion m_xml_version;
    cCharFile m_input_file;
    cXTLToDocumentParser m_template_parser;

    cCCharBuffer m_language_namespace_uri;
    cCCharBuffer m_variable_namespace_uri;
    cCCharBuffer m_expression_namespace_uri;

    /**
     **********************************************************************
     * Constructor: cXTLCGI
     *
     *      Author: $author$
     *        Date: 11/17/2005
     **********************************************************************
     */
    cXTLCGI
    (const char *name="xtl",
     const char *language_namespace_uri="XML-Transform-Language",
     const char *variable_namespace_uri="XML-Transform-Variable",
     const char *expression_namespace_uri="XML-Transform-Expression")
    : cIs(name), 
      m_content_stream(*this),
      m_content_writer(m_content_stream),
      m_template_parser(m_content_stream),
      m_language_namespace_uri(language_namespace_uri),
      m_variable_namespace_uri(variable_namespace_uri),
      m_expression_namespace_uri(expression_namespace_uri)
    {
        m_requires_template_type = true;
        m_requires_template_filename = true;
    }
    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 11/17/2004
     **********************************************************************
     */
    virtual int OnTransform() 
    {
        int result=0;
        eError error;
        cDocumentNamespaceInterface 
            *language_namespace, 
            *variable_namespace, 
            *expression_namespace;

        if ((error = cDocumentFactory::m_instance.Initialize()))
            return OnErrorMessage
            ("Unable to initialize document factory");

        if ((error = OpenTemplateFile
            (m_input_file, m_template_filename)))
            result = 1;
        else
        {
            if (!(m_template_document = cDocumentFactory::m_instance.CreateDocumentByType
                (m_template_type)))
                result = OnErrorMessageName
                ("Unable to create template type", m_template_type);
            else
            {
                cDocumentNodeFactoryInterface& node_factory = m_template_document->GetNodeFactory();

                if ((language_namespace = node_factory.GetNamespace(m_language_namespace_uri)))
                if ((variable_namespace = node_factory.GetNamespace(m_variable_namespace_uri)))
                if ((expression_namespace = node_factory.GetNamespace(m_expression_namespace_uri)))

                if ((error = m_template_document->
                    ParseFromStream(m_input_file)))
                    result = OnErrorMessageName
                    ("Unable to parse template from file", m_template_filename);

                else
                {
                    m_xml_printer.Print
                    (m_content_writer, 
                     *m_template_document, &m_xml_version);

                    m_template_parser.SetLanguageNamespace(language_namespace);
                    m_template_parser.SetVariableNamespace(variable_namespace);
                    m_template_parser.SetExpressionNamespace(expression_namespace);

                    if (!(error = m_template_parser.Initialize()))
                    {
                        m_template_parser.Parse(*m_template_document);
                        m_template_parser.Finalize();
                    }
                }
                cDocumentFactory::m_instance.
                DestroyDocument(*m_template_document);
            }

            CloseTemplateFile(m_input_file, m_template_filename);
        }
        cDocumentFactory::m_instance.Finalize();
        return result;
    }
} g_xtlcgi;

