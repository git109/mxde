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
<!--   File: medusaxde-footer.xsl                                           -->
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
<!-- Template: "footer"                                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/3/2009                                                     -->
<!--========================================================================-->
<xsl:template name="footer">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="menus" select="xde:menus"/>
    <xsl:param name="footer" select="xde:footer"/>
    <xsl:param name="footer_width" select="$footer/xde:size/@width"/>
    <xsl:param name="footer_bgcolor" select="$footer/xde:color/@bgcolor"/>
    <xsl:param name="footer_font" select="$footer/xde:fonts/xde:font['off' = @hover]"/>
    <xsl:param name="footer_item" select="$footer/xde:footer-item"/>

    <xsl:variable name="menu_sections" select="$menus/xde:menu-sections"/>
    <xsl:variable name="section_bgcolor" select="$menu_sections/xde:color[((@for = $for) or (not (@for)))]/@bgcolor"/>
    <xsl:variable name="menu_items" select="$menus/xde:menu-items"/>
    <xsl:variable name="menu_item_images" select="$menu_items/xde:images[(((@for) and (@for = $for)) or (not (@for)))]/xde:image"/>
    <xsl:variable name="menu_item_left_image" select="$menu_item_images['left' = @id]"/>
    <xsl:variable name="separator_thickness" select="$menu_item_left_image/@width"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
	<table 
	 border="{$border}"
     bgcolor="{$footer_bgcolor}"
	 width="100%" height="100%"
	 cellspacing="0" cellpadding="0">
        <!--========================================================================-->
		<tr><td>
	        <table 
	         border="{$border}"
             bgcolor="{$footer_bgcolor}"
	         height="100%"
	         cellspacing="0" cellpadding="0">
                <!--========================================================================-->
                <tr>
		            <xsl:for-each select="$footer_item">
                        <xsl:variable name="is_separator_footer">
                            <xsl:if test="(('yes' = @is_separator_footer) or ('yes' = @is_separator))">
                                <xsl:text>yes</xsl:text>
                            </xsl:if>
                        </xsl:variable>
                        
                        <xsl:choose>
                            <xsl:when test="('yes' = $is_separator_footer)">
                                <td nowrap="yes" width="{$separator_thickness}" bgcolor="{$section_bgcolor}"></td>
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:variable name="footer_location">
                                    <xsl:apply-templates select="." mode="folder_location">
                                        <xsl:with-param name="is_location_query_and_for" select="'yes'"/>
                                        <xsl:with-param name="is_location_query_and_using" select="'yes'"/>
                                    </xsl:apply-templates>
                                </xsl:variable>

                                <td class="footer" width="{$footer_width}" align="middle">
				                    <a class="footer"
                                     onclick="return onClickFooter('{$footer_location}')"
				                     href="{$footer_location}">
					                    <font
					                     face="{$footer_font/@face}"
					                     size="{$footer_font/@size}">
                                            <nobr><b><xsl:value-of select="xde:text"/></b></nobr>
					                    </font>
				                    </a>
			                    </td>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
		        </tr>
                <!--========================================================================-->
            </table>
		</td></tr>
        <!--========================================================================-->
	</table>
</xsl:template>

</xsl:transform>
