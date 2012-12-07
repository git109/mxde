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
 *   File: cwinncwindow.hxx
 *
 * Author: $author$
 *   Date: 5/31/2009
 **********************************************************************
 */
#ifndef _CWINNCWINDOW_HXX
#define _CWINNCWINDOW_HXX

#include "cwinwindow.hxx"

#define CWINNCWINDOW_BG_COLOR_R 0xFF
#define CWINNCWINDOW_BG_COLOR_G 0xFF
#define CWINNCWINDOW_BG_COLOR_B 0xDD

#define CWINNCWINDOW_BG_COLOR \
    RGB(CWINNCWINDOW_BG_COLOR_R, \
        CWINNCWINDOW_BG_COLOR_G, \
        CWINNCWINDOW_BG_COLOR_B)

#define CWINNCWINDOW_WINDOW_CLASSNAME \
    "cWinNCWindow"

/**
 **********************************************************************
 * Typedef: cWinNCWindowExtends
 *
 *  Author: $author$
 *    Date: 5/31/2009
 **********************************************************************
 */
typedef cWinWindow
cWinNCWindowExtends;

/**
 **********************************************************************
 *  Class: cWinNCWindow
 *
 * Author: $author$
 *   Date: 5/31/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinNCWindow
: public cWinNCWindowExtends
{
public:
    typedef cWinNCWindowExtends cExtends;
    typedef cWinNCWindow cDerives;
    /**
     **********************************************************************
     * Constructor: cWinNCWindow
     *
     *      Author: $author$
     *        Date: 5/31/2009
     **********************************************************************
     */
    cWinNCWindow
    (HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinNCWindow
     *
     *     Author: $author$
     *       Date: 5/31/2009
     **********************************************************************
     */
    virtual ~cWinNCWindow()
    {
    }

    /**
     **********************************************************************
     * Function: SizeClientArea
     *
     *   Author: $author$
     *     Date: 12/31/2009
     **********************************************************************
     */
    virtual eError SizeClientArea
    (UINT width, UINT height, BOOL bRepaint=FALSE) 
    {
        eError error = e_ERROR_NONE;
        HWND hWnd;
        RECT rect;
        if ((hWnd = Attached()))
        if ((GetWindowRect(hWnd, &rect)))
            MoveWindow
            (hWnd, rect.left,rect.right, 
             width,height, bRepaint);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnSize
     *
     *   Author: $author$
     *     Date: 6/2/2009
     **********************************************************************
     */
    virtual BOOL OnSize
    (LRESULT& lResult,
     HRGN& hRgn,
     RECT& r,
     HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL handled = FALSE;
        return handled;
    }
    /**
     **********************************************************************
     * Function: OnNCPaint
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual BOOL OnNCPaint
    (LRESULT& lResult,
     HDC hDC,
     RECT& r,
     HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL handled = FALSE;
        return handled;
    }
    /**
     **********************************************************************
     * Function: OnNCHitTest
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual BOOL OnNCHitTest
    (LRESULT& lResult,
     POINT& p,
     RECT& r,
     HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL handled = FALSE;
        return handled;
    }
    /**
     **********************************************************************
     * Function: OnNCCalcSize
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual BOOL OnNCCalcSize
    (LRESULT& lResult,
     RECT& r,
     LPNCCALCSIZE_PARAMS pNCCParams,
     HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        BOOL handled = FALSE;
        return handled;
    }

    /**
     **********************************************************************
     * Function: On_WM_SIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_SIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        HRGN hRgn = NULL;
        BOOL handled;
        RECT r;

        if ((GetWindowRect(hWnd, &r)))
        {
            r.right -= r.left;
            r.bottom -= r.top;
            r.left = r.top = 0;

            if ((handled = OnSize
                (lResult, hRgn, r, hWnd,msg,wParam,lParam)))
            {
                if (hRgn)
                if ((SetWindowRegion(hWnd, hRgn)))
                    return lResult;
            }
        }
        lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCCALCSIZE_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCCALCSIZE_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        LPNCCALCSIZE_PARAMS pNCCParams = 0;
        LPRECT pRect;
        BOOL handled;

        if ((pRect = (LPRECT)(lParam)))
        {
            if (wParam)
            {
                pNCCParams = (LPNCCALCSIZE_PARAMS)(lParam);
                pRect = &pNCCParams->rgrc[0];
                lResult = WVR_VALIDRECTS;

                if ((handled = OnNCCalcSize
                    (lResult, *pRect, pNCCParams, hWnd, msg, wParam, lParam)))
                    return lResult;
            }
        }
        lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCHITTEST_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCHITTEST_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        BOOL handled;
        POINT p;
        RECT r;
        if ((GetWindowRect(hWnd, &r)))
        {
            p.x = GET_X_LPARAM(lParam);
            p.y = GET_Y_LPARAM(lParam);

            if ((handled = OnNCHitTest
                (lResult, p, r, hWnd, msg, wParam, lParam)))
                return lResult;
        }
        lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_NCPAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual LRESULT On_WM_NCPAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        BOOL handled;
        HDC hDC;
        RECT r;
        if ((GetWindowRect(hWnd, &r)))
        if ((hDC = GetWindowDC(hWnd)))
        {
            r.right -= r.left;
            r.bottom -= r.top;
            r.left = r.top = 0;

            handled = OnNCPaint
            (lResult, hDC, r, hWnd, msg, wParam, lParam);
            ReleaseDC(hWnd, hDC);

            if (handled)
                return lResult;
        }
        lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: SetWindowRegion
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HRGN SetWindowRegion
    (HWND hWnd, HRGN hToRgn, BOOL bRedraw=TRUE) 
#if defined(CWINNCWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINNCWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
#if !defined(CWINNCWINDOW_MEMBER_FUNCS_IMPLEMENT)
        if ((hWnd) &&  (hToRgn))
        if ((SetWindowRgn(hWnd, hToRgn, bRedraw)))
            hRgn = hToRgn;
#else /* !defined(CWINNCWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINNCWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINNCWINDOW_MEMBER_FUNCS_INTERFACE) */
};
#endif /* _CWINNCWINDOW_HXX */
