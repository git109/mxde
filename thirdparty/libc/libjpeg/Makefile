########################################################################
# Copyright (c) 1988-2015 $organization$
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
#   Date: 11/11/2015
#
# Thirdpary Makefile for jpeg
########################################################################

MAKEDIR=$(PWD)

########################################################################
#
# jpeg defs
#
########################################################################
JPEG_VERSION_MAJOR = 9
JPEG_VERSION_MINOR = a
JPEG_VERSION_RELEASE = 

JPEG_VERSION_SEPARATOR =
JPEG_VERSION_MAJOR_SEPARATOR = $(JPEG_VERSION_SEPARATOR)
JPEG_VERSION_MINOR_SEPARATOR = 

JPEG_VERSION_SHORT = $(JPEG_VERSION_MAJOR)$(JPEG_VERSION_MINOR)$(JPEG_VERSION_RELEASE)
JPEG_VERSION = $(JPEG_VERSION_MAJOR)$(JPEG_VERSION_MAJOR_SEPARATOR)$(JPEG_VERSION_MINOR)$(JPEG_VERSION_MINOR_SEPARATOR)$(JPEG_VERSION_RELEASE)

JPEG_NAME_SEPARATOR = -
JPEG_NAME_BASE = jpeg
JPEG_NAME = $(JPEG_NAME_BASE)$(JPEG_NAME_SEPARATOR)$(JPEG_VERSION)
JPEG_TGZ_NAME = $(JPEG_NAME_BASE)src.v$(JPEG_VERSION)
JPEG_INSTALL_NAME_SEPARATOR = -
JPEG_INSTALL_NAME = $(JPEG_NAME_BASE)$(JPEG_INSTALL_NAME_SEPARATOR)$(JPEG_VERSION)

JPEG_ARCHIVED = tar
JPEG_COMPRESSED = gz
JPEG_ARCHIVE_SEPARATOR = .
JPEG_ARCHIVED_SEPARATOR = $(JPEG_ARCHIVE_SEPARATOR)
JPEG_COMPRESSED_SEPARATOR = $(JPEG_ARCHIVE_SEPARATOR)

JPEG_BUILD = $(HOME)/build
JPEG_PREFIX = $(JPEG_BUILD)/$(JPEG_INSTALL_NAME)
JPEG_EXEC_PREFIX = $(JPEG_PREFIX)
JPEG_CONF_PREFIX = $(JPEG_PREFIX)
JPEG_DOCS_PREFIX = $(JPEG_PREFIX)
JPEG_LINK_NAME = $(JPEG_BUILD)/$(JPEG_NAME_BASE)
JPEG_DIR = $(JPEG_NAME)
JPEG_EXTRACT_DIR = $(JPEG_NAME)
JPEG_TGZ_PREFIX = 
JPEG_TGZ = $(JPEG_TGZ_NAME)$(JPEG_TGZ_PREFIX)$(JPEG_ARCHIVED_SEPARATOR)$(JPEG_ARCHIVED)$(JPEG_COMPRESSED_SEPARATOR)$(JPEG_COMPRESSED)
JPEG_PATCH_TGZ_PREFIX = $(JPEG_NAME_SEPARATOR)patch
JPEG_PATCH_TGZ = $(JPEG_NAME)$(JPEG_PATCH_TGZ_PREFIX)$(JPEG_ARCHIVED_SEPARATOR)$(JPEG_ARCHIVED)$(JPEG_COMPRESSED_SEPARATOR)$(JPEG_COMPRESSED)
JPEG_DOCS_TGZ_PREFIX = $(JPEG_NAME_SEPARATOR)docs
JPEG_DOCS_TGZ = $(JPEG_NAME)$(JPEG_DOCS_TGZ_PREFIX)$(JPEG_ARCHIVED_SEPARATOR)$(JPEG_ARCHIVED)$(JPEG_COMPRESSED_SEPARATOR)$(JPEG_COMPRESSED)

ifeq ($(JPEG_ARCHIVED),tar)
ifeq ($(JPEG_COMPRESSED),gz)
JPEG_TAR_UNCOMPRESS = z
JPEG_TAR_COMPRESS = z
else
ifeq ($(JPEG_COMPRESSED),bz2)
JPEG_TAR_UNCOMPRESS = j
JPEG_TAR_COMPRESS = j
else
endif
endif
JPEG_LIST = tar -tv$(JPEG_TAR_UNCOMPRESS)f
JPEG_EXTRACT = tar -x$(JPEG_TAR_UNCOMPRESS)f
JPEG_ARCHIVE = tar -cv$(JPEG_TAR_COMPRESS)f
else
ifeq ($(JPEG_ARCHIVED),zip)
JPEG_LIST = unzip -l
JPEG_EXTRACT = unzip
JPEG_ARCHIVE = zip
else
JPEG_LIST = echo unable to list
JPEG_EXTRACT = echo unable to extract
JPEG_ARCHIVE = echo unable to archive
endif
endif

