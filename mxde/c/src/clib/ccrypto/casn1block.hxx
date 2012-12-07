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
 *   File: casn1block.hxx
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
#if !defined(_CASN1BLOCK_HXX) || defined(CASN1BLOCK_MEMBERS_ONLY)
#if !defined(_CASN1BLOCK_HXX) && !defined(CASN1BLOCK_MEMBERS_ONLY)
#define _CASN1BLOCK_HXX
#endif /* !defined(_CASN1BLOCK_HXX) && !defined(CASN1BLOCK_MEMBERS_ONLY) */

#if !defined(CASN1BLOCK_MEMBERS_ONLY)
#include "casn1type.hxx"
#include "casn1length.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1Block
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Block
: public cASN1Base
{
public:
    typedef cASN1Base cExtends;

    cASN1Type m_type;
    cASN1Length m_length;

    /**
     **********************************************************************
     *  Constructor: cASN1Block
     *
     *       Author: $author$
     *         Date: 3/21/2010
     **********************************************************************
     */
    cASN1Block()
    {
    }
#else /* !defined(CASN1BLOCK_MEMBERS_ONLY) */
#endif /* !defined(CASN1BLOCK_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader)
#if defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        TLENGTH count2;

        if (0 <= (count = m_type.Read(reader)))
        if (0 <= (count2 = m_length.Read(reader)))
            count += count2;
        else
        count = count2;
#else /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Form
     *
     *   Author: $author$
     *     Date: 3/21/2010
     **********************************************************************
     */
    virtual eASN1Form Form() const 
#if defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Form value = e_ASN1_FORM_Undefined;
#if !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_type.Form());
#else /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Class
     *
     *   Author: $author$
     *     Date: 3/21/2010
     **********************************************************************
     */
    virtual eASN1Class Class() const 
#if defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Class value = e_ASN1_CLASS_Undefined;
#if !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_type.Class());
#else /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Type
     *
     *   Author: $author$
     *     Date: 3/21/2010
     **********************************************************************
     */
    virtual eASN1Type Type() const 
#if defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    {
        eASN1Type value = e_ASN1_TYPE_Undefined;
#if !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT)
        value = (m_type.Value());
#else /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 3/21/2010
     **********************************************************************
     */
    virtual TSIZE Length() const 
#if defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE)
    ;
#else /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    {
        TSIZE value = 0;
#if !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT)
        value = (m_length.Value());
#else /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Size
     *
     *    Author: $author$
     *      Date: 3/31/2010
     **********************************************************************
     */
    virtual TSIZE Size() const
#if defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */
    {
        TSIZE size = 0;
#if !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT)
        size = (m_length.Value()+m_length.Size()+m_type.Size());
#else /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1BLOCK_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CASN1BLOCK_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1BLOCK_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1BLOCK_MEMBERS_ONLY) */
#endif /* !defined(CASN1BLOCK_MEMBERS_ONLY) */

#endif /* !defined(_CASN1BLOCK_HXX) || defined(CASN1BLOCK_MEMBERS_ONLY) */
