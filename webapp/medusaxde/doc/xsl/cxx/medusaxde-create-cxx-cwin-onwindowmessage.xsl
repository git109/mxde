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
<!--   File: medusaxde-create-cxx-cwin-onwindowmessage.xsl                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 11/19/2011                                                     -->
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
<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../medusaxde-parameters.xsl"/>
<xsl:include href="../medusaxde-templates.xsl"/>
<xsl:include href="../medusaxde-form-parameters.xsl"/>
<xsl:include href="../medusaxde-form-templates.xsl"/>
<xsl:include href="../medusaxde-transform-parameters.xsl"/>
<xsl:include href="../medusaxde-transform-templates.xsl"/>    
<xsl:include href="medusaxde-cxx-form-parameters.xsl"/>
<xsl:include href="medusaxde-cxx-form-templates.xsl"/>
<xsl:include href="medusaxde-cxx-class-form-parameters.xsl"/>
<xsl:include href="medusaxde-cxx-class-form-templates.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_do" select="'Create '"/>
<xsl:param name="default_xde_form_title_what" select="'C++'"/>
<xsl:param name="default_xde_form_title_what_file" select="' File'"/>
<xsl:param name="default_xde_form_title_what_parameters" select="' Parameters'"/>
<xsl:param name="default_xde_form_title">
    <xsl:value-of select="$default_xde_form_title_do"/>
    <xsl:value-of select="$default_xde_form_title_what"/>
    <xsl:value-of select="$default_xde_form_title_what_what"/>
    <xsl:value-of select="$default_xde_form_title_what_what_what"/>
    <xsl:value-of select="$default_xde_form_title_what_what_what_what"/>
</xsl:param>
<xsl:param name="default_xde_form_section">
    <xsl:value-of select="$default_xde_form_title_what"/>
    <xsl:value-of select="$default_xde_form_title_what_file"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>
<xsl:param name="default_xde_form_what_section">
    <xsl:value-of select="$default_xde_form_title_what"/>
    <xsl:value-of select="$default_xde_form_title_what_what"/>
    <xsl:value-of select="$default_xde_form_title_what_what_what"/>
    <xsl:value-of select="$default_xde_form_title_what_what_what_what"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="form_section">
    <xsl:choose>
        <xsl:when test="'1' != $form">
            <xsl:value-of select="$default_xde_form_section"/>
        </xsl:when>
        <xsl:otherwise>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:variable name="form_what_section">
    <xsl:value-of select="$default_xde_form_what_section"/>
</xsl:variable>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_what_what" select="''"/>
<xsl:param name="default_xde_form_title_what_what_what" select="' cWin'"/>
<xsl:param name="default_xde_form_title_what_what_what_what" select="' On_?_WindowMessage'"/>
<xsl:param name="default_cxx_form_class_interface" select="''"/>
<xsl:param name="default_cxx_form_class" select="'c'"/>
<xsl:param name="default_cxx_form_class_implements" select="''"/>
<xsl:param name="default_cxx_form_class_extends" select="''"/>
<xsl:param name="default_cxx_form_class_constructor" select="'yes'"/>
<xsl:param name="default_cxx_form_class_destructor" select="'virtual'"/>
<xsl:param name="default_cxx_form_class_function" select="'virtual'"/>
<xsl:param name="default_cxx_form_class_members_only" select="''"/>

