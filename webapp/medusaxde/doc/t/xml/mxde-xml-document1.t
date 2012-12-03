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
%#   File: mxde-xml-document.t
%#
%# Author: $author$           
%#   Date: 10/1/2009
%########################################################################
%with(%
%%(%
%%if(%file%,%(%
%%include(%filepath%/mxde-xml-file.t)%%
%%include(%filepath%/mxde-xml-doctype.t)%%
%)%,%(%
%)%)%%
%%if(%derived_fileinclude%,%(%
%%include(%derived_fileinclude%)%%
%)%,%(%
%%include(%filepath%/mxde-xml-document-begin.t)%%
%%with(%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%%(%
%%include(%filepath%/mxde-xml-elements.t)%%
%%include(%filepath%/mxde-xml-document-end.t)%%
%)%)%%
%)%)%
