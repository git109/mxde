<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2011 $organization$                                 -->
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
<!--   File: medusaxde-cxx-form-parameters.xsl                              -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 2/12/2011                                                      -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xalan="http://xml.apache.org/xalan"
 xmlns:xde="Medusa-Xos-Development-Environment"
 xmlns:mxde="Medusa-Xos-Development-Environment"
 xmlns:medusade="Medusa-Xos-Development-Environment"
 xmlns:msxsl="urn:schemas-microsoft-com:xslt"
 exclude-result-prefixes="xsl xalan xde mxde medusade msxsl"
 version="1.0">

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_cxx_file_extension" select="''"/>
<xsl:param name="form_cxx_file_extension" select="$default_cxx_file_extension"/>
<xsl:param name="cxx_file_extension">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]/mxde:cxx_file_extension"/>
    <xsl:variable name="select_default" select="$select['' = @for]/mxde:cxx_file_extension"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_file_extension">
            <xsl:value-of select="$form_cxx_file_extension"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="'' != $select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_file_extension"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_file_type" select="''"/>
<xsl:param name="form_cxx_file_type" select="$default_cxx_file_type"/>
<xsl:param name="cxx_file_type">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]/mxde:cxx_file_type"/>
    <xsl:variable name="select_default" select="$select['' = @for]/mxde:cxx_file_type"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_file_type">
            <xsl:value-of select="$form_cxx_file_type"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="'' != $select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_file_type"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_file_is_class" select="''"/>
<xsl:param name="form_cxx_file_is_class" select="$default_cxx_file_is_class"/>
<xsl:param name="cxx_file_is_class">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]"/>
    <xsl:variable name="select_default" select="$select['' = @for]"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_file_is_class">
            <xsl:value-of select="$form_cxx_file_is_class"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for/mxde:cxx_file_is_class"/>
        </xsl:when>
        <xsl:when test="$select_default">
            <xsl:value-of select="$select_default/mxde:cxx_file_is_class"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_file_is_class"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_file_is_case" select="''"/>
<xsl:param name="form_cxx_file_is_case" select="$default_cxx_file_is_case"/>
<xsl:param name="cxx_file_is_case">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]"/>
    <xsl:variable name="select_default" select="$select['' = @for]"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_file_is_case">
            <xsl:value-of select="$form_cxx_file_is_case"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for/mxde:cxx_file_is_case"/>
        </xsl:when>
        <xsl:when test="$select_default">
            <xsl:value-of select="$select_default/mxde:cxx_file_is_case"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_file_is_case"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_code_style" select="''"/>
<xsl:param name="form_cxx_code_style" select="$default_cxx_code_style"/>
<xsl:param name="cxx_code_style">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]"/>
    <xsl:variable name="select_default" select="$select['' = @for]"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_code_style">
            <xsl:value-of select="$form_cxx_code_style"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for/mxde:cxx_code_style"/>
        </xsl:when>
        <xsl:when test="$select_default">
            <xsl:value-of select="$select_default/mxde:cxx_code_style"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_code_style"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<xsl:param name="default_cxx_function_proto" select="''"/>
<xsl:param name="form_cxx_function_proto" select="$default_cxx_function_proto"/>
<xsl:param name="cxx_function_proto">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]/mxde:cxx_function_proto"/>
    <xsl:variable name="select_default" select="$select['' = @for]/mxde:cxx_function_proto"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_function_proto">
            <xsl:value-of select="$form_cxx_function_proto"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="'' != $select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_function_proto"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_comment" select="''"/>
<xsl:param name="form_cxx_comment" select="$default_cxx_comment"/>
<xsl:param name="cxx_comment">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]/mxde:cxx_comment"/>
    <xsl:variable name="select_default" select="$select['' = @for]/mxde:cxx_comment"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_comment">
            <xsl:value-of select="$form_cxx_comment"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="'' != $select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_comment"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_class_comment" select="''"/>
<xsl:param name="form_cxx_class_comment" select="$default_cxx_class_comment"/>
<xsl:param name="cxx_class_comment">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]/mxde:cxx_class_comment"/>
    <xsl:variable name="select_default" select="$select['' = @for]/mxde:cxx_class_comment"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_class_comment">
            <xsl:value-of select="$form_cxx_class_comment"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="'' != $select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_class_comment"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>
    
