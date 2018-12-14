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
 *   File: cproperty.hxx
 *
 * Author: $author$
 *   Date: 4/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPROPERTY_HXX
#define _CPROPERTY_HXX

#include "clistt.hxx"
#include "ccharbuffer.hxx"

class cProperty;

/**
 **********************************************************************
 *  Class: cPropertyList
 *
 * Author: $author$
 *   Date: 4/12/2004
 **********************************************************************
 */
class cPropertyList
: public cListT<cProperty, cPropertyList>
{
public:
    typedef cListT<cProperty, cPropertyList> cIs;
};

/**
 **********************************************************************
 *  Class: cProperty
 *
 * Author: $author$
 *   Date: 4/12/2004
 **********************************************************************
 */
class cProperty
: public cListItemT<cProperty>
{
public:
    typedef cListItemT<cProperty> cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 4/15/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST_TYPE,
        e_TYPE_TEXT=e_FIRST_TYPE,
        e_TYPE_INT,
        e_TYPE_BOOL,
        e_TYPE_ENUM,
        e_NEXT_TYPE,
        e_LAST_TYPE=e_NEXT_TYPE-1
    };

    cCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cProperty
     *
     *      Author: $author$
     *        Date: 4/12/2004
     **********************************************************************
     */
    cProperty(const char *name=0, int length=-1) 
    {
        eError error;

        if (name)
        if (0 > (length = SetName(name, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cProperty
     *
     *      Author: $author$
     *        Date: 4/12/2004
     **********************************************************************
     */
    cProperty(cPropertyList &list,const char *name=0, int length=-1) 
    {
        eError error;

        if (name)
        if (0 > (length = SetName(name, length)))
            throw(error = -length);

        list.Add(this);
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual int SetName(const char *buffer, int length=-1)
    {
        length = m_name.Copy(buffer, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual const char *GetName(int &length) const
    {
        const char *buffer;

        buffer = m_name.GetBuffer(length);
        return buffer;
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual int SetValue(const char *buffer, int length=-1)
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual const char *GetValue(int &length) const
    {
        const char *buffer=0;

        length = -e_ERROR_NOT_IMPLEMENTED;
        return buffer;
    }

    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 4/15/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        int type = e_TYPE_TEXT;
        return type;
    }
};

/**
 **********************************************************************
 *  Class: cIntProperty
 *
 * Author: $author$
 *   Date: 4/12/2004
 **********************************************************************
 */
class cIntProperty
: public cProperty
{
public:
    typedef cProperty cIs;

    int &m_value;
    mutable cCharBuffer m_value_buffer;

    /**
     **********************************************************************
     * Constructor: cIntProperty
     *
     *      Author: $author$
     *        Date: 4/12/2004
     **********************************************************************
     */
    cIntProperty
    (int &value, const char *name=0, int length=-1) 
    : cIs(name, length),
      m_value(value)
    {
    }
    /**
     **********************************************************************
     * Constructor: cIntProperty
     *
     *      Author: $author$
     *        Date: 4/12/2004
     **********************************************************************
     */
    cIntProperty
    (cPropertyList &list, int &value, const char *name=0, int length=-1) 
    : cIs(list, name, length),
      m_value(value)
    {
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual int SetValue(const char *buffer, int length=-1)
    {
        if (0 < (length = m_value_buffer.Copy(buffer, length)))
        if ((buffer = m_value_buffer.GetBuffer()))
            m_value = atoi(buffer);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual const char *GetValue(int &length) const
    {
        const char *buffer=0;

        if (0 < (length = m_value_buffer.CopyInt(m_value)))
            buffer = m_value_buffer.GetBuffer(length);
        return buffer;
    }
};

/**
 **********************************************************************
 *  Class: cBoolProperty
 *
 * Author: $author$
 *   Date: 4/15/2004
 **********************************************************************
 */
class cBoolProperty
: public cProperty
{
public:
    typedef cProperty cIs;

    bool &m_value;
    mutable cCharBuffer m_value_buffer;

    /**
     **********************************************************************
     * Constructor: cBoolProperty
     *
     *      Author: $author$
     *        Date: 4/15/2004
     **********************************************************************
     */
    cBoolProperty
    (bool &value, const char *name=0, int length=-1) 
    : cIs(name, length),
      m_value(value) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cBoolProperty
     *
     *      Author: $author$
     *        Date: 4/15/2004
     **********************************************************************
     */
    cBoolProperty
    (cPropertyList &list, bool &value, const char *name=0, int length=-1) 
    : cIs(list, name, length),
      m_value(value) 
    {
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 4/15/2004
     **********************************************************************
     */
    virtual int SetValue(const char *buffer, int length=-1)
    {
        if (0 < (length = m_value_buffer.Copy(buffer, length)))
        if ((buffer = m_value_buffer.GetBuffer()))
            m_value = !strcmp("yes", buffer);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 4/15/2004
     **********************************************************************
     */
    virtual const char *GetValue(int &length) const
    {
        const char *buffer=m_value?"yes":"no";

        if (0 < (length = m_value_buffer.Copy(buffer)))
            buffer = m_value_buffer.GetBuffer(length);
        return buffer;
    }
};

#endif /* ndef _CPROPERTY_HXX */
