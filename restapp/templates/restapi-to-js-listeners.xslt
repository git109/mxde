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
<!--   File: restapi-to-js-listeners.xslt                                   -->
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
<!-- Template: match "rapi:param" mode "rapi_js_listeners_params"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_js_listeners_params">
<xsl:param name="callback" select="''"/>
<xsl:if test="(1 &lt; position())">
<xsl:text> &amp;&amp; </xsl:text>
</xsl:if>
<xsl:text>('</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>' in info.callback.</xsl:text>
<xsl:value-of select="$callback"/>
<xsl:text>)</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_listeners_params"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_listeners_params">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_js_listeners_args"             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_js_listeners_args">
<xsl:param name="callback" select="''"/>
<xsl:if test="(1 &lt; position())">
<xsl:text>, </xsl:text>
</xsl:if>
<xsl:text>info.callback.</xsl:text>
<xsl:value-of select="$callback"/>
<xsl:text>.</xsl:text>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_listeners_args"                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/18/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_listeners_args">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_js_listeners"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_js_listeners">
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
<xsl:apply-templates mode="rapi_js_listeners" select="./*">
<xsl:with-param name="namespace" select="$object_namespace"/>
<xsl:with-param name="path" select="$object_path"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_js_listeners"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_js_listeners">
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
<xsl:apply-templates mode="rapi_js_listeners" select="./*">
<xsl:with-param name="namespace" select="$object_namespace"/>
<xsl:with-param name="path" select="$object_path"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_js_listeners"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_js_listeners">
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
/// </xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text> Listener</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>
///
</xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.listen</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text> = false;

</xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.Listener</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text> = function(callback) {
    this.callback = callback;
    this.connect();
}
</xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.Listener</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>.prototype.connect = function() {
    var fThis = this;
    this.ws = wsConnectEventCallback(function(evt){
        var info;
        if (wsOnMessageAlert)
            alert("evt = \""+evt.data+"\"");
        if ((info = JSON.parse(evt.data))) {
            if (('object' in info) &amp;&amp; ('callback' in info)) {
                if ((info.object == '</xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>')) {
                    if (('</xsl:text>
<xsl:value-of select="$callback"/>
<xsl:text>' in info.callback)) {</xsl:text>
<xsl:choose>
<xsl:when test="(0 &lt; count(rapi:param))">
<xsl:text>
                        if (</xsl:text>
<xsl:apply-templates mode="rapi_js_listeners_params" select="rapi:param">
<xsl:with-param name="callback" select="$callback"/>
</xsl:apply-templates>
<xsl:text>) {
                            fThis.callback(</xsl:text>
<xsl:apply-templates mode="rapi_js_listeners_args" select="rapi:param">
<xsl:with-param name="callback" select="$callback"/>
</xsl:apply-templates>
<xsl:text>);
                        } else {
                            if (wsUnexpectedEventAlert)
                            alert("unexpeceted evt = \""+evt.data+"\"");
                        }</xsl:text>
</xsl:when>
<xsl:otherwise>
<xsl:text>
                        fThis.callback();</xsl:text>
</xsl:otherwise>
</xsl:choose>
<xsl:text>
                    } else {
                        if (wsUnexpectedEventAlert)
                        alert("unexpeceted evt = \""+evt.data+"\"");
                    }
                } else {
                    if (wsUnexpectedEventAlert)
                    alert("unexpeceted evt = \""+evt.data+"\"");
                }
            }
        } else {
            alert("failed on JSON.parse(\""+evt.data+"\")");
        }
    });
}
</xsl:text>
<xsl:value-of select="$namespace"/>
<xsl:text>.Listener</xsl:text>
<xsl:value-of select="$event"/>
<xsl:text>.prototype.disconnect = function() {
    wsDisconnectEventCallback(this.ws);
}
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_js_listeners"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/17/2014                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_js_listeners">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
</xsl:template>

</xsl:stylesheet>
