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
 *   File: ascii.cxx
 *
 * Author: $author$
 *   Date: 3/25/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumenttemplatecgi.hxx"
#include "htmlmacro.h"

/**
 **********************************************************************
 *  Class: cASCIICGI
 *
 * Author: $author$
 *   Date: 3/25/2004
 **********************************************************************
 */
class cASCIICGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    int m_char_min,m_char_max;
    const char *m_char_allow;

    const char *m_echo_document_command;

    /**
     **********************************************************************
     * Constructor: cASCIICGI
     *
     *      Author: $author$
     *        Date: 3/25/2004
     **********************************************************************
     */
    cASCIICGI(const char *name="ascii")
    : cIs(name),
      m_char_min(32),
      m_char_max(127),
      m_char_allow("\n\r\t"),
      m_echo_document_command("echo_document")
    {
    }

    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 3/18/2004
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
     *     Date: 3/18/2004
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
     *     Date: 3/18/2004
     **********************************************************************
     */
    virtual int OnCommandOrCGI()
    {
        int c,result=0;
        cContentDocumentSource content_output_document(*this);
        cFileDocumentSource file_document_source;

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        if (!m_document_filename)
            return OnMissingDocumentFilename();

        if (m_command)
        {
            if (!strcmp(m_command, m_echo_document_command))
            {
                if (!(result = OnOpenDocumentFileSource
                    (file_document_source, m_document_filename)))
                {
                    OutputContentType(m_output_content_type);

                    OutputFromStream(file_document_source);
                    file_document_source.Close();
                }
            }
            else result = OnUnknownCommand();
        }
        else
        {
            if (!(result = OnOpenDocumentFileSource
                (file_document_source, m_document_filename)))
            {
                OutputContentType(m_output_content_type);

                while (0 <= (c = file_document_source.Getc()))
                    if (((m_char_min <= c) && (m_char_max >= c)) 
                        || strchr(m_char_allow, c))
                        content_output_document.Putc(c);

                file_document_source.Close();
            }
        }
        return result;
    }
} g_ascii_cgi;
