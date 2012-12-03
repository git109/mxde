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
<!--   File: medusaxde-transform-templates.xsl                              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/13/2011                                                      -->
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
<!-- Template: "transformation_form_fields"                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 9/18/2009                                                    -->
<!--========================================================================-->
<xsl:template name="transformation_form_fields">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_document_file" select="''"/>
    <xsl:param name="is_param_template_file" select="''"/>
    <xsl:param name="is_param_template_file_separator" select="''"/>
    <xsl:param name="is_param_document_path" select="''"/>
    <xsl:param name="is_param_document_path_item" select="''"/>
    <xsl:param name="is_param_template_path" select="''"/>
    <xsl:param name="is_param_template_path_item" select="''"/>

    <xsl:param name="section_text" select="'Transformation Parameters'"/>

    <xsl:param name="document_file_text" select="'Document File'"/>
    <xsl:param name="document_file_text_before" select="''"/>
    <xsl:param name="document_file_text_after" select="''"/>
    <xsl:param name="document_file_param" select="'document_file'"/>
    <xsl:param name="document_file" select="''"/>
    
    <xsl:param name="template_file_text" select="'Template File'"/>
    <xsl:param name="template_file_text_before" select="''"/>
    <xsl:param name="template_file_text_after" select="''"/>
    <xsl:param name="template_file_param" select="'template_file'"/>
    <xsl:param name="template_file" select="''"/>

    <xsl:param name="document_path_text" select="'Document Path'"/>
    <xsl:param name="document_path_text_before" select="''"/>
    <xsl:param name="document_path_text_after" select="''"/>
    <xsl:param name="document_path_param" select="'document_path'"/>
    <xsl:param name="document_path" select="''"/>

    <xsl:param name="document_path_item_text" select="''"/>
    <xsl:param name="document_path_item_text_before" select="''"/>
    <xsl:param name="document_path_item_text_after" select="''"/>
    <xsl:param name="document_path_item_param" select="'document_path_item'"/>
    <xsl:param name="document_path_item" select="''"/>
    
    <xsl:param name="template_path_text" select="'Template Path'"/>
    <xsl:param name="template_path_text_before" select="''"/>
    <xsl:param name="template_path_text_after" select="''"/>
    <xsl:param name="template_path_param" select="'template_path'"/>
    <xsl:param name="template_path" select="''"/>

    <xsl:param name="template_path_item_text" select="''"/>
    <xsl:param name="template_path_item_text_before" select="''"/>
    <xsl:param name="template_path_item_text_after" select="''"/>
    <xsl:param name="template_path_item_param" select="'template_path_item'"/>
    <xsl:param name="template_path_item" select="''"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_document_file)) or ('yes' = $is_param_document_file)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$document_file_text"/>
            <xsl:with-param name="text_before" select="$document_file_text_before"/>
            <xsl:with-param name="text_after" select="$document_file_text_after"/>
            <xsl:with-param name="name" select="$document_file_param"/>
            <xsl:with-param name="value" select="$document_file"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_document_path)) or ('yes' = $is_param_document_path)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$document_path_text"/>
            <xsl:with-param name="text_before" select="$document_path_text_before"/>
            <xsl:with-param name="text_after" select="$document_path_text_after"/>
            <xsl:with-param name="name" select="$document_path_param"/>
            <xsl:with-param name="value" select="$document_path"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_document_path_item)) or ('yes' = $is_param_document_path_item)">
        <xsl:call-template name="dropbox_row">
            <xsl:with-param name="text" select="$document_path_item_text"/>
            <xsl:with-param name="text_before" select="$document_path_item_text_before"/>
            <xsl:with-param name="text_after" select="$document_path_item_text_after"/>
            <xsl:with-param name="name" select="$document_path_item_param"/>
            <xsl:with-param name="value" select="$document_path_item"/>
            <xsl:with-param name="option" select="$xde_document_paths/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_file_separator)) or ('yes' = $is_param_template_file_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_file)) or ('yes' = $is_param_template_file)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$template_file_text"/>
            <xsl:with-param name="text_before" select="$template_file_text_before"/>
            <xsl:with-param name="text_after" select="$template_file_text_after"/>
            <xsl:with-param name="name" select="$template_file_param"/>
            <xsl:with-param name="value" select="$template_file"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_path)) or ('yes' = $is_param_template_path)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$template_path_text"/>
            <xsl:with-param name="text_before" select="$template_path_text_before"/>
            <xsl:with-param name="text_after" select="$template_path_text_after"/>
            <xsl:with-param name="name" select="$template_path_param"/>
            <xsl:with-param name="value" select="$template_path"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_template_path_item)) or ('yes' = $is_param_template_path_item)">
        <xsl:call-template name="dropbox_row">
            <xsl:with-param name="text" select="$template_path_item_text"/>
            <xsl:with-param name="text_before" select="$template_path_item_text_before"/>
            <xsl:with-param name="text_after" select="$template_path_item_text_after"/>
            <xsl:with-param name="name" select="$template_path_item_param"/>
            <xsl:with-param name="value" select="$template_path_item"/>
            <xsl:with-param name="option" select="$xde_template_paths/*"/>
        </xsl:call-template>
    </xsl:if>

</xsl:template>

</xsl:transform>
