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
%#   File: mxde-httpd-conf-autoindex.t
%#
%# Author: $author$     
%#   Date: 6/9/2011
%########################################################################
%with(%
%%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Autoindex %do(%right_separator%)%%
%%do(%left_separator%)% ... %do(%right_separator%)%%
%%do(%end_separator%)%%
%%lt%%kk_%IfModule%_kk% mod_autoindex.c%gt%
IndexOptions FancyIndexing FoldersFirst
%lt%/%kk_%IfModule%_kk%%gt%
%
%%do(%begin_separator%)%%
%%do(%left_separator%)% ... %do(%right_separator%)%%
%%do(%left_separator%)% Autoindex %do(%right_separator%)%%
%%do(%end_separator%)%%
%)%)%