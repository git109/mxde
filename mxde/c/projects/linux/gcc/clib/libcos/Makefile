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
#   Date: 3/12/2009
#
# Linux Gcc makefile for libcos shared library
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# targets
#
SLIBTARGET = libcos.so

#
# shared library C++ .cxx sources
#
SLIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cbase/cdebug.cxx \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform_io.cxx \
$(PKG)/$(SRC)/clib/cos/cfileinterface.cxx \
$(PKG)/$(SRC)/clib/cos/cfile.cxx \
$(PKG)/$(SRC)/clib/cos/cmaininterface.cxx \
$(PKG)/$(SRC)/clib/cos/cmain.cxx \
$(PKG)/$(SRC)/clib/cos/cmainarginterface.cxx \
$(PKG)/$(SRC)/clib/cos/cmainarg.cxx \
$(PKG)/$(SRC)/clib/cos/cargmaininterface.cxx \
$(PKG)/$(SRC)/clib/cos/cargmain.cxx \

#$(PKG)/$(SRC)/clib/cos/cmainarg.cxx \

#
# shared library libs
#
LIBSSO = \
-ldl \
-lpthread \
-lcbase \

SLIBDEP = \
$(PKG)/$(BLD)/libcbase.a \

SLIBDEP_DIRS = \
../libcbase \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcbase.a:
	@(echo      Building libcbase.a ...;\
	  pushd ../libcbase;\
	  ((make) || (exit 1));\
	  popd)

