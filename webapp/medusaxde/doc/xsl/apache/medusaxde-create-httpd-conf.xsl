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
<!--   File: medusaxde-create-httpd-conf.xsl                                -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 12/2/2012                                                      -->
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
<xsl:param name="default_xde_form_title_what" select="'Apache .conf File'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/apache/mxde-httpd-conf.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "httpd_conf_form_fields"                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 12/2/2012                                                    -->
<!--========================================================================-->
<xsl:template name="httpd_conf_form_fields">

    <xsl:param name="is_param_" select="''"/>

    <xsl:param name="is_param_section" select="$is_param_"/>

    <xsl:param name="is_param_aliases" select="$is_param_"/>
    <xsl:param name="is_param_script_aliases" select="$is_param_"/>
    <xsl:param name="is_param_add_types" select="$is_param_"/>
    <xsl:param name="is_param_actions" select="$is_param_"/>

    <xsl:param name="section_text">
        <xsl:value-of select="$default_xde_form_title_what"/>
        <xsl:value-of select="' Parameters'"/>
    </xsl:param>

    <xsl:param name="aliases_text" select="''"/>
    <xsl:param name="aliases_text_before" select="'Alias'"/>
    <xsl:param name="aliases_text_after" select="'(?,...=?;...)'"/>
    <xsl:param name="aliases_param" select="'aliases'"/>
    <xsl:param name="aliases" select="''"/>

    <xsl:param name="script_aliases_text" select="''"/>
    <xsl:param name="script_aliases_text_before" select="'ScriptAlias'"/>
    <xsl:param name="script_aliases_text_after" select="'(?,...=?;...)'"/>
    <xsl:param name="script_aliases_param" select="'script_aliases'"/>
    <xsl:param name="script_aliases" select="''"/>

    <xsl:param name="add_types_text" select="''"/>
    <xsl:param name="add_types_text_before" select="'AddType'"/>
    <xsl:param name="add_types_text_after" select="'(?=?,...;...)'"/>
    <xsl:param name="add_types_param" select="'add_types'"/>
    <xsl:param name="add_types" select="''"/>

    <xsl:param name="actions_text" select="''"/>
    <xsl:param name="actions_text_before" select="'Action'"/>
    <xsl:param name="actions_text_after" select="'(?,...=?;...)'"/>
    <xsl:param name="actions_param" select="'actions'"/>
    <xsl:param name="actions" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_aliases)) or ('yes' = $is_param_aliases)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$aliases_text"/>
        <xsl:with-param name="text_before" select="$aliases_text_before"/>
        <xsl:with-param name="text_after" select="$aliases_text_after"/>
        <xsl:with-param name="name" select="$aliases_param"/>
        <xsl:with-param name="value" select="$aliases"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_script_aliases)) or ('yes' = $is_param_script_aliases)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$script_aliases_text"/>
        <xsl:with-param name="text_before" select="$script_aliases_text_before"/>
        <xsl:with-param name="text_after" select="$script_aliases_text_after"/>
        <xsl:with-param name="name" select="$script_aliases_param"/>
        <xsl:with-param name="value" select="$script_aliases"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_add_types)) or ('yes' = $is_param_add_types)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$add_types_text"/>
        <xsl:with-param name="text_before" select="$add_types_text_before"/>
        <xsl:with-param name="text_after" select="$add_types_text_after"/>
        <xsl:with-param name="name" select="$add_types_param"/>
        <xsl:with-param name="value" select="$add_types"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_actions)) or ('yes' = $is_param_actions)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$actions_text"/>
        <xsl:with-param name="text_before" select="$actions_text_before"/>
        <xsl:with-param name="text_after" select="$actions_text_after"/>
        <xsl:with-param name="name" select="$actions_param"/>
        <xsl:with-param name="value" select="$actions"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 12/2/2012                                                    -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="file" select="'httpd.conf'"/>
        <xsl:with-param name="date" select="$current_date"/>
        <xsl:with-param name="year" select="$current_year"/>
    </xsl:call-template>
    <xsl:call-template name="httpd_conf_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
