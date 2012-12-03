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
<!--   File: medusaxde-form-templates.xsl                                   -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/12/2011                                                      -->
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
<xsl:include href="medusaxde-form-control-templates.xsl"/>
<xsl:include href="medusaxde-form-row-control-templates.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="default_form_section">
    <xsl:choose>
        <xsl:when test="'1' != $form">
            <xsl:value-of select="$default_xde_form_section"/>
        </xsl:when>
        <xsl:otherwise>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- main                                                                   -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "main"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="main">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="form_main">
    </xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "form_main"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="form_main">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="head">
    </xsl:call-template>
    <body>
        <xsl:call-template name="form">
        </xsl:call-template>
    </body>
</xsl:template>

<!--========================================================================-->
<!-- Template: "head"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="head">
    <xsl:param name="relative_path">
        <xsl:if test="('' != $template_path)">
            <xsl:value-of select="$template_path"/>
            <xsl:value-of select="'/'"/>
        </xsl:if>
        <xsl:value-of select="'../'"/>
    </xsl:param>

    <xsl:param name="stylesheet" select="xde:head/xde:stylesheet"/>
    <xsl:param name="stylesheet_type" select="$stylesheet/@type"/>
    <xsl:param name="stylesheet_href">
        <xsl:value-of select="$relative_path"/>
        <xsl:value-of select="$stylesheet/@href"/>
    </xsl:param>

    <xsl:param name="script" select="xde:head/xde:script"/>
    <xsl:param name="script_language" select="$script/@language"/>
    <xsl:param name="script_src">
        <xsl:value-of select="$relative_path"/>
        <xsl:value-of select="$script/@src"/>
    </xsl:param>

    <xsl:param name="tab_font" select="xde:tabs/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="footer_font" select="xde:footer/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="section_font" select="xde:menus/xde:menu-sections/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="item_font" select="xde:menus/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="folder_font" select="xde:folders/xde:fonts[((@for = $for) or (not (@for)))]/*"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <head>
        <link rel="stylesheet" type="{$stylesheet_type}" href="{$stylesheet_href}"/>
        <style type="text/css">
            a.tab {color: <xsl:value-of select="$tab_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.tab:hover {color: <xsl:value-of select="$tab_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.section {color: <xsl:value-of select="$section_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.section:hover {color: <xsl:value-of select="$section_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.item {color: <xsl:value-of select="$item_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.item:hover {color: <xsl:value-of select="$item_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.folder {color: <xsl:value-of select="$folder_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.folder:hover {color: <xsl:value-of select="$folder_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.footer {color: <xsl:value-of select="$footer_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.footer:hover {color: <xsl:value-of select="$footer_font['on' = @hover]/@color"/>; text-decoration: underline;}
        </style>
        <script language="{$script_language}" src="{$script_src}"/>
        <script language="javaScript">
        </script>
    </head>
</xsl:template>

<!--========================================================================-->
<!-- form                                                                   -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "form"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="form">
    <xsl:variable name="xborder" select="'1'"/>
    <xsl:variable name="border" select="$border"/>
    <xsl:variable name="image" select="xde:folders/xde:forms/xde:images/xde:image"/>
    <xsl:variable name="top_left_image_width" select="$image['top_left' = @id]/@width"/>
    <xsl:variable name="top_left_image_height" select="$image['top_left' = @id]/@height"/>
    <xsl:variable name="top_left_image_location" select="$image['top_left' = @id]/@location"/>
    <xsl:variable name="bottom_left_image_width" select="$image['bottom_left' = @id]/@width"/>
    <xsl:variable name="bottom_left_image_height" select="$image['bottom_left' = @id]/@height"/>
    <xsl:variable name="bottom_left_image_location" select="$image['bottom_left' = @id]/@location"/>
    <xsl:variable name="top_right_image_width" select="$image['top_right' = @id]/@width"/>
    <xsl:variable name="top_right_image_height" select="$image['top_right' = @id]/@height"/>
    <xsl:variable name="top_right_image_location" select="$image['top_right' = @id]/@location"/>
    <xsl:variable name="bottom_right_image_width" select="$image['bottom_right' = @id]/@width"/>
    <xsl:variable name="bottom_right_image_height" select="$image['bottom_right' = @id]/@height"/>
    <xsl:variable name="bottom_right_image_location" select="$image['bottom_right' = @id]/@location"/>
    <xsl:variable name="submit_valign" select="'top'"/>
    <xsl:variable name="submit_valign_1" select="'top'"/>
    <xsl:variable name="on_submit">
        <xsl:choose>
            <xsl:when test="'yes' = $xde_form_onsubmit_is_location">
                <xsl:text>return onSubmitLocation('</xsl:text>
                <xsl:value-of select="$xde_form_action"/>
                <xsl:text>')</xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>return setFormSubmit2(getFormValue('form_action_item'),getFormValue('form_action'),getFormValue('form_method'))</xsl:text>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <form
     name="form"
     method="{$xde_form_method}"
     action="{$xde_form_action}"
     onsubmit="{$on_submit}">
        <table
         border="{$border}"
         bgcolor="{$xde_form_header_bgcolor}"
         width="100%" cellspacing="0" cellpadding="0">
            <tr><td>
                <font
                 face="{$xde_form_header_font_face}"
                 size="{$xde_form_header_font_size}"
                 color="{$xde_form_header_font_color}">
                    <b><xsl:value-of select="$xde_form_title"/></b>
                </font>
            </td></tr>
            <tr><td>
                <table
                 border="{$border}"
                 bgcolor="{$xde_form_section_bgcolor}"
                 width="100%" cellspacing="0" cellpadding="0">
                    <xsl:choose>
                        <!--==========================================================-->
                        <!--==========================================================-->
                        <xsl:when test="'1' = $form">
                        <tr><td valign="top">
                            <table
                             border="{$border}"
                             width="100%"
                             cellspacing="0" cellpadding="0">
                                <tr><td
                                     align="left"
                                     valign="top"
                                     width="{$top_left_image_width}"
                                     height="{$top_left_image_height}">
                                    <img src="{$top_left_image_location}"/>
                                </td></tr>
                            </table>
                        </td><td valign="bottom" align="middle">
                                    <font
                                     face="{$xde_form_section_font_face}"
                                     size="{$xde_form_section_font_size}"
                                     color="{$xde_form_section_font_color}">
                                        <b><xsl:value-of select="$xde_form_section"/></b>
                                    </font>
                                </td></tr>
                        <tr><td valign="{$submit_valign_1}">
                             <table
                              border="{$border}"
                              width="100%"
                              cellspacing="0" cellpadding="10">
                                 <tr><td align="middle">
                                     <input type="submit" name="submit" value="{$xde_form_submit}"/>
                                 </td></tr>
                             </table>
                        </td><td>
                            <table
                             border="{$border}"
                             width="100%"
                             cellspacing="0" cellpadding="0">
                                <xsl:call-template name="form_fields"/>
                            </table>
                        </td></tr>
                        <tr><td valign="bottom">
                            <table
                             border="{$border}"
                             width="100%"
                             cellspacing="0" cellpadding="0">
                                <tr><td
                                     align="left"
                                     valign="bottom"
                                     width="{$bottom_left_image_width}"
                                     height="{$bottom_left_image_height}">
                                    <img src="{$bottom_left_image_location}"/>
                                </td></tr>
                            </table>
                        </td></tr>
                        </xsl:when>
                        <!--==========================================================-->
                        <!--==========================================================-->
                        <xsl:otherwise>
                        <tr><td valign="top">
                            <table
                             border="{$border}"
                             width="100%" height="100%"
                             cellspacing="0" cellpadding="0">
                                <tr><td
                                     align="left"
                                     valign="top"
                                     width="{$top_left_image_width}"
                                     height="{$top_left_image_height}">
                                    <img src="{$top_left_image_location}"/>
                                </td></tr>
                            </table>
                        </td><td valign="{$submit_valign}">
                             <table
                              border="{$border}"
                              width="100%"
                              cellspacing="0" cellpadding="10">
                                 <tr><td valign="middle" align="middle">
                                     <input type="submit" name="submit" value="{$xde_form_submit}"/>
                                 </td></tr>
                             </table>
                        </td><td>
                            <table
                             border="{$border}"
                             width="100%"
                             cellspacing="0" cellpadding="0">
                                <xsl:call-template name="form_fields"/>
                            </table>
                        </td></tr>
                        <tr><td
                             align="left"
                             valign="bottom"
                             width="{$bottom_left_image_width}"
                             height="{$bottom_left_image_height}">
                            <img src="{$bottom_left_image_location}"/>
                        </td></tr>
                        </xsl:otherwise>
                    </xsl:choose>
                </table>
            </td></tr>
        </table>
    </form>
</xsl:template>

<!--========================================================================-->
<!-- form fields                                                            -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "file_type_form_fields"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="file_type_form_fields">
    <xsl:param name="is_param_section" select="'yes'"/>
    <xsl:param name="section_text" select="''"/>
    <xsl:param name="is_param_content_type" select="'yes'"/>
    <xsl:param name="content_type" select="'text/html'"/>
    <xsl:param name="is_param_file" select="'yes'"/>
    <xsl:param name="file" select="''"/>
    <xsl:param name="is_param_for" select="'no'"/>
    <xsl:param name="date" select="''"/>
    <xsl:param name="year" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="form_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_section" select="$is_param_section"/>
        <xsl:with-param name="section_text" select="$section_text"/>
        <xsl:with-param name="is_param_content_type" select="$is_param_content_type"/>
        <xsl:with-param name="content_type" select="$content_type"/>
    </xsl:call-template>
    <xsl:call-template name="file_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_file" select="$is_param_file"/>
        <xsl:with-param name="file" select="$file"/>
        <xsl:with-param name="is_param_for" select="$is_param_for"/>
        <xsl:with-param name="file_date" select="$date"/>
        <xsl:with-param name="copyright_year" select="$year"/>
    </xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "file_creation_form_fields"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="file_creation_form_fields">
    <xsl:param name="is_param_" select="'yes'"/>
    <xsl:param name="is_param_file" select="'no'"/>
    <xsl:param name="date" select="''"/>
    <xsl:param name="year" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_form_fields">
        <xsl:with-param name="is_param_" select="$is_param_"/>
        <xsl:with-param name="is_param_file" select="$is_param_file"/>
        <xsl:with-param name="file_date" select="$date"/>
        <xsl:with-param name="copyright_year" select="$year"/>
    </xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "file_form_fields"                                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="file_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_separator" select="'no'"/>
    <xsl:param name="is_param_file" select="''"/>
    <xsl:param name="is_param_for" select="'no'"/>
    <xsl:param name="is_param_author" select="''"/>
    <xsl:param name="is_param_organization" select="''"/>
    <xsl:param name="is_param_copyright" select="''"/>
    <xsl:param name="is_param_copyright_year" select="''"/>
    <xsl:param name="is_param_open_source" select="''"/>
    <xsl:param name="is_param_file_date" select="''"/>

    <xsl:param name="section_text" select="'File Creation Parameters'"/>

    <xsl:param name="file_text" select="'Output File'"/>
    <xsl:param name="file_text_before" select="''"/>
    <xsl:param name="file_text_after" select="''"/>
    <xsl:param name="file_param" select="'file'"/>
    <xsl:param name="file" select="''"/>

    <xsl:param name="for_text" select="'For'"/>
    <xsl:param name="for_text_before" select="''"/>
    <xsl:param name="for_text_after" select="''"/>
    <xsl:param name="for_param" select="'for'"/>
    <xsl:param name="for" select="''"/>

    <xsl:param name="author_text" select="'Author'"/>
    <xsl:param name="author_text_before" select="''"/>
    <xsl:param name="author_text_after" select="''"/>
    <xsl:param name="author_param" select="'author'"/>
    <xsl:param name="author" select="$author"/>

    <xsl:param name="organization_text" select="'Organization'"/>
    <xsl:param name="organization_text_before" select="''"/>
    <xsl:param name="organization_text_after" select="''"/>
    <xsl:param name="organization_param" select="'organization'"/>
    <xsl:param name="organization" select="$organization"/>

    <xsl:param name="file_date_text" select="'Date'"/>
    <xsl:param name="file_date_text_before" select="''"/>
    <xsl:param name="file_date_text_after" select="''"/>
    <xsl:param name="file_date_param" select="'file_date'"/>
    <xsl:param name="file_date" select="''"/>

    <xsl:param name="copyright_text" select="'Copyright'"/>
    <xsl:param name="copyright_text_before" select="''"/>
    <xsl:param name="copyright_text_after" select="''"/>
    <xsl:param name="copyright_param" select="'copyright'"/>
    <xsl:param name="copyright" select="$copyright"/>

    <xsl:param name="copyright_year_text" select="'Year'"/>
    <xsl:param name="copyright_year_text_before" select="''"/>
    <xsl:param name="copyright_year_text_after" select="''"/>
    <xsl:param name="copyright_year_param" select="'copyright_year'"/>
    <xsl:param name="copyright_year" select="''"/>

    <xsl:param name="open_source_text" select="'Open Source'"/>
    <xsl:param name="open_source_text_before" select="''"/>
    <xsl:param name="open_source_text_after" select="''"/>
    <xsl:param name="open_source_param" select="'open_source'"/>
    <xsl:param name="open_source" select="$open_source"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separator)) or ('yes' = $is_param_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file)) or ('yes' = $is_param_file)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$file_text"/>
            <xsl:with-param name="text_before" select="$file_text_before"/>
            <xsl:with-param name="text_after" select="$file_text_after"/>
            <xsl:with-param name="name" select="$file_param"/>
            <xsl:with-param name="value" select="$file"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_open_source)) or ('yes' = $is_param_open_source)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$open_source_text"/>
            <xsl:with-param name="name" select="$open_source_param"/>
            <xsl:with-param name="value" select="$open_source"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_copyright)) or ('yes' = $is_param_copyright)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$copyright_text"/>
            <xsl:with-param name="name" select="$copyright_param"/>
            <xsl:with-param name="value" select="$copyright"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_organization)) or ('yes' = $is_param_organization)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$organization_text"/>
            <xsl:with-param name="text_before" select="$organization_text_before"/>
            <xsl:with-param name="text_after" select="$organization_text_after"/>
            <xsl:with-param name="name" select="$organization_param"/>
            <xsl:with-param name="value" select="$organization"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_author)) or ('yes' = $is_param_author)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$author_text"/>
            <xsl:with-param name="text_before" select="$author_text_before"/>
            <xsl:with-param name="text_after" select="$author_text_after"/>
            <xsl:with-param name="name" select="$author_param"/>
            <xsl:with-param name="value" select="$author"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_copyright_year)) or ('yes' = $is_param_copyright_year)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$copyright_year_text"/>
            <xsl:with-param name="text_before" select="$copyright_year_text_before"/>
            <xsl:with-param name="text_after" select="$copyright_year_text_after"/>
            <xsl:with-param name="name" select="$copyright_year_param"/>
            <xsl:with-param name="value" select="$copyright_year"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_date)) or ('yes' = $is_param_file_date)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$file_date_text"/>
            <xsl:with-param name="text_before" select="$file_date_text_before"/>
            <xsl:with-param name="text_after" select="$file_date_text_after"/>
            <xsl:with-param name="name" select="$file_date_param"/>
            <xsl:with-param name="value" select="$file_date"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "form_form_fields"                                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="form_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_separator" select="'no'"/>
    <xsl:param name="is_param_content_type" select="'no'"/>
    <xsl:param name="is_param_method" select="''"/>
    <xsl:param name="is_param_action" select="''"/>
    <xsl:param name="is_param_action_item" select="''"/>
    <xsl:param name="is_param_action_default" select="''"/>
    <xsl:param name="is_param_action_default_show" select="''"/>

    <xsl:param name="section_text" select="'Form Parameters'"/>
    
    <xsl:param name="content_type_text" select="'Content-type'"/>
    <xsl:param name="content_type_text_before" select="''"/>
    <xsl:param name="content_type_text_after" select="''"/>
    <xsl:param name="content_type_param" select="'content_type'"/>
    <xsl:param name="content_type" select="''"/>
    
    <xsl:param name="method_text" select="'Method'"/>
    <xsl:param name="method_text_before" select="''"/>
    <xsl:param name="method_text_after" select="''"/>
    <xsl:param name="method_param" select="'form_method'"/>
    <xsl:param name="method" select="''"/>
    
    <xsl:param name="action_text" select="'Action'"/>
    <xsl:param name="action_text_before" select="''"/>
    <xsl:param name="action_text_after" select="''"/>
    <xsl:param name="action_param" select="'form_action'"/>
    <xsl:param name="action" select="''"/>

    <xsl:param name="action_item_text" select="''"/>
    <xsl:param name="action_item_text_before" select="''"/>
    <xsl:param name="action_item_text_after" select="''"/>
    <xsl:param name="action_item_param" select="'form_action_item'"/>
    <xsl:param name="action_item" select="''"/>

    <xsl:param name="action_default_param" select="'form_action_default'"/>
    <xsl:param name="action_default" select="$xde_form_action"/>

    <xsl:param name="action_default_show_text" select="''"/>
    <xsl:param name="action_default_show_text_before" select="''"/>
    <xsl:param name="action_default_show_text_after" select="''"/>
    <xsl:param name="action_default_show" select="$action_default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separator)) or ('yes' = $is_param_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_content_type)) or ('yes' = $is_param_content_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$content_type_text"/>
            <xsl:with-param name="name" select="$content_type_param"/>
            <xsl:with-param name="value" select="$content_type"/>
            <xsl:with-param name="option" select="$xde_content_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_method)) or ('yes' = $is_param_method)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$method_text"/>
            <xsl:with-param name="text_before" select="$method_text_before"/>
            <xsl:with-param name="text_after" select="$method_text_after"/>
            <xsl:with-param name="name" select="$method_param"/>
            <xsl:with-param name="value" select="$method"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_action)) or ('yes' = $is_param_action)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$action_text"/>
            <xsl:with-param name="text_before" select="$action_text_before"/>
            <xsl:with-param name="text_after" select="$action_text_after"/>
            <xsl:with-param name="name" select="$action_param"/>
            <xsl:with-param name="value" select="$action"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_action_item)) or ('yes' = $is_param_action_item)">
        <xsl:call-template name="dropbox_row">
            <xsl:with-param name="text" select="$action_item_text"/>
            <xsl:with-param name="name" select="$action_item_param"/>
            <xsl:with-param name="value" select="$action_item"/>
            <xsl:with-param name="option" select="$xde_action_list/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_action_default)) or ('yes' = $is_param_action_default)">
        <xsl:call-template name="hidden">
            <xsl:with-param name="name" select="$action_default_param"/>
            <xsl:with-param name="value" select="$action_default"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_action_default_show)) or ('yes' = $is_param_action_default_show)">
        <xsl:call-template name="static_row">
            <xsl:with-param name="text" select="$action_default_show_text"/>
            <xsl:with-param name="text_before" select="$action_default_show_text_before"/>
            <xsl:with-param name="text_after" select="$action_default_show_text_after"/>
            <xsl:with-param name="value" select="$action_default_show"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "css_font_style"                                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 9/25/2009                                                    -->
