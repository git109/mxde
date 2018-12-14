/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   Date: 12/27/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ccontentdocumentsource.hxx"
#include "cfiledocumentsource.hxx"
#include "ctransformtypeinterface.hxx"
#include "ctransforminterface.hxx"
#include "cdocumentcgi.hxx"

/**
 **********************************************************************
 *  Class: cDTGGI
 *
 * Author: $author$
 *   Date: 12/27/2003
 **********************************************************************
 */
class cDTGGI
: public cDocumentCGI
{
public:
    typedef cDocumentCGI cIs;

    const char *m_echo_document_command;
    const char *m_echo_template_command;

    /**
     **********************************************************************
     * Constructor: cDTGGI
     *
     *      Author: $author$
     *        Date: 12/27/2003
     **********************************************************************
     */
    cDTGGI(const char *name="dt")
    : cIs(name),
      m_echo_document_command("echo_document"),
      m_echo_template_command("echo_template")
    {
    }

    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 2/3/2004
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
     *     Date: 2/3/2004
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
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnCommandOrCGI()
    {
        int result=0;
        eError error;
        cFileDocumentSource template_source;
        cFileDocumentSource document_source;
        cTransformInterface *transform;
        cTransformTypeInterface *transform_type;

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        if (!m_transform_type)
            return OnMissingTransformType();

        if (!m_input_type)
            return OnMissingTemplateType();

        if (!m_input_filename)
            return OnMissingTemplateFilename();

        if (!m_document_type)
            return OnMissingDocumentType();

        if (!m_document_filename)
            return OnMissingDocumentFilename();

        if (!(transform_type = cTransformTypeInterface::GetByName(m_transform_type)))
            return OnUnknownTransformType();

        if ((transform = transform_type->GetTransform(error)))
        {
            if (!(result = OnOpenTemplateFileSource
                (template_source, m_input_filename, m_input_type)))
            {
                if (!(result = OnOpenDocumentFileSource
                    (document_source, m_document_filename, m_document_type)))
                {
                    result = OnTransform
                    (*transform, document_source, template_source);
                    document_source.Close();
                }
                template_source.Close();
            }
            transform_type->FreeTransform(*transform);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int OnTransform
    (cTransformInterface &transform,
     cFileDocumentSource &document_source,
     cFileDocumentSource &template_source)
    {
        int result=0;
        const char *error_message;
        eError error;
        cContentDocumentSource output_source(*this);

        OutputContentType(m_output_content_type);

        if (m_output_type)
            output_source.SetType(m_output_type);

        if ((error = transform.Initialize()))
        {
            if (!(error = transform.GetLastError(error_message)))
                error_message = 0;

            result = OnTransformationError(error_message);
        }
        else
        {
            if (m_command)
            {
                if (!strcmp(m_command, m_echo_document_command))
                    error = transform.EchoDocument
                    (output_source, document_source, m_document_factory);

                else if (!strcmp(m_command, m_echo_template_command))
                        error = transform.EchoDocument
                        (output_source, template_source, m_document_factory);
            }
            else error = transform.TransformDocument
                 (output_source, document_source,
                  template_source, m_document_factory);

            if (error)
            {
                if (!(error = transform.GetLastError(error_message)))
                    error_message = 0;

                result = OnTransformationError(error_message);
            }
            transform.Finalize();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnOpenDocumentFileSource
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnOpenDocumentFileSource
    (cFileDocumentSource &source, 
     const char *filename, const char *type=0)
    {
        eError error;
        int count;

        if (type)
        if (0 > (count = source.SetType(type)))
            return OnErrorMessageName
            ("unable to set document type", type);

        if (!(error = source.Open(filename)))
            return 0;

        return OnErrorMessageName
        ("unable to open document file", filename);
    }
    /**
     **********************************************************************
     * Function: OnOpenTemplateFileSource
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnOpenTemplateFileSource
    (cFileDocumentSource &source, 
     const char *filename, const char *type=0)
    {
        eError error;
        int count;

        if (type)
        if (0 > (count = source.SetType(type)))
            return OnErrorMessageName
            ("unable to set template type", type);

        if (!(error = source.Open(filename)))
            return 0;

        return OnErrorMessageName
        ("unable to open template file", filename);
    }
    /**
     **********************************************************************
     * Function: OnOutputFormVaraibles
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnOutputFormVaraibles()
    {
        cHTTPForm::cField *field;

        OutputContentType(GetContentTypeHTML());

        OutputL(H1, m_name, H1_, 0);
        OutputL(BOLD, "Form Content Type", BOLD_, " = \"", GetInputContentType(), "\"", BR, 0);
        OutputL(BR, BOLD, "Form fields", BOLD_, UL, 0);

        if ((field = GetFirstFormField()))
        do
        {
            OutputL
            (BOLD, field->GetName(), BOLD_,
             " = \"", field->GetValue(), "\"", BR, 0);
        }
        while ((field = field->GetNext()));

        Output(UL_);

        return 0;
    }
} g_dtcgi;
