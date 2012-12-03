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
%#   Date: 10/3/2009
%########################################################################
%with(%
%filename,%(%else-then(%filename%,%(%filename(%file%)%)%)%)%,%
%FileName,%(%else-then(%FileName%,%(%filename%)%)%)%,%
%FILENAME,%(%else-then(%FILENAME%,%(%toupper(%FileName%)%)%)%)%,%
%filename,%(%else-then(%_FileName%,%(%tolower(%FileName%)%)%)%)%,%
%name,%(%else-then(%name%,%(%filebase(%filename(%file%)%)%)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%%(%
%<?xml version="1.0"?>
<!-- %FileName% -->
<VisualStudioPropertySheet
    ProjectType="Visual C++"
    Version="8.00"
    Name="%name%"
    >
    
    <UserMacro
        Name="SOURCE"
        Value="..\..\..\..\.."
    />
    <UserMacro
        Name="BUILD"
        Value="$(SOURCE_HOME)\build"
    />
    <UserMacro
        Name="BUILD_WIN32"
        Value="$(BUILD)\win32\vc8"
    />
    <UserMacro
        Name="BUILD_WIN32_LIB"
        Value="$(BUILD_WIN32)\$(ConfigurationName)\lib"
    />
    <UserMacro
        Name="BUILD_WIN32_BIN"
        Value="$(BUILD_WIN32)\$(ConfigurationName)\bin"
    />
    <UserMacro
        Name="BUILD_WIN32_OBJ"
        Value="$(BUILD_WIN32)\$(ConfigurationName)\obj"
    />

    <UserMacro
        Name="%NAME%_VERSION"
        Value="1.0.0"
    />
    <UserMacro
        Name="%NAME%_DIR"
        Value="%name%\%name%-$(%NAME%_VERSION)"
    />

    <UserMacro
        Name="%NAME%_HOME"
        Value="$(SOURCE_HOME)\$(%NAME%_DIR)"
    />
    <UserMacro
        Name="%NAME%_BUILD"
        Value="$(%NAME%_HOME)\build"
    />
    <UserMacro
        Name="%NAME%_BUILD_WIN32"
        Value="$(%NAME%_BUILD)\vc8\win32"
    />
    <UserMacro
        Name="%NAME%_WIN32_BIN"
        Value="$(%NAME%_BUILD_WIN32)\$(ConfigurationName)\bin"
    />
    <UserMacro
        Name="%NAME%_WIN32_LIB"
        Value="$(%NAME%_BUILD_WIN32)\$(ConfigurationName)\lib"
    />
    <UserMacro
        Name="%NAME%_WIN32_OBJ"
        Value="$(%NAME%_BUILD_WIN32)\$(ConfigurationName)\obj"
    />

    <UserMacro
        Name="%NAME%_ROOT"
        Value="$(SOURCE)\$(%NAME%_DIR)"
    />
    <UserMacro
        Name="%NAME%_INCLUDES"
        Value="$(%NAME%_ROOT)"
    />
</VisualStudioPropertySheet>
%
%)%)%