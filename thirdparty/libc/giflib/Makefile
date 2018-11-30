########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   Date: 7/22/2018
#
# Thirdpary Makefile for giflib
########################################################################

########################################################################
#
# giflib defs
#
########################################################################
GIFLIB_MAKEDIR=$(PWD)

GIFLIB_THIRDPARTY = $(GIFLIB_MAKEDIR)/..
#GIFLIB_BUILD_HOME = $(GIFLIB_THIRDPARTY)

ifndef GIFLIB_UNAME
GIFLIB_UNAME = $(shell uname)
endif

ifndef GIFLIB_OS
ifneq ($(GIFLIB_UNAME), Darwin)
GIFLIB_OS = linux
else
GIFLIB_OS = macosx
endif
endif

#
# giflib version
#
GIFLIB_VERSION_MAJOR = 4
GIFLIB_VERSION_MINOR = 1
GIFLIB_VERSION_RELEASE = 6

GIFLIB_VERSION_SEPARATOR = .
GIFLIB_VERSION_MAJOR_SEPARATOR = $(GIFLIB_VERSION_SEPARATOR)
GIFLIB_VERSION_MINOR_SEPARATOR = $(GIFLIB_VERSION_SEPARATOR)

GIFLIB_VERSION_SHORT = $(GIFLIB_VERSION_MAJOR)$(GIFLIB_VERSION_MINOR)$(GIFLIB_VERSION_RELEASE)
GIFLIB_VERSION = $(GIFLIB_VERSION_MAJOR)$(GIFLIB_VERSION_MAJOR_SEPARATOR)$(GIFLIB_VERSION_MINOR)$(GIFLIB_VERSION_MINOR_SEPARATOR)$(GIFLIB_VERSION_RELEASE)

#
# giflib name
#
GIFLIB_NAME_SEPARATOR = -
GIFLIB_NAME_BASE = giflib
GIFLIB_NAME = $(GIFLIB_NAME_BASE)$(GIFLIB_NAME_SEPARATOR)$(GIFLIB_VERSION)
GIFLIB_INSTALL_NAME_SEPARATOR = -
GIFLIB_INSTALL_NAME = $(GIFLIB_NAME_BASE)$(GIFLIB_INSTALL_NAME_SEPARATOR)$(GIFLIB_VERSION)
GIFLIB_DIR = $(GIFLIB_NAME)

#
# giflib archive
#
GIFLIB_ARCHIVED = tar
GIFLIB_COMPRESSED = gz
GIFLIB_ARCHIVE_SEPARATOR = .
GIFLIB_ARCHIVED_SEPARATOR = $(GIFLIB_ARCHIVE_SEPARATOR)
GIFLIB_COMPRESSED_SEPARATOR = $(GIFLIB_ARCHIVE_SEPARATOR)

GIFLIB_EXTRACT_DIR = $(GIFLIB_NAME)
GIFLIB_TGZ_PREFIX = 
GIFLIB_TGZ = $(GIFLIB_NAME)$(GIFLIB_TGZ_PREFIX)$(GIFLIB_ARCHIVED_SEPARATOR)$(GIFLIB_ARCHIVED)$(GIFLIB_COMPRESSED_SEPARATOR)$(GIFLIB_COMPRESSED)
GIFLIB_PATCH_TGZ_PREFIX = $(GIFLIB_NAME_SEPARATOR)patch
GIFLIB_PATCH_TGZ = $(GIFLIB_NAME)$(GIFLIB_PATCH_TGZ_PREFIX)$(GIFLIB_ARCHIVED_SEPARATOR)$(GIFLIB_ARCHIVED)$(GIFLIB_COMPRESSED_SEPARATOR)$(GIFLIB_COMPRESSED)
GIFLIB_DOCS_TGZ_PREFIX = $(GIFLIB_NAME_SEPARATOR)docs
GIFLIB_DOCS_TGZ = $(GIFLIB_NAME)$(GIFLIB_DOCS_TGZ_PREFIX)$(GIFLIB_ARCHIVED_SEPARATOR)$(GIFLIB_ARCHIVED)$(GIFLIB_COMPRESSED_SEPARATOR)$(GIFLIB_COMPRESSED)

