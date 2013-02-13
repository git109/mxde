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
#   Date: 3/23/2009
#
# Linux Gcc makefile for ccgi executable
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
-I$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi \
-I$(PKG)/$(SRC)/clib/cxttp/chttp \
-I$(PKG)/$(SRC)/clib/cxttp \

#
# targets
#
EXETARGET = ccgi

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/capp/ccgi/ccgi/ccgicgi.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cgimain.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgimainargs.cxx \
$(PKG)/$(SRC)/clib/cos/cmainargs.cxx \

#
# executable libs
#
LIBS = \
-lcos \
-lcxttp \

include $(PKG)/$(PRJ)/Makerules
