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
#   File: libcxt.pro
#
# Author: $author$
#   Date: 6/22/2013
#
# QtCreator project for Static Library libcxt
########################################################################
SRC = ../../../../../src
LIB = ../../lib

TARGET = cxt

TEMPLATE = lib

INCLUDEPATH += \
$$(HOME)/build/motif/include \
$$SRC/clib/cx11/cxm/cplatform \
$$SRC/clib/cx11/cxm \
$$SRC/clib/cx11/cxaw \
$$SRC/clib/cx11/cxaw/cplatform \
$$SRC/clib/cx11/cxt/cplatform \
$$SRC/clib/cx11/cxt \
$$SRC/clib/cx11/cplatform \
$$SRC/clib/cx11 \
$$SRC/clib/cimage/cx11 \
$$SRC/clib/cimage \
$$SRC/clib/cos/cplatform \
$$SRC/clib/cos \
$$SRC/clib/cbase \

DEFINES += \

CONFIG += staticlib

SOURCES += \
$$SRC/clib/cx11/cxt/cxtbase.cxx \
$$SRC/clib/cx11/cxt/cxtbaseinterface.cxx \
$$SRC/clib/cx11/cxt/cxteventhandler.cxx \
$$SRC/clib/cx11/cxt/cxteventhandlerinterface.cxx \
$$SRC/clib/cx11/cxt/cxtstring.cxx \
$$SRC/clib/cx11/cxt/cxtappcontext.cxx \
$$SRC/clib/cx11/cxt/cxtappcontextattached.cxx \
$$SRC/clib/cx11/cxt/cxtapplicationshellmain.cxx \
$$SRC/clib/cx11/cxt/cxtmain.cxx \
$$SRC/clib/cx11/cxt/cxtmaininterface.cxx \
$$SRC/clib/cx11/cxt/cxtshapedmain.cxx \
$$SRC/clib/cx11/cxt/cxtarg.cxx \
$$SRC/clib/cx11/cxt/cxtarginterface.cxx \
$$SRC/clib/cx11/cxt/cxtargitem.cxx \
$$SRC/clib/cx11/cxt/cxtarglist.cxx \
$$SRC/clib/cx11/cxt/cxtarglistinterface.cxx \
$$SRC/clib/cx11/cxt/cxtcommandwidget.cxx \
$$SRC/clib/cx11/cxt/cxtcompositewidget.cxx \
$$SRC/clib/cx11/cxt/cxttextwidget.cxx \
$$SRC/clib/cx11/cxt/cxtwidget.cxx \
$$SRC/clib/cx11/cxt/cxtwidgetattached.cxx \
$$SRC/clib/cx11/cxt/cxtwidgetcreated.cxx \
$$SRC/clib/cx11/cxt/cxtwidgetinterface.cxx \
$$SRC/clib/cx11/cxt/cxtcore.cxx \
$$SRC/clib/cx11/cxt/cxtcoreinterface.cxx \
$$SRC/clib/cx11/cxt/cxtobject.cxx \
$$SRC/clib/cx11/cxt/cxtobjectinterface.cxx \
$$SRC/clib/cx11/cxt/cxtrectobj.cxx \
$$SRC/clib/cx11/cxt/cxtrectobjinterface.cxx \
$$SRC/clib/cx11/cxt/cxtwindowobj.cxx \
$$SRC/clib/cx11/cxt/cxtwindowobjinterface.cxx \
$$SRC/clib/cx11/cxt/cxtcomposite.cxx \
$$SRC/clib/cx11/cxt/cxtcompositeinterface.cxx \
$$SRC/clib/cx11/cxt/cxtshell.cxx \
$$SRC/clib/cx11/cxt/cxtshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxtoverrideshell.cxx \
$$SRC/clib/cx11/cxt/cxtoverrideshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxtwmshell.cxx \
$$SRC/clib/cx11/cxt/cxtwmshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxtvendorshell.cxx \
$$SRC/clib/cx11/cxt/cxtvendorshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxttoplevelshell.cxx \
$$SRC/clib/cx11/cxt/cxttoplevelshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxtapplicationshell.cxx \
$$SRC/clib/cx11/cxt/cxtapplicationshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxtellipticalroundedapplicationshell.cxx \
$$SRC/clib/cx11/cxt/cxtshapedapplicationshell.cxx \
$$SRC/clib/cx11/cxt/cxttransientshell.cxx \
$$SRC/clib/cx11/cxt/cxttransientshellinterface.cxx \
$$SRC/clib/cx11/cxt/cxtconstraint.cxx \
$$SRC/clib/cx11/cxt/cxtconstraintinterface.cxx \
$$SRC/clib/cx11/cxt/cxtwidgetclass.cxx \
$$SRC/clib/cx11/cxt/cxtwidgetclassattached.cxx \
$$SRC/clib/cx11/cxt/cxtwidgetclassinterface.cxx \
$$SRC/clib/cx11/cxt/cxtcallback.cxx \
$$SRC/clib/cx11/cxt/cxtcallbackinterface.cxx \

