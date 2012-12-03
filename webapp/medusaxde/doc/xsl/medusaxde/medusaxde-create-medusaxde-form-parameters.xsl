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
<!--   File: medusaxde-create-medusaxde-form-parameters.xsl                 -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 4/9/2011                                                       -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde mxde medusade msxsl"
 version="1.0">

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../medusaxde-create.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_what" select="'Medusa XDE Form Parameters'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/medusaxde/medusaxde-form-parameters.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="xsl_template_type_tree">
    <type default="yes" value="name">name</type>
    <type value="match">match</type>
</xsl:variable>
<xsl:variable name="xsl_template_types"
 select="exsl:node-set($xsl_template_type_tree)"/>

<xsl:variable name="mxde_section_types_tree">
    <type xdefault="" name="">section</type>
    <type xdefault="" name="">subsection</type>
    <type xdefault="" name="">separator_section</type>
    <type xdefault="" name="">section_separator</type>
</xsl:variable>
<xsl:variable name="mxde_section_types"
 select="exsl:node-set($mxde_section_types_tree)"/>

<xsl:variable name="mxde_input_types_tree">
    <type default="" name="">input</type>
    <type xdefault="" name="">hidden</type>
    <type xdefault="" name="">static</type>
</xsl:variable>
<xsl:variable name="mxde_input_types"
 select="exsl:node-set($mxde_input_types_tree)"/>

<xsl:variable name="mxde_button_types_tree">
    <type xdefault="" name="">yesno</type>
    <type xdefault="" name="">noyes</type>
    <type xdefault="" name="">radios</type>
    <type xdefault="" name="">checkboxes</type>
    <type xdefault="" name="">checkbox</type>
</xsl:variable>
<xsl:variable name="mxde_button_types"
 select="exsl:node-set($mxde_button_types_tree)"/>

<xsl:variable name="mxde_list_types_tree">
    <type xdefault="" name="">listbox</type>
    <type xdefault="" name="">dropbox</type>
</xsl:variable>
<xsl:variable name="mxde_list_types"
 select="exsl:node-set($mxde_list_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "form_parameters_form_fields"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/9/2011                                                     -->
