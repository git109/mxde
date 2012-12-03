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
%#   File: mxde-fb-pluginmac-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 4/11/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-pluginmac-hpp-cpp.t)%)%)%,%
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
%
#ifndef _%PLUGIN_NAME%MAC_HH
#define _%PLUGIN_NAME%MAC_HH

#include "Mac/PluginWindowMac.h"
#include "Mac/PluginWindowMacCG.h"
#include "Mac/PluginWindowMacCA.h"
#include "Mac/PluginWindowMacICA.h"
#include "PluginEvents/MacEventCarbon.h"
#include "PluginEvents/MacEventCocoa.h"

#include "%Plugin_name%.hpp"
#include "%Plugin_name%JavaScriptAPI.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

FB_FORWARD_PTR(%Plugin_name%Mac)
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%MacImplement
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%Implement
%Plugin_name%MacImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%Mac
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%
%Plugin_name%MacExtend;
///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%Mac
///
/// Author: $author$
///   Date: %date%
///////////////////////////////////////////////////////////////////////
class %Plugin_name%Mac
: virtual public %Plugin_name%MacImplement,
  public %Plugin_name%MacExtend
{
public:
    typedef %Plugin_name%MacImplement Implements;
    typedef %Plugin_name%MacExtend Extends;

    //%Plugin_name%MacWindow m_window;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: %Plugin_name%Mac
    ///
    ///       Author: %author%
    ///         Date: %date%
    ///////////////////////////////////////////////////////////////////////
    %Plugin_name%Mac(const std::string& mimeType);
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~%Plugin_name%Mac
    ///
    ///      Author: %author%
    ///        Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual ~%Plugin_name%Mac();

    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindowMac)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindowMac)
        EVENTTYPE_CASE(FB::CoreGraphicsDraw, onDrawCG, FB::PluginWindowMacCG)
        PLUGIN_EVENT_MAP_CASCADE(%Plugin_name%)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onWindowAttached(FB::AttachedEvent* evt, FB::PluginWindowMac* wnd);
    virtual bool onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindowMac* wnd);
    virtual bool onDrawCG(FB::CoreGraphicsDraw* evt, FB::PluginWindowMacCG* gc);
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

#endif // _%PLUGIN_NAME%MAC_HH 
%
%)%,%(%
%
#include "%Plugin_name%Mac.hh"

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
///  Class: %Plugin_name%Mac
///
/// Author: $author$
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Constructor: %Plugin_name%Mac::%Plugin_name%Mac
///
///       Author: $author$
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%Mac::%Plugin_name%Mac()
{
}
///////////////////////////////////////////////////////////////////////
///   Destructor: %Plugin_name%Mac::~%Plugin_name%Mac
///
///       Author: $author$
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%Mac::~%Plugin_name%Mac()
{
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%Mac::onWindowAttached
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%Mac::onWindowAttached
(FB::AttachedEvent* evt, FB::PluginWindowMac* wnd)
{
    bool handled = false;
    bool isCA = (FB::PluginWindowMac::DrawingModelCoreAnimation == wnd->getDrawingModel());
    bool isInvalidatingCA = (FB::PluginWindowMac::DrawingModelInvalidatingCoreAnimation == wnd->getDrawingModel());

    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%Mac::onWindowDetached
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%Mac::onWindowDetached
(FB::DetachedEvent* evt, FB::PluginWindowMac* wnd)
{
    bool handled = false;
    return handled;
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%Mac::onDrawCG
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%Mac::onDrawCG
(FB::CoreGraphicsDraw* evt, FB::PluginWindowMacCG* gc)
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