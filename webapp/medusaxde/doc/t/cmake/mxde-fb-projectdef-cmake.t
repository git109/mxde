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
%#   File: mxde-fb-projectdef-cmake.t
%#
%# Author: $author$
%#   Date: 3/6/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-projectdef-cmake.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-cmake.t)%%
%)%,%(%
%%with(%
%platform,%(%else-then(%platform%,%(Win)%)%)%,%
%Platform,%(%else-then(%Platform%,%(%platform%)%)%)%,%
%PLATFORM,%(%else-then(%PLATFORM%,%(%toupper(%Platform%)%)%)%)%,%
%platform,%(%else-then(%_Platform%,%(%tolower(%Platform%)%)%)%)%,%
%%(%
%%if(%equal(Win,%Platform%)%,%(%
%
%cc_%#
# Windows template platform definition CMake file
# Included from ../CMakeLists.txt
#%_cc%
set (VCVersion "vc9")

%cc_%#
# remember that the current source dir is the project root; this file is in Win/
#%_cc%
file (GLOB PLATFORM RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    Win/[^.]*.cpp
    Win/[^.]*.hpp
    Win/[^.]*.cc
    Win/[^.]*.h
    Win/[^.]*.cmake
    )

%cc_%#
# use this to add preprocessor definitions
#%_cc%
add_definitions(
    /D "_ATL_STATIC_REGISTRY"
)

SOURCE_GROUP(Win FILES ${PLATFORM})

set (SOURCES
    ${SOURCES}
    ${PLATFORM}
    )

add_windows_plugin(${PROJECT_NAME} SOURCES)

%cc_%#
# add incluide directories here
#%_cc%
include_directories(
"${CMAKE_CURRENT_SOURCE_DIR}/"
)

%cc_%#
# add library directories here
#%_cc%
link_directories(
)

%cc_%#
# add library dependencies here; leave ${PLUGIN_INTERNAL_DEPS} there
# unless you know what you're doing!
#%_cc%
target_link_libraries(${PROJECT_NAME}
${PLUGIN_INTERNAL_DEPS}
)

%cc_%#
# This is an example of how to add a build step to sign the plugin DLL before
# the WiX installer builds.  The first filename (certificate.pfx) should be
# the path to your pfx file.  If it requires a passphrase, the passphrase
# should be located inside the second file. If you don't need a passphrase
# then set the second filename to "".  If you don't want signtool to timestamp
# your DLL then make the last parameter "".
#
# Note that this will not attempt to sign if the certificate isn't there --
# that's so that you can have development machines without the cert and it'll
# still work. Your cert should only be on the build machine and shouldn't be in
# source control!
# -- uncomment lines below this to enable signing --
#firebreath_sign_plugin(${PROJECT_NAME}
#    "${CMAKE_CURRENT_SOURCE_DIR}/sign/certificate.pfx"
#    "${CMAKE_CURRENT_SOURCE_DIR}/sign/passphrase.txt"
#    "http://timestamp.verisign.com/scripts/timestamp.dll")
#%_cc%

set(WIX_HEAT_FLAGS
    -gg                 %cc_%# Generate GUIDs%_cc%
    -srd                %cc_%# Suppress Root Dir%_cc%
    -cg PluginDLLGroup  %cc_%# Set the Component group name%_cc%
    -dr INSTALLDIR      %cc_%# Set the directory ID to put the files in%_cc%
    )

add_wix_installer( ${PLUGIN_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/Win/WiX/${PLUGIN_NAME}Installer.wxs
    PluginDLLGroup
    ${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/
    ${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/${FBSTRING_PluginFileName}.dll
    ${PROJECT_NAME}
    )

%cc_%#
# This is an example of how to add a build step to sign the WiX installer
# -- uncomment lines below this to enable signing --
#firebreath_sign_file("${PLUGIN_NAME}_WiXInstall"
#    "${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/${PLUGIN_NAME}.msi"
#    "${CMAKE_CURRENT_SOURCE_DIR}/sign/certificate.pfx"
#    "${CMAKE_CURRENT_SOURCE_DIR}/sign/passphrase.txt"
#    "http://timestamp.verisign.com/scripts/timestamp.dll")
#%cc_%
%
%)%)%%
%%if(%equal(Mac,%Platform%)%,%(%
%
%cc_%#
# Mac template platform definition CMake file
# Included from ../CMakeLists.txt
#%_cc%

set (SOURCE_ROOT "${HOME}/source/frameworks")
set (BUILD_CONFIGURATION "$(CONFIGURATION)")

%cc_%#
# remember that the current source dir is the project root; this file is in Mac/
#%_cc%
file (GLOB PLATFORM RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    Mac/[^.]*.cpp
    Mac/[^.]*.hpp
    Mac/[^.]*.mm
    Mac/[^.]*.hh
    Mac/[^.]*.m
    Mac/[^.]*.h
    Mac/[^.]*.cmake
    )

%cc_%#
# use this to add preprocessor definitions
#%_cc%
add_definitions(
)

SOURCE_GROUP(Mac FILES ${PLATFORM})

set (SOURCES
    ${SOURCES}
    ${PLATFORM}
    )

set(PLIST "Mac/bundle_template/Info.plist")
set(STRINGS "Mac/bundle_template/InfoPlist.strings")
set(LOCALIZED "Mac/bundle_template/Localized.r")

add_mac_plugin(${PROJECT_NAME} ${PLIST} ${STRINGS} ${LOCALIZED} SOURCES)

include_directories(
"${CMAKE_CURRENT_SOURCE_DIR}/"
)

find_library(OPENGL_FRAMEWORK OpenGL)
find_library(QUARTZ_CORE_FRAMEWORK QuartzCore)
find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
find_library(CORE_VIDEO_FRAMEWORK CoreVideo)
find_library(CORE_AUDIO_FRAMEWORK CoreAudio)
find_library(AUDIO_TOOLBOX_FRAMEWORK AudioToolbox)
find_library(APPLICATION_SERVICES_FRAMEWORK ApplicationServices)
%cc_%#find_library(COCOA_FRAMEWORK Cocoa)
#find_library(CARBON_FRAMEWORK Carbon) %_cc%

%cc_%
#
# add library dependencies here; leave ${PLUGIN_INTERNAL_DEPS} there
# unless you know what you're doing!
#%_cc%
target_link_libraries(${PROJECT_NAME}
    ${PLUGIN_INTERNAL_DEPS}
    ${OPENGL_FRAMEWORK}
    ${QUARTZ_CORE_FRAMEWORK}
    )
%
%)%)%%
%%if(%equal(X11,%Platform%)%,%(%
%
%cc_%#
# X11 template platform definition CMake file
# Included from ../CMakeLists.txt
#%_cc%

%cc_%#
# remember that the current source dir is the project root; this file is in X11/
#%_cc%
file (GLOB PLATFORM RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    X11/*.cpp
    X11/*.hpp
    X11/*.cc
    X11/*.h
    X11/*.cmake
    )

SOURCE_GROUP(X11 FILES ${PLATFORM})

%cc_%#
# use this to add preprocessor definitions
#%_cc%
add_definitions(
)

set (SOURCES
    ${SOURCES}
    ${PLATFORM}
    )

add_x11_plugin(${PROJECT_NAME} SOURCES)

%cc_%#
# add incluide directories here
#%_cc%
include_directories(
"${CMAKE_CURRENT_SOURCE_DIR}/"
)

%cc_%#
# add library directories here
#%_cc%
link_directories(
)

%cc_%#
# add library dependencies here; leave ${PLUGIN_INTERNAL_DEPS} there unless you know what you're doing!
#%_cc%
target_link_libraries(${PROJECT_NAME}
    ${PLUGIN_INTERNAL_DEPS}
    )
%
%)%)%%
%)%)%%
%)%)%%
%)%)%