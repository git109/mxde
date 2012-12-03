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
<!--   File: medusaxde.xsl                                                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/12/2011                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde mxde medusade msxsl"
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
<xsl:include href="medusaxde-parameters.xsl"/>
<xsl:include href="medusaxde-templates.xsl"/>

<xsl:include href="medusaxde-header.xsl"/>
<xsl:include href="medusaxde-footer.xsl"/>
<xsl:include href="medusaxde-tabs.xsl"/>
<xsl:include href="medusaxde-menus.xsl"/>
<xsl:include href="medusaxde-folders.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="mxde_xsl" select="'medusaxde.xsl'"/>

<xsl:variable name="frames_src">
    <xsl:value-of select="$and_menu"/>
    <xsl:value-of select="$and_border"/>
</xsl:variable>

<xsl:variable name="header_src">
    <xsl:value-of select="$mxde_xsl"/>
    <xsl:value-of select="'?frame=header'"/>
    <xsl:value-of select="$frames_src"/>
</xsl:variable>

<xsl:variable name="footer_src">
    <xsl:value-of select="$mxde_xsl"/>
    <xsl:value-of select="'?frame=footer'"/>
    <xsl:value-of select="$frames_src"/>
</xsl:variable>

<xsl:variable name="menu_src">
    <xsl:value-of select="$mxde_xsl"/>
    <xsl:value-of select="'?frame=menu'"/>
    <xsl:value-of select="$frames_src"/>
</xsl:variable>

<xsl:variable name="folder_src">
    <xsl:value-of select="$mxde_xsl"/>
    <xsl:value-of select="'?frame=folder'"/>
    <xsl:value-of select="$frames_src"/>
</xsl:variable>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "title"                                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/4/2009                                                     -->
<!--========================================================================-->
<xsl:template name="title">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="head" select="mxde:head"/>
    <xsl:param name="title" select="mxde:header/mxde:text"/>
    <xsl:param name="for">
        <xsl:choose>
            <xsl:when test="(not ($head/mxde:title))">
                <xsl:apply-templates mode="for_text" select="$head"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:apply-templates mode="for_text" select="$head/mxde:title"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>
    <xsl:param name="using">
        <xsl:choose>
            <xsl:when test="(not ($head/mxde:title))">
                <xsl:apply-templates mode="using_text" select="$head"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:apply-templates mode="using_text" select="$head/mxde:title"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:param>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <title>
        <xsl:value-of select="$title"/>
        <xsl:if test="'' != $for">
            <xsl:value-of select="' for '"/>
            <xsl:value-of select="$for"/>
        </xsl:if>
        <xsl:if test="'' != $using">
            <xsl:value-of select="' using '"/>
            <xsl:value-of select="$using"/>
        </xsl:if>
    </title>
</xsl:template>

