########################################################################
# Copyright (c) 1988-2013 $organization$
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
#   File: libcbase.pro
#
# Author: $author$
#   Date: 6/18/2013
#
# QtCreator project for Static Library libcbase
########################################################################
SRC = ../../../../../src

TARGET = cbase

TEMPLATE = lib

INCLUDEPATH += \
$$SRC/clib/cos/cplatform \
$$SRC/clib/cos \
$$SRC/clib/cbase \

DEFINES += \

CONFIG += staticlib

SOURCES += \
$$SRC/clib/cbase/cbase.cxx \
$$SRC/clib/cbase/cchars.cxx \
$$SRC/clib/cbase/cerror.cxx \
$$SRC/clib/cbase/cexportbase.cxx \
$$SRC/clib/cbase/cimplementbase.cxx \
$$SRC/clib/cbase/cinterfacebase.cxx \
$$SRC/clib/cbase/ctypes.cxx \
$$SRC/clib/cbase/cacquired.cxx \
$$SRC/clib/cbase/cacquiredinterface.cxx \
$$SRC/clib/cbase/callocated.cxx \
$$SRC/clib/cbase/callocatedinterface.cxx \
$$SRC/clib/cbase/cattached.cxx \
$$SRC/clib/cbase/cattachedinterface.cxx \
$$SRC/clib/cbase/cbuffer.cxx \
$$SRC/clib/cbase/cbufferinterface.cxx \
$$SRC/clib/cbase/ccreated.cxx \
$$SRC/clib/cbase/ccreatedinterface.cxx \
$$SRC/clib/cbase/cinstance.cxx \
$$SRC/clib/cbase/cinstancebase.cxx \
$$SRC/clib/cbase/cinstanceinterface.cxx \
$$SRC/clib/cbase/clist.cxx \
$$SRC/clib/cbase/clistitem.cxx \
$$SRC/clib/cbase/copened.cxx \
$$SRC/clib/cbase/copenedinterface.cxx \
$$SRC/clib/cbase/cattachedsequence.cxx \
$$SRC/clib/cbase/ccounter.cxx \
$$SRC/clib/cbase/cdigitizer.cxx \
$$SRC/clib/cbase/csequence.cxx \
$$SRC/clib/cbase/csequenceinterface.cxx \
$$SRC/clib/cbase/csplitter.cxx \
$$SRC/clib/cbase/cstore.cxx \
$$SRC/clib/cbase/cstoreinterface.cxx \
$$SRC/clib/cbase/cattachedstream.cxx \
$$SRC/clib/cbase/cnamevalueevent.cxx \
$$SRC/clib/cbase/cnamevalueeventinterface.cxx \
$$SRC/clib/cbase/cstream.cxx \
$$SRC/clib/cbase/cstreaminterface.cxx \
$$SRC/clib/cbase/creader.cxx \
$$SRC/clib/cbase/creaderinterface.cxx \
$$SRC/clib/cbase/ctchartocharreader.cxx \
$$SRC/clib/cbase/cwriter.cxx \
$$SRC/clib/cbase/cwriterinterface.cxx \
$$SRC/clib/cbase/cccharstringinterface.cxx \
$$SRC/clib/cbase/cchar.cxx \
$$SRC/clib/cbase/ccharinterface.cxx \
$$SRC/clib/cbase/cstring.cxx \
$$SRC/clib/cbase/cstringbase.cxx \
$$SRC/clib/cbase/cstringbaseinterface.cxx \
$$SRC/clib/cbase/cstringinterface.cxx \
$$SRC/clib/cbase/ctchartostring.cxx \
$$SRC/clib/cbase/cavltree.cxx \
$$SRC/clib/cbase/cavltreebranch.cxx \
$$SRC/clib/cbase/cavltreebranchinterface.cxx \
$$SRC/clib/cbase/cavltreeinterface.cxx \
$$SRC/clib/cbase/ctree.cxx \
$$SRC/clib/cbase/ctreebase.cxx \
$$SRC/clib/cbase/ctreebranch.cxx \
$$SRC/clib/cbase/ctreebranchinterface.cxx \
$$SRC/clib/cbase/ctreeinterface.cxx \
$$SRC/clib/cbase/cseparatorinterface.cxx \
$$SRC/clib/cbase/carray.cxx \
$$SRC/clib/cbase/carrayinterface.cxx \
$$SRC/clib/cbase/creference.cxx \
$$SRC/clib/cbase/creferenced.cxx \
$$SRC/clib/cbase/creferencedinstance.cxx \
$$SRC/clib/cbase/creferenceinstance.cxx \
$$SRC/clib/cbase/cloaded.cxx \
$$SRC/clib/cbase/cloadedinterface.cxx \
$$SRC/clib/cbase/cdelegated.cxx \
$$SRC/clib/cbase/cdelegatedinterface.cxx \

