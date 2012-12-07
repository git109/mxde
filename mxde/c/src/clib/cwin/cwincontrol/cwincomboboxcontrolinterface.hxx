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
 *   File: cwincomboboxcontrolinterface.hxx
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
#if !defined(_CWINCOMBOBOXCONTROLINTERFACE_HXX) || defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINCOMBOBOXCONTROLINTERFACE_HXX) && !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY)
#define _CWINCOMBOBOXCONTROLINTERFACE_HXX
#endif /* !defined(_CWINCOMBOBOXCONTROLINTERFACE_HXX) && !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY)
#include "cwincontrolinterface.hxx"
#include "cwincomboboxcontrolwindowsuperclass.hxx"

#define CWINCOMBOBOXCONTROL_WINDOW_CLASSNAME \
    CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINCOMBOBOXCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE | WS_EX_CLIENTEDGE

#define CWINCOMBOBOXCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE | WS_BORDER | CBS_DROPDOWNLIST

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinComboBoxControlInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinControlInterface
cWinComboBoxControlInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinComboBoxControlInterface
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinComboBoxControlInterface
: virtual public cWinComboBoxControlInterfaceImplement
{
public:
    typedef cWinComboBoxControlInterfaceImplement cImplements;
#else /* !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWINCOMBOBOXCONTROLIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinComboBoxControlImplementImplement
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinComboBoxControlInterface
cWinComboBoxControlImplementImplement;
/**
 **********************************************************************
 *  Class: cWinComboBoxControlImplement
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinComboBoxControlImplement
: virtual public cWinComboBoxControlImplementImplement
{
public:
    typedef cWinComboBoxControlImplementImplement cImplements;
#else /* !defined(CWINCOMBOBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROLIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWINCOMBOBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROLIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINCOMBOBOXCONTROLINTERFACE_HXX) || defined(CWINCOMBOBOXCONTROLINTERFACE_MEMBERS_ONLY) */
