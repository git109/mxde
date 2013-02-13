#############################################################################
# Copyright (c) 1988-2009 medusa@medusade.org
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
#   Date: 6/22/2009
#
#############################################################################

PKG = $(PWD)/../../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/clib/cimage/cx11 \
-I$(PKG)/$(SRC)/clib/cimage \
-I$(PKG)/$(SRC)/clib/cx11/cxm/cplatform \
-I$(PKG)/$(SRC)/clib/cx11/cplatform \
-I$(PKG)/$(SRC)/clib/cx11 \
-I$(BUILD)/Motif/include \
-I$(SOURCE)/include/Motif \

#
# targets
#
EXETARGET = cxtest

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cos/argmain.cxx \
$(PKG)/$(SRC)/clib/cos/cmainargs.cxx \
$(PKG)/$(SRC)/clib/cx11/cxmainargs.cxx \
$(PKG)/$(SRC)/capp/cx11/cxtest/cxtestmain.cxx \
$(PKG)/$(SRC)/clib/cimage/cimagebaseinterface.cxx \
$(PKG)/$(SRC)/clib/cimage/cimagebase.cxx \
$(PKG)/$(SRC)/clib/cimage/cmidpointcircle.cxx \

#
# executable libs
#
LIBS = \
-lcx11 \
-lcos \
-lX11 \
-lXpm \
-lXext \

include $(PKG)/$(PRJ)/Makerules
