<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2011 $organization$                                 -->
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
<!--   File: medusaxde-vcproj-to-makefile.xslt                              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/22/2011                                                      -->
<!--========================================================================-->
<xsl:stylesheet
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
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../medusaxde-current-date.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="content_type" select="''"/>
<xsl:param name="organization" select="'$organization$'"/>
<xsl:param name="author" select="'$author$'"/>
<xsl:param name="year" select="$current_year"/>
<xsl:param name="date" select="$current_date"/>

<xsl:param name="project_target_type" select="''"/>
<xsl:param name="project_target" select="'target'"/>
<xsl:param name="target" select="$project_target"/>
    
<xsl:param name="PKG" select="'$(MEDUSAXDECROOT)'"/>
<xsl:param name="PRJ" select="'projects/linux/Makefile'"/>
<xsl:param name="BLD" select="'build/linux'"/>
<xsl:param name="SRC" select="'src'"/>
    
<xsl:param name="LIBS">
    <xsl:choose>
        <xsl:when test="('shared-library' = $project_target_type)">LIBSSO</xsl:when>
        <xsl:when test="('static-library' = $project_target_type)"></xsl:when>
        <xsl:otherwise>LIBS</xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="EXE">
    <xsl:choose>
        <xsl:when test="('shared-library' = $project_target_type)">SLIB</xsl:when>
        <xsl:when test="('static-library' = $project_target_type)">LIB</xsl:when>
        <xsl:otherwise>EXE</xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="exe">
    <xsl:choose>
        <xsl:when test="('shared-library' = $project_target_type)">Shared Library</xsl:when>
        <xsl:when test="('static-library' = $project_target_type)">Static Library</xsl:when>
        <xsl:otherwise>Executable</xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="ext">
    <xsl:choose>
        <xsl:when test="('shared-library' = $project_target_type)">.so</xsl:when>
        <xsl:when test="('static-library' = $project_target_type)">.a</xsl:when>
        <xsl:otherwise></xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="v">
</xsl:variable>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "html"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="html">
    <html>
        <xsl:apply-templates mode="head" select="."/>
        <xsl:apply-templates mode="body" select="."/>
    </html>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "head"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="head">
    <head>
        <style
         type="text/css">
            font.comment {color: green; font-style:italic; }
            font.commenteol {color: teal; font-style:italic; }
            font.processor {color: purple; font-weight: bolder; }
            font.keyword {color: blue; font-weight: bolder; }
            font.keywordx {color: purple; font-weight: bolder; }
            font.keywordy {color: purple; font-weight: bolder; }
            font.string {color: maroon; }
            font.char {color: red; }
        </style>
    </head>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "body"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="body">
    <body>
        <pre>
            <xsl:apply-templates mode="VisualStudioProject" select="."/>
        </pre>
    </body>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "text"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="text">
    <xsl:apply-templates mode="VisualStudioProject" select="."/>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
    
<!--========================================================================-->
<!-- Template: "keyword"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/23/2011                                                    -->
<!--========================================================================-->
<xsl:template name="keyword">
    <xsl:param name="class" select="'keyword'"/>
    <xsl:param name="text" select="''"/>
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:copy-of select="$text"/>
        </xsl:when>
        <xsl:otherwise>
            <font class="{$class}">
                <xsl:copy-of select="$text"/>
            </font>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "comment"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/23/2011                                                    -->
<!--========================================================================-->
<xsl:template name="comment">
    <xsl:param name="class" select="'comment'"/>
    <xsl:param name="text" select="''"/>
    <xsl:call-template name="keyword">
        <xsl:with-param name="class" select="$class"/>
        <xsl:with-param name="text" select="$text"/>
    </xsl:call-template>
</xsl:template>
    
<!--========================================================================-->
<!--========================================================================-->
    
