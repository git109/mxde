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
#   File: libcxm.pro
#
# Author: $author$
#   Date: 6/24/2013
#
# QtCreator project for Static Library libcxm
########################################################################
SRC = ../../../../../src
LIB = ../../lib

TARGET = cxm

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
$$SRC/clib/cx11/cxm/cxmapplicationshell.cxx \
$$SRC/clib/cx11/cxm/cxmbase.cxx \
$$SRC/clib/cx11/cxm/cxmdropsite.cxx \
$$SRC/clib/cx11/cxm/cxmmain.cxx \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_Display.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_DragC.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_DragDrop.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_Label.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_MainW.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_Primitive.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_PushB.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_Text.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_TextF.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_Transfer.c \
$$SRC/clib/cx11/cxm/cplatform/cplatform_Xm_Xm.c \
$$SRC/clib/cx11/cxm/cxmmanager.cxx \
$$SRC/clib/cx11/cxm/cxmmanagerinterface.cxx \
$$SRC/clib/cx11/cxm/cxmbulletinboard.cxx \
$$SRC/clib/cx11/cxm/cxmbulletinboardinterface.cxx \
$$SRC/clib/cx11/cxm/cxmform.cxx \
$$SRC/clib/cx11/cxm/cxmforminterface.cxx \
$$SRC/clib/cx11/cxm/cxmprimitive.cxx \
$$SRC/clib/cx11/cxm/cxmprimitiveinterface.cxx \
$$SRC/clib/cx11/cxm/cxmtext.cxx \
$$SRC/clib/cx11/cxm/cxmtextinterface.cxx \
$$SRC/clib/cx11/cxm/cxmlabel.cxx \
$$SRC/clib/cx11/cxm/cxmlabelinterface.cxx \
$$SRC/clib/cx11/cxm/cxmpushbutton.cxx \
$$SRC/clib/cx11/cxm/cxmpushbuttoninterface.cxx \
$$SRC/clib/cx11/cxm/cxmtextfield.cxx \
$$SRC/clib/cx11/cxm/cxmtextfieldinterface.cxx \
$$SRC/clib/cx11/cxm/cxmstring.cxx \
$$SRC/clib/cx11/cxm/cxmstringattached.cxx \
$$SRC/clib/cx11/cxm/cxmstringcreated.cxx \

