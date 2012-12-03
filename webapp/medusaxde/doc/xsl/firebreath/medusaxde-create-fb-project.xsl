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
<!--   File: medusaxde-create-fb-project.xsl                                -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/6/2012                                                       -->
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
<xsl:param name="default_xde_form_title_what" select="'FireBreath Project'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/cmake/mxde-fb-pluginconfig-cmake.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "plugin_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template name="plugin_form_fields">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_separator_section" select="$is_param_"/>
    <xsl:param name="is_param_plugin_name" select="$is_param_"/>
    <xsl:param name="is_param_plugin_prefix" select="$is_param_"/>
    <xsl:param name="is_param_plugin_version" select="$is_param_"/>
    <xsl:param name="is_param_plugin_mimetype" select="$is_param_"/>
    <xsl:param name="is_param_plugin_uuid_1" select="$is_param_"/>
    <xsl:param name="is_param_plugin_uuid_2" select="$is_param_"/>
    <xsl:param name="is_param_plugin_uuid_3" select="$is_param_"/>
    <xsl:param name="is_param_plugin_uuid_4" select="$is_param_"/>
    <xsl:param name="is_param_plugin_uuid_5" select="$is_param_"/>
    <xsl:param name="is_param_plugin_uuid_6" select="$is_param_"/>

    <xsl:param name="section_text" select="'Plugin Parameters'"/>

    <xsl:param name="plugin_name_text" select="'Name'"/>
    <xsl:param name="plugin_name_text_before" select="''"/>
    <xsl:param name="plugin_name_text_after" select="''"/>
    <xsl:param name="plugin_name_param" select="'plugin_name'"/>
    <xsl:param name="plugin_name" select="'Plugin'"/>

    <xsl:param name="plugin_prefix_text" select="'Prefix'"/>
    <xsl:param name="plugin_prefix_text_before" select="''"/>
    <xsl:param name="plugin_prefix_text_after" select="''"/>
    <xsl:param name="plugin_prefix_param" select="'plugin_prefix'"/>
    <xsl:param name="plugin_prefix" select="'P'"/>

    <xsl:param name="plugin_version_text" select="'Version'"/>
    <xsl:param name="plugin_version_text_before" select="''"/>
    <xsl:param name="plugin_version_text_after" select="''"/>
    <xsl:param name="plugin_version_param" select="'plugin_version'"/>
    <xsl:param name="plugin_version" select="'1.0.0.0'"/>

    <xsl:param name="plugin_mimetype_text" select="'MIME type'"/>
    <xsl:param name="plugin_mimetype_text_before" select="''"/>
    <xsl:param name="plugin_mimetype_text_after" select="''"/>
    <xsl:param name="plugin_mimetype_param" select="'plugin_mimetype'"/>
    <xsl:param name="plugin_mimetype" select="'application/x-'"/>

    <xsl:param name="plugin_uuid_1_text" select="''"/>
    <xsl:param name="plugin_uuid_1_text_before" select="'FBTYPELIB_GUID'"/>
    <xsl:param name="plugin_uuid_1_text_after" select="''"/>
    <xsl:param name="plugin_uuid_1_param" select="'plugin_uuid_1'"/>
    <xsl:param name="plugin_uuid_1" select="''"/>

    <xsl:param name="plugin_uuid_2_text" select="''"/>
    <xsl:param name="plugin_uuid_2_text_before" select="'IFBControl_GUID'"/>
    <xsl:param name="plugin_uuid_2_text_after" select="''"/>
    <xsl:param name="plugin_uuid_2_param" select="'plugin_uuid_2'"/>
    <xsl:param name="plugin_uuid_2" select="''"/>

    <xsl:param name="plugin_uuid_3_text" select="''"/>
    <xsl:param name="plugin_uuid_3_text_before" select="'FBControl_GUID'"/>
    <xsl:param name="plugin_uuid_3_text_after" select="''"/>
    <xsl:param name="plugin_uuid_3_param" select="'plugin_uuid_3'"/>
    <xsl:param name="plugin_uuid_3" select="''"/>

    <xsl:param name="plugin_uuid_4_text" select="''"/>
    <xsl:param name="plugin_uuid_4_text_before" select="'IFBComJavascriptObject_GUID'"/>
    <xsl:param name="plugin_uuid_4_text_after" select="''"/>
    <xsl:param name="plugin_uuid_4_param" select="'plugin_uuid_4'"/>
    <xsl:param name="plugin_uuid_4" select="''"/>

    <xsl:param name="plugin_uuid_5_text" select="''"/>
    <xsl:param name="plugin_uuid_5_text_before" select="'FBComJavascriptObject_GUID'"/>
    <xsl:param name="plugin_uuid_5_text_after" select="''"/>
    <xsl:param name="plugin_uuid_5_param" select="'plugin_uuid_5'"/>
    <xsl:param name="plugin_uuid_5" select="''"/>

    <xsl:param name="plugin_uuid_6_text" select="''"/>
    <xsl:param name="plugin_uuid_6_text_before" select="'IFBComEventSource_GUID'"/>
    <xsl:param name="plugin_uuid_6_text_after" select="''"/>
    <xsl:param name="plugin_uuid_6_param" select="'plugin_uuid_6'"/>
    <xsl:param name="plugin_uuid_6" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_name)) or ('yes' = $is_param_plugin_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_name_text"/>
            <xsl:with-param name="text_before" select="$plugin_name_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_name_text_after"/>
            <xsl:with-param name="name" select="$plugin_name_param"/>
            <xsl:with-param name="value" select="$plugin_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_prefix)) or ('yes' = $is_param_plugin_prefix)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_prefix_text"/>
            <xsl:with-param name="text_before" select="$plugin_prefix_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_prefix_text_after"/>
            <xsl:with-param name="name" select="$plugin_prefix_param"/>
            <xsl:with-param name="value" select="$plugin_prefix"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_version)) or ('yes' = $is_param_plugin_version)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_version_text"/>
            <xsl:with-param name="text_before" select="$plugin_version_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_version_text_after"/>
            <xsl:with-param name="name" select="$plugin_version_param"/>
            <xsl:with-param name="value" select="$plugin_version"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_mimetype)) or ('yes' = $is_param_plugin_mimetype)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_mimetype_text"/>
            <xsl:with-param name="text_before" select="$plugin_mimetype_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_mimetype_text_after"/>
            <xsl:with-param name="name" select="$plugin_mimetype_param"/>
            <xsl:with-param name="value" select="$plugin_mimetype"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separator_section)) or ('yes' = $is_param_separator_section)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_uuid_1)) or ('yes' = $is_param_plugin_uuid_1)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_uuid_1_text"/>
            <xsl:with-param name="text_before" select="$plugin_uuid_1_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_uuid_1_text_after"/>
            <xsl:with-param name="name" select="$plugin_uuid_1_param"/>
            <xsl:with-param name="value" select="$plugin_uuid_1"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_uuid_2)) or ('yes' = $is_param_plugin_uuid_2)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_uuid_2_text"/>
            <xsl:with-param name="text_before" select="$plugin_uuid_2_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_uuid_2_text_after"/>
            <xsl:with-param name="name" select="$plugin_uuid_2_param"/>
            <xsl:with-param name="value" select="$plugin_uuid_2"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_uuid_3)) or ('yes' = $is_param_plugin_uuid_3)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_uuid_3_text"/>
            <xsl:with-param name="text_before" select="$plugin_uuid_3_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_uuid_3_text_after"/>
            <xsl:with-param name="name" select="$plugin_uuid_3_param"/>
            <xsl:with-param name="value" select="$plugin_uuid_3"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_uuid_4)) or ('yes' = $is_param_plugin_uuid_4)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_uuid_4_text"/>
            <xsl:with-param name="text_before" select="$plugin_uuid_4_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_uuid_4_text_after"/>
            <xsl:with-param name="name" select="$plugin_uuid_4_param"/>
            <xsl:with-param name="value" select="$plugin_uuid_4"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_uuid_5)) or ('yes' = $is_param_plugin_uuid_5)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_uuid_5_text"/>
            <xsl:with-param name="text_before" select="$plugin_uuid_5_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_uuid_5_text_after"/>
            <xsl:with-param name="name" select="$plugin_uuid_5_param"/>
            <xsl:with-param name="value" select="$plugin_uuid_5"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_plugin_uuid_6)) or ('yes' = $is_param_plugin_uuid_6)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$plugin_uuid_6_text"/>
            <xsl:with-param name="text_before" select="$plugin_uuid_6_text_before"/>
            <xsl:with-param name="text_after" select="$plugin_uuid_6_text_after"/>
            <xsl:with-param name="name" select="$plugin_uuid_6_param"/>
            <xsl:with-param name="value" select="$plugin_uuid_6"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="file" select="'PluginConfig.cmake'"/>
    </xsl:call-template>
    <xsl:call-template name="plugin_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
