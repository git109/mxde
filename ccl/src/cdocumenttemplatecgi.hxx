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
 *   File: cdocumenttemplatecgi.hxx
 *
 * Author: $author$
 *   Date: 1/16/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTTEMPLATECGI_HXX
#define _CDOCUMENTTEMPLATECGI_HXX

#include "chttpformparameter.hxx"
#include "ccgimain.hxx"
#include "cfiledocumentsource.hxx"
#include "ccontentdocumentsource.hxx"
#include "htmlmacro.h"

/**
 **********************************************************************
 *  Class: cDocumentTemplateCGI
 *
 * Author: $author$
 *   Date: 1/16/2004
 **********************************************************************
 */
class cDocumentTemplateCGI
: public cCGIMain
{
public:
    typedef cCGIMain cIs;

    /**
     **********************************************************************
     *  Class: cOverwriteArgSwitch
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class cOverwriteArgSwitch
    : public cArgSwitch
    {
    public:
        typedef cArgSwitch cIs;

        cDocumentTemplateCGI &m_cgi;
        bool m_on;

        /**
         **********************************************************************
         * Constructor: cOverwriteArgSwitch
         *
         *      Author: $author$
         *        Date: 8/18/2003
         **********************************************************************
         */
        cOverwriteArgSwitch(cDocumentTemplateCGI &cgi, const char *name, bool on) 
        : cIs(name),
          m_cgi(cgi),
          m_on(on) 
        {
        }
        /**
         **********************************************************************
         * Function: OnSwitch
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual int OnSwitch
        (int args, int argn, char *arg, int argc, char **argv)
        {
            m_cgi.SetOverwrite(m_on);
            return argn;
        }
    };

    const char *m_name;
    const char *m_content_type;
    const char *m_error_content_type;
    const char *m_output_content_type;
    const char *m_input_variable_name;
    const char *m_output_variable_name;
    const char *m_form_variable_name;
    const char *m_input_filename;
    const char *m_input_uri;
    const char *m_input_type;
    const char *m_output_filename;
    const char *m_output_uri;
    const char *m_output_type;
    const char *m_document_filename;
    const char *m_document_uri;
    const char *m_document_type;
    const char *m_transform_type;
    const char *m_command;

    bool m_requires_document_filename;
    bool m_requires_input_filename;
    bool m_overwrite;

    cOverwriteArgSwitch m_overwrite_switch;
    cOverwriteArgSwitch m_nonoverwrite_switch;

    cHTTPFormParameter m_content_type_form_parameter;
    cHTTPFormParameter m_transform_type_form_parameter;
    cHTTPFormParameter m_document_type_form_parameter;
    cHTTPFormParameter m_document_filename_form_parameter;
    cHTTPFormParameter m_document_uri_form_parameter;
    cHTTPFormParameter m_document_form_parameter;
    cHTTPFormParameter m_template_type_form_parameter;
    cHTTPFormParameter m_template_filename_form_parameter;
    cHTTPFormParameter m_template_uri_form_parameter;
    cHTTPFormParameter m_template_form_parameter;
    cHTTPFormParameter m_output_type_form_parameter;
    cHTTPFormParameter m_output_filename_form_parameter;
    cHTTPFormParameter m_output_uri_form_parameter;
    cHTTPFormParameter m_output_form_parameter;
    cHTTPFormParameter m_input_type_form_parameter;
    cHTTPFormParameter m_input_filename_form_parameter;
    cHTTPFormParameter m_input_uri_form_parameter;
    cHTTPFormParameter m_input_form_parameter;
    cHTTPFormParameter m_command_form_parameter;

    /**
     **********************************************************************
     * Constructor: cDocumentTemplateCGI
     *
     *      Author: $author$
     *        Date: 1/16/2004
     **********************************************************************
     */
    cDocumentTemplateCGI(const char *name="cDocumentTemplateCGI") 
    : m_name(name),
      m_input_variable_name("input"),
      m_output_variable_name("output"),
      m_form_variable_name("form"),
      m_content_type(0),
      m_error_content_type(m_content_type_none),
      m_output_content_type(m_content_type_none),
      m_transform_type(0),
      m_input_type(0),
      m_input_filename(0),
      m_input_uri(0),
      m_output_type(0),
      m_output_filename(0),
      m_output_uri(0),
      m_document_type("xml"),
      m_document_filename(0),
      m_document_uri(0),
      m_command(0),

      m_requires_document_filename(false),
      m_requires_input_filename(false),

      m_overwrite(false),
      m_overwrite_switch(*this, "overwrite", true),
      m_nonoverwrite_switch(*this, "nonoverwrite", false),

      m_content_type_form_parameter
      ("content_type", m_content_type, 1),

      m_transform_type_form_parameter
      ("transform_type", m_transform_type, 1),

      m_document_type_form_parameter
      ("document_type", m_document_type, 1),
      m_document_filename_form_parameter
      ("document_file", m_document_filename, 1),
      m_document_uri_form_parameter
      ("document_uri", m_document_uri, 1),
      m_document_form_parameter
      ("document", m_document_uri, 1),

      m_template_type_form_parameter
      ("template_type", m_input_type, 1),
      m_template_filename_form_parameter
      ("template_file", m_input_filename, 1),
      m_template_uri_form_parameter
      ("template_uri", m_input_uri, 1),
      m_template_form_parameter
      ("template", m_input_uri, 1),

      m_output_type_form_parameter
      ("output_type", m_output_type, 1),
      m_output_filename_form_parameter
      ("output_file", m_output_filename, 1),
      m_output_uri_form_parameter
      ("output_uri", m_output_uri, 1),
      m_output_form_parameter
      (m_output_variable_name, m_output_filename, 1),

      m_input_type_form_parameter
      ("input_type", m_input_type, 1),
      m_input_filename_form_parameter
      ("input_file", m_input_filename, 1),
      m_input_uri_form_parameter
      ("input_uri", m_input_uri, 1),
      m_input_form_parameter
      (m_input_variable_name, m_input_filename, 1),

      m_command_form_parameter("command", m_command, 1)
    {
    }

    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnCommand() 
    {
        m_requires_document_filename = RequiresDocumentFilename(false);
        m_requires_input_filename = RequiresInputFilename(false);
        m_error_content_type = m_content_type_none;
        m_output_content_type = m_content_type_none;

        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnCGI() 
    {
        m_requires_document_filename = RequiresDocumentFilename(true);
        m_requires_input_filename = RequiresInputFilename(true);
        m_error_content_type = m_content_type_html;
        m_output_content_type = m_content_type_text;

        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 12/13/2004
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

        if (m_requires_document_filename)
        if (!m_document_filename)
            return OnMissingDocumentFilename();

        if (m_requires_input_filename)
        if (!m_input_filename)
            return OnMissingTemplateFilename();

        result = OnTransform();
        return result;
    }

    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnTransform() 
    {
        int result=0;

        OutputContentType();
        return result;
    }

    /**
     **********************************************************************
     * Function: OnGetFormParameters
     *
     *   Author: $author$
     *     Date: 12/30/2003
     **********************************************************************
     */
    virtual int OnGetFormParameters()
    {
        int result=0;
        const char *name;
        eError error;
        cHTTPForm::cField *form_field;
        cHTTPFormParameter *form_parameter;

        if ((form_parameter = cHTTPFormParameter::m_list.GetFirst()))
        do
        {
            if ((name = form_parameter->GetName()))
            if ((form_field = GetFirstFormFieldByName(name)))
            if ((error = form_parameter->OnFormField(*form_field)))
                return 1;
        }
        while ((form_parameter = form_parameter->GetNext()));

        return result;
    }

    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if ((argn > 0) && (e_MODE_CGI != GetMode()))
        {
            if (!m_input_filename)
                m_input_filename = arg;

            else if (!m_output_filename)
                    m_output_filename = arg;
        }

        return cIs::OnMainArgValue(args, argn, arg, argc, argv);
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
     * Function: OnUnknownCommand
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnUnknownCommand()
    {
        return OnErrorMessageName
        ("unknown command", m_command);
    }
    /**
     **********************************************************************
     * Function: OnTransformationError
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnTransformationError(const char *error_message)
    {
        return OnErrorMessageName
        ("transformation error", error_message);
    }
    /**
     **********************************************************************
     * Function: OnUnknownTransformType
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnUnknownTransformType()
    {
        return OnErrorMessageName
        ("unknown transform type", m_transform_type);
    }
    /**
     **********************************************************************
     * Function: OnMissingTransformType
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnMissingTransformType()
    {
        return OnMissingParameter
        (m_transform_type_form_parameter.GetName());
    }

    /**
     **********************************************************************
     * Function: OnMissingInput
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    virtual int OnMissingInput() 
    {
        return OnMissingParameter
        (m_input_variable_name);
    }
    /**
     **********************************************************************
     * Function: OnMissingInputType
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    virtual int OnMissingInputType() 
    {
        return OnMissingParameter
        (m_input_type_form_parameter.GetName());
    }
    /**
     **********************************************************************
     * Function: OnMissingInputFilename
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    virtual int OnMissingInputFilename() 
    {
        return OnMissingParameter
        (m_input_filename_form_parameter.GetName());
    }
    /**
     **********************************************************************
     * Function: OnMissingTemplateType
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnMissingTemplateType()
    {
        return OnMissingParameter
        (m_template_type_form_parameter.GetName());
    }
    /**
     **********************************************************************
     * Function: OnMissingTemplateFilename
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnMissingTemplateFilename()
    {
        return OnMissingParameter
        (m_template_filename_form_parameter.GetName());
    }
    /**
     **********************************************************************
     * Function: OnMissingDocumentType
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnMissingDocumentType()
    {
        return OnMissingParameter
        (m_document_type_form_parameter.GetName());
    }
    /**
     **********************************************************************
     * Function: OnMissingDocumentFilename
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnMissingDocumentFilename()
    {
        return OnMissingParameter
        (m_document_filename_form_parameter.GetName());
    }
    /**
     **********************************************************************
     * Function: OnMissingParameter
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnMissingParameter(const char *name)
    {
        return OnErrorMessageName
        ("missing parameter", name);
    }
    /**
     **********************************************************************
     * Function: OnErrorMessageName
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnErrorMessageName
    (const char *message, const char *name)
    {
        int result=1;

        if (name)
            OutputErrorL
            (H1, m_name, H1_, BOLD, message, " \"", 
             BOLD_, name, BOLD, "\"", BOLD_, BR, 0);

        else OutputErrorL
        (H1, m_name, H1_, BOLD, message, BR, 0);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnErrorMessage
     *
     *   Author: $author$
     *     Date: 12/27/2003
     **********************************************************************
     */
    virtual int OnErrorMessage(const char *message)
    {
        int result=1;

        OutputErrorL
        (H1, m_name, H1_, BOLD, message, BR, 0);
        return result;
    }

    /**
     **********************************************************************
     * Function: GetInputFilename
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    const char *GetInputFilename()
    {
        if (!m_input_filename)
        if ((m_input_filename = m_env[e_ENV_PATH_TRANSLATED]))
        if (!m_input_filename[0])
            m_input_filename = 0;

        return m_input_filename;
    }

    /**
     **********************************************************************
     * Function: GetDocumentFilename
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual const char* GetDocumentFilename() 
    {
        if (m_document_filename)
        if (m_document_filename[0])
            return m_document_filename;

        return 0;
    }

    /**
     **********************************************************************
     * Function: RequiresDocumentFilename
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual bool RequiresDocumentFilename(bool on_cgi) 
    {
        bool on = false;
        return on;
    }
    /**
     **********************************************************************
     * Function: RequiresInputFilename
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual bool RequiresInputFilename(bool on_cgi) 
    {
        bool on = on_cgi;
        return on;
    }

    /**
     **********************************************************************
     * Function: OpenDocumentFile
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    eError OpenDocumentFile
    (cCharFile &file, const char *filename)
    {
        eError error = OpenFile(file, filename, "document");
        return error;
    }
    /**
     **********************************************************************
     * Function: CloseDocumentFile
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    eError CloseDocumentFile
    (cCharFile &file, const char *filename)
    {
        eError error = CloseFile(file, filename, "document");
        return error;
    }

    /**
     **********************************************************************
     * Function: OpenTemplateFile
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    eError OpenTemplateFile
    (cCharFile &file, const char *filename)
    {
        eError error = OpenFile(file, filename, "template");
        return error;
    }
    /**
     **********************************************************************
     * Function: CloseTemplateFile
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    eError CloseTemplateFile
    (cCharFile &file, const char *filename)
    {
        eError error = CloseFile(file, filename, "template");
        return error;
    }

    /**
     **********************************************************************
     * Function: OpenInputFile
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    eError OpenInputFile
    (cCharFile &file, const char *filename)
    {
        eError error = OpenFile(file, filename, "input");
        return error;
    }
    /**
     **********************************************************************
     * Function: CloseInputFile
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    eError CloseInputFile(cCharFile &file, const char *filename)
    {
        eError error = CloseFile(file, filename, "input");
        return error;
    }

    /**
     **********************************************************************
     * Function: OpenOutputFile
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    eError OpenOutputFile
    (cCharFile &file, 
     const char *filename, 
     const char *whatfile="output")
    {
        const char *whatspace = (*whatfile)?" ":"";
        eError error;

        if (!m_overwrite)
        if (!(error = file.Exist(filename))
            || (error != e_ERROR_NOT_EXIST))
        {
            OutputErrorFormatted
            ("%s%s%sfile \"%s%s%s\" already exists%s\n", 
             BOLD, whatfile, whatspace, BOLD_, filename, BOLD, BOLD_);
            return e_ERROR_ALREADY_EXIST;
        }

        if ((error = file.Open(filename, "w")))
            OutputErrorFormatted
            ("%sUnable to open %s%sfile \"%s%s%s\"%s\n", 
             BOLD, whatfile, whatspace, BOLD_, filename, BOLD, BOLD_);

        return error;
    }
    /**
     **********************************************************************
     * Function: OpenFile
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    eError OpenFile
    (cCharFile &file, 
     const char *filename, 
     const char *whatfile="")
    {
        const char *whatspace = (*whatfile)?" ":"";
        eError error;

        if ((error = file.Open(filename)))
            OutputErrorFormatted
            ("%sUnable to open %s%sfile \"%s%s%s\"%s\n", 
             BOLD, whatfile, whatspace, BOLD_, filename, BOLD, BOLD_);

        return error;
    }
    /**
     **********************************************************************
     * Function: CloseFile
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    eError CloseFile
    (cCharFile &file, 
     const char *filename, 
     const char *whatfile="")
    {
        const char *whatspace = (*whatfile)?" ":"";
        eError error;

        if ((error = file.Close()))
            OutputErrorFormatted
            ("%sUnable to close %s%sfile \"%s%s%s\"%s\n", 
             BOLD, whatfile, whatspace, BOLD_, filename, BOLD, BOLD_);

        return error;
    }

    /**
     **********************************************************************
     * Function: SetOverwrite
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    inline bool SetOverwrite(bool on=true)
    {
        bool was_on = m_overwrite;

        m_overwrite = on;
        return was_on;
    }
    /**
     **********************************************************************
     * Function: GetOverwrite
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    inline bool GetOverwrite() const
    {
        return m_overwrite;
    }

    /**
     **********************************************************************
     * Function: SetInputVariableName
     *
     *   Author: $author$
     *     Date: 7/12/2005
     **********************************************************************
     */
    inline const char* SetInputVariableName(const char* name) 
    {
        return m_input_variable_name = name;
    }
    /**
     **********************************************************************
     * Function: GetInputVariableName
     *
     *   Author: $author$
     *     Date: 7/12/2005
     **********************************************************************
     */
    inline const char* GetInputVariableName() const 
    {
        return m_input_variable_name;
    }

    /**
     **********************************************************************
     * Function: SetOutputVariableName
     *
     *   Author: $author$
     *     Date: 7/12/2005
     **********************************************************************
     */
    inline const char* SetOutputVariableName(const char* name) 
    {
        return m_output_variable_name = name;
    }
    /**
     **********************************************************************
     * Function: GetOutputVariableName
     *
     *   Author: $author$
     *     Date: 7/12/2005
     **********************************************************************
     */
    inline const char* GetOutputVariableName() const 
    {
        return m_output_variable_name;
    }
};

#endif /* ndef _CDOCUMENTTEMPLATECGI_HXX */