#
# giflib extract
#
ifeq ($(GIFLIB_ARCHIVED),tar)
ifeq ($(GIFLIB_COMPRESSED),gz)
GIFLIB_TAR_UNCOMPRESS = z
GIFLIB_TAR_COMPRESS = z
else
ifeq ($(GIFLIB_COMPRESSED),bz2)
GIFLIB_TAR_UNCOMPRESS = j
GIFLIB_TAR_COMPRESS = j
else
ifeq ($(GIFLIB_COMPRESSED),xz)
GIFLIB_TAR_UNCOMPRESS = J
GIFLIB_TAR_COMPRESS = J
else
endif
endif
endif
GIFLIB_LIST = tar -tv$(GIFLIB_TAR_UNCOMPRESS)f
GIFLIB_EXTRACT = tar -x$(GIFLIB_TAR_UNCOMPRESS)f
GIFLIB_ARCHIVE = tar -cv$(GIFLIB_TAR_COMPRESS)f
else
ifeq ($(GIFLIB_ARCHIVED),zip)
GIFLIB_LIST = unzip -l
GIFLIB_EXTRACT = unzip
GIFLIB_ARCHIVE = zip
else
GIFLIB_LIST = echo unable to list
GIFLIB_EXTRACT = echo unable to extract
GIFLIB_ARCHIVE = echo unable to archive
endif
endif

GIFLIB_LIST_TGZ = $(GIFLIB_LIST) $(GIFLIB_TGZ)
GIFLIB_EXTRACT_TGZ = $(GIFLIB_EXTRACT) $(GIFLIB_TGZ)
GIFLIB_TOUCH_EXTRACT = touch $(GIFLIB_DIR)
GIFLIB_REMOVE_DIR = $(GIFLIB_REMOVE) $(GIFLIB_DIR)

GIFLIB_LIST_PATCH = $(GIFLIB_LIST)
GIFLIB_EXTRACT_PATCH = $(GIFLIB_EXTRACT)
GIFLIB_LIST_PATCH_TGZ = $(GIFLIB_LIST_PATCH) $(GIFLIB_PATCH_TGZ)
GIFLIB_EXTRACT_PATCH_TGZ = $(GIFLIB_EXTRACT_PATCH) $(GIFLIB_PATCH_TGZ)

GIFLIB_LIST_DOCS = $(GIFLIB_LIST)
GIFLIB_EXTRACT_DOCS = $(GIFLIB_EXTRACT)
GIFLIB_LIST_DOCS_TGZ = $(GIFLIB_LIST_DOCS) $(GIFLIB_DOCS_TGZ)
GIFLIB_EXTRACT_DOCS_TGZ = $(GIFLIB_EXTRACT_DOCS) $(GIFLIB_DOCS_TGZ) -C$(GIFLIB_DOCS_PREFIX)

#
# giflib build
#
ifndef GIFLIB_BUILD_HOME
GIFLIB_BUILD = $(HOME)/build
else
GIFLIB_BUILD = $(GIFLIB_BUILD_HOME)/build
endif
GIFLIB_PREFIX = $(GIFLIB_BUILD)/$(GIFLIB_INSTALL_NAME)
GIFLIB_EXEC_PREFIX = $(GIFLIB_PREFIX)
GIFLIB_CONF_PREFIX = $(GIFLIB_PREFIX)
GIFLIB_DOCS_PREFIX = $(GIFLIB_PREFIX)
GIFLIB_LINK_NAME = $(GIFLIB_BUILD)/$(GIFLIB_NAME_BASE)

GIFLIB_MKDIR = mkdir -p
GIFLIB_REMOVE = rm -r -f

GIFLIB_MAKE_DIR = $(GIFLIB_DIR)
GIFLIB_MAKE_PUSHD = pushd $(GIFLIB_MAKE_DIR)
GIFLIB_MAKE = make

