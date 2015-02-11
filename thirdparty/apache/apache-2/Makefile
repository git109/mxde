########################################################################
# Copyright (c) 1988-2014 $organization$
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
#   Date: 10/4/2014
#
# Thirdpary Makefile for Httpd
########################################################################

MAKEDIR=$(PWD)

########################################################################
#
# Httpd defs
#
########################################################################
HTTPD_VERSION_MAJOR = 2
HTTPD_VERSION_MINOR = 0
HTTPD_VERSION_RELEASE = 64

HTTPD_VERSION_SEPARATOR = .
HTTPD_VERSION_MAJOR_SEPARATOR = $(HTTPD_VERSION_SEPARATOR)
HTTPD_VERSION_MINOR_SEPARATOR = $(HTTPD_VERSION_SEPARATOR)

HTTPD_VERSION_SHORT = $(HTTPD_VERSION_MAJOR)$(HTTPD_VERSION_MINOR)$(HTTPD_VERSION_RELEASE)
HTTPD_VERSION = $(HTTPD_VERSION_MAJOR)$(HTTPD_VERSION_MAJOR_SEPARATOR)$(HTTPD_VERSION_MINOR)$(HTTPD_VERSION_MINOR_SEPARATOR)$(HTTPD_VERSION_RELEASE)

HTTPD_NAME_SEPARATOR = -
HTTPD_NAME_BASE = httpd
HTTPD_NAME = $(HTTPD_NAME_BASE)$(HTTPD_NAME_SEPARATOR)$(HTTPD_VERSION)
HTTPD_INSTALL_NAME_SEPARATOR = -
HTTPD_INSTALL_NAME = $(HTTPD_NAME_BASE)$(HTTPD_INSTALL_NAME_SEPARATOR)$(HTTPD_VERSION)

HTTPD_ARCHIVED = tar
HTTPD_COMPRESSED = gz
HTTPD_ARCHIVE_SEPARATOR = .
HTTPD_ARCHIVED_SEPARATOR = $(HTTPD_ARCHIVE_SEPARATOR)
HTTPD_COMPRESSED_SEPARATOR = $(HTTPD_ARCHIVE_SEPARATOR)

HTTPD_BUILD = $(HOME)/build
HTTPD_PREFIX = $(HTTPD_BUILD)/$(HTTPD_INSTALL_NAME)
HTTPD_EXEC_PREFIX = $(HTTPD_PREFIX)
HTTPD_CONF_PREFIX = $(HTTPD_PREFIX)
HTTPD_DOCS_PREFIX = $(HTTPD_PREFIX)
HTTPD_LINK_NAME = $(HTTPD_BUILD)/$(HTTPD_NAME_BASE)
HTTPD_DIR = $(HTTPD_NAME)
HTTPD_EXTRACT_DIR = $(HTTPD_NAME)
HTTPD_TGZ_PREFIX = 
HTTPD_TGZ = $(HTTPD_NAME)$(HTTPD_TGZ_PREFIX)$(HTTPD_ARCHIVED_SEPARATOR)$(HTTPD_ARCHIVED)$(HTTPD_COMPRESSED_SEPARATOR)$(HTTPD_COMPRESSED)
HTTPD_PATCH_TGZ_PREFIX = $(HTTPD_NAME_SEPARATOR)patch
HTTPD_PATCH_TGZ = $(HTTPD_NAME)$(HTTPD_PATCH_TGZ_PREFIX)$(HTTPD_ARCHIVED_SEPARATOR)$(HTTPD_ARCHIVED)$(HTTPD_COMPRESSED_SEPARATOR)$(HTTPD_COMPRESSED)
HTTPD_DOCS_TGZ_PREFIX = $(HTTPD_NAME_SEPARATOR)docs
HTTPD_DOCS_TGZ = $(HTTPD_NAME)$(HTTPD_DOCS_TGZ_PREFIX)$(HTTPD_ARCHIVED_SEPARATOR)$(HTTPD_ARCHIVED)$(HTTPD_COMPRESSED_SEPARATOR)$(HTTPD_COMPRESSED)

ifeq ($(HTTPD_ARCHIVED),tar)
ifeq ($(HTTPD_COMPRESSED),gz)
HTTPD_TAR_UNCOMPRESS = z
HTTPD_TAR_COMPRESS = z
else
ifeq ($(HTTPD_COMPRESSED),bz2)
HTTPD_TAR_UNCOMPRESS = j
HTTPD_TAR_COMPRESS = j
else
endif
endif
HTTPD_LIST = tar -tv$(HTTPD_TAR_UNCOMPRESS)f
HTTPD_EXTRACT = tar -x$(HTTPD_TAR_UNCOMPRESS)f
HTTPD_ARCHIVE = tar -cv$(HTTPD_TAR_COMPRESS)f
else
ifeq ($(HTTPD_ARCHIVED),zip)
HTTPD_LIST = unzip -l
HTTPD_EXTRACT = unzip
HTTPD_ARCHIVE = zip
else
HTTPD_LIST = echo unable to list
HTTPD_EXTRACT = echo unable to extract
HTTPD_ARCHIVE = echo unable to archive
endif
endif

