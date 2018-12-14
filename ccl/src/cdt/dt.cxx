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
 *   File: dt.cxx
 *
 * Author: $author$
 *   Date: 11/27/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumenttransformcgi.hxx"
#include "ccontentstream.hxx"
#include "ccharstreamwriter.hxx"
#include "cdocumenttoxmlcharprinter.hxx"
#include "cdtparse.h"
#include "cdtparser.hxx"
#include "cxmltodocumentparser.hxx"
#include "ccharstreamhandle.hxx"
#include "cdocumentprocessor.hxx"

/**
 **********************************************************************
 *  Class: cDTCGI
 *
 * Author: $author$
 *   Date: 11/27/2005
 **********************************************************************
 */
class cDTCGI
: public cDocumentTransformCGI
{
public:
    typedef cDocumentTransformCGI cIs;

    cContentStream m_content_stream;
    cCharStreamWriter m_content_writer;
    cDocumentToXMLCharPrinter m_xml_printer;
    cXMLVersion m_xml_version;

    cCCharBuffer m_namespace_attribute_prefix;
    cCCharBuffer m_language_namespace_prefix;
    cCCharBuffer m_language_namespace_uri;

    cDocumentNamespaceFactory m_ns_factory;
    cXMLToDocumentParser m_xml_parser;
    cDocumentFactoryInterface& m_factory;
    cDocumentNodeFactoryInterface& m_node_factory;
    cDocumentEventInterface& m_event;
    cDocumentInterface& m_template_document;
    cDocumentInterface* m_input_document;
    cDocumentInterface* m_result_document;
    cDTParser m_dt_parser;
    cDocumentProcessor m_processor;

    cCharStreamHandle m_input_stream;
    cCharFile m_input_file;

    cCharBuffer m_command_echo_template;

    /**
     **********************************************************************
     * Constructor: cDTCGI
     *
     *      Author: $author$
     *        Date: 11/27/2005
     **********************************************************************
     */
    cDTCGI
    (const char *name="dt",
     const char *namespace_attribute_prefix="xmlns",
     const char *language_namespace_prefix="xdt",
     const char *language_namespace_uri="XML-Document-Transform",
     const char *document_path="../xml") 
    : cIs(name), 
      m_content_stream(*this),
      m_content_writer(m_content_stream),
      m_namespace_attribute_prefix(namespace_attribute_prefix),
      m_language_namespace_prefix(language_namespace_prefix),
      m_language_namespace_uri(language_namespace_uri),

      m_xml_parser
      (m_ns_factory, m_namespace_attribute_prefix),

      m_result_document(0),
      m_input_document(0),
      m_template_document(m_xml_parser.m_document),

      m_event(m_xml_parser.m_event),
      m_node_factory(m_xml_parser.m_node_factory),
      m_factory(m_xml_parser),

      m_dt_parser
      (m_template_document, 
       m_node_factory, m_factory,
       m_content_stream, m_input_stream),

      m_processor
      (m_event, m_node_factory, m_factory,
       m_xml_parser, m_namespace_attribute_prefix),

      m_command_echo_template("echo_template")
    {
        m_document_path = document_path,
        m_requires_input_filename = false;
        m_requires_template_filename = true;
        m_dt_parser.m_trace = false;
    }
    /**
     **********************************************************************
     *  Destructor: ~cDTCGI
     *
     *      Author: $author$
     *        Date: 11/27/2005
     **********************************************************************
     */
    virtual ~cDTCGI()
    {
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int OnCommandOrCGI() 
    {
        int result=cIs::OnCommandOrCGI();
        return result;
    }
    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    virtual int OnTransform() 
    {
        int result=0;
        eError error;

        if (!(result = OnParseTemplateFile()))
        {
            if (!(result = OnGetInputDocument()))
            {
                if (m_command)
                {
                    if (!(m_command_echo_template.Compare(m_command)))
                    {
                        SetContentType(m_output_content_type);

                        result = OnEchoTemplate();
                    }
                }
                else if ((m_result_document = m_xml_parser.CreateDocument()))
                {
                    if (!(error = m_processor.Initialize()))
                    {
                        if (!(result = OnGetEnvVariables()))
                        if (!(result = OnGetFormVariables()))
                        if (!(error = m_processor.PreprocessDocument
                            (*m_result_document, 
                             m_template_document, 
                             *m_input_document)))
                        if (!(error = m_processor.ProcessDocument
                            (*m_result_document, 
                             m_template_document, 
                             *m_input_document)))
                        {
                            SetContentType(m_output_content_type);

                            m_xml_printer.Print
                            (m_content_writer, 
                             *m_result_document, &m_xml_version);
                        }
                        m_processor.Finalize();
                    }
                    m_xml_parser.DestroyDocument(*m_result_document);
                }
                OnFreeInputDocument();
            }
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnGetInputDocument
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnGetInputDocument() 
    {
        int result = 1;

        if ((m_input_document = m_xml_parser.CreateDocument()))
        if (m_document_filename)
        {
            if ((result = OnParseDocumentFile()))
                OnFreeInputDocument();
        }
        else result = 0;

        return result;
    }
    /**
     **********************************************************************
     * Function: OnFreeInputDocument
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnFreeInputDocument() 
    {
        int result=0;
        eError error;

        if ((error = m_xml_parser.
            DestroyDocument(*m_input_document)))
            result = 1;
        return result;
    }
    /**
     **********************************************************************
     * Function: OnParseDocumentFile
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnParseDocumentFile() 
    {
        int result=1;
        eError error,error2;

        if (!(error = OpenDocumentFile
            (m_input_file, m_document_filename)))
        {
            error = m_input_document->ParseFromStream(m_input_file);

            if (!(error2 = CloseDocumentFile
                (m_input_file, m_document_filename)))
            if (!error)
                result = 0;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnParseTemplateFile
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnParseTemplateFile() 
    {
        int result=0;
        eError error;

        if ((error = OpenTemplateFile
            (m_input_file, m_template_filename)))
            result = 1;
        else
        {
            if (!(error = m_input_stream.Attach(&m_input_file)))
            {
                result = OnParseTemplateFile(m_template_filename);

                if ((error = m_input_stream.Detach()))
                    result = 1;
            }

            if ((error = CloseTemplateFile
                (m_input_file, m_template_filename)))
                result = 1;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnParseTemplateFile
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnParseTemplateFile(const char* filename) 
    {
        int result;

        if (0 > (result = m_dt_parser.SetFilename(filename)))
            return result = 1;

        if ((result = m_dt_parser.yyparse()))
            return result=1;

        return result;
    }
    /**
     **********************************************************************
     * Function: OnEchoTemplate
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual int OnEchoTemplate() 
    {
        int result = 0;

        m_xml_printer.Print
        (m_content_writer, 
         m_template_document, &m_xml_version);
        return result;
    }

    /**
     **********************************************************************
     * Function: OnGetEnvVariables
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int OnGetEnvVariables() 
    {
        int env, result = 0;
        const char *name, *value;

        for (env = e_FIRST_ENV; env <= e_LAST_ENV; env++)
        {
            if ((name = m_env_name[env]))
            if ((value = m_env[env]))
            if ((result = OnSetEnvVariable
                (name, -1, value, -1)))
                break;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnGetFormVariables
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int OnGetFormVariables() 
    {
        int result = 0;
        const char *name, *value;
        cHTTPForm::cField *field;

        if ((field = GetFirstFormField()))
        do
        {
            if ((name = field->GetName()))
            if ((value = field->GetValue()))
            if ((result = OnSetFormVariable
                (name, -1, value, -1)))
                break;
        }
        while ((field = field->GetNext()));
        return result;
    }

    /**
     **********************************************************************
     * Function: OnSetEnvVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int OnSetEnvVariable
    (const char* name, int namelen=-1,
     const char* value=0, int valuelen=-1) 
    {
        int result = OnSetVariable
        (name, namelen, value, valuelen);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnSetFormVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int OnSetFormVariable
    (const char* name, int namelen=-1,
     const char* value=0, int valuelen=-1) 
    {
        int result = OnSetVariable
        (name, namelen, value, valuelen);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnSetVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int OnSetVariable
    (const char* name, int namelen=-1,
     const char* value=0, int valuelen=-1) 
    {
        int length,result = 0;
        eError error;
        cCCharBuffer name_buffer;
        cCCharBuffer value_buffer;

        if (0 < (length = name_buffer.Copyc(name, namelen)))
        if (0 <= (length = value_buffer.Copyc(value, valuelen)))
        if ((error = m_processor.SetVariableToText
            (name_buffer, value_buffer)))
            result = 1;
        return result;
    }
} g_dt_cgi;

