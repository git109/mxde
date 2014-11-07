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
#   File: libxosnadir.pri
#
# Author: $author$
#   Date: 8/12/2014
########################################################################
XOS_PKG = ../../../../..
XOS_BLD = ../..

XOS_PRJ = $${XOS_PKG}
XOS_BIN = $${XOS_BLD}/bin
XOS_LIB = $${XOS_BLD}/lib
XOS_SRC = $${XOS_PKG}/src

libxosnadir_INCLUDEPATH += \
$${XOS_SRC}/xos/nadir \
$${XOS_SRC} \

libxosnadir_DEFINES += \

########################################################################
# io
libxosnadir_HEADERS += \
$${XOS_SRC}/xos/nadir/xos/io/file/writer.hpp \
$${XOS_SRC}/xos/nadir/xos/io/logger.hpp \
$${XOS_SRC}/xos/nadir/xos/io/reader.hpp \
$${XOS_SRC}/xos/nadir/xos/io/writer.hpp \

libxosnadir_SOURCES += \
$${XOS_SRC}/xos/nadir/xos/io/file/writer.cpp \
$${XOS_SRC}/xos/nadir/xos/io/main/logger.cpp \
$${XOS_SRC}/xos/nadir/xos/io/reader.cpp \

########################################################################
# mt
libxosnadir_HEADERS += \
$${XOS_SRC}/xos/nadir/xos/mt/acquire.hpp \
$${XOS_SRC}/xos/nadir/xos/mt/acquirer.hpp \
$${XOS_SRC}/xos/nadir/xos/mt/releaser.hpp \
$${XOS_SRC}/xos/nadir/xos/mt/lock.hpp \
$${XOS_SRC}/xos/nadir/xos/mt/locker.hpp \
$${XOS_SRC}/xos/nadir/xos/mt/wait.hpp \
$${XOS_SRC}/xos/nadir/xos/mt/waiter.hpp \

libxosnadir_SOURCES += \
$${XOS_SRC}/xos/nadir/xos/mt/main/mutex.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/acquire.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/acquirer.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/releaser.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/lock.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/locker.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/wait.cpp \
$${XOS_SRC}/xos/nadir/xos/mt/waiter.cpp \

########################################################################
# base
libxosnadir_HEADERS += \
$${XOS_SRC}/xos/nadir/xos/base/getopt/main_opt.hpp \
$${XOS_SRC}/xos/nadir/xos/base/getopt/main.hpp \
$${XOS_SRC}/xos/nadir/xos/base/main.hpp \
$${XOS_SRC}/xos/nadir/xos/base/string.hpp \
$${XOS_SRC}/xos/nadir/xos/base/attacher.hpp \
$${XOS_SRC}/xos/nadir/xos/base/base.hpp \

libxosnadir_SOURCES += \
$${XOS_SRC}/xos/nadir/xos/base/getopt/main_opt.cpp \
$${XOS_SRC}/xos/nadir/xos/base/getopt/main.cpp \
$${XOS_SRC}/xos/nadir/xos/base/string.cpp \
$${XOS_SRC}/xos/nadir/xos/base/attacher.cpp \
$${XOS_SRC}/xos/nadir/xos/base/base.cpp \

########################################################################
libxosnadir_LIBS += \
-L$${XOS_LIB}/libxosnadir \
-lxosnadir \
