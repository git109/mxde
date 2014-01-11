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
<!--   File: medusaxde-create-fb-jsapi-cxx.xsl                              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/7/2012                                                       -->
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
<xsl:param name="default_xde_form_title_what" select="'FireBreath C++ JSAPI'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/xsl/firebreath/JavaScriptAPI.xslt'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="class_prefixes_tree">
    <prefix default="yes" value="c">c</prefix>
    <prefix value="C">C</prefix>
    <prefix value="">no</prefix>
</xsl:variable>
<xsl:variable name="class_prefixes" select="exsl:node-set($class_prefixes_tree)"/>

<xsl:variable name="class_types_tree">
    <type default="yes" value="_INTERFACE_CLASS">interface</type>
    <type value="_IMPLEMENT_CLASS">implement</type>
    <type value="_EXPORT_CLASS">export</type>
    <type value="">no</type>
</xsl:variable>
<xsl:variable name="class_types" select="exsl:node-set($class_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "jsapi_form_fields"                                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/11/2012                                                    -->
<!--========================================================================-->
<xsl:template name="jsapi_form_fields">

    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_include" select="$is_param_"/>
    <xsl:param name="is_param_c_NAMESPACE" select="$is_param_"/>
    <xsl:param name="is_param_class_prefix" select="$is_param_"/>
    <xsl:param name="is_param_class_type" select="$is_param_"/>
    <xsl:param name="is_param_class" select="$is_param_"/>

    <xsl:param name="include_text" select="''"/>
    <xsl:param name="include_text_before" select="'#include &quot;'"/>
    <xsl:param name="include_text_after" select="'&quot;'"/>
    <xsl:param name="include_param" select="'include'"/>
    <xsl:param name="include" select="'cInterfaceBase.hpp'"/>

    <xsl:param name="c_NAMESPACE_text" select="''"/>
    <xsl:param name="c_NAMESPACE_text_before" select="'#if defined('"/>
    <xsl:param name="c_NAMESPACE_text_after" select="') namespace ? {'"/>
    <xsl:param name="c_NAMESPACE_param" select="'c_NAMESPACE'"/>
    <xsl:param name="c_NAMESPACE" select="'c_NAMESPACE'"/>

    <xsl:param name="class_prefix_text" select="''"/>
    <xsl:param name="class_prefix_text_before" select="'c...'"/>
    <xsl:param name="class_prefix_text_after" select="''"/>
    <xsl:param name="class_prefix_option" select="''"/>
    <xsl:param name="class_prefix_options" select="$class_prefixes/*"/>
    <xsl:param name="class_prefix_param" select="'class_prefix'"/>
    <xsl:param name="class_prefix" select="''"/>
    
    <xsl:param name="class_text" select="''"/>
    <xsl:param name="class_text_before" select="'class'"/>
    <xsl:param name="class_text_after" select="''"/>
    <xsl:param name="class_param" select="'class'"/>
    <xsl:param name="class" select="''"/>

    <xsl:param name="class_type_text" select="''"/>
    <xsl:param name="class_type_text_before" select="''"/>
    <xsl:param name="class_type_text_after" select="''"/>
    <xsl:param name="class_type_option" select="''"/>
    <xsl:param name="class_type_options" select="$class_types/*"/>
    <xsl:param name="class_type_param" select="'class_type'"/>
    <xsl:param name="class_type" select="''"/>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_include)) or ('yes' = $is_param_include)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$include_text"/>
        <xsl:with-param name="text_before" select="$include_text_before"/>
        <xsl:with-param name="text_after" select="$include_text_after"/>
        <xsl:with-param name="name" select="$include_param"/>
        <xsl:with-param name="value" select="$include"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_c_NAMESPACE)) or ('yes' = $is_param_c_NAMESPACE)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$c_NAMESPACE_text"/>
            <xsl:with-param name="text_before" select="$c_NAMESPACE_text_before"/>
            <xsl:with-param name="text_after" select="$c_NAMESPACE_text_after"/>
            <xsl:with-param name="name" select="$c_NAMESPACE_param"/>
            <xsl:with-param name="value" select="$c_NAMESPACE"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_prefix)) or ('yes' = $is_param_class_prefix)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_prefix_text"/>
            <xsl:with-param name="text_before" select="$class_prefix_text_before"/>
            <xsl:with-param name="text_after" select="$class_prefix_text_after"/>
            <xsl:with-param name="name" select="$class_prefix_param"/>
            <xsl:with-param name="value" select="$class_prefix"/>
            <xsl:with-param name="option" select="$class_prefix_options"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_type)) or ('yes' = $is_param_class_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_type_text"/>
            <xsl:with-param name="text_before" select="$class_type_text_before"/>
            <xsl:with-param name="text_after" select="$class_type_text_after"/>
            <xsl:with-param name="name" select="$class_type_param"/>
            <xsl:with-param name="value" select="$class_type"/>
            <xsl:with-param name="option" select="$class_type_options"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class)) or ('yes' = $is_param_class)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_text"/>
            <xsl:with-param name="text_before" select="$class_text_before"/>
            <xsl:with-param name="text_after" select="$class_text_after"/>
            <xsl:with-param name="name" select="$class_param"/>
            <xsl:with-param name="value" select="$class"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/7/2012                                                     -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="file" select="'cFBPlugin_JavaScriptAPI'"/>
        <xsl:with-param name="date" select="$current_date"/>
        <xsl:with-param name="year" select="$current_year"/>
    </xsl:call-template>
    <xsl:call-template name="jsapi_form_fields">
        <xsl:with-param name="class" select="'cFBPlugin_JavaScriptAPI'"/>
        <xsl:with-param name="class_prefix" select="'c'"/>
        <xsl:with-param name="class_type" select="'_INTERFACE_CLASS'"/>
    </xsl:call-template>
</xsl:template>
</xsl:transform>

