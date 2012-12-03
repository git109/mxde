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
%#   File: mxde-hxx-cxx-object.t
%#
%# Author: $author$           
%#   Date: 3/15/2010
%########################################################################
%apply-x(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%hxx_cxx_includefile,%(%else(%derived_fileinclude%%hxx_cxx_fileinclude%,%(%filepath%/mxde-hxx-cxx-object.t)%)%)%,%
%%(%
%%
%%if(%hxx_cxx_includefile%,%(%
%%with(%
%not_object_class,%(%else-then(%not_object_class%,%(%else(%class_object%,%(yes)%)%)%)%)%,%
%object_class,%(%else(%not_object_class%,%(%object_class%)%,%(no)%)%)%,%
%%(%
%%include(%filepath%/mxde-hxx-cxx.t)%%
%)%)%%
%)%,%(%
%%with(%
%class_template_parameters,%(%if-then(%class_template_parameters%,;)%%parameters(class_template_parameters_item,,;)%)%,%
%%(%
%%if(%file_h%%file_hxx%,%(%
%%if(%ifdef%,%(%
%%include(%filepath%/mxde-cxx-ifdef.t)%%
%)%)%%
%%if(%ifndef%,%(%
%%include(%filepath%/mxde-cxx-ifndef.t)%%
%)%)%%
%)%)%%
%%if(%file_h%,%(%
%
%_#if_% %_defined_%(__cplusplus)
%_extern_% "C" {
%_#endif_% %cc_%%left_comment% defined(__cplusplus) %right_comment%%_cc%
%
%)%,%(%
%%else(%file_c%,%(%
%
%else(%Class_namespace%,%(%
%%kk_%#if%_kk% %class_namespace_ifdef%
%kk_%namespace%_kk% %Class_namespace_define% {
%kk_%#endif%_kk% %class_namespace_ifdef_cc%%
%)%,%(%
%%parse(%Class_namespace%,;,,,,%(%
%%kk_%namespace%_kk% %Class_namespace% {
%
%)%,Class_namespace)%%
%)%)%

%
%)%)%%
%)%)%%
%%if(%file_hxx%,%(%
%%include(%filepath%/mxde-cxx-typedefs.t)%%
%)%)%%
%%
%%if(%file_hxx%,%(%
%%include(%filepath%/mxde-cxx-enums.t)%%
%)%)%%
%%
%%if(%file%,%(%
%%if(%file_hxx%,%(%
%%if(%OBJECT_CLASSES%,%(%
%%kk_%#else%_kk% %file_class_members_ifndef_cc%
%kk_%#endif%_kk% %file_class_members_ifndef_cc%
%
%)%)%%
%)%)%%
%)%)%%
%%
%%if(%Class_name%,%(%
%%parse(%Class_name%,;,,,,%(%apply(%
%class_name,%tolower(%Class_name%)%,%
%CLASS_NAME,%toupper(%Class_name%)%,%
%%(%
%%include(%filepath%/mxde-%file_type%-class.t)%%
%)%)%)%,Class_name)%%
%)%,%(%
%%include(%filepath%/mxde-%file_type%-classes.t)%%
%)%)%%
%%
%%if(%file%,%(%
%%if(%file_hxx%,%(%
%%if(%OBJECT_CLASSES%,%(%
%
%kk_%#if%_kk% %file_class_members_ifndef%
%
%)%)%%
%)%)%%
%)%)%%
%%
%%if(%file_h%,%(%
%
%_#if_% %_defined_%(__cplusplus)
}
%_#endif_% %cc_%%left_comment% defined(__cplusplus) %right_comment%%_cc%

%
%)%,%(%
%%include(%filepath%/mxde-hxx-cxx-function.t)%%
%%else(%file_c%,%(%
%

%else(%Class_namespace%,%(%
%%kk_%#if%_kk% %class_namespace_ifdef%
}
%kk_%#endif%_kk% %class_namespace_ifdef_cc%%
%)%,%(%
%%reverse-parse(%Class_namespace%,;,,,,%(%
%} %cc_%%left_comment% namespace %Class_namespace% %right_comment%%_cc%
%
%)%,Class_namespace)%%
%)%)%

%
%)%)%%
%)%)%%
%%
%)%)%%
%)%)%%
%)%)%