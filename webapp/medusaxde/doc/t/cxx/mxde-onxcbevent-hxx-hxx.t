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
%#   File: mxde-onxcbevent-hxx-hxx.t
%#
%# Author: $author$
%#   Date: 3/18/2013
%########################################################################
%with(%
%class_member_funcs_interface_ifdefs,%(%else-no(%class_member_funcs_interface_ifdefs%,%(%class_member_funcs_interface_ifdefs%)%)%)%,%
%class_member_funcs_implement_ifdefs,%(%else-no(%class_member_funcs_implement_ifdefs%,%(%class_member_funcs_implement_ifdefs%)%)%)%,%
%xevents,%(%else-then(%xevents%,%(%parse(%import(%filepath%/../../xml/xcb-events.txt)%,%(
)%,,;)%)%)%)%,%
%on_xevents,%(%else-then(%on_xevents%,%(%else-then(%parameters(on_xevent,,;)%,%(%xevents%)%)%)%)%)%,%
%OnWindowMessageDefault,%(%else(%equal(0,%OnWindowMessageDefault%)%,%(%OnWindowMessageDefault%)%)%)%,%
%OnEventDefault,%(%else-then(%OnEventDefault%,%(%if(%OnWindowMessageDefault%,%(OnEventDefault)%)%)%)%)%,%
%DefaultEventHandler,%(%else-then(%DefaultEventHandler%,%(DefaultEventHandler)%)%)%,%
%OnEventDefault,%(%else(%equal(0,%OnEventDefault%)%,%(%OnEventDefault%)%)%)%,%
%DefaultEventHandler,%(%else(%equal(%DefaultEventHandler%,%OnEventDefault%)%,%(%DefaultEventHandler%)%)%)%,%
%OnEvent,%(%else-then(%OnEvent%,%(OnEvent)%)%)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%%(%
%%parse(%on_xevents%,;,,,,%(%
%%if(%What%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: On_XCB_%toupper(%What%)%_Event
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%%kk_%bool%_kk% On_XCB_%toupper(%What%)%_Event(%_const_% xcb_generic_event_t& xcbEvent) %
%%if(%class_member_funcs_interface_ifdefs%,%(
%
%%_#if_% %_defined_%(%CLASS%_MEMBER_FUNCS_INTERFACE)
%indent%= 0;
%_#else_% %cc_%%left_comment% %CLASS%_MEMBER_FUNCS_INTERFACE %right_comment%%_cc%
%
%%indent%)%)%%
%{
%
%%if(%on_windowmessage_body%,%(%
%%do(%on_windowmessage_body%)%%
%)%,%(%
%%indent%    %e_%%Class_prefix%%kk_%bool%_kk% isDone = %kk_%false%_kk%;
%if(%OnEventDefault%,%(%
%%indent%    isDone = %OnEventDefault%(xcbEvent);
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% isDone;
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
%%if(%on_xevent_default%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %OnEventDefault%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%%kk_%bool%_kk% %OnEventDefault%(%_const_% xcb_generic_event_t& xcbEvent) %
%%if(%class_member_funcs_interface_ifdefs%,%(%
%
%_#if_% %_defined_%(%CLASS%_MEMBER_FUNCS_INTERFACE)
%indent%= 0;
%_#else_% %cc_%%left_comment% %CLASS%_MEMBER_FUNCS_INTERFACE %right_comment%%_cc%
%
%)%)%%
%%indent%{
%
%%if(%on_windowmessage_body%,%(%
%%do(%on_windowmessage_body%)%%
%)%,%(%
%%indent%    %e_%%Class_prefix%%kk_%bool%_kk% isDone = %kk_%false%_kk%;
%if(%DefaultEventHandler%,%(%
%%indent%    %cc_%%left_comment%isDone = %DefaultEventHandler%(xcbEvent);%right_comment%%_cc%
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% isDone;
%
%)%)%%
%%indent%}
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#endif_% %cc_%%left_comment% defined(%CLASS%_MEMBER_FUNCS_INTERFACE) %right_comment%%_cc%
%
%)%)%%
%)%)%%
%%if(%on_xevent_function%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %OnEvent%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%%kk_%bool%_kk% %OnEvent%(%_const_% xcb_generic_event_t& xcbEvent) 
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
%%indent%    %e_%%Class_prefix%%kk_%bool%_kk% isDone = %kk_%false%_kk%;
%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%
%)%)%%
%%indent%    %_switch_%(xcbEvent.type)
%indent%    {
%indent%    %_default_%:
%indent%    isDone = %OnEventDefault%(xcbEvent);
%indent%    }
%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%if(%DefaultEventHandler%,%(%
%%indent%    %cc_%%left_comment%isDone = %DefaultEventHandler%(xcbEvent);%right_comment%%_cc%
)%)%%
%%indent%    %_return_% isDone;
%
%)%)%%
%%indent%}
%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#endif_% %cc_%%left_comment% defined(%CLASS%_MEMBER_FUNCS_INTERFACE) %right_comment%%_cc%
%
%)%)%%
%)%)%%
%)%)%