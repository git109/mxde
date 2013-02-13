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
<!--   File: medusaxde-create-xosdevelopment-project.xsl                    -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 4/25/2012                                                      -->
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
<xsl:param name="default_xde_form_title_what" select="'XosDevelopment Project'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/xosdevelopment/mxde-xosdevelopment-xdep.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<xsl:param name="xdep_default_project_name" select="'Project'"/>

<xsl:param name="xdep_file_types_tree">
    <type default="yes" value="xdep">.xdep</type>
    <type xdefault="" value="xdp">.xdp</type>
    <type xdefault="" value="no">no</type>
</xsl:param>
<xsl:param name="xdep_file_types"
 select="exsl:node-set($xdep_file_types_tree)"/>

<xsl:param name="xdep_target_types_tree">
    <type default="yes" value="executable">Executable</type>
    <type xdefault="" value="shared-library">Shared Library</type>
    <type xdefault="" value="static-library">Static Library</type>
</xsl:param>
<xsl:param name="xdep_target_types"
 select="exsl:node-set($xdep_target_types_tree)"/>

<xsl:param name="xdep_source_types_tree">
    <type default="yes" value="c++">C++</type>
</xsl:param>
<xsl:param name="xdep_source_types"
 select="exsl:node-set($xdep_source_types_tree)"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="path_parts_tree">
    <part xdefault="" xvalue="">include-paths</part>
    <part xdefault="" xvalue="">library-paths</part>
</xsl:variable>
<xsl:variable name="path_parts"
 select="exsl:node-set($path_parts_tree)"/>

<xsl:variable name="parts_tree">
    <part xdefault="" xvalue="">defines</part>
    <part xdefault="" xvalue="">sources</part>
    <part xdefault="" xvalue="">libraries</part>
    <part default="yes" value="">project</part>
</xsl:variable>
<xsl:variable name="parts"
 select="exsl:node-set($parts_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "xdep_file_type_form_fields"                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/26/2012                                                    -->
<!--========================================================================-->
<xsl:template name="xdep_file_type_form_fields">

    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_file_type" select="$is_param_"/>
    <xsl:param name="is_param_separator" select="$is_param_"/>
    <xsl:param name="is_param_path_part" select="$is_param_"/>
    <xsl:param name="is_param_part" select="$is_param_"/>

    <xsl:param name="file_type_text" select="''"/>
    <xsl:param name="file_type_text_before" select="''"/>
    <xsl:param name="file_type_text_after" select="''"/>
    <xsl:param name="file_type_option" select="''"/>
    <xsl:param name="file_type_options" select="$xdep_file_types/*"/>
    <xsl:param name="file_type_param" select="'file_type'"/>
    <xsl:param name="file_type" select="''"/>

    <xsl:param name="part_text" select="''"/>
    <xsl:param name="part_text_before" select="''"/>
    <xsl:param name="part_text_after" select="'&gt;'"/>
    <xsl:param name="part_option" select="''"/>
    <xsl:param name="part_options" select="$parts/*"/>
    <xsl:param name="part_param" select="'part'"/>
    <xsl:param name="part" select="''"/>

    <xsl:param name="path_part_text" select="''"/>
    <xsl:param name="path_part_text_before" select="'&lt;'"/>
    <xsl:param name="path_part_text_after" select="''"/>
    <xsl:param name="path_part_option" select="''"/>
    <xsl:param name="path_part_options" select="$path_parts/*"/>
    <xsl:param name="path_part_param" select="$part_param"/>
    <xsl:param name="path_part" select="$part"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_type)) or ('yes' = $is_param_file_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$file_type_text"/>
        <xsl:with-param name="text_before" select="$file_type_text_before"/>
        <xsl:with-param name="text_after" select="$file_type_text_after"/>
        <xsl:with-param name="name" select="$file_type_param"/>
        <xsl:with-param name="value" select="$file_type"/>
        <xsl:with-param name="option" select="$file_type_options"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separator)) or ('yes' = $is_param_separator)">
    <xsl:call-template name="separator_section_row">
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_path_part)) or ('yes' = $is_param_path_part)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$path_part_text"/>
        <xsl:with-param name="text_before" select="$path_part_text_before"/>
        <xsl:with-param name="text_after" select="$path_part_text_after"/>
        <xsl:with-param name="name" select="$path_part_param"/>
        <xsl:with-param name="value" select="$path_part"/>
        <xsl:with-param name="option" select="$path_part_options"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_part)) or ('yes' = $is_param_part)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$part_text"/>
        <xsl:with-param name="text_before" select="$part_text_before"/>
        <xsl:with-param name="text_after" select="$part_text_after"/>
        <xsl:with-param name="name" select="$part_param"/>
        <xsl:with-param name="value" select="$part"/>
        <xsl:with-param name="option" select="$part_options"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "xdep_form_fields"                                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/25/2012                                                    -->
