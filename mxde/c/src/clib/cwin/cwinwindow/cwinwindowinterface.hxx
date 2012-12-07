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
 *   File: cwinwindowinterface.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINWINDOWINTERFACE_HXX) || defined(CWINWINDOWINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINWINDOWINTERFACE_HXX) && !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY)
#define _CWINWINDOWINTERFACE_HXX
#endif /* !defined(_CWINWINDOWINTERFACE_HXX) && !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY)
#include "cwinwindowmessagetargetinterface.hxx"
#include "cwinattachedhinstanceinterface.hxx"
#include "cwinhwnd.hxx"

#define CWIN_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define CWIN_DEFAULT_WINDOW_EXSTYLE 0

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinWindowHandleInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinHWNDInterface
cWinWindowHandleInterfaceImplement;
/**
 **********************************************************************
 * Typedef: cWinWindowMessageInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinWindowMessageTargetInterface
cWinWindowMessageInterfaceImplement;
/**
 **********************************************************************
 * Typedef: cWinInstanceHandleInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinAttachedHINSTANCEInterface
cWinInstanceHandleInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinWindowInterface
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinWindowInterface
: virtual public cWinWindowHandleInterfaceImplement,
  virtual public cWinWindowMessageInterfaceImplement,
  virtual public cWinInstanceHandleInterfaceImplement
{
public:
    typedef cWinWindowHandleInterfaceImplement cImplements;
    typedef cWinWindowMessageInterfaceImplement cMessageImplements;
    typedef cWinInstanceHandleInterfaceImplement cInstanceImplements;
#else /* !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY)
/* include cWinWindow member functions interface
 */
#define CWINWINDOW_MEMBERS_ONLY
#define CWINWINDOW_MEMBER_FUNCS_INTERFACE
#include "cwinwindow.hxx"
#undef CWINWINDOW_MEMBER_FUNCS_INTERFACE
#undef CWINWINDOW_MEMBERS_ONLY
};

#if !defined(CWINWINDOWIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinWindowImplementImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinWindowInterface
cWinWindowImplementImplement;
/**
 **********************************************************************
 * Typedef: cWinWindowMessageImplementImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinWindowMessageTargetImplement
cWinWindowMessageImplementImplement;
/**
 **********************************************************************
 * Typedef: cWinInstanceHandleImplementImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinAttachedHINSTANCEImplement
cWinInstanceHandleImplementImplement;
/**
 **********************************************************************
 *  Class: cWinWindowImplement
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinWindowImplement
: virtual public cWinWindowImplementImplement,
  virtual public cWinWindowMessageImplementImplement,
  virtual public cWinInstanceHandleImplementImplement
{
public:
    typedef cWinWindowImplementImplement cImplements;
#else /* !defined(CWINWINDOWIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINWINDOWIMPLEMENT_MEMBERS_ONLY)
/* include cWinWindow member functions implement
 */
#define CWINWINDOW_MEMBERS_ONLY
#define CWINWINDOW_MEMBER_FUNCS_IMPLEMENT
#include "cwinwindow.hxx"
#undef CWINWINDOW_MEMBER_FUNCS_IMPLEMENT
#undef CWINWINDOW_MEMBERS_ONLY
};
#else /* !defined(CWINWINDOWIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINWINDOWINTERFACE_HXX) || defined(CWINWINDOWINTERFACE_MEMBERS_ONLY) */
