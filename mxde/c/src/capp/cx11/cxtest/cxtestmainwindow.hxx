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
 *   File: cxtestmainwindow.hxx
 *
 * Author: $author$           
 *   Date: 7/9/2009
 **********************************************************************
 */
#if !defined(_CXTESTMAINWINDOW_HXX) || defined(CXTESTMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CXTESTMAINWINDOW_HXX) && !defined(CXTESTMAINWINDOW_MEMBERS_ONLY)
#define _CXTESTMAINWINDOW_HXX
#endif /* !defined(_CXTESTMAINWINDOW_HXX) && !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CXTESTMAINWINDOW_MEMBERS_ONLY)
#include "cxwindow.hxx"
#include "cxmwmhintsinterface.hxx"
#include "cximagesolidbrush.hxx"
#include "cximagebase.hxx"
#include "cxcolor.hxx"
#include "cxcolormap.hxx"
#include "cxtextproperty.hxx"
#include "cmidpointellipse.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXTestMainWindow
 *
 * Author: $author$           
 *   Date: 7/9/2009
 **********************************************************************
 */
class cXTestMainWindow
: public cXWindow
{
public:
    typedef cXWindow cExtends;

    cXColormap m_colormap;
    cXColor m_blackColor;
    cXColor m_whiteColor;
    cXColor m_foregroundColor;

    cXImageBase m_image;
    cXImageSolidBrush m_blackBrush;
    cXImageSolidBrush m_whiteBrush;
    cXImageSolidBrush m_foregroundBrush;

    cMidpointEllipse m_midpointEllipse;
    cFilledMidpointEllipse m_filledMidpointEllipse;

    cXMwmHintsInterface& m_mwmHints;
    bool m_addWMDecorations;

    /**
     **********************************************************************
     *  Constructor: cXTestMainWindow
     *
     *       Author: $author$           
     *         Date: 7/9/2009
     **********************************************************************
     */
    cXTestMainWindow
    (cXMwmHintsInterface& mwmHints,
     cXDisplayInterface& display) 
    : cExtends(display),

      m_colormap(display),
      m_blackColor(display, m_colormap),
      m_whiteColor(display, m_colormap),
      m_foregroundColor(display, m_colormap),

      m_image(cExtends::m_gc),
      m_blackBrush(m_image),
      m_whiteBrush(m_image),
      m_foregroundBrush(m_image),

      m_midpointEllipse(m_image),
      m_filledMidpointEllipse(m_image),

      m_mwmHints(mwmHints),
      m_addWMDecorations(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXTestMainWindow
     *
     *      Author: $author$           
     *        Date: 7/9/2009
     **********************************************************************
     */
    virtual ~cXTestMainWindow()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: ChangeWMDecorations
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError ChangeWMDecorations
    (cXMwmHintsInterface& mwmHints,
     CARD32 decorations)
#if defined(CXMAINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMAINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMAINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = ChangeWMHints
        (mwmHints, MWM_HINTS_DECORATIONS, 0, decorations);
#else /* !defined(CXMAINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMAINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAINWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ChangeWMHints
     *
     *    Author: $author$           
     *      Date: 6/28/2010
     **********************************************************************
     */
    virtual eError ChangeWMHints
    (cXMwmHintsInterface& mwmHints,
     CARD32 flags = 0, CARD32 functions = 0, 
     CARD32 decorations = 0, INT32 inputMode = 0)
#if defined(CXMAINWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMAINWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMAINWINDOW_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Window xWindow;
        Display* xDisplay;
        
        if (None != (xWindow = Attached()))
        if ((xDisplay = DisplayAttached()))
            error = mwmHints.ChangeHints
            (*xDisplay, xWindow, flags, 
             functions, decorations, inputMode);

#else /* !defined(CXMAINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMAINWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAINWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTESTMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnButtonPressXEvent
     *
     *   Author: $author$           
     *     Date: 6/29/2010
     **********************************************************************
     */
    virtual eError OnButtonPressXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        DBI(("()...\n"));
        return error;
    }
    /**
     **********************************************************************
     * Function: OnButtonReleaseXEvent
     *
     *   Author: $author$           
     *     Date: 6/29/2010
     **********************************************************************
     */
    virtual eError OnButtonReleaseXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        CARD32 wmDecorations = (m_addWMDecorations)
        ?(MWM_DECOR_TITLE):(MWM_DECOR_NONE);

        DBI(("()...\n"));

        if (!(ChangeWMDecorations(m_mwmHints, wmDecorations)))
        {
            Unmap();
            Map();
            m_addWMDecorations = !m_addWMDecorations;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: BeforeOpen
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual eError BeforeOpen
    (cXDisplayInterface& display,
     Window parentXWindow) 
    {
        eError error = e_ERROR_NONE;
        if (None != (m_colormap.AttachDefault()))
        if (!(error = m_foregroundColor.AllocateBYTE(255, 0, 0)))
        {
            m_blackBrush.Attach(0);
            m_whiteBrush.Attach(1);
            m_foregroundBrush.Attach(m_foregroundColor.Attached());
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: AfterClose
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual eError AfterClose
    (cXDisplayInterface& display,
     Window parentXWindow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEnterNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 4/17/2010
     **********************************************************************
     */
    virtual eError OnEnterNotifyXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        Display* xDisplay;
        Window xWindow;

        DBI(("() \n"));

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow = Attached()))
        {
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLeaveNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 4/17/2010
     **********************************************************************
     */
    virtual eError OnLeaveNotifyXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        Display* xDisplay;
        Window xWindow;

        DBI(("() \n"));

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow = Attached()))
        {
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnConfigureNotifyXEvent
     *
     *   Author: $author$           
     *     Date: 7/9/2009
     **********************************************************************
     */
    virtual eError OnConfigureNotifyXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        int width = 50;
        int height = 25;
        XRectangle r;
        Display* xDisplay;
        Window xWindow;
        Pixmap xPixmap;
        GC xGC;
        XGCValues xGCValues;

        DBI(("() \n"));

        if (!(GetWindowRectangle(r)))
        {
            width = (r.width/2);
            height = (r.height/2);
        }

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow = Attached()))
        if (None != (xPixmap = XCreatePixmap
            (xDisplay, xWindow, r.width, r.height, 1)))
        {
            if ((xGC = XCreateGC(xDisplay, xPixmap, 0, &xGCValues)))
            {
                GC xGCAttached = m_gc.Attached();
                Drawable xGCDrawable = m_gc.SelectDrawable(xPixmap);

                XSetForeground(xDisplay, xGC, m_blackBrush.Attached());
                XFillRectangle(xDisplay, xPixmap, xGC, 0,0, r.width,r.height);

                m_gc.Attach(xGC);

                m_filledMidpointEllipse.PlotEllipse
                (m_whiteBrush, width,height, width,height);

                m_gc.Attach(xGCAttached);
                m_gc.SelectDrawable(xGCDrawable);

                XShapeCombineMask
                (xDisplay, xWindow, 
                 ShapeBounding, 0,0, xPixmap, ShapeSet);

                XFreeGC(xDisplay, xGC);
            }

            XFreePixmap(xDisplay, xPixmap);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Paint
    (cXGCInterface& gc,
     cXRegionInterface& region,
     cXRectangle& rect) 
    {
        eError error = e_ERROR_NONE;
        int width = 50;
        int height = 25;
        XRectangle r;

        if (!(GetWindowRectangle(r)))
        {
            width = (r.width/2);
            height = (r.height/2);
        }

        m_filledMidpointEllipse.PlotEllipse
        (m_foregroundBrush, width,height, width,height, 
         e_CIRCLE_QUADRANT_1 | e_CIRCLE_QUADRANT_3);

        m_midpointEllipse.PlotEllipse
        (m_foregroundBrush, width,height, width,height, 
         e_CIRCLE_QUADRANT_2 | e_CIRCLE_QUADRANT_4);

        return error;
    }
#else /* !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CXTESTMAINWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CXTESTMAINWINDOW_HXX) || defined(CXTESTMAINWINDOW_MEMBERS_ONLY) */
