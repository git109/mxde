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
<!--   File: medusaxde-xsl-form-parameters.xsl                              -->
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
<xsl:variable name="xsl_param_expr_types_tree">
    <type default="yes" value="">&gt;</type>
    <type value="select">select</type>
    <type value="if">&lt;xsl:if test</type>
    <type value="choose">&lt;xsl:choose when</type>
</xsl:variable>
<xsl:variable name="xsl_param_expr_types" 
 select="exsl:node-set($xsl_param_expr_types_tree)"/>

<xsl:variable name="xsl_nodeset_types_tree">
    <type default="yes">exsl:node-set</type>
    <type>xalan:nodeset</type>
</xsl:variable>
<xsl:variable name="xsl_nodeset_types"
 select="exsl:node-set($xsl_nodeset_types_tree)"/>
    
<xsl:variable name="xsl_versions_tree">
    <version default="yes" value="1.0">1.0</version>
    <version value="2.0">2.0</version>
</xsl:variable>
<xsl:variable name="xsl_versions" 
 select="exsl:node-set($xsl_versions_tree)"/>
    
<xsl:variable name="xsl_output_methods_tree">
    <method value="html">html</method>
    <method value="xml">xml</method>
    <method value="text">text</method>
    <method default="yes" value="no">none</method>
</xsl:variable>
<xsl:variable name="xsl_output_methods" 
 select="exsl:node-set($xsl_output_methods_tree)"/>
    
<xsl:param name="xsl_standard_includes_tree">
    <include></include>
    <include>../mxde-parameters.xsl</include>
    <include>../mxde-template.xsl</include>
    <include>../mxde-form-parameters.xsl</include>
    <include>../mxde-form-template.xsl</include>
</xsl:param>
<xsl:param name="xsl_standard_includes"
 select="exsl:node-set($xsl_standard_includes_tree)"/>
    
<xsl:param name="xsl_template_types_tree">
    <type>match</type>
    <type>name</type>
    <type default="yes">no</type>
</xsl:param>
<xsl:param name="xsl_template_types"
 select="exsl:node-set($xsl_template_types_tree)"/>

<xsl:param name="xsl_is_stylesheet_options_tree">
    <option value="yes">stylesheet</option>
    <option value="no" default="yes">transform</option>
</xsl:param>
<xsl:param name="xsl_is_stylesheet_options"
 select="exsl:node-set($xsl_is_stylesheet_options_tree)"/>

</xsl:transform>
