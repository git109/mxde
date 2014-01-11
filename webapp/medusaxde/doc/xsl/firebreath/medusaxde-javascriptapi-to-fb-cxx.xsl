<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2012 $organization$                                 -->
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
<!--   File: medusaxde-javascriptapi-to-fb-cxx.xsl                          -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/29/2012                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:medusaxde="Medusa-Xos-Development-Environment"
 exclude-result-prefixes="xsl exsl xalan msxsl xde mxde medusade medusaxde"
 version="1.0">

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->
<xsl:include href="../cxx/medusaxde-cxx-content-type-templates.xsl"/>
<xsl:include href="../cxx/medusaxde-to-cxx-templates.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="events_class" select="'EventsInterface'"/>
<xsl:param name="events_class_prefix" select="$class_prefix"/>
<xsl:param name="events_class_type" select="$class_type"/>
<xsl:param name="events_class_access" select="'public'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="events_class_type_space">
    <xsl:if test="('' != $events_class_type)">
        <xsl:value-of select="$events_class_prefix"/>
        <xsl:value-of select="$events_class_type"/>
        <xsl:value-of select="' '"/>
    </xsl:if>
</xsl:variable>


<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "property" mode "register"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="property" mode="register">
    <xsl:param name="filter" select="''"/>
    <xsl:variable name="included">
        <xsl:choose>
            <xsl:when test="(('yes' = @readOnly) and ('readOnly' = $filter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:when test="(('' = @readOnly) and ('readWrite' = $filter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:when test="('' = $filter)">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('' != @name) and ('' != @type) and ('' != $included))">
<xsl:call-template name="comment">
<xsl:with-param name="text">
        // <xsl:value-of select="@name"/>
        //
</xsl:with-param>
</xsl:call-template>        registerProperty
        ("<xsl:value-of select="@name"/>", make_property(this,
         &amp;Derives::get_<xsl:value-of select="@name"/>
         <xsl:if test="(not ('yes' = @readOnly))">, &amp;Derives::set_<xsl:value-of select="@name"/>
         </xsl:if>));
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: match "property" mode "hpp"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="property" mode="hpp">
    <xsl:param name="proto" select="''"/>
    <xsl:param name="filter" select="''"/>
    <xsl:variable name="type">
        <xsl:choose>
            <xsl:when test="('string' = @type)">
                <xsl:value-of select="'std::'"/>
                <xsl:value-of select="@type"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="@type"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="set_type">
        <xsl:choose>
            <xsl:when test="('string' = @type)">
                <xsl:value-of select="'const std::'"/>
                <xsl:value-of select="@type"/>
                <xsl:value-of select="'&amp;'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="@type"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="return_val">
        <xsl:choose>
            <xsl:when test="('int' = @type)">
                <xsl:value-of select="' = -1'"/>
            </xsl:when>
            <xsl:when test="('bool' = @type)">
                <xsl:value-of select="' = false'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="included">
        <xsl:choose>
            <xsl:when test="(('yes' = @readOnly) and ('readOnly' = $filter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:when test="(('' = @readOnly) and ('readWrite' = $filter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:when test="('' = $filter)">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>

<xsl:if test="(('' != @name) and ('' != @type) and ('' != $included))">
<!--========================================================================-->
<!-- get                                                                    -->
<!--========================================================================-->
<xsl:call-template name="comment">
<xsl:with-param name="text">
    // <xsl:value-of select="@name"/>
    //
</xsl:with-param>
</xsl:call-template>
<xsl:text>    </xsl:text>
<xsl:value-of select="$type"/>
<xsl:text> get_</xsl:text>
<xsl:value-of select="@name"/>()<xsl:choose>
<xsl:when test="('yes' = $proto)">;
</xsl:when>
<xsl:otherwise>
    { <xsl:value-of select="$type"/> val<xsl:value-of select="$return_val"/>;
      Implements* delegated;
      if ((delegated = Delegated()))
          val = delegated-&gt;get_<xsl:value-of select="@name"/>();
      return val; }
</xsl:otherwise>
</xsl:choose>

<xsl:if test="(not ('yes' = @readOnly))">
<!--========================================================================-->
<!-- set                                                                    -->
<!--========================================================================-->
<xsl:text>    </xsl:text>
<xsl:value-of select="'void'"/>
<xsl:text> set_</xsl:text>
<xsl:value-of select="@name"/>(<xsl:value-of select="$set_type"/> val)<xsl:choose>
<xsl:when test="('yes' = $proto)">;
</xsl:when>
<xsl:otherwise>
    { Implements* delegated;
      if ((delegated = Delegated()))
          delegated-&gt;set_<xsl:value-of select="@name"/>(val); }
</xsl:otherwise>
</xsl:choose>
</xsl:if>

</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "property" mode "cpp"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="property" mode="cpp">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "properties" mode "properties"                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="properties" mode="properties">
<!--========================================================================-->
<!-- members                                                                -->
<!--========================================================================-->
<xsl:call-template name="comment">
<xsl:with-param name="text">    //
    // read/write properties
    //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="hpp">
    <xsl:with-param name="filter" select="'readWrite'"/>
</xsl:apply-templates>
<xsl:call-template name="comment">
<xsl:with-param name="text">
    //
    // read only properties
    //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="hpp">
    <xsl:with-param name="filter" select="'readOnly'"/>
</xsl:apply-templates>
<!--========================================================================-->
<!-- delegation                                                             -->
<!--========================================================================-->
<xsl:text>
    class </xsl:text>
<xsl:value-of select="$events_class_type_space"/><xsl:value-of select="$events_class"/>
<xsl:text>;
</xsl:text>
<xsl:call-template name="function_header">
    <xsl:with-param name="name">
        <xsl:value-of select="'Delegate'"/>
    </xsl:with-param>
</xsl:call-template>
<xsl:text/>    virtual Implements* Delegate(<xsl:value-of select="$events_class"/>* events=0)
    { return ((Implements*)(this)); }
<xsl:call-template name="function_header">
    <xsl:with-param name="name">
        <xsl:value-of select="'Delegated'"/>
    </xsl:with-param>
</xsl:call-template>
<xsl:text/>    virtual Implements* Delegated()
#if !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
    { return 0; }
#else <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>    ;
#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
<!--========================================================================-->
<!-- registration                                                           -->
<!--========================================================================-->
<xsl:text>
</xsl:text>
#if !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
#else <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
<xsl:call-template name="function_header">
    <xsl:with-param name="name">
        <xsl:value-of select="'RegisterProperties'"/>
    </xsl:with-param>
</xsl:call-template>
<xsl:text/>    virtual void RegisterProperties()
    {
    <xsl:call-template name="comment">
<xsl:with-param name="text">    //
        // read/write properties
        //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="register">
    <xsl:with-param name="filter" select="'readWrite'"/>
</xsl:apply-templates>
<xsl:call-template name="comment">
<xsl:with-param name="text">
        //
        // read only properties
        //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="register">
    <xsl:with-param name="filter" select="'readOnly'"/>
</xsl:apply-templates>
    }
<xsl:text/>#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "properties"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="properties">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "parameter" mode "parameter"                           -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="parameter" mode="parameter">
    <xsl:param name="type_only" select="''"/>
    <xsl:variable name="type">
        <xsl:choose>
            <xsl:when test="('string' = @type)">
                <xsl:value-of select="'const std::'"/>
                <xsl:value-of select="@type"/>
                <xsl:value-of select="'&amp;'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="@type"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="name">
        <xsl:choose>
            <xsl:when test="(('yes' = $type_only) or ('void' = @type))">
                <xsl:value-of select="''"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="@name"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:value-of select="$type"/><xsl:if test="('' != $name)">
    <xsl:text> </xsl:text> <xsl:value-of select="$name"/></xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "parameter"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="parameter">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "method" mode "parameters"                             -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="method" mode="parameters">
    <xsl:for-each select="parameter">
        <xsl:if test="(1 &lt; position())"><xsl:text>, </xsl:text></xsl:if>
        <xsl:apply-templates select="." mode="parameter"/>
    </xsl:for-each>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "parameters"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="parameters">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "parameter" mode "argument"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="parameter" mode="argument">
<xsl:value-of select="@name"/>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "argument"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="argument">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "method" mode "arguments"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="method" mode="arguments">
    <xsl:for-each select="parameter">
        <xsl:if test="(1 &lt; position())"><xsl:text>, </xsl:text></xsl:if>
        <xsl:apply-templates select="." mode="argument"/>
    </xsl:for-each>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "arguments"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="arguments">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "method" mode "register"                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="method" mode="register">
    <xsl:param name="filter" select="''"/>
    <xsl:variable name="included">
        <xsl:choose>
            <xsl:when test="(('yes' = @const) and ('const' = $filter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:when test="('' = $filter)">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
<!--========================================================================-->
<!-- Template Body                                                          -->
<!--========================================================================-->
<xsl:if test="(('' != @name) and ('' != $included))">
<xsl:call-template name="comment">
<xsl:with-param name="text">
        // <xsl:value-of select="@name"/>
        //
</xsl:with-param>
</xsl:call-template>
<xsl:text/>        registerMethod
        ("<xsl:value-of select="@name"/>", make_method
         (this, &amp;Derives::<xsl:value-of select="@name"/>));
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "method" mode "hpp"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="method" mode="hpp">
    <xsl:param name="proto" select="''"/>
    <xsl:param name="filter" select="''"/>
    <xsl:variable name="return">
        <xsl:choose>
            <xsl:when test="('string' = @return)">
                <xsl:value-of select="'std::'"/>
                <xsl:value-of select="@return"/>
            </xsl:when>
            <xsl:when test="('' = @return)">
                <xsl:value-of select="'void'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="@return"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="return_val">
        <xsl:choose>
            <xsl:when test="('int' = @return)">
                <xsl:value-of select="' = -1'"/>
            </xsl:when>
            <xsl:when test="('bool' = @return)">
                <xsl:value-of select="' = false'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="multiple_params">
        <xsl:choose>
            <xsl:when test="(1 &lt; count(./parameter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
    <xsl:variable name="included">
        <xsl:choose>
            <xsl:when test="(('yes' = @const) and ('const' = $filter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:when test="('' = $filter)">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>
<!--========================================================================-->
<!-- Template Body                                                          -->
<!--========================================================================-->

<xsl:if test="(('' != @name) and ('' != $included))">
<xsl:call-template name="comment">
<xsl:with-param name="text">
    // <xsl:value-of select="@name"/>
    //
</xsl:with-param>
</xsl:call-template>
<xsl:text>    virtual </xsl:text>
<xsl:value-of select="$return"/>
<xsl:text> </xsl:text>
<xsl:value-of select="@name"/><xsl:if test="('' != $multiple_params)"><xsl:text>
    </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="parameters"/>)<xsl:choose>
<xsl:when test="('yes' = $proto)">;
</xsl:when>
<xsl:otherwise>
    <xsl:choose>
        <xsl:when test="('' != @return)">
    { <xsl:value-of select="$return"/> val<xsl:value-of select="$return_val"/>;
      Implements* delegated;
      if ((delegated = Delegated()))
          val = delegated-&gt;<xsl:value-of select="@name"/><xsl:if test="('' != $multiple_params)"><xsl:text>
          </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="arguments"/>);
      return val; }
        </xsl:when>
        <xsl:otherwise>
    { Implements* delegated;
      if ((delegated = Delegated()))
          delegated-&gt;<xsl:value-of select="@name"/><xsl:if test="('' != $multiple_params)"><xsl:text>
          </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="arguments"/>); }
        </xsl:otherwise>
    </xsl:choose>
