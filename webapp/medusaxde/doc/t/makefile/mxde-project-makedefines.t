%########################################################################
%# Copyright (c) 1988-2013 $organization$
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
%#   File: mxde-project-makedefines.t
%#
%# Author: $author$
%#   Date: 10/11/2013
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
%file_base,%(%else-then(%file_base%,%(Makedefines)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%target%)%)%)%,%
%file,%(%else-then(%file%,%(%file_base%%then-if(%file_extension%,%(.)%)%)%)%)%,%
%%(%
%%include(%base_includefile%)%%
%)%)%%
%)%,%(%
%%with(%
%%(%
%%include(%filepath%/%this_includefile_base%-rules.t)%%
%)%)%%
%)%)%%
%)%)%

