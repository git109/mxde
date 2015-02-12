%########################################################################
%# Copyright (c) 1988-2010 $organization$  
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
%#   File: mxde-hxx-cxx-file.t
%#
%# Author: $author$           
%#   Date: 3/15/2010
%########################################################################
%apply-x(%
%file,%(%if(%equal(tolower,%file_is_case%)%,%(%file%)%,%(%File%)%)%)%,%
%File,%(%if(%equal(tolower,%file_is_case%)%,%(%file%)%,%(%File%)%)%)%,%
%File_base,%(%if(%equal(tolower,%file_is_case%)%,%(%file_base%)%,%(%File_base%)%)%)%,%
%%(%
%%apply-x(%
%filepath,%(%filepath%/..)%,%
%%(%
%%include(%filepath%/mxde-%if-then(%style%,%(-)%)%file.t)%%
%)%)%%
%%if(%file_hxx%,%(%
%%include(%filepath%/mxde-%if-then(%style%,%(-)%)%hxx-file-ifdef-begin.t)%%
%%parse(%include_system%,;,,,,%(%
%%_#include_% %ii_%%lt%%do(%include%)%%gt%%_ii%
%
%)%,include)%%
%%parse(%include%,;,,,,%(%
%%_#include_% %ii_%"%do(%include%)%"%_ii%
%
%)%,include)%%
%%parse(%import_system%,;,,,,%(%
%%_#import_% %ii_%%lt%%import%%gt%%_ii%
%
%)%,import)%%
%%parse(%import%,;,,,,%(%
%%_#import_% %ii_%"%import%"%_ii%
%
%)%,import)%%
%)%)%%
%%if(%file_cxx%,%(%
%%if(%no_default_cxx_include%,%(%
%%parse(%include_system%,;,,,,%(%
%%_#include_% %ii_%%lt%%do(%include%)%%gt%%_ii%
%
%)%,include)%%
%%parse(%include%,;,,,,%(%
%%_#include_% %ii_%"%do(%include%)%"%_ii%
%
%)%,include)%%
%%parse(%import_system%,;,,,,%(%
%%_#import_% %ii_%%lt%%import%%gt%%_ii%
%
%)%,import)%%
%%parse(%import%,;,,,,%(%
%%_#import_% %ii_%"%import%"%_ii%
%
%)%,import)%%
%)%,%(%
%%_#include_% %ii_%"%File_base%.%file_hxx_extension%"%_ii%
%
%)%)%%
%)%)%%
%%parse(%Namespace%,;,,,,%(%
%%kk_%namespace%_kk% %Namespace% {
%
%)%,Namespace)%%
%%include(%derived_fileinclude%%hxx_cxx_fileinclude%)%%
%%reverse-parse(%Namespace%,;,,,,%(%
%} %cc_%%left_comment% namespace %Namespace% %right_comment%%_cc%
%
%)%,Namespace)%%
%%
%%if(%file_hxx%,%(%
%%include(%filepath%/mxde-%if-then(%style%,%(-)%)%hxx-file-ifdef-end.t)%%
%)%)%%
%%
%)%)%