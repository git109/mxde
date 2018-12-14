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
 * File:   t.cxx
 *
 * Author: $author$
 * Date:   6/30/2003
 *
 **********************************************************************
 */

#include "cdocumenttemplatecgi.hxx"
#include "cdocumentfactory.hxx"
#include "chttpformparameter.hxx"
#include "ccontentstream.hxx"
#include "ccgimain.hxx"
#include "ct.hxx"

/**
 **********************************************************************
 *  Class: cTCGI
 *
 * Author: $author$
 *   Date: 8/14/2003
 **********************************************************************
 */
class cTCGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    cT m_t;

    /**
     **********************************************************************
     * Constructor: cTCGI
     *
     *      Author: $author$
     *        Date: 8/14/2003
     **********************************************************************
     */
    cTCGI(const char *name="t")
    : cIs(name)
    {
    }

    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
    virtual int OnCommand()
    {
        int result;
        eError error;
        cCharFile output;
        cCharFile input(stdin);
        cContentStream content(*this);

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        else 
        {
            if (m_output_type)
            if ((m_content_type = GetTypeContentType(m_output_type)))
                m_output_content_type = m_content_type;
        }

        m_input_filename = GetInputFilename();
                
        if (m_requires_input_filename)
        if (!m_input_filename)
        {
            OutputErrorFormatted
            ("\"%s\" missing\n", m_input_variable_name);
            return 1;
        }

        if (m_input_filename)
        if ((error = OpenInputFile(input, m_input_filename)))
            return 1;

        if (m_output_filename)
        if ((error = OpenOutputFile(output, m_output_filename)))
            return 1;

        if ((error = m_t.Initialize()))
        {
            OutputErrorFormatted("T initialize failed\n");
            return 1;
        }

        GetFormVariables();

        if (!(result = OnGetDocument()))
        {
            if (m_output_filename)
            {
                error = m_t.Expand(output, input);

                OutputFormatted
                ("%s output file \"%s\"\n",
                 error?"Failed to create":"Created", m_output_filename);
            }
            else
            {
                OutputContentType(m_output_content_type);
                error = m_t.Expand(content, input);
            }
        }

        m_t.Finalize();

        if (error)
            return 1;

        return result;
    }
    /**
     **********************************************************************
     * Function: GetInputFilename
     *
     *   Author: $author$
     *     Date: 8/10/2004
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
     * Function: OnGetDocument
     *
     *   Author: $author$
     *     Date: 1/3/2004
     **********************************************************************
     */
    virtual int OnGetDocument()
    {
        int result=0;
        eError error;
        cCharFile file;
        cElementInterface *element;
        const char *text;

        if (m_document_type)
        if (m_document_type[0])
        if (m_document_filename)
        if (m_document_filename[0])
        if (!(error = OpenFile(file, m_document_filename)))
        {
            if ((m_document = m_document_factory.CreateDocumentByType
                (m_document_type)))
            if ((error = m_document->ParseFromStream(file)))
                result = 1;

            else
            {
                m_t.SetDocument(m_document);

                if ((element = m_document->GetFirstElement()))
                {
                    text = element->GetText();
                    m_t.SetElement(element);
                }
            }

            file.Close();
        }
        else result = 1;

        return result;
    }
    /**
     **********************************************************************
     * Function: GetFormVariables
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    int GetFormVariables()
    {
        cElementInterface *element=0;
        cElementInterface *child,*text;
        cDocumentInterface *document;
        cTInterface::cVariableInterface *variable;
        cHTTPForm::cField *field;
        int count = 0;

        if ((variable = m_t.GetVariable(m_form_variable_name)))
        if ((document = m_document_factory.CreateDocument()))
        if ((element = document->AddElement(m_form_variable_name)))
            variable->SetElement(element);
        else document->FreeInstance();

        if ((field = GetFirstFormField()))
        do
        {
            if (element)
            if ((child = element->AddElement
                (field->GetName(), field->GetNameLength())))
                text = child->AddTextElement
                (field->GetValue(), field->GetValueLength());

            m_t.SetValue
            (field->GetName(), field->GetNameLength(),
             field->GetValue(), field->GetValueLength());
            ++count;
        }
        while ((field = field->GetNext()));

        return count;
    }
} g_tcgi;
