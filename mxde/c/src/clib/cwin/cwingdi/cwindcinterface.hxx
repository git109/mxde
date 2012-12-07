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
 *   File: cwindcinterface.hxx
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
#if !defined(_CWINDCINTERFACE_HXX) || defined(CWINDCINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINDCINTERFACE_HXX) && !defined(CWINDCINTERFACE_MEMBERS_ONLY)
#define _CWINDCINTERFACE_HXX
#endif /* !defined(_CWINDCINTERFACE_HXX) && !defined(CWINDCINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINDCINTERFACE_MEMBERS_ONLY)
#include "cwinhdccreatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDCInterfaceImplement
 *
 *  Author: $author$
 *    Date: 8/4/2010
 **********************************************************************
 */
typedef cWinHDCCreatedInterface
cWinDCInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinDCInterface
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinDCInterface
: virtual public cWinDCInterfaceImplement
{
public:
    typedef cWinDCInterfaceImplement cImplements;
#else /* !defined(CWINDCINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINDCINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINDCINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWINDCIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinDCImplementImplement
 *
 *  Author: $author$
 *    Date: 8/4/2010
 **********************************************************************
 */
typedef cWinDCInterface
cWinDCImplementImplement;
/**
 **********************************************************************
 *  Class: cWinDCImplement
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinDCImplement
: virtual public cWinDCImplementImplement
{
public:
    typedef cWinDCImplementImplement cImplements;
#else /* !defined(CWINDCIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINDCIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINDCIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWINDCIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINDCIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDCINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINDCINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINDCINTERFACE_HXX) || defined(CWINDCINTERFACE_MEMBERS_ONLY) */
