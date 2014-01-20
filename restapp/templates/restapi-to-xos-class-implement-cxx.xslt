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
<!--   File: restapi-to-xos-class-implement-cxx.xslt                        -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/3/2014                                                       -->
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
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output method="text"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../../restapi-standard-parameters.xslt"/>
<xsl:include href="../../restapi-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-cxx-standard-parameters.xslt"/>
<xsl:include href="../../restapi-to-cxx-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-xos-cxx-standard-parameters.xslt"/>
<xsl:include href="../../restapi-to-xos-cxx-standard-templates.xslt"/>

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
<!-- Template: match "rapi:function" mode "rapi_functions"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_functions">
<xsl:if test="(2 &gt; position())">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:if>
<xsl:apply-templates mode="rapi_function_begin" select=".">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_end" select=".">
</xsl:apply-templates>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_object_begin"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/7/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_object_begin">
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
<xsl:choose>
<xsl:when test="('yes' = $is_object_namespace)">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:when>
<xsl:otherwise>
    <xsl:value-of select="$namespace"/>
</xsl:otherwise>
</xsl:choose>
</xsl:variable>
<xsl:variable name="class_extend">
<xsl:call-template name="class_namespace">
    <xsl:with-param name="namespace" select="$class_namespace"/>
    <xsl:with-param name="name" select="@name"/>
</xsl:call-template>
</xsl:variable>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' != $is_object_namespace)">
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$server_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:text>
typedef </xsl:text><xsl:value-of select="$class_extend"/>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>Extend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class </xsl:text><xsl:value-of select="$CLASS_EXPORT"/><xsl:text></xsl:text>
<xsl:value-of select="@name"/><xsl:text>: public </xsl:text>
<xsl:value-of select="@name"/>Extend<xsl:text> {
public:
    typedef </xsl:text><xsl:value-of select="@name"/><xsl:text>Extend Extends;
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_object_end"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/7/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_object_end">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
protected:
};
</xsl:text>
<xsl:text>
</xsl:text>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$server_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' != $is_object_namespace)">
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_cxx_begin"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_cxx_object_begin">
<xsl:if test="('yes' != $is_object_namespace)">
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$server_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_cxx_end"                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_cxx_object_end">
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$server_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' != $is_object_namespace)">
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi" select="./*">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$server_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:text>
static </xsl:text><xsl:value-of select="@name"/>
<xsl:text> the_</xsl:text><xsl:value-of select="@name"/><xsl:text>;
</xsl:text>
<xsl:text>
</xsl:text>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$server_namespace"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' != $is_object_namespace)">
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
<!--========================================================================-->
<!--========================================================================-->
<xsl:text>
</xsl:text><xsl:value-of select="@name"/>
<xsl:text>&amp; </xsl:text><xsl:value-of select="@name"/>
<xsl:text>::GetTheInstance() {
    return </xsl:text>
<xsl:if test="('yes' != $is_object_namespace)">
<xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
<xsl:text>::</xsl:text>
</xsl:if>
<xsl:value-of select="$server_namespace"/>
<xsl:text>::</xsl:text><xsl:value-of select="$implement_namespace"/>
<xsl:text>::the_</xsl:text><xsl:value-of select="@name"/><xsl:text>;
}
</xsl:text>
<xsl:text>
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_begin"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/6/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_begin">
<xsl:call-template name="file_header">
<xsl:with-param name="file">
<xsl:value-of select="$file_base"/>
<xsl:value-of select="'_instance'"/>
<xsl:value-of select="$file_cxx_extension"/>
</xsl:with-param>
<!--========================================================================-->
<!--========================================================================-->
</xsl:call-template>
<xsl:call-template name="include_cxx">
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
<xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_end"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/6/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_end">
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
<xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>

</xsl:transform>
