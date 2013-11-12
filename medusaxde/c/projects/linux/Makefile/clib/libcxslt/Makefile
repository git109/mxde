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
# Linux Gcc Makefile for Static Library libcxslt Xos Development project
########################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux
PRJ = projects/linux/Makefile
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
-I$(PKG)/src/clib/cxml/cxslt \
-I$(PKG)/src/clib/cxml \

#
# targets
#
LIBTARGET = libcxslt.a

#
# Static Library C sources
#
LIB_C_SOURCES = \

#
# Static Library C++ .cxx sources
#
LIB_CXX_SOURCES = \

#
# Static Library C++ .cpp sources
#
LIB_CPP_SOURCES = \
$(PKG)/$(SRC)/clib/cxml/cxslt/cXsltParam.cpp \
$(PKG)/$(SRC)/clib/cxml/cxslt/cXsltParamInterface.cpp \
$(PKG)/$(SRC)/clib/cxml/cxslt/cXsltParams.cpp \
$(PKG)/$(SRC)/clib/cxml/cxslt/cXsltParamsInterface.cpp \
$(PKG)/$(SRC)/clib/cxml/cxslt/cXsltProcessor.cpp \
$(PKG)/$(SRC)/clib/cxml/cxslt/cXsltProcessorInterface.cpp \

#
# Static Library depends
#
#LIBDEP = \
#$(PKG)/$(BLD)/libsomelib.a \
#
LIBDEP = \

#
# Static Library depend dirs
#
#LIBDEP_DIRS = \
#../libsomelib
#
LIBDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Static Library depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#