<!--==========================================================-->
<!-- Template: match File                                     -->
<!--                                                          -->
<!--   Author: $author$                                       -->
<!--     Date: 1/28/2008                                      -->
<!--==========================================================-->
<xsl:template mode="Files" match="File">
<xsl:text>#</xsl:text>
<xsl:value-of select="translate(@RelativePath, '\', '/')"/>
<xsl:text> \
</xsl:text>
</xsl:template>
    
<!--==========================================================-->
<!-- Template: match                                          -->
<!--                                                          -->
<!--   Author: $author$                                       -->
<!--     Date: 1/28/2008                                      -->
<!--==========================================================-->
<xsl:template mode="Files" match="Files">
<xsl:apply-templates mode="Files" select="./*"/>
</xsl:template>
    
<!--==========================================================-->
<!-- Template: match Files                                    -->
<!--                                                          -->
<!--   Author: $author$                                       -->
<!--     Date: 1/28/2008                                      -->
<!--==========================================================-->
<xsl:template mode="Files" match="Filter">
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:apply-templates mode="Files" select="./*"/>
        </xsl:when>
        <xsl:otherwise>
            <font class="comment">
                <xsl:apply-templates mode="Files" select="./*"/>
            </font>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
    
<!--==========================================================-->
<!-- Template: match *                                        -->
<!--                                                          -->
<!--   Author: $author$                                       -->
<!--     Date: 1/28/2008                                      -->
<!--==========================================================-->
<xsl:template mode="Files" match="*">
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
#   File: Makefile
#
# Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
#   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
#
# Linux Gcc Makefile for </xsl:text>
<xsl:value-of select="$exe"/><xsl:text> </xsl:text>
<xsl:value-of select="$target"/><xsl:text> Xos Development project
########################################################################
</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
PKG = </xsl:text><xsl:value-of select="$PKG"/><xsl:text>

BLD = </xsl:text><xsl:value-of select="$BLD"/><xsl:text>
PRJ = </xsl:text><xsl:value-of select="$PRJ"/><xsl:text>
SRC = </xsl:text><xsl:value-of select="$SRC"/><xsl:text>

include $(PKG)/$(PRJ)/Makedefines

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# user defines
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
USRDEFINES = \

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# user includes
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
USRINCLUDES = \

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# targets
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$EXE"/><xsl:text>TARGET = </xsl:text>
<xsl:value-of select="$target"/><xsl:value-of select="$ext"/><xsl:text>

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> C sources
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$EXE"/><xsl:text>_C_SOURCES = \

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> C++ .cxx sources
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$EXE"/><xsl:text>_CXX_SOURCES = \

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> C++ .cpp sources
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$EXE"/><xsl:text>_CPP_SOURCES = \

</xsl:text>
<xsl:apply-templates mode="Files" select="./*"/>
<xsl:if test="('' != $LIBS)">
<xsl:text>
</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> libs
#
#</xsl:text><xsl:value-of select="$LIBS"/><xsl:text> = \
#-lsomelib
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$LIBS"/><xsl:text> = \
</xsl:text>
</xsl:if>
<xsl:text>
</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> depends
#
#</xsl:text><xsl:value-of select="$EXE"/><xsl:text>DEP = \
#$(PKG)/$(BLD)/libsomelib.a \
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$EXE"/><xsl:text>DEP = \

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> depend dirs
#
#</xsl:text><xsl:value-of select="$EXE"/><xsl:text>DEP_DIRS = \
#../libsomelib
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text><xsl:value-of select="$EXE"/><xsl:text>DEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

</xsl:text>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text>#
# </xsl:text><xsl:value-of select="$exe"/><xsl:text> depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#</xsl:text>
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "VisualStudioProject"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="VisualStudioProject">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "VisualStudioProject"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="VisualStudioProject">
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:apply-templates mode="text" select="."/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:apply-templates mode="html" select="."/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 8/22/2011                                                    -->
<!--========================================================================-->
<xsl:template match="*">
<b>Unexpected document type "</b><xsl:value-of select="name()"/><b>"</b>
</xsl:template>
</xsl:stylesheet>
