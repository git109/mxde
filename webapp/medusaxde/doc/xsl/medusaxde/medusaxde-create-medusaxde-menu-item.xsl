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
<!--   File: medusaxde-create-medusaxde-menu-item.xsl                       -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 4/9/2011                                                       -->
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
<xsl:param name="default_xde_form_title_what" select="'Medusa XDE Menu Item'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/medusaxde/medusaxde-menu-item.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "menu_item_form_fields"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/24/2011                                                    -->
<!--========================================================================-->
<xsl:template name="menu_item_form_fields">

    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_id" select="$is_param_"/>
    <xsl:param name="is_param_is_separator" select="$is_param_"/>
    <xsl:param name="is_param_is_location_query_and" select="$is_param_"/>
    <xsl:param name="is_param_is_location_query_and_for" select="$is_param_"/>
    <xsl:param name="is_param_is_location_query_and_using" select="$is_param_"/>
    <xsl:param name="is_param_location_path" select="$is_param_"/>
    <xsl:param name="is_param_location_query" select="$is_param_"/>
    <xsl:param name="is_param_location" select="$is_param_"/>
    <xsl:param name="is_param_text" select="$is_param_"/>

    <xsl:param name="section_text" select="'Medusa XDE Menu Item Parameters'"/>

    <xsl:param name="id_text" select="''"/>
    <xsl:param name="id_text_before" select="'&lt;menu-item id=&quot;'"/>
    <xsl:param name="id_text_after" select="'&quot;'"/>
    <xsl:param name="id_param" select="'id'"/>
    <xsl:param name="id" select="''"/>

    <xsl:param name="is_separator_text" select="''"/>
    <xsl:param name="is_separator_text_before" select="'is_separator=&quot;'"/>
    <xsl:param name="is_separator_text_after" select="'&quot;'"/>
    <xsl:param name="is_separator_param" select="'is_separator'"/>
    <xsl:param name="is_separator" select="'no'"/>

    <xsl:param name="is_location_query_and_text" select="''"/>
    <xsl:param name="is_location_query_and_text_before" select="'is_location_query_and=&quot;'"/>
    <xsl:param name="is_location_query_and_text_after" select="'&quot;'"/>
    <xsl:param name="is_location_query_and_param" select="'is_location_query_and'"/>
    <xsl:param name="is_location_query_and" select="'yes'"/>

    <xsl:param name="is_location_query_and_for_text" select="''"/>
    <xsl:param name="is_location_query_and_for_text_before" select="'is_location_query_and_for=&quot;'"/>
    <xsl:param name="is_location_query_and_for_text_after" select="'&quot;'"/>
    <xsl:param name="is_location_query_and_for_param" select="'is_location_query_and_for'"/>
    <xsl:param name="is_location_query_and_for" select="'yes'"/>

    <xsl:param name="is_location_query_and_using_text" select="''"/>
    <xsl:param name="is_location_query_and_using_text_before" select="'is_location_query_and_using=&quot;'"/>
    <xsl:param name="is_location_query_and_using_text_after" select="'&quot;'"/>
    <xsl:param name="is_location_query_and_using_param" select="'is_location_query_and_using'"/>
    <xsl:param name="is_location_query_and_using" select="'yes'"/>

    <xsl:param name="location_path_text" select="''"/>
    <xsl:param name="location_path_text_before" select="'location_path=&quot;'"/>
    <xsl:param name="location_path_text_after" select="'&quot;'"/>
    <xsl:param name="location_path_param" select="'location_path'"/>
    <xsl:param name="location_path" select="''"/>

    <xsl:param name="location_query_text" select="''"/>
    <xsl:param name="location_query_text_before" select="'location_query=&quot;'"/>
    <xsl:param name="location_query_text_after" select="'&quot;'"/>
    <xsl:param name="location_query_param" select="'location_query'"/>
    <xsl:param name="location_query" select="''"/>

    <xsl:param name="location_text" select="''"/>
    <xsl:param name="location_text_before" select="'location=&quot;'"/>
    <xsl:param name="location_text_after" select="'&quot;&gt;'"/>
    <xsl:param name="location_param" select="'location'"/>
    <xsl:param name="location" select="''"/>

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

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_is_separator)) or ('yes' = $is_param_is_separator)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$is_separator_text"/>
        <xsl:with-param name="text_before" select="$is_separator_text_before"/>
        <xsl:with-param name="text_after" select="$is_separator_text_after"/>
        <xsl:with-param name="name" select="$is_separator_param"/>
        <xsl:with-param name="value" select="$is_separator"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_is_location_query_and)) or ('yes' = $is_param_is_location_query_and)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$is_location_query_and_text"/>
        <xsl:with-param name="text_before" select="$is_location_query_and_text_before"/>
        <xsl:with-param name="text_after" select="$is_location_query_and_text_after"/>
        <xsl:with-param name="name" select="$is_location_query_and_param"/>
        <xsl:with-param name="value" select="$is_location_query_and"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_is_location_query_and_for)) or ('yes' = $is_param_is_location_query_and_for)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$is_location_query_and_for_text"/>
        <xsl:with-param name="text_before" select="$is_location_query_and_for_text_before"/>
        <xsl:with-param name="text_after" select="$is_location_query_and_for_text_after"/>
        <xsl:with-param name="name" select="$is_location_query_and_for_param"/>
        <xsl:with-param name="value" select="$is_location_query_and_for"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_is_location_query_and_using)) or ('yes' = $is_param_is_location_query_and_using)">
    <xsl:call-template name="yesno_row">
        <xsl:with-param name="text" select="$is_location_query_and_using_text"/>
        <xsl:with-param name="text_before" select="$is_location_query_and_using_text_before"/>
        <xsl:with-param name="text_after" select="$is_location_query_and_using_text_after"/>
        <xsl:with-param name="name" select="$is_location_query_and_using_param"/>
        <xsl:with-param name="value" select="$is_location_query_and_using"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_location_path)) or ('yes' = $is_param_location_path)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$location_path_text"/>
        <xsl:with-param name="text_before" select="$location_path_text_before"/>
        <xsl:with-param name="text_after" select="$location_path_text_after"/>
        <xsl:with-param name="name" select="$location_path_param"/>
        <xsl:with-param name="value" select="$location_path"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_location_query)) or ('yes' = $is_param_location_query)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$location_query_text"/>
        <xsl:with-param name="text_before" select="$location_query_text_before"/>
        <xsl:with-param name="text_after" select="$location_query_text_after"/>
        <xsl:with-param name="name" select="$location_query_param"/>
        <xsl:with-param name="value" select="$location_query"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_location)) or ('yes' = $is_param_location)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$location_text"/>
        <xsl:with-param name="text_before" select="$location_text_before"/>
        <xsl:with-param name="text_after" select="$location_text_after"/>
        <xsl:with-param name="name" select="$location_param"/>
        <xsl:with-param name="value" select="$location"/>
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
<!--     Date: 4/9/2011                                                     -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="menu_item_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
        

