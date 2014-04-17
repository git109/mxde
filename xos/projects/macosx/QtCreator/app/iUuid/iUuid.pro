########################################################################
# Copyright (c) 1988-2014 $organization$
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
#   File: iUuid.pro
#
# Author: $author$
#   Date: 2/18/2014
########################################################################
include(../../../../QtCreator/lib/libXosCore.pri)
include(../../../../QtCreator/lib/libXosCocoa.pri)

TARGET = iUuid

INCLUDEPATH += \
$${libXosCore_INCLUDEPATH} \

DEFINES += \
$${libXosCore_DEFINES} \

OBJECTIVE_HEADERS += \
$${XOS_SRC}/app/gui/cocoa/network/uuid/MainWindow.hh \
$${XOS_SRC}/app/gui/cocoa/network/uuid/iUuid.hh \

OBJECTIVE_SOURCES += \
$${XOS_SRC}/app/gui/cocoa/network/uuid/iUuid.mm \
$${XOS_SRC}/xos/gui/cocoa/iMain_main.mm \

HEADERS += \
$${XOS_SRC}/app/gui/network/uuid/MainWindow.hpp \
$${XOS_SRC}/xos/crypto/random/Pseudo.hpp \

SOURCES += \
$${XOS_SRC}/app/gui/network/uuid/MainWindow.cpp \
$${XOS_SRC}/xos/crypto/random/Pseudo.cpp \

LIBS += \
-L$${XOS_LIB}/libiCocoa \
-liCocoa \
$${libXosCore_LIBS} \
$${libXosCrypto_LIBS} \
