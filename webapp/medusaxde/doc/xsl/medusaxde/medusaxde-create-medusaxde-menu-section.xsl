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
<!--   File: medusaxde-create-medusaxde-menu-section.xsl                    -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 5/5/2011                                                       -->
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
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../medusaxde-create.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_what" select="'Medusa XDE Menu Section'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/medusaxde/medusaxde-menu-section.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "menu_section_form_fields"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/5/2011                                                     -->
<!--========================================================================-->
<xsl:template name="menu_section_form_fields">
    <xsl:param name="is_param_" select="''"/>

    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_id" select="$is_param_"/>
    <xsl:param name="is_param_for" select="$is_param_"/>
    <xsl:param name="is_param_or_not_for" select="$is_param_"/>
    <xsl:param name="is_param_using" select="$is_param_"/>
    <xsl:param name="is_param_or_not_using" select="$is_param_"/>
    <xsl:param name="is_param_text" select="$is_param_"/>

    <xsl:param name="section_text" select="'Medusa XDE Menu Section Parameters'"/>

    <xsl:param name="id_text" select="''"/>
    <xsl:param name="id_text_before" select="'&lt;menu-section id=&quot;'"/>
    <xsl:param name="id_text_after" select="'&quot;'"/>
    <xsl:param name="id_param" select="'id'"/>
    <xsl:param name="id" select="''"/>

    <xsl:param name="for_text" select="''"/>
    <xsl:param name="for_text_before" select="'for=&quot;'"/>
    <xsl:param name="for_text_after" select="'&quot;'"/>
    <xsl:param name="for_param" select="'for'"/>
    <xsl:param name="for" select="''"/>

    <xsl:param name="or_not_for_text" select="''"/>
    <xsl:param name="or_not_for_text_before" select="'or_not_for=&quot;'"/>
    <xsl:param name="or_not_for_text_after" select="'&quot;'"/>
    <xsl:param name="or_not_for_param" select="'or_not_for'"/>
    <xsl:param name="or_not_for" select="'no'"/>

    <xsl:param name="using_text" select="''"/>
    <xsl:param name="using_text_before" select="'using=&quot;'"/>
    <xsl:param name="using_text_after" select="'&quot;'"/>
    <xsl:param name="using_param" select="'using'"/>
    <xsl:param name="using" select="''"/>

    <xsl:param name="or_not_using_text" select="''"/>
    <xsl:param name="or_not_using_text_before" select="'or_not_using=&quot;'"/>
    <xsl:param name="or_not_using_text_after" select="'&quot;&gt;'"/>
    <xsl:param name="or_not_using_param" select="'or_not_using'"/>
    <xsl:param name="or_not_using" select="'no'"/>

    <xsl:param name="text_text" select="''"/>
    <xsl:param name="text_text_before" select="'&lt;text&gt;'"/>
    <xsl:param name="text_text_after" select="'&lt;/text&gt;'"/>
    <xsl:param name="text_param" select="'text'"/>
    <xsl:param name="text" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
    <xsl:call-template name="section_row">
        <xsl:with-param name="text" select="$section_text"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_id)) or ('yes' = $is_param_id)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$id_text"/>
        <xsl:with-param name="text_before" select="$id_text_before"/>
        <xsl:with-param name="text_after" select="$id_text_after"/>
        <xsl:with-param name="name" select="$id_param"/>
        <xsl:with-param name="value" select="$id"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_for)) or ('yes' = $is_param_for)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$for_text"/>
        <xsl:with-param name="text_before" select="$for_text_before"/>
        <xsl:with-param name="text_after" select="$for_text_after"/>
        <xsl:with-param name="name" select="$for_param"/>
        <xsl:with-param name="value" select="$for"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_or_not_for)) or ('yes' = $is_param_or_not_for)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$or_not_for_text"/>
        <xsl:with-param name="text_before" select="$or_not_for_text_before"/>
        <xsl:with-param name="text_after" select="$or_not_for_text_after"/>
        <xsl:with-param name="name" select="$or_not_for_param"/>
        <xsl:with-param name="value" select="$or_not_for"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_using)) or ('yes' = $is_param_using)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$using_text"/>
        <xsl:with-param name="text_before" select="$using_text_before"/>
        <xsl:with-param name="text_after" select="$using_text_after"/>
        <xsl:with-param name="name" select="$using_param"/>
        <xsl:with-param name="value" select="$using"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_or_not_using)) or ('yes' = $is_param_or_not_using)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$or_not_using_text"/>
        <xsl:with-param name="text_before" select="$or_not_using_text_before"/>
        <xsl:with-param name="text_after" select="$or_not_using_text_after"/>
        <xsl:with-param name="name" select="$or_not_using_param"/>
        <xsl:with-param name="value" select="$or_not_using"/>
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

</xsl:template>

<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/5/2011                                                     -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="menu_section_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
        

