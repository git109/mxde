%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: mxde-objc-function-body-cxx.t
%#
%# Author: $author$
%#   Date: 1/31/2014
%########################################################################
%with(%
%%(%
% {
%with(%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%%(%
%%else(%equal(void,%f_return_type%)%,%(%
%%else(%equal(self,%f_return_name%)%,%(%
%%if(%f_return_type%%f_return_name%,%(%
%%indent%%
%%if-then(%f_return_type%,%( )%)%%
%%if-then(%f_return_name%,%(%
%%then-if(%f_return_value%,%( = )%)%%
%)%)%%
%;
%
%)%)%%
%)%)%%
%)%)%%
%%parse(%Class_function_statement%,;,,,%(%
%%indent%%do(%s%)%;
%
%)%,s)%%
%%else(%equal(void,%f_return_type%)%,%(%
%%if(%f_return_type%%f_return_name%,%(%
%%indent%%
%%then-if(%f_return_name%,%(%_return_% )%)%%
%;
%
%)%)%%
%)%)%%
%)%)%%
%%indent%}%
%)%)%