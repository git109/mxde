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
 *   File: casn1class.hxx
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
#if !defined(_CASN1CLASS_HXX) || defined(CASN1CLASS_MEMBERS_ONLY)
#if !defined(_CASN1CLASS_HXX) && !defined(CASN1CLASS_MEMBERS_ONLY)
#define _CASN1CLASS_HXX
#endif /* !defined(_CASN1CLASS_HXX) && !defined(CASN1CLASS_MEMBERS_ONLY) */

#if !defined(CASN1CLASS_MEMBERS_ONLY)
#include "casn1base.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1Class
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Class
: public cASN1Base
{
public:
    typedef cASN1Base cExtends;

    eASN1Class m_value;
    const CHAR* m_name;

    /**
     **********************************************************************
     *  Constructor: cASN1Class
     *
     *       Author: $author$
     *         Date: 3/19/2010
     **********************************************************************
     */
    cASN1Class
    (eASN1Class value = e_ASN1_CLASS_Universal)
    : m_value(value)
    {
        m_name = GetNameOf(m_value);
    }
#else /* !defined(CASN1CLASS_MEMBERS_ONLY) */
#endif /* !defined(CASN1CLASS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Class SetValue
    (eASN1Class toValue) 
#if defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Class value = e_ASN1_CLASS_Undefined;
#if !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT)
        m_name = GetNameOf(value = (m_value = toValue));
#else /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Value
     *
     *   Author: $author$
     *     Date: 3/20/2010
     **********************************************************************
     */
    virtual eASN1Class Value() const 
#if defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Class value = e_ASN1_CLASS_Undefined;
#if !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_value);
#else /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Name
     *
     *   Author: $author$
     *     Date: 3/19/2010
     **********************************************************************
     */
    virtual const CHAR* Name() const 
#if defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */
    {
        const CHAR* name = 0;
#if !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) 
        name = (m_name);
#else /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetNameOf
     *
     *   Author: $author$
     *     Date: 3/19/2010
     **********************************************************************
     */
    virtual const CHAR* GetNameOf
    (eASN1Class ofValue) const 
#if defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */
    {
        const CHAR* name = "undefined";
#if !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) 
        switch(ofValue)
        {
        case e_ASN1_CLASS_Universal:
            return "Universal";

        case e_ASN1_CLASS_Application:
            return "Application";

        case e_ASN1_CLASS_Context:
            return "Context";

        case e_ASN1_CLASS_Private:
            return "Private";
        }
#else /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1CLASS_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CASN1CLASS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1CLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1CLASS_MEMBERS_ONLY) */
#endif /* !defined(CASN1CLASS_MEMBERS_ONLY) */

#endif /* !defined(_CASN1CLASS_HXX) || defined(CASN1CLASS_MEMBERS_ONLY) */
