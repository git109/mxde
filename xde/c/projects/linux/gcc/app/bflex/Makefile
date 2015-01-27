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
# Linux makefile for bflex executable
#
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

BFLEX = echo bflex
BYACC = echo byacc

BFLEX_SRC = $(PKG)/$(SRC)/capp/bflex

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(BFLEX_SRC)

#
# targets
#
EXETARGET = bflex

#
# executable C sources
#
EXE_C_SOURCES = \
$(BFLEX_SRC)/ccl.c \
$(BFLEX_SRC)/dfa.c \
$(BFLEX_SRC)/ecs.c \
$(BFLEX_SRC)/gen.c \
$(BFLEX_SRC)/main.c \
$(BFLEX_SRC)/misc.c \
$(BFLEX_SRC)/nfa.c \
$(BFLEX_SRC)/parse.c \
$(BFLEX_SRC)/scan.c \
$(BFLEX_SRC)/skel.c \
$(BFLEX_SRC)/sym.c \
$(BFLEX_SRC)/tblcmp.c \
$(BFLEX_SRC)/yylex.c

include $(PKG)/$(PRJ)/Makerules
