########################################################################
# Copyright (c) 1988-2011 $organization$
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
#   Date: $date$
#
# MacOSX Gcc Makefile for Shared Library libcxml Xos Development project
########################################################################

PKG = $(PWD)/../../../../..

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
-I$(PKG)/src/clib/cxml \

#
# targets
#
SLIBTARGET = libcxml.dylib

#
# Shared Library C sources
#
SLIB_C_SOURCES = \

#
# Shared Library C++ .cxx sources
#
SLIB_CXX_SOURCES = \

#
# Shared Library C++ .cpp sources
#
SLIB_CPP_SOURCES = \
$(PKG)/$(SRC)/clib/cxml/cXmlAttributeEncoder.cpp \
$(PKG)/$(SRC)/clib/cxml/cXmlTextEncoder.cpp \

#
# Shared Library libs
#
#LIBSSO = \
#-lsomelib
#
LIBSSO = \
-lcbase \
-lcos \
-lpthread \

#
# Shared Library depends
#
#SLIBDEP = \
#$(PKG)/$(BLD)/libsomelib.a \
#
SLIBDEP = \

#
# Shared Library depend dirs
#
#SLIBDEP_DIRS = \
#../libsomelib
#
SLIBDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Shared Library depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#

