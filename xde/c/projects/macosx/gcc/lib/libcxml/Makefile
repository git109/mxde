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
#   Date: 1/1/2009
#
# MaxOSX makefile for XDE library libcxml.dylib
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
-I$(PKG)/$(SRC)/cxml \
-I$(PKG)/$(SRC)/cos \
-I$(PKG)/$(SRC) \

#
# targets
#
LIBTARGET = libcxml.$(LIBEXT)

#
# static library C++ .cxx sources
#
LIB_CXX_SOURCES = \
$(PKG)/$(SRC)/cxml/cxmlchar.cxx \
$(PKG)/$(SRC)/cxml/cxmlcharwriter.cxx \
$(PKG)/$(SRC)/cxml/cxmlstring.cxx \
$(PKG)/$(SRC)/cxml/cxmlchartostring.cxx \
$(PKG)/$(SRC)/cxml/cxmlstringtochars.cxx \
$(PKG)/$(SRC)/cxml/cxmlstringtostring.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodelistinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodeitem.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodelist.cxx \
$(PKG)/$(SRC)/cxml/cxmlnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodetype.cxx \
$(PKG)/$(SRC)/cxml/cxmlcharacterdatanodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlcharacterdatanode.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodenameinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodename.cxx \
$(PKG)/$(SRC)/cxml/cxmlnamednodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlnamednode.cxx \
$(PKG)/$(SRC)/cxml/cxmlparentnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlparentnamednode.cxx \
$(PKG)/$(SRC)/cxml/cxmltextnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmltextnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlentitynodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlentitynode.cxx \
$(PKG)/$(SRC)/cxml/cxmlentityreferencenodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlentityreferencenode.cxx \
$(PKG)/$(SRC)/cxml/cxmlstaticentitynode.cxx \
$(PKG)/$(SRC)/cxml/cxmlcommentnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlcommentnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlprocessinginstructionnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlprocessinginstructionnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlattributenodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlattributenode.cxx \
$(PKG)/$(SRC)/cxml/cxmlbeginelementnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlbeginelementnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlparentbeginelementnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlendelementnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlendelementnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlelementnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlelementnode.cxx \
$(PKG)/$(SRC)/cxml/cxmldocumentnodeinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmldocumentnode.cxx \
$(PKG)/$(SRC)/cxml/cxmlchartoxmlnodelistwriter.cxx \
$(PKG)/$(SRC)/cxml/cxmlchartoxmlparsereventswriter.cxx \
$(PKG)/$(SRC)/cxml/cxmlparserevents.cxx \
$(PKG)/$(SRC)/cxml/cxmldocumentparserinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmldocumentparser.cxx \
$(PKG)/$(SRC)/cxml/cxmlprocessing.cxx \
$(PKG)/$(SRC)/cxml/cxmlnodeprocessor.cxx \
$(PKG)/$(SRC)/cxml/cxmlelementprocessorlist.cxx \
$(PKG)/$(SRC)/cxml/cxmlelementnodeprocessor.cxx \
$(PKG)/$(SRC)/cxml/cxmlprocessorinterface.cxx \
$(PKG)/$(SRC)/cxml/cxmlprocessor.cxx \

LIBDEP = \
$(PKG)/$(BLD)/libcos.$(LIBEXT) \

LIBDEP_DIRS = \
../libcos \

include $(PKG)/$(PRJ)/Makerules

$(PKG)/$(BLD)/libcos.$(LIBEXT):
	@(echo      Building libcos.$(LIBEXT) ...;\
	  pushd ../libcos;\
	  ((make) || (exit 1));\
	  popd)
