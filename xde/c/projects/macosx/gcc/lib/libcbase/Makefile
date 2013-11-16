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
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \

#
# user defines
#
USRDEFINES = \
-DDEFAULT_DEBUG_LEVELS=1

#
# user ld flags
#
USRLDFLAGS = \
-L$(PKG)/$(BLD)

#
# targets
#
LIBTARGET = libcbase.$(LIBEXT)

#
# library C sources
#
LIB_C_SOURCES = \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform.c \

#
# library C++ .cxx sources
#
LIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cbase/cinterfacebase.cxx \
$(PKG)/$(SRC)/clib/cbase/cbase.cxx \
$(PKG)/$(SRC)/clib/cbase/creaderinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cwriterinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cstreaminterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cattachinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cattachedinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cattached.cxx \
$(PKG)/$(SRC)/clib/cbase/clist.cxx \
$(PKG)/$(SRC)/clib/cbase/cbinarytree.cxx \
$(PKG)/$(SRC)/clib/cbase/cavltree.cxx \
$(PKG)/$(SRC)/clib/cbase/credblacktree.cxx \
$(PKG)/$(SRC)/clib/cbase/cstringinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cstring.cxx \
$(PKG)/$(SRC)/clib/cbase/cbufferinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cbuffer.cxx \

include $(PKG)/$(PRJ)/Makerules
