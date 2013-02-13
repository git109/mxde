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
%#   File: mxde-cxx-class-function-pattern.t
%#
%# Author: $author$
%#   Date: 2/25/2012
%########################################################################
%with(%
%%(%

%%if(%equal(doundo,%class_function_pattern%)%%equal(createdestroy,%class_function_pattern%)%,%(%

%%if(%class_function_Do%,%(%
%%with(%
%Class_function_return,%()%,%
%CLASS_FUNCTION_RETURN,%()%,%
%class_function_return,%(%class_function_do_return%)%,%
%class_function_parameters,%(%class_function_do_parameters%)%,%
%Class_function_name,%(%Class_function_prefix%%class_function_Do%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%

%%if(%class_function_Undo%,%(%
%%with(%
%Class_function_return,%()%,%
%CLASS_FUNCTION_RETURN,%()%,%
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
%Class_function_return,%()%,%
%CLASS_FUNCTION_RETURN,%()%,%
%class_function_return,%(%class_function_do_return%)%,%
%class_function_parameters,%(%class_function_do_parameters%)%,%
%Class_function_name,%(%Class_function_prefix%%class_function_Do%%Class_function_name%%Class_function_suffix%)%,%
%%(%
%%include(%filepath%/mxde-cxx-class-function.t)%%
%)%)%%
%)%)%%

%%if(%class_function_Undo%,%(%
%%with(%
%Class_function_return,%()%,%
%CLASS_FUNCTION_RETURN,%()%,%
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

%)%)%