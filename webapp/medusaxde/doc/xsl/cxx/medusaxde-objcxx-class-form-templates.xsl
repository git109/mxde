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
<!--   File:  medusaxde-objcxx-class-form-templates.xsl                     -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/9/2012                                                       -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "objcxx_class_form_fields"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/9/2012                                                     -->
<!--========================================================================-->
<xsl:template name="objcxx_class_form_fields">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_begin_separator" select="'no'"/>
    <xsl:param name="is_param_end_separator" select="'no'"/>
    <xsl:param name="is_param_class_comment" select="$is_param_"/>
    <xsl:param name="is_param_class_comment_fields" select="$is_param_class_comment"/>
    <xsl:param name="is_param_is_class_comment_fields" select="$is_param_class_comment_fields"/>
    <xsl:param name="is_param_class_type" select="$is_param_"/>
    <xsl:param name="is_param_class" select="$is_param_"/>
    <xsl:param name="is_param_extends" select="$is_param_"/>
    <xsl:param name="is_param_implements" select="$is_param_"/>
    <xsl:param name="is_param_class_init_separator" select="$is_param_"/>
    <xsl:param name="is_param_class_init_comment" select="$is_param_class_comment"/>
    <xsl:param name="is_param_class_init" select="$is_param_"/>
    <xsl:param name="is_param_class_init_parameters" select="$is_param_"/>
    <xsl:param name="is_param_class_init_body" select="$is_param_"/>
    <xsl:param name="is_param_class_dealloc_comment" select="$is_param_class_comment"/>
    <xsl:param name="is_param_class_dealloc" select="$is_param_"/>
    <xsl:param name="is_param_class_dealloc_body" select="$is_param_"/>
    <xsl:param name="is_param_class_function_separator" select="$is_param_"/>
    <xsl:param name="is_param_class_function_comment" select="$is_param_class_comment"/>
    <xsl:param name="is_param_class_function_type" select="$is_param_"/>
    <xsl:param name="is_param_class_function" select="$is_param_"/>
    <xsl:param name="is_param_class_function_return" select="$is_param_"/>
    <xsl:param name="is_param_class_function_parameters" select="$is_param_"/>
    <xsl:param name="is_param_class_function_body" select="$is_param_"/>

    <xsl:param name="section_text" select="'Objective-C++ Class Parameters'"/>

    <xsl:param name="class_comment_text" select="''"/>
    <xsl:param name="class_comment_text_before" select="'//...'"/>
    <xsl:param name="class_comment_text_after" select="''"/>
    <xsl:param name="class_comment_param" select="'class_comment'"/>
    <xsl:param name="class_comment" select="'yes'"/>

    <xsl:param name="is_class_comment_fields_param" select="'is_class_comment_fields'"/>
    <xsl:param name="is_class_comment_fields" select="'yes'"/>

    <xsl:param name="class_comment_fields_text" select="''"/>
    <xsl:param name="class_comment_fields_text_before" select="'//...'"/>
    <xsl:param name="class_comment_fields_text_after" select="''"/>
    <xsl:param name="class_comment_fields_options" select="$cxx_class_comment_fields"/>
    <xsl:param name="class_comment_fields_param" select="'class_comment_fields_'"/>

    <xsl:param name="class_type_text" select="''"/>
    <xsl:param name="class_type_text_before" select="''"/>
    <xsl:param name="class_type_text_after" select="''"/>
    <xsl:param name="class_type_option" select="''"/>
    <xsl:param name="class_type_options" select="$objcxx_class_types/*"/>
    <xsl:param name="class_type_param" select="'class_type'"/>
    <xsl:param name="class_type" select="''"/>

    <xsl:param name="class_text" select="''"/>
    <xsl:param name="class_text_before" select="'class'"/>
    <xsl:param name="class_text_after" select="''"/>
    <xsl:param name="class_param" select="'class'"/>
    <xsl:param name="class" select="''"/>

    <xsl:param name="extends_text" select="''"/>
    <xsl:param name="extends_text_before" select="':'"/>
    <xsl:param name="extends_text_after" select="''"/>
    <xsl:param name="extends_param" select="'extends'"/>
    <xsl:param name="extends" select="''"/>

    <xsl:param name="implements_text" select="''"/>
    <xsl:param name="implements_text_before" select="'&lt;'"/>
    <xsl:param name="implements_text_after" select="'&gt;'"/>
    <xsl:param name="implements_param" select="'implements'"/>
    <xsl:param name="implements" select="''"/>

    <xsl:param name="class_init_comment_text" select="''"/>
    <xsl:param name="class_init_comment_text_before" select="'//...'"/>
    <xsl:param name="class_init_comment_text_after" select="''"/>
    <xsl:param name="class_init_comment_param" select="'class_init_comment'"/>
    <xsl:param name="class_init_comment" select="'yes'"/>

    <xsl:param name="class_init_text" select="''"/>
    <xsl:param name="class_init_text_before" select="'-(id)init'"/>
    <xsl:param name="class_init_text_after" select="''"/>
    <xsl:param name="class_init_param" select="'class_init'"/>
    <xsl:param name="class_init" select="''"/>

    <xsl:param name="class_init_parameters_text" select="''"/>
    <xsl:param name="class_init_parameters_text_before" select="'('"/>
    <xsl:param name="class_init_parameters_text_after" select="')'"/>
    <xsl:param name="class_init_parameters_param" select="'class_init_parameters'"/>
    <xsl:param name="class_init_parameters" select="''"/>

    <xsl:param name="class_init_body_text" select="''"/>
    <xsl:param name="class_init_body_text_before" select="'{'"/>
    <xsl:param name="class_init_body_text_after" select="'}'"/>
    <xsl:param name="class_init_body_param" select="'class_init_body'"/>
    <xsl:param name="class_init_body" select="''"/>

    <xsl:param name="class_dealloc_comment_text" select="''"/>
    <xsl:param name="class_dealloc_comment_text_before" select="'//...'"/>
    <xsl:param name="class_dealloc_comment_text_after" select="''"/>
    <xsl:param name="class_dealloc_comment_param" select="'class_dealloc_comment'"/>
    <xsl:param name="class_dealloc_comment" select="'yes'"/>

    <xsl:param name="class_dealloc_text" select="''"/>
    <xsl:param name="class_dealloc_text_before" select="'-(void)dealloc'"/>
    <xsl:param name="class_dealloc_text_after" select="''"/>
    <xsl:param name="class_dealloc_param" select="'class_dealloc'"/>
    <xsl:param name="class_dealloc" select="''"/>

    <xsl:param name="class_dealloc_body_text" select="''"/>
    <xsl:param name="class_dealloc_body_text_before" select="'{'"/>
    <xsl:param name="class_dealloc_body_text_after" select="'}'"/>
    <xsl:param name="class_dealloc_body_param" select="'class_dealloc_body'"/>
    <xsl:param name="class_dealloc_body" select="''"/>

    <xsl:param name="class_function_comment_text" select="''"/>
    <xsl:param name="class_function_comment_text_before" select="'//...'"/>
    <xsl:param name="class_function_comment_text_after" select="''"/>
    <xsl:param name="class_function_comment_param" select="'class_function_comment'"/>
    <xsl:param name="class_function_comment" select="'yes'"/>

    <xsl:param name="class_function_type_text" select="''"/>
    <xsl:param name="class_function_type_text_before" select="''"/>
    <xsl:param name="class_function_type_text_after" select="''"/>
    <xsl:param name="class_function_type_option" select="''"/>
    <xsl:param name="class_function_type_options" select="$objcxx_class_function_types/*"/>
    <xsl:param name="class_function_type_param" select="'class_function'"/>
    <xsl:param name="class_function_type" select="''"/>

    <xsl:param name="class_function_text" select="'function'"/>
    <xsl:param name="class_function_text_before" select="''"/>
    <xsl:param name="class_function_text_after" select="''"/>
    <xsl:param name="class_function_param" select="'class_function_name'"/>
    <xsl:param name="class_function" select="''"/>

    <xsl:param name="class_function_return_text" select="''"/>
    <xsl:param name="class_function_return_text_before" select="'('"/>
    <xsl:param name="class_function_return_text_after" select="')'"/>
    <xsl:param name="class_function_return_param" select="'class_function_return'"/>
    <xsl:param name="class_function_return" select="''"/>

    <xsl:param name="class_function_parameters_text" select="''"/>
    <xsl:param name="class_function_parameters_text_before" select="'('"/>
    <xsl:param name="class_function_parameters_text_after" select="')'"/>
    <xsl:param name="class_function_parameters_param" select="'class_function_parameters'"/>
    <xsl:param name="class_function_parameters" select="''"/>

    <xsl:param name="class_function_body_text" select="''"/>
    <xsl:param name="class_function_body_text_before" select="'{'"/>
    <xsl:param name="class_function_body_text_after" select="'}'"/>
    <xsl:param name="class_function_body_param" select="'class_function_body'"/>
    <xsl:param name="class_function_body" select="''"/>

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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_begin_separator)) or ('yes' = $is_param_begin_separator)">
        <xsl:call-template name="separator_section_row">
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

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_is_class_comment_fields)) or ('yes' = $is_param_is_class_comment_fields)">
    <xsl:call-template name="hidden">
        <xsl:with-param name="name" select="$is_class_comment_fields_param"/>
        <xsl:with-param name="value" select="$is_class_comment_fields"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_comment_fields)) or ('yes' = $is_param_class_comment_fields)">
    <xsl:call-template name="checkboxes_row">
        <xsl:with-param name="text" select="$class_comment_fields_text"/>
        <xsl:with-param name="text_before" select="$class_comment_fields_text_before"/>
        <xsl:with-param name="text_after" select="$class_comment_fields_text_after"/>
        <xsl:with-param name="name" select="$class_comment_fields_param"/>
        <xsl:with-param name="option" select="$class_comment_fields_options/*"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_type)) or ('yes' = $is_param_class_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_type_text"/>
            <xsl:with-param name="text_before" select="$class_type_text_before"/>
            <xsl:with-param name="text_after" select="$class_type_text_after"/>
            <xsl:with-param name="name" select="$class_type_param"/>
            <xsl:with-param name="value" select="$class_type"/>
            <xsl:with-param name="option" select="$class_type_options"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_extends)) or ('yes' = $is_param_extends)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$extends_text"/>
            <xsl:with-param name="text_before" select="$extends_text_before"/>
            <xsl:with-param name="text_after" select="$extends_text_after"/>
            <xsl:with-param name="name" select="$extends_param"/>
            <xsl:with-param name="value" select="$extends"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_implements)) or ('yes' = $is_param_implements)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$implements_text"/>
            <xsl:with-param name="text_before" select="$implements_text_before"/>
            <xsl:with-param name="text_after" select="$implements_text_after"/>
            <xsl:with-param name="name" select="$implements_param"/>
            <xsl:with-param name="value" select="$implements"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_init_separator)) or ('yes' = $is_param_class_init_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_init_comment)) or ('yes' = $is_param_class_init_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_init_comment_text"/>
            <xsl:with-param name="text_before" select="$class_init_comment_text_before"/>
            <xsl:with-param name="text_after" select="$class_init_comment_text_after"/>
            <xsl:with-param name="name" select="$class_init_comment_param"/>
            <xsl:with-param name="value" select="$class_init_comment"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_init)) or ('yes' = $is_param_class_init)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_init_text"/>
            <xsl:with-param name="text_before" select="$class_init_text_before"/>
            <xsl:with-param name="text_after" select="$class_init_text_after"/>
            <xsl:with-param name="name" select="$class_init_param"/>
            <xsl:with-param name="value" select="$class_init"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_init_parameters)) or ('yes' = $is_param_class_init_parameters)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_init_parameters_text"/>
            <xsl:with-param name="text_before" select="$class_init_parameters_text_before"/>
            <xsl:with-param name="text_after" select="$class_init_parameters_text_after"/>
            <xsl:with-param name="name" select="$class_init_parameters_param"/>
            <xsl:with-param name="value" select="$class_init_parameters"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_init_body)) or ('yes' = $is_param_class_init_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_init_body_text"/>
            <xsl:with-param name="text_before" select="$class_init_body_text_before"/>
            <xsl:with-param name="text_after" select="$class_init_body_text_after"/>
            <xsl:with-param name="name" select="$class_init_body_param"/>
            <xsl:with-param name="value" select="$class_init_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_dealloc_comment)) or ('yes' = $is_param_class_dealloc_comment)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_dealloc_comment_text"/>
            <xsl:with-param name="text_before" select="$class_dealloc_comment_text_before"/>
            <xsl:with-param name="text_after" select="$class_dealloc_comment_text_after"/>
            <xsl:with-param name="name" select="$class_dealloc_comment_param"/>
            <xsl:with-param name="value" select="$class_dealloc_comment"/>
        </xsl:call-template>
    </xsl:if>
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_dealloc)) or ('yes' = $is_param_class_dealloc)">
        <xsl:call-template name="yesno_row">
            <xsl:with-param name="text" select="$class_dealloc_text"/>
            <xsl:with-param name="text_before" select="$class_dealloc_text_before"/>
            <xsl:with-param name="text_after" select="$class_dealloc_text_after"/>
            <xsl:with-param name="name" select="$class_dealloc_param"/>
            <xsl:with-param name="value" select="$class_dealloc"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_dealloc_body)) or ('yes' = $is_param_class_dealloc_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_dealloc_body_text"/>
            <xsl:with-param name="text_before" select="$class_dealloc_body_text_before"/>
            <xsl:with-param name="text_after" select="$class_dealloc_body_text_after"/>
            <xsl:with-param name="name" select="$class_dealloc_body_param"/>
            <xsl:with-param name="value" select="$class_dealloc_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_separator)) or ('yes' = $is_param_class_function_separator)">
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
    
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_type)) or ('yes' = $is_param_class_function_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$class_function_type_text"/>
            <xsl:with-param name="text_before" select="$class_function_type_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_type_text_after"/>
            <xsl:with-param name="name" select="$class_function_type_param"/>
            <xsl:with-param name="value" select="$class_function_type"/>
            <xsl:with-param name="option" select="$class_function_type_options"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function)) or ('yes' = $is_param_class_function)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_text"/>
            <xsl:with-param name="text_before" select="$class_function_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_text_after"/>
            <xsl:with-param name="name" select="$class_function_param"/>
            <xsl:with-param name="value" select="$class_function"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_class_function_body)) or ('yes' = $is_param_class_function_body)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$class_function_body_text"/>
            <xsl:with-param name="text_before" select="$class_function_body_text_before"/>
            <xsl:with-param name="text_after" select="$class_function_body_text_after"/>
            <xsl:with-param name="name" select="$class_function_body_param"/>
            <xsl:with-param name="value" select="$class_function_body"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_end_separator)) or ('yes' = $is_param_end_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>
</xsl:template>
</xsl:transform>
