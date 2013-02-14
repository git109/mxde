///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosXWindowMain.hpp
///
/// Author: $author$
///   Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXWINDOWMAIN_HPP
#define _XOSXWINDOWMAIN_HPP

#include "XosXMain.hpp"
#include "XosXAtom.hpp"
#include "XosXWindow.hpp"

#define XOSXWINDOWMAIN_DEFAULT_WINDOW_X 0
#define XOSXWINDOWMAIN_DEFAULT_WINDOW_Y \
    XOSXWINDOWMAIN_DEFAULT_WINDOW_X

#define XOSXWINDOWMAIN_DEFAULT_WINDOW_WIDTH 100
#define XOSXWINDOWMAIN_DEFAULT_WINDOW_HEIGHT \
    XOSXWINDOWMAIN_DEFAULT_WINDOW_WIDTH

#define XOSXWINDOWMAIN_DEFAULT_WINDOW_BORDER_WIDTH 0
#define XOSXWINDOWMAIN_DEFAULT_WINDOW_BORDER_COLOR 0
#define XOSXWINDOWMAIN_DEFAULT_WINDOW_BACKGROUND_COLOR 0

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowMainImplement
///
///  Author: $author$
///    Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosXMainImplement
XosXWindowMainImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowMainExtend
///
///  Author: $author$
///    Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosXMain
XosXWindowMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWindowMain
///
/// Author: $author$
///   Date: 5/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXWindowMain
: virtual public XosXWindowMainImplement,
  public XosXWindowMainExtend
{
public:
    typedef XosXWindowMainImplement Implements;
    typedef XosXWindowMainExtend Extends;

    int m_mainWindowX;
    int m_mainWindowY;
    unsigned m_mainWindowWidth;
    unsigned m_mainWindowHeight;
    unsigned m_mainWindowBorderWidth;
    Pixel m_mainWindowBorderColor;
    Pixel m_mainWindowBackgroundColor;
    XosXWindowInterface* m_mainWindow;

    XosXWindow m_rootWindow;
    XosXWindow m_defaultMainWindow;

    XosXAtom m_atom_WM_PROTOCOLS;
    XosXAtom m_atom_WM_DELETE_WINDOW;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXWindowMain
    ///
    ///       Author: $author$
    ///         Date: 5/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosXWindowMain
    (const char* displayName=XOSXMAIN_DEFAULT_DISPLAY_NAME)
    : Extends(displayName),
      m_mainWindowX(XOSXWINDOWMAIN_DEFAULT_WINDOW_X),
      m_mainWindowY(XOSXWINDOWMAIN_DEFAULT_WINDOW_Y),
      m_mainWindowWidth(XOSXWINDOWMAIN_DEFAULT_WINDOW_WIDTH),
      m_mainWindowHeight(XOSXWINDOWMAIN_DEFAULT_WINDOW_HEIGHT),
      m_mainWindowBorderWidth(XOSXWINDOWMAIN_DEFAULT_WINDOW_BORDER_WIDTH),
      m_mainWindowBorderColor(XOSXWINDOWMAIN_DEFAULT_WINDOW_BORDER_COLOR),
      m_mainWindowBackgroundColor(XOSXWINDOWMAIN_DEFAULT_WINDOW_BACKGROUND_COLOR),
      m_mainWindow(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXWindowMain
    ///
    ///      Author: $author$
    ///        Date: 5/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXWindowMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: OnClientMessageXEvent
    ///
    ///   Author: $author$
    ///     Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnClientMessageXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
        XOS_DBI(("()...\n"));
        if (m_atom_WM_PROTOCOLS.Attached() == xEvent.xclient.message_type)
            error = On_WM_PROTOCOLS_ClientMessageXEvent(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_PROTOCOLS_ClientMessageXEvent
    ///
    ///   Author: $author$
    ///     Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On_WM_PROTOCOLS_ClientMessageXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
        XOS_DBI(("()...\n"));
        if (m_atom_WM_DELETE_WINDOW.Attached() == (xEvent.xclient.data.l[0]))
            error = On_WM_DELETE_WINDOW_ClientMessageXEvent(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: On_WM_DELETE_WINDOW_ClientMessageXEvent
    ///
    ///   Author: $author$
    ///     Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError On_WM_DELETE_WINDOW_ClientMessageXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
        XOS_DBI(("()...\n"));
        m_doneProcessXEvents = true;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterOpenDisplay
    ///
    ///    Author: $author$
    ///      Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterOpenDisplay
    (int argc, char** argv, char** env)
    {
        int err = 0;
        if (!(err = Extends::AfterOpenDisplay(argc, argv, env))) {
            m_mainWindowBorderColor = GetMainWindowBorderColor();
            m_mainWindowBackgroundColor = GetMainWindowBackgroundColor();
        }
        return err;
    }
    virtual Pixel GetMainWindowBorderColor() const {
        return BlackColor();
    }
    virtual Pixel GetMainWindowBackgroundColor() const {
        return WhiteColor();
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeProcessXEvents
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeProcessXEvents
    (int argc, char** argv, char** env)
    {
        int err = 1;
        Display* xDisplay = 0;
        Window xWindow = None;
        Atom xAtom = None;
        bool isCreated = false;

        XOS_DBI(("()...\n"));

        if ((xDisplay = m_display.Attached()))
        if (None != (xWindow = m_display.RootWindowAttached()))
        {
            m_rootWindow.Attach(xDisplay, xWindow, isCreated);

            if (!(xAtom = m_atom_WM_PROTOCOLS.AttachIntern
                (xDisplay, "WM_PROTOCOLS", False)))
                { XOS_DBE(("() failed on m_atom_WM_PROTOCOLS.AttachIntern()")); }

            if (!(xAtom = m_atom_WM_DELETE_WINDOW.AttachIntern
                (xDisplay, "WM_DELETE_WINDOW", False)))
                { XOS_DBE(("() failed on m_atom_WM_DELETE_WINDOW.AttachIntern()")); }

            if (!(err = BeforeOpenMainWindow(argc, argv, env)))
            if ((m_mainWindow = OpenMainWindow(argc, argv, env)))
            {
                if ((xAtom = m_atom_WM_DELETE_WINDOW.Attached()))
                if ((xWindow = (m_mainWindow->Attached()))) 
                {
                    if (!(XSetWMProtocols(xDisplay, xWindow, &xAtom, 1)))
                        { XOS_DBE(("() failed on XSetWMProtocols()")); }
                }

                if (!(err = AfterOpenMainWindow(*m_mainWindow, argc, argv, env)))
                    return err;

                CloseMainWindow(m_mainWindow, argc, argv, env);
                m_mainWindow = 0;
            }
            else err = 1;

            xWindow = m_rootWindow.Detach(xDisplay, isCreated);
       }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterProcessXEvents
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterProcessXEvents
    (int argc, char** argv, char** env)
    {
        Display* xDisplay = 0;
        Window xWindow = None;
        bool isCreated = false;
        int err = 1;
        int err2;

        XOS_DBI(("()...\n"));

        if ((m_mainWindow))
        {
            err = BeforeCloseMainWindow(*m_mainWindow, argc, argv, env);

            if ((err2 = CloseMainWindow(m_mainWindow, argc, argv, env)))
            if (!(err)) err = err2;

            m_mainWindow = 0;
        }
        xWindow = m_rootWindow.Detach(xDisplay, isCreated);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeOpenMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeOpenMainWindow
    (int argc, char** argv, char** env)
    {
        int err = 0;

        XOS_DBI(("()...\n"));

        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterOpenMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterOpenMainWindow
    (XosXWindowInterface& mainWindow,
     int argc, char** argv, char** env)
    {
        int err = 0;

        XOS_DBI(("()...\n"));

        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeCloseMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeCloseMainWindow
    (XosXWindowInterface& mainWindow,
     int argc, char** argv, char** env)
    {
        int err = 0;

        XOS_DBI(("()...\n"));

        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterCloseMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterCloseMainWindow
    (int argc, char** argv, char** env)
    {
        int err = 0;

        XOS_DBI(("()...\n"));

        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OpenMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosXWindowInterface* OpenMainWindow
    (int argc, char** argv, char** env)
    {
        XosXWindowInterface* mainWindow = 0;
        Display* xDisplay;
        Window xWindow;

        XOS_DBI(("()...\n"));

        if ((xDisplay = m_display.Attached()))
        if ((mainWindow = CreateMainWindow(argc, argv, env)))
        {
            XosXEventTargetInterface* eventTarget = mainWindow;

            if (None != (xWindow = mainWindow->Attached()))
                m_context.Save(*xDisplay, xWindow, (XPointer)(eventTarget));

            mainWindow->Map();
        }
        return mainWindow;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: CloseMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int CloseMainWindow
    (XosXWindowInterface* mainWindow,
     int argc, char** argv, char** env)
    {
        int err = 0;
        Display* xDisplay;
        Window xWindow;

        XOS_DBI(("()...\n"));

        if ((xDisplay = m_display.Attached()))
        if ((mainWindow))
        {
            mainWindow->Unmap();

            if (None != (xWindow = mainWindow->Attached()))
                m_context.Delete(*xDisplay, xWindow);

            err = DestroyMainWindow(mainWindow, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: CreateMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosXWindowInterface* CreateMainWindow
    (int argc, char** argv, char** env)
    {
        XosXWindowInterface* mainWindow = 0;
        Display* xDisplay = 0;
        Window xWindow = None;

        XOS_DBI(("()...\n"));

        if (None != (xWindow = m_rootWindow.Attached(xDisplay)))
        if ((xDisplay))
        if ((mainWindow = CreateMainWindow(*xDisplay, xWindow, argc, argv, env)))
        {
            long xEventMask = XosXWindow::GetDefaultXEventMask();
            mainWindow->SelectInput(xEventMask);
        }
        /*if (!(error = m_defaultMainWindow.CreateSimple
            (*xDisplay, xWindow, 
             m_mainWindowX,m_mainWindowY, m_mainWindowWidth,m_mainWindowHeight, 
             m_mainWindowBorderWidth, m_mainWindowBorderColor, m_mainWindowBackgroundColor)))
        {
            m_defaultMainWindow.SelectInput(xEventMask);
            mainWindow = &m_defaultMainWindow;
        }*/
        return mainWindow;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: CreateMainWindow
    ///
    ///    Author: $author$
    ///      Date: 6/20/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosXWindowInterface* CreateMainWindow
    (Display& xDisplay, Window xWindow, 
     int argc, char** argv, char** env)
    {
        XosXWindowInterface* mainWindow = 0;
        XosError error;
        if (!(error = m_defaultMainWindow.CreateSimple
            (xDisplay, xWindow, 
             m_mainWindowX,m_mainWindowY, m_mainWindowWidth,m_mainWindowHeight, 
             m_mainWindowBorderWidth, m_mainWindowBorderColor, m_mainWindowBackgroundColor)))
            mainWindow = &m_defaultMainWindow;
        return mainWindow;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DestroyMainWindow
    ///
    ///    Author: $author$
    ///      Date: 5/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int DestroyMainWindow
    (XosXWindowInterface* mainWindow,
     int argc, char** argv, char** env)
    {
        XosXWindowInterface* mainWindowInterface = &m_defaultMainWindow;
        int err = 1;
        XosError error;

        XOS_DBI(("()...\n"));

        if ((mainWindow == mainWindowInterface))
        {
            //mainWindow->SelectInput(0);
            if (!(error = m_defaultMainWindow.Destroy()))
                err = 0;
        }
        return err;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXWINDOWMAIN_HPP 
