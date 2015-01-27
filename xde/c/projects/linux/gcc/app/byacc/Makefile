#############################################################################
# Copyright (c) 1988-2009 $organization$
#
# This software is provided by the author and contributors ``as is'' and
# any express or implied warranties, including, but not limited to, the
# implied warranties of merchantability and fitness for a particular purpose
# are disclaimed.  In no event shall the author or contributors be liable
# for any direct, indirect, incidental, special, exemplary, or consequential
# damages (including, but not limited to, procurement of substitute goods
# or services; loss of use, data, or profits; or business interruption)
# however caused and on any theory of liability, whether in contract, strict
# liability, or tort (including negligence or otherwise) arising in any way
# out of the use of this software, even if advised of the possibility of
# such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 7/31/2009
#
# Linux makefile for byacc executable
#
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

BFLEX = echo bflex
BYACC = echo byacc

BYACC_SRC = $(PKG)/$(SRC)/capp/byacc

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(BYACC_SRC)

#
# targets
#
EXETARGET = byacc

#
# executable C sources
#
EXE_C_SOURCES = \
$(BYACC_SRC)/closure.c \
$(BYACC_SRC)/error.c \
$(BYACC_SRC)/lalr.c \
$(BYACC_SRC)/lr0.c \
$(BYACC_SRC)/main.c \
$(BYACC_SRC)/mkpar.c \
$(BYACC_SRC)/output.c \
$(BYACC_SRC)/reader.c \
$(BYACC_SRC)/skeleton.c \
$(BYACC_SRC)/symtab.c \
$(BYACC_SRC)/verbose.c \
$(BYACC_SRC)/warshall.c \

include $(PKG)/$(PRJ)/Makerules
