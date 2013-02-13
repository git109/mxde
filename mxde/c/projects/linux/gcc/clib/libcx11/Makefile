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
-I$(PKG)/$(SRC)/clib/cimage/cx11 \
-I$(PKG)/$(SRC)/clib/cimage \
-I$(PKG)/$(SRC)/clib/cx11/cplatform \
-I$(PKG)/$(SRC)/clib/cx11 \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib \

#
# user libdirs
#
USRLIBDIRS = \
-L$(BUILD)/libXpm/lib \

#
# targets
#
SLIBTARGET = libcx11.so

#
# shared library C++ .cxx sources
#
SLIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cx11/cxbaseinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxbase.cxx \
$(PKG)/$(SRC)/clib/cx11/cxdisplayinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxdisplay.cxx \
$(PKG)/$(SRC)/clib/cx11/cxobjectinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxobject.cxx \
$(PKG)/$(SRC)/clib/cx11/cxdrawableattached.cxx \
$(PKG)/$(SRC)/clib/cx11/cxwindowattached.cxx \
$(PKG)/$(SRC)/clib/cx11/cxwindowinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxwindow.cxx \
$(PKG)/$(SRC)/clib/cx11/cxtextproperty.cxx \
$(PKG)/$(SRC)/clib/cx11/cxeventtargetinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxeventtarget.cxx \
$(PKG)/$(SRC)/clib/cx11/cxcolormapattached.cxx \
$(PKG)/$(SRC)/clib/cx11/cxcolormapinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxcolormap.cxx \
$(PKG)/$(SRC)/clib/cx11/cxcolorinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxcolor.cxx \
$(PKG)/$(SRC)/clib/cx11/cxpixelattached.cxx \
$(PKG)/$(SRC)/clib/cx11/cxgcattached.cxx \
$(PKG)/$(SRC)/clib/cx11/cxgcinterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxgc.cxx \
$(PKG)/$(SRC)/clib/cx11/cxrectangle.cxx \
$(PKG)/$(SRC)/clib/cx11/cxregioninterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxregion.cxx \
$(PKG)/$(SRC)/clib/cx11/cxmaininterface.cxx \
$(PKG)/$(SRC)/clib/cx11/cxmain.cxx \
$(PKG)/$(SRC)/clib/cimage/cx11/cximagebaseinterface.cxx \
$(PKG)/$(SRC)/clib/cimage/cx11/cximagebase.cxx \
$(PKG)/$(SRC)/clib/cimage/cx11/cximagesolidbrush.cxx \

#$(PKG)/$(SRC)/clib/cx11/cxmainargs.cxx \

#
# shared library libs
#
LIBSSO = \
-lcos \
-lX11 \
-lXpm \
-lXext \

include $(PKG)/$(PRJ)/Makerules
