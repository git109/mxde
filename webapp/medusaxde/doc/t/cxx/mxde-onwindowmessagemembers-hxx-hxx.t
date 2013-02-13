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
%#   File: mxde-onwindowmessagemembers-hxx-hxx.t
%#
%# Author: $author$
%#   Date: 12/11/2011
%########################################################################
%with(%
%class_member_funcs_interface_ifdefs,%(%else-no(%class_member_funcs_interface_ifdefs%,%(%class_member_funcs_interface_ifdefs%)%)%)%,%
%class_member_funcs_implement_ifdefs,%(%else-no(%class_member_funcs_implement_ifdefs%,%(%class_member_funcs_implement_ifdefs%)%)%)%,%
%window_messages_file,%(%else-then(%win_messages_file%,%(../../xml/win-messages.txt)%)%)%,%
%window_messages,%(%else-then(%window_messages%,%(%parse(%import(%filepath%/%window_messages_file%)%,%(
)%,,;)%)%)%)%,%
%on_window_messages,%(%else-then(%on_window_messages%,%(%else-then(%parameters(on_window_message,,;)%,%(%window_messages%)%)%)%)%)%,%
%On_,%(%else-then(%On_%,%(On_)%)%)%,%
%_WindowMessage,%(%else-then(%_WindowMessage%,%(_WindowMessage)%)%)%,%
%OnWindowMessageDefault,%(%else(%equal(0,%OnWindowMessageDefault%)%,%(%OnWindowMessageDefault%)%)%)%,%
%DefWindowProc,%(%else(%equal(DefWindowProc,%OnWindowMessageDefault%)%,%(DefWindowProc)%)%)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%CLASS,%(%FILE_MODULE%%CLASS%)%,%
%%(%
%%if(%class%,%(%
%
%_#if_% %_defined_%%(()%%CLASS%_MEMBERS_CLASS%())%
%
%%parse(%Class_namespace%,;,,,,%(%
%%kk_%namespace%_kk% %Class_namespace% {
%
%)%,Class_namespace)%%
%%with(indent,%(%_indent%)%,%(%
%%if(%class_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)%  Class: %Class%
%do(%left_separator%)%
%do(%left_separator%)% Author: %author%
%do(%left_separator%)%   Date: %date%
%do(%end_separator%)%%
%)%)%%
%)%)%%
%%_indent%%_class_% %Class%
%_indent%{
%_indent%%_public_%:
%_#endif_% %cc_%%left_comment% defined%(()%%CLASS%_MEMBERS_CLASS%())% %right_comment%%_cc%
%
%
%
%)%)%%
%%parse(%on_window_messages%,;,,,,%(%
%%if(%What%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %On_%%What%%_WindowMessage%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% LRESULT %On_%%What%%_WindowMessage%
%indent%(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#if_% %_defined_%(%CLASS%_MEMBER_FUNCS_INTERFACE)
%indent%= 0;
%_#else_% %cc_%%left_comment% %CLASS%_MEMBER_FUNCS_INTERFACE %right_comment%%_cc%
%
%)%)%%
%%indent%{
%
%%if(%on_windowmessage_body%,%(%
%%do(%on_windowmessage_body%)%%
%)%,%(%
%%indent%    LRESULT lResult = 0;
%if(%OnWindowMessageDefault%,%(%
%%indent%    lResult = %OnWindowMessageDefault%(hWnd,msg,wParam,lParam);
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% lResult;
%
%)%)%%
%%indent%}
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#endif_% %cc_%%left_comment% defined(%CLASS%_MEMBER_FUNCS_INTERFACE) %right_comment%%_cc%
%
%)%)%%
%)%)%%
%)%,What)%%
%%if(%on_window_message_default%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %OnWindowMessageDefault%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% LRESULT %OnWindowMessageDefault%
%indent%(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#if_% %_defined_%(%CLASS%_MEMBER_FUNCS_INTERFACE)
%indent%= 0;
%_#else_% %cc_%%left_comment% %CLASS%_MEMBER_FUNCS_INTERFACE %right_comment%%_cc%
%
%)%)%%
%%indent%{
%
%%if(%on_windowmessage_body%,%(%
%%do(%on_windowmessage_body%)%%
%)%,%(%
%%indent%    LRESULT lResult = 0;
%if(%DefWindowProc%,%(%
%%indent%    %cc_%%left_comment%lResult = %DefWindowProc%(hWnd,msg,wParam,lParam);%right_comment%%_cc%
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% lResult;
%
%)%)%%
%%indent%}
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#endif_% %cc_%%left_comment% defined(%CLASS%_MEMBER_FUNCS_INTERFACE) %right_comment%%_cc%
%
%)%)%%
%)%)%%
%%if(%class%,%(%
%
%_#if_% %_defined_%%(()%%CLASS%_MEMBERS_CLASS%())%
%_indent%};
%
%%reverse-parse(%Class_namespace%,;,,,,%(%
%} %cc_%%left_comment% namespace %Class_namespace% %right_comment%%_cc%
%
%)%,Class_namespace)%%
%%_#endif_% %cc_%%left_comment% defined%(()%%CLASS%_MEMBERS_CLASS%())% %right_comment%%_cc%
%
%
%)%)%%
%)%)%