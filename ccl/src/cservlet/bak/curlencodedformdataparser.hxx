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
 *   File: curlencodedformdataparser.hxx
 *
 * Author: $author$
 *   Date: 11/18/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURLENCODEDFORMDATAPARSER_HXX
#define _CURLENCODEDFORMDATAPARSER_HXX

#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cURLEncodedFormDataParser
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cURLEncodedFormDataParser
{
public:
    typedef int (cURLEncodedFormDataParser::*mPutc)(int c);

    mPutc m_old_putc, m_putc;
    cCharBuffer *m_hex_buffer, m_name_buffer, m_value_buffer;
    const char *m_name, *m_value;
    int m_namelen, m_valuelen;
    int m_x;

    /**
     **********************************************************************
     * Constructor: cURLEncodedFormDataParser
     *
     *      Author: $author$
     *        Date: 11/18/2004
     **********************************************************************
     */
    cURLEncodedFormDataParser() 
    : m_old_putc(NamePutc),
      m_putc(NamePutc)
    {
        m_hex_buffer = &m_name_buffer;
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/19/2004
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        int length;

        m_old_putc = NamePutc;
        m_putc = NamePutc;
        m_hex_buffer = &m_name_buffer;

        if (0 > (length = m_name_buffer.Clear()))
            error = -length;

        if (0 > (length = m_value_buffer.Clear()))
        if (!error)
            error = -length;

        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/19/2004
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        int c = -e_ERROR_ENDOF;

        c = (this->*m_putc)(c);
        return error;
    }
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual int Putc(int c) 
    {
        c = (this->*m_putc)(c);
        return c;
    }
    /**
     **********************************************************************
     * Function: NamePutc
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    int NamePutc(int c) 
    {
        eError error;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '&':
            if (!(m_name = m_name_buffer.GetBuffer(m_namelen)))
                c = -e_ERROR_FAILED;
            else if ((error = OnFormField(m_name, m_namelen)))
                    c = -error;
            else if (0 > (m_namelen = m_name_buffer.Clear()))
                    c = m_namelen;

            m_namelen = 0;
            break;

        case '=':
            if (!(m_name = m_name_buffer.GetBuffer(m_namelen)))
                c = -e_ERROR_FAILED;
            else m_putc = ValuePutc;
            break;

        case '%':
            m_old_putc = m_putc;
            m_putc = Hex1Putc;
            m_hex_buffer = &m_name_buffer;
            break;

        case '+':
            c = m_name_buffer.Putc(' ');
            break;

        default:
            c = m_name_buffer.Putc(c);
        }
        return c;
    }
    /**
     **********************************************************************
     * Function: ValuePutc
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    int ValuePutc(int c) 
    {
        eError error;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '&':
            if (!(m_value = m_value_buffer.GetBuffer(m_valuelen)))
                c = -e_ERROR_FAILED;
            else if ((error = OnFormField
                     (m_name, m_namelen, m_value, m_valuelen)))
                    c = -error;
            else if (0 > (m_namelen = m_name_buffer.Clear()))
                    c = m_namelen;
            else if (0 > (m_valuelen = m_value_buffer.Clear()))
                    c = m_valuelen;

            m_namelen = 0;
            m_valuelen = 0;
            m_putc = NamePutc;
            break;

        case '%':
            m_old_putc = m_putc;
            m_putc = Hex1Putc;
            m_hex_buffer = &m_value_buffer;
            break;

        case '+':
            c = m_value_buffer.Putc(' ');
            break;

        default:
            c = m_value_buffer.Putc(c);
        }
        return c;
    }
    /**
     **********************************************************************
     * Function: Hex1Putc
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    int Hex1Putc(int c) 
    {
        if ((c >= '0') && (c <= '9'))
            m_x = c - '0';

        else if ((c >= 'a') && (c <= 'f'))
                m_x = c - 'a' + 10;

        else if ((c >= 'A') && (c <= 'F'))
                m_x = c - 'A' + 10;

        else m_x = 1;

        m_putc = Hex2Putc;
        return c;
    }
    /**
     **********************************************************************
     * Function: Hex2Putc
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    int Hex2Putc(int c) 
    {
        int x = 0;

        if ((c >= '0') && (c <= '9'))
            x = c - '0';

        else if ((c >= 'a') && (c <= 'f'))
                x = c - 'a' + 10;

        else if ((c >= 'A') && (c <= 'F'))
                x = c - 'A' + 10;

        c = m_hex_buffer->Putc((m_x << 4) | x);
        m_putc = m_old_putc;
        return c;
    }
    /**
     **********************************************************************
     * Function: OnFormField
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual eError OnFormField
    (const char *name, int namelen=-1, 
     const char *value="", int valuelen=-1) 
    {
        eError result = e_ERROR_NONE;
        return result;
    }
};

#endif /* ndef _CURLENCODEDFORMDATAPARSER_HXX */
