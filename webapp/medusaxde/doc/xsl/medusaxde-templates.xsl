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
<!--   File: medusaxde-templates.xsl                                        -->
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
<!-- Template: match "*"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/12/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <b>Unexpected document type "</b>
    <xsl:value-of select="name()"/>
    <b>"</b>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "mxde:medusaxde"                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/12/2011                                                    -->
<!--========================================================================-->
<xsl:template match="mxde:medusaxde">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <html>
        <xsl:call-template name="main"/>
    </html>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*" mode "for_text"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/4/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="for_text">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="for_text" select="/*/mxde:for/mxde:for-which[(@for = $for)]/mxde:text"/>
    <xsl:param name="text_for" select="mxde:text[((@for) and (@for = $for))]"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="('' != $text_for)">
            <xsl:value-of select="$text_for"/>
        </xsl:when>
        <xsl:when test="('' != $for_text)">
            <xsl:value-of select="$for_text"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$for"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "using_text"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/4/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="using_text">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="using_text" select="/*/mxde:using/mxde:using-which[(@using = $using)]/mxde:text"/>
    <xsl:param name="text_using" select="mxde:text[((@using) and (@using = $using))]"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="('' != $text_using)">
            <xsl:value-of select="$text_using"/>
        </xsl:when>
        <xsl:when test="('' != $using_text)">
            <xsl:value-of select="$using_text"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$using"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*" mode "is_using_element"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                               -->
