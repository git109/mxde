########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   File: libev.pro
#
# Author: $author$
#   Date: 6/28/2016
########################################################################
include(../../../QtCreator/libev/libev.pri)

TARGET = ev
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += \
$${libev_INCLUDEPATH} \

DEFINES += \
$${libev_DEFINES} \

HEADERS += \
$${libev_HEADERS} \
$${EVUP_SRC}/os/unix/cevunixsystemtime.hpp \
$${EVUP_SRC}/os/unix/cevunixfiletime.hpp \
$${EVUP_SRC}/os/unix/cevunixfilesystem.hpp \

SOURCES += \
$${libev_SOURCES} \
$${EVUP_SRC}/os/unix/cevunixsystemtime.cpp \
$${EVUP_SRC}/os/unix/cevunixfiletime.cpp \
$${EVUP_SRC}/os/unix/cevunixfilesystem.cpp \

