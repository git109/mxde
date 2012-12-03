%########################################################################
%# Copyright (c) 1988-2010 $organization$  
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
%#   File: mxde-httpd-conf-action.t
%#
%# Author: $author$     
%#   Date: 7/27/2010
%########################################################################
%with(%
%action_type,%(%else-then(%left(%action%,:)%,%(%action%)%)%)%,%
%action_target,%(%else-then(%right(%action%,:)%,%()%)%)%,%
%action_types,%(%else-then(%parse(%action_type%,%(,)%,,%( )%)%,%(%action_type%)%)%)%,%
%%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Action %action_types% %do(%right_separator%)%%
%%do(%end_separator%)%%
%%parse(%action_type%,%(,)%,,,,%(%
%%kk_%Action%_kk% %action_type% %action_target%%exe%
%
%)%,action_type)%%
%)%)%