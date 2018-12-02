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
#   File: cxtest.pro
#
# Author: $author$
#   Date: 6/18/2013
#
# QtCreator project for Executable cxtest
########################################################################
SRC = ../../../../../src
LIB = ../../lib

TARGET = cxtest

INCLUDEPATH += \
$$(HOME)/build/motif/include \
$$SRC/clib/cx11/cxm/cplatform \
$$SRC/clib/cx11/cxm \
$$SRC/clib/cx11/cplatform \
$$SRC/clib/cx11 \
$$SRC/clib/cimage/cx11 \
$$SRC/clib/cimage \
$$SRC/clib/cos/cplatform \
$$SRC/clib/cos \
$$SRC/clib/cbase \

DEFINES += \

SOURCES += \
$$SRC/clib/cos/argmain.cxx \
$$SRC/clib/cos/cmainargs.cxx \
$$SRC/clib/cx11/cxmain.cxx \
$$SRC/clib/cx11/cxmainargs.cxx \
$$SRC/capp/cx11/cxtest/cxtestmain.cxx \
$$SRC/capp/cx11/cxtest/cxtestmainwindow.cxx \

LIBS += \
-L$$LIB/libcbase \
-L$$LIB/libcdebug \
-L$$LIB/libcos \
-L$$LIB/libcx11 \

LIBS += \
-lcx11 \
-lcos \
-lcdebug \
-lcbase \
-lX11 \
-lXpm \
-lXext \

