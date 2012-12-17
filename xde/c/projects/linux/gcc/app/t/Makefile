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
#   Date: 12/30/2008
#
# Linux makefile for XDE executable t
#
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user defines
#
USRDEFINES = \
-DDEFAULT_MAIN_DEBUG_LEVELS=1

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/ct \
-I$(PKG)/$(SRC)/cos/cunix \
-I$(PKG)/$(SRC)/cos \
-I$(PKG)/$(SRC) \

#
# targets
#
EXETARGET = t

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/ct/ctdatefunctions.cxx \
$(PKG)/$(SRC)/ct/ctfilefunctions.cxx \
$(PKG)/$(SRC)/ct/ctfunctions.cxx \
$(PKG)/$(SRC)/ct/ctmain.cxx \
$(PKG)/$(SRC)/cos/argmain.cxx \

#
# executable libs
#
LIBS = \
-lct \
-lcos \

EXEDEP = \
$(PKG)/$(BLD)/libct.so \

SLIBDEP_DIRS = \
../../lib/libct \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libct.so:
	@(echo      Building libct.so ...;\
	  pushd ../../lib/libct;\
	  ((make) || (exit 1));\
	  popd)
