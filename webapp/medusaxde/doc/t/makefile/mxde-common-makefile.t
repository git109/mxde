%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: mxde-common-makefile.t
%#
%# Author: $author$
%#   Date: 12/8/2014
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%%(%
%%else(%makefile_rules%,%(%
%%with(%
%platform,%(Common)%,%
%makefile_rules,%(mxde-common-makefile.t)%,%
%%(%
%%include(%filepath%/mxde-project-makefile.t)%%
%)%)%%
%)%,%(%
%
%cc_%#
# user defines
#%_cc%
%Target%_USRDEFINES += \
$(%exe_deps%_USRDEFINES) \

%cc_%#
# user includes
#%_cc%
%Target%_USRINCLUDES += \
$(%exe_deps%_USRINCLUDES) \

%cc_%#
# user libdirs
#%_cc%
%Target%_USRLIBDIRS += \
$(%exe_deps%_USRLIBDIRS) \

%cc_%#
# user c++ flags
#%_cc%
%Target%_USRCXXFLAGS += \
$(%exe_deps%_USRCXXFLAGS) \

%cc_%#
# user c flags
#%_cc%
%Target%_USRCFLAGS += \
$(%exe_deps%_USRCFLAGS) \

%cc_%#
# user ld flags
#%_cc%
%Target%_USRLDFLAGS += \
$(%exe_deps%_USRLDFLAGS) \

%cc_%#
# C sources
#%_cc%
%Target%_C_SOURCES += \
$(%exe_deps%_C_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(c,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# C++ .cc sources
#%_cc%
%Target%_CC_SOURCES += \
$(%exe_deps%_CC_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(cc,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# C++ .cxx sources
#%_cc%
%Target%_CXX_SOURCES += \
$(%exe_deps%_CXX_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(cxx,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# C++ .cpp sources
#%_cc%
%Target%_CPP_SOURCES += \
$(%exe_deps%_CPP_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(cpp,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# Objective C .m sources
#%_cc%
%Target%_M_SOURCES += \
$(%exe_deps%_M_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(m,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# Objective C++ .mm sources
#%_cc%
%Target%_MM_SOURCES += \
$(%exe_deps%_MM_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(mm,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# libs
#
#LIBS += \
#-lsomelib
#%_cc%
%Target%_LIBS += \
$(%exe_deps%_LIBS) \%parse(%exe_libs%,;,,,,%(
-l%l% \)%,l)%
%
%)%)%%
%)%)%