#############################################################################
# Copyright (c) 1988-2010 medusa@medusade.org
#
# This software is provided by the author and contributors ``as is'' and
# any express or implied warranties, including, but not limited to, the
# implied warranties of merchantability and fitness for a particular purpose
# are disclaimed.  In no event shall the author or contributors be liable
# for any direct, indirect, incidental, special, exemplary, or consequential
# damages (including, but not limited to, procurement of substitute goods
# or services; loss of use, data, or profits; or business interruption)
# however caused and on any theory of liability, whether in contract, strict
# liability, or tort (including negligence or otherwise) arising in any way
# out of the use of this software, even if advised of the possibility of
# such damage.
#
#   File: Makefile
#
# Author: medusa@medusade.org
#   Date: 10/30/2010
#
# Linux makefile for libcthread shared library
#############################################################################

PKG = $(PWD)/../../../../..

BLD = build/linux/gcc
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# targets
#
SLIBTARGET = libcthread.so
EXETARGET = cthreadtest

#
# shared library C++ .cxx sources
#
SLIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cos/cthread/cmutexattached.cxx \
$(PKG)/$(SRC)/clib/cos/cthread/cmutexinterface.cxx \
$(PKG)/$(SRC)/clib/cos/cthread/cmutex.cxx \
$(PKG)/$(SRC)/clib/cos/cthread/csemaphoreattached.cxx \
$(PKG)/$(SRC)/clib/cos/cthread/csemaphoreinterface.cxx \
$(PKG)/$(SRC)/clib/cos/cthread/csemaphore.cxx \

#
# exe C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cos/cthread/cthreadtest.cxx \

#
# shared library libs
#
LIBSSO = \
-ldl \
-lpthread \
-lcbase \
-lcos \

#
# exe libs
#
LIBS = \
-lrt \
-ldl \
-lpthread \
-lcbase \
-lcthread \
-lcos \

include $(PKG)/$(PRJ)/Makerules
