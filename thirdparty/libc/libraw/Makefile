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
#   Date: 2/21/2016
#
# Thirdpary Makefile for LibRaw
########################################################################

MAKEDIR=$(PWD)

########################################################################
#
# libRaw defs
#
########################################################################
LIBRAW_VERSION_MAJOR = 0
LIBRAW_VERSION_MINOR = 17
LIBRAW_VERSION_RELEASE = 1

LIBRAW_VERSION_SEPARATOR = .
LIBRAW_VERSION_MAJOR_SEPARATOR = $(LIBRAW_VERSION_SEPARATOR)
LIBRAW_VERSION_MINOR_SEPARATOR = $(LIBRAW_VERSION_SEPARATOR)

LIBRAW_VERSION_SHORT = $(LIBRAW_VERSION_MAJOR)$(LIBRAW_VERSION_MINOR)$(LIBRAW_VERSION_RELEASE)
LIBRAW_VERSION = $(LIBRAW_VERSION_MAJOR)$(LIBRAW_VERSION_MAJOR_SEPARATOR)$(LIBRAW_VERSION_MINOR)$(LIBRAW_VERSION_MINOR_SEPARATOR)$(LIBRAW_VERSION_RELEASE)

LIBRAW_NAME_SEPARATOR = -
LIBRAW_NAME_BASE = LibRaw
LIBRAW_NAME = $(LIBRAW_NAME_BASE)$(LIBRAW_NAME_SEPARATOR)$(LIBRAW_VERSION)
LIBRAW_INSTALL_NAME_SEPARATOR = -
LIBRAW_INSTALL_NAME = $(LIBRAW_NAME_BASE)$(LIBRAW_INSTALL_NAME_SEPARATOR)$(LIBRAW_VERSION)

LIBRAW_ARCHIVED = tar
LIBRAW_COMPRESSED = gz
LIBRAW_ARCHIVE_SEPARATOR = .
LIBRAW_ARCHIVED_SEPARATOR = $(LIBRAW_ARCHIVE_SEPARATOR)
LIBRAW_COMPRESSED_SEPARATOR = $(LIBRAW_ARCHIVE_SEPARATOR)

LIBRAW_BUILD = $(HOME)/build
LIBRAW_PREFIX = $(LIBRAW_BUILD)/$(LIBRAW_INSTALL_NAME)
LIBRAW_EXEC_PREFIX = $(LIBRAW_PREFIX)
LIBRAW_CONF_PREFIX = $(LIBRAW_PREFIX)
LIBRAW_DOCS_PREFIX = $(LIBRAW_PREFIX)
LIBRAW_LINK_NAME = $(LIBRAW_BUILD)/$(LIBRAW_NAME_BASE)
LIBRAW_DIR = $(LIBRAW_NAME)
LIBRAW_EXTRACT_DIR = $(LIBRAW_NAME)
LIBRAW_TGZ_PREFIX = 
LIBRAW_TGZ = $(LIBRAW_NAME)$(LIBRAW_TGZ_PREFIX)$(LIBRAW_ARCHIVED_SEPARATOR)$(LIBRAW_ARCHIVED)$(LIBRAW_COMPRESSED_SEPARATOR)$(LIBRAW_COMPRESSED)
LIBRAW_PATCH_TGZ_PREFIX = $(LIBRAW_NAME_SEPARATOR)patch
LIBRAW_PATCH_TGZ = $(LIBRAW_NAME)$(LIBRAW_PATCH_TGZ_PREFIX)$(LIBRAW_ARCHIVED_SEPARATOR)$(LIBRAW_ARCHIVED)$(LIBRAW_COMPRESSED_SEPARATOR)$(LIBRAW_COMPRESSED)
LIBRAW_DOCS_TGZ_PREFIX = $(LIBRAW_NAME_SEPARATOR)docs
LIBRAW_DOCS_TGZ = $(LIBRAW_NAME)$(LIBRAW_DOCS_TGZ_PREFIX)$(LIBRAW_ARCHIVED_SEPARATOR)$(LIBRAW_ARCHIVED)$(LIBRAW_COMPRESSED_SEPARATOR)$(LIBRAW_COMPRESSED)

ifeq ($(LIBRAW_ARCHIVED),tar)
ifeq ($(LIBRAW_COMPRESSED),gz)
LIBRAW_TAR_UNCOMPRESS = z
LIBRAW_TAR_COMPRESS = z
else
ifeq ($(LIBRAW_COMPRESSED),bz2)
LIBRAW_TAR_UNCOMPRESS = j
LIBRAW_TAR_COMPRESS = j
else
endif
endif
LIBRAW_LIST = tar -tv$(LIBRAW_TAR_UNCOMPRESS)f
LIBRAW_EXTRACT = tar -x$(LIBRAW_TAR_UNCOMPRESS)f
LIBRAW_ARCHIVE = tar -cv$(LIBRAW_TAR_COMPRESS)f
else
ifeq ($(LIBRAW_ARCHIVED),zip)
LIBRAW_LIST = unzip -l
LIBRAW_EXTRACT = unzip
LIBRAW_ARCHIVE = zip
else
LIBRAW_LIST = echo unable to list
LIBRAW_EXTRACT = echo unable to extract
LIBRAW_ARCHIVE = echo unable to archive
endif
endif

