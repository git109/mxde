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
#   Date: 12/23/2008
#
# MaxOSX makefile for XDE library libcxerces.dylib
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
-I$(PKG)/$(SRC)/clib/cos/cxalan \
-I$(XERCESCROOT)/src/xercesc \
-I$(XERCESCROOT)/src \
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \

#
# targets
#
SLIBTARGET = libcxerces.dylib

#
# shared library C sources
#
SLIB_C_SOURCES = \

#
# shared library C++ .cxx sources
#
SLIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cxalan/cxmlchstring.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxmlreaderinterface.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxmlreader.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxmlnodeinterface.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxmlnode.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxmlnodereader.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxmlnodetype.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxercesxmlreader.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxercesexception.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxercesinputsource.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxercesbininputstream.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxerceserrorhandler.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxercesinitializer.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxercesdomparser.cxx \

#
# shared library libs
#
LIBSSO = \
-lcos \

SLIBDEP = \
$(PKG)/$(BLD)/libcos.dylib \

SLIBDEP_DIRS = \
../libcos \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcos.dylib:
	@(echo      Building libcos.dylib ...;\
	  pushd ../libcos;\
	  ((make) || (exit 1));\
	  popd)
