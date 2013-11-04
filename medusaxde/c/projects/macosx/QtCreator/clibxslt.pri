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
#   File: clibxslt.pri
#
# Author: $author$
#   Date: 11/2/2013
########################################################################
clibxslt_INCLUDEPATH += \
${HOME}/build/libxslt/include \
${HOME}/build/libxml2/include/libxml2 \
$${PKG}/$${SRC}/clib/cxml/cxslt \
$${PKG}/$${SRC}/clib/cxml \

clibxslt_DEFINES += \

clibxslt_HEADERS += \

clibxslt_SOURCES += \

clibxslt_LIBS += \
-L${HOME}/build/libxslt/lib \
-lxslt \
-lexslt \
-L${HOME}/build/libxml2/lib \
-lxml2 \
-L$${BLD}/lib/libclibxslt \
-lclibxslt \



        

