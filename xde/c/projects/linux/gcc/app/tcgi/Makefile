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
#   Date: 12/22/2008
#
# Linux makefile for tcgi
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
-I$(PKG)/$(SRC)/clib/ct \
-I$(PKG)/$(SRC)/clib/ccgi \
-I$(PKG)/$(SRC)/clib/cxttp \
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \

#
# targets
#
EXETARGET = tcgi

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/ccgi/cgi.cxx \
$(PKG)/$(SRC)/clib/ct/ctcgi.cxx \
$(PKG)/$(SRC)/clib/ct/ctfunctions.cxx \
$(PKG)/$(SRC)/clib/ct/ctfilefunctions.cxx \
$(PKG)/$(SRC)/clib/ct/ctdatefunctions.cxx \

#
# executable libs
#
LIBS = \
-lct \
-lccgi \
-lcxttp \
-lcos \

EXEDEP = \
$(PKG)/$(BLD)/libct.$(SLIBEXT) \
$(PKG)/$(BLD)/libccgi.$(SLIBEXT) \

EXEDEP_DIRS = \
../../lib/libct \
../../lib/libccgi \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libct.$(SLIBEXT):
	@(echo      Building libct.$(SLIBEXT) ...;\
	  pushd ../../lib/libct;\
	  ((make) || (exit 1));\
	  popd)

$(PKG)/$(BLD)/libccgi.$(SLIBEXT):
	@(echo      Building libccgi.$(SLIBEXT) ...;\
	  pushd ../../lib/libccgi;\
	  ((make) || (exit 1));\
	  popd)
