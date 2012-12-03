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
<!--   File: medusaxde-form-parameters.xsl                                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/12/2011                                                      -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_bgcolor" select="'gray'"/>
<xsl:param name="default_xde_form_header_bgcolor" select="'white'"/>
<xsl:param name="default_xde_form_section_bgcolor" select="'black'"/>
<xsl:param name="default_xde_form_subsection_bgcolor" select="'gray'"/>
<xsl:param name="default_xde_form_separator_section_bgcolor" select="'gray'"/>

<xsl:param name="default_xde_form_font_face" select="'arial'"/>
<xsl:param name="default_xde_form_font_size" select="'2'"/>
<xsl:param name="default_xde_form_font_color" select="'black'"/>

<xsl:param name="default_xde_form_section_font_face" select="$default_xde_form_font_face"/>
<xsl:param name="default_xde_form_section_font_size" select="'3'"/>
<xsl:param name="default_xde_form_section_font_color" select="'green'"/>

<xsl:param name="default_xde_form_separator_section_height" select="'7'"/>
<xsl:param name="default_xde_form_section_separator_height" select="'7'"/>
    
<xsl:param name="default_xde_form_subsection_font_face" select="$default_xde_form_font_face"/>
<xsl:param name="default_xde_form_subsection_font_size" select="'2'"/>
<xsl:param name="default_xde_form_subsection_font_color" select="'black'"/>

<xsl:param name="default_xde_form_header_font_face" select="$default_xde_form_font_face"/>
<xsl:param name="default_xde_form_header_font_size" select="'3'"/>
<xsl:param name="default_xde_form_header_font_color" select="'green'"/>

<xsl:param name="default_xde_form_input_size" select="'32'"/>

<xsl:param name="default_xde_form_submit" select="'Submit'"/>
<xsl:param name="default_xde_form_method" select="'post'"/>
    
<!--========================================================================-->
<!-- values                                                                 -->
<!--========================================================================-->
<xsl:param name="form_xde_form_submit" select="$default_xde_form_submit" />
<xsl:param name="xde_form_submit">
    <xsl:choose>
        <xsl:when test="'' != $form_xde_form_submit">
            <xsl:value-of select="$form_xde_form_submit" />
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_submit" />
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<xsl:param name="form_xde_form_method" select="$default_xde_form_method" />
<xsl:param name="xde_form_method">
    <xsl:choose>
        <xsl:when test="'' != $form_xde_form_method">
            <xsl:value-of select="$form_xde_form_method" />
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_method" />
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<xsl:param name="form_xde_form_action" select="$default_xde_form_action" />
<xsl:param name="xde_form_action">
    <xsl:choose>
        <xsl:when test="'' != $form_xde_form_action">
            <xsl:value-of select="$form_xde_form_action" />
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_action" />
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="form_xde_form_section" select="''" />
<xsl:param name="xde_form_section">
    <xsl:choose>
        <xsl:when test="'' != $form_xde_form_section">
            <xsl:value-of select="$form_xde_form_section" />
        </xsl:when>
        <xsl:otherwise>
            <xsl:if test="'1' = $form">
                <xsl:value-of select="$default_xde_form_section" />
            </xsl:if>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="form_xde_form_title" select="$default_xde_form_title" />
<xsl:param name="xde_form_title">
    <xsl:choose>
        <xsl:when test="'' != $form_xde_form_title">
            <xsl:value-of select="$form_xde_form_title" />
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_title" />
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="form_xde_form_onsubmit_is_location" select="$default_xde_form_onsubmit_is_location"/>
<xsl:param name="xde_form_onsubmit_is_location">
    <xsl:choose>
        <xsl:when test="'' != $form_xde_form_onsubmit_is_location">
            <xsl:value-of select="$form_xde_form_onsubmit_is_location"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_onsubmit_is_location"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="xde_for_parameters" 
 select="/*/mxde:for/mxde:for-which"/>
  
<xsl:variable name="xde_action_item_tree">
    <item></item>
    <item>/xde-cgi/cgi</item>
    <item>/xde-cgi/cgicatch</item>
    <item>/xde-cgi/tcgi</item>
    <item>http://localhost/xde-cgi/cgi.exe</item>
    <item>http://localhost/xde-cgi/cgicatch.exe</item>
    <item>http://localhost/xde-cgi/tcgi.exe</item>
    <item></item>
    <item>/mxde-cgi/ccgi</item>
    <item>/mxde-cgi/ccgicatch</item>
    <item>/mxde-cgi/ctcgi</item>
    <item>http://localhost/mxde-cgi/ccgi.exe</item>
    <item>http://localhost/mxde-cgi/ccgicatch.exe</item>
    <item>http://localhost/mxde-cgi/ctcgi.exe</item>
    <item></item>
    <item>/mxde/t/mxde-form-t-parameters.t</item>
    <item>/mxde/t/mxde-form-value-t-parameters.t</item>
    <item>/mxde/t/mxde-form-xsl-parameters.t</item>
    <item>/mxde/t/mxde-form-value-xsl-parameters.t</item>
