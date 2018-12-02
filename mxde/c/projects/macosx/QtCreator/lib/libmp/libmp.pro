########################################################################
# Copyright (c) 1988-2014 $organization$
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
#   File: libmp.pro
#
# Author: $author$
#   Date: 1/13/2014
########################################################################
SRC = ../../../../../src

TARGET = mp

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${SRC}/clib/cmpint/mp \

DEFINES += \
STDC_HEADERS=1 SIZEOF_INT=8 HAVE_ALLOCA_H=1 HAVE_ALLOCA=1

HEADERS += \

SOURCES += \
$${SRC}/clib/cmpint/mp/extract-double.c \
$${SRC}/clib/cmpint/mp/insert-double.c \
$${SRC}/clib/cmpint/mp/memory.c \
$${SRC}/clib/cmpint/mp/mp_bpl.c \
$${SRC}/clib/cmpint/mp/mp_clz_tab.c \
$${SRC}/clib/cmpint/mp/mp_set_fns.c \
$${SRC}/clib/cmpint/mp/random.c \
$${SRC}/clib/cmpint/mp/stack-alloc.c \
$${SRC}/clib/cmpint/mp/version.c \
