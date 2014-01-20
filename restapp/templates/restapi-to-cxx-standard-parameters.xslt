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
<!--   File: restapi-to-cxx-standard-parameters.xslt                        -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/1/2014                                                       -->
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
<xsl:param name="class_interface" select="'export'"/>
<xsl:param name="class_implement" select="'InterfaceBase'"/>
<xsl:param name="class_extend" select="'ExportBase'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="class_export">
    <xsl:if test="('' != $class_interface)">
        <xsl:value-of select="'_'"/>
        <xsl:value-of select="$class_interface"/>
        <xsl:value-of select="'_class '"/>
    </xsl:if>
</xsl:variable>
<xsl:variable name="CLASS_EXPORT" select="translate($class_export,$a2z,$A2Z)"/>

<xsl:variable name="FILE_IFNDEF" select="translate($file_ifndef,$a2z,$A2Z)"/>

<xsl:variable name="NAMESPACE" select="translate($namespace,$a2z,$A2Z)"/>
<xsl:variable name="NAMESPACE_2" select="translate($namespace_2,$a2z,$A2Z)"/>
<xsl:variable name="NAMESPACE_3" select="translate($namespace_3,$a2z,$A2Z)"/>
<xsl:variable name="NAMESPACE_4" select="translate($namespace_4,$a2z,$A2Z)"/>

<xsl:variable name="IFNDEF_BASE">
<xsl:choose>
<xsl:when test="('' != $FILE_IFNDEF)">
<xsl:text>_</xsl:text>
<xsl:value-of select="$FILE_IFNDEF"/>
</xsl:when>
<xsl:otherwise>
<xsl:if test="('' != $NAMESPACE)">
<xsl:text>_</xsl:text>
<xsl:value-of select="$NAMESPACE"/>
</xsl:if>
<xsl:if test="('' != $NAMESPACE_2)">
<xsl:text>_</xsl:text>
<xsl:value-of select="$NAMESPACE_2"/>
</xsl:if>
<xsl:if test="('' != $NAMESPACE_3)">
<xsl:text>_</xsl:text>
<xsl:value-of select="$NAMESPACE_3"/>
</xsl:if>
<xsl:if test="('' != $NAMESPACE_4)">
<xsl:text>_</xsl:text>
<xsl:value-of select="$NAMESPACE_4"/>
</xsl:if>
</xsl:otherwise>
</xsl:choose>
<xsl:text>_</xsl:text>
<xsl:value-of select="$FILE_BASE"/>
</xsl:variable>
<xsl:variable name="IFNDEF">
<xsl:value-of select="$IFNDEF_BASE"/>
<xsl:value-of select="$FILE_EXTENSION"/>
</xsl:variable>

<xsl:variable name="namespace_begin">
<xsl:if test="('' != $namespace)">
<xsl:text>namespace </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text> {
</xsl:text>
</xsl:if>
<xsl:if test="('' != $namespace_2)">
<xsl:text>namespace </xsl:text>
<xsl:value-of select="$namespace_2"/>
<xsl:text> {
</xsl:text>
</xsl:if>
<xsl:if test="('' != $namespace_3)">
<xsl:text>namespace </xsl:text>
<xsl:value-of select="$namespace_3"/>
<xsl:text> {
</xsl:text>
</xsl:if>
<xsl:if test="('' != $namespace_4)">
<xsl:text>namespace </xsl:text>
<xsl:value-of select="$namespace_4"/>
<xsl:text> {
</xsl:text>
</xsl:if>
</xsl:variable>

<xsl:variable name="namespace_end">
<xsl:if test="('' != $namespace_4)">
<xsl:text>} // namespace </xsl:text>
<xsl:value-of select="$namespace_4"/>
<xsl:text>
</xsl:text>
</xsl:if>
<xsl:if test="('' != $namespace_3)">
<xsl:text>} // namespace </xsl:text>
<xsl:value-of select="$namespace_3"/>
<xsl:text>
</xsl:text>
</xsl:if>
<xsl:if test="('' != $namespace_2)">
<xsl:text>} // namespace </xsl:text>
<xsl:value-of select="$namespace_2"/>
<xsl:text>
</xsl:text>
</xsl:if>
<xsl:if test="('' != $namespace)">
<xsl:text>} // namespace </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>
</xsl:text>
</xsl:if>
</xsl:variable>

</xsl:transform>