<xsl:param name="default_cxx_function_comment" select="''"/>
<xsl:param name="form_cxx_function_comment" select="$default_cxx_function_comment"/>
<xsl:param name="cxx_function_comment">
    <xsl:variable name="select" select="$xde_for_parameters"/>
    <xsl:variable name="select_for" select="$select[$for = @for]/mxde:cxx_function_comment"/>
    <xsl:variable name="select_default" select="$select['' = @for]/mxde:cxx_function_comment"/>
    <xsl:choose>
        <xsl:when test="'' != $form_cxx_function_comment">
            <xsl:value-of select="$form_cxx_function_comment"/>
        </xsl:when>
        <xsl:when test="$select_for">
            <xsl:value-of select="$select_for"/>
        </xsl:when>
        <xsl:when test="'' != $select_default">
            <xsl:value-of select="$select_default"/>
        </xsl:when>
        <xsl:otherwise>
            <xsl:value-of select="$default_cxx_function_comment"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:param>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="cxx_yes_is_tree">
    <is default="no" value="yes">yes</is>
    <is default="yes" value="">no</is>
</xsl:variable>
<xsl:variable name="cxx_yes_is" 
 select="exsl:node-set($cxx_yes_is_tree)"/>

<xsl:variable name="cxx_file_is_tree">
    <is default="yes" name="class" value="class">class</is>
    <is default="yes" name="case" value="tolower">lowercase</is>
</xsl:variable>
<xsl:variable name="cxx_file_is" 
 select="exsl:node-set($cxx_file_is_tree)"/>

<xsl:variable name="cxx_file_name_is_tree">
    <is default="no" value="module">Module</is>
    <is default="no" value="class">Class</is>
    <is default="yes" value="no">no</is>
</xsl:variable>
<xsl:variable name="cxx_file_name_is" 
 select="exsl:node-set($cxx_file_name_is_tree)"/>

<xsl:variable name="cxx_file_case_is_tree">
    <is default="no" value="tocamel">camel</is>
    <is default="no" value="toupper">upper</is>
    <is default="no" value="tolower">lower</is>
    <is default="yes" value="no">no case</is>
</xsl:variable>
<xsl:variable name="cxx_file_case_is" 
 select="exsl:node-set($cxx_file_case_is_tree)"/>

<xsl:variable name="hxx_file_extensions_tree">
    <extension value="hxx">.hxx</extension>
    <extension value="hpp">.hpp</extension>
    <extension value="hh">.hh</extension>
    <extension value="h">.h</extension>
</xsl:variable>
<xsl:variable name="hxx_file_extensions" 
 select="exsl:node-set($hxx_file_extensions_tree)"/>

<xsl:variable name="cxx_file_extensions_tree">
    <extension value="cxx">.cxx</extension>
    <extension value="cpp">.cpp</extension>
    <extension value="cc">.cc</extension>
    <extension value="mm">.mm</extension>
    <extension value="c">.c</extension>
    <extension value="m">.m</extension>
</xsl:variable>
<xsl:variable name="cxx_file_extensions" 
 select="exsl:node-set($cxx_file_extensions_tree)"/>
    
<xsl:variable name="hxx_cxx_file_extensions_tree">
    <xsl:copy-of select="$hxx_file_extensions/*"/>
    <xsl:copy-of select="$cxx_file_extensions/*"/>
    <extension default="yes" value="">no</extension>
</xsl:variable>
<xsl:variable name="hxx_cxx_file_extensions" 
 select="exsl:node-set($hxx_cxx_file_extensions_tree)"/>

<xsl:variable name="c_file_types_tree">
    <type value="h">.h</type>
    <type value="c">.c</type>
    <type default="yes">no</type>
</xsl:variable>
<xsl:variable name="c_file_types" 
 select="exsl:node-set($c_file_types_tree)"/>
    
<xsl:variable name="hxx_file_types_tree">
    <type default="yes" value="hxx">.hxx</type>
    <type value="hpp">.hpp</type>
    <type value="h">.h</type>
</xsl:variable>
<xsl:variable name="hxx_file_types" 
 select="exsl:node-set($hxx_file_types_tree)"/>

<xsl:variable name="cxx_file_types_tree">
    <type value="cxx">.cxx</type>
    <type value="cpp">.cpp</type>
    <type value="c">.c</type>
    <type xdefault="yes">no</type>
