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
#   File: libcx11.pro
#
# Author: $author$
#   Date: 6/18/2013
#
# QtCreator project for Static Library libcx11
########################################################################
SRC = ../../../../../src

TARGET = cx11

TEMPLATE = lib

INCLUDEPATH += \
$$SRC/clib/cx11/cxm/cplatform \
$$SRC/clib/cx11/cxm \
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
$$SRC/clib/cx11/cxbase.cxx \
$$SRC/clib/cx11/cxbaseinterface.cxx \
$$SRC/clib/cx11/cxeventtarget.cxx \
$$SRC/clib/cx11/cxeventtargetinterface.cxx \
$$SRC/clib/cx11/cxrectangle.cxx \
$$SRC/clib/cx11/cxmaininterface.cxx \
$$SRC/clib/cx11/cxwindowmain.cxx \
$$SRC/clib/cx11/cxwindowmaininterface.cxx \
$$SRC/clib/cx11/cxwindow.cxx \
$$SRC/clib/cx11/cxwindowattached.cxx \
$$SRC/clib/cx11/cxwindowcreated.cxx \
$$SRC/clib/cx11/cxwindowinterface.cxx \
$$SRC/clib/cx11/cxgc.cxx \
$$SRC/clib/cx11/cxgcattached.cxx \
$$SRC/clib/cx11/cxgcinterface.cxx \
$$SRC/clib/cx11/cxgetgc.cxx \
$$SRC/clib/cx11/cxgetgcinterface.cxx \
$$SRC/clib/cx11/cxdrawableattached.cxx \
$$SRC/clib/cx11/cxregion.cxx \
$$SRC/clib/cx11/cxregionattached.cxx \
$$SRC/clib/cx11/cxregioninterface.cxx \
$$SRC/clib/cx11/cxobject.cxx \
$$SRC/clib/cx11/cxobjectinterface.cxx \
$$SRC/clib/cx11/cxcolor.cxx \
$$SRC/clib/cx11/cxcolorinterface.cxx \
$$SRC/clib/cx11/cxcolormap.cxx \
$$SRC/clib/cx11/cxcolormapattached.cxx \
$$SRC/clib/cx11/cxcolormapinterface.cxx \
$$SRC/clib/cx11/cxpixel.cxx \
$$SRC/clib/cx11/cxpixelattached.cxx \
$$SRC/clib/cx11/cxpixelinterface.cxx \
$$SRC/clib/cx11/cxatom.cxx \
$$SRC/clib/cx11/cxatomattached.cxx \
$$SRC/clib/cx11/cxatominterface.cxx \
$$SRC/clib/cx11/cxmwmhints.cxx \
$$SRC/clib/cx11/cxmwmhintsinterface.cxx \
$$SRC/clib/cx11/cxproperty.cxx \
$$SRC/clib/cx11/cxpropertyinterface.cxx \
$$SRC/clib/cx11/cxpixmap.cxx \
$$SRC/clib/cx11/cxpixmapattached.cxx \
$$SRC/clib/cx11/cxpixmapinterface.cxx \
$$SRC/clib/cx11/cxpm.cxx \
$$SRC/clib/cx11/cxpmimage.cxx \
$$SRC/clib/cx11/cxpmimageinterface.cxx \
$$SRC/clib/cx11/cxpminfo.cxx \
$$SRC/clib/cx11/cxpminfointerface.cxx \
$$SRC/clib/cx11/cxpminterface.cxx \
$$SRC/clib/cimage/cx11/cximage.cxx \
$$SRC/clib/cimage/cx11/cximagebase.cxx \
$$SRC/clib/cimage/cx11/cximagebaseinterface.cxx \
$$SRC/clib/cimage/cx11/cximagecolor.cxx \
$$SRC/clib/cimage/cx11/cximageinterface.cxx \
$$SRC/clib/cimage/cx11/cximageobject.cxx \
$$SRC/clib/cx11/cxfont.cxx \
$$SRC/clib/cx11/cxfontattached.cxx \
$$SRC/clib/cx11/cxfontinterface.cxx \
$$SRC/clib/cx11/cxfontstruct.cxx \
$$SRC/clib/cx11/cxfontstructattached.cxx \
$$SRC/clib/cx11/cxfontstructinterface.cxx \
$$SRC/clib/cx11/cxdisplay.cxx \
$$SRC/clib/cx11/cxdisplayattached.cxx \
$$SRC/clib/cx11/cxdisplayinterface.cxx \
$$SRC/clib/cx11/cxdisplayopened.cxx \

