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
%#   File: mxde-onwindowmessagecases-hxx-hxx.t
%#
%# Author: $author$
%#   Date: 12/11/2011
%########################################################################
%with(%
%On_,%(%else-then(%On_%,%(On_)%)%)%,%
%_WindowMessage,%(%else-then(%_WindowMessage%,%(_WindowMessage)%)%)%,%
%OnWindowMessageDefault,%(%else-then(%OnWindowMessageDefault%,%(OnWindowMessageDefault)%)%)%,%
%window_messages_file,%(%else-then(%win_messages_file%,%(../../xml/win-messages.txt)%)%)%,%
%window_messages,%(%else-then(%window_messages%,%(%parse(%import(%filepath%/%window_messages_file%)%,%(
)%,,;)%)%)%)%,%
%on_window_messages,%(%else-then(%on_window_messages%,%(%else-then(%parameters(on_window_message,,;)%,%(%window_messages%)%)%)%)%)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%%indent_%)%,%
%CLASS,%(%FILE_MODULE%%CLASS%)%,%
%%(%
%
%_#if_% %_defined_%%(()%%CLASS%_MEMBER_CASES_SWITCH%())%
%indent%%_switch_%(msg)
%indent%{
%_#endif_% %cc_%%left_comment% defined%(()%%CLASS%_MEMBER_CASES_SWITCH%())% %right_comment%%_cc%
%
%%parse(%on_window_messages%,;,,,,%(%
%%if(%What%,%(%
%
%indent%   %_case_% %What%:
%indent%        lResult = %On_%%What%%_WindowMessage%
%indent%        (hWnd, msg, wParam, lParam);
%indent%        %_break_%;
%
%)%)%%
%)%,What)%%
%%if(%on_window_message_default%,%(%
%
%indent%   %_default_%:
%indent%        lResult = %OnWindowMessageDefault%
%indent%        (hWnd, msg, wParam, lParam);
%indent%        %_break_%;
%
%)%)%%
%
%_#if_% %_defined_%%(()%%CLASS%_MEMBER_CASES_SWITCH%())%
%indent%}
%_#endif_% %cc_%%left_comment% defined%(()%%CLASS%_MEMBER_CASES_SWITCH%())% %right_comment%%_cc%

%
%)%)%