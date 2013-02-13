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
<!--   File: medusaxde-cxx-form-templates.xsl                               -->
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
<!-- Template: "cxx_form_fields"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/4/2011                                                     -->
<!--========================================================================-->
<xsl:template name="cxx_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_begin_separator" select="'no'"/>
    <xsl:param name="is_param_end_separator" select="'no'"/>
    <xsl:param name="is_param_file_is" select="''"/>
    <xsl:param name="is_param_file_case_is" select="''"/>
    <xsl:param name="is_param_file_name_is" select="''"/>
    <xsl:param name="is_param_file_extension" select="''"/>
    <xsl:param name="is_param_file_type" select="''"/>
    <xsl:param name="is_param_hxx_file_type" select="'no'"/>
    <xsl:param name="is_param_cxx_file_type" select="'no'"/>
    <xsl:param name="is_param_comment_type" select="''"/>
    <xsl:param name="is_param_module" select="'no'"/>
    <xsl:param name="is_param_style" select="'no'"/>
    <xsl:param name="is_param_include_system" select="''"/>
    <xsl:param name="is_param_include_system_list" select="'no'"/>
    <xsl:param name="is_param_include" select="''"/>
    <xsl:param name="is_param_include_list" select="'no'"/>
    <xsl:param name="is_param_ifdef_separator" select="''"/>
    <xsl:param name="is_param_ifdef" select="''"/>
    <xsl:param name="is_param_ifndef" select="''"/>
    <xsl:param name="is_param_if" select="''"/>
    <xsl:param name="is_param_define_separator" select="''"/>
    <xsl:param name="is_param_define" select="''"/>
    <xsl:param name="is_param_define_prefixsuffix" select="''"/>
    <xsl:param name="is_param_undef" select="''"/>
    <xsl:param name="is_param_namespace" select="'no'"/>
    <xsl:param name="is_param_typedef" select="''"/>
    <xsl:param name="is_param_typedef_comment" select="$is_param_typedef"/>
    <xsl:param name="is_param_typedef_separator" select="''"/>
    <xsl:param name="is_param_enum" select="''"/>
    <xsl:param name="is_param_enum_comment" select="$is_param_enum"/>
    <xsl:param name="is_param_enum_separator" select="''"/>
    <xsl:param name="is_param_enum_list" select="$is_param_enum"/>
    <xsl:param name="is_param_enum_item_before" select="$is_param_enum"/>
    <xsl:param name="is_param_enum_item_after" select="$is_param_enum"/>
    <xsl:param name="is_param_function_separator" select="$is_param_"/>
    <xsl:param name="is_param_function" select="$is_param_"/>
    <xsl:param name="is_param_function_comment" select="$is_param_function"/>
    <xsl:param name="is_param_function_type" select="$is_param_function"/>
    <xsl:param name="is_param_function_name" select="$is_param_function"/>
    <xsl:param name="is_param_function_return" select="$is_param_function"/>
    <xsl:param name="is_param_function_param" select="$is_param_function"/>
    <xsl:param name="is_param_function_body" select="$is_param_function"/>
    <xsl:param name="is_param_function_main" select="$is_param_"/>
    <xsl:param name="is_param_function_main_comment" select="$is_param_function_main"/>
    <xsl:param name="is_param_function_main_return" select="$is_param_function_main"/>
    <xsl:param name="is_param_function_main_param" select="$is_param_function_main"/>
    <xsl:param name="is_param_function_main_body" select="$is_param_function_main"/>

    <xsl:param name="is_comment_text" select="''"/>
    <xsl:param name="is_comment_text_before" select="'//...'"/>
    <xsl:param name="is_comment_text_after" select="''"/>

    <xsl:param name="section_text" select="'C++ Parameters'"/>

    <xsl:param name="file_is_text" select="''"/>
    <xsl:param name="file_is_text_before" select="''"/>
    <xsl:param name="file_is_text_after" select="''"/>
    <xsl:param name="file_is_param" select="'file_is_'"/>
    <xsl:param name="file_is_class_param" select="'file_is_class'"/>
    <xsl:param name="file_is_case_param" select="'file_is_case'"/>
    <xsl:param name="file_is_class" select="$cxx_file_is_class"/>
    <xsl:param name="file_is_case" select="$cxx_file_is_case"/>

    <xsl:param name="file_case_is_text" select="''"/>
    <xsl:param name="file_case_is_text_before" select="''"/>
    <xsl:param name="file_case_is_text_after" select="''"/>
    <xsl:param name="file_case_is_param" select="'file_case_is'"/>
    <xsl:param name="file_case_is" select="''"/>

    <xsl:param name="file_name_is_text" select="''"/>
    <xsl:param name="file_name_is_text_before" select="''"/>
    <xsl:param name="file_name_is_text_after" select="''"/>
    <xsl:param name="file_name_is_param" select="'file_name_is'"/>
    <xsl:param name="file_name_is" select="''"/>

    <xsl:param name="file_extension_text" select="''"/>
    <xsl:param name="file_extension_text_before" select="''"/>
    <xsl:param name="file_extension_text_after" select="''"/>
    <xsl:param name="file_extension_param" select="'file_extension'"/>
    <xsl:param name="file_extension" select="$cxx_file_extension"/>
    <xsl:param name="file_extensions" select="$hxx_cxx_file_extensions"/>

    <xsl:param name="file_type_text" select="''"/>
    <xsl:param name="file_type_text_before" select="''"/>
    <xsl:param name="file_type_text_after" select="''"/>
    <xsl:param name="file_type_param" select="'file_type'"/>
    <xsl:param name="file_type" select="$cxx_file_type"/>
    <xsl:param name="file_types" select="$hxx_cxx_file_types"/>

    <xsl:param name="hxx_file_type_text" select="''"/>
    <xsl:param name="hxx_file_type_text_before" select="''"/>
    <xsl:param name="hxx_file_type_text_after" select="''"/>
    <xsl:param name="hxx_file_type_param" select="$file_type_param"/>
    <xsl:param name="hxx_file_type" select="$cxx_file_type"/>

    <xsl:param name="cxx_file_type_text" select="''"/>
    <xsl:param name="cxx_file_type_text_before" select="''"/>
    <xsl:param name="cxx_file_type_text_after" select="''"/>
    <xsl:param name="cxx_file_type_param" select="$file_type_param"/>
    <xsl:param name="cxx_file_type" select="$cxx_file_type"/>

    <xsl:param name="comment_type_text" select="''"/>
    <xsl:param name="comment_type_text_before" select="'//...'"/>
    <xsl:param name="comment_type_text_after" select="''"/>
    <xsl:param name="comment_type_param" select="'comment_type'"/>
    <xsl:param name="comment_type" select="''"/>
    <xsl:param name="comment_types" select="$cxx_comment_types"/>

    <xsl:param name="module_text" select="''"/>
    <xsl:param name="module_text_before" select="'#ifndef _'"/>
    <xsl:param name="module_text_after" select="'_?_?'"/>
    <xsl:param name="module_param" select="'module'"/>
    <xsl:param name="module" select="''"/>

    <xsl:param name="style_text" select="'style'"/>
    <xsl:param name="style_text_before" select="''"/>
    <xsl:param name="style_text_after" select="''"/>
    <xsl:param name="style_param" select="'style'"/>
    <xsl:param name="style" select="''"/>

    <xsl:param name="include_system_text" select="''"/>
    <xsl:param name="include_system_text_before" select="'#include &lt;'"/>
    <xsl:param name="include_system_text_after" select="'&gt;'"/>
    <xsl:param name="include_system_param" select="'include_system'"/>
    <xsl:param name="include_system" select="''"/>

    <xsl:param name="include_system_list_text" select="''"/>
    <xsl:param name="include_system_list_text_before" select="'&lt;'"/>
    <xsl:param name="include_system_list_text_after" select="'&gt;'"/>
    <xsl:param name="include_system_list_param" select="'include_system_list'"/>
    <xsl:param name="include_system_list" select="''"/>

    <xsl:param name="include_text" select="''"/>
    <xsl:param name="include_text_before" select="'#include &quot;'"/>
    <xsl:param name="include_text_after" select="'&quot;'"/>
    <xsl:param name="include_param" select="'include'"/>
    <xsl:param name="include" select="''"/>

    <xsl:param name="include_list_text" select="''"/>
    <xsl:param name="include_list_text_before" select="'&quot;'"/>
    <xsl:param name="include_list_text_after" select="'&quot;'"/>
    <xsl:param name="include_list_param" select="'include_list'"/>
    <xsl:param name="include_list" select="''"/>

    <xsl:param name="ifdef_text" select="''"/>
    <xsl:param name="ifdef_text_before" select="'#if defined('"/>
    <xsl:param name="ifdef_text_after" select="')'"/>
    <xsl:param name="ifdef_param" select="'ifdef'"/>
    <xsl:param name="ifdef" select="''"/>
    
    <xsl:param name="ifndef_text" select="''"/>
    <xsl:param name="ifndef_text_before" select="'#if !defined('"/>
    <xsl:param name="ifndef_text_after" select="')'"/>
    <xsl:param name="ifndef_param" select="'ifndef'"/>
    <xsl:param name="ifndef" select="''"/>
    
    <xsl:param name="if_text" select="''"/>
    <xsl:param name="if_text_before" select="'#if ('"/>
    <xsl:param name="if_text_after" select="')'"/>
    <xsl:param name="if_param" select="'if'"/>
    <xsl:param name="if" select="''"/>

    <xsl:param name="define_prefixsuffix_text" select="''"/>
    <xsl:param name="define_prefixsuffix_text_before" select="'?d/d?'"/>
    <xsl:param name="define_prefixsuffix_text_after" select="''"/>
    <xsl:param name="define_prefixsuffix_param" select="'define_prefixsuffix'"/>
    <xsl:param name="define_prefixsuffix" select="''"/>

    <xsl:param name="define_text" select="''"/>
    <xsl:param name="define_text_before" select="'#define'"/>
    <xsl:param name="define_text_after" select="''"/>
    <xsl:param name="define_param" select="'define'"/>
    <xsl:param name="define" select="''"/>
    
    <xsl:param name="undef_text" select="''"/>
    <xsl:param name="undef_text_before" select="'#undef'"/>
    <xsl:param name="undef_text_after" select="''"/>
    <xsl:param name="undef_param" select="'undef'"/>
    <xsl:param name="undef" select="''"/>

    <xsl:param name="namespace_text" select="''"/>
    <xsl:param name="namespace_text_before" select="'namespace'"/>
    <xsl:param name="namespace_text_after" select="'{'"/>
    <xsl:param name="namespace_param" select="'namespace'"/>
    <xsl:param name="namespace" select="''"/>

    <xsl:param name="typedef_text" select="''"/>
    <xsl:param name="typedef_text_before" select="'typedef'"/>
    <xsl:param name="typedef_text_after" select="';'"/>
    <xsl:param name="typedef_param" select="'typedef'"/>
    <xsl:param name="typedef" select="''"/>

    <xsl:param name="typedef_comment_text" select="$is_comment_text"/>
    <xsl:param name="typedef_comment_text_before" select="$is_comment_text_before"/>
    <xsl:param name="typedef_comment_text_after" select="$is_comment_text"/>
    <xsl:param name="typedef_comment_param" select="'typedef_comment'"/>
    <xsl:param name="typedef_comment" select="'no'"/>

    <xsl:param name="enum_text" select="''"/>
    <xsl:param name="enum_text_before" select="'enum'"/>
    <xsl:param name="enum_text_after" select="''"/>
    <xsl:param name="enum_param" select="'enum'"/>
    <xsl:param name="enum" select="''"/>

    <xsl:param name="enum_comment_text" select="$is_comment_text"/>
    <xsl:param name="enum_comment_text_before" select="$is_comment_text_before"/>
    <xsl:param name="enum_comment_text_after" select="$is_comment_text"/>
    <xsl:param name="enum_comment_param" select="'enum_comment'"/>
    <xsl:param name="enum_comment" select="'yes'"/>

    <xsl:param name="enum_list_text" select="''"/>
    <xsl:param name="enum_list_text_before" select="'{'"/>
    <xsl:param name="enum_list_text_after" select="''"/>
    <xsl:param name="enum_list_param" select="'enum_list'"/>
    <xsl:param name="enum_list" select="''"/>
    
    <xsl:param name="enum_item_before_text" select="''"/>
    <xsl:param name="enum_item_before_text_before" select="''"/>
    <xsl:param name="enum_item_before_text_after" select="'?'"/>
    <xsl:param name="enum_item_before_param" select="'enum_item_before'"/>
    <xsl:param name="enum_item_before" select="''"/>
    
    <xsl:param name="enum_item_after_text" select="''"/>
    <xsl:param name="enum_item_after_text_before" select="'?'"/>
    <xsl:param name="enum_item_after_text_after" select="'};'"/>
    <xsl:param name="enum_item_after_param" select="'enum_item_after'"/>
    <xsl:param name="enum_item_after" select="''"/>

    <xsl:param name="function_comment_text" select="$is_comment_text"/>
    <xsl:param name="function_comment_text_before" select="$is_comment_text_before"/>
    <xsl:param name="function_comment_text_after" select="$is_comment_text_after"/>
    <xsl:param name="function_comment_param" select="'function_comment'"/>
    <xsl:param name="function_comment" select="'yes'"/>

    <xsl:param name="function_return_text" select="'Function'"/>
    <xsl:param name="function_return_text_before" select="'return'"/>
    <xsl:param name="function_return_text_after" select="';'"/>
    <xsl:param name="function_return_param" select="'function_return'"/>
    <xsl:param name="function_return" select="''"/>

    <xsl:param name="function_type_text" select="''"/>
    <xsl:param name="function_type_text_before" select="''"/>
    <xsl:param name="function_type_text_after" select="''"/>
    <xsl:param name="function_type_param" select="'function_type'"/>
    <xsl:param name="function_type" select="''"/>

    <xsl:param name="function_name_text" select="'name'"/>
    <xsl:param name="function_name_text_before" select="''"/>
    <xsl:param name="function_name_text_after" select="''"/>
    <xsl:param name="function_name_param" select="'function_name'"/>
    <xsl:param name="function_name" select="''"/>

    <xsl:param name="function_param_text" select="''"/>
    <xsl:param name="function_param_text_before" select="'('"/>
    <xsl:param name="function_param_text_after" select="')'"/>
    <xsl:param name="function_param_param" select="'function_param'"/>
    <xsl:param name="function_param" select="''"/>

    <xsl:param name="function_body_text" select="''"/>
    <xsl:param name="function_body_text_before" select="'{'"/>
    <xsl:param name="function_body_text_after" select="'}'"/>
    <xsl:param name="function_body_param" select="'function_body_param'"/>
    <xsl:param name="function_body" select="''"/>

    <xsl:param name="function_main_comment_text" select="$is_comment_text"/>
    <xsl:param name="function_main_comment_text_before" select="$is_comment_text_before"/>
    <xsl:param name="function_main_comment_text_after" select="$is_comment_text_after"/>
    <xsl:param name="function_main_comment_param" select="'function_main_comment'"/>
    <xsl:param name="function_main_comment" select="'yes'"/>

    <xsl:param name="function_main_return_text" select="''"/>
    <xsl:param name="function_main_return_text_before" select="''"/>
    <xsl:param name="function_main_return_text_after" select="''"/>
    <xsl:param name="function_main_return_param" select="'function_main_return'"/>
    <xsl:param name="function_main_return" select="'int err=0'"/>

    <xsl:param name="function_main_text" select="''"/>
    <xsl:param name="function_main_text_before" select="'main'"/>
    <xsl:param name="function_main_text_after" select="''"/>
    <xsl:param name="function_main_form_param" select="'function_main'"/>
    <xsl:param name="function_main" select="'no'"/>

    <xsl:param name="function_main_param_text" select="''"/>
    <xsl:param name="function_main_param_text_before" select="'('"/>
    <xsl:param name="function_main_param_text_after" select="')'"/>
    <xsl:param name="function_main_param_param" select="'function_main_param'"/>
    <xsl:param name="function_main_param" select="'int argc,char** argv,char** env'"/>

    <xsl:param name="function_main_body_text" select="''"/>
    <xsl:param name="function_main_body_text_before" select="'{'"/>
    <xsl:param name="function_main_body_text_after" select="'}'"/>
    <xsl:param name="function_main_body_param" select="'function_main_body'"/>
    <xsl:param name="function_main_body" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_begin_separator)) or ('yes' = $is_param_begin_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_extension)) or ('yes' = $is_param_file_extension)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_extension_text"/>
            <xsl:with-param name="name" select="$file_extension_param"/>
            <xsl:with-param name="value" select="$file_extension"/>
            <xsl:with-param name="option" select="$file_extensions/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_hxx_file_type)) or ('yes' = $is_param_hxx_file_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$hxx_file_type_text"/>
            <xsl:with-param name="name" select="$hxx_file_type_param"/>
            <xsl:with-param name="value" select="$hxx_file_type"/>
            <xsl:with-param name="option" select="$hxx_file_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_cxx_file_type)) or ('yes' = $is_param_cxx_file_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$cxx_file_type_text"/>
            <xsl:with-param name="name" select="$cxx_file_type_param"/>
            <xsl:with-param name="value" select="$cxx_file_type"/>
            <xsl:with-param name="option" select="$cxx_file_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_type)) or ('yes' = $is_param_file_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_type_text"/>
            <xsl:with-param name="name" select="$file_type_param"/>
            <xsl:with-param name="value" select="$file_type"/>
            <xsl:with-param name="option" select="$file_types/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_case_is)) or ('yes' = $is_param_file_case_is)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_case_is_text"/>
            <xsl:with-param name="name" select="$file_case_is_param"/>
            <xsl:with-param name="value" select="$file_case_is"/>
            <xsl:with-param name="option" select="$cxx_file_case_is/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_name_is)) or ('yes' = $is_param_file_name_is)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_name_is_text"/>
            <xsl:with-param name="name" select="$file_name_is_param"/>
            <xsl:with-param name="value" select="$file_name_is"/>
            <xsl:with-param name="option" select="$cxx_file_name_is/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_is)) or ('yes' = $is_param_file_is)">
        <xsl:call-template name="checkboxes_row">
            <xsl:with-param name="text" select="$file_is_text"/>
            <xsl:with-param name="text_before" select="$file_is_text_before"/>
            <xsl:with-param name="text_after" select="$file_is_text_after"/>
            <xsl:with-param name="name" select="$file_is_param"/>
            <xsl:with-param name="value_name" select="$file_is_case_param"/>
            <xsl:with-param name="value" select="$file_is_case"/>
            <xsl:with-param name="option" select="$cxx_file_is/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_comment_type)) or ('yes' = $is_param_comment_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$comment_type_text"/>
        <xsl:with-param name="text_before" select="$comment_type_text_before"/>
        <xsl:with-param name="text_after" select="$comment_type_text_after"/>
        <xsl:with-param name="name" select="$comment_type_param"/>
        <xsl:with-param name="value" select="$comment_type"/>
        <xsl:with-param name="option" select="$comment_types/*"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_style)) or ('yes' = $is_param_style)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$style_text"/>
            <xsl:with-param name="text_before" select="$style_text_before"/>
            <xsl:with-param name="text_after" select="$style_text_after"/>
            <xsl:with-param name="name" select="$style_param"/>
            <xsl:with-param name="value" select="$style"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_module)) or ('yes' = $is_param_module)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$module_text"/>
            <xsl:with-param name="text_before" select="$module_text_before"/>
            <xsl:with-param name="text_after" select="$module_text_after"/>
            <xsl:with-param name="name" select="$module_param"/>
            <xsl:with-param name="value" select="$module"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_include_system)) or ('yes' = $is_param_include_system)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$include_system_text"/>
            <xsl:with-param name="text_before" select="$include_system_text_before"/>
            <xsl:with-param name="text_after" select="$include_system_text_after"/>
            <xsl:with-param name="name" select="$include_system_param"/>
            <xsl:with-param name="value" select="$include_system"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_include_system_list)) or ('yes' = $is_param_include_system_list)">
        <xsl:call-template name="listbox_row">
            <xsl:with-param name="multiple" select="'yes'"/>
            <xsl:with-param name="text" select="$include_system_list_text"/>
            <xsl:with-param name="name" select="$include_system_list_param"/>
            <xsl:with-param name="value" select="$include_system_list"/>
            <xsl:with-param name="option" select="$cxx_include_system_items/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_include)) or ('yes' = $is_param_include)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$include_text"/>
            <xsl:with-param name="text_before" select="$include_text_before"/>
            <xsl:with-param name="text_after" select="$include_text_after"/>
            <xsl:with-param name="name" select="$include_param"/>
            <xsl:with-param name="value" select="$include"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_include_list)) or ('yes' = $is_param_include_list)">
        <xsl:if test="'' != $include_items/*">
        <xsl:call-template name="listbox_row">
            <xsl:with-param name="text" select="$include_list_text"/>
            <xsl:with-param name="name" select="$include_list_param"/>
            <xsl:with-param name="value" select="$include_list"/>
            <xsl:with-param name="option" select="$cxx_include_items/*"/>
        </xsl:call-template>
        </xsl:if>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_ifdef_separator)) or ('yes' = $is_param_ifdef_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_ifdef)) or ('yes' = $is_param_ifdef)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$ifdef_text"/>
            <xsl:with-param name="text_before" select="$ifdef_text_before"/>
            <xsl:with-param name="text_after" select="$ifdef_text_after"/>
            <xsl:with-param name="name" select="$ifdef_param"/>
            <xsl:with-param name="value" select="$ifdef"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_ifndef)) or ('yes' = $is_param_ifndef)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$ifndef_text"/>
            <xsl:with-param name="text_before" select="$ifndef_text_before"/>
            <xsl:with-param name="text_after" select="$ifndef_text_after"/>
            <xsl:with-param name="name" select="$ifndef_param"/>
            <xsl:with-param name="value" select="$ifndef"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_if)) or ('yes' = $is_param_if)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$if_text"/>
            <xsl:with-param name="text_before" select="$if_text_before"/>
            <xsl:with-param name="text_after" select="$if_text_after"/>
            <xsl:with-param name="name" select="$if_param"/>
            <xsl:with-param name="value" select="$if"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_define_separator)) or ('yes' = $is_param_define_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_define_prefixsuffix)) or ('yes' = $is_param_define_prefixsuffix)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$define_prefixsuffix_text"/>
            <xsl:with-param name="text_before" select="$define_prefixsuffix_text_before"/>
            <xsl:with-param name="text_after" select="$define_prefixsuffix_text_after"/>
            <xsl:with-param name="name" select="$define_prefixsuffix_param"/>
            <xsl:with-param name="value" select="$define_prefixsuffix"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_define)) or ('yes' = $is_param_define)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$define_text"/>
            <xsl:with-param name="text_before" select="$define_text_before"/>
            <xsl:with-param name="text_after" select="$define_text_after"/>
            <xsl:with-param name="name" select="$define_param"/>
            <xsl:with-param name="value" select="$define"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_undef)) or ('yes' = $is_param_undef)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$undef_text"/>
            <xsl:with-param name="text_before" select="$undef_text_before"/>
            <xsl:with-param name="text_after" select="$undef_text_after"/>
            <xsl:with-param name="name" select="$undef_param"/>
            <xsl:with-param name="value" select="$undef"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_namespace)) or ('yes' = $is_param_namespace)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$namespace_text"/>
            <xsl:with-param name="text_before" select="$namespace_text_before"/>
            <xsl:with-param name="text_after" select="$namespace_text_after"/>
            <xsl:with-param name="name" select="$namespace_param"/>
            <xsl:with-param name="value" select="$namespace"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_typedef_separator)) or ('yes' = $is_param_typedef_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_typedef_comment)) or ('yes' = $is_param_typedef_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$typedef_comment_text"/>
            <xsl:with-param name="text_before" select="$typedef_comment_text_before"/>
            <xsl:with-param name="text_after" select="$typedef_comment_text_after"/>
            <xsl:with-param name="name" select="$typedef_comment_param"/>
            <xsl:with-param name="value" select="$typedef_comment"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_typedef)) or ('yes' = $is_param_typedef)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$typedef_text"/>
            <xsl:with-param name="text_before" select="$typedef_text_before"/>
            <xsl:with-param name="text_after" select="$typedef_text_after"/>
            <xsl:with-param name="name" select="$typedef_param"/>
            <xsl:with-param name="value" select="$typedef"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_enum_separator)) or ('yes' = $is_param_enum_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_enum_comment)) or ('yes' = $is_param_enum_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$enum_comment_text"/>
            <xsl:with-param name="text_before" select="$enum_comment_text_before"/>
            <xsl:with-param name="text_after" select="$enum_comment_text_after"/>
            <xsl:with-param name="name" select="$enum_comment_param"/>
            <xsl:with-param name="value" select="$enum_comment"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_enum)) or ('yes' = $is_param_enum)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$enum_text"/>
            <xsl:with-param name="text_before" select="$enum_text_before"/>
            <xsl:with-param name="text_after" select="$enum_text_after"/>
            <xsl:with-param name="name" select="$enum_param"/>
            <xsl:with-param name="value" select="$enum"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_enum_list)) or ('yes' = $is_param_enum_list)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$enum_list_text"/>
            <xsl:with-param name="text_before" select="$enum_list_text_before"/>
            <xsl:with-param name="text_after" select="$enum_list_text_after"/>
            <xsl:with-param name="name" select="$enum_list_param"/>
            <xsl:with-param name="value" select="$enum_list"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_enum_item_before)) or ('yes' = $is_param_enum_item_before)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$enum_item_before_text"/>
            <xsl:with-param name="text_before" select="$enum_item_before_text_before"/>
            <xsl:with-param name="text_after" select="$enum_item_before_text_after"/>
            <xsl:with-param name="name" select="$enum_item_before_param"/>
            <xsl:with-param name="value" select="$enum_item_before"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_enum_item_after)) or ('yes' = $is_param_enum_item_after)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$enum_item_after_text"/>
            <xsl:with-param name="text_before" select="$enum_item_after_text_before"/>
            <xsl:with-param name="text_after" select="$enum_item_after_text_after"/>
            <xsl:with-param name="name" select="$enum_item_after_param"/>
            <xsl:with-param name="value" select="$enum_item_after"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_separator)) or ('yes' = $is_param_function_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_comment)) or ('yes' = $is_param_function_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$function_comment_text"/>
            <xsl:with-param name="text_before" select="$function_comment_text_before"/>
            <xsl:with-param name="text_after" select="$function_comment_text_after"/>
            <xsl:with-param name="name" select="$function_comment_param"/>
            <xsl:with-param name="value" select="$function_comment"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_return)) or ('yes' = $is_param_function_return)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_return_text"/>
            <xsl:with-param name="text_before" select="$function_return_text_before"/>
            <xsl:with-param name="text_after" select="$function_return_text_after"/>
            <xsl:with-param name="name" select="$function_return_param"/>
            <xsl:with-param name="value" select="$function_return"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_type)) or ('yes' = $is_param_function_type)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_type_text"/>
            <xsl:with-param name="text_before" select="$function_type_text_before"/>
            <xsl:with-param name="text_after" select="$function_type_text_after"/>
            <xsl:with-param name="name" select="$function_type_param"/>
            <xsl:with-param name="value" select="$function_type"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_name)) or ('yes' = $is_param_function_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_name_text"/>
            <xsl:with-param name="text_before" select="$function_name_text_before"/>
            <xsl:with-param name="text_after" select="$function_name_text_after"/>
            <xsl:with-param name="name" select="$function_name_param"/>
            <xsl:with-param name="value" select="$function_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_param)) or ('yes' = $is_param_function_param)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_param_text"/>
            <xsl:with-param name="text_before" select="$function_param_text_before"/>
            <xsl:with-param name="text_after" select="$function_param_text_after"/>
            <xsl:with-param name="name" select="$function_param_param"/>
            <xsl:with-param name="value" select="$function_param"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_body)) or ('yes' = $is_param_function_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_body_text"/>
            <xsl:with-param name="text_before" select="$function_body_text_before"/>
            <xsl:with-param name="text_after" select="$function_body_text_after"/>
            <xsl:with-param name="name" select="$function_body_param"/>
            <xsl:with-param name="value" select="$function_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_main_comment)) or ('yes' = $is_param_function_main_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$function_main_comment_text"/>
            <xsl:with-param name="text_before" select="$function_main_comment_text_before"/>
            <xsl:with-param name="text_after" select="$function_main_comment_text_after"/>
            <xsl:with-param name="name" select="$function_main_comment_param"/>
            <xsl:with-param name="value" select="$function_main_comment"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_main_return)) or ('yes' = $is_param_function_main_return)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_main_return_text"/>
            <xsl:with-param name="text_before" select="$function_main_return_text_before"/>
            <xsl:with-param name="text_after" select="$function_main_return_text_after"/>
            <xsl:with-param name="name" select="$function_main_return_param"/>
            <xsl:with-param name="value" select="$function_main_return"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_main)) or ('yes' = $is_param_function_main)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$function_main_text"/>
            <xsl:with-param name="text_before" select="$function_main_text_before"/>
            <xsl:with-param name="text_after" select="$function_main_text_after"/>
            <xsl:with-param name="name" select="$function_main_form_param"/>
            <xsl:with-param name="value" select="$function_main"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_main_param)) or ('yes' = $is_param_function_main_param)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_main_param_text"/>
            <xsl:with-param name="text_before" select="$function_main_param_text_before"/>
            <xsl:with-param name="text_after" select="$function_main_param_text_after"/>
            <xsl:with-param name="name" select="$function_main_param_param"/>
            <xsl:with-param name="value" select="$function_main_param"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_function_main_body)) or ('yes' = $is_param_function_main_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$function_main_body_text"/>
            <xsl:with-param name="text_before" select="$function_main_body_text_before"/>
            <xsl:with-param name="text_after" select="$function_main_body_text_after"/>
            <xsl:with-param name="name" select="$function_main_body_param"/>
            <xsl:with-param name="value" select="$function_main_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_end_separator)) or ('yes' = $is_param_end_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "cxx_file_form_fields"                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/4/2011                                                     -->
<!--========================================================================-->
<xsl:template name="cxx_file_form_fields">
    <xsl:param name="is_param_section" select="'yes'"/>
    <xsl:param name="section_text" select="''"/>
    <xsl:param name="is_param_content_type" select="'yes'"/>
    <xsl:param name="content_type" select="'text/html'"/>
    <xsl:param name="is_param_for" select="'no'"/>
    <xsl:param name="is_param_file" select="'yes'"/>
    <xsl:param name="is_param_file_is" select="$is_param_file"/>
    <xsl:param name="is_param_file_case_is" select="$is_param_file"/>
    <xsl:param name="is_param_file_type" select="$is_param_file"/>
    <xsl:param name="is_param_file_extension" select="$is_param_file"/>
    <xsl:param name="file_extensions" select="$hxx_cxx_file_extensions"/>
    <xsl:param name="file_types" select="$hxx_cxx_file_types"/>
    <xsl:param name="file_extension_param" select="'file_extension'"/>
    <xsl:param name="file_type_param" select="'file_type'"/>
    <xsl:param name="is_param_comment_type" select="$is_param_file"/>
    <xsl:param name="comment_type" select="$cxx_comment"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="is_param_section" select="$is_param_section"/>
        <xsl:with-param name="section_text" select="$section_text"/>
        <xsl:with-param name="is_param_content_type" select="$is_param_content_type"/>
        <xsl:with-param name="content_type" select="$content_type"/>
        <xsl:with-param name="is_param_file" select="$is_param_file"/>
    </xsl:call-template>
    <xsl:call-template name="cxx_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_file_is" select="$is_param_file_is"/>
        <xsl:with-param name="is_param_file_case_is" select="$is_param_file_case_is"/>
        <xsl:with-param name="is_param_file_type" select="$is_param_file_type"/>
        <xsl:with-param name="is_param_file_extension" select="$is_param_file_extension"/>
        <xsl:with-param name="file_types" select="$file_types"/>
        <xsl:with-param name="file_extensions" select="$file_extensions"/>
        <xsl:with-param name="file_type_param" select="$file_type_param"/>
        <xsl:with-param name="file_extension_param" select="$file_extension_param"/>
        <xsl:with-param name="is_param_comment_type" select="$is_param_comment_type"/>
        <xsl:with-param name="comment_type" select="$comment_type"/>
    </xsl:call-template>
    <xsl:call-template name="file_form_fields">
        <xsl:with-param name="is_param_" select="'no'"/>
        <xsl:with-param name="is_param_for" select="$is_param_for"/>
    </xsl:call-template>
</xsl:template>

</xsl:transform>
