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
%#   File: mxde-fb-pluginconfig-cmake.t
%#
%# Author: $author$
%#   Date: 3/6/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-pluginconfig-cmake.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-cmake.t)%%
%)%,%(%
%%with(%
%plugin_name,%(%else-then(%plugin_name%,%(plugin_name)%)%)%,%
%Plugin_name,%(%else-then(%Plugin_name%,%(%plugin_name%)%)%)%,%
%PLUGIN_NAME,%(%else-then(%PLUGIN_NAME%,%(%toupper(%Plugin_name%)%)%)%)%,%
%plugin_name,%(%else-then(%_Plugin_name%,%(%tolower(%Plugin_name%)%)%)%)%,%
%plugin_prefix,%(%else-then(%plugin_prefix%,%(plugin_prefix)%)%)%,%
%Plugin_prefix,%(%else-then(%Plugin_prefix%,%(%plugin_prefix%)%)%)%,%
%PLUGIN_PREFIX,%(%else-then(%PLUGIN_PREFIX%,%(%toupper(%Plugin_prefix%)%)%)%)%,%
%plugin_prefix,%(%else-then(%_Plugin_prefix%,%(%tolower(%Plugin_prefix%)%)%)%)%,%
%plugin_version,%(%else-then(%plugin_version%,%(plugin_version)%)%)%,%
%Plugin_version,%(%else-then(%Plugin_version%,%(%plugin_version%)%)%)%,%
%PLUGIN_VERSION,%(%else-then(%PLUGIN_VERSION%,%(%toupper(%Plugin_version%)%)%)%)%,%
%plugin_version,%(%else-then(%_Plugin_version%,%(%tolower(%Plugin_version%)%)%)%)%,%
%plugin_mimetype,%(%else-then(%plugin_mimetype%,%(plugin_mimetype)%)%)%,%
%Plugin_mimetype,%(%else-then(%Plugin_mimetype%,%(%plugin_mimetype%)%)%)%,%
%PLUGIN_MIMETYPE,%(%else-then(%PLUGIN_MIMETYPE%,%(%toupper(%Plugin_mimetype%)%)%)%)%,%
%plugin_mimetype,%(%else-then(%_Plugin_mimetype%,%(%tolower(%Plugin_mimetype%)%)%)%)%,%
%plugin_uuid_1,%(%else-then(%plugin_uuid_1%,%(plugin_uuid_1)%)%)%,%
%plugin_uuid_2,%(%else-then(%plugin_uuid_2%,%(plugin_uuid_2)%)%)%,%
%plugin_uuid_3,%(%else-then(%plugin_uuid_3%,%(plugin_uuid_3)%)%)%,%
%plugin_uuid_4,%(%else-then(%plugin_uuid_4%,%(plugin_uuid_4)%)%)%,%
%plugin_uuid_5,%(%else-then(%plugin_uuid_5%,%(plugin_uuid_5)%)%)%,%
%plugin_uuid_6,%(%else-then(%plugin_uuid_6%,%(plugin_uuid_6)%)%)%,%
%%(%
%
set(PLUGIN_NAME "%Plugin_name%")
set(PLUGIN_MIMETYPE "%Plugin_mimetype%")
set(PLUGIN_PREFIX "%Plugin_prefix%")
set(PLUGIN_VERSION "%Plugin_version%")
set(COMPANY_NAME "%organization%")
set(YEAR "%year()%")

%cc_%#
# ActiveX constants
#%_cc%
set(FBTYPELIB_NAME ${PLUGIN_NAME}Lib)
set(FBTYPELIB_DESC "${PLUGIN_NAME} ${PLUGIN_VERSION} Type Library")
set(IFBControl_DESC "${PLUGIN_NAME} Control Interface")
set(FBControl_DESC "${PLUGIN_NAME} Control Class")
set(IFBComJavascriptObject_DESC "${PLUGIN_NAME} IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "${PLUGIN_NAME} ComJavascriptObject Class")
set(IFBComEventSource_DESC "${PLUGIN_NAME} IFBComEventSource Interface")
set(AXVERSION_NUM "1")

%cc_%#
# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
#%_cc%
set(FBTYPELIB_GUID %plugin_uuid_1%)
set(IFBControl_GUID %plugin_uuid_2%)
set(FBControl_GUID %plugin_uuid_3%)
set(IFBComJavascriptObject_GUID %plugin_uuid_4%)
set(FBComJavascriptObject_GUID %plugin_uuid_5%)
set(IFBComEventSource_GUID %plugin_uuid_6%)

%cc_%#
# these are the pieces that are relevant to using it from Javascript
#%_cc%
set(ACTIVEX_PROGID "${COMPANY_NAME}.${PLUGIN_NAME}")
set(MOZILLA_PLUGINID "${COMPANY_NAME}/${PLUGIN_NAME}")

%cc_%#
# strings
#%_cc%
set(FBSTRING_CompanyName "${COMPANY_NAME}")
set(FBSTRING_FileDescription "${PLUGIN_NAME} Plugin")
set(FBSTRING_PLUGIN_VERSION "${PLUGIN_VERSION}")
set(FBSTRING_LegalCopyright "Copyright ${YEAR} ${COMPANY_NAME}")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "${PLUGIN_NAME}")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "${PLUGIN_NAME}")
set(FBSTRING_MIMEType "${PLUGIN_MIMETYPE}")

%cc_%# If you're not planning on your plugin doing any drawing, uncomment this line
#set (FB_GUI_DISABLED 1) %_cc%

%cc_%#
# Mac plugin settings. If your plugin does not draw, set these all to 0
#%_cc%
set(FBMAC_USE_QUICKDRAW 1)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 1)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 1)

%cc_%# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1) %_cc%
%
%)%)%%
%)%)%%
%)%)%