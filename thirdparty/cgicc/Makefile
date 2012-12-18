########################################################################
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
# Author: medusa@medusade.org
#   Date: 4/3/2011
#
# Thirdpary Makefile for Cgicc
########################################################################

MAKEDIR=$(PWD)

########################################################################
#
# Cgicc defs
#
########################################################################
CGICC_VERSION_MAJOR = 3
CGICC_VERSION_MINOR = 2
CGICC_VERSION_RELEASE = 9

CGICC_VERSION_SEPARATOR = .
CGICC_VERSION_MAJOR_SEPARATOR = $(CGICC_VERSION_SEPARATOR)
CGICC_VERSION_MINOR_SEPARATOR = $(CGICC_VERSION_SEPARATOR)

CGICC_VERSION_SHORT = $(CGICC_VERSION_MAJOR)$(CGICC_VERSION_MINOR)$(CGICC_VERSION_RELEASE)
CGICC_VERSION = $(CGICC_VERSION_MAJOR)$(CGICC_VERSION_MAJOR_SEPARATOR)$(CGICC_VERSION_MINOR)$(CGICC_VERSION_MINOR_SEPARATOR)$(CGICC_VERSION_RELEASE)

CGICC_NAME_SEPARATOR = -
CGICC_NAME_BASE = cgicc
CGICC_NAME = $(CGICC_NAME_BASE)$(CGICC_NAME_SEPARATOR)$(CGICC_VERSION)
CGICC_INSTALL_NAME_SEPARATOR = -
CGICC_INSTALL_NAME = $(CGICC_NAME_BASE)$(CGICC_INSTALL_NAME_SEPARATOR)$(CGICC_VERSION)
CGICC_ARCHIVED = tar
CGICC_COMPRESSED = gz

CGICC_BUILD = $(HOME)/build
CGICC_PREFIX = $(CGICC_BUILD)/$(CGICC_INSTALL_NAME)
CGICC_EXEC_PREFIX = $(CGICC_BUILD)/$(CGICC_INSTALL_NAME)
CGICC_CONF_PREFIX = $(CGICC_PREFIX)
CGICC_DOCS_PREFIX = $(CGICC_PREFIX)
CGICC_LINK_NAME = $(CGICC_BUILD)/$(CGICC_NAME_BASE)
CGICC_DIR = $(CGICC_NAME)
CGICC_EXTRACT_DIR = $(CGICC_NAME)
CGICC_TGZ_PREFIX = 
CGICC_TGZ = $(CGICC_NAME)$(CGICC_TGZ_PREFIX).$(CGICC_ARCHIVED).$(CGICC_COMPRESSED)
CGICC_PATCH_TGZ_PREFIX = $(CGICC_NAME_SEPARATOR)patch
CGICC_PATCH_TGZ = $(CGICC_NAME)$(CGICC_PATCH_TGZ_PREFIX).$(CGICC_ARCHIVED).$(CGICC_COMPRESSED)
CGICC_DOCS_TGZ_PREFIX = $(CGICC_NAME_SEPARATOR)docs
CGICC_DOCS_TGZ = $(CGICC_NAME)$(CGICC_DOCS_TGZ_PREFIX).$(CGICC_ARCHIVED).$(CGICC_COMPRESSED)

ifeq ($(CGICC_ARCHIVED),tar)
ifeq ($(CGICC_COMPRESSED),gz)
CGICC_TAR_UNCOMPRESS = z
CGICC_TAR_COMPRESS = z
else
ifeq ($(CGICC_COMPRESSED),bz2)
CGICC_TAR_UNCOMPRESS = j
CGICC_TAR_COMPRESS = j
else
endif
endif
CGICC_LIST = tar -tv$(CGICC_TAR_UNCOMPRESS)f
CGICC_EXTRACT = tar -x$(CGICC_TAR_UNCOMPRESS)f
CGICC_ARCHIVE = tar -cv$(CGICC_TAR_COMPRESS)f
else
CGICC_LIST = echo unable to list
CGICC_EXTRACT = echo unable to extract
CGICC_ARCHIVE = echo unable to archive
endif

