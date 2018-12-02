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
#   File: libbn.pro
#
# Author: $author$
#   Date: 1/13/2014
########################################################################
SRC = ../../../../../src

TARGET = bn

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${SRC}/clib/cmpint/bn \

DEFINES += \

HEADERS += \

SOURCES += \
$${SRC}/clib/cmpint/bn/bn_add.c \
$${SRC}/clib/cmpint/bn/bn_blind.c \
$${SRC}/clib/cmpint/bn/bn_div.c \
$${SRC}/clib/cmpint/bn/bn_exp.c \
$${SRC}/clib/cmpint/bn/bn_gcd.c \
$${SRC}/clib/cmpint/bn/bn_lib.c \
$${SRC}/clib/cmpint/bn/bn_mod.c \
$${SRC}/clib/cmpint/bn/bn_mont.c \
$${SRC}/clib/cmpint/bn/bn_mpi.c \
$${SRC}/clib/cmpint/bn/bn_msb.c \
$${SRC}/clib/cmpint/bn/bn_mul.c \
$${SRC}/clib/cmpint/bn/bn_mulw.c \
$${SRC}/clib/cmpint/bn/bn_prime.c \
$${SRC}/clib/cmpint/bn/bn_randm.c \
$${SRC}/clib/cmpint/bn/bn_recp.c \
$${SRC}/clib/cmpint/bn/bn_shift.c \
$${SRC}/clib/cmpint/bn/bn_sqr.c \
$${SRC}/clib/cmpint/bn/bn_sub.c \
$${SRC}/clib/cmpint/bn/bn_word.c \

