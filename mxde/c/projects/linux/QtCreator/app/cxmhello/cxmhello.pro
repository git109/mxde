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
#   File: cxmhello.pro
#
# Author: $author$
#   Date: 6/24/2013
#
# QtCreator project for Executable cxmhello
########################################################################
SRC = ../../../../../src
LIB = ../../lib

TARGET = cxmhello

INCLUDEPATH += \
$$(HOME)/build/motif/include \
$$SRC/clib/cx11/cxm/cplatform \
$$SRC/clib/cx11/cxm \
$$SRC/clib/cx11/cxaw \
$$SRC/clib/cx11/cxaw/cplatform \
$$SRC/clib/cx11/cxt/cplatform \
$$SRC/clib/cx11/cxt \
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
$$SRC/capp/cx11/cxm/cxmhello/cxmhellomain.cxx \

LIBS += \
-L$$(HOME)/build/motif/lib \
-L$$LIB/libcbase \
-L$$LIB/libcdebug \
-L$$LIB/libcos \
-L$$LIB/libcx11 \
-L$$LIB/libcxt \
-L$$LIB/libcxm \

LIBS += \
-lcxm \
-lcxt \
-lcx11 \
-lcos \
-lcdebug \
-lcbase \
-lXm \
-lXaw \
-lXt \
-lX11 \
-lXpm \
-lXext \

