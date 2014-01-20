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
<!--   File: restapi-to-js-html.xslt                                        -->
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
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../../restapi-standard-parameters.xslt"/>
<xsl:include href="../../restapi-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-html-standard-parameters.xslt"/>
<xsl:include href="../../restapi-to-html-standard-templates.xslt"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="form" select="'the_form'"/>
<xsl:param name="httpHost" select="''"/>
<xsl:param name="httpPort" select="''"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "namespace_case"                                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template name="namespace_case">
<xsl:param name="name" select="''"/>
<xsl:value-of select="translate($name,$A2Z,$a2z)"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: "object_case"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template name="object_case">
<xsl:param name="name" select="''"/>
<xsl:value-of select="$name"/>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_html_functions_args"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_html_functions_args">
<xsl:param name="count" select="0"/>
<xsl:param name="object_id" select="''"/>
<xsl:param name="object_name" select="''"/>
<xsl:param name="object_path" select="''"/>
<xsl:if test="(1 &lt; position())">
<xsl:text>,</xsl:text>
</xsl:if>
<xsl:text>getFormValue('</xsl:text>
<xsl:value-of select="$object_name"/>
<xsl:text>_</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>','</xsl:text>
<xsl:value-of select="$form"/>
<xsl:text>')</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_html_functions"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/19/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_html_functions">
<xsl:param name="count" select="0"/>
<xsl:param name="object_id" select="''"/>
<xsl:param name="object_name" select="''"/>
<xsl:param name="object_path" select="''"/>
<xsl:variable name="value">
    <xsl:choose>
        <xsl:when test="(0 &lt; count(rapi:value))">
        <xsl:value-of select="rapi:value"/>
        </xsl:when>
        <xsl:otherwise>
        <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:if test="(1 &lt; position())">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:if test="(0 &lt; $count)">
<br/>
</xsl:if>
<xsl:apply-templates mode="rapi_html_functions_type" select="rapi:type">
</xsl:apply-templates>
<xsl:value-of select="@name"/><xsl:text> = </xsl:text>
<input name="{$object_name}_{@name}" value="{$value}"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_html_functions"             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_html_functions">
<xsl:param name="object_id" select="''"/>
<xsl:param name="object_name" select="''"/>
<xsl:param name="object_path" select="''"/>
<xsl:variable name="oid">
<xsl:call-template name="object_id">
<xsl:with-param name="object_id" select="$object_id"/>
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="oname">
<xsl:call-template name="object_name">
<xsl:with-param name="object_name" select="$object_name"/>
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="opath">
<xsl:call-template name="object_path">
<xsl:with-param name="object_path" select="$object_path"/>
<xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="onClick">
<xsl:value-of select="$oid"/>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="rapi_html_functions_args" select="rapi:param">
<xsl:with-param name="count" select="count(rapi:param)"/>
<xsl:with-param name="object_id" select="$oid"/>
<xsl:with-param name="object_name" select="$oname"/>
<xsl:with-param name="object_path" select="$opath"/>
</xsl:apply-templates>
<xsl:text>)</xsl:text>
</xsl:variable>
<xsl:comment>===========<xsl:value-of select="translate($oid,$id,$id-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> function: <xsl:value-of select="$oid"/><xsl:text> </xsl:text></xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>===========<xsl:value-of select="translate($oid,$id,$id-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<xsl:if test="(1 &lt; position())">
<br/>
</xsl:if>
<xsl:apply-templates mode="rapi_html_functions" select="rapi:return">
</xsl:apply-templates>
<input type="button"
 name="{$oname}"
 value="{$oid}"
 onClick="{$onClick}"/>(<xsl:apply-templates mode="rapi_html_functions" select="rapi:param">
<xsl:with-param name="count" select="count(rapi:param)"/>
<xsl:with-param name="object_id" select="$oid"/>
<xsl:with-param name="object_name" select="$oname"/>
<xsl:with-param name="object_path" select="$opath"/>
</xsl:apply-templates>)<br/><xsl:text>
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:application"                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:application">
<xsl:variable name="object_path">
<xsl:value-of select="'/'"/>
<xsl:value-of select="translate(@namespace,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:variable name="title">
<xsl:value-of select="$framework"/>
<xsl:text> </xsl:text>
<xsl:value-of select="$application"/>
<xsl:text>.</xsl:text>
<xsl:value-of select="$section"/>
<xsl:text> JavaScript Test</xsl:text>
</xsl:variable>
<xsl:comment>=======<xsl:value-of select="translate($file,$fn,$fn-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> file: <xsl:value-of select="$file"/><xsl:text> </xsl:text></xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>=======<xsl:value-of select="translate($file,$fn,$fn-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<html><xsl:text>
</xsl:text><title><xsl:value-of select="$title"/></title>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> head </xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<head><xsl:text>
</xsl:text><script type="text/javaScript" src="{$thirdparty_js}"></script><xsl:text>
</xsl:text><script type="text/javaScript" src="{$framework_js}"></script><xsl:text>
</xsl:text><script type="text/javaScript" src="{$section_js}"></script><xsl:text>
</xsl:text><script type="text/javaScript"><xsl:text>
function onLoad() {</xsl:text>
<xsl:if test="('' != $httpHost)">
<xsl:text>
    httpHost = "</xsl:text>
<xsl:value-of select="$httpHost"/>
<xsl:text>";</xsl:text>
</xsl:if>
<xsl:if test="('' != $httpPort)">
<xsl:text>
    httpPort = "</xsl:text>
<xsl:value-of select="$httpPort"/>
<xsl:text>";</xsl:text>
</xsl:if>
<xsl:text>
    getHttpHostAlert = false;
    getHttpPortAlert = false;
    wsSetToCurrentHttpLocation();
}
</xsl:text>
</script><xsl:text>
</xsl:text></head><xsl:text>
</xsl:text><xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> body </xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<body onLoad="onLoad()"><xsl:text>
</xsl:text><h2><xsl:value-of select="$title"/></h2><xsl:text>
</xsl:text>
<form name="{$form}"><xsl:text>
</xsl:text>
<xsl:apply-templates mode="rapi_html_functions" select="./*">
<xsl:with-param name="object_id">
<xsl:call-template name="object_id">
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
<xsl:with-param name="object_name">
<xsl:call-template name="object_name">
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
<xsl:with-param name="object_path">
<xsl:call-template name="object_path">
<xsl:with-param name="object_path" select="$object_path"/>
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
</xsl:apply-templates>
</form><xsl:text>
</xsl:text>
</body><xsl:text>
</xsl:text>
</html>
</xsl:template>

</xsl:transform>

        

