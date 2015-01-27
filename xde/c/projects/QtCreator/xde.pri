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
#   File: xde.pri
#
# Author: $author$
#   Date: $date$
#
# QtCreator project include for xde
########################################################################

XDE_PKG = ../../../../../..
XDE_BLD = ../..
XDE_PRJ = $${XDE_PKG}
XDE_SRC = $${XDE_PKG}/c/src
XDE_BIN = $${XDE_BLD}/bin
XDE_LIB = $${XDE_BLD}/lib

########################################################################
# thirdparty
THIRDPARTY = $${XDE_PRJ}/../thirdparty

########################################################################
# xerces-xalan
XML_XERCES_XALAN = $${THIRDPARTY}/xml-xerces-xalan
XML_XERCES = $${XML_XERCES_XALAN}/xml-xerces
XML_XALAN = $${XML_XERCES_XALAN}/xml-xalan
XML_XERCES_C_ROOT = $${XML_XERCES}/c
XML_XALAN_C_ROOT = $${XML_XALAN}/c
XML_XERCES_C_LIB = $${XML_XERCES_C_ROOT}/lib
XML_XERCES_C_SRC = $${XML_XERCES_C_ROOT}/src
XML_XERCES_C_SRC_XERCESC = $${XML_XERCES_C_SRC}/xercesc
XML_XALAN_C_LIB = $${XML_XALAN_C_ROOT}/lib
XML_XALAN_C_SRC = $${XML_XALAN_C_ROOT}/src
XML_XALAN_C_SRC_XALANC = $${XML_XALAN_C_SRC}/xalanc

XML_XERCES_INCLUDES = $${XML_XERCES_C_SRC} \
$${XML_XERCES_C_SRC_XERCESC}

XML_XERCES_LIBDIRS = $${XML_XERCES_C_LIB}
XML_XERCES_DEBUG_LIBS = xerces-c_2D.lib
XML_XERCES_RELEASE_LIBS = xerces-c_2.lib
XML_XERCES_LIBS = $${XML_XERCES_RELEASE_LIBS}

XML_XALAN_INCLUDES = $${XML_XALAN_C_SRC} \
$${XML_XALAN_C_SRC_XALANC} \
$${XML_XERCES_INCLUDES}

XML_XALAN_LIBDIRS = $${XML_XALAN_C_LIB} \
$${XML_XERCES_LIBDIRS}

XML_XALAN_DEBUG_LIBS = Xalan-C_1D.lib $${XML_XERCES_DEBUG_LIBS}
XML_XALAN_RELEASE_LIBS = Xalan-C_1.lib $${XML_XERCES_RELEASE_LIBS}
XML_XALAN_LIBS = $${XML_XALAN_RELEASE_LIBS}

########################################################################
# xde
XDE_CSERVER_INCLUDES = \
$${XDE_SRC}/clib/cserver \
$${XDE_SRC}/clib/cservlet \
$${XDE_SRC}/clib/ccgi \
$${XDE_SRC}/clib/cxttp

XDE_CXML_INCLUDES = \
$${XDE_SRC}/clib/cxml \
$${XDE_SRC}/clib/cxalan \
$${XDE_SRC}/clib/ct \
$${XDE_SRC}/clib/cyy

XDE_CMPINT_INCLUDES = \
$${XDE_SRC}/clib/cmpint/bn \
$${XDE_SRC}/clib/cmpint/mp \
$${XDE_SRC}/clib/cmpint

XDE_COS_INCLUDES = \
$${XDE_SRC}/clib/csocket \
$${XDE_SRC}/clib/cfs \
$${XDE_SRC}/clib/cos/cwin \
$${XDE_SRC}/clib/cos/cunix \
$${XDE_SRC}/clib/cos/cplatform \
$${XDE_SRC}/clib/cos

XDE_CWIN_INCLUDES = \
$${XDE_SRC}/clib/cimager \
$${XDE_SRC}/clib/cwin

XDE_INCLUDES = \
$${XDE_CSERVER_INCLUDES} \
$${XDE_CXML_INCLUDES} \
$${XDE_CMPINT_INCLUDES} \
$${XDE_COS_INCLUDES} \
$${XDE_SRC}/clib/cbase \
$${XDE_SRC}/clib

xde_INCLUDEPATH += \
$${XDE_INCLUDES} \

xde_DEFINES += \
DB_PRINTF=platform_db_printf \
