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
<!--   File: restapi-to-xos-cxx-standard-parameters.xslt                    -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="file_ifndef" select="''"/>

<xsl:param name="file_hxx_extension" select="'.hpp'"/>
<xsl:param name="file_cxx_extension" select="'.cpp'"/>

<xsl:param name="include_path" select="''"/>
<xsl:param name="include_base" select="$file_base"/>
<xsl:param name="include_extension" select="$file_hxx_extension"/>
<xsl:param name="include">
<xsl:value-of select="$include_path"/>
<xsl:value-of select="$include_base"/>
<xsl:value-of select="$include_extension"/>
</xsl:param>

<xsl:param name="include_cxx_path" select="''"/>
<xsl:param name="include_cxx_base" select="$file_base"/>
<xsl:param name="include_cxx_extension" select="$file_cxx_extension"/>
<xsl:param name="include_cxx">
<xsl:value-of select="$include_cxx_path"/>
<xsl:value-of select="$include_cxx_base"/>
<xsl:value-of select="$include_cxx_extension"/>
</xsl:param>

<xsl:param name="namespace">
    <xsl:choose>
        <xsl:when test="(/*/@namespace) and ('' != /*/@namespace)">
            <xsl:value-of select="translate(/*/@namespace,$A2Z,$a2z)"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'restapp'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
<xsl:param name="namespace_2" select="''"/>
<xsl:param name="namespace_3" select="''"/>
<xsl:param name="namespace_4" select="''"/>

<xsl:param name="server_namespace" select="'server'"/>
<xsl:param name="client_namespace" select="'client'"/>
<xsl:param name="implement_namespace" select="'implement'"/>

<xsl:param name="is_server_namespace" select="'yes'"/>
<xsl:param name="is_client_namespace" select="''"/>
<xsl:param name="is_object_namespace" select="''"/>

<xsl:param name="path">
    <xsl:value-of select="'/'"/>
    <xsl:value-of select="$namespace"/>
</xsl:param>
<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

</xsl:transform>

        

