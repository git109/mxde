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
#   Date: 4/25/2009
#
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# targets
#
EXETARGET = xim

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/cimager \
-I$(PKG)/$(SRC)/cx11 \
-I$(PKG)/$(SRC)/cos/cunix \
-I$(PKG)/$(SRC)/cos \
-I$(PKG)/$(SRC) \
-I/usr/include/X11 \
-I/usr/X11R6/include \

#
# user ld flags
#
USRLDFLAGS = \
-L/usr/lib/X11 \
-L/usr/X11R6/lib \

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/cimager/cx11imager.cxx \
$(PKG)/$(SRC)/cimager/cx11imagerobject.cxx \
$(PKG)/$(SRC)/cx11/cxobject.cxx \
$(PKG)/$(SRC)/cx11/cxpixmap.cxx \
$(PKG)/$(SRC)/cx11/cxdisplay.cxx \
$(PKG)/$(SRC)/cx11/cxeventtarget.cxx \
$(PKG)/$(SRC)/cx11/cxwindow.cxx \
$(PKG)/$(SRC)/cx11/cxmain.cxx \
$(PKG)/$(SRC)/cx11/cxmainargs.cxx \
$(PKG)/$(SRC)/capp/x11/xim/cximmainwindow.cxx \
$(PKG)/$(SRC)/cos/main.cxx \


#
# executable libs
#
LIBS = \
-lcos \
-lX11 \
-lXpm \
-lXext

xEXEDEP = \
$(PKG)/$(BLD)/libcos.$(SLIBEXT) \

xEXEDEP_DIRS = \
../../lib/libcos \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcos.$(SLIBEXT):
	@(echo      Building libcos.$(SLIBEXT) ...;\
	  pushd ../../lib/libcos;\
	  ((make) || (exit 1));\
	  popd)
