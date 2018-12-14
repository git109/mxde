#############################################################################
# Copyright (c) 1988-2006 $organization$.
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
#   File: makefile
#
# Author: $author$
#   Date: 2/19/2006
#
#    $Id$
#
# Makefile for "httpp".
#
#############################################################################


INCLUDEFILE=

ifneq "$(INCLUDEFILE)" ""
include $(INCLUDEFILE)
endif

MAKEFILE=makefile
DEPENDFILE=dependfile

###################################################################
# path settings

TEMPLATE=.
INCLUDE=.
SRC=.
LIB=.
OBJ=.
BIN=.

KERNEL_INCLUDE_PATHS= \
	-I/usr/src/linux-2.4/include

INCLUDE_PATHS= \
	-I../../src/chttp \
	-I../../src/cservlet \
	-I../../src/ieee80215 \
	-I../../src

###################################################################
# compiler settings

GCC=gcc
GXX=g++

KERNEL_CC=$(GCC) -c
CC=$(GCC) -c
CCXX=$(GXX) -c

KERNEL_CC_OPTIONS= -D_DBPRINTK -D__KERNEL__ -DLINUX -DMODULE -Wall -O2 -pipe
CC_OPTIONS= -g
CCXX_OPTIONS= -g

KERNEL_CC_INCLUDE_PATHS= $(KERNEL_INCLUDE_PATHS) $(INCLUDE_PATHS)
CC_INCLUDE_PATHS= $(INCLUDE_PATHS)
CCXX_INCLUDE_PATHS= $(INCLUDE_PATHS)

###################################################################
# linker settings

KERNEL_LDC=ld
LDC=gcc
LDCXX=g++

KERNEL_LDC_OPTIONS= -r
LDC_OPTIONS= -g
LDCXX_OPTIONS= -g

KERNEL_LDC_LIB_PATHS= -L.
LDC_LIB_PATHS= -L.
LDCXX_LIB_PATHS= -L.

###################################################################
# makedepend settings

MAKEDEPEND_INCLUDE_PATHS=$(CC_INCLUDE_PATHS) $(CCXX_INCLUDE_PATHS)
MAKEDEPEND_OPTIONS=$(MAKEDEPEND_INCLUDE_PATHS) -s"\# dependancies"

#################################################################
# target

HTTPP_CXX= \
	$(SRC)/../cmain.cxx \
	$(SRC)/../cmainarg.cxx \
	$(SRC)/httpp.cxx

HTTPP_CXX_OBJS=$(HTTPP_CXX:.cxx=.o)

HTTPP_OBJS=$(HTTPP_CXX_OBJS) 

HTTPP_EXE=httpp

###################################################################
# all targets

C=
CXX=$(HTTPP_CXX)
CPP=

OBJS=$(HTTPP_OBJS)
EXES=$(HTTPP_EXE)

###################################################################
# standard rules

all: $(EXES) $(OBJS)

depend:
	makedepend $(MAKEDEPEND_OPTIONS) -f$(DEPENDFILE) \
	$(CC_INCLUDE_PATHS) $(CCXX_INCLUDE_PATHS) \
	$(C) $(CXX) $(CPP)

clean:
	rm -f $(EXES)
	rm -f $(OBJS)

#################################################################
# target rules

$(HTTPP_EXE): $(HTTPP_OBJS) $(HTTPP_LIBS)
	$(LDCXX) $(LDCXX_OPTIONS) -o $(@) $(LDCXX_LIB_PATHS) $(HTTPP_LIBS) $(HTTPP_OBJS)

#################################################################
# implicit rules

$(C:.c=.o): %.o: %.c
	$(CC) $(CC_OPTIONS) $(CC_INCLUDE_PATHS) -o $@ $<

$(CXX:.cxx=.o): %.o: %.cxx
	$(CCXX) $(CCXX_OPTIONS) $(CCXX_INCLUDE_PATHS) -o $@ $<

$(CPP:.cpp=.o): %.o: %.cpp
	$(CCPP) $(CCPP_OPTIONS) $(CCPP_INCLUDE_PATHS) -o $@ $<


######################################################################
# included dependancies

ifneq "$(MAKEFILE)" "$(DEPENDFILE)"
ifneq "$(DEPENDFILE)" ""

$(DEPENDFILE): $(MAKEFILE)
	touch $(DEPENDFILE)
	
include $(DEPENDFILE)
endif
endif

###################################################################
# dependancies