<!--========================================================================-->
<xsl:template name="form_parameters_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_template_type" select="''"/>
    <xsl:param name="is_param_template_name" select="''"/>
    <xsl:param name="is_param_template_separator" select="''"/>
    <xsl:param name="is_param_name" select="''"/>
    <xsl:param name="is_param_select" select="''"/>
    <xsl:param name="is_param_type" select="''"/>
    <xsl:param name="is_param_options" select="$is_param_"/>
    <xsl:param name="is_param_option" select="$is_param_"/>
    <xsl:param name="is_param_text" select="$is_param_"/>
    <xsl:param name="is_param_text_before" select="$is_param_"/>
    <xsl:param name="is_param_text_after" select="$is_param_"/>

    <xsl:param name="section_text" select="$default_xde_form_title_what"/>

    <xsl:param name="template_type_text" select="''"/>
    <xsl:param name="template_type_text_before" select="'&lt;xsl:template'"/>
    <xsl:param name="template_type_text_after" select="''"/>
    <xsl:param name="template_type_param" select="'template_type'"/>
    <xsl:param name="template_type" select="''"/>

    <xsl:param name="template_name_text" select="''"/>
    <xsl:param name="template_name_text_before" select="'=&quot;'"/>
    <xsl:param name="template_name_text_after" select="'&quot;'"/>
    <xsl:param name="template_name_param" select="'template_name'"/>
    <xsl:param name="template_name" select="'form_fields'"/>

    <xsl:param name="name_text" select="''"/>
    <xsl:param name="name_text_before" select="'&lt;xsl:param name=&quot;'"/>
    <xsl:param name="name_text_after" select="'&quot;'"/>
    <xsl:param name="name_param" select="'name'"/>
    <xsl:param name="name" select="'p'"/>

    <xsl:param name="select_text" select="''"/>
    <xsl:param name="select_text_before" select="'select=&quot;'"/>
    <xsl:param name="select_text_after" select="'&quot;'"/>
    <xsl:param name="select_param" select="'select'"/>
    <xsl:param name="select" select="''"/>

    <xsl:param name="type_text" select="''"/>
    <xsl:param name="type_text_before" select="''"/>
    <xsl:param name="type_text_after" select="''"/>
    <xsl:param name="type_param" select="'type'"/>
    <xsl:param name="type" select="''"/>

    <xsl:param name="options_text" select="''"/>
    <xsl:param name="options_text_before" select="'&quot;options&quot;=&quot;'"/>
    <xsl:param name="options_text_after" select="'&quot;'"/>
    <xsl:param name="options_option" select="''"/>
    <xsl:param name="options_options" select="''"/>
    <xsl:param name="options_param" select="'options'"/>
    <xsl:param name="options" select="'%name%s/*'"/>

    <xsl:param name="option_text" select="''"/>
    <xsl:param name="option_text_before" select="'&quot;option&quot;=&quot;'"/>
    <xsl:param name="option_text_after" select="'&quot;'"/>
    <xsl:param name="option_option" select="''"/>
    <xsl:param name="option_options" select="''"/>
    <xsl:param name="option_param" select="'option'"/>
    <xsl:param name="option" select="''"/>

    <xsl:param name="text_text" select="''"/>
    <xsl:param name="text_text_before" select="'&quot;text&quot;=&quot;'"/>
    <xsl:param name="text_text_after" select="'&quot;'"/>
    <xsl:param name="text_option" select="''"/>
    <xsl:param name="text_options" select="''"/>
    <xsl:param name="text_param" select="'text'"/>
    <xsl:param name="text" select="''"/>

    <xsl:param name="text_before_text" select="''"/>
    <xsl:param name="text_before_text_before" select="'&quot;text_before&quot;=&quot;'"/>
    <xsl:param name="text_before_text_after" select="'&quot;'"/>
    <xsl:param name="text_before_option" select="''"/>
    <xsl:param name="text_before_options" select="''"/>
    <xsl:param name="text_before_param" select="'text_before'"/>
    <xsl:param name="text_before" select="''"/>

    <xsl:param name="text_after_text" select="''"/>
    <xsl:param name="text_after_text_before" select="'&quot;text_after&quot;=&quot;'"/>
    <xsl:param name="text_after_text_after" select="'&quot;'"/>
    <xsl:param name="text_after_option" select="''"/>
    <xsl:param name="text_after_options" select="''"/>
    <xsl:param name="text_after_param" select="'text_after'"/>
    <xsl:param name="text_after" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
    <xsl:call-template name="section_row">
        <xsl:with-param name="text" select="$section_text"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_type)) or ('yes' = $is_param_template_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$template_type_text"/>
        <xsl:with-param name="text_before" select="$template_type_text_before"/>
        <xsl:with-param name="text_after" select="$template_type_text_after"/>
        <xsl:with-param name="name" select="$template_type_param"/>
        <xsl:with-param name="value" select="$template_type"/>
        <xsl:with-param name="option" select="$xsl_template_types/*"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_name)) or ('yes' = $is_param_template_name)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$template_name_text"/>
        <xsl:with-param name="text_before" select="$template_name_text_before"/>
        <xsl:with-param name="text_after" select="$template_name_text_after"/>
        <xsl:with-param name="name" select="$template_name_param"/>
        <xsl:with-param name="value" select="$template_name"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_separator)) or ('yes' = $is_param_template_separator)">
    <xsl:call-template name="separator_section_row">
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_name)) or ('yes' = $is_param_name)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$name_text"/>
        <xsl:with-param name="text_before" select="$name_text_before"/>
        <xsl:with-param name="text_after" select="$name_text_after"/>
        <xsl:with-param name="name" select="$name_param"/>
        <xsl:with-param name="value" select="$name"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_select)) or ('yes' = $is_param_select)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$select_text"/>
        <xsl:with-param name="text_before" select="$select_text_before"/>
        <xsl:with-param name="text_after" select="$select_text_after"/>
        <xsl:with-param name="name" select="$select_param"/>
        <xsl:with-param name="value" select="$select"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_type)) or ('yes' = $is_param_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$type_text"/>
        <xsl:with-param name="text_before" select="$type_text_before"/>
        <xsl:with-param name="text_after" select="$type_text_after"/>
        <xsl:with-param name="name" select="$type_param"/>
        <xsl:with-param name="value" select="$type"/>
        <xsl:with-param name="option" select="$mxde_section_types/*"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_type)) or ('yes' = $is_param_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$type_text"/>
        <xsl:with-param name="text_before" select="$type_text_before"/>
        <xsl:with-param name="text_after" select="$type_text_after"/>
        <xsl:with-param name="name" select="$type_param"/>
        <xsl:with-param name="value" select="$type"/>
        <xsl:with-param name="option" select="$mxde_input_types/*"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_type)) or ('yes' = $is_param_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$type_text"/>
        <xsl:with-param name="text_before" select="$type_text_before"/>
        <xsl:with-param name="text_after" select="$type_text_after"/>
        <xsl:with-param name="name" select="$type_param"/>
        <xsl:with-param name="value" select="$type"/>
        <xsl:with-param name="option" select="$mxde_button_types/*"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_type)) or ('yes' = $is_param_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$type_text"/>
        <xsl:with-param name="text_before" select="$type_text_before"/>
        <xsl:with-param name="text_after" select="$type_text_after"/>
        <xsl:with-param name="name" select="$type_param"/>
        <xsl:with-param name="value" select="$type"/>
        <xsl:with-param name="option" select="$mxde_list_types/*"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_options)) or ('yes' = $is_param_options)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$options_text"/>
        <xsl:with-param name="text_before" select="$options_text_before"/>
        <xsl:with-param name="text_after" select="$options_text_after"/>
        <xsl:with-param name="name" select="$options_param"/>
        <xsl:with-param name="value" select="$options"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_option)) or ('yes' = $is_param_option)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$option_text"/>
        <xsl:with-param name="text_before" select="$option_text_before"/>
        <xsl:with-param name="text_after" select="$option_text_after"/>
        <xsl:with-param name="name" select="$option_param"/>
        <xsl:with-param name="value" select="$option"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_text)) or ('yes' = $is_param_text)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$text_text"/>
        <xsl:with-param name="text_before" select="$text_text_before"/>
        <xsl:with-param name="text_after" select="$text_text_after"/>
        <xsl:with-param name="name" select="$text_param"/>
        <xsl:with-param name="value" select="$text"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_text_before)) or ('yes' = $is_param_text_before)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$text_before_text"/>
        <xsl:with-param name="text_before" select="$text_before_text_before"/>
        <xsl:with-param name="text_after" select="$text_before_text_after"/>
        <xsl:with-param name="name" select="$text_before_param"/>
        <xsl:with-param name="value" select="$text_before"/>
     </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_text_after)) or ('yes' = $is_param_text_after)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$text_after_text"/>
        <xsl:with-param name="text_before" select="$text_after_text_before"/>
        <xsl:with-param name="text_after" select="$text_after_text_after"/>
        <xsl:with-param name="name" select="$text_after_param"/>
        <xsl:with-param name="value" select="$text_after"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/9/2011                                                     -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="form_parameters_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
        

