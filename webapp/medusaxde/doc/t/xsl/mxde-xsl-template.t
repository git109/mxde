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
%#   File: mxde-xsl-template.t
%#
%# Author: $author$           
%#   Date: 9/30/2009
%########################################################################
%with(%
%section_name,%(Templates)%,%
%%(%
%%if(%xsl_templates%,%(%
%%else(%no_template_section%,%(%
%%do(%section%)%%
%)%)%%
%%parse(%xsl_template_name%,;,,%(
)%,,%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)%%
%%padd( Template: %if-then(%equal(match,%xsl_template%)%,%( )%)%"%xsl_template_name%" %then-if(%if-then(%xsl_template_mode%,")%,mode ")%, ,%separator_padd%)%%
%%do(%right_separator%)%%
%%do(%left_separator%)%%
%%padd( , ,%separator_padd%)%%
%%do(%right_separator%)%%
%%do(%left_separator%)%%
%%padd(   Author: %author%, ,%separator_padd%)%%
%%do(%right_separator%)%%
%%do(%left_separator%)%%
%%padd(     Date: %date%, ,%separator_padd%)%%
%%do(%right_separator%)%%
%%do(%end_separator%)%%
%%lt%%xsl:template% %xsl_template%="%xsl_template_name%"%
%%if-then(%then-if(%xsl_template_mode%,%( mode=")%)%,%(")%)%%
%%gt%
%with(%
%_indent,%(%indent%)%,%
%indent,%(%indent%%if(%xsl_template_indent%,%(%indent_%)%)%)%,%
%xsl_param_section,%(%xsl_template_sections%)%,%
%xsl_params,%(%xsl_template_params%)%,%
%xsl_param,%(%xsl_template_param%)%,%
%xsl_param_expr_type,%(%xsl_template_param_expr_type%)%,%
%xsl_param_select,%(%xsl_template_param_select%)%,%
%xsl_param_select_nodeset,%(%xsl_template_param_select_nodeset%)%,%
%xsl_variables,%(%xsl_template_variables%)%,%
%xsl_variable,%(%xsl_template_variable%)%,%
%xsl_variable_expr_type,%(%xsl_template_variable_expr_type%)%,%
%xsl_variable_select,%(%xsl_template_variable_select%)%,%
%xsl_variable_select_nodeset,%(%xsl_template_variable_select_nodeset%)%,%
%%(%
%%with(%
%param_section_name,%(Template Parameters)%,%
%%(%
%%include(%filepath%/mxde-xsl-param.t)%%
%)%)%%
%%with(%
%param_section_name,%(Template Variables)%,%
%%(%
%%include(%filepath%/mxde-xsl-variable.t)%%
%)%)%%
%%with(%
%section_name,%(Template Body)%,%
%%(%
%%if(%xsl_template_sections%,%(%
%%do(%section%)%%
%)%)%%
%)%)%%
%)%)%%
%%lt%/%xsl:template%%gt%
%
%)%,xsl_template_name)%%
%)%)%%
%)%)%