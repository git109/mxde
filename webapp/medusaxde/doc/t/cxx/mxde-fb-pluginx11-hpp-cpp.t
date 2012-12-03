%########################################################################
%# Copyright (c) 1988-2012 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: mxde-fb-pluginx11-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 4/20/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-pluginx11-hpp-cpp.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-fb-hpp-cpp.t)%%
%)%,%(%
%%with(%
%plugin_name,%(%else-then(%plugin_name%,%(plugin_name)%)%)%,%
%Plugin_name,%(%else-then(%Plugin_name%,%(%plugin_name%)%)%)%,%
%PLUGIN_NAME,%(%else-then(%PLUGIN_NAME%,%(%toupper(%Plugin_name%)%)%)%)%,%
%plugin_name,%(%else-then(%_Plugin_name%,%(%tolower(%Plugin_name%)%)%)%)%,%
%Plugin_base,%(%else-then(%Plugin_base%,%(%left(%Plugin_name%,Plugin)%)%)%)%,%
%PLUGIN_BASE,%(%else-then(%PLUGIN_BASE%,%(%toupper(%Plugin_base%)%)%)%)%,%
%plugin_base,%(%else-then(%_Plugin_base%,%(%tolower(%Plugin_base%)%)%)%)%,%
%%(%
%%else(%file_mm%%file_cpp%,%(%
%#ifndef _%PLUGIN_NAME%X11_HPP
#define _%PLUGIN_NAME%X11_HPP

#include "X11/PluginWindowX11.h"
#include "PluginEvents/X11Event.h"

#include "%Plugin_name%.hpp"
#include "%Plugin_name%JavaScriptAPI.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

FB_FORWARD_PTR(%Plugin_name%X11)
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%X11Implement
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%Implement
%Plugin_name%X11Implement;
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%X11
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%
%Plugin_name%X11Extend;
///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%X11
///
/// Author: $author$
///   Date: %date%
///////////////////////////////////////////////////////////////////////
class %Plugin_name%X11
: virtual public %Plugin_name%X11Implement,
  public %Plugin_name%X11Extend
{
public:
    typedef %Plugin_name%X11Implement Implements;
    typedef %Plugin_name%X11Extend Extends;

    //%Plugin_name%X11Window m_window;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: %Plugin_name%X11
    ///
    ///       Author: %author%
    ///         Date: %date%
    ///////////////////////////////////////////////////////////////////////
    %Plugin_name%X11(const std::string& mimeType);
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~%Plugin_name%X11
    ///
    ///      Author: %author%
    ///        Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual ~%Plugin_name%X11();

    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::X11Event, onX11Event, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::ResizedEvent, onWindowResized, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::RefreshEvent, onWindowRefresh, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindowX11)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindowX11)
        PLUGIN_EVENT_MAP_CASCADE(%Plugin_name%)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onWindowAttached(FB::AttachedEvent* evt, FB::PluginWindowX11* wnd);
    virtual bool onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindowX11* wnd);
    virtual bool onWindowResized(FB::ResizedEvent *evt, FB::PluginWindowX11* wnd);
    virtual bool onWindowRefresh(FB::RefreshEvent *evt, FB::PluginWindowX11* wnd);
    virtual bool onMouseUp(FB::MouseUpEvent* evt, FB::PluginWindowX11* wnd);
    virtual bool onX11Event(FB::X11Event* evt, FB::PluginWindowX11* wnd);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/

    ////////////////////////////////////////////////////////////////////////
    ///  Function: Delegate
    ///
    ///    Author: %author%
    ///      Date: %date%
    ////////////////////////////////////////////////////////////////////////
    //virtual Implements::Implements* Delegate(EventsInterface* events=0)
    //{ return m_window.Delegate(events); }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _%PLUGIN_NAME%X11_HPP 
%
%)%,%(%
%#include "%Plugin_name%X11.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%
///
/// Author: $author$
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::StaticInitialize
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
void %Plugin_name%::StaticInitialize()
{
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::StaticDeinitialize
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
void %Plugin_name%::StaticDeinitialize()
{
}

///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%X11
///
/// Author: $author$
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Constructor: %Plugin_name%X11::%Plugin_name%X11
///
///       Author: $author$
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%X11::%Plugin_name%X11
(const std::string& mimeType)
: Extends(mimeType)
{
}
///////////////////////////////////////////////////////////////////////
///   Destructor: %Plugin_name%X11::~%Plugin_name%X11
///
///       Author: $author$
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%X11::~%Plugin_name%X11()
{
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%X11::onWindowAttached
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%X11::onWindowAttached
(FB::AttachedEvent* evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%X11::onWindowDetached
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%X11::onWindowDetached
(FB::DetachedEvent* evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    return handled;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%X11::onWindowResized
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%X11::onWindowResized
(FB::ResizedEvent *evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%X11::onWindowRefresh
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%X11::onWindowRefresh
(FB::RefreshEvent *evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    return handled;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%X11::onMouseUp
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%X11::onMouseUp
(FB::MouseUpEvent* evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    return handled;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%X11::onX11Event
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%X11::onX11Event
(FB::X11Event* evt, FB::PluginWindowX11* wnd)
{
    bool handled = false;
    return handled;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
%
%)%)%%
%)%)%%
%)%)%%
%)%)%