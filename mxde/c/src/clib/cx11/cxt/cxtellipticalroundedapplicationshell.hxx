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
 *   File: cxtellipticalroundedapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 5/29/2010
 **********************************************************************
 */
#if !defined(_CXTELLIPTICALROUNDEDAPPLICATIONSHELL_HXX) || defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXTELLIPTICALROUNDEDAPPLICATIONSHELL_HXX) && !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXTELLIPTICALROUNDEDAPPLICATIONSHELL_HXX
#endif /* !defined(_CXTELLIPTICALROUNDEDAPPLICATIONSHELL_HXX) && !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cxtshapedapplicationshell.hxx"
#include "croundedrectangle.hxx"
#include "cxwindow.hxx"
#include "cxpixmap.hxx"
#include "cxgc.hxx"

#define CXTELLIPTICALROUNDEDAPPLICATIONSHELL_CORNER_RADIUS_WIDTH 24
#define CXTELLIPTICALROUNDEDAPPLICATIONSHELL_CORNER_RADIUS_HEIGHT 24
#define CXTELLIPTICALROUNDEDAPPLICATIONSHELL_EDGE_THICKNESS 4

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtEllipticalRoundedApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 5/29/2010
 **********************************************************************
 */
typedef cXtShapedApplicationShell
cXtEllipticalRoundedApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXtEllipticalRoundedApplicationShell
 *
 * Author: $author$           
 *   Date: 5/29/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtEllipticalRoundedApplicationShell
