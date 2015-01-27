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
#   File: libcfs.pri
#
# Author: $author$
#   Date: 1/19/2015
########################################################################

libcfs_INCLUDEPATH += \

libcfs_DEFINES += \

libcfs_HEADERS += \
$${XDE_SRC}/clib/cos/cfileinterface.hxx \
$${XDE_SRC}/clib/cos/cfile.hxx \
$${XDE_SRC}/clib/cfs/cfilepatheventinterface.hxx \
$${XDE_SRC}/clib/cfs/cfilepathinterface.hxx \
$${XDE_SRC}/clib/cfs/ctofilepathwriter.hxx \
$${XDE_SRC}/clib/cfs/cfilepath.hxx \

libcfs_SOURCES += \
$${XDE_SRC}/clib/cos/cfileinterface.cxx \
$${XDE_SRC}/clib/cos/cfile.cxx \
$${XDE_SRC}/clib/cfs/cfilepatheventinterface.cxx \
$${XDE_SRC}/clib/cfs/cfilepathinterface.cxx \
$${XDE_SRC}/clib/cfs/ctofilepathwriter.cxx \
$${XDE_SRC}/clib/cfs/cfilepath.cxx \

libcfs_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_stat.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_path.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_file.h \

libcfs_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_stat.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_path.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_file.c \

libcfs_LIBS += \

