#############################################################################
# Copyright (c) 1988-2017 medusa@medusade.org
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
#   Date: 12/23/2017
#
# Os Gcc makefile for libcos library
#############################################################################
OS = macosx
PKG = ../../../../..

BLD = build/$(OS)/gcc
PRJ = projects/$(OS)/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \
-I$(PKG)/$(SRC)/clib \

#
# targets
#
LIBTARGET = libcbase.a

#
# library C sources
#
LIB_C_SOURCES = \

#
# library C++ .cxx sources
#
LIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cbase/cerror.cxx \
$(PKG)/$(SRC)/clib/cbase/ctypes.cxx \
$(PKG)/$(SRC)/clib/cbase/cbase.cxx \
$(PKG)/$(SRC)/clib/cbase/cexportbase.cxx \
$(PKG)/$(SRC)/clib/cbase/cinterfacebase.cxx \
$(PKG)/$(SRC)/clib/cbase/cimplementbase.cxx \
$(PKG)/$(SRC)/clib/cbase/cinstancebase.cxx \
$(PKG)/$(SRC)/clib/cbase/cinstance.cxx \
$(PKG)/$(SRC)/clib/cbase/cinstanceinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cacquired.cxx \
$(PKG)/$(SRC)/clib/cbase/cacquiredinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/callocated.cxx \
$(PKG)/$(SRC)/clib/cbase/callocatedinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cattached.cxx \
$(PKG)/$(SRC)/clib/cbase/cattachedinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/ccreated.cxx \
$(PKG)/$(SRC)/clib/cbase/ccreatedinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cbuffer.cxx \
$(PKG)/$(SRC)/clib/cbase/cbufferinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/copened.cxx \
$(PKG)/$(SRC)/clib/cbase/copenedinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/clist.cxx \
$(PKG)/$(SRC)/clib/cbase/clistitem.cxx \
$(PKG)/$(SRC)/clib/cbase/cattachedsequence.cxx \
$(PKG)/$(SRC)/clib/cbase/ccounter.cxx \
$(PKG)/$(SRC)/clib/cbase/cdigitizer.cxx \
$(PKG)/$(SRC)/clib/cbase/csequence.cxx \
$(PKG)/$(SRC)/clib/cbase/csequenceinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/csplitter.cxx \
$(PKG)/$(SRC)/clib/cbase/cstore.cxx \
$(PKG)/$(SRC)/clib/cbase/cstoreinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cattachedstream.cxx \
$(PKG)/$(SRC)/clib/cbase/cnamevalueevent.cxx \
$(PKG)/$(SRC)/clib/cbase/cnamevalueeventinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/creader.cxx \
$(PKG)/$(SRC)/clib/cbase/creaderinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cstream.cxx \
$(PKG)/$(SRC)/clib/cbase/cstreaminterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cwriter.cxx \
$(PKG)/$(SRC)/clib/cbase/cwriterinterface.cxx \
$(PKG)/$(SRC)/clib/cbase/cstring.cxx \
$(PKG)/$(SRC)/clib/cbase/cstringinterface.cxx \

include $(PKG)/$(PRJ)/Makerules
