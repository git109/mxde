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
%#   File: mxde-hxx-class-member-funcs-interface.t
%#
%# Author: $author$           
%#   Date: 2/20/2011
%########################################################################
%with(%
%class,%(%else-then(%derived_class%,%(%class_derives%)%)%)%,%
%Class,%(%else-then(%Derived_class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%DERIVED_CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Derived_class%,%(%tolower(%Class%)%)%)%)%,%
%class_file_type,%(%else-then(%file_type%,%(hxx)%)%)%,%
%Class_file_type,%(%else-then(%Class_file_type%,%(%class_file_type%)%)%)%,%
%CLASS_FILE_TYPE,%(%else-then(%CLASS_FILE_TYPE%,%(%toupper(%Class_file_type%)%)%)%)%,%
%class_file_type,%(%else-then(%_Class_file_type%,%(%tolower(%Class_file_type%)%)%)%)%,%
%class_file,%(%else-then(%class_file%,%(%else(%equal(tolower,%file_is_case%)%,%(%Class%)%,%(%class%)%)%)%)%)%,%
%Class_file,%(%else-then(%Class_file%,%(%class_file%)%)%)%,%
%CLASS_FILE,%(%else-then(%CLASS_FILE%,%(%toupper(%Class_file%)%)%)%)%,%
%class_file,%(%else-then(%_Class_file%,%(%tolower(%Class_file%)%)%)%)%,%
%class_file_interface,%(%else-then(%class_file_interface%,%(%else(%equal(tolower,%file_is_case%)%,%(%Class%Interface)%,%(%class%interface)%)%)%)%)%,%
%Class_file_interface,%(%else-then(%Class_file_interface%,%(%class_file_interface%)%)%)%,%
%class_file_interface,%(%else-then(%_Class_file_interface%,%(%tolower(%Class_file_interface%)%)%)%)%,%
%%(%
%%cc_%%left_comment% include %Class% member functions interface
 %right_comment%%_cc%
%_#define_% %CLASS%_MEMBERS_ONLY
%_#define_% %CLASS%_MEMBER_FUNCS_INTERFACE
%_#include_% %ii_%"%Class_file%.%Class_file_type%"%_ii%
%_#undef_% %CLASS%_MEMBER_FUNCS_INTERFACE
%_#undef_% %CLASS%_MEMBERS_ONLY
%
%)%)%