LIBRAW_MKDIR = mkdir -p
LIBRAW_REMOVE = rm -r -f

LIBRAW_MAKE_DIR = $(LIBRAW_DIR)
LIBRAW_MAKE_PUSHD = pushd $(LIBRAW_MAKE_DIR)
LIBRAW_MAKE = make

LIBRAW_CONFIGURE_PUSHD = pushd $(LIBRAW_MAKE_DIR)
LIBRAW_CONFIGURE = ./configure --prefix=$(LIBRAW_PREFIX) --exec_prefix=$(LIBRAW_EXEC_PREFIX)
LIBRAW_HELP = ./configure --help

LIBRAW_LIST_TGZ = $(LIBRAW_LIST) $(LIBRAW_TGZ)
LIBRAW_EXTRACT_TGZ = $(LIBRAW_EXTRACT) $(LIBRAW_TGZ)
LIBRAW_TOUCH_EXTRACT = touch $(LIBRAW_DIR)
LIBRAW_REMOVE_DIR = $(LIBRAW_REMOVE) $(LIBRAW_DIR)

LIBRAW_LIST_PATCH = $(LIBRAW_LIST)
LIBRAW_EXTRACT_PATCH = $(LIBRAW_EXTRACT)
LIBRAW_LIST_PATCH_TGZ = $(LIBRAW_LIST_PATCH) $(LIBRAW_PATCH_TGZ)
LIBRAW_EXTRACT_PATCH_TGZ = $(LIBRAW_EXTRACT_PATCH) $(LIBRAW_PATCH_TGZ)

LIBRAW_LIST_DOCS = $(LIBRAW_LIST)
LIBRAW_EXTRACT_DOCS = $(LIBRAW_EXTRACT)
LIBRAW_LIST_DOCS_TGZ = $(LIBRAW_LIST_DOCS) $(LIBRAW_DOCS_TGZ)
LIBRAW_EXTRACT_DOCS_TGZ = $(LIBRAW_EXTRACT_DOCS) $(LIBRAW_DOCS_TGZ) -C$(LIBRAW_DOCS_PREFIX)

########################################################################
#
# rules
#
########################################################################

all:

test: test-libraw

install-links: install-libraw-links

install-docs: install-libraw-docs

install-prefix: install-libraw-prefix

install: install-libraw

build: build-libraw

clean: clean-libraw

configed: configed-$(LIBRAW_DIR)

config: config-$(LIBRAW_DIR)

help: help-libraw

list-docs: list-libraw-docs

list-patch: list-libraw-patch

extract-patch: extract-libraw-patch

list: list-libraw

extract: extract-libraw

unextract: unextract-libraw

archive: archive-libraw

linked: libraw-linked

prefixed: libraw-prefixed

archived: libraw-archived

extracted: libraw-extracted

########################################################################
#
# libRaw rules
#
########################################################################

#
# Test libRaw
#
test-libraw:
	@($(LIBRAW_MAKE_PUSHD);\
	  (($(LIBRAW_MAKE) test) || (exit 1));\
	  popd)

#
# Install libRaw
#
install-libraw: configed-$(LIBRAW_DIR)
	@(echo Installing $(LIBRAW_DIR)...;\
	  $(LIBRAW_MAKE_PUSHD);\
	  (($(LIBRAW_MAKE) install) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBRAW_DIR)) || (exit 1));\
	  popd)
	  
