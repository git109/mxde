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
%#   File: mxde-xml-doctype.t
%#
%# Author: $author$           
%#   Date: 10/1/2009
%########################################################################
%with(%
%%(%
%%parse(%xml_doctype%,;,,,,%(%
%%with(%
%doctype,%(%xml_doctype%)%,%
%%(%
%%lt%%kk_%!DOCTYPE%_kk% %xml_doctype% %
%%if(%xml_doctype_type%,%(%
%)%,%(%
%[%
%%if-then(%
%%parse(%xml_entity%,;,%(
%indent_%)%,,,%(%
%%with(%
%entity,%(%left(%xml_entity%,:)%)%,%
%entity_type,%(%xml_entity_type%)%,%
%entity_value,%(%else-then(%right(%xml_entity%,:)%,%(%xml_entity_value%)%)%)%,%
%name,%(%entity%)%,%
%type,%(%entity_type%)%,%
%value,%(%entity_value%)%,%
%%(%
%%lt%%kk_%!ENTITY%_kk% %entity% %if(%entity_type%,%(%
%%kk_%%entity_type%%_kk% %ii_%"%do(%entity_value%)%"%_ii%%
%)%,%(%
%)%)%%gt%%
%)%)%%
%)%,xml_entity)%%
%,%(
)%)%%
%)%)%]%gt%
%
%)%)%%
%)%,xml_doctype)%%
%)%)%