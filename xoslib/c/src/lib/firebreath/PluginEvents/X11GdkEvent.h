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
///   File: X11GdkEvent.h
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _FB_EVENTS_X11GDKEVENT_H
#define _FB_EVENTS_X11GDKEVENT_H

#include <gdk/gdk.h>

namespace FB {

///////////////////////////////////////////////////////////////////////
///  Class: X11GdkEvent
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
class X11GdkEvent
{
public:
    GdkEvent m_gdkEvent;

    X11GdkEvent
    (GdkWindow* window=0, GdkEventType type=GDK_NOTHING, gint8 send_event=TRUE)
    {
        m_gdkEvent.any.type = type;
        m_gdkEvent.any.window = window;
        m_gdkEvent.any.send_event = send_event;
    }

    bool SendEvent()
    {
        bool sent = false;
        if ((sent = (m_gdkEvent.any.type != GDK_NOTHING) && (m_gdkEvent.any.window != 0)))
        {
            gdk_threads_enter();
            gdk_event_put(&m_gdkEvent);
            gdk_threads_leave();
        }
        return sent;
    }

    inline operator GdkEvent* () const
    { return (GdkEvent*)(&m_gdkEvent); }
};

///////////////////////////////////////////////////////////////////////
///  Class: X11GdkEventExpose
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
class X11GdkEventExpose
: public X11GdkEvent
{
public:
    typedef X11GdkEvent Extends;

    X11GdkEventExpose
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

} // namespace FB 

#endif // _FB_EVENTS_X11GDKEVENT_H 
