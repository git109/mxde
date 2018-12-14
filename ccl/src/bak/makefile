#################################################################
#
#   File: makefile
#
# Author: $author$
#   Date: 4/16/2004
#
#    $Id$
#
# Linux makefile
#
#################################################################

INCLUDEFILE=

ifneq "$(INCLUDEFILE)" ""
include $(INCLUDEFILE)
endif

MAKEFILE=makefile
DEPENDFILE=dependfile

###################################################################
# path settings

TEMPLATE=../../../xml
INCLUDE=../../../src
SRC=../../../src
LIB=../../../lib
OBJ=../../../obj
BIN=../../../bin

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
# target driver

DRIVER_C= \
	$(SRC)/driver.c

DRIVER_C_OBJS=$(DRIVER_C:.c=.o)

DRIVER_OBJS=$(DRIVER_C_OBJS) 

#################################################################
# target driverd

DRIVERD_CXX= \
	$(SRC)/cmain.cxx \
	$(SRC)/driverd.cxx

DRIVERD_CXX_OBJS=$(DRIVERD_CXX:.cxx=.o)

DRIVERD_OBJS=$(DRIVERD_CXX_OBJS) 

###################################################################
# all targets

KERNEL_C=$(DRIVER_C) 
C=
CXX=$(DRIVERD_CXX) 
CPP=

OBJS=$(DRIVER_OBJ) $(DRIVERD_OBJ) 
MODS=$(DRIVER_MOD) 
EXES=$(DRIVERD_EXE) 

###################################################################
# standard rules

all: $(MODS) $(EXES) $(OBJS)

make:
	dt -document_type=xml -document_file=developfile.xml \
	template_type=dt transform_type=dt \
	$(TEMPLATE)/developfile-to-linux-makefile.dt \
	makefile

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
	$(KERNEL_LD) $(KERNEL_LD_OPTIONS) -o $(@) $(KERNEL_LD_LIB_PATHS) $(DRIVER_LIBS) $(DRIVER_OBJS)

#################################################################
# driverd rules

$(DRIVERD_EXE): $(DRIVERD_OBJS) $(DRIVERD_LIBS)
	$(LD) $(LD_OPTIONS) -o $(@) $(LD_LIB_PATHS) $(DRIVERD_LIBS) $(DRIVERD_OBJS)

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
