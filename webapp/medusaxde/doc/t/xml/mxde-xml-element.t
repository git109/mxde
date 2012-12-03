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
%#   File: mxde-xml-element.t
%#
%# Author: $author$           
%#   Date: 4/24/2011
%########################################################################
%with(%
%xml_element_text,%(%else-then(%xml_element_text%,%(%do(%right(%xml_element%,=)%)%)%)%)%,%
%xml_element,%(%else-then(%left(%xml_element%,=)%,%(%xml_element%)%)%)%,%
%%(%
%%else(%xml_element_no_section%,%(%
%%with(section_name,%(%xml_element%)%,%(%
%%do(%section%)%%
%)%)%%
%)%)%%
%%indent%%lt%%xml_element_ns_prefix%%xml_element%%
%%then-if(%if-then(%xml_element_ns%,%(="%xml_element_ns_uri%")%)%,%(
%indent% xmlns:)%)%%
%%with(%
%xml_attr,%(%xml_element_attr%)%,%
%xml_attr_value,%(%xml_element_attr_value%)%,%
%xml_attr_inline,%(%else-then(%xml_element_attr_inline%,%(%xml_element_inline%)%)%)%,%
%%(%
%%include(%filepath%/mxde-xml-attributes.t)%%
%)%)%%
%%gt%%
%%else(%xml_element_inline%,%(
%indent%)%)%%
%%if(%xml_element_text%,%(%
%%else(%xml_element_inline%,%(%indent_%)%)%%
%%xml_element_text%%
%%else(%xml_element_inline%,%(
%indent%)%)%%
%)%)%%
%%if(%xml_element_element%,%(%
%%with(%
%indent,%(%indent%%indent_%)%,%
%%(%
%%indent%%lt%%xml_element_element_ns_prefix%%xml_element_element%%
%%with(%
%xml_attr,%(%xml_element_element_attr%)%,%
%xml_attr_value,%(%xml_element_element_attr_value%)%,%
%xml_attr_inline,%(%else-then(%xml_element_element_attr_inline%,%(xml_element_element_inline)%)%)%,%
%%(%
%%include(%filepath%/mxde-xml-attributes.t)%%
%)%)%%
%%gt%%
%%else(%xml_element_element_inline%,%(
%indent%)%)%%
%%xml_element_element_text%%
%%lt%/%xml_element_element_ns_prefix%%xml_element_element%%gt%
%
%)%)%%
%)%)%%
%%lt%/%xml_element_ns_prefix%%xml_element%%gt%
%
%)%)%