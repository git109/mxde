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
#   Date: 6/18/2013
#
# QtCreator project for Static Library libcos
########################################################################
SRC = ../../../../../src

TARGET = cos

TEMPLATE = lib

INCLUDEPATH += \
$$SRC/clib/cos/cplatform \
$$SRC/clib/cos \
$$SRC/clib/cbase \


DEFINES += \

CONFIG += staticlib

SOURCES += \
$$SRC/clib/cos/cplatform/cplatform.cxx \
$$SRC/clib/cos/cplatform/cplatform_build.cxx \
$$SRC/clib/cos/cplatform/cplatform_conio.cxx \
$$SRC/clib/cos/cplatform/cplatform_device.cxx \
$$SRC/clib/cos/cplatform/cplatform_fcntl.cxx \
$$SRC/clib/cos/cplatform/cplatform_io.cxx \
$$SRC/clib/cos/cplatform/cplatform_ioctl.cxx \
$$SRC/clib/cos/cplatform/cplatform_mutex.cxx \
$$SRC/clib/cos/cplatform/cplatform_path.cxx \
$$SRC/clib/cos/cplatform/cplatform_semaphore.cxx \
$$SRC/clib/cos/cplatform/cplatform_serial_comm.cxx \
$$SRC/clib/cos/cplatform/cplatform_socket.cxx \
$$SRC/clib/cos/cplatform/cplatform_stdio.cxx \
$$SRC/clib/cos/cplatform/cplatform_time.cxx \
$$SRC/clib/cos/cargmain.cxx \
$$SRC/clib/cos/cargmaininterface.cxx \
$$SRC/clib/cos/cmain.cxx \
$$SRC/clib/cos/cmainarg.cxx \
$$SRC/clib/cos/cmainarginterface.cxx \
$$SRC/clib/cos/cmainargitem.cxx \
$$SRC/clib/cos/cmainarglist.cxx \
$$SRC/clib/cos/cmaininterface.cxx \
$$SRC/clib/cos/coptmain.cxx \
$$SRC/clib/cos/coptmaininterface.cxx \
$$SRC/clib/cos/cfile.cxx \
$$SRC/clib/cos/cfileattachedinterface.cxx \
$$SRC/clib/cos/cfileinterface.cxx \
$$SRC/clib/cos/cfilepath.cxx \
$$SRC/clib/cos/cfilepathinterface.cxx \
$$SRC/clib/cos/cfilepathseparatorevents.cxx \
$$SRC/clib/cos/cfilepathseparatoreventsinterface.cxx \
$$SRC/clib/cos/ctofilepathseparatorwriter.cxx \
$$SRC/clib/cos/cdevice.cxx \
$$SRC/clib/cos/cdeviceattached.cxx \
$$SRC/clib/cos/cdeviceattachedinterface.cxx \
$$SRC/clib/cos/cdeviceinterface.cxx \
$$SRC/clib/cos/cdeviceopened.cxx \
$$SRC/clib/cos/cdeviceopenedinterface.cxx \
$$SRC/clib/cos/cserialcomm.cxx \
$$SRC/clib/cos/cserialcomminterface.cxx \

