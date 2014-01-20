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
<!--   File: restapi-to-xos-http-processors-implement-cxx.xslt              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/2/2014                                                       -->
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
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output method="text"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../../restapi-standard-parameters.xslt"/>
<xsl:include href="../../restapi-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-cxx-standard-parameters.xslt"/>
<xsl:include href="../../restapi-to-cxx-standard-templates.xslt"/>
<xsl:include href="../../restapi-to-xos-cxx-standard-parameters.xslt"/>
<xsl:include href="../../restapi-to-xos-http-processors-cxx-parameters.xslt"/>
<xsl:include href="../../restapi-to-xos-http-processors-cxx-templates.xslt"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:type" mode "rapi_function_process_param"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:type" mode="rapi_function_process_param">
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_function_process_param"        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_function_process_param">
<xsl:text>, const </xsl:text>
<xsl:apply-templates mode="rapi_function_process_param" select="rapi:type">
</xsl:apply-templates>
<xsl:text>&amp; </xsl:text>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_function_process_param"       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_function_process_param">
<xsl:text>, </xsl:text>
<xsl:apply-templates mode="rapi_function_process_param" select="rapi:type">
</xsl:apply-templates>
<xsl:text>&amp; </xsl:text>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_process_param"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_process_param">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_function_process_arg"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_function_process_arg">
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_function_process_arg"          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_function_process_arg">
<xsl:if test="(1 &lt; position())">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_process_arg"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_process_arg">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_functions"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_functions">
<xsl:param name="namespace" select="''"/>
<xsl:param name="object" select="''"/>
<xsl:param name="count" select="''"/>
<xsl:text>
typedef </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>::</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>Processor </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>ProcessorExtend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class </xsl:text>
<xsl:value-of select="$CLASS_EXPORT"/>
<xsl:value-of select="@name"/>
<xsl:text>Processor: public </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>ProcessorExtend {
public:
    typedef </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>ProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    </xsl:text><xsl:value-of select="@name"/><xsl:text>Processor(const String&amp; path): Extends(path) {
    }
    </xsl:text><xsl:value-of select="@name"/><xsl:text>Processor() {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool&amp; processed</xsl:text>
<xsl:apply-templates mode="rapi_function_process_param" select="rapi:return">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_process_param" select="rapi:param">
</xsl:apply-templates>
<xsl:text>) {
        XOS_LOG_TRACE("in...");
        </xsl:text><xsl:value-of select="$object"/>
<xsl:text>&amp; the</xsl:text><xsl:value-of select="$object"/>
<xsl:text> = </xsl:text><xsl:value-of select="$object"/>
<xsl:text>::GetTheInstance();
        </xsl:text>
<xsl:apply-templates mode="rapi_function_process_arg" select="rapi:return">
</xsl:apply-templates>
<xsl:text> = the</xsl:text><xsl:value-of select="$object"/>
<xsl:text>.</xsl:text><xsl:value-of select="@name"/><xsl:text>(</xsl:text>
<xsl:apply-templates mode="rapi_function_process_arg" select="rapi:param">
</xsl:apply-templates>
<xsl:text>);
        XOS_LOG_TRACE("...out");
    }
};
</xsl:text>
<xsl:if test="($count = position())">
<xsl:text>
</xsl:text>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_include_hxx"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_include_hxx">
<xsl:param name="path" select="''"/>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:text>#include "</xsl:text>
<xsl:value-of select="$object_path"/><xsl:text>/</xsl:text>
<xsl:value-of select="@name"/>
<xsl:value-of select="$include_extension"/><xsl:text>"
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_hxx"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_hxx">
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:if test="('' != $namespace)">
        <xsl:value-of select="$namespace"/>
        <xsl:value-of select="'::'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$processor_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_functions" select="rapi:function">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
        <xsl:value-of select="'::'"/>
        <xsl:value-of select="$processor_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="object">
        <xsl:value-of select="@name"/>
    </xsl:with-param>
    <xsl:with-param name="count">
        <xsl:value-of select="count(rapi:function)"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$processor_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_functions_cxx"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_functions_cxx">
<xsl:param name="processor_index" select="''"/>
<xsl:param name="processor_path" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:param name="count" select="''"/>
<xsl:if test="(('' = $processor_index) and ('' = $processor_path)) or (('' != $processor_index) and (('' != $processor_path) and ($path != $processor_path)))">
<xsl:if test="(2 &gt; position())">
<xsl:text>
</xsl:text>
</xsl:if>
<xsl:text>static </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>Processor the_</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>Processor</xsl:text>
<xsl:if test="('' != $processor_index) and ('' != $processor_path)">
<xsl:value-of select="$processor_index"/>
<xsl:text>("</xsl:text>
<xsl:value-of select="$processor_path"/>
<xsl:value-of select="'/'"/>
<xsl:value-of select="@name"/>
<xsl:text>")</xsl:text>
</xsl:if>
<xsl:text>;
</xsl:text>
<xsl:if test="($count = position())">
<xsl:text>
</xsl:text>
</xsl:if>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions_cxx"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions_cxx">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_cxx"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_cxx">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:if test="('' != $namespace)">
        <xsl:value-of select="$namespace"/>
        <xsl:value-of select="'::'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="translate(@name,$A2Z,$a2z)"/>
</xsl:variable>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$processor_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_functions_cxx" select="rapi:function">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
        <xsl:value-of select="'::'"/>
        <xsl:value-of select="$processor_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
    <xsl:with-param name="count">
        <xsl:value-of select="count(rapi:function)"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_functions_cxx" select="rapi:function">
    <xsl:with-param name="processor_path" select="$processor_path"/>
    <xsl:with-param name="processor_index" select="$processor_index"/>
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
        <xsl:value-of select="'::'"/>
        <xsl:value-of select="$processor_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
    <xsl:with-param name="count">
        <xsl:value-of select="count(rapi:function)"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$implement_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$processor_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>

</xsl:transform>
