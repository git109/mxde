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
#   File: mydriver.makefile
#
# Author: $author$
#   Date: 8/1/2005
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

MAKEFILE=mydriver.makefile
DEPENDFILE=dependfile

###################################################################
# path settings

TEMPLATE=.
INCLUDE=.
SRC=.
LIB=.
OBJ=.
BIN=.

###################################################################
# compiler settings

KERNEL_CC=gcc -c
CC=gcc -c
CCXX=g++ -c

KERNEL_CC_OPTIONS= -D_DBPRINTK -D__KERNEL__ -DLINUX -DMODULE -Wall -O2 -pipe
CC_OPTIONS= -g
CCXX_OPTIONS= -g

KERNEL_CC_INCLUDE_PATHS= -I$(INCLUDE) -I/usr/src/linux-2.4/include
CC_INCLUDE_PATHS= -I$(INCLUDE)
CCXX_INCLUDE_PATHS= -I$(INCLUDE)

###################################################################
# linker settings

KERNEL_LDC=ld -r
LDC=gcc
LDCXX=g++

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
# mydriver target

DRIVER_C= \
	$(SRC)/mydriver.c

DRIVER_C_OBJS=$(DRIVER_C:.c=.o)

DRIVER_OBJS=$(DRIVER_C_OBJS) 

DRIVER_MOD=mydriver.o

#################################################################
# driverd target

DRIVERD_CXX= \
	$(SRC)/main.cxx \
	$(SRC)/mytest.cxx

DRIVERD_CXX_OBJS=$(DRIVERD_CXX:.cxx=.o)

DRIVERD_OBJS=$(DRIVERD_CXX_OBJS) 

DRIVERD_EXE=mytest

###################################################################
# all targets

KERNEL_C=$(DRIVER_C) 
C=
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
# mydriver rules

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


