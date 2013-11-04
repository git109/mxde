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
# MacOSX Gcc Makefile for Static Library libclibxslt Xos Development project
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
-I$(HOME)/build/libxslt/include \
-I$(HOME)/build/libxml2/include/libxml2 \
-I$(PKG)/src/clib/cxml/cxslt \
-I$(PKG)/src/clib/cxml \

#
# user libdirs
#
USRLIBDIRS = \
-L$(HOME)/build/libxslt/lib \
-L$(HOME)/build/libxml2/lib \

#
# targets
#
LIBTARGET = libclibxslt.a

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
$(PKG)/$(SRC)/clib/clibc/clibxml2/clibxslt/cLibXsltXsltParams.cpp \
$(PKG)/$(SRC)/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessor.cpp \
$(PKG)/$(SRC)/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorInterface.cpp \

include $(PKG)/$(PRJ)/Makerules
