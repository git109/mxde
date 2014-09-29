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
%#   File: mxde-onprocess-http-method-hxx-hxx.t
%#
%# Author: $author$
%#   Date: 6/7/2014
%########################################################################
%with(%
%http_methods,%(%else-then(%http_methods%,%(%parse(%import(%filepath%/../../xml/http11-methods.txt)%,%(
)%,,;)%)%)%)%,%
%do_http_methods,%(%else-then(%do_http_methods%,%(%else-then(%parameters(do_http_method,,;)%,%(%http_methods%)%)%)%)%)%,%
%%(%
%%parse(%do_http_methods%,;,,,,%(%
%%_virtual_% %_bool_% OnProcess%Method%(http::Response%amp% response, %_const_% http::Request%amp% request) {
    %_bool_% processed = %_false_%;
    XOS_LOG_DEBUG("in...");
    processed = OnProcessAny(response, request);
    XOS_LOG_DEBUG("...out");
    %_return_% processed;
}
%
%)%,Method)%%
%)%)%