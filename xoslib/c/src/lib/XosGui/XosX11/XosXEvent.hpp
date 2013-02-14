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
///   File: XosXEvent.hpp
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXEVENT_HPP
#define _XOSXEVENT_HPP

#include "XosXInterfaceBase.hpp"
#include "XosXBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef XosXInterfaceBase XosXEventImplement;
typedef XosXBase XosXEventExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXEvent
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXEvent
: virtual public XosXEventImplement,
  public XosXEventExtend
{
public:
    typedef XosXEventImplement Implements;
    typedef XosXEventExtend Extends;

    XEvent m_xEvent;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXEvent
    ///
    ///       Author: $author$
    ///         Date: 4/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosXEvent
    (Display *display=0, Window window=None,
     int type=-1, Bool send_event=True, unsigned long serial=0)
    {
        m_xEvent.xany.display = display;
        m_xEvent.xany.window = window;
        m_xEvent.xany.send_event = send_event;
        m_xEvent.xany.serial = serial;
        m_xEvent.xany.type = type;
    }
    virtual XosError Send(Bool propigate=False, long eventMask=0) {
        XosError error = XOS_ERROR_FAILED;
        Status success;
        if ((m_xEvent.xany.display != 0) && (m_xEvent.xany.window != None)) {
            if ((success = XSendEvent
                (m_xEvent.xany.display, m_xEvent.xany.window, 
                 propigate, eventMask, &m_xEvent)))
                error = XOS_ERROR_NONE;
            else
            XOS_DBE(("() failed on XSendEvent()\n"));
        }
        return error;
    }
    inline operator XEvent* () const
    { return (XEvent*)(&m_xEvent); }
};

///////////////////////////////////////////////////////////////////////
///  Class: XosXExposeEvent
///
/// Author: $author$
///   Date: 4/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXExposeEvent
: public XosXEvent
{
public:
    typedef XosXEvent Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXExposeEvent
    ///
    ///       Author: $author$
    ///         Date: 4/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosXExposeEvent
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

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXEVENT_HPP 
        

