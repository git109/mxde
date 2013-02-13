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
 *   File: cxtmd5main.hxx
 *
 * Author: $author$           
 *   Date: 4/29/2010
 **********************************************************************
 */
#if !defined(_CXTMD5MAIN_HXX) || defined(CXTMD5MAIN_MEMBERS_ONLY)
#if !defined(_CXTMD5MAIN_HXX) && !defined(CXTMD5MAIN_MEMBERS_ONLY)
#define _CXTMD5MAIN_HXX
#endif /* !defined(_CXTMD5MAIN_HXX) && !defined(CXTMD5MAIN_MEMBERS_ONLY) */

#if !defined(CXTMD5MAIN_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Simple.h"
#include "cplatform_X11_Xaw_Box.h"
#include "cplatform_X11_Xaw_Form.h"
#include "cplatform_X11_Xaw_AsciiText.h"
#include "cplatform_X11_Xaw_Command.h"
#include "cxtmain.hxx"
#include "cxteventhandler.hxx"
#include "cxtcallback.hxx"
#include "cxtarglist.hxx"
#include "cxttextwidget.hxx"
#include "cxtcommandwidget.hxx"
#include "cxtwidget.hxx"
#include "cxcolor.hxx"
#include "cxcolormap.hxx"
#include "cxproperty.hxx"
#include "cxmwmhints.hxx"
#include "cxatom.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtMD5MainExtend
 *
 *  Author: $author$           
 *    Date: 4/29/2010
 **********************************************************************
 */
typedef cXtMain
cXtMD5MainExtend;
/**
 **********************************************************************
 *  Class: cXtMD5Main
 *
 * Author: $author$           
 *   Date: 4/29/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtMD5Main
: virtual public cXtEventHandlerImplement,
  virtual public cXtCallbackImplement,
  public cXtMD5MainExtend
{
public:
    typedef cXtMD5MainExtend cExtends;

    cXAtom m_atomWmProtocols;
    cXAtom m_atomWmDeleteWindow;

    cXAtom m_atomXdndEnter;
    cXProperty m_propertyXdndAware;

    cXtWidget m_shellWidget;
    cXtWidget m_formWidget;
    cXtTextWidget m_hashTextWidget;
    cXtTextWidget m_fileTextWidget;
    cXtTextWidget m_editTextWidget;
    cXtCommandWidget m_okWidget;
    cXtCommandWidget m_cancelWidget;

    cXColormap m_colormap;
    cXColor m_redColor;
    cXColor m_greenColor;
    cXColor m_blueColor;
    cXColor m_paperColor;
    cXColor m_greyColor;
    cXColor m_lightGreyColor;
    cXColor m_darkGreyColor;
    cXColor m_blackColor;
    cXColor m_whiteColor;

    cXMwmHints m_mwmHints;
    bool m_changeMwmHints;

    /**
     **********************************************************************
     *  Constructor: cXtMD5Main
     *
     *       Author: $author$           
     *         Date: 4/29/2010
     **********************************************************************
     */
    cXtMD5Main
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME)
    : cExtends(xtNameChars, xtClassNameChars),

      m_propertyXdndAware(2),

      m_shellWidget(m_display),
      m_formWidget(m_display),
      m_hashTextWidget(m_display),
      m_fileTextWidget(m_display),
      m_editTextWidget(m_display),
      m_okWidget(m_display),
      m_cancelWidget(m_display),

      m_colormap(m_display),
      m_redColor(m_display, m_colormap),
      m_greenColor(m_display, m_colormap),
      m_blueColor(m_display, m_colormap),
      m_paperColor(m_display, m_colormap),
      m_greyColor(m_display, m_colormap),
      m_lightGreyColor(m_display, m_colormap),
      m_darkGreyColor(m_display, m_colormap),
      m_blackColor(m_display, m_colormap),
      m_whiteColor(m_display, m_colormap),

      m_changeMwmHints(false)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtMD5Main
     *
     *      Author: $author$           
     *        Date: 4/29/2010
     **********************************************************************
     */
    virtual ~cXtMD5Main()
    {
    }
#else /* !defined(CXTMD5MAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTMD5MAIN_MEMBERS_ONLY) */

