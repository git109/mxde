%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: mxde-objc-interface-comment-hxx.t
%#
%# Author: $author$
%#   Date: 1/30/2014
%########################################################################
%with(%
%%(%
%%do(%begin_separator%)%%
%%do(%left_separator%)% Interface: %Class%%
%%if(%class_comment_fields%,%(%
%%if(%and(%class_comment_fields_author%,%class_comment_fields_date%)%,%(
%do(%left_separator%)%)%)%%
%%if(%class_comment_fields_author%,%(
%do(%left_separator%)%    Author: %author%)%)%%
%%if(%class_comment_fields_date%,%(
%do(%left_separator%)%      Date: %date%)%)%%
%)%)%
%do(%end_separator%)%%
%)%)%