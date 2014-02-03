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
<!--   File: medusaxde-xsl-forrm-templates.xsl                              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/26/2011                                                      -->
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

<!--==========================================================-->
<!-- Parameters                                               -->
<!--==========================================================-->

<!--==========================================================-->
<!-- Variables                                                -->
<!--==========================================================-->
<xsl:variable name="xsl_file_extensions_tree">
    <extension default="yes" value="xslt">.xslt</extension>
    <extension value="xsl">.xsl</extension>
    <extension value="">no</extension>
</xsl:variable>
<xsl:variable name="xsl_file_extensions"
 select="exsl:node-set($xsl_file_extensions_tree)"/>

<xsl:variable name="xsl_exclude_prefixes_tree">
    <prefix default="yes">xalan</prefix>
    <prefix default="yes">msxsl</prefix>
    <prefix default="yes">xde</prefix>
    <prefix default="yes">mxde</prefix>
    <prefix default="yes">medusade</prefix>
    <prefix default="yes">medusaxde</prefix>
</xsl:variable>
<xsl:variable name="xsl_exclude_prefixes"
 select="exsl:node-set($xsl_exclude_prefixes_tree)"/>

<!--==========================================================-->
<!-- Templates                                                -->
<!--==========================================================-->

<!--==========================================================-->
<!-- Template: xsl_file_form_fields                           -->
<!--                                                          -->
<!--   Author: $author$                                       -->
<!--     Date: 3/30/2009                                      -->
<!--==========================================================-->
<xsl:template name="xsl_file_form_fields">
    <xsl:param name="is_param_" select="'yes'"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="section_text" select="''"/>
    <xsl:param name="is_param_content_type" select="$is_param_"/>
    <xsl:param name="content_type" select="'text/html'"/>
    <xsl:param name="is_param_file" select="$is_param_"/>
    <xsl:param name="is_param_file_extension" select="$is_param_"/>

    <xsl:param name="file_extension_text" select="''"/>
    <xsl:param name="file_extension_text_before" select="''"/>
    <xsl:param name="file_extension_text_after" select="''"/>
    <xsl:param name="file_extension_option" select="''"/>
    <xsl:param name="file_extension_options" select="$xsl_file_extensions/*"/>
    <xsl:param name="file_extension_param" select="'file_type_extension'"/>
    <xsl:param name="file_extension" select="''"/>

    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="is_param_section" select="$is_param_section"/>
        <xsl:with-param name="section_text" select="$section_text"/>
        <xsl:with-param name="is_param_content_type" select="$is_param_content_type"/>
        <xsl:with-param name="content_type" select="$content_type"/>
        <xsl:with-param name="is_param_file" select="$is_param_file"/>
    </xsl:call-template>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_extension)) or ('yes' = $is_param_file_extension)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_extension_text"/>
            <xsl:with-param name="text_before" select="$file_extension_text_before"/>
            <xsl:with-param name="text_after" select="$file_extension_text_after"/>
            <xsl:with-param name="name" select="$file_extension_param"/>
            <xsl:with-param name="value" select="$file_extension"/>
            <xsl:with-param name="option" select="$file_extension_options"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--==========================================================-->
