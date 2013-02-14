///
///   File: X11GdkSnippet.cpp
///
/// This code snippet illustrates the use of the "FB::X11GdkEventExpose" class to
/// implement "InvalidateWindow" on an FB X11 plugin
///
#include "PluginEvents/X11GdkEvent.h"

//
// I use this class as FBs plugin window implementation
//
class XosFBPluginX11WindowImplemented
: public XosX11WindowImplemented // Non FB version of window implementation
{
public:
    typedef XosX11WindowImplemented Extends;

    FB::PluginWindowX11* m_wnd;

    XosFBPluginX11WindowImplemented
    (FB::PluginWindowX11* wnd=0)
    : m_wnd(wnd) {}

    virtual bool InvalidateWindow
    (bool eraseBackground = true)
    {
        bool handled = false;
        GdkRegion* gdkRegion = 0;

        XOS_DBT(("()...\n"));

        if ((handled = ((m_wnd) && (m_gdkWindow))))
        {
            gdk_threads_enter();

            FB::Rect rect = m_wnd->getWindowPosition();
            FB::Rect crect = m_wnd->getWindowClipping();

            FB::X11GdkEventExpose exposeEvent
            (m_gdkWindow, gdkRegion, 
             0,0, rect.right-rect.left,rect.bottom-rect.top);

            exposeEvent.SendEvent();

            gdk_threads_leave();

            //m_wnd->InvalidateWindow();
        }
        return handled;
    }
};

//
// I noticed that "onWindowRefresh" was not being called in the following class:
//
class XosWebRtcClientFBPluginX11: XosWebRtcClientFBPlugin
{
//...
    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::X11Event, onX11Event, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::ResizedEvent, onWindowResized, FB::PluginWindowX11) //** Not being called **
        EVENTTYPE_CASE(FB::RefreshEvent, onWindowRefresh, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindowX11)
        PLUGIN_EVENT_MAP_CASCADE(XosWebRtcClientFBPlugin)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onWindowAttached(FB::AttachedEvent* evt, FB::PluginWindowX11* wnd);
    virtual bool onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindowX11* wnd);
    virtual bool onWindowResized(FB::ResizedEvent *evt, FB::PluginWindowX11* wnd);
    virtual bool onWindowRefresh(FB::RefreshEvent *evt, FB::PluginWindowX11* wnd);
    virtual bool onMouseUp(FB::MouseUpEvent* evt, FB::PluginWindowX11* wnd);
    virtual bool onX11Event(FB::X11Event* evt, FB::PluginWindowX11* wnd);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/
// ...
};

//
// So I added the following to "onX11Event"
//
bool XosWebRtcClientFBPluginX11::onX11Event
(FB::X11Event* evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    GdkEvent* gdkEvent;

    if ((evt) && (wnd))
    if ((gdkEvent = evt->m_event))
    {
        GdkEventType type = gdkEvent->type;
        switch(type)
        {
        case GDK_EXPOSE:
            XOS_DBT(("() GDK_EXPOSE...\n"));

            if (!(handled = m_windowPeer.OnX11Event
            ((XosX11WindowX11EventImplemented*)(evt))))
            {
                FB::Rect rect = wnd->getWindowPosition();
                FB::Rect crect = wnd->getWindowClipping();
                FB::RefreshEvent refreshEvent(NormalizeRect(rect));
                //
                //** Call referesh event code from here **
                //
                handled = onWindowRefresh(&refreshEvent, wnd);
                //handled = m_windowPeer.OnWindowRefresh
                //(0,0, rect.right-rect.left,rect.bottom-rect.top,
                // (XosX11WindowRefreshEventImplemented*)(&refreshEvent));
            }
            break;

        default:
            handled = m_windowPeer.OnX11Event
            ((XosX11WindowX11EventImplemented*)(evt));
        }
    }
    return handled;
}
