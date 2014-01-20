%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: restapi-objects-to-application-restapi.t
%#
%# Author: $author$
%#   Date: 1/8/2014
%########################################################################
%with(%
%document,%(%else-then(%document%,%(application)%)%)%,%
%Application,%(%else-then(%Application%,%(Application)%)%)%,%
%Namespace,%(%else-then(%Namespace%,%(RestApp)%)%)%,%
%xmlns_prefix,%(%else-then(%xmlns_prefix%,%(rapi)%)%)%,%
%xmlns_uri,%(%else-then(%xmlns_uri%,%(RestApplicationProgramInterface)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(.restapi)%)%)%,%
%object,%(%include(%filepath(%input%)%/%tolower(%Application%)%/%Application%-objects.t)%)%,%
%padd_length,%(%length(========================================================================)%)%,%
%%(%
%<?xml version="1.0" encoding="utf-8"?>
<!--========================================================================-->
<!--%padd( Copyright (c) 1988-%year()% $organization$, ,%padd_length%)%-->
<!--                                                                        -->
<!-- This software is provided by the author and contributors ``as is''     -->
<!-- and any express or implied warranties, including, but not limited to,  -->
<!-- the implied warranties of merchantability and fitness for a particular -->
<!-- purpose are disclaimed. In no event shall the author or contributors   -->
<!-- be liable for any direct, indirect, incidental, special, exemplary,    -->
<!-- or consequential damages (including, but not limited to, procurement   -->
<!-- of substitute goods or services; loss of use, data, or profits; or     -->
<!-- business interruption) however caused and on any theory of liability,  -->
<!-- whether in contract, strict liability, or tort (including negligence   -->
<!-- or otherwise) arising in any way out of the use of this software,      -->
<!-- even if advised of the possibility of such damage.                     -->
<!--                                                                        -->
<!--%padd(   File: %Application%%file_extension%, ,%padd_length%)%-->
<!--                                                                        -->
<!--%padd( Author: $author$, ,%padd_length%)%-->
<!--%padd(   Date: %date()%, ,%padd_length%)%-->
<!--========================================================================-->
<!DOCTYPE %document% [
%parse(%object%,%(
)%,,,,%(%
%%with(object,%(%tolower(%Object%)%)%,%(
    <!ENTITY %object%
      SYSTEM "%object%/%Object%%file_extension%">
)%)%%
%)%,Object)%
]>
<%document%
 name="%Application%"
 namespace="%Namespace%"
 xmlns:%xmlns_prefix%="%xmlns_uri%"
 xmlns="%xmlns_uri%">
%parse(%object%,%(
)%,,,,%(%
%%with(object,%(%tolower(%Object%)%)%,%(
    &%object%;
)%)%%
%)%,Object)%
</%document%>
%
%)%)%