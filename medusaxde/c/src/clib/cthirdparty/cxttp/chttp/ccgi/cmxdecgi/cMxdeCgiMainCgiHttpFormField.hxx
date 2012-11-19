/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cMxdeCgiMainCgiHttpFormField.hxx
 *
 * Author: $author$
 *   Date: 10/2/2011
 **********************************************************************
 */
#if !defined(_CMXDECGIMAINCGIHTTPFORMFIELD_HXX) || defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY)
#if !defined(_CMXDECGIMAINCGIHTTPFORMFIELD_HXX) && !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY)
#define _CMXDECGIMAINCGIHTTPFORMFIELD_HXX
#endif /* !defined(_CMXDECGIMAINCGIHTTPFORMFIELD_HXX) && !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY)
#include "cMxdeCgiMainHttpFormField.hxx"
#include "cHttpFormFieldInterface.hpp"
#include "cHttpFormFieldItem.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiHttpFormFieldImplement
 *
 *  Author: $author$
 *    Date: 10/2/2011
 **********************************************************************
 */
typedef cHttpFormFieldImplement
cMxdeCgiMainCgiHttpFormFieldImplement;
/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiHttpFormFieldExtend
 *
 *  Author: $author$
 *    Date: 10/2/2011
 **********************************************************************
 */
typedef cInstanceBase
cMxdeCgiMainCgiHttpFormFieldExtend;
/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgiHttpFormField
 *
 * Author: $author$
 *   Date: 10/2/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cMxdeCgiMainCgiHttpFormField
: virtual public cMxdeCgiMainCgiHttpFormFieldImplement,
  public cMxdeCgiMainCgiHttpFormFieldExtend
{
public:
    typedef cMxdeCgiMainCgiHttpFormFieldImplement cImplements;
    typedef cMxdeCgiMainCgiHttpFormFieldExtend cExtends;

    cHttpFormFieldItem m_item;
    cMxdeCgiMainHttpFormField* m_formField;
    mutable const char* m_nameChars;
    mutable const char* m_valueChars;
    mutable cString m_name;
    mutable cString m_value;

    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMainCgiHttpFormField
     *
     *       Author: $author$
     *         Date: 10/2/2011
     **********************************************************************
     */
    cMxdeCgiMainCgiHttpFormField
    (cMxdeCgiMainHttpFormField* formField=0)
    : m_item(*this),
      m_formField(formField),
      m_nameChars(0),
      m_valueChars(0)
    {
    }
#else /* !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: Attach
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* Attach
    (cMxdeCgiMainHttpFormField* formField)
    {
        m_formField = formField;
        m_nameChars = 0;
        m_valueChars = 0;
        return m_formField;
    }

    /**
     **********************************************************************
     *  Function: SetName
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual cString& SetName
    (const cString& toName)
    {
        const char* chars;
        ssize_t length;
        if ((chars = toName.Chars(length)))
            SetName(chars, length);
        return (cString&)(m_name);
    }
    /**
     **********************************************************************
     *  Function: SetName
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual cString& SetName
    (const char* chars, ssize_t length=-1)
    {
        if ((chars) && (m_formField))
        if (0 <= (m_formField->SetName(chars, length)))
        if (!(m_nameChars = 0))
            GetName();
        return (cString&)(m_name);
    }
    /**
     **********************************************************************
     *  Function: GetName
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual const cString& GetName() const
    {
        const char* chars;
        ssize_t length;
        if (!(m_nameChars) && (m_formField))
        if ((chars = m_formField->GetName(length)))
        if (0 <= (m_name.Assign(chars, length)))
            m_nameChars = m_name.Chars(length);
        return m_name;
    }

    /**
     **********************************************************************
     *  Function: SetValue
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual cString& SetValue
    (const cString& toValue)
    {
        const char* chars;
        ssize_t length;
        if ((chars = toValue.Chars(length)))
            SetValue(chars, length);
        return (cString&)(m_value);
    }
    /**
     **********************************************************************
     *  Function: SetValue
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual cString& SetValue
    (const char* chars, ssize_t length=-1)
    {
        if ((chars) && (m_formField))
        if (0 <= (m_formField->SetValue(chars, length)))
        if (!(m_valueChars = 0))
            GetValue();
        return (cString&)(m_value);
    }
    /**
     **********************************************************************
     *  Function: GetValue
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual const cString& GetValue() const
    {
        const char* chars;
        ssize_t length;
        if (!(m_valueChars) && (m_formField))
        if ((chars = m_formField->GetValue(length)))
        if (0 <= (m_value.Assign(chars, length)))
            m_valueChars = m_value.Chars(length);
        return m_value;
    }

    /**
     **********************************************************************
     *  Function: GetNameChars
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual const char* GetNameChars
    (ssize_t& length, bool negativeIsNullTerminated=false) const
    {
        const cString& name = GetName();
        const char* chars = 0;
        if ((chars = name.Chars(length)))
        if ((negativeIsNullTerminated))
            length = -length;
        return chars;
    }
    /**
     **********************************************************************
     *  Function: GetValueChars
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual const char* GetValueChars
    (ssize_t& length, bool negativeIsNullTerminated=false) const
    {
        const cString& value = GetValue();
        const char* chars = 0;
        if ((chars = value.Chars(length)))
        if ((negativeIsNullTerminated))
            length = -length;
        return chars;
    }

    /**
     **********************************************************************
     *  Function: SetIsFromQueryString
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual bool SetIsFromQueryString
    (bool isTrue=true)
    {
        bool is = false;
        if ((m_formField))
        is = m_formField->SetIsFromQueryString(isTrue);
        return is;
    }
    /**
     **********************************************************************
     *  Function: GetIsFromQueryString
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual bool GetIsFromQueryString() const
    {
        bool is = false;
        if ((m_formField))
        is = m_formField->GetIsFromQueryString();
        return is;
    }

    /**
     **********************************************************************
     *  Function: Item
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    virtual cHttpFormFieldItem& Item() const
    {
        return (cHttpFormFieldItem&)(m_item);
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY) */

#endif /* !defined(_CMXDECGIMAINCGIHTTPFORMFIELD_HXX) || defined(CMXDECGIMAINCGIHTTPFORMFIELD_MEMBERS_ONLY) */
        

