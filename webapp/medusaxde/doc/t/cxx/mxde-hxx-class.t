%########################################################################
%# Copyright (c) 1988-2010 $organization$  
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
%#   File: mxde-hxx-class.t
%#
%# Author: $author$           
%#   Date: 12/31/2010
%########################################################################
%apply-x(%
%file_class_members_ifndef,%(!%_defined_%(%CLASS_MEMBERS_ONLY%))%,%
%file_class_members_ifndef_cc,%(%cc_%%left_comment% !defined(%CLASS_MEMBERS_ONLY%) %right_comment%%_cc%)%,%
%class_template_parameter_derives,%(%if(%class_pattern_tc%,%
%%(%_class_% TDerives=%Class_prefix%%Class%%Class_suffix%)%)%)%,%
%class_template_parameter_implement,%(%if(%implements_pattern_tc%,%
%%(%parse(%Implements%,;,,;,,%(%_class_% T%Implements%=%Class_prefix%%Implements%)%,Implements)%)%)%)%,%
%class_template_parameter_extend,%(%if(%extends_pattern_tc%,%
%%(%parse(%Extends%,;,,;,,%(%_class_% T%Extends%=%Class_prefix%%Extends%)%,Extends)%)%)%)%,%
%class_template_parameter_implements,%(%if(%implements_pattern_tc%,%
%%(%else(%parse(%Implements%,;,,;,,,)%,%(%_class_% TImplements=T%Implements%)%)%)%)%)%,%
%class_template_parameter_extends,%(%if(%extends_pattern_tc%,%
%%(%else(%parse(%Extends%,;,,;,,,)%,%(%_class_% TExtends=T%Extends%)%)%)%)%)%,%
%class_template_parameter_item,%(%parameters(class_template_parameters_item,;)%)%,%
%class_template_parameter_list,%(%class_template_parameter_derives%;%class_template_parameter_implement%;%class_template_parameters%%class_template_parameter_item%;%class_template_parameter_extend%;%class_template_parameter_implements%;%class_template_parameter_extends%)%,%
%class_constructor_type,%(%else(%equal(yes,%class_constructor%)%,%(%kk_%%class_constructor%%_kk% )%)%)%,%
%class_destructor_type,%(%else(%equal(yes,%class_destructor%)%,%(%kk_%%class_destructor%%_kk% )%)%)%,%
%classes_or_nofile,%(%if(%object_class%,%(%if(%file%,%(%classes%)%,%(true)%)%)%)%)%,%
%Full_class_name,%(%Class_prefix%%Class%%Class_suffix%%Template_class_suffix%)%,%
%%(%
%%if(%Class%,%(%
%%
%%if(%class_template%%class_pattern_tc%%implements_pattern_tc%%extends_pattern_tc%,%(%
%%else-no(%cbases%,%(%
%%_#undef_% CDB_CLASS
%_#define_% CDB_CLASS "%Full_class_name%"
%
%)%)%%
%)%)%%
%%if(%classes_or_nofile%,%(%
%
%kk_%#if%_kk% %file_class_members_ifndef%
%
%)%)%%
%%if(%class_comment%,%(%
%%include(%filepath%/mxde-%if-then(%style%,%(-)%)%hxx-class-comment.t)%%
%)%)%%
%%
%%if(%class_template%%class_pattern_tc%%implements_pattern_tc%%extends_pattern_tc%,%(%
%%kk_%template%_kk%%if(%class_template_parameter_list%,%(
)%)%%lt%%
%%with(%
%list,%(%parse(%class_template_parameter_list%,;,,,,%(%if-then(%t%,;)%)%,t)%)%,%
%%(%
%%parse(%list%,;,,%(,
 )%,,%(%do(%t%)%)%,t)%%
%)%)%%
%%gt%
%
%)%)%%
%%
%%kk_%class%_kk% %CLASS_INTERFACE%%Full_class_name%%
%%else(%is_kr_indent%,%(
)%)%%
%%if(%Implements%%Extends%,%
%%(: %
%%parse(%Implements%,;,,%(%(,)%%else(%is_kr_indent%,%(
%indent%  )%)%)%,,%(%
%%kk_%virtual%_kk% %_implements_access_%%
%%if(%class_template_parameter_implements%,%(TImplements)%,%(%
%%if(%implements_pattern_tc%%implements_pattern_t%,%(T)%,%
%%(%Implements_prefix%)%)%%do(%Implements%)%%
%)%)%%
%)%,Implements)%%
%%if(%and(%Implements%,%Extends%)%,%(%(,)%%else(%is_kr_indent%,%(
%indent%  )%)%)%)%%
%%
%%parse(%Extends%,;,,%(%(,)%%else(%is_kr_indent%,%(
%indent%  )%)%)%,,%(%
%%_extends_access_%%
%%if(%class_template_parameter_extends%,%(TExtends)%,%(%
%%if(%extends_pattern_tc%%extends_pattern_t%,%(T)%,%
%%(%Extends_prefix%)%)%%do(%Extends%)%%
%)%)%%
%)%,Extends)%%else(%is_kr_indent%,%(
)%)%)%)%%
%%if(%is_kr_indent%,%( )%)%{
%_class_access_%%
%%apply(_indent,%indent%,indent,%indent%%indent_%,%(%
%%parse(%Implements%,;,,,,%(%
%%indent%%_typedef_% %
%%if(%class_template_parameter_implements%,%(TImplements)%,%
%%(%
%%if(%implements_pattern_tc%%implements_pattern_t%,%(T)%,%
%%(%Implements_prefix%)%)%%do(%Implements%)%%
%)%)% %cImplements%;
)%,Implements)%%
%%
%%parse(%Extends%,;,,,,%(%
%%indent%%_typedef_% %
%%if(%class_template_parameter_extends%,%(TExtends)%,%
%%(%
%%if(%extends_pattern_tc%%extends_pattern_t%,%(T)%,%
%%(%Extends_prefix%)%)%%do(%Extends%)%%
%)%)% %cExtends%;
)%,Extends)%%
%%
%%if(%class_constructor%,%(%
%%include(%filepath%/mxde-hxx-class-constructor.t)%%
%)%)%%
%%if(%class_destructor%,%(%
%%if(%class_constructor%,%(%
%%include(%filepath%/mxde-hxx-class-destructor.t)%%
%)%)%%
%)%)%%
%%if(%object_class%,%(%
%%kk_%#else%_kk% %file_class_members_ifndef_cc%
%kk_%#endif%_kk% %file_class_members_ifndef_cc%

)%)%%
%%if(%class_function%,%(%
%%if(%class_function_prototype%,%(%
%%else(%class_function_abstract%,%(%
%%if(%object_class%,%(%
%%kk_%#if%_kk% %file_class_members_ifndef%
%
%)%)%%
%)%)%%
%)%)%%
%%if(%Class_function_name%,%(%
%%parse(%Class_function_name%,;,,,,%(%
%%with(f,%(%Class_function_name%)%,_f,%(%tolower(%Class_function_name%)%)%,%(%
%%include(%filepath%/mxde-hxx-class-function-pattern.t)%%
%)%)%%
%)%,Class_function_name)%%
%)%,%(%
%%include(%filepath%/mxde-hxx-class-function-pattern.t)%%
%)%)%%
%%if(%class_function_prototype%,%(%
%%else(%class_function_abstract%,%(%
%%if(%object_class%,%(%
%%kk_%#else%_kk% %file_class_members_ifndef_cc%
%kk_%#endif%_kk% %file_class_members_ifndef_cc%

%
%)%)%%
%)%)%%
%)%)%%
%)%)%%
%%if(%object_class%,%(%
%%kk_%#if%_kk% %file_class_members_ifndef%
%
%%if(%is_interface_class%,%(%
%%include(%filepath%/mxde-hxx-class-member-funcs-interface.t)%%
%)%)%%
%%if(%is_implement_class%,%(%
%%include(%filepath%/mxde-hxx-class-member-funcs-implement.t)%%
%)%)%%
%)%)%%
%};
%
%%if(%classes_or_nofile%,%(%
%%kk_%#else%_kk% %file_class_members_ifndef_cc%
%kk_%#endif%_kk% %file_class_members_ifndef_cc%
%
%)%)%%
%%if(%class_template%%class_pattern_tc%%implements_pattern_tc%%extends_pattern_tc%,%(%
%%else-no(%cbases%,%(%
%%_#undef_% CDB_CLASS
%
%)%)%%
%)%)%%
%)%)%%
%)%)%