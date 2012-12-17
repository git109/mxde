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
%#   File: mxde-objc-parameters-hxx.t
%#
%# Author: $author$
%#   Date: 12/12/2012
%########################################################################
%with(%
%%(%
%%parse(%parameters%,;,, ,%(%
%%apply-x(%
%p_arg_type,%(%left-of-right(%p%, )%)%,%
%p_type,%(%else-then(%right(%p_arg_type%,:)%,%(%p_arg_type%)%)%)%,%
%p_name,%(%else-then(%right(%p%, )%,%(%p%)%)%)%,%
%p_arg,%(%else(%first_parameter%,%(%if-then(%else-then(%left(%p_arg_type%,:)%,%(%p_name%)%)%,%(:)%)%)%)%)%,%
%%(%
%%p_arg%%(()%%p_type%%())%%p_name%%
%)%)%%
%)%,p)%%
%)%)%