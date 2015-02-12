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
<!--   File: medusaxde-create-cxx-class-all.xsl                             -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/13/2011                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:medusaxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde medusaxde medusade msxsl"
 version="1.0">

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="medusaxde-create-cxx-class-part.xsl"/>

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
<!-- Template: "extra_form_fields"                                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/8/2011                                                     -->
<!--========================================================================-->
<xsl:template name="extra_form_fields">

    <xsl:param name="is_param_" select="''"/>

    <xsl:param name="is_param_form" select="$is_param_"/>

    <xsl:param name="form_text" select="''"/>
    <xsl:param name="form_text_before" select="'form='"/>
    <xsl:param name="form_text_after" select="''"/>
    <xsl:param name="form_param" select="'form_param'"/>
    <!--xsl:param name="form" select="$form"/-->

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_form)) or ('yes' = $is_param_form)">
    <xsl:call-template name="static_row">
        <xsl:with-param name="text" select="$form_text"/>
        <xsl:with-param name="text_before" select="$form_text_before"/>
        <xsl:with-param name="text_after" select="$form_text_after"/>
        <xsl:with-param name="name" select="$form_param"/>
        <xsl:with-param name="value" select="$form"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/1/2011                                                     -->
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
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="section_text" select="$form_what_section"/>
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
    <!--xsl:call-template name="extra_form_fields">
    </xsl:call-template-->
</xsl:template>

</xsl:transform>
