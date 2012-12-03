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
%#   File: mxde-onxevent-hxx-cxx.t
%#
%# Author: $author$
%#   Date: 4/29/2012
%########################################################################
%with(%
%class_member_funcs_interface_ifdefs,%(%else-no(%class_member_funcs_interface_ifdefs%,%(%class_member_funcs_interface_ifdefs%)%)%)%,%
%class_member_funcs_implement_ifdefs,%(%else-no(%class_member_funcs_implement_ifdefs%,%(%class_member_funcs_implement_ifdefs%)%)%)%,%
%xevents,%(%else-then(%xevents%,%(%parse(%import(%filepath%/../../xml/x11-events.txt)%,%(
)%,,;)%)%)%)%,%
%on_xevents,%(%else-then(%on_xevents%,%(%else-then(%parameters(on_xevent,,;)%,%(%xevents%)%)%)%)%)%,%
%OnWindowMessageDefault,%(%else(%equal(0,%OnWindowMessageDefault%)%,%(%OnWindowMessageDefault%)%)%)%,%
%OnXEventDefault,%(%else-then(%OnXEventDefault%,%(%if(%OnWindowMessageDefault%,%(OnXEventDefault)%)%)%)%)%,%
%DefaultXEventHandler,%(%else-then(%DefaultXEventHandler%,%(DefaultXEventHandler)%)%)%,%
%OnXEventDefault,%(%else(%equal(0,%OnXEventDefault%)%,%(%OnXEventDefault%)%)%)%,%
%DefaultXEventHandler,%(%else(%equal(%DefaultXEventHandler%,%OnXEventDefault%)%,%(%DefaultXEventHandler%)%)%)%,%
%OnXEvent,%(%else-then(%OnXEvent%,%(OnXEvent)%)%)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%%(%
%%parse(%on_xevents%,;,,,,%(%
%%if(%What%,%(%
%%if(%class_function_comment%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Function: On%What%XEvent
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%Error On%What%XEvent(%_const_% XEvent& xEvent) 
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
%%indent%    %e_%%Class_prefix%Error error = %e_%%CLASS_PREFIX%_ERROR_NONE;
%if(%OnXEventDefault%,%(%
%%indent%    error = %OnXEventDefault%(xEvent);
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% error;
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
%%do(%left_separator%)% Function: %OnXEventDefault%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%Error %OnXEventDefault%(%_const_% XEvent& xEvent) 
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
%%indent%    %e_%%Class_prefix%Error error = %e_%%CLASS_PREFIX%_ERROR_NONE;
%if(%DefaultXEventHandler%,%(%
%%indent%    %cc_%%left_comment%error = %DefaultXEventHandler%(xEvent);%right_comment%%_cc%
)%)%%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%indent%    %_return_% error;
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
%%do(%left_separator%)% Function: %OnXEvent%
%do(%left_separator%)%
%do(%left_separator%)%   Author: %author%
%do(%left_separator%)%     Date: %date%
%do(%end_separator%)%%
%)%)%%
%%indent%%_virtual_% %e_%%Class_prefix%Error %OnXEvent%(%_const_% XEvent& xEvent) 
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
%%indent%    %e_%%Class_prefix%Error error = %e_%%CLASS_PREFIX%_ERROR_NONE;
%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#if_% !%_defined_%(%CLASS%_MEMBER_FUNCS_IMPLEMENT) 
%
%)%)%%
%%indent%    %_switch_%(xEvent.type)
%indent%    {
%indent%    %_default_%:
%indent%    error = %OnXEventDefault%(xEvent);
%indent%    }
%
%%if(%class_member_funcs_implement_ifdefs%,%(%
%%_#else_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%_#endif_% %cc_%%left_comment% !defined(%CLASS%_MEMBER_FUNCS_IMPLEMENT) %right_comment%%_cc%
%
%)%)%%
%%if(%DefaultXEventHandler%,%(%
%%indent%    %cc_%%left_comment%error = %DefaultXEventHandler%(xEvent);%right_comment%%_cc%
)%)%%
%%indent%    %_return_% error;
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