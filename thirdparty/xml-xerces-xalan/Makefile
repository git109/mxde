########################################################################
# Copyright (c) 1988-2012 $organization$
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
#   File: Makefile
#
# Author: $author$
#   Date: 12/15/2012
#
# Thirdpary Makefile for xml-xerces-xalan
########################################################################

GCC=gcc
GXX=g++

XERCESXALANDIR=xml-xerces-xalan
XERCESXALANCDIR=$(XERCESXALANDIR)/linux/c

MAKEDIR=$(PWD)
BINDIR=$(HOME)/build/$(XERCESXALANCDIR)/bin
LIBDIR=$(HOME)/build/$(XERCESXALANCDIR)/lib

##
#
# Xerces
#
##

XERCESCDIR=xml-xerces
XERCESCSUBDIR=$(XERCESCDIR)/c
XERCESCROOT=$(PWD)/$(XERCESCDIR)/c
XERCESCSRC=$(XERCESCDIR)/c/src/xercesc

ifdef XERCESCSRCLIB
XERCESCLIB=$(XERCESCDIR)/c/src/xercesc/lib
else
XERCESCLIB=$(XERCESCDIR)/c/lib
endif

LIBXERCESC=libxerces-c
LIBXERCESDEPDOM=libxerces-depdom
XERCESCVERSION=2_6_0
XERCESCSOVERSION=26
XERCESTARGZDIR=xerces-c-src_$(XERCESCVERSION)
XERCESTARGZ=xerces-c-src_$(XERCESCVERSION).tar.gz

XERCESC_CONFIGURE=./runConfigure -plinux -c$(GCC) -x$(GXX) -minmem -nsocket -tnative -rpthread
#XERCESC_CONFIGURE=./runConfigure -pmingw-msys -c$(GCC) -x$(GXX) -minmem -nsocket -tnative -rnone

XERCESCLIB_INSTALL=$(LIBDIR)
XERCESCBIN_INSTALL=$(BINDIR)

##
#
# Xalan
#
##

XALANCDIR=xml-xalan
XALANCSUBDIR=$(XALANCDIR)/c
XALANCROOT=$(PWD)/$(XALANCSUBDIR)
XALANCSRC=$(XALANCSUBDIR)/src/xalanc

ifdef XALANCSRCLIB
XALANCLIB=$(XALANCSUBDIR)/src/xalanc/lib
else
XALANCLIB=$(XALANCSUBDIR)/lib
endif

LIBXALANC=libxalan-c
XALANCVERSION=1_6
XALANCSOVERSION=16
XALANTARGZ=Xalan-C_$(XALANCVERSION)-src.tar.gz
XALANPATCHTARGZ=Xalan-C_$(XALANCVERSION)-src-xde-linux-patch.tar.gz

XALANC_CONFIGURE=./runConfigure -plinux -c$(GCC) -x$(GXX) -tnative -rpthread

XALANCLIB_INSTALL=$(LIBDIR)
XALANCBIN_INSTALL=$(BINDIR)

##
#
# all
#
##

all: builded-xerces builded-xalan

install: install-xerces install-xalan

uninstall: uninstall-xalan uninstall-xerces

build: build-xerces build-xalan

clean: clean-xalan clean-xerces

config: config-xerces config-xalan

unextract: unextract-xalan unextract-xerces

extract: extract-xerces extract-xalan

##
#
# Xerces
#
##

xerces: builded-xerces

#
# Install Xerces
#
uninstall-xerces: 
	@(echo Removing Xerces from $(XERCESCLIB_INSTALL)...;\
	  pushd $(XERCESCLIB_INSTALL);\
	  ((rm -f $(LIBXERCESC).so) || (exit 1)) && \
	  ((rm -f $(LIBXERCESC).so.$(XERCESCSOVERSION)) || (exit 1)) && \
	  ((rm -f $(LIBXERCESC).so.$(XERCESCSOVERSION).0) || (exit 1)) && \
	  ((rm -f $(LIBXERCESDEPDOM).so) || (exit 1)) && \
	  ((rm -f $(LIBXERCESDEPDOM).so.$(XERCESCSOVERSION)) || (exit 1)) && \
	  ((rm -f $(LIBXERCESDEPDOM).so.$(XERCESCSOVERSION).0) || (exit 1)) && \
	  popd)

