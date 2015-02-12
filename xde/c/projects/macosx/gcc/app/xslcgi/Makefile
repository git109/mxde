#############################################################################
# Copyright (c) 1988-2008 $organization$
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
#   Date: 12/24/2008
#
# MaxOSX makefile for XDE executable xslcgi
#
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/macosx
PRJ = projects/macosx/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/clib/cxalan \
-I$(PKG)/$(SRC)/clib/ccgi \
-I$(PKG)/$(SRC)/clib/cxttp \
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \

#
# user libdirs
#
USRLIBDIRS = \
-L$(XERCESXALAN_LIB) \
-L$(XERCESC_LIB) \
-L$(XALANC_LIB) \

#
# targets
#
EXETARGET = xslcgi

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/capp/ccgi/xslcgi/cxslcgi.cxx \
$(PKG)/$(SRC)/clib/ccgi/cgi.cxx \
$(PKG)/$(SRC)/clib/cbase/cnamelist.cxx \

#
# executable libs
#
LIBS = \
-lxalan-c \
-lxerces-c \
-lcxalan \
-lcxerces \
-lccgi \
-lcxttp \
-lcos \

EXEDEP = \
$(PKG)/$(BLD)/libcxalan.$(SLIBEXT) \
$(PKG)/$(BLD)/libcxerces.$(SLIBEXT) \
$(PKG)/$(BLD)/libccgi.$(SLIBEXT) \

SLIBDEP_DIRS = \
../../lib/libcxalan \
../../lib/libcxerces \
../../lib/libccgi \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcxalan.$(SLIBEXT):
	@(echo      Building libcxalan.$(SLIBEXT) ...;\
	  pushd ../../lib/libcxalan;\
	  ((make) || (exit 1));\
	  popd)

$(PKG)/$(BLD)/libcxerces.$(SLIBEXT):
	@(echo      Building libcxerces.$(SLIBEXT) ...;\
	  pushd ../../lib/libcxerces;\
	  ((make) || (exit 1));\
	  popd)

$(PKG)/$(BLD)/libccgi.$(SLIBEXT):
	@(echo      Building libccgi.$(SLIBEXT) ...;\
	  pushd ../../lib/libccgi;\
	  ((make) || (exit 1));\
	  popd)
