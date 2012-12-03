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
%#   File: medusaxde-menu.t
%#
%# Author: $author$           
%#   Date: 5/7/2011
%########################################################################
%with(%
%this_file,%(%else-then(%this_file%,%(medusaxde-menu.t)%)%)%,%
%this_filepath,%(%else-then(%this_filepath%,%(%filepath(%input%)%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%filepath(%input%)%)%/xml)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%this_filepath%/%this_file%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%with(%
%xml_document,%(menu)%,%
%xml_document_ns,%(%
%%if(%file%,%(medusaxde;mxde;xde)%)%%
%)%,%
%xml_document_ns_uri,%(%
%%if(%file%,%(Medusa-Xos-Development-Environment)%)%%
%)%,%
%%(%
%%include(%filepath%/mxde-xml.t)%%
%)%)%%
%)%,%(%
%%parse(%id%,;,,,,%(%
%%with(%
%xml_document_attr,%(%
%%if(%file%,%(xmlns=%xml_document_ns_uri%;)%)%%
%id=%id%%
%)%,%
%%(%
%%if(%file%,%(%
%%include(%filepath%/mxde-xml-document-begin.t)%%
%%include(%filepath%/mxde-xml-document-end.t)%%
%)%,%(%
%)%)%%
%)%)%%
%)%,id)%%
%)%)%%
%)%)%