########################################################################
# Copyright (c) 1988-2014 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 3/8/2014
#
# MacOSX Gcc Makefile for Executable ccgicatch Xos Development project
########################################################################

PKG = $(PWD)/../../../../../..

BLD = build/macosx
PRJ = projects/macosx/Makefile
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user defines
#
USRDEFINES = \

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/src/clib/cxttp/chttp/ccgi \
-I$(PKG)/src/clib/cxttp/chttp \
-I$(PKG)/src/clib/cxttp \

#
# targets
#
EXETARGET = ccgicatch

#
# Executable C sources
#
EXE_C_SOURCES = \

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES = \

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES = \
$(PKG)/$(SRC)/capp/ccgi/ccgicatch/cCgiCatch.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiMain_main.cpp \

#
# Executable libs
#
#LIBS = \
#-lsomelib
#
LIBS = \
-lcxttp \
-lcos \
-lcbase \
-lcplatform \

#
# Executable depends
#
#EXEDEP = \
#$(PKG)/$(BLD)/libsomelib.a \
#
EXEDEP = \

#
# Executable depend dirs
#
#EXEDEP_DIRS = \
#../libsomelib
#
EXEDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#

