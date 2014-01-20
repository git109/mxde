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
<!--   File: restapi-to-js-standard-templates.xslt                          -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="object_root" select="'/'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "file_header"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template name="file_header">
<xsl:param name="file" select="$file"/>
<xsl:text>////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-</xsl:text><xsl:value-of select="$year"/>
<xsl:text> </xsl:text><xsl:value-of select="$organization"/><xsl:text>
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: </xsl:text><xsl:value-of select="$file"/><xsl:text>
///
/// Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
///   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
////////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!-- Template: "object_namespace"                                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template name="object_namespace">
<xsl:param name="namespace" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $namespace)">
<xsl:value-of select="$namespace"/>
<xsl:value-of select="'.'"/>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: "object_path"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template name="object_path">
<xsl:param name="path" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $path)">
<xsl:value-of select="$path"/>
<xsl:value-of select="'/'"/>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>

</xsl:stylesheet>
