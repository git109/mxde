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
<!--   File: medusaxde-to-cxx-templates.xsl                                 -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 3/5/2012                                                       -->
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
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="organization" select="'$organization$'"/>
<xsl:param name="author" select="'$author$'"/>
<xsl:param name="file" select="'$file$'"/>
<xsl:param name="file_date" select="'$file$'"/>
<xsl:param name="copyright_year" select="'$year$'"/>
<xsl:param name="year" select="$copyright_year"/>
<xsl:param name="date" select="$file_date"/>
    
<xsl:param name="include" select="'XosInterfaceBase.hpp'"/>
<xsl:param name="class" select="$file"/>
<xsl:param name="class_prefix" select="''"/>
<xsl:param name="class_type" select="'c_INTERFACE_CLASS'"/>
<xsl:param name="class_access" select="'public'"/>
<xsl:param name="c_NAMESPACE" select="'c_NAMESPACE'"/>

<xsl:variable name="class_type_space">
    <xsl:if test="('' != $class_type)">
        <xsl:value-of select="$class_prefix"/>
        <xsl:value-of select="$class_type"/>
        <xsl:value-of select="' '"/>
    </xsl:if>
</xsl:variable>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="a2z" select="'abcdefghijklmnopqrstuvwxyz'"/>
<xsl:variable name="A2Z" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>
<xsl:variable name="FILE" select="translate(translate($file,$a2z,$A2Z),'.','_')"/>
<xsl:variable name="CLASS" select="translate($class,$a2z,$A2Z)"/>
    
<xsl:variable name="begin_comment">
<xsl:text>////////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:variable>
<xsl:variable name="middle_comment">
<xsl:text>///</xsl:text>
</xsl:variable>
<xsl:variable name="end_comment">
<xsl:text>////////////////////////////////////////////////////////////////////////
</xsl:text>
</xsl:variable>
<xsl:variable name="left_comment">
<xsl:text>//</xsl:text>
</xsl:variable>
<xsl:variable name="right_comment">
<xsl:text></xsl:text>
</xsl:variable>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "file_header"                                                -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template name="file_header">
<xsl:param name="file" select="$file"/>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:value-of select="$begin_comment"/>
<xsl:text></xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> Copyright (c) 1988-</xsl:text><xsl:value-of select="$year"/><xsl:text> </xsl:text><xsl:value-of select="$organization"/><xsl:text>
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text>
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> This software is provided by the author and contributors ``as is'' 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> and any express or implied warranties, including, but not limited to, 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> the implied warranties of merchantability and fitness for a particular 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> purpose are disclaimed. In no event shall the author or contributors 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> be liable for any direct, indirect, incidental, special, exemplary, 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> or consequential damages (including, but not limited to, procurement 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> of substitute goods or services; loss of use, data, or profits; or 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> business interruption) however caused and on any theory of liability, 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> whether in contract, strict liability, or tort (including negligence 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> or otherwise) arising in any way out of the use of this software, 
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> even if advised of the possibility of such damage.
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text>
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text>   File: </xsl:text><xsl:value-of select="$file"/><xsl:text>
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text>
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text> Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
</xsl:text><xsl:value-of select="$middle_comment"/><xsl:text>   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
</xsl:text><xsl:value-of select="$end_comment"/>
</xsl:with-param>
</xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "file_ifdef"                                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template name="file_ifdef">
<xsl:param name="file" select="$file"/>
<xsl:param name="class" select="$class"/>
<xsl:variable name="FILE" select="translate(translate($file,$a2z,$A2Z),'.','_')"/>
<xsl:variable name="CLASS" select="translate(translate($class,$a2z,$A2Z),'.','_')"/>
<xsl:text/>#if !defined(_<xsl:value-of select="$FILE"/>) || defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
#if !defined(_<xsl:value-of select="$FILE"/>) &amp;&amp; !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
#define _<xsl:value-of select="$FILE"/>
#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(_<xsl:value-of select="$FILE"/>) &amp;&amp; !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
#if !defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:template>
<!--========================================================================-->
<!-- Template: "file_endif"                                                 -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template name="file_endif">
<xsl:param name="file" select="$file"/>
<xsl:param name="class" select="$class"/>
<xsl:variable name="FILE" select="translate(translate($file,$a2z,$A2Z),'.','_')"/>
<xsl:variable name="CLASS" select="translate(translate($class,$a2z,$A2Z),'.','_')"/>
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
#endif <xsl:call-template name="comment">
<xsl:with-param name="text">
    <xsl:value-of select="$left_comment"/> !defined(_<xsl:value-of select="$FILE"/>) || defined(<xsl:value-of select="$CLASS"/>_MEMBERS_ONLY)
</xsl:with-param>
</xsl:call-template>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "class_header"                                               -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template name="class_header">
<xsl:param name="indent" select="''"/>
<xsl:param name="class" select="$class"/>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:value-of select="$indent"/><xsl:value-of select="$begin_comment"/>
<xsl:text></xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>  Class: </xsl:text><xsl:value-of select="$class"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text> Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>   Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$end_comment"/>
</xsl:with-param>
</xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "function_header"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/5/2012                                                     -->
<!--========================================================================-->
<xsl:template name="function_header">
<xsl:param name="name" select="'function'"/>
<xsl:param name="indent" select="'    '"/>
<xsl:call-template name="comment">
<xsl:with-param name="text">
<xsl:value-of select="$indent"/><xsl:value-of select="$begin_comment"/>
<xsl:text></xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>  Function: </xsl:text><xsl:value-of select="$name"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>    Author: </xsl:text><xsl:value-of select="$author"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$middle_comment"/><xsl:text>      Date: </xsl:text><xsl:value-of select="$date"/><xsl:text>
</xsl:text><xsl:value-of select="$indent"/><xsl:value-of select="$end_comment"/>
</xsl:with-param>
</xsl:call-template>
</xsl:template>

<!--========================================================================-->
<!-- Template: "c_NAMESPACE_begin"                                          -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/11/2012                                                    -->
<!--========================================================================-->
<xsl:template name="c_NAMESPACE_begin">
<xsl:if test="('' != $c_NAMESPACE)">
#if defined(<xsl:value-of select="$c_NAMESPACE"/>)
namespace <xsl:value-of select="$c_NAMESPACE"/> {
#endif<xsl:call-template name="comment">
<xsl:with-param name="text"> // defined(<xsl:value-of select="$c_NAMESPACE"/>)
</xsl:with-param>
</xsl:call-template>
</xsl:if>
</xsl:template>
<!--========================================================================-->
<!-- Template: "c_NAMESPACE_end"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 3/11/2012                                                    -->
<!--========================================================================-->
<xsl:template name="c_NAMESPACE_end">
<xsl:if test="('' != $c_NAMESPACE)">
#if defined(<xsl:value-of select="$c_NAMESPACE"/>)
}
#endif<xsl:call-template name="comment">
<xsl:with-param name="text"> // defined(<xsl:value-of select="$c_NAMESPACE"/>)
</xsl:with-param>
</xsl:call-template>
</xsl:if>
</xsl:template>

</xsl:transform>
