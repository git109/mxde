########################################################################
# Copyright (c) 1988-2015 $organization$
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
#   File: libcipc.pri
#
# Author: $author$
#   Date: 1/19/2015
########################################################################

libcipc_INCLUDEPATH += \

libcipc_DEFINES += \

libcipc_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_ipc.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_msg.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_semaphore.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_mutex.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_thread.h \

libcipc_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_ipc.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_msg.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_semaphore.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_mutex.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_thread.c \

libcipc_HEADERS += \
$${XDE_SRC}/clib/cos/cmessagequeueinterface.hxx \
$${XDE_SRC}/clib/cos/cmessagequeue.hxx \
$${XDE_SRC}/clib/cos/csemaphoreinterface.hxx \
$${XDE_SRC}/clib/cos/csemaphore.hxx \
$${XDE_SRC}/clib/cos/cthreadinterface.hxx \
$${XDE_SRC}/clib/cos/cthread.hxx \

libcipc_SOURCES += \
$${XDE_SRC}/clib/cos/cmessagequeueinterface.cxx \
$${XDE_SRC}/clib/cos/cmessagequeue.cxx \
$${XDE_SRC}/clib/cos/csemaphoreinterface.cxx \
$${XDE_SRC}/clib/cos/csemaphore.cxx \
$${XDE_SRC}/clib/cos/cthreadinterface.cxx \
$${XDE_SRC}/clib/cos/cthread.cxx \

libcipc_LIBS += \
