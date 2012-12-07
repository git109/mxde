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
 *   File: ccryptocipher.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOCIPHER_HXX) || defined(CCRYPTOCIPHER_MEMBERS_ONLY)
#if !defined(_CCRYPTOCIPHER_HXX) && !defined(CCRYPTOCIPHER_MEMBERS_ONLY)
#define _CCRYPTOCIPHER_HXX
#endif /* !defined(_CCRYPTOCIPHER_HXX) && !defined(CCRYPTOCIPHER_MEMBERS_ONLY) */

#if !defined(CCRYPTOCIPHER_MEMBERS_ONLY)
#include "ccryptobase.hxx"
#include "ccryptocipherinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoCipherExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cCryptoBase
cCryptoCipherExtend;
/**
 **********************************************************************
 *  Class: cCryptoCipher
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cCryptoCipher
: virtual public cCryptoCipherImplement,
  public cCryptoCipherExtend
{
public:
    typedef cCryptoCipherImplement cImplements;
    typedef cCryptoCipherExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cCryptoCipher
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cCryptoCipher()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCryptoCipher
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cCryptoCipher()
    {
    }
#else /* !defined(CCRYPTOCIPHER_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOCIPHER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Encrypt
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH Encrypt
    (BYTE* out, TSIZE outSize, 
     const BYTE* in, TLENGTH inLength = UNDEFINED_LENGTH)
#if defined(CCRYPTOCIPHER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOCIPHER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOCIPHER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOCIPHER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOCIPHER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CCRYPTOCIPHER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Decrypt
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH Decrypt
    (BYTE* out, TSIZE outSize, 
     const BYTE* in, TLENGTH inLength = UNDEFINED_LENGTH)
#if defined(CCRYPTOCIPHER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOCIPHER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOCIPHER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOCIPHER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOCIPHER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CCRYPTOCIPHER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCRYPTOCIPHER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOCIPHER_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOCIPHER_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOCIPHER_HXX) || defined(CCRYPTOCIPHER_MEMBERS_ONLY) */
