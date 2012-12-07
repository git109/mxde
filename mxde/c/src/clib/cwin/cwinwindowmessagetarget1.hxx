/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwinwindowmessagetarget.hxx
 *
 * Author: $author$
 *   Date: 5/19/2009
 **********************************************************************
 */
#if !defined(_CWINWINDOWMESSAGETARGET_HXX) || defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
#if !defined(_CWINWINDOWMESSAGETARGET_HXX) && !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
#define _CWINWINDOWMESSAGETARGET_HXX
#endif /* !defined(_CWINWINDOWMESSAGETARGET_HXX) && !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */

#if !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
#include "cwinwindowmessagetargetinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinWindowMessageTarget
 *
 * Author: $author$
 *   Date: 5/19/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindowMessageTarget
: virtual public cWinWindowMessageTargetImplement
{
public:
    typedef cWinWindowMessageTargetImplement cImplements;
    typedef cWinWindowMessageTarget cDerives;

    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 5/19/2009
     **********************************************************************
     */
    static LRESULT CALLBACK WindowProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult;
        LPVOID userData;
        CREATESTRUCT *cs;
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
            if ((target = (cWinWindowMessageTargetInterface*)
                (userData = cs->lpCreateParams)))
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

        lResult = DefWindowProc(hWnd, msg, wParam, lParam);
        return lResult;
    }
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */

#include "cwinwindowmessagetarget_members.hxx"

    /**
     **********************************************************************
     * Function: OnWindowMessage
     *
     *   Author: $author$
     *     Date: 7/15/2009
     **********************************************************************
     */
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE */
    {
        LRESULT lResult = 0;

        switch(msg)
        {
#include "cwinwindowmessagetarget_cases.hxx"

        default:
            lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        }
        return lResult;
    }
#endif /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */

#endif /* !defined(_CWINWINDOWMESSAGETARGET_HXX) || defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */
