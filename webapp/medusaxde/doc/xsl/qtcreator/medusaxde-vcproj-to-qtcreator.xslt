<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2013 $organization$                                 -->
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
<!--   File: medusaxde-vcproj-to-qtcreator.xslt                             -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 6/7/2013                                                       -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:medusaxde="Medusa-Xos-Development-Environment"
 exclude-result-prefixes="xsl exsl xalan msxsl xde mxde medusade medusaxde"
 version="1.0">

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../visualstudio/medusaxde-vcproj-to.xslt"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="file_name">
    <xsl:value-of select="$target"/>
    <xsl:value-of select="'.pro'"/>
</xsl:param>

<xsl:param name="template">
    <xsl:choose>
        <xsl:when test="('shared-library' = $project_target_type)">lib</xsl:when>
        <xsl:when test="('static-library' = $project_target_type)">lib</xsl:when>
        <xsl:otherwise>exe</xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="config">
    <xsl:choose>
        <xsl:when test="('shared-library' = $project_target_type)"></xsl:when>
        <xsl:when test="('static-library' = $project_target_type)">
            <xsl:text>CONFIG += staticlib

</xsl:text>
        </xsl:when>
        <xsl:otherwise></xsl:otherwise>
    </xsl:choose>
</xsl:param>
<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "File" mode "Files"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="File" mode="Files">
<xsl:text></xsl:text>
<xsl:value-of select="translate(@RelativePath, '\', '/')"/>
<xsl:text> \
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "Files" mode "Files"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="Files" mode="Files">
<xsl:apply-templates mode="Files" select="./*"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "Filter" mode "Files"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="Filter" mode="Files">
<xsl:apply-templates mode="Files" select="./*"/>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "VisualStudioProject" mode "VisualStudioProject"       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="VisualStudioProject" mode="VisualStudioProject">
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>########################################################################
# Copyright (c) 1988-</xsl:text><xsl:value-of select="$year"/><xsl:text> </xsl:text><xsl:value-of select="$organization"/><xsl:text>
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: </xsl:text><xsl:value-of select="$file_name"/><xsl:text>
#
# Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
#   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
#
# QtCreator project for </xsl:text>
<xsl:value-of select="$exe"/><xsl:text> </xsl:text>
<xsl:value-of select="$target"/><xsl:text>
########################################################################
</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>TARGET = </xsl:text><xsl:value-of select="$target"/><xsl:text>

TEMPLATE = </xsl:text><xsl:value-of select="$template"/><xsl:text>

INCLUDEPATH += \

DEFINES += \

</xsl:text><xsl:value-of select="$config"/><xsl:text>SOURCES += \
</xsl:text>
<xsl:apply-templates mode="Files" select="./*"/><xsl:text>
</xsl:text>
</xsl:template>
    
</xsl:transform>
