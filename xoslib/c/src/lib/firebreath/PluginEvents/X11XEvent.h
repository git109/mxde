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
///   File: X11XEvent.h
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _FB_EVENTS_X11XEVENT_H
#define _FB_EVENTS_X11XEVENT_H

#include <X11/Xlib.h>

namespace FB {

///////////////////////////////////////////////////////////////////////
///  Class: X11XEvent
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
class X11XEvent
{
public:
    XEvent m_xEvent;

    X11XEvent
    (Display *display=0, Window window=None,
     int type=-1, Bool send_event=True, unsigned long serial=0)
    {
        m_xEvent.xany.display = display;
        m_xEvent.xany.window = window;
        m_xEvent.xany.send_event = send_event;
        m_xEvent.xany.serial = serial;
        m_xEvent.xany.type = type;
    }

    bool SendEvent
    (bool propagate, long eventMask)
    {
        bool sent = false;

        if ((m_xEvent.xany.display != 0) && (m_xEvent.xany.window != None) 
            && (m_xEvent.xany.type > 1) && (m_xEvent.xany.type < LASTEvent))
        {
            sent = (Success == XSendEvent
            (m_xEvent.xany.display, m_xEvent.xany.window, propagate, eventMask, &m_xEvent));
        }
        return sent;
    }

    inline operator XEvent* () const
    { return (XEvent*)(&m_xEvent); }
};

///////////////////////////////////////////////////////////////////////
///  Class: X11ExposeXEvent
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
class X11ExposeXEvent
: public X11XEvent
{
public:
    typedef X11XEvent Extends;

    X11ExposeXEvent
    (Display *display=0, Window window=None,
     int x=0, int y=0, int width=0, int height=0, int count=0,
     int type=Expose, Bool send_event=True, unsigned long serial=0)
    : Extends(display, window, type, send_event, serial)
    {
        m_xEvent.xexpose.x = x;
        m_xEvent.xexpose.y = y;
        m_xEvent.xexpose.width = width;
        m_xEvent.xexpose.height = height;
        m_xEvent.xexpose.count = count;
    }
};

} // namespace FB 

#endif // _FB_EVENTS_X11XEVENT_H 