<!--========================================================================-->
<xsl:template name="css_font_style">
    <xsl:param name="font_face" select="$xde_form_font_face"/>
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="('' != $font_face)">
        <xsl:value-of select="'font-face:'"/>
        <xsl:value-of select="$font_face"/>
        <xsl:value-of select="';'"/>
    </xsl:if>
    <xsl:if test="('' != $font_size)">
        <xsl:value-of select="'font-size:'"/>
        <xsl:call-template name="css_font_size">
            <xsl:with-param name="font_size"  select="$font_size"/>
        </xsl:call-template>
        <xsl:value-of select="';'"/>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "css_font_size"                                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 9/25/2009                                                    -->
<!--========================================================================-->
<xsl:template name="css_font_size">
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="2 &gt; $font_size">
            <xsl:value-of select="'7pt'"/>
        </xsl:when>
        <xsl:when test="2 = $font_size">
            <xsl:value-of select="'9pt'"/>
        </xsl:when>
        <xsl:when test="3 = $font_size">
            <xsl:value-of select="'10pt'"/>
        </xsl:when>
        <xsl:when test="4 = $font_size">
            <xsl:value-of select="'12pt'"/>
        </xsl:when>
        <xsl:when test="5 = $font_size">
            <xsl:value-of select="'16pt'"/>
        </xsl:when>
        <xsl:when test="6 = $font_size">
            <xsl:value-of select="'20pt'"/>
        </xsl:when>
        <xsl:when test="6 &lt; $font_size">
            <xsl:value-of select="'30pt'"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$font_size"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
</xsl:transform>
 