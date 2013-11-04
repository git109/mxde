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
#   File: libcos.pro
#
# Author: $author$
#   Date: 11/2/2013
########################################################################
PKG = ../../../../..
SRC = src
BLD = ..

include(../../cbase.pri)

TARGET = cos

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${cbase_INCLUDEPATH} \

DEFINES += \
$${cbase_DEFINES} \

HEADERS += \
$${PKG}/$${SRC}/clib/cplatform/cplatform_pthread.h \
$${PKG}/$${SRC}/clib/cplatform/cplatform_time.h \
$${PKG}/$${SRC}/clib/cos/cthread/cWait.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cWaitInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cMutex.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cMutexBase.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cMutexInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cSemaphore.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cSemaphoreBase.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cSemaphoreInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cCondition.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cConditionBase.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cConditionInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cThread.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cThreadBase.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cThreadInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadMutex.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadMutexInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadSemaphore.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadSemaphoreInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadCondition.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadConditionInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThread.hpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePath.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParser.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParserEvents.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParserEventsInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParserInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileStatBase.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileStatInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemTimeBase.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemTimeInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryTimeBase.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryTimeInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryTimeWhen.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryType.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryBase.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntry.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileStat.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileStatInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemTime.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemTimeInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntryTime.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntryTimeInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntry.hpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntryInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cDebug.hpp \
$${PKG}/$${SRC}/clib/cos/cDebugImplemented.hpp \
$${PKG}/$${SRC}/clib/cos/cDebugInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cCharFile.hpp \
$${PKG}/$${SRC}/clib/cos/cCharFileInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cFile.hpp \
$${PKG}/$${SRC}/clib/cos/cFileInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cMain.hpp \
$${PKG}/$${SRC}/clib/cos/cMainInterface.hpp \
$${PKG}/$${SRC}/clib/cos/cOptMain.hpp \
$${PKG}/$${SRC}/clib/cos/cOptMainInterface.hpp \


SOURCES += \
$${PKG}/$${SRC}/clib/cplatform/cplatform_pthread.c \
$${PKG}/$${SRC}/clib/cplatform/cplatform_time.c \
$${PKG}/$${SRC}/clib/cos/cthread/cWait.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cWaitInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cMutex.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cMutexBase.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cMutexInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cSemaphore.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cSemaphoreBase.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cSemaphoreInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cCondition.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cConditionBase.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cConditionInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cThread.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cThreadBase.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cThreadInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadMutex.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadMutexInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadSemaphore.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadSemaphoreInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadCondition.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadConditionInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThread.cpp \
$${PKG}/$${SRC}/clib/cos/cthread/cpthread/cPThreadInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePath.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParser.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParserEvents.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParserEventsInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFilePathParserInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileStatBase.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileStatInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemTimeBase.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemTimeInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryTimeBase.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryTimeInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryTimeWhen.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryType.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryBase.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntryInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cFileSystemEntry.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileStat.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileStatInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemTime.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemTimeInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntryTime.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntryTimeInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntry.cpp \
$${PKG}/$${SRC}/clib/cos/cfs/cunixfs/cUnixFileSystemEntryInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cDebug.cpp \
$${PKG}/$${SRC}/clib/cos/cDebugImplemented.cpp \
$${PKG}/$${SRC}/clib/cos/cDebugInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cCharFile.cpp \
$${PKG}/$${SRC}/clib/cos/cCharFileInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cFile.cpp \
$${PKG}/$${SRC}/clib/cos/cFileInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cMain.cpp \
$${PKG}/$${SRC}/clib/cos/cMainInterface.cpp \
$${PKG}/$${SRC}/clib/cos/cOptMain.cpp \
$${PKG}/$${SRC}/clib/cos/cOptMainInterface.cpp \