HTTPD_MKDIR = mkdir -p
HTTPD_REMOVE = rm -r -f

HTTPD_MAKE_DIR = $(HTTPD_DIR)
HTTPD_MAKE_PUSHD = pushd $(HTTPD_MAKE_DIR)
HTTPD_MAKE = make

HTTPD_CONFIGURE_PUSHD = pushd $(HTTPD_MAKE_DIR)
HTTPD_CONFIGURE = ./configure --prefix=$(HTTPD_PREFIX) --exec_prefix=$(HTTPD_EXEC_PREFIX)
HTTPD_HELP = ./configure --help

HTTPD_LIST_TGZ = $(HTTPD_LIST) $(HTTPD_TGZ)
HTTPD_EXTRACT_TGZ = $(HTTPD_EXTRACT) $(HTTPD_TGZ)
HTTPD_TOUCH_EXTRACT = touch $(HTTPD_DIR)
HTTPD_REMOVE_DIR = $(HTTPD_REMOVE) $(HTTPD_DIR)

HTTPD_LIST_PATCH = $(HTTPD_LIST)
HTTPD_EXTRACT_PATCH = $(HTTPD_EXTRACT)
HTTPD_LIST_PATCH_TGZ = $(HTTPD_LIST_PATCH) $(HTTPD_PATCH_TGZ)
HTTPD_EXTRACT_PATCH_TGZ = $(HTTPD_EXTRACT_PATCH) $(HTTPD_PATCH_TGZ)

HTTPD_LIST_DOCS = $(HTTPD_LIST)
HTTPD_EXTRACT_DOCS = $(HTTPD_EXTRACT)
HTTPD_LIST_DOCS_TGZ = $(HTTPD_LIST_DOCS) $(HTTPD_DOCS_TGZ)
HTTPD_EXTRACT_DOCS_TGZ = $(HTTPD_EXTRACT_DOCS) $(HTTPD_DOCS_TGZ) -C$(HTTPD_DOCS_PREFIX)

########################################################################
#
# rules
#
########################################################################

all:

test: test-httpd

install-links: install-httpd-links

install-docs: install-httpd-docs

install-prefix: install-httpd-prefix

install: install-httpd

build: build-httpd

clean: clean-httpd

configed: configed-$(HTTPD_DIR)

config: config-$(HTTPD_DIR)

help: help-httpd

list-docs: list-httpd-docs

list-patch: list-httpd-patch

extract-patch: extract-httpd-patch

list: list-httpd

extract: extract-httpd

unextract: unextract-httpd

archive: archive-httpd

linked: httpd-linked

prefixed: httpd-prefixed

archived: httpd-archived

extracted: httpd-extracted

########################################################################
#
# Httpd rules
#
########################################################################

#
# Test Httpd
#
test-httpd:
	@($(HTTPD_MAKE_PUSHD);\
	  (($(HTTPD_MAKE) test) || (exit 1));\
	  popd)

#
# Install Httpd
#
install-httpd: configed-$(HTTPD_DIR)
	@(echo Installing $(HTTPD_DIR)...;\
	  $(HTTPD_MAKE_PUSHD);\
	  (($(HTTPD_MAKE) install) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(HTTPD_DIR)) || (exit 1));\
	  popd)
	  
