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
 *   File: cwinroundedframemdichildwindow.hxx
 *
 * Author: $author$
 *   Date: 1/5/2010
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEMDICHILDWINDOW_HXX) || defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEMDICHILDWINDOW_HXX) && !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEMDICHILDWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEMDICHILDWINDOW_HXX) && !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY)
#include "cwinmdichildwindow.hxx"
#include "cwinroundedframewindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinRoundedFrameMDIChildWindow;
/**
 **********************************************************************
 * Typedef: cWinRoundedFrameMDIChildWindowExtend
 *
 *  Author: $author$
 *    Date: 1/5/2010
 **********************************************************************
 */
typedef cWinMDIChildWindowT
<cWinRoundedFrameMDIChildWindow, cWinRoundedFrameWindow>
cWinRoundedFrameMDIChildWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameMDIChildWindow
 *
 * Author: $author$
 *   Date: 1/5/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRoundedFrameMDIChildWindow
: public cWinRoundedFrameMDIChildWindowExtend
{
public:
    typedef cWinRoundedFrameMDIChildWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameMDIChildWindow
     *
     *       Author: $author$
     *         Date: 1/5/2010
     **********************************************************************
     */
    cWinRoundedFrameMDIChildWindow
    (COLORREF bgColor=CWINSTANDARDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINMDICHILDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, hBgBrush,
       windowClassNameChars,
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedFrameMDIChildWindow
     *
     *      Author: $author$
     *        Date: 1/5/2010
     **********************************************************************
     */
    virtual ~cWinRoundedFrameMDIChildWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_CREATE_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = cExtends::On_WM_CREATE_WindowMessage(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_MOVE_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_MOVE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = cExtends::On_WM_MOVE_WindowMessage(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_SIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_SIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = cExtends::On_WM_SIZE_WindowMessage(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/5/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_NCPAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = cExtends::On_WM_NCPAINT_WindowMessage(hWnd,msg,wParam,lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEMDICHILDWINDOW_HXX) || defined(CWINROUNDEDFRAMEMDICHILDWINDOW_MEMBERS_ONLY) */
