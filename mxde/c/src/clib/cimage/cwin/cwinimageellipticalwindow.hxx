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
 *   File: cwinimageellipticalwindow.hxx
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGEELLIPTICALWINDOW_HXX) || defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGEELLIPTICALWINDOW_HXX) && !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY)
#define _CWINIMAGEELLIPTICALWINDOW_HXX
#endif /* !defined(_CWINIMAGEELLIPTICALWINDOW_HXX) && !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY)
#include "cwinellipticalwindow.hxx"
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
 *  Class: cWinImageEllipticalWindow
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageEllipticalWindow
: public cWinEllipticalWindow
{
public:
    typedef cWinEllipticalWindow cExtends;

    cWinRegionImageExtend m_regionImage;
    cWinRegionImageBrush m_regionBrush;
    
    /**
     **********************************************************************
     *  Constructor: cWinImageEllipticalWindow
     *
     *       Author: $author$
     *         Date: 12/2/2009
     **********************************************************************
     */
    cWinImageEllipticalWindow
    (TSIZE radiusWidth=CWINELLIPTICALWINDOW_RADIUS_WIDTH,
     TSIZE radiusHeight=CWINELLIPTICALWINDOW_RADIUS_HEIGHT,
     COLORREF bgColor=CWINELLIPTICALWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINELLIPTICALWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (radiusWidth, radiusHeight, bgColor, hBgBrush,
       windowClassNameChars, hInstance, attached, isCreated),
      m_regionBrush((cWinRegionImageBase&)(m_regionImage))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageEllipticalWindow
     *
     *      Author: $author$
     *        Date: 12/2/2009
     **********************************************************************
     */
    virtual ~cWinImageEllipticalWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateWindowEllipticalRegion
     *
     *    Author: $author$
     *      Date: 12/2/2009
     **********************************************************************
     */
    virtual HRGN CreateWindowEllipticalRegion
    (RECT& rect)
#if defined(CWINIMAGEELLIPTICALWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINIMAGEELLIPTICALWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
#if !defined(CWINIMAGEELLIPTICALWINDOW_MEMBER_FUNCS_IMPLEMENT)
        int w = (rect.right-rect.left);
        int h = (rect.bottom-rect.top);
        int wRadius = w/2;
        int hRadius = h/2;
        eError error;
        if (!(error = m_regionBrush.CreateRect(0,0, 1,1)))
        {
            if (!(error = m_regionImage.CreateRect
                (wRadius-1,hRadius-1, wRadius,hRadius)))
            {
                if (!(error = m_regionImage.FillEllipseRectangle
                    (m_regionBrush, rect.left,rect.top, w,h)))
                    hRgn = m_regionImage.Detach();
                else
                m_regionImage.Destroy();
            }
            m_regionBrush.Destroy(true);
        }
#else /* !defined(CWINIMAGEELLIPTICALWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGEELLIPTICALWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINIMAGEELLIPTICALWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEELLIPTICALWINDOW_HXX) || defined(CWINIMAGEELLIPTICALWINDOW_MEMBERS_ONLY) */
