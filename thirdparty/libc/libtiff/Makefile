########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   Date: 3/28/2016
#
# Thirdpary Makefile for libtiff
########################################################################

MAKEDIR=$(PWD)

########################################################################
#
# libtiff defs
#
########################################################################
LIBTIFF_VERSION_MAJOR = 3
LIBTIFF_VERSION_MINOR = 8
LIBTIFF_VERSION_RELEASE = 2

LIBTIFF_VERSION_SEPARATOR = .
LIBTIFF_VERSION_MAJOR_SEPARATOR = $(LIBTIFF_VERSION_SEPARATOR)
LIBTIFF_VERSION_MINOR_SEPARATOR = $(LIBTIFF_VERSION_SEPARATOR)

LIBTIFF_VERSION_SHORT = $(LIBTIFF_VERSION_MAJOR)$(LIBTIFF_VERSION_MINOR)$(LIBTIFF_VERSION_RELEASE)
LIBTIFF_VERSION = $(LIBTIFF_VERSION_MAJOR)$(LIBTIFF_VERSION_MAJOR_SEPARATOR)$(LIBTIFF_VERSION_MINOR)$(LIBTIFF_VERSION_MINOR_SEPARATOR)$(LIBTIFF_VERSION_RELEASE)

LIBTIFF_NAME_SEPARATOR = -
LIBTIFF_NAME_BASE = tiff
LIBTIFF_NAME = $(LIBTIFF_NAME_BASE)$(LIBTIFF_NAME_SEPARATOR)$(LIBTIFF_VERSION)
LIBTIFF_INSTALL_NAME_SEPARATOR = -
LIBTIFF_INSTALL_NAME = $(LIBTIFF_NAME_BASE)$(LIBTIFF_INSTALL_NAME_SEPARATOR)$(LIBTIFF_VERSION)

LIBTIFF_ARCHIVED = tar
LIBTIFF_COMPRESSED = gz
LIBTIFF_ARCHIVE_SEPARATOR = .
LIBTIFF_ARCHIVED_SEPARATOR = $(LIBTIFF_ARCHIVE_SEPARATOR)
LIBTIFF_COMPRESSED_SEPARATOR = $(LIBTIFF_ARCHIVE_SEPARATOR)

LIBTIFF_BUILD = $(HOME)/build
LIBTIFF_PREFIX = $(LIBTIFF_BUILD)/$(LIBTIFF_INSTALL_NAME)
LIBTIFF_EXEC_PREFIX = $(LIBTIFF_PREFIX)
LIBTIFF_CONF_PREFIX = $(LIBTIFF_PREFIX)
LIBTIFF_DOCS_PREFIX = $(LIBTIFF_PREFIX)
LIBTIFF_LINK_NAME = $(LIBTIFF_BUILD)/$(LIBTIFF_NAME_BASE)
LIBTIFF_DIR = $(LIBTIFF_NAME)
LIBTIFF_EXTRACT_DIR = $(LIBTIFF_NAME)
LIBTIFF_TGZ_PREFIX = 
LIBTIFF_TGZ = $(LIBTIFF_NAME)$(LIBTIFF_TGZ_PREFIX)$(LIBTIFF_ARCHIVED_SEPARATOR)$(LIBTIFF_ARCHIVED)$(LIBTIFF_COMPRESSED_SEPARATOR)$(LIBTIFF_COMPRESSED)
LIBTIFF_PATCH_TGZ_PREFIX = $(LIBTIFF_NAME_SEPARATOR)patch
LIBTIFF_PATCH_TGZ = $(LIBTIFF_NAME)$(LIBTIFF_PATCH_TGZ_PREFIX)$(LIBTIFF_ARCHIVED_SEPARATOR)$(LIBTIFF_ARCHIVED)$(LIBTIFF_COMPRESSED_SEPARATOR)$(LIBTIFF_COMPRESSED)
LIBTIFF_DOCS_TGZ_PREFIX = $(LIBTIFF_NAME_SEPARATOR)docs
LIBTIFF_DOCS_TGZ = $(LIBTIFF_NAME)$(LIBTIFF_DOCS_TGZ_PREFIX)$(LIBTIFF_ARCHIVED_SEPARATOR)$(LIBTIFF_ARCHIVED)$(LIBTIFF_COMPRESSED_SEPARATOR)$(LIBTIFF_COMPRESSED)

ifeq ($(LIBTIFF_ARCHIVED),tar)
ifeq ($(LIBTIFF_COMPRESSED),gz)
LIBTIFF_TAR_UNCOMPRESS = z
LIBTIFF_TAR_COMPRESS = z
else
ifeq ($(LIBTIFF_COMPRESSED),bz2)
LIBTIFF_TAR_UNCOMPRESS = j
LIBTIFF_TAR_COMPRESS = j
else
endif
endif
LIBTIFF_LIST = tar -tv$(LIBTIFF_TAR_UNCOMPRESS)f
LIBTIFF_EXTRACT = tar -x$(LIBTIFF_TAR_UNCOMPRESS)f
LIBTIFF_ARCHIVE = tar -cv$(LIBTIFF_TAR_COMPRESS)f
else
ifeq ($(LIBTIFF_ARCHIVED),zip)
LIBTIFF_LIST = unzip -l
LIBTIFF_EXTRACT = unzip
LIBTIFF_ARCHIVE = zip
else
LIBTIFF_LIST = echo unable to list
LIBTIFF_EXTRACT = echo unable to extract
LIBTIFF_ARCHIVE = echo unable to archive
endif
endif

