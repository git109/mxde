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
<!--   File: medusaxde-create-xsl-include.xsl                               -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/26/2011                                                      -->
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

<!--==========================================================-->
<!-- Include                                                  -->
<!--==========================================================-->
<xsl:include href="medusaxde-create-xsl.xsl"/>

<!--==========================================================-->
<!-- Parameters                                               -->
<!--==========================================================-->
<xsl:param name="default_xde_form_title_what" select="'&lt;xsl:include&gt;'"/>
    
<xsl:param name="default_is_param_xsl_" select="'no'"/>
<xsl:param name="default_is_param_xsl_output" select="'no'"/>
<xsl:param name="default_is_param_xsl_include" select="'yes'"/>
<xsl:param name="default_is_param_xsl_param" select="'no'"/>
<xsl:param name="default_is_param_xsl_variable" select="'no'"/>
<xsl:param name="default_is_param_xsl_template" select="'no'"/>
<xsl:param name="default_xsl_is_stylesheet" select="'no'"/>

<!--==========================================================-->
<!-- Variables                                                -->
<!--==========================================================-->

</xsl:transform>
