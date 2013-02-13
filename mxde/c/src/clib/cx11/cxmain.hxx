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
 *   File: cxmain.hxx
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
#if !defined(_CXMAIN_HXX) || defined(CXMAIN_MEMBERS_ONLY)
#if !defined(_CXMAIN_HXX) && !defined(CXMAIN_MEMBERS_ONLY)
#define _CXMAIN_HXX
#endif /* !defined(_CXMAIN_HXX) && !defined(CXMAIN_MEMBERS_ONLY) */

#if !defined(CXMAIN_MEMBERS_ONLY)
#include "cxmaininterface.hxx"
#include "cxdisplay.hxx"
#include "cargmain.hxx"
#include "cdebug.hxx"

#define DEFAULT_CXMAIN_DISPLAY_NAME ":0"
#define DEFAULT_CXMAIN_DISPLAY_SCREEN -1

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXMainArg
 *
 *  Author: $author$           
 *    Date: 6/22/2009
 **********************************************************************
 */
typedef cMainArg
cXMainArg;

/**
 **********************************************************************
 * Typedef: cXMainExtend
 *
 *  Author: $author$           
 *    Date: 6/24/2010
 **********************************************************************
 */
typedef cArgMain
cXMainExtend;

/**
 **********************************************************************
 *  Class: cXMain
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cXMain
: virtual public cXMainImplement,
  public cXMainExtend
{
public:
    typedef cXMainImplement cImplements;
    typedef cXMainExtend cExtends;

    static cXMainInterface* m_theXMain;
    cXMainInterface* m_oldXMain;

    const tChar* m_displayNameChars;
    tString m_displayName;
    int m_displayScreen;

    bool m_quit;

    cXDisplay m_display;

    /**
     **********************************************************************
     *  Constructor: cXMain
     *
     *       Author: $author$           
     *         Date: 6/21/2009
     **********************************************************************
     */
    cXMain
    (const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : m_oldXMain(m_theXMain),
      m_displayNameChars(displayNameChars),
      m_displayScreen(displayScreen),
      m_quit(false)
    {
        m_theXMain = this;
    }
    /**
     **********************************************************************
     *  Destructor: ~cXMain
     *
     *      Author: $author$           
     *        Date: 6/21/2009
     **********************************************************************
     */
    virtual ~cXMain()
    {
        DBI(("() \n"));
        if (this == m_theXMain)
            m_theXMain = m_oldXMain;
    }

    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    virtual tInt Run
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt err = 0;
        cXDisplayInterface* display;
        Window rootXWindow;
        eError error;

        if (!(error = BeforeOpenDisplay
            (m_displayNameChars, argc, argv, env)))

        if ((display = OpenDisplay
            (error, m_displayNameChars, argc, argv, env)))
        {
            if (None == (rootXWindow = 
                display->GetRootWindow(m_displayScreen)))
                DBW(("() root window is None\n"));

            if (!(error = AfterOpenDisplay
                (*display, rootXWindow, argc, argv, env)))
            {
                ProcessXEvents(*display);

                BeforeCloseDisplay
                (*display, rootXWindow, argc, argv, env);
            }

            CloseDisplay
            (*display, m_displayNameChars, argc, argv, env);

            AfterCloseDisplay
            (m_displayNameChars, argc, argv, env);
        }
        return err;
    }
#else /* !defined(CXMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMAIN_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: ProcessXEvents
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    virtual eError ProcessXEvents
    (cXDisplayInterface& display, 
     XContext xContext=1) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        XEvent xEvent;
        int isTrue;

        if (!(isTrue = SetQuit(false)))
        while (!Quit())
        {
            if (0 < (isTrue = GetXEvent(xEvent, display)))
            if (!(error = DispatchXEvent(xEvent, display, xContext)))
                continue;

            break;
        }
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetXEvent
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    virtual int GetXEvent
    (XEvent& xEvent,
     cXDisplayInterface& display) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        int gotEvent = -e_ERROR_NOT_ATTACHED;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;
        int err;
        if ((xDisplay = display.Attached()))
        if (!(err = XNextEvent(xDisplay, &xEvent)))
            gotEvent = true;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return gotEvent;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DispatchXEvent
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    virtual eError DispatchXEvent
    (XEvent& xEvent, 
     cXDisplayInterface& display, 
     XContext xContext=1) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT)
        cXEventTargetInterface* target;
        Display* xDisplay;
        Window xWindow;
        eError error2;

        if ((xDisplay = display.Attached()))
        if (None != (xWindow = xEvent.xany.window))
        if ((target = FindTarget
            (error2, *xDisplay, xWindow, xContext)))
            return error = target->OnXEvent(xEvent);

        error = OnXEvent(xEvent);
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OpenDisplay
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual cXDisplayInterface* OpenDisplay
    (eError& error,
     const char* displayName,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        cXDisplayInterface* display = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_FAILED;
        if ((displayName))
        if (!(error = m_display.Open(displayName)))
            display = &m_display;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return display;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CloseDisplay
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual eError CloseDisplay
    (cXDisplayInterface& display,
     const char* displayName,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        eError error = display.Close();
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: BeforeOpenDisplay
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError BeforeOpenDisplay
    (const char* displayName,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AfterOpenDisplay
     *
     *    Author: $author$           
     *      Date: 4/21/2010
     **********************************************************************
     */
    virtual eError AfterOpenDisplay
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: BeforeCloseDisplay
     *
     *    Author: $author$           
     *      Date: 4/21/2010
     **********************************************************************
     */
    virtual eError BeforeCloseDisplay
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AfterCloseDisplay
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError AfterCloseDisplay
    (const char* displayName,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetQuit
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    virtual int SetQuit
    (bool isTrue=true) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        m_quit = isTrue;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        isTrue = false;
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Quit
     *
     *   Author: $author$           
     *     Date: 6/27/2009
     **********************************************************************
     */
    virtual bool Quit() const 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        bool isTrue = m_quit;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        bool isTrue = false;
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetDisplayName
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual tLength SetDisplayName
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        tLength count = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        if (0 <= (count = m_displayName.Assign(chars, length)))
        if ((chars = m_displayName.Chars(length)))
             m_displayNameChars = chars;
        else
        m_displayNameChars = DEFAULT_CXMAIN_DISPLAY_NAME;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DisplayName
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual const tChar* DisplayName() const 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        const tChar* chars = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        chars = m_displayNameChars;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: TheXMain
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    static cXMainInterface* TheXMain() 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    ;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        return m_theXMain;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXMAIN_MEMBERS_ONLY)
#include "cxobjectimplement_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXMAIN_HXX) || defined(CXMAIN_MEMBERS_ONLY) */
