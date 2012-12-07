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
 *   File: cwincheckboxcontrol.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINCHECKBOXCONTROL_HXX) || defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY)
#if !defined(_CWINCHECKBOXCONTROL_HXX) && !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY)
#define _CWINCHECKBOXCONTROL_HXX
#endif /* !defined(_CWINCHECKBOXCONTROL_HXX) && !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY) */

#if !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY)
#include "cwincheckboxcontrolwindowsuperclass.hxx"
#include "cwincontrol.hxx"

#define CWINCHECKBOXCONTROL_WINDOW_CLASSNAME \
    CWINCHECKBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINCHECKBOXCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE

#define CWINCHECKBOXCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE | BS_AUTOCHECKBOX

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCheckBoxControlExtend
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinControl
cWinCheckBoxControlExtend;
/**
 **********************************************************************
 *  Class: cWinCheckBoxControl
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCheckBoxControl
: /*virtual public cWinCheckBoxControlImplement,*/
  public cWinCheckBoxControlExtend
{
public:
    /*typedef cWinCheckBoxControlImplement cImplements;*/
    typedef cWinCheckBoxControlExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinCheckBoxControl
     *
     *       Author: $author$
     *         Date: 7/21/2010
     **********************************************************************
     */
    cWinCheckBoxControl
    (LPCTSTR className=CWINCHECKBOXCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINCHECKBOXCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINCHECKBOXCONTROL_DEFAULT_WINDOW_EXSTYLE,
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
     *  Destructor: ~cWinCheckBoxControl
     *
     *      Author: $author$
     *        Date: 7/21/2010
     **********************************************************************
     */
    virtual ~cWinCheckBoxControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: GetIsChecked
     *
     *    Author: $author$
     *      Date: 8/3/2010
     **********************************************************************
     */
    virtual int GetIsChecked() const
#if defined(CWINCHECKBOXCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCHECKBOXCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINCHECKBOXCONTROL_MEMBER_FUNCS_IMPLEMENT)
        int is = -e_ERROR_NOT_ATTACHED;
        HWND hWnd;
        
        if ((hWnd = Attached()))
            is = (BST_CHECKED == SendMessage
                  (hWnd, BM_GETSTATE, 0, 0));
#else /* !defined(CWINCHECKBOXCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        int is = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINCHECKBOXCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINCHECKBOXCONTROL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINCHECKBOXCONTROL_HXX) || defined(CWINCHECKBOXCONTROL_MEMBERS_ONLY) */
