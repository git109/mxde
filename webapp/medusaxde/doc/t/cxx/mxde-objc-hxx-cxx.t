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
%#   File: mxde-objc-hxx-cxx.t
%#
%# Author: $author$
%#   Date: 1/17/2012
%########################################################################
%with(%
%objc_class_function_type,%(%if(%equal(class,%class_function%)%,%(+)%,%(-)%)%)%,%
%class_protocol,%(%else-then(%class_protocol%,%(%equal(protocol,%class_type%)%)%)%)%,%
%class_interface,%(%else-then(%class_interface%,%(%equal(interface,%class_type%)%)%)%)%,%
%class_implementation,%(%else-then(%class_implementation%,%(%equal(implementation,%class_type%)%)%)%)%,%
%%(%
%%parse(%class%,;,,,,%(%
%%include(%filepath%/mxde-objc-%file_type%.t)%%
%)%,class)%%
%)%)%