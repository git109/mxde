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
 *   File: chttpheaderparser.hxx
 *
 * Author: $author$
 *   Date: 11/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPHEADERPARSER_HXX
#define _CHTTPHEADERPARSER_HXX

#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cHTTPHeaderParser
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHTTPHeaderParser
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 11/4/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST_STATE,

        e_STATE_LINE,
        e_STATE_NAME,
        e_STATE_VALUE,
        e_STATE_CONTENT,

        e_NEXT_STATE,
        e_LAST_STATE=e_NEXT_STATE-1
    } m_state;

    bool m_new_line;

    cCharBuffer 
        *m_buffer, m_header_buffer, m_line_buffer, 
        m_name_buffer, m_value_buffer;

    /**
     **********************************************************************
     * Constructor: cHTTPHeaderParser
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cHTTPHeaderParser() 
    : m_state(e_STATE_LINE),
      m_new_line(false),
      m_buffer(&m_line_buffer)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;
        int length;

        m_state = e_STATE_LINE;
        m_buffer = &m_line_buffer;
        
        if (0 <= (length = m_header_buffer.Clear()))
        if (0 <= (length = m_line_buffer.Clear()))
        if (0 <= (length = m_name_buffer.Clear()))
        if (0 <= (length = m_value_buffer.Clear()))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int Putc(int c) 
    {
        if (e_STATE_CONTENT == m_state)
            return c;

        if (0 > (c = m_header_buffer.Putc(c)))
            return c;

        switch(c)
        {
        case ':':
            if (e_STATE_NAME == m_state)
            {
                m_state = e_STATE_VALUE;
                m_buffer = &m_value_buffer;
                m_value_buffer.Clear();
            }
            else if (0 > (c = m_buffer->Putc(c)))
                    return c;
            break;

        case '\r':
            break;

        case '\n':
            if (m_new_line)
            {
                m_new_line = false;
                m_state = e_STATE_CONTENT;
                c = PutEndc(c);
            }
            else
            {
                m_new_line = true;

                switch(m_state)
                {
                case e_STATE_LINE:
                    c = PutLineEndc(c);
                    break;

                case e_STATE_VALUE:
                    c = PutFieldEndc(c);
                    m_value_buffer.Clear();
                }
                m_state = e_STATE_NAME;
                m_buffer = &m_name_buffer;
                m_name_buffer.Clear();
            }
            break;

        default:
            m_new_line = false;

            if (0 > (c = m_buffer->Putc(c)))
                return c;
        }
        return c;
    }
    /**
     **********************************************************************
     * Function: PutFieldEndc
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int PutFieldEndc(int c) 
    {
        const char *chars,*vchars;
        int length,vlength;
        char vc;
        eError error;

        if ((chars = m_name_buffer.GetBuffer(length)))
        if ((vchars = m_value_buffer.GetBuffer(vlength)))
        {
            for (; (vc = *vchars); vchars++)
                if (' ' != vc)
                    break;

            if ((error = OnField(chars, length, vchars, vlength)))
                c = -error;
        }
        return c;
    }
    /**
     **********************************************************************
     * Function: PutLineEndc
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int PutLineEndc(int c) 
    {
        const char *chars;
        int length;
        eError error;

        if ((chars = m_line_buffer.GetBuffer(length)))
        if ((error = OnLine(chars, length)))
            c = -error;

        return c;
    }
    /**
     **********************************************************************
     * Function: PutEndc
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int PutEndc(int c) 
    {
        const char *chars;
        int length;
        eError error;

        if ((chars = m_header_buffer.GetBuffer(length)))
        if ((error = OnEnd(chars, length)))
            c = -error;

        return c;
    }

    /**
     **********************************************************************
     * Function: OnLine
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError OnLine
    (const char* chars,  int length=-1) 
    {
        eError error = -e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnField
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError OnField
    (const char* name,  int namelen=-1,
     const char* value=0,  int valuelen=-1) 
    {
        eError error = -e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError OnEnd
    (const char* chars,  int length=-1) 
    {
        eError error = -e_ERROR_NONE;
        return error;
    }
};

#endif /* ndef _CHTTPHEADERPARSER_HXX */
