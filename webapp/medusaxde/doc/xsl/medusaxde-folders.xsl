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
<!--   File: medusaxde-folders.xsl                                          -->
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

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "folder_text"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/10/2009                                                    -->
<!--========================================================================-->
<xsl:template name="folder_text">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="text_valign" select="'center'"/>

    <xsl:param name="folder_fonts" select="xde:folders/xde:fonts"/>
    <xsl:param name="brand_font" select="$folder_fonts/xde:font[@id = 'brand']"/>
    <xsl:param name="product_font" select="$folder_fonts/xde:font[@id = 'product']"/>
    <xsl:param name="version_font" select="$folder_fonts/xde:font[@id = 'version']"/>
    <xsl:param name="for_font" select="$folder_fonts/xde:font[@id = 'for']"/>
    <xsl:param name="what_font" select="$folder_fonts/xde:font[@id = 'what']"/>

    <xsl:param name="folder_text" select="xde:folders/xde:text"/>
    <xsl:param name="brand" select="$folder_text/xde:brand"/>
    <xsl:param name="product" select="$folder_text/xde:product"/>
    <xsl:param name="version" select="$folder_text/xde:version"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->
    <xsl:variable name="for_which" select="/*/mxde:for/mxde:for-which[(@for = $for)]"/>
    <xsl:variable name="for_what_tree">
        <mxde:what href="{$for_which/@href}" target="{$for_which/@target}">
            <mxde:text><xsl:apply-templates mode="for_text" select="$folder_text"/></mxde:text>
        </mxde:what>
    </xsl:variable>
    <xsl:variable name="for_what" select="exsl:node-set($for_what_tree)"/>

    <xsl:variable name="using_which" select="/*/mxde:using/mxde:using-which[(@using = $using)]"/>
    <xsl:variable name="using_what_tree">
        <mxde:what href="{$using_which/@href}" target="{$using_which/@target}">
            <mxde:text><xsl:apply-templates mode="using_text" select="$folder_text"/></mxde:text>
        </mxde:what>
    </xsl:variable>
    <xsl:variable name="using_what" select="exsl:node-set($using_what_tree)"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr><td align="center" valign="{$text_valign}" nowrap="yes">
        <font 
         face="{$brand_font/@face}" 
         size="{$brand_font/@size}" 
         color="{$brand_font/@color}">
            <xsl:apply-templates mode="folder_text" select="$brand"/>
        </font>
        <font 
         face="{$product_font/@face}" 
         size="{$product_font/@size}" 
         color="{$product_font/@color}">
            <b><xsl:value-of select="$product"/></b><br/>
        </font>
        <font 
         face="{$version_font/@face}" 
         size="{$version_font/@size}" 
         color="{$version_font/@color}">
            <b><xsl:value-of select="$version"/></b><br/>
        </font>
        <xsl:if test="('' != $for) and ('' != $for_what)">
            <font 
             face="{$for_font/@face}" 
             size="{$for_font/@size}" 
             color="{$for_font/@color}">
                <br/><b><xsl:value-of select="'for'"/></b><br/>
            </font>
            <font 
             face="{$what_font/@face}" 
             size="{$what_font/@size}" 
             color="{$what_font/@color}">
                <xsl:apply-templates mode="folder_text" select="$for_what"/>
            </font>
        </xsl:if>
        <xsl:if test="('' != $using) and ('' != $using_what)">
            <font 
             face="{$for_font/@face}" 
             size="{$for_font/@size}" 
             color="{$for_font/@color}">
                <br/><b><xsl:value-of select="'using'"/></b><br/>
            </font>
            <font 
             face="{$what_font/@face}" 
             size="{$what_font/@size}" 
             color="{$what_font/@color}">
                <xsl:apply-templates mode="folder_text" select="$using_what"/>
            </font>
        </xsl:if>
    </td></tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "folder"                                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/3/2009                                                     -->
<!--========================================================================-->
<xsl:template name="folder">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="folder_images" select="mxde:folders/mxde:images"/>
    <xsl:param name="background_images" select="$folder_images/mxde:image[(@id = 'background')]"/>
    <xsl:param name="background_for" select="$background_images[($for = @for)]"/>
    <xsl:param name="background_using" select="$background_images[($using = @using)]"/>
    <xsl:param name="background_for_count" select="count($background_for)"/>
    <xsl:param name="background_using_count" select="count($background_using)"/>
    <xsl:param name="background_count" select="($background_for_count + $background_using_count)"/>
    <xsl:param name="xbackground_count" select="count($background_images[(((not(@for) and ('' != $using)) or (@for = $for)) and ((not(@using) and ('' != for)) or (@using = $using)))])"/>
    <xsl:param name="xbackground" select="$background_images[((0 = $background_count) and not(@for) and not(@using)) or (((not(@for) and ('' != $using)) or (@for = $for)) and ((not(@using) and ('' != for)) or (@using = $using)))]"/>
    <xsl:param name="background" select="$background_images[((0 = $background_count) and not(@for) and not(@using)) or ((($for = @for) or (not(@for) and @using)) and (($using = @using) or (not(@using) and @for)))]"/>

    <!--========================================================================-->
    <!-- Variables                                                              -->
    <!--========================================================================-->
    <xsl:variable name="text_valign">
        <xsl:choose>
            <xsl:when test="('' != $background/@text_valign)">
                <xsl:value-of select="$background/@text_valign"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>center</xsl:text>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <table class="folder" 
     border="{$border}"
	 width="100%" height="100%"
     background="{$background/@location}"
	 cellspacing="0" cellpadding="0">
        <!--========================================================================-->
        <xsl:choose>
            <xsl:when test="('top' = $text_valign) or ('bottom' = $text_valign) or ('center' = $text_valign)">
                <xsl:call-template name="folder_text">
                    <xsl:with-param name="text_valign" select="$text_valign"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <xsl:variable name="valign">
                    <xsl:choose>
                        <xsl:when test="('bottom_top' = $text_valign)">
                            <xsl:text>top</xsl:text>
                        </xsl:when>
                        <xsl:when test="('top_bottom' = $text_valign)">
                            <xsl:text>bottom</xsl:text>
                        </xsl:when>
                        <xsl:when test="('top_center' = $text_valign) or ('bottom_center' = $text_valign)">
                            <xsl:text>center</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:variable>

                <xsl:if test="('bottom_top' = $text_valign) or ('bottom_center' = $text_valign)">
                    <tr><td height="50%"></td></tr>
                </xsl:if>
                <xsl:call-template name="folder_text">
                    <xsl:with-param name="text_valign" select="$valign"/>
                </xsl:call-template>
                <xsl:if test="('top_bottom' = $text_valign) or ('top_center' = $text_valign)">
                    <tr><td height="50%"></td></tr>
                </xsl:if>
            </xsl:otherwise>
        </xsl:choose>
        <!--========================================================================-->
    </table>
</xsl:template>
    
</xsl:transform>
