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
<!--   File: restapi-to-xos-class-cxx.xslt                                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 1/3/2014                                                       -->
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
<xsl:include href="../../restapi-to-xos-cxx-standard-templates.xslt"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="callback" select="'Callback'"/>
<xsl:param name="listener" select="'Listener'"/>
<xsl:param name="message" select="'Message'"/>
<xsl:param name="queue" select="'Queue'"/>
<xsl:param name="process" select="'Process'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:type" mode "rapi_types"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:type" mode="rapi_types">
<xsl:if test="(2 &gt; position())">
<xsl:text>
</xsl:text>
</xsl:if>
<xsl:text>    typedef </xsl:text>
<xsl:apply-templates mode="type_name" select="rapi:type">
</xsl:apply-templates>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>;
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:value" mode "rapi_enums"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:value" mode="rapi_enums">
<xsl:if test="(1 &lt; position())">
<xsl:text>,</xsl:text>
</xsl:if>
<xsl:text>
        </xsl:text>
<xsl:value-of select="@name"/>
<xsl:if test="('' != text())">
<xsl:text> = </xsl:text>
<xsl:value-of select="text()"/>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:enum" mode "rapi_enums"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:enum" mode="rapi_enums">
<xsl:text>
    typedef int </xsl:text><xsl:value-of select="@name"/><xsl:text>;
    enum {</xsl:text>
<xsl:apply-templates mode="rapi_enums" select="rapi:value">
</xsl:apply-templates>
<xsl:text>
    };
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_struct_fields_to"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_struct_fields_to">
<xsl:text>
            to.Put("</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>", </xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:struct" mode "rapi_structs"                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:struct" mode="rapi_structs">
<xsl:variable name="param_with_value" select="rapi:param[(0 &lt; count(rapi:value))]"/>
<xsl:text>
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    struct </xsl:text><xsl:value-of select="$CLASS_EXPORT"/>
<xsl:text></xsl:text><xsl:value-of select="@name"/>
<xsl:text> {</xsl:text>
<xsl:apply-templates mode="struct_fields" select="rapi:param">
</xsl:apply-templates>
<xsl:text>
        </xsl:text><xsl:value-of select="@name"/><xsl:text>(</xsl:text>
<xsl:apply-templates mode="struct_param" select="rapi:param">
</xsl:apply-templates>
        <xsl:text>)</xsl:text>
<xsl:apply-templates mode="struct_construct" select="rapi:param">
</xsl:apply-templates>
                <xsl:text> {
        }
        </xsl:text><xsl:value-of select="@name"/><xsl:text>(const </xsl:text>
<xsl:value-of select="@name"/><xsl:text>&amp; copy)</xsl:text>
<xsl:apply-templates mode="struct_copy_construct" select="rapi:param">
</xsl:apply-templates>
                <xsl:text> {
        }
        </xsl:text><xsl:value-of select="@name"/><xsl:text>()</xsl:text>
<xsl:apply-templates mode="struct_default_construct" select="$param_with_value">
</xsl:apply-templates>
                <xsl:text> {
        }
        Variant&amp; To(Variant&amp; to) const {</xsl:text>
<xsl:apply-templates mode="rapi_struct_fields_to" select="rapi:param">
</xsl:apply-templates>
<xsl:text>
            return to;
        }
        String&amp; To(String&amp; to) const {
            Variant from;
            To(from);
            from.To(to);
            return to;
        }
        operator String() const {
            String to;
            To(to);
            return to;
        }
    };
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_callbacks"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_callbacks">
<xsl:param name="name" select="''"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:text>
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    class </xsl:text><xsl:value-of select="@name"/><xsl:text>Interface: virtual public InterfaceBase {
    public:
        virtual void On</xsl:text>
<xsl:value-of select="$name"/>
<xsl:value-of select="$event"/>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="function_param" select="rapi:param">
<xsl:with-param name="type_prefix" select="'const '"/>
<xsl:with-param name="type_suffix" select="'&amp;'"/>
</xsl:apply-templates>
<xsl:text>) {
        }
        void operator()(</xsl:text>
 <xsl:apply-templates mode="function_param" select="rapi:param">
 <xsl:with-param name="type_prefix" select="'const '"/>
 <xsl:with-param name="type_suffix" select="'&amp;'"/>
 </xsl:apply-templates>
 <xsl:text>) {
            On</xsl:text>
<xsl:value-of select="$name"/>
<xsl:value-of select="$event"/>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="function_arg" select="rapi:param">
</xsl:apply-templates>
<xsl:text>);
        }
    };
    typedef </xsl:text><xsl:value-of select="@name"/>
