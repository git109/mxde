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
<!--   File: medusaxde-form-control-templates.xsl                           -->
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
<!-- group controls                                                         -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "yesno"                                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="yesno">
    <xsl:param name="name" select="'yesno'"/>
    <xsl:param name="value"/>
    <xsl:param name="yes" select="'yes'"/>
    <xsl:param name="no" select="'no'"/>
    <xsl:param name="yes_value" select="$yes"/>
    <xsl:param name="no_value" select="$no"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="radio">
        <xsl:with-param name="name" select="$name"/>
        <xsl:with-param name="value" select="$value"/>
        <xsl:with-param name="option" select="$yes_value"/>
        <xsl:with-param name="text" select="$yes"/>
        <xsl:with-param name="default">
            <xsl:if test="$yes_value = $default">
                <xsl:value-of select="'yes'"/>
            </xsl:if>
        </xsl:with-param>
    </xsl:call-template>
    <xsl:call-template name="radio">
        <xsl:with-param name="name" select="$name"/>
        <xsl:with-param name="value" select="$value"/>
        <xsl:with-param name="option" select="$no_value"/>
        <xsl:with-param name="text" select="$no"/>
        <xsl:with-param name="default">
            <xsl:if test="$no_value = $default">
                <xsl:value-of select="'yes'"/>
            </xsl:if>
        </xsl:with-param>
    </xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "noyes"                                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="noyes">
    <xsl:param name="name" select="'noyes'"/>
    <xsl:param name="value"/>
    <xsl:param name="yes" select="'yes'"/>
    <xsl:param name="no" select="'no'"/>
    <xsl:param name="yes_value" select="$yes"/>
    <xsl:param name="no_value" select="$no"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="radio">
        <xsl:with-param name="name" select="$name"/>
        <xsl:with-param name="value" select="$value"/>
        <xsl:with-param name="option" select="$no_value"/>
        <xsl:with-param name="text" select="$no"/>
        <xsl:with-param name="default">
            <xsl:if test="$no_value = $default">
                <xsl:value-of select="'yes'"/>
            </xsl:if>
        </xsl:with-param>
    </xsl:call-template>
    <xsl:call-template name="radio">
        <xsl:with-param name="name" select="$name"/>
        <xsl:with-param name="value" select="$value"/>
        <xsl:with-param name="option" select="$yes_value"/>
        <xsl:with-param name="text" select="$yes"/>
        <xsl:with-param name="default">
            <xsl:if test="$yes_value = $default">
                <xsl:value-of select="'yes'"/>
            </xsl:if>
        </xsl:with-param>
    </xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "radios"                                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="radios">
    <xsl:param name="name" select="'enum'"/>
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:for-each select="$option">
        <xsl:variable name="option_text" select="."/>
        <xsl:variable name="option_value">
            <xsl:call-template name="option_value">
                <xsl:with-param name="select" select="."/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="option_default">
            <xsl:call-template name="option_default">
                <xsl:with-param name="select" select="."/>
            </xsl:call-template>
        </xsl:variable>

        <xsl:call-template name="radio">
            <xsl:with-param name="name" select="$name"/>
            <xsl:with-param name="value" select="$value"/>
            <xsl:with-param name="option" select="$option_value"/>
            <xsl:with-param name="text" select="$option_text"/>
            <xsl:with-param name="default">
                <xsl:if test="(('yes' = $option_default) or ($option_value = $default))">
                    <xsl:value-of select="'yes'"/>
                </xsl:if>
            </xsl:with-param>
        </xsl:call-template>
    </xsl:for-each>
</xsl:template>

