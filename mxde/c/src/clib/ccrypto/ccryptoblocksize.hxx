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
 *   File: ccryptoblocksize.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOBLOCKSIZE_HXX) || defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY)
#if !defined(_CCRYPTOBLOCKSIZE_HXX) && !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY)
#define _CCRYPTOBLOCKSIZE_HXX
#endif /* !defined(_CCRYPTOBLOCKSIZE_HXX) && !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY) */

#if !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY)
#include "ccryptobase.hxx"
#include "ccryptoblocksizeinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoBlockSizeExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cCryptoBase
cCryptoBlockSizeExtend;
/**
 **********************************************************************
 *  Class: cCryptoBlockSize
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cCryptoBlockSize
: virtual public cCryptoBlockSizeImplement,
  public cCryptoBlockSizeExtend
{
public:
    typedef cCryptoBlockSizeImplement cImplements;
    typedef cCryptoBlockSizeExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cCryptoBlockSize
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cCryptoBlockSize()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCryptoBlockSize
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cCryptoBlockSize()
    {
    }
#else /* !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetCryptoBlockSize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH SetCryptoBlockSize
    (TLENGTH toValue = UNDEFINED_LENGTH)
#if defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = -e_ERROR_NOT_ALLOWED;
#if !defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CryptoBlockSize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH CryptoBlockSize() const
#if defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH value = 1;
#if !defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CCRYPTOBLOCKSIZE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOBLOCKSIZE_HXX) || defined(CCRYPTOBLOCKSIZE_MEMBERS_ONLY) */
