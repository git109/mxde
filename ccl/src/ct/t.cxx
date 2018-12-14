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
 *   File: t.cxx
 *
 * Author: $author$
 *   Date: 11/25/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumenttemplatecgi.hxx"
#include "chttpformparameter.hxx"
#include "ccontentstream.hxx"
#include "ccgimain.hxx"
#include "ct.hxx"

/**
 **********************************************************************
 *  Class: cTCGI
 *
 * Author: $author$
 *   Date: 11/25/2005
 **********************************************************************
 */
class cTCGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    cContentStream m_content;
    cT m_t;

    /**
     **********************************************************************
     * Constructor: cTCGI
     *
     *      Author: $author$
     *        Date: 11/25/2005
     **********************************************************************
     */
    cTCGI(const char *name="t")
    : cIs(name), 
      m_content(*this)
    {
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
        cCharFile output;
        cCharFile input(stdin);

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

        GetEnvVariables();
        GetFormVariables();

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
            error = m_t.Expand(m_content, input);
        }

        m_t.Finalize();

        if (error)
            return 1;

        return result;
    }
    /**
     **********************************************************************
     * Function: OnGetMissingContentType
     *
     *   Author: $author$
     *     Date: 11/17/2003
     **********************************************************************
     */
    virtual int OnGetMissingContentType()
    {
        int result = 0;

        if (m_output_type)
        if ((m_content_type = GetTypeContentType(m_output_type)))
            m_output_content_type = m_content_type;

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
        cHTTPForm::cField *field;
        const char *variable_name;
        int count = 0;

        if (m_input_filename 
            && (variable_name = GetInputVariableName()))
            m_t.SetValue
            (variable_name, -1, m_input_filename, -1);

        if (m_output_filename 
            && (variable_name = GetOutputVariableName()))
            m_t.SetValue
            (variable_name, -1, m_output_filename, -1);

        if ((field = GetFirstFormField()))
        do
        {
            m_t.SetValue
            (field->GetName(), field->GetNameLength(),
             field->GetValue(), field->GetValueLength());

            ++count;
        }
        while ((field = field->GetNext()));

        return count;
    }
    /**
     **********************************************************************
     * Function: GetEnvVariables
     *
     *   Author: $author$
     *     Date: 7/29/2005
     **********************************************************************
     */
    int GetEnvVariables()
    {
        int env, count = 0;
        const char *name, *value;

        for (env = e_FIRST_ENV; env <= e_LAST_ENV; env++)
        {
            if ((name = m_env_name[env]))
            if ((value = m_env[env]))
            {
                m_t.SetValue(name, -1, value);
                count++;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: GetInputFilename
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual const char *GetInputFilename()
    {
        return cIs::GetInputFilename();
    }
} g_tcgi;

