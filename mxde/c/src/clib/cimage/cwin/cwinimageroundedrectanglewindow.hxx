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
 *   File: cwinimageroundedrectanglewindow.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGEROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGEROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#define _CWINIMAGEROUNDEDRECTANGLEWINDOW_HXX
#endif /* !defined(_CWINIMAGEROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#include "cwinroundedrectanglewindow.hxx"
#include "cwinregionimage.hxx"
#include "cwinregionimageextend.hxx"
#include "cwinregionimagebrush.hxx"
#include "cwinregionimagebase.hxx"
#include "cwinregion.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinImageRoundedRectangleWindowExtend
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cWinRoundedRectangleWindow
cWinImageRoundedRectangleWindowExtend;
/**
 **********************************************************************
 *  Class: cWinImageRoundedRectangleWindow
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageRoundedRectangleWindow
: public cWinImageRoundedRectangleWindowExtend
{
public:
    typedef cWinImageRoundedRectangleWindowExtend cExtends;
    
    cWinRegionImageExtend m_regionImage;
    cWinRegionImageBrush m_regionBrush;
    
    /**
     **********************************************************************
     *  Constructor: cWinImageRoundedRectangleWindow
     *
     *       Author: $author$
     *         Date: 12/30/2009
     **********************************************************************
     */
    cWinImageRoundedRectangleWindow
    (TSIZE cornerRadius=CWINROUNDEDRECTANGLEWINDOW_CORNER_RADIUS,
     COLORREF bgColor=CWINSHAPEDWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINSHAPEDWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (cornerRadius, 
       bgColor, hBgBrush, 
       windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_regionBrush((cWinRegionImageBase&)(m_regionImage))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageRoundedRectangleWindow
     *
     *      Author: $author$
     *        Date: 12/30/2009
     **********************************************************************
     */
    virtual ~cWinImageRoundedRectangleWindow()
    {
    }
#else /* !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateWindowRoundedRectangleRegion
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowRoundedRectangleRegion
    (RECT& rect, LONG cornerRadius, 
     LONG topMargin=0, LONG bottomMargin=0, 
     LONG leftMargin=0, LONG rightMargin=0) 
    {
        int w = (rect.right-rect.left);
        int h = (rect.bottom-rect.top);
        HRGN hRgn = NULL;
        eError error;
        
        if (!(error = m_regionBrush.CreateRect
            (rect.left+leftMargin,
             rect.top+topMargin+cornerRadius, 
             rect.right-rightMargin,
             rect.bottom-bottomMargin-cornerRadius)))
        {
            if (!(error = m_region.CreateRect
                (rect.left+leftMargin+cornerRadius, 
                 rect.top+topMargin, 
                 rect.right-rightMargin-cornerRadius,
                 rect.bottom-bottomMargin)))
            {
                if ((m_regionImage.Attach(m_region.Attached())))
                if (!(error = m_regionImage.Combine(m_regionBrush)))
                if (!(error = m_regionBrush.SetRect(0,0, 1,1)))
                
                if (!(error = m_regionImage.FillCircle
                    (m_regionBrush, 
                     rect.left+leftMargin+cornerRadius-1,
                     rect.top+topMargin+cornerRadius-1, 
                     cornerRadius, e_QUADRANT_4)))
                     
                if (!(error = m_regionImage.FillCircle
                    (m_regionBrush, 
                     rect.right-rightMargin-cornerRadius,
                     rect.top+topMargin+cornerRadius-1, 
                     cornerRadius, e_QUADRANT_1)))
                     
                if (!(error = m_regionImage.FillCircle
                    (m_regionBrush, rect.right-cornerRadius,rect.bottom-cornerRadius, 
                     cornerRadius, e_QUADRANT_2)))
                     
                if (!(error = m_regionImage.FillCircle
                    (m_regionBrush, 
                     rect.left+leftMargin+cornerRadius-1,
                     rect.bottom-bottomMargin-cornerRadius, 
                     cornerRadius, e_QUADRANT_3)))
                     
                    hRgn = m_regionImage.Attached();
            }
            m_regionBrush.Destroy(true);
        }
        return hRgn;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINIMAGEROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