#
# Build Httpd
#
build-httpd: configed-$(HTTPD_DIR)
	@(echo Building $(HTTPD_DIR)...;\
	  $(HTTPD_MAKE_PUSHD);\
	  (($(HTTPD_MAKE)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(HTTPD_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean Httpd
#
clean-httpd: configed-$(HTTPD_DIR)
	@(echo Cleaning $(HTTPD_DIR)...;\
	  $(HTTPD_MAKE_PUSHD);\
	  (($(HTTPD_MAKE) clean) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(HTTPD_DIR)) || (exit 1));\
	  popd)
	  
#
# Config Httpd
#
config-$(HTTPD_DIR): unconfig-$(HTTPD_DIR) configed-$(HTTPD_DIR)

unconfig-$(HTTPD_DIR):
	@(rm -f configed-$(HTTPD_DIR))

configed-$(HTTPD_DIR): $(HTTPD_DIR)
	@(echo Configing $(HTTPD_DIR)...;\
	  $(HTTPD_CONFIGURE_PUSHD);\
	  (($(HTTPD_CONFIGURE)) || (exit 1)) && \
	  ((touch $(HTTPD_DIR)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(HTTPD_DIR)) || (exit 1));\
	  popd)

#
# Help Httpd
#
help-httpd:
	@($(HTTPD_CONFIGURE_PUSHD);\
	  (($(HTTPD_HELP)) || (exit 1));\
	  popd)

#
# List Httpd Docs
#
list-httpd-docs: $(HTTPD_DOCS_TGZ)
	@(echo Listing $(HTTPD_DOCS_TGZ)...;\
	  (($(HTTPD_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install Httpd Docs
#
install-httpd-docs: $(HTTPD_DOCS_PREFIX)
	@(echo Extracting $(HTTPD_DOCS_TGZ)...;\
	  (($(HTTPD_EXTRACT_DOCS_TGZ)) || (exit 1)))

#
# List Httpd Patch
#
list-httpd-patch: $(HTTPD_PATCH_TGZ)
	@(echo Listing $(HTTPD_PATCH_TGZ)...;\
	  (($(HTTPD_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract Httpd patch
#
extract-httpd-patch: $(HTTPD_DIR)
	@(echo Extracting $(HTTPD_PATCH_TGZ)...;\
	  (($(HTTPD_EXTRACT_PATCH_TGZ)) || (exit 1)))

#
# List Httpd
#
list-httpd: 
	@(echo Listing $(HTTPD_TGZ)...;\
	  (($(HTTPD_LIST_TGZ)) || (exit 1)))

#
# Extract Httpd
#
extract-httpd: unextract-httpd $(HTTPD_DIR)

unextract-httpd: 
	@(echo Removing $(HTTPD_DIR)...;\
	  (($(HTTPD_REMOVE_DIR)) || (exit 1)))

$(HTTPD_DIR): $(HTTPD_TGZ)
	@(echo Extracting $(HTTPD_TGZ)...;\
	  (($(HTTPD_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(HTTPD_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# Archive Httpd
#
archive-httpd: 
	@(echo Archiving $(HTTPD_DIR) to $(HTTPD_TGZ)...;\
	  (($(HTTPD_ARCHIVE) $(HTTPD_TGZ) $(HTTPD_DIR)) || (exit 1)))

#
# Install Httpd links
#
install-httpd-links: 
	@((echo removing $(HTTPD_LINK_NAME)) && \
	  ((rm -f $(HTTPD_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(HTTPD_LINK_NAME) "->" $(HTTPD_PREFIX)) && \
	  ((ln -s $(HTTPD_PREFIX) $(HTTPD_LINK_NAME)) || (exit 1)))
	  
#
# Httpd linked
#
httpd-linked: 
	@echo link is $(HTTPD_LINK_NAME) "->" $(HTTPD_PREFIX)
	  
#
# Install Httpd prefix
#
install-httpd-prefix: 
	@((echo makeing $(HTTPD_PREFIX)) && \
	  ((mkdir -p $(HTTPD_PREFIX)) || (exit 1)) && \
	  (echo makeing $(HTTPD_EXEC_PREFIX)) && \
	  ((mkdir -p $(HTTPD_EXEC_PREFIX)) || (exit 1)))
	  
#
# Httpd prefixed
#
httpd-prefixed: 
	@((echo prefix is $(HTTPD_PREFIX)) && \
	  (echo exec prefix is $(HTTPD_EXEC_PREFIX)) && \
	  (echo conf prefix is $(HTTPD_CONF_PREFIX)) && \
	  (echo docs prefix is $(HTTPD_DOCS_PREFIX)))
	  
$(HTTPD_PREFIX):
	@(echo Makeing Directory $(HTTPD_PREFIX)...;\
	  (($(HTTPD_MKDIR) $(HTTPD_PREFIX)) || (exit 1)))

$(HTTPD_EXEC_PREFIX):
	@(echo Makeing Directory $(HTTPD_EXEC_PREFIX)...;\
	  (($(HTTPD_MKDIR) $(HTTPD_EXEC_PREFIX)) || (exit 1)))

$(HTTPD_CONF_PREFIX):
	@(echo Makeing Directory $(HTTPD_CONF_PREFIX)...;\
	  (($(HTTPD_MKDIR) $(HTTPD_CONF_PREFIX)) || (exit 1)))

$(HTTPD_DOCS_PREFIX):
	@(echo Makeing Directory $(HTTPD_DOCS_PREFIX)...;\
	  (($(HTTPD_MKDIR) $(HTTPD_DOCS_PREFIX)) || (exit 1)))

#
# Httpd archived
#
httpd-archived: 
	@(echo $(HTTPD_TGZ))
	  
#
# Httpd extracted
#
httpd-extracted: 
	@(echo $(HTTPD_EXTRACT) $(HTTPD_TGZ))



        

