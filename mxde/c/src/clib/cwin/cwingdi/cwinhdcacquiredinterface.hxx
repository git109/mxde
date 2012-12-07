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
 *   File: cwinhdcacquiredinterface.hxx
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
#if !defined(_CWINHDCACQUIREDINTERFACE_HXX) || defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINHDCACQUIREDINTERFACE_HXX) && !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY)
#define _CWINHDCACQUIREDINTERFACE_HXX
#endif /* !defined(_CWINHDCACQUIREDINTERFACE_HXX) && !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY)
#include "cwinhdcattached.hxx"
#include "cacquiredinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWinHDCAcquiredInterface;
/**
 **********************************************************************
 * Typedef: cWinHDCAcquiredInterfaceImplement
 *
 *  Author: $author$
 *    Date: 8/3/2010
 **********************************************************************
 */
typedef cAcquiredInterfaceT
<cWinHDCAcquiredInterface, cWinHDCAttachedInterface>
cWinHDCAcquiredInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinHDCAcquiredInterface
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDCAcquiredInterface
: virtual public cWinHDCAcquiredInterfaceImplement
{
public:
    typedef cWinHDCAcquiredInterfaceImplement cImplements;
#else /* !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWINHDCACQUIREDIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cWinHDCAcquiredImplement;
/**
 **********************************************************************
 * Typedef: cWinHDCAcquiredImplementImplement
 *
 *  Author: $author$
 *    Date: 8/3/2010
 **********************************************************************
 */
typedef cAcquiredImplementT
<cWinHDCAcquiredImplement, cWinHDCAcquiredInterface>
cWinHDCAcquiredImplementImplement;
/**
 **********************************************************************
 *  Class: cWinHDCAcquiredImplement
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinHDCAcquiredImplement
: virtual public cWinHDCAcquiredImplementImplement
{
public:
    typedef cWinHDCAcquiredImplementImplement cImplements;
#else /* !defined(CWINHDCACQUIREDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCACQUIREDIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINHDCACQUIREDIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWINHDCACQUIREDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCACQUIREDIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINHDCACQUIREDINTERFACE_HXX) || defined(CWINHDCACQUIREDINTERFACE_MEMBERS_ONLY) */
