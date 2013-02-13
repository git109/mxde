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
 *   File: cxtapplicationshellmain.hxx
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
#if !defined(_CXTAPPLICATIONSHELLMAIN_HXX) || defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY)
#if !defined(_CXTAPPLICATIONSHELLMAIN_HXX) && !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY)
#define _CXTAPPLICATIONSHELLMAIN_HXX
#endif /* !defined(_CXTAPPLICATIONSHELLMAIN_HXX) && !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY) */

#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY)
#include "cxtapplicationshell.hxx"
#include "cxtmain.hxx"
#include "cxmwmhints.hxx"
#include "cxatom.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtApplicationShellMainExtend
 *
 *  Author: $author$           
 *    Date: 5/19/2010
 **********************************************************************
 */
typedef cXtMain
cXtApplicationShellMainExtend;
/**
 **********************************************************************
 *  Class: cXtApplicationShellMain
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtApplicationShellMain
: /*virtual public cXtApplicationShellMainImplement,
  */public cXtApplicationShellMainExtend
{
public:
    /*typedef cXtApplicationShellMainImplement cImplements;
    */typedef cXtApplicationShellMainExtend cExtends;

    Display* m_xDisplay;

    cXtApplicationShell m_shellWidget;
    Widget m_xShellWidget;
    Window m_xShellWindow;

    INT m_shellWidgetXtNinput;
    INT m_shellWidgetXtNx;
    INT m_shellWidgetXtNy;
    INT m_shellWidgetXtNwidth;
    INT m_shellWidgetXtNheight;

    cXMwmHints m_mwmHints;

    cXAtom m_atom_WM_PROTOCOLS;
    cXAtom m_atom_WM_DELETE_WINDOW;

    Atom m_xAtom_WM_PROTOCOLS;
    Atom m_xAtom_WM_DELETE_WINDOW;

    /**
     **********************************************************************
     *  Constructor: cXtApplicationShellMain
     *
     *       Author: $author$           
     *         Date: 5/19/2010
     **********************************************************************
     */
    cXtApplicationShellMain
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME,
     const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends
      (xtNameChars, xtClassNameChars, 
       displayNameChars, displayScreen),

      m_xDisplay(0),

      m_shellWidget(m_display, xtNameChars),
      m_xShellWidget(None),
      m_xShellWindow(None),

      m_shellWidgetXtNinput(True),
      m_shellWidgetXtNx(0),
      m_shellWidgetXtNy(0),
      m_shellWidgetXtNwidth(200),
      m_shellWidgetXtNheight(100),

      m_xAtom_WM_PROTOCOLS(None),
      m_xAtom_WM_DELETE_WINDOW(None)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtApplicationShellMain
     *
     *      Author: $author$           
     *        Date: 5/19/2010
     **********************************************************************
     */
    virtual ~cXtApplicationShellMain()
    {
    }
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual cXtApplicationShellInterface* CreateApplicationShell
    (eError& error,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        cXtApplicationShellInterface* shellWidget = 0;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        const String className = AppClassName();
        cXtApplicationShellInterface* applicationShell;
        const XtChar* widgetNameChars;
        String widgetName;
        cXtString widgetNameString;
        WidgetClass widgetClass;
        Widget widgetParent;
        Widget widget;
        ArgList argList;
        TLENGTH count;

        DBT(("()...\n"));

        error = e_ERROR_FAILED;

        if (!(applicationShell = ApplicationShell()))
            return 0;

        DBT(("() applicationShell = %p\n", applicationShell));

        if (!(className))
            return 0;

        DBT(("() className = \"%s\"\n", className));

        if (!(widgetNameChars = applicationShell->Name()))
            return 0;

        DBT(("() widgetNameChars = \"%s\"\n", widgetNameChars));

        if (0 >= (count = widgetNameString.assign(widgetNameChars)))
            return 0;

        if (!(widgetName = widgetNameString.str()))
            return 0;

        DBT(("() widgetName = \"%s\"\n", widgetName));

        if (!(widgetClass = applicationShell->WidgetClassToAttach()))
            return 0;

        DBT(("() widgetClass = %p\n", widgetClass));

        if (0 <= (count = applicationShell->ClearArgValues()))
        {
            if (0 <= (m_shellWidgetXtNinput))
                applicationShell->AppendArgValues
                (XtNinput, m_shellWidgetXtNinput);

            if (0 <= (m_shellWidgetXtNx))
                applicationShell->AppendArgValues
                (XtNx, m_shellWidgetXtNx);

            if (0 <= (m_shellWidgetXtNy))
                applicationShell->AppendArgValues
                (XtNy, m_shellWidgetXtNy);

            if (0 <= (m_shellWidgetXtNwidth))
                applicationShell->AppendArgValues
                (XtNwidth, m_shellWidgetXtNwidth);

            if (0 <= (m_shellWidgetXtNheight))
                applicationShell->AppendArgValues
                (XtNheight, m_shellWidgetXtNheight);

            if (!(argList = applicationShell->ArgValues(count)))
                return 0;

            DBT(("() argList = %p[%d]\n", argList, count));

            if ((widget = applicationShell->CreateShellAttached
                (error, widgetName, className, 
                 widgetClass, argList, count)))
            {
                DBT(("() created ApplicationShell\n"));
                shellWidget = applicationShell;
            }
        }
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return shellWidget;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DestroyApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError DestroyApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = shellWidget.Destroy();
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: BeforeCreateApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/24/2010
     **********************************************************************
     */
    virtual eError BeforeCreateApplicationShell
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        DBT(("()...\n"));
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AfterCreateApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError AfterCreateApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        DBT(("()...\n"));
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: BeforeDestroyApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError BeforeDestroyApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        DBT(("()...\n"));
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: RealizeApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError RealizeApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = shellWidget.Realize();
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AfterRealizeApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual eError AfterRealizeApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        DBT(("()...\n"));
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetApplicationShellWMProtocols
     *
     *    Author: $author$           
     *      Date: 5/23/2010
     **********************************************************************
     */
    virtual eError SetApplicationShellWMProtocols
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        Display* xDisplay;
        Widget xWidget;
        Window xWindow;
        Atom xAtom;
        Bool success;

        DBT(("()...\n"));

        if ((xDisplay = display.Attached()))
        if (None != (xWidget = shellWidget.Attached()))
        if (None != (xWindow = XtWindow(xWidget)))
        if (None != (xAtom = m_atom_WM_DELETE_WINDOW.Attached()))
        if (!(success = XSetWMProtocols
            (xDisplay, xWindow, &xAtom, 1)))
            DBE(("()\nfailed success = %d on XSetWMProtocols()\n", success));
        else
        error = e_ERROR_NONE;

#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual cXtApplicationShellInterface* ApplicationShell() const
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        cXtApplicationShellInterface* shellWidget = 0;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        DBT(("()...\n"));
        shellWidget = (cXtApplicationShellInterface*)(&m_shellWidget);
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return shellWidget;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AddMainEventHandler
     *
     *    Author: $author$           
     *      Date: 5/23/2010
     **********************************************************************
     */
    virtual eError AddMainEventHandler
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        EventMask eventHandlerMask = MainEventHandlerMask();
        Widget xWidget;

        DBT(("() xWidget = %p\n", shellWidget.Attached()));

        if (None != (xWidget = shellWidget.Attached()))
        {
            XtAddEventHandler
            (xWidget, eventHandlerMask, True,
             HandleXtEvent, (XtPointer)((cXtEventHandlerInterface*)(this)));
            error = e_ERROR_NONE;
        }
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: MainEventHandlerMask
     *
     *    Author: $author$           
     *      Date: 5/21/2010
     **********************************************************************
     */
    virtual EventMask MainEventHandlerMask() const
#if defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        EventMask xEventMask = NoEventMask;
#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return xEventMask;
    }
#endif /* defined(CXTAPPLICATIONSHELLMAIN_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: AfterOpenDisplay
     *
     *    Author: $author$           
     *      Date: 5/19/2010
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
        cXtApplicationShellInterface* shellWidget;

        DBT(("()...\n"));

        if (None != (m_mwmHints.AttachIntern(display)))

        if (None != (m_xAtom_WM_PROTOCOLS = m_atom_WM_PROTOCOLS.
            AttachIntern(display, "WM_PROTOCOLS", False)))

        if (None != (m_xAtom_WM_DELETE_WINDOW = m_atom_WM_DELETE_WINDOW.
            AttachIntern(display, "WM_DELETE_WINDOW", False)))

        if (!(error = BeforeCreateApplicationShell
            (display, rootXWindow, argc, argv, env)))

        if ((shellWidget = CreateApplicationShell
            (error, display, rootXWindow, argc, argv, env)))
        {
            if (!(error = AfterCreateApplicationShell
                (*shellWidget, display, rootXWindow, argc, argv, env)))

            if (!(error = RealizeApplicationShell
                (*shellWidget, display, rootXWindow, argc, argv, env)))
            {
                if ((m_xDisplay = display.Attached()))

                if (None != (m_xShellWidget = shellWidget->Attached()))

                if (None != (m_xShellWindow = XtWindow(m_xShellWidget)))

                if (!(error = AfterRealizeApplicationShell
                    (*shellWidget, display, rootXWindow, argc, argv, env)))

                if (!(error = AddMainEventHandler
                    (*shellWidget, display, rootXWindow, argc, argv, env)))

                if (!(error = SetApplicationShellWMProtocols
                    (*shellWidget, display, rootXWindow, argc, argv, env)))
                    return error;
            }

            DestroyApplicationShell
            (*shellWidget, display, rootXWindow, argc, argv, env);
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnHandle_ClientMessage_XtEvent
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual eError OnHandle_ClientMessage_XtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;
        if (xEvent.xclient.message_type == m_xAtom_WM_PROTOCOLS)
        {
            DBI(("()\n WM_PROTOCOLS\n"));

            error = OnHandle_WM_PROTOCOLS_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnHandle_WM_PROTOCOLS_XtEvent
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual eError OnHandle_WM_PROTOCOLS_XtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;
        if (xEvent.xclient.data.l[0] == m_xAtom_WM_DELETE_WINDOW)
        {
            DBI(("()\n WM_DELETE_WINDOW\n"));

            error = OnHandle_WM_DELETE_WINDOW_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnHandle_WM_DELETE_WINDOW_XtEvent
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual eError OnHandle_WM_DELETE_WINDOW_XtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;
        if (xWidget == m_xShellWidget)
        {
            continueToDispatch = False;
            SetQuit();
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTAPPLICATIONSHELLMAIN_HXX) || defined(CXTAPPLICATIONSHELLMAIN_MEMBERS_ONLY) */
