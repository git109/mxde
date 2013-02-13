<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2013 $organization$                                 -->
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
<!--   File: medusaxde-create-vsprops.xsl                                   -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/3/2013                                                       -->
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
<xsl:param name="default_xde_form_title_what" select="'VisualStudio .vsprops File'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/xml/mxde-vsprops.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "vsprops_form_fields"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/3/2013                                                     -->
<!--========================================================================-->
<xsl:template name="vsprops_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_file_separator" select="''"/>
    <xsl:param name="is_param_project" select="''"/>
    <xsl:param name="is_param_project_group" select="''"/>
    <xsl:param name="is_param_project_version" select="''"/>

    <xsl:param name="project_text" select="'Project'"/>
    <xsl:param name="project_text_before" select="''"/>
    <xsl:param name="project_text_after" select="''"/>
    <xsl:param name="project_param" select="'project'"/>
    <xsl:param name="project" select="'Project'"/>

    <xsl:param name="project_group_text" select="'Croup'"/>
    <xsl:param name="project_group_text_before" select="''"/>
    <xsl:param name="project_group_text_after" select="''"/>
    <xsl:param name="project_group_param" select="'project_group'"/>
    <xsl:param name="project_group" select="$project"/>

    <xsl:param name="project_version_text" select="'Version'"/>
    <xsl:param name="project_version_text_before" select="''"/>
    <xsl:param name="project_version_text_after" select="''"/>
    <xsl:param name="project_version_param" select="'project_version'"/>
    <xsl:param name="project_version" select="'1.1.1'"/>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_separator)) or ('yes' = $is_param_file_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_project)) or ('yes' = $is_param_project)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$project_text"/>
            <xsl:with-param name="text_before" select="$project_text_before"/>
            <xsl:with-param name="text_after" select="$project_text_after"/>
            <xsl:with-param name="name" select="$project_param"/>
            <xsl:with-param name="value" select="$project"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_project_group)) or ('yes' = $is_param_project_group)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$project_group_text"/>
            <xsl:with-param name="text_before" select="$project_group_text_before"/>
            <xsl:with-param name="text_after" select="$project_group_text_after"/>
            <xsl:with-param name="name" select="$project_group_param"/>
            <xsl:with-param name="value" select="$project_group"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_project_version)) or ('yes' = $is_param_project_version)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$project_version_text"/>
            <xsl:with-param name="text_before" select="$project_version_text_before"/>
            <xsl:with-param name="text_after" select="$project_version_text_after"/>
            <xsl:with-param name="name" select="$project_version_param"/>
            <xsl:with-param name="value" select="$project_version"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/3/2013                                                     -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="vsprops_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>

        

