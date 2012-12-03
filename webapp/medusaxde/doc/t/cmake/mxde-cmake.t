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
%#   File: mxde-cmake.t
%#
%# Author: $author$
%#   Date: 3/6/2012
%########################################################################
%with(%
%file,%(%else-then(%file%,%(Makefile)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath(%filepath%)%)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/mxde-cmake.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/mxde-source-html.t)%)%,%(%
%%with(%
%file_type_extension,%(%else-then(%file_type_extension%,%()%)%)%,%
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
%%apply(filepath,%includepath%,%(%
%%include(%filepath%/mxde-file.t)%%
%)%)%%
%)%,%(%
%)%)%%
%%if(%derived_fileinclude%,%(%
%%include(%derived_fileinclude%)%%
%)%,%(%
%%include(%filepath%/mxde-cmake-begin.t)%%
%%include(%filepath%/mxde-cmake-end.t)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%