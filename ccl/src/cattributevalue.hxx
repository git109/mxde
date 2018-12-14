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
 *   File: cattributevalue.hxx
 *
 * Author: $author$
 *   Date: 4/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CATTRIBUTEVALUE_HXX
#define _CATTRIBUTEVALUE_HXX

#include "cdocumentinterface.hxx"

/**
 **********************************************************************
 *  Class: cAttributeValue
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cAttributeValue
{
public:
    cAttributeInterface *m_attribute;

    /**
     **********************************************************************
     * Constructor: cAttributeValue
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cAttributeValue
    (cElementInterface &element, const char *name) 
    {
        m_attribute = element.GetFirstAttributeByName(name);
    }
};

/**
 **********************************************************************
 *  Class: cBoolAttributeValue
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cBoolAttributeValue
: public cAttributeValue
{
public:
    typedef cAttributeValue cIs;

    bool m_value;

    /**
     **********************************************************************
     * Constructor: cBoolAttributeValue
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cBoolAttributeValue
    (cElementInterface &element, 
     const char *name, bool default_value=false)
    : cIs(element, name),
      m_value(default_value)
    {
        const char *text;
        int textlen;

        if (m_attribute)
        if ((text = m_attribute->GetText(textlen)))
        if (0 < textlen)
        if (!(m_value = !strcmp("true",text)))
            m_value = !strcmp("yes",text);
    }

    /**
     **********************************************************************
     * Operator: bool
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    inline operator bool() const
    {
        return m_value;
    }
};

/**
 **********************************************************************
 *  Class: cEnumAttributeValue
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cEnumAttributeValue
: public cAttributeValue
{
public:
    typedef cAttributeValue cIs;

    int m_value;

    /**
     **********************************************************************
     * Constructor: cEnumAttributeValue
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cEnumAttributeValue
    (cElementInterface &element, 
     const char *name, const char **value_name, 
     int first_value, int last_value, int default_value=0)
    : cIs(element, name),
      m_value(default_value)
    {
        const char *text;
        int textlen;

        if (m_attribute)
        if ((text = m_attribute->GetText(textlen)))
        if (0 < textlen)
        for (int value=first_value; value <= last_value; value++, value_name++)
        {
            if (!(strcmp(*value_name, text)))
            {
                m_value = value;
                break;
            }
        }
    }

    /**
     **********************************************************************
     * Operator: int
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    inline operator int() const
    {
        return m_value;
    }
};

/**
 **********************************************************************
 *  Class: cIntAttributeValue
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cIntAttributeValue
: public cAttributeValue
{
public:
    typedef cAttributeValue cIs;

    int m_value;

    /**
     **********************************************************************
     * Constructor: cIntAttributeValue
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cIntAttributeValue
    (cElementInterface &element, 
     const char *name, int default_value=0)
    : cIs(element, name),
      m_value(default_value)
    {
        const char *text;
        int textlen;

        if (m_attribute)
        if ((text = m_attribute->GetText(textlen)))
        if (0 < textlen)
            m_value = atoi(text);
    }

    /**
     **********************************************************************
     * Operator: int
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    inline operator int() const
    {
        return m_value;
    }
};

/**
 **********************************************************************
 *  Class: cCharPointerAttributeValue
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cCharPointerAttributeValue
: public cAttributeValue
{
public:
    typedef cAttributeValue cIs;

    const char *m_value;
    int m_valuelen;

    /**
     **********************************************************************
     * Constructor: cCharPointerAttributeValue
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cCharPointerAttributeValue 
    (cElementInterface &element, 
     const char *name, const char *default_value=0)
    : cIs(element, name),
      m_value(default_value)
    {
        if (m_attribute)
            m_value = m_attribute->GetText(m_valuelen);
    }

    /**
     **********************************************************************
     * Operator: const char *
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    inline operator const char *() const
    {
        return m_value;
    }
};

#endif /* ndef _CATTRIBUTEVALUE_HXX */
