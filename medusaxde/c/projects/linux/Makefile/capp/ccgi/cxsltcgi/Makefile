########################################################################
# Copyright (c) 1988-2011 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: $date$
#
# Linux Gcc Makefile for Executable cxsltcgi Xos Development project
########################################################################

PKG = $(MEDUSAXDECROOT)

BLD = build/linux
PRJ = projects/linux/Makefile
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user defines
#
USRDEFINES = \

#
# user includes
#
USRINCLUDES = \
-I$(HOME)/build/cgicc/include/cgicc \
-I$(HOME)/build/cgicc/include \
-I$(PKG)/src/clib/cxttp/chttp/ccgi \
-I$(PKG)/src/clib/cxttp/chttp \
-I$(PKG)/src/clib/cxttp \
-I$(PKG)/src/clib/cxml/cxslt \
-I$(PKG)/src/clib/cxml \

#
# targets
#
EXETARGET = cxsltcgi

#
# Executable C sources
#
EXE_C_SOURCES = \

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES = \

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES = \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cCgi_main.cpp \
$(PKG)/$(SRC)/capp/ccgi/cxsltcgi/cXsltCgi.cpp \

#
# Executable libs
#
#LIBS = \
#-lsomelib
#
LIBS = \
-lccgicc \
-lcxalan \
-lcxttp \
-lcos \
-lcbase \

#
# Executable depends
#
#EXEDEP = \
#$(PKG)/$(BLD)/libsomelib.a \
#
EXEDEP = \

#
# Executable depend dirs
#
#EXEDEP_DIRS = \
#../libsomelib
#
EXEDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#

