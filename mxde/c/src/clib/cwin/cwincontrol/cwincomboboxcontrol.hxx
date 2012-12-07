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
 *   File: cwincomboboxcontrol.hxx
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
#if !defined(_CWINCOMBOBOXCONTROL_HXX) || defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY)
#if !defined(_CWINCOMBOBOXCONTROL_HXX) && !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY)
#define _CWINCOMBOBOXCONTROL_HXX
#endif /* !defined(_CWINCOMBOBOXCONTROL_HXX) && !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY)
#include "cwincomboboxcontrolwindowsuperclass.hxx"
#include "cwincomboboxcontrolinterface.hxx"
#include "cwincontrol.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinComboBoxControlExtend
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinControl
cWinComboBoxControlExtend;
/**
 **********************************************************************
 *  Class: cWinComboBoxControl
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinComboBoxControl
: virtual public cWinComboBoxControlImplement,
  public cWinComboBoxControlExtend
{
public:
    typedef cWinComboBoxControlImplement cImplements;
    typedef cWinComboBoxControlExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinComboBoxControl
     *
     *       Author: $author$
     *         Date: 7/22/2010
     **********************************************************************
     */
    cWinComboBoxControl
    (LPCTSTR className=CWINCOMBOBOXCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINCOMBOBOXCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINCOMBOBOXCONTROL_DEFAULT_WINDOW_EXSTYLE,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (className, style, exStyle, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinComboBoxControl
     *
     *      Author: $author$
     *        Date: 7/22/2010
     **********************************************************************
     */
    virtual ~cWinComboBoxControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINCOMBOBOXCONTROL_HXX) || defined(CWINCOMBOBOXCONTROL_MEMBERS_ONLY) */
