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
#   File: ccgicc.pro
#
# Author: $author$
#   Date: 1/14/2015
########################################################################
PKG = ../../../../..
SRC = src
BLD = ../..

include(../../cbase.pri)
include(../../ccgicc.pri)
include(../../cxttp.pri)

TARGET = ccgicc

INCLUDEPATH += \
$${ccgicc_INCLUDEPATH} \
$${cxttp_INCLUDEPATH} \
$${cbase_INCLUDEPATH} \

DEFINES += \

HEADERS += \
$${PKG}/$${SRC}/capp/ccgicc/cCgiccCgi.hpp \

SOURCES += \
$${PKG}/$${SRC}/capp/ccgicc/cCgiccCgi.cpp \
$${PKG}/$${SRC}/clib/cxttp/chttp/ccgi/cCgi_main.cpp \

LIBS += \
$${ccgicc_LIBS} \
$${cxttp_LIBS} \
$${cbase_LIBS} \
-lpthread \
-ldl \
