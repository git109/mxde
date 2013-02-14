########################################################################
# Copyright (c) 1988-2013 $organization$
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
#   Date: 2/7/2013
#
# MacOSX Gcc Makefile for Xoslib XosMacHello Executable
########################################################################

PKG = $(PWD)/../../../../..

PRJ = projects/macosx/Makefile
SRC = src
BLD = ../build/macosx


include $(PKG)/$(PRJ)/Makedefines

#
# user ld flags
#
USRLDFLAGS = \
-Wl,-framework,QTKit \
-Wl,-framework,QuartzCore \
-Wl,-framework,CoreFoundation \
-Wl,-framework,CoreVideo \
-Wl,-framework,CoreAudio \
-Wl,-framework,Cocoa \
-Wl,-framework,Carbon \
-Wl,-framework,AudioToolbox \
-Wl,-framework,ApplicationServices \
-Wl,-framework,OpenGL \

#
# user c flags
#
USRCFLAGS = \

#
# user c++ flags
#
USRCXXFLAGS = \

#
# user defines
#
USRDEFINES = \

#
# user includes
#
USRINCLUDES = \

#
# user libdirs
#
USRLIBDIRS = \

#
# target
#
EXETARGET = XosMacHello

#
# Executable C sources
#
EXE_C_SOURCES = \

#
# Executable C++ .cc sources
#
EXE_CC_SOURCES = \

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES = \

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES = \

#
# Executable Objective C .m sources
#
EXE_M_SOURCES = \

#
# Executable Objective C++ .mm sources
#
EXE_MM_SOURCES = \
$(PKG)/$(SRC)/lib/XosCore/XosMain.mm \
$(PKG)/$(SRC)/lib/XosGui/XosOpenGL/XosOpenGLContext.mm \
$(PKG)/$(SRC)/lib/XosGui/XosOpenGL/XosOpenGLTexture2DImageRenderer.mm \
$(PKG)/$(SRC)/lib/XosGui/XosOpenGL/XosMac/XosNSOpenGLViewTexture2DImageRenderer.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacBaseMain.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacHello.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacMain.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacMainMain.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacOpenGLContext.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacWindow.mm \
$(PKG)/$(SRC)/lib/XosGui/XosMac/XosMacWindowMain.mm \

#
# Executable libs
#
#LIBS = \
#-lsomelib
#
LIBS = \
-lXosCore \

#
# Executable depends
#
#EXEDEP = \
#$(PKG)/$(BLD)/libsomelib \
#
EXEDEP = \

#
# Executable depend dirs
#
#EXEDEP_DIRS = \
#../libsomelib
#
EXEDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#

