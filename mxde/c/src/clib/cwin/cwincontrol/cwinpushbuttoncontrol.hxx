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
 *   File: cwinpushbuttoncontrol.hxx
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
#if !defined(_CWINPUSHBUTTONCONTROL_HXX) || defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY)
#if !defined(_CWINPUSHBUTTONCONTROL_HXX) && !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY)
#define _CWINPUSHBUTTONCONTROL_HXX
#endif /* !defined(_CWINPUSHBUTTONCONTROL_HXX) && !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY) */

#if !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY)
#include "cwinpushbuttoncontrolwindowsuperclass.hxx"
#include "cwincontrol.hxx"

#define CWINPUSHBUTTONCONTROL_WINDOW_CLASSNAME \
    CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINPUSHBUTTONCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE

#define CWINPUSHBUTTONCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE | BS_PUSHBUTTON

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinPushButtonControlExtend
 *
 *  Author: $author$
 *    Date: 7/28/2010
 **********************************************************************
 */
typedef cWinControl
cWinPushButtonControlExtend;
/**
 **********************************************************************
 *  Class: cWinPushButtonControl
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinPushButtonControl
: //virtual public cWinPushButtonControlImplement,
  public cWinPushButtonControlExtend
{
public:
    //typedef cWinPushButtonControlImplement cImplements;

    typedef cWinPushButtonControlExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinPushButtonControl
     *
     *       Author: $author$
     *         Date: 7/28/2010
     **********************************************************************
     */
    cWinPushButtonControl
    (LPCTSTR className=CWINPUSHBUTTONCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINPUSHBUTTONCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINPUSHBUTTONCONTROL_DEFAULT_WINDOW_EXSTYLE,
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
     *  Destructor: ~cWinPushButtonControl
     *
     *      Author: $author$
     *        Date: 7/28/2010
     **********************************************************************
     */
    virtual ~cWinPushButtonControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY) */

#if !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINPUSHBUTTONCONTROL_HXX) || defined(CWINPUSHBUTTONCONTROL_MEMBERS_ONLY) */
