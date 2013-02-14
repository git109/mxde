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
///   File: XosGdkEvent.hpp
///
/// Author: $author$
///   Date: 5/2/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSGDKEVENT_HPP
#define _XOSGDKEVENT_HPP

#include "XosGtk.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosGdkEvent
///
/// Author: $author$
///   Date: 5/2/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosGdkEvent
{
public:
    GdkEvent m_gdkEvent;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosGdkEvent
    ///
    ///       Author: $author$
    ///         Date: 5/2/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkEvent
    (GdkWindow* window=0, GdkEventType type=GDK_NOTHING, gint8 send_event=TRUE)
    {
        m_gdkEvent.any.type = type;
        m_gdkEvent.any.window = window;
        m_gdkEvent.any.send_event = send_event;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Put
    ///
    ///    Author: $author$
    ///      Date: 5/2/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Put()
    {
        bool isSuccess = false;
        if ((isSuccess = ((m_gdkEvent.any.type != GDK_NOTHING) && (m_gdkEvent.any.window != 0))))
            gdk_event_put(&m_gdkEvent);
        return isSuccess;
    }

    inline operator GdkEvent* () const
    { return (GdkEvent*)(&m_gdkEvent); }
};

///////////////////////////////////////////////////////////////////////
///  Class: XosGdkEventExpose
///
/// Author: $author$
///   Date: 5/2/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosGdkEventExpose
: public XosGdkEvent
{
public:
    typedef XosGdkEvent Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosGdkEventExpose
    ///
    ///       Author: $author$
    ///         Date: 5/2/2012
    ///////////////////////////////////////////////////////////////////////
    XosGdkEventExpose
    (GdkWindow* window=0, GdkRegion* region=0,
     int x=0, int y=0, int width=0, int height=0, int count=0,
     GdkEventType type=GDK_EXPOSE, gint8 send_event=TRUE)
    : Extends(window, type, send_event)
    {
        m_gdkEvent.expose.area.x = x;
        m_gdkEvent.expose.area.y = y;
        m_gdkEvent.expose.area.width = width;
        m_gdkEvent.expose.area.height = height;
        m_gdkEvent.expose.region = region;
        m_gdkEvent.expose.count = count;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSGDKEVENT_HPP 
