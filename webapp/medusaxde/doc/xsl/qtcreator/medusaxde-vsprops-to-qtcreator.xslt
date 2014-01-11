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
<!--   File: medusaxde-vsprops-to-qtcreator.xslt                            -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/11/2013                                                      -->
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
<xsl:include href="../visualstudio/medusaxde-vsprops-to-templates.xslt"/>
<xsl:include href="../medusaxde-string-templates.xsl"/>

<!--========================================================================-->
<!-- Template: match "UserMacro" mode "UserMacro"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/20/2011                                                   -->
<!--========================================================================-->
<xsl:template match="UserMacro" mode="UserMacro">
<xsl:variable name="Value">
    <xsl:call-template name="string-replace-all">
        <xsl:with-param name="text" select="@Value"/>
        <xsl:with-param name="replace" select="'$'"/>
        <xsl:with-param name="by" select="'$$'"/>
    </xsl:call-template>
</xsl:variable>
<xsl:value-of select="@Name"/>
<xsl:text> = </xsl:text>
<xsl:value-of select="translate($Value, '\();', '/{} ')"/>
<xsl:text>
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "UserMacro"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/20/2011                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="UserMacro">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "VisualStudioPropertySheet" mode "VisualStudioPropertySheet"-->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/11/2013                                                    -->
<!--========================================================================-->
<xsl:template match="VisualStudioPropertySheet" mode="VisualStudioPropertySheet">
<xsl:call-template name="file"/>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>
########################################################################
# QMake definitions form VisualStudioPropertySheet
# ...
########################################################################
</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates mode="UserMacro" select="./*"/>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>########################################################################
# ...
# QMake definitions form VisualStudioPropertySheet
########################################################################
</xsl:text>
</xsl:with-param>
</xsl:call-template>
</xsl:template>
    
</xsl:transform>
