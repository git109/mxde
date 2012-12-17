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
%#   File: mxde-objc-implementation-cxx.t
%#
%# Author: $author$
%#   Date: 12/13/2012
%########################################################################
%with(%
%%(%
%%else(%no_before_separator_lf%,%(
)%)%%
%%else-no(%class_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Implentation: %Class%
%do(%left_separator%)%
%do(%left_separator%)%       Author: %author%
%do(%left_separator%)%         Date: %date%
%do(%end_separator%)%%
%)%)%%
%%_@implementation_% %Class%%
%%with(%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%f_type,%(%if-then(%pp_%%if(%equal(class,%Class_function%)%,%(+)%,%(-)%)%%_pp%,%( )%)%)%,%
%f_return_type,%(%else-then(%left(%Class_function_return%, )%,%(%else(%right(%Class_function_return%,=)%,%(%Class_function_return%)%)%)%)%)%,%
%f_return_name,%(%else-then(%left(%right-of-left(%Class_function_return%, )%,=)%,%(%right-of-left(%Class_function_return%, )%)%)%)%,%
%f_return_value,%(%right(%Class_function_return%,=)%)%,%
%f_return,%(%if(%f_return_type%,%(%(()%%do(%f_return_type%)%%())%)%)%)%,%
%%(%
%%if(%Class_function%,%(%
%%parse(%Class_function_name%,;,%(
)%,,%(%
%%include(%filepath%/mxde-objc-function-proto-hxx.t)%%
% {
%with(%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%%(%
%%if(%f_return_type%%f_return_name%,%(%
%%indent%%
%%if-then(%f_return_type%,%( )%)%%
%%if-then(%f_return_name%,%(%
%%then-if(%f_return_value%,%( = )%)%%
%)%)%%
%;
%
%)%)%%
%%parse(%Class_function_statement%,;,,,%(%
%%indent%%do(%s%)%;
%
%)%,s)%%
%%if(%f_return_type%%f_return_name%,%(%
%%indent%%
%%then-if(%f_return_name%,%(%_return_% )%)%%
%;
%
%)%)%%
%)%)%%
%%indent%}%
%)%,f_name)%%
%)%)%%
%)%)%%
%
%_@end_%
%
%)%)%