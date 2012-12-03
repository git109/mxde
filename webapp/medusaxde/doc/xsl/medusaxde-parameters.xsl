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
<!--   File: medusaxde-parameters.xsl                                       -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="border" select="'0'"/>
<xsl:param name="frame_border" select="'0'"/>
    
<xsl:param name="for" select="''"/>
<xsl:param name="using" select="''"/>
<xsl:param name="form" select="'1'"/>
    
<xsl:param name="frame" select="''"/>
<xsl:param name="tab" select="''"/>
<xsl:param name="menu" select="''"/>
<xsl:param name="section" select="''"/>
<xsl:param name="item" select="''"/>
<xsl:param name="folder" select="''"/>

<xsl:param name="default_document_path" select="''"/>
<xsl:param name="form_document_path" select="$default_document_path"/>
<xsl:param name="document_path">
    <xsl:choose>
        <xsl:when test="'' != $form_document_path">
            <xsl:value-of select="$form_document_path"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_document_path"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<xsl:param name="default_template_path" select="''"/>
<xsl:param name="form_template_path" select="$default_template_path"/>
<xsl:param name="template_path">
    <xsl:choose>
        <xsl:when test="'' != $form_template_path">
            <xsl:value-of select="$form_template_path"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_template_path"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<xsl:param name="default_xml_document" select="'medusaxde.xml'"/>
<xsl:param name="form_xml_document" select="$default_xml_document"/>
<xsl:param name="xml_document">
    <xsl:choose>
        <xsl:when test="'' != $form_xml_document">
            <xsl:value-of select="$form_xml_document"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_xml_document"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<xsl:param name="default_author" select="''"/>
<xsl:param name="form_author" select="$default_author"/>
<xsl:param name="author">
    <xsl:variable name="select" select="/*/mxde:for/mxde:for-which"/>
    <xsl:variable name="select_for" select="$select[($for = @for)]/mxde:author"/>
    <xsl:variable name="select_default" select="$select[('' = @for)]/mxde:author"/>
    <xsl:choose>
        <xsl:when test="'' != $form_author">
            <xsl:value-of select="$form_author"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="$select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_author"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
  
<xsl:param name="default_organization" select="''"/>
<xsl:param name="form_organization" select="$default_organization"/>
<xsl:param name="organization">
    <xsl:variable name="select" select="/*/mxde:for/mxde:for-which"/>
    <xsl:variable name="select_for" select="$select[($for = @for)]/mxde:organization"/>
    <xsl:variable name="select_default" select="$select[('' = @for)]/mxde:organization"/>
    <xsl:choose>
        <xsl:when test="'' != $form_organization">
            <xsl:value-of select="$form_organization"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="$select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_organization"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
  
<xsl:param name="default_copyright" select="'yes'"/>
<xsl:param name="form_copyright" select="''"/>
<xsl:param name="copyright">
    <xsl:variable name="select" select="/*/mxde:for/mxde:for-which"/>
    <xsl:variable name="select_for" select="$select[($for = @for)]/mxde:copyright"/>
    <xsl:variable name="select_default" select="$select[('' = @for)]/mxde:copyright"/>
    <xsl:choose>
        <xsl:when test="'' != $form_copyright">
            <xsl:value-of select="$form_copyright"/>
        </xsl:when>
        <xsl:when test="($select_for) and ('' != $select_for)">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="($select_default) and ('' != $select_default)">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_copyright"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
  
<xsl:param name="default_open_source" select="'yes'"/>
<xsl:param name="form_open_source" select="''"/>
<xsl:param name="open_source">
    <xsl:variable name="select" select="/*/mxde:for/mxde:for-which"/>
    <xsl:variable name="select_for" select="$select[($for = @for)]/mxde:open_source"/>
    <xsl:variable name="select_default" select="$select[('' = @for)]/mxde:open_source"/>
    <xsl:choose>
        <xsl:when test="'' != $form_open_source">
            <xsl:value-of select="$form_open_source"/>
        </xsl:when>
        <xsl:when test="($select_for) and ('' != $select_for)">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="($select_default) and ('' != $select_default)">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_open_source"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
  
<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="query_document">
    <xsl:value-of select="'?document_file='"/>
    <xsl:value-of select="$xml_document"/>
</xsl:variable>

<xsl:variable name="and_border">
    <xsl:if test="'' != $author">
        <xsl:value-of select="'&amp;author='"/>
        <xsl:value-of select="$author"/>
    </xsl:if>
    <xsl:if test="'' != $for">
        <xsl:value-of select="'&amp;for='"/>
        <xsl:value-of select="$for"/>
    </xsl:if>
    <xsl:if test="'' != $using">
        <xsl:value-of select="'&amp;using='"/>
        <xsl:value-of select="$using"/>
    </xsl:if>
    <xsl:if test="'' != $border">
        <xsl:value-of select="'&amp;border='"/>
        <xsl:value-of select="$border"/>
    </xsl:if>
</xsl:variable>

<xsl:variable name="and_menu">
    <xsl:if test="'' != $tab">
        <xsl:value-of select="'&amp;tab='"/>
        <xsl:value-of select="$tab"/>
    </xsl:if>
    <xsl:if test="'' != $menu">
        <xsl:value-of select="'&amp;menu='"/>
        <xsl:value-of select="$menu"/>
    </xsl:if>
    <xsl:if test="'' != $section">
        <xsl:value-of select="'&amp;section='"/>
        <xsl:value-of select="$section"/>
    </xsl:if>
    <xsl:if test="'' != $item">
        <xsl:value-of select="'&amp;item='"/>
        <xsl:value-of select="$item"/>
    </xsl:if>
</xsl:variable>

<xsl:variable name="and_author">
    <xsl:if test="'' != $author">
        <xsl:value-of select="'&amp;author='"/>
        <xsl:value-of select="$author"/>
    </xsl:if>
</xsl:variable>

<xsl:variable name="and_for">
    <xsl:if test="'' != $for">
        <xsl:value-of select="'&amp;for='"/>
        <xsl:value-of select="$for"/>
    </xsl:if>
</xsl:variable>

<xsl:variable name="and_using">
    <xsl:if test="'' != $using">
        <xsl:value-of select="'&amp;using='"/>
        <xsl:value-of select="$using"/>
    </xsl:if>
</xsl:variable>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="current_date_host" select="'localhost'"/>
<xsl:param name="current_date_location">
    <xsl:value-of select="'http://'"/>
    <xsl:value-of select="$current_date_host"/>
    <xsl:value-of select="'/medusaxde/t/mxde-date-to-xml.t?content_type=xml'"/>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="current_date_document" select="document($current_date_location)"/>
<xsl:variable name="current_date">
    <xsl:choose>
        <xsl:when test="($current_date_document/*/@date)">
            <xsl:value-of select="$current_date_document/*/@date"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'$date$'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:variable name="current_year">
    <xsl:choose>
        <xsl:when test="($current_date_document/*/@year)">
            <xsl:value-of select="$current_date_document/*/@year"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'$year$'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
    
</xsl:transform>
