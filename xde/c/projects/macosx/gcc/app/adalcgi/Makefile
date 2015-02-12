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
#   Date: 7/31/2009
#
# MaxOSX makefile for XDE adalcgi executable
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
-I$(PKG)/$(SRC)/cfs \
-I$(PKG)/$(SRC)/cyy \
-I$(PKG)/$(SRC)/ccgi \
-I$(PKG)/$(SRC)/cxttp

#
# targets
#
EXETARGET = adalcgi

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/capp/adacgi/cadalex.cxx \
$(PKG)/$(SRC)/capp/adacgi/cadalexer.cxx \
$(PKG)/$(SRC)/capp/adacgi/cadacgi.cxx \
$(PKG)/$(SRC)/cyy/clexercgilex.cxx \
$(PKG)/$(SRC)/cyy/clexersource.cxx \
$(PKG)/$(SRC)/cyy/clexertoken.cxx \
$(PKG)/$(SRC)/cyy/cyylexer.cxx \
$(PKG)/$(SRC)/ccgi/ctemplatenamelist.cxx \
$(PKG)/$(SRC)/ccgi/cdocumentnamelist.cxx \
$(PKG)/$(SRC)/ccgi/ctemplatefilenameitems.cxx \
$(PKG)/$(SRC)/ccgi/cdocumentfilenameitems.cxx \
$(PKG)/$(SRC)/ccgi/cgi.cxx \

#
# executable libs
#
LIBS = \
-lct \
-lccgi \
-lcos \

include $(PKG)/$(PRJ)/Makerules
