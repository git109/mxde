%#############################################################################
%# Copyright (c) 1988-2011 $organization$     
%#
%# This software is provided by the author and contributors ``as is'' and
%# any express or implied warranties, including, but not limited to, the
%# implied warranties of merchantability and fitness for a particular purpose
%# are disclaimed.  In no event shall the author or contributors be liable
%# for any direct, indirect, incidental, special, exemplary, or consequential
%# damages (including, but not limited to, procurement of substitute goods
%# or services; loss of use, data, or profits; or business interruption)
%# however caused and on any theory of liability, whether in contract, strict
%# liability, or tort (including negligence or otherwise) arising in any way
%# out of the use of this software, even if advised of the possibility of
%# such damage.
%#
%#   File: mxde-thirdparty-makefile.t
%#
%# Author: $author$           
%#   Date: 3/24/2011
%#
%#############################################################################
%with(%
%this_includefile,%(mxde-thirdparty-makefile.t)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%base_includefile,%(%filepath%/mxde-makefile.t)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/%this_includefile%)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%with(%
%what,%(%else-then(%what%,%(project)%)%)%,%
%What,%(%else-then(%What%,%(%what%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_What%,%(%tolower(%What%)%)%)%)%,%
%for,%(%else-then(%for%,%(Thirdpary Makefile for %What%)%)%)%,%
%For,%(%else-then(%For%,%(%for%)%)%)%,%
%FOR,%(%else-then(%FOR%,%(%toupper(%For%)%)%)%)%,%
%%(%
%%include(%base_includefile%)%%
%)%)%%
%)%,%(%
%%with(%
%version_major,%(%else-then(%version_major%,%(1)%)%)%,%
%version_Major,%(%else-then(%version_Major%,%(%version_major%)%)%)%,%
%version_MAJOR,%(%else-then(%version_MAJOR%,%(%toupper(%version_Major%)%)%)%)%,%
%version_major,%(%else-then(%version__Major%,%(%tolower(%version_Major%)%)%)%)%,%
%version_minor,%(%else-then(%version_minor%,%()%)%)%,%
%version_Minor,%(%else-then(%version_Minor%,%(%version_minor%)%)%)%,%
%version_MINOR,%(%else-then(%version_MINOR%,%(%toupper(%version_Minor%)%)%)%)%,%
%version_minor,%(%else-then(%version__Minor%,%(%tolower(%version_Minor%)%)%)%)%,%
%version_release,%(%else-then(%version_release%,%()%)%)%,%
%version_Release,%(%else-then(%version_Release%,%(%version_release%)%)%)%,%
%version_RELEASE,%(%else-then(%version_RELEASE%,%(%toupper(%version_Release%)%)%)%)%,%
%version_release,%(%else-then(%version__Release%,%(%tolower(%version_Release%)%)%)%)%,%
%archive_separator,%(%else-then(%archive_separator%,%(.)%)%)%,%
%archived,%(%else-then(%archived%,%(tar)%)%)%,%
%Archived,%(%else-then(%Archived%,%(%archived%)%)%)%,%
%ARCHIVED,%(%else-then(%ARCHIVED%,%(%toupper(%Archived%)%)%)%)%,%
%archived,%(%else-then(%_Archived%,%(%tolower(%Archived%)%)%)%)%,%
%compressed,%(%else-then(%compressed%,%()%)%)%,%
%Compressed,%(%else-then(%Compressed%,%(%compressed%)%)%)%,%
%COMPRESSED,%(%else-then(%COMPRESSED%,%(%toupper(%Compressed%)%)%)%)%,%
%compressed,%(%else-then(%_Compressed%,%(%tolower(%Compressed%)%)%)%)%,%
%%(%
%%include(%filepath%/mxde-thirdparty-makefile-rules.t)%%
%)%)%%
%)%)%%
%)%)%
