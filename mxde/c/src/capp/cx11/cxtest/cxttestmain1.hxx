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
 *   Date: 4/27/2010
 **********************************************************************
 */
#if !defined(_CXTTESTMAIN_HXX) || defined(CXTTESTMAIN_MEMBERS_ONLY)
#if !defined(_CXTTESTMAIN_HXX) && !defined(CXTTESTMAIN_MEMBERS_ONLY)
#define _CXTTESTMAIN_HXX
#endif /* !defined(_CXTTESTMAIN_HXX) && !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXTTESTMAIN_MEMBERS_ONLY)
#include "cplatform_X11_Xaw_Form.h"
#include "cplatform_X11_Xaw_AsciiText.h"
#include "cplatform_X11_Xaw_Simple.h"
#include "cplatform_X11_Intrinsic.h"
#include "cxteventhandler.hxx"
#include "cxtmain.hxx"
#include "cxtwidget.hxx"
#include "cxtarglist.hxx"
#include "cxatom.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTestMainExtend
 *
 *  Author: $author$           
 *    Date: 4/27/2010
 **********************************************************************
 */
typedef cXtMain
cXtTestMainExtend;
/**
 **********************************************************************
 *  Class: cXtTestMain
 *
 * Author: $author$           
 *   Date: 4/27/2010
 **********************************************************************
 */
class cXtTestMain
: virtual public cXtEventHandlerImplement,
  public cXtTestMainExtend
{
public:
    typedef cXtTestMainExtend cExtends;

    const String m_nameChars;
    const String m_classNameChars;

    cXtWidget m_shellWidget;
    cXtWidget m_formWidget;
    cXtWidget m_textWidget;

    cXAtom m_atomWmProtocols;
    cXAtom m_atomWmDeleteWindow;

    /**
     **********************************************************************
     *  Constructor: cXtTestMain
     *
     *       Author: $author$           
     *         Date: 4/27/2010
     **********************************************************************
     */
    cXtTestMain
    (const String nameChars = "cXtTestMain", 
     const String classNameChars = "cXtTestMain")
    : m_nameChars(nameChars),
      m_classNameChars(classNameChars),
      m_shellWidget(m_display),
      m_formWidget(m_display),
      m_textWidget(m_display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtTestMain
     *
     *      Author: $author$           
     *        Date: 4/27/2010
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
        cXtArgList textArgList
        (XtNeditType,XawtextEdit, 
         XtNscrollHorizontal,XawtextScrollWhenNeeded, 
         XtNscrollVertical,XawtextScrollWhenNeeded, 
         XtNx,0, XtNy,0, XtNwidth,400, XtNheight,10, 0);
        cXtArgList formArgList
        (XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);
        cXtArgList argList
        (XtNallowShellResize,False, 
         XtNx,0, XtNy,0, XtNwidth,400, XtNheight,100, 0);
        Widget parentWidget;
        Widget formWidget;
        Widget widget;
        Atom atom;
        eError error2;

        if (None != (m_atomWmProtocols.AttachIntern(display, "WM_PROTOCOLS", False)))

        if (None != (atom = m_atomWmDeleteWindow.AttachIntern(display, "WM_DELETE_WINDOW", False)))

        if (None != (parentWidget = m_shellWidget.CreateShellAttached
            (error2, m_nameChars, m_classNameChars,
             applicationShellWidgetClass, argList, argList.Length())))
        {
            if (None != (formWidget = m_formWidget.CreateAttached
                (error2, m_nameChars, parentWidget,
                 formWidgetClass, formArgList, formArgList.Length())))
            {
            if (None != (widget = m_textWidget.CreateAttached
                (error2, m_nameChars, formWidget,
                 asciiTextWidgetClass, textArgList, textArgList.Length())))
            {
                m_textWidget.ManageChild();
                m_formWidget.ManageChild();
                m_shellWidget.Realize();
                m_textWidget.SetIsCreated(false);
                m_formWidget.SetIsCreated(false);
                m_shellWidget.SetIsCreated(false);

                XtAddEventHandler
                (parentWidget, NoEventMask, True,
                 HandleXtEvent, (XtPointer)((cXtEventHandlerInterface*)(this)));

                XSetWMProtocols
                (display.Attached(), XtWindow(parentWidget),
                 &atom, 1);

                return error;
            }
            m_formWidget.Destroy(true);
            }
            m_shellWidget.Destroy(true);
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: BeforeCloseDisplay
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual eError BeforeCloseDisplay
    (cXDisplayInterface& display,
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

        if (xEvent.type == ClientMessage)
        if (xEvent.xclient.message_type == m_atomWmProtocols.Attached())
        if (xEvent.xclient.data.l[0] == m_atomWmDeleteWindow.Attached())
        if (xWidget == m_shellWidget.Attached())
        {
            DBI(("() WM_DELETE_WINDOW\n"));
            SetQuit();
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTTESTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTTESTMAIN_HXX) || defined(CXTTESTMAIN_MEMBERS_ONLY) */