JPEG_MKDIR = mkdir -p
JPEG_REMOVE = rm -r -f

JPEG_MAKE_DIR = $(JPEG_DIR)
JPEG_MAKE_PUSHD = pushd $(JPEG_MAKE_DIR)
JPEG_MAKE = make

JPEG_CONFIGURE_PUSHD = pushd $(JPEG_MAKE_DIR)
JPEG_CONFIGURE = ./configure --prefix=$(JPEG_PREFIX) --exec_prefix=$(JPEG_EXEC_PREFIX)
JPEG_HELP = ./configure --help

JPEG_LIST_TGZ = $(JPEG_LIST) $(JPEG_TGZ)
JPEG_EXTRACT_TGZ = $(JPEG_EXTRACT) $(JPEG_TGZ)
JPEG_TOUCH_EXTRACT = touch $(JPEG_DIR)
JPEG_REMOVE_DIR = $(JPEG_REMOVE) $(JPEG_DIR)

JPEG_LIST_PATCH = $(JPEG_LIST)
JPEG_EXTRACT_PATCH = $(JPEG_EXTRACT)
JPEG_LIST_PATCH_TGZ = $(JPEG_LIST_PATCH) $(JPEG_PATCH_TGZ)
JPEG_EXTRACT_PATCH_TGZ = $(JPEG_EXTRACT_PATCH) $(JPEG_PATCH_TGZ)

JPEG_LIST_DOCS = $(JPEG_LIST)
JPEG_EXTRACT_DOCS = $(JPEG_EXTRACT)
JPEG_LIST_DOCS_TGZ = $(JPEG_LIST_DOCS) $(JPEG_DOCS_TGZ)
JPEG_EXTRACT_DOCS_TGZ = $(JPEG_EXTRACT_DOCS) $(JPEG_DOCS_TGZ) -C$(JPEG_DOCS_PREFIX)

########################################################################
#
# rules
#
########################################################################

all:

test: test-jpeg

install-links: install-jpeg-links

install-docs: install-jpeg-docs

install-prefix: install-jpeg-prefix

install: install-jpeg

build: build-jpeg

clean: clean-jpeg

configed: configed-$(JPEG_DIR)

config: config-$(JPEG_DIR)

help: help-jpeg

list-docs: list-jpeg-docs

list-patch: list-jpeg-patch

extract-patch: extract-jpeg-patch

list: list-jpeg

extract: extract-jpeg

unextract: unextract-jpeg

archive: archive-jpeg

linked: jpeg-linked

prefixed: jpeg-prefixed

archived: jpeg-archived

extracted: jpeg-extracted

########################################################################
#
# jpeg rules
#
########################################################################

#
# Test jpeg
#
test-jpeg:
	@($(JPEG_MAKE_PUSHD);\
	  (($(JPEG_MAKE) test) || (exit 1));\
	  popd)

#
# Install jpeg
#
install-jpeg: configed-$(JPEG_DIR)
	@(echo Installing $(JPEG_DIR)...;\
	  $(JPEG_MAKE_PUSHD);\
	  (($(JPEG_MAKE) install) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(JPEG_DIR)) || (exit 1));\
	  popd)
	  
