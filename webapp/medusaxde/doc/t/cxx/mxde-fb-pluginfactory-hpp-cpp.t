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
%#   File: mxde-fb-pluginfactory-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 4/20/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-pluginfactory-hpp-cpp.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-fb-hpp-cpp.t)%%
%)%,%(%
%%with(%
%Os,%(%else-then(%Os%,%()%)%)%,%
%OS,%(%else-then(%OS%,%(%toupper(%Os%)%)%)%)%,%
%os,%(%else-then(%_Os%,%(%tolower(%Os%)%)%)%)%,%
%plugin_name,%(%else-then(%plugin_name%,%(plugin_name)%)%)%,%
%Plugin_name,%(%else-then(%Plugin_name%,%(%plugin_name%)%)%)%,%
%PLUGIN_NAME,%(%else-then(%PLUGIN_NAME%,%(%toupper(%Plugin_name%)%)%)%)%,%
%plugin_name,%(%else-then(%_Plugin_name%,%(%tolower(%Plugin_name%)%)%)%)%,%
%Plugin_base,%(%else-then(%Plugin_base%,%(%left(%Plugin_name%,Plugin)%)%)%)%,%
%PLUGIN_BASE,%(%else-then(%PLUGIN_BASE%,%(%toupper(%Plugin_base%)%)%)%)%,%
%plugin_base,%(%else-then(%_Plugin_base%,%(%tolower(%Plugin_base%)%)%)%)%,%
%%(%
%%else(%file_mm%%file_cpp%,%(%
%#ifndef _%PLUGIN_NAME%%OS%FACTORY_%FILE_EXTENSION%
#define _%PLUGIN_NAME%%OS%FACTORY_%FILE_EXTENSION%

#include "FactoryBase.h"
#include %lt%boost/make_shared.hpp%gt%
#include "%Plugin_name%%Os%.%file_extension%"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: %Plugin_name%%Os%FactoryExtends
///
///  Author: %author%
///    Date: %date%
///////////////////////////////////////////////////////////////////////
typedef FB::FactoryBase
%Plugin_name%%Os%FactoryExtends;
///////////////////////////////////////////////////////////////////////
///  Class: %Plugin_name%%Os%Factory
///
/// Author: %author%
///   Date: %date%
///////////////////////////////////////////////////////////////////////
class %Plugin_name%%Os%Factory
: public %Plugin_name%%Os%FactoryExtends
{
public:
    typedef %Plugin_name%%Os%FactoryExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Function: createPlugin
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual FB::PluginCorePtr createPlugin
    (const std::string& mimetype)
    {
        FB::PluginCorePtr plugin 
        = boost::make_shared%lt%%Plugin_name%%Os%%gt%(mimetype);
        return plugin;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: globalPluginInitialize
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual void globalPluginInitialize()
    {
        %Plugin_name%::StaticInitialize();
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: globalPluginDeinitialize
    ///
    ///    Author: %author%
    ///      Date: %date%
    ///////////////////////////////////////////////////////////////////////
    virtual void globalPluginDeinitialize()
    {
        %Plugin_name%::StaticDeinitialize();
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _%PLUGIN_NAME%%OS%FACTORY_%FILE_EXTENSION% 
%
%)%,%(%
%#include "%Plugin_name%%Os%Factory.%file_extension_hpp%"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Function: getFactoryInstance
///
///    Author: $author$
///      Date: %date%
///////////////////////////////////////////////////////////////////////
FB::FactoryBasePtr getFactoryInstance()
{
    static boost::shared_ptr%lt%%Plugin_name%%Os%Factory%gt% 
    factory = boost::make_shared%lt%%Plugin_name%%Os%Factory%gt%();
    return factory;
}
%
%)%)%%
%)%)%%
%)%)%%
%)%)%