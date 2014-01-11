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
%#   File: mxde-onxcbeventcases-hxx-cxx.t
%#
%# Author: $author$
%#   Date: 3/18/2013
%########################################################################
%with(%
%On_,%(%else-then(%On_%,%(On_)%)%)%,%
%_XEvent,%(%else-then(%_XEvent%,%(_Event)%)%)%,%
%OnXEventDefault,%(%else-then(%OnXEventDefault%,%(OnEventDefault)%)%)%,%
%xevents_file,%(%else-then(%win_messages_file%,%(../../xml/xcb-events.txt)%)%)%,%
%xevents,%(%else-then(%xevents%,%(%parse(%import(%filepath%/%xevents_file%)%,%(
)%,,;)%)%)%)%,%
%on_xevents,%(%else-then(%on_xevents%,%(%else-then(%parameters(on_xevent,,;)%,%(%xevents%)%)%)%)%)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%%indent_%)%,%
%%(%
%
%_#if_% %_defined_%%(()%%CLASS%_MEMBER_CASES_SWITCH%())%
%indent%%_switch_%(xcbEvent.response_type)
%indent%{
%_#endif_% %cc_%%left_comment% defined%(()%%CLASS%_MEMBER_CASES_SWITCH%())% %right_comment%%_cc%
%
%%parse(%on_xevents%,;,,,,%(%
%%if(%What%,%(%
%
%indent%   %_case_% XCB_%toupper(%What%)%:
%indent%        isDone = %On_%XCB_%toupper(%What%)%%_XEvent%(xcbEvent);
%indent%        %_break_%;
%
%)%)%%
%)%,What)%%
%%if(%on_xevent_default%,%(%
%
%indent%   %_default_%:
%indent%        isDone = %OnXEventDefault%(xcbEvent);
%indent%        %_break_%;
%
%)%)%%
%
%_#if_% %_defined_%%(()%%CLASS%_MEMBER_CASES_SWITCH%())%
%indent%}
%_#endif_% %cc_%%left_comment% defined%(()%%CLASS%_MEMBER_CASES_SWITCH%())% %right_comment%%_cc%

%
%)%)%      

