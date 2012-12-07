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
 *   File: cwinglteapotmainwindow.hxx
 *
 * Author: $author$
 *   Date: 12/5/2009
 **********************************************************************
 */
#if !defined(_CWINGLTEAPOTMAINWINDOW_HXX) || defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINGLTEAPOTMAINWINDOW_HXX) && !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY)
#define _CWINGLTEAPOTMAINWINDOW_HXX
#endif /* !defined(_CWINGLTEAPOTMAINWINDOW_HXX) && !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY)
#include "cwinstandardwindow.hxx"
#include <GL/mesa_wgl.h>

#define CWINGLTEAPOTMAINWINDOW_WINDOW_CLASSNAME \
    "cWinGLTeapotMainWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinGLTeapotMainWindowExtends
 *
 *  Author: $author$
 *    Date: 12/5/2009
 **********************************************************************
 */
typedef cWinStandardWindow
cWinGLTeapotMainWindowExtends;
/**
 **********************************************************************
 *  Class: cWinGLTeapotMainWindow
 *
 * Author: $author$
 *   Date: 12/5/2009
 **********************************************************************
 */
class cWinGLTeapotMainWindow
: public cWinGLTeapotMainWindowExtends
{
public:
    typedef cWinGLTeapotMainWindowExtends cExtends;

    HDC m_hDC;    
    HGLRC m_hGLRC;
    
    /**
     **********************************************************************
     *  Constructor: cWinGLTeapotMainWindow
     *
     *       Author: $author$
     *         Date: 12/5/2009
     **********************************************************************
     */
    cWinGLTeapotMainWindow
    (COLORREF bgColor=CWINSTANDARDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINGLTEAPOTMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
      m_hGLRC(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinGLTeapotMainWindow
     *
     *      Author: $author$
     *        Date: 12/5/2009
     **********************************************************************
     */
    virtual ~cWinGLTeapotMainWindow()
    {
    }
    /**
     **********************************************************************
     *  Function: CreateMainWindow
     *
     *    Author: $author$
     *      Date: 12/5/2009
     **********************************************************************
     */
    virtual eError CreateMainWindow
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow)
    {
        eError error = e_ERROR_FAILED;
        const TCHAR* chars;
        HWND hWndDesktop;
        RECT r;
        
        if ((chars = windowClass.WindowClassName()))
        if ((hWndDesktop = GetDesktopWindow()))
        if (GetClientRect(hWndDesktop, &r))
        {
            int w = (r.right-r.left)/2;
            int h = (r.bottom-r.top)/2;
            int x = (r.right-r.left)/3-w/2;
            int y = (r.bottom-r.top)/3-h/2;
            
            if (!(error = Create
                (hInstance, chars, NULL, hWndDesktop, 
                 NULL, WS_OVERLAPPEDWINDOW, 0, x,y, w, h)))
            {
                SetText(cmdLine);
                Show();
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: On_WM_CREATE_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_CREATE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        eError error;
        HDC hDC;
        HGLRC hGLRC;
        if ((hDC = GetDC(hWnd)))
        {
            if ((hGLRC = CreateWindowGL(hDC)))
            {
                HDC hDCCurrent = wglGetCurrentDC();
                HGLRC hGLRCCurrent = wglGetCurrentContext();
                
                if (!(error = InitializeWindowGL(hDC, hGLRC)))
                {
                    m_hDC = hDC;
                    m_hGLRC = hGLRC;
                    return lResult;
                }
                wglDeleteContext(hGLRC);
            }
            ReleaseDC(hWnd, hDC);
        }
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/3/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult;
        if (m_hGLRC)
        {
           wglDeleteContext(m_hGLRC);
           m_hGLRC = 0;
        }
        if (m_hDC)
        {
           ReleaseDC(hWnd, m_hDC);
           m_hDC = 0;
        }
        SetIsCreated(false);
        PostQuitMessage(0);
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0; //OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        HDC hDC;
        PAINTSTRUCT ps;
        
        if ((hDC = BeginPaint(hWnd, &ps)))
        {
            if ((m_hDC))
            if ((m_hGLRC))
                RedrawWindowGL(m_hDC, m_hGLRC);
                
            EndPaint(hWnd, &ps);
        }       
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_SIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_SIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult;
        ResizeWindowGL(m_hDC, m_hGLRC, LOWORD(lParam), HIWORD(lParam));
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: CreateWindowGL
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual HGLRC CreateWindowGL(HDC hDC);
    /**
     **********************************************************************
     * Function: InitializeWindowGL
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual eError InitializeWindowGL(HDC hDC, HGLRC hGLRC);
    /**
     **********************************************************************
     * Function: ResizeWindowGL
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual eError ResizeWindowGL
    (HDC hDC, HGLRC hGLRC, int w, int h);
    /**
     **********************************************************************
     * Function: RedrawWindowGL
     *
     *   Author: $author$
     *     Date: 12/6/2009
     **********************************************************************
     */
    virtual eError RedrawWindowGL(HDC hDC, HGLRC hGLRC);
#else /* !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINGLTEAPOTMAINWINDOW_HXX) || defined(CWINGLTEAPOTMAINWINDOW_MEMBERS_ONLY) */
