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
 *   File: ccryptokey.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOKEY_HXX) || defined(CCRYPTOKEY_MEMBERS_ONLY)
#if !defined(_CCRYPTOKEY_HXX) && !defined(CCRYPTOKEY_MEMBERS_ONLY)
#define _CCRYPTOKEY_HXX
#endif /* !defined(_CCRYPTOKEY_HXX) && !defined(CCRYPTOKEY_MEMBERS_ONLY) */

#if !defined(CCRYPTOKEY_MEMBERS_ONLY)
#include "ccryptobase.hxx"
#include "ccryptokeyinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoKeyExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cCryptoBase
cCryptoKeyExtend;
/**
 **********************************************************************
 *  Class: cCryptoKey
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cCryptoKey
: virtual public cCryptoKeyImplement,
  public cCryptoKeyExtend
{
public:
    typedef cCryptoKeyImplement cImplements;
    typedef cCryptoKeyExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cCryptoKey
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cCryptoKey()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCryptoKey
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cCryptoKey()
    {
    }
#else /* !defined(CCRYPTOKEY_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOKEY_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetCryptoKeyMin
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetCryptoKeyMin
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetCryptoKeyMax
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetCryptoKeyMax
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetCryptoKeySize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetCryptoKeySize
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CryptoKeyMin
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoKeyMin() const
#if defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CryptoKeyMax
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoKeyMax() const
#if defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CryptoKeySize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoKeySize() const
#if defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOKEY_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOKEY_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCRYPTOKEY_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOKEY_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOKEY_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOKEY_HXX) || defined(CCRYPTOKEY_MEMBERS_ONLY) */
