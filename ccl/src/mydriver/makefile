#############################################################################
# Copyright (c) 1988-2005 $organization$.
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
#   Date: 11/14/2007
#
#    $Id$
#
# Makefile for Linux driver "mydriver".
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
LIB=.
BIN=.

CCL=../..

INCLUDE_PATHS= \
	-I$(CCL)/src/ieee80215 \
	-I$(CCL)/src/cservlet \
	-I$(CCL)/src

KERNEL_CC_INCLUDE_PATHS= \
	-I/usr/src/linux-2.4/include \
	-I$(CCL)/src

CC_INCLUDE_PATHS= $(INCLUDE_PATHS)
CCXX_INCLUDE_PATHS= $(INCLUDE_PATHS)

###################################################################
# compiler settings

GCC=/usr/local/gcc335/bin/gcc
GXX=/usr/local/gcc335/bin/g++
#GCC=gcc
#GXX=g++

KERNEL_CC=$(GCC) -c
CC=$(GCC) -c
CCXX=$(GXX) -c

KERNEL_CC_OPTIONS= -D_DBPRINTK -D__KERNEL__ -DLINUX -DMODULE -Wall -O2 -pipe
CC_OPTIONS= -g
CCXX_OPTIONS= -g

###################################################################
# linker settings

KERNEL_LDC=ld -r
LDC=$(GCC)
LDCXX=$(GXX)

KERNEL_LDC_OPTIONS=
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
# driver target

DRIVER_C= \
	mydriver.c

DRIVER_C_OBJS=$(DRIVER_C:.c=.o)

DRIVER_OBJS=$(DRIVER_C_OBJS) 

DRIVER_MOD=mydriver

#################################################################
# driverd target

DRIVERD_C= \

DRIVERD_CXX= \
	main.cxx \
	mytest.cxx

DRIVERD_C_OBJS=$(DRIVERD_C:.c=.o)

DRIVERD_CXX_OBJS=$(DRIVERD_CXX:.cxx=.o)

DRIVERD_OBJS=$(DRIVERD_C_OBJS) $(DRIVERD_CXX_OBJS) 

DRIVERD_EXE=mytest

###################################################################
# all targets

KERNEL_C=$(DRIVER_C) 
C=$(DRIVERD_C)
CXX=$(DRIVERD_CXX)
CPP=

OBJS=$(DRIVER_OBJS) $(DRIVERD_OBJS)
MODS=$(DRIVER_MOD) 
EXES=$(DRIVERD_EXE)

###################################################################
# standard rules

all: $(MODS) $(EXES) $(OBJS)

depend:
	makedepend $(MAKEDEPEND_OPTIONS) -f$(DEPENDFILE) \
	$(KERNEL_CC_INCLUDE_PATHS) $(CC_INCLUDE_PATHS) $(CCXX_INCLUDE_PATHS) \
	$(KERNEL_C) $(C) $(CXX) $(CPP)

clean:
	rm -f $(MODS)
	rm -f $(EXES)
	rm -f $(OBJS)

#################################################################
# driver rules

$(DRIVER_MOD): $(DRIVER_OBJS) $(DRIVER_LIBS)
	$(KERNEL_LDC) $(KERNEL_LDC_OPTIONS) -o $(@) $(KERNEL_LDC_LIB_PATHS) $(DRIVER_LIBS) $(DRIVER_OBJS)

#################################################################
# driverd rules

$(DRIVERD_EXE): $(DRIVERD_OBJS) $(DRIVERD_LIBS)
	$(LDCXX) $(LDCXX_OPTIONS) -o $(@) $(LDCXX_LIB_PATHS) $(DRIVERD_LIBS) $(DRIVERD_OBJS)

#################################################################
# implicit rules

$(KERNEL_C:.c=.o): %.o: %.c
	$(KERNEL_CC) $(KERNEL_CC_OPTIONS) $(KERNEL_CC_INCLUDE_PATHS) -o $@ $<

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
