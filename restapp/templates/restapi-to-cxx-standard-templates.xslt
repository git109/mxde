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
<!--   File: restapi-to-cxx-standard-templates.xslt                         -->
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
<!-- Template: "file_header"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template name="file_header">
<xsl:param name="file" select="$file"/>
<xsl:text>////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-</xsl:text><xsl:value-of select="$year"/>
<xsl:text> </xsl:text><xsl:value-of select="$organization"/><xsl:text>
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: </xsl:text><xsl:value-of select="$file"/><xsl:text>
///
/// Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
///   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
////////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "file_ifndef_begin"                                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/1/2014                                                     -->
<!--========================================================================-->
<xsl:template name="file_ifndef_begin">
<xsl:text>#if !defined(</xsl:text><xsl:value-of select="$IFNDEF"/><xsl:text>)
#define </xsl:text><xsl:value-of select="$IFNDEF"/>
<xsl:text>
</xsl:text>
<xsl:text>
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: "file_ifndef_end"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/1/2014                                                     -->
<!--========================================================================-->
<xsl:template name="file_ifndef_end">
<xsl:text>
#endif // !defined(</xsl:text><xsl:value-of select="$IFNDEF"/><xsl:text>)
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "include_hxx_begin"                                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template name="include_hxx_begin">
<xsl:if test="('' != $include)">
<xsl:text>#include "</xsl:text><xsl:value-of select="$include"/><xsl:text>"
</xsl:text>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "include_hxx_end"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template name="include_hxx_end">
<xsl:if test="('' != $include)">
<xsl:text>
</xsl:text>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "include_hxx"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template name="include_hxx">
<xsl:call-template name="include_hxx_begin"></xsl:call-template>
<xsl:call-template name="include_hxx_end"></xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: "include_cxx"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template name="include_cxx">
<xsl:if test="('' != $file_base)">
<xsl:text>#include "</xsl:text>
<xsl:value-of select="$include_cxx_path"/>
<xsl:value-of select="$file_base"/>
<xsl:value-of select="$include_cxx_extension"/>
<xsl:text>"
</xsl:text>
<xsl:text>
</xsl:text>
</xsl:if>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "namespace_begin"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 12/24/2013                                                   -->
<!--========================================================================-->
<xsl:template name="namespace_begin">
<xsl:param name="namespace" select="$namespace"/>
<xsl:param name="namespace_2" select="$namespace_2"/>
<xsl:param name="namespace_3" select="$namespace_3"/>
<xsl:param name="namespace_4" select="$namespace_4"/>
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
</xsl:template>
<!--========================================================================-->
<!-- Template: "namespace_end"                                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 12/24/2013                                                   -->
<!--========================================================================-->
<xsl:template name="namespace_end">
<xsl:param name="namespace" select="$namespace"/>
<xsl:param name="namespace_2" select="$namespace_2"/>
<xsl:param name="namespace_3" select="$namespace_3"/>
<xsl:param name="namespace_4" select="$namespace_4"/>
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
</xsl:template>

<!--========================================================================-->
<!-- Template: "class_namespace"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template name="class_namespace">
<xsl:param name="namespace" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $namespace)">
<xsl:value-of select="$namespace"/>
<xsl:text>::</xsl:text>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: "object_namespace"                                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template name="object_namespace">
<xsl:param name="namespace" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $namespace)">
<xsl:value-of select="$namespace"/>
<xsl:text>.</xsl:text>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: "object_path"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template name="object_path">
<xsl:param name="path" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:if test="('' != $path)">
<xsl:value-of select="$path"/>
<xsl:text>/</xsl:text>
</xsl:if>
<xsl:value-of select="$name"/>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:type" mode "type_name"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:type" mode="type_name">
<xsl:variable name="name">
<xsl:call-template name="string-replace-all">
<xsl:with-param name="text" select="@name"/>
<xsl:with-param name="replace" select="'.'"/>
<xsl:with-param name="by" select="'::'"/>
</xsl:call-template>
</xsl:variable>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "type_name"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="type_name">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "function_return"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="function_return">
<xsl:param name="type_prefix" select="''"/>
<xsl:param name="type_suffix" select="''"/>
<xsl:param name="name" select="@name"/>
<xsl:param name="type">
<xsl:apply-templates mode="type_name" select="rapi:type"/>
</xsl:param>
<xsl:value-of select="$type_prefix"/>
<xsl:value-of select="$type"/>
<xsl:value-of select="$type_suffix"/>
<xsl:text> </xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "function_return"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="function_return">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "function_param"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="function_param">
<xsl:param name="type_prefix" select="''"/>
<xsl:param name="type_suffix" select="''"/>
<xsl:param name="name" select="@name"/>
<xsl:param name="type">
<xsl:apply-templates mode="type_name" select="rapi:type"/>
</xsl:param>
<xsl:if test="(1 &lt; position())">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:value-of select="$type_prefix"/>
<xsl:value-of select="$type"/>
<xsl:value-of select="$type_suffix"/>
<xsl:text> </xsl:text>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "function_param"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="function_param">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "function_arg"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="function_arg">
<xsl:if test="(1 &lt; position())"><xsl:text>, </xsl:text></xsl:if>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "function_arg"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="function_arg">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:value" mode "function_result"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:value" mode="function_result">
<xsl:text> = </xsl:text>
<xsl:value-of select="text()"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "function_result"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="function_result">
<xsl:param name="type_prefix" select="''"/>
<xsl:param name="type_suffix" select="''"/>
<xsl:param name="name" select="@name"/>
<xsl:param name="type">
<xsl:apply-templates mode="type_name" select="rapi:type"/>
</xsl:param>
<xsl:text>        </xsl:text>
<xsl:value-of select="$type_prefix"/>
<xsl:value-of select="$type"/>
<xsl:value-of select="$type_suffix"/>
<xsl:text> </xsl:text>
<xsl:value-of select="$name"/>
<xsl:apply-templates mode="function_result" select="rapi:value"/>
<xsl:text>;
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:return" mode "function_result"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="function_result">
<xsl:param name="type_prefix" select="''"/>
<xsl:param name="type_suffix" select="''"/>
<xsl:param name="name" select="@name"/>
<xsl:param name="type">
<xsl:apply-templates mode="type_name" select="rapi:type"/>
</xsl:param>
<xsl:text>        </xsl:text>
<xsl:value-of select="$type_prefix"/>
<xsl:value-of select="$type"/>
<xsl:value-of select="$type_suffix"/>
<xsl:text> </xsl:text>
<xsl:value-of select="$name"/>
<xsl:apply-templates mode="function_result" select="rapi:value"/>
<xsl:text>;
        return </xsl:text>
