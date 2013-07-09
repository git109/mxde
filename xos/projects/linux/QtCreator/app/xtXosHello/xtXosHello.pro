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
#   File: xtXosHello.pro
#
# Author: $author$
#   Date: 7/2/2013
#
# QtCreator project for Executable xtXosHello
########################################################################
include(../../../../QtCreator/lib/libXosCore.pri)

TARGET = xtXosHello

INCLUDEPATH += \
$$(HOME)/build/motif/include \
$${libXosCore_INCLUDEPATH} \

DEFINES += \
$${libXosCore_DEFINES} \

SOURCES += \
$${XOS_SRC}/app/gui/x11/xt/hello/Main.cpp \

LIBS += \
-L$${XOS_LIB}/libXosXt \
-L$${XOS_LIB}/libXosX11 \
-lXosXt \
-lXosX11 \
$${libXosCore_LIBS} \
-lGL \
-lGLU \
-lXaw \
-lXt \
-lX11 \
-lXpm \
-lXext \
-lrt \
