########################################################################
# Copyright (c) 1988-2013 $organization$
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
#   File: libcxttp.pro
#
# Author: $author$
#   Date: 11/2/2013
########################################################################
PKG = ../../../../..
SRC = src
BLD = ..

include(../../cbase.pri)
include(../../cxttp.pri)

TARGET = cxttp

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${cxttp_INCLUDEPATH} \
$${cbase_INCLUDEPATH} \

DEFINES += \
$${base_DEFINES} \
$${cxttp_DEFINES} \

HEADERS += \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormField.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldInterface.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldItem.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldList.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFields.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldsInterface.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiEnv.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiEnvInterface.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiContentStream.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiContentStreamInterface.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiInterface.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgi.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiXmlWriter.hpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiXmlWriterInterface.hpp \

SOURCES += \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormField.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldInterface.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldItem.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldList.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFields.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/cHttpFormFieldsInterface.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiEnv.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiEnvInterface.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiContentStream.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiContentStreamInterface.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiInterface.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgi.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiXmlWriter.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgiXmlWriterInterface.cpp \

LIBS += \

