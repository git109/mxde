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
#   File: libcos.pri
#
# Author: $author$
#   Date: 1/19/2015
########################################################################

libcos_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

libcos_DEFINES += \
$${xde_DEFINES} \

libcos_HEADERS += \
$${libcfs_HEADERS} \
$${libcipc_HEADERS} \

libcos_SOURCES += \
$${libcfs_SOURCES} \
$${libcipc_SOURCES} \

libcos_HEADERS += \
$${XDE_SRC}/clib/cos/cdebug.hxx \
$${XDE_SRC}/clib/cos/cdeviceinterface.hxx \
$${XDE_SRC}/clib/cos/cdevice.hxx \
$${XDE_SRC}/clib/cos/cmaininterface.hxx \
$${XDE_SRC}/clib/cos/cmain.hxx \
$${XDE_SRC}/clib/cos/cmainarginterface.hxx \
$${XDE_SRC}/clib/cos/cmainarg.hxx \
$${XDE_SRC}/clib/cos/cargmain.hxx \

libcos_SOURCES += \
$${XDE_SRC}/clib/cos/cdebug.cxx \
$${XDE_SRC}/clib/cos/cdeviceinterface.cxx \
$${XDE_SRC}/clib/cos/cdevice.cxx \
$${XDE_SRC}/clib/cos/cmaininterface.cxx \
$${XDE_SRC}/clib/cos/cmain.cxx \
$${XDE_SRC}/clib/cos/cmainarginterface.cxx \
$${XDE_SRC}/clib/cos/cmainarg.cxx \
$${XDE_SRC}/clib/cos/cargmain.cxx \

libcos_LIBS += \
