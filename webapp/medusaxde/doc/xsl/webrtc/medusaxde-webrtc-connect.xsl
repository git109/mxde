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
<!--   File: medusaxde-webrtc-connect.xsl                                   -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 11/29/2012                                                     -->
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
<xsl:include href="../medusaxde-form.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_do" select="'Connect To'"/>
<xsl:param name="default_xde_form_title_what" select="' WebRTC'"/>
<xsl:param name="default_xde_form_title_what_file" select="' Connection'"/>
<xsl:param name="default_xde_form_title_what_parameters" select="' Parameters'"/>

<xsl:param name="default_xde_form_action" select="'/medusaxde/xsl/webrtc/medusaxde-webrtc-connection.xsl'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'html'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="video_codec_modes_tree">
    <mode>QQVGA</mode>
    <mode default="yes">QVGA</mode>
    <mode>VGA</mode>
    <mode>HD</mode>
    <mode>FHD</mode>
</xsl:variable>
<xsl:variable name="video_codec_modes" select="exsl:node-set($video_codec_modes_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "webrtc_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/30/2012                                                   -->
<!--========================================================================-->
<xsl:template name="webrtc_form_fields">
    <xsl:param name="is_param_" select="''"/>

    <xsl:param name="is_param_separator" select="$is_param_"/>

    <xsl:param name="is_param_user_name" select="$is_param_"/>
    <xsl:param name="is_param_server_name" select="$is_param_"/>
    <xsl:param name="is_param_server_port" select="$is_param_"/>
    <xsl:param name="is_param_video_codec_mode" select="$is_param_"/>
    <xsl:param name="is_param_mimeType" select="$is_param_"/>

    <xsl:param name="user_name_text" select="'User Name'"/>
    <xsl:param name="user_name_text_before" select="''"/>
    <xsl:param name="user_name_text_after" select="''"/>
    <xsl:param name="user_name_param" select="'userName'"/>
    <xsl:param name="user_name" select="'username'"/>

    <xsl:param name="server_name_text" select="'Server Name'"/>
    <xsl:param name="server_name_text_before" select="''"/>
    <xsl:param name="server_name_text_after" select="''"/>
    <xsl:param name="server_name_param" select="'serverName'"/>
    <xsl:param name="server_name" select="'localhost'"/>

    <xsl:param name="server_port_text" select="'Server Port'"/>
    <xsl:param name="server_port_text_before" select="''"/>
    <xsl:param name="server_port_text_after" select="''"/>
    <xsl:param name="server_port_param" select="'serverPort'"/>
    <xsl:param name="server_port" select="'8888'"/>

    <xsl:param name="video_codec_mode_text" select="'Video Mode'"/>
    <xsl:param name="video_codec_mode_text_before" select="''"/>
    <xsl:param name="video_codec_mode_text_after" select="''"/>
    <xsl:param name="video_codec_mode_options" select="$video_codec_modes/*"/>
    <xsl:param name="video_codec_mode_param" select="'videoCodecMode'"/>
    <xsl:param name="video_codec_mode" select="''"/>

    <xsl:param name="mimeType_text" select="'Mime Type'"/>
    <xsl:param name="mimeType_text_before" select="''"/>
    <xsl:param name="mimeType_text_after" select="''"/>
    <xsl:param name="mimeType_param" select="'mimeType'"/>
    <xsl:param name="mimeType" select="'application/x-xoswebrtcclientfbplugin'"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separator)) or ('yes' = $is_param_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_user_name)) or ('yes' = $is_param_user_name)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$user_name_text"/>
        <xsl:with-param name="text_before" select="$user_name_text_before"/>
        <xsl:with-param name="text_after" select="$user_name_text_after"/>
        <xsl:with-param name="name" select="$user_name_param"/>
        <xsl:with-param name="value" select="$user_name"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_server_name)) or ('yes' = $is_param_server_name)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$server_name_text"/>
        <xsl:with-param name="text_before" select="$server_name_text_before"/>
        <xsl:with-param name="text_after" select="$server_name_text_after"/>
        <xsl:with-param name="name" select="$server_name_param"/>
        <xsl:with-param name="value" select="$server_name"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_server_port)) or ('yes' = $is_param_server_port)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$server_port_text"/>
        <xsl:with-param name="text_before" select="$server_port_text_before"/>
        <xsl:with-param name="text_after" select="$server_port_text_after"/>
        <xsl:with-param name="name" select="$server_port_param"/>
        <xsl:with-param name="value" select="$server_port"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_video_codec_mode)) or ('yes' = $is_param_video_codec_mode)">
        <xsl:call-template name="dropbox_row">
            <xsl:with-param name="text" select="$video_codec_mode_text"/>
            <xsl:with-param name="text_before" select="$video_codec_mode_text_before"/>
            <xsl:with-param name="text_after" select="$video_codec_mode_text_after"/>
            <xsl:with-param name="name" select="$video_codec_mode_param"/>
            <xsl:with-param name="value" select="$video_codec_mode"/>
            <xsl:with-param name="option" select="$video_codec_mode_options"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_mimeType)) or ('yes' = $is_param_mimeType)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$mimeType_text"/>
            <xsl:with-param name="text_before" select="$mimeType_text_before"/>
            <xsl:with-param name="text_after" select="$mimeType_text_after"/>
            <xsl:with-param name="name" select="$mimeType_param"/>
            <xsl:with-param name="value" select="$mimeType"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "derived_form_fields"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/29/2012                                                   -->
<!--========================================================================-->
<xsl:template name="derived_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="webrtc_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
