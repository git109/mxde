########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   File: evd2u.pro
#
# Author: $author$
#   Date: 6/28/2016
########################################################################
include(../../../QtCreator/libev/libev.pri)
include(../../../QtCreator/evd2u/evd2u.pri)

TARGET = evd2u

INCLUDEPATH += \
$${libev_INCLUDEPATH} \

HEADERS += \
$${evd2u_HEADERS} \

SOURCES += \
$${evd2u_SOURCES} \

LIBS += \
$${libev_LIBS} \
-lpthread \
-ldl \
