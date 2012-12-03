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
%#   File: mxde-cxx-class.t
%#
%# Author: $author$           
%#   Date: 12/31/2010
%########################################################################
%apply-x(%
%class_and_file,%(%if(%file%,%(%class%)%)%)%,%
%Full_class_name,%(%Class_prefix%%Class%%Class_suffix%%Template_class_suffix%)%,%
%%(%
%%if(%class%,%(%
%%if(%class_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)%  Class: %Full_class_name%
%do(%left_separator%)%
%do(%left_separator%)% Author: %author%
%do(%left_separator%)%   Date: %date%
%do(%end_separator%)%%
%)%)%%
%)%)%%
%%if(%class_and_file%,%(%
%%if(%class_instance_test%,%(%
%%_#if_% %_defined_%(%CLASS_CLASS%_INSTANCE_TEST)
%Class_Class% g_%Class_Class%;
%_#endif_% %cc_%%left_comment% defined(%CLASS_CLASS%_INSTANCE_TEST) %right_comment%%_cc%
%
%)%)%%
%)%)%%
%%if(%class_constructor%,%(%
%%if(%class_constructor_proto%,%(%
%%include(%filepath%/mxde-cxx-class-constructor.t)%%
%)%)%%
%)%)%%
%%if(%class_destructor%,%(%
%%if(%class_destructor_proto%,%(%
%%include(%filepath%/mxde-cxx-class-destructor.t)%%
%)%)%%
%)%)%%
%%if(%class_function%,%(%
%%if(%class_function_prototype%,%(%
%%else(%class_function_abstract%,%(%
%%parse(%Class_function_name%,;,,,,%(%
%%if(%equal(doundo,%class_function_pattern%)%%equal(createdestroy,%class_function_pattern%)%,%(%
%%if(%class_function_Do%,%(%
%%with(%
%Class_function_name,%(%Class_function_prefix%%class_function_Do%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%
%%if(%class_function_Undo%,%(%
%%with(%
%class_function_return,%(%class_function_undo_return%)%,%
%class_function_parameters,%(%class_function_undo_parameters%)%,%
%Class_function_name,%(%Class_function_prefix%%class_function_Undo%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%
%)%)%%
%%if(%equal(setget,%class_function_pattern%)%,%(%
%%if(%class_function_Do%,%(%
%%with(%
%Class_function_name,%(%Class_function_prefix%%class_function_Do%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%
%%if(%class_function_Undo%,%(%
%%with(%
%class_function_const,%(%class_function_get_const%)%,%
%class_function_return,%(%class_function_undo_return%)%,%
%class_function_parameters,%(%class_function_undo_parameters%)%,%
%Class_function_name,%(%Class_function_prefix%%class_function_Undo%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%
%)%)%%
%%else(%class_function_pattern%,%
%%(%
%%with(%
%Class_function_name,%(%Class_function_prefix%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%
%)%,Class_function_name)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%