<!--========================================================================-->
<!-- Template: "checkboxes"                                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="checkboxes">
    <xsl:param name="option"/>
    <xsl:param name="name" select="''"/>
    <xsl:param name="value" select="''"/>
    <xsl:param name="value_name" select="''"/>
    <xsl:param name="yes" select="'yes'"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:for-each select="$option">
        <xsl:variable name="option_text" select="."/>
        <xsl:variable name="option_name">
            <xsl:value-of select="$name"/>
            <xsl:call-template name="option_name"/>
        </xsl:variable>
        <xsl:variable name="option_value">
            <xsl:call-template name="option_value">
                <xsl:with-param name="value" select="$yes"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="option_default">
            <xsl:call-template name="option_default"/>
        </xsl:variable>
        <xsl:variable name="option_checked">
          <xsl:if test="((''!=$value_name) and ($option_name=$value_name))">
            <xsl:value-of select="$value"/>
          </xsl:if>
        </xsl:variable>

        <xsl:call-template name="checkbox">
            <xsl:with-param name="value" select="$option_checked"/>
            <xsl:with-param name="name" select="$option_name"/>
            <xsl:with-param name="text" select="$option_text"/>
            <xsl:with-param name="option" select="$option_value"/>
            <xsl:with-param name="default" select="$option_default"/>
        </xsl:call-template>
    </xsl:for-each>
</xsl:template>

<!--========================================================================-->
<!-- Template: "option_name"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="option_name">
    <xsl:param name="select" select="."/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="'' != $select/@name">
            <xsl:value-of select="$select/@name"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$select"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: "option_value"                                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="option_value">
    <xsl:param name="select" select="."/>
    <xsl:param name="value" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="$select/@value">
            <xsl:value-of select="$select/@value"/>
        </xsl:when>
        <xsl:when test="'' != $value">
            <xsl:value-of select="$value"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$select"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: "option_default"                                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="option_default">
    <xsl:param name="select" select="."/>
    <xsl:param name="yes" select="'yes'"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="'' != $select/@default">
            <xsl:value-of select="$select/@default"/>
        </xsl:when>
        <xsl:when test="$select/@default">
            <xsl:value-of select="$yes"/>
        </xsl:when>
        <xsl:otherwise>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- controls                                                               -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "listbox"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="listbox">
    <xsl:param name="font_face" select="$xde_form_font_face"/>
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <xsl:param name="style">
        <xsl:call-template name="css_font_style">
            <xsl:with-param name="font_face" select="$font_face"/>
            <xsl:with-param name="font_size" select="$font_size"/>
        </xsl:call-template>
    </xsl:param>
    <xsl:param name="class" select="''"/>
    <xsl:param name="what" select="'listbox'"/>
    <xsl:param name="size" select="'2'"/>
    <xsl:param name="multiple" select="''"/>
    <xsl:param name="name" select="'listbox'"/>
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="'yes' = $multiple">
            <select class="{$class}_{$what}" style="{$style}" name="{$name}" size="{$size}" multiple="">
                <xsl:call-template name="select_options">
                    <xsl:with-param name="value" select="$value"/>
                    <xsl:with-param name="option" select="$option"/>
                    <xsl:with-param name="default" select="$default"/>
                </xsl:call-template>
            </select>
        </xsl:when>
        <xsl:otherwise>
            <select class="{$class}_{$what}" style="{$style}" name="{$name}" size="{$size}">
                <xsl:call-template name="select_options">
                    <xsl:with-param name="value" select="$value"/>
                    <xsl:with-param name="option" select="$option"/>
                    <xsl:with-param name="default" select="$default"/>
                </xsl:call-template>
            </select>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: "dropbox"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="dropbox">
    <xsl:param name="font_face" select="$xde_form_font_face"/>
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <xsl:param name="style">
        <xsl:call-template name="css_font_style">
            <xsl:with-param name="font_face" select="$font_face"/>
            <xsl:with-param name="font_size" select="$font_size"/>
        </xsl:call-template>
    </xsl:param>
    <xsl:param name="class" select="''"/>
    <xsl:param name="name" select="'dropbox'"/>
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <select class="{$class}" name="{$name}" style="{$style}" size="1">
        <xsl:call-template name="select_options">
            <xsl:with-param name="value" select="$value"/>
            <xsl:with-param name="option" select="$option"/>
            <xsl:with-param name="default" select="$default"/>
        </xsl:call-template>
    </select>
