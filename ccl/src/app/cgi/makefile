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
#   Date: 11/25/2005
#
#    $Id$
#
# Makefile for "cgi".
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
INCLUDE=../..
SRC1=../..
SRC=../../ccgi
LIB=.
OBJ=.
BIN=.

###################################################################
# compiler settings

GCC=/usr/local/gcc331/bin/gcc
GXX=/usr/local/gcc331/bin/g++

KERNEL_CC=$(GCC) -c
CC=$(GCC) -c
CCXX=$(GXX) -c

KERNEL_CC_OPTIONS= -D_DBPRINTK -D__KERNEL__ -DLINUX -DMODULE -Wall -O2 -pipe
CC_OPTIONS= -O3
CCXX_OPTIONS= -O3

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
# target

CGI_CXX= \
	$(SRC1)/cargswitch.cxx \
	$(SRC)/ccgi.cxx \
	$(SRC)/ccgimain.cxx \
	$(SRC)/chttpcontent.cxx \
	$(SRC)/chttpform.cxx \
	$(SRC)/cgi.cxx

CGI_CXX_OBJS=$(CGI_CXX:.cxx=.o)

CGI_OBJS=$(CGI_CXX_OBJS) 

CGI_EXE=cgi

###################################################################
# all targets

C=
CXX=$(CGI_CXX)
CPP=

OBJS=$(CGI_OBJS)
EXES=$(CGI_EXE)

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

$(CGI_EXE): $(CGI_OBJS) $(CGI_LIBS)
	$(LDCXX) $(LDCXX_OPTIONS) -o $(@) $(LDCXX_LIB_PATHS) $(CGI_LIBS) $(CGI_OBJS)

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