#
# Build libRaw
#
build-libraw: configed-$(LIBRAW_DIR)
	@(echo Building $(LIBRAW_DIR)...;\
	  $(LIBRAW_MAKE_PUSHD);\
	  (($(LIBRAW_MAKE)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBRAW_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean libRaw
#
clean-libraw: configed-$(LIBRAW_DIR)
	@(echo Cleaning $(LIBRAW_DIR)...;\
	  $(LIBRAW_MAKE_PUSHD);\
	  (($(LIBRAW_MAKE) clean) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBRAW_DIR)) || (exit 1));\
	  popd)
	  
#
# Config libRaw
#
config-$(LIBRAW_DIR): unconfig-$(LIBRAW_DIR) configed-$(LIBRAW_DIR)

unconfig-$(LIBRAW_DIR):
	@(rm -f configed-$(LIBRAW_DIR))

configed-$(LIBRAW_DIR): $(LIBRAW_DIR)
	@(echo Configing $(LIBRAW_DIR)...;\
	  $(LIBRAW_CONFIGURE_PUSHD);\
	  (($(LIBRAW_CONFIGURE)) || (exit 1)) && \
	  ((touch $(LIBRAW_DIR)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(LIBRAW_DIR)) || (exit 1));\
	  popd)

#
# Help libRaw
#
help-libraw:
	@($(LIBRAW_CONFIGURE_PUSHD);\
	  (($(LIBRAW_HELP)) || (exit 1));\
	  popd)

#
# List libRaw Docs
#
list-libraw-docs: $(LIBRAW_DOCS_TGZ)
	@(echo Listing $(LIBRAW_DOCS_TGZ)...;\
	  (($(LIBRAW_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install libRaw Docs
#
install-libraw-docs: $(LIBRAW_DOCS_PREFIX)
	@(echo Extracting $(LIBRAW_DOCS_TGZ)...;\
	  (($(LIBRAW_EXTRACT_DOCS_TGZ)) || (exit 1)))

#
# List libRaw Patch
#
list-libraw-patch: $(LIBRAW_PATCH_TGZ)
	@(echo Listing $(LIBRAW_PATCH_TGZ)...;\
	  (($(LIBRAW_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract libRaw patch
#
extract-libraw-patch: $(LIBRAW_DIR)
	@(echo Extracting $(LIBRAW_PATCH_TGZ)...;\
	  (($(LIBRAW_EXTRACT_PATCH_TGZ)) || (exit 1)))

#
# List libRaw
#
list-libraw: 
	@(echo Listing $(LIBRAW_TGZ)...;\
	  (($(LIBRAW_LIST_TGZ)) || (exit 1)))

#
# Extract libRaw
#
extract-libraw: unextract-libraw $(LIBRAW_DIR)

unextract-libraw: 
	@(echo Removing $(LIBRAW_DIR)...;\
	  (($(LIBRAW_REMOVE_DIR)) || (exit 1)))

$(LIBRAW_DIR): $(LIBRAW_TGZ)
	@(echo Extracting $(LIBRAW_TGZ)...;\
	  (($(LIBRAW_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(LIBRAW_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# Archive libRaw
#
archive-libraw: 
	@(echo Archiving $(LIBRAW_DIR) to $(LIBRAW_TGZ)...;\
	  (($(LIBRAW_ARCHIVE) $(LIBRAW_TGZ) $(LIBRAW_DIR)) || (exit 1)))

#
# Install libRaw links
#
install-libraw-links: 
	@((echo removing $(LIBRAW_LINK_NAME)) && \
	  ((rm -f $(LIBRAW_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(LIBRAW_LINK_NAME) "->" $(LIBRAW_PREFIX)) && \
	  ((ln -s $(LIBRAW_PREFIX) $(LIBRAW_LINK_NAME)) || (exit 1)))
	  
#
# libRaw linked
#
libraw-linked: 
	@echo link is $(LIBRAW_LINK_NAME) "->" $(LIBRAW_PREFIX)
	  
#
# Install libRaw prefix
#
install-libraw-prefix: 
	@((echo makeing $(LIBRAW_PREFIX)) && \
	  ((mkdir -p $(LIBRAW_PREFIX)) || (exit 1)) && \
	  (echo makeing $(LIBRAW_EXEC_PREFIX)) && \
	  ((mkdir -p $(LIBRAW_EXEC_PREFIX)) || (exit 1)))
	  
#
# libRaw prefixed
#
libraw-prefixed: 
	@((echo prefix is $(LIBRAW_PREFIX)) && \
	  (echo exec prefix is $(LIBRAW_EXEC_PREFIX)) && \
	  (echo conf prefix is $(LIBRAW_CONF_PREFIX)) && \
	  (echo docs prefix is $(LIBRAW_DOCS_PREFIX)))
	  
$(LIBRAW_PREFIX):
	@(echo Makeing Directory $(LIBRAW_PREFIX)...;\
	  (($(LIBRAW_MKDIR) $(LIBRAW_PREFIX)) || (exit 1)))

$(LIBRAW_EXEC_PREFIX):
	@(echo Makeing Directory $(LIBRAW_EXEC_PREFIX)...;\
	  (($(LIBRAW_MKDIR) $(LIBRAW_EXEC_PREFIX)) || (exit 1)))

$(LIBRAW_CONF_PREFIX):
	@(echo Makeing Directory $(LIBRAW_CONF_PREFIX)...;\
	  (($(LIBRAW_MKDIR) $(LIBRAW_CONF_PREFIX)) || (exit 1)))

$(LIBRAW_DOCS_PREFIX):
	@(echo Makeing Directory $(LIBRAW_DOCS_PREFIX)...;\
	  (($(LIBRAW_MKDIR) $(LIBRAW_DOCS_PREFIX)) || (exit 1)))

#
# libRaw archived
#
libraw-archived: 
	@(echo $(LIBRAW_TGZ))
	  
#
# libRaw extracted
#
libraw-extracted: 
	@(echo $(LIBRAW_EXTRACT) $(LIBRAW_TGZ))



        

