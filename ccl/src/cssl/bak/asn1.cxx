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
 *   File: asn1.cxx
 *
 * Author: $author$
 *   Date: 2/2/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumenttemplatecgi.hxx"
#include "casn1parser.hxx"
#include "cbytefile.hxx"

/**
 **********************************************************************
 *  Class: cASN1ToXMLParser
 *
 * Author: $author$
 *   Date: 2/3/2005
 **********************************************************************
 */
class cASN1ToXMLParser
: public cASN1Parser
{
public:
    typedef cASN1Parser cIs;

    cCharStream &m_out;

    /**
     **********************************************************************
     * Constructor: cASN1ToXMLParser
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cASN1ToXMLParser(cCharStream &out) 
    : m_out(out)
    {
    }
    /**
     **********************************************************************
     * Function: OnObjectIDValue
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    virtual eError OnObjectIDValue
    (const cASN1ObjectIdentifier &id) 
    {
        eError error = e_ERROR_NONE;
        const char *name = id.GetName();

        m_out.WriteL("<ObjectIdentifier name=\"", name, "\"/>\n", 0);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPrimative
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    virtual eError OnPrimative
    (cBYTEStream &stream, const char *name,
     unsigned type, unsigned length) 
    {
        eError error = e_ERROR_NONE;

        m_out.WriteL("<Primative name=\"", name, "\" length=\"", 0);
        m_out.WriteInt(length);
        m_out.Write("\">\n");

        error = cIs::OnPrimative(stream, name, type, length);

        m_out.Write("</Primative>\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnConstruct
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    virtual eError OnConstruct
    (cBYTEStream &stream, const char *name,
     unsigned type, unsigned length) 
    {
        eError error = e_ERROR_NONE;

        m_out.WriteL("<Construct name=\"", name, "\" length=\"", 0);
        m_out.WriteInt(length);
        m_out.Write("\">\n");

        error = cIs::OnConstruct(stream, name, type, length);

        m_out.Write("</Construct>\n");
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cASN1CGI
 *
 * Author: $author$
 *   Date: 2/2/2005
 **********************************************************************
 */
class cASN1CGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    cASN1ToXMLParser m_parser;

    /**
     **********************************************************************
     * Constructor: cASN1CGI
     *
     *      Author: $author$
     *        Date: 2/2/2005
     **********************************************************************
     */
    cASN1CGI(const char *name="asn1")
    : cIs(name),
      m_parser(m_out)
    {
    }
    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 2/2/2005
     **********************************************************************
     */
    virtual int OnCommand() 
    {
        int result;

        eError error;
        cCharFile output;
        cBYTEFile input(stdin);
        cContentStream content(*this);

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        else if (m_output_type)
        {           
            if ((m_content_type = GetTypeContentType(m_output_type)))
                m_output_content_type = m_content_type;
        }
        else m_output_content_type = m_content_type_xml;

        m_input_filename = GetInputFilename();
                
        if (!m_input_filename)
        {
            OutputErrorFormatted
            ("\"%s\" missing\n", m_input_variable_name);
            return 1;
        }

        if ((error = OpenInputFile(input, m_input_filename)))
            return 1;

        OutputContentType(m_output_content_type);

        m_parser.Parse(input);
        return result;
    }
    /**
     **********************************************************************
     * Function: OpenInputFile
     *
     *   Author: $author$
     *     Date: 2/3/2005
     **********************************************************************
     */
    eError OpenInputFile(cBYTEFile &file, const char *filename)
    {
        eError error;

        if ((error = file.Open(filename, "rb")))
            OutputErrorFormatted
            ("Unable to open input file \"%s\"\n", filename);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetInputFilename
     *
     *   Author: $author$
     *     Date: 2/3/2005
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
} g_asn1;