#
# giflib configure
#
ifneq ($(GIFLIB_UNAME), Darwin)
GIFLIB_CONFIGURE_UNAME = --enable-shared=no
else
GIFLIB_CONFIGURE_UNAME = --enable-shared=no
endif
GIFLIB_CONFIGURE_CONFIGURE = ./configure
GIFLIB_CONFIGURE_HELP = $(GIFLIB_CONFIGURE_CONFIGURE) --help
GIFLIB_CONFIGURE_PUSHD = pushd $(GIFLIB_MAKE_DIR)
GIFLIB_CONFIGURE = $(GIFLIB_CONFIGURE_CONFIGURE) \
$(GIFLIB_CONFIGURE_UNAME) --prefix=$(GIFLIB_PREFIX) --exec_prefix=$(GIFLIB_EXEC_PREFIX)

#
# giflib help
#
GIFLIB_HELP = $(GIFLIB_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

package: archive unextract

again: unextract build

test: test-giflib

install-links: install-giflib-links

install-docs: install-giflib-docs

install-prefix: install-giflib-prefix

install: install-giflib

build: build-giflib

clean: clean-giflib

configed: configed-$(GIFLIB_DIR)

config: config-$(GIFLIB_DIR)

help: help-giflib

list-docs: list-giflib-docs

list-patch: list-giflib-patch

extract-patch: extract-giflib-patch

list: list-giflib

extract: extract-giflib

unextract: unextract-giflib

archive: archive-giflib

linked: giflib-linked

prefixed: giflib-prefixed

archived: giflib-archived

extracted: giflib-extracted

########################################################################
#
# giflib rules
#
########################################################################

#
# Help giflib
#
help-giflib: $(GIFLIB_DIR)
	@($(GIFLIB_CONFIGURE_PUSHD);\
	  (($(GIFLIB_HELP)) || (exit 1));\
	  popd)

#
# Install giflib
#
install-giflib: configed-$(GIFLIB_DIR)
	@(echo Installing $(GIFLIB_DIR)...;\
	  $(GIFLIB_MAKE_PUSHD);\
	  (($(GIFLIB_MAKE) install) || (exit 1)) && \
	  ((touch $(GIFLIB_MAKEDIR)/configed-$(GIFLIB_DIR)) || (exit 1));\
	  popd)
	  
#
# Build giflib
#
build-giflib: configed-$(GIFLIB_DIR)
	@(echo Building $(GIFLIB_DIR)...;\
	  $(GIFLIB_MAKE_PUSHD);\
	  (($(GIFLIB_MAKE)) || (exit 1)) && \
	  ((touch $(GIFLIB_MAKEDIR)/configed-$(GIFLIB_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean giflib
#
clean-giflib: configed-$(GIFLIB_DIR)
	@(echo Cleaning $(GIFLIB_DIR)...;\
	  $(GIFLIB_MAKE_PUSHD);\
	  (($(GIFLIB_MAKE) clean) || (exit 1)) && \
	  ((touch $(GIFLIB_MAKEDIR)/configed-$(GIFLIB_DIR)) || (exit 1));\
	  popd)
	  
#
# Test giflib
#
test-giflib: configed-$(GIFLIB_DIR)
	@(echo Building test $(GIFLIB_DIR)...;\
	  $(GIFLIB_MAKE_PUSHD);\
	  (($(GIFLIB_MAKE) test) || (exit 1)) && \
	  ((touch $(GIFLIB_MAKEDIR)/configed-$(GIFLIB_DIR)) || (exit 1));\
	  popd)
	  
#
# Config giflib
#
config-$(GIFLIB_DIR): unconfig-$(GIFLIB_DIR) configed-$(GIFLIB_DIR)

unconfig-$(GIFLIB_DIR):
	@(rm -f configed-$(GIFLIB_DIR))

configed-$(GIFLIB_DIR): $(GIFLIB_DIR)
	@(echo Configing $(GIFLIB_DIR)...;\
	  $(GIFLIB_CONFIGURE_PUSHD);\
	  (($(GIFLIB_CONFIGURE)) || (exit 1)) && \
	  ((touch $(GIFLIB_DIR)) || (exit 1)) && \
	  ((touch $(GIFLIB_MAKEDIR)/configed-$(GIFLIB_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List giflib Docs
#
list-giflib-docs: $(GIFLIB_DOCS_TGZ)
	@(echo Listing $(GIFLIB_DOCS_TGZ)...;\
	  (($(GIFLIB_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install giflib Docs
#
install-giflib-docs: $(GIFLIB_DOCS_PREFIX)
	@(echo Extracting $(GIFLIB_DOCS_TGZ)...;\
	  (($(GIFLIB_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List giflib Patch
#
list-giflib-patch: $(GIFLIB_PATCH_TGZ)
	@(echo Listing $(GIFLIB_PATCH_TGZ)...;\
	  (($(GIFLIB_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract giflib patch
#
extract-giflib-patch: $(GIFLIB_DIR)
	@(echo Extracting $(GIFLIB_PATCH_TGZ)...;\
	  (($(GIFLIB_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List giflib
#
list-giflib: 
	@(echo Listing $(GIFLIB_TGZ)...;\
	  (($(GIFLIB_LIST_TGZ)) || (exit 1)))

#
# giflib extracted
#
giflib-extracted: 
	@(echo $(GIFLIB_EXTRACT) $(GIFLIB_TGZ))

#
# Extract giflib
#
extract-giflib: unextract-giflib $(GIFLIB_DIR)

unextract-giflib: unconfig-$(GIFLIB_DIR)
	@(echo Removing $(GIFLIB_DIR)...;\
	  (($(GIFLIB_REMOVE_DIR)) || (exit 1)))

$(GIFLIB_DIR): $(GIFLIB_TGZ)
	@(echo Extracting $(GIFLIB_TGZ)...;\
	  (($(GIFLIB_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(GIFLIB_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# giflib archived
#
giflib-archived: 
	@(echo $(GIFLIB_TGZ))
	  
#
# Archive giflib
#
archive-giflib: 
	@(echo Archiving $(GIFLIB_DIR) to $(GIFLIB_TGZ)...;\
	  (($(GIFLIB_ARCHIVE) $(GIFLIB_TGZ) $(GIFLIB_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# giflib linked
#
giflib-linked: 
	@echo link is $(GIFLIB_LINK_NAME) "->" $(GIFLIB_PREFIX)
	  
#
# Install giflib links
#
install-giflib-links: 
	@((echo removing $(GIFLIB_LINK_NAME)) && \
	  ((rm -f $(GIFLIB_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(GIFLIB_LINK_NAME) "->" $(GIFLIB_PREFIX)) && \
	  ((ln -s $(GIFLIB_PREFIX) $(GIFLIB_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# giflib prefixed
#
giflib-prefixed: 
	@((echo prefix is $(GIFLIB_PREFIX)) && \
	  (echo exec prefix is $(GIFLIB_EXEC_PREFIX)) && \
	  (echo conf prefix is $(GIFLIB_CONF_PREFIX)) && \
	  (echo docs prefix is $(GIFLIB_DOCS_PREFIX)))
	  
#
# Install giflib prefix
#
install-giflib-prefix: 
	@((echo makeing $(GIFLIB_PREFIX)) && \
	  ((mkdir -p $(GIFLIB_PREFIX)) || (exit 1)) && \
	  (echo makeing $(GIFLIB_EXEC_PREFIX)) && \
	  ((mkdir -p $(GIFLIB_EXEC_PREFIX)) || (exit 1)))
	  
$(GIFLIB_PREFIX):
	@(echo Makeing Directory $(GIFLIB_PREFIX)...;\
	  (($(GIFLIB_MKDIR) $(GIFLIB_PREFIX)) || (exit 1)))

$(GIFLIB_EXEC_PREFIX):
	@(echo Makeing Directory $(GIFLIB_EXEC_PREFIX)...;\
	  (($(GIFLIB_MKDIR) $(GIFLIB_EXEC_PREFIX)) || (exit 1)))

$(GIFLIB_CONF_PREFIX):
	@(echo Makeing Directory $(GIFLIB_CONF_PREFIX)...;\
	  (($(GIFLIB_MKDIR) $(GIFLIB_CONF_PREFIX)) || (exit 1)))

$(GIFLIB_DOCS_PREFIX):
	@(echo Makeing Directory $(GIFLIB_DOCS_PREFIX)...;\
	  (($(GIFLIB_MKDIR) $(GIFLIB_DOCS_PREFIX)) || (exit 1)))




        

