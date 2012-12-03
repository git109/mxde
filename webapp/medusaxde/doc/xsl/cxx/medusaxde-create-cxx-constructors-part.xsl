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
<!--   File: medusaxde-create-cxx-constructors-part.xsl                     -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/20/2011                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde mxde medusade msxsl"
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
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 6/16/2010                                                    -->
<!--========================================================================-->
<xsl:template name="form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="cxx_file_form_fields">
        <xsl:with-param name="section_text" select="$form_section"/>
        <xsl:with-param name="is_param_file_case_is" select="'no'"/>
        <xsl:with-param name="is_param_file_name_is" select="'no'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_section" select="'yes'"/>
        <xsl:with-param name="section_text" select="$form_what_section"/>
        <xsl:with-param name="is_param_class_constructor" select="'yes'"/>
        <xsl:with-param name="class_constructor" select="$default_cxx_form_class_constructor"/>
        <xsl:with-param name="is_param_class_constructor_separator" select="'yes'"/>
        <xsl:with-param name="is_param_class_destructor" select="'yes'"/>
        <xsl:with-param name="class_destructor" select="$default_cxx_form_class_destructor"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_separator" select="'yes'"/>
        <xsl:with-param name="is_param_class_object" select="'no'"/>
        <xsl:with-param name="is_param_class" select="'yes'"/>
        <xsl:with-param name="class" select="$default_cxx_form_class"/>
        <xsl:with-param name="is_param_class_members_only_ifdefs_hidden" select="$default_cxx_form_class_members_only"/>
        <xsl:with-param name="class_members_only_ifdefs" select="$default_cxx_form_class_members_only"/>
    </xsl:call-template>
    <xsl:call-template name="file_creation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="transformation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="form_form_fields">
    </xsl:call-template>
</xsl:template>

</xsl:transform>
