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
%#   File: mxde-events-xml.t
%#
%# Author: $author$
%#   Date: 2/23/2014
%########################################################################
%with(%
%thisfile,%(mxde-events-xml.t)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%thisfile%)%)%)%,%
%event,%(%else-then(%event%,%(event)%)%)%,%
%event_importfile,%(%else-then(%event_importfile%,%(../../xml/%event%s.txt)%)%)%,%
%xml_document,%(%else-then(%xml_document%,%(%event%s)%)%)%,%
%xml_element,%(%else-then(%xml_element%,%(%event%)%)%)%,%
%xml_element_attr,%(%else-then(%xml_element_attr%,%(id)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-xml.t)%%
%)%,%(%
%%lt%%xml_document_ns_prefix%%xml_document%%
%%parse(%xml_document_ns_list%,;,,,,%(%
%%then-if(%if-then(%xml_document_ns%,%(="%xml_document_ns_uri%")%)%,%(
 xmlns:)%)%%
%)%,xml_document_ns)%%
%%gt%
%
%%apply-x(%
%indent,%(%indent%%indent_%)%,%
%%(%
%%parse(%import(%filepath%/%event_importfile%)%,%(
)%,,,,%(%
%%if(%xml_element_attr_value%,%(%
%%include(%filepath%/mxde-xml-element.t)%%
%)%)%%
%)%,xml_element_attr_value)%%
%)%)%%
%%lt%/%xml_document_ns_prefix%%xml_document%%gt%
%
%)%)%%
%)%)%