<xsl:param name="default_xde_form_action" select="'/medusaxde/t/cxx/mxde-onwindowmessage-hxx-cxx.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>
<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "windows_messages_form_fields"                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/19/2011                                                   -->
<!--========================================================================-->
<xsl:template name="windows_messages_form_fields">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_on_window_message_list" select="''"/>
    <xsl:param name="is_param_window_message_lresult" select="$is_param_"/>
    <xsl:param name="is_param_on_window_message_default" select="$is_param_"/>

    <xsl:param name="section_text" select="'Window Message Parameters'"/>

    <xsl:param name="on_window_message_list_multiple" select="'yes'"/>
    <xsl:param name="on_window_message_list_size" select="'10'"/>
    <xsl:param name="on_window_message_list_text" select="''"/>
    <xsl:param name="on_window_message_list_text_before" select="'On_'"/>
    <xsl:param name="on_window_message_list_text_after" select="'_WindowMessage'"/>
    <xsl:param name="on_window_message_list_param" select="'on_window_message'"/>
    <xsl:param name="on_window_message" select="''"/>

    <xsl:param name="window_message_lresult_options_tree">
        <option value="OnWindowMessageDefault">OnWindowMessageDefault(...)</option>
        <option value="DefWindowProc">DefWindowProc(...)</option>
        <option default="yes" value="">0</option>
    </xsl:param>
    <xsl:param name="window_message_lresult_options"
     select="exsl:node-set($window_message_lresult_options_tree)"/>

    <xsl:param name="window_message_lresult_text" select="''"/>
    <xsl:param name="window_message_lresult_text_before" select="'lResult='"/>
    <xsl:param name="window_message_lresult_text_after" select="';'"/>
    <xsl:param name="window_message_lresult_option" select="''"/>
    <xsl:param name="window_message_lresult_param" select="'OnWindowMessageDefault'"/>
    <xsl:param name="window_message_lresult" select="''"/>

    <xsl:param name="on_window_message_default_text" select="''"/>
    <xsl:param name="on_window_message_default_text_before" select="''"/>
    <xsl:param name="on_window_message_default_text_after" select="'OnWindowMessageDefault'"/>
    <xsl:param name="on_window_message_default_param" select="'on_window_message_default'"/>
    <xsl:param name="on_window_message_default" select="''"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->
    <xsl:variable name="windows_messages_document_location"
     select="'../../xml/win-messages.xml'"/>
    <xsl:variable name="windows_messages_document"
     select="document($windows_messages_document_location)"/>
    <xsl:variable name="window_message_options_tree">
        <message></message>
        <xsl:for-each select="$windows_messages_document/*/*">
            <message>
                <xsl:value-of select="@id"/>
            </message>
        </xsl:for-each>
    </xsl:variable>
    <xsl:variable name="window_message_options"
     select="exsl:node-set($window_message_options_tree)"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_on_window_message_list)) or ('yes' = $is_param_on_window_message_list)">
        <xsl:call-template name="listbox_row">
            <xsl:with-param name="multiple" select="$on_window_message_list_multiple"/>
            <xsl:with-param name="size" select="$on_window_message_list_size"/>
            <xsl:with-param name="text" select="$on_window_message_list_text"/>
            <xsl:with-param name="text_before" select="$on_window_message_list_text_before"/>
            <xsl:with-param name="text_after" select="$on_window_message_list_text_after"/>
            <xsl:with-param name="name" select="$on_window_message_list_param"/>
            <xsl:with-param name="value" select="$on_window_message"/>
            <xsl:with-param name="option" select="$window_message_options/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_window_message_lresult)) or ('yes' = $is_param_window_message_lresult)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$window_message_lresult_text"/>
            <xsl:with-param name="text_before" select="$window_message_lresult_text_before"/>
            <xsl:with-param name="text_after" select="$window_message_lresult_text_after"/>
            <xsl:with-param name="name" select="$window_message_lresult_param"/>
            <xsl:with-param name="value" select="$window_message_lresult"/>
            <xsl:with-param name="option" select="$window_message_lresult_options/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_on_window_message_default)) or ('yes' = $is_param_on_window_message_default)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$on_window_message_default_text"/>
            <xsl:with-param name="text_before" select="$on_window_message_default_text_before"/>
            <xsl:with-param name="text_after" select="$on_window_message_default_text_after"/>
            <xsl:with-param name="name" select="$on_window_message_default_param"/>
            <xsl:with-param name="value" select="$on_window_message_default"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/19/2011                                                   -->
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
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_module" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_class_namespace" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="windows_messages_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_section" select="'yes'"/>
        <xsl:with-param name="section_text" select="$default_xde_form_what_section"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_class" select="'yes'"/>
        <xsl:with-param name="is_param_class_object" select="'no'"/>
        <xsl:with-param name="is_param_class_comment" select="'yes'"/>
        <xsl:with-param name="is_param_class_separator" select="'yes'"/>
        <xsl:with-param name="class" select="'c'"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_class_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_class_function_comment" select="'yes'"/>
    </xsl:call-template>
    <xsl:call-template name="windows_messages_form_fields">
        <xsl:with-param name="is_param_section" select="'no'"/>
    </xsl:call-template>
    <xsl:call-template name="file_creation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="transformation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="form_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>

