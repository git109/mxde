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

#include "ccontentstream.hxx"
#include "cargswitch.hxx"
#include "ccharfile.hxx"
#include "ct.hxx"
#include "ccgi.hxx"

/**
 **********************************************************************
 *  Class: cTCGI
 *
 * Author: $author$
 *   Date: 8/14/2003
 **********************************************************************
 */
class cTCGI
: public cCGI
{
public:
    typedef cCGI cIs;

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

        cTCGI &m_cgi;
        bool m_on;

        /**
         **********************************************************************
         * Constructor: cOverwriteArgSwitch
         *
         *      Author: $author$
         *        Date: 8/18/2003
         **********************************************************************
         */
        cOverwriteArgSwitch(cTCGI &cgi, const char *name, bool on) 
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

    static cTCGI *m_instance;

    const char *m_error_content_type;
    const char *m_input_variable_name;
    const char *m_output_variable_name;
    const char *m_input_filename;
    const char *m_output_filename;

    bool m_overwrite;

    cT m_t;

    cOverwriteArgSwitch m_overwrite_switch;
    cOverwriteArgSwitch m_nonoverwrite_switch;

    /**
     **********************************************************************
     * Constructor: cTCGI
     *
     *      Author: $author$
     *        Date: 8/14/2003
     **********************************************************************
     */
    cTCGI()
    : m_input_variable_name("input"),
      m_output_variable_name("output"),
      m_input_filename(0),
      m_output_filename(0),
      m_error_content_type(m_content_type_none),
      m_overwrite(false),
      m_overwrite_switch(*this, "overwrite", true),
      m_nonoverwrite_switch(*this, "nonoverwrite", false)
    {
        eError error;

        if (m_instance)
            throw(error = e_ERROR_ALREADY_INSTANTIATED);

        m_instance = this;
    }
    /**
     **********************************************************************
     * Destructor: ~cTCGI
     *
     *     Author: $author$
     *       Date: 8/14/2003
     **********************************************************************
     */
    virtual ~cTCGI()
    {
        eError error;

        if (m_instance != this)
            throw(error = e_ERROR_NOT_INSTANTIATED);

        m_instance = 0;
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual int OnCGI()
    {
        cHTTPForm::cField *field;

        m_error_content_type = m_content_type_text;

        if ((field = GetFirstFormFieldByName
            (m_input_variable_name)))
        if ((m_input_filename = field->GetValue()))
        if (!m_input_filename[0])
            m_input_filename = 0;

        if (!m_input_filename)
        {
            OutputErrorFormatted
            ("\"%s\" missing\n", m_input_variable_name);
            return 1;
        }
        return OnCommand();
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
        eError error;
        cCharFile output;
        cCharFile input(stdin);
        cContentStream content(*this);

        SetContentType(m_error_content_type);

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

        if (m_output_filename)
        {
            error = m_t.Expand(output, input);

            OutputFormatted
            ("%s output file \"%s\"\n",
             error?"Failed to create":"Created", m_output_filename);
        }
        else
        {
            OutputContentType(m_content_type_none);
            error = m_t.Expand(content, input);
        }

        m_t.Finalize();

        if (error)
            return 1;

        return 0;
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
        if (argn > 0)
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
     * Function: GetFormVariables
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    int GetFormVariables()
    {
        cHTTPForm::cField *field;
        int count = 0;

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
     * Function: OpenInputFile
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    eError OpenInputFile(cCharFile &file, const char *filename)
    {
        eError error;

        if ((error = file.Open(filename)))
            OutputErrorFormatted
            ("Unable to open input file \"%s\"\n", filename);

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
    eError OpenOutputFile(cCharFile &file, const char *filename)
    {
        eError error;

        if (!m_overwrite)
        if (!(error = file.Exist(filename))
            || (error != e_ERROR_NOT_EXIST))
        {
            OutputErrorFormatted
            ("Output file \"%s\" already exists\n", filename);
            return e_ERROR_ALREADY_EXIST;
        }

        if ((error = file.Open(filename, "w")))
            OutputErrorFormatted
            ("Unable to open output file \"%s\"\n", filename);

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
} g_t_cgi;

cTCGI *cTCGI::m_instance = 0;

/**
 **********************************************************************
 *  Class: cTCGIOverwriteArgSwitch
 *
 * Author: $author$
 *   Date: 8/18/2003
 **********************************************************************
 */
class cTCGIOverwriteArgSwitch
: public cArgSwitch
{
public:
    typedef cArgSwitch cIs;

    bool m_on;

    /**
     **********************************************************************
     * Constructor: cTCGIOverwriteArgSwitch
     *
     *      Author: $author$
     *        Date: 8/18/2003
     **********************************************************************
     */
    cTCGIOverwriteArgSwitch(const char *name, bool on) 
    : cIs(name),
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
        cTCGI *cgi;

        if ((cgi = cTCGI::m_instance))
            cgi->SetOverwrite(m_on);

        return argn;
    }
};

cTCGIOverwriteArgSwitch g_tcgi_overwrite_switch("overwrite", true);
cTCGIOverwriteArgSwitch g_tcgi_nonoverwrite_switch("nonoverwrite", false);