install-xerces: builded-xerces
	@(echo Installing Xerces to $(XERCESCLIB_INSTALL)...;\
	  pushd $(XERCESCLIB);\
	  ((mkdir -p $(XERCESCLIB_INSTALL)) || (exit 1)) && \
	  ((cp -a $(LIBXERCESC).so.$(XERCESCSOVERSION).0 $(XERCESCLIB_INSTALL)) || (exit 1)) && \
	  ((cp -a $(LIBXERCESDEPDOM).so.$(XERCESCSOVERSION).0 $(XERCESCLIB_INSTALL)) || (exit 1)) && \
	  cd $(XERCESCLIB_INSTALL) && \
	  ((ln -f -s $(LIBXERCESC).so.$(XERCESCSOVERSION).0 $(LIBXERCESC).so.$(XERCESCSOVERSION)) || (exit 1)) && \
	  ((ln -f -s $(LIBXERCESC).so.$(XERCESCSOVERSION) $(LIBXERCESC).so) || (exit 1)) && \
	  ((ln -f -s $(LIBXERCESDEPDOM).so.$(XERCESCSOVERSION).0 $(LIBXERCESDEPDOM).so.$(XERCESCSOVERSION)) || (exit 1)) && \
	  ((ln -f -s $(LIBXERCESDEPDOM).so.$(XERCESCSOVERSION) $(LIBXERCESDEPDOM).so) || (exit 1)) && \
	  popd)


#
# Build Xerces
#
build-xerces: unbuild-xerces builded-xerces

unbuild-xerces:
	@(rm -f builded-xerces)

builded-xerces: configed-xerces
	@(echo Building Xerces...;\
	  touch builded-xerces;\
	  pushd $(XERCESCSRC);\
	  ((make XERCESCROOT=$(XERCESCROOT)) || ((rm -f $(MAKEDIR)/builded-xerces) && (exit 1)));\
	  popd)


#
# Clean Xerces
#
clean-xerces: configed-xerces
	@(echo Cleaning Xerces...;\
	  pushd $(XERCESCSRC);\
	  ((make XERCESCROOT=$(XERCESCROOT) clean) || (exit 1));\
	  popd)


#
# Config Xerces
#
config-xerces: $(XERCESCDIR)
	@(echo Configing Xerces...;\
	  touch configed-xerces;\
	  export XERCESCROOT=$(XERCESCROOT);\
	  pushd $(XERCESCSRC);\
	  (($(XERCESC_CONFIGURE)) || ((rm -f $(MAKEDIR)/configed-xerces) && (exit 1)));\
	  popd)

unconfig-xerces:
	@(echo Unconfiging Xerces...;\
	  rm -f configed-xerces)

configed-xerces: $(XERCESCDIR)
	@(echo Configing Xerces...;\
	  touch configed-xerces;\
	  export XERCESCROOT=$(XERCESCROOT);\
	  pushd $(XERCESCSRC);\
	  (($(XERCESC_CONFIGURE)) || ((rm -f $(MAKEDIR)/configed-xerces) && (exit 1)));\
	  popd)

help-xerces: $(XERCESCDIR)
	@(echo Help on Xerces...;\
	  pushd $(XERCESCSRC);\
	  (($(XERCESC_CONFIGURE) -h) || (exit 1));\
	  popd)


#
# Extract Xerces
#
extract-xerces:
	@(echo Extracting $(XERCESTARGZ)...;\
	  rm -f -r $(XERCESCDIR);\
	  mkdir -p $(XERCESCDIR);\
	  ((tar -xzf $(XERCESTARGZ)) || (exit 1));\
	  ((mv $(XERCESTARGZDIR) $(XERCESCSUBDIR)) || (exit 1));\
	  touch $(XERCESCDIR))

unextract-xerces:
	@(echo Removing $(XERCESCDIR)...;\
	  rm -f -r $(XERCESCDIR))

$(XERCESCDIR): $(XERCESTARGZ)
	@(echo Extracting $(XERCESTARGZ)...;\
	  rm -f -r $(XERCESCDIR);\
	  ((tar -xzf $(XERCESTARGZ)) || (exit 1));\
	  touch $(XERCESCDIR))

##
#
# Xalan
#
##

xalan: builded-xalan

