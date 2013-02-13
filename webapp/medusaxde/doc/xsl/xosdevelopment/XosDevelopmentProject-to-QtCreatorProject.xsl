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
<!--   File: XosDevelopmentProject-to-QtCreatorProject.xsl                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 4/30/2012                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xdep="Xos-Development-Environment-Project"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde mxde medusade msxsl"
 version="1.0">

<!--========================================================================-->
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="project-type" select="'QtCreator'"/>

<xsl:param name="project">
    <xsl:choose>
        <xsl:when test="/*/@name">
            <xsl:value-of select="/*/@name"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
<xsl:param name="target">
    <xsl:choose>
        <xsl:when test="/*/@target">
            <xsl:value-of select="/*/@target"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
<xsl:param name="target-type">
    <xsl:choose>
        <xsl:when test="/*/@target-type">
            <xsl:value-of select="/*/@target-type"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
<xsl:param name="source-type">
    <xsl:choose>
        <xsl:when test="/*/@source-type">
            <xsl:value-of select="/*/@source-type"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
<xsl:param name="template">
    <xsl:choose>
        <xsl:when test="('executable' = $target-type)">
            <xsl:value-of select="'app'"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'lib'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
<xsl:param name="config">
    <xsl:choose>
        <xsl:when test="('static-library' = $target-type)">
            <xsl:value-of select="'staticLib'"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="content_type" select="'html'"/>

<xsl:param name="file">
<xsl:value-of select="$project"/>
<xsl:value-of select="'.pro'"/>
</xsl:param>
<xsl:param name="organization" select="'$organization'"/>
<xsl:param name="author" select="'$author'"/>
<xsl:param name="date" select="'$date'"/>
<xsl:param name="year" select="'$year'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "keyword"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/1/2012                                                     -->
<!--========================================================================-->
<xsl:template name="keyword">
    <xsl:param name="text" select="''"/>
    <xsl:param name="type" select="'keyword'"/>
    <xsl:choose>
        <xsl:when test="(('text' = $content_type) or ('text/plain' = $content_type))">
            <xsl:copy-of select="$text"/>
        </xsl:when>
        <xsl:otherwise>
            <font class="{$type}">
                <xsl:copy-of select="$text"/>
            </font>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "xdep:project" mode "text"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/1/2012                                                     -->
<!--========================================================================-->
<xsl:template match="xdep:project" mode="text">

<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'comment'"/>
<xsl:with-param name="text">########################################################################
# Copyright (c) 1988-<xsl:value-of select="$year"/><xsl:text> </xsl:text>
<xsl:value-of select="$organization"/>
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: <xsl:value-of select="$file"/>
#
# Author: <xsl:value-of select="$author"/>
#   Date: <xsl:value-of select="$date"/>
########################################################################
</xsl:with-param>
</xsl:call-template>

<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">TARGET</xsl:with-param>
</xsl:call-template>
<xsl:text> = </xsl:text>
<xsl:value-of select="$target"/>

<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">

TEMPLATE</xsl:with-param>
</xsl:call-template>
<xsl:text> = </xsl:text>
<xsl:value-of select="$template"/>

<xsl:if test="('' != $config)">
<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">

CONFIG</xsl:with-param>
</xsl:call-template>
<xsl:text> += </xsl:text>
<xsl:value-of select="$config"/>
</xsl:if>

<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">

INCLUDEPATH</xsl:with-param>
</xsl:call-template>
<xsl:text> += \
</xsl:text>
<xsl:for-each select="xdep:include-paths">
<xsl:for-each select="xdep:paths">
<xsl:for-each select="xdep:path">
<xsl:if test="('' != .)">
<xsl:value-of select="."/><xsl:text> \
</xsl:text>
</xsl:if>
</xsl:for-each>
</xsl:for-each>
</xsl:for-each>

<xsl:text>
</xsl:text>
<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">DEFINES</xsl:with-param>
</xsl:call-template>
<xsl:text> += \
</xsl:text>

<xsl:text>
</xsl:text>
<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">SOURCES</xsl:with-param>
</xsl:call-template>
<xsl:text> += \
</xsl:text>
<xsl:for-each select="xdep:sources">
<xsl:for-each select="xdep:files">
<xsl:for-each select="xdep:file">
<xsl:if test="('' != .)">
<xsl:if test="(@path and ('' != @path))">
<xsl:value-of select="@path"/><xsl:text>/</xsl:text>
</xsl:if>
<xsl:value-of select="."/><xsl:text> \
</xsl:text>
</xsl:if>
</xsl:for-each>
</xsl:for-each>
</xsl:for-each>

<xsl:text>
</xsl:text>
<xsl:call-template name="keyword">
<xsl:with-param name="type" select="'keyword'"/>
<xsl:with-param name="text">LIBS</xsl:with-param>
</xsl:call-template>
<xsl:text> += \
</xsl:text>
<xsl:for-each select="xdep:library-paths">
<xsl:for-each select="xdep:paths">
<xsl:for-each select="xdep:path">
<xsl:if test="('' != .)">
<xsl:text></xsl:text>-Xlinker -R<xsl:value-of select="."/><xsl:text> \
</xsl:text>
<xsl:text></xsl:text>-L<xsl:value-of select="."/><xsl:text> \
</xsl:text>
</xsl:if>
</xsl:for-each>
</xsl:for-each>
</xsl:for-each>
<xsl:for-each select="xdep:libraries">
<xsl:for-each select="xdep:libraries">
<xsl:for-each select="xdep:library">
<xsl:if test="('' != .)">
<xsl:text></xsl:text>-l<xsl:value-of select="."/><xsl:text> \
</xsl:text>
</xsl:if>
</xsl:for-each>
</xsl:for-each>
</xsl:for-each>

</xsl:template>

<!--========================================================================-->
<!-- Template: match "*" mode "text"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/1/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="text">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "xdep:project" mode "html"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/1/2012                                                     -->
<!--========================================================================-->
<xsl:template match="xdep:project" mode="html">
<html>
    <head>
        <style type="text/css">
            font.text {color: black; font-style: normal; font-weight: normal; }
            font.string {color: red; font-style: italic; font-weight: normal; }
            font.processor {color: purple; font-style: italic; font-weight: bold; }
            font.comment {color: green; font-style: italic; font-weight: normal; }
            font.define {color: magenta; font-style: normal; font-weight: normal; }
            font.include {color: maroon; font-style: normal; font-weight: normal; }
            font.keywordx {color: teal; font-weight: normal; font-weight: bold; }
            font.keyword {color: blue; font-weight: normal; font-weight: bold; }
        </style>
        <script>
        </script>
    </head>
    <body>
        <pre>
            <xsl:apply-templates mode="text" select="."/>
        </pre>
    </body>
</html>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*" mode "html"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 5/1/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="html">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "xdep:project"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/30/2012                                                    -->
<!--========================================================================-->
<xsl:template match="xdep:project">
<xsl:choose>
    <xsl:when test="(('text' = $content_type) or ('text/plain' = $content_type))">
        <xsl:apply-templates mode="text" select="."/>
    </xsl:when>
    <xsl:otherwise>
        <xsl:apply-templates mode="html" select="."/>
    </xsl:otherwise>
</xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/30/2012                                                    -->
<!--========================================================================-->
<xsl:template match="*">
<b>Unexpected document type "</b><xsl:value-of select="name()"/><b>"</b>
</xsl:template>
</xsl:transform>

