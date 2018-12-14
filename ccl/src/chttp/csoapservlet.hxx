/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: csoapservlet.hxx
 *
 * Author: $author$
 *   Date: 1/4/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSOAPSERVLET_HXX
#define _CSOAPSERVLET_HXX

#include "csoapobjectcontainer.hxx"
#include "csoapobject.hxx"
#include "cverbosewriter.hxx"
#include "cdocumenttoxmlcharprinter.hxx"
#include "chttpservlet.hxx"
#include "cxmltodocumentparser.hxx"
#include "cdocumentprocessor.hxx"

/**
 **********************************************************************
 *  Class: cSOAPServlet
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cSOAPServlet
: public cHttpServlet
{
public:
    typedef cHttpServlet cIs;

    const char* m_class_name;
    cSOAPObjectContainerInterface& m_object_container;

    cXMLVersion m_xml_version;
    cDocumentToXMLCharPrinter m_xml_printer;

    cCCharBuffer m_ns_attribute_prefix;
    cDocumentNamespaceFactory m_ns_factory;
    cXMLToDocumentParser m_xml_parser;
    cDocumentFactoryInterface& m_factory;
    cDocumentNodeFactoryInterface& m_node_factory;
    cDocumentEventInterface& m_event;
    cDocumentProcessor m_processor;

    cCCharBuffer m_soap_object_variable_name;
    cCCharBuffer m_soap_method_variable_name;
    cCCharBuffer m_soap_result_variable_name;

    cCCharBuffer m_soap_ns_uri;
    cCCharBuffer m_soap_encoding_ns_uri;
    cCCharBuffer m_soap_envelope;
    cCCharBuffer m_soap_body;
    cCharBuffer m_soap_action;
    const char* m_soap_action_chars;
    cCharBuffer m_soap_content_type;
    const char* m_soap_content_type_chars;

    cDocumentNamespaceInterface* m_soap_ns;
    cDocumentNamespaceInterface* m_soap_encoding_ns;

    const char *m_template_filename;
    cDocumentInterface* m_template_document;

    cCharFile m_input_file;

    /**
     **********************************************************************
     * Constructor: cSOAPServlet
     *
     *      Author: $author$
     *        Date: 12/31/2005
     **********************************************************************
     */
    cSOAPServlet
    (cSOAPObjectContainerInterface& object_container,
     const char* class_name="cSOAPServlet",
     const char* name="soap",
     const char *template_filename="conf/soap-return.xdt",
     const char *soap_object_variable_name="soapObject",
     const char *soap_method_variable_name="soapMethod",
     const char *soap_result_variable_name="soapResultValue",
     const char *soap_ns_uri="http://schemas.xmlsoap.org/soap/envelope/",
     const char *soap_encoding_ns_uri="http://schemas.xmlsoap.org/soap/encoding/",
     const char *soap_envelope="Envelope",
     const char *soap_body="Body",
     const char *soap_action="SOAPAction",
     const char *soap_content_type="text/xml",
     const char *ns_attribute_prefix="xmlns") 
    : cIs(name),
      m_class_name(class_name),
      m_object_container(object_container),
      m_ns_attribute_prefix(ns_attribute_prefix),
      m_xml_parser(m_ns_factory, m_ns_attribute_prefix),
      m_event(m_xml_parser.m_event),
      m_node_factory(m_xml_parser.m_node_factory),
      m_factory(m_xml_parser),
      m_processor
      (m_event, m_node_factory, m_factory,
       m_xml_parser, m_ns_attribute_prefix),
      m_template_filename(template_filename),

      m_soap_object_variable_name(soap_object_variable_name),
      m_soap_method_variable_name(soap_method_variable_name),
      m_soap_result_variable_name(soap_result_variable_name),

      m_soap_ns_uri(soap_ns_uri),
      m_soap_encoding_ns_uri(soap_encoding_ns_uri),
      m_soap_envelope(soap_envelope),
      m_soap_body(soap_body),
      m_soap_action(soap_action),
      m_soap_content_type(soap_content_type),
      m_soap_ns(0),
      m_soap_encoding_ns(0)
    {
    }
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 1/1/2006
     **********************************************************************
     */
    virtual eError Init() 
    {
        eError error = e_ERROR_FAILED;

        if ((m_soap_action_chars 
            = m_soap_action.GetBuffer()))
        if ((m_soap_content_type_chars 
            = m_soap_content_type.GetBuffer()))
        if ((m_soap_ns = m_ns_factory.
            GetNamespace(m_soap_ns_uri)))
        {
            if ((m_soap_encoding_ns = m_ns_factory.
                GetNamespace(m_soap_encoding_ns_uri)))
            {
                if (!(error = GetTemplateDocument()))
                {
                    if (!(error = m_processor.Initialize()))
                    {
                        return error = e_ERROR_NONE;
                        m_processor.Finalize();
                    }
                    FreeTemplateDocument();
                }
                m_ns_factory.FreeNamespace(*m_soap_encoding_ns);
                m_soap_ns = 0;
            }
            m_ns_factory.FreeNamespace(*m_soap_ns);
            m_soap_ns = 0;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 1/1/2006
     **********************************************************************
     */
    virtual eError Final() 
    {
        eError error2, error;
        
        error = m_processor.Finalize();

        if ((error2 = FreeTemplateDocument()))
        if (!error)
            error = error2;

        if ((error2 = m_ns_factory.FreeNamespace(*m_soap_encoding_ns)))
        if (!error)
            error = error2;

        if ((error2 = m_ns_factory.FreeNamespace(*m_soap_ns)))
        if (!error)
            error = error2;

        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 12/31/2005
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error2, error = e_ERROR_NONE;
        cCharReaderInterface &reader = request.GetReader();
        cCharWriterInterface &writer = response.GetWriter();
        cVerbose verbose(m_verbose);
        cVerboseWriter verbose_writer(verbose);
        cDocumentInterface* input_document;
        cDocumentInterface* result_document;
        cDocumentInterface* result_value;
        cDocumentNodeListInterface* old_result_value;
        cDocumentElementInterface* envelope_element;
        cDocumentElementInterface* body_element;
        cDocumentElementInterface* method_element;
        cSOAPObjectInterface* object;
        const char* text;
        int length;
        cCCharBuffer object_name;

        response.SetStatusOK();
        response.SetContentType(m_soap_content_type_chars);

        if (HasSOAPContentType(request))
        if ((text = GetSOAPAction(length, request)))
        if (0 < (length = object_name.Writec(text, length)))
        if ((object = m_object_container.GetObjectByName(object_name)))
        if ((input_document = m_xml_parser.CreateDocument()))
        {
            if (!(error2 = input_document->ParseFromReader(reader)))
            {
                if (m_verbose)
                {
                    m_verbose->VerboseFormatted
                    ("%s: ...Received request document\n\n",
                     m_class_name);

                    m_xml_printer.Print
                    (verbose_writer, 
                     *input_document, &m_xml_version);

                    m_verbose->VerboseFormatted
                    ("\n\n");
                }

            if ((envelope_element = input_document->GetFirstElementByName(m_soap_envelope)))
            if ((m_soap_ns = &envelope_element->GetNamespace()))
            if ((body_element = envelope_element->GetFirstElementByName(m_soap_body)))
            if ((m_soap_ns = &body_element->GetNamespace()))
            if ((method_element = body_element->GetFirstElement()))
            {
                if ((result_document = m_xml_parser.CreateDocument()))
                {
                    if ((result_value = m_xml_parser.CreateDocument()))
                    {
                        const cCCharBuffer& method_name = method_element->GetName();

                        if (!(error2 = object->CallMethodByName
                            (*result_value, *method_element, m_processor)))
                        if (!(error2 = m_processor.PreprocessDocument
                            (*result_document, 
                             *m_template_document, *input_document)))
                        if (!(error2 = m_processor.SetVariableToText
                            (m_soap_object_variable_name, object_name)))
                        if (!(error2 = m_processor.SetVariableToText
                            (m_soap_method_variable_name, method_name)))
                        {
                            old_result_value = m_processor.GetSetVariable
                            (error2, m_soap_result_variable_name, result_value);

                            if (!error2)
                            if (!(error2 = m_processor.ProcessDocument
                                (*result_document, 
                                 *m_template_document, *input_document)))
                            {
                                if (m_verbose)
                                {
                                    m_verbose->VerboseFormatted
                                    ("%s: Sending response document...\n\n",
                                     m_class_name);

                                    m_xml_printer.Print
                                    (verbose_writer, 
                                     *result_document, &m_xml_version);

                                    m_verbose->VerboseFormatted
                                    ("\n\n");
                                }
                                m_xml_printer.Print
                                (writer, *result_document, &m_xml_version);
                            }

                            old_result_value = m_processor.GetSetVariable
                            (error2, m_soap_result_variable_name, old_result_value);
                        }
                        m_xml_parser.DestroyDocument(*result_value);
                    }
                    m_xml_parser.DestroyDocument(*result_document);
                }
            }
            }
            m_xml_parser.DestroyDocument(*input_document);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetSOAPAction
     *
     *   Author: $author$
     *     Date: 1/3/2006
     **********************************************************************
     */
    const char* GetSOAPAction
    (int &length, cHttpServletRequestInterface &request) const 
    {
        const char* text;

        if ((text = request.GetHeader(length, m_soap_action_chars)))
        if (2 < length)
        {
            length -= 2;
            return text+1;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: HasSOAPContentType
     *
     *   Author: $author$
     *     Date: 1/3/2006
     **********************************************************************
     */
    bool HasSOAPContentType
    (cHttpServletRequestInterface &request) const
    {
        const char* text;
        int length;

        if ((text = request.GetContentType(length)))
        if ((text = strstr(text, m_soap_content_type_chars)))
            return true;
        return false;
    }
    /**
     **********************************************************************
     * Function: GetTemplateDocument
     *
     *   Author: $author$
     *     Date: 1/2/2006
     **********************************************************************
     */
    virtual eError GetTemplateDocument() 
    {
        eError result = 1;

        if ((m_template_document = m_xml_parser.CreateDocument()))
        if (m_template_filename)
        {
            if ((result = ParseTemplateFile()))
                FreeTemplateDocument();
        }
        else result = 0;

        return result;
    }
    /**
     **********************************************************************
     * Function: FreeTemplateDocument
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError FreeTemplateDocument() 
    {
        eError error;

        error = m_xml_parser.
        DestroyDocument(*m_template_document);
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseTemplateFile
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError ParseTemplateFile() 
    {
        eError error,error2;

        if (!(error = m_input_file.Open(m_template_filename)))
        {
            error = m_template_document->ParseFromStream(m_input_file);

            if ((error2 = m_input_file.Close()))
            if (!error)
                error = error2;
        }
        return error;
    }
};

#endif /* _CSOAPSERVLET_HXX */
