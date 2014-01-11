%########################################################################
%# Copyright (c) 1988-$year$ $organization$
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
%#   File: mxde-onxevent-members-hxx-hxx.t
%#
%# Author: $author$
%#   Date: $date$
%########################################################################
%with(%
%class_function_comment,%()%,%
%class_member_funcs_interface_ifdefs,%(%else-no(%class_member_funcs_interface_ifdefs%,%(%class_member_funcs_interface_ifdefs%)%)%)%,%
%class_member_funcs_implement_ifdefs,%(%else-no(%class_member_funcs_implement_ifdefs%,%(%class_member_funcs_implement_ifdefs%)%)%)%,%
%xevents_file,%(%else-then(%win_messages_file%,%(../../xml/x11-events.txt)%)%)%,%
%xevents,%(%else-then(%xevents%,%(%parse(%import(%filepath%/%xevents_file%)%,%(
)%,,;)%)%)%)%,%
%on_xevents,%(%else-then(%on_xevents%,%(%else-then(%parameters(on_xevent,,;)%,%(%xevents%)%)%)%)%)%,%
%On_,%(%else-then(%On_%,%(On)%)%)%,%
%_XEvent,%(%else-then(%_XEvent%,%(XEvent)%)%)%,%
%DefaultXEventHandler,%(%else-then(%DefaultXEventHandler%,%(DefaultXEventHandler)%)%)%,%
%OnXEventDefault,%(%else(%equal(0,%OnXEventDefault%)%,%(%OnXEventDefault%)%)%)%,%
%DefaultXEventHandler,%(%else(%equal(%DefaultXEventHandler%,%OnXEventDefault%)%,%(%DefaultXEventHandler%)%)%)%,%
%OnXEvent,%(%else-then(%OnXEvent%,%(OnXEvent)%)%)%,%
%ONXEVENT,%(%else-then(%ONXEVENT%,%(%toupper(%OnXEvent%)%)%)%)%,%
%error_t,%(%else-then(%error_t%,%(%_bool_%)%)%)%,%
%Error_t,%(%else-then(%Error_t%,%(%error_t%)%)%)%,%
%ERROR_T,%(%else-then(%ERROR_T%,%(%toupper(%Error_t%)%)%)%)%,%
%error_t,%(%else-then(%_Error_t%,%(%tolower(%Error_t%)%)%)%)%,%
%error,%(%else-then(%error%,%(isHandled)%)%)%,%
%Error,%(%else-then(%Error%,%(%error%)%)%)%,%
%ERROR,%(%else-then(%ERROR%,%(%toupper(%Error%)%)%)%)%,%
%error,%(%else-then(%_Error%,%(%tolower(%Error%)%)%)%)%,%
%ERROR_NONE,%(%else-then(%ERROR_NONE%,%(%_false_%)%)%)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%%(%
%
%
%%parse(%on_xevents%,;,,,,%(%
%%if(%What%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %On_%%What%%_XEvent%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%%Error_t% %On_%%What%%_XEvent%(%_const_% XEvent& xEvent) %
%%if(%class_member_funcs_interface_ifdefs%,%(%
%
%_#if_% %_defined_%(%CLASS%_MEMBER_FUNCS_INTERFACE)
%indent%= 0;
%_#else_% %cc_%%left_comment% %CLASS%_MEMBER_FUNCS_INTERFACE %right_comment%%_cc%
%
%%indent%)%)%%
%%if(%class_function_abstract%,%(%
%= 0;
%
%)%,%(%
%{
%
%%if(%on_windowmessage_body%,%(%
%%do(%on_windowmessage_body%)%%
%)%,%(%
%%indent%    %e_%%Class_prefix%%Error_t% %Error% = %ERROR_NONE%;
%if(%m_delegated%,%(%
%%_#if_% %_defined_%(%CLASS%_MEMBERS_DELEGATED)
%indent%    %kk_%if%_kk% ((m_delegated))
%indent%         %Error% = m_delegated-%gt%%On_%%What%%_XEvent%(xEvent);
%indent%    %kk_%else%_kk%
%_#endif_% %cc_%%left_comment% defined(%CLASS%_MEMBERS_DELEGATED) %right_comment%%_cc%
%
%)%)%%
%%if(1%OnXEventDefault%,%(%
%%indent%    %Error% = %OnXEventDefault%(xEvent);
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% %Error%;
%
%)%)%%
%%indent%}
%
%)%)%%
%%if(%class_member_funcs_interface_ifdefs%,%(%
%%_#endif_% %cc_%%left_comment% defined(%CLASS%_MEMBER_FUNCS_INTERFACE) %right_comment%%_cc%
%
%)%)%%
%)%)%%
%)%,What)%%
%%if(%on_xevent_default%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: %OnXEventDefault%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%%Error_t% %OnXEventDefault%(%_const_% XEvent& xEvent) %
%%if(%class_member_funcs_interface_ifdefs%,%(%
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
%%indent%    %e_%%Class_prefix%%Error_t% %Error% = %ERROR_NONE%;
%if(%DefaultXEventHandler%,%(%
%%indent%    %Error% = %DefaultXEventHandler%(xEvent);
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% %Error%;
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

