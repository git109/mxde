#############################################################################
# Copyright (c) 1988-2008 $organization$
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
# Author: $author$
#   Date: 12/22/2008
#
#############################################################################

PKG = $(PWD)/../../../../../..

BLD = build/macosx
PRJ = projects/macosx/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase

#
# user defines
#
USRDEFINES = \
-DDEFAULT_DEBUG_LEVELS=1

#
# user ld flags
#
USRLDFLAGS = \
-L$(PKG)/$(BLD)

#
# targets
#
LIBTARGET = libcipc.$(LIBEXT)

#
# library C sources
#
LIB_C_SOURCES = \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform_ipc.c \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform_msg.c \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform_semaphore.c \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform_mutex.c \
$(PKG)/$(SRC)/clib/cos/cplatform/cplatform_thread.c \

#
# library C++ .cxx sources
#
LIB_CXX_SOURCES = \
$(PKG)/$(SRC)/clib/cos/cmessagequeueinterface.cxx \
$(PKG)/$(SRC)/clib/cos/cmessagequeue.cxx \
$(PKG)/$(SRC)/clib/cos/csemaphoreinterface.cxx \
$(PKG)/$(SRC)/clib/cos/csemaphore.cxx \
$(PKG)/$(SRC)/clib/cos/cthreadinterface.cxx \
$(PKG)/$(SRC)/clib/cos/cthread.cxx \

include $(PKG)/$(PRJ)/Makerules