</xsl:template>

<!--========================================================================-->
<!-- Template: "select_options"                                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="select_options">
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:for-each select="$option">
        <xsl:variable name="option_value">
            <xsl:choose>
                <xsl:when test="(@value) and ('' != @value)">
                    <xsl:value-of select="@value"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="text()"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:variable name="option_text" select="text()"/>
        <xsl:variable name="option_eq_value" select="(('' != $value) and ('' != $default) and ($option_value = $value))"/>
        <xsl:variable name="option_eq_default" select="(('' = $value) and ('' != $default) and ($option_value = $default))"/>
        <xsl:variable name="option_is_default" select="(('' = $value) and ('' = $default) and ('yes' = @default))"/>
        <xsl:choose>
            <xsl:when test="($option_eq_value) or ($option_eq_default) or ($option_is_default)">
                <option value="{$option_value}" selected="">
                    <xsl:value-of select="$option_text"/>
                </option>
            </xsl:when>
            <xsl:otherwise>
                <option value="{$option_value}">
                    <xsl:value-of select="$option_text"/>
                </option>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:for-each>
</xsl:template>

<!--========================================================================-->
<!-- Template: "radio"                                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="radio">
    <xsl:param name="font_face" select="$xde_form_font_face"/>
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <xsl:param name="name" select="'radio'"/>
    <xsl:param name="value"/>
    <xsl:param name="text"/>
    <xsl:param name="option" select="'radio'"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <font face="{$font_face}" size="{$font_size}">
        <xsl:choose>
            <xsl:when test="((''!=$value) and ($option=$value)) or ((''=$value) and ($default='yes'))">
                <input type="radio" name="{$name}" value="{$option}" checked=""/>
            </xsl:when>
            <xsl:otherwise>
                <input type="radio" name="{$name}" value="{$option}"/>
            </xsl:otherwise>
        </xsl:choose>
        <xsl:value-of select="$text"/>
    </font>
</xsl:template>

<!--========================================================================-->
<!-- Template: "checkbox"                                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="checkbox">
    <xsl:param name="font_face" select="$xde_form_font_face"/>
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <xsl:param name="name" select="'checkbox'"/>
    <xsl:param name="value"/>
    <xsl:param name="text"/>
    <xsl:param name="option" select="'checkbox'"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <font face="{$font_face}" size="{$font_size}">
        <xsl:choose>
            <xsl:when test="((''!=$value) and ($option=$value)) or ((''=$value) and ($default='yes'))">
                <input type="checkbox" name="{$name}" value="{$option}" checked=""/>
            </xsl:when>
            <xsl:otherwise>
                <input type="checkbox" name="{$name}" value="{$option}"/>
            </xsl:otherwise>
        </xsl:choose>
        <xsl:value-of select="$text"/>
    </font>
</xsl:template>

<!--========================================================================-->
<!-- Template: "input"                                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="input">
    <xsl:param name="font_face" select="$xde_form_font_face"/>
    <xsl:param name="font_size" select="$xde_form_font_size"/>
    <xsl:param name="style">
        <xsl:call-template name="css_font_style">
            <xsl:with-param name="font_face" select="$font_face"/>
            <xsl:with-param name="font_size" select="$font_size"/>
        </xsl:call-template>
    </xsl:param>
    <xsl:param name="name" select="'input'"/>
    <xsl:param name="value" select="''"/>
    <xsl:param name="size" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <input
     type="text" 
     name="{$name}" 
     size="{$size}"
     value="{$value}"
     style="{$style}"/>
</xsl:template>

<!--========================================================================-->
<!-- Template: "hidden"                                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="hidden">
    <xsl:param name="name" select="'input'"/>
    <xsl:param name="value" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <input
     type="hidden" 
     name="{$name}" 
     value="{$value}"/>
</xsl:template>

</xsl:transform>
