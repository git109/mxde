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
///   File: XosXWindow.hpp
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSXWINDOW_HPP) || defined(XOSXWINDOW_MEMBERS_ONLY)
#if !defined(_XOSXWINDOW_HPP) && !defined(XOSXWINDOW_MEMBERS_ONLY)
#define _XOSXWINDOW_HPP
#endif // !defined(_XOSXWINDOW_HPP) && !defined(XOSXWINDOW_MEMBERS_ONLY) 

#if !defined(XOSXWINDOW_MEMBERS_ONLY)
#include "XosXWindowInterface.hpp"
#include "XosXWindowAttached.hpp"

#define XOSXWINDOW_DEFAULT_XEVENT_MASK \
   ExposureMask|ColormapChangeMask|PropertyChangeMask|VisibilityChangeMask|\
   KeymapStateMask|EnterWindowMask|LeaveWindowMask|FocusChangeMask|\
   KeyPressMask|KeyReleaseMask|ButtonPressMask|ButtonReleaseMask|\
   PointerMotionMask|StructureNotifyMask|SubstructureNotifyMask|\
   SubstructureRedirectMask

#define XOSXWINDOW_DEFAULT_XEVENT_GRAB_MASK \
   ButtonPressMask|ButtonReleaseMask|\
   PointerMotionMask|EnterWindowMask|LeaveWindowMask

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowImplement
///
///  Author: $author$
///    Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosXWindowInterface
XosXWindowImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWindowExtend
///
///  Author: $author$
///    Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosXWindowCreatedAttached
XosXWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWindow
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXWindow
: virtual public XosXWindowImplement,
  public XosXWindowExtend
{
public:
    typedef XosXWindowImplement Implements;
    typedef XosXWindowExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXWindow
    ///
    ///       Author: $author$
    ///         Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    XosXWindow
    (Display* xDisplay=0,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : Extends(xDisplay, attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXWindow
    ///
    ///      Author: $author$
    ///        Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: CreateSimple
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError CreateSimple
    (Display& xDisplay, Window parentXWindow, 
     int x,int y, unsigned int width,unsigned int height, 
     unsigned int borderWidth, Pixel border, Pixel background, 
     bool onlyDestroyed=false)
    {
        XosError error = XOS_ERROR_FAILED;
        XosError error2;
        Window detached;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if (None != (detached = XCreateSimpleWindow
            (&xDisplay, parentXWindow, x,y, width,height, 
             borderWidth, border, background)))
        {
            Attach(&xDisplay, detached, true);
            error = XOS_ERROR_NONE;
        }
        else
        { XOS_DBE(("()\n failed on XCreateSimpleWindow()\n")); }

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy(bool onlyCreated=false)
    {
        XosError error = XOS_ERROR_FAILED;
        Display* xDisplay = 0;
        Window detached = None;
        bool isCreated = false;
        Status success;

        if (None != (detached = Detach(xDisplay, isCreated)))
        {
            if ((xDisplay))
            {
                if (!(success = XDestroyWindow(xDisplay, detached)))
                { XOS_DBE(("()\n failed on XDestroyWindow(xDisplay=%p, detached=0x%x)", xDisplay, detached)); }
                else
                error = XOS_ERROR_NONE;
            }
        }
        else
        if (!(onlyCreated))
            error = XOS_ERROR_NONE;

        return error;
    }
#else // !defined(XOSXWINDOW_MEMBERS_ONLY) 
#endif // !defined(XOSXWINDOW_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SelectInput
    ///
    ///    Author: $author$
    ///      Date: 6/2/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError SelectInput(long xEventMask)
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        int err;
        if ((m_xDisplay) && (None != m_attached))
        {
            if ((err = XSelectInput(m_xDisplay, m_attached, xEventMask)))
            { XOS_DBE(("() result %d on XSelectInput()\n", err)); }
            //else
            error = XOS_ERROR_NONE;
        }
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Map
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Map()
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        int err;
        if ((m_xDisplay) && (None != m_attached))
        {
            if ((err = XMapWindow(m_xDisplay, m_attached)))
            { XOS_DBE(("() result %d on XMapWindow()\n", err)); }
            //else
            error = XOS_ERROR_NONE;
        }
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Unmap
    ///
    ///    Author: $author$
    ///      Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Unmap()
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        int err;
        if ((m_xDisplay) && (None != m_attached))
        {
            if ((err = XUnmapWindow(m_xDisplay, m_attached)))
            { XOS_DBE(("() result %d on XUnmapWindow()\n", err)); }
            //else
            error = XOS_ERROR_NONE;
        }
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ChangeBackground
    ///
    ///    Author: $author$
    ///      Date: 2/10/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError ChangeBackground(Pixel background)
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        unsigned long valueMask = CWBackPixel;
        XSetWindowAttributes xSetWindowAttributes; 
        xSetWindowAttributes.background_pixel = background;
        error = ChangeWindowAttributes(valueMask, xSetWindowAttributes);
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ChangeWindowAttributes
    ///
    ///    Author: $author$
    ///      Date: 2/10/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError ChangeWindowAttributes
    (unsigned long valueMask, XSetWindowAttributes& xSetWindowAttributes)
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Status success;
        if ((m_xDisplay) && (None != m_attached))
        {
            if (!(success = XChangeWindowAttributes
                (m_xDisplay, m_attached, valueMask, &xSetWindowAttributes)))
            { XOS_DBE(("() failed on XChangeWindowAttributes()\n")); }
            else
            error = XOS_ERROR_NONE;
        }
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetWindowAttributes
    ///
    ///    Author: $author$
    ///      Date: 2/7/2013
    ///////////////////////////////////////////////////////////////////////
    virtual XosError GetWindowAttributes
    (XWindowAttributes& xWindowAttributes)
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
        Status success;
        if ((m_xDisplay) && (None != m_attached))
        {
            if (!(success = XGetWindowAttributes
                (m_xDisplay, m_attached, &xWindowAttributes)))
            { XOS_DBE(("() failed on XGetWindowAttributes()\n")); }
            else
            error = XOS_ERROR_NONE;
        }
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDefaultXEventMask
    ///
    ///    Author: $author$
    ///      Date: 6/2/2012
    ///////////////////////////////////////////////////////////////////////
    static long GetDefaultXEventMask()
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        static long defaultXEventMask = XOSXWINDOW_DEFAULT_XEVENT_MASK;
        return defaultXEventMask;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDefaultXEventGrabMask
    ///
    ///    Author: $author$
    ///      Date: 6/2/2012
    ///////////////////////////////////////////////////////////////////////
    static long GetDefaultXEventGrabMask()
#if defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
    {
        static long defaultXEventMask = XOSXWINDOW_DEFAULT_XEVENT_GRAB_MASK;
        return defaultXEventMask;
    }
#endif // defined(XOSXWINDOW_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSXWINDOW_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(XOSXWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSXWINDOW_MEMBERS_ONLY) 
#endif // !defined(XOSXWINDOW_MEMBERS_ONLY) 

#endif // !defined(_XOSXWINDOW_HPP) || defined(XOSXWINDOW_MEMBERS_ONLY) 
