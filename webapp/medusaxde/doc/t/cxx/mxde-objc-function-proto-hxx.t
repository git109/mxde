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
%#   File: mxde-objc-function-proto-hxx.t
%#
%# Author: $author$
%#   Date: 12/12/2012
%########################################################################
%with(%
%%(%
%%else-no(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %f_name%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%f_type%%f_return%%f_name%%
%%if(%Class_function_parameters%,%(%
%%with(%
%first_parameter,%(yes)%,%
%parameters,%(%else-then(%left(%Class_function_parameters%,;)%,%(%Class_function_parameters%)%)%)%,%
%%(%
%%if(%parameters%,%(:)%)%%
%%include(%filepath%/mxde-objc-parameters-hxx.t)%%
%)%)%%
%%with(%
%parameters,%(%right-of-left(%Class_function_parameters%,;)%)%,%
%%(%
%%if(%parameters%,%( )%)%%
%%include(%filepath%/mxde-objc-parameters-hxx.t)%%
%)%)%%
%)%)%%
%)%)%