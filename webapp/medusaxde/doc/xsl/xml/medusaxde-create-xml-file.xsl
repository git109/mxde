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
<!--   File: medusaxde-create-xml-file.xsl                                  -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 11/30/2012                                                     -->
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
<xsl:include href="../medusaxde-create.xsl"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="default_xde_form_title_what" select="'XML File'"/>
<xsl:param name="default_xde_form_action" select="'/medusaxde/t/xml/mxde-xml.t'"/>

<xsl:param name="default_xde_form_onsubmit_is_location" select="''"/>
<xsl:param name="default_xde_form_output_type" select="'text'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="xml_file_extensions_tree">
    <type value="xml">.xml</type>
    <type default="yes" value="">no</type>
</xsl:variable>
<xsl:variable name="xml_file_extensions"
 select="exsl:node-set($xml_file_extensions_tree)"/>

<xsl:variable name="xml_encoding_types_tree">
    <type value="utf-8">UTF-8</type>
    <type default="yes" value="no">none</type>
</xsl:variable>
<xsl:variable name="xml_encoding_types"
 select="exsl:node-set($xml_encoding_types_tree)"/>
    
<xsl:variable name="xml_stylesheet_types_tree">
    <type>text/xsl</type>
    <type default="yes" value="no">none</type>
</xsl:variable>
<xsl:variable name="xml_stylesheet_types"
 select="exsl:node-set($xml_stylesheet_types_tree)"/>

<xsl:variable name="xml_doctype_types_tree">
    <type>PUBLIC</type>
    <type default="yes" value="no">[</type>
</xsl:variable>
<xsl:variable name="xml_doctype_types"
 select="exsl:node-set($xml_doctype_types_tree)"/>
    
<xsl:variable name="xml_entity_types_tree">
    <type>SYSTEM</type>
    <type default="yes" value="no">none</type>
</xsl:variable>
<xsl:variable name="xml_entity_types"
 select="exsl:node-set($xml_entity_types_tree)"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: "xml_file_form_fields"                                       -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/30/2012                                                   -->
<!--========================================================================-->
<xsl:template name="xml_file_form_fields">
    <xsl:param name="is_param_" select="'yes'"/>
    <xsl:param name="is_param_section" select="$is_param_"/>
    <xsl:param name="section_text" select="''"/>
    <xsl:param name="is_param_content_type" select="$is_param_"/>
    <xsl:param name="content_type" select="'text/html'"/>
    <xsl:param name="is_param_file" select="$is_param_"/>
    <xsl:param name="is_param_file_extension" select="$is_param_"/>

    <xsl:param name="file_extension_text" select="''"/>
    <xsl:param name="file_extension_text_before" select="''"/>
    <xsl:param name="file_extension_text_after" select="''"/>
    <xsl:param name="file_extension_option" select="''"/>
    <xsl:param name="file_extension_options" select="$xml_file_extensions/*"/>
    <xsl:param name="file_extension_param" select="'file_type_extension'"/>
    <xsl:param name="file_extension" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="file_type_form_fields">
        <xsl:with-param name="is_param_section" select="$is_param_section"/>
        <xsl:with-param name="section_text" select="$section_text"/>
        <xsl:with-param name="is_param_content_type" select="$is_param_content_type"/>
        <xsl:with-param name="content_type" select="$content_type"/>
        <xsl:with-param name="is_param_file" select="$is_param_file"/>
    </xsl:call-template>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_file_extension)) or ('yes' = $is_param_file_extension)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$file_extension_text"/>
            <xsl:with-param name="text_before" select="$file_extension_text_before"/>
            <xsl:with-param name="text_after" select="$file_extension_text_after"/>
            <xsl:with-param name="name" select="$file_extension_param"/>
            <xsl:with-param name="value" select="$file_extension"/>
            <xsl:with-param name="option" select="$file_extension_options"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<!--========================================================================-->
