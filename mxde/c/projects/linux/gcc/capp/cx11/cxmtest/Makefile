 
#############################################################################
# Copyright (c) 1988-2010 medusa@medusade.org
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
# Author: medusa@medusade.org
#   Date: 4/28/2010
#
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(BUILD)/libXpm/include \
-I$(BUILD)/motif/include \
-I$(PKG)/$(SRC)/clib/cimage/cx11 \
-I$(PKG)/$(SRC)/clib/cimage \
-I$(PKG)/$(SRC)/clib/cx11/cxm/cplatform \
-I$(PKG)/$(SRC)/clib/cx11/cxm \
-I$(PKG)/$(SRC)/clib/cx11/cxt/cplatform \
-I$(PKG)/$(SRC)/clib/cx11/cxt \
-I$(PKG)/$(SRC)/clib/cx11/cplatform \
-I$(PKG)/$(SRC)/clib/cx11 \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib \

#
# user includes
#
USRLIBDIRS = \
-L$(BUILD)/libXpm/lib \
-L$(BUILD)/motif/lib \

#
# targets
#
EXETARGET = cxmtest

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cos/argmain.cxx \
$(PKG)/$(SRC)/clib/cos/cmainargs.cxx \
$(PKG)/$(SRC)/clib/cx11/cxmainargs.cxx \
$(PKG)/$(SRC)/capp/cx11/cxm/cxmtest/cxmtestmain.cxx \

#
# executable libs
#
LIBS = \
-lcxt \
-lcx11 \
-lcos \
-lXm \
-lXt \
-lXext \
-lXpm \
-lX11 \

include $(PKG)/$(PRJ)/Makerules
