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
<!--   File:  medusaxde-objcxx-form-templates.xsl                           -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/9/2012                                                       -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "objcxx_file_form_fields"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/9/2012                                                     -->
<!--========================================================================-->
<xsl:template name="objcxx_file_form_fields">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_begin_separator" select="'no'"/>
    <xsl:param name="is_param_end_separator" select="'no'"/>
    <xsl:param name="is_param_module" select="$is_param_"/>
    <xsl:param name="is_param_import" select="$is_param_"/>
    <xsl:param name="is_param_import_system" select="$is_param_"/>

    <xsl:param name="module_text" select="''"/>
    <xsl:param name="module_text_before" select="'#ifndef _'"/>
    <xsl:param name="module_text_after" select="'_?_?'"/>
    <xsl:param name="module_param" select="'module'"/>
    <xsl:param name="module" select="''"/>

    <xsl:param name="import_text" select="''"/>
    <xsl:param name="import_text_before" select="'#import &quot;'"/>
    <xsl:param name="import_text_after" select="'&quot;'"/>
    <xsl:param name="import_param" select="'import'"/>
    <xsl:param name="import" select="''"/>

    <xsl:param name="import_system_text" select="''"/>
    <xsl:param name="import_system_text_before" select="'#import &lt;'"/>
    <xsl:param name="import_system_text_after" select="'&gt;'"/>
    <xsl:param name="import_system_param" select="'import_system'"/>
    <xsl:param name="import_system" select="''"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_begin_separator)) or ('yes' = $is_param_begin_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_module)) or ('yes' = $is_param_module)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$module_text"/>
            <xsl:with-param name="text_before" select="$module_text_before"/>
            <xsl:with-param name="text_after" select="$module_text_after"/>
            <xsl:with-param name="name" select="$module_param"/>
            <xsl:with-param name="value" select="$module"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_import)) or ('yes' = $is_param_import)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$import_text"/>
            <xsl:with-param name="text_before" select="$import_text_before"/>
            <xsl:with-param name="text_after" select="$import_text_after"/>
            <xsl:with-param name="name" select="$import_param"/>
            <xsl:with-param name="value" select="$import"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_import_system)) or ('yes' = $is_param_import_system)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$import_system_text"/>
            <xsl:with-param name="text_before" select="$import_system_text_before"/>
            <xsl:with-param name="text_after" select="$import_system_text_after"/>
            <xsl:with-param name="name" select="$import_system_param"/>
            <xsl:with-param name="value" select="$import_system"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_end_separator)) or ('yes' = $is_param_end_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
</xsl:template>
</xsl:transform>
