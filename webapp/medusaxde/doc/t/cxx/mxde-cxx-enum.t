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
%#   File: mxde-cxx-enum.t
%#
%# Author: $author$           
%#   Date: 2/4/2011
%########################################################################
%with(%
%%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)%    Enum: %do(%enum%)%
%do(%left_separator%)%
%do(%left_separator%)%  Author: %author%
%do(%left_separator%)%    Date: %date%
%do(%end_separator%)%%
%%_enum_% %do(%enum%)%
{
%with(indent,%(%indent%%indent_%)%,%(%
%%parse(%enum_list%,;,,%(,)%,%(
)%,%(%
%%with(%
%enum_name,%(%else-then(%left(%enum_item%,=)%,%(%enum_item%)%)%)%,%
%enum_value,%(%then-if(%right(%enum_item%,=)%,%( = )%)%)%,%
%%(%
%%indent%%enum_item_before%%enum_name%%enum_item_after%%enum_value%%
%)%)%%
%)%,enum_item)%%
%)%)%%
%};
%
%)%)%