</xsl:otherwise>
</xsl:choose>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "methods" mode "methods"                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="methods" mode="methods">
<xsl:call-template name="comment">
<xsl:with-param name="text">
    //
    // methods
    //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="hpp">
</xsl:apply-templates>
<!--========================================================================-->
<!-- registration                                                           -->
<!--========================================================================-->
<xsl:text>
</xsl:text>
#if !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
#else <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
<xsl:call-template name="function_header">
    <xsl:with-param name="name">
        <xsl:value-of select="'RegisterMethods'"/>
    </xsl:with-param>
</xsl:call-template>
<xsl:text/>    virtual void RegisterMethods()
    {
<xsl:apply-templates select="./*" mode="register">
</xsl:apply-templates>
<xsl:text/>    }
<xsl:text/>#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "methods"                                     -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="methods">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "event" mode "arguments"                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/9/2012                                                     -->
<!--========================================================================-->
<xsl:template match="event" mode="arguments">
    <xsl:for-each select="parameter">
        <xsl:if test="(1 &lt; position())"><xsl:text>, </xsl:text></xsl:if>
        <xsl:apply-templates select="." mode="argument"/>
    </xsl:for-each>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "event" mode "parameters"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/6/2012                                                     -->
<!--========================================================================-->
<xsl:template match="event" mode="parameters">
    <xsl:param name="type_only" select="''"/>
    <xsl:for-each select="parameter">
        <xsl:if test="(1 &lt; position())"><xsl:text>, </xsl:text></xsl:if>
        <xsl:apply-templates select="." mode="parameter">
            <xsl:with-param name="type_only" select="$type_only"/>
        </xsl:apply-templates>
    </xsl:for-each>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "event" mode "event"                                   -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/8/2012                                                     -->
