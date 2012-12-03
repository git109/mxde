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
<!--   File: medusaxde-header.xsl                                           -->
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

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "heading"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/3/2009                                                     -->
<!--========================================================================-->
<xsl:template name="heading">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="fonts" select="xde:header/xde:fonts[((@for = $for) or (not (@for)))]"/>
    <xsl:param name="font" select="$fonts/xde:font[@id = 'text']"/>
    <xsl:param name="for_font" select="$fonts/xde:font[@id = 'for']"/>
    <xsl:param name="what_font" select="$fonts/xde:font[@id = 'what']"/>
    <xsl:param name="text" select="xde:header/xde:text[((@for = $for) or (not (@for)))]"/>
    <xsl:param name="for_text">
        <xsl:apply-templates mode="for_text" select="xde:header"/>
    </xsl:param>
    <xsl:param name="using_text">
        <xsl:apply-templates mode="using_text" select="xde:header"/>
    </xsl:param>
    <xsl:param name="for_align">
        <xsl:choose>
            <xsl:when test="'' != $using_text">
                <xsl:value-of select="'right'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="'left'"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <table
     border="{$border}"
     width="100%" height="100%"
     cellspacing="0" cellpadding="0">
        <tr>
            <td valign="top" align="left" nowrap="yes">
                <font
                 face="{$font/@face}"
                 size="{$font/@size}"
                 color="{$font/@color}">
                    <b><xsl:value-of select="$text"/></b>
                </font>
            </td>
            <xsl:if test="('' != $for_text) or ('' != $using_text)">
                <td valign="top" align="right" nowrap="yes">
                <xsl:if test="'' != $for_text">
                    <font
                     face="{$for_font/@face}"
                     size="{$for_font/@size}"
                     color="{$for_font/@color}">
                        <b><xsl:value-of select="' for '"/></b>
                    </font>
                    <font
                     face="{$what_font/@face}"
                     size="{$what_font/@size}"
                     color="{$what_font/@color}">
                        <b><xsl:value-of select="$for_text"/></b>
                    </font>
                </xsl:if>
                <xsl:if test="'' != $using_text">
                    <font
                     face="{$for_font/@face}"
                     size="{$for_font/@size}"
                     color="{$for_font/@color}">
                        <b><xsl:value-of select="' using '"/></b>
                    </font>
                    <font
                     face="{$what_font/@face}"
                     size="{$what_font/@size}"
                     color="{$what_font/@color}">
                        <b><xsl:value-of select="$using_text"/></b>
                    </font>
                </xsl:if>
                </td>
            </xsl:if>
        </tr>
    </table>
</xsl:template>

<!--========================================================================-->
<!-- Template: "header"                                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/3/2009                                                     -->
<!--========================================================================-->
<xsl:template name="header">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="height" select="xde:header/xde:size/@height"/>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <table
     border="{$border}"
     width="100%" height="{$height}"
     cellspacing="0" cellpadding="0">
        <tr><td valign="top">
            <xsl:call-template name="heading"/>
        </td></tr>
        <tr><td valign="bottom">
            <xsl:call-template name="tabs"/>
        </td></tr>
    </table>
</xsl:template>

</xsl:transform>
