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
#   Date: 1/2/2009
#
# Linux makefile for XDE executable xmllcgi
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
-I$(PKG)/$(SRC)/cxml \
-I$(PKG)/$(SRC)/cxttp \
-I$(PKG)/$(SRC)/ccgi \
-I$(PKG)/$(SRC)/cos \
-I$(PKG)/$(SRC) \

#
# targets
#
EXETARGET = xmllcgi

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/ccgi/cgi.cxx \
$(PKG)/$(SRC)/ccgi/cdocumentfilenameitems.cxx \
$(PKG)/$(SRC)/ccgi/ctemplatefilenameitems.cxx \
$(PKG)/$(SRC)/capp/xmllcgi/cxmllexercgi.cxx \
$(PKG)/$(SRC)/capp/xmllcgi/cxmllexercginodeprocessor.cxx \

#
# executable libs
#
LIBS = \
-lcos \
-lccgi \
-lcxml \

EXEDEP = \
$(PKG)/$(BLD)/libcxml.$(SLIBEXT) \
$(PKG)/$(BLD)/libccgi.$(SLIBEXT) \

EXEDEP_DIRS = \
../../lib/libcxml \
../../lib/libccgi \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcxml.$(SLIBEXT):
	@(echo      Building libcxml.$(SLIBEXT) ...;\
	  pushd ../../lib/libcxml;\
	  ((make) || (exit 1));\
	  popd)

$(PKG)/$(BLD)/libccgi.$(SLIBEXT):
	@(echo      Building libccgi.$(SLIBEXT) ...;\
	  pushd ../../lib/libccgi;\
	  ((make) || (exit 1));\
	  popd)
