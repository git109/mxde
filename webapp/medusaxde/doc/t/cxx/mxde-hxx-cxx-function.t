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
%#   File: mxde-hxx-cxx-function.t
%#
%# Author: $author$
%#   Date: 10/17/2011
%########################################################################
%with(%
%Function_type,%(%else-then(%Function_type%,%(%function_type%)%)%)%,%
%FUNCTION_TYPE,%(%else-then(%FUNCTION_TYPE%,%(%toupper(%Function_type%)%)%)%)%,%
%function_type,%(%else-then(%_Function_type%,%(%tolower(%Function_type%)%)%)%)%,%
%Function_name,%(%else-then(%Function_name%,%(%function_name%)%)%)%,%
%FUNCTION_NAME,%(%else-then(%FUNCTION_NAME%,%(%toupper(%Function_name%)%)%)%)%,%
%function_name,%(%else-then(%_Function_name%,%(%tolower(%Function_name%)%)%)%)%,%
%Function_return,%(%else-then(%Function_return%,%(%function_return%)%)%)%,%
%FUNCTION_RETURN,%(%else-then(%FUNCTION_RETURN%,%(%toupper(%Function_return%)%)%)%)%,%
%function_return,%(%else-then(%_Function_return%,%(%tolower(%Function_return%)%)%)%)%,%
%Function_param,%(%else-then(%Function_param%,%(%function_param%)%)%)%,%
%FUNCTION_PARAM,%(%else-then(%FUNCTION_PARAM%,%(%toupper(%Function_param%)%)%)%)%,%
%function_param,%(%else-then(%_Function_param%,%(%tolower(%Function_param%)%)%)%)%,%
%Function_body,%(%else-then(%Function_body%,%(%function_body%)%)%)%,%
%FUNCTION_BODY,%(%else-then(%FUNCTION_BODY%,%(%toupper(%Function_body%)%)%)%)%,%
%function_body,%(%else-then(%_Function_body%,%(%tolower(%Function_body%)%)%)%)%,%
%function_return_type_name,%(%else-then(%class_function_return_type_name%,%(%else-then(%left(%Function_return%,=)%,%(%Function_return%)%)%)%)%)%,%
%Function_return_type_name,%(%else-then(%Function_return_type_name%,%(%function_return_type_name%)%)%)%,%
%FUNCTION_RETURN_TYPE_NAME,%(%else-then(%FUNCTION_RETURN_TYPE_NAME%,%(%toupper(%Function_return_type_name%)%)%)%)%,%
%function_return_type_name,%(%else-then(%_Function_return_type_name%,%(%tolower(%Function_return_type_name%)%)%)%)%,%
%function_return_type,%(%else-then(%function_return_type%,%(%else-then(%left-of-right(%Function_return_type_name%, )%,%(%Function_return_type_name%)%)%)%)%)%,%
%Function_return_type,%(%else-then(%Function_return_type%,%(%function_return_type%)%)%)%,%
%FUNCTION_RETURN_TYPE,%(%else-then(%FUNCTION_RETURN_TYPE%,%(%toupper(%Function_return_type%)%)%)%)%,%
%function_return_type,%(%else-then(%_Function_return_type%,%(%tolower(%Function_return_type%)%)%)%)%,%
%function_return_name_value,%(%else-then(%function_return_name_value%,%(%else-then(%right(%Function_return%, )%,%()%)%)%)%)%,%
%Function_return_name_value,%(%else-then(%Function_return_name_value%,%(%function_return_name_value%)%)%)%,%
%FUNCTION_RETURN_NAME_VALUE,%(%else-then(%FUNCTION_RETURN_NAME_VALUE%,%(%toupper(%Function_return_name_value%)%)%)%)%,%
%function_return_name_value,%(%else-then(%_Function_return_name_value%,%(%tolower(%Function_return_name_value%)%)%)%)%,%
%function_return_name,%(%else-then(%function_return_name%,%(%else-then(%left(%Function_return_name_value%,=)%,%(%Function_return_name_value%)%)%)%)%)%,%
%Function_return_name,%(%else-then(%Function_return_name%,%(%function_return_name%)%)%)%,%
%FUNCTION_RETURN_NAME,%(%else-then(%FUNCTION_RETURN_NAME%,%(%toupper(%Function_return_name%)%)%)%)%,%
%function_return_name,%(%else-then(%_Function_return_name%,%(%tolower(%Function_return_name%)%)%)%)%,%
%function_return_value,%(%else-then(%function_return_value%,%(%right(%Function_return_name_value%,=)%)%)%)%,%
%Function_return_value,%(%else-then(%Function_return_value%,%(%function_return_value%)%)%)%,%
%FUNCTION_RETURN_VALUE,%(%else-then(%FUNCTION_RETURN_VALUE%,%(%toupper(%Function_return_value%)%)%)%)%,%
%function_return_value,%(%else-then(%_Function_return_value%,%(%tolower(%Function_return_value%)%)%)%)%,%
%%(%
%%parse(%Function_name%,;,,,,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)%  Function: %Function_name%
%do(%left_separator%)%
%do(%left_separator%)%    Author: %author%
%do(%left_separator%)%      Date: %date%
%do(%end_separator%)%%
%%indent%%if-then(%Function_return_type%, )%%if-then(%Function_type%, )%%Function_name%%
%%if(%Function_param%,%(
%indent%)%)%%
%%(()%%
%%if(%Function_param%,%(%
%%parse(%Function_param%,;,,%(,
%indent% )%,,%(%
%%parse(%Function_param%,%(,)%,,%(,
%indent% )%,,%(%
%%else-then(%left(%p%,=)%,%(%p%)%)%%
%)%,p)%%
%)%,Function_param)%%
%)%)%%
%%())%%
%%if(%file_h%%file_hxx%,%(%
%;
%
%)%,%(%
%
%indent%{
%
%%if(%Function_return_name%,%(%indent%%indent_%%Function_return_type% %Function_return_name%%then-if(%Function_return_value%, = )%;
)%)%%
%%if(%Function_return_name%,%(%indent%%indent_%%kk_%return%_kk% %Function_return_name%;
)%)%%
%%indent%}
%
%)%)%%
%)%,Function_name)%%
%)%)%