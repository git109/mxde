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
%#   File: mxde-fb-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 3/11/2012
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath(%filepath%)%)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/mxde-fb-hpp-cpp.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/mxde-source-html.t)%)%,%(%
%%with(%
%file_base,%(%else-then(%file_base%,%(%filebase(%file%)%)%)%)%,%
%file_extension_of_file,%(%else-then(%file_extension_of_file%,%(%fileextension(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%file_extension_of_file%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%file_extension%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(%else-then(%filetype%,%(%file_extension%)%)%)%)%)%,%
%file_hh,%(%else-then(%file_hh%,%(%equal(hh,%file_type%)%)%)%)%,%
%file_mm,%(%else-then(%file_mm%,%(%equal(mm,%file_type%)%)%)%)%,%
%file_hpp,%(%else-then(%file_hpp%,%(%equal(hpp,%file_type%)%)%)%)%,%
%file_cpp,%(%else-then(%file_cpp%,%(%equal(cpp,%file_type%)%)%)%)%,%
%file_extension_hpp,%(%else-then(%file_extension_hpp%,%(%else(%file_mm%,%(hpp)%,%(hh)%)%)%)%)%,%
%FILE_EXTENSION_HPP,%(%else-then(%FILE_EXTENSION_HPP%,%(%toupper(%file_extension_hpp%)%)%)%)%,%
%left_comment,%(///)%,%
%right_comment,%()%,%
%middle_comment,%(%%indent%%%left_comment%)%,%
%first_comment,%(%cc_%%middle_comment%)%,%
%last_comment,%(%middle_comment%%_cc%)%,%
%separator,%(///////////////////////////////////////////////////////////////////////
)%,%
%begin_separator,%(%%indent%%%cc_%%separator%)%,%
%end_separator,%(%%indent%%%separator%%_cc%)%,%
%left_separator,%(%%indent%%///)%,%
%right_separator,%(
)%,%
%derived_fileinclude,%(%derived_includefile%)%,%
%derived_includefile,%()%,%
%%(%
%%if(%file%,%(%
%%apply(filepath,%includepath%,%(%
%%include(%filepath%/mxde-file.t)%%
%)%)%%
%)%,%(%
%)%)%%
%%if(%derived_fileinclude%,%(%
%%include(%derived_fileinclude%)%%
%)%,%(%
%)%)%%
%)%)%%
%)%)%%
%)%)%