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
#   File: libXosCore.pri
#
# Author: $author$
#   Date: 6/8/2013
########################################################################
XOS_PRJ = ../../../../..
XOS_BLD = ../..
XOS_BIN = $${XOS_BLD}/bin
XOS_LIB = $${XOS_BLD}/lib
XOS_SRC = $${XOS_PRJ}/src

libXosCore_INCLUDEPATH += \
$${XOS_SRC} \

libXosCore_DEFINES += \

libXosCore_SOURCES += \
$${XOS_SRC}/xos/base/Acquired.cpp \
$${XOS_SRC}/xos/base/Array.cpp \
$${XOS_SRC}/xos/base/Attached.cpp \
$${XOS_SRC}/xos/base/Base.cpp \
$${XOS_SRC}/xos/base/Created.cpp \
$${XOS_SRC}/xos/base/Error.cpp \
$${XOS_SRC}/xos/base/ExportBase.cpp \
$${XOS_SRC}/xos/base/InterfaceBase.cpp \
$${XOS_SRC}/xos/base/Join.cpp \
$${XOS_SRC}/xos/base/List.cpp \
$${XOS_SRC}/xos/base/Locked.cpp \
$${XOS_SRC}/xos/base/Locker.cpp \
$${XOS_SRC}/xos/base/Opened.cpp \
$${XOS_SRC}/xos/base/Platform.cpp \
$${XOS_SRC}/xos/base/Reference.cpp \
$${XOS_SRC}/xos/base/Stream.cpp \
$${XOS_SRC}/xos/base/String.cpp \
$${XOS_SRC}/xos/base/StringBase.cpp \
$${XOS_SRC}/xos/base/Wait.cpp \
$${XOS_SRC}/xos/base/Wrapped.cpp \
$${XOS_SRC}/xos/os/FILEStream.cpp \
$${XOS_SRC}/xos/os/Logger.cpp \
$${XOS_SRC}/xos/os/MainBase.cpp \
$${XOS_SRC}/xos/os/MainOpt.cpp \
$${XOS_SRC}/xos/os/StreamLogger.cpp \
$${XOS_SRC}/xos/network/Addresses.cpp \
$${XOS_SRC}/xos/network/ip/v4/AddressString.cpp \
$${XOS_SRC}/xos/network/Endpoints.cpp \
$${XOS_SRC}/xos/network/Transports.cpp \
$${XOS_SRC}/xos/fs/Path.cpp \
$${XOS_SRC}/xos/fs/PathDirectory.cpp \
$${XOS_SRC}/xos/fs/PathDirectoryAppender.cpp \
$${XOS_SRC}/xos/fs/PathParser.cpp \
$${XOS_SRC}/xos/fs/PathParserEvents.cpp \
$${XOS_SRC}/xos/fs/Time.cpp \
$${XOS_SRC}/xos/gui/ImageRenderer.cpp \
$${XOS_SRC}/xos/gui/qt/ImageRenderer.cpp \
$${XOS_SRC}/xos/gui/opengl/Context.cpp \
$${XOS_SRC}/xos/gui/opengl/ImageRenderer.cpp \

libXosCore_LIBS += \
-L$${XOS_LIB}/libXosCore \

libXosCore_LIBS += \
-lXosCore \

XOS_MXDE_SRC += \
$${XOS_PRJ}/../mxde/c/src \

XosMxde_INCLUDEPATH += \
$${XOS_SRC}/xos/mxde \
$${XOS_MXDE_SRC}/clib/ccrypto \
$${XOS_MXDE_SRC}/clib/cos/cplatform \
$${XOS_MXDE_SRC}/clib/cos \
$${XOS_MXDE_SRC}/clib/cbase \

