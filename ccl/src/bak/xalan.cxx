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
 *   File: xalan.cxx
 *
 * Author: $author$
 *   Date: 12/11/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _XALAN_CXX
#define _XALAN_CXX

#include "ccgimain.hxx"
#include "ccontentstream.hxx"
#include "cxalandocument.hxx"
#include "cxalandocumentfactory.hxx"
#include "cxalanfunction.hxx"
#include "cxalantransformer.hxx"
#include "cxalancharstreamxsltresulttarget.hxx"
#include "cxerceserrorhandler.hxx"
#include "ccharbufferparameter.hxx"
#include "htmlmacro.h"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanParameter
 *
 * Author: $author$
 *   Date: 12/18/2003
 **********************************************************************
 */
class cXalanParameter
: public cCharBufferParameterT<cXalanParameter>
{
public:
    typedef cCharBufferParameterT<cXalanParameter> cIs;

    /**
     **********************************************************************
     * Constructor: cXalanParameter
     *
     *      Author: $author$
     *        Date: 12/18/2003
     **********************************************************************
     */
    cXalanParameter(const char *name, const char *&value) 
    : cIs(this, name, value) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXalanParameter
     *
     *      Author: $author$
     *        Date: 12/18/2003
     **********************************************************************
     */
    cXalanParameter(const char *name) 
    : cIs(this, name) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanParameter
     *
     *     Author: $author$
     *       Date: 12/18/2003
     **********************************************************************
     */
    virtual ~cXalanParameter()
    {
    }

    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 12/18/2003
     **********************************************************************
     */
    virtual eError OnElement(cXalanElement &element)
    {
        eError error;
        cXalanText text;

        if (!(error = element.GetFirstTextNode(text)))
            error = SetValue(text.GetCharText());

        return error;
    }
};

/*
 **********************************************************************
 *  Class: cXalanParameter::cIs::cList
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
cXalanParameter *cXalanParameter::cIs::cList::cIs::m_first=0;
cXalanParameter *cXalanParameter::cIs::cList::cIs::m_last=0;

/*
 **********************************************************************
 *  Class: cXalanParameter::cIs
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
cXalanParameter::cIs::cList cXalanParameter::cIs::m_list;

/**
 **********************************************************************
 *  Class: cXalanFormParameter
 *
 * Author: $author$
 *   Date: 12/19/2003
 **********************************************************************
 */
