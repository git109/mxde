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
%#   File: mxde-httpd-conf-alias.t
%#
%# Author: $author$     
%#   Date: 7/27/2010
%########################################################################
%with(%
%alias_dir,%(%else-then(%right-of-left(%alias%,=)%,%()%)%)%,%
%alias,%(%else-then(%left(%alias%,=)%,%(%alias%)%)%)%,%
%alias_names,%(%else-then(%parse(%alias%,%(,)%,,%( )%)%,%(%alias%)%)%)%,%
%%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Alias %alias_names% %do(%right_separator%)%%
%%do(%end_separator%)%%
%%parse(%alias%,%(,)%,,,,%(%
%%kk_%Alias%_kk% %alias% %ii_%"%alias_dir%"%_ii%
%
%)%,alias)%%
%%lt%%kk_%Directory%_kk% %ii_%"%alias_dir%"%_ii%%gt%
    Options Indexes MultiViews FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
%lt%/%kk_%Directory%_kk%%gt%
%
%)%)%