#if !defined(CXTMD5MAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: AfterOpenDisplay
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError AfterOpenDisplay
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;

        cXtArgList shellArgList
        (XtNinput, True, 
         XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);

        cXtArgList formArgList
        (XtNx,40, XtNy,40, XtNwidth,100, XtNheight,100, 0);

        cXtArgList staticTextArgList
        (XtNdisplayCaret,False,
         XtNeditType,XawtextRead, 
         XtNscrollHorizontal,XawtextScrollNever, 
         XtNscrollVertical,XawtextScrollNever, 
         XtNx,10, XtNy,10, 0);

        cXtArgList editTextArgList
        (XtNeditType,XawtextEdit, 
         XtNscrollHorizontal,XawtextScrollNever, 
         XtNscrollVertical,XawtextScrollNever, 
         XtNx,10, XtNy,10, 0);

        cXtArgList commandArgList
        (XtNshapeStyle,XawShapeRectangle, 
         XtNx,100, XtNy,10, 0);

        Widget xShellWidget;
        Widget xFormWidget;
        Widget xFileNameWidget;
        Atom xAtomWmDeleteWindow;
        Atom xAtomXdndAware;
        Display* xDisplay;
        eError error2;

        if ((xDisplay = display.Attached()))
        if (None != (m_colormap.AttachDefault()))
        if (!(error2 = m_redColor.AllocateBYTE(255, 0, 0)))
        if (!(error2 = m_greenColor.AllocateBYTE(0, 255, 0)))
        if (!(error2 = m_blueColor.AllocateBYTE(0, 0, 255)))
        if (!(error2 = m_paperColor.AllocateBYTE(0xff, 0xff, 0xdd)))
        if (!(error2 = m_greyColor.AllocateBYTE(0xcc, 0xcc, 0xcc)))
        if (!(error2 = m_lightGreyColor.AllocateBYTE(0xee, 0xee, 0xee)))
        if (!(error2 = m_darkGreyColor.AllocateBYTE(0xaa, 0xaa, 0xaa)))
        if (!(error2 = m_blackColor.AllocateBYTE(0, 0, 0)))
        if (!(error2 = m_whiteColor.AllocateBYTE(255, 255, 255)))

        if (None != (m_atomWmProtocols.AttachIntern(display, "WM_PROTOCOLS", False)))

        if (None != (xAtomWmDeleteWindow = m_atomWmDeleteWindow.AttachIntern(display, "WM_DELETE_WINDOW", False)))

        if (None != (m_atomXdndEnter.AttachIntern(display, "XdndEnter", False)))

        if (None != (m_propertyXdndAware.AttachIntern(display, "XdndAware", False)))

        if (None != (xShellWidget = m_shellWidget.CreateShellAttached
            (error2, m_xtNameChars, m_xtClassNameChars,
             applicationShellWidgetClass, shellArgList, shellArgList.Length())))
        {
            if (None != (xFormWidget = m_formWidget.CreateAttached
                (error2, m_xtNameChars, xShellWidget, compositeWidgetClass, 
                 formArgList, formArgList.Length(), true)))
            {
                m_formWidget.SetValuesL
                (XtNbackground,m_paperColor.Attached(), 0);

                if (None != (m_hashTextWidget.CreateAttached
                    (error2, m_xtNameChars, xFormWidget, asciiTextWidgetClass, 
                     staticTextArgList, staticTextArgList.Length(), true)))
                {
                    XFontStruct* xFont = 0;
                    TLENGTH hashSize = 16;
                    TLENGTH hashWidth = 100;
                    TLENGTH hashHeight = 40;
                    TLENGTH hashX = 10;
                    TLENGTH hashY = 10;
                    TLENGTH count;

                    if ((xFont = m_hashTextWidget.GetFont(error2)))
                    {
                        DBI(("() xFont->max_bounds.width = %d\n", xFont->max_bounds.width));
                        hashWidth = (hashSize * xFont->max_bounds.width);
                    }

                    if (0 < (count = m_hashTextWidget.GetHeight()))
                        hashHeight = count+10;

                    m_hashTextWidget.SetValuesL
                    (XtNwidth,hashWidth, XtNx,hashX, XtNy,hashY, 0);

                    if (None != (xFileNameWidget = m_fileTextWidget.CreateAttached
                        (error2, m_xtNameChars, xFormWidget, asciiTextWidgetClass, 
                         editTextArgList, editTextArgList.Length(), true)))
                    {
                        m_fileTextWidget.SetValuesL
                        (XtNwidth,hashWidth, XtNx,hashX, XtNy,hashY+hashHeight, 0);

                        if (None != (m_editTextWidget.CreateAttached
                            (error2, m_xtNameChars, xFormWidget, asciiTextWidgetClass, 
                             editTextArgList, editTextArgList.Length(), true)))
                        {
                            m_editTextWidget.SetValuesL
                            (XtNwidth,hashWidth, XtNx,hashX, XtNy,hashY+hashHeight*2, 0);

                            if (None != (m_okWidget.CreateAttached
                                (error2, m_xtNameChars, xFormWidget, commandWidgetClass, 
                                 commandArgList, commandArgList.Length(), true)))
                            {
                                m_okWidget.SetValuesL
                                (XtNlabel,(XtArgVal)("Ok"), 
                                 XtNx,hashX+hashWidth+10, XtNy,hashY, 0);

                                XtAddCallback
                                (m_okWidget.Attached(),
                                 XtNcallback, XtCallback,
                                 (XtPointer)((cXtCallbackInterface*)(this)));

                                if (None != (m_cancelWidget.CreateAttached
                                    (error2, m_xtNameChars, xFormWidget, commandWidgetClass, 
                                     commandArgList, commandArgList.Length(), true)))
                                {
                                    TLENGTH w1,w2;

                                    m_cancelWidget.SetValuesL
                                    (XtNlabel,(XtArgVal)("Cancel"), 
                                     XtNx,hashX+hashWidth+10, XtNy,hashY+hashHeight, 0);

                                    XtAddCallback
                                    (m_cancelWidget.Attached(),
                                     XtNcallback, XtCallback,
                                     (XtPointer)((cXtCallbackInterface*)(this)));

                                    if (0 <= (w1 = m_okWidget.GetWidth()))
                                    if (0 <= (w2 = m_cancelWidget.GetWidth()))
                                    if (w1 < w2)
                                        m_okWidget.SetValuesL(XtNwidth,w2,0);
                                    else
                                    if (w1 > w2)
                                        m_cancelWidget.SetValuesL(XtNwidth,w1,0);
                                }
                            }

                            m_shellWidget.Realize();

                            XtAddEventHandler
                            (xShellWidget, NoEventMask, True,
                             HandleXtEvent, (XtPointer)((cXtEventHandlerInterface*)(this)));

                            XSetWMProtocols
                            (display.Attached(), XtWindow(xShellWidget),
                             &xAtomWmDeleteWindow, 1);

                            m_propertyXdndAware.ChangeProperty
                            (*display.Attached(), XtWindow(xShellWidget));

                            m_mwmHints.ChangeHints
                            (*xDisplay, XtWindow(xShellWidget), 
                             MWM_HINTS_DECORATIONS, 0, MWM_DECOR_NONE);
                            m_changeMwmHints = true;
                            return error;

                            m_editTextWidget.Destroy(true);
                        }
                        m_fileTextWidget.Destroy(true);
                    }
                    m_hashTextWidget.Destroy(true);
                }
                m_formWidget.Destroy(true);
            }
            m_shellWidget.Destroy(true);
        }
        return error;
    }

    /**
     **********************************************************************
     *  Function: OnXtCallback
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError OnXtCallback
    (Widget xWidget, XtPointer clientData, XtPointer callData)
    {
        eError error = e_ERROR_NONE;
        Display* xDisplay;
        Window xWindow;

        DBI(("() in...\n"));

        if (m_okWidget.Attached() == xWidget)
        {
            DBI(("() Ok\n"));

            if (m_changeMwmHints)
            if (None != (xWidget = m_shellWidget.Attached()))
            if (None != (xWindow = XtWindow(xWidget)))
            if ((xDisplay = m_display.Attached()))
            {
                m_changeMwmHints = false;
                XUnmapWindow(xDisplay, xWindow);
                m_mwmHints.ChangeHints
                (*xDisplay, xWindow, 
                 MWM_HINTS_DECORATIONS, 0, MWM_DECOR_TITLE);
                XMapWindow(xDisplay, xWindow);
            }
        }
        else
        if (m_cancelWidget.Attached() == xWidget)
        {
            DBI(("() Cancel\n"));

            if (!m_changeMwmHints)
            if (None != (xWidget = m_shellWidget.Attached()))
            if (None != (xWindow = XtWindow(xWidget)))
            if ((xDisplay = m_display.Attached()))
            {
                m_changeMwmHints = True;
                XUnmapWindow(xDisplay, xWindow);
                m_mwmHints.ChangeHints
                (*xDisplay, xWindow, 
                 MWM_HINTS_DECORATIONS, 0, MWM_DECOR_NONE);
                XMapWindow(xDisplay, xWindow);
            }
        }
        DBI(("() ...out\n"));
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnHandleXtEvent
     *
     *    Author: $author$           
     *      Date: 4/28/2010
     **********************************************************************
     */
    virtual eError OnHandleXtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;

        DBI(("()...\n"));

        continueToDispatch = True;

        if (xEvent.type == ClientMessage)
        {
            DBI(("() ClientMessage\n"));
            if (xEvent.xclient.message_type == m_atomWmProtocols.Attached())
            {
                DBI(("() WM_PROTOCOLS\n"));
                if (xEvent.xclient.data.l[0] == m_atomWmDeleteWindow.Attached())
                if (xWidget == m_shellWidget.Attached())
                {
                    DBI(("() WM_DELETE_WINDOW\n"));
                    continueToDispatch = False;
                    SetQuit();
                }
            }
            else
            if (xEvent.xclient.message_type == m_atomXdndEnter.Attached())
            {
                DBI(("() XdndEnter\n"));
            }
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTMD5MAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTMD5MAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTMD5MAIN_HXX) || defined(CXTMD5MAIN_MEMBERS_ONLY) */
