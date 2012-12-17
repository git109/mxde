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
<!--   File: medusaxde-transform-parameters.xsl                             -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/13/2011                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde mxde medusade msxsl"
 version="1.0">

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="xde_template_paths_tree">
    <path></path>
    <path>c:/source/mxde/webapp/medusaxde/doc/t</path>
    <path>c:/source/mxde/webapp/medusaxde/doc/xsl</path>
    <path></path>
    <path>/home/mxde/source/mxde/webapp/medusaxde/doc/t</path>
    <path>/home/mxde/source/mxde/webapp/medusaxde/doc/xsl</path>
</xsl:variable>
<xsl:variable name="xde_template_paths" 
 select="exsl:node-set($xde_template_paths_tree)"/>

<xsl:param name="xde_document_paths_tree">
    <xsl:copy-of select="$xde_template_paths_tree"/>
</xsl:param>
<xsl:param name="xde_document_paths"
 select="exsl:node-set($xde_document_paths_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

</xsl:transform>
