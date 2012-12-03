%########################################################################
%# Copyright (c) 1988-2012 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: mxde-subdirs-makefile.t
%#
%# Author: $author$
%#   Date: 3/30/2012
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%this_includefile,%(%else-then(%this_includefile%,%(%filename(%input%)%)%)%)%,%
%this_includefile_base,%(%else-then(%this_includefile_base%,%(%filebase(%this_includefile%)%)%)%)%,%
%base_includefile,%(%filepath%/mxde-makefile.t)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%with(%
%platform,%(%else-then(%platform%,%(Linux)%)%)%,%
%Platform,%(%else-then(%Platform%,%(%platform%)%)%)%,%
%PLATFORM,%(%else-then(%PLATFORM%,%(%toupper(%Platform%)%)%)%)%,%
%platform,%(%else-then(%_Platform%,%(%tolower(%Platform%)%)%)%)%,%
%tools,%(%else-then(%tools%,%(Gcc)%)%)%,%
%Tools,%(%else-then(%Tools%,%(%tools%)%)%)%,%
%TOOLS,%(%else-then(%TOOLS%,%(%toupper(%Tools%)%)%)%)%,%
%tools,%(%else-then(%_Tools%,%(%tolower(%Tools%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Xde)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%project,%(%else-then(%project%,%(Project)%)%)%,%
%Project,%(%else-then(%Project%,%(%project%)%)%)%,%
%PROJECT,%(%else-then(%PROJECT%,%(%toupper(%Project%)%)%)%)%,%
%project,%(%else-then(%_Project%,%(%tolower(%Project%)%)%)%)%,%
%what,%(%else-then(%what%,%(Executable)%)%)%,%
%What,%(%else-then(%What%,%(%what%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_What%,%(%tolower(%What%)%)%)%)%,%
%for,%(%else-then(%for%,%(%Platform% %Tools% Makefile for %Framework% %Project% %What%)%)%)%,%
%For,%(%else-then(%For%,%(%for%)%)%)%,%
%FOR,%(%else-then(%FOR%,%(%toupper(%For%)%)%)%)%,%
%pkg,%(%else-then(%pkg%,%($(PWD)/../../../../../..)%)%)%,%
%Pkg,%(%else-then(%Pkg%,%(%pkg%)%)%)%,%
%PKG,%(%else-then(%PKG%,%(%toupper(%Pkg%)%)%)%)%,%
%pkg,%(%else-then(%_Pkg%,%(%tolower(%Pkg%)%)%)%)%,%
%prj,%(%else-then(%prj%,%(c/projects/linux/Makefile)%)%)%,%
%Prj,%(%else-then(%Prj%,%(%prj%)%)%)%,%
%PRJ,%(%else-then(%PRJ%,%(%toupper(%Prj%)%)%)%)%,%
%prj,%(%else-then(%_Prj%,%(%tolower(%Prj%)%)%)%)%,%
%src,%(%else-then(%src%,%(c/src)%)%)%,%
%Src,%(%else-then(%Src%,%(%src%)%)%)%,%
%SRC,%(%else-then(%SRC%,%(%toupper(%Src%)%)%)%)%,%
%src,%(%else-then(%_Src%,%(%tolower(%Src%)%)%)%)%,%
%%(%
%%include(%base_includefile%)%%
%)%)%%
%)%,%(%
%%with(%
%%(%
%
PKG = %Pkg%

PRJ = %Prj%
SRC = %Src%

include $(PKG)/$(PRJ)/Makedefines

%cc_%#
# Source subdirs
#
#SRC_DIRS = \
#$(PKG)/$(PRJ)/somedir \
#%_cc%
SRC_DIRS = \

include $(PKG)/$(PRJ)/Makedirs
%
%)%)%%
%)%)%%
%)%)%