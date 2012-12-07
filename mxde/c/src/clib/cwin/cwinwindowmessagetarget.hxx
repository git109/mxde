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
 *   File: cwinwindowmessagetarget.hxx
 *
 * Author: $author$
 *   Date: 1/4/2010
 **********************************************************************
 */
#if !defined(_CWINWINDOWMESSAGETARGET_HXX) || defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
#if !defined(_CWINWINDOWMESSAGETARGET_HXX) && !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
#define _CWINWINDOWMESSAGETARGET_HXX
#endif /* !defined(_CWINWINDOWMESSAGETARGET_HXX) && !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */

#if !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY)
#include "cwinwindowmessagetargetinterface.hxx"
#include "cwinbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinWindowMessageTargetExtend
 *
 *  Author: $author$
 *    Date: 1/4/2010
 **********************************************************************
 */
typedef cWinBase
cWinWindowMessageTargetExtend;
/**
 **********************************************************************
 *  Class: cWinWindowMessageTarget
 *
 * Author: $author$
 *   Date: 1/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindowMessageTarget
: virtual public cWinWindowMessageTargetImplement,
  public cWinWindowMessageTargetExtend
{
public:
    typedef cWinWindowMessageTargetImplement cImplements;
    typedef cWinWindowMessageTargetExtend cExtends;
    
    cWinWindowMessageTargetInterface* m_windowMessageListen;
    
    /**
     **********************************************************************
     *  Constructor: cWinWindowMessageTarget
     *
     *       Author: $author$
     *         Date: 1/4/2010
     **********************************************************************
     */
    cWinWindowMessageTarget
    (cWinWindowMessageTargetInterface* windowMessageListen=0)
    : m_windowMessageListen(windowMessageListen)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinWindowMessageTarget
     *
     *      Author: $author$
     *        Date: 1/4/2010
     **********************************************************************
     */
    virtual ~cWinWindowMessageTarget()
    {
    }
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBERS_ONLY) */

#define CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_NO_WINDOW_MESSAGE_DEFAULT
#include "cwinwindowmessagetarget_members.hxx"
#undef CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_NO_WINDOW_MESSAGE_DEFAULT

    /**
     **********************************************************************
     * Function: OnDefaultWindowMessage
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual LRESULT OnDefaultWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    {
        LRESULT lResult = 0;
#if !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
#endif /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    {
        LRESULT lResult = 0;
#if !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
        lResult = DefWindowProc(hWnd, msg, wParam, lParam);
        return lResult;
    }
#endif /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnWindowMessage
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    {
        LRESULT lResult = 0;
#if !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) 
        cWinWindowMessageTargetInterface* windowMessageListen = (m_windowMessageListen);
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
        cWinWindowMessageTargetInterface* windowMessageListen = WindowMessageListen();
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */

        if (windowMessageListen)
            windowMessageListen->OnWindowMessage(hWnd,msg,wParam,lParam);
            
        switch(msg)
        {
#include "cwinwindowmessagetarget_cases.hxx"

        default:
            lResult = OnDefaultWindowMessage(hWnd,msg,wParam,lParam);
        }
        return lResult;
    }
#endif /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */

#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 1/4/2010
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
#endif /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowMessageListen
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual cWinWindowMessageTargetInterface* SetWindowMessageListen
    (cWinWindowMessageTargetInterface* toWindowMessageListen) 
#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    {
        cWinWindowMessageTargetInterface* windowMessageListen = 0;
#if !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) 
        windowMessageListen = (m_windowMessageListen = toWindowMessageListen);
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
        return windowMessageListen;
    }
#endif /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowMessageListen
     *
     *   Author: $author$
     *     Date: 1/4/2010
     **********************************************************************
     */
    virtual cWinWindowMessageTargetInterface* WindowMessageListen() const 
#if defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_INTERFACE) */
    {
        cWinWindowMessageTargetInterface* windowMessageListen = 0;
#if !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) 
        windowMessageListen = (m_windowMessageListen);
#else /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWMESSAGETARGET_MEMBER_FUNCS_IMPLEMENT) */
        return windowMessageListen;
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
