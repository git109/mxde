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
 *   File: cwinhdccreatedinterface.hxx
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
#if !defined(_CWINHDCCREATEDINTERFACE_HXX) || defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINHDCCREATEDINTERFACE_HXX) && !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY)
#define _CWINHDCCREATEDINTERFACE_HXX
#endif /* !defined(_CWINHDCCREATEDINTERFACE_HXX) && !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY)
#include "cwinhdcacquiredinterface.hxx"
#include "ccreatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWinHDCCreatedInterface;
/**
 **********************************************************************
 * Typedef: cWinHDCCreatedInterfaceImplement
 *
 *  Author: $author$
 *    Date: 8/4/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinHDCCreatedInterface, cWinHDCAcquiredInterface>
cWinHDCCreatedInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinHDCCreatedInterface
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDCCreatedInterface
: virtual public cWinHDCCreatedInterfaceImplement
{
public:
    typedef cWinHDCCreatedInterfaceImplement cImplements;
#else /* !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWINHDCCREATEDIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cWinHDCCreatedImplement;
/**
 **********************************************************************
 * Typedef: cWinHDCCreatedImplementImplement
 *
 *  Author: $author$
 *    Date: 8/4/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinHDCCreatedImplement, cWinHDCCreatedInterface>
cWinHDCCreatedImplementImplement;
/**
 **********************************************************************
 *  Class: cWinHDCCreatedImplement
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinHDCCreatedImplement
: virtual public cWinHDCCreatedImplementImplement
{
public:
    typedef cWinHDCCreatedImplementImplement cImplements;
#else /* !defined(CWINHDCCREATEDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCCREATEDIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINHDCCREATEDIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWINHDCCREATEDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCCREATEDIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINHDCCREATEDINTERFACE_HXX) || defined(CWINHDCCREATEDINTERFACE_MEMBERS_ONLY) */
