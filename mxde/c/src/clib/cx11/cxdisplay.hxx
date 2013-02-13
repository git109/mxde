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
 *   File: cxdisplay.hxx
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
#if !defined(_CXDISPLAY_HXX) || defined(CXDISPLAY_MEMBERS_ONLY)
#if !defined(_CXDISPLAY_HXX) && !defined(CXDISPLAY_MEMBERS_ONLY)
#define _CXDISPLAY_HXX
#endif /* !defined(_CXDISPLAY_HXX) && !defined(CXDISPLAY_MEMBERS_ONLY) */

#if !defined(CXDISPLAY_MEMBERS_ONLY)
#include "cxdisplayinterface.hxx"
#include "cxdisplayopened.hxx"
#include "cstring.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXDisplay
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cXDisplay
: virtual public cXDisplayImplement,
  public cXDisplayOpened
{
public:
    typedef cXDisplayOpened cExtends;

    const char* m_displayNameChars;
    cString m_displayName;

    /**
     **********************************************************************
     *  Constructor: cXDisplay
     *
     *       Author: $author$           
     *         Date: 6/21/2009
     **********************************************************************
     */
    cXDisplay
    (const char* displayNameChars=0,
     Display* attached=NULL,
     bool isOpen=false)
    : cExtends(attached, isOpen),
      m_displayNameChars(displayNameChars)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXDisplay
     *
     *       Author: $author$           
     *         Date: 5/18/2010
     **********************************************************************
     */
    cXDisplay
    (Display* attached,
     bool isOpen=false,
     const char* displayNameChars=0)
    : cExtends(attached, isOpen),
      m_displayNameChars(displayNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXDisplay
     *
     *      Author: $author$           
     *        Date: 6/21/2009
     **********************************************************************
     */
    virtual ~cXDisplay()
    {
    }
#else /* !defined(CXDISPLAY_MEMBERS_ONLY) */
#endif /* !defined(CXDISPLAY_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$           
     *     Date: 6/21/2009
     **********************************************************************
     */
    virtual eError Open
    (const char* name,
     bool onlyClosed=false) 
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXDISPLAY_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        TLENGTH length;
        Display *detached, *attached;
        int isOpen;

        if ((error = Closed(onlyClosed)))
            return error;

        if (0 > (length = m_displayName.Assign(name)))
            return error = -length;

        if (!(m_displayNameChars = m_displayName.Chars(length)))
            return e_ERROR_FAILED;

        if (!(detached = OpenDetached(error, name)))
            return error;

        if (detached == (attached = Attach(detached)))
        if (0 < (isOpen = SetIsOpen()))
            return e_ERROR_NONE;
        else Detach();

        CloseDetached(*detached, name);
        error = e_ERROR_FAILED;
#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$           
     *     Date: 6/21/2009
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpen=false) 
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXDISPLAY_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        Display* detached;
        int isOpen;

        if ((error = Opened(onlyOpen, true)))
            return error;

        if (!m_displayNameChars)
            return e_ERROR_FAILED;

        if (0 > (isOpen = SetIsOpen(false)))
            return error = -isOpen;

        if ((detached = Detach()))
            error = CloseDetached
            (*detached, m_displayNameChars);
        else
        if (onlyOpen)
            error = e_ERROR_NOT_ATTACHED;

#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OpenDetached
     *
     *   Author: $author$           
     *     Date: 6/21/2009
     **********************************************************************
     */
    virtual Display* OpenDetached
    (eError& error,
     const char* name) const 
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXDISPLAY_MEMBER_FUNCS_INTERFACE */
    {
        Display* detached = NULL;
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_FAILED;
        if ((detached = XOpenDisplay(name)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XOpenDisplay(\"%s\")", name));
#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CloseDetached
     *
     *   Author: $author$           
     *     Date: 6/21/2009
     **********************************************************************
     */
    virtual eError CloseDetached
    (Display& detached, const char* name) const 
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXDISPLAY_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        int err;
        if (!(err = XCloseDisplay(&detached)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XCloseDisplay(%p)\n", &detached));
#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetRootWindow
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual Window GetRootWindow
    (int screen=-1) const 
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXDISPLAY_MEMBER_FUNCS_INTERFACE */
    {
        Window xWindow = None;
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;

        if (0 > screen)
            xWindow = GetDefaultRootWindow();
        else
        if ((xDisplay = Attached()))
            xWindow = RootWindow(xDisplay, screen);

#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return xWindow;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetDefaultRootWindow
     *
     *   Author: $author$           
     *     Date: 6/28/2009
     **********************************************************************
     */
    virtual Window GetDefaultRootWindow() const 
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXDISPLAY_MEMBER_FUNCS_INTERFACE */
    {
        Window xWindow = None;
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) 
        Display* xDisplay;

        if ((xDisplay = Attached()))
            xWindow = DefaultRootWindow(xDisplay);

#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return xWindow;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: BlackPixelOf
     *
     *    Author: $author$           
     *      Date: 4/29/2010
     **********************************************************************
     */
    virtual Pixel BlackPixelOf
    (int screen = -1) const
#if defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */
    {
        Pixel xPixel = None;
#if !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        Screen* xScreen;
        if ((xDisplay = Attached()))
        {
            if (0 > (screen))
            if ((xScreen = XDefaultScreenOfDisplay(xDisplay)))
                screen = XScreenNumberOfScreen(xScreen);
            else
            return xPixel;

            xPixel = XBlackPixel(xDisplay, screen);
        }
#else /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXDISPLAY_MEMBER_FUNCS_IMPLEMENT) */
        return xPixel;
    }
#endif /* defined(CXDISPLAY_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXDISPLAY_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXDISPLAY_MEMBERS_ONLY) */
#endif /* !defined(CXDISPLAY_MEMBERS_ONLY) */

#endif /* !defined(_CXDISPLAY_HXX) || defined(CXDISPLAY_MEMBERS_ONLY) */
