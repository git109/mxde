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
<!--   File: medusaxde-current-date.xsl                                     -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/16/2012                                                      -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="current_date_host" select="'localhost'"/>
<xsl:param name="current_date_location">
    <xsl:value-of select="'http://'"/>
    <xsl:value-of select="$current_date_host"/>
    <xsl:value-of select="'/medusaxde/t/mxde-date-to-xml.t?content_type=xml'"/>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="current_date_document" select="document($current_date_location)"/>
<xsl:variable name="current_date">
    <xsl:choose>
        <xsl:when test="($current_date_document/*/@date)">
            <xsl:value-of select="$current_date_document/*/@date"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'$date$'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:variable name="current_year">
    <xsl:choose>
        <xsl:when test="($current_date_document/*/@year)">
            <xsl:value-of select="$current_date_document/*/@year"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'$year$'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
    
</xsl:transform>
