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
%#   File: mxde-xsl-param.t
%#
%# Author: $author$           
%#   Date: 9/30/2009
%########################################################################
%with(%
%section_name,%(%else-then(%param_section_name%,%(Parameters)%)%)%,%
%xsl_param_select_nodeset_type,%(%else-then(%xsl_param_select_nodeset_type%,%(%xslxns%:%xsl_nodeset%)%)%)%,%
%%(%
%%if(%xsl_params%,%(%
%%if(%xsl_param_section%,%(%
%%do(%section%)%%
%)%)%%
%%parse(%xsl_param%,;,,,,%(%
%%with(%
%prefix,%(%xsl_param_prefix%)%,%
%suffix,%(%xsl_param_suffix%)%,%
%base,%(%name%)%,%
%name,%(%prefix%%name%%suffix%)%,%
%%(%
%%if(%equal(select,%xsl_param_expr_type%)%,%(%
%%if(%xsl_param_select_nodeset%,%(%
%%indent%%lt%%xsl:param%%
% name=%ss_%"%do(%name%)%%xsl_nodeset_tree_suffix%"%_ss%%gt%
%indent%%lt%/%xsl:param%%gt%
%
%)%)%%
%)%)%%
%%indent%%lt%%xsl:param%%
% name=%ss_%"%do(%name%)%"%_ss%%
%%if(%equal(select,%xsl_param_expr_type%)%,%(%
% select=%ss_%"%
%%if(%xsl_param_select_nodeset%,%(%
%%xsl_param_select_nodeset_type%%(()%$%do(%name%)%%xsl_nodeset_tree_suffix%%())%%
%)%)%%
%%parse(%xsl_param_select%,;,,%(%xsl_expr_and%)%,,%(%
%%do(%xsl_param_select%)%%
%)%,xsl_param_select)%%
%"%_ss%%
%/%gt%
%
%%if(%xsl_param_select_nodeset%,%(%
%
%
%)%)%%
%)%,%(%
%%if(%equal(if,%xsl_param_expr_type%)%,%(%
%%gt%
%indent%%indent_%%lt%%xsl:if% test=%ss_%"%
%%parse(%xsl_param_select%,;,,%(%xsl_expr_and%)%,,%(%
%%do(%xsl_param_select%)%%
%)%,xsl_param_select)%%
%"%_ss%%gt%
%indent%%indent_%%lt%/%xsl:if%%gt%
%indent%%lt%/%xsl:param%%gt%
%
%)%,%(%
%%if(%equal(choose,%xsl_param_expr_type%)%,%(%
%%gt%
%indent%%indent_%%lt%%xsl:choose%%gt%
%if(%xsl_param_select%,%(%
%%parse(%xsl_param_select%,;,,,,%(%
%%indent%%indent_%%indent_%%lt%%xsl:when% test=%ss_%"%do(%xsl_param_select%)%"%_ss%%gt%
%indent%%indent_%%indent_%%lt%/%xsl:when%%gt%
%
%)%,xsl_param_select)%%
%)%,%(%
%%indent%%indent_%%indent_%%lt%%xsl:when% test=%ss_%"%do(%xsl_param_select%)%"%_ss%%gt%
%indent%%indent_%%indent_%%lt%/%xsl:when%%gt%
%
%)%)%%
%%indent%%indent_%%indent_%%lt%%xsl:otherwise%%gt%
%indent%%indent_%%indent_%%lt%/%xsl:otherwise%%gt%
%indent%%indent_%%lt%/%xsl:choose%%gt%
%indent%%lt%/%xsl:param%%gt%
%
%)%,%(%
%%gt%
%indent%%lt%/%xsl:param%%gt%
%
%)%)%%
%)%)%%
%)%)%%
%)%)%%
%)%,name)%%
%
%)%)%%
%)%)%