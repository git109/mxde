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
<!--   File: medusaxde-cgi-env-parameters.xsl                               -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/20/2011                                                      -->
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
<xsl:param name="cgi_env_SCRIPT_NAME" select="''"/> 
<xsl:param name="cgi_env_HTTP_USER_AGENT" select="''"/> 
<xsl:param name="cgi_env_HTTP_ACCEPT" select="''"/> 
<xsl:param name="cgi_env_REMOTE_IDENT" select="''"/>
<xsl:param name="cgi_env_REMOTE_HOST" select="''"/>
<xsl:param name="cgi_env_REQUEST_METHOD" select="''"/> 
<xsl:param name="cgi_env_REQUEST_LINE" select="''"/>
<xsl:param name="cgi_env_REMOTE_USER" select="''"/>
<xsl:param name="cgi_env_REMOTE_ADDR" select="''"/> 
<xsl:param name="cgi_env_QUERY_STRING" select="''"/> 
<xsl:param name="cgi_env_PATH_TRANSLATED" select="''"/>
<xsl:param name="cgi_env_PATH_INFO" select="''"/>
<xsl:param name="cgi_env_OUTPUT_FILE" select="''"/>
<xsl:param name="cgi_env_CONTENT_TYPE" select="''"/>
<xsl:param name="cgi_env_CONTENT_LENGTH" select="''"/>
<xsl:param name="cgi_env_CONTENT_FILE" select="''"/>
<xsl:param name="cgi_env_AUTH_TYPE" select="''"/>
<xsl:param name="cgi_env_SERVER_SOFTWARE" select="''"/> 
<xsl:param name="cgi_env_SERVER_PROTOCOL" select="''"/> 
<xsl:param name="cgi_env_SERVER_PORT" select="''"/> 
<xsl:param name="cgi_env_SERVER_NAME" select="''"/> 
<xsl:param name="cgi_env_GATEWAY_INTERFACE" select="''"/> 

</xsl:transform>
