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
<!--   File: medusaxde-menus.xsl                                            -->
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
<!-- Template: "menu_item"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/9/2009                                                     -->
<!--========================================================================-->
<xsl:template name="menu_item">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="menus" select="xde:menus"/>
    <xsl:param name="section_image" select="$menus/xde:menu-sections/xde:images/xde:image"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->
    <xsl:variable name="menu_bgcolor" select="$menus/xde:color/@bgcolor"/>
    <xsl:variable name="menu_width" select="$menus/xde:size/@width"/>
    <xsl:variable name="menu_height" select="$menus/xde:size/@height"/>
    <xsl:variable name="menu_sections" select="$menus/xde:menu-sections"/>
    <xsl:variable name="section_bgcolor" select="$menu_sections/xde:color[((not (@for)) or (@for = $for))]/@bgcolor"/>

    <xsl:variable name="menu_items" select="$menus/xde:menu-items"/>
    <xsl:variable name="menu_font" select="$menu_items/xde:fonts/xde:font[('off' = @hover)]"/>
    <xsl:variable name="menu_images" select="$menu_items/xde:images[((not (@for)) or (@for = $for))]/xde:image"/>
    <xsl:variable name="left_menu_image" select="$menu_images[('left' = @id)]"/>
    <xsl:variable name="left_menu_image_location">
        <xsl:apply-templates select="$left_menu_image" mode="element_location">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="left_section_image" select="$section_image[('left' = @id)]"/>

    <xsl:variable name="is_separator_item">
        <xsl:if test="(('yes' = @is_separator_item) or ('yes' = @is_separator))">
            <xsl:text>yes</xsl:text>
        </xsl:if>
    </xsl:variable>
    <xsl:variable name="is_location_query_and">
        <xsl:choose>
            <xsl:when test="('no' != @is_location_query_and)">yes</xsl:when>
            <xsl:otherwise>no</xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="is_location_query_and_border">
        <xsl:choose>
            <xsl:when test="('no' != @is_location_query_and_border)">yes</xsl:when>
            <xsl:otherwise>no</xsl:otherwise>
        </xsl:choose>
    </xsl:variable>

    <xsl:variable name="item_location">
        <xsl:value-of select="'?frame=menu'"/>
        <xsl:value-of select="'&amp;tab='"/>
        <xsl:value-of select="$tab"/>
        <xsl:value-of select="'&amp;menu='"/>
        <xsl:value-of select="$menu"/>
        <xsl:value-of select="'&amp;section='"/>
        <xsl:value-of select="$section"/>
        <xsl:value-of select="'&amp;item='"/>
        <xsl:value-of select="@id"/>
        <xsl:value-of select="$and_border"/>
    </xsl:variable>
    <xsl:variable name="folder_location">
        <xsl:apply-templates select="." mode="folder_location">
            <xsl:with-param name="is_location_query_and" select="$is_location_query_and"/>
            <xsl:with-param name="is_location_query_and_border" select="$is_location_query_and_border"/>
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="folder_location_target">
        <xsl:apply-templates select="." mode="element_location_target">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="folder_location_on_click">
        <xsl:apply-templates select="." mode="folder_location_on_click">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="on_click">
        <xsl:text>return </xsl:text>
        <xsl:value-of select="$folder_location_on_click"/>
        <xsl:text>('</xsl:text>
        <xsl:value-of select="$folder_location"/>
        <xsl:text>')</xsl:text>
    </xsl:variable>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <!--========================================================================-->
        <!-- separator                                                              -->
        <!--========================================================================-->
        <xsl:when test="'yes' = $is_separator_item">
            <tr><td
                 bgcolor="{$section_bgcolor}"
                 colspan="2"
                 height="{$left_menu_image/@width}">
            </td></tr>
        </xsl:when>

        <!--========================================================================-->
        <!-- item                                                                   -->
        <!--========================================================================-->
        <xsl:otherwise>
            <tr><td
             align="left" valign="top"
             width="{$left_section_image/@width}"
             height="{$left_menu_image/@height}">
                <img src="{$left_menu_image_location}"/>
            </td><td nowrap="yes">
                <xsl:choose>
                    <xsl:when test="'' != $folder_location_target">
                        <a class="item"
                         target="{$folder_location_target}"
                         href="{$folder_location}">
                            <font 
                             face="{$menu_font/@face}"
                             size="{$menu_font/@size}">
                                <nobr><b><xsl:value-of select="xde:text"/></b></nobr>
                            </font>
                        </a>
                    </xsl:when>
                    <xsl:otherwise>
                        <a class="item"
                         onclick="{$on_click}"
                         href="{$item_location}">
                            <font 
                             face="{$menu_font/@face}"
                             size="{$menu_font/@size}">
                                <nobr><b><xsl:value-of select="xde:text"/></b></nobr>
                            </font>
                        </a>
                    </xsl:otherwise>
                </xsl:choose>
            </td></tr>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "menu_section"                                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/9/2009                                                     -->
<!--========================================================================-->
<xsl:template name="menu_section">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="menus" select="xde:menus"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->
    <xsl:variable name="menu_items" select="$menus/xde:menu-items"/>
    <xsl:variable name="menu_images" select="$menu_items/xde:images/xde:image"/>
    <xsl:variable name="left_menu_image" select="$menu_images[('left' = @id)]"/>
    <xsl:variable name="menu_sections" select="$menus/xde:menu-sections"/>
    <xsl:variable name="section_images" select="$menu_sections/xde:images[((not (@for)) or (@for = $for))]/xde:image"/>
    <xsl:variable name="section_bgcolor" select="$menu_sections/xde:color[((not (@for)) or (@for = $for))]/@bgcolor"/>
    <xsl:variable name="section_font" select="$menu_sections/xde:fonts/xde:font[('off' = @hover)]"/>
    <xsl:variable name="section_spacing" select="$menu_sections/xde:size/@spacing"/>
    <xsl:variable name="state">
        <xsl:choose>
            <xsl:when test="(@id = $section)">
                <xsl:value-of select="'top'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="'bottom'"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="image_state">
        <xsl:choose>
            <xsl:when test="('yes' = @is_menu_item)">
                <xsl:value-of select="'bottom'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$state"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="section_rows" select="@rows"/>
    <xsl:variable name="row_text" select="xde:text[$section_rows = @row]"/>
    <xsl:variable name="section_image" select="$section_images[($image_state = @state) and (not($section_rows) or ($section_rows = @rows))]"/>
    <xsl:variable name="left_section_image" select="$section_image[('left' = @id)]"/>
    <xsl:variable name="left_section_image_location">
        <xsl:apply-templates select="$left_section_image" mode="element_location">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="next_section">
        <xsl:choose>
            <xsl:when test="(@id != $section)">
                <xsl:value-of select="'&amp;section='"/>
                <xsl:value-of select="@id"/>
            </xsl:when>
            <xsl:otherwise>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="section_location">
        <xsl:value-of select="'?frame=menu'"/>
        <xsl:value-of select="'&amp;tab='"/>
        <xsl:value-of select="$tab"/>
        <xsl:value-of select="'&amp;menu='"/>
        <xsl:value-of select="$menu"/>
        <xsl:value-of select="$next_section"/>
        <xsl:value-of select="$and_border"/>
    </xsl:variable>
    <xsl:variable name="folder_location_on_click">
        <xsl:apply-templates select="." mode="folder_location_on_click">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="folder_location">
        <xsl:apply-templates select="." mode="folder_location">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="folder_location_target">
        <xsl:apply-templates select="." mode="element_location_target">
        </xsl:apply-templates>
    </xsl:variable>
    <xsl:variable name="on_click">
        <xsl:choose>
            <xsl:when test="('yes' = @is_menu_item)">
                <xsl:text>return </xsl:text>
                <xsl:value-of select="$folder_location_on_click"/>
                <xsl:text>('</xsl:text>
                <xsl:value-of select="$folder_location"/>
                <xsl:text>')</xsl:text>
            </xsl:when>
            <xsl:otherwise>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(1 &lt; position())">
    <tr><td 
         colspan="2"
         height="{$section_spacing}">
    </td></tr>
    </xsl:if>
    <!--========================================================================-->
    <tr><td 
         align="left" valign="top" 
         bgcolor="{$section_bgcolor}"
         width="{$left_section_image/@width}"
         height="{$left_section_image/@height}">
        <img src="{$left_section_image_location}"/>
    </td><td nowrap="yes" bgcolor="{$section_bgcolor}">
        <a class="section" 
         onclick="{$on_click}" 
         href="{$section_location}">
            <font
             face="{$section_font/@face}"
             size="{$section_font/@size}"
             xcolor="{$section_font/@color}">
                <b><xsl:value-of select="xde:text"/></b>
                <xsl:if test="$row_text">
                    <br/><b><xsl:value-of select="$row_text"/></b>
                </xsl:if>
            </font>
        </a>
    </td></tr>
    <!--========================================================================-->
    <xsl:if test="(@id = $section) and (not ('yes' = @is_menu_item))">
        <xsl:variable name="menu_item" select="xde:menu-item"/>
        <xsl:for-each select="$menu_item">
            <xsl:if test="(not (@for)) or (((@for) and (@for = $for)) or (('yes' = @or_not_for) and ('' = $for)))">
            <xsl:if test="(not (@using)) or (((@using) and (@using = $using)) or (('yes' = @or_not_using) and ('' = $using)))">
                <xsl:call-template name="menu_item">
                    <xsl:with-param name="menus" select="$menus"/>
                    <xsl:with-param name="section_image" select="$section_image"/>
                </xsl:call-template>
            </xsl:if>
            </xsl:if>
        </xsl:for-each>
        <tr><td
             bgcolor="{$section_bgcolor}"
             colspan="2"
             height="{$left_menu_image/@width}">
        </td></tr>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "menu"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/3/2009                                                     -->
<!--========================================================================-->
<xsl:template name="menu">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="menus" select="xde:menus"/>
    <xsl:param name="menu_bgcolor" select="$menus/xde:color/@bgcolor"/>
    <xsl:param name="menu_width" select="$menus/xde:size/@width"/>
    <xsl:param name="menu_height" select="$menus/xde:size/@height"/>
    <xsl:param name="menu_font" select="$menus/xde:fonts/xde:font[('off' = @hover)]"/>
    <xsl:param name="tab_default" select="xde:tabs/xde:tab[('yes' = @default)]"/>
    <xsl:param name="tab">
        <xsl:choose>
            <xsl:when test="('' = $tab)">
                <xsl:value-of select="$tab_default/@id"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$tab"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="menu">
        <xsl:choose>
            <xsl:when test="('' = $menu)">
                <xsl:value-of select="$tab"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$menu"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="menu_menu" select="$menus/xde:menu[(@id = $menu)]"/>
    <xsl:param name="menu_section" select="$menu_menu/xde:menu-section"/>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->
    <xsl:variable name="menu_sections" select="$menus/xde:menu-sections"/>
    <xsl:variable name="raise_selected_section_to_top" select="$menu_sections/@raise_selected_to_top"/>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <table
     border="{$border}"
     bgcolor="{$menu_bgcolor}"
     width="{$menu_width}" height="100%"
     cellspacing="0" cellpadding="0">
        <!--========================================================================-->
        <tr><td valign="top">
            <table
             border="{$border}"
             width="100%" cellspacing="0" cellpadding="0">
                <!--========================================================================-->
                <xsl:if test="('yes' = $raise_selected_section_to_top)">
                <xsl:for-each select="$menu_section">
                    <xsl:variable name="is_using_element">
                        <xsl:apply-templates mode="is_using_element" select="."/>
                    </xsl:variable>
                    <xsl:if test="(@id = $section)">
                    <xsl:if test="(not (@for)) or (((@for) and (@for = $for)) or (('yes' = @or_not_for) and ('' = $for)))">
                    <xsl:if test="(not (@using)) or (((@using) and (@using = $using)) or (('yes' = @or_not_using) and ('' = $using)) or ('yes' = $is_using_element))">
                        <xsl:call-template name="menu_section">
                            <xsl:with-param name="menus" select="$menus"/>
                        </xsl:call-template>
                    </xsl:if>
                    </xsl:if>
                    </xsl:if>
                </xsl:for-each>
                </xsl:if>
                <xsl:for-each select="$menu_section">
                    <xsl:variable name="is_using_element">
                        <xsl:apply-templates mode="is_using_element" select="."/>
                    </xsl:variable>
                    <xsl:if test="(('yes' != $raise_selected_section_to_top) or (@id != $section))">
                    <xsl:if test="(not (@for)) or (((@for) and (@for = $for)) or (('yes' = @or_not_for) and ('' = $for)))">
                    <xsl:if test="(not (@using)) or (((@using) and (@using = $using)) or (('yes' = @or_not_using) and ('' = $using)) or ('yes' = $is_using_element))">
                        <xsl:call-template name="menu_section">
                            <xsl:with-param name="menus" select="$menus"/>
                        </xsl:call-template>
                    </xsl:if>
                    </xsl:if>
                    </xsl:if>
                </xsl:for-each>
                <!--========================================================================-->
            </table>
        </td></tr>
        <!--========================================================================-->
    </table>
</xsl:template>

</xsl:transform>
