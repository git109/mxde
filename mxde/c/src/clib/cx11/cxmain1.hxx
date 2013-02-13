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
#include "cxwindow.hxx"
#include "cargmain.hxx"
#include "cdebug.hxx"

#define DEFAULT_CXMAIN_DISPLAY_NAME ":0"
#define DEFAULT_CXMAIN_DISPLAY_SCREEN -1

#define DEFAULT_CXMAIN_WINDOW_X 0
#define DEFAULT_CXMAIN_WINDOW_Y \
    DEFAULT_CXMAIN_WINDOW_X

#define DEFAULT_CXMAIN_WINDOW_WIDTH 100
#define DEFAULT_CXMAIN_WINDOW_HEIGHT \
    DEFAULT_CXMAIN_WINDOW_WIDTH

#define DEFAULT_CXMAIN_WINDOW_BORDER_WIDTH 0
#define DEFAULT_CXMAIN_WINDOW_BORDER 0
#define DEFAULT_CXMAIN_WINDOW_BACKGROUND (255 << 8)

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
 *  Class: cXMain
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class cXMain
: virtual public cXMainImplement,
  public cArgMain
{
public:

    static cXMainInterface* m_theXMain;
    cXMainInterface* m_oldXMain;

    const tChar* m_displayNameChars;
    tString m_displayName;
    int m_displayScreen;

    int m_mainWindowX;
    int m_mainWindowY;
    unsigned m_mainWindowWidth;
    unsigned m_mainWindowHeight;
    unsigned m_mainWindowBorderWidth;
    unsigned m_mainWindowBorder;
    unsigned m_mainWindowBackground;

    bool m_quit;

    cXDisplay m_display;
    cXWindow m_window;

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
      m_mainWindowX(DEFAULT_CXMAIN_WINDOW_X),
      m_mainWindowY(DEFAULT_CXMAIN_WINDOW_Y),
      m_mainWindowWidth(DEFAULT_CXMAIN_WINDOW_WIDTH),
      m_mainWindowHeight(DEFAULT_CXMAIN_WINDOW_HEIGHT),
      m_mainWindowBorderWidth(DEFAULT_CXMAIN_WINDOW_BORDER_WIDTH),
      m_mainWindowBorder(DEFAULT_CXMAIN_WINDOW_BORDER),
      m_mainWindowBackground(DEFAULT_CXMAIN_WINDOW_BACKGROUND),
      m_quit(false),
      m_window(m_display)
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
     * Function: OnButtonReleaseXEvent
     *
     *   Author: $author$           
     *     Date: 6/20/2009
     **********************************************************************
     */
    virtual eError OnButtonReleaseXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        DBI(("() \n"));
        SetQuit();
        return error;
    }
#else /* !defined(CXMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMAIN_MEMBERS_ONLY) */

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
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        tInt err = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        cXDisplayInterface* display;
        cXWindowInterface* window;
        Window rootXWindow;
        eError error;

        if (!(error = BeforeOpenDisplay
            (m_displayNameChars, argc, argv, env)))

        if ((display = OpenDisplay
            (error, m_displayNameChars, argc, argv, env)))
        {
            if (None != (rootXWindow = 
                display->GetRootWindow(m_displayScreen)))

            if (!(error = BeforeOpenMainWindow
                (*display, rootXWindow,
                 argc, argv, env)))

            if ((window = OpenMainWindow
                (error, *display, rootXWindow,
                 m_mainWindowX, m_mainWindowY,
                 m_mainWindowWidth, m_mainWindowHeight, 
                 argc, argv, env)))
            {
                window->SetXEventDelegateAfter(this);

                if (!(error = AfterOpenMainWindow
                    (*display, *window, rootXWindow,
                     argc, argv, env)))
                    ProcessXEvents(*display);

                CloseMainWindow
                (*display, *window, argc, argv, env);

                AfterCloseMainWindow
                (*display, rootXWindow,
                 argc, argv, env);
            }
            CloseDisplay
            (*display, m_displayNameChars, argc, argv, env);

            AfterCloseDisplay
            (m_displayNameChars, argc, argv, env);
        }
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

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
     * Function: OpenMainWindow
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual cXWindowInterface* OpenMainWindow
    (eError& error,
     cXDisplayInterface& display,
     Window rootXWindow,
     int x,int y,
     unsigned int width,
     unsigned int height,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        cXWindowInterface* window = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        if ((window = CreateMainWindow
            (error, display, rootXWindow, 
             x,y, width,height, argc, argv, env)))
             error = window->Map();
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return window;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CloseMainWindow
     *
     *   Author: $author$           
     *     Date: 6/25/2009
     **********************************************************************
     */
    virtual eError CloseMainWindow
    (cXDisplayInterface& display,
     cXWindowInterface& window,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        eError error2;
        error = window.Unmap();
        if ((error2 = DestroyMainWindow
            (display, window, argc, argv, env)))
        if (!error)
            error = error2;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: BeforeOpenMainWindow
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError BeforeOpenMainWindow
    (cXDisplayInterface& display,
     Window rootXWindow,
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
     * Function: AfterOpenMainWindow
     *
     *   Author: $author$           
     *     Date: 4/13/2010
     **********************************************************************
     */
    virtual eError AfterOpenMainWindow
    (cXDisplayInterface& display,
     cXWindowInterface& window,
     Window rootXWindow,
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
     * Function: AfterCloseMainWindow
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError AfterCloseMainWindow
    (cXDisplayInterface& display,
     Window rootXWindow,
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
     * Function: CreateMainWindow
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual cXWindowInterface* CreateMainWindow
    (eError& error,
     cXDisplayInterface& display,
     Window rootXWindow,
     int x,int y,
     unsigned int width,
     unsigned int height,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        cXWindowInterface* window = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        cXWindowInterface* mainWindow;

        if ((mainWindow = MainWindow(error)))
        if (!(error = mainWindow->CreateSimple
            (rootXWindow,
             m_mainWindowX,m_mainWindowY, 
             m_mainWindowWidth,m_mainWindowHeight, 
             m_mainWindowBorderWidth,m_mainWindowBorder, 
             m_mainWindowBackground, true)))
             window = mainWindow;

#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return window;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyMainWindow
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual eError DestroyMainWindow
    (cXDisplayInterface& display,
     cXWindowInterface& window,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        error = window.Destroy();
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: MainWindow
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual cXWindowInterface* MainWindow
    (eError& error) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        cXWindowInterface* window = &m_window;
        error = e_ERROR_NONE;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        cXWindowInterface* window = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return window;
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

    /**
     **********************************************************************
     * Function: SetWidth
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual tLength SetWidth
    (tSize toValue) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        tLength value = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_mainWindowWidth = toValue);
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Width
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual tSize Width() const 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        tSize value = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        value = m_mainWindowWidth;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetHeight
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual tLength SetHeight
    (tSize toValue) 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        tLength value = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        value = (m_mainWindowHeight = toValue);
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Height
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual tSize Height() const 
#if defined(CXMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXMAIN_MEMBER_FUNCS_INTERFACE */
    {
        tSize value = 0;
#if !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) 
        value = m_mainWindowHeight;
#else /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return value;
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
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXMAIN_HXX) || defined(CXMAIN_MEMBERS_ONLY) */
