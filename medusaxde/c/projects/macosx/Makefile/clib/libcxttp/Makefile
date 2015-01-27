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
# MacOSX Gcc Makefile for Static Library libcxttp Xos Development project
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
-I$(PKG)/src/clib/cxttp/chttp/ccgi \
-I$(PKG)/src/clib/cxttp/chttp \
-I$(PKG)/src/clib/cxttp \
-I$(PKG)/src/clib/cxml \

#
# targets
#
LIBTARGET = libcxttp.a

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
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttp.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttpFormField.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttpFormFieldInterface.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttpFormFieldItem.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttpFormFieldList.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttpFormFields.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/cHttpFormFieldsInterface.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiEnv.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiEnvInterface.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiContentStream.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiContentStreamInterface.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiInterface.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgi.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiMain.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiXmlWriter.cpp \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgiXmlWriterInterface.cpp \

include $(PKG)/$(PRJ)/Makerules
