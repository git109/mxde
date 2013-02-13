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
 *   File: cxmtestapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 6/25/2010
 **********************************************************************
 */
#if !defined(_CXMTESTAPPLICATIONSHELL_HXX) || defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXMTESTAPPLICATIONSHELL_HXX) && !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXMTESTAPPLICATIONSHELL_HXX
#endif /* !defined(_CXMTESTAPPLICATIONSHELL_HXX) && !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cxtcryptoapplicationshell.hxx"
#include "cxmwmhintsinterface.hxx"
#include "cxmtextfield.hxx"
#include "cxmpushbutton.hxx"
#include "cxmlabel.hxx"
#include "cxmform.hxx"
#include "cxmstring.hxx"
#include "cxmdropsite.hxx"
#include "cxatom.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmTestApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 6/25/2010
 **********************************************************************
 */
typedef cXtCryptoApplicationShell
cXmTestApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXmTestApplicationShell
 *
 * Author: $author$           
 *   Date: 6/25/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmTestApplicationShell
: /*virtual public cXmTestApplicationShellImplement,*/
  public cXmTestApplicationShellExtend
{
public:
    /*typedef cXmTestApplicationShellImplement cImplements;*/
    typedef cXmTestApplicationShellExtend cExtends;

    cXMwmHintsInterface& m_mwmHints;
    bool m_addWMDecorations;

    cXmTextField m_hashWidget;
    cXmTextField m_fileWidget;
    
    cXmPushButton m_okWidget;
    cXmPushButton m_cancelWidget;

    cXmForm m_formWidget;
    bool m_formWidgetMapped;

    cXAtom m_fileDropAtom;
    cXmDropSite m_fileDropSite;
    
    /**
     **********************************************************************
     *  Constructor: cXmTestApplicationShell
     *
     *       Author: $author$           
     *         Date: 6/25/2010
     **********************************************************************
     */
    cXmTestApplicationShell
    (cXMwmHintsInterface& mwmHints,
     cXDisplayInterface& display,
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

      m_mwmHints(mwmHints),
      m_addWMDecorations(false),

      m_hashWidget(display),
      m_fileWidget(display),

      m_okWidget(display),
      m_cancelWidget(display),

      m_formWidget(display),
      m_formWidgetMapped(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmTestApplicationShell
     *
     *      Author: $author$           
     *        Date: 6/25/2010
     **********************************************************************
     */
    virtual ~cXmTestApplicationShell()
    {
    }
#else /* !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: OnXtCallback
     *
     *    Author: $author$           
     *      Date: 7/9/2010
     **********************************************************************
     */
    virtual eError OnXtCallback
    (Widget xWidget, XtPointer clientData, XtPointer callData)
    {
        eError error = e_ERROR_NONE;

        DBI(("() in...\n"));
        
        if (xWidget == (m_okWidget.Attached()))
            DBI(("() Ok\n"));
        else
        if (xWidget == (m_cancelWidget.Attached()))
            DBI(("() Cancel\n"));
            
        DBI(("() ...out\n"));
        return error;
    }
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
        
        DBI(("() in...\n"));
        DBI(("() ...out\n"));
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

        if (!(ChangeWMDecorations(m_mwmHints, wmDecorations)))
            m_addWMDecorations = !m_addWMDecorations;
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

        DBI(("()...\n"));

        if (None != (xFormWidget = m_formWidget.Attached()))
        {
            DBI
            (("(cx=%d,cy=%d, cWidth=%d,cHeight=%d)...\n", 
              cx,cy, cWidth,cHeight));

            if (!(XtIsManaged(xFormWidget)))
            if (!(m_formWidgetMapped))
            {
                DBI(("()\n XtRealizeWidget(xFormWidget=0x%x)\n", xFormWidget));
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
        (XtNinput,True, XmNmargin,0, XmNshadowThickness,0,
         XtNx,cx, XtNy,cy, XtNwidth,cWidth, XtNheight,cHeight, 0);

        cXtArgList textArgList
        (XmNeditable,False, XmNmarginWidth,0, XmNmarginHeight,0,
         XtNx,0, XtNy,0, XtNwidth,150, XtNheight,50, 0);

        cXtArgList editArgList
        (XmNeditable,True, XmNmarginWidth,0, XmNmarginHeight,0,
         XtNx,0, XtNy,0, XtNwidth,150, XtNheight,50, 0);

        cXtArgList buttonArgList
        (XmNmargin,0, XtNx,0, XtNy,0, XtNwidth,50, XtNheight,50, 0);

        eError error2;
        Widget xFormWidget;
        Widget xTextWidget;
        Widget xButtonWidget;
        XRectangle xRect;
        Atom xAtom;

        if (None != (xFormWidget = m_formWidget.CreateAttached
            (error2, xWidget, /*xmBulletinBoardWidgetClass,*/
             formArgList, formArgList.Length())))
        {
            DBI(("()\n"));

            m_formWidgetMapped = false;

            if (None != (xTextWidget = m_hashWidget.CreateAttached
                (error2, xFormWidget, /*xmTextFieldWidgetClass,*/ 
                 textArgList, textArgList.Length())))
            {
                m_hashWidget.ManageChild();
            }
            if (None != (xTextWidget = m_fileWidget.CreateAttached
                (error2, xFormWidget, /*xmTextFieldWidgetClass,*/ 
                 editArgList, editArgList.Length())))
            {
                m_fileWidget.ManageChild();
                /*
                if (None != (xAtom = m_fileDropAtom.
                    AttachIntern(xDisplay, "FILE_NAME")))
                    m_fileDropSite.Register(xTextWidget, xAtom);
                */
            }
            if (None != (xButtonWidget = m_cancelWidget.CreateAttached
                (error2, xFormWidget, 
                 buttonArgList, buttonArgList.Length())))
            {
                cXmString xmString("Cancel");

                m_cancelWidget.SetValuesL
                (XmNlabelString,(XtArgVal)(xmString.Attached()), 0);

                m_cancelWidget.AddCallback
                (XmNactivateCallback, (cXtCallbackInterface*)(this));
                
                if (!(m_hashWidget.GetRectangle(xRect)))
                    m_cancelWidget.SetValuesL(XtNx, xRect.width, 0);
                    
                if (!(m_cancelWidget.GetRectangle(xRect)))
                {
                    m_hashWidget.SetValuesL(XtNheight, xRect.height, 0);
                    m_fileWidget.SetValuesL(XtNheight, xRect.height, XtNy, xRect.height, 0);
                    m_cancelWidget.SetValuesL(XtNy, xRect.height, 0);
                }
                    
                m_cancelWidget.ManageChild();
            }
            if (None != (xButtonWidget = m_okWidget.CreateAttached
                (error2, xFormWidget, 
                 buttonArgList, buttonArgList.Length())))
            {
                cXmString xmString("Ok");

                m_okWidget.SetValuesL
                (XmNlabelString,(XtArgVal)(xmString.Attached()), 0);

                m_okWidget.AddCallback
                (XmNactivateCallback, (cXtCallbackInterface*)(this));
                
                if (!(m_cancelWidget.GetRectangle(xRect)))
                    m_okWidget.SetValuesL
                    (XtNx,xRect.x, XtNwidth,xRect.width, XtNheight,xRect.height, 0);
                    
                m_okWidget.ManageChild();
            }
            if (!(m_hashWidget.GetRectangle(xRect)))
            {
                unsigned width = xRect.width;
                unsigned height = xRect.height*2;
                
                if (!(m_cancelWidget.GetRectangle(xRect)))
                {
                    width += xRect.width;
                    
                    DBI(("()\n width=%d, height=%d\n", width,height));
                    
                    m_formWidget.SetValuesL
                    (XtNwidth,width, XtNheight,height, 0);
                }
            }
        }
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
    virtual eError xBeforeCreateShapedApplicationShell
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

        if (!(None != (xWidget = Attached())))
            DBE(("(\n !(None != (xWidget = Attached()))\n"));
        else
        if (!((xDisplay = DisplayAttached())))
            DBE(("(\n !((xDisplay = DisplayAttached()))\n"));
        else
        if (!(error2 = shellWidget.GetRectangle(rect)))
        {
            if (!(None != (xWindow = WindowAttached())))
                DBW(("(\n !(None != (xWindow = WindowAttached()))\n"));

            if (!(error2 = OnXtSizeRoundedRectangle
                (cx,cy, cWidth,cHeight, rect, xWidget, xWindow, *xDisplay)))

            if (!(error2 = CreateXtFormWidget
                (cx,cy, cWidth,cHeight, rect, xWidget, xWindow, *xDisplay)))
            {
                DBF
                (("()\n created XtFormWidget "
                  "cx=%d,cy=%d, cWidth=%d,cHeight=%d\n", 
                  cx,cy, cWidth,cHeight));
            }
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXMTESTAPPLICATIONSHELL_HXX) || defined(CXMTESTAPPLICATIONSHELL_MEMBERS_ONLY) */
