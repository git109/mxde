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
# Os Gcc makefile for libcxttp library
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
-I$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi \
-I$(PKG)/$(SRC)/clib/cxttp/chttp \
-I$(PKG)/$(SRC)/clib/cxttp \

#
# targets
#
LIBTARGET = libcxttp.a

#
# library C++ .cxx sources
#
LIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cxttp/cxttp.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttp.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/curlencodedstream.cxx \
\
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformfieldinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformfielditem.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformfieldlist.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformfield.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformfieldsinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformfields.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ctohttpformwriterinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ctohttpformwriter.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformreaderinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpformreader.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpforminterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/chttpform.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgimain.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/cdiagnosticcgimain.cxx \
\
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgi.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgibase.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgiinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ctocgienvwriterinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ctocgienvwriter.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgienvreaderinterface.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgienvreader.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgienv.cxx \
$(PKG)/$(SRC)/clib/cxttp/chttp/ccgi/ccgimaininterface.cxx \

include $(PKG)/$(PRJ)/Makerules
