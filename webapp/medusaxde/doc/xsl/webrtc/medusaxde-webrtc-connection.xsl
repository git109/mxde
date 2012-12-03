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
<!--   File: medusaxde-webrtc-connection.xsl                                -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 11/29/2012                                                     -->
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
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Includes                                                               -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="userName" select="'username'"/>
<xsl:param name="serverName" select="'localhost'"/>
<xsl:param name="serverPort" select="'8888'"/>
<xsl:param name="videoCodecMode" select="'QVGA'"/>
<xsl:param name="mimeType" select="'application/x-xoswebrtcclientfbplugin'"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->

<!--========================================================================-->
<!-- Template: match "*"                                                    -->
<!--                                                                        -->
<!--   Author: $author$                                                     -->
<!--     Date: 11/29/2012                                                   -->
<!--========================================================================-->
<xsl:template match="*">
<html>
    <!--========================================================================-->
    <!--                                                                        -->
    <!-- head                                                                   -->
    <!--                                                                        -->
    <!--========================================================================-->
    <head>
        <title>WebRTC Connection</title>
        <!--========================================================================-->
        <!--                                                                        -->
        <!-- style                                                                  -->
        <!--                                                                        -->
        <!--========================================================================-->
        <style type="text/css">
            object
            {
                border: 5px solid gray;
                text-align: center;
                margin: 0 auto;
                float: left;
                width: 100%;
                height: 100%;
            }
            table.full
            {
                width: 100%;
                height: 100%;
            }
            tr.full
            {
                height: 100%;
            }
            td.full
            {
                width: 100%;
            }
        </style>
        <!--========================================================================-->
        <!--                                                                        -->
        <!-- script                                                                 -->
        <!--                                                                        -->
        <!--========================================================================-->
        <script language="JavaScript" type="text/JavaScript">
            function on_load()
            {
                add_eventListeners();
                connect_To_Server()
            }
            
            function add_eventListeners()
            {
                add_eventListener("FailedToConnectToServer", on_FailedToConnectToServer);
                add_eventListener("SignedIn", on_SignedIn);
            }
            function add_eventListener(name, listener) {
                if (plugin().addEventListener)
                    plugin().addEventListener(name, listener);
                else
                    plugin().attachEvent("on" + name, listener);
            }

            function on_FailedToConnectToServer(server) {
                alert("Failed to connect to server " + server);
                return true;
            }
            function on_SignedIn(message) {
                alert("SignedIn "+message);
                return true;
            }
            
            function connect_To_Server()
            {
                plugin().videoCodecMode = id_videoCodecMode().value;
                plugin().Signin(id_userName().value, id_serverName().value, id_serverPort().value);
                return false;
            }
            function disconnect_Server() 
            {
                plugin().Signout();
                id_videoCodecMode().value = plugin().videoCodecMode;
                return false;
            }

            function add_eventListener(name, listener)
            {
                if (plugin().addEventListener)
                    plugin().addEventListener(name, listener);
                else
                plugin().attachEvent("on" + name, listener);
            }

            function pluginOuter() 
            {
                return document.getElementById("id_pluginOuter");
            }
            function plugin() 
            {
                return document.getElementById("plugin");
            }
            
            function id_userName()
            { return document.getElementById("id_userName"); }
            function id_serverName()
            { return document.getElementById("id_serverName"); }
            function id_serverPort()
            { return document.getElementById("id_serverPort"); }
            function id_videoCodecMode()
            { return document.getElementById("id_videoCodecMode"); }

        </script>
    </head>
    <!--========================================================================-->
    <!--                                                                        -->
    <!-- body                                                                   -->
    <!--                                                                        -->
    <!--========================================================================-->
    <body onload="on_load()">
        <table class="full">
            <tr class="full"><td id="id_pluginOuter" class="full">
            <object id="plugin"
             type="{$mimeType}"
             xwidth="480" xheight="480"
             xxdrawingModel="NPDrawingModelInvalidatingCoreAnimation"
             xdrawingModel="NPDrawingModelCoreAnimation"
             drawingModel="NPDrawingModelCoreGraphics">
            </object>
            </td></tr>
            <tr><td>
            <form id="form" action="">
                <input id="id_userName" name="form_userName" value="{$userName}" />
                <input id="id_serverName" name="form_serverName" value="{$serverName}" />
                <input id="id_serverPort" name="form_serverPort" value="{$serverPort}" />
                <input id="id_videoCodecMode" name="form_videoCodecMode" value="{$videoCodecMode}" />
                <input type="submit" value="+" onclick="return connect_To_Server();"/>
                <input type="submit" value="-" onclick="return disconnect_Server();"/>
            </form>
            </td></tr>
        </table>
    </body>
</html>
</xsl:template>
</xsl:transform>

        

