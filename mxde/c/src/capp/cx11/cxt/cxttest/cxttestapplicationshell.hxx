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
 *   File: cxttestapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXTTESTAPPLICATIONSHELL_HXX) || defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXTTESTAPPLICATIONSHELL_HXX) && !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXTTESTAPPLICATIONSHELL_HXX
#endif /* !defined(_CXTTESTAPPLICATIONSHELL_HXX) && !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Simple.h"
#include "cplatform_X11_Xaw_Command.h"
#include "cplatform_X11_Xaw_AsciiText.h"
#include "cxtellipticalroundedapplicationshell.hxx"
#include "cxtcompositewidget.hxx"
#include "cxttextwidget.hxx"
#include "cxtcommandwidget.hxx"
#include "cxcolormap.hxx"
#include "cximagecolor.hxx"
#include "ckeyiconimageobject.hxx"
#include "cxfontstruct.hxx"
#include "cxfont.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTestApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cXtEllipticalRoundedApplicationShell
cXtTestApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXtTestApplicationShell
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtTestApplicationShell
: /*virtual public cXtTestApplicationShellImplement,
  */public cXtTestApplicationShellExtend
{
public:
    /*typedef cXtTestApplicationShellImplement cImplements;
    */typedef cXtTestApplicationShellExtend cExtends;

    typedef char tChar;

    cXColormap m_colormap;
    cXImage m_objectImage;
    cXImageColor m_blackColor;
    cXImageColor m_greyColor;
    cXImageColor m_regionColor;

    TSIZE m_keyIconWidth;
    TSIZE m_keyIconHeight;
    cKeyIconImageObject m_keyIcon;
    cKeyIconImageObject m_keyIconRegion;
    cXFont m_keyIconFont;
    cXFontStruct m_keyIconFontStruct;

    cXtTextWidget m_hashTextWidget;
    cXtTextWidget m_fileTextWidget;
    cXtTextWidget m_editTextWidget;

    cXtCommandWidget m_okWidget;
    cXtCommandWidget m_cancelWidget;

    cXtCompositeWidget m_formWidget;
    bool m_formWidgetMapped;

    /**
     **********************************************************************
     *  Constructor: cXtTestApplicationShell
     *
     *       Author: $author$           
     *         Date: 6/9/2010
     **********************************************************************
     */
    cXtTestApplicationShell
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
      (display, cornerRadiusWidth, cornerRadiusHeight, edgeThickness, 
       name, className, widgetClassAttached, attached, isCreated),

      m_colormap(display),
      m_objectImage(m_imageGC),
      m_blackColor(m_objectImage, m_colormap, 0,0,0),
      m_greyColor(m_objectImage, m_colormap, 128,128,128),
      m_regionColor(m_objectImage, m_colormap, 1,1,1),

      m_keyIconWidth(64),
      m_keyIconHeight(32),
      m_keyIcon
      (m_objectImage, 
       m_blackColor,m_greyColor,m_blackColor, 
       m_keyIconWidth,m_keyIconHeight),
      m_keyIconRegion
      (m_objectImage, 
       m_regionColor,m_regionColor,m_regionColor, 
       m_keyIconWidth,m_keyIconHeight),
      m_keyIconFont(display),
      m_keyIconFontStruct(display),

      m_hashTextWidget(m_display),
      m_fileTextWidget(m_display),
      m_editTextWidget(m_display),

      m_okWidget(m_display),
      m_cancelWidget(m_display),

      m_formWidget(display),
      m_formWidgetMapped(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtTestApplicationShell
     *
     *      Author: $author$           
     *        Date: 6/9/2010
     **********************************************************************
     */
    virtual ~cXtTestApplicationShell()
    {
    }
#else /* !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: CreateXtFormWidget
     *
     *   Author: $author$           
     *     Date: 6/18/2010
     **********************************************************************
     */
    virtual eError CreateXtFormWidget
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;

        cXtArgList formArgList
        (XtNinput,True, XtNborderWidth, 0,
         XtNx,cx, XtNy,cy, XtNwidth,cWidth, XtNheight,cHeight, 0);

        cXtArgList staticTextArgList
        (XtNdisplayCaret,False,
         XtNeditType,XawtextRead, 
         XtNscrollHorizontal,XawtextScrollNever, 
         XtNscrollVertical,XawtextScrollNever, 
         XtNx,0, XtNy,0, 0);

        cXtArgList editTextArgList
        (XtNeditType,XawtextEdit, 
         XtNscrollHorizontal,XawtextScrollNever, 
         XtNscrollVertical,XawtextScrollNever, 
         XtNx,0, XtNy,20, 0);

        cXtArgList commandArgList
        (XtNshapeStyle,XawShapeRectangle, 
         XtNx,100, XtNy,0, 0);

        eError error2;
        Widget xFormWidget;
        Widget xControlWidget;
        cXtString name;
        String nameString;

        if (0 < (name.assign(m_nameChars)))
        if ((nameString = name.str()))
        if (None != (xFormWidget = m_formWidget.CreateAttached
            (error2, nameString, xWidget, /* command simplecompositeWidgetClass,*/ 
             formArgList, formArgList.Length()/*, true*/)))
        {
            m_formWidgetMapped = false;

            if (None != (xControlWidget = m_hashTextWidget.CreateAttached
                (error2, nameString, xFormWidget, asciiTextWidgetClass, 
                 staticTextArgList, staticTextArgList.Length(), true)))
            {
                XFontStruct* xFont = 0;
                TLENGTH commandLength = 6;
                TLENGTH commandWidth = 40;
                TLENGTH hashSize = 16;
                TLENGTH hashWidth = 100;
                TLENGTH hashHeight = 40;
                TLENGTH hashX = 0;
                TLENGTH hashY = 0;
                TLENGTH count;

                if ((xFont = m_hashTextWidget.GetFont(error2)))
                {
                    DBF(("() xFont->max_bounds.width = %d\n", xFont->max_bounds.width));
                    hashWidth = (hashSize * xFont->max_bounds.width);
                    hashHeight = (xFont->max_bounds.ascent+xFont->max_bounds.descent);
                }
                m_hashTextWidget.SetValuesL
                (XtNx,hashX, XtNy,hashY, XtNwidth,hashWidth, 0);

                if (None != (xControlWidget = m_editTextWidget.CreateAttached
                    (error2, nameString, xFormWidget, asciiTextWidgetClass, 
                     editTextArgList, editTextArgList.Length(), true)))
                {
                    m_editTextWidget.SetValuesL
                    (XtNx,hashX, XtNy,hashY+(hashHeight+10), 
                     XtNwidth,hashWidth, 0);
                }

                if (None != (xControlWidget = m_cancelWidget.CreateAttached
                    (error2, nameString, xFormWidget, commandWidgetClass, 
                     commandArgList, commandArgList.Length(), true)))
                {
                    if ((xFont = m_hashTextWidget.GetFont(error2)))
                    {
                        DBF(("() xFont->max_bounds.width = %d\n", xFont->max_bounds.width));
                        commandWidth = (commandLength * xFont->max_bounds.width);
                    }
                    m_cancelWidget.SetValuesL
                    (XtNlabel,(XtArgVal)("Cancel"), 
                     XtNx,hashX+(hashWidth+10), 
                     XtNy,hashY+(hashHeight+10), XtNwidth,commandWidth, 0);
                }

                if (None != (xControlWidget = m_okWidget.CreateAttached
                    (error2, nameString, xFormWidget, commandWidgetClass, 
                     commandArgList, commandArgList.Length(), true)))
                {
                    m_okWidget.SetValuesL
                    (XtNlabel,(XtArgVal)("Ok"), 
                     XtNx,hashX+(hashWidth+10), 
                     XtNy,hashY, XtNwidth,commandWidth, 0);
                }
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAfterXtSizeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/19/2010
     **********************************************************************
     */
    virtual eError OnAfterXtSizeRoundedRectangle
    (tInt& cx, tInt& cy, tSize& cWidth, tSize& cHeight,
     XRectangle& rect, Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        Window xFormWindow;
        Widget xFormWidget;
        XRectangle rectForm;

        if (None != (xFormWidget = m_formWidget.Attached()))
        {
            DBF
            (("(cx=%d,cy=%d, cWidth=%d,cHeight=%d)...\n", 
              cx,cy, cWidth,cHeight));

            //if (!(None != (xFormWindow = m_formWidget.WindowAttached())))
            if (!(XtIsManaged(xFormWidget)))
            //if (!(XtIsRealized(xFormWidget)))
            if (!(m_formWidgetMapped))
            {
                DBF(("()\n XtRealizeWidget(xFormWidget=0x%x)\n", xFormWidget));
                XtRealizeWidget(xFormWidget);
                XtMapWidget(xFormWidget);
                m_formWidgetMapped = true;
            }

            rectForm.x = cx;
            rectForm.y = cy;
            rectForm.width = cWidth;
            rectForm.height = cHeight;
            m_formWidget.SetRectangle(rectForm);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAfterXtShapeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/10/2010
     **********************************************************************
     */
    virtual eError OnAfterXtShapeRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xPixmapGC, Pixmap xPixmap,
     Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        GC xGCAttached = m_imageGC.Attached();
        XRectangle fontRect;
        Font xFont;

        if ((m_imageGC.Attach(xPixmapGC)))
        {
            Drawable xGCDrawable = m_imageGC.SelectDrawable(xPixmap);

            cy = cy-m_cornerRadiusHeight-m_topMargin+m_edgeThickness+1;

            m_keyIconRegion.Plot(cx,cy);

            if (None != (xFont = m_keyIconFont.Attached()))
                m_imageGC.SetFont(xFont);

            if (!(m_keyIconFontStruct.MaxRectangle(fontRect)))
                cy += fontRect.y;

            m_imageGC.SetForeground(1);
            m_imageGC.DrawString(cx+m_keyIcon.m_width,cy, "MD5");

            m_imageGC.SelectDrawable(xGCDrawable);
        }
        m_imageGC.Attach(xGCAttached);
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
        XRectangle fontRect;
        Font xFont;

        cy = cy-m_cornerRadiusHeight-m_topMargin+m_edgeThickness+1;

        m_keyIcon.Plot(cx,cy);

        if (None != (xFont = m_keyIconFont.Attached()))
            m_imageGC.SetFont(xFont);

        if (!(m_keyIconFontStruct.MaxRectangle(fontRect)))
            cy += fontRect.y;

        m_imageGC.DrawString(cx+m_keyIcon.m_width,cy, "MD5");
        return error;
    }
    /**
     **********************************************************************
     * Function: BeforeCreateShapedApplicationShell
     *
     *   Author: $author$           
     *     Date: 6/9/2010
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
        XRectangle fontRect;
        Font xFont;

        DBI(("()...\n"));

        if (None != (m_colormap.Attach(colormap.Attached())))
        {
            m_blackColor.AllocateBYTE();
            m_greyColor.AllocateBYTE();
            m_regionColor.Attach(fgRegionBrush.Attached());
        }
        m_topMargin = m_keyIconHeight/2;
        
        if (None != (xFont = m_keyIconFont.LoadAttached
            ("-adobe-helvetica-bold-r-*-*-24-*-*-*-*-*-*-*")))
        if (!(m_keyIconFontStruct.Query(xFont)))
        if (!(m_keyIconFontStruct.MaxRectangle(fontRect)))
            DBI
            (("()\n font rectangle x = %d, y = %d, width = %d, height = %d\n",
              fontRect.x,fontRect.y, fontRect.width,fontRect.height));
        return error;
    }
    /**
     **********************************************************************
     * Function: AfterCreateShapedApplicationShell
     *
     *   Author: $author$           
     *     Date: 6/9/2010
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
        eError error = e_ERROR_NONE;
        eError error2;
        Display* xDisplay;
        Window xWindow;
        Widget xWidget;
        XRectangle rect;
        tSize cWidth,cHeight;
        tInt cx,cy;

        DBF(("()...\n"));

        if (!(None != (xWidget = shellWidget.Attached())))
            DBE(("(\n !(None != (xWidget = shellWidget.Attached()))\n"));
        else
        if (!((xDisplay = shellWidget.DisplayAttached())))
            DBE(("(\n !((xDisplay = shellWidget.DisplayAttached()))\n"));
        else
        if (!(error2 = shellWidget.GetRectangle(rect)))
        {
            if (!(None != (xWindow = shellWidget.WindowAttached())))
                DBW(("(\n !(None != (xWindow = shellWidget.WindowAttached()))\n"));

            if (!(error2 = OnXtSizeRoundedRectangle
                (cx,cy, cWidth,cHeight, rect, xWidget, xWindow, *xDisplay)))
            if (!(error2 = CreateXtFormWidget
                (cx,cy, cWidth,cHeight, rect, xWidget, xWindow, *xDisplay)))
            {
                DBF
                (("()\n created XtFormWidget "
                  "cx=%d,cy=%d, cWidth=%d,cHeight=%d\n", cx,cy, cWidth,cHeight));
            }
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTTESTAPPLICATIONSHELL_HXX) || defined(CXTTESTAPPLICATIONSHELL_MEMBERS_ONLY) */
