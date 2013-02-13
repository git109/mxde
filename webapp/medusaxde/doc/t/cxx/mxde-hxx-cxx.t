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
%#   File: mxde-hxx-cxx.t
%#
%# Author: $author$           
%#   Date: 3/15/2010
%########################################################################
%apply-x(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath%/..)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/mxde-hxx-cxx.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/mxde-source-html.t)%)%,%(%
%%apply-x(%
%lf,%(
)%,%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%indent_,%(    )%,%
%xde,%(%else-then(%xde%,%(mxde)%)%)%,%
%_xde_,%(%else-then(%_xde_%,%(_)%)%)%,%
%_xde_namespace,%(%else-then(%_xde_namespace%,%(%if-then(%_xde_%,%(namespace)%)%)%)%)%,%
%Xde,%(%else-then(%Xde%,%(%xde%)%)%)%,%
%XDE,%(%else-then(%XDE%,%(%toupper(%Xde%)%)%)%)%,%
%xde,%(%else-then(%_Xde%,%(%tolower(%Xde%)%)%)%)%,%
%_Xde_,%(%else-then(%_Xde_%,%(%_xde_%)%)%)%,%
%_XDE_,%(%else-then(%_XDE_%,%(%toupper(%_Xde_%)%)%)%)%,%
%_xde_,%(%else-then(%__Xde_%,%(%tolower(%_Xde_%)%)%)%)%,%
%_Xde_namespace,%(%else-then(%_Xde_namespace%,%(%_xde_namespace%)%)%)%,%
%_XDE_NAMESPACE,%(%else-then(%_XDE_NAMESPACE%,%(%toupper(%_Xde_namespace%)%)%)%)%,%
%_xde_namespace,%(%else-then(%__Xde_namespace%,%(%tolower(%_Xde_namespace%)%)%)%)%,%
%_#import_,%(%else-then(%_#import_%,%(%xx_%#import%_xx%)%)%)%,%
%_@class_,%(%else-then(%_@class_%,%(%xx_%@class%_xx%)%)%)%,%
%_@interface_,%(%else-then(%_@interface_%,%(%xx_%@interface%_xx%)%)%)%,%
%_@implementation_,%(%else-then(%_@implementation_%,%(%xx_%@implementation%_xx%)%)%)%,%
%_@protocol_,%(%else-then(%_@protocol_%,%(%xx_%@protocol%_xx%)%)%)%,%
%_@property_,%(%else-then(%_@property_%,%(%xx_%@property%_xx%)%)%)%,%
%_@end_,%(%else-then(%_@end_%,%(%xx_%@end%_xx%)%)%)%,%
%_#include_,%(%else-then(%_#include_%,%(%kk_%#include%_kk%)%)%)%,%
%_#if_,%(%else-then(%_#if_%,%(%kk_%#if%_kk%)%)%)%,%
%_#ifdef_,%(%else-then(%_#ifdef_%,%(%kk_%#ifdef%_kk%)%)%)%,%
%_#ifndef_,%(%else-then(%_#ifndef_%,%(%kk_%#ifndef%_kk%)%)%)%,%
%_#elif_,%(%else-then(%_#elif_%,%(%kk_%#elif%_kk%)%)%)%,%
%_#else_,%(%else-then(%_#else_%,%(%kk_%#else%_kk%)%)%)%,%
%_#endif_,%(%else-then(%_#endif_%,%(%kk_%#endif%_kk%)%)%)%,%
%_#define_,%(%else-then(%_#define_%,%(%kk_%#define%_kk%)%)%)%,%
%_#undef_,%(%else-then(%_#undef_%,%(%kk_%#undef%_kk%)%)%)%,%
%_#pragma_,%(%else-then(%_#pragma_%,%(%kk_%#pragma%_kk%)%)%)%,%
%_defined_,%(%else-then(%_defined_%,%(%kk_%defined%_kk%)%)%)%,%
%__attribute__,%(%else-then(%__attribute__%,%(%kk_%__attribute__%_kk%)%)%)%,%
%_namespace_,%(%else-then(%_namespace_%,%(%kk_%namespace%_kk%)%)%)%,%
%_template_,%(%else-then(%_template_%,%(%kk_%template%_kk%)%)%)%,%
%_typedef_,%(%else-then(%_typedef_%,%(%kk_%typedef%_kk%)%)%)%,%
%_enum_,%(%else-then(%_enum_%,%(%kk_%enum%_kk%)%)%)%,%
%_struct_,%(%else-then(%_struct_%,%(%kk_%struct%_kk%)%)%)%,%
%_union_,%(%else-then(%_union_%,%(%kk_%union%_kk%)%)%)%,%
%_class_,%(%else-then(%_class_%,%(%kk_%class%_kk%)%)%)%,%
%_public_,%(%else-then(%_public_%,%(%kk_%public%_kk%)%)%)%,%
%_protected_,%(%else-then(%_protected_%,%(%kk_%protected%_kk%)%)%)%,%
%_private_,%(%else-then(%_private_%,%(%kk_%private%_kk%)%)%)%,%
%_virtual_,%(%else-then(%_virtual_%,%(%kk_%virtual%_kk%)%)%)%,%
%_volitile_,%(%else-then(%_volitile_%,%(%kk_%volitile%_kk%)%)%)%,%
%_extern_,%(%else-then(%_extern_%,%(%kk_%extern%_kk%)%)%)%,%
%_static_,%(%else-then(%_static_%,%(%kk_%static%_kk%)%)%)%,%
%_const_,%(%else-then(%_const_%,%(%kk_%const%_kk%)%)%)%,%
%_signed_,%(%else-then(%_signed_%,%(%kk_%signed%_kk%)%)%)%,%
%_unsigned_,%(%else-then(%_unsigned_%,%(%kk_%unsigned%_kk%)%)%)%,%
%_long_,%(%else-then(%_long_%,%(%kk_%long%_kk%)%)%)%,%
%_short_,%(%else-then(%_short_%,%(%kk_%short%_kk%)%)%)%,%
%_double_,%(%else-then(%_double_%,%(%kk_%double%_kk%)%)%)%,%
%_float_,%(%else-then(%_float_%,%(%kk_%float%_kk%)%)%)%,%
%_int_,%(%else-then(%_int_%,%(%kk_%int%_kk%)%)%)%,%
%_char_,%(%else-then(%_char_%,%(%kk_%char%_kk%)%)%)%,%
%_bool_,%(%else-then(%_bool_%,%(%kk_%bool%_kk%)%)%)%,%
%_return_,%(%else-then(%_return_%,%(%kk_%return%_kk%)%)%)%,%
%_switch_,%(%else-then(%_switch_%,%(%kk_%switch%_kk%)%)%)%,%
%_case_,%(%else-then(%_case_%,%(%kk_%case%_kk%)%)%)%,%
%_break_,%(%else-then(%_break_%,%(%kk_%break%_kk%)%)%)%,%
%_default_,%(%else-then(%_default_%,%(%kk_%default%_kk%)%)%)%,%
%cxx_comments,%(%else-then(%cxx_comments%,%(%equal(cxx,%comment_type%)%)%)%)%,%
%cxxx_comments,%(%else-then(%cxxx_comments%,%(%equal(cxxx,%comment_type%)%)%)%)%,%
%cppp_comments,%(%else-then(%cppp_comments%,%(%equal(cppp,%comment_type%)%)%)%)%,%
%cpp_comments,%(%else-then(%equal(hpp,%file_type%)%,%(%equal(cpp,%file_type%)%)%)%)%,%
%left_comment,%(%else(%cpp_comments%,%(/*)%,%(//)%)%)%,%
%right_comment,%(%else(%cpp_comments%,%(*/)%,%()%)%)%,%
%first_comment,%(%%indent%%%else(%cpp_comments%,%(/*)%,%(//)%)%)%,%
%last_comment,%(%%indent%%%else(%cpp_comments%,%( */)%,%(//)%)%)%,%
%middle_comment,%(%%indent%%%else(%cpp_comments%,%( *)%,%(//)%)%)%,%
%separator,%(%else(%cpp_comments%,%
%%( **********************************************************************)%,%
%%(///////////////////////////////////////////////////////////////////////)%)%)%,%
%begin_separator,%(%%indent%%%cc_%%else(%cpp_comments%,%(%else(%cxx_comments%,%(/**)%,%(/*)%)%
%%indent%%)%,%()%)%%separator%
)%,%
%end_separator,%(%%indent%%%separator%%else(%cpp_comments%,%(
%%indent%% */)%,%()%)%%_cc%
)%,%
%left_separator,%(%%indent%%%else(%cpp_comments%,%( *)%,%(%else(%cppp_comments%,%(//)%,%(///)%)%)%)%)%,%
%namespace,%(%else-then(%namespace%,%()%)%)%,%
%Namespace,%(%else-then(%Namespace%,%(%namespace%)%)%)%,%
%NAMESPACE,%(%else-then(%NAMESPACE%,%(%toupper(%Namespace%)%)%)%)%,%
%namespace,%(%else-then(%_Namespace%,%(%tolower(%Namespace%)%)%)%)%,%
%class_comment,%(%else(%equal(no,%class_comment%)%,%(%else-then(%class_comment%,%(yes)%)%)%)%)%,%
%class_constructor_comment,%(%else(%equal(no,%class_constructor_comment%)%,%(%else-then(%class_constructor_comment%,%(yes)%)%)%)%)%,%
%class_destructor_comment,%(%else(%equal(no,%class_destructor_comment%)%,%(%else-then(%class_destructor_comment%,%(yes)%)%)%)%)%,%
%class_function_comment,%(%else(%equal(no,%class_function_comment%)%,%(%else-then(%class_function_comment%,%(yes)%)%)%)%)%,%
%class_namespace_define,%(%else-then(%class_namespace_define%,%(%else-no(%else-then(%class_namespace_define_is%,yes)%,%(%else-no(%else-then(%cbases%,yes)%,%(c)%)%_NAMESPACE)%)%)%)%)%,%
%Class_namespace_define,%(%else-then(%Class_namespace_define%,%(%class_namespace_define%)%)%)%,%
%CLASS_NAMESPACE_DEFINE,%(%else-then(%CLASS_NAMESPACE_DEFINE%,%(%toupper(%Class_namespace_define%)%)%)%)%,%
%class_namespace_define,%(%else-then(%_Class_namespace_define%,%(%tolower(%Class_namespace_define%)%)%)%)%,%
%class_namespace,%(%else-then(%class_namespace%,%(%Namespace%)%)%)%,%
%Class_namespace,%(%else-then(%Class_namespace%,%(%class_namespace%)%)%)%,%
%CLASS_NAMESPACE,%(%else-then(%CLASS_NAMESPACE%,%(%toupper(%Class_namespace%)%)%)%)%,%
%class_namespace,%(%else-then(%_Class_namespace%,%(%tolower(%Class_namespace%)%)%)%)%,%
%class_pattern_tc,%(%else-then(%class_pattern_tc%,%(%equal(tc,%class_pattern%)%)%)%)%,%
%class_pattern_t,%(%else-then(%class_pattern_t%,%(%equal(t,%class_pattern%)%)%)%)%,%
%class_pattern_c,%(%else-then(%class_pattern_c%,%(%equal(c,%class_pattern%)%)%)%)%,%
%class_prefix,%(%else-then(%class_prefix%,%(%else-then(%equal(c,%class_pattern%)%,%(%if(%equal(tc,%class_pattern%)%,%(c)%)%)%)%)%)%)%,%
%Class_prefix,%(%else-then(%Class_prefix%,%(%class_prefix%)%)%)%,%
%CLASS_PREFIX,%(%else-then(%CLASS_PREFIX%,%(%toupper(%Class_prefix%)%)%)%)%,%
%class_prefix,%(%else-then(%_Class_prefix%,%(%tolower(%Class_prefix%)%)%)%)%,%
%class_suffix,%(%else-then(%class_suffix%,%()%)%)%,%
%Class_suffix,%(%else-then(%Class_suffix%,%(%class_suffix%)%)%)%,%
%CLASS_SUFFIX,%(%else-then(%CLASS_SUFFIX%,%(%toupper(%Class_suffix%)%)%)%)%,%
%class_suffix,%(%else-then(%_Class_suffix%,%(%tolower(%Class_suffix%)%)%)%)%,%
%class_template,%(%else-then(%class_template%,%(%if(%class_pattern_tc%%class_pattern_t%,%(yes)%)%)%)%)%,%
%template_class_suffix,%(%else-then(%template_class_suffix%,%(%if(%class_pattern_tc%%class_pattern_t%,%(T)%)%)%)%)%,%
%Template_class_suffix,%(%else-then(%Template_class_suffix%,%(%template_class_suffix%)%)%)%,%
%TEMPLATE_CLASS_SUFFIX,%(%else-then(%TEMPLATE_CLASS_SUFFIX%,%(%toupper(%Template_class_suffix%)%)%)%)%,%
%template_class_suffix,%(%else-then(%_Template_class_suffix%,%(%tolower(%Template_class_suffix%)%)%)%)%,%
%interface_prefix,%(%else-then(%interface_prefix%,%(%else-then(%equal(c,%class_implements_pattern%)%,%(%else-then(,%(%class_prefix%)%)%)%)%)%)%)%,%
%Interface_prefix,%(%else-then(%Interface_prefix%,%(%interface_prefix%)%)%)%,%
%INTERFACE_PREFIX,%(%else-then(%INTERFACE_PREFIX%,%(%toupper(%Interface_prefix%)%)%)%)%,%
%interface_prefix,%(%else-then(%_Interface_prefix%,%(%tolower(%Interface_prefix%)%)%)%)%,%
%interface_suffix,%(%else-then(%interface_suffix%,%(Interface)%)%)%,%
%Interface_suffix,%(%else-then(%Interface_suffix%,%(%interface_suffix%)%)%)%,%
%INTERFACE_SUFFIX,%(%else-then(%INTERFACE_SUFFIX%,%(%toupper(%Interface_suffix%)%)%)%)%,%
%interface_suffix,%(%else-then(%_Interface_suffix%,%(%tolower(%Interface_suffix%)%)%)%)%,%
%implement_prefix,%(%else-then(%implement_prefix%,%(%class_prefix%)%)%)%,%
%Implement_prefix,%(%else-then(%Implement_prefix%,%(%implement_prefix%)%)%)%,%
%IMPLEMENT_PREFIX,%(%else-then(%IMPLEMENT_PREFIX%,%(%toupper(%Implement_prefix%)%)%)%)%,%
%implement_prefix,%(%else-then(%_Implement_prefix%,%(%tolower(%Implement_prefix%)%)%)%)%,%
%implement_suffix,%(%else-then(%implement_suffix%,%(Implement)%)%)%,%
%Implement_suffix,%(%else-then(%Implement_suffix%,%(%implement_suffix%)%)%)%,%
%IMPLEMENT_SUFFIX,%(%else-then(%IMPLEMENT_SUFFIX%,%(%toupper(%Implement_suffix%)%)%)%)%,%
%implement_suffix,%(%else-then(%_Implement_suffix%,%(%tolower(%Implement_suffix%)%)%)%)%,%
%is_interface_class,%(%equal(interface,%class_interface%)%)%,%
%is_implement_class,%(%equal(implement,%class_interface%)%)%,%
%C_prefixes,%(%else(%equal(no,%cbases%)%,%(c_)%,%(_)%)%)%,%
%C_PREFIXES,%(%else-then(%C_PREFIXES%,%(%toupper(%C_prefixes%)%)%)%)%,%
%c_prefixes,%(%else-then(%_C_prefixes%,%(%tolower(%C_prefixes%)%)%)%)%,%
%interface_class,%(%else-then(%interface_class%,%(interface)%)%)%,%
%Interface_class,%(%if(%interface_class%,%(%c_prefixes%%interface_class%_class )%)%)%,%
%INTERFACE_CLASS,%(%if(%interface_class%,%(%c_prefixes%%toupper(%interface_class%_class )%)%)%)%,%
%interface_class,%(%if(%interface_class%,%(%c_prefixes%%tolower(%interface_class%_class )%)%)%)%,%
%implement_class,%(%else-then(%implement_class%,%(implement)%)%)%,%
%Implement_class,%(%if(%implement_class%,%(%c_prefixes%%implement_class%_class )%)%)%,%
%IMPLEMENT_CLASS,%(%if(%implement_class%,%(%c_prefixes%%toupper(%implement_class%_class )%)%)%)%,%
%implement_class,%(%if(%implement_class%,%(%c_prefixes%%tolower(%implement_class%_class )%)%)%)%,%
%instance_class,%(%else-then(%instance_class%,%(instance)%)%)%,%
%Instance_class,%(%if(%instance_class%,%(%c_prefixes%%instance_class%_class )%)%)%,%
%INSTANCE_CLASS,%(%if(%instance_class%,%(%c_prefixes%%toupper(%instance_class%_class )%)%)%)%,%
%instance_class,%(%if(%instance_class%,%(%c_prefixes%%tolower(%instance_class%_class )%)%)%)%,%
%export_class,%(%else-then(%export_class%,%(export)%)%)%,%
%Export_class,%(%if(%export_class%,%(%c_prefixes%%export_class%_class )%)%)%,%
%EXPORT_CLASS,%(%if(%export_class%,%(%c_prefixes%%toupper(%export_class%)%)%)%)%,%
%export_class,%(%if(%export_class%,%(%c_prefixes%%tolower(%export_class%)%)%)%)%,%
%class_interface,%(%if-then(%else-then(%not-no(%class_interface%)%,%(%class_interface_name%)%)%,%(_class )%)%)%,%
%Class_interface,%(%else-then(%Class_interface%,%(%then-if(%class_interface%,%c_prefixes%)%)%)%)%,%
%CLASS_INTERFACE,%(%else-then(%CLASS_INTERFACE%,%(%then-if(%toupper(%class_interface%)%,%c_prefixes%)%)%)%)%,%
%class_interface,%(%else-then(%_Class_interface%,%(%then-if(%tolower(%class_interface%)%,%c_prefixes%)%)%)%)%,%
%class_name,%(%else-then(%class_name%,%()%)%)%,%
%Class_name,%(%else-then(%Class_name%,%(%class_name%)%)%)%,%
%CLASS_NAME,%(%else-then(%CLASS_NAME%,%(%toupper(%Class_name%)%)%)%)%,%
%class_name,%(%else-then(%_Class_name%,%(%tolower(%Class_name%)%)%)%)%,%
%class,%(%else-then(%class%,%(%class_item%)%)%)%,%
%classes,%(%left(%class%,;)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%Class_Class,%(%else-then(%Class_Class%,%(%Class_prefix%%Class%%Class_suffix%%Template_class_suffix%)%)%)%,%
%CLASS_CLASS,%(%else-then(%CLASS_CLASS%,%(%toupper(%Class_Class%)%)%)%)%,%
%class_class,%(%else-then(%_Class_Class%,%(%tolower(%Class_Class%)%)%)%)%,%
%member_class,%(%else-then(%classes%,%(%Class%)%)%)%,%
%Member_class,%(%else-then(%Member_class%,%(%member_class%)%)%)%,%
%MEMBER_CLASS,%(%else-then(%MEMBER_CLASS%,%(%toupper(%Member_class%)%)%)%)%,%
%member_class,%(%else-then(%_Member_class%,%(%tolower(%Member_class%)%)%)%)%,%
%members_class,%(%else-then(%members_class%,%(%Class_prefix%%Member_class%%Class_suffix%)%)%)%,%
%Members_class,%(%else-then(%Members_class%,%(%members_class%)%)%)%,%
%MEMBERS_CLASS,%(%else-then(%MEMBERS_CLASS%,%(%toupper(%Members_class%)%)%)%)%,%
%members_class,%(%else-then(%_Members_class%,%(%tolower(%Members_class%)%)%)%)%,%
%Classes,%(%else-then(%Classes%,%(%classes%)%)%)%,%
%CLASSES,%(%else-then(%CLASSES%,%(%toupper(%Classes%)%)%)%)%,%
%classes,%(%else-then(%_Classes%,%(%tolower(%Classes%)%)%)%)%,%
%object_class,%(%else-then(%object_class%,%(%class_members_only_ifdefs%)%)%)%,%
%object_class,%(%else(%equal(no,%object_class%)%,%(%object_class%)%)%)%,%
%Object_class,%(%else-then(%Object_class%,%(%object_class%)%)%)%,%
%OBJECT_CLASS,%(%else-then(%OBJECT_CLASS%,%(%toupper(%Object_class%)%)%)%)%,%
%object_class,%(%else-then(%_Object_class%,%(%tolower(%Object_class%)%)%)%)%,%
%object_classes,%(%if(%object_class%,%(%classes%)%)%)%,%
%Object_classes,%(%else-then(%Object_classes%,%(%object_classes%)%)%)%,%
%OBJECT_CLASSES,%(%else-then(%OBJECT_CLASSES%,%(%toupper(%Object_classes%)%)%)%)%,%
%object_classes,%(%else-then(%_Object_classes%,%(%tolower(%Object_classes%)%)%)%)%,%
%class_members_only,%(%else-then(%class_members_only%,%(%do(%class_members_only_ifdefs_name%)%)%)%)%,%
%class_members_only,%(%else-then(%class_members_only%,%(%Members_class%_members_only)%)%)%,%
%Class_members_only,%(%else-then(%Class_members_only%,%(%class_members_only%)%)%)%,%
%CLASS_MEMBERS_ONLY,%(%else-then(%CLASS_MEMBERS_ONLY%,%(%toupper(%Class_members_only%)%)%)%)%,%
%class_members_only,%(%else-then(%_Class_members_only%,%(%tolower(%Class_members_only%)%)%)%)%,%
%class_member_funcs_interface,%(%else-then(%class_member_funcs_interface%,%(%do(%class_member_funcs_interface_ifdefs_name%)%)%)%)%,%
%class_member_funcs_interface,%(%else-then(%class_member_funcs_interface%,%(%Members_class%_member_funcs_interface)%)%)%,%
%Class_member_funcs_interface,%(%else-then(%Class_member_funcs_interface%,%(%class_member_funcs_interface%)%)%)%,%
%CLASS_MEMBER_FUNCS_INTERFACE,%(%else-then(%CLASS_MEMBER_FUNCS_INTERFACE%,%(%toupper(%Class_member_funcs_interface%)%)%)%)%,%
%class_member_funcs_interface,%(%else-then(%_Class_member_funcs_interface%,%(%tolower(%Class_member_funcs_interface%)%)%)%)%,%
%class_member_funcs_implement,%(%else-then(%class_member_funcs_implement%,%(%do(%class_member_funcs_implement_ifdefs_name%)%)%)%)%,%
%class_member_funcs_implement,%(%else-then(%class_member_funcs_implement%,%(%Members_class%_member_funcs_implement)%)%)%,%
%Class_member_funcs_implement,%(%else-then(%Class_member_funcs_implement%,%(%class_member_funcs_implement%)%)%)%,%
%CLASS_MEMBER_FUNCS_IMPLEMENT,%(%else-then(%CLASS_MEMBER_FUNCS_IMPLEMENT%,%(%toupper(%Class_member_funcs_implement%)%)%)%)%,%
%class_member_funcs_implement,%(%else-then(%_Class_member_funcs_implement%,%(%tolower(%Class_member_funcs_implement%)%)%)%)%,%
%extends_pattern_tc,%(%else-then(%extends_pattern_tc%,%(%equal(tc,%class_extends_pattern%)%)%)%)%,%
%extends_pattern_t,%(%else-then(%extends_pattern_t%,%(%equal(t,%class_extends_pattern%)%)%)%)%,%
%extends_pattern_c,%(%else-then(%extends_pattern_c%,%(%equal(c,%class_extends_pattern%)%)%)%)%,%
%extends_prefix,%(%else-then(%extends_prefix%,%(%else-then(%equal(c,%class_extends_pattern%)%,%(%else-then(,%(%class_prefix%)%)%)%)%)%)%)%,%
%Extends_prefix,%(%else-then(%Extends_prefix%,%(%extends_prefix%)%)%)%,%
%EXTENDS_PREFIX,%(%else-then(%EXTENDS_PREFIX%,%(%toupper(%Extends_prefix%)%)%)%)%,%
%extends_prefix,%(%else-then(%_Extends_prefix%,%(%tolower(%Extends_prefix%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(%if-then(%class_extends%,%(%if(%class_extends_item%,;)%)%)%%class_extends_item%)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%implements_pattern_tc,%(%else-then(%implements_pattern_tc%,%(%equal(tc,%class_implements_pattern%)%)%)%)%,%
%implements_pattern_t,%(%else-then(%implements_pattern_t%,%(%equal(tc,%class_implements_pattern%)%)%)%)%,%
%implements_pattern_c,%(%else-then(%implements_pattern_c%,%(%equal(tc,%class_implements_pattern%)%)%)%)%,%
%implements_prefix,%(%else-then(%implements_prefix%,%(%else-then(%equal(c,%class_implements_pattern%)%,%(%else-then(,%(%class_prefix%)%)%)%)%)%)%)%,%
%Implements_prefix,%(%else-then(%Implements_prefix%,%(%implements_prefix%)%)%)%,%
%IMPLEMENTS_PREFIX,%(%else-then(%IMPLEMENTS_PREFIX%,%(%toupper(%Implements_prefix%)%)%)%)%,%
%implements_prefix,%(%else-then(%_Implements_prefix%,%(%tolower(%Implements_prefix%)%)%)%)%,%
%implements_items,%(%else-then(%implements_items%,%(%parameters(class_implements_item,,;)%)%)%)%,%
%implements,%(%else-then(%implements%,%(%if-then(%class_implements%,%(%if(%implements_items%,;)%)%)%%implements_items%)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%derives,%(%else-then(%derives%,%(%class_derives%)%)%)%,%
%Derives,%(%else-then(%Derives%,%(%derives%)%)%)%,%
%DERIVES,%(%else-then(%DERIVES%,%(%toupper(%Derives%)%)%)%)%,%
%derives,%(%else-then(%_Derives%,%(%tolower(%Derives%)%)%)%)%,%
%cBases,%(%else(%equal(no,%cbases%)%,%(c)%)%)%,%
%CBASES,%(%else-then(%CBASES%,%(%toupper(%cBases%)%)%)%)%,%
%cbases,%(%else-then(%_cBases%,%(%tolower(%cBases%)%)%)%)%,%
%cExtends,%(%else-then(%cExtends%,%(%cBases%Extends)%)%)%,%
%CEXTENDS,%(%else-then(%CEXTENDS%,%(%toupper(%cExtends%)%)%)%)%,%
%cextends,%(%else-then(%_cExtends%,%(%tolower(%cExtends%)%)%)%)%,%
%cImplements,%(%else-then(%cImplements%,%(%cBases%Implements)%)%)%,%
%CIMPLEMENTS,%(%else-then(%CIMPLEMENTS%,%(%toupper(%cImplements%)%)%)%)%,%
%cimplements,%(%else-then(%_cImplements%,%(%tolower(%cImplements%)%)%)%)%,%
%_class_access_,%(%else-no(%class_access%,%(%kk_%%class_access%%_kk%:
)%)%)%,%
%_extends_access_,%(%else-no(%class_extends_access%,%(%kk_%%class_extends_access%%_kk% )%)%)%,%
%_implements_access_,%(%else-no(%class_implements_access%,%(%kk_%%class_implements_access%%_kk% )%)%)%,%
%class_function,%(%else(%equal(no,%class_function%)%,%(%class_function%)%)%)%,%
%class_function_static,%(%if(%equal(static,%class_function%)%,%(%class_function%)%)%)%,%
%class_function_get_const,%(%else(%equal(no,%class_function_get_const%)%,%(const)%)%)%,%
%class_function_const,%(%else(%equal(no,%class_function_const%)%,%(%class_function_const%)%)%)%,%
%class_function_type,%(%else(%equal(yes,%class_function%)%,%(%kk_%%class_function%%_kk% )%)%)%,%
%class_function_do_return,%(%else-then(%left(%class_function_return%,/)%,%(%else(%right(%class_function_return%,/)%,%(%class_function_return%)%)%)%)%)%,%
%class_function_undo_return,%(%else-then(%right(%class_function_return%,/)%,%(%else(%left(%class_function_return%,/)%,%(%class_function_return%)%)%)%)%)%,%
%class_function_return,%(%else-then(%left(%class_function_return%,/)%,%(%else-then(%right(%class_function_return%,/)%,%(%class_function_return%)%)%)%)%)%,%
%class_function_do_parameters,%(%else-then(%left(%class_function_parameters%,/)%,%(%else(%right(%class_function_parameters%,/)%,%(%class_function_parameters%)%)%)%)%)%,%
%class_function_undo_parameters,%(%else-then(%right(%class_function_parameters%,/)%,%(%else(%left(%class_function_parameters%,/)%,%(%class_function_parameters%)%)%)%)%)%,%
%class_function_parameters,%(%else-then(%left(%class_function_parameters%,/)%,%(%else-then(%right(%class_function_parameters%,/)%,%(%class_function_parameters%)%)%)%)%)%,%
%Class_function,%(%else-then(%Class_function%,%(%class_function%)%)%)%,%
%CLASS_FUNCTION,%(%else-then(%CLASS_FUNCTION%,%(%toupper(%Class_function%)%)%)%)%,%
%Class_function_return,%(%else-then(%Class_function_return%,%(%class_function_return%)%)%)%,%
%CLASS_FUNCTION_RETURN,%(%else-then(%CLASS_FUNCTION_RETURN%,%(%toupper(%Class_function_return%)%)%)%)%,%
%Class_function_parameters,%(%else-then(%Class_function_parameters%,%(%class_function_parameters%)%)%)%,%
%CLASS_FUNCTION_PARAMETERS,%(%else-then(%CLASS_FUNCTION_PARAMETERS%,%(%toupper(%Class_function_parameters%)%)%)%)%,%
%class_function_statement,%(%else-then(%class_function_statement%,%(%class_function_body%)%)%)%,%
%Class_function_statement,%(%else-then(%Class_function_statement%,%(%class_function_statement%)%)%)%,%
%CLASS_FUNCTION_STATEMENT,%(%else-then(%CLASS_FUNCTION_STATEMENT%,%(%toupper(%Class_function_statement%)%)%)%)%,%
%class_function_statement,%(%else-then(%_Class_function_statement%,%(%tolower(%Class_function_statement%)%)%)%)%,%
%class_function_name,%(%else-then(%class_function_name%,%()%)%)%,%
%Class_function_name,%(%else-then(%Class_function_name%,%(%class_function_name%)%)%)%,%
%CLASS_FUNCTION_NAME,%(%else-then(%CLASS_FUNCTION_NAME%,%(%toupper(%Class_function_name%)%)%)%)%,%
%class_function_name,%(%else-then(%_Class_function_name%,%(%tolower(%Class_function_name%)%)%)%)%,%
%class_function_pattern,%(%else(%equal(no,%class_function_pattern%)%,%(%class_function_pattern%)%)%)%,%
%class_function_pattern_names,%(%else-then(%else-then(%class_function_pattern_names%,%(%class_function_pattern_names_item%)%)%,%(%if(%equal(doundo,%class_function_pattern%)%,%(Do/Undo)%,%(%if(%equal(createdestroy,%class_function_pattern%)%,%(Create/Destroy)%,%(Set/Get)%)%)%)%)%)%)%,%
%class_function_doundo,%(%else-then(%class_function_doundo%,%(%else-then(%class_function_pattern_names%,%(%else-then(%class_function_pattern_names_item%,%()%)%)%)%)%)%)%,%
%class_function_DoUndo,%(%else-then(%class_function_DoUndo%,%(%class_function_doundo%)%)%)%,%
%CLASS_FUNCTION_DOUNDO,%(%else-then(%CLASS_FUNCTION_DOUNDO%,%(%toupper(%class_function_DoUndo%)%)%)%)%,%
%class_function_doundo,%(%else-then(%_class_function_DoUndo%,%(%tolower(%class_function_DoUndo%)%)%)%)%,%
%class_function_do,%(%else-then(%class_function_do%,%(%else-then(%left(%class_function_DoUndo%,/)%,%(%class_function_DoUndo%)%)%)%)%)%,%
%class_function_Do,%(%else-then(%class_function_Do%,%(%class_function_do%)%)%)%,%
%CLASS_FUNCTION_DO,%(%else-then(%CLASS_FUNCTION_DO%,%(%toupper(%class_function_Do%)%)%)%)%,%
%class_function_do,%(%else-then(%_class_function_Do%,%(%tolower(%class_function_Do%)%)%)%)%,%
%class_function_undo,%(%else-then(%class_function_undo%,%(%right(%class_function_DoUndo%,/)%)%)%)%,%
%class_function_Undo,%(%else-then(%class_function_Undo%,%(%class_function_undo%)%)%)%,%
%CLASS_FUNCTION_UNDO,%(%else-then(%CLASS_FUNCTION_UNDO%,%(%toupper(%class_function_Undo%)%)%)%)%,%
%class_function_undo,%(%else-then(%_class_function_Undo%,%(%tolower(%class_function_Undo%)%)%)%)%,%
%class_function_prefix,%(%else-then(%class_function_prefix%,%(%else-then(%left(%class_function_name_fixes%,/)%,%(%class_function_name_fixes%)%)%)%)%)%,%
%Class_function_prefix,%(%else-then(%Class_function_prefix%,%(%class_function_prefix%)%)%)%,%
%CLASS_FUNCTION_PREFIX,%(%else-then(%CLASS_FUNCTION_PREFIX%,%(%toupper(%Class_function_prefix%)%)%)%)%,%
%class_function_prefix,%(%else-then(%_Class_function_prefix%,%(%tolower(%Class_function_prefix%)%)%)%)%,%
%class_function_suffix,%(%else-then(%class_function_suffix%,%(%right(%class_function_name_fixes%,/)%)%)%)%,%
%Class_function_suffix,%(%else-then(%Class_function_suffix%,%(%class_function_suffix%)%)%)%,%
%CLASS_FUNCTION_SUFFIX,%(%else-then(%CLASS_FUNCTION_SUFFIX%,%(%toupper(%Class_function_suffix%)%)%)%)%,%
%class_function_suffix,%(%else-then(%_Class_function_suffix%,%(%tolower(%Class_function_suffix%)%)%)%)%,%
%file_is_class_prefix,%(%else-then(%file_is_class_prefix%,%(%if(%class_pattern_tc%%class_pattern_c%,%(c)%)%)%)%)%,%
%File_is_class_prefix,%(%else-then(%File_is_class_prefix%,%(%file_is_class_prefix%)%)%)%,%
%FILE_IS_CLASS_PREFIX,%(%else-then(%FILE_IS_CLASS_PREFIX%,%(%toupper(%File_is_class_prefix%)%)%)%)%,%
%file_is_class_prefix,%(%else-then(%_File_is_class_prefix%,%(%tolower(%File_is_class_prefix%)%)%)%)%,%
%file,%(%else-then(%file%,%(%if(%file_is_class%,%(%File_is_class_prefix%%Member_class%)%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%file%)%)%)%)%,%
%file_extension_of_file,%(%else-then(%file_extension_of_file%,%(%fileextension(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension_of_file%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(%else-then(%filetype%,%(hxx)%)%)%)%)%,%
%file_type_extension,%(%else-then(%file_type_extension%,%(%file_type%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%file_type_extension%)%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension_of_file%,%(.%file_extension%)%)%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%File_type,%(%else-then(%File_type%,%(%file_type%)%)%)%,%
%FILE_TYPE,%(%else-then(%FILE_TYPE%,%(%toupper(%File_type%)%)%)%)%,%
%file_type,%(%else-then(%_File_type%,%(%tolower(%File_type%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
%module,%(%else-then(%module%,%()%)%)%,%
%Module,%(%else-then(%Module%,%(%module%)%)%)%,%
%MODULE,%(%else-then(%MODULE%,%(%toupper(%Module%)%)%)%)%,%
%module,%(%else-then(%_Module%,%(%tolower(%Module%)%)%)%)%,%
%file_module,%(%else-then(%file_module%,%(%if-then(%Module%,%(_)%)%)%)%)%,%
%File_module,%(%else-then(%File_module%,%(%file_module%)%)%)%,%
%FILE_MODULE,%(%else-then(%FILE_MODULE%,%(%toupper(%File_module%)%)%)%)%,%
%file_module,%(%else-then(%_File_module%,%(%tolower(%File_module%)%)%)%)%,%
%file_h,%(%else-then(%file_h%,%(%equal(h,%file_type%)%)%)%)%,%
%file_c,%(%else-then(%file_c%,%(%equal(c,%file_type%)%)%)%)%,%
%file_hpp,%(%else-then(%file_hpp%,%(%equal(hpp,%file_type%)%)%)%)%,%
%file_cpp,%(%else-then(%file_cpp%,%(%equal(cpp,%file_type%)%)%)%)%,%
%file_hxx,%(%else-then(%file_hxx%,%(%equal(hpp,%file_type%)%%equal(hxx,%file_type%)%%equal(h,%file_type%)%)%)%)%,%
%file_cxx,%(%else-then(%file_cxx%,%(%equal(cpp,%file_type%)%%equal(cxx,%file_type%)%%equal(c,%file_type%)%)%)%)%,%
%file_hxx_extension,%(%else-then(%file_hxx_extension%,%(%if(%file_c%,h,%(%if(%file_cpp%,hpp,hxx)%)%)%)%)%)%,%
%file_cxx_type,%(%if(%file_cpp%%file_cxx%%file_c%,%(cxx)%,%(%if(%file_hpp%%file_hxx%%file_h%,%(hxx)%)%)%)%)%,%
%file_ifndef,%(%else-then(%file_ifndef%,%(%_XDE_%%FILE_MODULE%%FILE_BASE%_%FILE_EXTENSION%)%)%)%,%
%file_ifndef_cc,%(%else-then(%file_ifndef_cc%,%(%cc_%%left_comment% %file_ifndef% %right_comment%%_cc%)%)%)%,%
%file_class_ifdef,%(!%_defined_%(%file_ifndef%) || %_defined_%(%CLASS_MEMBERS_ONLY%))%,%
%file_class_ifndef,%(!%_defined_%(%file_ifndef%) && !%_defined_%(%CLASS_MEMBERS_ONLY%))%,%
%file_class_ifdef_cc,%(%cc_%%left_comment% !defined(%file_ifndef%) || defined(%CLASS_MEMBERS_ONLY%) %right_comment%%_cc%)%,%
%file_class_ifndef_cc,%(%cc_%%left_comment% !defined(%file_ifndef%) && !defined(%CLASS_MEMBERS_ONLY%) %right_comment%%_cc%)%,%
%file_class_members_ifndef,%(!%_defined_%(%CLASS_MEMBERS_ONLY%))%,%
%file_class_members_ifndef_cc,%(%cc_%%left_comment% !defined(%CLASS_MEMBERS_ONLY%) %right_comment%%_cc%)%,%
%class_namespace_ifdef,%(%_defined_%(%Class_namespace_define%))%,%
%class_namespace_ifdef_cc,%(%cc_%%left_comment% defined(%Class_namespace_define%) %right_comment%%_cc%)%,%
%class_member_funcs_ifdefs,%(%else(%equal(no,%class_member_funcs_ifdefs%)%,%(%object_class%)%)%)%,%
%class_member_funcs_interface_ifdefs,%(%else(%equal(no,%class_member_funcs_interface_ifdefs%)%,%(%class_member_funcs_ifdefs%)%)%)%,%
%class_member_funcs_interface_ifdef,%(%_defined_%(%CLASS_MEMBER_FUNCS_INTERFACE%))%,%
%class_member_funcs_interface_ifdef_cc,%(%cc_%%left_comment% defined(%CLASS_MEMBER_FUNCS_INTERFACE%) %right_comment%%_cc%)%,%
%class_member_funcs_implement_ifdefs,%(%else(%equal(no,%class_member_funcs_implement_ifdefs%)%,%(%class_member_funcs_interface_ifdefs%)%)%)%,%
%class_member_funcs_implement_ifdef,%(%_defined_%(%CLASS_MEMBER_FUNCS_IMPLEMENT%))%,%
%class_member_funcs_implement_ifdef_cc,%(%cc_%%left_comment% defined(%CLASS_MEMBER_FUNCS_IMPLEMENT%) %right_comment%%_cc%)%,%
%class_member_funcs_implement_ifndefs,%(%else(%equal(no,%class_member_funcs_implement_ifndefs%)%,%(%class_member_funcs_implement_ifdefs%)%)%)%,%
%class_member_funcs_implement_ifndef,%(!%_defined_%(%CLASS_MEMBER_FUNCS_IMPLEMENT%))%,%
%class_member_funcs_implement_ifndef_cc,%(%cc_%%left_comment% !defined(%CLASS_MEMBER_FUNCS_IMPLEMENT%) %right_comment%%_cc%)%,%
%derived_fileinclude,%(%derived_includefile%)%,%
%hxx_cxx_fileinclude,%(%hxx_cxx_includefile%)%,%
%derived_includefile,%()%,%
%hxx_cxx_includefile,%()%,%
%%(%
%%if(%file%,%(%
%%include(%filepath%/mxde-hxx-cxx-file.t)%%
%)%,%(%
%%include(%derived_fileinclude%%hxx_cxx_fileinclude%)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%