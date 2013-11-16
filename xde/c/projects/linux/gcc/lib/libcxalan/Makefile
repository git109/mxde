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
# Linux makefile for XDE shared library libcxalan
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
-I$(PKG)/$(SRC)/clib/cos/cxalan \
-I$(XALANCROOT)/src/xalanc \
-I$(XALANCROOT)/src \
-I$(XERCESCROOT)/src/xercesc \
-I$(XERCESCROOT)/src \
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \

#
# targets
#
SLIBTARGET = libcxalan.$(SLIBEXT)

#
# shared library C sources
#
SLIB_C_SOURCES = \

#
# shared library C++ .cxx sources
#
SLIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cxalan/cxalanoutputstream.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalanwriter.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalanparameter.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalantransformerinitializer.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalantransformer.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalanxsltinputsource.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalanxsltresulttarget.cxx \
$(PKG)/$(SRC)/clib/cxalan/cxalanxsltransformer.cxx \

#
# shared library libs
#
LIBSSO = \
-lcxerces \
-lcos \

SLIBDEP = \
$(PKG)/$(BLD)/libcxerces.$(SLIBEXT) \

SLIBDEP_DIRS = \
../libcxerces \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcxerces.$(SLIBEXT):
	@(echo      Building libcxerces.$(SLIBEXT) ...;\
	  pushd ../libcxerces;\
	  ((make) || (exit 1));\
	  popd)
