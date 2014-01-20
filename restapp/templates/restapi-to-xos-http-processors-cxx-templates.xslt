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
<!--   File: restapi-to-xos-http-processors-cxx-templates.xslt              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/7/2014                                                       -->
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
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_include_hxx"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_include_hxx">
<xsl:param name="path" select="''"/>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:apply-templates mode="rapi_include_hxx" select="./*">
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_include_hxx"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_include_hxx">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_include_cxx"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_include_cxx">
<xsl:param name="path" select="''"/>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:apply-templates mode="rapi_include_hxx" select="./*">
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_include_cxx"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_include_cxx">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_hxx"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_hxx">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:if test="('' != $namespace)">
        <xsl:value-of select="$namespace"/>
        <xsl:value-of select="'::'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_hxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_hxx"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_hxx">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_cxx"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_cxx">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:if test="('' != $namespace)">
        <xsl:value-of select="$namespace"/>
        <xsl:value-of select="'::'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_cxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_cxx"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_cxx">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:application"                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/1/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application">
<xsl:choose>
<xsl:when test="($file_hxx_extension = $file_extension)">
<xsl:call-template name="file_header"></xsl:call-template>
<xsl:call-template name="file_ifndef_begin"></xsl:call-template>
<xsl:call-template name="include_hxx_begin"></xsl:call-template>
<xsl:apply-templates mode="rapi_include_hxx" select="./*">
<xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
<xsl:call-template name="include_hxx_end"></xsl:call-template>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_hxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:call-template name="object_path">
            <xsl:with-param name="path" select="$path"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:call-template name="file_ifndef_end"></xsl:call-template>
</xsl:when>
<!--========================================================================-->
<!--========================================================================-->
<xsl:when test="($file_cxx_extension = $file_extension)">
<xsl:call-template name="file_header"></xsl:call-template>
<xsl:call-template name="include_cxx"></xsl:call-template>
<xsl:apply-templates mode="rapi_include_cxx" select="./*">
<xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_cxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:call-template name="object_path">
            <xsl:with-param name="path" select="$path"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:when>
<!--========================================================================-->
<!--========================================================================-->
<xsl:otherwise>
<xsl:call-template name="file_header"></xsl:call-template>
</xsl:otherwise>
</xsl:choose>
</xsl:template>

</xsl:transform>
