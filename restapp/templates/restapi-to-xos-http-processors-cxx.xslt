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
<!--   File: restapi-to-xos-http-processors-cxx.xslt                        -->
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
<!-- Template: match "rapi:param" mode "rapi_function_process_arg"          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_function_process_arg">
<xsl:text>, </xsl:text>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_function_process_arg"          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_function_process_arg">
<xsl:text>, </xsl:text>
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
<!-- Template: match "rapi:param" mode "rapi_function_param_get"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_function_param_get">
<xsl:text>
        request.Get(</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>, "</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>");
        XOS_LOG_TRACE("\"</xsl:text>
<xsl:value-of select="@name"/><xsl:text>\" = " &lt;&lt; </xsl:text>
<xsl:value-of select="@name"/><xsl:text>);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_param_get"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_param_get">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_function_return_put"          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_function_return_put">
<xsl:text>
        XOS_LOG_TRACE("\"</xsl:text>
<xsl:value-of select="@name"/><xsl:text>\" = " &lt;&lt; </xsl:text>
<xsl:value-of select="@name"/><xsl:text>);
        response.Put("</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>", </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_return_put"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_return_put">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:type" mode "rapi_function_param"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:type" mode="rapi_function_param">
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:value" mode "rapi_function_param"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:value" mode="rapi_function_param">
<xsl:text> = </xsl:text>
<xsl:value-of select="."/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_function_param"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_function_param">
<xsl:text>
        </xsl:text>
<xsl:apply-templates mode="rapi_function_param" select="rapi:type">
</xsl:apply-templates>
<xsl:text> </xsl:text>
<xsl:value-of select="@name"/>
<xsl:apply-templates mode="rapi_function_param" select="rapi:value">
</xsl:apply-templates>
<xsl:text>;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_param"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_param">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_function_return"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_function_return">
<xsl:text>
        </xsl:text>
<xsl:apply-templates mode="rapi_function_param" select="rapi:type">
</xsl:apply-templates>
<xsl:text> </xsl:text>
<xsl:value-of select="@name"/>
<xsl:apply-templates mode="rapi_function_param" select="rapi:value">
</xsl:apply-templates>
<xsl:text>;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_return"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_return">
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
<xsl:param name="path" select="''"/>
<xsl:param name="count" select="0"/>
<xsl:variable name="object_path">
    <xsl:if test="('' != $path)">
        <xsl:value-of select="$path"/>
        <xsl:value-of select="'/'"/>
    </xsl:if>
    <xsl:value-of select="@name"/>
</xsl:variable>
<xsl:if test="(2 &gt; position())">
<xsl:text>
typedef </xsl:text><xsl:value-of select="$processor_implement"/><xsl:text> ProcessorImplement;
typedef </xsl:text><xsl:value-of select="$processor_extend"/><xsl:text> ProcessorExtend;
</xsl:text>
</xsl:if>
<xsl:text>
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class </xsl:text>
<xsl:value-of select="$CLASS_EXPORT"/>
<xsl:value-of select="@name"/>
<xsl:text>Processor
: virtual public ProcessorImplement, public ProcessorExtend {
public:
    typedef ProcessorImplement Implements;
    typedef ProcessorExtend Extends;
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    </xsl:text><xsl:value-of select="@name"/><xsl:text>Processor(const String&amp; path): Extends(path) {
    }
    </xsl:text><xsl:value-of select="@name"/><xsl:text>Processor(): Extends(ThePath()) {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual bool Any
    (Response&amp; response, const Request&amp; request, const String&amp; method) {
        XOS_LOG_TRACE("in...");
        bool processed = true;</xsl:text>
<xsl:apply-templates mode="rapi_function_return" select="rapi:return">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_param" select="rapi:param">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_param_get" select="rapi:param">
</xsl:apply-templates><xsl:text>
        Process(processed</xsl:text>
<xsl:apply-templates mode="rapi_function_process_arg" select="rapi:return">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_process_arg" select="rapi:param">
</xsl:apply-templates>
<xsl:text>);</xsl:text>
<xsl:apply-templates mode="rapi_function_return_put" select="rapi:return">
</xsl:apply-templates>
<xsl:text>
        XOS_LOG_TRACE("...out");
        return processed;
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    virtual void Process(bool&amp; processed</xsl:text>
<xsl:apply-templates mode="rapi_function_process_param" select="rapi:return">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_process_param" select="rapi:param">
</xsl:apply-templates>
<xsl:text>) {
    }
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    static String&amp; ThePath() {
        static String thePath("</xsl:text><xsl:value-of select="$object_path"/><xsl:text>");
        return thePath;
    }
};
</xsl:text>
<xsl:if test="(position() = $count)">
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
<!-- Template: match "rapi:object" mode "rapi_hxx"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_hxx">
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
<xsl:apply-templates mode="rapi_functions" select="rapi:function">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
    <xsl:with-param name="count">
        <xsl:value-of select="count(rapi:function)"/>
    </xsl:with-param>
</xsl:apply-templates>
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
<xsl:apply-templates mode="rapi_cxx" select="rapi:function">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="$processor_namespace"/>
</xsl:call-template>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>

</xsl:transform>