<xsl:text>Interface* </xsl:text><xsl:value-of select="@name"/><xsl:text>;
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_functions"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_functions">
<xsl:if test="(2 &gt; position())">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:if>
<xsl:apply-templates mode="rapi_function_begin" select=".">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_function_end" select=".">
</xsl:apply-templates>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_functions_begin"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_functions_begin">
<xsl:text>
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    </xsl:text><xsl:value-of select="@name"/><xsl:text>() {
    }
    virtual ~</xsl:text><xsl:value-of select="@name"/><xsl:text>() {
    }
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_on_event_body"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_on_event_body">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:variable name="_event" select="translate($event,$A2Z,$a2z)"/>
<xsl:text>
        </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/>
<xsl:text> m(</xsl:text>
<xsl:apply-templates mode="function_arg" select="rapi:param"/>
<xsl:text>);
        m_</xsl:text><xsl:value-of select="$_event"/>
<xsl:text></xsl:text><xsl:value-of select="$queue"/>
<xsl:text>.</xsl:text><xsl:value-of select="$do"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/><xsl:text>(m, true);</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_dispatch_event_body"        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_dispatch_event_body">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:variable name="_event" select="translate($event,$A2Z,$a2z)"/>
<xsl:text>
        Locker lockr(m_</xsl:text><xsl:value-of select="$_event"/><xsl:value-of select="$listener"/><xsl:text>s);
        </xsl:text><xsl:value-of select="$event"/><xsl:value-of select="$listener"/><xsl:text>s::iterator begin = m_</xsl:text>
<xsl:value-of select="$_event"/><xsl:value-of select="$listener"/><xsl:text>s.begin();
        </xsl:text><xsl:value-of select="$event"/><xsl:value-of select="$listener"/><xsl:text>s::iterator end = m_</xsl:text>
<xsl:value-of select="$_event"/><xsl:value-of select="$listener"/><xsl:text>s.end();
        </xsl:text><xsl:value-of select="$event"/><xsl:value-of select="$listener"/><xsl:text>s::iterator i;
        for (i = begin; i != end; ++i) {
            </xsl:text><xsl:value-of select="$event"/><xsl:value-of select="$callback"/><xsl:text> cb;
            if ((cb = (</xsl:text><xsl:value-of select="$event"/><xsl:value-of select="$callback"/><xsl:text>)(*i))) {
                (*cb)(</xsl:text><xsl:apply-templates mode="function_arg" select="rapi:param"/><xsl:text>);
            }
        }</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:param" mode "rapi_recieve_event_body"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:param" mode="rapi_receive_event_body">
<xsl:text>
            </xsl:text><xsl:value-of select="@name"/><xsl:text> = m.</xsl:text>
<xsl:value-of select="@name"/><xsl:text>;</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_recieve_event_body"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_receive_event_body">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:variable name="_event" select="translate($event,$A2Z,$a2z)"/>
<xsl:text>
        </xsl:text><xsl:value-of select="$event"/><xsl:value-of select="$message"/>
<xsl:text> m(</xsl:text><xsl:apply-templates mode="function_arg" select="rapi:param"/><xsl:text>);
        if ((m_</xsl:text><xsl:value-of select="$_event"/><xsl:value-of select="$queue"/>
<xsl:text>.</xsl:text><xsl:value-of select="$do"/><xsl:value-of select="$message"/><xsl:text>(m, true))) {</xsl:text>
<xsl:apply-templates mode="rapi_receive_event_body" select="rapi:param">
    <xsl:with-param name="do" select="$do"/>
</xsl:apply-templates>
<xsl:text>
            success = true;
        }</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_process_event_body"         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_process_event_body">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:variable name="_event" select="translate($event,$A2Z,$a2z)"/>
<xsl:text>
</xsl:text>
<xsl:apply-templates mode="function_result" select="rapi:param"/>
<xsl:text>        if ((</xsl:text><xsl:value-of select="$do"/><xsl:value-of select="$event"/>
<xsl:text>(</xsl:text><xsl:apply-templates mode="function_arg" select="rapi:param"/><xsl:text>))) {
            Dispatch</xsl:text><xsl:value-of select="$event"/>
<xsl:text>(</xsl:text><xsl:apply-templates mode="function_arg" select="rapi:param"/><xsl:text>);
            success = true;
        }</xsl:text>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_send_event"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_send_event">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:param name="body" select="''"/>
