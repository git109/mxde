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
 *   File: chttpcontent.hxx
 *
 * Author: $author$
 *   Date: 8/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPCONTENT_HXX
#define _CHTTPCONTENT_HXX

#include "ccharstream.hxx"
#include "ccontentinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cHTTPContent
 *
 * Author: $author$
 *   Date: 8/5/2003
 **********************************************************************
 */
class cHTTPContent
: virtual public cContentInterface,
  public cImplement
{
public:
    typedef cImplement cIs;

    /**
     **********************************************************************
     *   Enum: eContentType
     *
     * Author: $author$
     *   Date: 8/9/2003
     **********************************************************************
     */
    enum eContentType
    {
        e_FIRST_CONTENT_TYPE,
        e_CONTENT_TYPE_URLENCODED = e_FIRST_CONTENT_TYPE,
        e_CONTENT_TYPE_MULTIPART,
        e_CONTENT_TYPE_TEXT,
        e_CONTENT_TYPE_HTML,
        e_CONTENT_TYPE_XML,
        e_CONTENT_TYPE_UNKNOWN,
        e_NUMBEROF_CONTENT_TYPES = e_CONTENT_TYPE_UNKNOWN,
        e_LAST_CONTENT_TYPE = e_NUMBEROF_CONTENT_TYPES-1
    };

    static const char *m_content_types[e_NUMBEROF_CONTENT_TYPES];
    static const char *m_content_type_types[e_NUMBEROF_CONTENT_TYPES];

    static const char *m_before_content_type;
    static const char *m_after_content_type;
    static const char *m_content_type_none;
    static const char *m_content_type_text;
    static const char *m_content_type_html;
    static const char *m_content_type_xml;
    static const char *m_content_type_rtf;

    bool m_output_error;
    const char *m_output_content_type;
    const char *m_content_type;

    cCharStream *m_out;
    cCharStream *m_err;

    /**
     **********************************************************************
     * Constructor: cHTTPContent
     *
     *      Author: $author$
     *        Date: 8/5/2003
     **********************************************************************
     */
    cHTTPContent
    (cCharStream *out=0, cCharStream *err=0, 
     const char *content_type=0)
    : m_output_error(false),
      m_output_content_type(0),
      m_content_type(content_type),
      m_out(out),
      m_err(err)
    {
        if (!m_content_type)
            m_content_type = m_content_type_text;
    }
    /**
     **********************************************************************
     * Destructor: ~cHTTPContent
     *
     *     Author: $author$
     *       Date: 8/5/2003
     **********************************************************************
     */
    virtual ~cHTTPContent()
    {
    }
    /**
     **********************************************************************
     * Function: OutputContentType
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int OutputContentType(const char *content_type=0)
    {
        int count;
        int size = 0;

        if (!m_out)
            return -e_ERROR_NOT_ATTACHED;

        if (m_output_content_type)
            return 0;

        if (!(m_output_content_type = content_type))
            m_output_content_type = m_content_type;

        else if (!m_output_content_type[0])
                m_output_content_type=m_content_type_none;

        else if (!strcmp(m_output_content_type,m_content_type_html))
                m_output_content_type=m_content_type_html;

        else if (!strcmp(m_output_content_type,m_content_type_xml))
                m_output_content_type=m_content_type_xml;

        else if (!strcmp(m_output_content_type,m_content_type_text))
                m_output_content_type=m_content_type_text;

        m_content_type = m_output_content_type;

        if (m_output_content_type != m_content_type_none)

        if ((size = m_out->Write(m_before_content_type)) >= 0)
        {
            if ((count = m_out->Write(m_output_content_type)) < 0)
                return count;

            size += count;

            if ((count = m_out->Write(m_after_content_type)) < 0)
                return count;

            size += count;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OutputErrorFormatted
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int OutputErrorFormatted(const char *format,...)
    {
        int count;
        va_list va;

        va_start(va,format);
        count=VOutputErrorFormatted(format,va);
        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: VOutputErrorFormatted
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int VOutputErrorFormatted(const char *format,va_list va)
    {
        int count;
        int size=0;
        bool output_xml_error=false;

        if (!m_err)
            return -e_ERROR_NOT_ATTACHED;

        if (m_output_error)
            return 0;

        m_output_error=true;

        if (m_err == m_out)
        if (!m_output_content_type)
        if ((count = OutputContentType()) < 0)
            return count;
        else size += count;

        if ((output_xml_error=(m_output_content_type==m_content_type_xml)))
        if ((count = m_err->Write("<error>\n")) < 0)
            return count;
        else size += count;

        if ((count = m_err->VPrintFormatted(format,va)) < 0)
            return count;
        else size += count;

        if (output_xml_error)
        {
            if ((count = m_err->Write("</error>\n")) < 0)
                return count;
            else size += count;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: OutputFormatted
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int OutputFormatted(const char *format,...)
    {
        int count;
        va_list va;

        va_start(va,format);
        count=VOutputFormatted(format,va);
        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: VOutputFormatted
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int VOutputFormatted(const char *format,va_list va)
    {
        int count;
        int size=0;

        if (!m_out)
            return -e_ERROR_NOT_ATTACHED;

        if (!m_output_content_type)
        if ((count = OutputContentType()) < 0)
            return count;
        else size += count;

        if ((count = m_out->VPrintFormatted(format,va)) < 0)
            return count;
        else size += count;

        return size;
    }

    /**
     **********************************************************************
     * Function: OutputL
     *
     *   Author: $author$
     *     Date: 12/5/2003
     **********************************************************************
     */
    virtual int OutputL(const char *buffer,...)
    {
        int count,count2;
        va_list va;

        va_start(va,buffer);

        if (0 <= (count = Output(buffer)))
        if (0 <= (count2 = OutputV(va)))
            count += count2;
        else count = count2;

        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputV
     *
     *   Author: $author$
     *     Date: 12/5/2003
     **********************************************************************
     */
    virtual int OutputV(va_list va)
    {
        int count,count2;
        const char *buffer;

        for (count = 0; 0 != (buffer = va_arg(va,const char *)); count += count2)
            if (0 > (count2 = Output(buffer)))
                return count2;

        return count;
    }

    /**
     **********************************************************************
     * Function: OutputErrorL
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual int OutputErrorL(const char *buffer,...)
    {
        int count,count2;
        va_list va;

        va_start(va,buffer);

        if (0 <= (count = OutputError(buffer)))
        if (0 <= (count2 = OutputErrorV(va)))
            count += count2;
        else count = count2;

        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: OutputErrorV
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual int OutputErrorV(va_list va)
    {
        int count,count2;
        const char *buffer;

        for (count = 0; 0 != (buffer = va_arg(va,const char *)); count += count2)
        {
            m_output_error=false;

            if (0 > (count2 = OutputError(buffer)))
                return count2;
        }

        return count;
    }

    /**
     **********************************************************************
     * Function: OutputError
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int OutputError(const char *buffer,int length=-1)
    {
        int count;
        int size=0;

        if (!m_err)
            return -e_ERROR_NOT_ATTACHED;

        if (m_output_error)
            return 0;

        m_output_error=true;

        if (m_err == m_out)
        if (!m_output_content_type)
        if ((count = OutputContentType()) < 0)
            return count;
        else size += count;

        if ((count = m_err->Write(buffer, length)) < 0)
            return count;
        else size += count;

        return size;
    }
    /**
     **********************************************************************
     * Function: Output
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int Output(const char *buffer,int length=-1)
    {
        int count;
        int size=0;

        if (!m_out)
            return -e_ERROR_NOT_ATTACHED;

        if (!m_output_content_type)
        if ((count = OutputContentType()) < 0)
            return count;
        else size += count;

        if ((count = m_out->Write(buffer, length)) < 0)
            return count;
        else size += count;

        return size;
    }
    /**
     **********************************************************************
     * Function: SetOut
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual cCharStream *SetOut(cCharStream *out)
    {
        cCharStream *old_out = m_out;

        m_out = out;
        return old_out;
    }
    /**
     **********************************************************************
     * Function: GetOut
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual cCharStream *GetOut() const
    {
        return m_out;
    }
    /**
     **********************************************************************
     * Function: SetErr
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual cCharStream *SetErr(cCharStream *err)
    {
        cCharStream *old_err = m_err;

        m_err = err;
        return old_err;
    }
    /**
     **********************************************************************
     * Function: GetErr
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual cCharStream *GetErr() const
    {
        return m_err;
    }
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual const char *SetContentType(const char *content_type)
    {
        const char *old_content_type = m_content_type;

        m_content_type = content_type;
        return old_content_type;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 8/14/2003
     **********************************************************************
     */
    virtual const char *GetContentType() const
    {
        return m_content_type;
    }
    /**
     **********************************************************************
     * Function: GetOutputContentType
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetOutputContentType() const
    {
        return m_output_content_type;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeXML
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeXML() const
    {
        return m_content_type_xml;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeHTML
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeHTML() const
    {
        return m_content_type_html;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeText
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeText() const
    {
        return m_content_type_text;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeNone
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeNone() const
    {
        return m_content_type_none;
    }
    /**
     **********************************************************************
     * Function: GetTypeContentType
     *
     *   Author: $author$
     *     Date: 1/14/2004
     **********************************************************************
     */
    static const char *GetTypeContentType(const char *type)
    {
        int t;

        for (t = e_FIRST_CONTENT_TYPE; t <= e_LAST_CONTENT_TYPE; t++)
        {
            if (!strcmp(type, m_content_type_types[t]))
                return m_content_types[t];
        }
        return 0;
    }
};


#endif