CGICC_REMOVE = rm -r -f

CGICC_MAKE_DIR = $(CGICC_DIR)
CGICC_MAKE_PUSHD = pushd $(CGICC_MAKE_DIR)
CGICC_MAKE = make

CGICC_CONFIGURE_PUSHD = pushd $(CGICC_MAKE_DIR)
CGICC_CONFIGURE = ./configure --prefix=$(CGICC_PREFIX) --exec_prefix=$(CGICC_EXEC_PREFIX)
CGICC_HELP = ./configure --help

CGICC_LIST_TGZ = $(CGICC_LIST) $(CGICC_TGZ)
CGICC_EXTRACT_TGZ = $(CGICC_EXTRACT) $(CGICC_TGZ)
CGICC_TOUCH_EXTRACT = touch $(CGICC_DIR)
CGICC_REMOVE_DIR = $(CGICC_REMOVE) $(CGICC_DIR)

CGICC_LIST_PATCH = $(CGICC_LIST)
CGICC_EXTRACT_PATCH = $(CGICC_EXTRACT)
CGICC_LIST_PATCH_TGZ = $(CGICC_LIST) $(CGICC_PATCH_TGZ)
CGICC_EXTRACT_PATCH_TGZ = $(CGICC_EXTRACT) $(CGICC_PATCH_TGZ)

CGICC_LIST_DOCS = $(CGICC_LIST)
CGICC_EXTRACT_DOCS = $(CGICC_EXTRACT)
CGICC_LIST_DOCS_TGZ = $(CGICC_LIST) $(CGICC_DOCS_TGZ)
CGICC_EXTRACT_DOCS_TGZ = $(CGICC_EXTRACT) $(CGICC_DOCS_TGZ)

########################################################################
#
# rules
#
########################################################################

all:

test: test-cgicc

install-links: install-cgicc-links

install: install-cgicc

build: build-cgicc

clean: clean-cgicc

install-prefix: install-cgicc-prefix

configed: configed-$(CGICC_DIR)

config: config-$(CGICC_DIR)

help: help-cgicc

list-patch: list-patch-cgicc

extract-patch: extract-patch-cgicc

list: list-cgicc

extract: extract-cgicc

unextract: unextract-cgicc

archive: archive-cgicc

linked: cgicc-linked

prefixed: cgicc-prefixed

archived: cgicc-archived

extracted: cgicc-extracted

########################################################################
#
# Cgicc rules
#
########################################################################

#
# Test Cgicc
#
test-cgicc:
	@($(CGICC_MAKE_PUSHD);\
	  (($(CGICC_MAKE) test) || (exit 1));\
	  popd)

#
# Install Cgicc
#
install-cgicc: configed-$(CGICC_DIR)
	@(echo Installing $(CGICC_DIR)...;\
	  $(CGICC_MAKE_PUSHD);\
	  (($(CGICC_MAKE) install) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(CGICC_DIR)) || (exit 1));\
	  popd)
	  
