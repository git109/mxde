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
 *   File: cwinmdichildwindowclass.hxx
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
#if !defined(_CWINMDICHILDWINDOWCLASS_HXX) || defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY)
#if !defined(_CWINMDICHILDWINDOWCLASS_HXX) && !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY)
#define _CWINMDICHILDWINDOWCLASS_HXX
#endif /* !defined(_CWINMDICHILDWINDOWCLASS_HXX) && !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY) */

#define CWINMDICHILDWINDOWCLASS_WINDOW_CLASSNAME "cWinMDIChildWindow"

#if !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY)
#include "cwinwindowclass.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinMDIChildWindowClass
 *
 * Author: $author$
 *   Date: 1/2/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIChildWindowClass
: public cWinWindowClass
{
public:
    typedef cWinWindowClass cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMDIChildWindowClass
     *
     *       Author: $author$
     *         Date: 1/2/2010
     **********************************************************************
     */
    cWinMDIChildWindowClass
    (LPCTSTR windowClassNameChars=_T(CWINMDICHILDWINDOWCLASS_WINDOW_CLASSNAME),
     WNDPROC windowProc=MDIChildWindowProc,
     int windowExtra=(int)(sizeof(cWinInterfaceBase*)),
     int windowExtraOffset=0,
     int classExtra=0,
     int classExtraOffset=0,
     UINT classStyle=0,
     ATOM attached=NULL,
     bool isRegistered=false,
     bool isCreated=false) 
    : cExtends
      (windowClassNameChars, 
       windowProc, windowExtra, windowExtraOffset,
       classExtra, classExtraOffset, classStyle, 
       attached, isRegistered, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIChildWindowClass
     *
     *      Author: $author$
     *        Date: 1/2/2010
     **********************************************************************
     */
    virtual ~cWinMDIChildWindowClass()
    {
    }
#else /* !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY) */

#if !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: MDIChildWindowProc
     *
     *   Author: $author$
     *     Date: 1/2/2010
     **********************************************************************
     */
    static LRESULT CALLBACK MDIChildWindowProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
        LPVOID userData;
        CREATESTRUCT *cs;
        MDICREATESTRUCT *mcs;
        cWinWindowMessageTargetInterface* target;

#if defined(WINDOWS_MSC_VER_8)
#pragma warning(push)
#pragma warning(disable:4312)
#endif /* defined(WINDOWS_MSC_VER_8) */

        if ((target = (cWinWindowMessageTargetInterface*)
            (GetWindowLongPtr(hWnd, GWLP_USERDATA))))
        {
            lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
            return lResult;
        }

        switch(msg)
        {
#if defined(WINDOWS_WCE)
        case WM_CREATE:
#else /* defined(WINDOWS_WCE) */
        case WM_NCCREATE:
#endif /* defined(WINDOWS_WCE) */
            if ((cs = (CREATESTRUCT*)(lParam)))
            if ((mcs = (MDICREATESTRUCT*)(cs->lpCreateParams)))
            if ((target = (cWinWindowMessageTargetInterface*)
                (userData = (LPVOID)(mcs->lParam))))
            {
                SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG)(LONG_PTR)(userData));
                lResult = target->OnWindowMessage(hWnd, msg, wParam, lParam);
                return lResult;
            }
            break;
        }

#if defined(WINDOWS_MSC_VER_8)
#pragma warning(pop)
#endif /* defined(WINDOWS_MSC_VER_8) */

        lResult = DefMDIChildProc(hWnd, msg, wParam, lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDICHILDWINDOWCLASS_HXX) || defined(CWINMDICHILDWINDOWCLASS_MEMBERS_ONLY) */
