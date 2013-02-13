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
 *   File: cxttestmain.hxx
 *
 * Author: $author$           
 *   Date: 5/20/2010
 **********************************************************************
 */
#if !defined(_CXTTESTMAIN_HXX) || defined(CXTTESTMAIN_MEMBERS_ONLY)
#if !defined(_CXTTESTMAIN_HXX) && !defined(CXTTESTMAIN_MEMBERS_ONLY)
#define _CXTTESTMAIN_HXX
#endif /* !defined(_CXTTESTMAIN_HXX) && !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#define DEFAULT_CXTTESTMAIN_PIXMAP_FILENAME "csdiag.xpm"

#if !defined(CXTTESTMAIN_MEMBERS_ONLY)
#include "cxtshapedmain.hxx"
#include "cmidpointellipse.hxx"
#include "croundedrectangle.hxx"
#include "cxttestapplicationshell.hxx"
#include "cxtellipticalroundedapplicationshell.hxx"
#include "cxpm.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTestMainExtend
 *
 *  Author: $author$           
 *    Date: 5/20/2010
 **********************************************************************
 */
typedef cXtShapedMain
cXtTestMainExtend;
/**
 **********************************************************************
 *  Class: cXtTestMain
 *
 * Author: $author$           
 *   Date: 5/20/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtTestMain
: /*virtual public cXtTestMainImplement,
  */public cXtTestMainExtend
{
public:
    /*typedef cXtTestMainImplement cImplements;
    */typedef cXtTestMainExtend cExtends;

    cMidpointEllipse m_midpointEllipse;
    cFilledMidpointEllipse m_filledMidpointEllipse;

    cEllipticalRoundedRectangle m_roundedRectangle;
    cFilledEllipticalRoundedRectangle m_filledRoundedRectangle;
    unsigned m_cornerRadius;
    unsigned m_edgeThickness;

    cXtTestApplicationShell m_shapedShellWidget;

    const char* m_pixmapFileName;
    cXPixmap m_pixmapMask;
    cXPixmap m_pixmap;

    bool m_addWMDecorations;

    /**
     **********************************************************************
     *  Constructor: cXtTestMain
     *
     *       Author: $author$           
     *         Date: 5/20/2010
     **********************************************************************
     */
    cXtTestMain
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME,
     const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends
      (xtNameChars, xtClassNameChars, 
       displayNameChars, displayScreen),

      m_midpointEllipse(m_image),
      m_filledMidpointEllipse(m_image),

      m_roundedRectangle(m_image),
      m_filledRoundedRectangle(m_image),
      m_cornerRadius(24),
      m_edgeThickness(4),

      m_shapedShellWidget
      (m_display, m_cornerRadius,m_cornerRadius, m_edgeThickness),

      m_pixmapFileName(DEFAULT_CXTTESTMAIN_PIXMAP_FILENAME),
      m_pixmapMask(m_display),
      m_pixmap(m_display),

      m_addWMDecorations(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtTestMain
     *
     *      Author: $author$           
     *        Date: 5/20/2010
     **********************************************************************
     */
    virtual ~cXtTestMain()
    {
    }
#else /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXTTESTMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnHandle_ButtonPress_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/25/2010
     **********************************************************************
     */
    virtual eError OnHandle_ButtonPress_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        DBI(("()...\n"));
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_ButtonRelease_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/25/2010
     **********************************************************************
     */
    virtual eError OnHandle_ButtonRelease_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        CARD32 wmDecorations = (m_addWMDecorations)
        ?(MWM_DECOR_TITLE):(MWM_DECOR_NONE);

        DBI(("()...\n"));

        eError error2;
        Display* xDisplay;
        Window xWindow;

        if (xWidget == (m_xShellWidget))
        if (None != (xWindow = XtWindow(xWidget)))
        if ((xDisplay = m_display.Attached()))
        {
            XUnmapWindow(xDisplay, xWindow);
            m_mwmHints.ChangeHints
            (*xDisplay, xWindow, 
             MWM_HINTS_DECORATIONS, 0, wmDecorations);
            XMapWindow(xDisplay, xWindow);
            m_addWMDecorations = !m_addWMDecorations;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_Expose_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/25/2010
     **********************************************************************
     */
    virtual eError OnHandle_Expose_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        Display* xDisplay;
        Window xWindow;

        if (xWidget == (m_shapedShellWidget.Attached()))
        {
            DBI(("()\n m_shapedShellWidget.OnHandle_Expose_XtEvent()...\n"));

            if (!(error = m_shapedShellWidget.OnHandle_Expose_XtEvent
                (xWidget, xPointer, xEvent,continueToDispatch )))

            if (None != (xWindow = m_shapedShellWidget.WindowAttached()))
            {
                DBT(("()\n m_pixmap.CopyArea()...\n"));
                m_pixmap.CopyArea
                ((Drawable)(xWindow), m_pixmapMask,
                 (int)(m_shapedShellWidget.m_cornerRadiusWidth), 
                 (int)(m_shapedShellWidget.m_cornerRadiusHeight));
            }
            return error;
        }

        if (xWidget == (m_xShellWidget))
        if (None != (xWindow = XtWindow(xWidget)))
        if ((xDisplay = m_display.Attached()))
        {
            cXWindow window(m_display, xWindow);
            XRectangle rect;

            if (!(error2 = window.GetWindowRectangle(rect)))
            {
                int width = rect.width/2;
                int height = rect.height/2;
                GC xGC;

                if (!(xGC = m_imageGC.Attached()))
                {
                    DBT(("() m_imageGC.Create(xWindow)\n"));
                    m_imageGC.Create(xWindow);
                }

                if ((xGC = m_imageGC.Attached()))
                {
                    /*
                    m_filledMidpointEllipse.PlotEllipse
                    (m_fgBrush, width,height, width,height, 
                     e_CIRCLE_QUADRANT_1 | e_CIRCLE_QUADRANT_3);

                    m_midpointEllipse.PlotEllipse
                    (m_fgBrush, width,height, width,height, 
                     e_CIRCLE_QUADRANT_2 | e_CIRCLE_QUADRANT_4);
                    */

                    cXImageSolidBrush m_edgeBrush
                    (m_fgBrush, m_edgeThickness,m_edgeThickness);

                    m_filledRoundedRectangle.PlotEllipticalRoundedRectangle
                    (m_bgBrush, m_cornerRadius-1,m_cornerRadius-1, 
                     rect.width-(m_cornerRadius*2)+2,rect.height-(m_cornerRadius*2)+2, 
                     m_cornerRadius,m_cornerRadius);

                    m_roundedRectangle.PlotEllipticalRoundedRectangle
                    (m_edgeBrush, m_cornerRadius-1,m_cornerRadius-1, 
                     rect.width-(m_cornerRadius*2)+2,rect.height-(m_cornerRadius*2)+2, 
                     m_cornerRadius,m_cornerRadius, m_edgeThickness);
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
     *     Date: 5/24/2010
     **********************************************************************
     */
    virtual eError OnHandle_ConfigureNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        Display* xDisplay;
        Window xWindow;

        DBI(("()...\n"));

        if (xWidget == (m_shapedShellWidget.Attached()))
        {
            DBI(("()\n m_shapedShellWidget.OnHandle_ConfigureNotify_XtEvent()...\n"));
            error = m_shapedShellWidget.OnHandle_ConfigureNotify_XtEvent
            (xWidget, xPointer, xEvent,continueToDispatch );
            return error;
        }

        if (xWidget == (m_xShellWidget))
        if (None != (xWindow = XtWindow(xWidget)))
        if ((xDisplay = m_display.Attached()))
        {
            cXWindow window(m_display, xWindow);
            XRectangle rect;

            if (!(error2 = window.GetWindowRectangle(rect)))
            {
                int width = rect.width/2;
                int height = rect.height/2;
                Pixmap xPixmap;
                XGCValues xGCValues;
                GC xGC;

                DBT(("() width = %d, height = %d\n", width, height));

                if (!(xGC = m_imageGC.Attached()))
                {
                    DBT(("() m_imageGC.Create(xWindow)\n"));
                    m_imageGC.Create(xWindow);
                }

                if ((xGC = m_imageGC.Attached()))

                if (None != (xPixmap = XCreatePixmap
                    (xDisplay, xWindow, rect.width, rect.height, 1)))
                {
                    if ((xGC = XCreateGC(xDisplay, xPixmap, 0, &xGCValues)))
                    {
                        Drawable xGCDrawable = m_imageGC.SelectDrawable(xPixmap);
                        GC xGCAttached = m_imageGC.Attached();

                        XSetForeground(xDisplay, xGC, m_bgRegionBrush.Attached());
                        XFillRectangle(xDisplay, xPixmap, xGC, 0,0, rect.width,rect.height);

                        m_imageGC.Attach(xGC);

                        /*
                        m_filledMidpointEllipse.PlotEllipse
                        (m_fgRegionBrush, width,height, width,height);
                        */

                        m_filledRoundedRectangle.PlotEllipticalRoundedRectangle
                        (m_fgRegionBrush, m_cornerRadius-1,m_cornerRadius-1, 
                         rect.width-(m_cornerRadius*2)+2,rect.height-(m_cornerRadius*2)+2, 
                         m_cornerRadius,m_cornerRadius);

                        m_imageGC.Attach(xGCAttached);
                        m_imageGC.SelectDrawable(xGCDrawable);

                        XShapeCombineMask
                        (xDisplay, xWindow, 
                         ShapeBounding, 0,0, xPixmap, ShapeSet);
                        /*
                        rect.x = 0;
                        rect.y = 0;

                        XShapeCombineRectangles
                        (xDisplay, xWindow, ShapeBounding, 
                         0,0, &rect, 1, ShapeSet, Unsorted);
                        */
                        XFreeGC(xDisplay, xGC);
                    }
                    XFreePixmap(xDisplay, xPixmap);
                }
            }
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: BeforeCreateShapedApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError BeforeCreateShapedApplicationShell
    (cXImageSolidBrush& fgRegionBrush,
     cXImageSolidBrush& bgRegionBrush,
     cXImageSolidBrush& fgBrush,
     cXImageSolidBrush& bgBrush,
     cXColormap& colormap,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;

        m_shapedShellWidget.BeforeCreateShapedApplicationShell
        (fgRegionBrush, bgRegionBrush, fgBrush, bgBrush,
         colormap,display,rootXWindow,argc,argv,env);

        m_shapedShellWidget.m_fgRegionBrush.Attach(fgRegionBrush.Attached());
        m_shapedShellWidget.m_bgRegionBrush.Attach(bgRegionBrush.Attached());

        m_shapedShellWidget.m_fgBrush.Attach(fgBrush.Attached());
        m_shapedShellWidget.m_bgBrush.Attach(bgBrush.Attached());

        return error;

        if ((m_pixmapFileName))
        {
            cXColor color(display, colormap);
            const char* colorName;
            cXpmImage xpmImage;
            cXpmInfo xpmInfo;
            cXpm xpm;

            if (!(xpm.ReadFileToXpmImage
                (m_pixmapFileName, xpmImage, xpmInfo)))
            {
                DBI
                (("() xpm.width = %u, xpm.height = %u\n", 
                  xpmImage.m_xpmImage.width, xpmImage.m_xpmImage.height));

                for (unsigned i=0; i<xpmImage.m_xpmImage.ncolors; i++)
                {
                    XpmColor& xpmColor = xpmImage.m_xpmImage.colorTable[i];
                    DBI(("() color[%u].string = \"%s\"\n", i, xpmColor.string));
                    DBI(("() color[%u].c_color = \"%s\"\n", i, xpmColor.c_color));

                    if ((colorName = xpmColor.c_color))
                    if ((color.Lookup(colorName)))
                        DBI(("()\ncolor \"%s\" undefined\n", xpmColor.c_color));
                    else
                    {
                        DBI(("()\n"
                             "color[%u].c_color.red = 0x%x\n"
                             "color[%u].c_color.green = 0x%x\n"
                             "color[%u].c_color.blue = 0x%x\n",
                             i,color.m_xColor.red, 
                             i,color.m_xColor.green, 
                             i,color.m_xColor.blue));
                    }
                }
                xpmImage.Destroy();
                xpmInfo.Destroy();
            }
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: AfterCreateShapedApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError AfterCreateShapedApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXImageSolidBrush& fgRegionBrush,
     cXImageSolidBrush& bgRegionBrush,
     cXImageSolidBrush& fgBrush,
     cXImageSolidBrush& bgBrush,
     cXColormap& colormap,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        cXtApplicationShellInterface& shapedShellWidget 
        = (cXtApplicationShellInterface&)(m_shapedShellWidget);
        eError error = e_ERROR_NONE;
        Window xWindow;

        if (&shellWidget != &shapedShellWidget)
            shapedShellWidget.Attach(shellWidget.Attached());

        m_shapedShellWidget.AfterCreateShapedApplicationShell
        (shellWidget, fgRegionBrush, bgRegionBrush, fgBrush, bgBrush,
         colormap,display,rootXWindow,argc,argv,env);

        return error;

        if (None != (xWindow = rootXWindow))
        if ((m_pixmap.CreateFromFile
            (m_pixmapMask, xWindow, m_pixmapFileName)))
            DBE(("()\n failed on m_pixmap.CreateFromFile(%s)\n", DEFAULT_CXTTESTMAIN_PIXMAP_FILENAME));
        return error;
    }
    /**
     **********************************************************************
     *  Function: AfterRealizeApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/24/2010
     **********************************************************************
     */
    virtual eError AfterRealizeApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     *  Function: MainEventHandlerMask
     *
     *    Author: $author$           
     *      Date: 5/25/2010
     **********************************************************************
     */
    virtual EventMask MainEventHandlerMask() const
    {
        EventMask xEventMask 
        = ButtonPressMask | ButtonReleaseMask 
        | cExtends::MainEventHandlerMask();
        DBI(("()...\n"));
        return xEventMask;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTTESTMAIN_HXX) || defined(CXTTESTMAIN_MEMBERS_ONLY) */