<!--========================================================================-->
<xsl:template match="event" mode="event">
    <xsl:variable name="multiple_params">
        <xsl:choose>
            <xsl:when test="(1 &lt; count(./parameter))">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>

<xsl:if test="('' != @name)">
<xsl:call-template name="comment">
<xsl:with-param name="text">
        // <xsl:value-of select="@name"/>
        //
</xsl:with-param>
</xsl:call-template>
<xsl:text/>        virtual void <xsl:value-of select="@name"/>
<xsl:if test="('yes' = $multiple_params)"><xsl:text>
        </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="parameters"/>)
        { }
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "event"                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/8/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="event">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "event" mode "event_helper"                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/8/2012                                                     -->
<!--========================================================================-->
<xsl:template match="event" mode="event_helper">
    <xsl:variable name="helper_name" select="substring-after(@name,'on')"/>
    <xsl:variable name="params" select="count(./parameter[('' != @name)])"/>
    <xsl:variable name="multiple_params">
        <xsl:choose>
            <xsl:when test="(1 &lt; $params)">
                <xsl:value-of select="'yes'"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="''"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:variable>

<xsl:if test="('' != @name)">
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text/>
    // <xsl:value-of select="@name"/>
    //
</xsl:with-param>
</xsl:call-template>
<xsl:text/>    FB_JSAPI_EVENT(<xsl:value-of select="$helper_name"/>
<xsl:text>, </xsl:text><xsl:value-of select="$params"/><xsl:text>, </xsl:text>
<xsl:if test="('yes' = $multiple_params)"><xsl:text>
    </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="parameters">
        <xsl:with-param name="type_only" select="'yes'"/>
    </xsl:apply-templates>));
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "event_helper"                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/8/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="event_helper">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "event" mode "event_fire"                              -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/9/2012                                                     -->
<!--========================================================================-->
<xsl:template match="event" mode="event_fire">
<xsl:variable name="helper_name" select="substring-after(@name,'on')"/>
<xsl:variable name="params" select="count(./parameter[('' != @name)])"/>
<xsl:variable name="multiple_params">
    <xsl:choose>
        <xsl:when test="(1 &lt; $params)">
            <xsl:value-of select="'yes'"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="''"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:variable>

