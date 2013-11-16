#############################################################################
# Copyright (c) 1988-2007 $organization$.
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
#   File: Makefile
#
# Author: $author$
#   Date: 7/31/2009
#
# Linux makefile for XDE
#
#############################################################################

PKG = $(PWD)/../../../..
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

SRC_DIRS = \
$(PKG)/$(PRJ)/lib/libcbase \
$(PKG)/$(PRJ)/lib/libcos \
$(PKG)/$(PRJ)/lib/libcxttp \
$(PKG)/$(PRJ)/lib/libccgi \
$(PKG)/$(PRJ)/lib/libct \

#$(PKG)/$(PRJ)/lib/libcxerces \
#$(PKG)/$(PRJ)/lib/libcxalan \

include $(PKG)/$(PRJ)/Makedirs

install:
	@(echo Installing libs...;\
	  ((mkdir -p $(HOME)/build/xde) || (exit 1));\
	  ((cp -r $(PKGBLD)/lib $(HOME)/build/xde) || (exit 1));\
	  echo ...Installed libs)
