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
 *   File: cwinroundedrectanglewindow.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CWINROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDRECTANGLEWINDOW_HXX
#endif /* !defined(_CWINROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#include "cwinshapedwindow.hxx"

#define CWINROUNDEDRECTANGLEWINDOW_CORNER_RADIUS 10

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRoundedRectangleWindowExtend
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cWinShapedWindow
cWinRoundedRectangleWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedRectangleWindow
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRoundedRectangleWindow
: public cWinRoundedRectangleWindowExtend
{
public:
    typedef cWinRoundedRectangleWindowExtend cExtends;
    
    TSIZE m_cornerRadius;
    
    TSIZE m_topMargin;
    TSIZE m_bottomMargin;
    TSIZE m_leftMargin;
    TSIZE m_rightMargin;
    
    /**
     **********************************************************************
     *  Constructor: cWinRoundedRectangleWindow
     *
     *       Author: $author$
     *         Date: 12/30/2009
     **********************************************************************
     */
    cWinRoundedRectangleWindow
    (TSIZE cornerRadius,
     COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINSHAPEDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_cornerRadius(cornerRadius),
      
      m_topMargin(0),
      m_bottomMargin(0),
      m_leftMargin(0),
      m_rightMargin(0)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cWinRoundedRectangleWindow
     *
     *       Author: $author$
     *         Date: 12/30/2009
     **********************************************************************
     */
    cWinRoundedRectangleWindow
    (COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINSHAPEDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_cornerRadius(CWINROUNDEDRECTANGLEWINDOW_CORNER_RADIUS),
      
      m_topMargin(0),
      m_bottomMargin(0),
      m_leftMargin(0),
      m_rightMargin(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedRectangleWindow
     *
     *      Author: $author$
     *        Date: 12/30/2009
     **********************************************************************
     */
    virtual ~cWinRoundedRectangleWindow()
    {
    }
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetCornerRadius
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH SetCornerRadius
    (TSIZE toValue) 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_cornerRadius = toValue);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CornerRadius
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH CornerRadius() const 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_cornerRadius);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetTopMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH SetTopMargin
    (TSIZE toValue) 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_topMargin = toValue);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: TopMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH TopMargin() const 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_topMargin);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetBottomMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH SetBottomMargin
    (TSIZE toValue) 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_bottomMargin = toValue);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BottomMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH BottomMargin() const 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_bottomMargin);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetLeftMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH SetLeftMargin
    (TSIZE toValue) 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_leftMargin = toValue);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: LeftMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH LeftMargin() const 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_leftMargin);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetRightMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH SetRightMargin
    (TSIZE toValue) 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_rightMargin = toValue);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RightMargin
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual TLENGTH RightMargin() const 
#if defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH value = (m_rightMargin);
#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CWINROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateWindowRegion
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowRegion
    (RECT& rect) 
    {
        HRGN hRgn = NULL;
        
        if ((hRgn = CreateWindowRoundedRectangleRegion
            (rect, m_cornerRadius, m_topMargin, m_bottomMargin, 
             m_leftMargin, m_rightMargin)))
             
             OnAfterCreateWindowRoundedRectangleRegion
             (hRgn, rect, m_cornerRadius, m_topMargin, 
              m_bottomMargin, m_leftMargin, m_rightMargin);
        return hRgn;
    }
    /**
     **********************************************************************
     * Function: CreateWindowRoundedRectangleRegion
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowRoundedRectangleRegion
    (RECT& r, LONG cornerRadius, 
     LONG topMargin=0, LONG bottomMargin=0, 
     LONG leftMargin=0, LONG rightMargin=0) 
    {
        HRGN hRgn = NULL;
        eError error;
        
        hRgn = m_region.CreateRoundRectAttached
        (error, r.left+leftMargin,r.top+topMargin, 
         r.right-rightMargin+1,r.bottom-bottomMargin+1, 
         cornerRadius*2-1, cornerRadius*2-1);
        return hRgn;
    }
    /**
     **********************************************************************
     * Function: OnAfterCreateWindowRoundedRectangleRegion
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual HRGN OnAfterCreateWindowRoundedRectangleRegion
    (HRGN hRgn, RECT& r, LONG cornerRadius, 
     LONG topMargin=0, LONG bottomMargin=0, 
     LONG leftMargin=0, LONG rightMargin=0) 
    {
        return hRgn;
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
        {
            MoveWindow
            (hWnd, rect.left,rect.top, 
             width+m_leftMargin+m_rightMargin+m_cornerRadius*2,
             height+m_topMargin+m_bottomMargin+m_cornerRadius*2, bRepaint);
             
            if ((bRepaint))
            if ((GetClientRect(hWnd, &rect)))
                InvalidateRect(hWnd, &rect, bRepaint);
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
