%########################################################################
%# Copyright (c) 1988-2010 $organization$  
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
%#   File: mxde-httpd-conf.t
%#
%# Author: $author$     
%#   Date: 7/27/2010
%########################################################################
%with(%
%thisfile,%(%else-then(%thisfile%,%(mxde-httpd-conf.t)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath%/..)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/%thisfile%)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/mxde-source-html.t)%%
%)%,%(%
%%
%%with(%
%left_comment,%(#)%,%
%right_comment,%()%,%
%middle_comment,%(#)%,%
%begin_comment,%(%cc_%%left_comment%)%,%
%end_comment,%(%right_comment%%_cc%)%,%
%separator_middle,%(########################################################################)%,%
%separator_padd,%(%length(%separator_middle%)%)%,%
%separator,%(%left_comment%%separator_middle%%right_comment%)%,%
%begin_separator,%(%%indent%%%cc_%%separator%
)%,%
%end_separator,%(%%indent%%%separator%%_cc%
)%,%
%left_separator,%(%%indent%%%left_comment%)%,%
%right_separator,%(%right_comment%
)%,%
%xfile,%(%else-then(%file%,%(httpd-local.conf)%)%)%,%
%%(%
%%if(%file%,%(%
%%parse(%file%,;,,,,%(%
%%with(%
%file_base,%(%filebase(%file%)%)%,%
%file_extension,%(%fileextension(%file%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%%(%
%%include(%filepath%/mxde-httpd-conf-file.t)%%
%)%)%%
%)%,file)%%
%)%,%(%
%%include(%filepath%/mxde-httpd-conf-file.t)%%
%)%)%%
%)%)%%
%%
%)%)%%
%)%)%