</xsl:variable>
<xsl:variable name="cxx_file_types" 
 select="exsl:node-set($cxx_file_types_tree)"/>
    
<xsl:variable name="hxx_cxx_file_types_tree">
    <xsl:copy-of select="$hxx_file_types/*"/>
    <xsl:copy-of select="$cxx_file_types/*"/>
</xsl:variable>
<xsl:variable name="hxx_cxx_file_types" 
 select="exsl:node-set($hxx_cxx_file_types_tree)"/>

<xsl:variable name="cxx_comment_types_tree">
    <type value="cppp">///...</type>
    <type value="cxxx">/**...*/</type>
    <type value="cpp">//...</type>
    <type value="cxx">/*...*/</type>
    <type default="yes" value="yes">yes</type>
    <type value="no">no</type>
</xsl:variable>
<xsl:variable name="cxx_comment_types"
 select="exsl:node-set($cxx_comment_types_tree)"/>

<xsl:variable name="cxx_comment_fields_tree">
    <field name="copyright" value="copyright" default="yes">Copyright...</field>
    <field name="opensource" value="opensource" default="yes">This software...</field>
    <field name="author" value="author" default="yes">Author:...</field>
    <field name="date" value="date" default="yes">Date:...</field>
</xsl:variable>
<xsl:variable name="cxx_comment_fields"
 select="exsl:node-set($cxx_comment_fields_tree)"/>

<xsl:variable name="cxx_code_styles_tree">
    <style value="kr">K&amp;R</style>
    <style default="yes" value="no">no</style>
</xsl:variable>
<xsl:variable name="cxx_code_styles"
 select="exsl:node-set($cxx_code_styles_tree)"/>

<xsl:variable name="cxx_include_system_item_tree">
    <item></item>
    <item>stdio.h</item>
    <item>stdlib.h</item>
    <item>stdarg.h</item>
    <item>string.h</item>
    <item>sys/types.h</item>
    <item>sys/stat.h</item>
</xsl:variable>
<xsl:variable name="cxx_include_system_items" 
 select="exsl:node-set($cxx_include_system_item_tree)"/>

<xsl:variable name="cxx_include_item_tree">
    <item></item>
</xsl:variable>
<xsl:variable name="cxx_include_items" 
 select="exsl:node-set($cxx_include_item_tree)"/>

<!--========================================================================-->

<xsl:variable name="cxx_class_comment_fields_tree">
    <field name="author" value="author" default="yes">Author:...</field>
    <field name="date" value="date" default="yes">Date:...</field>
</xsl:variable>
<xsl:variable name="cxx_class_comment_fields"
 select="exsl:node-set($cxx_class_comment_fields_tree)"/>

<xsl:variable name="cxx_class_bases_prefixes_tree">
    <prefix default="yes" value="c">c</prefix>
    <prefix value="C">C</prefix>
    <prefix value="no">no</prefix>
</xsl:variable>
<xsl:variable name="cxx_class_bases_prefixes"
 select="exsl:node-set($cxx_class_bases_prefixes_tree)"/>
    
<xsl:variable name="cxx_class_access_tree_base">
    <access default="yes" value="public">public</access>
    <access value="protected">protected</access>
    <access value="private">private</access>
</xsl:variable>
<xsl:variable name="cxx_class_access_types_base" 
 select="exsl:node-set($cxx_class_access_tree_base)"/>

<xsl:variable name="cxx_class_access_tree">
    <xsl:copy-of select="$cxx_class_access_types_base/*"/>
    <access>no</access>
</xsl:variable>
<xsl:variable name="cxx_class_access_types" 
 select="exsl:node-set($cxx_class_access_tree)"/>

<xsl:variable name="cxx_class_access_tree_yesno">
    <xsl:copy-of select="$cxx_class_access_types_base/*"/>
    <access>yes</access>
    <access value="no">no</access>
</xsl:variable>
<xsl:variable name="cxx_class_access_types_yesno" 
 select="exsl:node-set($cxx_class_access_tree_yesno)"/>

<xsl:variable name="cxx_class_derivation_pattern_types_tree">
    <type value="tc">&lt;class T?=c?&gt;</type>
    <type value="t">&lt;class T?&gt;</type>
    <type value="c">c?</type>
    <type value="no" default="yes">no</type>
</xsl:variable>
<xsl:variable name="cxx_class_derivation_pattern_types" 
 select="exsl:node-set($cxx_class_derivation_pattern_types_tree)"/>

