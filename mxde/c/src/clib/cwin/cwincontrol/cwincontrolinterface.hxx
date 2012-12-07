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
 *   File: cwincontrolinterface.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINCONTROLINTERFACE_HXX) || defined(CWINCONTROLINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINCONTROLINTERFACE_HXX) && !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY)
#define _CWINCONTROLINTERFACE_HXX
#endif /* !defined(_CWINCONTROLINTERFACE_HXX) && !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY)
#include "cwinwindowinterface.hxx"
#include <commctrl.h>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinControlInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinWindowInterface
cWinControlInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinControlInterface
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinControlInterface
: virtual public cWinControlInterfaceImplement
{
public:
    typedef cWinControlInterfaceImplement cImplements;
#else /* !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY)
/* include cWinControl member functions interface
 */
#define CWINCONTROL_MEMBERS_ONLY
#define CWINCONTROL_MEMBER_FUNCS_INTERFACE
#include "cwincontrol.hxx"
#undef CWINCONTROL_MEMBER_FUNCS_INTERFACE
#undef CWINCONTROL_MEMBERS_ONLY
};

#if !defined(CWINCONTROLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinControlImplementImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinControlInterface
cWinControlImplementImplement;
/**
 **********************************************************************
 *  Class: cWinControlImplement
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinControlImplement
: virtual public cWinControlImplementImplement
{
public:
    typedef cWinControlImplementImplement cImplements;
#else /* !defined(CWINCONTROLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINCONTROLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINCONTROLIMPLEMENT_MEMBERS_ONLY)
/* include cWinControl member functions implement
 */
#define CWINCONTROL_MEMBERS_ONLY
#define CWINCONTROL_MEMBER_FUNCS_IMPLEMENT
#include "cwincontrol.hxx"
#undef CWINCONTROL_MEMBER_FUNCS_IMPLEMENT
#undef CWINCONTROL_MEMBERS_ONLY
};
#else /* !defined(CWINCONTROLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINCONTROLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCONTROLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINCONTROLINTERFACE_HXX) || defined(CWINCONTROLINTERFACE_MEMBERS_ONLY) */
