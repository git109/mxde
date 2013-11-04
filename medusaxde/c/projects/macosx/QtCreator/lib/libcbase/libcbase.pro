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
#   File: libcbase.pro
#
# Author: $author$
#   Date: 11/2/2013
########################################################################
PKG = ../../../../..
SRC = src
BLD = ..

include(../../cbase.pri)

TARGET = cbase

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${cbase_INCLUDEPATH} \

DEFINES += \
$${cbase_DEFINES} \

HEADERS += \
$${PKG}/$${SRC}/clib/cbase/cBase.hpp \
$${PKG}/$${SRC}/clib/cbase/cError.hpp \
$${PKG}/$${SRC}/clib/cbase/cImplementBase.hpp \
$${PKG}/$${SRC}/clib/cbase/cInstanceBase.hpp \
$${PKG}/$${SRC}/clib/cbase/cInterfaceBase.hpp \
$${PKG}/$${SRC}/clib/cbase/cExportBase.hpp \
$${PKG}/$${SRC}/clib/cbase/cReader.hpp \
$${PKG}/$${SRC}/clib/cbase/cReaderInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cWriter.hpp \
$${PKG}/$${SRC}/clib/cbase/cWriterInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cStream.hpp \
$${PKG}/$${SRC}/clib/cbase/cStreamInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cCharReader.hpp \
$${PKG}/$${SRC}/clib/cbase/cCharReaderInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cCharWriter.hpp \
$${PKG}/$${SRC}/clib/cbase/cCharWriterInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cCharStream.hpp \
$${PKG}/$${SRC}/clib/cbase/cCharStreamInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cString.hpp \
$${PKG}/$${SRC}/clib/cbase/cStringInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cStringReader.hpp \
$${PKG}/$${SRC}/clib/cbase/cStringReaderInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cStringWriter.hpp \
$${PKG}/$${SRC}/clib/cbase/cStringWriterInterface.hpp \
$${PKG}/$${SRC}/clib/cbase/cReference.hpp \
$${PKG}/$${SRC}/clib/cbase/cReferenced.hpp \
$${PKG}/$${SRC}/clib/cbase/cTypes.hpp \
$${PKG}/$${SRC}/clib/cbase/cArray.hpp \
$${PKG}/$${SRC}/clib/cbase/cArrayInterface.hpp \

SOURCES += \
$${PKG}/$${SRC}/clib/cbase/cBase.cpp \
$${PKG}/$${SRC}/clib/cbase/cError.cpp \
$${PKG}/$${SRC}/clib/cbase/cImplementBase.cpp \
$${PKG}/$${SRC}/clib/cbase/cInstanceBase.cpp \
$${PKG}/$${SRC}/clib/cbase/cInterfaceBase.cpp \
$${PKG}/$${SRC}/clib/cbase/cExportBase.cpp \
$${PKG}/$${SRC}/clib/cbase/cReader.cpp \
$${PKG}/$${SRC}/clib/cbase/cReaderInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cWriter.cpp \
$${PKG}/$${SRC}/clib/cbase/cWriterInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cStream.cpp \
$${PKG}/$${SRC}/clib/cbase/cStreamInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cCharReader.cpp \
$${PKG}/$${SRC}/clib/cbase/cCharReaderInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cCharWriter.cpp \
$${PKG}/$${SRC}/clib/cbase/cCharWriterInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cCharStream.cpp \
$${PKG}/$${SRC}/clib/cbase/cCharStreamInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cString.cpp \
$${PKG}/$${SRC}/clib/cbase/cStringInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cStringReader.cpp \
$${PKG}/$${SRC}/clib/cbase/cStringReaderInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cStringWriter.cpp \
$${PKG}/$${SRC}/clib/cbase/cStringWriterInterface.cpp \
$${PKG}/$${SRC}/clib/cbase/cReference.cpp \
$${PKG}/$${SRC}/clib/cbase/cReferenced.cpp \
$${PKG}/$${SRC}/clib/cbase/cTypes.cpp \
$${PKG}/$${SRC}/clib/cbase/cArray.cpp \
$${PKG}/$${SRC}/clib/cbase/cArrayInterface.cpp \

