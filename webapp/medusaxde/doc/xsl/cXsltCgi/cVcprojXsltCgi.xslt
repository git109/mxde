<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2011 $organization$                                 -->
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
<!--   File: cVcprojXsltCgi.xslt                                            -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/20/2011                                                      -->
<!--========================================================================-->
<xsl:stylesheet
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
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../medusaxde-cgi-env-parameters.xsl"/>
<xsl:include href="../medusaxde-parameters.xsl"/>
<xsl:include href="../medusaxde-templates.xsl"/>
<xsl:include href="../medusaxde-form-parameters.xsl"/>
<xsl:include href="../medusaxde-form-templates.xsl"/>
<xsl:include href="../medusaxde-transform-parameters.xsl"/>
<xsl:include href="../medusaxde-transform-templates.xsl"/>    

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_do" select="'Convert '"/>
<xsl:param name="default_xde_form_title_what" select="'.vcproj File'"/>
<xsl:param name="default_xde_form_title_what_file" select="'Output File'"/>
<xsl:param name="default_xde_form_title_what_parameters" select="' Parameters'"/>
<xsl:param name="default_xde_form_title">
    <xsl:value-of select="$default_xde_form_title_do"/>
    <xsl:value-of select="$default_xde_form_title_what"/>
</xsl:param>
<xsl:param name="default_xde_form_section">
    <xsl:value-of select="$default_xde_form_title_what_file"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<xsl:param name="makefile_template" select="'/medusaxde/xsl/makefile/medusaxde-vcproj-to-makefile.xslt'"/>
<xsl:param name="qtcreator_template" select="'/medusaxde/xsl/qtcreator/medusaxde-vcproj-to-qtcreator.xslt'"/>
<xsl:param name="xosdevelopment_template" select="'/medusaxde/xsl/xosdevelopment/medusaxde-vcproj-to-xosdevelopment.xslt'"/>

<xsl:param name="default_xde_form_action" select="''"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<xsl:param name="xsl_form_section">
    <xsl:value-of select="$default_xde_form_title_what"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<xsl:param name="xsl_transform_form_section">
    <xsl:value-of select="'&lt;xsl:transform&gt;'"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<xsl:param name="project_target" select="'x'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="document_file" select="$cgi_env_PATH_TRANSLATED"/>

<xsl:variable name="project_file_types_tree">
    <type default="yes" value="{$makefile_template}">Makefile</type>
    <type value="{$qtcreator_template}">QtCreator</type>
    <type value="{$xosdevelopment_template}">XosDevelopment</type>
</xsl:variable>
<xsl:variable name="project_file_types" 
 select="exsl:node-set($project_file_types_tree)"/>

<xsl:variable name="project_target_types_tree">
    <type default="yes" value="executable">Executable (.exe)</type>
    <type value="shared-library">Shared Library (.dll)</type>
    <type value="static-library">Static Library (.lib)</type>
</xsl:variable>
<xsl:variable name="project_target_types"
 select="exsl:node-set($project_target_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "vcproj_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/21/2011                                                    -->
<!--========================================================================-->
<xsl:template name="vcproj_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_vcproj" select="$is_param_"/>
    <xsl:param name="is_param_project_file_type" select="$is_param_"/>
    <xsl:param name="is_param_project_target_type" select="$is_param_"/>
    <xsl:param name="is_param_project_target" select="$is_param_"/>

    <xsl:param name="section_text" select="'.vcproj Parameters'"/>

    <xsl:param name="vcproj_text" select="'.vcproj File'"/>
    <xsl:param name="vcproj_text_before" select="''"/>
    <xsl:param name="vcproj_text_after" select="''"/>
    <xsl:param name="vcproj_param" select="'document_file'"/>
    <xsl:param name="vcproj" select="$document_file"/>

    <xsl:param name="project_file_type_text" select="'To'"/>
    <xsl:param name="project_file_type_text_before" select="''"/>
    <xsl:param name="project_file_type_text_after" select="''"/>
    <xsl:param name="project_file_type_option" select="''"/>
    <xsl:param name="project_file_type_options" select="$project_file_types/*"/>
    <xsl:param name="project_file_type_param" select="'form_action'"/>
    <xsl:param name="project_file_type" select="''"/>

    <xsl:param name="project_target_type_text" select="'Target Type'"/>
    <xsl:param name="project_target_type_text_before" select="''"/>
    <xsl:param name="project_target_type_text_after" select="''"/>
    <xsl:param name="project_target_type_option" select="''"/>
    <xsl:param name="project_target_type_options" select="$project_target_types/*"/>
    <xsl:param name="project_target_type_param" select="'project_target_type'"/>
    <xsl:param name="project_target_type" select="''"/>

    <xsl:param name="project_target_text" select="'Target Name'"/>
    <xsl:param name="project_target_text_before" select="''"/>
    <xsl:param name="project_target_text_after" select="''"/>
    <xsl:param name="project_target_param" select="'project_target'"/>
    <xsl:param name="project_target" select="$project_target"/>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_vcproj)) or ('yes' = $is_param_vcproj)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$vcproj_text"/>
        <xsl:with-param name="text_before" select="$vcproj_text_before"/>
        <xsl:with-param name="text_after" select="$vcproj_text_after"/>
        <xsl:with-param name="name" select="$vcproj_param"/>
        <xsl:with-param name="value" select="$vcproj"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_project_file_type)) or ('yes' = $is_param_project_file_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$project_file_type_text"/>
            <xsl:with-param name="text_before" select="$project_file_type_text_before"/>
            <xsl:with-param name="text_after" select="$project_file_type_text_after"/>
            <xsl:with-param name="name" select="$project_file_type_param"/>
            <xsl:with-param name="value" select="$project_file_type"/>
            <xsl:with-param name="option" select="$project_file_type_options"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_project_target_type)) or ('yes' = $is_param_project_target_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$project_target_type_text"/>
            <xsl:with-param name="text_before" select="$project_target_type_text_before"/>
            <xsl:with-param name="text_after" select="$project_target_type_text_after"/>
            <xsl:with-param name="name" select="$project_target_type_param"/>
            <xsl:with-param name="value" select="$project_target_type"/>
            <xsl:with-param name="option" select="$project_target_type_options"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_project_target)) or ('yes' = $is_param_project_target)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$project_target_text"/>
            <xsl:with-param name="text_before" select="$project_target_text_before"/>
            <xsl:with-param name="text_after" select="$project_target_text_after"/>
            <xsl:with-param name="name" select="$project_target_param"/>
            <xsl:with-param name="value" select="$project_target"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/20/2011                                                    -->
<!--========================================================================-->
<xsl:template name="form_fields">
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="section_text" select="$default_form_section"/>
    </xsl:call-template>
    <xsl:call-template name="vcproj_form_fields">
    </xsl:call-template>
    <xsl:call-template name="form_form_fields">
        <xsl:with-param name="xis_param_action" select="'no'"/>
    </xsl:call-template>
</xsl:template>
</xsl:stylesheet>
