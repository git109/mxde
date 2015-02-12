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
%#   File: mxde-project-makefile.t
%#
%# Author: $author$
%#   Date: 3/30/2012
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%this_includefile,%(%else-then(%this_includefile%,%(%filename(%input%)%)%)%)%,%
%this_includefile_base,%(%else-then(%this_includefile_base%,%(%filebase(%this_includefile%)%)%)%)%,%
%base_includefile,%(%filepath%/mxde-makefile.t)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%with(%
%platform,%(%else-then(%platform%,%(Linux)%)%)%,%
%Platform,%(%else-then(%Platform%,%(%platform%)%)%)%,%
%PLATFORM,%(%else-then(%PLATFORM%,%(%toupper(%Platform%)%)%)%)%,%
%platform,%(%else-then(%_Platform%,%(%tolower(%Platform%)%)%)%)%,%
%tools,%(%else-then(%tools%,%(Gcc)%)%)%,%
%Tools,%(%else-then(%Tools%,%(%tools%)%)%)%,%
%TOOLS,%(%else-then(%TOOLS%,%(%toupper(%Tools%)%)%)%)%,%
%tools,%(%else-then(%_Tools%,%(%tolower(%Tools%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Xde)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%pkg_path,%(%else-then(%pkg_path%,%()%)%)%,%
%Pkg_path,%(%else-then(%Pkg_path%,%(%pkg_path%)%)%)%,%
%PKG_PATH,%(%else-then(%PKG_PATH%,%(%toupper(%Pkg_path%)%)%)%)%,%
%pkg_path,%(%else-then(%_Pkg_path%,%(%tolower(%Pkg_path%)%)%)%)%,%
%pkg_dir,%(%else-then(%pkg_dir%,%(../../../../../..)%)%)%,%
%Pkg_dir,%(%else-then(%Pkg_dir%,%(%pkg_dir%)%)%)%,%
%PKG_DIR,%(%else-then(%PKG_DIR%,%(%toupper(%Pkg_dir%)%)%)%)%,%
%pkg_dir,%(%else-then(%_Pkg_dir%,%(%tolower(%Pkg_dir%)%)%)%)%,%
%pkg,%(%else-then(%pkg%,%(%if-then(%Pkg_path%,%if(%Pkg_dir%,/)%)%%Pkg_dir%)%)%)%,%
%Pkg,%(%else-then(%Pkg%,%(%pkg%)%)%)%,%
%PKG,%(%else-then(%PKG%,%(%toupper(%Pkg%)%)%)%)%,%
%pkg,%(%else-then(%_Pkg%,%(%tolower(%Pkg%)%)%)%)%,%
%mak_dir,%(%else-then(%mak_dir%,%(Makefile%then-if(%Tools%,/)%)%)%)%,%
%Mak_dir,%(%else-then(%Mak_dir%,%(%mak_dir%)%)%)%,%
%MAK_DIR,%(%else-then(%MAK_DIR%,%(%toupper(%Mak_dir%)%)%)%)%,%
%mak_dir,%(%else-then(%_Mak_dir%,%(%tolower(%Mak_dir%)%)%)%)%,%
%prj_path,%(%else-then(%prj_path%,%(c/projects)%)%)%,%
%Prj_path,%(%else-then(%Prj_path%,%(%prj_path%)%)%)%,%
%PRJ_PATH,%(%else-then(%PRJ_PATH%,%(%toupper(%Prj_path%)%)%)%)%,%
%prj_path,%(%else-then(%_Prj_path%,%(%tolower(%Prj_path%)%)%)%)%,%
%prj_dir,%(%else-then(%prj_dir%,%(%platform%/%Mak_dir%)%)%)%,%
%Prj_dir,%(%else-then(%Prj_dir%,%(%prj_dir%)%)%)%,%
%PRJ_DIR,%(%else-then(%PRJ_DIR%,%(%toupper(%Prj_dir%)%)%)%)%,%
%prj_dir,%(%else-then(%_Prj_dir%,%(%tolower(%Prj_dir%)%)%)%)%,%
%prj,%(%else-then(%prj%,%(%if-then(%Prj_path%,%if(%Prj_dir%,/)%)%%Prj_dir%)%)%)%,%
%Prj,%(%else-then(%Prj%,%(%prj%)%)%)%,%
%PRJ,%(%else-then(%PRJ%,%(%toupper(%Prj%)%)%)%)%,%
%prj,%(%else-then(%_Prj%,%(%tolower(%Prj%)%)%)%)%,%
%mak,%(%else-then(%mak%,%(%if-then(%Prj_path%,%if(%Mak_dir%,/)%)%%Mak_dir%)%)%)%,%
%Mak,%(%else-then(%Mak%,%(%mak%)%)%)%,%
%MAK,%(%else-then(%MAK%,%(%toupper(%Mak%)%)%)%)%,%
%mak,%(%else-then(%_Mak%,%(%tolower(%Mak%)%)%)%)%,%
%src_path,%(%else-then(%src_path%,%(c/src)%)%)%,%
%Src_path,%(%else-then(%Src_path%,%(%src_path%)%)%)%,%
%SRC_PATH,%(%else-then(%SRC_PATH%,%(%toupper(%Src_path%)%)%)%)%,%
%src_path,%(%else-then(%_Src_path%,%(%tolower(%Src_path%)%)%)%)%,%
%src_dir,%(%else-then(%src_dir%,%()%)%)%,%
%Src_dir,%(%else-then(%Src_dir%,%(%src_dir%)%)%)%,%
%SRC_DIR,%(%else-then(%SRC_DIR%,%(%toupper(%Src_dir%)%)%)%)%,%
%src_dir,%(%else-then(%_Src_dir%,%(%tolower(%Src_dir%)%)%)%)%,%
%src,%(%else-then(%src%,%(%if-then(%Src_path%,%if(%Src_dir%,/)%)%%Src_dir%)%)%)%,%
%Src,%(%else-then(%Src%,%(%src%)%)%)%,%
%SRC,%(%else-then(%SRC%,%(%toupper(%Src%)%)%)%)%,%
%src,%(%else-then(%_Src%,%(%tolower(%Src%)%)%)%)%,%
%bld_path,%(%else-then(%bld_path%,%()%)%)%,%
%Bld_path,%(%else-then(%Bld_path%,%(%bld_path%)%)%)%,%
%BLD_PATH,%(%else-then(%BLD_PATH%,%(%toupper(%Bld_path%)%)%)%)%,%
%bld_path,%(%else-then(%_Bld_path%,%(%tolower(%Bld_path%)%)%)%)%,%
%bld_dir,%(%else-then(%bld_dir%,%()%)%)%,%
%Bld_dir,%(%else-then(%Bld_dir%,%(%bld_dir%)%)%)%,%
%BLD_DIR,%(%else-then(%BLD_DIR%,%(%toupper(%Bld_dir%)%)%)%)%,%
%bld_dir,%(%else-then(%_Bld_dir%,%(%tolower(%Bld_dir%)%)%)%)%,%
%bld,%(%else-then(%bld%,%(%if-then(%Bld_path%,%if(%Bld_dir%,/)%)%%Bld_dir%)%)%)%,%
%Bld,%(%else-then(%Bld%,%(%bld%)%)%)%,%
%BLD,%(%else-then(%BLD%,%(%toupper(%Bld%)%)%)%)%,%
%bld,%(%else-then(%_Bld%,%(%tolower(%Bld%)%)%)%)%,%
%exe,%(%else-then(%exe%,%(Exe)%)%)%,%
%Exe,%(%else-then(%Exe%,%(%exe%)%)%)%,%
%EXE,%(%else-then(%EXE%,%(%toupper(%Exe%)%)%)%)%,%
%exe,%(%else-then(%_Exe%,%(%tolower(%Exe%)%)%)%)%,%
%executable,%(%else-then(%executable%,%(%if(%equal(SLib,%Exe%)%,%(Shared Library)%,%(%if(%equal(Lib,%Exe%)%,%(Static Library)%,%(Executable)%)%)%)%)%)%)%,%
%Executable,%(%else-then(%Executable%,%(%executable%)%)%)%,%
%EXECUTABLE,%(%else-then(%EXECUTABLE%,%(%toupper(%Executable%)%)%)%)%,%
%executable,%(%else-then(%_Executable%,%(%tolower(%Executable%)%)%)%)%,%
%libs,%(%else-then(%libs%,%(Libs)%)%)%,%
%Libs,%(%else-then(%Libs%,%(%libs%)%)%)%,%
%LIBS,%(%else-then(%LIBS%,%(%toupper(%Libs%)%)%)%)%,%
%libs,%(%else-then(%_Libs%,%(%tolower(%Libs%)%)%)%)%,%
%target,%(%else-then(%target%,%(Project)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%ext,%(%else-then(%ext%,%(%if(%equal(SLib,%Exe%)%,%(.$(SLIBEXT))%,%(%if(%equal(Lib,%Exe%)%,%(.$(LIBEXT))%)%)%)%)%)%)%,%
%Ext,%(%else-then(%Ext%,%(%ext%)%)%)%,%
%EXT,%(%else-then(%EXT%,%(%toupper(%Ext%)%)%)%)%,%
%ext,%(%else-then(%_Ext%,%(%tolower(%Ext%)%)%)%)%,%
%project,%(%else-then(%project%,%(%else-then(%Target%,%(Project)%)%)%)%)%,%
%Project,%(%else-then(%Project%,%(%project%)%)%)%,%
%PROJECT,%(%else-then(%PROJECT%,%(%toupper(%Project%)%)%)%)%,%
%project,%(%else-then(%_Project%,%(%tolower(%Project%)%)%)%)%,%
%what,%(%else-then(%what%,%(%Executable%)%)%)%,%
%What,%(%else-then(%What%,%(%what%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_What%,%(%tolower(%What%)%)%)%)%,%
%for,%(%else-then(%for%,%(%Platform% %Tools% Makefile for %Framework% %Project% %What%)%)%)%,%
%For,%(%else-then(%For%,%(%for%)%)%)%,%
%FOR,%(%else-then(%FOR%,%(%toupper(%For%)%)%)%)%,%
%%(%
%%include(%base_includefile%)%%
%)%)%%
%)%,%(%
%%with(%
%includefile_rules,%(%else-then(%includefile_rules%,%(%this_includefile_base%-rules.t)%)%)%,%
%%(%
%%include(%filepath%/%includefile_rules%)%%
%)%)%%
%)%)%%
%)%)%