#
# Build Cgicc
#
build-cgicc: configed-$(CGICC_DIR)
	@(echo Building $(CGICC_DIR)...;\
	  $(CGICC_MAKE_PUSHD);\
	  (($(CGICC_MAKE)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(CGICC_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean Cgicc
#
clean-cgicc: configed-$(CGICC_DIR)
	@(echo Cleaning $(CGICC_DIR)...;\
	  $(CGICC_MAKE_PUSHD);\
	  (($(CGICC_MAKE) clean) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(CGICC_DIR)) || (exit 1));\
	  popd)
	  
#
# Config Cgicc
#
config-$(CGICC_DIR): unconfig-$(CGICC_DIR) configed-$(CGICC_DIR)

unconfig-$(CGICC_DIR):
	@(rm -f configed-$(CGICC_DIR))

configed-$(CGICC_DIR): $(CGICC_DIR)
	@(echo Configing $(CGICC_DIR)...;\
	  $(CGICC_CONFIGURE_PUSHD);\
	  (($(CGICC_CONFIGURE)) || (exit 1)) && \
	  ((touch $(CGICC_DIR)) || (exit 1)) && \
	  ((touch $(MAKEDIR)/configed-$(CGICC_DIR)) || (exit 1));\
	  popd)

#
# Help Cgicc
#
help-cgicc:
	@($(CGICC_CONFIGURE_PUSHD);\
	  (($(CGICC_HELP)) || (exit 1));\
	  popd)

#
# List Docs Cgicc
#
list-docs-cgicc: $(CGICC_DOCS_TGZ)
	@(echo Listing $(CGICC_DOCS_TGZ)...;\
	  (($(CGICC_LIST_DOCS_TGZ)) || (exit 1)))

#
# Extract Docs Cgicc
#
extract-docs-cgicc: $(CGICC_DOCS_PREFIX)
	@(echo Extracting $(CGICC_DOCS_TGZ)...;\
	  (($(CGICC_EXTRACT_DOCS_TGZ)) || (exit 1)))

#
# List Patch Cgicc
#
list-patch-cgicc: $(CGICC_PATCH_TGZ)
	@(echo Listing $(CGICC_PATCH_TGZ)...;\
	  (($(CGICC_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract Patch Cgicc
#
extract-patch-cgicc: $(CGICC_DIR)
	@(echo Extracting $(CGICC_PATCH_TGZ)...;\
	  (($(CGICC_EXTRACT_PATCH_TGZ)) || (exit 1)))

#
# List Cgicc
#
list-cgicc: 
	@(echo Listing $(CGICC_TGZ)...;\
	  (($(CGICC_LIST) $(CGICC_TGZ)) || (exit 1)))

#
# Extract Cgicc
#
extract-cgicc: unextract-cgicc $(CGICC_DIR)

unextract-cgicc: 
	@(echo Removing $(CGICC_DIR)...;\
	  (($(CGICC_REMOVE_DIR)) || (exit 1)))

$(CGICC_DIR): $(CGICC_TGZ)
	@(echo Extracting $(CGICC_TGZ)...;\
	  (($(CGICC_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(CGICC_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# Archive Cgicc
#
archive-cgicc: 
	@(echo Archiving $(CGICC_DIR) to $(CGICC_TGZ)...;\
	  (($(CGICC_ARCHIVE) $(CGICC_TGZ) $(CGICC_DIR)) || (exit 1)))

#
# Install Cgicc links
#
install-cgicc-links: 
	@((echo removing $(CGICC_LINK_NAME)) && \
	  ((rm -f $(CGICC_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(CGICC_LINK_NAME) "->" $(CGICC_PREFIX)) && \
	  ((ln -s $(CGICC_PREFIX) $(CGICC_LINK_NAME)) || (exit 1)))
	  
#
# Cgicc linked
#
cgicc-linked: 
	@echo link is $(CGICC_LINK_NAME) "->" $(CGICC_PREFIX)
	  
#
# Install Cgicc prefix
#
install-cgicc-prefix: 
	@((echo makeing $(CGICC_PREFIX)) && \
	  ((mkdir -p $(CGICC_PREFIX)) || (exit 1)) && \
	  (echo makeing $(CGICC_EXEC_PREFIX)) && \
	  ((mkdir -p $(CGICC_EXEC_PREFIX)) || (exit 1)))
	  
#
# Cgicc prefixed
#
cgicc-prefixed: 
	@((echo prefix is $(CGICC_PREFIX)) && \
	  (echo exec prefix is $(CGICC_EXEC_PREFIX)))
	  
#
# Cgicc archived
#
cgicc-archived: 
	@(echo $(CGICC_TGZ))
	  
#
# Cgicc extracted
#
cgicc-extracted: 
	@(echo $(CGICC_EXTRACT) $(CGICC_TGZ))


