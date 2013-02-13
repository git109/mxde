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
 *   File: cxwindowmain.hxx
 *
 * Author: $author$           
 *   Date: 4/21/2010
 **********************************************************************
 */
#if !defined(_CXWINDOWMAIN_HXX) || defined(CXWINDOWMAIN_MEMBERS_ONLY)
#if !defined(_CXWINDOWMAIN_HXX) && !defined(CXWINDOWMAIN_MEMBERS_ONLY)
#define _CXWINDOWMAIN_HXX
#endif /* !defined(_CXWINDOWMAIN_HXX) && !defined(CXWINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CXWINDOWMAIN_MEMBERS_ONLY)
#include "cxwindowmaininterface.hxx"
#include "cxwindow.hxx"
#include "cxatom.hxx"
#include "cxmain.hxx"

#define DEFAULT_CXWINDOWMAIN_WINDOW_X 0
#define DEFAULT_CXWINDOWMAIN_WINDOW_Y \
    DEFAULT_CXWINDOWMAIN_WINDOW_X

#define DEFAULT_CXWINDOWMAIN_WINDOW_WIDTH 100
#define DEFAULT_CXWINDOWMAIN_WINDOW_HEIGHT \
    DEFAULT_CXWINDOWMAIN_WINDOW_WIDTH

#define DEFAULT_CXWINDOWMAIN_WINDOW_BORDER_WIDTH 0
#define DEFAULT_CXWINDOWMAIN_WINDOW_BORDER 0
#define DEFAULT_CXWINDOWMAIN_WINDOW_BACKGROUND (255 << 8)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXWindowMainExtend
 *
 *  Author: $author$           
 *    Date: 4/21/2010
 **********************************************************************
 */
typedef cXMain
cXWindowMainExtend;
/**
 **********************************************************************
 *  Class: cXWindowMain
 *
 * Author: $author$           
 *   Date: 4/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXWindowMain
: virtual public cXWindowMainImplement,
  public cXWindowMainExtend
{
public:
    typedef cXWindowMainImplement cImplements;
    typedef cXWindowMainExtend cExtends;

    int m_mainWindowX;
    int m_mainWindowY;
    unsigned m_mainWindowWidth;
    unsigned m_mainWindowHeight;
    unsigned m_mainWindowBorderWidth;
    unsigned m_mainWindowBorder;
    unsigned m_mainWindowBackground;

    cXWindow m_window;
    cXAtom m_atom_WM_PROTOCOLS;
    cXAtom m_atom_WM_DELETE_WINDOW;

    /**
     **********************************************************************
     *  Constructor: cXWindowMain
     *
     *       Author: $author$           
     *         Date: 4/21/2010
     **********************************************************************
     */
    cXWindowMain
    (const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends(displayNameChars, displayScreen),
      m_mainWindowX(DEFAULT_CXWINDOWMAIN_WINDOW_X),
      m_mainWindowY(DEFAULT_CXWINDOWMAIN_WINDOW_Y),
      m_mainWindowWidth(DEFAULT_CXWINDOWMAIN_WINDOW_WIDTH),
      m_mainWindowHeight(DEFAULT_CXWINDOWMAIN_WINDOW_HEIGHT),
      m_mainWindowBorderWidth(DEFAULT_CXWINDOWMAIN_WINDOW_BORDER_WIDTH),
      m_mainWindowBorder(DEFAULT_CXWINDOWMAIN_WINDOW_BORDER),
      m_mainWindowBackground(DEFAULT_CXWINDOWMAIN_WINDOW_BACKGROUND),
      m_window(m_display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXWindowMain
     *
     *      Author: $author$           
     *        Date: 4/21/2010
     **********************************************************************
     */
    virtual ~cXWindowMain()
    {
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
        cXWindowInterface* window;
        Window rootXWindow;
        Atom xAtom;
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
                if (!(xAtom = m_atom_WM_PROTOCOLS.AttachIntern
                    (*display, "WM_PROTOCOLS", False)))
                    { DBE(("() failed on m_atom_WM_PROTOCOLS.AttachIntern()")); }

                if (!(xAtom = m_atom_WM_DELETE_WINDOW.AttachIntern
                    (*display, "WM_DELETE_WINDOW", False)))
                    { DBE(("() failed on m_atom_WM_DELETE_WINDOW.AttachIntern()")); }

                if (!(error = BeforeOpenMainWindow
                    (*display, rootXWindow, argc, argv, env)))

                if ((window = OpenMainWindow
                    (error, *display, rootXWindow,
                     m_mainWindowX, m_mainWindowY,
                     m_mainWindowWidth, m_mainWindowHeight, 
                     argc, argv, env)))
                {
                    window->SetXEventDelegateAfter(this);

                    if ((xAtom = m_atom_WM_DELETE_WINDOW.Attached()))
                        window->SetWMProtocols(&xAtom, 1);

                    if (!(error = AfterOpenMainWindow
                        (*display, *window, rootXWindow, argc, argv, env)))
                    {
                        ProcessXEvents(*display);

                        BeforeCloseMainWindow
                        (*display, *window, rootXWindow, argc, argv, env);
                    }

                    CloseMainWindow
                    (*display, *window, argc, argv, env);

                    AfterCloseMainWindow
                    (*display, rootXWindow, argc, argv, env);
                }

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

    /**
     **********************************************************************
     * Function: OnClientMessageXEvent
     *
     *   Author: $author$           
     *     Date: 2/12/2013
     **********************************************************************
     */
    virtual eError OnClientMessageXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        DBI(("() \n"));
        if (m_atom_WM_PROTOCOLS.Attached() == xEvent.xclient.message_type)
        if (m_atom_WM_DELETE_WINDOW.Attached() == (xEvent.xclient.data.l[0]))
            SetQuit();
        return error;
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
        return error;
    }
#else /* !defined(CXWINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWMAIN_MEMBERS_ONLY) */

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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        cXWindowInterface* window = 0;
#if !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) 
        if ((window = CreateMainWindow
            (error, display, rootXWindow, 
             x,y, width,height, argc, argv, env)))
             error = window->Map();
#else /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return window;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) 
        eError error2;
        error = window.Unmap();
        if ((error2 = DestroyMainWindow
            (display, window, argc, argv, env)))
        if (!error)
            error = error2;
#else /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: BeforeCloseMainWindow
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError BeforeCloseMainWindow
    (cXDisplayInterface& display,
     cXWindowInterface& window,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        return error;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        cXWindowInterface* window = 0;
#if !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) 
        cXWindowInterface* mainWindow;

        if ((mainWindow = MainWindow(error)))
        if (!(error = mainWindow->CreateSimple
            (rootXWindow, x,y, width,height, 
             m_mainWindowBorderWidth,m_mainWindowBorder, 
             m_mainWindowBackground, true)))
             window = mainWindow;

#else /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return window;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) 
        error = window.Destroy();
#else /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) 
        cXWindowInterface* window = &m_window;
        error = e_ERROR_NONE;
#else /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
        cXWindowInterface* window = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXWINDOWMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return window;
    }
#endif /* defined(CXWINDOWMAIN_MEMBER_FUNCS_INTERFACE) */

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

#if !defined(CXWINDOWMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOWMAIN_HXX) || defined(CXWINDOWMAIN_MEMBERS_ONLY) */
