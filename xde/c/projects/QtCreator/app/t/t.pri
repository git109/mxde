########################################################################
# Copyright (c) 1988-2015 $organization$
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
#   File: t.pri
#
# Author: $author$
#   Date: 1/20/2015
########################################################################

t_INCLUDEPATH += \

t_DEFINES += \

t_HEADERS += \
$${XDE_SRC}/clib/ct/ctdatefunctions.hxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.hxx \
$${XDE_SRC}/clib/ct/ctfunctions.hxx \
$${XDE_SRC}/clib/ct/ctmain.hxx \
$${XDE_SRC}/clib/cos/argmain.hxx \

t_SOURCES += \
$${XDE_SRC}/clib/ct/ctdatefunctions.cxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.cxx \
$${XDE_SRC}/clib/ct/ctfunctions.cxx \
$${XDE_SRC}/clib/ct/ctmain.cxx \
$${XDE_SRC}/clib/cos/argmain.cxx \
$${XDE_SRC}/clib/cos/cdebug_printf.c \

t_LIBS += \
-L$${XDE_LIB}/libct \
-lct \
-L$${XDE_LIB}/libcos \
-lcos \
-L$${XDE_LIB}/libcbase \
-lcbase \
