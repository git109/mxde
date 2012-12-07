/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: casn1type.hxx
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
#if !defined(_CASN1TYPE_HXX) || defined(CASN1TYPE_MEMBERS_ONLY)
#if !defined(_CASN1TYPE_HXX) && !defined(CASN1TYPE_MEMBERS_ONLY)
#define _CASN1TYPE_HXX
#endif /* !defined(_CASN1TYPE_HXX) && !defined(CASN1TYPE_MEMBERS_ONLY) */

#if !defined(CASN1TYPE_MEMBERS_ONLY)
#include "casn1class.hxx"
#include "casn1form.hxx"
#include "casn1base.hxx"
#include "creader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1Type
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Type
: public cASN1Base
{
public:
    typedef cASN1Base cExtends;

    eASN1Type m_value;
    const CHAR* m_name;

    cASN1Form m_form;
    cASN1Class m_class;

    /**
     **********************************************************************
     *  Constructor: cASN1Type
     *
     *       Author: $author$
     *         Date: 3/19/2010
     **********************************************************************
     */
    cASN1Type
    (eASN1Type value = e_ASN1_TYPE_Any,
     eASN1Form formValue = e_ASN1_FORM_Primative,
     eASN1Class classValue = e_ASN1_CLASS_Universal)
    : m_value(value),
      m_form(formValue),
      m_class(classValue)
    {
        m_name = GetNameOf(m_value);
    }
    /**
     **********************************************************************
     *  Constructor: cASN1Type
     *
     *       Author: $author$
     *         Date: 3/19/2010
     **********************************************************************
     */
    cASN1Type
    (const cASN1Type& type)
    {
        Copy(type);
    }
#else /* !defined(CASN1TYPE_MEMBERS_ONLY) */
#endif /* !defined(CASN1TYPE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader) 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        BYTE byte;
        if (0 < (count = reader.Read(&byte, 1)))
        {
            m_form.SetValue(byte & e_ASN1_FORM_Mask);
            m_class.SetValue(byte & e_ASN1_CLASS_Mask);
            SetValue(byte & e_ASN1_TYPE_Mask);
        }
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Type Copy
    (const cASN1Type& type) 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Type value = e_ASN1_TYPE_Undefined;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        value = Set(type.Value(), type.Form(), type.Class());
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Type Set
    (eASN1Type toValue, 
     eASN1Form toFormValue, 
     eASN1Class toClassValue) 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Type value = e_ASN1_TYPE_Undefined;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        if (toFormValue == (m_form.SetValue(toFormValue)))
        if (toClassValue == (m_class.SetValue(toClassValue)))
            value = SetValue(toValue);
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Form
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Form Form() const 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Form value = e_ASN1_FORM_Undefined;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT)
        value = (m_form.Value());
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Class
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Class Class() const 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Class value = e_ASN1_CLASS_Undefined;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_class.Value());
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Type SetValue
    (eASN1Type toValue) 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Type value = e_ASN1_TYPE_Undefined;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        m_name = GetNameOf(value = (m_value = toValue));
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Value
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Type Value() const 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Type value = e_ASN1_TYPE_Undefined;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_value);
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Name
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual const CHAR* Name() const 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        const CHAR* name = 0;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        name = (m_name);
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Size
     *
     *   Author: $author$
     *     Date: 3/25/2010
     **********************************************************************
     */
    virtual BYTE Size() const 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        BYTE size = 1;
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetNameOf
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual const CHAR* GetNameOf
    (eASN1Type ofValue) const 
#if defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */
    {
        const CHAR* name = "undefined";
#if !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) 
        static const CHAR* name0[]
        ={
            "Any",
            "Boolean",
            "Integer",
            "BitString",
            "OctetString",
            "Null",
            "ObjectID",
            "Object",
            "External",
            "Real",
            "Enum",
         };
        static const CHAR* name1[]
        ={
            "Sequence",
            "Set",
            "NumericString",
            "PrintableString",
            "TeletexString",
            "VideotexString",
            "IA5String",
            "UTCTime",
            "GeneralizedTime",
            "GraphicString",
            "VisibleString",
            "GeneralString",
         };

        if ((ofValue >= e_ASN1_TYPE_Any) 
            && (ofValue <= e_ASN1_TYPE_Enum))
            return name0[ofValue-e_ASN1_TYPE_Any];

        if ((ofValue >= e_ASN1_TYPE_Sequence) 
            && (ofValue <= e_ASN1_TYPE_GeneralString))
            return name1[ofValue-e_ASN1_TYPE_Sequence];

#else /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1TYPE_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CASN1TYPE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1TYPE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1TYPE_MEMBERS_ONLY) */
#endif /* !defined(CASN1TYPE_MEMBERS_ONLY) */

#endif /* !defined(_CASN1TYPE_HXX) || defined(CASN1TYPE_MEMBERS_ONLY) */
