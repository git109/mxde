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
<!--   File: restapi-to-js-functions.xslt                                   -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/17/2014                                                      -->
<!--========================================================================-->
<xsl:stylesheet
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:rapi="RestApplicationProgramInterface"
 exclude-result-prefixes="xsl exsl rapi"
 version="1.0">

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_js_function_params"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_js_function_params">
<xsl:if test="(1 &lt; position())">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_params"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_params">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:value" mode "rapi_js_function_result_value"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:value" mode="rapi_js_function_result_value">
<xsl:text> = </xsl:text>
<xsl:value-of select="text()"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_result_value"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_result_value">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_js_function_result"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_js_function_result">
<xsl:text>
    var </xsl:text>
<xsl:value-of select="@name"/>
<xsl:apply-templates mode="rapi_js_function_result_value" select="rapi:value">
</xsl:apply-templates>
<xsl:text>;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_result"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_result">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_js_function_ajax_args"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_js_function_ajax_args">
<xsl:if test="(1 &lt; position())">
<xsl:text>,</xsl:text>
</xsl:if>
<xsl:text>
        '</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>': </xsl:text>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_ajax_args"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_ajax_args">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_js_function_async_result"     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_js_function_async_result">
<xsl:text>
        </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text> = true;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_async_result"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_async_result">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_js_function_sync_result"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_js_function_sync_result">
<xsl:text>
        </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text> = getAjaxRequestResponse(req);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_sync_result"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_sync_result">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:return" mode "rapi_js_function_return"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:return" mode="rapi_js_function_return">
<xsl:text>
    return </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_function_return"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_function_return">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_js_functions"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_js_functions">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
    <xsl:with-param name="namespace" select="$namespace"/>
    <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
    <xsl:with-param name="path" select="$path"/>
    <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_js_functions" select="./*">
<xsl:with-param name="namespace" select="$object_namespace"/>
<xsl:with-param name="path" select="$object_path"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_js_functions"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_js_functions">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
    <xsl:with-param name="namespace" select="$namespace"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
    <xsl:with-param name="path" select="$path"/>
    <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_js_functions" select="./*">
<xsl:with-param name="namespace" select="$object_namespace"/>
<xsl:with-param name="path" select="$object_path"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_js_functions"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_js_functions">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
    <xsl:with-param name="namespace" select="$namespace"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
    <xsl:with-param name="path" select="$path"/>
    <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="listener">
    <xsl:choose>
        <xsl:when test="(@listener and ('' != @listener))">
        <xsl:value-of select="@listener"/>
        </xsl:when>
        <xsl:otherwise>
        <xsl:value-of select="'callback'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:variable name="event">
    <xsl:choose>
        <xsl:when test="(@event and (@event != ''))">
        <xsl:value-of select="@event"/>
        </xsl:when>
        <xsl:otherwise>
        <xsl:value-of select="'Event'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:variable name="callback">
    <xsl:choose>
        <xsl:when test="(@callback and (@callback != ''))">
        <xsl:value-of select="@callback"/>
        </xsl:when>
        <xsl:otherwise>
        <xsl:value-of select="$event"/>
        <xsl:value-of select="'Callback'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:text>
///
/// function </xsl:text>
<xsl:value-of select="$object_namespace"/>
<xsl:text>
///
</xsl:text>
<xsl:value-of select="$object_namespace"/>
<xsl:text> = function(</xsl:text>
<xsl:apply-templates mode="rapi_js_function_params" select="rapi:param">
</xsl:apply-templates>
<xsl:if test="(0 &lt; count(rapi:param))">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:if test="(@listen)">
<xsl:value-of select="$listener"/>
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:text>callbacks) {
    var url = makeAjaxUrl("</xsl:text>
<xsl:value-of select="$object_root"/>
<xsl:value-of select="$object_path"/>
<xsl:text>");
    var async = false;</xsl:text>
<xsl:apply-templates mode="rapi_js_function_result" select="rapi:return">
</xsl:apply-templates>
<xsl:text>
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;</xsl:text>
 <xsl:apply-templates mode="rapi_js_function_async_result" select="rapi:return">
 </xsl:apply-templates>
<xsl:text>
    }}
    AjaxRequest.get
    ({'url': url,</xsl:text>
<xsl:if test="(0 &lt; count(rapi:param))">
<xsl:text>
      'parameters': {</xsl:text>
<xsl:apply-templates mode="rapi_js_function_ajax_args" select="rapi:param">
</xsl:apply-templates>
<xsl:text>
       },</xsl:text>
</xsl:if>
<xsl:text>
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, </xsl:text>
<xsl:choose>
<xsl:when test="(0 &lt; count(rapi:return))">true</xsl:when>
<xsl:otherwise>false</xsl:otherwise>
</xsl:choose>
<xsl:text>, callbacks); if (!async) {</xsl:text>
<xsl:apply-templates mode="rapi_js_function_sync_result" select="rapi:return">
</xsl:apply-templates>
<xsl:text>
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});</xsl:text>
<xsl:if test="(@listen)">
<xsl:text>
    if (('listen</xsl:text>
<xsl:value-of select="$event"/><xsl:text>' in </xsl:text>
<xsl:value-of select="$namespace"/><xsl:text>)) {
    </xsl:text>
<xsl:choose>
<xsl:when test="('' != @listen)">
<xsl:text>if (('Listener</xsl:text>
<xsl:value-of select="$event"/><xsl:text>' in </xsl:text>
<xsl:value-of select="$namespace"/><xsl:text>)) {
        </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.listen</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text> = new </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.Listener</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>(</xsl:text>
<xsl:value-of select="$listener"/>
<xsl:text>);
    }</xsl:text>
</xsl:when>
<xsl:otherwise>
<xsl:text>if (</xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.listen</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>) {
    if ('disconnect' in </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.listen</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>) {
        </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.listen</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>.disconnect();
        </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.listen</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text> = false;
    }}</xsl:text>
</xsl:otherwise>
</xsl:choose>
<xsl:text>}</xsl:text>
</xsl:if>
<xsl:apply-templates mode="rapi_js_function_return" select="rapi:return">
</xsl:apply-templates>
<xsl:text>
}
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_functions"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_functions">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
</xsl:template>

</xsl:stylesheet>
