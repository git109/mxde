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
%#   File: medusaxde-menu-item.t
%#
%# Author: $author$           
%#   Date: 4/24/2011
%########################################################################
%with(%
%this_filepath,%(%else-then(%this_filepath%,%(%filepath(%input%)%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%filepath(%input%)%)%/xml)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%this_filepath%/medusaxde-menu-item.t)%)%)%,%
%xml_element,%(menu-item)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-xml.t)%%
%)%,%(%
%%parse(%id%,;,,,,%(%
%%if(%equal(yes,%is_separator%)%,%(%
%%with(%
%xml_element_attr,%(is_separator=yes)%,%
%xml_element_attr_inline,%(yes)%,%
%xml_element_element_inline,%(yes)%,%
%xml_element_element,%()%,%
%xml_element_element_text,%()%,%
%%(%
%%include(%filepath%/mxde-xml-element.t)%%
%)%)%%
%)%,%(%
%%with(%
%xml_element_attr,%(id=%id%;is_location_query_and=%is_location_query_and%;is_location_query_and_for=%is_location_query_and_for%;is_location_query_and_using=%is_location_query_and%;location_path=%location_path%;location_query=%location_query%;location=%location%)%,%
%xml_element_element_inline,%(yes)%,%
%xml_element_element,%(text)%,%
%xml_element_element_text,%(%text%)%,%
%%(%
%%include(%filepath%/mxde-xml-element.t)%%
%)%)%%
%)%)%%
%)%,id)%%
%)%)%%
%)%)%