: /*virtual public cXtEllipticalRoundedApplicationShellImplement,
  */public cXtEllipticalRoundedApplicationShellExtend
{
public:
    /*typedef cXtEllipticalRoundedApplicationShellImplement cImplements;
    */typedef cXtEllipticalRoundedApplicationShellExtend cExtends;

    TSIZE m_cornerRadiusWidth;
    TSIZE m_cornerRadiusHeight;
    TSIZE m_edgeThickness;
    TSIZE m_topMargin;
    TSIZE m_bottomMargin;
    TSIZE m_leftMargin;
    TSIZE m_rightMargin;

    cEllipticalRoundedRectangle m_roundedRectangle;
    cFilledEllipticalRoundedRectangle m_filledRoundedRectangle;

    /**
     **********************************************************************
     *  Constructor: cXtEllipticalRoundedApplicationShell
     *
     *       Author: $author$           
     *         Date: 5/29/2010
     **********************************************************************
     */
    cXtEllipticalRoundedApplicationShell
    (cXDisplayInterface& display,
     TSIZE cornerRadiusWidth = CXTELLIPTICALROUNDEDAPPLICATIONSHELL_CORNER_RADIUS_WIDTH,
     TSIZE cornerRadiusHeight = CXTELLIPTICALROUNDEDAPPLICATIONSHELL_CORNER_RADIUS_HEIGHT,
     TSIZE edgeThickness = CXTELLIPTICALROUNDEDAPPLICATIONSHELL_EDGE_THICKNESS,
     const XtChar* name = CXTAPPLICATIONSHELL_NAME,
     const XtChar* className = CXTAPPLICATIONSHELL_CLASS_NAME,
     WidgetClass widgetClassAttached = CXTAPPLICATIONSHELL_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, name, className,
       widgetClassAttached, attached, isCreated),
      
      m_roundedRectangle(m_image),
      m_filledRoundedRectangle(m_image),

      m_cornerRadiusWidth(cornerRadiusWidth),
      m_cornerRadiusHeight(cornerRadiusHeight),
      m_edgeThickness(edgeThickness),
      m_topMargin(0),
      m_bottomMargin(0),
      m_leftMargin(0),
      m_rightMargin(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtEllipticalRoundedApplicationShell
     *
     *      Author: $author$           
     *        Date: 5/29/2010
     **********************************************************************
     */
    virtual ~cXtEllipticalRoundedApplicationShell()
    {
    }
#else /* !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnBeforeXtShapeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnBeforeXtShapeRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xPixmapGC, Pixmap xPixmap,
     Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAfterXtShapeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnAfterXtShapeRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xPixmapGC, Pixmap xPixmap,
     Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnXtShapeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnXtShapeRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xPixmapGC, Pixmap xPixmap,
     Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;

        XSetForeground
        (&xDisplay, xPixmapGC, m_bgRegionBrush.Attached());
        XFillRectangle
        (&xDisplay, xPixmap, xPixmapGC, 0,0, rect.width,rect.height);

        if (!(error = OnBeforeXtShapeRoundedRectangle
            (cx,cy, cWidth,cHeight, 
             rect,xPixmapGC,xPixmap, 
             xWidget, xWindow,xDisplay)))
        {
            GC xGCAttached = m_imageGC.Attached();

            if ((m_imageGC.Attach(xPixmapGC)))
            {
                Drawable xGCDrawable = m_imageGC.SelectDrawable(xPixmap);

                m_filledRoundedRectangle.PlotEllipticalRoundedRectangle
                (m_fgRegionBrush, cx,cy, cWidth,cHeight, 
                 m_cornerRadiusWidth,m_cornerRadiusHeight);

                m_imageGC.SelectDrawable(xGCDrawable);
            }
            m_imageGC.Attach(xGCAttached);

            if (!(error = OnAfterXtShapeRoundedRectangle
                (cx,cy, cWidth,cHeight, 
                 rect,xPixmapGC,xPixmap,
                 xWidget, xWindow,xDisplay)))
            {
                XShapeCombineMask
                (&xDisplay, xWindow, 
                 ShapeBounding, 0,0, xPixmap, ShapeSet);
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeforeXtPaintRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnBeforeXtPaintRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xGC, Widget xWidget, 
     Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAfterXtPaintRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnAfterXtPaintRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xGC, Widget xWidget, 
     Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnXtPaintRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnXtPaintRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xGC, Widget xWidget, 
     Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;

        cXImageSolidBrush m_edgeBrush
        (m_fgBrush, m_edgeThickness,m_edgeThickness);

        if (!(error = OnBeforeXtPaintRoundedRectangle
            (cx,cy, cWidth,cHeight, rect,xGC, 
             xWidget, xWindow,xDisplay)))
        {
            m_filledRoundedRectangle.PlotEllipticalRoundedRectangle
            (m_bgBrush, cx,cy, cWidth,cHeight, 
             m_cornerRadiusWidth,m_cornerRadiusHeight);

            m_roundedRectangle.PlotEllipticalRoundedRectangle
            (m_edgeBrush, cx,cy, cWidth,cHeight, 
             m_cornerRadiusWidth,m_cornerRadiusHeight, 
             m_edgeThickness);

            error = OnAfterXtPaintRoundedRectangle
            (cx,cy, cWidth,cHeight, rect,xGC, 
             xWidget, xWindow,xDisplay);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeforeXtSizeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/18/2010
     **********************************************************************
     */
    virtual eError OnBeforeXtSizeRoundedRectangle
    (tInt& cx, tInt& cy, tSize& cWidth, tSize& cHeight,
     XRectangle& rect, Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAfterXtSizeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/18/2010
     **********************************************************************
     */
    virtual eError OnAfterXtSizeRoundedRectangle
    (tInt& cx, tInt& cy, tSize& cWidth, tSize& cHeight,
     XRectangle& rect, Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnXtSizeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/10/2010
     **********************************************************************
     */
    virtual eError OnXtSizeRoundedRectangle
    (tInt& cx, tInt& cy, tSize& cWidth, tSize& cHeight,
     XRectangle& rect, Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;

        if ((error = OnBeforeXtSizeRoundedRectangle
            (cx,cy, cWidth,cHeight, rect, 
             xWidget, xWindow, xDisplay)))
            return error;

        cx = m_cornerRadiusWidth+m_leftMargin-1;
        cy = m_cornerRadiusHeight+m_topMargin-1;
        cWidth = rect.width-m_leftMargin-m_rightMargin-(m_cornerRadiusWidth*2)+2;
        cHeight = rect.height-m_topMargin-m_bottomMargin-(m_cornerRadiusHeight*2)+2;

        error = OnAfterXtSizeRoundedRectangle
        (cx,cy, cWidth,cHeight, rect, 
         xWidget, xWindow, xDisplay);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_Expose_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/30/2010
     **********************************************************************
     */
    virtual eError OnHandle_Expose_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        XRectangle rect;
        Display* xDisplay;
        Window xWindow;
        GC xGC;

        if (!(xWidget != (Attached())))
        if (None != (xWindow = WindowAttached()))
        if ((xDisplay = m_display.Attached()))
        {
            cXWindow window(m_display, xWindow);

            if (!(error2 = window.GetWindowRectangle(rect)))
            {
                if ((xGC = GetGCAttached()))
                {

                    tInt cx = m_cornerRadiusWidth-1;
                    tInt cy = m_cornerRadiusHeight-1;
                    tSize cWidth = rect.width-(m_cornerRadiusWidth*2)+2;
                    tSize cHeight = rect.height-(m_cornerRadiusHeight*2)+2;

                    if (!(error2 = OnXtSizeRoundedRectangle
                        (cx,cy, cWidth,cHeight, rect, 
                         xWidget, xWindow, *xDisplay)))
                        OnXtPaintRoundedRectangle
                        (cx,cy, cWidth,cHeight, rect,xGC, 
                         xWidget, xWindow, *xDisplay);
                    /*
                    cXImageSolidBrush m_edgeBrush
                    (m_fgBrush, m_edgeThickness,m_edgeThickness);

                    m_filledRoundedRectangle.PlotEllipticalRoundedRectangle
                    (m_bgBrush, cx,cy, cWidth,cHeight, 
                     m_cornerRadiusWidth,m_cornerRadiusHeight);

                    m_roundedRectangle.PlotEllipticalRoundedRectangle
                    (m_edgeBrush, cx,cy, cWidth,cHeight, 
                     m_cornerRadiusWidth,m_cornerRadiusHeight, 
                     m_edgeThickness);
                    */
                    FreeGCAttached(xGC);
                }
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_ConfigureNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 6/1/2010
     **********************************************************************
     */
    virtual eError OnHandle_ConfigureNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        XRectangle rect;
        Display* xDisplay;
        Window xWindow;
        Pixmap xPixmap;
        GC xPixmapGC;
        GC xGC;

        if (!(xWidget != (Attached())))
        if (None != (xWindow = WindowAttached()))
        if ((xDisplay = m_display.Attached()))
        {
            cXWindow window(m_display, xWindow);

            if (!(error2 = window.GetWindowRectangle(rect)))
            {
                if ((xGC = GetGCAttached()))
                {
                    cXPixmap pixmap(m_display);

                    if (None != (xPixmap = pixmap.CreateAttached
                        (error2, xWindow, rect.width, rect.height, 1)))
                    {
                        cXGC pixmapGC(m_display);
                        
                        if ((xPixmapGC = pixmapGC.CreateAttached
                            (error2, xPixmap)))
                        {
                            tInt cx = m_cornerRadiusWidth-1;
                            tInt cy = m_cornerRadiusHeight-1;
                            tSize cWidth = rect.width-(m_cornerRadiusWidth*2)+2;
                            tSize cHeight = rect.height-(m_cornerRadiusHeight*2)+2;

                            if (!(error2 = OnXtSizeRoundedRectangle
                                (cx,cy, cWidth,cHeight, rect, 
                                 xWidget, xWindow, *xDisplay)))
                                OnXtShapeRoundedRectangle
                                (cx,cy, cWidth,cHeight, 
                                 rect,xPixmapGC,xPixmap,
                                 xWidget, xWindow, *xDisplay);
                            /*
                            GC xGCAttached = m_imageGC.Attached();

                            XSetForeground
                            (xDisplay, xPixmapGC, m_bgRegionBrush.Attached());
                            XFillRectangle
                            (xDisplay, xPixmap, xPixmapGC, 0,0, rect.width,rect.height);

                            if ((m_imageGC.Attach(xPixmapGC)))
                            {
                                Drawable xGCDrawable = m_imageGC.SelectDrawable(xPixmap);

                                m_filledRoundedRectangle.PlotEllipticalRoundedRectangle
                                (m_fgRegionBrush, cx,cy, cWidth,cHeight, 
                                 m_cornerRadiusWidth,m_cornerRadiusHeight);

                                m_imageGC.SelectDrawable(xGCDrawable);
                            }
                            m_imageGC.Attach(xGCAttached);

                            XShapeCombineMask
                            (xDisplay, xWindow, 
                             ShapeBounding, 0,0, xPixmap, ShapeSet);
                            */
                        }
                    }
                    FreeGCAttached(xGC);
                }
            }
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTELLIPTICALROUNDEDAPPLICATIONSHELL_HXX) || defined(CXTELLIPTICALROUNDEDAPPLICATIONSHELL_MEMBERS_ONLY) */
