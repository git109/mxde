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
<!--   File: cXsltCgi.xslt                                                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/15/2011                                                      -->
<!--========================================================================-->
<xsl:stylesheet
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 xmlns:cXsltCgi="cXsltCgi"
 exclude-result-prefixes="xsl xalan msxsl"
 version="1.0">

<!--========================================================================-->
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="content_type" select="''"/>
<xsl:param name="content_types_tree">
    <type>text/plain</type>
    <type>text/html</type>
    <type>text/xml</type>
</xsl:param>
<xsl:param name="content_types" select="exsl:node-set($content_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: match "*"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/15/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*">
<b>Unexpected document type "</b><xsl:value-of select="name()"/><b>"</b>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "cXsltCgi:cXsltCgi"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/15/2011                                                    -->
<!--========================================================================-->
<xsl:template match="cXsltCgi:cXsltCgi">
<b>Content-type = "</b><xsl:value-of select="$content_type"/><b>"</b>
</xsl:template>
</xsl:stylesheet>
