<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2012 $organization$                                 -->
<!--                                                                        -->
<!-- This software is provided by the author and contributors ``as is''     -->
<!-- and any express or implied warranties, including, but not limited to,  -->
<!-- the implied warranties of merchantability and fitness for a particular -->
<!-- purpose are disclaimed. In no event shall the author or contributors   -->
<!-- be liable for any direct, indirect, incidental, special, exemplary,    -->
<!-- or consequential damages (including, but not limited to, procurement   -->
<!-- of substitute goods or services; loss of use, data, or profits; or     -->
<!-- business interruption) however caused and on any theory of liability,  -->
<!-- whether in contract, strict liability, or tort (including negligence   -->
<!-- or otherwise) arising in any way out of the use of this software,      -->
<!-- even if advised of the possibility of such damage.                     -->
<!--                                                                        -->
<!--   File: medusaxde-create-t.xsl                                         -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 11/29/2012                                                     -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:medusaxde="Medusa-Xos-Development-Environment"
 exclude-result-prefixes="xsl exsl xalan msxsl xde mxde medusade medusaxde"
 version="1.0">

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../medusaxde-create.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/t/mxde-t.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="t_file_extensions_tree">
    <type value="t">.t</type>
    <type default="yes" value="">no</type>
</xsl:variable>
<xsl:variable name="t_file_extensions"
 select="exsl:node-set($t_file_extensions_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "t_file_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/29/2012                                                   -->
<!--========================================================================-->
<xsl:template name="t_file_form_fields">
    <xsl:param name="is_param_" select="'yes'"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="section_text" select="''"/>
    <xsl:param name="is_param_content_type" select="$is_param_"/>
    <xsl:param name="content_type" select="'text/html'"/>
    <xsl:param name="is_param_file" select="$is_param_"/>
    <xsl:param name="is_param_file_extension" select="$is_param_"/>

    <xsl:param name="file" select="'t'"/>
    <xsl:param name="file_extension_text" select="''"/>
    <xsl:param name="file_extension_text_before" select="''"/>
    <xsl:param name="file_extension_text_after" select="''"/>
    <xsl:param name="file_extension_option" select="''"/>
    <xsl:param name="file_extension_options" select="$t_file_extensions/*"/>
    <xsl:param name="file_extension_param" select="'file_type_extension'"/>
    <xsl:param name="file_extension" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="is_param_section" select="$is_param_section"/>
        <xsl:with-param name="section_text" select="$section_text"/>
        <xsl:with-param name="is_param_content_type" select="$is_param_content_type"/>
        <xsl:with-param name="content_type" select="$content_type"/>
        <xsl:with-param name="is_param_file" select="$is_param_file"/>
        <xsl:with-param name="file" select="$file"/>
    </xsl:call-template>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_extension)) or ('yes' = $is_param_file_extension)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_extension_text"/>
            <xsl:with-param name="text_before" select="$file_extension_text_before"/>
            <xsl:with-param name="text_after" select="$file_extension_text_after"/>
            <xsl:with-param name="name" select="$file_extension_param"/>
            <xsl:with-param name="value" select="$file_extension"/>
            <xsl:with-param name="option" select="$file_extension_options"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "t_form_fields"                                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/21/2015                                                    -->
<!--========================================================================-->
<xsl:template name="t_form_fields">

    <xsl:param name="is_param_" select="''"/>

    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_parameter" select="$is_param_"/>
    <xsl:param name="is_param_parameter_prefix" select="$is_param_"/>
    <xsl:param name="is_param_parameter_postfix" select="$is_param_"/>
    <xsl:param name="is_param_parameters" select="$is_param_"/>
    <xsl:param name="is_param_ul_parameters" select="$is_param_"/>

    <xsl:param name="section_text">
        <xsl:value-of select="$default_xde_form_title_what"/>
        <xsl:value-of select="' Parameters'"/>
    </xsl:param>

    <xsl:param name="parameter_text" select="'Parameters'"/>
    <xsl:param name="parameter_text_before" select="''"/>
    <xsl:param name="parameter_text_after" select="';...'"/>
    <xsl:param name="parameter_param" select="'parameter'"/>
    <xsl:param name="parameter" select="'Parameter'"/>

    <xsl:param name="parameter_prefix_text" select="''"/>
    <xsl:param name="parameter_prefix_text_before" select="''"/>
    <xsl:param name="parameter_prefix_text_after" select="'?'"/>
    <xsl:param name="parameter_prefix_param" select="'parameter_prefix'"/>
    <xsl:param name="parameter_prefix" select="''"/>

    <xsl:param name="parameter_postfix_text" select="''"/>
    <xsl:param name="parameter_postfix_text_before" select="'?'"/>
    <xsl:param name="parameter_postfix_text_after" select="''"/>
    <xsl:param name="parameter_postfix_param" select="'parameter_postfix'"/>
    <xsl:param name="parameter_postfix" select="''"/>

    <xsl:param name="parameters_text" select="''"/>
    <xsl:param name="parameters_text_before" select="''"/>
    <xsl:param name="parameters_text_after" select="''"/>
    <xsl:param name="parameters_param" select="'parameters'"/>
    <xsl:param name="parameters" select="'yes'"/>

    <xsl:param name="ul_parameters_text" select="'upper/lower'"/>
    <xsl:param name="ul_parameters_text_before" select="''"/>
    <xsl:param name="ul_parameters_text_after" select="''"/>
    <xsl:param name="ul_parameters_param" select="'ul_parameters'"/>
    <xsl:param name="ul_parameters" select="'yes'"/>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
    <xsl:call-template name="section_row">
        <xsl:with-param name="text" select="$section_text"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_parameter)) or ('yes' = $is_param_parameter)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$parameter_text"/>
        <xsl:with-param name="text_before" select="$parameter_text_before"/>
        <xsl:with-param name="text_after" select="$parameter_text_after"/>
        <xsl:with-param name="name" select="$parameter_param"/>
        <xsl:with-param name="value" select="$parameter"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_parameter_prefix)) or ('yes' = $is_param_parameter_prefix)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$parameter_prefix_text"/>
        <xsl:with-param name="text_before" select="$parameter_prefix_text_before"/>
        <xsl:with-param name="text_after" select="$parameter_prefix_text_after"/>
        <xsl:with-param name="name" select="$parameter_prefix_param"/>
        <xsl:with-param name="value" select="$parameter_prefix"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_parameter_postfix)) or ('yes' = $is_param_parameter_postfix)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$parameter_postfix_text"/>
        <xsl:with-param name="text_before" select="$parameter_postfix_text_before"/>
        <xsl:with-param name="text_after" select="$parameter_postfix_text_after"/>
        <xsl:with-param name="name" select="$parameter_postfix_param"/>
        <xsl:with-param name="value" select="$parameter_postfix"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_parameters)) or ('yes' = $is_param_parameters)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$parameters_text"/>
        <xsl:with-param name="text_before" select="$parameters_text_before"/>
        <xsl:with-param name="text_after" select="$parameters_text_after"/>
        <xsl:with-param name="name" select="$parameters_param"/>
        <xsl:with-param name="value" select="$parameters"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_ul_parameters)) or ('yes' = $is_param_ul_parameters)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$ul_parameters_text"/>
        <xsl:with-param name="text_before" select="$ul_parameters_text_before"/>
        <xsl:with-param name="text_after" select="$ul_parameters_text_after"/>
        <xsl:with-param name="name" select="$ul_parameters_param"/>
        <xsl:with-param name="value" select="$ul_parameters"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/29/2012                                                    -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="t_file_form_fields">
    </xsl:call-template>
    <xsl:call-template name="t_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
