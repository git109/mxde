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
 *   File: ccryptokeyinterface.hxx
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOKEYINTERFACE_HXX) || defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY)
#if !defined(_CCRYPTOKEYINTERFACE_HXX) && !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY)
#define _CCRYPTOKEYINTERFACE_HXX
#endif /* !defined(_CCRYPTOKEYINTERFACE_HXX) && !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY)
#include "ccryptointerfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoKeyInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/5/2010
 **********************************************************************
 */
typedef cCryptoInterfaceBase
cCryptoKeyInterfaceImplement;
/**
 **********************************************************************
 *  Class: cCryptoKeyInterface
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cCryptoKeyInterface
: virtual public cCryptoKeyInterfaceImplement
{
public:
    typedef cCryptoKeyInterfaceImplement cImplements;
#else /* !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cCryptoKeyImplement
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cCryptoKeyImplement
: virtual public cCryptoKeyInterface
{
public:
    typedef cCryptoKeyInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOKEYINTERFACE_HXX) || defined(CCRYPTOKEYINTERFACE_MEMBERS_ONLY) */
