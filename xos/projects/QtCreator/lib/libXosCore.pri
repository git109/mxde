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

libXosCore_HEADERS += \
$${XOS_SRC}/xos/base/Acquired.hpp \
$${XOS_SRC}/xos/base/Array.hpp \
$${XOS_SRC}/xos/base/Attached.hpp \
$${XOS_SRC}/xos/base/Base.hpp \
$${XOS_SRC}/xos/base/Created.hpp \
$${XOS_SRC}/xos/base/Error.hpp \
$${XOS_SRC}/xos/base/ExportBase.hpp \
$${XOS_SRC}/xos/base/InterfaceBase.hpp \
$${XOS_SRC}/xos/base/Join.hpp \
$${XOS_SRC}/xos/base/List.hpp \
$${XOS_SRC}/xos/base/Locked.hpp \
$${XOS_SRC}/xos/base/Locker.hpp \
$${XOS_SRC}/xos/base/Named.hpp \
$${XOS_SRC}/xos/base/Opened.hpp \
$${XOS_SRC}/xos/base/Platform.hpp \
$${XOS_SRC}/xos/base/Reference.hpp \
$${XOS_SRC}/xos/base/Readerhpp \
$${XOS_SRC}/xos/base/StringReader.hpp \
$${XOS_SRC}/xos/base/Stream.hpp \
$${XOS_SRC}/xos/base/String.hpp \
$${XOS_SRC}/xos/base/StringBase.hpp \
$${XOS_SRC}/xos/base/Wait.hpp \
$${XOS_SRC}/xos/base/Wrapped.hpp \
$${XOS_SRC}/xos/os/FILEStream.hpp \
$${XOS_SRC}/xos/os/Logger.hpp \
$${XOS_SRC}/xos/os/MainBase.hpp \
$${XOS_SRC}/xos/os/MainOpt.hpp \
$${XOS_SRC}/xos/os/StreamLogger.hpp \
$${XOS_SRC}/xos/network/Addresses.hpp \
$${XOS_SRC}/xos/network/ip/v4/AddressString.hpp \
$${XOS_SRC}/xos/network/Endpoints.hpp \
$${XOS_SRC}/xos/network/Transports.hpp \
$${XOS_SRC}/xos/fs/Path.hpp \
$${XOS_SRC}/xos/fs/PathDirectory.hpp \
$${XOS_SRC}/xos/fs/PathDirectoryAppender.hpp \
$${XOS_SRC}/xos/fs/PathParser.hpp \
$${XOS_SRC}/xos/fs/PathParserEvents.hpp \
$${XOS_SRC}/xos/fs/Time.hpp \
$${XOS_SRC}/xos/gui/ImageRenderer.hpp \
$${XOS_SRC}/xos/gui/qt/ImageRenderer.hpp \
$${XOS_SRC}/xos/gui/opengl/Context.hpp \
$${XOS_SRC}/xos/gui/opengl/ImageRenderer.hpp \

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
$${XOS_SRC}/xos/base/Named.cpp \
$${XOS_SRC}/xos/base/Opened.cpp \
$${XOS_SRC}/xos/base/Platform.cpp \
$${XOS_SRC}/xos/base/Reference.cpp \
$${XOS_SRC}/xos/base/Reader.cpp \
$${XOS_SRC}/xos/base/StringReader.cpp \
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
$${XOS_SRC}/xos/gui/ImageRenderers.cpp \
$${XOS_SRC}/xos/gui/opengl/Context.cpp \

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
