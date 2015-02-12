<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2014 $organization$                                 -->
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
<!--   File: medusaxde-create-cxx-class-getopts.xsl                         -->
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
<xsl:include href="medusaxde-create-cxx-class-base.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/cxx/mxde-getopts-hxx-cxx.t'"/>
<xsl:param name="default_xde_form_title_what_what" select="''"/>
<xsl:param name="default_xde_form_title_what_what_what_what" select="' getopts'"/>
<xsl:param name="default_cxx_form_class_interface" select="'export'"/>
<xsl:param name="default_cxx_form_class" select="'main'"/>
<xsl:param name="default_cxx_form_class_implements" select="''"/>
<xsl:param name="default_cxx_form_class_extends" select="'main'"/>
<xsl:param name="default_cxx_form_class_constructor" select="''"/>
<xsl:param name="default_cxx_form_class_destructor" select="''"/>
<xsl:param name="default_cxx_form_class_members_only" select="''"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "getopt_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 10/31/2014                                                   -->
<!--========================================================================-->
<xsl:template name="getopt_form_fields">
<xsl:param name="is_param_" select="''"/>

<xsl:param name="is_param_section" select="$is_param_"/>
<xsl:param name="is_param_On" select="$is_param_"/>
<xsl:param name="is_param_Option" select="$is_param_"/>
<xsl:param name="is_param_OnOption" select="$is_param_"/>
<xsl:param name="is_param_OptionUsage" select="$is_param_"/>
<xsl:param name="is_param_Options" select="$is_param_"/>

<xsl:param name="section_text" select="'On?Option Parameters'"/>

<xsl:param name="On_text" select="''"/>
<xsl:param name="On_text_before" select="'virtual int'"/>
<xsl:param name="On_text_after" select="''"/>
<xsl:param name="On_param" select="'On'"/>
<xsl:param name="On" select="'On'"/>

<xsl:param name="Option_text" select="''"/>
<xsl:param name="Option_text_before" select="''"/>
<xsl:param name="Option_text_after" select="'(...){...}'"/>
<xsl:param name="Option_param" select="'Option'"/>
<xsl:param name="Option" select="'Option'"/>

<xsl:param name="OnOption_text" select="''"/>
<xsl:param name="OnOption_text_before" select="'Extends::'"/>
<xsl:param name="OnOption_text_after" select="'(...);'"/>
<xsl:param name="OnOption_param" select="'OnOption'"/>
<xsl:param name="OnOption" select="'OnOption'"/>

    <xsl:param name="OptionUsage_text" select="''"/>
    <xsl:param name="OptionUsage_text_before" select="'virtual const char*'"/>
    <xsl:param name="OptionUsage_text_after" select="'(){...}'"/>
    <xsl:param name="OptionUsage_param" select="'OptionUsage'"/>
    <xsl:param name="OptionUsage" select="'OptionUsage'"/>

<xsl:param name="Options_text" select="''"/>
<xsl:param name="Options_text_before" select="'virtual const char*'"/>
<xsl:param name="Options_text_after" select="'(){...}'"/>
<xsl:param name="Options_param" select="'Options'"/>
<xsl:param name="Options" select="'Options'"/>

<xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
<xsl:call-template name="section_row">
    <xsl:with-param name="text" select="$section_text"/>
</xsl:call-template>
</xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_On)) or ('yes' = $is_param_On)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$On_text"/>
        <xsl:with-param name="text_before" select="$On_text_before"/>
        <xsl:with-param name="text_after" select="$On_text_after"/>
        <xsl:with-param name="name" select="$On_param"/>
        <xsl:with-param name="value" select="$On"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_Option)) or ('yes' = $is_param_Option)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$Option_text"/>
        <xsl:with-param name="text_before" select="$Option_text_before"/>
        <xsl:with-param name="text_after" select="$Option_text_after"/>
        <xsl:with-param name="name" select="$Option_param"/>
        <xsl:with-param name="value" select="$Option"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_OnOption)) or ('yes' = $is_param_OnOption)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$OnOption_text"/>
        <xsl:with-param name="text_before" select="$OnOption_text_before"/>
        <xsl:with-param name="text_after" select="$OnOption_text_after"/>
        <xsl:with-param name="name" select="$OnOption_param"/>
        <xsl:with-param name="value" select="$OnOption"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_OptionUsage)) or ('yes' = $is_param_OptionUsage)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$OptionUsage_text"/>
        <xsl:with-param name="text_before" select="$OptionUsage_text_before"/>
        <xsl:with-param name="text_after" select="$OptionUsage_text_after"/>
        <xsl:with-param name="name" select="$OptionUsage_param"/>
        <xsl:with-param name="value" select="$OptionUsage"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_Options)) or ('yes' = $is_param_Options)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$Options_text"/>
        <xsl:with-param name="text_before" select="$Options_text_before"/>
        <xsl:with-param name="text_after" select="$Options_text_after"/>
        <xsl:with-param name="name" select="$Options_param"/>
        <xsl:with-param name="value" select="$Options"/>
    </xsl:call-template>
    </xsl:if>

</xsl:template>

<!--========================================================================-->
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 10/28/2014                                                   -->
<!--========================================================================-->
<xsl:template name="form_fields">
<xsl:call-template name="cxx_file_form_fields">
    <xsl:with-param name="is_param_" select="'no'"/>
    <xsl:with-param name="is_param_section" select="'yes'"/>
    <xsl:with-param name="section_text" select="$form_section"/>
    <xsl:with-param name="is_param_content_type" select="'yes'"/>
</xsl:call-template>
<xsl:call-template name="cxx_form_fields">
    <xsl:with-param name="is_param_" select="'no'"/>
    <xsl:with-param name="is_param_module" select="'yes'"/>
</xsl:call-template>
<xsl:call-template name="cxx_class_form_fields">
    <xsl:with-param name="is_param_" select="'no'"/>
    <xsl:with-param name="is_param_section" select="'yes'"/>
    <xsl:with-param name="section_text" select="$form_what_section"/>
    <xsl:with-param name="is_param_class" select="'yes'"/>
    <xsl:with-param name="is_param_class_prefix" select="'no'"/>
    <xsl:with-param name="is_param_class_bases_prefix" select="'no'"/>
    <xsl:with-param name="is_param_class_object" select="'no'"/>
    <xsl:with-param name="is_param_class_template" select="'no'"/>
    <xsl:with-param name="is_param_class_template_parameters" select="'yes'"/>
    <xsl:with-param name="class_template_parameters_text_before" select="'&lt;short&gt;:&lt;long&gt;=&lt;name&gt;'"/>
    <xsl:with-param name="class_template_parameters_text_after" select="';...'"/>
    <xsl:with-param name="is_param_class_extends_access" select="'no'"/>
    <xsl:with-param name="is_param_class_implements_access" select="'no'"/>
    <xsl:with-param name="class_implements_text_before" select="'#ifndef _'"/>
    <xsl:with-param name="class_implements_text_after" select="'_?_?'"/>
    <xsl:with-param name="is_param_class_access" select="'no'"/>
    <xsl:with-param name="is_param_class_derives" select="'no'"/>
    <xsl:with-param name="class" select="$default_cxx_form_class"/>
    <xsl:with-param name="class_extends" select="$default_cxx_form_class_extends"/>
    <xsl:with-param name="class_extends_text_before" select="':'"/>
</xsl:call-template>
<xsl:call-template name="getopt_form_fields">
</xsl:call-template>
<xsl:call-template name="form_form_fields">
</xsl:call-template>
</xsl:template>

</xsl:transform>

        

