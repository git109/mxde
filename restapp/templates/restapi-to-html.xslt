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
<!--   File: restapi-to-html.xslt                                           -->
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
<xsl:value-of select="translate($name,$A2Z,$a2z)"/>
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
<input name="{@name}" value="{$value}">
</input>
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
<xsl:variable name="form">
<xsl:call-template name="object_name">
<xsl:with-param name="object_name" select="$oname"/>
<xsl:with-param name="name" select="'form'"/>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="action">
    <xsl:text>/</xsl:text>
    <xsl:value-of select="$opath"/>
</xsl:variable>
<xsl:comment>===========<xsl:value-of select="translate($oid,$id,$id-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> function: <xsl:value-of select="$oid"/><xsl:text> </xsl:text></xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>===========<xsl:value-of select="translate($oid,$id,$id-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<form
 name="{$form}" action="{$action}" method="{@action}"
 onsubmit="setFormMethod(getFormValue('method'),'{$form}');return setFormAction(getFormValue('scheme')+'://'+getFormValue('host')+':'+getFormValue('port')+'/'+getFormValue('submit','{$form}'),'{$form}');">
<xsl:text></xsl:text>
<xsl:apply-templates mode="rapi_html_functions" select="rapi:return">
</xsl:apply-templates>
<input type="submit" name="submit" value="{$opath}"/>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="rapi_html_functions" select="rapi:param">
<xsl:with-param name="count" select="count(rapi:param)"/>
</xsl:apply-templates>
<xsl:text>);</xsl:text><br/>
</form>
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
<xsl:call-template name="object_path">
<xsl:with-param name="object_path" select="translate(@namespace,$A2Z,$a2z)"/>
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:variable>
<xsl:variable name="title">
<xsl:value-of select="$framework"/>
<xsl:text> </xsl:text>
<xsl:value-of select="$application"/>
<xsl:text>.</xsl:text>
<xsl:value-of select="$section"/>
<xsl:text> Test</xsl:text>
</xsl:variable>
<xsl:comment>=======<xsl:value-of select="translate($file,$fn,$fn-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> file: <xsl:value-of select="$file"/><xsl:text> </xsl:text></xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>=======<xsl:value-of select="translate($file,$fn,$fn-)"/>=</xsl:comment><xsl:text>
</xsl:text>
<html>
<title><xsl:value-of select="$title"/></title>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> head </xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<head>
<script type="text/javaScript" src="{$framework_js}"></script>
</head>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<xsl:comment> body </xsl:comment><xsl:text>
</xsl:text>
<xsl:comment>======</xsl:comment><xsl:text>
</xsl:text>
<body  onLoad="getFormValueAlert=false;setFormActionAlert=false;">
<h2><xsl:value-of select="$title"/></h2>
<form name="form" action="" method=""
 onsubmit="setFormMethod(getFormValue('method'));return setFormAction(getFormValue('scheme')+'://'+getFormValue('host')+':'+getFormValue('port')+'/'+getFormValue('path')+'?'+getFormValue('query')+'#'+getFormValue('fragment'));">
<input name="scheme" value="{$scheme}"/><xsl:text>://</xsl:text>
<input name="host" value="{$host}"/><xsl:text>:</xsl:text>
<input name="port" value="{$port}"/><xsl:text>/</xsl:text>
<br/>
<input name="path" value="{$object_path}"/>
<xsl:text>?</xsl:text><input name="query" value=""/>
<xsl:text>#</xsl:text><input name="fragment" value=""/>
<br/>
method <input type="radio" name="method" value="GET" checked="checked"/><xsl:text>GET
</xsl:text>
<input type="radio" name="method" value="POST"/><xsl:text>POST
</xsl:text>
<input type="radio" name="method" value="PUT"/><xsl:text>PUT
</xsl:text>
<input type="radio" name="method" value="DELETE"/><xsl:text>DELETE
</xsl:text>
<input type="radio" name="method" value="OPTIONS"/><xsl:text>OPTIONS
</xsl:text>
<input type="radio" name="method" value="HEAD"/><xsl:text>HEAD
</xsl:text>
<input type="submit" name="submit" value="submit"/>
<br/>
</form>
<xsl:apply-templates mode="rapi_html_functions" select="./*">
<xsl:with-param name="object_path">
<xsl:call-template name="object_path">
<xsl:with-param name="object_path" select="translate(@namespace,$A2Z,$a2z)"/>
<xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:with-param>
</xsl:apply-templates>
</body>
</html>
</xsl:template>

</xsl:transform>

        

