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
 *   File: chttpheaderfield.hxx
 *
 * Author: $author$
 *   Date: 2/13/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPHEADERFIELD_HXX
#define _CHTTPHEADERFIELD_HXX

#include "chttpheadertransferencodingfieldtype.hxx"
#include "chttpheaderfieldtype.hxx"
#include "ccharbuffer.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderField
 *
 * Author: $author$
 *   Date: 2/13/2006
 **********************************************************************
 */
class cHttpHeaderField
: public cDynamicListItemT<cHttpHeaderField>
{
public:
    typedef cDynamicListItemT<cHttpHeaderField> cIs;

    cCharBuffer m_name, m_value;
    cHttpHeaderFieldType m_type;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderField
     *
     *      Author: $author$
     *        Date: 2/13/2006
     **********************************************************************
     */
    cHttpHeaderField
    (const char *name=0, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error;

        if ((error = Set(name, namelen, value, valuelen)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual eError Set
    (const char *name=0, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        if (name)
        {
            if (0 > (namelen = m_name.Copy(name, namelen)))
                return error = -namelen;

            if ((name = m_name.GetBuffer(namelen)))
                m_type.SetValue(name);

            else m_type.SetValue
                 (cHttpHeaderFieldType::e_NONE);
        }

        if (value)
        if (0 > (valuelen = m_value.Copy(value, valuelen)))
            error = -valuelen;

        return error;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetName(int &length) const
    {
        const char* chars = m_name.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetValue(int &length) const
    {
        const char* chars = m_value.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetValueType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetValueType() const
    {
        int type, value_type = 0;

        switch(type = m_type.GetValue())
        {
        case cHttpHeaderFieldType::e_FIELD_CONNECTION:
        case cHttpHeaderFieldType::e_FIELD_CONTENT_TYPE:
        case cHttpHeaderFieldType::e_FIELD_CONTENT_LENGTH:
        case cHttpHeaderFieldType::e_FIELD_FROM:
        case cHttpHeaderFieldType::e_FIELD_HOST:
        case cHttpHeaderFieldType::e_FIELD_ACCEPT:
        case cHttpHeaderFieldType::e_FIELD_TRANSFER_ENCODING:
        case cHttpHeaderFieldType::e_FIELD_QUERY_STRING:
            break;
        }
        return value_type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        int type = m_type.GetValue();
        return type;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldListEvent
 *
 * Author: $author$
 *   Date: 2/14/2006
 **********************************************************************
 */
class cHttpHeaderFieldListEvent
{
public:
    /**
     **********************************************************************
     * Function: OnAddField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        int type = field.GetType();

        switch(type)
        {
        case cHttpHeaderFieldType::e_FIELD_CONNECTION:
            error = OnAddConnectionField(field);
            break;

        case cHttpHeaderFieldType::e_FIELD_CONTENT_TYPE:
            error = OnAddContentTypeField(field);
            break;

        case cHttpHeaderFieldType::e_FIELD_CONTENT_LENGTH:
            error = OnAddContentLengthField(field);
            break;

        case cHttpHeaderFieldType::e_FIELD_TRANSFER_ENCODING:
            error = OnAddTransferEncodingField(field);
            break;

        case cHttpHeaderFieldType::e_FIELD_HOST:
            error = OnAddHostField(field);
            break;

        case cHttpHeaderFieldType::e_FIELD_QUERY_STRING:
            error = OnAddQueryStringField(field);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddConnectionField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddConnectionField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddContentTypeField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddContentTypeField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddContentLengthField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddContentLengthField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddTransferEncodingField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddTransferEncodingField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        cHttpHeaderTransferEncodingFieldType field_type;
        const char *value;
        int valuelen;
        int type;

        if ((value = field.GetValue(valuelen)))
        switch((type = field_type.SetValueByNamed(value)))
        {
        case cHttpHeaderTransferEncodingFieldType
             ::e_TRANSFER_ENCODING_CHUNKED:
            error = OnAddChunkedTransferEncodingField(field);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddChunkedTransferEncodingField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddChunkedTransferEncodingField
    (cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddHostField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddHostField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddQueryStringField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddQueryStringField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldListEventProxy
 *
 * Author: $author$
 *   Date: 2/26/2006
 **********************************************************************
 */
class cHttpHeaderFieldListEventProxy
: public cHttpHeaderFieldListEvent
{
public:
    typedef cHttpHeaderFieldListEvent cIs;

    cHttpHeaderFieldListEvent& m_event;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldListEventProxy
     *
     *      Author: $author$
     *        Date: 2/26/2006
     **********************************************************************
     */
    cHttpHeaderFieldListEventProxy
    (cHttpHeaderFieldListEvent& event) 
    : m_event(event)
    {
    }
    /**
     **********************************************************************
     * Function: OnAddField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddField(cHttpHeaderField& field) 
    {
        eError error = m_event.OnAddField(field);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddConnectionField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddConnectionField(cHttpHeaderField& field) 
    {
        eError error = m_event.OnAddConnectionField(field);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddContentTypeField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddContentTypeField(cHttpHeaderField& field) 
    {
        eError error = m_event.OnAddContentTypeField(field);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddContentLengthField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddContentLengthField(cHttpHeaderField& field) 
    {
        eError error = m_event.OnAddContentLengthField(field);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddTransferEncodingField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddTransferEncodingField(cHttpHeaderField& field) 
    {
        eError error = m_event.OnAddTransferEncodingField(field);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddChunkedTransferEncodingField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddChunkedTransferEncodingField
    (cHttpHeaderField& field) 
    {
        eError error = m_event.OnAddChunkedTransferEncodingField(field);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldList
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cHttpHeaderFieldList
: public cDynamicListT
  <cHttpHeaderField, cHttpHeaderFieldList>
{
public:
    typedef cDynamicListT
    <cHttpHeaderField, cHttpHeaderFieldList> cIs;

    cHttpHeaderFieldListEvent& m_event;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldList
     *
     *      Author: $author$
     *        Date: 2/14/2006
     **********************************************************************
     */
    cHttpHeaderFieldList
    (cHttpHeaderFieldListEvent& event) 
    : m_event(event)
    {
    }
    /**
     **********************************************************************
     * Function: AddField
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual cHttpHeaderField* AddField
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1)
    {
        cHttpHeaderField* field;

        if ((field = new cHttpHeaderField
            (name, namelen, value, valuelen)))
        {
            m_event.OnAddField(*field);
            Add(field);
        }
        return field;
    }
};

#endif /* _CHTTPHEADERFIELD_HXX */
