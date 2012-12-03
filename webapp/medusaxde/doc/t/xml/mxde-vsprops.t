%########################################################################
%# Copyright (c) 1988-2009 $organization$     
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
%#   File: mxde-vsprops.t
%#
%# Author: $author$           
%#   Date: 12/5/2009
%########################################################################
%with(%
%html_,%(%if(%equal(text/html,%content_type%)%,%(<html><body><pre>)%)%)%,%
%_html,%(%if(%html_%,%(</pre></body></html>)%)%)%,%
%lt,%(%if(%html_%,%(&lt;)%,%(<)%)%)%,%
%gt,%(%if(%html_%,%(&gt;)%,%(>)%)%)%,%
%project,%(%else-then(%project%,%(Project)%)%)%,%
%Project,%(%else-then(%Project%,%(%project%)%)%)%,%
%PROJECT,%(%else-then(%PROJECT%,%(%toupper(%Project%)%)%)%)%,%
%project,%(%else-then(%_Project%,%(%tolower(%Project%)%)%)%)%,%
%project_version,%(%else-then(%project_version%,%(1.0.0)%)%)%,%
%project_Version,%(%else-then(%project_Version%,%(%project_version%)%)%)%,%
%project_VERSION,%(%else-then(%project_VERSION%,%(%toupper(%project_Version%)%)%)%)%,%
%project_version,%(%else-then(%project__Version%,%(%tolower(%project_Version%)%)%)%)%,%
%project_group,%(%else-then(%project_group%,%(%Project%)%)%)%,%
%project_Group,%(%else-then(%project_Group%,%(%project_group%)%)%)%,%
%project_GROUP,%(%else-then(%project_GROUP%,%(%toupper(%project_Group%)%)%)%)%,%
%project_group,%(%else-then(%project__Group%,%(%tolower(%project_Group%)%)%)%)%,%
%source_root_dir,%(%else-then(%source_root_Dir%,%(../../../../../..)%)%)%,%
%source_root_Dir,%(%else-then(%source_root_Dir%,%(%source_root_dir%)%)%)%,%
%source_root_DIR,%(%else-then(%source_root_DIR%,%(%toupper(%source_root_Dir%)%)%)%)%,%
%source_root_dir,%(%else-then(%source_root__Dir%,%(%tolower(%source_root_Dir%)%)%)%)%,%
%SOURCE_HOME,%(%else-then(%SOURCE_HOME%,%(SOURCE_HOME)%)%)%,%
%SOURCE_ROOT_DIR,%(%else-then(%SOURCE_ROOT_DIR%,%(SOURCE_ROOT_DIR)%)%)%,%
%SOURCE_BUILD_DIR,%(%else-then(%SOURCE_BUILD_DIR%,%(SOURCE_BUILD_DIR)%)%)%,%
%PROJECT_GROUP,%(%else-then(%PROJECT_GROUP%,%(%PROJECT%_GROUP)%)%)%,%
%PROJECT_NAME,%(%else-then(%PROJECT_NAME%,%(%PROJECT%_NAME)%)%)%,%
%PROJECT_VERSION,%(%else-then(%PROJECT_VERSION%,%(%PROJECT%_VERSION)%)%)%,%
%PROJECT_SOURCE_DIR,%(%else-then(%PROJECT_SOURCE_DIR%,%(%PROJECT%_SOURCE_DIR)%)%)%,%
%PROJECT_BUILD_DIR,%(%else-then(%PROJECT_BUILD_DIR%,%(%PROJECT%_BUILD_DIR)%)%)%,%
%PROJECT_DIR,%(%else-then(%PROJECT_DIR%,%(%PROJECT%_DIR)%)%)%,%
%PROJECT_BUILD,%(%else-then(%PROJECT_BUILD%,%(%PROJECT%_BUILD)%)%)%,%
%PROJECT_BUILD_OBJ,%(%else-then(%PROJECT_BUILD_OBJ%,%(%PROJECT%_OBJ)%)%)%,%
%PROJECT_BUILD_LIB,%(%else-then(%PROJECT_BUILD_LIB%,%(%PROJECT%_LIB)%)%)%,%
%PROJECT_BUILD_BIN,%(%else-then(%PROJECT_BUILD_BIN%,%(%PROJECT%_BIN)%)%)%,%
%PROJECT_INCLUDE_DIRS,%(%else-then(%PROJECT_INCLUDE_DIRS%,%(%PROJECT%_INCLUDE_DIRS)%)%)%,%
%PROJECT_LIB_DIRS,%(%else-then(%PROJECT_LIB_DIRS%,%(%PROJECT%_LIB_DIRS)%)%)%,%
%PROJECT_LIBS,%(%else-then(%PROJECT_LIBS%,%(%PROJECT%_LIBS)%)%)%,%
%INCLUDE_DIRS,%(%else-then(%INCLUDE_DIRS%,%(INCLUDE_DIRS)%)%)%,%
%LIB_DIRS,%(%else-then(%LIB_DIRS%,%(LIB_DIRS)%)%)%,%
%LIBS,%(%else-then(%LIBS%,%(LIBS)%)%)%,%
%BUILD_DIR,%(%else-then(%BUILD_DIR%,%(BUILD_DIR)%)%)%,%
%BUILD_OBJ,%(%else-then(%BUILD_OBJ%,%(BUILD_OBJ)%)%)%,%
%BUILD_LIB,%(%else-then(%BUILD_LIB%,%(BUILD_LIB)%)%)%,%
%BUILD_BIN,%(%else-then(%BUILD_BIN%,%(BUILD_BIN)%)%)%,%
%%(%
%%html_%
%lt%?xml version="1.0" encoding="Windows-1252"?%gt%
%lt%!--===============================================--%gt%
%lt%VisualStudioPropertySheet
	ProjectType="Visual C++"
	Version="8.00"
	Name="%Project%"
	%gt%
    
    %lt%UserMacro
		Name="%SOURCE_ROOT_DIR%"
		Value="%source_root_Dir%"
	/%gt%
    
    %lt%UserMacro
		Name="%SOURCE_BUILD_DIR%"
		Value="$(%SOURCE_HOME%)"
	/%gt%
    
    %lt%!--===============================================--%gt%
    
    %lt%UserMacro
		Name="%PROJECT_GROUP%"
		Value="%project_Group%"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_NAME%"
		Value="%Project%"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_VERSION%"
		Value="%project_Version%"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_DIR%"
		Value="$(%PROJECT_GROUP%)/$(%PROJECT_NAME%)-$(%PROJECT_VERSION%)"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_SOURCE_DIR%"
		Value="$(%SOURCE_ROOT_DIR%)/$(%PROJECT_DIR%)"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_BUILD_DIR%"
		Value="$(%SOURCE_BUILD_DIR%)/$(%PROJECT_DIR%)"
	/%gt%
	
    %lt%!--===============================================--%gt%

    %lt%UserMacro
		Name="%PROJECT_BUILD%"
		Value="$(%PROJECT_BUILD_DIR%)/build/$(PlatformName)/vc8/$(ConfigurationName)"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_BUILD_OBJ%"
		Value="$(%PROJECT_BUILD%)/obj"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_BUILD_LIB%"
		Value="$(%PROJECT_BUILD%)/lib"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_BUILD_BIN%"
		Value="$(%PROJECT_BUILD%)/bin"
	/%gt%
	
    %lt%UserMacro
		Name="%PROJECT_INCLUDE_DIRS%"
		Value="$(%PROJECT_SOURCE_DIR%)/include"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_LIB_DIRS%"
		Value="$(%PROJECT_BUILD_LIB%)"
	/%gt%
    %lt%UserMacro
		Name="%PROJECT_LIBS%"
		Value="%project_Libs%"
	/%gt%
	
    %lt%!--===============================================--%gt%
    
    %lt%UserMacro
		Name="%BUILD_DIR%"
		Value="$(%PROJECT_BUILD%)"
	/%gt%
    %lt%UserMacro
		Name="%BUILD_OBJ%"
		Value="$(%PROJECT_BUILD_OBJ%)"
	/%gt%
    %lt%UserMacro
		Name="%BUILD_LIB%"
		Value="$(%PROJECT_BUILD_LIB%)"
	/%gt%
    %lt%UserMacro
		Name="%BUILD_BIN%"
		Value="$(%PROJECT_BUILD_BIN%)"
	/%gt%

    %lt%UserMacro
		Name="%INCLUDE_DIRS%"
		Value="$(%PROJECT_INCLUDE_DIRS%)"
	/%gt%
    %lt%UserMacro
		Name="%LIB_DIRS%"
		Value="$(%PROJECT_LIB_DIRS%)"
	/%gt%
    %lt%UserMacro
		Name="%LIBS%"
		Value="$(%PROJECT_LIBS%)"
	/%gt%
	
%lt%/VisualStudioPropertySheet%gt%
%_html%
%
%)%)%