LIBTIFF_MKDIR = mkdir -p
LIBTIFF_REMOVE = rm -r -f

LIBTIFF_MAKE_DIR = $(LIBTIFF_DIR)
LIBTIFF_MAKE_PUSHD = pushd $(LIBTIFF_MAKE_DIR)
LIBTIFF_MAKE = make

LIBTIFF_CONFIGURE_PUSHD = pushd $(LIBTIFF_MAKE_DIR)
LIBTIFF_CONFIGURE = ./configure --prefix=$(LIBTIFF_PREFIX) --exec_prefix=$(LIBTIFF_EXEC_PREFIX)
LIBTIFF_HELP = ./configure --help

LIBTIFF_LIST_TGZ = $(LIBTIFF_LIST) $(LIBTIFF_TGZ)
LIBTIFF_EXTRACT_TGZ = $(LIBTIFF_EXTRACT) $(LIBTIFF_TGZ)
LIBTIFF_TOUCH_EXTRACT = touch $(LIBTIFF_DIR)
LIBTIFF_REMOVE_DIR = $(LIBTIFF_REMOVE) $(LIBTIFF_DIR)

LIBTIFF_LIST_PATCH = $(LIBTIFF_LIST)
LIBTIFF_EXTRACT_PATCH = $(LIBTIFF_EXTRACT)
LIBTIFF_LIST_PATCH_TGZ = $(LIBTIFF_LIST_PATCH) $(LIBTIFF_PATCH_TGZ)
LIBTIFF_EXTRACT_PATCH_TGZ = $(LIBTIFF_EXTRACT_PATCH) $(LIBTIFF_PATCH_TGZ)

LIBTIFF_LIST_DOCS = $(LIBTIFF_LIST)
LIBTIFF_EXTRACT_DOCS = $(LIBTIFF_EXTRACT)
LIBTIFF_LIST_DOCS_TGZ = $(LIBTIFF_LIST_DOCS) $(LIBTIFF_DOCS_TGZ)
LIBTIFF_EXTRACT_DOCS_TGZ = $(LIBTIFF_EXTRACT_DOCS) $(LIBTIFF_DOCS_TGZ) -C$(LIBTIFF_DOCS_PREFIX)

########################################################################
#
# rules
#
########################################################################

all:

test: test-libtiff

install-links: install-libtiff-links

install-docs: install-libtiff-docs

install-prefix: install-libtiff-prefix

install: install-libtiff

build: build-libtiff

clean: clean-libtiff

configed: configed-$(LIBTIFF_DIR)

config: config-$(LIBTIFF_DIR)

help: help-libtiff

list-docs: list-libtiff-docs

list-patch: list-libtiff-patch

extract-patch: extract-libtiff-patch

list: list-libtiff

extract: extract-libtiff

unextract: unextract-libtiff

archive: archive-libtiff

linked: libtiff-linked

prefixed: libtiff-prefixed

archived: libtiff-archived

extracted: libtiff-extracted

########################################################################
#
# libtiff rules
#
########################################################################

#
# Test libtiff
#
test-libtiff:
	@($(LIBTIFF_MAKE_PUSHD);\
	  (($(LIBTIFF_MAKE) test) || (exit 1));\
	  popd)

#
# Install libtiff
#
install-libtiff: configed-$(LIBTIFF_DIR)
	@(echo Installing $(LIBTIFF_DIR)...;\
	  $(LIBTIFF_MAKE_PUSHD);\
	  (($(LIBTIFF_MAKE) install) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBTIFF_DIR)) || (exit 1));\
	  popd)
	  
#
# Build libtiff
#
build-libtiff: configed-$(LIBTIFF_DIR)
	@(echo Building $(LIBTIFF_DIR)...;\
	  $(LIBTIFF_MAKE_PUSHD);\
	  (($(LIBTIFF_MAKE)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBTIFF_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean libtiff
#
clean-libtiff: configed-$(LIBTIFF_DIR)
	@(echo Cleaning $(LIBTIFF_DIR)...;\
	  $(LIBTIFF_MAKE_PUSHD);\
	  (($(LIBTIFF_MAKE) clean) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBTIFF_DIR)) || (exit 1));\
	  popd)
	  
#
# Config libtiff
#
config-$(LIBTIFF_DIR): unconfig-$(LIBTIFF_DIR) configed-$(LIBTIFF_DIR)

unconfig-$(LIBTIFF_DIR):
	@(rm -f configed-$(LIBTIFF_DIR))

configed-$(LIBTIFF_DIR): $(LIBTIFF_DIR)
	@(echo Configing $(LIBTIFF_DIR)...;\
	  $(LIBTIFF_CONFIGURE_PUSHD);\
	  (($(LIBTIFF_CONFIGURE)) || (exit 1)) && \
	  ((touch $(LIBTIFF_DIR)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBTIFF_DIR)) || (exit 1));\
	  popd)

