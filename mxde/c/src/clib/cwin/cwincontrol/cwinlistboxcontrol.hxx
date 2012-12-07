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
 *   File: cwinlistboxcontrol.hxx
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
#if !defined(_CWINLISTBOXCONTROL_HXX) || defined(CWINLISTBOXCONTROL_MEMBERS_ONLY)
#if !defined(_CWINLISTBOXCONTROL_HXX) && !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY)
#define _CWINLISTBOXCONTROL_HXX
#endif /* !defined(_CWINLISTBOXCONTROL_HXX) && !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY)
#include "cwinlistboxcontrolwindowsuperclass.hxx"
#include "cwinlistboxcontrolinterface.hxx"
#include "cwincontrol.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinListBoxControlExtend
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinControl
cWinListBoxControlExtend;
/**
 **********************************************************************
 *  Class: cWinListBoxControl
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinListBoxControl
: virtual public cWinListBoxControlImplement,
  public cWinListBoxControlExtend
{
public:
    typedef cWinListBoxControlImplement cImplements;
    typedef cWinListBoxControlExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinListBoxControl
     *
     *       Author: $author$
     *         Date: 7/22/2010
     **********************************************************************
     */
    cWinListBoxControl
    (LPCTSTR className=CWINLISTBOXCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINLISTBOXCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINLISTBOXCONTROL_DEFAULT_WINDOW_EXSTYLE,
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
     *  Destructor: ~cWinListBoxControl
     *
     *      Author: $author$
     *        Date: 7/22/2010
     **********************************************************************
     */
    virtual ~cWinListBoxControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINLISTBOXCONTROL_HXX) || defined(CWINLISTBOXCONTROL_MEMBERS_ONLY) */
