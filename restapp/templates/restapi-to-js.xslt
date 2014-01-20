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
<!--   File: restapi-to-js.xslt                                             -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/17/2014                                                      -->
<!--========================================================================-->
<xsl:stylesheet
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:rapi="RestApplicationProgramInterface"
 exclude-result-prefixes="xsl exsl rapi"
 version="1.0">

<!--========================================================================-->
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="text"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../../restapi-standard-parameters.xslt"/>
<xsl:include href="../../restapi-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-js-standard-parameters.xslt"/>
<xsl:include href="../../restapi-to-js-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-js-objects.xslt"/>
<xsl:include href="../../restapi-to-js-functions.xslt"/>
<xsl:include href="../../restapi-to-js-listeners.xslt"/>

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
<!-- Template: match "rapi:application"                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:application">
<xsl:call-template name="file_header">
</xsl:call-template>
<xsl:text>
////////////////////////////////////////////////////////////////////////
/// Objects
////////////////////////////////////////////////////////////////////////
var </xsl:text>
<xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
<xsl:text> = new Object();
</xsl:text>
<xsl:apply-templates mode="rapi_js_objects" select="./*">
<xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
<xsl:with-param name="path">
<xsl:call-template name="object_path">
<xsl:with-param name="path" select="translate(@namespace,$A2Z,$a2z)"/>
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
</xsl:apply-templates>
<xsl:text>
////////////////////////////////////////////////////////////////////////
/// Functions
////////////////////////////////////////////////////////////////////////
</xsl:text>
<xsl:apply-templates mode="rapi_js_functions" select="./*">
<xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
<xsl:with-param name="path">
<xsl:call-template name="object_path">
<xsl:with-param name="path" select="translate(@namespace,$A2Z,$a2z)"/>
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
</xsl:apply-templates>
<xsl:text>
////////////////////////////////////////////////////////////////////////
/// Listeners
////////////////////////////////////////////////////////////////////////
</xsl:text>
<xsl:apply-templates mode="rapi_js_listeners" select="./*">
<xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
<xsl:with-param name="path">
<xsl:call-template name="object_path">
<xsl:with-param name="path" select="translate(@namespace,$A2Z,$a2z)"/>
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
</xsl:apply-templates>
</xsl:template>

</xsl:stylesheet>