<xsl:if test="('' != @name)">
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:text/>
    // <xsl:value-of select="@name"/>
    //
</xsl:with-param>
</xsl:call-template>
<xsl:text/>    virtual void <xsl:value-of select="@name"/>
<xsl:if test="('yes' = $multiple_params)"><xsl:text>
    </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="parameters"/>)
    { fire_<xsl:value-of select="$helper_name"/>
<xsl:if test="('yes' = $multiple_params)"><xsl:text>
      </xsl:text></xsl:if>(<xsl:apply-templates select="." mode="arguments"/>); }
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "event_fire"                                  -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/9/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="event_fire">
</xsl:template>
<!--========================================================================-->
<!-- Template: match "events" mode "events"                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="events" mode="events">
<xsl:param name="indent" select="'    '"/>
<xsl:text>
</xsl:text>
#if !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
<xsl:call-template name="class_header">
    <xsl:with-param name="class" select="$events_class"/>
    <xsl:with-param name="indent" select="$indent"/>
</xsl:call-template>
<xsl:value-of select="$indent"/><xsl:text>class </xsl:text>
<xsl:value-of select="$events_class_type_space"/><xsl:value-of select="$events_class"/>
<xsl:text>
</xsl:text>
<xsl:value-of select="$indent"/>{
<xsl:value-of select="$indent"/><xsl:value-of select="$events_class_access"/>:
<xsl:apply-templates select="./*" mode="event">
    <xsl:with-param name="indent">
        <xsl:value-of select="$indent"/>
        <xsl:value-of select="'    '"/>
    </xsl:with-param>
</xsl:apply-templates>
<xsl:value-of select="$indent"/>};
#else <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
<xsl:call-template name="comment">
<xsl:with-param name="text">    //
    // event helpers
    //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="event_helper"/>
