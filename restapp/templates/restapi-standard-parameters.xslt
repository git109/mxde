<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2014 $organization$                                 -->
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
<!--   File: restapi-standard-parameters.xslt                               -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/1/2014                                                       -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 xmlns:rapi="RestApplicationProgramInterface"
 exclude-result-prefixes="xsl exsl xalan msxsl rapi"
 version="1.0">

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="content_type" select="'text/plain'"/>

<xsl:param name="current_date_scheme" select="'http://'"/>
<xsl:param name="current_date_host" select="'localhost'"/>
<xsl:param name="current_date_path" select="'/medusaxde/t/mxde-date-to-xml.t'"/>
<xsl:param name="current_date_query" select="'?content_type=xml'"/>
<xsl:param name="current_date_location">
    <xsl:value-of select="$current_date_scheme"/>
    <xsl:value-of select="$current_date_host"/>
    <xsl:value-of select="$current_date_path"/>
    <xsl:value-of select="$current_date_query"/>
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

<xsl:variable name="a2z" select="'abcdefghijklmnopqrstuvwxyz'"/>
<xsl:variable name="A2Z" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>
<xsl:variable name="z29" select="'0123456789'"/>

<xsl:variable name="a2-" select="'=========================='"/>
<xsl:variable name="z2-" select="'=========='"/>

<xsl:variable name="a2z.">
<xsl:value-of select="$a2z"/>
<xsl:value-of select="'.'"/>
</xsl:variable>

<xsl:variable name="A2Z_">
<xsl:value-of select="$A2Z"/>
<xsl:value-of select="'_'"/>
</xsl:variable>

<xsl:variable name="id">
<xsl:value-of select="$a2z"/>
<xsl:value-of select="$A2Z"/>
<xsl:value-of select="$z29"/>
<xsl:value-of select="'.'"/>
<xsl:value-of select="'_'"/>
</xsl:variable>

<xsl:variable name="id-">
<xsl:value-of select="$a2-"/>
<xsl:value-of select="$a2-"/>
<xsl:value-of select="$z2-"/>
<xsl:value-of select="'='"/>
<xsl:value-of select="'='"/>
</xsl:variable>

<xsl:variable name="fn">
<xsl:value-of select="$a2z"/>
<xsl:value-of select="$A2Z"/>
<xsl:value-of select="$z29"/>
<xsl:value-of select="'.'"/>
<xsl:value-of select="'-'"/>
<xsl:value-of select="'_'"/>
</xsl:variable>

<xsl:variable name="fn-">
<xsl:value-of select="$a2-"/>
<xsl:value-of select="$a2-"/>
<xsl:value-of select="$z2-"/>
<xsl:value-of select="'='"/>
<xsl:value-of select="'='"/>
<xsl:value-of select="'='"/>
</xsl:variable>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="organization" select="'$organization$'"/>
<xsl:param name="author" select="'$author$'"/>
<xsl:param name="year" select="$current_year"/>
<xsl:param name="date" select="$current_date"/>

<xsl:param name="copyright_year" select="$year"/>
<xsl:param name="file_date" select="$date"/>

<xsl:param name="file_base" select="'file'"/>
<xsl:param name="file_extension" select="''"/>
<xsl:param name="file">
<xsl:value-of select="$file_base"/>
<xsl:value-of select="$file_extension"/>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="FILE_BASE" select="translate($file_base,$a2z.,$A2Z_)"/>
<xsl:variable name="FILE_EXTENSION" select="translate($file_extension,$a2z.,$A2Z_)"/>

</xsl:transform>
