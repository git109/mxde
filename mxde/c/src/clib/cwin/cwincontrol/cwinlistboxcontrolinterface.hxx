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
 *   File: cwinlistboxcontrolinterface.hxx
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
#if !defined(_CWINLISTBOXCONTROLINTERFACE_HXX) || defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINLISTBOXCONTROLINTERFACE_HXX) && !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY)
#define _CWINLISTBOXCONTROLINTERFACE_HXX
#endif /* !defined(_CWINLISTBOXCONTROLINTERFACE_HXX) && !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY)
#include "cwincontrolinterface.hxx"

#define CWINLISTBOXCONTROL_WINDOW_CLASSNAME \
    CWINLISTBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINLISTBOXCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE | WS_EX_CLIENTEDGE

#define CWINLISTBOXCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE | WS_BORDER | WS_VSCROLL

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinListBoxControlInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinControlInterface
cWinListBoxControlInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinListBoxControlInterface
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinListBoxControlInterface
: virtual public cWinListBoxControlInterfaceImplement
{
public:
    typedef cWinListBoxControlInterfaceImplement cImplements;
#else /* !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWINLISTBOXCONTROLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinListBoxControlImplementImplement
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinListBoxControlInterface
cWinListBoxControlImplementImplement;
/**
 **********************************************************************
 *  Class: cWinListBoxControlImplement
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinListBoxControlImplement
: virtual public cWinListBoxControlImplementImplement
{
public:
    typedef cWinListBoxControlImplementImplement cImplements;
#else /* !defined(CWINLISTBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROLIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWINLISTBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINLISTBOXCONTROLINTERFACE_HXX) || defined(CWINLISTBOXCONTROLINTERFACE_MEMBERS_ONLY) */
