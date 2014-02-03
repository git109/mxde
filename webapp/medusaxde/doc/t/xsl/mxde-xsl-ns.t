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
%#   File: mxde-xsl-ns.t
%#
%# Author: $author$           
%#   Date: 9/29/2009
%########################################################################
%with(%
%%(%
%%parse(%xslns_list%,;,%(
 )%,,,%(%
%%with(%
%xmlns_uri,%(%do(%%%xmlns%_uri%%)%)%,%
%xmlns,%(%do(%%%xmlns%%%)%)%,%
%%(%
%%xx_%xmlns:%xmlns%%_xx%=%ss_%"%xmlns_uri%"%_ss%%
%)%)%%
%)%,xmlns)%%
%%parse(%xsl_ns_list%,;,,,,%(%
%%with(%
%xmlns_uri,%(%do(%%%xmlns%_uri%%)%)%,%
%xmlns,%(%do(%%%xmlns%%%)%)%,%
%%(%
%%if(%and(%xmlns%,%xmlns_uri%)%,%(%
%
 %xx_%xmlns:%xmlns%%_xx%=%ss_%"%xmlns_uri%"%_ss%%
%)%)%%
%)%)%%
%)%,xmlns)%%
%%parse(%xsl_exclude_prefixes_xslns_list%,;,,,,%(%
%%if(%do(%%xsl_exclude_prefixes_%do(%%%xmlns%%%)%%%)%,%(%
%%with(%
%xmlns_uri,%(%do(%%%xmlns%_uri%%)%)%,%
%xmlns,%(%do(%%%xmlns%%%)%)%,%
%%(%
%
 %xx_%xmlns:%xmlns%%_xx%=%ss_%"%xmlns_uri%"%_ss%%
%)%)%%
%)%)%%
%)%,xmlns)%%
%%if(%xslns_list%%xsl_ns_list%%xsl_exclude_prefixes_xslns_list%,%(
 exclude-result-prefixes=%ss_%"%
%%parse(%xslns_list%,;,, ,,%(%
%%do(%%%xmlns%%%)%%
%)%,xmlns)%%
%%parse(%xsl_ns_list%,;,,,,%(%
%%with(%
%xmlns_uri,%(%do(%%%xmlns%_uri%%)%)%,%
%xmlns,%(%do(%%%xmlns%%%)%)%,%
%%(%
%%if(%and(%xmlns%,%xmlns_uri%)%,%(%
% %xmlns%%
%)%)%%
%)%)%%
%)%,xmlns)%%
%%parse(%xsl_exclude_prefixes_xslns_list%,;,,,,%(%
%%if(%do(%%xsl_exclude_prefixes_%do(%%%xmlns%%%)%%%)%,%(%
% %do(%%%xmlns%%%)%%
%)%)%%
%)%,xmlns)%%
%"%_ss%)%)%%
%)%)%