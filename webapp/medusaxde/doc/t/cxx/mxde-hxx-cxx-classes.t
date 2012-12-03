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
%#   File: mxde-hxx-cxx-classes.t
%#
%# Author: $author$           
%#   Date: 12/31/2010
%########################################################################
%apply-x(%
%%(%
%%else(%left(%Class%,;)%,%(%
%%include(%filepath%/mxde-%file_type%-class.t)%%
%)%,%(%
%%parse(%Class%,;,,,,%(%
%%apply-x(%
%class,%(%tolower(%Class%)%)%,%
%CLASS,%(%toupper(%Class%)%)%,%
%Class_Class,%(%else-then(%Class_Class%,%(%Class_prefix%%Class%%Class_suffix%%Template_class_suffix%)%)%)%,%
%CLASS_CLASS,%(%else-then(%CLASS_CLASS%,%(%toupper(%Class_Class%)%)%)%)%,%
%class_class,%(%else-then(%_Class_Class%,%(%tolower(%Class_Class%)%)%)%)%,%
%Class_members_only,%(%Class_prefix%%Class%%Class_suffix%_members_only)%,%
%CLASS_MEMBERS_ONLY,%(%toupper(%Class_members_only%)%)%,%
%class_members_only,%(%tolower(%Class_members_only%)%)%,%
%Class_member_funcs_interface,%(%Class_prefix%%Class%%Class_suffix%_member_funcs_interface)%,%
%CLASS_MEMBER_FUNCS_INTERFACE,%(%toupper(%Class_member_funcs_interface%)%)%,%
%class_member_funcs_interface,%(%tolower(%Class_member_funcs_interface%)%)%,%
%Class_member_funcs_implement,%(%Class_prefix%%Class%%Class_suffix%_member_funcs_implement)%,%
%CLASS_MEMBER_FUNCS_IMPLEMENT,%(%toupper(%Class_member_funcs_implement%)%)%,%
%class_member_funcs_implement,%(%tolower(%Class_member_funcs_implement%)%)%,%
%%(%
%%include(%filepath%/mxde-%file_type%-class.t)%%
%)%)%%
%)%,Class)%%
%)%)%%
%)%)%