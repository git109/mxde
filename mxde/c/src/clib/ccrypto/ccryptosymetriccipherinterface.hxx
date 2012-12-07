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
 *   File: ccryptosymetriccipherinterface.hxx
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOSYMETRICCIPHERINTERFACE_HXX) || defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY)
#if !defined(_CCRYPTOSYMETRICCIPHERINTERFACE_HXX) && !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY)
#define _CCRYPTOSYMETRICCIPHERINTERFACE_HXX
#endif /* !defined(_CCRYPTOSYMETRICCIPHERINTERFACE_HXX) && !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY)
#include "ccryptointerfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoSymetricCipherInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/5/2010
 **********************************************************************
 */
typedef cCryptoInterfaceBase
cCryptoSymetricCipherInterfaceImplement;
/**
 **********************************************************************
 *  Class: cCryptoSymetricCipherInterface
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cCryptoSymetricCipherInterface
: virtual public cCryptoSymetricCipherInterfaceImplement
{
public:
    typedef cCryptoSymetricCipherInterfaceImplement cImplements;
#else /* !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cCryptoSymetricCipherImplement
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cCryptoSymetricCipherImplement
: virtual public cCryptoSymetricCipherInterface
{
public:
    typedef cCryptoSymetricCipherInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOSYMETRICCIPHERINTERFACE_HXX) || defined(CCRYPTOSYMETRICCIPHERINTERFACE_MEMBERS_ONLY) */
