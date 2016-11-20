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
#   File: cxxlcgi.pri
#
# Author: $author$
#   Date: 1/20/2015
########################################################################

cxxlcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

cxxlcgi_DEFINES += \
$${xde_DEFINES} \

cxxlcgi_HEADERS += \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlcgi.hxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlex.hxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlexer.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.hxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.hxx \
$${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.hxx \
$${XDE_SRC}/clib/cyy/clexercgi.hxx \
$${XDE_SRC}/clib/cyy/clexercgilex.hxx \
$${XDE_SRC}/clib/cyy/clexersource.hxx \
$${XDE_SRC}/clib/cyy/clexertoken.hxx \
$${XDE_SRC}/clib/cyy/cyylexer.hxx \
$${XDE_SRC}/clib/ct/ctfunctions.hxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.hxx \
$${XDE_SRC}/clib/ct/ctdatefunctions.hxx \

cxxlcgi_SOURCES += \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlcgi.cxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlex.cxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlexer.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.cxx \
$${XDE_SRC}/clib/cyy/clexercgi.cxx \
$${XDE_SRC}/clib/cyy/clexercgilex.cxx \
$${XDE_SRC}/clib/cyy/clexersource.cxx \
$${XDE_SRC}/clib/cyy/clexertoken.cxx \
$${XDE_SRC}/clib/cyy/cyylexer.cxx \
$${XDE_SRC}/clib/ct/ctfunctions.cxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.cxx \
$${XDE_SRC}/clib/ct/ctdatefunctions.cxx \
$${XDE_SRC}/clib/cos/cdebug_printf.c \

cxxlcgi_LIBS += \
-L$${XDE_LIB}/libct \
-lct \
-L$${XDE_LIB}/libccgi \
-lccgi \
-L$${XDE_LIB}/libcos \
-lcos \
-L$${XDE_LIB}/libcbase \
-lcbase \