#
# Build jpeg
#
build-jpeg: configed-$(JPEG_DIR)
	@(echo Building $(JPEG_DIR)...;\
	  $(JPEG_MAKE_PUSHD);\
	  (($(JPEG_MAKE)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(JPEG_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean jpeg
#
clean-jpeg: configed-$(JPEG_DIR)
	@(echo Cleaning $(JPEG_DIR)...;\
	  $(JPEG_MAKE_PUSHD);\
	  (($(JPEG_MAKE) clean) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(JPEG_DIR)) || (exit 1));\
	  popd)
	  
#
# Config jpeg
#
config-$(JPEG_DIR): unconfig-$(JPEG_DIR) configed-$(JPEG_DIR)

unconfig-$(JPEG_DIR):
	@(rm -f configed-$(JPEG_DIR))

configed-$(JPEG_DIR): $(JPEG_DIR)
	@(echo Configing $(JPEG_DIR)...;\
	  $(JPEG_CONFIGURE_PUSHD);\
	  (($(JPEG_CONFIGURE)) || (exit 1)) && \
	  ((touch $(JPEG_DIR)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(JPEG_DIR)) || (exit 1));\
	  popd)

#
# Help jpeg
#
help-jpeg:
	@($(JPEG_CONFIGURE_PUSHD);\
	  (($(JPEG_HELP)) || (exit 1));\
	  popd)

#
# List jpeg Docs
#
list-jpeg-docs: $(JPEG_DOCS_TGZ)
	@(echo Listing $(JPEG_DOCS_TGZ)...;\
	  (($(JPEG_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install jpeg Docs
#
install-jpeg-docs: $(JPEG_DOCS_PREFIX)
	@(echo Extracting $(JPEG_DOCS_TGZ)...;\
	  (($(JPEG_EXTRACT_DOCS_TGZ)) || (exit 1)))

#
# List jpeg Patch
#
list-jpeg-patch: $(JPEG_PATCH_TGZ)
	@(echo Listing $(JPEG_PATCH_TGZ)...;\
	  (($(JPEG_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract jpeg patch
#
extract-jpeg-patch: $(JPEG_DIR)
	@(echo Extracting $(JPEG_PATCH_TGZ)...;\
	  (($(JPEG_EXTRACT_PATCH_TGZ)) || (exit 1)))

#
# List jpeg
#
list-jpeg: 
	@(echo Listing $(JPEG_TGZ)...;\
	  (($(JPEG_LIST_TGZ)) || (exit 1)))

#
# Extract jpeg
#
extract-jpeg: unextract-jpeg $(JPEG_DIR)

unextract-jpeg: 
	@(echo Removing $(JPEG_DIR)...;\
	  (($(JPEG_REMOVE_DIR)) || (exit 1)))

$(JPEG_DIR): $(JPEG_TGZ)
	@(echo Extracting $(JPEG_TGZ)...;\
	  (($(JPEG_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(JPEG_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# Archive jpeg
#
archive-jpeg: 
	@(echo Archiving $(JPEG_DIR) to $(JPEG_TGZ)...;\
	  (($(JPEG_ARCHIVE) $(JPEG_TGZ) $(JPEG_DIR)) || (exit 1)))

#
# Install jpeg links
#
install-jpeg-links: 
	@((echo removing $(JPEG_LINK_NAME)) && \
	  ((rm -f $(JPEG_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(JPEG_LINK_NAME) "->" $(JPEG_PREFIX)) && \
	  ((ln -s $(JPEG_PREFIX) $(JPEG_LINK_NAME)) || (exit 1)))
	  
#
# jpeg linked
#
jpeg-linked: 
	@echo link is $(JPEG_LINK_NAME) "->" $(JPEG_PREFIX)
	  
#
# Install jpeg prefix
#
install-jpeg-prefix: 
	@((echo makeing $(JPEG_PREFIX)) && \
	  ((mkdir -p $(JPEG_PREFIX)) || (exit 1)) && \
	  (echo makeing $(JPEG_EXEC_PREFIX)) && \
	  ((mkdir -p $(JPEG_EXEC_PREFIX)) || (exit 1)))
	  
#
# jpeg prefixed
#
jpeg-prefixed: 
	@((echo prefix is $(JPEG_PREFIX)) && \
	  (echo exec prefix is $(JPEG_EXEC_PREFIX)) && \
	  (echo conf prefix is $(JPEG_CONF_PREFIX)) && \
	  (echo docs prefix is $(JPEG_DOCS_PREFIX)))
	  
$(JPEG_PREFIX):
	@(echo Makeing Directory $(JPEG_PREFIX)...;\
	  (($(JPEG_MKDIR) $(JPEG_PREFIX)) || (exit 1)))

$(JPEG_EXEC_PREFIX):
	@(echo Makeing Directory $(JPEG_EXEC_PREFIX)...;\
	  (($(JPEG_MKDIR) $(JPEG_EXEC_PREFIX)) || (exit 1)))

$(JPEG_CONF_PREFIX):
	@(echo Makeing Directory $(JPEG_CONF_PREFIX)...;\
	  (($(JPEG_MKDIR) $(JPEG_CONF_PREFIX)) || (exit 1)))

$(JPEG_DOCS_PREFIX):
	@(echo Makeing Directory $(JPEG_DOCS_PREFIX)...;\
	  (($(JPEG_MKDIR) $(JPEG_DOCS_PREFIX)) || (exit 1)))

#
# jpeg archived
#
jpeg-archived: 
	@(echo $(JPEG_TGZ))
	  
#
# jpeg extracted
#
jpeg-extracted: 
	@(echo $(JPEG_EXTRACT) $(JPEG_TGZ))



        

