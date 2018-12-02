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
#   File: libmpz.pro
#
# Author: $author$
#   Date: 1/13/2014
########################################################################
SRC = ../../../../../src
BLD = ../..

TARGET = mpz

TEMPLATE = lib

CONFIG += staticlib

INCLUDEPATH += \
$${SRC}/clib/cmpint/mp/mpn/generic \
$${SRC}/clib/cmpint/mp \

DEFINES += \
STDC_HEADERS=1 SIZEOF_INT=8 HAVE_ALLOCA_H=1 HAVE_ALLOCA=1

HEADERS += \

SOURCES += \
$${SRC}/clib/cmpint/mp/mpz/abs.c \
$${SRC}/clib/cmpint/mp/mpz/add.c \
$${SRC}/clib/cmpint/mp/mpz/add_ui.c \
$${SRC}/clib/cmpint/mp/mpz/and.c \
$${SRC}/clib/cmpint/mp/mpz/array_init.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_q.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_q_ui.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_qr.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_qr_ui.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_r.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_r_ui.c \
$${SRC}/clib/cmpint/mp/mpz/cdiv_ui.c \
$${SRC}/clib/cmpint/mp/mpz/clear.c \
$${SRC}/clib/cmpint/mp/mpz/clrbit.c \
$${SRC}/clib/cmpint/mp/mpz/cmp.c \
$${SRC}/clib/cmpint/mp/mpz/cmp_si.c \
$${SRC}/clib/cmpint/mp/mpz/cmp_ui.c \
$${SRC}/clib/cmpint/mp/mpz/com.c \
$${SRC}/clib/cmpint/mp/mpz/divexact.c \
$${SRC}/clib/cmpint/mp/mpz/fac_ui.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_q.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_q_2exp.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_q_ui.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_qr.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_qr_ui.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_r.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_r_2exp.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_r_ui.c \
$${SRC}/clib/cmpint/mp/mpz/fdiv_ui.c \
$${SRC}/clib/cmpint/mp/mpz/gcd.c \
$${SRC}/clib/cmpint/mp/mpz/gcd_ui.c \
$${SRC}/clib/cmpint/mp/mpz/gcdext.c \
$${SRC}/clib/cmpint/mp/mpz/get_d.c \
$${SRC}/clib/cmpint/mp/mpz/get_si.c \
$${SRC}/clib/cmpint/mp/mpz/get_str.c \
$${SRC}/clib/cmpint/mp/mpz/get_ui.c \
$${SRC}/clib/cmpint/mp/mpz/getbit.c \
$${SRC}/clib/cmpint/mp/mpz/getlimbn.c \
$${SRC}/clib/cmpint/mp/mpz/hamdist.c \
$${SRC}/clib/cmpint/mp/mpz/init.c \
$${SRC}/clib/cmpint/mp/mpz/inp_raw.c \
$${SRC}/clib/cmpint/mp/mpz/inp_str.c \
$${SRC}/clib/cmpint/mp/mpz/invert.c \
$${SRC}/clib/cmpint/mp/mpz/ior.c \
$${SRC}/clib/cmpint/mp/mpz/iset.c \
$${SRC}/clib/cmpint/mp/mpz/iset_d.c \
$${SRC}/clib/cmpint/mp/mpz/iset_si.c \
$${SRC}/clib/cmpint/mp/mpz/iset_str.c \
$${SRC}/clib/cmpint/mp/mpz/iset_ui.c \
$${SRC}/clib/cmpint/mp/mpz/jacobi.c \
$${SRC}/clib/cmpint/mp/mpz/legendre.c \
$${SRC}/clib/cmpint/mp/mpz/mod.c \
$${SRC}/clib/cmpint/mp/mpz/mod_inverse.c \
$${SRC}/clib/cmpint/mp/mpz_msb.c \
$${SRC}/clib/cmpint/mp/mpz/mul.c \
$${SRC}/clib/cmpint/mp/mpz/mul_2exp.c \
$${SRC}/clib/cmpint/mp/mpz/mul_ui.c \
$${SRC}/clib/cmpint/mp/mpz/neg.c \
$${SRC}/clib/cmpint/mp/mpz/out_raw.c \
$${SRC}/clib/cmpint/mp/mpz/out_str.c \
$${SRC}/clib/cmpint/mp/mpz/perfsqr.c \
$${SRC}/clib/cmpint/mp/mpz/popcount.c \
$${SRC}/clib/cmpint/mp/mpz/pow_ui.c \
$${SRC}/clib/cmpint/mp/mpz/powm.c \
$${SRC}/clib/cmpint/mp/mpz/powm_ui.c \
$${SRC}/clib/cmpint/mp/mpz/pprime_p.c \
$${SRC}/clib/cmpint/mp/mpz/random.c \
$${SRC}/clib/cmpint/mp/mpz/random2.c \
$${SRC}/clib/cmpint/mp/mpz/realloc.c \
$${SRC}/clib/cmpint/mp/mpz/scan0.c \
$${SRC}/clib/cmpint/mp/mpz/scan1.c \
$${SRC}/clib/cmpint/mp/mpz/set.c \
$${SRC}/clib/cmpint/mp/mpz/set_d.c \
$${SRC}/clib/cmpint/mp/mpz/set_f.c \
$${SRC}/clib/cmpint/mp/mpz/set_q.c \
$${SRC}/clib/cmpint/mp/mpz/set_si.c \
$${SRC}/clib/cmpint/mp/mpz/set_str.c \
$${SRC}/clib/cmpint/mp/mpz/set_ui.c \
$${SRC}/clib/cmpint/mp/mpz/setbit.c \
$${SRC}/clib/cmpint/mp/mpz/size.c \
$${SRC}/clib/cmpint/mp/mpz/sizeinbase.c \
$${SRC}/clib/cmpint/mp/mpz/sqrt.c \
$${SRC}/clib/cmpint/mp/mpz/sqrtrem.c \
$${SRC}/clib/cmpint/mp/mpz/sub.c \
$${SRC}/clib/cmpint/mp/mpz/sub_ui.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_q.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_q_2exp.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_q_ui.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_qr.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_qr_ui.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_r.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_r_2exp.c \
$${SRC}/clib/cmpint/mp/mpz/tdiv_r_ui.c \
$${SRC}/clib/cmpint/mp/mpz/ui_pow_ui.c \
