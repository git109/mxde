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
<!--   File: medusaxde-form-row-control-templates.xsl                       -->
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
<!-- Includes                                                               -->
<!--========================================================================-->

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
<!-- row controls                                                           -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "separator_section_row"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="separator_section_row">
    <xsl:param name="bgcolor" select="$xde_form_separator_section_bgcolor"/>
    <xsl:param name="height" select="$xde_form_separator_section_height"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
        <td nowrap="yes" 
            colspan="2" 
            bgcolor="{$bgcolor}" 
            align="middle"
            height="{$height}">
        </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "section_separator_row"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="section_separator_row">
    <xsl:param name="bgcolor" select="$xde_form_section_bgcolor"/>
    <xsl:param name="height" select="$xde_form_section_separator_height"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr>
        <td bgcolor="{$bgcolor}"
         height="{$height}">        
        </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "subsection_row"                                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/26/2011                                                    -->
<!--========================================================================-->
<xsl:template name="subsection_row">
    <xsl:param name="bgcolor" select="$xde_form_subsection_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_subsection_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_subsection_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_subsection_font_color"/>
    <xsl:param name="text" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="section_row">
        <xsl:with-param name="bgcolor" select="$bgcolor"/>
        <xsl:with-param name="text_font_face" select="$text_font_face"/>
        <xsl:with-param name="text_font_size" select="$text_font_size"/>
        <xsl:with-param name="text_font_color" select="$text_font_color"/>
        <xsl:with-param name="text" select="$text"/>
    </xsl:call-template>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "section_row"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="section_row">
    <xsl:param name="bgcolor" select="$xde_form_section_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_section_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_section_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_section_font_color"/>
    <xsl:param name="align" select="'middle'"/>
    <xsl:param name="valign" select="'middle'"/>
    <xsl:param name="text" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="{$valign}">
           <td nowrap="yes" colspan="2" 
            bgcolor="{$bgcolor}" align="{$align}">
               <font
                face="{$text_font_face}"
                size="{$text_font_size}"
                color="{$text_font_color}">
                    <b><xsl:value-of select="$text"/></b>
               </font>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "text_row"                                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="text_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="bold" select="''"/>
    <xsl:param name="align" select="'middle'"/>
    <xsl:param name="valign" select="'middle'"/>
    
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="{$valign}">
           <td nowrap="yes" colspan="2" 
            bgcolor="{$bgcolor}" align="{$align}">
               <font
                face="{$text_font_face}"
                size="{$text_font_size}"
                color="{$text_font_color}">
                   <xsl:choose>
                       <xsl:when test="'' != $bold">
                            <b><xsl:value-of select="$text"/></b>
                       </xsl:when>
                       <xsl:otherwise>
                            <xsl:value-of select="$text"/>
                       </xsl:otherwise>
                   </xsl:choose>
               </font>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "listbox_row"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="listbox_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="label" select="''"/>
    <xsl:param name="name" select="'listbox'"/>
    <xsl:param name="size" select="'2'"/>
    <xsl:param name="multiple" select="''"/>
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
           <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
               <table border="{$border}" width="100%" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <xsl:if test="'' != $label">
                           <a name="{$label}"/>
                       </xsl:if>
                       <td align="middle">
                           <font
                            face="{$text_font_face}"
                            size="{$text_font_size}"
                            color="{$text_font_color}">
                               <xsl:value-of select="$text"/>
                           </font>
                       </td>
                       <xsl:if test="'' != $text_before">
                           <td align="right">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_before"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td bgcolor="{$bgcolor}" align="left">
                           <xsl:call-template name="listbox">
                               <xsl:with-param name="class" select="'folder'"/>
                               <xsl:with-param name="size" select="$size"/>
                               <xsl:with-param name="multiple" select="$multiple"/>
                               <xsl:with-param name="name" select="$name"/>
                               <xsl:with-param name="value" select="$value"/>
                               <xsl:with-param name="option" select="$option"/>
                               <xsl:with-param name="default" select="$default"/>
                           </xsl:call-template>
                       </td>
                       <xsl:if test="'' != $text_after">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "dropbox_row"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="dropbox_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="label" select="''"/>
    <xsl:param name="name" select="'dropbox'"/>
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
           <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
               <table border="{$border}" width="100%" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <xsl:if test="'' != $label">
                           <a name="{$label}"/>
                       </xsl:if>
                       <td align="middle">
                           <font
                            face="{$text_font_face}"
                            size="{$text_font_size}"
                            color="{$text_font_color}">
                               <xsl:value-of select="$text"/>
                           </font>
                       </td>
                       <xsl:if test="'' != $text_before">
                           <td align="right">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_before"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td bgcolor="{$bgcolor}" align="left">
                           <xsl:call-template name="dropbox">
                               <xsl:with-param name="name" select="$name"/>
                               <xsl:with-param name="value" select="$value"/>
                               <xsl:with-param name="option" select="$option"/>
                               <xsl:with-param name="default" select="$default"/>
                           </xsl:call-template>
                       </td>
                       <xsl:if test="'' != $text_after">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
       </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "yesno_row"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="yesno_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="text" select="''"/>
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
    <tr valign="middle">
           <td nowrap="yes" bgcolor="{$bgcolor}" align="right">
               <table border="{$border}" width="100%" 
                cellspacing="0" cellpadding="0">
                   <tr>
                      <td nowrap="yes" align="middle">
                          <font
                           face="{$text_font_face}"
                           size="{$text_font_size}"
                           color="{$text_font_color}">
                               <xsl:value-of select="$text"/>
                          </font>
                      </td>
                       <xsl:if test="'' != $text_before">
                       <td nowrap="yes" align="right">
                           <font
                            face="{$text_font_face}"
                            size="{$text_font_size}"
                            color="{$text_font_color}">
                               <b><xsl:value-of select="$text_before"/></b>
                           </font>
                       </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td>
                           <xsl:call-template name="yesno">
                               <xsl:with-param name="name" select="$name"/>
                               <xsl:with-param name="value" select="$value"/>
                               <xsl:with-param name="yes" select="$yes"/>
                               <xsl:with-param name="no" select="$no"/>
                               <xsl:with-param name="yes_value" select="$yes_value"/>
                               <xsl:with-param name="no_value" select="$no_value"/>
                               <xsl:with-param name="default" select="$default"/>
                           </xsl:call-template>
                       </td>
                       <xsl:if test="'' != $text_after">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "noyes_row"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="noyes_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="text" select="''"/>
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
    <tr valign="middle">
           <!--td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
               <font
                face="{$text_font_face}"
                size="{$text_font_size}"
                color="{$text_font_color}">
                    <xsl:value-of select="$text"/>
               </font>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <xsl:call-template name="noyes">
                   <xsl:with-param name="name" select="$name"/>
                   <xsl:with-param name="value" select="$value"/>
                   <xsl:with-param name="yes" select="$yes"/>
                   <xsl:with-param name="no" select="$no"/>
                   <xsl:with-param name="yes_value" select="$yes_value"/>
                   <xsl:with-param name="no_value" select="$no_value"/>
                   <xsl:with-param name="default" select="$default"/>
               </xsl:call-template>
           </td-->
           <td nowrap="yes" bgcolor="{$bgcolor}" align="right">
               <table border="{$border}" width="100%"
                cellspacing="0" cellpadding="0">
                   <tr>
                      <td nowrap="yes" align="middle">
                          <font
                           face="{$text_font_face}"
                           size="{$text_font_size}"
                           color="{$text_font_color}">
                               <xsl:value-of select="$text"/>
                          </font>
                      </td>
                       <xsl:if test="'' != $text_before">
                       <td nowrap="yes" align="right">
                           <font
                            face="{$text_font_face}"
                            size="{$text_font_size}"
                            color="{$text_font_color}">
                               <b><xsl:value-of select="$text_before"/></b>
                           </font>
                       </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}"
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td>
                           <xsl:call-template name="noyes">
                               <xsl:with-param name="name" select="$name"/>
                               <xsl:with-param name="value" select="$value"/>
                               <xsl:with-param name="yes" select="$yes"/>
                               <xsl:with-param name="no" select="$no"/>
                               <xsl:with-param name="yes_value" select="$yes_value"/>
                               <xsl:with-param name="no_value" select="$no_value"/>
                               <xsl:with-param name="default" select="$default"/>
                           </xsl:call-template>
                       </td>
                       <xsl:if test="'' != $text_after">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "radios_row"                                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="radios_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="name" select="'enum'"/>
    <xsl:param name="value"/>
    <xsl:param name="option"/>
    <xsl:param name="default"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
           <td bgcolor="{$bgcolor}" align="middle">
               <table border="{$border}" width="100%" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td nowrap="yes" align="middle">
                           <font
                            face="{$text_font_face}"
                            size="{$text_font_size}"
                            color="{$text_font_color}">
                                <xsl:value-of select="$text"/>
                           </font>
                       </td>
                       <xsl:if test="'' != $text_before">
                           <td nowrap="yes" align="right">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_before"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td>
                           <xsl:call-template name="radios">
                               <xsl:with-param name="name" select="$name"/>
                               <xsl:with-param name="value" select="$value"/>
                               <xsl:with-param name="option" select="$option"/>
                               <xsl:with-param name="default" select="$default"/>
                           </xsl:call-template>
                       </td>
                       <xsl:if test="'' != $text_after">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "checkboxes_row"                                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="checkboxes_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="name" select="''"/>
    <xsl:param name="value_name" select="''"/>
    <xsl:param name="value" select="''"/>
    <xsl:param name="yes" select="'yes'"/>
    <xsl:param name="option"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
           <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
               <table border="{$border}" width="100%" 
                cellspacing="0" cellpadding="0">
                   <tr>
                      <td nowrap="yes" align="middle">
                       <font
                           face="{$text_font_face}"
                           size="{$text_font_size}"
                           color="{$text_font_color}">
                            <xsl:value-of select="$text"/>
                       </font>
                      </td>
                      <xsl:if test="'' != $text_before">
                          <td nowrap="yes" align="right">
                              <font
                               face="{$text_font_face}"
                               size="{$text_font_size}"
                               color="{$text_font_color}">
                                  <b><xsl:value-of select="$text_before"/></b>
                              </font>
                          </td>
                      </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td>
                           <xsl:call-template name="checkboxes">
                               <xsl:with-param name="name" select="$name"/>
                               <xsl:with-param name="value_name" select="$value_name"/>
                               <xsl:with-param name="value" select="$value"/>
                               <xsl:with-param name="yes" select="$yes"/>
                               <xsl:with-param name="option" select="$option"/>
                           </xsl:call-template>
                       </td>
                       <xsl:if test="('' != $text_after)">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "checkbox_row"                                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="checkbox_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="yes" select="'yes'"/>
    <xsl:param name="name" select="''"/>
    <xsl:param name="value" select="''"/>
    <xsl:param name="option" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <!--tr valign="middle">
        <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
            <table border="{$border}" width="100%" 
             cellspacing="0" cellpadding="0">
                <tr>
                    <td nowrap="yes" align="middle">
                        <font
                            face="{$text_font_face}"
                            size="{$text_font_size}"
                            color="{$text_font_color}">
                            <xsl:value-of select="$text"/>
                        </font>
                    </td>
                </tr>
            </table>
        </td>
        <td bgcolor="{$bgcolor}" align="left">
            <xsl:call-template name="checkbox">
                <xsl:with-param name="name" select="$name"/>
                <xsl:with-param name="value" select="$value"/>
                <xsl:with-param name="text" select="$option"/>
                <xsl:with-param name="option" select="$yes"/>
            </xsl:call-template>
        </td>
    </tr-->
    <tr valign="middle">
           <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
               <table border="{$border}" width="100%" 
                cellspacing="0" cellpadding="0">
                   <tr>
                      <td nowrap="yes" align="middle">
                       <font
                           face="{$text_font_face}"
                           size="{$text_font_size}"
                           color="{$text_font_color}">
                            <xsl:value-of select="$text"/>
                       </font>
                      </td>
                      <xsl:if test="'' != $text_before">
                          <td nowrap="yes" align="right">
                              <font
                               face="{$text_font_face}"
                               size="{$text_font_size}"
                               color="{$text_font_color}">
                                  <b><xsl:value-of select="$text_before"/></b>
                              </font>
                          </td>
                      </xsl:if>
                   </tr>
               </table>
           </td>
           <td bgcolor="{$bgcolor}" align="left">
               <table border="{$border}" 
                cellspacing="0" cellpadding="0">
                   <tr>
                       <td>
                            <xsl:call-template name="checkbox">
                                <xsl:with-param name="name" select="$name"/>
                                <xsl:with-param name="value" select="$value"/>
                                <xsl:with-param name="text" select="$option"/>
                                <xsl:with-param name="option" select="$yes"/>
                            </xsl:call-template>
                       </td>
                       <xsl:if test="('' != $text_after)">
                           <td align="left">
                               <font
                                face="{$text_font_face}"
                                size="{$text_font_size}"
                                color="{$text_font_color}">
                                   <b><xsl:value-of select="$text_after"/></b>
                               </font>
                           </td>
                       </xsl:if>
                   </tr>
               </table>
           </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "input_row"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="input_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="name" select="'input'"/>
    <xsl:param name="value" select="''"/>
    <xsl:param name="label" select="''"/>
    <xsl:param name="size" select="$xde_form_input_size"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
        <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
            <table border="{$border}" width="100%" 
             cellspacing="0" cellpadding="0">
                <tr>
                    <xsl:if test="'' != $label">
                        <a name="{$label}"/>
                    </xsl:if>
                    <td align="middle">
                        <font
                         face="{$text_font_face}"
                         size="{$text_font_size}"
                         color="{$text_font_color}">
                            <xsl:value-of select="$text"/>
                        </font>
                    </td>
                    <xsl:if test="'' != $text_before">
                        <td align="right">
                            <font
                             face="{$text_font_face}"
                             size="{$text_font_size}"
                             color="{$text_font_color}">
                                <b>
                                    <xsl:value-of select="$text_before"/>
                                </b>
                            </font>
                        </td>
                    </xsl:if>
                </tr>
            </table>
        </td>
        <td bgcolor="{$bgcolor}" align="left">
            <table border="{$border}" 
             cellspacing="0" cellpadding="0">
                <tr>
                    <td align="right">
                        <input
                         type="text" 
                         name="{$name}" 
                         size="{$size}"
                         value="{$value}"/>
                    </td>
                    <xsl:if test="'' != $text_after">
                        <td align="left">
                            <font
                             face="{$text_font_face}"
                             size="{$text_font_size}"
                             color="{$text_font_color}">
                                <b>
                                    <xsl:value-of select="$text_after"/>
                                </b>
                            </font>
                        </td>
                    </xsl:if>
                </tr>
            </table>
        </td>
    </tr>