<xsl:variable name="cxx_class_template_is_tree">
    <is value="yes">yes</is>
    <is value="no" default="yes">no</is>
</xsl:variable>
<xsl:variable name="cxx_class_template_is" 
 select="exsl:node-set($cxx_class_template_is_tree)"/>
    
<xsl:variable name="cxx_class_interface_types_tree">
    <interface>interface</interface>
    <interface>implement</interface>
    <interface>instance</interface>
    <interface>export</interface>
    <interface default="yes" value="">no</interface>
</xsl:variable>
<xsl:variable name="cxx_class_interface_types"
 select="exsl:node-set($cxx_class_interface_types_tree)"/>
    
<xsl:variable name="cxx_class_constructor_types_tree">
    <type>explicit</type>
    <type>inline</type>
    <type>yes</type>
    <type default="yes" value="">no</type>
</xsl:variable>
<xsl:variable name="cxx_class_constructor_types"
 select="exsl:node-set($cxx_class_constructor_types_tree)"/>
    
<xsl:variable name="cxx_class_destructor_types_tree">
    <type>virtual</type>
    <type>yes</type>
    <type default="yes" value="">no</type>
</xsl:variable>
<xsl:variable name="cxx_class_destructor_types"
 select="exsl:node-set($cxx_class_destructor_types_tree)"/>

<xsl:variable name="cxx_class_function_types_tree">
    <type>virtual</type>
    <type>inline</type>
    <type>static</type>
    <type>yes</type>
    <type default="yes" value="">no</type>
</xsl:variable>
<xsl:variable name="cxx_class_function_types"
 select="exsl:node-set($cxx_class_function_types_tree)"/>
    
<xsl:variable name="cxx_class_function_const_proto_types_tree">
    <type value="yes" name="const">const</type>
    <type value="yes" name="prototype">;</type>
    <type value="yes" name="abstract">=0;</type>
</xsl:variable>
<xsl:variable name="cxx_class_function_const_proto_types"
 select="exsl:node-set($cxx_class_function_const_proto_types_tree)"/>
    
<!--========================================================================-->
    
<xsl:variable name="cxx_function_pattern_tree">
    <pattern value="doundo">Do/Undo</pattern>
    <pattern value="createdestroy">Create/Destroy</pattern>
    <pattern value="setget">Set/Get</pattern>
    <pattern default="yes" value="">no</pattern>
</xsl:variable>
<xsl:variable name="cxx_function_patterns"
 select="exsl:node-set($cxx_function_pattern_tree)"/>

<xsl:variable name="cxx_function_pattern_tree2">
    <pattern value="create">Create</pattern>
    <pattern value="destroy">Destroy</pattern>
    <pattern value="set">Set</pattern>
    <pattern value="get">Get</pattern>
    <pattern default="yes" value="">no</pattern>
</xsl:variable>
<xsl:variable name="cxx_function_patterns2"
 select="exsl:node-set($cxx_function_pattern_tree2)"/>

<xsl:variable name="cxx_function_pattern_name_item">
    <item></item>
    <item>Attach/Detach</item>
    <item>Create/Destroy</item>
    <item>Give/Take</item>
    <item>Initialize/Finalize</item>
    <item>Lock/Unlock</item>
    <item>Open/Close</item>
    <item>Read/Write</item>
    <item>Wait/Continue</item>
    <item>Set/Get</item>
    <item>Set/</item>
    <item>/Get</item>
</xsl:variable>
<xsl:variable name="cxx_function_pattern_name_list"
 select="exsl:node-set($cxx_function_pattern_name_item)"/>

<xsl:variable name="cxx_main_type_tree">
    <type>int</type>
    <type>void</type>
    <type default="yes">no</type>
</xsl:variable>
<xsl:variable name="cxx_main_types"
 select="exsl:node-set($cxx_main_type_tree)"/>

<xsl:variable name="cxx_main_main_parameters_item">
    <item default="yes" value="int argc;const char** argv;const char** env">int,const char**,const char**</item>
    <item value="int argc;char** argv;char** env">int,char**,char**</item>
    <item>void</item>
</xsl:variable>
<xsl:variable name="cxx_main_main_parameters_list"
 select="exsl:node-set($cxx_main_main_parameters_item)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

</xsl:transform>
