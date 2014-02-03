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
%%include(%filepath%/mxde-%if-then(%style%,%(-)%)%objc-implementation-comment-cxx.t)%%
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
%%if(%Class_init%,%(%
%%with(%
%class_function_comment,%(%class_init_comment%)%,%
%Class_function_parameters,%(%class_init_parameters%)%,%
%Class_function_statement,%(%class_init_body%)%,%
%f_name,%(init)%,%
%f_type,%(%if-then(%pp_%%if(%equal(class,%Class_init%)%,%(+)%,%(-)%)%%_pp%,%( )%)%)%,%
%f_return_type,%(%else-then(%left(%Class_init_return%, )%,%(%else(%right(%Class_init_return%,=)%,%(%Class_init_return%)%)%)%)%)%,%
%f_return_name,%(%else-then(%left(%right-of-left(%Class_init_return%, )%,=)%,%(%right-of-left(%Class_init_return%, )%)%)%)%,%
%f_return_value,%(%right(%Class_init_return%,=)%)%,%
%f_return,%(%if(%f_return_type%,%(%(()%%do(%f_return_type%)%%())%)%)%)%,%
%%(%
%
%include(%filepath%/mxde-objc-function-proto-hxx.t)%%
%%include(%filepath%/mxde-objc-function-body-cxx.t)%%
%)%)%%
%)%)%%
%%if(%Class_dealloc%,%(%
%%with(%
%class_function_comment,%(%class_dealloc_comment%)%,%
%Class_function_parameters,%(%class_dealloc_parameters%)%,%
%Class_function_statement,%(%class_dealloc_body%)%,%
%f_name,%(dealloc)%,%
%f_type,%(%if-then(%pp_%%if(%equal(class,%Class_dealloc%)%,%(+)%,%(-)%)%%_pp%,%( )%)%)%,%
%f_return_type,%(%else-then(%left(%Class_dealloc_return%, )%,%(%else(%right(%Class_dealloc_return%,=)%,%(%Class_dealloc_return%)%)%)%)%)%,%
%f_return_name,%(%else-then(%left(%right-of-left(%Class_dealloc_return%, )%,=)%,%(%right-of-left(%Class_dealloc_return%, )%)%)%)%,%
%f_return_value,%(%right(%Class_dealloc_return%,=)%)%,%
%f_return,%(%if(%f_return_type%,%(%(()%%do(%f_return_type%)%%())%)%)%)%,%
%%(%
%
%include(%filepath%/mxde-objc-function-proto-hxx.t)%%
%%include(%filepath%/mxde-objc-function-body-cxx.t)%%
%)%)%%
%)%)%%
%%if(%Class_function%,%(%
%%parse(%Class_function_name%,;,%(
)%,,%(%
%%include(%filepath%/mxde-objc-function-proto-hxx.t)%%
%%include(%filepath%/mxde-objc-function-body-cxx.t)%%
%)%,f_name)%%
%)%)%%
%)%)%%
%
%_@end_%
%
%)%)%