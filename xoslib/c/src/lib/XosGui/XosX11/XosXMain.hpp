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
///   File: XosXMain.hpp
///
/// Author: $author$
///   Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXMAIN_HPP
#define _XOSXMAIN_HPP

#include "XosXEventTarget.hpp"
#include "XosXDisplay.hpp"
#include "XosXContext.hpp"
#include "XosXEvent.hpp"
#include "XosXColormap.hpp"
#include "XosXColor.hpp"
#include "XosOptMain.hpp"
#include "XosString.hpp"

#define XOSXMAIN_DEFAULT_DISPLAY_NAME ":0"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXMainImplement
///
///  Author: $author$
///    Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
typedef XosOptMainImplement
XosXMainImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXMainExtend
///
///  Author: $author$
///    Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
typedef XosOptMain
XosXMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXMain
///
/// Author: $author$
///   Date: 5/18/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXMain
: virtual public XosXEventTargetImplement,
  virtual public XosXMainImplement,
  public XosXMainExtend
{
public:
    typedef XosXEventTargetImplement TargetImplements;
    typedef XosXMainImplement Implements;
    typedef XosXMainExtend Extends;

    XosString m_displayName;
    XosXDisplay m_display;
    XosXContext m_context;
    XosXEvent m_event;
    XosXColor m_redColor;
    XosXColor m_greenColor;
    XosXColor m_blueColor;
    XosXColor m_whiteColor;
    XosXColor m_blackColor;
    XosXColormap m_colormap;
    bool m_doneProcessXEvents;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXMain
    ///
    ///       Author: $author$
    ///         Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    XosXMain
    (const char* displayName = XOSXMAIN_DEFAULT_DISPLAY_NAME)
    : m_displayName(displayName), m_doneProcessXEvents(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXMain
    ///
    ///      Author: $author$
    ///        Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnXEvent
    ///
    ///    Author: $author$
    ///      Date: 5/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnXEvent(const XEvent& xEvent)
    {
        Display* xDisplay = xEvent.xany.display;
        Window xWindow = xEvent.xany.window;
        XosError error = XOS_ERROR_NONE;
        XosXEventTargetInterface* target;

        XOS_DBT(("()...\n"));

        if (!(error = TargetImplements::OnXEvent(xEvent)))
        if ((target = (XosXEventTargetInterface*)(m_context.Find(*xDisplay, xWindow))))
            error = target->OnXEvent(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeOnXEvent
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool BeforeOnXEvent(const XEvent& xEvent)
    {
        bool isHandled = false;

        XOS_DBT(("()...\n"));

        return isHandled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterOnXEvent
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool AfterOnXEvent(const XEvent& xEvent)
    {
        bool isHandled = false;

        XOS_DBT(("()...\n"));

        return isHandled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: IsXEvent
    ///
    ///    Author: $author$
    ///      Date: 5/21/2012
    ///////////////////////////////////////////////////////////////////////
    static Bool IsXEvent
    (Display* xDisplay, XEvent* xEvent, XPointer arg)
    {
        return True;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: PeekXEvent
    ///
    ///    Author: $author$
    ///      Date: 5/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool PeekXEvent(XEvent& xEvent, Display& xDisplay)
    {
        if (False != (XCheckIfEvent
            (&xDisplay, &xEvent, IsXEvent, (XPointer)(this))))
            return true;
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetXEvent
    ///
    ///    Author: $author$
    ///      Date: 5/21/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetXEvent(XEvent& xEvent, Display& xDisplay)
    {
        XOS_DBT(("() in...\n"));
        XNextEvent(&xDisplay, &xEvent);
        XOS_DBT(("() ...out\n"));
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ProcessXEvent
    ///
    ///    Author: $author$
    ///      Date: 8/16/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool ProcessXEvent(XEvent& xEvent, Display& xDisplay)
    {
        XosError error;

        if ((BeforeOnXEvent(xEvent)))
            return true;

        if (!(error = OnXEvent(xEvent)))
            return AfterOnXEvent(xEvent);

        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ProcessPeekXEvent
    ///
    ///    Author: $author$
    ///      Date: 8/16/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool ProcessPeekXEvent()
    {
        Display* xDisplay;
        XEvent* xEvent;

        if ((xDisplay = m_display.Attached()))
        if ((xEvent = (XEvent*)(m_event)))
        if ((PeekXEvent(*xEvent, *xDisplay)))
            return ProcessXEvent(*xEvent, *xDisplay);

        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ProcessXEvents
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int ProcessXEvents
    (int argc, char** argv, char** env)
    {
        int err = 0;
        Display* xDisplay;
        XEvent* xEvent;
        XosError error;

        XOS_DBI(("() in...\n"));

        m_doneProcessXEvents = false;

        if ((xDisplay = m_display.Attached()))
        if ((xEvent = (XEvent*)(m_event)))
        while (!(m_doneProcessXEvents))
        {
            if ((GetXEvent(*xEvent, *xDisplay)))
            if ((BeforeOnXEvent(*xEvent)))
                continue;
            else
            if (!(error = OnXEvent(*xEvent)))
            {
                AfterOnXEvent(*xEvent);
                continue;
            }
            break;
        }
        XOS_DBI(("() ...out\n"));
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeProcessXEvents
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeProcessXEvents
    (int argc, char** argv, char** env)
    {
        int err = 0;

        XOS_DBI(("()...\n"));

        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterProcessXEvents
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterProcessXEvents
    (int argc, char** argv, char** env)
    {
        int err = 0;

        XOS_DBI(("()...\n"));

        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeOpenDisplay
    ///
    ///    Author: $author$
    ///      Date: 2/8/2013
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeOpenDisplay
    (int argc, char** argv, char** env)
    {
        int err = 0;
        return err;
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
        Display* xDisplay;
        Screen* xScreen;
        Colormap xColormap;
        XosError error;
        if ((xDisplay = m_display.Attached()))
        if ((xScreen = m_display.ScreenAttached()))
        if ((xColormap = m_colormap.AttachDefaultOfScreen(xDisplay, xScreen)))
        if (!(error = m_redColor.AllocateRGB8(xDisplay, xColormap, 255,0,0)))
        {
            if (!(error = m_greenColor.AllocateRGB8(xDisplay, xColormap, 0,255,0))) {
                if (!(error = m_blueColor.AllocateRGB8(xDisplay, xColormap, 0,0,255))) {
                    if (!(error = m_whiteColor.AttachWhiteOfScreen(xScreen))) {
                        if (!(error = m_blackColor.AttachBlackOfScreen(xScreen)))
                            return 0;
                    }
                    m_blueColor.Free();
                }
                m_greenColor.Free();
            }
            m_redColor.Free();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Run
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, char** argv, char** env)
    {
        int err = 0;
        int err2;

        XOS_DBI(("()...\n"));

        if (!(err = BeforeProcessXEvents(argc, argv, env)))
        {
            err = ProcessXEvents(argc, argv, env);

            if ((err2 = AfterProcessXEvents(argc, argv, env)))
            if (!(err)) err = err2;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeRun
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRun
    (int argc, char** argv, char** env)
    {
        int err = 0;
        XosError error;

        XOS_DBI(("()...\n"));

        if ((err = BeforeOpenDisplay(argc, argv, env)))
            return err;

        //
        // Open the display
        //
        if ((error = m_display.Open(m_displayName)))
        {
            XOS_DBE(("() failed to open display \"%s\"\n", m_displayName.c_str()));
            err = 1;
        }
        else 
        if ((err = AfterOpenDisplay(argc, argv, env)))
            m_display.Close();
        else
        //
        // Create context
        //
        if ((error = m_context.CreateUnique()))
        {
            XOS_DBE(("() failed to create unique context\n"));
            m_display.Close();
            err = 1;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterRun
    ///
    ///    Author: $author$
    ///      Date: 5/18/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterRun
    (int argc, char** argv, char** env)
    {
        int err = 0;
        XosError error;

        XOS_DBI(("()...\n"));

        // 
        // Destroy context
        //
        if ((error = m_context.Destroy()))
        {
            XOS_DBE(("() failed to destroy context\n"));
            err = 1;
        }
        //
        // Close the display
        //
        if ((error = m_display.Close()))
        {
            XOS_DBE(("() failed to close display \"%s\"\n", m_displayName.c_str()));
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    // colors
    ///////////////////////////////////////////////////////////////////////
    virtual Colormap GetColorMap() const {
        return m_colormap.Attached();
    }
    virtual Pixel RedColor() const {
        return m_redColor.Attached();
    }
    virtual Pixel GreenColor() const {
        return m_greenColor.Attached();
    }
    virtual Pixel BlueColor() const {
        return m_blueColor.Attached();
    }
    virtual Pixel WhiteColor() const {
        return m_whiteColor.Attached();
    }
    virtual Pixel BlackColor() const {
        return m_blackColor.Attached();
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnDisplayOption
    ///
    ///    Author: $author$
    ///      Date: 05/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int OnDisplayOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 1;
        if ((optarg))
        if ((optarg[0]))
        {
            m_displayName.assign(optarg);
            err = 0;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnOption
    ///
    ///    Author: $author$
    ///      Date: 05/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        switch(optval)
        {
        case 's':
            err = OnDisplayOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OptionUsage
    ///
    ///    Author: $author$
    ///      Date: 05/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt)
    {
        const char* chars = "";
        switch(longopt->val)
        {
        case 's':
            chars = "Display";
            optarg = "name:screen";
            break;

        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Options
    ///
    ///    Author: $author$
    ///      Date: 05/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Options
    (const struct option*& longopts)
    {
        int err = 0;
        static const char* chars = "s:d:h";
        static struct option optstruct[]= {
            {"display", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 's'},
            {"debug-levels", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'd'},
            {"help", e_MAIN_OPT_ARGUMENT_NONE, 0, 'h'},
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXMAIN_HPP 
