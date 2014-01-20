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
<!--   File: restapi-to-html-standard-parameters.xslt                       -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="scheme" select="'http'"/>
<xsl:param name="host" select="'localhost'"/>
<xsl:param name="port" select="'8080'"/>

<xsl:param name="framework" select="'RestApp'"/>
<xsl:param name="application" select="'Application'"/>
<xsl:param name="section" select="Section"/>

<xsl:param name="framework_path" select="'../..'"/>
<xsl:param name="application_path" select="'..'"/>
<xsl:param name="section_path" select="''"/>
<xsl:param name="js_path" select="'javascript'"/>

<xsl:param name="framework_js_suffix" select="'.js'"/>
<xsl:param name="section_js_suffix" select="$framework_js_suffix"/>

<xsl:param name="thidparty_js_path">
<xsl:if test="('' != $framework_path)">
<xsl:value-of select="$framework_path"/>
<xsl:value-of select="'/'"/>
</xsl:if>
<xsl:value-of select="'thirdparty'"/>
</xsl:param>

<xsl:param name="framework_js_path">
<xsl:if test="('' != $framework_path)">
<xsl:value-of select="$framework_path"/>
<xsl:value-of select="'/'"/>
</xsl:if>
<xsl:value-of select="$js_path"/>
</xsl:param>

<xsl:param name="thirdparty_js">
<xsl:if test="('' != $thidparty_js_path)">
<xsl:value-of select="$thidparty_js_path"/>
<xsl:value-of select="'/'"/>
</xsl:if>
<xsl:value-of select="'ajaxtoolbox/'"/>
<xsl:value-of select="'AJAXRequestWithTry.js'"/>
</xsl:param>

<xsl:param name="framework_js">
<xsl:if test="('' != $framework_js_path)">
<xsl:value-of select="$framework_js_path"/>
<xsl:value-of select="'/'"/>
</xsl:if>
<xsl:value-of select="$framework"/>
<xsl:value-of select="$framework_js_suffix"/>
</xsl:param>

<xsl:param name="section_js">
<xsl:if test="('' != $section_path)">
<xsl:value-of select="$section_path"/>
<xsl:value-of select="'/'"/>
</xsl:if>
<xsl:value-of select="$section"/>
<xsl:value-of select="$section_js_suffix"/>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

</xsl:transform>

        

