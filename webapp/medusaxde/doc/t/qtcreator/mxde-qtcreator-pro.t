%########################################################################
%# Copyright (c) 1988-2011 $organization$  
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
%#   File: mxde-qtcreator-pro.t
%#
%# Author: $author$           
%#   Date: 3/29/2011
%########################################################################
%with(%
%file,%(%else-then(%file%,%(Project)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%include_path,%(%else-then(%include_path%,%(%else(%included_path%,%(%includepath%)%)%)%)%)%,%
%included_path,%(%else-then(%included_path%,%(included_path)%)%)%,%
%includepath,%(%else-then(,%(%filepath(%filepath%)%)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/mxde-qtcreator-pro.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/mxde-source-html.t)%)%,%(%
%%with(%
%file_type_extension,%(%else-then(%file_type_extension%,%(.pro)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension(%file%)%)%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%left_comment,%(#)%,%
%right_comment,%()%,%
%middle_comment,%(%%indent%%%left_comment%)%,%
%first_comment,%(%cc_%%middle_comment%)%,%
%last_comment,%(%middle_comment%%_cc%)%,%
%separator,%(########################################################################
)%,%
%begin_separator,%(%%indent%%%cc_%%separator%)%,%
%end_separator,%(%%indent%%%separator%%_cc%)%,%
%left_separator,%(%%indent%%#)%,%
%right_separator,%(
)%,%
%ul_parameters,%(%else-no(%ul_parameters%,%(%ul_parameters%)%)%)%,%
%sg_parameters,%(%else-no(%sg_parameters%,%(%sg_parameters%)%)%)%,%
%derived_fileinclude,%(%derived_includefile%)%,%
%derived_includefile,%()%,%
%%(%
%%if(%file%,%(%
%%with(filepath,%includepath%,%(%
%%include(%filepath%/mxde-file.t)%%
%)%)%%
%)%,%(%
%)%)%%
%%with(%
%target,%(%else-then(%target%,%(target)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%target_type,%(%else-then(%target_type%,%(target_type)%)%)%,%
%Target_type,%(%else-then(%Target_type%,%(%target_type%)%)%)%,%
%TARGET_TYPE,%(%else-then(%TARGET_TYPE%,%(%toupper(%Target_type%)%)%)%)%,%
%target_type,%(%else-then(%_Target_type%,%(%tolower(%Target_type%)%)%)%)%,%
%defines,%(%else-then(%defines%,%(defines)%)%)%,%
%Defines,%(%else-then(%Defines%,%(%defines%)%)%)%,%
%DEFINES,%(%else-then(%DEFINES%,%(%toupper(%Defines%)%)%)%)%,%
%defines,%(%else-then(%_Defines%,%(%tolower(%Defines%)%)%)%)%,%
%includepath,%(%else-then(%include_path%,%(%include_path%)%)%)%,%
%Includepath,%(%else-then(%Include_path%,%(%includepath%)%)%)%,%
%INCLUDEPATH,%(%else-then(%INCLUDEPATH%,%(%toupper(%Includepath%)%)%)%)%,%
%includepath,%(%else-then(%_Includepath%,%(%tolower(%Includepath%)%)%)%)%,%
%libpath,%(%else-then(%libpath%,%(libpath)%)%)%,%
%Libpath,%(%else-then(%Libpath%,%(%libpath%)%)%)%,%
%LIBPATH,%(%else-then(%LIBPATH%,%(%toupper(%Libpath%)%)%)%)%,%
%libpath,%(%else-then(%_Libpath%,%(%tolower(%Libpath%)%)%)%)%,%
%libs,%(%else-then(%libs%,%(libs)%)%)%,%
%Libs,%(%else-then(%Libs%,%(%libs%)%)%)%,%
%LIBS,%(%else-then(%LIBS%,%(%toupper(%Libs%)%)%)%)%,%
%libs,%(%else-then(%_Libs%,%(%tolower(%Libs%)%)%)%)%,%
%lib_item,%(%else-then(,%(%parameters(lib_item,,;)%)%)%)%,%
%Lib_item,%(%else-then(%Lib_item%,%(%lib_item%)%)%)%,%
%LIB_ITEM,%(%else-then(%LIB_ITEM%,%(%toupper(%Lib_item%)%)%)%)%,%
%lib_item,%(%else-then(%_Lib_item%,%(%tolower(%Lib_item%)%)%)%)%,%
%%(%
%%if(%derived_fileinclude%,%(%
%%include(%derived_fileinclude%)%%
%)%,%(%
%%include(%filepath%/mxde-qtcreator-pro-rules.t)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%