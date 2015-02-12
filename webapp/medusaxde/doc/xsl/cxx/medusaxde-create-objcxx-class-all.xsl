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
<!--   File: medusaxde-create-objcxx-class-all.xsl                          -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/8/2012                                                       -->
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
<xsl:include href="medusaxde-create-objcxx-class-part.xsl"/>

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
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2012                                                     -->
<!--========================================================================-->
<xsl:template name="form_fields">
    <xsl:call-template name="cxx_file_form_fields">
        <xsl:with-param name="section_text" select="$form_section"/>
        <xsl:with-param name="is_param_file_case_is" select="'no'"/>
        <xsl:with-param name="is_param_file_name_is" select="'no'"/>
        <xsl:with-param name="is_param_code_style" select="'no'"/>
    </xsl:call-template>
    <xsl:call-template name="objcxx_file_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_begin_separator" select="'yes'"/>
        <xsl:with-param name="is_param_module" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_include" select="'yes'"/>
        <xsl:with-param name="is_param_include_system" select="'yes'"/>
        <xsl:with-param name="is_param_namespace" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="objcxx_file_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_begin_separator" select="'yes'"/>
        <xsl:with-param name="is_param_import" select="'yes'"/>
        <xsl:with-param name="is_param_import_system" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="objcxx_class_form_fields">
        <xsl:with-param name="is_param_" select="''"/>
        <xsl:with-param name="class" select="$default_objcxx_form_class"/>
        <xsl:with-param name="class_type" select="$default_objcxx_form_class_type"/>
        <xsl:with-param name="class_implements" select="$default_objcxx_form_class_implements"/>
        <xsl:with-param name="class_extends" select="$default_objcxx_form_class_extends"/>
        <xsl:with-param name="class_constructor" select="$default_objcxx_form_class_constructor"/>
        <xsl:with-param name="class_destructor" select="$default_objcxx_form_class_destructor"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_function_separator" select="'yes'"/>
        <xsl:with-param name="is_param_function_main" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_section" select="'yes'"/>
        <xsl:with-param name="is_param_typedef" select="'yes'"/>
        <xsl:with-param name="is_param_enum" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_ifdef_separator" select="'yes'"/>
        <xsl:with-param name="is_param_ifdef" select="'yes'"/>
        <xsl:with-param name="is_param_ifndef" select="'yes'"/>
        <xsl:with-param name="is_param_define" select="'yes'"/>
        <xsl:with-param name="is_param_undef" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="file_creation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="transformation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="form_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
