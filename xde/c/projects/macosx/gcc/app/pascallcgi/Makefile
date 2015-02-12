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
# MaxOSX makefile for XDE pascallcgi executable
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
-I$(PKG)/$(SRC)/ct \
-I$(PKG)/$(SRC)/cyy \
-I$(PKG)/$(SRC)/ccgi \
-I$(PKG)/$(SRC)/cxttp \

#
# targets
#
EXETARGET = pascallcgi

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/ccgi/cgi.cxx \
$(PKG)/$(SRC)/capp/pascalcgi/cpascallex.cxx \
$(PKG)/$(SRC)/capp/pascalcgi/cpascallexer.cxx \
$(PKG)/$(SRC)/capp/pascalcgi/cpascalcgi.cxx \
$(PKG)/$(SRC)/ct/ctfilefunctions.cxx \
$(PKG)/$(SRC)/ct/ctfunctions.cxx \
$(PKG)/$(SRC)/cyy/clexercgilex.cxx \

#
# executable libs
#
LIBS = \
-lct \
-lccgi \
-lcos \

include $(PKG)/$(PRJ)/Makerules
