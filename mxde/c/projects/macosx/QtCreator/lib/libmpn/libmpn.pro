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
#   File: libmpn.pro
#
# Author: $author$
#   Date: 1/13/2014
########################################################################
SRC = ../../../../../src

TARGET = mpn

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${SRC}/clib/cmpint/mp/mpn/generic \
$${SRC}/clib/cmpint/mp \

DEFINES += \

HEADERS += \
STDC_HEADERS=1 SIZEOF_INT=8 HAVE_ALLOCA_H=1 HAVE_ALLOCA=1

SOURCES += \
$${SRC}/clib/cmpint/mp/mpn/generic/add_n.c \
$${SRC}/clib/cmpint/mp/mpn/generic/addmul_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/bdivmod.c \
$${SRC}/clib/cmpint/mp/mpn/generic/cmp.c \
$${SRC}/clib/cmpint/mp/mpn/generic/divmod_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/divrem.c \
$${SRC}/clib/cmpint/mp/mpn/generic/divrem_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/dump.c \
$${SRC}/clib/cmpint/mp/mpn/generic/gcd.c \
$${SRC}/clib/cmpint/mp/mpn/generic/gcd_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/gcdext.c \
$${SRC}/clib/cmpint/mp/mpn/generic/get_str.c \
$${SRC}/clib/cmpint/mp/mpn/generic/hamdist.c \
$${SRC}/clib/cmpint/mp/mpn/generic/inlines.c \
$${SRC}/clib/cmpint/mp/mpn/generic/lshift.c \
$${SRC}/clib/cmpint/mp/mpn/generic/mod_1.c \
$${SRC}/clib/cmpint/mp/mpn/mp_bases.c \
$${SRC}/clib/cmpint/mp/mpn/generic/mul.c \
$${SRC}/clib/cmpint/mp/mpn/generic/mul_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/mul_n.c \
$${SRC}/clib/cmpint/mp/mpn/generic/perfsqr.c \
$${SRC}/clib/cmpint/mp/mpn/generic/popcount.c \
$${SRC}/clib/cmpint/mp/mpn/generic/pre_mod_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/random2.c \
$${SRC}/clib/cmpint/mp/mpn/generic/rshift.c \
$${SRC}/clib/cmpint/mp/mpn/generic/scan0.c \
$${SRC}/clib/cmpint/mp/mpn/generic/scan1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/set_str.c \
$${SRC}/clib/cmpint/mp/mpn/generic/sqrtrem.c \
$${SRC}/clib/cmpint/mp/mpn/generic/sub_n.c \
$${SRC}/clib/cmpint/mp/mpn/generic/submul_1.c \
$${SRC}/clib/cmpint/mp/mpn/generic/udiv_w_sdiv.c \

