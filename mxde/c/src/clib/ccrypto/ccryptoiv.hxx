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
 *   File: ccryptoiv.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOIV_HXX) || defined(CCRYPTOIV_MEMBERS_ONLY)
#if !defined(_CCRYPTOIV_HXX) && !defined(CCRYPTOIV_MEMBERS_ONLY)
#define _CCRYPTOIV_HXX
#endif /* !defined(_CCRYPTOIV_HXX) && !defined(CCRYPTOIV_MEMBERS_ONLY) */

#if !defined(CCRYPTOIV_MEMBERS_ONLY)
#include "ccryptobase.hxx"
#include "ccryptoivinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoIVExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cCryptoBase
cCryptoIVExtend;
/**
 **********************************************************************
 *  Class: cCryptoIV
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cCryptoIV
: virtual public cCryptoIVImplement,
  public cCryptoIVExtend
{
public:
    typedef cCryptoIVImplement cImplements;
    typedef cCryptoIVExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cCryptoIV
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cCryptoIV()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCryptoIV
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cCryptoIV()
    {
    }
#else /* !defined(CCRYPTOIV_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOIV_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetICryptoIVMin
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetICryptoIVMin
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetCryptoIVMax
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetCryptoIVMax
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetCryptoIVSize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetCryptoIVSize
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CryptoIVMin
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoIVMin() const
#if defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CryptoIVMax
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoIVMax() const
#if defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CryptoIVSize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoIVSize() const
#if defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOIV_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOIV_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCRYPTOIV_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOIV_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOIV_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOIV_HXX) || defined(CCRYPTOIV_MEMBERS_ONLY) */