<xsl:value-of select="$name"/>
<xsl:text>;
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "function_result"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="function_result">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:function" mode "function"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="function">
<xsl:if test="(1 = position())">
<xsl:text>
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:if>
<xsl:if test="(1 &lt; position())">
<xsl:text>
</xsl:text>
</xsl:if>
<xsl:text>    virtual </xsl:text>
<xsl:choose>
<xsl:when test="return">
<xsl:apply-templates mode="function_return" select="rapi:return"/>
</xsl:when>
<xsl:otherwise>
<xsl:text>void </xsl:text>
</xsl:otherwise>
</xsl:choose>
<xsl:value-of select="@name"/>
<xsl:if test="param"><xsl:text>
    </xsl:text>
</xsl:if>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="function_param" select="rapi:param">
<xsl:with-param name="type_prefix" select="'const '"/>
<xsl:with-param name="type_suffix" select="'&amp;'"/>
</xsl:apply-templates>
<xsl:text>)</xsl:text>
<xsl:text> {
</xsl:text>
<xsl:apply-templates mode="function_result" select="rapi:return"/>
<xsl:text>    }</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "function"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="function">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "struct_fields"                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="struct_fields">
<xsl:text>
        </xsl:text>
<xsl:apply-templates mode="type_name" select="rapi:type">
</xsl:apply-templates>
<xsl:text> </xsl:text>
<xsl:value-of select="@name"/><xsl:text>;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "struct_fields"                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="struct_fields">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "struct_param"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="struct_param">
<xsl:param name="type_prefix" select="''"/>
<xsl:param name="type_suffix" select="''"/>
<xsl:param name="name" select="@name"/>
<xsl:param name="type">
<xsl:apply-templates mode="type_name" select="rapi:type"/>
</xsl:param>
<xsl:if test="(1 &lt; position())">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:value-of select="$type_prefix"/>
<xsl:value-of select="$type"/>
<xsl:value-of select="$type_suffix"/>
<xsl:text> p_</xsl:text>
<xsl:value-of select="$name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "struct_param"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="struct_param">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "struct_construct"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="struct_construct">
<xsl:if test="(2 &gt; position())"><xsl:text>
        :</xsl:text></xsl:if>
<xsl:if test="(1 &lt; position())"><xsl:text>,</xsl:text></xsl:if>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>(p_</xsl:text><xsl:value-of select="@name"/><xsl:text>)</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "struct_construct"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="struct_construct">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "struct_copy_construct"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="struct_copy_construct">
<xsl:param name="copy" select="'copy'"/>
<xsl:if test="(2 &gt; position())"><xsl:text>
        :</xsl:text></xsl:if>
<xsl:if test="(1 &lt; position())"><xsl:text>,</xsl:text></xsl:if>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>(</xsl:text>
<xsl:value-of select="$copy"/>
<xsl:text>.</xsl:text><xsl:value-of select="@name"/><xsl:text>)</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "struct_copy_construct"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="struct_copy_construct">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:value" mode "struct_default_construct"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:value" mode="struct_default_construct">
<xsl:value-of select="text()"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "struct_default_construct"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="struct_default_construct">
<xsl:if test="(2 &gt; position())"><xsl:text>
        :</xsl:text></xsl:if>
<xsl:if test="(1 &lt; position())"><xsl:text>,</xsl:text></xsl:if>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>(</xsl:text>
<xsl:apply-templates mode="struct_default_construct" select="rapi:value">
</xsl:apply-templates>
<xsl:text>)</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "struct_default_construct"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/23/2013                                                   -->
<!--========================================================================-->
<xsl:template match="*" mode="struct_default_construct">
</xsl:template>

</xsl:transform>
