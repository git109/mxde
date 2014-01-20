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
<!--   File: restapi-to-xos-http-processors-cxx-parameters.xslt             -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="processor_path">
    <xsl:value-of select="''"/>
</xsl:param>
<xsl:param name="processor_index">
    <xsl:value-of select="'2'"/>
</xsl:param>
<xsl:param name="processor_namespace">
    <xsl:value-of select="$server_namespace"/>
</xsl:param>
<xsl:param name="processor_implement">
    <xsl:value-of select="$namespace"/>
    <xsl:value-of select="'::ProcessorImplement'"/>
</xsl:param>
<xsl:param name="processor_extend">
    <xsl:value-of select="$namespace"/>
    <xsl:value-of select="'::Processor'"/>
</xsl:param>

</xsl:transform>

        