<!-- Template: "xml_element_form_fields"                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/30/2012                                                   -->
<!--========================================================================-->
<xsl:template name="xml_element_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_param_xml_element" select="''"/>
    <xsl:param name="is_param_xml_element_ns" select="''"/>
    <xsl:param name="is_param_xml_element_ns_uri" select="''"/>
    <xsl:param name="is_param_xml_element_ns_is_uri" select="''"/>
    <xsl:param name="is_param_xml_element_attr" select="''"/>
    <xsl:param name="is_param_xml_element_attr_value" select="''"/>

    <xsl:param name="xml_element_text" select="'element'"/>
    <xsl:param name="xml_element_text_before" select="'&lt;'"/>
    <xsl:param name="xml_element_text_after" select="''"/>
    <xsl:param name="xml_element_param" select="'xml_element'"/>
    <xsl:param name="xml_element" select="''"/>

    <xsl:param name="xml_element_ns_text" select="''"/>
    <xsl:param name="xml_element_ns_text_before" select="'xmlns:'"/>
    <xsl:param name="xml_element_ns_text_after" select="''"/>
    <xsl:param name="xml_element_ns_param" select="'xml_element_ns'"/>
    <xsl:param name="xml_element_ns" select="''"/>

    <xsl:param name="xml_element_ns_uri_text" select="''"/>
    <xsl:param name="xml_element_ns_uri_text_before" select="'=&quot;'"/>
    <xsl:param name="xml_element_ns_uri_text_after" select="'&quot;'"/>
    <xsl:param name="xml_element_ns_uri_param" select="'xml_element_ns_uri'"/>
    <xsl:param name="xml_element_ns_uri" select="''"/>

    <xsl:param name="xml_element_ns_is_uri_text" select="''"/>
    <xsl:param name="xml_element_ns_is_uri_text_before" select="'xmlns=&quot;'"/>
    <xsl:param name="xml_element_ns_is_uri_text_after" select="'&quot;'"/>
    <xsl:param name="xml_element_ns_is_uri_param" select="'xml_element_ns_is_uri'"/>
    <xsl:param name="xml_element_ns_is_uri" select="''"/>

    <xsl:param name="xml_element_attr_text" select="'attr'"/>
    <xsl:param name="xml_element_attr_text_before" select="''"/>
    <xsl:param name="xml_element_attr_text_after" select="''"/>
    <xsl:param name="xml_element_attr_param" select="'xml_element_attr'"/>
    <xsl:param name="xml_element_attr" select="''"/>

    <xsl:param name="xml_element_attr_value_text" select="''"/>
    <xsl:param name="xml_element_attr_value_text_before" select="'=&quot;'"/>
    <xsl:param name="xml_element_attr_value_text_after" select="'&quot;&gt;'"/>
    <xsl:param name="xml_element_attr_value_param" select="'xml_element_attr_value'"/>
    <xsl:param name="xml_element_attr_value" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element)) or ('yes' = $is_param_xml_element)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_element_text"/>
            <xsl:with-param name="text_before" select="$xml_element_text_before"/>
            <xsl:with-param name="text_after" select="$xml_element_text_after"/>
            <xsl:with-param name="name" select="$xml_element_param"/>
            <xsl:with-param name="value" select="$xml_element"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element_ns)) or ('yes' = $is_param_xml_element_ns)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_element_ns_text"/>
            <xsl:with-param name="text_before" select="$xml_element_ns_text_before"/>
            <xsl:with-param name="text_after" select="$xml_element_ns_text_after"/>
            <xsl:with-param name="name" select="$xml_element_ns_param"/>
            <xsl:with-param name="value" select="$xml_element_ns"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element_ns_uri)) or ('yes' = $is_param_xml_element_ns_uri)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_element_ns_uri_text"/>
            <xsl:with-param name="text_before" select="$xml_element_ns_uri_text_before"/>
            <xsl:with-param name="text_after" select="$xml_element_ns_uri_text_after"/>
            <xsl:with-param name="name" select="$xml_element_ns_uri_param"/>
            <xsl:with-param name="value" select="$xml_element_ns_uri"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element_ns_is_uri)) or ('yes' = $is_param_xml_element_ns_is_uri)">
    <xsl:call-template name="input_row">
        <xsl:with-param name="text" select="$xml_element_ns_is_uri_text"/>
        <xsl:with-param name="text_before" select="$xml_element_ns_is_uri_text_before"/>
        <xsl:with-param name="text_after" select="$xml_element_ns_is_uri_text_after"/>
        <xsl:with-param name="name" select="$xml_element_ns_is_uri_param"/>
        <xsl:with-param name="value" select="$xml_element_ns_is_uri"/>
    </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element_attr)) or ('yes' = $is_param_xml_element_attr)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_element_attr_text"/>
            <xsl:with-param name="text_before" select="$xml_element_attr_text_before"/>
            <xsl:with-param name="text_after" select="$xml_element_attr_text_after"/>
            <xsl:with-param name="name" select="$xml_element_attr_param"/>
            <xsl:with-param name="value" select="$xml_element_attr"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element_attr_value)) or ('yes' = $is_param_xml_element_attr_value)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_element_attr_value_text"/>
            <xsl:with-param name="text_before" select="$xml_element_attr_value_text_before"/>
            <xsl:with-param name="text_after" select="$xml_element_attr_value_text_after"/>
            <xsl:with-param name="name" select="$xml_element_attr_value_param"/>
            <xsl:with-param name="value" select="$xml_element_attr_value"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "xml_form_fields"                                            -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/30/2012                                                   -->
