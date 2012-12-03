%#############################################################################
%# Copyright (c) 1988-2009 $organization$     
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
%#   File: mxde-file.t
%#
%# Author: $author$           
%#   Date: 9/27/2009
%#
%#############################################################################
%apply-x(%
%comments,%(%else-then(%comments%,%(yes)%)%)%,%
%copyright,%(%else(%equal(no,%copyright%)%,%(yes)%)%)%,%
%open_source,%(%else(%equal(no,%open_source%)%,%(yes)%)%)%,%
%right_separator,%(%else-then(%right_separator%,%(
)%)%)%,%
%%(%
%%if(%comments%,%(%
%%do(%begin_separator%)%%
%%if(%copyright%,%(%
%%include(%filepath%/mxde-copyright.t)%%
%%do(%left_separator%)%%padd(, ,%separator_padd%)%%do(%right_separator%)%%
%)%)%%
%%if(%open_source%,%(%
%%include(%filepath%/mxde-opensource.t)%%
%%do(%left_separator%)%%padd(, ,%separator_padd%)%%do(%right_separator%)%%
%)%)%%
%%do(%left_separator%)%%padd(   File: %file%, ,%separator_padd%)%%do(%right_separator%)%%
%%do(%left_separator%)%%padd(, ,%separator_padd%)%%do(%right_separator%)%%
%%do(%left_separator%)%%padd( Author: %author%, ,%separator_padd%)%%do(%right_separator%)%%
%%do(%left_separator%)%%padd(   Date: %date%, ,%separator_padd%)%%do(%right_separator%)%%
%%if(%for%,%(%
%%do(%left_separator%)%%padd(, ,%separator_padd%)%%do(%right_separator%)%%
%%do(%left_separator%)%%padd( %for%, ,%separator_padd%)%%do(%right_separator%)%%
%)%)%%
%%do(%end_separator%)%%
%)%)%%
%)%)%