</xsl:template>

<!--========================================================================-->
<!-- Template: "static_row"                                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 7/4/2010                                                     -->
<!--========================================================================-->
<xsl:template name="static_row">
    <xsl:param name="bgcolor" select="$xde_form_bgcolor"/>
    <xsl:param name="text_font_face" select="$xde_form_font_face"/>
    <xsl:param name="text_font_size" select="$xde_form_font_size"/>
    <xsl:param name="text_font_color" select="$xde_form_font_color"/>
    <xsl:param name="text" select="''"/>
    <xsl:param name="text_before" select="''"/>
    <xsl:param name="text_after" select="''"/>
    <xsl:param name="label" select="''"/>
    <xsl:param name="value" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <tr valign="middle">
        <td nowrap="yes" bgcolor="{$bgcolor}" align="middle">
            <table border="{$border}" width="100%" 
             cellspacing="0" cellpadding="0">
                <tr>
                    <xsl:if test="'' != $label">
                        <a name="{$label}"/>
                    </xsl:if>
                    <td nowrap="yes" align="middle">
                        <font
                         face="{$text_font_face}"
                         size="{$text_font_size}"
                         color="{$text_font_color}">
                            <xsl:value-of select="$text"/>
                        </font>
                    </td>
                    <xsl:if test="'' != $text_before">
                        <td nowrap="yes" align="right">
                            <font
                             face="{$text_font_face}"
                             size="{$text_font_size}"
                             color="{$text_font_color}">
                                <b>
                                    <xsl:value-of select="$text_before"/>
                                </b>
                            </font>
                        </td>
                    </xsl:if>
                </tr>
            </table>
        </td>
        <td bgcolor="{$bgcolor}" align="left">
            <table border="{$border}" 
             cellspacing="0" cellpadding="0">
                <tr>
                    <td nowrap="yes" align="left">
                        <xsl:value-of select="$value"/>
                    </td>
                    <xsl:if test="'' != $text_after">
                        <td nowrap="yes" align="left">
                            <font
                             face="{$text_font_face}"
                             size="{$text_font_size}"
                             color="{$text_font_color}">
                                <b>
                                    <xsl:value-of select="$text_after"/>
                                </b>
                            </font>
                        </td>
                    </xsl:if>
                </tr>
            </table>
        </td>
    </tr>
</xsl:template>

</xsl:transform>