<!--========================================================================-->
<xsl:template name="xml_form_fields">
    <xsl:param name="is_param_" select="''"/>
    <xsl:param name="is_section" select="''"/>
    <xsl:param name="is_param_section" select="$is_section"/>
    <xsl:param name="is_param_separators" select="''"/>
    <xsl:param name="is_param_xml_version" select="''"/>
    <xsl:param name="is_param_xml_encoding" select="$is_param_xml_version"/>
    <xsl:param name="is_param_xml_stylesheet" select="''"/>
    <xsl:param name="is_param_xml_stylesheet_href" select="$is_param_xml_stylesheet"/>
    <xsl:param name="is_param_xml_document" select="''"/>
    <xsl:param name="is_param_xml_document_ns" select="$is_param_xml_document"/>
    <xsl:param name="is_param_xml_document_ns_uri" select="$is_param_xml_document"/>
    <xsl:param name="is_param_xml_document_ns_is_uri" select="$is_param_xml_document"/>
    <xsl:param name="is_param_xml_document_attr" select="$is_param_xml_document"/>
    <xsl:param name="is_param_xml_document_attr_value" select="$is_param_xml_document"/>
    <xsl:param name="is_param_xml_element" select="''"/>
    <xsl:param name="is_param_xml_element_ns" select="$is_param_xml_element"/>
    <xsl:param name="is_param_xml_element_ns_uri" select="$is_param_xml_element"/>
    <xsl:param name="is_param_xml_element_attr" select="$is_param_xml_element"/>
    <xsl:param name="is_param_xml_element_attr_value" select="$is_param_xml_element"/>
    <xsl:param name="is_param_xml_doctype" select="''"/>
    <xsl:param name="is_param_xml_doctype_type" select="$is_param_xml_doctype"/>
    <xsl:param name="is_param_xml_doctype_identifier" select="$is_param_xml_doctype"/>
    <xsl:param name="is_param_xml_doctype_href" select="$is_param_xml_doctype"/>
    <xsl:param name="is_param_xml_entity" select="$is_param_xml_doctype"/>
    <xsl:param name="is_param_xml_entity_type" select="$is_param_xml_entity"/>
    <xsl:param name="is_param_xml_entity_value" select="$is_param_xml_entity"/>

    <xsl:param name="section_text" select="'XML Parameters'"/>

    <xsl:param name="xml_version_text" select="''"/>
    <xsl:param name="xml_version_text_before" select="'&lt;?xml version=&quot;'"/>
    <xsl:param name="xml_version_text_after" select="'&quot;'"/>
    <xsl:param name="xml_version_param" select="'xml_version'"/>
    <xsl:param name="xml_version" select="''"/>

    <xsl:param name="xml_encoding_text" select="''"/>
    <xsl:param name="xml_encoding_text_before" select="'encoding=&quot;'"/>
    <xsl:param name="xml_encoding_text_after" select="'&quot;?&gt;'"/>
    <xsl:param name="xml_encoding_param" select="'xml_encoding'"/>
    <xsl:param name="xml_encoding" select="''"/>

    <xsl:param name="xml_stylesheet_text" select="''"/>
    <xsl:param name="xml_stylesheet_text_before" select="'&lt;?xml-stylesheet type=&quot;'"/>
    <xsl:param name="xml_stylesheet_text_after" select="'&quot;'"/>
    <xsl:param name="xml_stylesheet_param" select="'xml_stylesheet'"/>
    <xsl:param name="xml_stylesheet" select="''"/>

    <xsl:param name="xml_stylesheet_href_text" select="''"/>
    <xsl:param name="xml_stylesheet_href_text_before" select="'href=&quot;'"/>
    <xsl:param name="xml_stylesheet_href_text_after" select="'&quot;?&gt;'"/>
    <xsl:param name="xml_stylesheet_href_param" select="'xml_stylesheet_href'"/>
    <xsl:param name="xml_stylesheet_href" select="''"/>

    <xsl:param name="xml_doctype_text" select="''"/>
    <xsl:param name="xml_doctype_text_before" select="'&lt;!DOCTYPE'"/>
    <xsl:param name="xml_doctype_text_after" select="''"/>
    <xsl:param name="xml_doctype_param" select="'xml_doctype'"/>
    <xsl:param name="xml_doctype" select="''"/>

    <xsl:param name="xml_doctype_type_text" select="''"/>
    <xsl:param name="xml_doctype_type_text_before" select="''"/>
    <xsl:param name="xml_doctype_type_text_after" select="''"/>
    <xsl:param name="xml_doctype_type_param" select="'xml_doctype_type'"/>
    <xsl:param name="xml_doctype_type" select="''"/>

    <xsl:param name="xml_doctype_identifier_text" select="''"/>
    <xsl:param name="xml_doctype_identifier_text_before" select="'&quot;'"/>
    <xsl:param name="xml_doctype_identifier_text_after" select="'&quot;'"/>
    <xsl:param name="xml_doctype_identifier_param" select="'xml_doctype_identifier'"/>
    <xsl:param name="xml_doctype_identifier" select="''"/>

    <xsl:param name="xml_doctype_href_text" select="''"/>
    <xsl:param name="xml_doctype_href_text_before" select="'&quot;'"/>
    <xsl:param name="xml_doctype_href_text_after" select="'&quot;'"/>
    <xsl:param name="xml_doctype_href_param" select="'xml_doctype_href'"/>
    <xsl:param name="xml_doctype_href" select="''"/>
    <xsl:param name="xml_entity_text" select="''"/>

    <xsl:param name="xml_entity_text_before" select="'&lt;!ENTITY'"/>
    <xsl:param name="xml_entity_text_after" select="''"/>
    <xsl:param name="xml_entity_param" select="'xml_entity'"/>
    <xsl:param name="xml_entity" select="''"/>

    <xsl:param name="xml_entity_type_text" select="''"/>
    <xsl:param name="xml_entity_type_text_before" select="''"/>
    <xsl:param name="xml_entity_type_text_after" select="''"/>
    <xsl:param name="xml_entity_type_param" select="'xml_entity_type'"/>
    <xsl:param name="xml_entity_type" select="''"/>

    <xsl:param name="xml_entity_value_text" select="''"/>
    <xsl:param name="xml_entity_value_text_before" select="'&quot;'"/>
    <xsl:param name="xml_entity_value_text_after" select="'&quot;&gt;]&gt;'"/>
    <xsl:param name="xml_entity_value_param" select="'xml_entity_value'"/>
    <xsl:param name="xml_entity_value" select="''"/>

    <xsl:param name="xml_document_text" select="'document'"/>
    <xsl:param name="xml_document_text_before" select="'&lt;'"/>
    <xsl:param name="xml_document_text_after" select="''"/>
    <xsl:param name="xml_document_param" select="'xml_document'"/>
    <xsl:param name="xml_document" select="''"/>

    <xsl:param name="xml_document_ns_text" select="''"/>
    <xsl:param name="xml_document_ns_text_before" select="'xmlns:'"/>
    <xsl:param name="xml_document_ns_text_after" select="''"/>
    <xsl:param name="xml_document_ns_param" select="'xml_document_ns'"/>
    <xsl:param name="xml_document_ns" select="''"/>

    <xsl:param name="xml_document_ns_uri_text" select="''"/>
    <xsl:param name="xml_document_ns_uri_text_before" select="'=&quot;'"/>
    <xsl:param name="xml_document_ns_uri_text_after" select="'&quot;'"/>
    <xsl:param name="xml_document_ns_uri_param" select="'xml_document_ns_uri'"/>
    <xsl:param name="xml_document_ns_uri" select="''"/>

    <xsl:param name="xml_document_ns_is_uri_text" select="''"/>
    <xsl:param name="xml_document_ns_is_uri_text_before" select="'xmlns=&quot;'"/>
    <xsl:param name="xml_document_ns_is_uri_text_after" select="'&quot;'"/>
    <xsl:param name="xml_document_ns_is_uri_param" select="'xml_document_ns_is_uri'"/>
    <xsl:param name="xml_document_ns_is_uri" select="''"/>

    <xsl:param name="xml_document_attr_text" select="'attr'"/>
    <xsl:param name="xml_document_attr_text_before" select="''"/>
    <xsl:param name="xml_document_attr_text_after" select="''"/>
    <xsl:param name="xml_document_attr_param" select="'xml_document_attr'"/>
    <xsl:param name="xml_document_attr" select="''"/>

    <xsl:param name="xml_document_attr_value_text" select="''"/>
    <xsl:param name="xml_document_attr_value_text_before" select="'=&quot;'"/>
    <xsl:param name="xml_document_attr_value_text_after" select="'&quot;&gt;'"/>
    <xsl:param name="xml_document_attr_value_param" select="'xml_document_attr_value'"/>
    <xsl:param name="xml_document_attr_value" select="''"/>

    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_section)) or ('yes' = $is_param_section)">
        <xsl:call-template name="section_row">
            <xsl:with-param name="text" select="$section_text"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_version)) or ('yes' = $is_param_xml_version)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_version_text"/>
            <xsl:with-param name="text_before" select="$xml_version_text_before"/>
            <xsl:with-param name="text_after" select="$xml_version_text_after"/>
            <xsl:with-param name="name" select="$xml_version_param"/>
            <xsl:with-param name="value" select="$xml_version"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_encoding)) or ('yes' = $is_param_xml_encoding)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xml_encoding_text"/>
            <xsl:with-param name="text_before" select="$xml_encoding_text_before"/>
            <xsl:with-param name="text_after" select="$xml_encoding_text_after"/>
            <xsl:with-param name="name" select="$xml_encoding_param"/>
            <xsl:with-param name="value" select="$xml_encoding"/>
            <xsl:with-param name="option" select="$xml_encoding_types/*"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separators)) or ('yes' = $is_param_separators)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_stylesheet)) or ('yes' = $is_param_xml_stylesheet)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xml_stylesheet_text"/>
            <xsl:with-param name="text_before" select="$xml_stylesheet_text_before"/>
            <xsl:with-param name="text_after" select="$xml_stylesheet_text_after"/>
            <xsl:with-param name="name" select="$xml_stylesheet_param"/>
            <xsl:with-param name="value" select="$xml_stylesheet"/>
            <xsl:with-param name="option" select="$xml_stylesheet_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_stylesheet_href)) or ('yes' = $is_param_xml_stylesheet_href)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_stylesheet_href_text"/>
            <xsl:with-param name="text_before" select="$xml_stylesheet_href_text_before"/>
            <xsl:with-param name="text_after" select="$xml_stylesheet_href_text_after"/>
            <xsl:with-param name="name" select="$xml_stylesheet_href_param"/>
            <xsl:with-param name="value" select="$xml_stylesheet_href"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separators)) or ('yes' = $is_param_separators)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_doctype)) or ('yes' = $is_param_xml_doctype)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_doctype_text"/>
            <xsl:with-param name="text_before" select="$xml_doctype_text_before"/>
            <xsl:with-param name="text_after" select="$xml_doctype_text_after"/>
            <xsl:with-param name="name" select="$xml_doctype_param"/>
            <xsl:with-param name="value" select="$xml_doctype"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_doctype_type)) or ('yes' = $is_param_xml_doctype_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xml_doctype_type_text"/>
            <xsl:with-param name="text_before" select="$xml_doctype_type_text_before"/>
            <xsl:with-param name="text_after" select="$xml_doctype_type_text_after"/>
            <xsl:with-param name="name" select="$xml_doctype_type_param"/>
            <xsl:with-param name="value" select="$xml_doctype_type"/>
            <xsl:with-param name="option" select="$xml_doctype_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_doctype_identifier)) or ('yes' = $is_param_xml_doctype_identifier)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_doctype_identifier_text"/>
            <xsl:with-param name="text_before" select="$xml_doctype_identifier_text_before"/>
            <xsl:with-param name="text_after" select="$xml_doctype_identifier_text_after"/>
            <xsl:with-param name="name" select="$xml_doctype_identifier_param"/>
            <xsl:with-param name="value" select="$xml_doctype_identifier"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_doctype_href)) or ('yes' = $is_param_xml_doctype_href)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_doctype_href_text"/>
            <xsl:with-param name="text_before" select="$xml_doctype_href_text_before"/>
            <xsl:with-param name="text_after" select="$xml_doctype_href_text_after"/>
            <xsl:with-param name="name" select="$xml_doctype_href_param"/>
            <xsl:with-param name="value" select="$xml_doctype_href"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_entity)) or ('yes' = $is_param_xml_entity)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_entity_text"/>
            <xsl:with-param name="text_before" select="$xml_entity_text_before"/>
            <xsl:with-param name="text_after" select="$xml_entity_text_after"/>
            <xsl:with-param name="name" select="$xml_entity_param"/>
            <xsl:with-param name="value" select="$xml_entity"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_entity_type)) or ('yes' = $is_param_xml_entity_type)">
        <xsl:call-template name="radios_row">
            <xsl:with-param name="text" select="$xml_entity_type_text"/>
            <xsl:with-param name="text_before" select="$xml_entity_type_text_before"/>
            <xsl:with-param name="text_after" select="$xml_entity_type_text_after"/>
            <xsl:with-param name="name" select="$xml_entity_type_param"/>
            <xsl:with-param name="value" select="$xml_entity_type"/>
            <xsl:with-param name="option" select="$xml_entity_types/*"/>
        </xsl:call-template>
    </xsl:if>
    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_entity_value)) or ('yes' = $is_param_xml_entity_value)">
        <xsl:call-template name="input_row">
            <xsl:with-param name="text" select="$xml_entity_value_text"/>
            <xsl:with-param name="text_before" select="$xml_entity_value_text_before"/>
            <xsl:with-param name="text_after" select="$xml_entity_value_text_after"/>
            <xsl:with-param name="name" select="$xml_entity_value_param"/>
            <xsl:with-param name="value" select="$xml_entity_value"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separators)) or ('yes' = $is_param_separators)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_document)) or ('yes' = $is_param_xml_document)">
        <xsl:call-template name="xml_element_form_fields">
            <xsl:with-param name="is_param_xml_element" select="$is_param_xml_document"/>
            <xsl:with-param name="is_param_xml_element_ns" select="$is_param_xml_document_ns"/>
            <xsl:with-param name="is_param_xml_element_ns_uri" select="$is_param_xml_document_ns_uri"/>
            <xsl:with-param name="is_param_xml_element_ns_is_uri" select="$is_param_xml_document_ns_is_uri"/>
            <xsl:with-param name="is_param_xml_element_attr" select="$is_param_xml_document_attr"/>
            <xsl:with-param name="is_param_xml_element_attr_value" select="$is_param_xml_document_attr_value"/>
            <xsl:with-param name="xml_element" select="$xml_document"/>
            <xsl:with-param name="xml_element_text" select="$xml_document_text"/>
            <xsl:with-param name="xml_element_param" select="$xml_document_param"/>
            <xsl:with-param name="xml_element_ns" select="$xml_document_ns"/>
            <xsl:with-param name="xml_element_ns_param" select="$xml_document_ns_param"/>
            <xsl:with-param name="xml_element_ns_uri" select="$xml_document_ns_uri"/>
            <xsl:with-param name="xml_element_ns_uri_param" select="$xml_document_ns_uri_param"/>
            <xsl:with-param name="xml_element_ns_is_uri_param" select="$xml_document_ns_is_uri_param"/>
            <xsl:with-param name="xml_element_attr" select="$xml_document_attr"/>
            <xsl:with-param name="xml_element_attr_text" select="$xml_document_attr_text"/>
            <xsl:with-param name="xml_element_attr_param" select="$xml_document_attr_param"/>
            <xsl:with-param name="xml_element_attr_value" select="$xml_document_attr_value"/>
            <xsl:with-param name="xml_element_attr_value_param" select="$xml_document_attr_value_param"/>
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_separators)) or ('yes' = $is_param_separators)">
        <xsl:call-template name="separator_section_row">
        </xsl:call-template>
    </xsl:if>

    <xsl:if test="(('no' != $is_param_) and ('no' != $is_param_xml_element)) or ('yes' = $is_param_xml_element)">
        <xsl:call-template name="xml_element_form_fields">
        </xsl:call-template>
    </xsl:if>
</xsl:template>
    
<!--========================================================================-->
<!-- Template: "create_form_fields"                                         -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/30/2012                                                   -->
<!--========================================================================-->
<xsl:template name="create_form_fields">
    <!--========================================================================-->
    <!-- Template Body                                                          -->
    <!--========================================================================-->
    <xsl:call-template name="xml_file_form_fields">
    </xsl:call-template>
    <xsl:call-template name="xml_form_fields">
    </xsl:call-template>
</xsl:template>
</xsl:transform>
