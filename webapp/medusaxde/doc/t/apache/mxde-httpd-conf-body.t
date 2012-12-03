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
%#   File: mxde-httpd-conf-body.t
%#
%# Author: $author$     
%#   Date: 7/27/2010
%########################################################################
%with(%
%exe,%(%if(%equal(Windows,%os%)%,%(.exe)%)%)%,%
%xaliases,%(%else-then(%aliases%,%(/Alias/:/Dir)%)%)%,%
%xscript_aliases,%(%else-then(%script_aliases%,%(/ScriptAlias/:/Dir)%)%)%,%
%xadd_types,%(%else-then(%add_types%,%(application/x-httpd-xsl:.xsl)%)%)%,%
%xactions,%(%else-then(%actions%,%(application/x-httpd-xsl:xslcgi)%)%)%,%
%%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Aliases %do(%right_separator%)%%
%%do(%left_separator%)% ... %do(%right_separator%)%%
%%do(%end_separator%)%%
%%lt%%kk_%IfModule%_kk% mod_alias.c%gt%
%
%%parse(%aliases%,;,%(
)%,,,%(%
%%include(%filepath%/mxde-httpd-conf-alias.t)%%
%)%,alias)%%
%%parse(%script_aliases%,;,%(
)%,,,%(%
%%include(%filepath%/mxde-httpd-conf-scriptalias.t)%%
%)%,script_alias)%%
%%parse(%add_types%,;,%(
)%,,,%(%
%%include(%filepath%/mxde-httpd-conf-addtype.t)%%
%)%,addtype)%%
%%parse(%actions%,;,%(
)%,,,%(%
%%include(%filepath%/mxde-httpd-conf-action.t)%%
%)%,action)%%
%
%lt%/%kk_%IfModule%_kk%%gt%
%
%%do(%begin_separator%)%%
%%do(%left_separator%)% ... %do(%right_separator%)%%
%%do(%left_separator%)% Aliases %do(%right_separator%)%%
%%do(%end_separator%)%%
%%include(%filepath%/mxde-httpd-conf-autoindex.t)%%
%)%)%