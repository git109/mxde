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
<!--   File: medusaxde-cxx-class-form-templates.xsl                         -->
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
<!-- Template: "cxx_class_form_fields"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 6/11/2009                                                    -->
<!--========================================================================-->
<xsl:template name="cxx_class_form_fields">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_class_comment" select="''"/>
    <xsl:param name="is_param_class_interface" select="''"/>
    <xsl:param name="is_param_class_interface_name" select="''"/>
    <xsl:param name="is_param_class_name" select="'no'"/>
    <xsl:param name="is_param_class" select="''"/>
    <xsl:param name="is_param_class_template" select="$is_param_class"/>
    <xsl:param name="is_param_class_template_parameters" select="$is_param_class_template"/>
    <xsl:param name="is_param_class_access" select="$is_param_class"/>
    <xsl:param name="is_param_class_extends" select="''"/>
    <xsl:param name="is_param_class_extends_access" select="$is_param_class_extends"/>
    <xsl:param name="is_param_class_implements" select="''"/>
    <xsl:param name="is_param_class_implements_access" select="$is_param_class_implements"/>
    <xsl:param name="is_param_class_derives" select="''"/>
    <xsl:param name="is_param_class_separator" select="''"/>
    <xsl:param name="is_param_class_constructor_separator" select="''"/>
    <xsl:param name="is_param_class_constructor" select="''"/>
    <xsl:param name="is_param_class_constructor_comment" select="$is_param_class_constructor"/>
    <xsl:param name="is_param_class_constructor_parameters" select="$is_param_class_constructor"/>
    <xsl:param name="is_param_class_constructor_construct" select="$is_param_class_constructor"/>
    <xsl:param name="is_param_class_constructor_proto" select="$is_param_class_constructor"/>
    <xsl:param name="is_param_class_constructor_body" select="$is_param_class_constructor"/>
    <xsl:param name="is_param_class_destructor_separator" select="''"/>
    <xsl:param name="is_param_class_destructor" select="''"/>
    <xsl:param name="is_param_class_destructor_comment" select="$is_param_class_destructor"/>
    <xsl:param name="is_param_class_destructor_proto" select="$is_param_class_destructor"/>
    <xsl:param name="is_param_class_destructor_body" select="$is_param_class_destructor"/>
    <xsl:param name="is_param_class_function_separator" select="''"/>
    <xsl:param name="is_param_class_function" select="''"/>
    <xsl:param name="is_param_class_function_comment" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_pattern" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_pattern_names" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_pattern_names_item" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_name_fixes" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_name" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_return" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_parameters" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_const_proto" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_function_body" select="$is_param_class_function"/>
    <xsl:param name="is_param_class_members_only_ifdefs" select="'no'"/>
    <xsl:param name="is_param_class_members_only_ifdefs_hidden" select="'no'"/>
    <xsl:param name="is_param_class_members_only_ifdefs_name" select="$is_param_class_members_only_ifdefs"/>
    <xsl:param name="is_param_class_member_funcs_interface_ifdefs" select="$is_param_class_members_only_ifdefs"/>
    <xsl:param name="is_param_class_member_funcs_interface_ifdefs_hidden" select="$is_param_class_members_only_ifdefs_hidden"/>
    <xsl:param name="is_param_class_member_funcs_interface_ifdefs_name" select="$is_param_class_member_funcs_interface_ifdefs"/>
    <xsl:param name="is_param_class_member_funcs_implement_ifdefs" select="$is_param_class_member_funcs_interface_ifdefs"/>
    <xsl:param name="is_param_class_member_funcs_implement_ifdefs_hidden" select="$is_param_class_member_funcs_interface_ifdefs_hidden"/>
    <xsl:param name="is_param_class_member_funcs_implement_ifdefs_name" select="$is_param_class_member_funcs_implement_ifdefs"/>

    <xsl:param name="section_text" select="'C++ Class Parameters'"/>

    <xsl:param name="class_comment_text" select="''"/>
    <xsl:param name="class_comment_text_before" select="'//...'"/>
    <xsl:param name="class_comment_text_after" select="''"/>
    <xsl:param name="class_comment_param" select="'class_comment'"/>
    <xsl:param name="class_comment" select="'yes'"/>

    <xsl:param name="class_constructor_comment_text" select="''"/>
    <xsl:param name="class_constructor_comment_text_before" select="'//...'"/>
    <xsl:param name="class_constructor_comment_text_after" select="''"/>
    <xsl:param name="class_constructor_comment_param" select="'class_constructor_comment'"/>
    <xsl:param name="class_constructor_comment" select="$class_comment"/>

    <xsl:param name="class_destructor_comment_text" select="''"/>
    <xsl:param name="class_destructor_comment_text_before" select="'//...'"/>
    <xsl:param name="class_destructor_comment_text_after" select="''"/>
    <xsl:param name="class_destructor_comment_param" select="'class_destructor_comment'"/>
    <xsl:param name="class_destructor_comment" select="$class_comment"/>

    <xsl:param name="class_function_comment_text" select="''"/>
    <xsl:param name="class_function_comment_text_before" select="'//...'"/>
    <xsl:param name="class_function_comment_text_after" select="''"/>
    <xsl:param name="class_function_comment_param" select="'class_function_comment'"/>
    <xsl:param name="class_function_comment" select="$class_comment"/>

    <xsl:param name="class_template_text" select="''"/>
    <xsl:param name="class_template_text_before" select="'template'"/>
    <xsl:param name="class_template_text_after" select="''"/>
    <xsl:param name="class_template_param" select="'class_template'"/>
    <xsl:param name="class_template" select="'no'"/>

    <xsl:param name="class_template_parameters_text" select="''"/>
    <xsl:param name="class_template_parameters_text_before" select="'&lt;'"/>
    <xsl:param name="class_template_parameters_text_after" select="'&gt;'"/>
    <xsl:param name="class_template_parameters_param" select="'class_template_parameters'"/>
    <xsl:param name="class_template_parameters" select="''"/>

    <xsl:param name="class_interface_text" select="''"/>
    <xsl:param name="class_interface_text_before" select="''"/>
    <xsl:param name="class_interface_text_after" select="''"/>
    <xsl:param name="class_interface_param" select="'class_interface'"/>
    <xsl:param name="class_interface" select="''"/>

    <xsl:param name="class_interface_name_text" select="''"/>
    <xsl:param name="class_interface_name_text_before" select="''"/>
    <xsl:param name="class_interface_name_text_after" select="''"/>
    <xsl:param name="class_interface_name_param" select="'class_interface_name'"/>
    <xsl:param name="class_interface_name" select="''"/>

    <xsl:param name="class_name_text" select="'name'"/>
    <xsl:param name="class_name_text_before" select="''"/>
    <xsl:param name="class_name_text_after" select="''"/>
    <xsl:param name="class_name_param" select="'class_name'"/>
    <xsl:param name="class_name" select="''"/>

    <xsl:param name="class_text" select="''"/>
    <xsl:param name="class_text_before" select="'class'"/>
    <xsl:param name="class_text_after" select="''"/>
    <xsl:param name="class_param" select="'class'"/>
    <xsl:param name="class" select="''"/>

    <xsl:param name="class_access_text" select="''"/>
    <xsl:param name="class_access_text_before" select="'{'"/>
    <xsl:param name="class_access_text_after" select="'}'"/>
    <xsl:param name="class_access_param" select="'class_access'"/>
    <xsl:param name="class_access" select="''"/>

    <xsl:param name="class_extends_access_text" select="''"/>
    <xsl:param name="class_extends_access_text_before" select="':'"/>
    <xsl:param name="class_extends_access_text_after" select="''"/>
    <xsl:param name="class_extends_access_param" select="'class_extends_access'"/>
    <xsl:param name="class_extends_access" select="''"/>

    <xsl:param name="class_extends_text" select="''"/>
    <xsl:param name="class_extends_text_before" select="''"/>
    <xsl:param name="class_extends_text_after" select="''"/>
    <xsl:param name="class_extends_param" select="'class_extends'"/>
    <xsl:param name="class_extends" select="''"/>

    <xsl:param name="class_implements_access_text" select="''"/>
    <xsl:param name="class_implements_access_text_before" select="':virtual'"/>
    <xsl:param name="class_implements_access_text_after" select="''"/>
    <xsl:param name="class_implements_access_param" select="'class_implements_access'"/>
    <xsl:param name="class_implements_access" select="''"/>

    <xsl:param name="class_implements_text" select="''"/>
    <xsl:param name="class_implements_text_before" select="''"/>
    <xsl:param name="class_implements_text_after" select="''"/>
    <xsl:param name="class_implements_param" select="'class_implements'"/>
    <xsl:param name="class_implements" select="''"/>

    <xsl:param name="class_derives_text" select="'derives'"/>
    <xsl:param name="class_derives_text_before" select="''"/>
    <xsl:param name="class_derives_text_after" select="''"/>
    <xsl:param name="class_derives_param" select="'class_derives'"/>
    <xsl:param name="class_derives" select="''"/>

    <xsl:param name="class_constructor_text" select="'Constructor'"/>
    <xsl:param name="class_constructor_text_before" select="''"/>
    <xsl:param name="class_constructor_text_after" select="''"/>
    <xsl:param name="class_constructor_param" select="'class_constructor'"/>
    <xsl:param name="class_constructor" select="''"/>

    <xsl:param name="class_constructor_parameters_text" select="''"/>
    <xsl:param name="class_constructor_parameters_text_before" select="'('"/>
    <xsl:param name="class_constructor_parameters_text_after" select="')'"/>
    <xsl:param name="class_constructor_parameters_param" select="'class_constructor_parameters'"/>
    <xsl:param name="class_constructor_parameters" select="''"/>

    <xsl:param name="class_constructor_construct_text" select="''"/>
    <xsl:param name="class_constructor_construct_text_before" select="':'"/>
    <xsl:param name="class_constructor_construct_text_after" select="''"/>
    <xsl:param name="class_constructor_construct_param" select="'class_constructor_construct'"/>
    <xsl:param name="class_constructor_construct" select="''"/>

    <xsl:param name="class_constructor_proto_text" select="''"/>
    <xsl:param name="class_constructor_proto_text_before" select="''"/>
    <xsl:param name="class_constructor_proto_text_after" select="';'"/>
    <xsl:param name="class_constructor_proto_param" select="'class_constructor_proto'"/>
    <xsl:param name="class_constructor_proto_option" select="''"/>
    <xsl:param name="class_constructor_proto" select="$cxx_function_proto"/>

    <xsl:param name="class_constructor_body_text" select="''"/>
    <xsl:param name="class_constructor_body_text_before" select="'{'"/>
    <xsl:param name="class_constructor_body_text_after" select="'}'"/>
    <xsl:param name="class_constructor_body_param" select="'class_constructor_body'"/>
    <xsl:param name="class_constructor_body" select="''"/>

    <xsl:param name="class_destructor_text" select="'Destructor'"/>
    <xsl:param name="class_destructor_text_before" select="''"/>
    <xsl:param name="class_destructor_text_after" select="''"/>
    <xsl:param name="class_destructor_param" select="'class_destructor'"/>
    <xsl:param name="class_destructor" select="''"/>

    <xsl:param name="class_destructor_proto_text" select="''"/>
    <xsl:param name="class_destructor_proto_text_before" select="''"/>
    <xsl:param name="class_destructor_proto_text_after" select="';'"/>
    <xsl:param name="class_destructor_proto_param" select="'class_destructor_proto'"/>
    <xsl:param name="class_destructor_proto_option" select="''"/>
    <xsl:param name="class_destructor_proto" select="$cxx_function_proto"/>

    <xsl:param name="class_destructor_body_text" select="''"/>
    <xsl:param name="class_destructor_body_text_before" select="'{'"/>
    <xsl:param name="class_destructor_body_text_after" select="'}'"/>
    <xsl:param name="class_destructor_body_param" select="'class_destructor_body'"/>
    <xsl:param name="class_destructor_body" select="''"/>

    <xsl:param name="class_function_text" select="'Function'"/>
    <xsl:param name="class_function_text_before" select="''"/>
    <xsl:param name="class_function_text_after" select="''"/>
    <xsl:param name="class_function_param" select="'class_function'"/>
    <xsl:param name="class_function" select="''"/>

    <xsl:param name="class_function_pattern_text" select="''"/>
    <xsl:param name="class_function_pattern_text_before" select="''"/>
    <xsl:param name="class_function_pattern_text_after" select="''"/>
    <xsl:param name="class_function_pattern_param" select="'class_function_pattern'"/>
    <xsl:param name="class_function_pattern" select="''"/>

    <xsl:param name="class_function_pattern_names_text" select="'?/?'"/>
    <xsl:param name="class_function_pattern_names_text_before" select="''"/>
    <xsl:param name="class_function_pattern_names_text_after" select="''"/>
    <xsl:param name="class_function_pattern_names_param" select="'class_function_pattern_names'"/>
    <xsl:param name="class_function_pattern_names" select="''"/>

    <xsl:param name="class_function_pattern_names_item_text" select="''"/>
    <xsl:param name="class_function_pattern_names_item_text_before" select="''"/>
    <xsl:param name="class_function_pattern_names_item_text_after" select="''"/>
    <xsl:param name="class_function_pattern_names_item_param" select="'class_function_pattern_names_item'"/>
    <xsl:param name="class_function_pattern_names_item" select="''"/>

    <xsl:param name="class_function_name_fixes_text" select="'?.../...?'"/>
    <xsl:param name="class_function_name_fixes_text_before" select="''"/>
    <xsl:param name="class_function_name_fixes_text_after" select="''"/>
    <xsl:param name="class_function_name_fixes_param" select="'class_function_name_fixes'"/>
    <xsl:param name="class_function_name_fixes" select="''"/>

    <xsl:param name="class_function_name_text" select="'name'"/>
    <xsl:param name="class_function_name_text_before" select="''"/>
    <xsl:param name="class_function_name_text_after" select="''"/>
    <xsl:param name="class_function_name_param" select="'class_function_name'"/>
    <xsl:param name="class_function_name" select="''"/>

    <xsl:param name="class_function_return_text" select="''"/>
    <xsl:param name="class_function_return_text_before" select="'return'"/>
    <xsl:param name="class_function_return_text_after" select="';'"/>
    <xsl:param name="class_function_return_param" select="'class_function_return'"/>
    <xsl:param name="class_function_return" select="''"/>

    <xsl:param name="class_function_parameters_text" select="''"/>
    <xsl:param name="class_function_parameters_text_before" select="'('"/>
    <xsl:param name="class_function_parameters_text_after" select="')'"/>
    <xsl:param name="class_function_parameters_param" select="'class_function_parameters'"/>
    <xsl:param name="class_function_parameters" select="''"/>

    <xsl:param name="class_function_const_proto_text" select="''"/>
    <xsl:param name="class_function_const_proto_text_before" select="''"/>
    <xsl:param name="class_function_const_proto_text_after" select="''"/>
    <xsl:param name="class_function_const_proto_param" select="'class_function_'"/>
    <xsl:param name="class_function_const_proto_name" select="'class_function_prototype'"/>
    <xsl:param name="class_function_const_proto" select="$cxx_function_proto"/>

    <xsl:param name="class_function_body_text" select="''"/>
    <xsl:param name="class_function_body_text_before" select="'{'"/>
    <xsl:param name="class_function_body_text_after" select="'}'"/>
    <xsl:param name="class_function_body_param" select="'class_function_body'"/>
    <xsl:param name="class_function_body" select="''"/>

    <xsl:param name="class_members_only_ifdefs_name_text" select="''"/>
    <xsl:param name="class_members_only_ifdefs_name_text_before" select="'#if defined('"/>
    <xsl:param name="class_members_only_ifdefs_name_text_after" select="')'"/>
    <xsl:param name="class_members_only_ifdefs_name_size" select="'42'"/>
    <xsl:param name="class_members_only_ifdefs_name_param" select="'class_members_only_ifdefs_name'"/>
    <xsl:param name="class_members_only_ifdefs_name" select="'%CLASS%_MEMBERS_ONLY'"/>

    <xsl:param name="class_members_only_ifdefs_text" select="''"/>
    <xsl:param name="class_members_only_ifdefs_text_before" select="''"/>
    <xsl:param name="class_members_only_ifdefs_text_after" select="''"/>
    <xsl:param name="class_members_only_ifdefs_param" select="'class_members_only_ifdefs'"/>
    <xsl:param name="class_members_only_ifdefs" select="'no'"/>

    <xsl:param name="class_member_funcs_interface_ifdefs_name_text" select="''"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_name_text_before" select="'#if defined('"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_name_text_after" select="')'"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_name_size" select="'42'"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_name_param" select="'class_member_funcs_interface_ifdefs_name'"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_name" select="'%CLASS%_MEMBER_FUNCS_INTERFACE'"/>
    
    <xsl:param name="class_member_funcs_interface_ifdefs_text" select="''"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_text_before" select="''"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_text_after" select="''"/>
    <xsl:param name="class_member_funcs_interface_ifdefs_param" select="'class_member_funcs_interface_ifdefs'"/>
    <xsl:param name="class_member_funcs_interface_ifdefs" select="$class_members_only_ifdefs"/>

    <xsl:param name="class_member_funcs_implement_ifdefs_name_text" select="''"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_name_text_before" select="'#if defined('"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_name_text_after" select="')'"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_name_size" select="'42'"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_name_param" select="'class_member_funcs_implement_ifdefs_name'"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_name" select="'%CLASS%_MEMBER_FUNCS_IMPLEMENT'"/>
    
    <xsl:param name="class_member_funcs_implement_ifdefs_text" select="''"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_text_before" select="''"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_text_after" select="''"/>
    <xsl:param name="class_member_funcs_implement_ifdefs_param" select="'class_member_funcs_implement_ifdefs'"/>
    <xsl:param name="class_member_funcs_implement_ifdefs" select="$class_member_funcs_interface_ifdefs"/>

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

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_comment)) or ('yes' = $is_param_class_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_comment_text"/>
            <xsl:with-param name="text_before" select="$class_comment_text_before"/>
            <xsl:with-param name="text_after" select="$class_comment_text_after"/>
            <xsl:with-param name="name" select="$class_comment_param"/>
            <xsl:with-param name="value" select="$class_comment"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_template)) or ('yes' = $is_param_class_template)">
    <xsl:call-template name="checkbox_row">
        <xsl:with-param name="text" select="$class_template_text"/>
        <xsl:with-param name="text_before" select="$class_template_text_before"/>
        <xsl:with-param name="text_after" select="$class_template_text_after"/>
        <xsl:with-param name="name" select="$class_template_param"/>
        <xsl:with-param name="value" select="$class_template"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_template_parameters)) or ('yes' = $is_param_class_template_parameters)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$class_template_parameters_text"/>
        <xsl:with-param name="text_before" select="$class_template_parameters_text_before"/>
        <xsl:with-param name="text_after" select="$class_template_parameters_text_after"/>
        <xsl:with-param name="name" select="$class_template_parameters_param"/>
        <xsl:with-param name="value" select="$class_template_parameters"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_interface_name)) or ('yes' = $is_param_class_interface_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_interface_name_text"/>
            <xsl:with-param name="text_before" select="$class_interface_name_text_before"/>
            <xsl:with-param name="text_after" select="$class_interface_name_text_after"/>
            <xsl:with-param name="name" select="$class_interface_name_param"/>
            <xsl:with-param name="value" select="$class_interface_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_interface)) or ('yes' = $is_param_class_interface)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_interface_text"/>
            <xsl:with-param name="text_before" select="$class_interface_text_before"/>
            <xsl:with-param name="text_after" select="$class_interface_text_after"/>
            <xsl:with-param name="name" select="$class_interface_param"/>
            <xsl:with-param name="value" select="$class_interface"/>
            <xsl:with-param name="option" select="$cxx_class_interface_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_name)) or ('yes' = $is_param_class_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_name_text"/>
            <xsl:with-param name="text_before" select="$class_name_text_before"/>
            <xsl:with-param name="text_after" select="$class_name_text_after"/>
            <xsl:with-param name="name" select="$class_name_param"/>
            <xsl:with-param name="value" select="$class_name"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class)) or ('yes' = $is_param_class)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_text"/>
            <xsl:with-param name="text_before" select="$class_text_before"/>
            <xsl:with-param name="text_after" select="$class_text_after"/>
            <xsl:with-param name="name" select="$class_param"/>
            <xsl:with-param name="value" select="$class"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_extends_access)) or ('yes' = $is_param_class_extends_access)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_extends_access_text"/>
            <xsl:with-param name="text_before" select="$class_extends_access_text_before"/>
            <xsl:with-param name="text_after" select="$class_extends_access_text_after"/>
            <xsl:with-param name="name" select="$class_extends_access_param"/>
            <xsl:with-param name="value" select="$class_extends_access"/>
            <xsl:with-param name="option" select="$cxx_class_access_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_extends)) or ('yes' = $is_param_class_extends)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_extends_text"/>
            <xsl:with-param name="text_before" select="$class_extends_text_before"/>
            <xsl:with-param name="text_after" select="$class_extends_text_after"/>
            <xsl:with-param name="name" select="$class_extends_param"/>
            <xsl:with-param name="value" select="$class_extends"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_implements_access)) or ('yes' = $is_param_class_implements_access)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_implements_access_text"/>
            <xsl:with-param name="text_before" select="$class_implements_access_text_before"/>
            <xsl:with-param name="text_after" select="$class_implements_access_text_after"/>
            <xsl:with-param name="name" select="$class_implements_access_param"/>
            <xsl:with-param name="value" select="$class_implements_access"/>
            <xsl:with-param name="option" select="$cxx_class_access_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_implements)) or ('yes' = $is_param_class_implements)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_implements_text"/>
            <xsl:with-param name="text_before" select="$class_implements_text_before"/>
            <xsl:with-param name="text_after" select="$class_implements_text_after"/>
            <xsl:with-param name="name" select="$class_implements_param"/>
            <xsl:with-param name="value" select="$class_implements"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_access)) or ('yes' = $is_param_class_access)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_access_text"/>
            <xsl:with-param name="text_before" select="$class_access_text_before"/>
            <xsl:with-param name="text_after" select="$class_access_text_after"/>
            <xsl:with-param name="name" select="$class_access_param"/>
            <xsl:with-param name="value" select="$class_access"/>
            <xsl:with-param name="option" select="$cxx_class_access_types/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_derives)) or ('yes' = $is_param_class_derives)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$class_derives_text"/>
        <xsl:with-param name="text_before" select="$class_derives_text_before"/>
        <xsl:with-param name="text_after" select="$class_derives_text_after"/>
        <xsl:with-param name="name" select="$class_derives_param"/>
        <xsl:with-param name="value" select="$class_derives"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_separator)) or ('yes' = $is_param_class_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor_comment)) or ('yes' = $is_param_class_constructor_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_constructor_comment_text"/>
            <xsl:with-param name="text_before" select="$class_constructor_comment_text_before"/>
            <xsl:with-param name="text_after" select="$class_constructor_comment_text_after"/>
            <xsl:with-param name="name" select="$class_constructor_comment_param"/>
            <xsl:with-param name="value" select="$class_constructor_comment"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor)) or ('yes' = $is_param_class_constructor)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_constructor_text"/>
            <xsl:with-param name="text_before" select="$class_constructor_text_before"/>
            <xsl:with-param name="text_after" select="$class_constructor_text_after"/>
            <xsl:with-param name="name" select="$class_constructor_param"/>
            <xsl:with-param name="value" select="$class_constructor"/>
            <xsl:with-param name="option" select="$cxx_class_constructor_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor_parameters)) or ('yes' = $is_param_class_constructor_parameters)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_constructor_parameters_text"/>
            <xsl:with-param name="text_before" select="$class_constructor_parameters_text_before"/>
            <xsl:with-param name="text_after" select="$class_constructor_parameters_text_after"/>
            <xsl:with-param name="name" select="$class_constructor_parameters_param"/>
            <xsl:with-param name="value" select="$class_constructor_parameters"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor_construct)) or ('yes' = $is_param_class_constructor_construct)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_constructor_construct_text"/>
            <xsl:with-param name="text_before" select="$class_constructor_construct_text_before"/>
            <xsl:with-param name="text_after" select="$class_constructor_construct_text_after"/>
            <xsl:with-param name="name" select="$class_constructor_construct_param"/>
            <xsl:with-param name="value" select="$class_constructor_construct"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor_proto)) or ('yes' = $is_param_class_constructor_proto)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$class_constructor_proto_text"/>
            <xsl:with-param name="text_before" select="$class_constructor_proto_text_before"/>
            <xsl:with-param name="text_after" select="$class_constructor_proto_text_after"/>
            <xsl:with-param name="name" select="$class_constructor_proto_param"/>
            <xsl:with-param name="value" select="$class_constructor_proto"/>
            <xsl:with-param name="option" select="$class_constructor_proto_option"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor_body)) or ('yes' = $is_param_class_constructor_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_constructor_body_text"/>
            <xsl:with-param name="text_before" select="$class_constructor_body_text_before"/>
            <xsl:with-param name="text_after" select="$class_constructor_body_text_after"/>
            <xsl:with-param name="name" select="$class_constructor_body_param"/>
            <xsl:with-param name="value" select="$class_constructor_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_constructor_separator)) or ('yes' = $is_param_class_constructor_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_destructor_comment)) or ('yes' = $is_param_class_destructor_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_destructor_comment_text"/>
            <xsl:with-param name="text_before" select="$class_destructor_comment_text_before"/>
            <xsl:with-param name="text_after" select="$class_destructor_comment_text_after"/>
            <xsl:with-param name="name" select="$class_destructor_comment_param"/>
            <xsl:with-param name="value" select="$class_destructor_comment"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_destructor)) or ('yes' = $is_param_class_destructor)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_destructor_text"/>
            <xsl:with-param name="text_before" select="$class_destructor_text_before"/>
            <xsl:with-param name="text_after" select="$class_destructor_text_after"/>
            <xsl:with-param name="name" select="$class_destructor_param"/>
            <xsl:with-param name="value" select="$class_destructor"/>
            <xsl:with-param name="option" select="$cxx_class_destructor_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_destructor_proto)) or ('yes' = $is_param_class_destructor_proto)">
        <xsl:call-template name="checkbox_row">
            <xsl:with-param name="text" select="$class_destructor_proto_text"/>
            <xsl:with-param name="text_before" select="$class_destructor_proto_text_before"/>
            <xsl:with-param name="text_after" select="$class_destructor_proto_text_after"/>
            <xsl:with-param name="name" select="$class_destructor_proto_param"/>
            <xsl:with-param name="value" select="$class_destructor_proto"/>
            <xsl:with-param name="option" select="$class_constructor_proto_option"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_destructor_body)) or ('yes' = $is_param_class_destructor_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_destructor_body_text"/>
            <xsl:with-param name="text_before" select="$class_destructor_body_text_before"/>
            <xsl:with-param name="text_after" select="$class_destructor_body_text_after"/>
            <xsl:with-param name="name" select="$class_destructor_body_param"/>
            <xsl:with-param name="value" select="$class_destructor_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_destructor_separator)) or ('yes' = $is_param_class_destructor_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_comment)) or ('yes' = $is_param_class_function_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_function_comment_text"/>
            <xsl:with-param name="text_before" select="$class_function_comment_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_comment_text_after"/>
            <xsl:with-param name="name" select="$class_function_comment_param"/>
            <xsl:with-param name="value" select="$class_function_comment"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function)) or ('yes' = $is_param_class_function)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_function_text"/>
            <xsl:with-param name="text_before" select="$class_function_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_text_after"/>
            <xsl:with-param name="name" select="$class_function_param"/>
            <xsl:with-param name="value" select="$class_function"/>
            <xsl:with-param name="option" select="$cxx_class_function_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_return)) or ('yes' = $is_param_class_function_return)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_return_text"/>
            <xsl:with-param name="text_before" select="$class_function_return_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_return_text_after"/>
            <xsl:with-param name="name" select="$class_function_return_param"/>
            <xsl:with-param name="value" select="$class_function_return"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_name)) or ('yes' = $is_param_class_function_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_name_text"/>
            <xsl:with-param name="text_before" select="$class_function_name_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_name_text_after"/>
            <xsl:with-param name="name" select="$class_function_name_param"/>
            <xsl:with-param name="value" select="$class_function_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_parameters)) or ('yes' = $is_param_class_function_parameters)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_parameters_text"/>
            <xsl:with-param name="text_before" select="$class_function_parameters_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_parameters_text_after"/>
            <xsl:with-param name="name" select="$class_function_parameters_param"/>
            <xsl:with-param name="value" select="$class_function_parameters"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_const_proto)) or ('yes' = $is_param_class_function_const_proto)">
        <xsl:call-template name="checkboxes_row">
            <xsl:with-param name="text" select="$class_function_const_proto_text"/>
            <xsl:with-param name="text_before" select="$class_function_const_proto_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_const_proto_text_after"/>
            <xsl:with-param name="name" select="$class_function_const_proto_param"/>
            <xsl:with-param name="value" select="$class_function_const_proto"/>
            <xsl:with-param name="option" select="$cxx_class_function_const_proto_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_body)) or ('yes' = $is_param_class_function_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_body_text"/>
            <xsl:with-param name="text_before" select="$class_function_body_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_body_text_after"/>
            <xsl:with-param name="name" select="$class_function_body_param"/>
            <xsl:with-param name="value" select="$class_function_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_name_fixes)) or ('yes' = $is_param_class_function_name_fixes)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_name_fixes_text"/>
            <xsl:with-param name="text_before" select="$class_function_name_fixes_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_name_fixes_text_after"/>
            <xsl:with-param name="name" select="$class_function_name_fixes_param"/>
            <xsl:with-param name="value" select="$class_function_name_fixes"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_pattern)) or ('yes' = $is_param_class_function_pattern)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_function_pattern_text"/>
            <xsl:with-param name="text_before" select="$class_function_pattern_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_pattern_text_after"/>
            <xsl:with-param name="name" select="$class_function_pattern_param"/>
            <xsl:with-param name="value" select="$class_function_pattern"/>
            <xsl:with-param name="option" select="$cxx_function_patterns/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_pattern_names)) or ('yes' = $is_param_class_function_pattern_names)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_pattern_names_text"/>
            <xsl:with-param name="text_before" select="$class_function_pattern_names_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_pattern_names_text_after"/>
            <xsl:with-param name="name" select="$class_function_pattern_names_param"/>
            <xsl:with-param name="value" select="$class_function_pattern_names"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_pattern_names_item)) or ('yes' = $is_param_class_function_pattern_names_item)">
        <xsl:call-template name="dropbox_row">
            <xsl:with-param name="text" select="$class_function_pattern_names_item_text"/>
            <xsl:with-param name="text_before" select="$class_function_pattern_names_item_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_pattern_names_item_text_after"/>
            <xsl:with-param name="name" select="$class_function_pattern_names_item_param"/>
            <xsl:with-param name="value" select="$class_function_pattern_names_item"/>
            <xsl:with-param name="option" select="$cxx_function_pattern_name_list/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_separator)) or ('yes' = $is_param_class_function_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_members_only_ifdefs_hidden)) or ('yes' = $is_param_class_members_only_ifdefs_hidden)">
        <xsl:call-template name="hidden">
            <xsl:with-param name="name" select="$class_members_only_ifdefs_param"/>
            <xsl:with-param name="value" select="$class_members_only_ifdefs"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_members_only_ifdefs_name)) or ('yes' = $is_param_class_members_only_ifdefs_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_members_only_ifdefs_name_text"/>
            <xsl:with-param name="text_before" select="$class_members_only_ifdefs_name_text_before"/>
            <xsl:with-param name="text_after" select="$class_members_only_ifdefs_name_text_after"/>
            <xsl:with-param name="size" select="$class_members_only_ifdefs_name_size"/>
            <xsl:with-param name="name" select="$class_members_only_ifdefs_name_param"/>
            <xsl:with-param name="value" select="$class_members_only_ifdefs_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_members_only_ifdefs)) or ('yes' = $is_param_class_members_only_ifdefs)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_members_only_ifdefs_text"/>
            <xsl:with-param name="text_before" select="$class_members_only_ifdefs_text_before"/>
            <xsl:with-param name="text_after" select="$class_members_only_ifdefs_text_after"/>
            <xsl:with-param name="name" select="$class_members_only_ifdefs_param"/>
            <xsl:with-param name="value" select="$class_members_only_ifdefs"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_member_funcs_interface_ifdefs_hidden)) or ('yes' = $is_param_class_member_funcs_interface_ifdefs_hidden)">
        <xsl:call-template name="hidden">
            <xsl:with-param name="name" select="$class_member_funcs_interface_ifdefs_param"/>
            <xsl:with-param name="value" select="$class_member_funcs_interface_ifdefs"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_member_funcs_interface_ifdefs_name)) or ('yes' = $is_param_class_member_funcs_interface_ifdefs_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_member_funcs_interface_ifdefs_name_text"/>
            <xsl:with-param name="text_before" select="$class_member_funcs_interface_ifdefs_name_text_before"/>
            <xsl:with-param name="text_after" select="$class_member_funcs_interface_ifdefs_name_text_after"/>
            <xsl:with-param name="size" select="$class_member_funcs_interface_ifdefs_name_size"/>
            <xsl:with-param name="name" select="$class_member_funcs_interface_ifdefs_name_param"/>
            <xsl:with-param name="value" select="$class_member_funcs_interface_ifdefs_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_member_funcs_interface_ifdefs)) or ('yes' = $is_param_class_member_funcs_interface_ifdefs)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_member_funcs_interface_ifdefs_text"/>
            <xsl:with-param name="text_before" select="$class_member_funcs_interface_ifdefs_text_before"/>
            <xsl:with-param name="text_after" select="$class_member_funcs_interface_ifdefs_text_after"/>
            <xsl:with-param name="name" select="$class_member_funcs_interface_ifdefs_param"/>
            <xsl:with-param name="value" select="$class_member_funcs_interface_ifdefs"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_member_funcs_implement_ifdefs_hidden)) or ('yes' = $is_param_class_member_funcs_implement_ifdefs_hidden)">
        <xsl:call-template name="hidden">
            <xsl:with-param name="name" select="$class_member_funcs_implement_ifdefs_param"/>
            <xsl:with-param name="value" select="$class_member_funcs_implement_ifdefs"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_member_funcs_implement_ifdefs_name)) or ('yes' = $is_param_class_member_funcs_implement_ifdefs_name)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_member_funcs_implement_ifdefs_name_text"/>
            <xsl:with-param name="text_before" select="$class_member_funcs_implement_ifdefs_name_text_before"/>
            <xsl:with-param name="text_after" select="$class_member_funcs_implement_ifdefs_name_text_after"/>
            <xsl:with-param name="size" select="$class_member_funcs_implement_ifdefs_name_size"/>
            <xsl:with-param name="name" select="$class_member_funcs_implement_ifdefs_name_param"/>
            <xsl:with-param name="value" select="$class_member_funcs_implement_ifdefs_name"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_member_funcs_implement_ifdefs)) or ('yes' = $is_param_class_member_funcs_implement_ifdefs)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_member_funcs_implement_ifdefs_text"/>
            <xsl:with-param name="text_before" select="$class_member_funcs_implement_ifdefs_text_before"/>
            <xsl:with-param name="text_after" select="$class_member_funcs_implement_ifdefs_text_after"/>
            <xsl:with-param name="name" select="$class_member_funcs_implement_ifdefs_param"/>
            <xsl:with-param name="value" select="$class_member_funcs_implement_ifdefs"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

</xsl:transform>