</xsl:variable>
<xsl:variable name="xde_action_list" 
 select="exsl:node-set($xde_action_item_tree)"/>
 
<xsl:variable name="xde_content_types_tree">
	<xde:content-type>text/xml</xde:content-type>
	<xde:content-type>text/html</xde:content-type>
	<xde:content-type
     default="yes">text/plain</xde:content-type>
	<xde:content-type>download</xde:content-type>
</xsl:variable>
<xsl:variable name="xde_content_types"
 select="exsl:node-set($xde_content_types_tree)"/>
    
<!--========================================================================-->
<!-- colors                                                                 -->
<!--========================================================================-->
<xsl:variable name="xde_forms_colors" select="/*/xde:folders/xde:forms/xde:colors"/>
<xsl:variable name="xde_form_bgcolor">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[@id = 'bgcolor']"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_bgcolor"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_header_bgcolor">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[@id = 'header_bgcolor']"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_header_bgcolor"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
    
<xsl:variable name="xde_form_section_bgcolor">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[@id = 'section_bgcolor']"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_section_bgcolor"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
    
<xsl:variable name="xde_form_subsection_bgcolor">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[@id = 'subsection_bgcolor']"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_subsection_bgcolor"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
    
<xsl:variable name="xde_form_separator_section_bgcolor">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[@id = 'separator_section_bgcolor']"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_separator_section_bgcolor"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<!--========================================================================-->
<!-- fonts                                                                  -->
<!--========================================================================-->
<xsl:variable name="xde_forms_fonts" select="/*/xde:folders/xde:forms/xde:fonts"/>
<xsl:variable name="xde_form_font" select="$xde_forms_fonts/xde:font[''=@id]"/>
<xsl:variable name="xde_form_font_face">
    <xsl:variable name="select" select="$xde_form_font/@face"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_font_face"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_font_size">
    <xsl:variable name="select" select="$xde_form_font/@size"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_font_size"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_font_color">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[$xde_form_font/@color=@id]"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_font_color"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_section_font" select="$xde_forms_fonts/xde:font['section'=@id]"/>
<xsl:variable name="xde_form_section_font_face">
    <xsl:variable name="select" select="$xde_form_section_font/@face"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_section_font_face"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_section_font_size">
    <xsl:variable name="select" select="$xde_form_section_font/@size"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_section_font_size"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_section_font_color">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[$xde_form_section_font/@color=@id]"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_section_font_color"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_subsection_font" select="$xde_forms_fonts/xde:font['subsection'=@id]"/>
<xsl:variable name="xde_form_subsection_font_face">
    <xsl:variable name="select" select="$xde_form_subsection_font/@face"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_subsection_font_face"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_subsection_font_size">
    <xsl:variable name="select" select="$xde_form_subsection_font/@size"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_subsection_font_size"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_subsection_font_color">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[$xde_form_subsection_font/@color=@id]"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_subsection_font_color"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_header_font" select="$xde_forms_fonts/xde:font['header'=@id]"/>
<xsl:variable name="xde_form_header_font_face">
    <xsl:variable name="select" select="$xde_form_header_font/@face"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_header_font_face"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_header_font_size">
    <xsl:variable name="select" select="$xde_form_header_font/@size"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_header_font_size"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_header_font_color">
    <xsl:variable name="select" select="$xde_forms_colors/xde:color[$xde_form_header_font/@color=@id]"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_header_font_color"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<!--========================================================================-->
<!-- sizes                                                                  -->
<!--========================================================================-->
<xsl:variable name="xde_form_section_separator_height">
    <xsl:variable name="select" select="/xde:config/xde:folders/xde:forms/xde:form-section-separators/@height"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_section_separator_height"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_separator_section_height">
    <xsl:variable name="select" select="/xde:config/xde:folders/xde:forms/xde:form-separator-sections/@height"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_separator_section_height"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:variable name="xde_form_input_size">
    <xsl:variable name="select" select="/xde:config/xde:folders/xde:forms/xde:input/@size"/>
    <xsl:choose>
        <xsl:when test="'' != $select">
            <xsl:value-of select="$select"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xde_form_input_size"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

</xsl:transform>
