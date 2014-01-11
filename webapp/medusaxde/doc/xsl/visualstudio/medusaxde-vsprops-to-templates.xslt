<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2013 $organization$                                 -->
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
<!--   File: medusaxde-vsprops-to-templates.xslt                            -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/11/2013                                                      -->
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
<xsl:param name="content_type" select="''"/>
<xsl:param name="organization" select="'$organization$'"/>
<xsl:param name="author" select="'$author$'"/>
<xsl:param name="date" select="'$date$'"/>
<xsl:param name="file" select="'$file$'"/>

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
<!--     Date: 8/23/2011                                                    -->
<!--========================================================================-->
<xsl:template name="keyword">
    <xsl:param name="class" select="'keyword'"/>
    <xsl:param name="text" select="''"/>
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:copy-of select="$text"/>
        </xsl:when>
        <xsl:otherwise>
            <font class="{$class}">
                <xsl:copy-of select="$text"/>
            </font>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "comment"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/23/2011                                                    -->
<!--========================================================================-->
<xsl:template name="comment">
    <xsl:param name="class" select="'comment'"/>
    <xsl:param name="text" select="''"/>
    <xsl:call-template name="keyword">
        <xsl:with-param name="class" select="$class"/>
        <xsl:with-param name="text" select="$text"/>
    </xsl:call-template>
</xsl:template>
    
<!--========================================================================-->
<!--========================================================================-->
    
<!--========================================================================-->
<!-- Template: match "*" mode "html"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="html">
    <html>
        <xsl:apply-templates mode="head" select="."/>
        <xsl:apply-templates mode="body" select="."/>
    </html>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "head"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="head">
    <head>
        <style
         type="text/css">
            font.comment {color: green; font-style:italic; }
            font.commenteol {color: teal; font-style:italic; }
            font.processor {color: purple; font-weight: bolder; }
            font.keyword {color: blue; font-weight: bolder; }
            font.keywordx {color: purple; font-weight: bolder; }
            font.keywordy {color: purple; font-weight: bolder; }
            font.string {color: maroon; }
            font.char {color: red; }
        </style>
    </head>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "body"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="body">
    <body>
        <pre>
            <xsl:apply-templates mode="VisualStudioPropertySheet" select="."/>
        </pre>
    </body>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "text"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="text">
    <xsl:apply-templates mode="VisualStudioPropertySheet" select="."/>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
    
<!--========================================================================-->
<!-- Template: match "*" mode "VisualStudioPropertySheet"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/20/2011                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="VisualStudioPropertySheet">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "VisualStudioPropertySheet"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/20/2011                                                   -->
<!--========================================================================-->
<xsl:template match="VisualStudioPropertySheet">
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
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
<!--     Date: 11/20/2011                                                   -->
<!--========================================================================-->
<xsl:template match="*">
<b>Unexpected document type "</b><xsl:value-of select="name()"/><b>"</b>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "file"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/11/2013                                                    -->
<!--========================================================================-->
<xsl:template name="file">
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>########################################################################
# Copyright (c) 1988-2011 </xsl:text><xsl:value-of select="$organization"/><xsl:text>
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
#   File: </xsl:text><xsl:value-of select="$file"/><xsl:text>
#
# Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
#   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
#
########################################################################
</xsl:text>
</xsl:with-param>
</xsl:call-template>
</xsl:template>

</xsl:transform>
