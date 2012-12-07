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
 *   File: ccryptosymetriccipher.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOSYMETRICCIPHER_HXX) || defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY)
#if !defined(_CCRYPTOSYMETRICCIPHER_HXX) && !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY)
#define _CCRYPTOSYMETRICCIPHER_HXX
#endif /* !defined(_CCRYPTOSYMETRICCIPHER_HXX) && !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY) */

#if !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY)
#include "ccryptobase.hxx"
#include "ccryptosymetriccipherinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoSymetricCipherExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cCryptoBase
cCryptoSymetricCipherExtend;
/**
 **********************************************************************
 *  Class: cCryptoSymetricCipher
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cCryptoSymetricCipher
: virtual public cCryptoSymetricCipherImplement,
  public cCryptoSymetricCipherExtend
{
public:
    typedef cCryptoSymetricCipherImplement cImplements;
    typedef cCryptoSymetricCipherExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cCryptoSymetricCipher
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cCryptoSymetricCipher()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCryptoSymetricCipher
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cCryptoSymetricCipher()
    {
    }
#else /* !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Crypt
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual TLENGTH Crypt()
#if defined(CCRYPTOSYMETRICCIPHER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCRYPTOSYMETRICCIPHER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CCRYPTOSYMETRICCIPHER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CCRYPTOSYMETRICCIPHER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCRYPTOSYMETRICCIPHER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CCRYPTOSYMETRICCIPHER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOSYMETRICCIPHER_HXX) || defined(CCRYPTOSYMETRICCIPHER_MEMBERS_ONLY) */
