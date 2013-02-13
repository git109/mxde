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
 *   File: cxtmain.hxx
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
#if !defined(_CXTMAIN_HXX) || defined(CXTMAIN_MEMBERS_ONLY)
#if !defined(_CXTMAIN_HXX) && !defined(CXTMAIN_MEMBERS_ONLY)
#define _CXTMAIN_HXX
#endif /* !defined(_CXTMAIN_HXX) && !defined(CXTMAIN_MEMBERS_ONLY) */

#if !defined(CXTMAIN_MEMBERS_ONLY)
#include "cxtappcontext.hxx"
#include "cxtmaininterface.hxx"
#include "cxteventhandlerinterface.hxx"
#include "cxtcallbackinterface.hxx"
#include "cxtstring.hxx"
#include "cxmain.hxx"

#define DEFAULT_CXTMAIN_NAME "cXtMain"
#define DEFAULT_CXTMAIN_CLASS_NAME DEFAULT_CXTMAIN_NAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtMainExtend
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cXMain
cXtMainExtend;
/**
 **********************************************************************
 *  Class: cXtMain
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtMain
: virtual public cXtMainImplement,
  virtual public cXtEventHandlerImplement,
  virtual public cXtCallbackImplement,
  public cXtMainExtend
{
public:
    typedef cXtMainImplement cImplements;
    typedef cXtMainExtend cExtends;

    cXtString m_appName;
    cXtString m_appClassName;
    cXtAppContext m_appContext;

    /**
     **********************************************************************
     *  Constructor: cXtMain
     *
     *       Author: $author$           
     *         Date: 4/22/2010
     **********************************************************************
     */
    cXtMain
    (const XtChar* xtNameChars = DEFAULT_CXTMAIN_NAME,
     const XtChar* xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME,
     const tChar* displayNameChars = DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen = DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends(displayNameChars, displayScreen),
      m_appName(xtNameChars),
      m_appClassName(xtClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtMain
     *
     *       Author: $author$           
     *         Date: 4/22/2010
     **********************************************************************
     */
    cXtMain
    (const String xtName,
     const String xtClassName,
     const tChar* displayNameChars = DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen = DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends(displayNameChars, displayScreen),
      m_appName(xtName),
      m_appClassName(xtClassName)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtMain
     *
     *       Author: $author$           
     *         Date: 4/22/2010
     **********************************************************************
     */
    cXtMain
    (const String xtName,
     const String xtClassName,
     const String displayNameChars,
     int displayScreen = DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends(displayNameChars, displayScreen),
      m_appName(xtName),
      m_appClassName(xtClassName)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtMain
     *
     *      Author: $author$           
     *        Date: 4/22/2010
     **********************************************************************
     */
    virtual ~cXtMain()
    {
    }
#else /* !defined(CXTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTMAIN_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AppName
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual String AppName() const
#if defined(CXTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTMAIN_MEMBER_FUNCS_IMPLEMENT)
        String xtName = (m_appName.str());
#else /* !defined(CXTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        String xtName = 0;
#endif /* !defined(CXTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return xtName;
    }
#endif /* defined(CXTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppClassName
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual String AppClassName() const
#if defined(CXTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTMAIN_MEMBER_FUNCS_IMPLEMENT)
        String xtClassName = (m_appClassName.str());
#else /* !defined(CXTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        String xtClassName = 0;
#endif /* !defined(CXTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return xtClassName;
    }
#endif /* defined(CXTMAIN_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTMAIN_MEMBERS_ONLY)
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
        return error;
    }

    /**
     **********************************************************************
     *  Function: OnHandleXtEvent
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError xOnHandleXtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;

        continueToDispatch = True;

        switch (xEvent.type)
        {
        case ClientMessage:
            DBT(("() ClientMessage\n"));
            error = OnHandle_ClientMessage_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnHandle_ClientMessage_XtEvent
     *
     *    Author: $author$           
     *      Date: 5/19/2010
     **********************************************************************
     */
    virtual eError xOnHandle_ClientMessage_XtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;
        return error;
    }

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
    {
        cXDisplayInterface* display = 0;
        XtAppContext xtAppContext;
        String xtAppClassName;
        String xtAppName;
        Display* xDisplay;

        DBT(("()...\n"));

        error = e_ERROR_NOT_ATTACHED;

        if ((xtAppName = m_appName.str()))
        if ((xtAppClassName = m_appClassName.str()))
        if ((xtAppContext = m_appContext.Attached()))
        if ((xDisplay = XtOpenDisplay
            (xtAppContext, displayName, 
             xtAppName, xtAppClassName, 
             0,0, &m_argc,m_argv)))
        {
            if (xDisplay == (m_display.Attach(xDisplay)))
            {
                error = e_ERROR_NONE;
                return &m_display;
            }
            XtCloseDisplay(xDisplay);
        }
        else
        DBE(("() failed on XtOpenDisplay()\n"));
        return display;
    }
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
    {
        eError error = e_ERROR_NONE;
        Display* xDisplay;

        DBT(("()...\n"));

        if (!(xDisplay = display.Detach()))
            error = e_ERROR_NOT_ATTACHED;
        else
        XtCloseDisplay(xDisplay);
        return error;
    }
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
    {
        eError error = e_ERROR_NONE;

        DBT(("() in...\n"));
        XtToolkitInitialize();
        error = m_appContext.Create(true);
        DBT(("() ...out\n"));
        return error;
    }
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
    {
        eError error = e_ERROR_NONE;
        error = m_appContext.Destroy(true);
        return error;
    }

    /**
     **********************************************************************
     * Function: ProcessXEvents
     *
     *   Author: $author$           
     *     Date: 5/13/2010
     **********************************************************************
     */
    virtual eError ProcessXEvents
    (cXDisplayInterface& display, 
     XContext xContext=1) 
    {
        eError error = e_ERROR_NONE;
        XtAppContext xtAppContext;
        XEvent xEvent;
        int isTrue;

        DBI(("()...\n"));

        if ((xtAppContext = m_appContext.Attached()))
        {
            //XtAppMainLoop(xtAppContext);
            if (!(isTrue = SetQuit(false)))
            do
            {
                if (0 < (isTrue = GetXEvent(xEvent, display)))
                if (!(error = DispatchXEvent(xEvent, display, xContext)))
                    continue;

                break;
            }
            while (!Quit());
        }
        else
        DBE(("() m_appContext.Attached() is 0\n"));
        return error;
    }
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
    {
        int gotEvent = True;
        XtAppContext xtAppContext;
        if ((xtAppContext = m_appContext.Attached()))
            XtAppNextEvent(xtAppContext, &xEvent);
        else
        gotEvent = -e_ERROR_NOT_ATTACHED;
        return gotEvent;
    }
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
    {
        eError error = e_ERROR_NONE;
        XtAppContext xtAppContext;
        if ((xtAppContext = m_appContext.Attached()))
            XtDispatchEvent(&xEvent);
        else
        error = e_ERROR_NOT_ATTACHED;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTMAIN_HXX) || defined(CXTMAIN_MEMBERS_ONLY) */
