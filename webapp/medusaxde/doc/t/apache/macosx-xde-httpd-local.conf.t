%########################################################################
%# Copyright (c) 1988-2012 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: macosx-xde-httpd-local.conf.t
%#
%# Author: $author$
%#   Date: 12/16/2012
%#
%# Template for Local httpd.conf file for Xde                             
%########################################################################
%with(%
%HOMEDRIVE,%(%else-then(%HOMEDRIVE%,%(%replace(\,/,%getenv(HOMEDRIVE)%)%)%)%)%,%
%HOMEPATH,%(%else-then(%HOMEPATH%,%(%replace(\,/,%getenv(HOMEPATH)%)%)%)%)%,%
%HOME,%(%else-then(%HOME%,%(%replace(\,/,%getenv(HOME)%)%)%)%)%,%
%HOME,%(%else-then(%HOME%,%(%HOMEDRIVE%%HOMEPATH%)%)%)%,%
%exe,%(%else-then(%exe%,%(%if(%HOMEDRIVE%,%(.exe)%)%)%)%)%,%
%file,%(%else-then(%file%,%(httpd-local.conf)%)%)%,%
%date,%(%else-then(%date%,%(%date()%)%)%)%,%
%%(#########################################################################
# Copyright (c) 1988-2012 $organization$                                 
#                                                                        
# This software is provided by the author and contributors ``as is''     
# and any express or implied warranties, including, but not limited to,  
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors   
# be liable for any direct, indirect, incidental, special, exemplary,    
# or consequential damages (including, but not limited to, procurement   
# of substitute goods or services; loss of use, data, or profits; or     
# business interruption) however caused and on any theory of liability,  
# whether in contract, strict liability, or tort (including negligence   
# or otherwise) arising in any way out of the use of this software,      
# even if advised of the possibility of such damage.                     
#                                                                        
#   File: %file%                                               
#                                                                        
# Author: $author$                                                       
#   Date: %date%                        
#
# Local httpd.conf file for Xde                             
#########################################################################

#########################################################################
# Aliases 
# ... 
#########################################################################
<IfModule mod_alias.c>

#########################################################################
# Alias /source/ 
#########################################################################
Alias /source/ "%HOME%/source/"
<Directory "%HOME%/source/">
    Options Indexes MultiViews FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
</Directory>

#########################################################################
# Alias /medusaxde/ 
#########################################################################
Alias /medusaxde/ "%HOME%/source/mxde/webapp/medusaxde/doc/"
<Directory "%HOME%/source/mxde/webapp/">
    Options Indexes MultiViews FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
</Directory>

#########################################################################
# ScriptAlias /medusaxde-cgi/ 
#########################################################################
ScriptAlias /medusaxde-cgi/ "%HOME%/build/medusaxde/bin/"
<Directory "%HOME%/build/medusaxde/bin/">
    PassEnv DYLD_LIBRARY_PATH
    Options  FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
</Directory>

#########################################################################
# ScriptAlias /xde-cgi/ 
#########################################################################
ScriptAlias /xde-cgi/ "%HOME%/build/xde/bin/"
<Directory "%HOME%/build/xde/bin/">
    PassEnv DYLD_LIBRARY_PATH
    Options  FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
</Directory>

#########################################################################
# AddType application/x-httpd-cxx 
#########################################################################
AddType application/x-httpd-cxx .h
AddType application/x-httpd-cxx .c
AddType application/x-httpd-cxx .m
AddType application/x-httpd-cxx .hh
AddType application/x-httpd-cxx .cc
AddType application/x-httpd-cxx .mm
AddType application/x-httpd-cxx .hpp
AddType application/x-httpd-cxx .cpp
AddType application/x-httpd-cxx .hxx
AddType application/x-httpd-cxx .cxx

#########################################################################
# AddType application/x-httpd-t 
#########################################################################
AddType application/x-httpd-t .t

#########################################################################
# AddType application/x-httpd-xsl 
#########################################################################
AddType application/x-httpd-xsl .xsl
AddType application/x-httpd-xsl .xslt

#########################################################################
# Action application/x-httpd-cxx 
#########################################################################
Action application/x-httpd-cxx /xde-cgi/cxxlcgi%exe%

#########################################################################
# Action application/x-httpd-t 
#########################################################################
Action application/x-httpd-t /xde-cgi/tcgi%exe%

#########################################################################
# Action application/x-httpd-xsl 
#########################################################################
Action application/x-httpd-xsl /medusaxde-cgi/clibxsltcgi%exe%

</IfModule>
#########################################################################
# ... 
# Aliases 
#########################################################################

#########################################################################
# Autoindex 
# ... 
#########################################################################
<IfModule mod_autoindex.c>
IndexOptions FancyIndexing FoldersFirst
</IfModule>
#########################################################################
# ... 
# Autoindex 
#########################################################################
)%)%