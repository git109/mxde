/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: chttpheaderfieldlistserializer.hxx
 *
 * Author: $author$
 *   Date: 2/14/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPHEADERFIELDLISTSERIALIZER_HXX
#define _CHTTPHEADERFIELDLISTSERIALIZER_HXX

#include "chttpheaderfield.hxx"
#include "chttpnameserializer.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldListSerializer
 *
 * Author: $author$
 *   Date: 2/14/2006
 **********************************************************************
 */
class cHttpHeaderFieldListSerializer
: public cHttpNameSerializer
{
public:
    typedef cHttpNameSerializer cIs;

    typedef int (cHttpHeaderFieldListSerializer::*mGetb)();

    const cHttpHeaderFieldList& m_field_list;

    mGetb m_getb;
    cHttpHeaderField* m_field;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldListSerializer
     *
     *      Author: $author$
     *        Date: 2/14/2006
     **********************************************************************
     */
    cHttpHeaderFieldListSerializer
    (const cHttpHeaderFieldList& field_list) 
    : m_field_list(field_list),
      m_getb(NameGetb)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        m_chars = "";
        m_charslen = 0;
        m_charspos = 1;

        if ((error = cIs::Initialize()))
            return error;

        if ((m_field = m_field_list.GetFirst()))
        if ((m_chars = m_field->GetName(m_charslen)))
            m_charspos = 0;

        m_getb = NameGetb;
        return error;
    }
    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    virtual int Getb() 
    {
        int result = (this->*m_getb)();
        return result;
    }
    /**
     **********************************************************************
     * Function: NameGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int NameGetb() 
    {
        int result = -e_ERROR_FAILED;

        if (m_charspos < m_charslen)
            result = cIs::Getb();

        else if ((m_chars = m_field->GetValue(m_charslen)))
        {
            result = ':';
            m_charspos = 0;
            m_getb = SpaceGetb;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: SapceGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int SpaceGetb() 
    {
        int result = ' ';
        m_getb = ValueGetb;
        return result;
    }
    /**
     **********************************************************************
     * Function: ValueGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int ValueGetb() 
    {
        int result = -e_ERROR_FAILED;

        if (m_charspos < m_charslen)
            result = cIs::Getb();

        else if ((m_field = m_field->GetNext()))
        {
            if ((m_chars = m_field->GetName(m_charslen)))
            {
                result = '\r';
                m_charspos = 0;
                m_getb = NewlineGetb;
            }
            else result = -e_ERROR_ENDOF;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: NewlineGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int NewlineGetb() 
    {
        int result = '\n';
        m_getb = NameGetb;
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldListDeserializer
 *
 * Author: $author$
 *   Date: 2/14/2006
 **********************************************************************
 */
class cHttpHeaderFieldListDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;
    typedef int (cHttpHeaderFieldListDeserializer::*mPutb)(BYTE b);

    cHttpHeaderFieldList& m_field_list;
    mPutb m_putb;
    cCharBuffer m_name, m_value;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldListDeserializer
     *
     *      Author: $author$
     *        Date: 2/14/2006
     **********************************************************************
     */
    cHttpHeaderFieldListDeserializer
    (cHttpHeaderFieldList& field_list)
    : m_field_list(field_list),
      m_putb(NamePutb)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error;
        int length;

        m_putb = NamePutb;

        if (!(error = cIs::Initialize()))
        if (!(error = m_field_list.Clear()))
        if (0 > (length = m_name.Clear()))
            error = -length;
        else if (0 > (length = m_value.Clear()))
                error = -length;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnField
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnField() 
    {
        eError error = e_ERROR_NONE;
        const char *name, *value;
        int namelen, valuelen;
        cHttpHeaderField* field;


        if ((name = m_name.GetBuffer(namelen)))
        if ((value = m_value.GetBuffer(valuelen)))
        {
            if ((field = m_field_list.AddField
                (name, namelen, value, valuelen)))
            {
            }
            if (0 > (namelen = m_name.Clear()))
                error = -namelen;

            if (0 > (valuelen = m_value.Clear()))
            if (!error)
                error = -valuelen;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Putb(BYTE b) 
    {
        int result = (this->*m_putb)(b);
        return result;
    }
    /**
     **********************************************************************
     * Function: NamePutb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    int NamePutb(BYTE b) 
    {
        int result = b;
        int count;

        switch(b)
        {
        case '\r':
            break;

        case '\n':
            m_done = true;
            break;

        case ':':
            if (0 > (count = m_value.Clear()))
                result = count;
            m_putb = SpacePutb;
            break;

        default:
            result = m_name.Putc(b);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: ValuePutb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    int ValuePutb(BYTE b) 
    {
        int result = b;
        eError error;

        switch(b)
        {
        case '\r':
            break;

        case '\n':
            if ((error = OnField()))
                result = -error;
            m_putb = NamePutb;
            break;

        default:
            result = m_value.Putc(b);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: SpacePutb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    int SpacePutb(BYTE b) 
    {
        int result = b;
        int count;

        switch(b)
        {
        case ' ':
        case '\t':
        case '\r':
            break;

        case '\n':
            if (0 > (count = m_name.Clear()))
                result = count;
            m_putb = NamePutb;
            break;

        default:
            m_putb = ValuePutb;
            result = m_value.Putc(b);
        }
        return result;
    }
};

#endif /* _CHTTPHEADERFIELDLISTSERIALIZER_HXX */


