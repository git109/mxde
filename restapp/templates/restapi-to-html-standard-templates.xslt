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
<!--   File: restapi-to-html-standard-templates.xslt                        -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/18/2014                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:rapi="RestApplicationProgramInterface"
 exclude-result-prefixes="xsl exsl rapi"
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
<!-- Template: "object_id"                                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template name="object_id">
<xsl:param name="object_id" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $object_id)">
<xsl:value-of select="$object_id"/>
<xsl:text>.</xsl:text>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: "object_name"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template name="object_name">
<xsl:param name="object_name" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $object_name)">
<xsl:value-of select="$object_name"/>
<xsl:text>_</xsl:text>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: "object_path"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template name="object_path">
<xsl:param name="object_path" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $object_path)">
<xsl:value-of select="$object_path"/>
<xsl:text>/</xsl:text>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_html_functions_args"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_html_functions_args">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:type" mode "rapi_html_functions_type"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:type" mode="rapi_html_functions_type">
<xsl:value-of select="@name"/>
<xsl:text> </xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_html_functions"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_html_functions">
<xsl:apply-templates mode="rapi_html_functions_type" select="rapi:type">
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_html_functions"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_html_functions">
<xsl:param name="object_id" select="''"/>
<xsl:param name="object_name" select="''"/>
<xsl:param name="object_path" select="''"/>
<xsl:variable name="oid">
<xsl:call-template name="object_id">
<xsl:with-param name="object_id" select="$object_id"/>
<xsl:with-param name="name">
<xsl:call-template name="namespace_case">
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:with-param>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="oname">
<xsl:call-template name="object_name">
<xsl:with-param name="object_name" select="$object_name"/>
<xsl:with-param name="name">
<xsl:call-template name="namespace_case">
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:with-param>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="opath">
<xsl:call-template name="object_path">
<xsl:with-param name="object_path" select="$object_path"/>
<xsl:with-param name="name">
<xsl:call-template name="namespace_case">
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:with-param>
</xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_html_functions" select="./*">
<xsl:with-param name="object_id" select="$oid"/>
<xsl:with-param name="object_name" select="$oname"/>
<xsl:with-param name="object_path" select="$opath"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_html_functions"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_html_functions">
<xsl:param name="object_id" select="''"/>
<xsl:param name="object_name" select="''"/>
<xsl:param name="object_path" select="''"/>
<xsl:variable name="oid">
<xsl:call-template name="object_id">
<xsl:with-param name="object_id" select="$object_id"/>
<xsl:with-param name="name">
<xsl:call-template name="object_case">
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:with-param>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="oname">
<xsl:call-template name="object_name">
<xsl:with-param name="object_name" select="$object_name"/>
<xsl:with-param name="name">
<xsl:call-template name="object_case">
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:with-param>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="opath">
<xsl:call-template name="object_path">
<xsl:with-param name="object_path" select="$object_path"/>
<xsl:with-param name="name">
<xsl:call-template name="object_case">
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:with-param>
</xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_html_functions" select="rapi:function">
<xsl:with-param name="object_id" select="$oid"/>
<xsl:with-param name="object_name" select="$oname"/>
<xsl:with-param name="object_path" select="$opath"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_html_functions"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_html_functions">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

</xsl:transform>

        

