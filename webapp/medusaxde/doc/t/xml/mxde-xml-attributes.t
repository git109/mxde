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
%#   File: mxde-xml-attributes.t
%#
%# Author: $author$           
%#   Date: 4/25/2011
%########################################################################
%with(%
%%(%
%%parse(%xml_attr%,;,%(%else(%xml_attr_inline%,%(
%indent%)%)% )%,,,%(%
%%with(%
%xml_attr_name,%(%else-then(%left(%xml_attr%,=)%,%(%xml_attr%)%)%)%,%
%xml_attr_value,%(%else-then(%right(%xml_attr%,=)%,%(%xml_attr_value%)%)%)%,%
%%(%
%%xml_attr_name%=%ss_%"%do(%xml_attr_value%)%"%_ss%%
%)%)%%
%)%,xml_attr)%%
%)%)%