<xsl:call-template name="comment">
<xsl:with-param name="text">
    //
    // event fires
    //
</xsl:with-param>
</xsl:call-template>
<xsl:apply-templates select="./*" mode="event_fire"/>
<xsl:text/>#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
</xsl:template>
<!--========================================================================-->
<!-- Template: match "*" mode "events"                                      -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template match="*" mode="events">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "JavaScriptAPI" mode "document"                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/29/2012                                                    -->
<!--========================================================================-->
<xsl:template match="JavaScriptAPI" mode="document">
    <xsl:variable name="file">
        <xsl:value-of select="$file"/>
        <xsl:value-of select="'.hpp'"/>
    </xsl:variable>
    <xsl:variable name="FILE" select="translate(translate($file,$a2z,$A2Z),'.','_')"/>
    <xsl:variable name="CLASS" select="translate(translate($class,$a2z,$A2Z),'.','_')"/>

    <xsl:call-template name="file_header">
        <xsl:with-param name="file">
            <xsl:value-of select="$file"/>
        </xsl:with-param>
    </xsl:call-template>
    <xsl:call-template name="file_ifdef">
        <xsl:with-param name="file">
            <xsl:value-of select="$file"/>
        </xsl:with-param>
    </xsl:call-template>
<xsl:if test="('' != $include)">#include &quot;<xsl:value-of select="$include"/>&quot;
</xsl:if>#include &lt;string&gt;
<xsl:call-template name="c_NAMESPACE_begin">
</xsl:call-template>
<xsl:text>
</xsl:text>
<xsl:call-template name="class_header">
    <xsl:with-param name="class">
        <xsl:value-of select="$class"/>
    </xsl:with-param>
</xsl:call-template>
<xsl:text>class </xsl:text>
<xsl:value-of select="$class_type_space"/><xsl:value-of select="$class"/>
{
<xsl:value-of select="$class_access"/>:
    typedef <xsl:value-of select="$class"/> Implements;
    typedef <xsl:value-of select="$class"/> Derives;
#else <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
<xsl:text/>#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text>
    <xsl:apply-templates select="./*" mode="properties"></xsl:apply-templates>
    <xsl:apply-templates select="./*" mode="methods"></xsl:apply-templates>
    <xsl:apply-templates select="./*" mode="events"></xsl:apply-templates>
#if !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
<xsl:text>};
</xsl:text>
<xsl:call-template name="c_NAMESPACE_end">
</xsl:call-template>
<xsl:call-template name="file_endif">
    <xsl:with-param name="file">
        <xsl:value-of select="$file"/>
    </xsl:with-param>
</xsl:call-template>
<xsl:text>
</xsl:text>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*" mode "document"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/29/2012                                                    -->
<!--========================================================================-->
<xsl:template match="*" mode="document">
</xsl:template>

<!--========================================================================-->
<!-- Template: match "JavaScriptAPI"                                        -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/29/2012                                                    -->
<!--========================================================================-->
<xsl:template match="JavaScriptAPI">
    <xsl:choose>
        <xsl:when test="('text/html' != $content_type)">
            <xsl:apply-templates mode="text" select="."/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:apply-templates mode="html" select="."/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 2/29/2012                                                    -->
<!--========================================================================-->
<xsl:template match="*">
<b>Unexpected document type "</b><xsl:value-of select="name()"/><b>"</b>
</xsl:template>
</xsl:transform>
