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
%#   File: mxde-xsl.t
%#
%# Author: $author$           
%#   Date: 9/29/2009
%########################################################################
%with(%
%processor_color,%(%else-then(%processor_color%,%(purple)%)%)%,%
%keyword_color,%(%else-then(%keyword_color%,%(teal)%)%)%,%
%keywordx_color,%(%else-then(%keywordx_color%,%(blue)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath(%filepath%)%)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/mxde-xsl.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%apply(filepath,%includepath%,%(%
%)%)%%
%%(%include(%includepath%/mxde-source-html.t)%%
%)%,%(%
%%with(%
%file_type_extension,%(%else-then(%file_type_extension%,%(xsl)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension(%file%)%)%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%xsl:transform,%(%kk_%xsl:%if(%equal(yes,%xsl_is_stylesheet%)%,stylesheet,transform)%%_kk%)%,%
%xsl:output,%(%kk_%xsl:output%_kk%)%,%
%xsl:include,%(%kk_%xsl:include%_kk%)%,%
%xsl:param,%(%kk_%xsl:param%_kk%)%,%
%xsl:with-param,%(%kk_%xsl:with-param%_kk%)%,%
%xsl:variable,%(%kk_%xsl:variable%_kk%)%,%
%xsl:template,%(%kk_%xsl:template%_kk%)%,%
%xsl:call-template,%(%kk_%xsl:call-template%_kk%)%,%
%xsl:copy-of,%(%kk_%xsl:copy-of%_kk%)%,%
%xsl:value-of,%(%kk_%xsl:value-of%_kk%)%,%
%xsl:select,%(%kk_%xsl:select%_kk%)%,%
%xsl:if,%(%kk_%xsl:if%_kk%)%,%
%xsl:choose,%(%kk_%xsl:choose%_kk%)%,%
%xsl:when,%(%kk_%xsl:when%_kk%)%,%
%xsl:otherwise,%(%kk_%xsl:otherwise%_kk%)%,%
%indent_,%(    )%,%
%left_processor,%(%lt%?)%,%
%right_processor,%(?%gt%)%,%
%begin_processor,%(%pp_%%left_processor%)%,%
%end_processor,%(%right_processor%%_pp%)%,%
%left_comment,%(%lt%!--)%,%
%right_comment,%(--%gt%)%,%
%middle_comment,%(----)%,%
%first_comment,%(%%indent%%%cc_%%lt%!--
)%,%
%last_comment,%(%%indent%%----%gt%%_cc%
)%,%
%begin_comment,%(%cc_%%left_comment%)%,%
%end_comment,%(%right_comment%%_cc%)%,%
%separator_extra,%(%include(%filepath%/%organization%-separator-extra.t)%)%,%
%separator_middle,%(========================================================================%separator_extra%)%,%
%separator_padd,%(%length(%separator_middle%)%)%,%
%separator,%(%left_comment%%separator_middle%%right_comment%)%,%
%begin_separator,%(%%indent%%%cc_%%separator%
)%,%
%end_separator,%(%%indent%%%separator%%_cc%
)%,%
%left_separator,%(%%indent%%%left_comment%)%,%
%right_separator,%(%right_comment%
)%,%
%section,%(%(%do(%begin_separator%)%%do(%left_separator%)%%padd( %section_name%, ,%separator_padd%)%%do(%right_separator%)%%do(%end_separator%)%)%)%,%
%template_separator,%(%(%do(%begin_separator%)%%do(%end_separator%)%)%)%,%
%xml_version,%(%else-then(%xml_version%,%(1.0)%)%)%,%
%xslns,%(%else-then(%xslns%,%(xsl)%)%)%,%
%exslns,%(%else-then(%exslns%,%(exsl)%)%)%,%
%xslxns,%(%else-then(%xslxns%,%(xalan)%)%)%,%
%msxslns,%(%else-then(%msxslns%,%(msxsl)%)%)%,%
%xdens,%(%else-then(%xdens%,%(xde)%)%)%,%
%mxdens,%(%else-then(%mxdens%,%(mxde)%)%)%,%
%medusadens,%(%else-then(%medusadens%,%(medusade)%)%)%,%
%medusaxdens,%(%else-then(%medusaxdens%,%(medusaxde)%)%)%,%
%xslns_uri,%(%else-then(%xslns_uri%,%(http://www.w3.org/1999/XSL/Transform)%)%)%,%
%exslns_uri,%(%else-then(%exslns_uri%,%(http://exslt.org/common)%)%)%,%
%xslxns_uri,%(%else-then(%xslxns_uri%,%(http://xml.apache.org/xalan)%)%)%,%
%msxslns_uri,%(%else-then(%msxslns_uri%,%(urn:schemas-microsoft-com:xslt)%)%)%,%
%xdens_uri,%(%else-then(%xdens_uri%,%(Medusa-Xos-Development-Environment)%)%)%,%
%mxdens_uri,%(%else-then(%mxdens_uri%,%(Medusa-Xos-Development-Environment)%)%)%,%
%medusadens_uri,%(%else-then(%medusadens_uri%,%(Medusa-Xos-Development-Environment)%)%)%,%
%medusaxdens_uri,%(%else-then(%medusaxdens_uri%,%(Medusa-Xos-Development-Environment)%)%)%,%
%xslns_list,%(%else-then(%xslns_list%,%(xslns;exslns;xslxns;msxslns;xdens;mxdens;medusadens;medusaxdens)%)%)%,%
%xsl_version,%(%else-then(%xsl_version%,%(1.0)%)%)%,%
%xsl_version_attr,%(
 version=%ss_%"%xsl_version%"%_ss%)%,%
%xsl_expr_and,%(%else-then(%xsl_expr_and%,%( and )%)%)%,%
%xsl_output_method,%(%else(%equal(no,%xsl_output_method%)%,%(%else-then(%xsl_output_method%,%()%)%)%)%)%,%
%xsl_output_indent,%(%else-then(%xsl_output_indent%,%(yes)%)%)%,%
%xsl_output_version,%(%else-then(%xsl_output_version%,%(yes)%)%)%,%
%xsl_output,%(%else(%equal(no,%xsl_output%)%,%(%xsl_output_method%)%)%)%,%
%xsl_params,%(%else(%equal(no,%xsl_params%)%,%(%xsl_param%)%)%)%,%
%xsl_variables,%(%else(%equal(no,%xsl_variables%)%,%(%xsl_variable%)%)%)%,%
%xsl_template,%(%else(%equal(no,%xsl_template%)%,%(%xsl_template%)%)%)%,%
%xsl_templates,%(%else(%equal(no,%xsl_templates%)%,%(%xsl_template_name%)%)%)%,%
%xsl_template_params,%(%else(%equal(no,%xsl_template_params%)%,%(%xsl_template_param%)%)%)%,%
%xsl_template_variables,%(%else(%equal(no,%xsl_template_variables%)%,%(%xsl_template_variable%)%)%)%,%
%xsl_include,%(%if-then(%xsl_include%,%(%if(%xsl_include_list%,%(;)%)%)%)%%parameters(xsl_include_list,,;,)%)%,%
%xsl_includes,%(%else(%equal(no,%xsl_includes%)%,%(%xsl_include%)%)%)%,%
%xsl_nodeset_tree_suffix,%(%else-then(%xsl_nodeset_tree_suffix%,%(_tree)%)%)%,%
%xsl_nodeset,%(%else-then(%xsl_nodeset%,%(nodeset)%)%)%,%
%derived_fileinclude,%(%derived_includefile%)%,%
%derived_includefile,%()%,%
%%(%
%%if(%file%,%(%
%%parse(%file%,;,,,,%(%
%%with(%
%file_base,%(%filebase(%file%)%)%,%
%file_extension,%(%fileextension(%file%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%%(%
%%include(%filepath%/mxde-xsl-transform.t)%%
%)%)%%
%)%,file)%%
%)%,%(%
%%include(%filepath%/mxde-xsl-transform.t)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%
