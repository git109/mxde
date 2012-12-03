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
%#   File: mxde-fb-pluginwin-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 3/12/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-pluginwin-hpp-cpp.t)%)%)%,%
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
%#ifndef _%PLUGIN_NAME%WIN_HPP
#define _%PLUGIN_NAME%WIN_HPP

#include "talk/base/win32window.h"
#include "PluginEvents/WindowsEvent.h"
#include "Win/PluginWindowWin.h"
#include "%Plugin_name%.hpp"
#include "%Plugin_name%JavaScriptAPI.hpp"
#include "%Plugin_name%WinWindow.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%WinImplement
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%Implement
%Plugin_name%WinImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%Win
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef %Plugin_name%
%Plugin_name%WinExtend;
///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%Win
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////
class %Plugin_name%Win
: virtual public %Plugin_name%WinImplement,
  public %Plugin_name%WinExtend
{
public:
    typedef %Plugin_name%WinImplement Implements;
    typedef %Plugin_name%WinExtend Extends;

    %Plugin_name%WinWindow m_window;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: %Plugin_name%Win
    ///
    ///       Author: %author%
    ///         Date: %date%
    ///////////////////////////////////////////////////////////////////////
    %Plugin_name%Win(const std::string& mimeType);
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~%Plugin_name%Win
    ///
    ///      Author: %author%
    ///        Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual ~%Plugin_name%Win();

    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::WindowsEvent, onWindowsEvent, FB::PluginWindowWin)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindowWin)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindowWin)
        PLUGIN_EVENT_MAP_CASCADE(Extends)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onWindowsEvent(FB::WindowsEvent* evt, FB::PluginWindowWin* wnd);
    virtual bool onWindowAttached(FB::AttachedEvent* evt, FB::PluginWindowWin* wnd);
    virtual bool onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindowWin* wnd);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/

    ////////////////////////////////////////////////////////////////////////
    ///  Function: Delegate
    ///
    ///    Author: %author%
    ///      Date: %date%
    ////////////////////////////////////////////////////////////////////////
    virtual Implements::Implements* Delegate(EventsInterface* events=0)
    { return m_window.Delegate(events); }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _%PLUGIN_NAME%WIN_HPP 
%
%)%,%(%
%#include "%Plugin_name%Win.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

static HMODULE s_hModule = 0;

///////////////////////////////////////////////////////////////////////
///  Function: GetThisModuleHandle
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
static HMODULE GetThisModuleHandle()
{
    static const TCHAR VariableInModule = 0; 
    HMODULE hModule = 0;
    GetModuleHandleEx
    (GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
     GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, 
     &VariableInModule, &hModule);
    return hModule;
}

///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::StaticInitialize
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
void %Plugin_name%::StaticInitialize()
{
    if ((s_hModule = GetThisModuleHandle()))
        talk_base::Win32Window::SetInstance(s_hModule);
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%::StaticDeinitialize
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
void %Plugin_name%::StaticDeinitialize()
{
    if ((s_hModule) && (GetThisModuleHandle() == s_hModule))
    {
        talk_base::Win32Window::Shutdown();
        s_hModule = 0;
    }
}

///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%Win
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Constructor: %Plugin_name%Win::%Plugin_name%Win
///
///       Author: %author%
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%Win::%Plugin_name%Win
(const std::string& mimeType)
: Extends(mimeType),
  m_window(*this)
{
}
///////////////////////////////////////////////////////////////////////
///   Destructor: %Plugin_name%Win::~%Plugin_name%Win
///
///       Author: %author%
///         Date: %date%
///////////////////////////////////////////////////////////////////////
%Plugin_name%Win::~%Plugin_name%Win()
{
}

///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%Win::onWindowsEvent
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%Win::onWindowsEvent
(FB::WindowsEvent* evt, FB::PluginWindowWin* wnd)
{
    bool handled = false;
    LRESULT lResult;
    if ((wnd-%gt%getHWND()) == (m_window.Attached()))
    if ((lResult = m_window.OnWindowMessage
        (evt-%gt%hWnd, evt-%gt%uMsg, evt-%gt%wParam, evt-%gt%lParam)))
        return true;
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%Win::onWindowAttached
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%Win::onWindowAttached
(FB::AttachedEvent* evt, FB::PluginWindowWin* wnd)
{
    bool handled = false;
    m_window.OnWindowAttached(wnd-%gt%getHWND());
    return handled;
}
///////////////////////////////////////////////////////////////////////
///  Function: %Plugin_name%Win::onWindowDetached
///
///    Author: %author%
///      Date: %date%
///////////////////////////////////////////////////////////////////////
bool %Plugin_name%Win::onWindowDetached
(FB::DetachedEvent* evt, FB::PluginWindowWin* wnd)
{
    bool handled = false;
    m_window.OnWindowDetached(wnd-%gt%getHWND());
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