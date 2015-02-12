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
<!--   File: medusaxde-create-cxx-class-attached.xsl                        -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 5/6/2012                                                       -->
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
<xsl:include href="medusaxde-create-cxx-class-derived-part.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_what_what" select="' c?Attached'"/>
<xsl:param name="default_xde_form_title_what_what_what_what" select="''"/>
<xsl:param name="default_cxx_form_class_interface" select="'export'"/>
<xsl:param name="default_cxx_form_class" select="''"/>
<xsl:param name="default_cxx_form_class_implements" select="''"/>
<xsl:param name="default_cxx_form_class_extends" select="''"/>
<xsl:param name="default_cxx_form_class_constructor" select="''"/>
<xsl:param name="default_cxx_form_class_destructor" select="''"/>
<xsl:param name="default_cxx_form_class_members_only" select="''"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/cxx/mxde-attached-hpp-cpp.t'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
    
<!--========================================================================-->
<!-- Template: "cxx_derived_class_form_fields"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/6/2012                                                     -->
<!--========================================================================-->
<xsl:template name="cxx_derived_class_form_fields">

    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_What" select="$is_param_"/>
    <xsl:param name="is_param_typedef" select="$is_param_"/>
    <xsl:param name="is_param_TAttached" select="$is_param_"/>
    <xsl:param name="is_param_TUnattached" select="$is_param_"/>
    <xsl:param name="is_param_VUnattached" select="$is_param_"/>

    <xsl:param name="section_text" select="''"/>

    <xsl:param name="What_text" select="''"/>
    <xsl:param name="What_text_before" select="'c'"/>
    <xsl:param name="What_text_after" select="'Attached;'"/>
    <xsl:param name="What_param" select="'What'"/>
    <xsl:param name="What" select="''"/>

    <xsl:param name="typedef_text" select="''"/>
    <xsl:param name="typedef_text_before" select="'typedef c'"/>
    <xsl:param name="typedef_text_after" select="'AttachedT'"/>
    <xsl:param name="typedef_param" select="'typedef_param'"/>
    <xsl:param name="typedef" select="''"/>

    <xsl:param name="TAttached_text" select="''"/>
    <xsl:param name="TAttached_text_before" select="'&lt;class Tattached='"/>
    <xsl:param name="TAttached_text_after" select="','"/>
    <xsl:param name="TAttached_param" select="'TAttached'"/>
    <xsl:param name="TAttached" select="''"/>

    <xsl:param name="TUnattached_text" select="''"/>
    <xsl:param name="TUnattached_text_before" select="'class TUnattached='"/>
    <xsl:param name="TUnattached_text_after" select="','"/>
    <xsl:param name="TUnattached_param" select="'TUnattached'"/>
    <xsl:param name="TUnattached" select="''"/>

    <xsl:param name="VUnattached_text" select="''"/>
    <xsl:param name="VUnattached_text_before" select="'TUnattached VUnattached='"/>
    <xsl:param name="VUnattached_text_after" select="'&gt;'"/>
    <xsl:param name="VUnattached_param" select="'VUnattached'"/>
    <xsl:param name="VUnattached" select="''"/>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
    <xsl:call-template name="section_row">
        <xsl:with-param name="text" select="$section_text"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_typedef)) or ('yes' = $is_param_typedef)">
        <xsl:call-template name="static_row">
            <xsl:with-param name="text" select="$typedef_text"/>
            <xsl:with-param name="text_before" select="$typedef_text_before"/>
            <xsl:with-param name="text_after" select="$typedef_text_after"/>
            <xsl:with-param name="name" select="$typedef_param"/>
            <xsl:with-param name="value" select="$typedef"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_TAttached)) or ('yes' = $is_param_TAttached)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$TAttached_text"/>
            <xsl:with-param name="text_before" select="$TAttached_text_before"/>
            <xsl:with-param name="text_after" select="$TAttached_text_after"/>
            <xsl:with-param name="name" select="$TAttached_param"/>
            <xsl:with-param name="value" select="$TAttached"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_TUnattached)) or ('yes' = $is_param_TUnattached)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$TUnattached_text"/>
            <xsl:with-param name="text_before" select="$TUnattached_text_before"/>
            <xsl:with-param name="text_after" select="$TUnattached_text_after"/>
            <xsl:with-param name="name" select="$TUnattached_param"/>
            <xsl:with-param name="value" select="$TUnattached"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_VUnattached)) or ('yes' = $is_param_VUnattached)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$VUnattached_text"/>
            <xsl:with-param name="text_before" select="$VUnattached_text_before"/>
            <xsl:with-param name="text_after" select="$VUnattached_text_after"/>
            <xsl:with-param name="name" select="$VUnattached_param"/>
            <xsl:with-param name="value" select="$VUnattached"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_What)) or ('yes' = $is_param_What)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$What_text"/>
            <xsl:with-param name="text_before" select="$What_text_before"/>
            <xsl:with-param name="text_after" select="$What_text_after"/>
            <xsl:with-param name="name" select="$What_param"/>
            <xsl:with-param name="value" select="$What"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/6/2012                                                     -->
<!--========================================================================-->
<xsl:template name="form_fields">
    <xsl:call-template name="cxx_file_form_fields">
        <xsl:with-param name="section_text" select="$form_section"/>
        <xsl:with-param name="is_param_file_case_is" select="'no'"/>
        <xsl:with-param name="is_param_file_name_is" select="'no'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_module" select="'yes'"/>
        <xsl:with-param name="is_param_include" select="'yes'"/>
        <xsl:with-param name="is_param_include_system" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_class_namespace" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_derived_class_form_fields">
        <xsl:with-param name="section_text" select="$form_what_section"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="section_text" select="$form_what_what_what_section"/>
        <xsl:with-param name="is_param_class_namespace" select="'no'"/>
        <xsl:with-param name="is_param_class_object">
            <xsl:choose>
                <xsl:when test="('yes' = $default_cxx_form_class_members_only)">
                    <xsl:value-of select="'yes'"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="'no'"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:with-param>
        <xsl:with-param name="class_interface" select="$default_cxx_form_class_interface"/>
        <xsl:with-param name="class" select="$default_cxx_form_class"/>
        <xsl:with-param name="class_implements" select="$default_cxx_form_class_implements"/>
        <xsl:with-param name="class_extends" select="$default_cxx_form_class_extends"/>
        <xsl:with-param name="class_constructor" select="$default_cxx_form_class_constructor"/>
        <xsl:with-param name="class_destructor" select="$default_cxx_form_class_destructor"/>
        <xsl:with-param name="is_param_class_members_only_ifdefs_hidden" select="$default_cxx_form_class_members_only"/>
        <xsl:with-param name="class_members_only_ifdefs" select="$default_cxx_form_class_members_only"/>
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
