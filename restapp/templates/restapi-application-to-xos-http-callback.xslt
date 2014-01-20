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
<!--   File: restapi-application-to-xos-http-callback.xslt                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/8/2014                                                       -->
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
<xsl:include href="../restapi-standard-parameters.xslt"/>
<xsl:include href="../restapi-standard-templates.xslt"/>
<xsl:include href="../restapi-to-cxx-standard-parameters.xslt"/>
<xsl:include href="../restapi-to-cxx-standard-templates.xslt"/>
<xsl:include href="../restapi-to-xos-cxx-standard-parameters.xslt"/>
<xsl:include href="../restapi-to-xos-cxx-standard-templates.xslt"/>

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
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_callback_interface"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_callback_interface">
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:text> virtual public </xsl:text>
    <xsl:value-of select="$class_namespace"/>
<xsl:text>Interface,
 </xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_callback_interface"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_callback_interface">
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_callback_interface" select="./*">
    <xsl:with-param name="namespace" select="$class_namespace"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_callback_interface"        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_callback_interface">
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_callback_interface" select="./*">
    <xsl:with-param name="namespace" select="$class_namespace"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_callback_interface"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_callback_interface">
<xsl:apply-templates mode="rapi_callback_interface" select="./*">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_callback_interface"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_callback_interface">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:type" mode "rapi_callback_param"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:type" mode="rapi_callback_param">
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:text>const </xsl:text>
<xsl:value-of select="$class_namespace"/>
<xsl:text>&amp; </xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_callback_param"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_callback_param">
<xsl:param name="namespace" select="''"/>
<xsl:if test="(1 &lt; position())">
<xsl:text>,
     </xsl:text>
</xsl:if>
<xsl:apply-templates mode="rapi_callback_param" select="rapi:type">
    <xsl:with-param name="namespace" select="$namespace"/>
</xsl:apply-templates>
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_callback_param"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_callback_param">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_callback_implement"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_callback_implement">
<xsl:if test="(1 &lt; position())">
<xsl:text>
        json.Append(",");</xsl:text>
</xsl:if>
<xsl:text>
        json.Append("\"</xsl:text><xsl:value-of select="@name"/><xsl:text>\":");
        json.Append(</xsl:text><xsl:value-of select="@name"/><xsl:text>);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_callback_implement"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_callback_implement">
<xsl:param name="name" select="''"/>
<xsl:param name="namespace" select="''"/>
<xsl:param name="object" select="''"/>
<xsl:variable name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when><xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:otherwise>
</xsl:choose>
</xsl:variable>
<xsl:if test="(2 &gt; position())">
<xsl:text>
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:if>
<xsl:text>    virtual void On</xsl:text>
<xsl:value-of select="$name"/>
<xsl:value-of select="$event"/>
<xsl:if test="(1 &lt; count(rapi:param))">
<xsl:text>
    </xsl:text>
</xsl:if>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="rapi_callback_param" select="rapi:param">
    <xsl:with-param name="namespace" select="$namespace"/>
</xsl:apply-templates>
<xsl:text>) {
        Json json("{\"object\":\"</xsl:text>
<xsl:value-of select="$object"/>
<xsl:text>\",\"callback\":{\"</xsl:text>
<xsl:value-of select="@name"/><xsl:text>\":{");</xsl:text>
<xsl:apply-templates mode="rapi_callback_implement" select="rapi:param">
</xsl:apply-templates>
<xsl:text>
        json.Append("}}}");
        OnEventData(json);
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_callback_implement"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_callback_implement">
<xsl:param name="name" select="''"/>
<xsl:param name="namespace" select="''"/>
<xsl:param name="object" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
        <xsl:with-param name="namespace" select="$object"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="class_name">
    <xsl:value-of select="$name"/>
    <xsl:value-of select="@name"/>
</xsl:variable>
<xsl:apply-templates mode="rapi_callback_implement" select="rapi:callback">
<xsl:with-param name="name" select="$class_name"/>
<xsl:with-param name="namespace" select="$class_namespace"/>
<xsl:with-param name="object" select="$object_namespace"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_callback_implement"        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_callback_implement">
<xsl:param name="namespace" select="''"/>
<xsl:param name="object" select="''"/>
<xsl:variable name="object_namespace">
    <xsl:call-template name="object_namespace">
        <xsl:with-param name="namespace" select="$object"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_callback_implement" select="./*">
<xsl:with-param name="namespace" select="$class_namespace"/>
<xsl:with-param name="object" select="$object_namespace"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_callback_implement"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_callback_implement">
<xsl:apply-templates mode="rapi_callback_implement" select="./*">
<xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
<xsl:with-param name="object" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_callback_implement"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_callback_implement">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_callback_process"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_callback_process">
<xsl:param name="do" select="''"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_callback_process"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_callback_process">
<xsl:param name="do" select="''"/>
<xsl:param name="namespace" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:text>
        </xsl:text><xsl:value-of select="$class_namespace"/>
<xsl:text>::GetTheInstance().Process</xsl:text><xsl:value-of select="$do"/>
<xsl:text>();</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_callback_process"          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_callback_process">
<xsl:param name="do" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_callback_process" select="./*">
    <xsl:with-param name="do" select="$do"/>
    <xsl:with-param name="namespace" select="$class_namespace"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_callback_process"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_callback_process">
<xsl:param name="do" select="''"/>
<xsl:apply-templates mode="rapi_callback_process" select="./*">
    <xsl:with-param name="do" select="$do"/>
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_callback_process"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_callback_process">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_callback_listeners"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_callback_listeners">
<xsl:param name="namespace" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:param name="do" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="@name"/>
    </xsl:call-template>
</xsl:variable>
<xsl:variable name="class_name">
    <xsl:value-of select="$name"/>
    <xsl:value-of select="@name"/>
</xsl:variable>
<xsl:variable name="event">
    <xsl:choose>
        <xsl:when test="(@event and ('' != @event))">
            <xsl:value-of select="@event"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="'Event'"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>
<xsl:text>
        </xsl:text>
<xsl:value-of select="$class_namespace"/>
<xsl:text> this</xsl:text><xsl:value-of select="$class_name"/><xsl:text> = this;
        </xsl:text><xsl:value-of select="$namespace"/>
<xsl:text>::GetTheInstance().</xsl:text><xsl:value-of select="$do"/>
<xsl:text></xsl:text><xsl:value-of select="$event"/>
<xsl:text>Listener(this</xsl:text><xsl:value-of select="$class_name"/>
<xsl:text>);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_callback_listeners"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_callback_listeners">
<xsl:param name="namespace" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:param name="do" select="''"/>
<xsl:apply-templates mode="rapi_callback_listeners" select="rapi:callback">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="@name"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="name">
        <xsl:value-of select="$name"/>
        <xsl:value-of select="@name"/>
    </xsl:with-param>
    <xsl:with-param name="do" select="$do"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_callback_listeners"        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_callback_listeners">
<xsl:param name="namespace" select="''"/>
<xsl:param name="name" select="''"/>
<xsl:param name="do" select="''"/>
<xsl:apply-templates mode="rapi_callback_listeners" select="./*">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="@name"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="name">
        <xsl:value-of select="$name"/>
        <xsl:value-of select="@name"/>
    </xsl:with-param>
    <xsl:with-param name="do" select="$do"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_callback_listeners"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_callback_listeners">
<xsl:param name="do" select="''"/>
<xsl:apply-templates mode="rapi_callback_listeners" select="./*">
<xsl:with-param name="do" select="$do"/>
<xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_callback_listeners"                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/8/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_callback_listeners">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_hxx_begin"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/6/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_hxx_begin">
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="'server'"/>
</xsl:call-template>
<xsl:text>
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class EventCallbackImplement
:</xsl:text>
<xsl:apply-templates mode="rapi_callback_interface" select="rapi:application"/>
<xsl:text> virtual public InterfaceBase {
public:
    typedef InterfaceBase Implements;
</xsl:text>
<xsl:apply-templates mode="rapi_callback_implement" select="rapi:application"/>
<xsl:text>
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void ProcessGetEvents() {</xsl:text>
<xsl:apply-templates mode="rapi_callback_process" select="rapi:application">
    <xsl:with-param name="do" select="'Get'"/>
</xsl:apply-templates>
<xsl:text>
    }
    virtual void ProcessPeekEvents() {</xsl:text>
<xsl:apply-templates mode="rapi_callback_process" select="rapi:application">
    <xsl:with-param name="do" select="'Peek'"/>
</xsl:apply-templates>
<xsl:text>
    }
</xsl:text>
<xsl:text>
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void AddEventListeners() {</xsl:text>
<xsl:apply-templates mode="rapi_callback_listeners" select="rapi:application">
    <xsl:with-param name="do" select="'Add'"/>
</xsl:apply-templates>
<xsl:text>
    }
    virtual void RemoveEventListeners() {</xsl:text>
<xsl:apply-templates mode="rapi_callback_listeners" select="rapi:application">
    <xsl:with-param name="do" select="'Remove'"/>
</xsl:apply-templates>
<xsl:text>
    }
</xsl:text>
<xsl:text>
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnEventData(const String&amp; event) {
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_hxx_end"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/6/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_hxx_end">
<xsl:text>};
</xsl:text>
<xsl:text>
</xsl:text>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="'server'"/>
</xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_include_hxx_end"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_include_hxx_end">
<xsl:param name="path" select="''"/>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name">
            <xsl:call-template name="object_path">
                <xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
                <xsl:with-param name="name" select="@name"/>
            </xsl:call-template>
        </xsl:with-param>
    </xsl:call-template>
</xsl:variable>
<xsl:text>#include "</xsl:text>
<xsl:value-of select="$object_path"/>
<xsl:value-of select="$file_hxx_extension"/><xsl:text>"
</xsl:text>
<xsl:text>
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_include_hxx_end"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_include_hxx_end">
<xsl:param name="path" select="''"/>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_include_hxx_end" select="./*">
    <xsl:with-param name="path" select="$object_path"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_include_hxx_end"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_include_hxx_end">
<xsl:param name="path" select="''"/>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<xsl:apply-templates mode="rapi_include_hxx_end" select="./*">
    <xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
</xsl:template>

</xsl:transform>
