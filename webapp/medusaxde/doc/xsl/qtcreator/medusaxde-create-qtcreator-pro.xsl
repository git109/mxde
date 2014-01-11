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
<!--   File: medusaxde-create-qtcreator-pro.xsl                             -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/27/2011                                                      -->
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
<xsl:param name="default_xde_form_title_what" select="'QtCreator Project'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/qtcreator/mxde-qtcreator-pro.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="target_types_tree">
    <type value="executable" default="yes">executable</type>
    <type value="shared-library">shared library (.so)</type>
    <type value="library">library (.a)</type>
</xsl:variable>
<xsl:variable name="target_types" 
 select="exsl:node-set($target_types_tree)"/>

<xsl:variable name="lib_items_tree">
    <lib></lib>
    <lib default="yes">pthread</lib>
    <lib default="yes">dl</lib>
    <lib default="yes">rt</lib>
</xsl:variable>
<xsl:variable name="lib_items" 
 select="exsl:node-set($lib_items_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "qtcreator_form_fields"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/27/2011                                                    -->
<!--========================================================================-->
<xsl:template name="qtcreator_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_target" select="''"/>
    <xsl:param name="is_param_target_type" select="''"/>
    <xsl:param name="is_param_defines" select="''"/>
    <xsl:param name="is_param_includepath" select="''"/>
    <xsl:param name="is_param_libpath" select="''"/>
    <xsl:param name="is_param_libs" select="''"/>
    <xsl:param name="is_param_lib_item" select="''"/>

    <xsl:param name="section_text" select="'QtCreator Parameters'"/>

    <xsl:param name="target_text" select="''"/>
    <xsl:param name="target_text_before" select="'TARGET ='"/>
    <xsl:param name="target_text_after" select="''"/>
    <xsl:param name="target_param" select="'target'"/>
    <xsl:param name="target" select="''"/>

    <xsl:param name="target_type_text" select="''"/>
    <xsl:param name="target_type_text_before" select="'TEMPLATE ='"/>
    <xsl:param name="target_type_text_after" select="''"/>
    <xsl:param name="target_type_param" select="'target_type'"/>
    <xsl:param name="target_type" select="''"/>

    <xsl:param name="defines_text" select="''"/>
    <xsl:param name="defines_text_before" select="'DEFINES +='"/>
    <xsl:param name="defines_text_after" select="''"/>
    <xsl:param name="defines_param" select="'defines'"/>
    <xsl:param name="defines" select="''"/>
    
    <xsl:param name="includepath_text" select="''"/>
    <xsl:param name="includepath_text_before" select="'INCLUDEPATH +='"/>
    <xsl:param name="includepath_text_after" select="''"/>
    <xsl:param name="includepath_param" select="'includepath'"/>
    <xsl:param name="includepath" select="''"/>
    
    <xsl:param name="libpath_text" select="''"/>
    <xsl:param name="libpath_text_before" select="'LIBS += -L'"/>
    <xsl:param name="libpath_text_after" select="''"/>
    <xsl:param name="libpath_param" select="'libpath'"/>
    <xsl:param name="libpath" select="''"/>

    <xsl:param name="libs_text" select="''"/>
    <xsl:param name="libs_text_before" select="'-l'"/>
    <xsl:param name="libs_text_after" select="''"/>
    <xsl:param name="libs_param" select="'libs'"/>
    <xsl:param name="libs" select="''"/>

    <xsl:param name="lib_item_text" select="''"/>
    <xsl:param name="lib_item_text_before" select="''"/>
    <xsl:param name="lib_item_text_after" select="''"/>
    <xsl:param name="lib_item_param" select="'lib_item'"/>
    <xsl:param name="lib_item" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
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
            <xsl:with-param name="option" select="$target_types/*"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_includepath)) or ('yes' = $is_param_includepath)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$includepath_text"/>
            <xsl:with-param name="text_before" select="$includepath_text_before"/>
            <xsl:with-param name="text_after" select="$includepath_text_after"/>
            <xsl:with-param name="name" select="$includepath_param"/>
            <xsl:with-param name="value" select="$includepath"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_libpath)) or ('yes' = $is_param_libpath)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$libpath_text"/>
            <xsl:with-param name="text_before" select="$libpath_text_before"/>
            <xsl:with-param name="text_after" select="$libpath_text_after"/>
            <xsl:with-param name="name" select="$libpath_param"/>
            <xsl:with-param name="value" select="$libpath"/>
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
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_lib_item)) or ('yes' = $is_param_lib_item)">
        <xsl:call-template name="listbox_row">
            <xsl:with-param name="size" select="'4'"/>
            <xsl:with-param name="multiple" select="'yes'"/>
            <xsl:with-param name="text" select="$lib_item_text"/>
            <xsl:with-param name="text_before" select="$lib_item_text_before"/>
            <xsl:with-param name="text_after" select="$lib_item_text_after"/>
            <xsl:with-param name="name" select="$lib_item_param"/>
            <xsl:with-param name="value" select="$lib_item"/>
            <xsl:with-param name="option" select="$lib_items/*"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/27/2011                                                    -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="qtcreator_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