<!--========================================================================-->
<xsl:template name="xdep_form_fields">

    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_name" select="$is_param_"/>
    <xsl:param name="is_param_target" select="$is_param_"/>
    <xsl:param name="is_param_target_type" select="$is_param_"/>
    <xsl:param name="is_param_source_type" select="$is_param_"/>
    <xsl:param name="is_param_sections_separator" select="$is_param_"/>
    <xsl:param name="is_param_include_paths" select="$is_param_"/>
    <xsl:param name="is_param_library_paths" select="$is_param_"/>
    <xsl:param name="is_param_defines" select="$is_param_"/>
    <xsl:param name="is_param_sources" select="$is_param_"/>
    <xsl:param name="is_param_libraries" select="$is_param_"/>

    <xsl:param name="section_text" select="'XosDevelopment Project Parameters'"/>

    <xsl:param name="name_text" select="''"/>
    <xsl:param name="name_text_before" select="'name=&quot;'"/>
    <xsl:param name="name_text_after" select="'&quot;'"/>
    <xsl:param name="name_param" select="'name'"/>
    <xsl:param name="name" select="$xdep_default_project_name"/>

    <xsl:param name="target_text" select="''"/>
    <xsl:param name="target_text_before" select="'target=&quot;'"/>
    <xsl:param name="target_text_after" select="'&quot;'"/>
    <xsl:param name="target_param" select="'target'"/>
    <xsl:param name="target" select="$name"/>

    <xsl:param name="target_type_text" select="''"/>
    <xsl:param name="target_type_text_before" select="'target-type=&quot;'"/>
    <xsl:param name="target_type_text_after" select="'&quot;'"/>
    <xsl:param name="target_type_option" select="''"/>
    <xsl:param name="target_type_options" select="$xdep_target_types/*"/>
    <xsl:param name="target_type_param" select="'target_type'"/>
    <xsl:param name="target_type" select="''"/>

    <xsl:param name="source_type_text" select="''"/>
    <xsl:param name="source_type_text_before" select="'source-type=&quot;'"/>
    <xsl:param name="source_type_text_after" select="'&quot;'"/>
    <xsl:param name="source_type_option" select="''"/>
    <xsl:param name="source_type_options" select="$xdep_source_types/*"/>
    <xsl:param name="source_type_param" select="'source_type'"/>
    <xsl:param name="source_type" select="''"/>

    <xsl:param name="include_paths_text" select="''"/>
    <xsl:param name="include_paths_text_before" select="'&lt;include-paths&gt;'"/>
    <xsl:param name="include_paths_text_after" select="'&lt;/include-paths&gt;'"/>
    <xsl:param name="include_paths_param" select="'include_paths_param'"/>
    <xsl:param name="include_paths" select="''"/>

    <xsl:param name="library_paths_text" select="''"/>
    <xsl:param name="library_paths_text_before" select="'&lt;library-paths&gt;'"/>
    <xsl:param name="library_paths_text_after" select="'&lt;/library-paths&gt;'"/>
    <xsl:param name="library_paths_param" select="'library_paths_param'"/>
    <xsl:param name="library_paths" select="''"/>

    <xsl:param name="defines_text" select="''"/>
    <xsl:param name="defines_text_before" select="'&lt;defines&gt;'"/>
    <xsl:param name="defines_text_after" select="'&lt;/defines&gt;'"/>
    <xsl:param name="defines_param" select="'defines_param'"/>
    <xsl:param name="defines" select="''"/>

    <xsl:param name="sources_text" select="''"/>
    <xsl:param name="sources_text_before" select="'&lt;sources&gt;'"/>
    <xsl:param name="sources_text_after" select="'&lt;/sources&gt;'"/>
    <xsl:param name="sources_param" select="'sources_param'"/>
    <xsl:param name="sources" select="''"/>

    <xsl:param name="libraries_text" select="''"/>
    <xsl:param name="libraries_text_before" select="'&lt;libraries&gt;'"/>
    <xsl:param name="libraries_text_after" select="'&lt;/libraries&gt;'"/>
    <xsl:param name="libraries_param" select="'libraries_param'"/>
    <xsl:param name="libraries" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
    <xsl:call-template name="section_row">
        <xsl:with-param name="text" select="$section_text"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_name)) or ('yes' = $is_param_name)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$name_text"/>
        <xsl:with-param name="text_before" select="$name_text_before"/>
        <xsl:with-param name="text_after" select="$name_text_after"/>
        <xsl:with-param name="name" select="$name_param"/>
        <xsl:with-param name="value" select="$name"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_target)) or ('yes' = $is_param_target)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$target_text"/>
        <xsl:with-param name="text_before" select="$target_text_before"/>
        <xsl:with-param name="text_after" select="$target_text_after"/>
        <xsl:with-param name="name" select="$target_param"/>
        <xsl:with-param name="value" select="$target"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_target_type)) or ('yes' = $is_param_target_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$target_type_text"/>
        <xsl:with-param name="text_before" select="$target_type_text_before"/>
        <xsl:with-param name="text_after" select="$target_type_text_after"/>
        <xsl:with-param name="name" select="$target_type_param"/>
        <xsl:with-param name="value" select="$target_type"/>
        <xsl:with-param name="option" select="$target_type_options"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_source_type)) or ('yes' = $is_param_source_type)">
    <xsl:call-template name="radios_row">
        <xsl:with-param name="text" select="$source_type_text"/>
        <xsl:with-param name="text_before" select="$source_type_text_before"/>
        <xsl:with-param name="text_after" select="$source_type_text_after"/>
        <xsl:with-param name="name" select="$source_type_param"/>
        <xsl:with-param name="value" select="$source_type"/>
        <xsl:with-param name="option" select="$source_type_options"/>
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_sections_separator)) or ('yes' = $is_param_sections_separator)">
    <xsl:call-template name="separator_section_row">
    </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_include_paths)) or ('yes' = $is_param_include_paths)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$include_paths_text"/>
        <xsl:with-param name="text_before" select="$include_paths_text_before"/>
        <xsl:with-param name="text_after" select="$include_paths_text_after"/>
        <xsl:with-param name="name" select="$include_paths_param"/>
        <xsl:with-param name="value" select="$include_paths"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_library_paths)) or ('yes' = $is_param_library_paths)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$library_paths_text"/>
        <xsl:with-param name="text_before" select="$library_paths_text_before"/>
        <xsl:with-param name="text_after" select="$library_paths_text_after"/>
        <xsl:with-param name="name" select="$library_paths_param"/>
        <xsl:with-param name="value" select="$library_paths"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_defines)) or ('yes' = $is_param_defines)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$defines_text"/>
        <xsl:with-param name="text_before" select="$defines_text_before"/>
        <xsl:with-param name="text_after" select="$defines_text_after"/>
        <xsl:with-param name="name" select="$defines_param"/>
        <xsl:with-param name="value" select="$defines"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_sources)) or ('yes' = $is_param_sources)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$sources_text"/>
        <xsl:with-param name="text_before" select="$sources_text_before"/>
        <xsl:with-param name="text_after" select="$sources_text_after"/>
        <xsl:with-param name="name" select="$sources_param"/>
        <xsl:with-param name="value" select="$sources"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_libraries)) or ('yes' = $is_param_libraries)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$libraries_text"/>
        <xsl:with-param name="text_before" select="$libraries_text_before"/>
        <xsl:with-param name="text_after" select="$libraries_text_after"/>
        <xsl:with-param name="name" select="$libraries_param"/>
        <xsl:with-param name="value" select="$libraries"/>
    </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/25/2012                                                    -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="file" select="$xdep_default_project_name"/>
    </xsl:call-template>
    <xsl:call-template name="xdep_file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="xdep_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
        