<!--========================================================================-->
<!-- Template: "head"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/2/2009                                                     -->
<!--========================================================================-->
<xsl:template name="head">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="stylesheet" select="xde:head/xde:stylesheet"/>
    <xsl:param name="stylesheet_type" select="$stylesheet/@type"/>
    <xsl:param name="stylesheet_href" select="$stylesheet/@href"/>

    <xsl:param name="script" select="xde:head/xde:script"/>
    <xsl:param name="script_language" select="$script/@language"/>
    <xsl:param name="script_src" select="$script/@src"/>

    <xsl:param name="tab_font" select="xde:tabs/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="footer_font" select="xde:footer/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="section_font" select="xde:menus/xde:menu-sections/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="item_font" select="xde:menus/xde:menu-items/xde:fonts[((@for = $for) or (not (@for)))]/*"/>
    <xsl:param name="folder_font" select="xde:folders/xde:fonts[((@for = $for) or (not (@for)))]/*"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <head>
        <xsl:call-template name="title">
        </xsl:call-template>
        <link rel="stylesheet" type="{$stylesheet_type}" href="{$stylesheet_href}"/>
        <style type="text/css">
            .footer
            { padding-left: 5;
              padding-right: 5; }

            .folder
            { background-position: center center;
              background-repeat: no-repeat; }

            a.tab {color: <xsl:value-of select="$tab_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.tab:hover {color: <xsl:value-of select="$tab_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.section {color: <xsl:value-of select="$section_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.section:hover {color: <xsl:value-of select="$section_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.item {color: <xsl:value-of select="$item_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.item:hover {color: <xsl:value-of select="$item_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.folder {color: <xsl:value-of select="$folder_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.folder:hover {color: <xsl:value-of select="$folder_font['on' = @hover]/@color"/>; text-decoration: underline;}

            a.footer {color: <xsl:value-of select="$footer_font['off' = @hover]/@color"/>; text-decoration: none;}
            a.footer:hover {color: <xsl:value-of select="$footer_font['on' = @hover]/@color"/>; text-decoration: underline;}
        </style>
        <script language="{$script_language}" src="{$script_src}">
        </script>
    </head>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "body"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/2/2009                                                     -->
<!--========================================================================-->
<xsl:template name="body">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="head"/>
    <body>
        <xsl:choose>
            <xsl:when test="('header' = $frame) or ('tabs' = $frame)">
                <xsl:call-template name="header"/>
            </xsl:when>
            <xsl:when test="('menu' = $frame)">
                <xsl:call-template name="menu"/>
            </xsl:when>
            <xsl:when test="('folder' = $frame)">
                <xsl:call-template name="folder"/>
            </xsl:when>
            <xsl:when test="('footer' = $frame)">
                <xsl:call-template name="footer"/>
            </xsl:when>
            <xsl:otherwise>
            </xsl:otherwise>
        </xsl:choose>
    </body>
</xsl:template>

<!--========================================================================-->
<!-- Template: "frameset"                                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/2/2009                                                     -->
<!--========================================================================-->
<xsl:template name="frameset">
    <!--========================================================================-->
    <!-- Template Parameters                                                    -->
    <!--========================================================================-->
    <xsl:param name="header_height" select="mxde:header/mxde:size/@height"/>
    <xsl:param name="footer_height" select="mxde:footer/mxde:size/@height"/>
    <xsl:param name="menu_width" select="mxde:menus/mxde:size/@width"/>
    <xsl:param name="folder_margin" select="mxde:folders/mxde:size/@margin"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <head>
        <xsl:call-template name="title">
        </xsl:call-template>
    </head>
    <frameset
		border="{$frame_border}"
		rows="{$header_height},*,{$footer_height}">

        <frame
		 name="headerFrame"
		 marginwidth="0"
		 marginheight="0"
		 noresize="yes"
		 scrolling="no"
	     src="{$header_src}"/>

        <frameset
	     cols="{$menu_width},*">

            <frame
             name="menuFrame"
             marginwidth="0"
             marginheight="0"
             noresize="yes"
             scrolling="no"
             src="{$menu_src}"/>

            <frameset
	         rows="{$folder_margin},*">

                <frame
				 name="topFolderFrame"
				 marginwidth="0"
				 marginheight="{$folder_margin}"
				 noresize="yes"
				 scrolling="no"
				 src=""/>

                <frameset
                 cols="{$folder_margin},*">

                    <frame
				     name="bottomFolderFrame"
				     marginwidth="{$folder_margin}"
				     marginheight="0"
				     noresize="yes"
				     scrolling="no"
				     src=""/>

                    <frame
				     name="folderFrame"
				     marginwidth="0"
				     marginheight="0"
				     noresize="yes"
				     scrolling="yes"
				     src="{$folder_src}"/>
                </frameset>
            </frameset>
        </frameset>

        <frame
		 name="footerFrame"
		 marginwidth="0"
		 marginheight="0"
		 noresize="yes"
		 scrolling="no"
	     src="{$footer_src}"/>
    </frameset>
</xsl:template>

<!--========================================================================-->
<!-- Template: "main"                                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 4/2/2009                                                     -->
<!--========================================================================-->
<xsl:template name="main">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:choose>
        <xsl:when test="('' != $frame)">
            <xsl:call-template name="body"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:call-template name="frameset"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

</xsl:transform>
