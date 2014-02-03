%########################################################################
%# Copyright (c) 1988-2011 $organization$  
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
%#   File: mxde-hxx-class-function.t
%#
%# Author: $author$           
%#   Date: 1/1/2011
%########################################################################
%with(%
%class_function_return,%(%else-then(%class_function_return%,%()%)%)%,%
%Class_function_return,%(%else-then(%Class_function_return%,%(%class_function_return%)%)%)%,%
%CLASS_FUNCTION_RETURN,%(%else-then(%CLASS_FUNCTION_RETURN%,%(%toupper(%Class_function_return%)%)%)%)%,%
%class_function_return,%(%else-then(%_Class_function_return%,%(%tolower(%Class_function_return%)%)%)%)%,%
%class_function_return_type_name,%(%else-then(%class_function_return_type_name%,%(%else-then(%lrft(%Class_function_return%,=)%,%(%Class_function_return%)%)%)%)%)%,%
%Class_function_return_type_name,%(%else-then(%Class_function_return_type_name%,%(%class_function_return_type_name%)%)%)%,%
%CLASS_FUNCTION_RETURN_TYPE_NAME,%(%else-then(%CLASS_FUNCTION_RETURN_TYPE_NAME%,%(%toupper(%Class_function_return_type_name%)%)%)%)%,%
%class_function_return_type_name,%(%else-then(%_Class_function_return_type_name%,%(%tolower(%Class_function_return_type_name%)%)%)%)%,%
%class_function_return_type,%(%else-then(%class_function_return_type%,%(%else-then(%left-of-right(%Class_function_return_type_name%, )%,%(%Class_function_return_type_name%)%)%)%)%)%,%
%Class_function_return_type,%(%else-then(%Class_function_return_type%,%(%class_function_return_type%)%)%)%,%
%CLASS_FUNCTION_RETURN_TYPE,%(%else-then(%CLASS_FUNCTION_RETURN_TYPE%,%(%toupper(%Class_function_return_type%)%)%)%)%,%
%class_function_return_type,%(%else-then(%_Class_function_return_type%,%(%tolower(%Class_function_return_type%)%)%)%)%,%
%class_function_return_name_value,%(%else-then(%class_function_return_name_value%,%(%else-then(%right(%Class_function_return%, )%,%()%)%)%)%)%,%
%Class_function_return_name_value,%(%else-then(%Class_function_return_name_value%,%(%class_function_return_name_value%)%)%)%,%
%CLASS_FUNCTION_RETURN_NAME_VALUE,%(%else-then(%CLASS_FUNCTION_RETURN_NAME_VALUE%,%(%toupper(%Class_function_return_name_value%)%)%)%)%,%
%class_function_return_name_value,%(%else-then(%_Class_function_return_name_value%,%(%tolower(%Class_function_return_name_value%)%)%)%)%,%
%class_function_return_name,%(%else-then(%class_function_return_name%,%(%else-then(%left(%Class_function_return_name_value%,=)%,%(%Class_function_return_name_value%)%)%)%)%)%,%
%Class_function_return_name,%(%else-then(%Class_function_return_name%,%(%class_function_return_name%)%)%)%,%
%CLASS_FUNCTION_RETURN_NAME,%(%else-then(%CLASS_FUNCTION_RETURN_NAME%,%(%toupper(%Class_function_return_name%)%)%)%)%,%
%class_function_return_name,%(%else-then(%_Class_function_return_name%,%(%tolower(%Class_function_return_name%)%)%)%)%,%
%class_function_return_value,%(%else-then(%class_function_return_value%,%(%right(%Class_function_return_name_value%,=)%)%)%)%,%
%Class_function_return_value,%(%else-then(%Class_function_return_value%,%(%class_function_return_value%)%)%)%,%
%CLASS_FUNCTION_RETURN_VALUE,%(%else-then(%CLASS_FUNCTION_RETURN_VALUE%,%(%toupper(%Class_function_return_value%)%)%)%)%,%
%class_function_return_value,%(%else-then(%_Class_function_return_value%,%(%tolower(%Class_function_return_value%)%)%)%)%,%
%%(%
%%if(%class_member_funcs_implement_ifndefs%,%(%
%%if(%class_function_static%,%(%
%%kk_%#if%_kk% %class_member_funcs_implement_ifndef%
%
%)%,%(%
%)%)%%
%)%)%%
%%if(%class_function_comment%,%(%
%%include(%filepath%/mxde-%if-then(%style%,%(-)%)%hxx-class-function-comment.t)%%
%)%)%%
%%indent%%class_function_type%%if-then(%do(%Class_function_return_type%)%, )%%Class_function_name%%
%%if(%class_function_parameters%,%(
%indent%)%)%%
%%(()%%
%%if(%class_function_parameters%,%(%
%%parse(%class_function_parameters%,;,,%(,
%indent% )%,,%(%do(%p%)%)%,p)%%
%)%)%%
%%())%%
%%if(%class_function_const%,%( %_const_%)%)%%
%%if(%class_function_prototype%%class_function_abstract%,%(%
%%if(%class_function_abstract%,%( = 0)%)%;
%
%)%,%(%
%%else(%is_kr_indent%,%(
)%)%%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%kk_%#if%_kk% %class_member_funcs_interface_ifdef%
%indent%%if(%class_function_static%,%(;
)%,%(= 0;
)%)%%
%%kk_%#else%_kk% %class_member_funcs_interface_ifdef_cc%
%
%)%)%%
%%else(%is_kr_indent%,%(%indent%)%,%( )%)%{
%if(%Class_function_return_name%,%(%indent%%indent_%%do(%Class_function_return_type%)% %do(%Class_function_return_name%)%%then-if(%do(%Class_function_return_value%)%, = )%;
)%)%%
%%if(%class_member_funcs_implement_ifndefs%,%(%
%%if(%class_function_static%,%(%
%)%,%(%
%%kk_%#if%_kk% %class_member_funcs_implement_ifndef%
%kk_%#else%_kk% %class_member_funcs_implement_ifndef_cc%
%kk_%#endif%_kk% %class_member_funcs_implement_ifndef_cc%
%
%)%)%%
%)%)%%
%%if(%Class_function_return_name%,%(%indent%%indent_%%kk_%return%_kk% %do(%Class_function_return_name%)%;
)%)%%
%%indent%}
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%kk_%#endif%_kk% %class_member_funcs_interface_ifdef_cc%
%
%%if(%class_function_static%,%(%
%)%,%(%
%
%
%)%)%%
%)%)%%
%)%)%%
%%if(%class_member_funcs_implement_ifndefs%,%(%
%%if(%class_function_static%,%(%
%%kk_%#else%_kk% %class_member_funcs_implement_ifndef_cc%
%kk_%#endif%_kk% %class_member_funcs_implement_ifndef_cc%
%
%
%
%)%,%(%
%)%)%%
%)%)%%
%)%)%