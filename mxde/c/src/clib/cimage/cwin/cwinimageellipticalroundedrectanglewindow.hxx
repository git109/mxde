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
 *   File: cwinimageellipticalroundedrectanglewindow.hxx
 *
 * Author: $author$
 *   Date: 11/28/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#define _CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_HXX
#endif /* !defined(_CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) && !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
#include "cwinellipticalroundedrectanglewindow.hxx"
#include "cwinregionimage.hxx"
#include "cwinregionimageextend.hxx"
#include "cwinregionimagebrush.hxx"
#include "cwinregionimagebase.hxx"
#include "cwinregion.hxx"

#define CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW__WINDOW_CLASSNAME \
    "cWinImageEllipticalRoundedRectangleWindow"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinImageEllipticalRoundedRectangleWindow
 *
 * Author: $author$
 *   Date: 11/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageEllipticalRoundedRectangleWindow
: public cWinEllipticalRoundedRectangleWindow
{
public:
    typedef cWinEllipticalRoundedRectangleWindow cExtends;
    
    cWinRegionImageExtend m_regionImage;
    cWinRegionImageBrush m_regionBrush;
    
    /**
     **********************************************************************
     *  Constructor: cWinImageEllipticalRoundedRectangleWindow
     *
     *       Author: $author$
     *         Date: 11/28/2009
     **********************************************************************
     */
    cWinImageEllipticalRoundedRectangleWindow
    (TSIZE cornerRadiusWidth=CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_WIDTH,
     TSIZE cornerRadiusHeight=CWINELLIPTICALROUNDEDRECTANGLEWINDOW_CORNER_RADIUS_HEIGHT,
     COLORREF bgColor=CWINELLIPTICALROUNDEDRECTANGLEWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW__WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (cornerRadiusWidth, cornerRadiusHeight, 
       bgColor, hBgBrush, windowClassNameChars,
       hInstance, attached, isCreated),
      m_regionBrush((cWinRegionImageBase&)(m_regionImage))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageEllipticalRoundedRectangleWindow
     *
     *      Author: $author$
     *        Date: 11/28/2009
     **********************************************************************
     */
    virtual ~cWinImageEllipticalRoundedRectangleWindow()
    {
    }
#else /* !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateWindowEllipticalRoundedRegion
     *
     *    Author: $author$
     *      Date: 11/28/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowEllipticalRoundedRegion
    (RECT& rect,
     LONG radiusWidth,
     LONG radiusHeight)
#if defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
#if !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT)
        int w = (rect.right-rect.left);
        int h = (rect.bottom-rect.top);
        eError error;
        if (!(error = m_regionBrush.CreateRect
            (rect.left,rect.top+radiusHeight-1, 
             rect.left+radiusWidth,rect.bottom-radiusHeight+1)))
        {
            if (!(error = m_regionImage.CreateRect
                (rect.left+radiusWidth-1,rect.top, 
                 rect.right-radiusWidth+1,rect.bottom)))
            {
                if (!(error = m_regionImage.Combine(m_regionBrush)))
                if (!(error = m_regionBrush.SetRect
                    (rect.right-radiusWidth-1,rect.top+radiusHeight-1,
                     rect.right,rect.bottom-radiusHeight+1)))
                if (!(error = m_regionImage.Combine(m_regionBrush)))
                if (!(error = m_regionBrush.SetRect(0,0, 1,1)))
                if (!(error = m_regionImage.FillEllipse
                    (m_regionBrush, rect.left+radiusWidth-1,rect.top+radiusWidth-1, 
                     radiusWidth,radiusHeight, e_QUADRANT_4)))
                if (!(error = m_regionImage.FillEllipse
                    (m_regionBrush, rect.right-radiusWidth+1,rect.top+radiusWidth-1, 
                     radiusWidth,radiusHeight, e_QUADRANT_1)))
                if (!(error = m_regionImage.FillEllipse
                    (m_regionBrush, rect.right-radiusWidth+1,rect.bottom-radiusWidth+1, 
                     radiusWidth,radiusHeight, e_QUADRANT_2)))
                if (!(error = m_regionImage.FillEllipse
                    (m_regionBrush, rect.left+radiusWidth-1,rect.bottom-radiusWidth+1, 
                     radiusWidth,radiusHeight, e_QUADRANT_3)))
                    hRgn = m_regionImage.Detach();
                    
                if (!hRgn)
                    m_regionImage.Destroy();
            }
            m_regionBrush.Destroy(true);
        }
#else /* !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_HXX) || defined(CWINIMAGEELLIPTICALROUNDEDRECTANGLEWINDOW_MEMBERS_ONLY) */