<!-- Template:  xsl_form_fields                               -->
<!--                                                          -->
<!--   Author: $author$                                       -->
<!--     Date: 3/31/2009                                      -->
<!--==========================================================-->
<xsl:template name="xsl_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_xsl_separators" select="''"/>
    <xsl:param name="is_param_xsl_is_stylesheet_separator" select="''"/>
    <xsl:param name="is_param_xsl_is_stylesheet" select="''"/>
    <xsl:param name="is_param_xsl_ns" select="''"/>
    <xsl:param name="is_param_xsl_ns_uri" select="$is_param_xsl_ns"/>
    <xsl:param name="is_param_xsl_exclude_prefixes" select="''"/>
    <xsl:param name="is_param_xsl_version" select="''"/>
    <xsl:param name="is_param_xsl_output_method" select="''"/>
    <xsl:param name="is_param_xsl_output_indent" select="$is_param_xsl_output_method"/>
    <xsl:param name="is_param_xsl_output_version" select="$is_param_xsl_output_method"/>
    <xsl:param name="is_param_xsl_include" select="''"/>
    <xsl:param name="is_param_xsl_include_list" select="$is_param_xsl_include"/>
    <xsl:param name="is_param_xsl_param" select="''"/>
    <xsl:param name="is_param_xsl_param_prefix" select="$is_param_xsl_param"/>
    <xsl:param name="is_param_xsl_param_suffix" select="$is_param_xsl_param"/>
    <xsl:param name="is_param_xsl_param_expr_type" select="$is_param_xsl_param"/>
    <xsl:param name="is_param_xsl_param_select_nodeset" select="$is_param_xsl_param"/>
    <xsl:param name="is_param_xsl_param_select_nodeset_type" select="$is_param_xsl_param"/>
    <xsl:param name="is_param_xsl_param_select" select="$is_param_xsl_param"/>
    <xsl:param name="is_param_xsl_variable" select="''"/>
    <xsl:param name="is_param_xsl_variable_prefix" select="$is_param_xsl_variable"/>
    <xsl:param name="is_param_xsl_variable_suffix" select="$is_param_xsl_variable"/>
    <xsl:param name="is_param_xsl_variable_expr_type" select="$is_param_xsl_variable"/>
    <xsl:param name="is_param_xsl_variable_select_nodeset" select="$is_param_xsl_variable"/>
    <xsl:param name="is_param_xsl_variable_select_nodeset_type" select="$is_param_xsl_variable"/>
    <xsl:param name="is_param_xsl_variable_select" select="$is_param_xsl_variable"/>
    <xsl:param name="is_param_xsl_template" select="''"/>
    <xsl:param name="is_param_xsl_template_separators" select="$is_param_xsl_template"/>
    <xsl:param name="is_param_xsl_template_name" select="$is_param_xsl_template"/>
    <xsl:param name="is_param_xsl_template_mode" select="$is_param_xsl_template"/>
    <xsl:param name="is_param_xsl_template_param" select="$is_param_xsl_template"/>
    <xsl:param name="is_param_xsl_template_param_expr_type" select="$is_param_xsl_template_param"/>
    <xsl:param name="is_param_xsl_template_param_select_nodeset" select="$is_param_xsl_template_param"/>
    <xsl:param name="is_param_xsl_template_param_select_nodeset_type" select="$is_param_xsl_template_param"/>
    <xsl:param name="is_param_xsl_template_param_select" select="$is_param_xsl_template_param"/>
    <xsl:param name="is_param_xsl_template_variable" select="$is_param_xsl_template"/>
    <xsl:param name="is_param_xsl_template_variable_expr_type" select="$is_param_xsl_template_variable"/>
    <xsl:param name="is_param_xsl_template_variable_select_nodeset" select="$is_param_xsl_template_variable"/>
    <xsl:param name="is_param_xsl_template_variable_select_nodeset_type" select="$is_param_xsl_template_variable"/>
    <xsl:param name="is_param_xsl_template_variable_select" select="$is_param_xsl_template_variable"/>

    <xsl:param name="section_text" select="''"/>

    <xsl:param name="xsl_is_stylesheet_text" select="''"/>
    <xsl:param name="xsl_is_stylesheet_text_before">
        <xsl:if test="('no' != $is_param_xsl_is_stylesheet)">
        <xsl:value-of select="'&lt;xsl:'"/>
        </xsl:if>
    </xsl:param>
    <xsl:param name="xsl_is_stylesheet_text_after">
        <xsl:if test="('no' = $is_param_xsl_version)">
        <xsl:value-of select="'&gt;'"/>
        </xsl:if>
    </xsl:param>
    <xsl:param name="xsl_is_stylesheet_param" select="'xsl_is_stylesheet'"/>
    <xsl:param name="xsl_is_stylesheet" select="''"/>

    <xsl:param name="xsl_ns_text" select="''"/>
    <xsl:param name="xsl_ns_text_before" select="'xmlns:'"/>
    <xsl:param name="xsl_ns_text_after" select="''"/>
    <xsl:param name="xsl_ns_param" select="'xsl_ns'"/>
    <xsl:param name="xsl_ns" select="''"/>

    <xsl:param name="xsl_ns_uri_text" select="''"/>
    <xsl:param name="xsl_ns_uri_text_before" select="'=&quot;'"/>
    <xsl:param name="xsl_ns_uri_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_ns_uri_param" select="'xsl_ns_uri'"/>
    <xsl:param name="xsl_ns_uri" select="''"/>

    <xsl:param name="xsl_exclude_prefixes_text" select="''"/>
    <xsl:param name="xsl_exclude_prefixes_text_before">
        <xsl:value-of select="'exclude-result-prefixes=&quot;'"/>
    </xsl:param>
    <xsl:param name="xsl_exclude_prefixes_text_after">
        <xsl:value-of select="'&quot;'"/>
    </xsl:param>
    <xsl:param name="xsl_exclude_prefixes_options" select="$xsl_exclude_prefixes"/>
    <xsl:param name="xsl_exclude_prefixes_param" select="'xsl_exclude_prefixes_'"/>

    <xsl:param name="xsl_version_text" select="''"/>
    <xsl:param name="xsl_version_text_before">
        <xsl:if test="('no' = $is_param_xsl_is_stylesheet)">
            <xsl:value-of select="'&lt;xsl:transform '"/>
        </xsl:if>
        <xsl:value-of select="'version=&quot;'"/>
    </xsl:param>
    <xsl:param name="xsl_version_text_after">
        <xsl:value-of select="'&quot;'"/>
        <xsl:if test="('no' != $is_param_xsl_is_stylesheet)">
            <xsl:value-of select="'&gt;'"/>
        </xsl:if>
    </xsl:param>
    <xsl:param name="xsl_version_param" select="'xsl_version'"/>
    <xsl:param name="xsl_version" select="''"/>
    
    <xsl:param name="xsl_output_method_text" select="''"/>
    <xsl:param name="xsl_output_method_text_before" select="'&lt;xsl:output method=&quot;'"/>
    <xsl:param name="xsl_output_method_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_output_method_param" select="'xsl_output_method'"/>
    <xsl:param name="xsl_output_method" select="''"/>

    <xsl:param name="xsl_output_indent_text" select="''"/>
    <xsl:param name="xsl_output_indent_text_before" select="'indent=&quot;'"/>
    <xsl:param name="xsl_output_indent_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_output_indent_param" select="'xsl_output_indent'"/>
    <xsl:param name="xsl_output_indent" select="'yes'"/>
    
    <xsl:param name="xsl_output_version_text" select="''"/>
    <xsl:param name="xsl_output_version_text_before" select="'version=&quot;'"/>
    <xsl:param name="xsl_output_version_text_after" select="'&quot;/&gt;'"/>
    <xsl:param name="xsl_output_version_param" select="'xsl_output_version'"/>
    <xsl:param name="xsl_output_version" select="'yes'"/>

    <xsl:param name="xsl_include_text" select="''"/>
    <xsl:param name="xsl_include_text_before" select="'&lt;xsl:include href=&quot;'"/>
    <xsl:param name="xsl_include_text_after">
        <xsl:choose>
            <xsl:when test="('no' = $is_param_xsl_include_list)">
                <xsl:value-of select="'&quot;/&gt;'"/>
            </xsl:when>
            <xsl:otherwise>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="xsl_include_param" select="'xsl_include'"/>
    <xsl:param name="xsl_include" select="''"/>

    <xsl:param name="xsl_include_list_text" select="''"/>
    <xsl:param name="xsl_include_list_text_before">
        <xsl:choose>
            <xsl:when test="('no' = $is_param_xsl_include)">
                <xsl:value-of select="'&lt;xsl:include href=&quot;'"/>
            </xsl:when>
            <xsl:otherwise>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="xsl_include_list_text_after" select="'&quot;/&gt;'"/>
    <xsl:param name="xsl_include_list_param" select="'xsl_include_list'"/>
    <xsl:param name="xsl_include_list_multiple" select="'yes'"/>
    <xsl:param name="xsl_include_list" select="''"/>

    <xsl:param name="xsl_param_text" select="''"/>
    <xsl:param name="xsl_param_text_before" select="'&lt;xsl:param name=&quot;'"/>
    <xsl:param name="xsl_param_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_param_param" select="'xsl_param'"/>
    <xsl:param name="xsl_param" select="''"/>

    <xsl:param name="xsl_param_prefix_text" select="'prefix'"/>
    <xsl:param name="xsl_param_prefix_text_before" select="'?'"/>
    <xsl:param name="xsl_param_prefix_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_param_prefix_param" select="'xsl_param_prefix'"/>
    <xsl:param name="xsl_param_prefix" select="''"/>
    
    <xsl:param name="xsl_param_suffix_text" select="'suffix'"/>
    <xsl:param name="xsl_param_suffix_text_before" select="'&quot;'"/>
    <xsl:param name="xsl_param_suffix_text_after" select="'?'"/>
    <xsl:param name="xsl_param_suffix_param" select="'xsl_param_suffix'"/>
    <xsl:param name="xsl_param_suffix" select="''"/>

    <xsl:param name="xsl_param_expr_type_text" select="''"/>
    <xsl:param name="xsl_param_expr_type_text_before" select="''"/>
    <xsl:param name="xsl_param_expr_type_text_after" select="''"/>
    <xsl:param name="xsl_param_expr_type_param" select="'xsl_param_expr_type'"/>
    <xsl:param name="xsl_param_expr_type" select="''"/>

    <xsl:param name="xsl_param_select_nodeset_text" select="''"/>
    <xsl:param name="xsl_param_select_nodeset_text_before" select="''"/>
    <xsl:param name="xsl_param_select_nodeset_text_after" select="''"/>
    <xsl:param name="xsl_param_select_nodeset_param" select="'xsl_param_select_nodeset'"/>
    <xsl:param name="xsl_param_select_nodeset_option" select="'select='"/>
    <xsl:param name="xsl_param_select_nodeset" select="''"/>

    <xsl:param name="xsl_param_select_nodeset_type_text" select="''"/>
    <xsl:param name="xsl_param_select_nodeset_type_text_before" select="'&quot;'"/>
    <xsl:param name="xsl_param_select_nodeset_type_text_after" select="'()&quot;'"/>
    <xsl:param name="xsl_param_select_nodeset_type_param" select="'xsl_param_select_nodeset_type'"/>
    <xsl:param name="xsl_param_select_nodeset_type" select="''"/>

    <xsl:param name="xsl_param_select_text" select="''"/>
    <xsl:param name="xsl_param_select_text_before" select="'=&quot;'"/>
    <xsl:param name="xsl_param_select_text_after" select="'&quot;/&gt;'"/>
    <xsl:param name="xsl_param_select_param" select="'xsl_param_select'"/>
    <xsl:param name="xsl_param_select" select="''"/>

    <xsl:param name="xsl_variable_text" select="''"/>
    <xsl:param name="xsl_variable_text_before" select="'&lt;xsl:variable name=&quot;'"/>
    <xsl:param name="xsl_variable_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_variable_param" select="'xsl_variable'"/>
    <xsl:param name="xsl_variable" select="''"/>

    <xsl:param name="xsl_variable_prefix_text" select="'prefix'"/>
    <xsl:param name="xsl_variable_prefix_text_before" select="'?'"/>
    <xsl:param name="xsl_variable_prefix_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_variable_prefix_param" select="'xsl_variable_prefix'"/>
    <xsl:param name="xsl_variable_prefix" select="''"/>
    
    <xsl:param name="xsl_variable_suffix_text" select="'suffix'"/>
    <xsl:param name="xsl_variable_suffix_text_before" select="'&quot;'"/>
    <xsl:param name="xsl_variable_suffix_text_after" select="'?'"/>
    <xsl:param name="xsl_variable_suffix_param" select="'xsl_variable_suffix'"/>
    <xsl:param name="xsl_variable_suffix" select="''"/>

    <xsl:param name="xsl_variable_expr_type_text" select="''"/>
    <xsl:param name="xsl_variable_expr_type_text_before" select="''"/>
    <xsl:param name="xsl_variable_expr_type_text_after" select="''"/>
    <xsl:param name="xsl_variable_expr_type_param" select="'xsl_variable_expr_type'"/>
    <xsl:param name="xsl_variable_expr_type" select="''"/>

    <xsl:param name="xsl_variable_select_nodeset_text" select="''"/>
    <xsl:param name="xsl_variable_select_nodeset_text_before" select="''"/>
    <xsl:param name="xsl_variable_select_nodeset_text_after" select="''"/>
    <xsl:param name="xsl_variable_select_nodeset_param" select="'xsl_variable_select_nodeset'"/>
    <xsl:param name="xsl_variable_select_nodeset_option" select="'select='"/>
    <xsl:param name="xsl_variable_select_nodeset" select="''"/>

    <xsl:param name="xsl_variable_select_nodeset_type_text" select="''"/>
    <xsl:param name="xsl_variable_select_nodeset_type_text_before" select="'&quot;'"/>
    <xsl:param name="xsl_variable_select_nodeset_type_text_after" select="'()&quot;'"/>
    <xsl:param name="xsl_variable_select_nodeset_type_param" select="'xsl_variable_select_nodeset_type'"/>
    <xsl:param name="xsl_variable_select_nodeset_type" select="''"/>

    <xsl:param name="xsl_variable_select_text" select="''"/>
    <xsl:param name="xsl_variable_select_text_before" select="'=&quot;'"/>
    <xsl:param name="xsl_variable_select_text_after" select="'&quot;/&gt;'"/>
    <xsl:param name="xsl_variable_select_param" select="'xsl_variable_select'"/>
    <xsl:param name="xsl_variable_select" select="''"/>

    <xsl:param name="xsl_template_text" select="''"/>
    <xsl:param name="xsl_template_text_before" select="'&lt;xsl:template'"/>
    <xsl:param name="xsl_template_text_after" select="''"/>
    <xsl:param name="xsl_template_param" select="'xsl_template'"/>
    <xsl:param name="xsl_template" select="''"/>

    <xsl:param name="xsl_template_name_text" select="''"/>
    <xsl:param name="xsl_template_name_text_before" select="'=&quot;'"/>
    <xsl:param name="xsl_template_name_text_after">
        <xsl:choose>
            <xsl:when test="(no != $is_param_xsl_template_mode)">
                <xsl:value-of select="'&quot;&gt;'"/>
            </xsl:when>
            <xsl:otherwise>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="xsl_template_name_param" select="'xsl_template_name'"/>
    <xsl:param name="xsl_template_name" select="''"/>

    <xsl:param name="xsl_template_mode_text" select="''"/>
    <xsl:param name="xsl_template_mode_text_before" select="'mode=&quot;'"/>
    <xsl:param name="xsl_template_mode_text_after" select="'&quot;&gt;'"/>
    <xsl:param name="xsl_template_mode_param" select="'xsl_template_mode'"/>
    <xsl:param name="xsl_template_mode" select="''"/>

    <xsl:param name="xsl_template_param_text" select="''"/>
    <xsl:param name="xsl_template_param_text_before" select="'&lt;xsl:param name=&quot;'"/>
    <xsl:param name="xsl_template_param_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_template_param_param" select="'xsl_template_param'"/>
    <xsl:param name="xsl_template_param_value" select="''"/>

    <xsl:param name="xsl_template_param_expr_type_text" select="''"/>
    <xsl:param name="xsl_template_param_expr_type_text_before" select="''"/>
    <xsl:param name="xsl_template_param_expr_type_text_after" select="''"/>
    <xsl:param name="xsl_template_param_expr_type_param" select="'xsl_template_param_expr_type'"/>
    <xsl:param name="xsl_template_param_expr_type" select="''"/>

    <xsl:param name="xsl_template_param_select_nodeset_text" select="''"/>
    <xsl:param name="xsl_template_param_select_nodeset_text_before" select="''"/>
    <xsl:param name="xsl_template_param_select_nodeset_text_after" select="''"/>
    <xsl:param name="xsl_template_param_select_nodeset_param" select="'xsl_template_param_select_nodeset'"/>
    <xsl:param name="xsl_template_param_select_nodeset_option" select="'select='"/>
    <xsl:param name="xsl_template_param_select_nodeset" select="''"/>

    <xsl:param name="xsl_template_param_select_nodeset_type_text" select="''"/>
    <xsl:param name="xsl_template_param_select_nodeset_type_text_before" select="'&quot;'"/>
    <xsl:param name="xsl_template_param_select_nodeset_type_text_after" select="'()&quot;'"/>
    <xsl:param name="xsl_template_param_select_nodeset_type_param" select="'xsl_template_param_select_nodeset_type'"/>
    <xsl:param name="xsl_template_param_select_nodeset_type" select="''"/>

    <xsl:param name="xsl_template_param_select_text" select="''"/>
    <xsl:param name="xsl_template_param_select_text_before" select="'=&quot;'"/>
    <xsl:param name="xsl_template_param_select_text_after" select="'&quot;/&gt;'"/>
    <xsl:param name="xsl_template_param_select_param" select="'xsl_template_param_select'"/>
    <xsl:param name="xsl_template_param_select" select="''"/>

    <xsl:param name="xsl_template_variable_text" select="''"/>
    <xsl:param name="xsl_template_variable_text_before" select="'&lt;xsl:variable name=&quot;'"/>
    <xsl:param name="xsl_template_variable_text_after" select="'&quot;'"/>
    <xsl:param name="xsl_template_variable_param" select="'xsl_template_variable'"/>
    <xsl:param name="xsl_template_variable" select="''"/>

    <xsl:param name="xsl_template_variable_expr_type_text" select="''"/>
    <xsl:param name="xsl_template_variable_expr_type_text_before" select="''"/>
    <xsl:param name="xsl_template_variable_expr_type_text_after" select="''"/>
    <xsl:param name="xsl_template_variable_expr_type_param" select="'xsl_template_variable_expr_type'"/>
    <xsl:param name="xsl_template_variable_expr_type" select="''"/>

    <xsl:param name="xsl_template_variable_select_nodeset_text" select="''"/>
    <xsl:param name="xsl_template_variable_select_nodeset_text_before" select="''"/>
    <xsl:param name="xsl_template_variable_select_nodeset_text_after" select="''"/>
    <xsl:param name="xsl_template_variable_select_nodeset_param" select="'xsl_template_variable_select_nodeset'"/>
    <xsl:param name="xsl_template_variable_select_nodeset_option" select="'select='"/>
    <xsl:param name="xsl_template_variable_select_nodeset" select="''"/>

    <xsl:param name="xsl_template_variable_select_nodeset_type_text" select="''"/>
    <xsl:param name="xsl_template_variable_select_nodeset_type_text_before" select="'&quot;'"/>
    <xsl:param name="xsl_template_variable_select_nodeset_type_text_after" select="'()&quot;'"/>
    <xsl:param name="xsl_template_variable_select_nodeset_type_param" select="'xsl_template_variable_select_nodeset_type'"/>
    <xsl:param name="xsl_template_variable_select_nodeset_type" select="''"/>

    <xsl:param name="xsl_template_variable_select_text" select="''"/>
    <xsl:param name="xsl_template_variable_select_text_before" select="'=&quot;'"/>
    <xsl:param name="xsl_template_variable_select_text_after" select="'&quot;/&gt;'"/>
    <xsl:param name="xsl_template_variable_select_param" select="'xsl_template_variable_select'"/>
    <xsl:param name="xsl_template_variable_select" select="''"/>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_is_stylesheet)) or ('yes' = $is_param_xsl_is_stylesheet)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_is_stylesheet_text"/>
            <xsl:with-param name="text_before" select="$xsl_is_stylesheet_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_is_stylesheet_text_after"/>
            <xsl:with-param name="name" select="$xsl_is_stylesheet_param"/>
            <xsl:with-param name="value" select="$xsl_is_stylesheet"/>
            <xsl:with-param name="option" select="$xsl_is_stylesheet_options/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_ns)) or ('yes' = $is_param_xsl_ns)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$xsl_ns_text"/>
        <xsl:with-param name="text_before" select="$xsl_ns_text_before"/>
        <xsl:with-param name="text_after" select="$xsl_ns_text_after"/>
        <xsl:with-param name="name" select="$xsl_ns_param"/>
        <xsl:with-param name="value" select="$xsl_ns"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_ns_uri)) or ('yes' = $is_param_xsl_ns_uri)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$xsl_ns_uri_text"/>
        <xsl:with-param name="text_before" select="$xsl_ns_uri_text_before"/>
        <xsl:with-param name="text_after" select="$xsl_ns_uri_text_after"/>
        <xsl:with-param name="name" select="$xsl_ns_uri_param"/>
        <xsl:with-param name="value" select="$xsl_ns_uri"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_exclude_prefixes)) or ('yes' = $is_param_xsl_exclude_prefixes)">
    <xsl:call-template name="checkboxes_row">
        <xsl:with-param name="text" select="$xsl_exclude_prefixes_text"/>
        <xsl:with-param name="text_before" select="$xsl_exclude_prefixes_text_before"/>
        <xsl:with-param name="text_after" select="$xsl_exclude_prefixes_text_after"/>
        <xsl:with-param name="name" select="$xsl_exclude_prefixes_param"/>
        <xsl:with-param name="option" select="$xsl_exclude_prefixes_options/*"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_version)) or ('yes' = $is_param_xsl_version)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_version_text"/>
            <xsl:with-param name="text_before" select="$xsl_version_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_version_text_after"/>
            <xsl:with-param name="name" select="$xsl_version_param"/>
            <xsl:with-param name="value" select="$xsl_version"/>
            <xsl:with-param name="option" select="$xsl_versions/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_is_stylesheet_separator)) or ('yes' = $is_param_xsl_is_stylesheet_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_output_method)) or ('yes' = $is_param_xsl_output_method)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_output_method_text"/>
            <xsl:with-param name="text_before" select="$xsl_output_method_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_output_method_text_after"/>
            <xsl:with-param name="name" select="$xsl_output_method_param"/>
            <xsl:with-param name="value" select="$xsl_output_method"/>
            <xsl:with-param name="option" select="$xsl_output_methods/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_output_indent)) or ('yes' = $is_param_xsl_output_indent)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$xsl_output_indent_text"/>
            <xsl:with-param name="text_before" select="$xsl_output_indent_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_output_indent_text_after"/>
            <xsl:with-param name="name" select="$xsl_output_indent_param"/>
            <xsl:with-param name="value" select="$xsl_output_indent"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_output_version)) or ('yes' = $is_param_xsl_output_version)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$xsl_output_version_text"/>
            <xsl:with-param name="text_before" select="$xsl_output_version_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_output_version_text_after"/>
            <xsl:with-param name="name" select="$xsl_output_version_param"/>
            <xsl:with-param name="value" select="$xsl_output_version"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_separators)) or ('yes' = $is_param_xsl_separators)">
        <xsl:call-template name="section_separator_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_include)) or ('yes' = $is_param_xsl_include)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_include_text"/>
            <xsl:with-param name="text_before" select="$xsl_include_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_include_text_after"/>
            <xsl:with-param name="name" select="$xsl_include_param"/>
            <xsl:with-param name="value" select="$xsl_include"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_include_list)) or ('yes' = $is_param_xsl_include_list)">
        <xsl:call-template name="listbox_row">
            <xsl:with-param name="multiple" select="$xsl_include_list_multiple"/>
            <xsl:with-param name="text" select="$xsl_include_list_text"/>
            <xsl:with-param name="text_before" select="$xsl_include_list_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_include_list_text_after"/>
            <xsl:with-param name="name" select="$xsl_include_list_param"/>
            <xsl:with-param name="value" select="$xsl_include_list"/>
            <xsl:with-param name="option" select="$xsl_standard_includes/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_separators)) or ('yes' = $is_param_xsl_separators)">
        <xsl:call-template name="section_separator_row">
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param)) or ('yes' = $is_param_xsl_param)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_param_text"/>
            <xsl:with-param name="text_before" select="$xsl_param_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_param_text_after"/>
            <xsl:with-param name="name" select="$xsl_param_param"/>
            <xsl:with-param name="value" select="$xsl_param"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param_prefix)) or ('yes' = $is_param_xsl_param_prefix)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_param_prefix_text"/>
            <xsl:with-param name="text_before" select="$xsl_param_prefix_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_param_prefix_text_after"/>
            <xsl:with-param name="name" select="$xsl_param_prefix_param"/>
            <xsl:with-param name="value" select="$xsl_param_prefix"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param_suffix)) or ('yes' = $is_param_xsl_param_suffix)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_param_suffix_text"/>
            <xsl:with-param name="text_before" select="$xsl_param_suffix_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_param_suffix_text_after"/>
            <xsl:with-param name="name" select="$xsl_param_suffix_param"/>
            <xsl:with-param name="value" select="$xsl_param_suffix"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param_expr_type)) or ('yes' = $is_param_xsl_param_expr_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_param_expr_type_text"/>
            <xsl:with-param name="name" select="$xsl_param_expr_type_param"/>
            <xsl:with-param name="value" select="$xsl_param_expr_type"/>
            <xsl:with-param name="option" select="$xsl_param_expr_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param_select_nodeset)) or ('yes' = $is_param_xsl_param_select_nodeset)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$xsl_param_select_nodeset_text"/>
            <xsl:with-param name="text_before" select="$xsl_param_select_nodeset_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_param_select_nodeset_text_after"/>
            <xsl:with-param name="name" select="$xsl_param_select_nodeset_param"/>
            <xsl:with-param name="value" select="$xsl_param_select_nodeset"/>
            <xsl:with-param name="option" select="$xsl_param_select_nodeset_option"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param_select_nodeset_type)) or ('yes' = $is_param_xsl_param_select_nodeset_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_param_select_nodeset_type_text"/>
            <xsl:with-param name="text_before" select="$xsl_param_select_nodeset_type_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_param_select_nodeset_type_text_after"/>
            <xsl:with-param name="name" select="$xsl_param_select_nodeset_type_param"/>
            <xsl:with-param name="value" select="$xsl_param_select_nodeset_type"/>
            <xsl:with-param name="option" select="$xsl_nodeset_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_param_select)) or ('yes' = $is_param_xsl_param_select)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_param_select_text"/>
            <xsl:with-param name="text_before" select="$xsl_param_select_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_param_select_text_after"/>
            <xsl:with-param name="name" select="$xsl_param_select_param"/>
            <xsl:with-param name="value" select="$xsl_param_select"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_separators)) or ('yes' = $is_param_xsl_separators)">
        <xsl:call-template name="section_separator_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable)) or ('yes' = $is_param_xsl_variable)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_variable_text"/>
            <xsl:with-param name="text_before" select="$xsl_variable_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_variable_text_after"/>
            <xsl:with-param name="name" select="$xsl_variable_param"/>
            <xsl:with-param name="value" select="$xsl_variable"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable_prefix)) or ('yes' = $is_param_xsl_variable_prefix)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_variable_prefix_text"/>
            <xsl:with-param name="text_before" select="$xsl_variable_prefix_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_variable_prefix_text_after"/>
            <xsl:with-param name="name" select="$xsl_variable_prefix_param"/>
            <xsl:with-param name="value" select="$xsl_variable_prefix"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable_suffix)) or ('yes' = $is_param_xsl_variable_suffix)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_variable_suffix_text"/>
            <xsl:with-param name="text_before" select="$xsl_variable_suffix_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_variable_suffix_text_after"/>
            <xsl:with-param name="name" select="$xsl_variable_suffix_param"/>
            <xsl:with-param name="value" select="$xsl_variable_suffix"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable_expr_type)) or ('yes' = $is_param_xsl_variable_expr_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_variable_expr_type_text"/>
            <xsl:with-param name="name" select="$xsl_variable_expr_type_param"/>
            <xsl:with-param name="value" select="$xsl_variable_expr_type"/>
            <xsl:with-param name="option" select="$xsl_param_expr_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable_select_nodeset)) or ('yes' = $is_param_xsl_variable_select_nodeset)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$xsl_variable_select_nodeset_text"/>
            <xsl:with-param name="text_before" select="$xsl_variable_select_nodeset_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_variable_select_nodeset_text_after"/>
            <xsl:with-param name="name" select="$xsl_variable_select_nodeset_param"/>
            <xsl:with-param name="value" select="$xsl_variable_select_nodeset"/>
            <xsl:with-param name="option" select="$xsl_variable_select_nodeset_option"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable_select_nodeset_type)) or ('yes' = $is_param_xsl_variable_select_nodeset_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_variable_select_nodeset_type_text"/>
            <xsl:with-param name="text_before" select="$xsl_variable_select_nodeset_type_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_variable_select_nodeset_type_text_after"/>
            <xsl:with-param name="name" select="$xsl_variable_select_nodeset_type_param"/>
            <xsl:with-param name="value" select="$xsl_variable_select_nodeset_type"/>
            <xsl:with-param name="option" select="$xsl_nodeset_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_variable_select)) or ('yes' = $is_param_xsl_variable_select)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_variable_select_text"/>
            <xsl:with-param name="text_before" select="$xsl_variable_select_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_variable_select_text_after"/>
            <xsl:with-param name="name" select="$xsl_variable_select_param"/>
            <xsl:with-param name="value" select="$xsl_variable_select"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_separators)) or ('yes' = $is_param_xsl_separators)">
        <xsl:call-template name="section_separator_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template)) or ('yes' = $is_param_xsl_template)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_template_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_param"/>
            <xsl:with-param name="value" select="$xsl_template"/>
            <xsl:with-param name="option" select="$xsl_template_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_name)) or ('yes' = $is_param_xsl_template_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_template_name_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_name_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_name_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_name_param"/>
            <xsl:with-param name="value" select="$xsl_template_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_mode)) or ('yes' = $is_param_xsl_template_mode)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_template_mode_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_mode_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_mode_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_mode_param"/>
            <xsl:with-param name="value" select="$xsl_template_mode"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_separators)) or ('yes' = $is_param_xsl_template_separators)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_param)) or ('yes' = $is_param_xsl_template_param)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_template_param_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_param_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_param_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_param_param"/>
            <xsl:with-param name="value" select="$xsl_template_param_value"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_param_expr_type)) or ('yes' = $is_param_xsl_template_param_expr_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_template_param_expr_type_text"/>
            <xsl:with-param name="name" select="$xsl_template_param_expr_type_param"/>
            <xsl:with-param name="value" select="$xsl_template_param_expr_type"/>
            <xsl:with-param name="option" select="$xsl_param_expr_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_param_select_nodeset)) or ('yes' = $is_param_xsl_template_param_select_nodeset)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$xsl_template_param_select_nodeset_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_param_select_nodeset_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_param_select_nodeset_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_param_select_nodeset_param"/>
            <xsl:with-param name="value" select="$xsl_template_param_select_nodeset"/>
            <xsl:with-param name="option" select="$xsl_param_select_nodeset_option"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_param_select_nodeset_type)) or ('yes' = $is_param_xsl_template_param_select_nodeset_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_template_param_select_nodeset_type_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_param_select_nodeset_type_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_param_select_nodeset_type_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_param_select_nodeset_type_param"/>
            <xsl:with-param name="value" select="$xsl_template_param_select_nodeset_type"/>
            <xsl:with-param name="option" select="$xsl_nodeset_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_param_select)) or ('yes' = $is_param_xsl_template_param_select)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_template_param_select_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_param_select_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_param_select_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_param_select_param"/>
            <xsl:with-param name="value" select="$xsl_template_param_select"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_separators)) or ('yes' = $is_param_xsl_template_separators)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_variable)) or ('yes' = $is_param_xsl_template_variable)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_template_variable_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_variable_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_variable_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_variable_param"/>
            <xsl:with-param name="value" select="$xsl_template_variable"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_variable_expr_type)) or ('yes' = $is_param_xsl_template_variable_expr_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_template_variable_expr_type_text"/>
            <xsl:with-param name="name" select="$xsl_template_variable_expr_type_param"/>
            <xsl:with-param name="value" select="$xsl_template_variable_expr_type"/>
            <xsl:with-param name="option" select="$xsl_param_expr_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_variable_select_nodeset)) or ('yes' = $is_param_xsl_template_variable_select_nodeset)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$xsl_template_variable_select_nodeset_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_variable_select_nodeset_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_variable_select_nodeset_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_variable_select_nodeset_param"/>
            <xsl:with-param name="value" select="$xsl_template_variable_select_nodeset"/>
            <xsl:with-param name="option" select="$xsl_template_variable_select_nodeset_option"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_variable_select_nodeset_type)) or ('yes' = $is_param_xsl_template_variable_select_nodeset_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xsl_template_variable_select_nodeset_type_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_variable_select_nodeset_type_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_variable_select_nodeset_type_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_variable_select_nodeset_type_param"/>
            <xsl:with-param name="value" select="$xsl_template_variable_select_nodeset_type"/>
            <xsl:with-param name="option" select="$xsl_nodeset_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xsl_template_variable_select)) or ('yes' = $is_param_xsl_template_variable_select)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xsl_template_variable_select_text"/>
            <xsl:with-param name="text_before" select="$xsl_template_variable_select_text_before"/>
            <xsl:with-param name="text_after" select="$xsl_template_variable_select_text_after"/>
            <xsl:with-param name="name" select="$xsl_template_variable_select_param"/>
            <xsl:with-param name="value" select="$xsl_template_variable_select"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

</xsl:transform>
