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
<!--   File: medusaxde-create.xsl                                           -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/26/2011                                                      -->
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
<xsl:include href="medusaxde-parameters.xsl"/>
<xsl:include href="medusaxde-templates.xsl"/>
<xsl:include href="medusaxde-form-parameters.xsl"/>
<xsl:include href="medusaxde-form-templates.xsl"/>
<xsl:include href="medusaxde-transform-parameters.xsl"/>
<xsl:include href="medusaxde-transform-templates.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_do" select="'Create '"/>
<xsl:param name="default_xde_form_title_what_file" select="' File'"/>
<xsl:param name="default_xde_form_title_what_parameters" select="' Parameters'"/>
<xsl:param name="default_xde_form_title">
    <xsl:value-of select="$default_xde_form_title_do"/>
    <xsl:value-of select="$default_xde_form_title_what"/>
</xsl:param>
<xsl:param name="default_xde_form_section">
    <xsl:value-of select="$default_xde_form_title_what"/>
    <xsl:value-of select="$default_xde_form_title_what_file"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<xsl:param name="xsl_form_section">
    <xsl:value-of select="$default_xde_form_title_what"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<xsl:param name="xsl_transform_form_section">
    <xsl:value-of select="'&lt;xsl:transform&gt;'"/>
    <xsl:value-of select="$default_xde_form_title_what_parameters"/>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="form_section">
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
<!-- Template: "form_fields"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/26/2011                                                    -->
<!--========================================================================-->
<xsl:template name="form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="create_form_fields">
    </xsl:call-template>
    <xsl:call-template name="transformation_form_fields">
    </xsl:call-template>
    <xsl:call-template name="file_creation_form_fields">
        <xsl:with-param name="date" select="$current_date"/>
        <xsl:with-param name="year" select="$current_year"/>
    </xsl:call-template>
    <xsl:call-template name="form_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