#
# Install Xalan
#
uninstall-xalan: 
	@(echo Removing Xalan from $(XALANCLIB_INSTALL)...;\
	  pushd $(XALANCLIB_INSTALL);\
	  ((rm -f $(LIBXALANC).so) || (exit 1)) && \
	  ((rm -f $(LIBXALANC).so.$(XALANCSOVERSION)) || (exit 1)) && \
	  ((rm -f $(LIBXALANC).so.$(XALANCSOVERSION).0) || (exit 1)) && \
	  popd)

install-xalan: builded-xalan
	@(echo Installing Xalan to $(XALANCLIB_INSTALL)...;\
	  pushd $(XALANCLIB);\
	  ((mkdir -p $(XALANCLIB_INSTALL)) || (exit 1)) && \
	  ((cp -a $(LIBXALANC).so.$(XALANCSOVERSION).0 $(XALANCLIB_INSTALL)) || (exit 1)) && \
	  cd $(XALANCLIB_INSTALL) && \
	  ((ln -f -s $(LIBXALANC).so.$(XALANCSOVERSION).0 $(LIBXALANC).so.$(XALANCSOVERSION)) || (exit 1)) && \
	  ((ln -f -s $(LIBXALANC).so.$(XALANCSOVERSION) $(LIBXALANC).so) || (exit 1)) && \
	  popd)


#
# Build Xalan
#
build-xalan: unbuild-xalan builded-xalan

unbuild-xalan:
	@(rm -f builded-xalan)

builded-xalan: configed-xalan
	@(echo Building Xalan...;\
	  touch builded-xalan;\
	  pushd $(XALANCSRC);\
	  ((make XERCESCROOT=$(XERCESCROOT) XALANCROOT=$(XALANCROOT)) || ((rm -f $(MAKEDIR)/builded-xalan) && (exit 1)));\
	  popd)


#
# Clean Xalan
#
clean-xalan: configed-xalan
	@(echo Cleaning Xalan...;\
	  pushd $(XALANCSRC);\
	  ((make XERCESCROOT=$(XERCESCROOT) XALANCROOT=$(XALANCROOT) clean) || (exit 1));\
	  popd)


#
# Config Xalan
#
config-xalan: $(XALANCDIR)
	@(echo Configing Xalan...;\
	  touch configed-xalan;\
	  export XERCESCROOT=$(XERCESCROOT);\
	  export XALANCROOT=$(XALANCROOT);\
	  pushd $(XALANCSRC);\
	  (($(XALANC_CONFIGURE)) || ((rm -f $(MAKEDIR)/configed-xalan) && (exit 1)));\
	  popd)

unconfig-xalan:
	@(echo Unconfiging Xalan...;\
	  rm -f configed-xalan)

configed-xalan: $(XALANCDIR)
	@(echo Configing Xalan...;\
	  touch configed-xalan;\
	  export XERCESCROOT=$(XERCESCROOT);\
	  export XALANCROOT=$(XALANCROOT);\
	  pushd $(XALANCSRC);\
	  (($(XALANC_CONFIGURE)) || ((rm -f $(MAKEDIR)/configed-xalan) && (exit 1)));\
	  popd)

help-xalan: $(XALANCDIR)
	@(echo Help on Xalan...;\
	  pushd $(XALANCSRC);\
	  (($(XALANC_CONFIGURE) -h) || (exit 1));\
	  popd)


#
# Extract Xalan
#
extract-xalan:
	@(echo Extracting $(XALANTARGZ)...;\
	  rm -f -r $(XALANCDIR);\
	  ((tar -xzf $(XALANTARGZ)) || (exit 1));\
	  echo Extracting $(XALANPATCHTARGZ)...;\
	  ((tar -xzf $(XALANPATCHTARGZ)) || (exit 1));\
	  touch $(XALANCDIR))

unextract-xalan:
	@(echo Removing $(XALANCDIR)...;\
	  rm -f -r $(XALANCDIR))

$(XALANCDIR): $(XALANTARGZ)
	@(echo Extracting $(XALANTARGZ)...;\
	  rm -f -r $(XALANCDIR);\
	  ((tar -xzf $(XALANTARGZ)) || (exit 1));\
	  echo Extracting $(XALANPATCHTARGZ)...;\
	  ((tar -xzf $(XALANPATCHTARGZ)) || (exit 1));\
	  touch $(XALANCDIR))

