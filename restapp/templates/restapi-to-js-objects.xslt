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
<!--   File: restapi-to-js-objects.xslt                                     -->
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
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_js_objects"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_js_objects">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
    <xsl:with-param name="namespace" select="$namespace"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
    <xsl:with-param name="path" select="$path"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_js_objects"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_js_objects">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
    <xsl:with-param name="namespace" select="$namespace"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
    <xsl:with-param name="path" select="$path"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:if test="(2 &gt; position())">
<xsl:text></xsl:text>
</xsl:if>
<xsl:text></xsl:text>
<xsl:value-of select="$object_namespace"/>
<xsl:text> = new Object();
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_objects"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_objects">
</xsl:template>

</xsl:stylesheet>

        

