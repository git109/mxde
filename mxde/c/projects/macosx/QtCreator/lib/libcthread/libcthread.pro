########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   File: libcos.pro
#
# Author: $author$
#   Date: 12/23/2017
#
# QtCreator project for Static Library libcthread
########################################################################
SRC = ../../../../../src

TARGET = cthread

TEMPLATE = lib

INCLUDEPATH += \
$${SRC}/clib/cos/cplatform \
$${SRC}/clib/cos/cthread \
$${SRC}/clib/cos \
$${SRC}/clib/cbase \


DEFINES += \

CONFIG += staticlib

HEADERS += \
$${SRC}/clib/cos/cthread/cmutexattached.hxx \
$${SRC}/clib/cos/cthread/cmutexinterface.hxx \
$${SRC}/clib/cos/cthread/cmutex.hxx \
$${SRC}/clib/cos/cthread/csemaphoreattached.hxx \
$${SRC}/clib/cos/cthread/csemaphoreinterface.hxx \
$${SRC}/clib/cos/cthread/csemaphore.hxx \

SOURCES += \
$${SRC}/clib/cos/cthread/cmutexattached.cxx \
$${SRC}/clib/cos/cthread/cmutexinterface.cxx \
$${SRC}/clib/cos/cthread/cmutex.cxx \
$${SRC}/clib/cos/cthread/csemaphoreattached.cxx \
$${SRC}/clib/cos/cthread/csemaphoreinterface.cxx \
$${SRC}/clib/cos/cthread/csemaphore.cxx \

