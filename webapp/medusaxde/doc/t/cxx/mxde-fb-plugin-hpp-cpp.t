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
%#   File: mxde-fb-plugin-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 3/11/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-plugin-hpp-cpp.t)%)%)%,%
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
%%else(%file_cpp%,%(%
%#ifndef _%PLUGIN_NAME%_HPP
#define _%PLUGIN_NAME%_HPP

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"
#include "PluginCore.h"
#include "%Plugin_name%JavaScriptAPI.hpp"
#include "%Plugin_name%Interface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

FB_FORWARD_PTR(%Plugin_name%API)
FB_FORWARD_PTR(%Plugin_name%)

///////////////////////////////////////////////////////////////////////
// Typedef: %Plugin_name%Implement
//
//  Author: %author%
//    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%Interface
%Plugin_name%Implement;
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%Extend
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef FB::PluginCore
%Plugin_name%Extend;
///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////
class %Plugin_name%
: virtual public %Plugin_name%Implement,
  public %Plugin_name%Extend
{
public:
    typedef %Plugin_name%Implement Implements;
    typedef %Plugin_name%Extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Function: StaticInitialize
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    static void StaticInitialize();
    ///////////////////////////////////////////////////////////////////////
    ///  Function: StaticDeinitialize
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    static void StaticDeinitialize();

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: %Plugin_name%
    ///
    ///       Author: %author%
    ///         Date: %date%
    ///////////////////////////////////////////////////////////////////////
    %Plugin_name%(const std::string& mimeType);
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~%Plugin_name%
    ///
    ///      Author: %author%
    ///        Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual ~%Plugin_name%();

    ///////////////////////////////////////////////////////////////////////
    ///  Function: onPluginReady
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual void onPluginReady();
    ///////////////////////////////////////////////////////////////////////
    ///  Function: shutdown
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual void shutdown();

    ///////////////////////////////////////////////////////////////////////
    ///  Function: createJSAPI
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual FB::JSAPIPtr createJSAPI();

    ///////////////////////////////////////////////////////////////////////
    ///  Function: isWindowless
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual bool isWindowless()
    {
        bool isTrue = false;
        return isTrue;
    }

    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::MouseDownEvent, onMouseDown, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindow)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onMouseDown(FB::MouseDownEvent* evt, FB::PluginWindow* wnd);
    virtual bool onMouseUp(FB::MouseUpEvent* evt, FB::PluginWindow* wnd);
    virtual bool onWindowAttached(FB::AttachedEvent* evt, FB::PluginWindow* wnd);
    virtual bool onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindow* wnd);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/

protected:

    std::string m_mimeType;
    %Plugin_name%APIWeakPtr m_pluginAPI;

    ///////////////////////////////////////////////////////////////////////
    ///  Function: getPluginAPI
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual %Plugin_name%APIPtr getPluginAPI();
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _%PLUGIN_NAME%_HPP 
%
%)%,%(%
%#include "%Plugin_name%API.hpp"
#include "%Plugin_name%.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Constructor: %Plugin_name%::%Plugin_name%
///
///       Author: %author%
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%::%Plugin_name%
(const std::string& mimeType)
: m_mimeType(mimeType)
{
}
///////////////////////////////////////////////////////////////////////
///   Destructor: %Plugin_name%::~%Plugin_name%
///
///       Author: %author%
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%::~%Plugin_name%()
{
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::onPluginReady
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
void %Plugin_name%::onPluginReady()
{
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::shutdown
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
void %Plugin_name%::shutdown()
{
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::createJSAPI
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
FB::JSAPIPtr %Plugin_name%::createJSAPI()
{
    %Plugin_name%APIPtr pluginAPI 
    = boost::make_shared%lt%%Plugin_name%API%gt%
    (FB::ptr_cast%lt%%Plugin_name%%gt%(shared_from_this()), m_host);
    m_pluginAPI = pluginAPI;
    return pluginAPI;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::getPluginAPI
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%APIPtr %Plugin_name%::getPluginAPI()
{
    %Plugin_name%APIPtr plugin(m_pluginAPI.lock());
    return plugin;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::onMouseDown
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%::onMouseDown
(FB::MouseDownEvent* evt, FB::PluginWindow* wnd)
{
    bool handled = false;
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::onMouseUp
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%::onMouseUp
(FB::MouseUpEvent* evt, FB::PluginWindow* wnd)
{
    bool handled = false;
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::onWindowAttached
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%::onWindowAttached
(FB::AttachedEvent* evt, FB::PluginWindow* wnd)
{
    bool handled = false;
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::onWindowDetached
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%::onWindowDetached
(FB::DetachedEvent* evt, FB::PluginWindow* wnd)
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