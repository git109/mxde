########################################################################
# Copyright (c) 1988-$year$ $organization$
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
#   File: libcbase.pro
#
# Author: $author$
#   Date: $date$
#
# QtCreator project for Static Library libbase
########################################################################
include(../../../../QtCreator/xde.pri)

TARGET = cbase

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${XDE_INCLUDES} \

DEFINES += \

SOURCES += \
$${XDE_SRC}/clib/cbase/cbase.cxx \
$${XDE_SRC}/clib/cbase/ccomparer.cxx \
$${XDE_SRC}/clib/cbase/ccounter.cxx \
$${XDE_SRC}/clib/cbase/cdigitizer.cxx \
$${XDE_SRC}/clib/cbase/cerror.cxx \
$${XDE_SRC}/clib/cbase/cinstance.cxx \
$${XDE_SRC}/clib/cbase/cinstanceinterface.cxx \
$${XDE_SRC}/clib/cbase/cinterface.cxx \
$${XDE_SRC}/clib/cbase/cinterfacebase.cxx \
$${XDE_SRC}/clib/cbase/cnamevalueeventinterface.cxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriter.cxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriterinterface.cxx \
$${XDE_SRC}/clib/cbase/creference.cxx \
$${XDE_SRC}/clib/cbase/creferenced.cxx \
$${XDE_SRC}/clib/cbase/csingleinstance.cxx \
$${XDE_SRC}/clib/cbase/cvector.cxx \
$${XDE_SRC}/clib/cbase/cvectorinterface.cxx \
$${XDE_SRC}/clib/cbase/cattached.cxx \
$${XDE_SRC}/clib/cbase/cattachedinterface.cxx \
$${XDE_SRC}/clib/cbase/cattachinterface.cxx \
$${XDE_SRC}/clib/cbase/cbuffer.cxx \
$${XDE_SRC}/clib/cbase/cbufferinterface.cxx \
$${XDE_SRC}/clib/cbase/cccharstring.cxx \
$${XDE_SRC}/clib/cbase/cchar.cxx \
$${XDE_SRC}/clib/cbase/ccharinterface.cxx \
$${XDE_SRC}/clib/cbase/ccreatedattached.cxx \
$${XDE_SRC}/clib/cbase/ccreatedinterface.cxx \
$${XDE_SRC}/clib/cbase/cdestroyinterface.cxx \
$${XDE_SRC}/clib/cbase/clist.cxx \
$${XDE_SRC}/clib/cbase/ccloseinterface.cxx \
$${XDE_SRC}/clib/cbase/copened.cxx \
$${XDE_SRC}/clib/cbase/copenedinterface.cxx \
$${XDE_SRC}/clib/cbase/copeninterface.cxx \
$${XDE_SRC}/clib/cbase/cbytestreaminterface.cxx \
$${XDE_SRC}/clib/cbase/clookstream.cxx \
$${XDE_SRC}/clib/cbase/creader.cxx \
$${XDE_SRC}/clib/cbase/creaderinterface.cxx \
$${XDE_SRC}/clib/cbase/cstream.cxx \
$${XDE_SRC}/clib/cbase/cstreaminterface.cxx \
$${XDE_SRC}/clib/cbase/cwriter.cxx \
$${XDE_SRC}/clib/cbase/cwriterinterface.cxx \
$${XDE_SRC}/clib/cos/cplatform/cplatform_string.c \
$${XDE_SRC}/clib/cbase/cstring.cxx \
$${XDE_SRC}/clib/cbase/cstringbase.cxx \
$${XDE_SRC}/clib/cbase/cstringinterface.cxx \
$${XDE_SRC}/clib/cbase/cavltree.cxx \
$${XDE_SRC}/clib/cbase/cbinarytree.cxx \
$${XDE_SRC}/clib/cbase/credblacktree.cxx \
