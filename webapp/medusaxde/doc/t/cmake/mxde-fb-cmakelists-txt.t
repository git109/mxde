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
%#   File: mxde-fb-cmakelists-txt.t
%#
%# Author: $author$
%#   Date: 3/6/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-fb-cmakelists-txt.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-cmake.t)%%
%)%,%(%
%%with(%
%%(%
%
%cc_%#
# Written to work with cmake 2.6
#%_cc%
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

Project(${PLUGIN_NAME})

file (GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.hpp
    [^.]*.h
    [^.]*.cmake
    )

include_directories(${PLUGIN_INCLUDE_DIRS})

%cc_%#
# Generated files are stored in ${GENERATED} by the project configuration
#%_cc%
SET_SOURCE_FILES_PROPERTIES(
    ${GENERATED}
    PROPERTIES
        GENERATED 1
    )

SOURCE_GROUP(Generated FILES
    ${GENERATED}
    )

SET( SOURCES
    ${GENERAL}
    ${GENERATED}
    )

%cc_%#
# This will include Win/projectDef.cmake, X11/projectDef.cmake, Mac/projectDef 
# depending on the platform
#%_cc%
include_platform()
%
%)%)%%
%)%)%%
%)%)%