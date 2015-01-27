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
#   File: libct.pri
#
# Author: $author$
#   Date: 1/20/2015
########################################################################

libct_INCLUDEPATH += \

libct_DEFINES += \

libct_HEADERS += \
$${XDE_SRC}/clib/ct/ctvariableinterface.hxx \
$${XDE_SRC}/clib/ct/ctvariable.hxx \
$${XDE_SRC}/clib/ct/ctvalueinterface.hxx \
$${XDE_SRC}/clib/ct/ctvalue.hxx \
$${XDE_SRC}/clib/ct/ctfunctioninterface.hxx \
$${XDE_SRC}/clib/ct/ctfunctionlist.hxx \
$${XDE_SRC}/clib/ct/ctfunctiontree.hxx \
$${XDE_SRC}/clib/ct/ctfunction.hxx \
$${XDE_SRC}/clib/ct/ctfunctionparameter.hxx \
$${XDE_SRC}/clib/ct/ctfunctionargument.hxx \
$${XDE_SRC}/clib/ct/ctinterface.hxx \
$${XDE_SRC}/clib/ct/ct.hxx \

libct_SOURCES += \
$${XDE_SRC}/clib/ct/ctvariableinterface.cxx \
$${XDE_SRC}/clib/ct/ctvariable.cxx \
$${XDE_SRC}/clib/ct/ctvalueinterface.cxx \
$${XDE_SRC}/clib/ct/ctvalue.cxx \
$${XDE_SRC}/clib/ct/ctfunctioninterface.cxx \
$${XDE_SRC}/clib/ct/ctfunctionlist.cxx \
$${XDE_SRC}/clib/ct/ctfunctiontree.cxx \
$${XDE_SRC}/clib/ct/ctfunction.cxx \
$${XDE_SRC}/clib/ct/ctfunctionparameter.cxx \
$${XDE_SRC}/clib/ct/ctfunctionargument.cxx \
$${XDE_SRC}/clib/ct/ctinterface.cxx \
$${XDE_SRC}/clib/ct/ct.cxx \

libct_LIBS += \



        