<!--     Date: 11/15/2009                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="is_using_element">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="(mxde:using[@yes = $using])">yes</xsl:when>
        <xsl:otherwise>no</xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "element_location"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/8/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="element_location">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="http_scheme" select="''"/>
    <xsl:param name="http_host" select="''"/>
    <xsl:param name="http_port" select="''"/>
    <xsl:param name="http_path" select="''"/>
    <xsl:param name="location_scheme">
        <xsl:choose>
            <xsl:when test="@location_scheme">
                <xsl:value-of select="@location_scheme"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$http_scheme"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="location_host">
        <xsl:choose>
            <xsl:when test="@location_host">
                <xsl:value-of select="@location_host"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$http_host"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="location_port">
        <xsl:choose>
            <xsl:when test="@location_port">
                <xsl:value-of select="@location_port"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$http_port"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="location_path">
        <xsl:choose>
            <xsl:when test="@location_path">
                <xsl:value-of select="@location_path"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$http_path"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="location_query">
        <xsl:choose>
            <xsl:when test="@location_query">
                <xsl:value-of select="'?'"/>
                <xsl:value-of select="@location_query"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="location_query_and">
        <xsl:choose>
            <xsl:when test="@location_query_and">
                <xsl:value-of select="'&amp;'"/>
                <xsl:value-of select="@location_query_and"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="location_fragment">
        <xsl:choose>
            <xsl:when test="@location_fragment">
                <xsl:value-of select="'#'"/>
                <xsl:value-of select="@location_fragment"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="@location">
            <xsl:value-of select="@location_path"/>
            <xsl:value-of select="@location"/>
            <xsl:value-of select="$location_query"/>
            <xsl:value-of select="$location_query_and"/>
            <xsl:value-of select="$location_fragment"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:if test="'' != $location_scheme">
                <xsl:value-of select="$location_scheme"/>
                <xsl:value-of select="':'"/>
            </xsl:if>
            <xsl:if test="'' != $location_host">
                <xsl:value-of select="'//'"/>
                <xsl:value-of select="$location_host"/>
            </xsl:if>
            <xsl:if test="'' != $location_port">
                <xsl:value-of select="':'"/>
                <xsl:value-of select="$location_port"/>
            </xsl:if>
            <xsl:value-of select="$location_path"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "element_location_target"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/8/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="element_location_target">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:value-of select="@location_target"/>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "element_is_location_target"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/8/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="element_is_location_target">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="('yes' = @is_location_target)">
            <xsl:value-of select="@is_location_target"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "element_location_query_and"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/8/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="element_location_query_and">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="location_query" select="@location_query"/>
    <xsl:param name="location_query_and" select="@location_query_and"/>
    <xsl:param name="location_fragment" select="@location_fragment"/>
    <xsl:param name="is_location_query" select="'no'"/>
    <xsl:param name="is_location_query_and" select="'no'"/>
    <xsl:param name="is_location_fragment" select="'no'"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="('no' != $is_location_query) or ('no' != @is_location_query)">
        <xsl:if test="'' != $location_query">
            <xsl:value-of select="$location_query"/>
        </xsl:if>
    </xsl:if>
    <xsl:if test="('no' != $is_location_query_and) or ('no' != @is_location_query_and)">
        <xsl:if test="'' != $location_query_and">
            <xsl:value-of select="$location_query_and"/>
        </xsl:if>
    </xsl:if>
    <xsl:if test="('no' != $is_location_fragment) or ('no' != @is_location_fragment)">
        <xsl:if test="'' != $location_fragment">
            <xsl:value-of select="$location_fragment"/>
        </xsl:if>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "folder_location"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/7/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="folder_location">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="is_location_query_and" select="'no'"/>
    <xsl:param name="is_location_query_and_menu" select="'no'"/>
    <xsl:param name="is_location_query_and_border" select="'no'"/>
    <xsl:param name="is_location_query_and_author" select="'no'"/>
    <xsl:param name="is_location_query_and_for" select="'no'"/>
    <xsl:param name="is_location_query_and_using" select="'no'"/>
    <xsl:param name="is_location_query_and_form" select="'no'"/>
    <xsl:param name="location_query_and_form" select="'1'"/>
    <xsl:param name="is_location_fragment" select="'no'"/>
    <xsl:param name="location_fragment" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:apply-templates select="." mode="element_location">
    </xsl:apply-templates>
    <xsl:apply-templates select="." mode="element_location_query_and">
        <xsl:with-param name="is_location_query_and" select="$is_location_query_and"/>
        <xsl:with-param name="location_query_and">
            <xsl:if test="('' != @location_query_and)">
                <xsl:value-of select="@location_query_and"/>
            </xsl:if>
            <xsl:if test="('yes' = $is_location_query_and_menu) or ('yes' = @is_location_query_and_menu)">
                <xsl:value-of select="$and_menu"/>
            </xsl:if>
            <xsl:if test="('no' != $is_location_query_and_author) or ('no' != @is_location_query_and_author)">
                <xsl:value-of select="$and_author"/>
            </xsl:if>
            <xsl:if test="('no' != $is_location_query_and_for) or ('no' != @is_location_query_and_for)">
                <xsl:value-of select="$and_for"/>
            </xsl:if>
            <xsl:if test="('no' != $is_location_query_and_using) or ('no' != @is_location_query_and_using)">
                <xsl:value-of select="$and_using"/>
            </xsl:if>
            <xsl:if test="('no' != $is_location_query_and_border) or ('no' != @is_location_query_and_border)">
                <xsl:value-of select="$and_border"/>
            </xsl:if>
            <xsl:if test="('no' != $is_location_query_and_form) or ('no' != @is_location_query_and_form)">
                <xsl:value-of select="'&amp;form='"/>
                <xsl:value-of select="$location_query_and_form"/>
            </xsl:if>
        </xsl:with-param>
        <xsl:with-param name="is_location_fragment" select="$is_location_fragment"/>
        <xsl:with-param name="location_fragment" select="$location_fragment"/>
    </xsl:apply-templates>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "folder_location_on_click"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/9/2009                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="folder_location_on_click">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="p">
    </xsl:param>

    <!--========================================================================-->
    <!-- Template Variables                                                     -->
    <!--========================================================================-->
    <xsl:variable name="is_location_target">
        <xsl:apply-templates select="." mode="element_is_location_target">
        </xsl:apply-templates>
    </xsl:variable>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="('' != $is_location_target)">
            <xsl:value-of select="'onClickLocation'"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'onClickItem'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "*" mode "folder_text"                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/10/2009                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="folder_text">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="select" select="."/>
    <xsl:param name="class" select="'folder'"/>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="('' != @href)">
            <xsl:choose>
                <xsl:when test="('' != @target)">
                    <a class="{$class}" href="{@href}" target="{@target}">
                        <b><xsl:value-of select="$select"/></b><br/>
                    </a>
                </xsl:when>
                <xsl:otherwise>
                    <a class="{$class}" href="{@href}">
                        <b><xsl:value-of select="$select"/></b><br/>
                    </a>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:when>
        <xsl:otherwise>
            <b><xsl:value-of select="$select"/></b><br/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
</xsl:transform>
