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
<!--   File: medusaxde-create-medusaxde-menu.xsl                            -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 5/5/2011                                                       -->
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
<xsl:param name="default_xde_form_title_what" select="'Medusa XDE Menu'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/medusaxde/medusaxde-menu.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="xml_versions_tree">
    <version>1.0</version>
    <version default="yes" value="">none</version>
</xsl:variable>
<xsl:variable name="xml_versions"
 select="exsl:node-set($xml_versions_tree)"/>

<xsl:variable name="xml_encoding_types_tree">
    <type>utf-8</type>
    <type default="yes" value="">none</type>
</xsl:variable>
<xsl:variable name="xml_encoding_types"
 select="exsl:node-set($xml_encoding_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "xml_form_fields"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/7/2011                                                     -->
<!--========================================================================-->
<xsl:template name="xml_form_fields">

    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_xml_version" select="$is_param_"/>
    <xsl:param name="is_param_xml_encoding" select="$is_param_"/>

    <xsl:param name="xml_version_text" select="''"/>
    <xsl:param name="xml_version_text_before" select="'&lt;?xml version=&quot;'"/>
    <xsl:param name="xml_version_text_after" select="'&quot;'"/>
    <xsl:param name="xml_version_option" select="''"/>
    <xsl:param name="xml_version_options" select="$xml_versions/*"/>
    <xsl:param name="xml_version_param" select="'xml_version'"/>
    <xsl:param name="xml_version" select="''"/>

    <xsl:param name="xml_encoding_text" select="''"/>
    <xsl:param name="xml_encoding_text_before" select="'encoding=&quot;'"/>
    <xsl:param name="xml_encoding_text_after" select="'&quot;?&gt;'"/>
    <xsl:param name="xml_encoding_option" select="''"/>
    <xsl:param name="xml_encoding_options" select="$xml_encoding_types/*"/>
    <xsl:param name="xml_encoding_param" select="'xml_encoding'"/>
    <xsl:param name="xml_encoding" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_version)) or ('yes' = $is_param_xml_version)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$xml_version_text"/>
        <xsl:with-param name="text_before" select="$xml_version_text_before"/>
        <xsl:with-param name="text_after" select="$xml_version_text_after"/>
        <xsl:with-param name="name" select="$xml_version_param"/>
        <xsl:with-param name="value" select="$xml_version"/>
        <xsl:with-param name="option" select="$xml_version_options"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_encoding)) or ('yes' = $is_param_xml_encoding)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$xml_encoding_text"/>
        <xsl:with-param name="text_before" select="$xml_encoding_text_before"/>
        <xsl:with-param name="text_after" select="$xml_encoding_text_after"/>
        <xsl:with-param name="name" select="$xml_encoding_param"/>
        <xsl:with-param name="value" select="$xml_encoding"/>
        <xsl:with-param name="option" select="$xml_encoding_options"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "menu_form_fields"                                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/5/2011                                                     -->
<!--========================================================================-->
<xsl:template name="menu_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_id" select="$is_param_"/>
    <xsl:param name="is_param_section" select="$is_param_"/>

    <xsl:param name="section_text" select="'Medusa XDE Menu Parameters'"/>

    <xsl:param name="id_text" select="''"/>
    <xsl:param name="id_text_before" select="'&lt;menu id=&quot;'"/>
    <xsl:param name="id_text_after" select="'&quot;&gt;'"/>
    <xsl:param name="id_param" select="'id'"/>
    <xsl:param name="id" select="''"/>

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
    <xsl:call-template name="xml_form_fields">
        <xsl:with-param name="xml_version" select="'1.0'"/>
        <xsl:with-param name="xml_encoding" select="'utf-8'"/>
    </xsl:call-template>
    <xsl:call-template name="menu_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
        

