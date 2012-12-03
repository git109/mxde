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
<!--   File: medusaxde-tabs.xsl                                             -->
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
<!-- Template: "tabs"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/3/2009                                                     -->
<!--========================================================================-->
<xsl:template name="tabs">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="menu_width" select="xde:menus/xde:size/@width"/>
    <xsl:param name="tab_bgcolor" select="xde:tabs/xde:color/@bgcolor"/>
    <xsl:param name="tab_font" select="xde:tabs/xde:fonts/xde:font['off' = @hover]"/>
    <xsl:param name="tab_image" select="xde:tabs/xde:images/xde:image"/>
    <xsl:param name="tab_width" select="xde:tabs/xde:size/@width"/>
    <xsl:param name="tab_height" select="xde:tabs/xde:size/@height"/>
    <xsl:param name="tab_tab" select="xde:tabs/xde:tab"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <table
     border="{$border}"
     bgcolor="{$tab_bgcolor}"
     width="100%" height="{$tab_height}"
     cellspacing="0" cellpadding="0">
        <!--========================================================================-->
        <tr><td height="{$tab_height}">
            <table
             border="{$border}"
             height="100%"
             cellspacing="0" cellpadding="0">
                <tr>
                    <td nowrap="yes" width="{$menu_width}">
                    </td>
                    <xsl:for-each select="$tab_tab">
                    <xsl:if test="(@id and ('' != @id))">
                    <xsl:if test="((('' != @for) and (@for = $for)) or (not ('' != @for)) or (('yes' = @or_not_for) and ('' = $for)))">
                    <xsl:if test="((('' != @using) and (@using = $using)) or (not ('' != @using)) or (('yes' = @or_not_using) and ('' = $using)))">
                        <xsl:variable name="state">
                            <xsl:choose>
                                <xsl:when test="(@id = $tab) or (('' = $tab) and ('yes' = @default))">
                                    <xsl:value-of select="'top'"/>
                                </xsl:when>
                                <xsl:otherwise>
                                    <xsl:value-of select="'bottom'"/>
                                </xsl:otherwise>
                            </xsl:choose>
                        </xsl:variable>
                        <xsl:variable name="image" select="$tab_image[@state = $state]/@location"/>
                        <xsl:variable name="text" select="xde:text"/>
                        <xsl:variable name="menu_location">
                            <xsl:value-of select="'?frame=menu'"/>
                            <xsl:value-of select="'&amp;tab='"/>
                            <xsl:value-of select="@id"/>
                            <xsl:value-of select="'&amp;menu='"/>
                            <xsl:value-of select="@menu"/>
                            <xsl:value-of select="$and_border"/>
                        </xsl:variable>
                        <xsl:variable name="tab_location">
                            <xsl:value-of select="'?frame=header'"/>
                            <xsl:value-of select="'&amp;tab='"/>
                            <xsl:value-of select="@id"/>
                            <xsl:value-of select="$and_border"/>
                        </xsl:variable>

                        <td
                         id="tab{position()}"
                         align="center"
                         nowrap="yes"
                         width="{$tab_width}"
                         background="{$image}">
                            <a class="tab"
                             onclick="return onClickTab('{$menu_location}')"
                             href="{$tab_location}">
                                <font
                                 face="{$tab_font/@face}"
                                 size="{$tab_font/@size}">
                                    <b><xsl:value-of select="$text"/></b>
                                </font>
                            </a>
                        </td>
                    </xsl:if>
                    </xsl:if>
                    </xsl:if>
                    </xsl:for-each>
                </tr>
            </table>
        </td></tr>
        <!--========================================================================-->
    </table>
</xsl:template>
    
</xsl:transform>
