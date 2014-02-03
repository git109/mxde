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
%class_init,%(%else-then(%else-no(%class_init%,%(yes)%)%,%()%)%)%,%
%Class_init,%(%else-then(%Class_init%,%(%class_init%)%)%)%,%
%CLASS_init,%(%else-then(%CLASS_init%,%(%toupper(%Class_init%)%)%)%)%,%
%class_init,%(%else-then(%_Class_init%,%(%tolower(%Class_init%)%)%)%)%,%
%class_init_return,%(%else-then(%class_init_return%,%(id self)%)%)%,%
%Class_init_return,%(%else-then(%Class_init_return%,%(%class_init_return%)%)%)%,%
%CLASS_init_return,%(%else-then(%CLASS_init_return%,%(%toupper(%Class_init_return%)%)%)%)%,%
%class_init_return,%(%else-then(%_Class_init_return%,%(%tolower(%Class_init_return%)%)%)%)%,%
%class_init_parameters,%(%else-then(%class_init_parameters%,%()%)%)%,%
%Class_init_parameters,%(%else-then(%Class_init_parameters%,%(%class_init_parameters%)%)%)%,%
%CLASS_init_parameters,%(%else-then(%CLASS_init_parameters%,%(%toupper(%Class_init_parameters%)%)%)%)%,%
%class_init_parameters,%(%else-then(%_Class_init_parameters%,%(%tolower(%Class_init_parameters%)%)%)%)%,%
%class_init_body,%(%else-then(%class_init_body%,%()%)%)%,%
%Class_init_body,%(%else-then(%Class_init_body%,%(%class_init_body%)%)%)%,%
%CLASS_init_body,%(%else-then(%CLASS_init_body%,%(%toupper(%Class_init_body%)%)%)%)%,%
%class_init_body,%(%else-then(%_Class_init_body%,%(%tolower(%Class_init_body%)%)%)%)%,%
%class_dealloc,%(%else-then(%else-no(%class_dealloc%,%(yes)%)%,%()%)%)%,%
%Class_dealloc,%(%else-then(%Class_dealloc%,%(%class_dealloc%)%)%)%,%
%CLASS_dealloc,%(%else-then(%CLASS_dealloc%,%(%toupper(%Class_dealloc%)%)%)%)%,%
%class_dealloc,%(%else-then(%_Class_dealloc%,%(%tolower(%Class_dealloc%)%)%)%)%,%
%class_dealloc_return,%(%else-then(%class_dealloc_return%,%(void)%)%)%,%
%Class_dealloc_return,%(%else-then(%Class_dealloc_return%,%(%class_dealloc_return%)%)%)%,%
%CLASS_dealloc_return,%(%else-then(%CLASS_dealloc_return%,%(%toupper(%Class_dealloc_return%)%)%)%)%,%
%class_dealloc_return,%(%else-then(%_Class_dealloc_return%,%(%tolower(%Class_dealloc_return%)%)%)%)%,%
%class_dealloc_parameters,%(%else-then(%class_dealloc_parameters%,%()%)%)%,%
%Class_dealloc_parameters,%(%else-then(%Class_dealloc_parameters%,%(%class_dealloc_parameters%)%)%)%,%
%CLASS_dealloc_parameters,%(%else-then(%CLASS_dealloc_parameters%,%(%toupper(%Class_dealloc_parameters%)%)%)%)%,%
%class_dealloc_parameters,%(%else-then(%_Class_dealloc_parameters%,%(%tolower(%Class_dealloc_parameters%)%)%)%)%,%
%class_dealloc_body,%(%else-then(%class_dealloc_body%,%([super dealloc])%)%)%,%
%Class_dealloc_body,%(%else-then(%Class_dealloc_body%,%(%class_dealloc_body%)%)%)%,%
%CLASS_dealloc_body,%(%else-then(%CLASS_dealloc_body%,%(%toupper(%Class_dealloc_body%)%)%)%)%,%
%class_dealloc_body,%(%else-then(%_Class_dealloc_body%,%(%tolower(%Class_dealloc_body%)%)%)%)%,%
%objc_class_function_type,%(%if(%equal(class,%class_function%)%,%(+)%,%(-)%)%)%,%
%class_protocol,%(%else-then(%class_protocol%,%(%equal(protocol,%class_type%)%)%)%)%,%
%class_interface,%(%else-then(%class_interface%,%(%equal(interface,%class_type%)%)%)%)%,%
%class_implementation,%(%else-then(%class_implementation%,%(%equal(implementation,%class_type%)%)%)%)%,%
%%(%
%%if(%ifdef%,%(%
%%include(%filepath%/mxde-cxx-ifdef.t)%%
%)%)%%
%%parse(%class%,;,,,,%(%
%%include(%filepath%/mxde-objc-%file_type%.t)%%
%)%,class)%%
%)%)%