#############################################################################
# Copyright (c) 1988-2017 medusa@medusade.org
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
#   Date: 12/23/2017
#
# Os makefile for libcthread library
#############################################################################
OS = macosx
PKG = ../../../../..

BLD = build/$(OS)/gcc
PRJ = projects/$(OS)/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# targets
#
LIBTARGET = libcthread.a
EXETARGET = cthreadtest

#
# library C++ .cxx sources
#
LIB_CXX_SOURCES = \
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
# exe libs
#
LIBS = \
-lcthread \
-lcos \
-lcbase \
-lpthread \
-ldl \

include $(PKG)/$(PRJ)/Makerules
