%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: mxde-meta-makefile.t
%#
%# Author: $author$
%#   Date: 12/8/2014
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%%(%
%%else(%makefile_rules%,%(%
%%with(makefile_rules,%(mxde-meta-makefile.t)%,%(%
%%include(%filepath%/mxde-project-makefile.t)%%
%)%)%%
%)%,%(%
%PKG = %Pkg%

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
%parse(%exe_dirs%,;,,,,%($(PKG)/$(PRJ)/%d% \
)%,d)%
include $(PKG)/$(PRJ)/Makedirs
%
%)%)%%
%)%)%