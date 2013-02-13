%########################################################################
%# Copyright (c) 1988-2009 $organization$     
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
%#   File: mxde-xml.t
%#
%# Author: $author$           
%#   Date: 10/1/2009
%########################################################################
%with(%
%processor_color,%(%else-then(%processor_color%,%(purple)%)%)%,%
%keyword_color,%(%else-then(%keyword_color%,%(teal)%)%)%,%
%keywordx_color,%(%else-then(%keywordx_color%,%(blue)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath%/..)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/mxde-xml.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/mxde-source-html.t)%%
%)%,%(%
%%with(%
%indent_,%(    )%,%
%left_processor,%(%lt%?)%,%
%right_processor,%(?%gt%)%,%
%begin_processor,%(%pp_%%left_processor%)%,%
%end_processor,%(%right_processor%%_pp%)%,%
%left_comment,%(%lt%!--)%,%
%right_comment,%(--%gt%)%,%
%middle_comment,%(----)%,%
%first_comment,%(%%indent%%%cc_%%lt%!--
)%,%
%last_comment,%(%%indent%%----%gt%%_cc%
)%,%
%begin_comment,%(%cc_%%left_comment%)%,%
%end_comment,%(%right_comment%%_cc%)%,%
%separator_extra,%(%include(%filepath%/%organization%-separator-extra.t)%)%,%
%separator_middle,%(========================================================================%separator_extra%)%,%
%separator_padd,%(%length(%separator_middle%)%)%,%
%separator,%(%left_comment%%separator_middle%%right_comment%)%,%
%begin_separator,%(%%indent%%%cc_%%separator%
)%,%
%end_separator,%(%%indent%%%separator%%_cc%
)%,%
%left_separator,%(%%indent%%%left_comment%)%,%
%right_separator,%(%right_comment%
)%,%
%section_separator,%(%(%do(%%indent%%%cc_%%left_comment%%%separator_middle%%%right_comment%%_cc%
)%)%)%,%
%section,%(%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)%%padd( , ,%separator_padd%)%%do(%right_separator%)%%
%%do(%left_separator%)%%padd( %section_name%, ,%separator_padd%)%%do(%right_separator%)%%
%%do(%left_separator%)%%padd( , ,%separator_padd%)%%do(%right_separator%)%%
%%do(%end_separator%)%)%)%,%
%xml_version,%(%else-then(%xml_version%,%(1.0)%)%)%,%
%xml_encoding,%(%else(%equal(no,%xml_encoding%)%,%(%xml_encoding%)%)%)%,%
%xml_stylesheet,%(%else(%equal(no,%xml_stylesheet%)%,%(%xml_stylesheet%)%)%)%,%
%xml_doctype_type,%(%else(%equal(no,%xml_doctype_type%)%,%(%xml_doctype_type%)%)%)%,%
%xml_entity_type,%(%else(%equal(no,%xml_entity_type%)%,%(%xml_entity_type%)%)%)%,%
%xml_document,%(%else-then(%xml_document%,%(document)%)%)%,%
%xml_document_ns,%(%else-then(%xml_document_ns%,%()%)%)%,%
%xml_document_ns_list,%(%else-then(%xml_document_ns%,%()%)%)%,%
%xml_document_ns,%(%else-then(%left(%xml_document_ns%,;)%,%(%xml_document_ns%)%)%)%,%
%xml_document_ns_uri,%(%else-then(%xml_document_ns_uri%,%()%)%)%,%
%xml_document_ns_is_uri,%(%else-then(%xml_document_ns_is_uri%,%()%)%)%,%
%xml_document_ns_prefix,%(%else(%xml_document_ns_is_uri%,%(%if-then(%xml_document_ns%,%(:)%)%)%)%)%,%
%xml_document_attr,%(%else-then(%xml_document_attr%,%()%)%)%,%
%xml_document_attr_value,%(%else-then(%xml_document_attr_value%,%()%)%)%,%
%xml_element,%(%else-then(%xml_element%,%()%)%)%,%
%file_type,%(%else-then(%file_type%,%(xml)%)%)%,%
%file_type_extension,%(%else-then(%file_type_extension%,%(%file_type%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension(%file%)%)%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%dot_file_extension,%(%then-if(%else-then(%file_extension%,%(%file_type_extension%)%)%,%(.)%)%)%,%
%derived_fileinclude,%(%derived_includefile%)%,%
%derived_includefile,%()%,%
%%(%
%%if(%file%,%(%
%%parse(%file%,;,,,,%(%
%%with(%
%file_base,%(%filebase(%file%)%)%,%
%file_extension,%(%fileextension(%file%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%%(%
%%include(%filepath%/mxde-xml-document.t)%%
%)%)%%
%)%,file)%%
%)%,%(%
%%include(%filepath%/mxde-xml-document.t)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%