#
# Help libtiff
#
help-libtiff:
	@($(LIBTIFF_CONFIGURE_PUSHD);\
	  (($(LIBTIFF_HELP)) || (exit 1));\
	  popd)

#
# List libtiff Docs
#
list-libtiff-docs: $(LIBTIFF_DOCS_TGZ)
	@(echo Listing $(LIBTIFF_DOCS_TGZ)...;\
	  (($(LIBTIFF_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install libtiff Docs
#
install-libtiff-docs: $(LIBTIFF_DOCS_PREFIX)
	@(echo Extracting $(LIBTIFF_DOCS_TGZ)...;\
	  (($(LIBTIFF_EXTRACT_DOCS_TGZ)) || (exit 1)))

#
# List libtiff Patch
#
list-libtiff-patch: $(LIBTIFF_PATCH_TGZ)
	@(echo Listing $(LIBTIFF_PATCH_TGZ)...;\
	  (($(LIBTIFF_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract libtiff patch
#
extract-libtiff-patch: $(LIBTIFF_DIR)
	@(echo Extracting $(LIBTIFF_PATCH_TGZ)...;\
	  (($(LIBTIFF_EXTRACT_PATCH_TGZ)) || (exit 1)))

#
# List libtiff
#
list-libtiff: 
	@(echo Listing $(LIBTIFF_TGZ)...;\
	  (($(LIBTIFF_LIST_TGZ)) || (exit 1)))

#
# Extract libtiff
#
extract-libtiff: unextract-libtiff $(LIBTIFF_DIR)

unextract-libtiff: 
	@(echo Removing $(LIBTIFF_DIR)...;\
	  (($(LIBTIFF_REMOVE_DIR)) || (exit 1)))

$(LIBTIFF_DIR): $(LIBTIFF_TGZ)
	@(echo Extracting $(LIBTIFF_TGZ)...;\
	  (($(LIBTIFF_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(LIBTIFF_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# Archive libtiff
#
archive-libtiff: 
	@(echo Archiving $(LIBTIFF_DIR) to $(LIBTIFF_TGZ)...;\
	  (($(LIBTIFF_ARCHIVE) $(LIBTIFF_TGZ) $(LIBTIFF_DIR)) || (exit 1)))

#
# Install libtiff links
#
install-libtiff-links: 
	@((echo removing $(LIBTIFF_LINK_NAME)) && \
	  ((rm -f $(LIBTIFF_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(LIBTIFF_LINK_NAME) "->" $(LIBTIFF_PREFIX)) && \
	  ((ln -s $(LIBTIFF_PREFIX) $(LIBTIFF_LINK_NAME)) || (exit 1)))
	  
#
# libtiff linked
#
libtiff-linked: 
	@echo link is $(LIBTIFF_LINK_NAME) "->" $(LIBTIFF_PREFIX)
	  
#
# Install libtiff prefix
#
install-libtiff-prefix: 
	@((echo makeing $(LIBTIFF_PREFIX)) && \
	  ((mkdir -p $(LIBTIFF_PREFIX)) || (exit 1)) && \
	  (echo makeing $(LIBTIFF_EXEC_PREFIX)) && \
	  ((mkdir -p $(LIBTIFF_EXEC_PREFIX)) || (exit 1)))
	  
#
# libtiff prefixed
#
libtiff-prefixed: 
	@((echo prefix is $(LIBTIFF_PREFIX)) && \
	  (echo exec prefix is $(LIBTIFF_EXEC_PREFIX)) && \
	  (echo conf prefix is $(LIBTIFF_CONF_PREFIX)) && \
	  (echo docs prefix is $(LIBTIFF_DOCS_PREFIX)))
	  
$(LIBTIFF_PREFIX):
	@(echo Makeing Directory $(LIBTIFF_PREFIX)...;\
	  (($(LIBTIFF_MKDIR) $(LIBTIFF_PREFIX)) || (exit 1)))

$(LIBTIFF_EXEC_PREFIX):
	@(echo Makeing Directory $(LIBTIFF_EXEC_PREFIX)...;\
	  (($(LIBTIFF_MKDIR) $(LIBTIFF_EXEC_PREFIX)) || (exit 1)))

$(LIBTIFF_CONF_PREFIX):
	@(echo Makeing Directory $(LIBTIFF_CONF_PREFIX)...;\
	  (($(LIBTIFF_MKDIR) $(LIBTIFF_CONF_PREFIX)) || (exit 1)))

$(LIBTIFF_DOCS_PREFIX):
	@(echo Makeing Directory $(LIBTIFF_DOCS_PREFIX)...;\
	  (($(LIBTIFF_MKDIR) $(LIBTIFF_DOCS_PREFIX)) || (exit 1)))

#
# libtiff archived
#
libtiff-archived: 
	@(echo $(LIBTIFF_TGZ))
	  
#
# libtiff extracted
#
libtiff-extracted: 
	@(echo $(LIBTIFF_EXTRACT) $(LIBTIFF_TGZ))



        

