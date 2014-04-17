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
#   File: libXosCore.pro
#
# Author: $author$
#   Date: 6/7/2013
#
# QtCreator project for Static Library libXosCore
########################################################################
include(../../../../QtCreator/lib/libXosCore.pri)

TARGET = XosCore
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += \
$${libXosCore_INCLUDEPATH} \

DEFINES += \
$${libXosCore_DEFINES} \

libXosCore_HEADERS += \
$${XOS_SRC}/xos/base/Coded.hpp \
$${XOS_SRC}/xos/base/Branch.hpp \
$${XOS_SRC}/xos/base/Tree.hpp \
$${XOS_SRC}/xos/base/AvlBranch.hpp \
$${XOS_SRC}/xos/base/RedblackBranch.hpp \
$${XOS_SRC}/xos/base/AvlTree.hpp \
$${XOS_SRC}/xos/base/RedblackTree.hpp \

libXosCore_SOURCES += \
$${XOS_SRC}/xos/base/Coded.cpp \
$${XOS_SRC}/xos/base/Branch.cpp \
$${XOS_SRC}/xos/base/Tree.cpp \
$${XOS_SRC}/xos/base/AvlBranch.cpp \
$${XOS_SRC}/xos/base/RedblackBranch.cpp \
$${XOS_SRC}/xos/base/AvlTree.cpp \
$${XOS_SRC}/xos/base/RedblackTree.cpp \

HEADERS += \
$${libXosCore_HEADERS} \
$${XOS_SRC}/xos/inet/json/Node.hpp \
$${XOS_SRC}/xos/inet/json/Text.hpp \
$${XOS_SRC}/xos/os/Time.hpp \
$${XOS_SRC}/xos/os/os/Time.hpp \
$${XOS_SRC}/xos/os/unix/Time.hpp \
$${XOS_SRC}/xos/os/Mutex.hpp \
$${XOS_SRC}/xos/os/os/Mutex.hpp \
$${XOS_SRC}/xos/os/unix/Mutex.hpp \
$${XOS_SRC}/xos/os/unix/Mutexes.hpp \

SOURCES += \
$${libXosCore_SOURCES} \
$${XOS_SRC}/xos/inet/json/Node.cpp \
$${XOS_SRC}/xos/inet/json/Text.cpp \
$${XOS_SRC}/xos/os/unix/Mutexes.cpp \
$${XOS_SRC}/xos/os/unix/Processes.cpp \
$${XOS_SRC}/xos/os/unix/Semaphores.cpp \
$${XOS_SRC}/xos/os/unix/Threads.cpp \
$${XOS_SRC}/xos/network/unix/Sockets.cpp \

QT += opengl
