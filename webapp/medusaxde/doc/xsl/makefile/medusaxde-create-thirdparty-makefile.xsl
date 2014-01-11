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
<!--   File: medusaxde-create-thirdparty-makefile.xsl                       -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/26/2011                                                      -->
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
<xsl:param name="default_xde_form_title_what" select="'Thirdparty Makefile'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/makefile/mxde-thirdparty-makefile.t'"/>
<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="archived_types_tree">
	<type default="yes">tar</type>
	<type>zip</type>
	<type>rpm</type>
	<type value="">none</type>
</xsl:variable>
<xsl:variable name="archived_types"
 select="exsl:node-set($archived_types_tree)"/>
    
<xsl:variable name="compressed_types_tree">
	<type default="yes">gz</type>
	<type>bz2</type>
	<type>z</type>
	<type value="">none</type>
</xsl:variable>
<xsl:variable name="compressed_types"
 select="exsl:node-set($compressed_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: "thirdparty_makefile_form_fields"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/26/2011                                                    -->
<!--========================================================================-->
<xsl:template name="thirdparty_makefile_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_section" select="''"/>
    <xsl:param name="is_param_what" select="''"/>
    <xsl:param name="is_param_version_section" select="''"/>
    <xsl:param name="is_param_version_major" select="''"/>
    <xsl:param name="is_param_version_minor" select="''"/>
    <xsl:param name="is_param_version_release" select="''"/>
    <xsl:param name="is_param_package_section" select="''"/>
    <xsl:param name="is_param_archived" select="''"/>
    <xsl:param name="is_param_compressed" select="''"/>

    <xsl:param name="section_text" select="'Thirdparty Makefile Parameters'"/>

    <xsl:param name="what_text" select="'For'"/>
    <xsl:param name="what_text_before" select="''"/>
    <xsl:param name="what_text_after" select="''"/>
    <xsl:param name="what_param" select="'what'"/>
    <xsl:param name="what" select="'Project'"/>

    <xsl:param name="version_section_text" select="'Version'"/>
    <xsl:param name="version_major_text" select="'Major'"/>
    <xsl:param name="version_major_text_before" select="''"/>
    <xsl:param name="version_major_text_after" select="''"/>
    <xsl:param name="version_major_param" select="'version_major'"/>
    <xsl:param name="version_major" select="'1'"/>

    <xsl:param name="version_minor_text" select="'Minor'"/>
    <xsl:param name="version_minor_text_before" select="''"/>
    <xsl:param name="version_minor_text_after" select="''"/>
    <xsl:param name="version_minor_param" select="'version_minor'"/>
    <xsl:param name="version_minor" select="'1'"/>

    <xsl:param name="version_release_text" select="'Release'"/>
    <xsl:param name="version_release_text_before" select="''"/>
    <xsl:param name="version_release_text_after" select="''"/>
    <xsl:param name="version_release_param" select="'version_release'"/>
    <xsl:param name="version_release" select="'1'"/>

    <xsl:param name="package_section_text" select="'Package'"/>
    <xsl:param name="archived_text" select="'Archived'"/>
    <xsl:param name="archived_text_before" select="''"/>
    <xsl:param name="archived_text_after" select="''"/>
    <xsl:param name="archived_param" select="'archived'"/>
    <xsl:param name="archived" select="'tar'"/>

    <xsl:param name="compressed_text" select="'Compressed'"/>
    <xsl:param name="compressed_text_before" select="''"/>
    <xsl:param name="compressed_text_after" select="''"/>
    <xsl:param name="compressed_param" select="'compressed'"/>
    <xsl:param name="compressed" select="'gz'"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_what)) or ('yes' = $is_param_what)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$what_text"/>
            <xsl:with-param name="text_before" select="$what_text_before"/>
            <xsl:with-param name="text_after" select="$what_text_after"/>
            <xsl:with-param name="name" select="$what_param"/>
            <xsl:with-param name="value" select="$what"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_version_section)) or ('yes' = $is_param_version_section)">
        <xsl:call-template name="subsection_row">
            <xsl:with-param name="text" select="$version_section_text"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_version_major)) or ('yes' = $is_param_version_major)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$version_major_text"/>
            <xsl:with-param name="text_before" select="$version_major_text_before"/>
            <xsl:with-param name="text_after" select="$version_major_text_after"/>
            <xsl:with-param name="name" select="$version_major_param"/>
            <xsl:with-param name="value" select="$version_major"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_version_minor)) or ('yes' = $is_param_version_minor)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$version_minor_text"/>
            <xsl:with-param name="text_before" select="$version_minor_text_before"/>
            <xsl:with-param name="text_after" select="$version_minor_text_after"/>
            <xsl:with-param name="name" select="$version_minor_param"/>
            <xsl:with-param name="value" select="$version_minor"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_version_release)) or ('yes' = $is_param_version_release)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$version_release_text"/>
            <xsl:with-param name="text_before" select="$version_release_text_before"/>
            <xsl:with-param name="text_after" select="$version_release_text_after"/>
            <xsl:with-param name="name" select="$version_release_param"/>
            <xsl:with-param name="value" select="$version_release"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_package_section)) or ('yes' = $is_param_package_section)">
        <xsl:call-template name="subsection_row">
            <xsl:with-param name="text" select="$package_section_text"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_archived)) or ('yes' = $is_param_archived)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$archived_text"/>
            <xsl:with-param name="text_before" select="$archived_text_before"/>
            <xsl:with-param name="text_after" select="$archived_text_after"/>
            <xsl:with-param name="name" select="$archived_param"/>
            <xsl:with-param name="value" select="$archived"/>
            <xsl:with-param name="option" select="$archived_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_compressed)) or ('yes' = $is_param_compressed)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$compressed_text"/>
            <xsl:with-param name="text_before" select="$compressed_text_before"/>
            <xsl:with-param name="text_after" select="$compressed_text_after"/>
            <xsl:with-param name="name" select="$compressed_param"/>
            <xsl:with-param name="value" select="$compressed"/>
            <xsl:with-param name="option" select="$compressed_types/*"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/26/2011                                                    -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
    </xsl:call-template>
    <xsl:call-template name="thirdparty_makefile_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