class cXalanFormParameter
: public cXalanParameter
{
public:
    typedef cXalanParameter cIs;

    /**
     **********************************************************************
     *  Class: cListItem
     *
     * Author: $author$
     *   Date: 12/19/2003
     **********************************************************************
     */
    class cListItem
    : public cListItemT<cListItem>
    {
    public:
        typedef cListItemT<cListItem> cIs;

        cXalanFormParameter &m_parameter;

        /**
         **********************************************************************
         * Constructor: cListItem
         *
         *      Author: $author$
         *        Date: 12/19/2003
         **********************************************************************
         */
        cListItem(cXalanFormParameter &parameter)
        : m_parameter(parameter)
        {
        }
    };

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 12/19/2003
     **********************************************************************
     */
    class cList
    : public cStaticListT<cListItem, cList>
    {
    public:
        typedef cStaticListT<cListItem, cList> cIs;

        /**
         **********************************************************************
         * Function: GetFirst
         *
         *   Author: $author$
         *     Date: 12/19/2003
         **********************************************************************
         */
        cXalanFormParameter *GetFirst() const
        {
            cListItem *item;

            if ((item = cIs::GetFirst()))
                return &item->m_parameter;

            return 0;
        }
    };

    static cList m_list;

    cListItem m_list_item;

    /**
     **********************************************************************
     * Constructor: cXalanFormParameter
     *
     *      Author: $author$
     *        Date: 12/19/2003
     **********************************************************************
     */
    cXalanFormParameter(const char *name, const char *&value)
    : cIs(name, value),
      m_list_item(*this)
    {
        m_list.Add(&m_list_item);
    }
    /**
     **********************************************************************
     * Constructor: cXalanFormParameter
     *
     *      Author: $author$
     *        Date: 12/19/2003
     **********************************************************************
     */
    cXalanFormParameter(const char *name) 
    : cIs(name),
      m_list_item(*this)
    {
        m_list.Add(&m_list_item);
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanFormParameter
     *
     *     Author: $author$
     *       Date: 12/19/2003
     **********************************************************************
     */
    virtual ~cXalanFormParameter()
    {
        m_list.Delete(&m_list_item);
    }

    /**
     **********************************************************************
     * Function: OnFormField
     *
     *   Author: $author$
     *     Date: 12/19/2003
     **********************************************************************
     */
    virtual eError OnFormField(cHTTPForm::cField &field)
    {
        eError error=0;
        const char *value;
        int length;

        if ((value = field.GetValue()))
        if (0 <= (length = field.GetValueLength()))
            error = SetValue(value, length);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 12/19/2003
     **********************************************************************
     */
    cXalanFormParameter *GetNext() const
    {
        cListItem *item;

        if ((item = m_list_item.GetNext()))
            return &item->m_parameter;

        return 0;
    }
};

/*
 **********************************************************************
 *  Class: cXalanFormParameter::cList
 *
 * Author: $author$
 *   Date: 12/19/2003
 **********************************************************************
 */
cXalanFormParameter::cListItem *cXalanFormParameter::cList::cIs::m_first=0;
cXalanFormParameter::cListItem *cXalanFormParameter::cList::cIs::m_last=0;

/*
 **********************************************************************
 *  Class: cXalanFormParameter
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
cXalanFormParameter::cList cXalanFormParameter::m_list;

/**
 **********************************************************************
 *  Class: cXalanFunctionParameter
 *
 * Author: $author$
 *   Date: 12/20/2003
 **********************************************************************
 */
class cXalanFunctionParameter
: public cXalanParameter
{
public:
    typedef cXalanParameter cIs;

    const char *m_name_attr_name;
    const char *m_namespace_attr_name;

    cXalanTransformer &m_xalan_transformer;

    /**
     **********************************************************************
     * Constructor: cXalanFunctionParameter
     *
     *      Author: $author$
     *        Date: 12/20/2003
     **********************************************************************
     */
    cXalanFunctionParameter
    (const char *name, cXalanTransformer &xalan_transformer) 
    : cIs(name),
      m_xalan_transformer(xalan_transformer),
      m_name_attr_name("name"),
      m_namespace_attr_name("namespace")
    {
    }

    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 12/20/2003
     **********************************************************************
     */
    virtual eError OnElement(cXalanElement &element)
    {
        const char *name;
        eError error;
        cXalanAttr name_attribute;
        cXalanAttr namespace_attribute;
        cXalanFunction *function;
        const nsXalan::XalanDOMString *xalan_name;
        const nsXalan::XalanDOMString *xalan_namespace;

        if (!(error = element.GetAttributeByName
            (name_attribute, m_name_attr_name)))
        if (!(error = element.GetAttributeByName
            (namespace_attribute, m_namespace_attr_name)))
        if ((xalan_namespace = namespace_attribute.GetText()))
        if ((xalan_name = name_attribute.GetText()))
        if ((name = name_attribute.GetCharText()))
        if ((function = cXalanFunction::m_static_list.GetFirstByName(name)))
        {
            function->SetDocumentFactory(&m_xalan_transformer.GetDocumentFactory());
            function->SetVariableSet(&m_xalan_transformer.GetVariableSet());

            m_xalan_transformer.installExternalFunction
            (*xalan_namespace, *xalan_name, *function);
        }
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cXalanCGI
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class cXalanCGI
: public cCGIMain
{
public:
    typedef cCGIMain cIs;

    cContentStream m_content_stream;

    const char *m_name;
    const char *m_form_variable_name;

    const char *m_config_filename;
    const char *m_document_filepath;
    const char *m_document_filename;
    const char *m_document_filename_extension;
    const char *m_template_filename;
    const char *m_template_filename_extension;
    const char *m_content_type;

    cXalanParameter m_name_parameter;
    cXalanParameter m_form_variable_name_parameter;
    cXalanFunctionParameter m_function_parameter;

    cXalanParameter m_config_filename_parameter;
    cXalanParameter m_document_filepath_parameter;
    cXalanFormParameter m_document_filename_parameter;
    cXalanFormParameter m_template_filename_parameter;
    cXalanFormParameter m_content_type_parameter;

    cXalanTransformer m_xalan_transformer;

    /**
     **********************************************************************
     * Constructor: cXalanCGI
     *
     *      Author: $author$
     *        Date: 12/11/2003
     **********************************************************************
     */
    cXalanCGI() 
    : m_content_stream(*this),

      m_name("xalan"),
      m_name_parameter("name", m_name),

      m_form_variable_name("form_parameters"),
      m_form_variable_name_parameter
      ("form_variable_name", m_form_variable_name),

      m_function_parameter
      ("external_function", m_xalan_transformer),

      m_config_filename("xalan_config.xml"),
      m_config_filename_parameter
      ("config_file", m_config_filename),

      m_document_filename(0),
      m_document_filename_extension("xml"),
      m_document_filename_parameter
      ("document_file", m_document_filename),

      m_document_filepath(0),
      m_document_filepath_parameter
      ("document_file_path", m_document_filepath),

      m_template_filename(0),
      m_template_filename_extension("xsl"),
      m_template_filename_parameter
      ("template_file", m_template_filename),

      m_content_type(0),
      m_content_type_parameter
      ("content_type", m_content_type)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanCGI
     *
     *     Author: $author$
     *       Date: 12/11/2003
     **********************************************************************
     */
    virtual ~cXalanCGI()
    {
    }

    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual int OnCommand()
    {
        SetContentType(GetContentTypeNone());
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual int OnCGI()
    {
        SetContentType(GetContentTypeHTML());
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual int OnCommandOrCGI()
    {
        eError error;
        cCharBuffer error_buffer;

        if (!(error = m_xalan_transformer.Initialize()))
        {
            if (!(error = OnGetConfigParameters()))
            if (!(error = OnGetFormParameters()))
            if (!(error = OnGetFormVariables()))
            if (!(error = OnSetTransformFormParameters()))
            {
                if (m_content_type)
                if (m_content_type[0])
                    SetContentType(m_content_type);

                OutputContentType();

                if (!GetTemplateFilename())
                    OnMissingParameter
                    (m_template_filename_parameter.GetName());
                else
                {
                    cXalanCharStreamXSLTResultTarget result_target(m_content_stream);

                    if (GetDocumentFilename())
                    {
                        error = m_xalan_transformer.Transform
                        (m_document_filename, m_template_filename,
                         result_target, &error_buffer);
                    }
                    else error = m_xalan_transformer.Transform
                         (m_template_filename,
                          result_target, &error_buffer);
                }

                if (error)
                    OnTransformationError(error_buffer.GetBuffer());
            }

            m_xalan_transformer.Finalize();
        }
        else OnTransformationError
             ("Transformer initialization failed");

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetTemplateFilename
     *
     *   Author: $author$
     *     Date: 8/1/2004
     **********************************************************************
     */
    const char *GetTemplateFilename()
    {
        if (0 >= m_template_filename_parameter.GetLength())
        if ((m_template_filename = m_env[e_ENV_PATH_TRANSLATED]))
        if (!m_template_filename[0])
            m_template_filename = 0;

        return m_template_filename;
    }
    /**
     **********************************************************************
     * Function: GetDocumentFilename
     *
     *   Author: $author$
     *     Date: 8/1/2004
     **********************************************************************
     */
    const char *GetDocumentFilename()
    {
        int length;
        const char *filename,*separator;
        cCharFile file;
        eError error;

        if ((filename = m_env[e_ENV_PATH_TRANSLATED]))
        if (filename[0])
        if (0 < m_document_filename_parameter.GetLength())
        {
            if (!(separator = strrchr(m_document_filename,'/')))
            if (!(separator = strrchr(m_document_filename,'\\')))
            if (!(separator = strrchr(m_document_filename,':')))
            {
                if (!(separator = strrchr(filename,'/')))
                if (!(separator = strrchr(filename,'\\')))
                    separator = strrchr(filename,':');

                if (separator)
                if (separator > filename)
                if (0 < (length = m_document_filepath_parameter.Copy
                         (filename, separator-filename+1)))
                if (0 < (length = m_document_filepath_parameter.Write
                         (m_document_filename)))
                if ((filename = m_document_filepath_parameter.GetValue()))
                    m_document_filename = filename;
            }
        }
        else 
        {
            if ((separator = strrchr(filename,'.')))
            if (0 < (length = m_document_filepath_parameter.Copy
                     (filename, separator-filename+1)))
            if (0 < (length = m_document_filepath_parameter.Write
                     (m_document_filename_extension)))
            if ((filename = m_document_filepath_parameter.GetValue()))
            if (!(error = file.Exist(filename)))
                m_document_filename = filename;
        }
        return m_document_filename;
    }
    /**
     **********************************************************************
     * Function: OnSetTransformFormParameters
     *
     *   Author: $author$
     *     Date: 7/25/2004
     **********************************************************************
     */
    virtual int OnSetTransformFormParameters()
    {
        int result=0;
        int namelen,valuelen;
        const char *name,*value;
        cHTTPForm::cField *form_field;

        if ((form_field = GetFirstFormField()))
        do
        {
            if ((name = form_field->GetName(namelen)))
            if (0 < namelen)
            if ((value = form_field->GetValue(valuelen)))
                m_xalan_transformer.SetParameter(name, value);
        }
        while ((form_field = form_field->GetNext()));

        return result;
    }
    /**
     **********************************************************************
     * Function: OnGetFormVariables
     *
     *   Author: $author$
     *     Date: 12/24/2003
     **********************************************************************
     */
    virtual int OnGetFormVariables()
    {
        int result=0;
        cXalanDocumentFactoryInterface &document_factory=m_xalan_transformer.GetDocumentFactory();
        cXalanVariableSetInterface &variable_set=m_xalan_transformer.GetVariableSet();
        nsXalan::XalanDocument *xalan_document;
        nsXalan::XalanElement *xalan_element;
        nsXalan::XalanElement *xalan_child_element;
        nsXalan::XalanText *xalan_child_text;
        cHTTPForm::cField *form_field;
        const char *field_name;
        const char *field_value;
        eError error;

        if ((xalan_document = document_factory.GetXalanDocument(error)))
        {
            nsXalan::XalanDOMString xalan_string(m_form_variable_name);

            if ((xalan_element = xalan_document->createElement(xalan_string)))
            {
                xalan_document->appendChild(xalan_element);

                if (!(error = variable_set.Set(m_form_variable_name, xalan_element)))
                if ((form_field = GetFirstFormField()))
                do
                {
                    if (0 < (form_field->GetNameLength()))
                    if ((field_name = form_field->GetName()))
                    {
                        xalan_string.assign(field_name);

                        if ((xalan_child_element = xalan_document->
                            createElement(xalan_string)))
                        {
                            xalan_element->appendChild(xalan_child_element);

                            if (0 < (form_field->GetValueLength()))
                            if ((field_value = form_field->GetValue()))
                            {
                                xalan_string.assign(field_value);

                                if ((xalan_child_text = xalan_document->
                                    createTextNode(xalan_string)))
                                    xalan_child_element->appendChild(xalan_child_text);
                            }
                        }
                    }
                }
                while ((form_field = form_field->GetNext()));
            }
        }

        return result;
    }
    /**
     **********************************************************************
     * Function: OnGetFormParameters
     *
     *   Author: $author$
     *     Date: 12/19/2003
     **********************************************************************
     */
    virtual int OnGetFormParameters()
    {
        int result=0;
        eError error;
        cHTTPForm::cField *form_field;
        cXalanFormParameter *form_parameter;

        if ((form_parameter = cXalanFormParameter::m_list.GetFirst()))
        do
        {
            if ((form_field = GetFirstFormFieldByName
                (form_parameter->GetName())))
            if ((error = form_parameter->OnFormField(*form_field)))
                return 1;
        }
        while ((form_parameter = form_parameter->GetNext()));

        return result;
    }
    /**
     **********************************************************************
     * Function: OnGetConfigParameters
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual int OnGetConfigParameters()
    {
        int result=0;
        int count;
        eError error;
        nsXalan::XalanDocument *config_document;
        cXalanParameter *parameter;
        cCharBuffer error_buffer;
        cCharFile file;

        do
        {
            m_config_filename_parameter.SetChanged(false);

            if (0 < m_config_filename_parameter.GetLength())
            if (0 <= (count = error_buffer.Clear()))
            if (!(error = file.Open(m_config_filename)))
            {
                if ((config_document = m_xalan_transformer.
                    ParseXalanDocument(file, &error_buffer)))
                {
                    cXalanDocument document(config_document);
                    cXalanElement root_element;
                    cXalanElement element;
                    cXalanText text;

                    if ((parameter = cXalanParameter::m_list.GetFirst()))
                    if (!(error = document.GetFirstElement(root_element)))
                    do
                    {
                        if (!(error = root_element.GetFirstElementByName
                            (element, parameter->GetName())))
                        do
                        {
                            if ((error = parameter->OnElement(element)))
                                break;
                        }
                        while (!(error = element.GetNextElementByName
                                 (element, parameter->GetName())));
                    }
                    while ((parameter = parameter->GetNext()));

                    m_xalan_transformer.FreeXalanDocument(*config_document);
                }
                else result = OnParseError(error_buffer.GetBuffer());

                file.Close();
            }

            if (result)
                break;
        }
        while (m_config_filename_parameter.GetChanged());

        return result;
    }
    /**
     **********************************************************************
     * Function: OnMissingParameter
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual int OnMissingParameter(const char *name)
    {
        OutputContentType();
        OutputErrorL
        (H1, m_name, H1_, UL, BOLD, "missing parameter \"", 
         BOLD_, name, BOLD, "\"", BOLD_, UL_, 0);
        return 1;
    }
    /**
     **********************************************************************
     * Function: OnParseError
     *
     *   Author: $author$
     *     Date: 12/14/2003
     **********************************************************************
     */
    virtual int OnParseError(const char *error_string)
    {
        OutputContentType();
        OutputErrorL
        (H1, m_name, H1_, UL, BOLD, "parse error \"", 
         BOLD_, error_string, BOLD, "\"", BOLD_, UL_, 0);
        return 1;
    }
    /**
     **********************************************************************
     * Function: OnTransformationError
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual int OnTransformationError(const char *error_string)
    {
        OutputContentType();
        OutputErrorL
        (H1, m_name, H1_, UL, BOLD, "transformation error \"", 
         BOLD_, error_string, BOLD, "\"", BOLD_, UL_, 0);
        return 1;
    }
} g_xalan_cgi;

#endif /* ndef _XALAN_CXX */
