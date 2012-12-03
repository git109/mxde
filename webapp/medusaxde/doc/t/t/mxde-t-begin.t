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
%#   File: mxde-t-begin.t
%#
%# Author: $author$           
%#   Date: 9/27/2009
%########################################################################
%with(%
%%(%
%%%%kk_%with%_kk%%(()%%%
%parse(%parameter%,;,,,,%(%
%%if(%ul_parameters%,%(%
%%apply-x(p,%(%tolower(%p%)%)%,%(%include(%filepath%/%fileprefix%t-parameter.t)%)%)%%
%%apply-x(p_v,%(%%%tolower(%p%)%%%)%,%(%include(%filepath%/%fileprefix%t-parameter.t)%)%)%%
%%apply-x(p_v,%(%%%kk_%toupper%_kk%%(()%%%%p%%%%())%%%)%,p,%(%toupper(%p%)%)%,%(%include(%filepath%/%fileprefix%t-parameter.t)%)%)%%
%%apply-x(p_n,%(_%p%)%,p_v,%(%%%kk_%tolower%_kk%%(()%%%%p%%%%())%%%)%,p,%(%tolower(%p%)%)%,%(%include(%filepath%/%fileprefix%t-parameter.t)%)%)%%
%)%,%(%
%%if(%sg_parameters%,%(%
%%apply-x(%
%p,%(%else-then(%left(%p%,/)%,%(%p%)%)%)%,%
%p_n,%(%kk_%left%_kk%%(()%%%%p%%%%(,)%/%())%)%,%
%p_v,%(%%%kk_%else%_kk%%(()%%%%kk_%right%_kk%%(()%%%%p%%%%(,)%/%())%%%%(,)%%%%(()%%%%p%%%%())%%%%())%%%)%,%
%%(%include(%filepath%/%fileprefix%t-parameter.t)%)%)%%
%%apply-x(%
%p,%(%else-then(%right(%p%,/)%,%(%p%)%)%)%,%
%p_n,%(%kk_%right%_kk%%(()%%%%p%%%%(,)%/%())%)%,%
%%(%include(%filepath%/%fileprefix%t-parameter.t)%)%)%%
%)%,%(%
%%apply-x(%
%p_v,%(%else-then(%parameter_value%,%(%p%)%)%)%,%
%%(%
%%include(%filepath%/%fileprefix%t-parameter.t)%%
%)%)%%
%)%)%%
%)%)%%
%)%,p)%%%%%%(()%%%
%)%)%