<xsl:text>    virtual bool </xsl:text>
<xsl:value-of select="$do"/>
<xsl:value-of select="$event"/>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="function_param" select="rapi:param">
<xsl:with-param name="type_prefix" select="'const '"/>
<xsl:with-param name="type_suffix" select="'&amp;'"/>
</xsl:apply-templates>
<xsl:text>) {
        bool success = false;</xsl:text>
<xsl:value-of select="$body"/>
<xsl:text>
        return success;
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_receive_event"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_receive_event">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:param name="body" select="''"/>
<xsl:text>    virtual bool </xsl:text>
<xsl:value-of select="$do"/>
<xsl:value-of select="$event"/>
<xsl:text>(</xsl:text>
<xsl:apply-templates mode="function_param" select="rapi:param">
<xsl:with-param name="type_prefix" select="''"/>
<xsl:with-param name="type_suffix" select="'&amp;'"/>
</xsl:apply-templates>
<xsl:text>) {
        bool success = false;</xsl:text>
<xsl:value-of select="$body"/>
<xsl:text>
        return success;
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_process_event"              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_process_event">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:param name="body" select="''"/>
<xsl:text>    virtual bool </xsl:text>
<xsl:value-of select="$process"/>
<xsl:value-of select="$do"/>
<xsl:value-of select="$event"/>
<xsl:text>(</xsl:text>
<xsl:text>) {
        bool success = false;</xsl:text>
<xsl:value-of select="$body"/>
<xsl:text>
        return success;
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_events"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_events">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
</xsl:text>
<xsl:apply-templates mode="rapi_send_event" select=".">
    <xsl:with-param name="do" select="'On'"/>
    <xsl:with-param name="body">
        <xsl:apply-templates mode="rapi_on_event_body" select=".">
            <xsl:with-param name="do" select="'Post'"/>
        </xsl:apply-templates>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_send_event" select=".">
    <xsl:with-param name="do" select="'Dispatch'"/>
    <xsl:with-param name="body">
        <xsl:apply-templates mode="rapi_dispatch_event_body" select=".">
            <xsl:with-param name="do" select="'Dispatch'"/>
        </xsl:apply-templates>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_receive_event" select=".">
    <xsl:with-param name="do" select="'Get'"/>
    <xsl:with-param name="body">
        <xsl:apply-templates mode="rapi_receive_event_body" select=".">
            <xsl:with-param name="do" select="'Get'"/>
        </xsl:apply-templates>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_receive_event" select=".">
    <xsl:with-param name="do" select="'Peek'"/>
    <xsl:with-param name="body">
        <xsl:apply-templates mode="rapi_receive_event_body" select=".">
            <xsl:with-param name="do" select="'Peek'"/>
        </xsl:apply-templates>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_process_event" select=".">
    <xsl:with-param name="do" select="'Get'"/>
    <xsl:with-param name="body">
        <xsl:apply-templates mode="rapi_process_event_body" select=".">
            <xsl:with-param name="do" select="'Get'"/>
        </xsl:apply-templates>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_process_event" select=".">
    <xsl:with-param name="do" select="'Peek'"/>
    <xsl:with-param name="body">
        <xsl:apply-templates mode="rapi_process_event_body" select=".">
            <xsl:with-param name="do" select="'Peek'"/>
        </xsl:apply-templates>
    </xsl:with-param>
</xsl:apply-templates>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_process"                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_process">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:text>
        if (!(</xsl:text>
<xsl:value-of select="$process"/>
<xsl:value-of select="$do"/>
<xsl:value-of select="$event"/>
<xsl:text>())) {
            success = false;
        }</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_events_process"            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_events_process">
<xsl:param name="do" select="'Do'"/>
<xsl:text>    virtual bool </xsl:text>
<xsl:value-of select="$process"/>
<xsl:value-of select="$do"/>
<xsl:text>() {
        bool success = true;</xsl:text>
<xsl:apply-templates mode="rapi_process" select="rapi:callback">
<xsl:with-param name="do" select="$do"/>
</xsl:apply-templates>
<xsl:text>
        return success;
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_events_process_begin"      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_events_process_begin">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
</xsl:text>
<xsl:apply-templates mode="rapi_events_process" select=".">
<xsl:with-param name="do" select="'Get'"/>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_events_process" select=".">
<xsl:with-param name="do" select="'Peek'"/>
</xsl:apply-templates>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_listener"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_listener">
<xsl:param name="do" select="'Do'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:text>    virtual bool </xsl:text>
<xsl:value-of select="$do"/>
<xsl:value-of select="$event"/>
<xsl:value-of select="$listener"/>
<xsl:text>(</xsl:text>
<xsl:value-of select="@name"/>
<xsl:text>&amp; callback) {
        bool success = true;
        m_</xsl:text>
<xsl:value-of select="translate($event,$A2Z,$a2z)"/>
<xsl:value-of select="$listener"/>
<xsl:text>s.</xsl:text>
<xsl:value-of select="$do"/>
<xsl:text>(callback);
        return success;
    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_listeners"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_listeners">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
</xsl:text>
<xsl:apply-templates mode="rapi_listener" select=".">
<xsl:with-param name="do" select="'Add'"/>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_listener" select=".">
<xsl:with-param name="do" select="'Remove'"/>
</xsl:apply-templates>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:callback" mode "rapi_listeners_listen"           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:callback" mode="rapi_listeners_listen">
<xsl:param name="message" select="'Message'"/>
<xsl:param name="queue" select="'Queue'"/>
<xsl:param name="listener" select="'Listener'"/>
<xsl:param name="event">
<xsl:choose>
<xsl:when test="(@event and ('' != @event))">
<xsl:value-of select="@event"/>
</xsl:when>
<xsl:otherwise>
</xsl:otherwise>
<xsl:value-of select="'Event'"/>
</xsl:choose>
</xsl:param>
<xsl:if test="(1 &lt; position())">
<xsl:text>protected:
</xsl:text>
</xsl:if>
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
</xsl:text>
<xsl:text>    struct </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/><xsl:text> {</xsl:text>
<xsl:apply-templates mode="struct_fields" select="rapi:param">
</xsl:apply-templates>
<xsl:text>
        </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/><xsl:text>(</xsl:text>
<xsl:apply-templates mode="struct_param" select="rapi:param">
<xsl:with-param name="type_prefix" select="'const '"/>
<xsl:with-param name="type_suffix" select="'&amp;'"/>
</xsl:apply-templates>
<xsl:text>)</xsl:text>
<xsl:apply-templates mode="struct_construct" select="rapi:param">
</xsl:apply-templates>
<xsl:text> {
        }
        </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/><xsl:text>(const </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/><xsl:text>&amp; copy)</xsl:text>
<xsl:apply-templates mode="struct_copy_construct" select="rapi:param">
</xsl:apply-templates>
<xsl:text> {
        }
    };
    typedef MessageQueueT&lt;</xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$message"/>
<xsl:text>&gt; </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$queue"/><xsl:text>;
    typedef CallbackListT&lt;</xsl:text><xsl:value-of select="@name"/>
<xsl:text>&gt; </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$listener"/><xsl:text>s;
    ////////////////////////////////////////////////////////////////////////
    </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$queue"/>
<xsl:text> m_</xsl:text><xsl:value-of select="translate($event,$A2Z,$a2z)"/>
<xsl:text></xsl:text><xsl:value-of select="$queue"/><xsl:text>;
    </xsl:text><xsl:value-of select="$event"/>
<xsl:text></xsl:text><xsl:value-of select="$listener"/>
<xsl:text>s m_</xsl:text><xsl:value-of select="translate($event,$A2Z,$a2z)"/>
<xsl:text></xsl:text><xsl:value-of select="$listener"/><xsl:text>s;
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_listeners_listen_begin"       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_listeners_listen_begin">
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    static </xsl:text>
<xsl:value-of select="@name"/>
    <xsl:text>&amp; GetTheInstance();
</xsl:text>
<xsl:text>    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
protected:
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_object_begin"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_object_begin">
<xsl:text>
typedef </xsl:text><xsl:value-of select="$class_implement"/>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>Implement;
typedef </xsl:text><xsl:value-of select="$class_extend"/>
<xsl:text> </xsl:text><xsl:value-of select="@name"/><xsl:text>Extend;
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
class </xsl:text><xsl:value-of select="$CLASS_EXPORT"/><xsl:text></xsl:text><xsl:value-of select="@name"/>
<xsl:text>: virtual public </xsl:text><xsl:value-of select="@name"/>
<xsl:text>Implement, public </xsl:text><xsl:value-of select="@name"/>
<xsl:text>Extend {
public:
    typedef </xsl:text><xsl:value-of select="@name"/><xsl:text>Implement Implements;
    typedef </xsl:text><xsl:value-of select="@name"/><xsl:text>Extend Extends;
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_object_end"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_object_end">
<xsl:text>};
</xsl:text>
<xsl:text>
</xsl:text>
</xsl:template>

</xsl:transform>
