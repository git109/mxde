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
<!--   File: medusaxde-vsprops-to-props.xslt                                -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 11/10/2012                                                     -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl exsl xalan msxsl"
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
<!-- Template: "processor"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/23/2011                                                    -->
<!--========================================================================-->
<xsl:template name="processor">
    <xsl:param name="class" select="'processor'"/>
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

<xsl:template name="lt">
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:text disable-output-escaping="yes">&lt;</xsl:text>
        </xsl:when>
        <xsl:otherwise>
            <xsl:text>&lt;</xsl:text>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
<xsl:template name="gt">
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:text disable-output-escaping="yes">&gt;</xsl:text>
        </xsl:when>
        <xsl:otherwise>
            <xsl:text>&gt;</xsl:text>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "UserMacro" mode "macros"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/10/2012                                                   -->
<!--========================================================================-->
<xsl:template match="UserMacro" mode="macros">
<xsl:text>    </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text"><xsl:value-of select="@Name"/></xsl:with-param></xsl:call-template><xsl:call-template name="gt"/>
<xsl:value-of select="@Value"/>
<xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">/<xsl:value-of select="@Name"/></xsl:with-param></xsl:call-template><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
</xsl:template>
  
<!--========================================================================-->
<!-- Template: match "UserMacro" mode "includes"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/10/2012                                                   -->
<!--========================================================================-->
<xsl:template match="UserMacro" mode="includes">
<xsl:text>    </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">BuildMacro</xsl:with-param></xsl:call-template><xsl:text> Include="</xsl:text>
<xsl:value-of select="@Name"/><xsl:text>"</xsl:text><xsl:call-template name="gt"/><xsl:text>
      </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">Value</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>$(</xsl:text>
<xsl:value-of select="@Name"/>
<xsl:text>)</xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">/Value</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>
    </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">/BuildMacro</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
</xsl:template>
  
<!--========================================================================-->
<!-- Template: match "VisualStudioPropertySheet" mode "VisualStudioPropertySheet"-->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/11/2012                                                   -->
<!--========================================================================-->
<xsl:template match="VisualStudioPropertySheet" mode="VisualStudioPropertySheet">
<xsl:call-template name="processor">
<xsl:with-param name="text">
<xsl:call-template name="lt"/><xsl:text>?xml version="1.0" encoding="utf-8"?</xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:call-template name="lt"/><xsl:text>!-- File: </xsl:text><xsl:value-of select="$file"/><xsl:text> --</xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">Project</xsl:with-param></xsl:call-template><xsl:text> ToolsVersion="</xsl:text><xsl:value-of select="'4.0'"/>
<xsl:text>" xmlns="</xsl:text>
<xsl:value-of select="'http://schemas.microsoft.com/developer/msbuild/2003'"/>
<xsl:text>"</xsl:text><xsl:call-template name="gt"/><xsl:text>
  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">ImportGroup</xsl:with-param></xsl:call-template><xsl:text> Label="PropertySheets" /</xsl:text><xsl:call-template name="gt"/><xsl:text>
  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">PropertyGroup</xsl:with-param></xsl:call-template><xsl:text> Label="UserMacros"</xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
<xsl:apply-templates mode="macros" select="./*"/>
<xsl:text>  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">/PropertyGroup</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>
  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">PropertyGroup</xsl:with-param></xsl:call-template><xsl:text> /</xsl:text><xsl:call-template name="gt"/><xsl:text>
  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">ItemDefinitionGroup</xsl:with-param></xsl:call-template><xsl:text> /</xsl:text><xsl:call-template name="gt"/><xsl:text>
  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">ItemGroup</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
<xsl:apply-templates mode="includes" select="./*"/>
<xsl:text>  </xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">/ItemGroup</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text><xsl:call-template name="lt"/><xsl:call-template name="keyword">
<xsl:with-param name="text">/Project</xsl:with-param></xsl:call-template><xsl:text></xsl:text><xsl:call-template name="gt"/><xsl:text>
</xsl:text>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "VisualStudioPropertySheet"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/10/2012                                                   -->
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
<!--     Date: 11/10/2012                                                   -->
<!--========================================================================-->
<xsl:template match="*">Unexpected document type "<xsl:value-of select="name()"/>"
</xsl:template>
</xsl:transform>
