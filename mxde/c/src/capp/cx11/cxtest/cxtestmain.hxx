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
 *   File: cxtestmain.hxx
 *
 * Author: $author$           
 *   Date: 7/9/2009
 **********************************************************************
 */
#if !defined(_CXTESTMAIN_HXX) || defined(CXTESTMAIN_MEMBERS_ONLY)
#if !defined(_CXTESTMAIN_HXX) && !defined(CXTESTMAIN_MEMBERS_ONLY)
#define _CXTESTMAIN_HXX
#endif /* !defined(_CXTESTMAIN_HXX) && !defined(CXTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXTESTMAIN_MEMBERS_ONLY)
#include "cxwindowmain.hxx"
#include "cxtestmainwindow.hxx"
#include "cxmwmhints.hxx"
#include "cxatom.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXTestMain
 *
 * Author: $author$           
 *   Date: 7/9/2009
 **********************************************************************
 */
class cXTestMain
: public cXWindowMain
{
public:
    typedef cXWindowMain cExtends;

    cXMwmHints m_mwmHints;
    cXTestMainWindow m_mainWindow;

    /**
     **********************************************************************
     *  Constructor: cXTestMain
     *
     *       Author: $author$           
     *         Date: 7/9/2009
     **********************************************************************
     */
    cXTestMain()
    : m_mainWindow(m_mwmHints, cExtends::m_display)
    {
    }
    /**
     **********************************************************************
     *   Destructor: ~cXTestMain
     *
     *       Author: $author$           
     *         Date: 7/9/2009
     **********************************************************************
     */
    virtual ~cXTestMain()
    {
        DBI(("() \n"));
    }

    /**
     **********************************************************************
     * Function: OnButtonReleaseXEvent
     *
     *   Author: $author$           
     *     Date: 6/29/2010
     **********************************************************************
     */
    virtual eError OnButtonReleaseXEvent
    (const XEvent& xEvent) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

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
    {
        eError error = m_mainWindow.BeforeOpen
        (display, rootXWindow);
        return error;
    }
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
    {
        eError error = e_ERROR_NONE;
        cXTextProperty tp("Hello");
        Window xWindow;
        Display* xDisplay;

        DBI(("()...\n"));

        if (None != (xWindow = window.Attached()))
        if ((xDisplay = display.Attached()))
        {
            /*
            cXMwmHints mwmHints;
            mwmHints.ChangeHints
            (*xDisplay, xWindow, 
             MWM_HINTS_DECORATIONS, 0, MWM_DECOR_TITLE);
            */
            XMoveWindow(xDisplay, xWindow, 0,0);
            XSetWMName(xDisplay, xWindow, &(XTextProperty&)(tp));
        }
        return error;
    }
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
    {
        eError error = m_mainWindow.AfterClose
        (display, rootXWindow);
        return error;
    }
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
    {
        cXWindowInterface* window = &m_mainWindow;
        error = e_ERROR_NONE;
        return window;
    }
#else /* !defined(CXTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTESTMAIN_MEMBERS_ONLY) */

#if !defined(CXTESTMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTESTMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTESTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTESTMAIN_HXX) || defined(CXTESTMAIN_MEMBERS_ONLY) */
