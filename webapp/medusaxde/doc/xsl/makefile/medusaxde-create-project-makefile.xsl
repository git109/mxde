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
<!--   File: medusaxde-create-project-makefile.xsl                          -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 5/27/2012                                                      -->
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
<xsl:param name="default_xde_form_title_what" select="'Xos Makefile'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/makefile/mxde-project-makefile.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<xsl:param name="makefile_platforms_tree">
    <platform value="Linux" default="yes">Linux</platform>
    <platform value="MacOSX">MacOSX</platform>
    <platform value="">no</platform>
</xsl:param>
<xsl:param name="makefile_platforms" select="exsl:node-set($makefile_platforms_tree)"/>

<xsl:param name="makefile_exe_types_tree">
    <type value="Exe" default="yes">Executable</type>
    <type value="SLib">Shared Library</type>
    <type value="Lib">Static Library</type>
</xsl:param>
<xsl:param name="makefile_exe_types" select="exsl:node-set($makefile_exe_types_tree)"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "project_makefile_form_fields"                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/27/2012                                                    -->
<!--========================================================================-->
<xsl:template name="project_makefile_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="is_param_platform" select="$is_param_"/>
    <xsl:param name="is_param_tools" select="$is_param_"/>
    <xsl:param name="is_param_framework" select="$is_param_"/>
    <xsl:param name="is_param_platform_separator" select="$is_param_"/>
    <xsl:param name="is_param_pkg_path" select="$is_param_"/>
    <xsl:param name="is_param_pkg_dir" select="$is_param_"/>
    <xsl:param name="is_param_prj_path" select="$is_param_"/>
    <xsl:param name="is_param_prj_dir" select="$is_param_"/>
    <xsl:param name="is_param_src_path" select="$is_param_"/>
    <xsl:param name="is_param_src_dir" select="$is_param_"/>
    <xsl:param name="is_param_bld_path" select="$is_param_"/>
    <xsl:param name="is_param_bld_dir" select="$is_param_"/>
    <xsl:param name="is_param_pkg_separator" select="$is_param_"/>
    <xsl:param name="is_param_exe_type" select="$is_param_"/>
    <xsl:param name="is_param_target" select="$is_param_"/>
    <xsl:param name="is_param_sources" select="$is_param_"/>
    <xsl:param name="is_param_libs" select="$is_param_"/>
    <xsl:param name="is_param_libs_separator" select="$is_param_"/>
    <xsl:param name="is_param_deps" select="$is_param_"/>
    <xsl:param name="is_param_dirs" select="$is_param_"/>

    <xsl:param name="section_text">
        <xsl:value-of select="$default_xde_form_title_what"/>
        <xsl:value-of select="' Parameters'"/>
    </xsl:param>

    <xsl:param name="platform_text" select="'Platform'"/>
    <xsl:param name="platform_text_before" select="''"/>
    <xsl:param name="platform_text_after" select="''"/>
    <xsl:param name="platform_option" select="''"/>
    <xsl:param name="platform_options" select="$makefile_platforms/*"/>
    <xsl:param name="platform_param" select="'platform'"/>
    <xsl:param name="platform" select="'Linux'"/>

    <xsl:param name="tools_text" select="'Toolset'"/>
    <xsl:param name="tools_text_before" select="''"/>
    <xsl:param name="tools_text_after" select="''"/>
    <xsl:param name="tools_param" select="'tools'"/>
    <xsl:param name="tools" select="'Gcc'"/>

    <xsl:param name="framework_text" select="'Framework'"/>
    <xsl:param name="framework_text_before" select="''"/>
    <xsl:param name="framework_text_after" select="''"/>
    <xsl:param name="framework_param" select="'framework'"/>
    <xsl:param name="framework" select="'Xde'"/>

    <xsl:param name="pkg_path_text" select="''"/>
    <xsl:param name="pkg_path_text_before" select="'PKG = '"/>
    <xsl:param name="pkg_path_text_after" select="''"/>
    <xsl:param name="pkg_path_param" select="'pkg_path'"/>
    <xsl:param name="pkg_path" select="'$(PWD)'"/>

    <xsl:param name="pkg_dir_text" select="''"/>
    <xsl:param name="pkg_dir_text_before" select="'/'"/>
    <xsl:param name="pkg_dir_text_after" select="''"/>
    <xsl:param name="pkg_dir_param" select="'pkg_dir'"/>
    <xsl:param name="pkg_dir" select="'../../../../../..'"/>

    <xsl:param name="prj_path_text" select="''"/>
    <xsl:param name="prj_path_text_before" select="'PRJ = '"/>
    <xsl:param name="prj_path_text_after" select="''"/>
    <xsl:param name="prj_path_param" select="'prj_path'"/>
    <xsl:param name="prj_path" select="'c/projects'"/>

    <xsl:param name="prj_dir_text" select="''"/>
    <xsl:param name="prj_dir_text_before" select="'/'"/>
    <xsl:param name="prj_dir_text_after" select="''"/>
    <xsl:param name="prj_dir_param" select="'prj_dir'"/>
    <xsl:param name="prj_dir" select="''"/>

    <xsl:param name="src_path_text" select="''"/>
    <xsl:param name="src_path_text_before" select="'SRC = '"/>
    <xsl:param name="src_path_text_after" select="''"/>
    <xsl:param name="src_path_param" select="'src_path'"/>
    <xsl:param name="src_path" select="'c/src'"/>

    <xsl:param name="src_dir_text" select="''"/>
    <xsl:param name="src_dir_text_before" select="'/'"/>
    <xsl:param name="src_dir_text_after" select="''"/>
    <xsl:param name="src_dir_param" select="'src_dir'"/>
    <xsl:param name="src_dir" select="''"/>

    <xsl:param name="bld_path_text" select="''"/>
    <xsl:param name="bld_path_text_before" select="'BLD = '"/>
    <xsl:param name="bld_path_text_after" select="''"/>
    <xsl:param name="bld_path_param" select="'bld_path'"/>
    <xsl:param name="bld_path" select="''"/>

    <xsl:param name="bld_dir_text" select="''"/>
    <xsl:param name="bld_dir_text_before" select="'/'"/>
    <xsl:param name="bld_dir_text_after" select="''"/>
    <xsl:param name="bld_dir_param" select="'bld_dir'"/>
    <xsl:param name="bld_dir" select="''"/>

    <xsl:param name="exe_type_text" select="''"/>
    <xsl:param name="exe_type_text_before" select="''"/>
    <xsl:param name="exe_type_text_after" select="''"/>
    <xsl:param name="exe_type_option" select="''"/>
    <xsl:param name="exe_type_options" select="$makefile_exe_types/*"/>
    <xsl:param name="exe_type_param" select="'exe'"/>
    <xsl:param name="exe_type" select="''"/>

    <xsl:param name="target_text" select="''"/>
    <xsl:param name="target_text_before" select="'TARGET = '"/>
    <xsl:param name="target_text_after" select="''"/>
    <xsl:param name="target_param" select="'target'"/>
    <xsl:param name="target" select="''"/>

    <xsl:param name="sources_text" select="''"/>
    <xsl:param name="sources_text_before" select="'SOURCES = '"/>
    <xsl:param name="sources_text_after" select="''"/>
    <xsl:param name="sources_param" select="'exe_sources'"/>
    <xsl:param name="sources" select="''"/>

    <xsl:param name="libs_text" select="''"/>
    <xsl:param name="libs_text_before" select="'LIBS = '"/>
    <xsl:param name="libs_text_after" select="''"/>
    <xsl:param name="libs_param" select="'exe_libs'"/>
    <xsl:param name="libs" select="''"/>

    <xsl:param name="deps_text" select="''"/>
    <xsl:param name="deps_text_before" select="'DEPS = '"/>
    <xsl:param name="deps_text_after" select="''"/>
    <xsl:param name="deps_param" select="'exe_deps'"/>
    <xsl:param name="deps" select="''"/>

    <xsl:param name="dirs_text" select="''"/>
    <xsl:param name="dirs_text_before" select="'DIRS = '"/>
    <xsl:param name="dirs_text_after" select="''"/>
    <xsl:param name="dirs_param" select="'exe_dirs'"/>
    <xsl:param name="dirs" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_platform)) or ('yes' = $is_param_platform)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$platform_text"/>
            <xsl:with-param name="text_before" select="$platform_text_before"/>
            <xsl:with-param name="text_after" select="$platform_text_after"/>
            <xsl:with-param name="name" select="$platform_param"/>
            <xsl:with-param name="value" select="$platform"/>
            <xsl:with-param name="option" select="$platform_options"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_tools)) or ('yes' = $is_param_tools)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$tools_text"/>
            <xsl:with-param name="text_before" select="$tools_text_before"/>
            <xsl:with-param name="text_after" select="$tools_text_after"/>
            <xsl:with-param name="name" select="$tools_param"/>
            <xsl:with-param name="value" select="$tools"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_framework)) or ('yes' = $is_param_framework)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$framework_text"/>
            <xsl:with-param name="text_before" select="$framework_text_before"/>
            <xsl:with-param name="text_after" select="$framework_text_after"/>
            <xsl:with-param name="name" select="$framework_param"/>
            <xsl:with-param name="value" select="$framework"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_platform_separator)) or ('yes' = $is_param_platform_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_pkg_path)) or ('yes' = $is_param_pkg_path)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$pkg_path_text"/>
            <xsl:with-param name="text_before" select="$pkg_path_text_before"/>
            <xsl:with-param name="text_after" select="$pkg_path_text_after"/>
            <xsl:with-param name="name" select="$pkg_path_param"/>
            <xsl:with-param name="value" select="$pkg_path"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_pkg_dir)) or ('yes' = $is_param_pkg_dir)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$pkg_dir_text"/>
            <xsl:with-param name="text_before" select="$pkg_dir_text_before"/>
            <xsl:with-param name="text_after" select="$pkg_dir_text_after"/>
            <xsl:with-param name="name" select="$pkg_dir_param"/>
            <xsl:with-param name="value" select="$pkg_dir"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_prj_path)) or ('yes' = $is_param_prj_path)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$prj_path_text"/>
            <xsl:with-param name="text_before" select="$prj_path_text_before"/>
            <xsl:with-param name="text_after" select="$prj_path_text_after"/>
            <xsl:with-param name="name" select="$prj_path_param"/>
            <xsl:with-param name="value" select="$prj_path"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_prj_dir)) or ('yes' = $is_param_prj_dir)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$prj_dir_text"/>
            <xsl:with-param name="text_before" select="$prj_dir_text_before"/>
            <xsl:with-param name="text_after" select="$prj_dir_text_after"/>
            <xsl:with-param name="name" select="$prj_dir_param"/>
            <xsl:with-param name="value" select="$prj_dir"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_src_path)) or ('yes' = $is_param_src_path)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$src_path_text"/>
            <xsl:with-param name="text_before" select="$src_path_text_before"/>
            <xsl:with-param name="text_after" select="$src_path_text_after"/>
            <xsl:with-param name="name" select="$src_path_param"/>
            <xsl:with-param name="value" select="$src_path"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_src_dir)) or ('yes' = $is_param_src_dir)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$src_dir_text"/>
            <xsl:with-param name="text_before" select="$src_dir_text_before"/>
            <xsl:with-param name="text_after" select="$src_dir_text_after"/>
            <xsl:with-param name="name" select="$src_dir_param"/>
            <xsl:with-param name="value" select="$src_dir"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_bld_path)) or ('yes' = $is_param_bld_path)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$bld_path_text"/>
            <xsl:with-param name="text_before" select="$bld_path_text_before"/>
            <xsl:with-param name="text_after" select="$bld_path_text_after"/>
            <xsl:with-param name="name" select="$bld_path_param"/>
            <xsl:with-param name="value" select="$bld_path"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_bld_dir)) or ('yes' = $is_param_bld_dir)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$bld_dir_text"/>
            <xsl:with-param name="text_before" select="$bld_dir_text_before"/>
            <xsl:with-param name="text_after" select="$bld_dir_text_after"/>
            <xsl:with-param name="name" select="$bld_dir_param"/>
            <xsl:with-param name="value" select="$bld_dir"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_pkg_separator)) or ('yes' = $is_param_pkg_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_exe_type)) or ('yes' = $is_param_exe_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$exe_type_text"/>
            <xsl:with-param name="text_before" select="$exe_type_text_before"/>
            <xsl:with-param name="text_after" select="$exe_type_text_after"/>
            <xsl:with-param name="name" select="$exe_type_param"/>
            <xsl:with-param name="value" select="$exe_type"/>
            <xsl:with-param name="option" select="$exe_type_options"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_sources)) or ('yes' = $is_param_sources)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$sources_text"/>
            <xsl:with-param name="text_before" select="$sources_text_before"/>
            <xsl:with-param name="text_after" select="$sources_text_after"/>
            <xsl:with-param name="name" select="$sources_param"/>
            <xsl:with-param name="value" select="$sources"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_libs)) or ('yes' = $is_param_libs)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$libs_text"/>
            <xsl:with-param name="text_before" select="$libs_text_before"/>
            <xsl:with-param name="text_after" select="$libs_text_after"/>
            <xsl:with-param name="name" select="$libs_param"/>
            <xsl:with-param name="value" select="$libs"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_libs_separator)) or ('yes' = $is_param_libs_separator)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_deps)) or ('yes' = $is_param_deps)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$deps_text"/>
            <xsl:with-param name="text_before" select="$deps_text_before"/>
            <xsl:with-param name="text_after" select="$deps_text_after"/>
            <xsl:with-param name="name" select="$deps_param"/>
            <xsl:with-param name="value" select="$deps"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_dirs)) or ('yes' = $is_param_dirs)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$dirs_text"/>
            <xsl:with-param name="text_before" select="$dirs_text_before"/>
            <xsl:with-param name="text_after" select="$dirs_text_after"/>
            <xsl:with-param name="name" select="$dirs_param"/>
            <xsl:with-param name="value" select="$dirs"/>
        </xsl:call-template>
    </xsl:if>

</xsl:template>

<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/27/2012                                                    -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="project_makefile_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
