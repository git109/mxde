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
<!--   File: restapi-to-xos-cxx-standard-templates.xslt                     -->
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
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_send_event"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_send_event">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_receive_event"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_receive_event">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_process_event"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_process_event">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_process"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/4/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_process">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_enums"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_enums">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_types"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_types">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_struct_fields_to"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_struct_fields_to">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_structs"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_structs">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_callbacks"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_callbacks">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions_begin"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions_end"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions_end">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_events_begin"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_events_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_events_end"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_events_end">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_events"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_events">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_listeners_begin"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_listeners_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_listeners_end"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_listeners_end">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_listeners"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_listeners">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_listeners_listen_begin"                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_listeners_listen_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_listeners_listen_end"                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_listeners_listen_end">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_listeners_listen"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_listeners_listen">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_events_process_begin"                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_events_process_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_events_process_end"                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_events_process_end">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_events_process"                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_events_process">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_function_begin"             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_function_begin">
<xsl:text>    virtual </xsl:text>
<xsl:choose>
<xsl:when test="rapi:return">
<xsl:apply-templates mode="function_return" select="rapi:return"/>
</xsl:when>
<xsl:otherwise>
<xsl:text>void </xsl:text>
</xsl:otherwise>
</xsl:choose>
<xsl:value-of select="@name"/>
<xsl:if test="rapi:param"><xsl:text>
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
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:function" mode "rapi_function_end"               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:function" mode="rapi_function_end">
<xsl:apply-templates mode="function_result" select="rapi:return"/>
<xsl:text>    }
</xsl:text>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_begin"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_function_end"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_function_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions_begin"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_functions_end"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_functions_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_object_begin"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_object_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_object_end"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_object_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_hxx"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_hxx">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
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
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_hxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "rapi:object" mode "rapi_hxx"                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:object" mode="rapi_hxx">
<xsl:param name="name" select="''"/>
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_name">
    <xsl:value-of select="$name"/>
    <xsl:value-of select="@name"/>
</xsl:variable>
<xsl:variable name="class_namespace">
<xsl:choose>
<xsl:when test="('yes' = $is_object_namespace)">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:when>
<xsl:otherwise>
    <xsl:value-of select="$namespace"/>
</xsl:otherwise>
</xsl:choose>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' = $is_object_namespace)">
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_object_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<xsl:apply-templates mode="rapi_enums" select="rapi:enum">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<xsl:apply-templates mode="rapi_types" select="rapi:type">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<xsl:apply-templates mode="rapi_structs" select="rapi:struct">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<xsl:apply-templates mode="rapi_callbacks" select="rapi:callback">
    <xsl:with-param name="name">
        <xsl:value-of select="$class_name"/>
    </xsl:with-param>
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_functions_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_functions" select="rapi:function">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_functions_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_events_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_events" select="rapi:callback">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_events_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_events_process_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_events_process" select="rapi:callback">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_events_process_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_listeners_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_listeners" select="rapi:callback">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_listeners_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_listeners_listen_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_listeners_listen" select="rapi:callback">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_listeners_listen_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_object_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' = $is_object_namespace)">
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_hxx"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_hxx">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_hxx_begin"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_hxx_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_hxx_end"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_hxx_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:application" mode "rapi_include_hxx"             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application" mode="rapi_include_hxx">
<xsl:call-template name="include_hxx"></xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_include_hxx"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_include_hxx">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_include_hxx_begin"                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_include_hxx_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_include_hxx_end"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_include_hxx_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_cxx_object_begin"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_cxx_object_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_cxx_object_end"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/3/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_cxx_object_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:namespace" mode "rapi_cxx"                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:namespace" mode="rapi_cxx">
<xsl:param name="namespace" select="''"/>
<xsl:param name="path" select="''"/>
<xsl:variable name="class_namespace">
    <xsl:call-template name="class_namespace">
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
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_cxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:template>
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
<xsl:choose>
<xsl:when test="('yes' = $is_object_namespace)">
    <xsl:call-template name="class_namespace">
        <xsl:with-param name="namespace" select="$namespace"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:when>
<xsl:otherwise>
    <xsl:value-of select="$namespace"/>
</xsl:otherwise>
</xsl:choose>
</xsl:variable>
<xsl:variable name="object_path">
    <xsl:call-template name="object_path">
        <xsl:with-param name="path" select="$path"/>
        <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
    </xsl:call-template>
</xsl:variable>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' = $is_object_namespace)">
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_cxx_object_begin" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:apply-templates mode="rapi_cxx_object_end" select=".">
    <xsl:with-param name="namespace">
        <xsl:value-of select="$class_namespace"/>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:value-of select="$object_path"/>
    </xsl:with-param>
</xsl:apply-templates>
<!--========================================================================-->
<!--========================================================================-->
<xsl:if test="('yes' = $is_object_namespace)">
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_cxx"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_cxx">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_cxx_begin"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_cxx_begin">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_cxx_end"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_cxx_end">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*" mode "rapi_begin"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_begin">
<xsl:call-template name="file_header"></xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi_end"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi_end">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "rapi"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/2/2014                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="rapi">
</xsl:template>

<!--========================================================================-->
<!--========================================================================-->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "rapi:application"                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 1/1/2014                                                     -->
<!--========================================================================-->
<xsl:template match="rapi:application">
<xsl:choose>
<xsl:when test="($file_hxx_extension = $file_extension)">
<xsl:call-template name="file_header"></xsl:call-template>
<xsl:call-template name="file_ifndef_begin"></xsl:call-template>
<xsl:apply-templates mode="rapi_include_hxx_begin" select=".">
    <xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_include_hxx" select=".">
    <xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_include_hxx_end" select=".">
    <xsl:with-param name="path" select="translate(@name,$A2Z,$a2z)"/>
</xsl:apply-templates>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_hxx_begin" select=".">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_hxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:call-template name="object_path">
            <xsl:with-param name="path" select="$path"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_hxx_end" select=".">
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:call-template name="file_ifndef_end"></xsl:call-template>
</xsl:when>
<!--========================================================================-->
<!--========================================================================-->
<xsl:when test="($file_cxx_extension = $file_extension)">
<xsl:call-template name="file_header"></xsl:call-template>
<xsl:call-template name="include_cxx"></xsl:call-template>
<xsl:call-template name="namespace_begin">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
<xsl:apply-templates mode="rapi_cxx_begin" select=".">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_cxx" select="./*">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:call-template name="object_path">
            <xsl:with-param name="path" select="$path"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_cxx_end" select=".">
</xsl:apply-templates>
<xsl:call-template name="namespace_end">
    <xsl:with-param name="namespace_2" select="translate(@name,$A2Z,$a2z)"/>
</xsl:call-template>
</xsl:when>
<!--========================================================================-->
<!--========================================================================-->
<xsl:otherwise>
<xsl:apply-templates mode="rapi_begin" select=".">
</xsl:apply-templates>
<xsl:apply-templates mode="rapi" select="./*">
    <xsl:with-param name="namespace">
        <xsl:call-template name="class_namespace">
            <xsl:with-param name="namespace" select="$namespace"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="path">
        <xsl:call-template name="object_path">
            <xsl:with-param name="path" select="$path"/>
            <xsl:with-param name="name" select="translate(@name,$A2Z,$a2z)"/>
        </xsl:call-template>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:apply-templates mode="rapi_end" select=".">
</xsl:apply-templates>
</xsl:otherwise>
</xsl:choose>
</xsl:template>

</xsl:transform>
