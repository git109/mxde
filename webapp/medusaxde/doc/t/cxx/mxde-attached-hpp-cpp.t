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
%#   File: mxde-attached-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 4/23/2012
%########################################################################
%with(%
%this_includefile,%(%else-then(%this_includefile%,%(mxde-attached-hpp-cpp.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-hxx-cxx.t)%%
%)%,%(%
%%with(%
%What,%(%else-then(%What%,%(%else-then(%Derives%,%(AttachedT)%)%)%)%)%,%
%TUnattached,%(%else-then(%TUnattached%,%(int)%)%)%,%
%VUnattached,%(%else-then(%VUnattached%,%(0)%)%)%,%
%Attached,%(%else-then(%Class%,%(%Class_prefix%%What%Attached)%)%)%,%
%AttachedExtends,%(%else-then(%Extends%,%(%Class_prefix%ExportBase)%)%)%,%
%AttachedImplements,%(%else-then(%Implements%,%(%Class_prefix%InterfaceBase)%)%)%,%
%TAttached,%(%else-then(%TAttached%,%(%else-then(%What%,%($attached$)%)%)%)%)%,%
%CreatedAttached,%(%else-then(%Class%,%(%Class_prefix%%What%CreatedAttached)%)%)%,%
%OpenedAttached,%(%else-then(%Class%,%(%Class_prefix%%What%OpenedAttached)%)%)%,%
%%(%
%%else(%file_cxx%%file_cpp%,%(%
%
%_#include_% %ii_%"%Class_prefix%CreatedAttached.hpp"%_ii%
%_#include_% %ii_%"%Class_prefix%OpenedAttached.hpp"%_ii%

%else(%Class_namespace%,%(%
%%kk_%#if%_kk% %class_namespace_ifdef%
%kk_%namespace%_kk% %Class_namespace_define% {
%kk_%#endif%_kk% %class_namespace_ifdef_cc%%
%)%,%(%
%%parse(%Class_namespace%,;,,,,%(%
%%kk_%namespace%_kk% %Class_namespace% {
%
%)%,Class_namespace)%%
%)%)%

%do(%begin_separator%)%%
%%do(%left_separator%)% Typedef: %Attached%Implement
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_typedef_% %Class_prefix%AttachedInterfaceT
%lt%%TAttached%, %TUnattached%, %VUnattached%, %AttachedImplements%%gt%
%Attached%Implement;
%do(%begin_separator%)%%
%%do(%left_separator%)% Typedef: %Attached%Extend
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_typedef_% %Class_prefix%AttachedT
%lt%%TAttached%, %TUnattached%, %VUnattached%, 
 %Attached%Implement, %AttachedExtends%%gt%
%Attached%Extend;
%do(%begin_separator%)%%
%%do(%left_separator%)%  Class: %Attached%
%do(%left_separator%)%
%do(%left_separator%)% Author: %author%
%do(%left_separator%)%   Date: %date%
%do(%end_separator%)%%
%%_class_% %INSTANCE_CLASS%%Attached%
: %_virtual_% %_public_% %Attached%Implement,
  %_public_% %Attached%Extend
{
%_public_%:
    %_typedef_% %Attached%Implement %c_%Implements;
    %_typedef_% %Attached%Extend %c_%Extends;

%apply(indent,%indent_%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Constructor: %Attached%
%do(%left_separator%)%
%do(%left_separator%)%      Author: %author%
%do(%left_separator%)%        Date: %date%
%do(%end_separator%)%)%)%%
%    %Attached%
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : %c_%Extends(attached) 
    {
    }
};

%do(%begin_separator%)%%
%%do(%left_separator%)% Typedef: %CreatedAttached%Implement
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_typedef_% %Class_prefix%CreatedAttachedInterfaceT
%lt%%TAttached%, %TUnattached%, %VUnattached%, %Attached%Implement%gt%
%CreatedAttached%Implement;
%do(%begin_separator%)%%
%%do(%left_separator%)% Typedef: %CreatedAttached%Extend
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_typedef_% %Class_prefix%CreatedAttachedT
%lt%%TAttached%, %TUnattached%, %VUnattached%, 
 %CreatedAttached%Implement, %Attached%%gt%
%CreatedAttached%Extend;
%do(%begin_separator%)%%
%%do(%left_separator%)%  Class: %CreatedAttached%
%do(%left_separator%)%
%do(%left_separator%)% Author: %author%
%do(%left_separator%)%   Date: %date%
%do(%end_separator%)%%
%%_class_% %INSTANCE_CLASS%%CreatedAttached%
: %_virtual_% %_public_% %CreatedAttached%Implement,
  %_public_% %CreatedAttached%Extend
{
%_public_%:
    %_typedef_% %CreatedAttached%Implement %c_%Implements;
    %_typedef_% %CreatedAttached%Extend %c_%Extends;

%apply(indent,%indent_%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Constructor: %CreatedAttached%
%do(%left_separator%)%
%do(%left_separator%)%      Author: %author%
%do(%left_separator%)%        Date: %date%
%do(%end_separator%)%)%)%%
%    %CreatedAttached%
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : %c_%Extends(attached, isCreated) 
    {
    }
};

%do(%begin_separator%)%%
%%do(%left_separator%)% Typedef: %OpenedAttached%Implement
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_typedef_% %Class_prefix%OpenedAttachedInterfaceT
%lt%%TAttached%, %TUnattached%, %VUnattached%, %Attached%Implement%gt%
%OpenedAttached%Implement;
%do(%begin_separator%)%%
%%do(%left_separator%)% Typedef: %OpenedAttached%Extend
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_typedef_% %Class_prefix%OpenedAttachedT
%lt%%TAttached%, %TUnattached%, %VUnattached%, 
 %OpenedAttached%Implement, %Attached%%gt%
%OpenedAttached%Extend;
%do(%begin_separator%)%%
%%do(%left_separator%)%  Class: %OpenedAttached%
%do(%left_separator%)%
%do(%left_separator%)% Author: %author%
%do(%left_separator%)%   Date: %date%
%do(%end_separator%)%%
%%_class_% %INSTANCE_CLASS%%OpenedAttached%
: %_virtual_% %_public_% %OpenedAttached%Implement,
  %_public_% %OpenedAttached%Extend
{
%_public_%:
    %_typedef_% %OpenedAttached%Implement %c_%Implements;
    %_typedef_% %OpenedAttached%Extend %c_%Extends;

%apply(indent,%indent_%,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Constructor: %OpenedAttached%
%do(%left_separator%)%
%do(%left_separator%)%      Author: %author%
%do(%left_separator%)%        Date: %date%
%do(%end_separator%)%)%)%%
%    %OpenedAttached%
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : %c_%Extends(attached, isOpen) 
    {
    }
};

%else(%Class_namespace%,%(%
%%kk_%#if%_kk% %class_namespace_ifdef%
}
%kk_%#endif%_kk% %class_namespace_ifdef_cc%%
%)%,%(%
%%parse(%Class_namespace%,;,,,,%(%
%} %cc_%%left_comment% namespace %Class_namespace% %right_comment%%_cc%
%
%)%,Class_namespace)%%
%)%)%

%
%)%,%(%
%
%else(%Class_namespace%,%(%
%%kk_%#if%_kk% %class_namespace_ifdef%
%kk_%namespace%_kk% %Class_namespace_define% {
%kk_%#endif%_kk% %class_namespace_ifdef_cc%%
%)%,%(%
%%parse(%Class_namespace%,;,,,,%(%
%%kk_%namespace%_kk% %Class_namespace% {
%
%)%,Class_namespace)%%
%)%)%

%else(%Class_namespace%,%(%
%%kk_%#if%_kk% %class_namespace_ifdef%
}
%kk_%#endif%_kk% %class_namespace_ifdef_cc%%
%)%,%(%
%%parse(%Class_namespace%,;,,,,%(%
%} %cc_%%left_comment% namespace %Class_namespace% %right_comment%%_cc%
%
%)%,Class_namespace)%%
%)%)%
%
%)%)%%
%)%)%%
%)%)%%
%)%)%