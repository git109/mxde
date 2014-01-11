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
%#   File: mxde-objc-main-cxx.t
%#
%# Author: $author$
%#   Date: 12/13/2012
%########################################################################
%with(%
%%(%
%%if(1,%(%
%%else(%no_before_separator_lf%,%(
)%)%%
%%else-no(%function_main%,%(%
%%else-no(%function_main_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: main
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%_int_% main%(()%%_int_% argc, %_char_%** argv, %_char_%** env%())% {
%with(indent,%(%indent%%indent_%)%,%(%
%%indent%%_int_% err = 0;
%indent%%_return_% err;
%
%)%)%}
%
%)%)%%
%)%)%%
%)%)%