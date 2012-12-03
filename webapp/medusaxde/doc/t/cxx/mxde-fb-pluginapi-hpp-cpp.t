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
%#   File: mxde-fb-pluginapi-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 3/12/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-pluginapi-hpp-cpp.t)%)%)%,%
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
%#ifndef _%PLUGIN_NAME%API_HPP
#define _%PLUGIN_NAME%API_HPP

#include %lt%string%gt%
#include %lt%sstream%gt%
#include %lt%boost/weak_ptr.hpp%gt%
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "%Plugin_name%.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%APIEventsImplement
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%JavaScriptAPI::EventsInterface
%Plugin_name%APIEventsImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%APIExtend
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef FB::JSAPIAuto
%Plugin_name%APIExtend;
///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%API
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////
class %Plugin_name%API
: virtual public %Plugin_name%APIEventsImplement,
  public %Plugin_name%APIExtend
{
public:
    typedef %Plugin_name%APIEventsImplement EventsImplements;
    typedef %Plugin_name%JavaScriptAPI Implements;
    typedef %Plugin_name%APIExtend Extends;
    typedef %Plugin_name%API Derives;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: %Plugin_name%API
    ///
    ///       Author: %author%
    ///         Date: %date%
    ///////////////////////////////////////////////////////////////////////
    %Plugin_name%API
    (const %Plugin_name%Ptr& plugin, const FB::BrowserHostPtr& host);
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~%Plugin_name%API
    ///
    ///      Author: %author%
    ///        Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual ~%Plugin_name%API();

#define %PLUGIN_NAME%JAVASCRIPTAPI_MEMBERS_ONLY
#include "%Plugin_name%JavaScriptAPI.hpp"
#undef %PLUGIN_NAME%JAVASCRIPTAPI_MEMBERS_ONLY

protected:

    %Plugin_name%WeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    Implements* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    ///  Function: getPlugin
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual %Plugin_name%Ptr getPlugin();
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _%PLUGIN_NAME%API_HPP 
%
%)%,%(%
%#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "%Plugin_name%API.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%API
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Constructor: %Plugin_name%API::%Plugin_name%API
///
///       Author: %author%
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%API::%Plugin_name%API
(const %Plugin_name%Ptr& plugin, const FB::BrowserHostPtr& host)
: m_plugin(plugin), m_host(host), m_delegated(0)
{
    RegisterMethods();
    RegisterProperties();
    if ((plugin))
        m_delegated = plugin-%gt%Delegate((EventsImplements*)(this));
}
///////////////////////////////////////////////////////////////////////
///   Destructor: %Plugin_name%API::~%Plugin_name%API
///
///       Author: %author%
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%API::~%Plugin_name%API()
{
    %Plugin_name%Ptr plugin;
    if ((plugin = getPlugin()))
        plugin-%gt%Delegate(0);
    m_delegated = 0;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%API::getPlugin
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%Ptr %Plugin_name%API::getPlugin()
{
    %Plugin_name%Ptr plugin(m_plugin.lock());
    return plugin;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%API::Delegated
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%API::Implements* 
%Plugin_name%API::Delegated()
{
    return m_delegated;
}

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
%
%)%)%%
%)%)%%
%)%)%%
%)%)%