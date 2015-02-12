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
%#   File: mxde-project-makefile-rules.t
%#
%# Author: $author$
%#   Date: 3/30/2012
%########################################################################
%with(%
%%(%
%PKG = %Pkg%

MAK = %Mak%
PRJ = %Prj%
SRC = %Src%%if(%Bld%,%(
BLD = %Bld%
)%)%

include $(PKG)/$(PRJ)/Makedefines
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(MAK)/%else(%equal(EXE,%EXE%)%,%(lib)%,%(app)%)%/%Target%/Makefile

%cc_%#
# target
#%_cc%
%EXE%TARGET = %Target%%Ext%

%cc_%#
# user defines
#%_cc%
USRDEFINES = \
$(%target%_USRDEFINES) \

%cc_%#
# user includes
#%_cc%
USRINCLUDES = \
$(%target%_USRINCLUDES) \

%cc_%#
# user libdirs
#%_cc%
USRLIBDIRS = \
$(%target%_USRLIBDIRS) \

%cc_%#
# user c++ flags
#%_cc%
USRCXXFLAGS = \
$(%target%_USRCXXFLAGS) \

%cc_%#
# user c flags
#%_cc%
USRCFLAGS = \
$(%target%_USRCFLAGS) \

%cc_%#
# user ld flags
#%_cc%
USRLDFLAGS = \
$(%target%_USRLDFLAGS) \

%cc_%#
# %Executable% C sources
#%_cc%
%EXE%_C_SOURCES = \
$(%target%_C_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(c,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# %Executable% C++ .cc sources
#%_cc%
%EXE%_CC_SOURCES = \
$(%target%_CC_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(cc,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# %Executable% C++ .cxx sources
#%_cc%
%EXE%_CXX_SOURCES = \
$(%target%_CXX_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(cxx,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# %Executable% C++ .cpp sources
#%_cc%
%EXE%_CPP_SOURCES = \
$(%target%_CPP_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(cpp,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# %Executable% Objective C .m sources
#%_cc%
%EXE%_M_SOURCES = \
$(%target%_M_SOURCE) \%parse(%exe_sources%,;,,,,%(%if(%equal(m,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%

%cc_%#
# %Executable% Objective C++ .mm sources
#%_cc%
%EXE%_MM_SOURCES = \
$(%target%_MM_SOURCES) \%parse(%exe_sources%,;,,,,%(%if(%equal(mm,%right(%s%,.)%)%,%(
$(PKG)/$(SRC)/%s% \)%)%)%,s)%
%if(%equal(EXE,%EXE%)%,%(
%cc_%#
# %Executable% libs
#
#%LIBS% = \
#-lsomelib
#%_cc%
%LIBS% = \
$(%target%_%LIBS%) \
)%)%
%cc_%#
# %Executable% depends
#
#%EXE%DEP = \
#$(PKG)/$(BLD)/libsomelib \
#%_cc%
%EXE%DEP = \

%cc_%#
# %Executable% depend dirs
#
#%EXE%DEP_DIRS = \
#../libsomelib
#%_cc%
%EXE%DEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

%cc_%#
# %Executable% depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#%_cc%
%

%)%)%