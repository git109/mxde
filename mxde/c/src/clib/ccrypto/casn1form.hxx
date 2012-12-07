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
 *   File: casn1form.hxx
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
#if !defined(_CASN1FORM_HXX) || defined(CASN1FORM_MEMBERS_ONLY)
#if !defined(_CASN1FORM_HXX) && !defined(CASN1FORM_MEMBERS_ONLY)
#define _CASN1FORM_HXX
#endif /* !defined(_CASN1FORM_HXX) && !defined(CASN1FORM_MEMBERS_ONLY) */

#if !defined(CASN1FORM_MEMBERS_ONLY)
#include "casn1base.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1Form
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Form
: public cASN1Base
{
public:
    typedef cASN1Base cExtends;

    eASN1Form m_value;
    const CHAR* m_name;

    /**
     **********************************************************************
     *  Constructor: cASN1Form
     *
     *       Author: $author$
     *         Date: 3/19/2010
     **********************************************************************
     */
    cASN1Form
    (eASN1Form value = e_ASN1_FORM_Primative)
    : m_value(value)
    {
        m_name = GetNameOf(m_value);
    }
#else /* !defined(CASN1FORM_MEMBERS_ONLY) */
#endif /* !defined(CASN1FORM_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Form SetValue
    (eASN1Form toValue) 
#if defined(CASN1FORM_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Form value = e_ASN1_FORM_Undefined;
#if !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) 
        m_name = GetNameOf(value = (m_value = toValue));
#else /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Value
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Form Value() const 
#if defined(CASN1FORM_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Form value = e_ASN1_FORM_Undefined;
#if !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_value);
#else /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Name
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual const CHAR* Name() const
#if defined(CASN1FORM_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */
    {
        const CHAR* name = 0;
#if !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) 
        name = (m_name);
#else /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetNameOf
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual const CHAR* GetNameOf
    (eASN1Form ofValue) const
#if defined(CASN1FORM_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */
    {
        const CHAR* name = "undefined";
#if !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) 
        switch(ofValue)
        {
        case e_ASN1_FORM_Primative:
            return "Primative";

        case e_ASN1_FORM_Construct:
            return "Construct";
        }
#else /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1FORM_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CASN1FORM_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1FORM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1FORM_MEMBERS_ONLY) */
#endif /* !defined(CASN1FORM_MEMBERS_ONLY) */

#endif /* !defined(_CASN1FORM_HXX) || defined(CASN1FORM_MEMBERS_ONLY) */
