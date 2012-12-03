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
%#   File: mxde-xml-document-begin.t
%#
%# Author: $author$           
%#   Date: 4/25/2011
%########################################################################
%with(%
%%(%
%%lt%%xml_document_ns_prefix%%xml_document%%
%%parse(%xml_document_ns_list%,;,,,,%(%
%%then-if(%if-then(%xml_document_ns%,%(=%ss_%"%xml_document_ns_uri%"%_ss%)%)%,%(
 xmlns:)%)%%
%)%,xml_document_ns)%%
%%then-if(%if(%xml_document_ns_is_uri%,%(%ss_%"%xml_document_ns_is_uri%"%_ss%)%)%,%(
 xmlns=)%)%%
%%with(%
%xml_attr,%(%xml_document_attr%)%,%
%xml_attr_value,%(%xml_document_attr_value%)%,%
%%(%
%%include(%filepath%/mxde-xml-attributes.t)%%
%)%)%%
%%gt%
%)%)%