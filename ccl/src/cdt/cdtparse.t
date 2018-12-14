%#################################################################
%#
%#   File: cdtparse.t
%#
%# Author: $author$
%#   Date: 2/16/2004
%#
%#    $Id$
%#
%#################################################################
/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: dtparse.y
 *
 * Author: $author$
 *   Date: %date()%
 *
 *    $Id$
 **********************************************************************
 */

%import(%else-then(%import_path%,../src)%/cdtparse-token.y)%
%%{
#undef NULL
#include "cdtparse.h"
#include "cdtparser.hxx"
#define YY(on) if ((m_error = on())) return YYOnError(""#on""); else YYOn(""#on"")
#define YY2(on,name) if ((m_error = on(name))) return YYOnError(""#on"",name); else YYOn(""#on"",name)
%%}

%%%%

/*
 **********************************************************************
 * file
 **********************************************************************
 */

file
 : file_definitions { return OnParsedDocument();}
 ;

file_definitions
 : file_definition file_definitions
 | file_definition
 ;

file_definition
 : using
 | include
 | file_interface_definition
 | file_namespace_definition
 | file_class_definition
 | template_definition
 | variable_declaration
 | statement_expr
 ;

using
 : XX_USING using_identifier ';'
 ;

using_identifier
 : uri_identifier document_qualified_class_name
 | uri_identifier
 ;

include
 : include_designator include_definitions
 ;

include_designator
 : XX_INCLUDE XX_TEXT_LITERAL { YY(OnInclude);}
 | XX_INCLUDE XX_URI_LITERAL { YY(OnIncludeURI);}
 ;

include_definitions
 : file_definitions ';'
 | ';'
 ;

file_interface_definition
 : file_interface_designator interface_body
 ;

file_interface_designator
 : XX_VIRTUAL XX_CLASS 
   uri_qualified_class_name  {YY(OnInterfaceName);}
 ;

interface_definition
 : interface_designator interface_body
 ;

interface_designator
 : XX_VIRTUAL XX_CLASS 
   qualified_class_name  {YY(OnInterfaceName);}
 ;

interface_body
 : '{' interface_member_definitions '}'
 | '{' '}'
 ;

interface_member_definitions
 : interface_member_definitions interface_member_definition
 | interface_member_definition
 ;

interface_member_definition
 : interface_definition         {YY(OnMember);}
 | class_definition             {YY(OnMember);}
 | interface_template_prototype {YY(OnMember);}
 ;

interface_template_prototype
 : XX_VIRTUAL template_prototype ';'
 ;

file_namespace_definition
 : file_namespace_designator namespace_body
 ;

file_namespace_designator
 : XX_NAMESPACE uri_qualified_class_name  {YY(OnNamespaceName);}
 ;

namespace_definition
 : namespace_designator namespace_body
 ;

namespace_designator
 : XX_NAMESPACE qualified_class_name  {YY(OnNamespaceName);}
 ;

namespace_body
 : '{' namespace_member_definitions '}'
 | '{' '}'
 ;

namespace_member_definitions
 : namespace_member_definitions namespace_member_definition
 | namespace_member_definition
 ;

namespace_member_definition
 : namespace_definition    {YY(OnMember);}
 | class_definition    {YY(OnMember);}
 | template_definition {YY(OnMember);}
 ;

file_class_definition
 : file_class_designator ':' class_is_list class_body
 | file_class_designator class_body
 ;

file_class_designator
 : XX_CLASS uri_qualified_class_name  {YY(OnClassName);}
 ;

class_definition
 : class_designator ':' class_is_list class_body
 | class_designator class_body
 ;

class_designator
 : XX_CLASS qualified_class_name  {YY(OnClassName);}
 ;

class_is_list
 : class_is_list ',' class_is
 | class_is
 ;

class_is
 : uri_qualified_class_name {YY(OnClassIs);}
 ;

class_body
 : '{' class_member_definitions '}'
 | '{' '}'
 ;

class_member_definitions
 : class_member_definitions class_member_definition
 | class_member_definition
 ;

class_member_definition
 : class_definition     {YY(OnMember);}
 | class_template_definition  {YY(OnMember);}
 | variable_declaration {YY(OnMember);}
 ;

class_template_definition
 : XX_VIRTUAL template_definition
 | template_definition
 ;

template_definition
 : template_prototype compond_statement {YY(OnTemplate);}
 ;

template_prototype
 : template_designator parameters
 ;

template_designator
 : typed_designator      {YY(OnTypedTemplateName);}
 | untyped_designator    {YY(OnTemplateName);}
 ;

typed_designator
 : type_specification class_name
 ;

untyped_designator
 : XX_VOID call_name
 | XX_TEMPLATE call_name
 ;

call_name
 : call_name_identifier {YY(OnCallIdentifier);}
 ;

call_name_identifier
 : XX_IDENTIFIER
 | XX_TEXT_LITERAL
 ;

parameters
 : '(' parameter_list ')' {YY(OnTemplateParameters);}
 | empty_parameters
 ;

empty_parameters
 : '(' ')'
 ;

parameter_list
 : parameter_list ',' 
   parameter_item {YY(OnTemplateParameter);}
 | parameter_item {YY(OnFirstTemplateParameter);}
 ;

parameter_item
 : type_specification 
   assignment_expr_item {YY(OnTypedTemplateParameterValue);}
 | assignment_expr_item {YY(OnTemplateParameterValue);}
 | type_specification 
   class_name           {YY(OnTypedTemplateParameterName);}
 | class_name           {YY(OnTemplateParameterName);}
 ;

assignment_expr_item
 : class_name '=' conditional_expr
 ;

statement_expr
 : statement
 | expr_list ';'
 ;

statement
 : if_statement
 | do_statement
 | loop_statement
 | for_statement
 | for_each_statement
 | with_statement
 | switch_statement
 | case_statement
 | compond_statement
 ;

compond_statement
 : compond_statement_begin compond_statement_list '}'
 | compond_statement_begin '}'
 ;

compond_statement_begin
 : '{' {YY(OnCompoundStatementBegin);}
 ;

compond_statement_list
 : compond_statement_list compond_statement_item
 | compond_statement_item
 ;
 
compond_statement_item
 : statement_expr {YY(OnCompoundStatementItem);}
 ;

if_statement
 : if_cond statement_expr XX_ELSE statement_expr {YY(OnIfElse);}
 | if_cond statement_expr                        {YY(OnIfThen);}
 ;

if_cond
 : if_designator condition
 ;

if_designator
 : XX_IF         {YY(OnIf);}
 | XX_IF XX_LNOT_OP {YY(OnIfNot);}
 ;

do_statement
 : XX_DO statement_expr do_loop_condition ';'
 ;

do_loop_condition
 : XX_WHILE condition {YY(OnDoWhile);}
 | XX_UNTIL condition {YY(OnDoUntil);}
 ;

loop_statement
 : loop_type condition statement_expr {YY(OnLoop);}
 ;

loop_type
 : XX_WHILE {YY(OnWhile);}
 | XX_UNTIL {YY(OnUntil);}
 ;

condition
 : '(' expr ')'
 ;

null_condition
 : '(' ')'
 ;

with_statement
 : XX_WITH arguments statement_expr {YY(OnWith);}
 ;

for_each_statement
 : XX_FOR XX_EACH condition statement_expr {YY(OnForEachOf);}
 | XX_FOR XX_EACH null_condition statement_expr {YY(OnForEach);}
 | XX_FOR XX_EACH '@' condition statement_expr {YY(OnForEachAttributeOf);}
 | XX_FOR XX_EACH '@' null_condition statement_expr {YY(OnForEachAttribute);}
 ;

for_statement
 : XX_FOR '(' expr ';' expr ';' expr ')' statement_expr {YY(OnFor);}
 ;

switch_statement
 : switch_condition '{' switch_cases '}'
 ;

switch_condition
 : XX_SWITCH condition {YY(OnSwitchCondition);}
 ;

switch_cases
 : switch_case_list switch_default
 | switch_case_list
 | switch_default
 ;

switch_case_list
 : switch_case_statement_list {YY(OnSwitchCaseList);}
 ;

switch_default
 : default {YY(OnSwitchDefault);}
 ;

switch_case_statement_list
 : switch_case_statement_list switch_case_statement
 | switch_case_statement
 ;

switch_case_statement
 : switch_case_matches statement_expr {YY(OnSwitchCaseStatement);}
 ;

switch_case_matches
 : switch_case_matches switch_case_match {YY(OnSwitchCaseMatch);}
 | switch_case_match                     {YY(OnSwitchCase);}
 ;

switch_case_match
 : XX_CASE conditional_expr ':'
 ;

default
 : XX_DEFAULT ':' statement_expr
 ;

case_statement
 : case '{' cases '}'
 ;

case
 : XX_CASE {YY(OnCase);}
 ;

cases
 : case_list case_default
 | case_list
 | case_default
 ;

case_list
 : case_statement_list {YY(OnCaseList);}
 ;

case_default
 : default {YY(OnCaseDefault);}
 ;

case_statement_list
 : case_statement_list case_when_statement
 | case_when_statement
 ;

case_when_statement
 : case_when_list statement_expr {YY(OnCaseWhenStatement);}
 ;

case_when_list
 : case_when_list case_when {YY(OnCaseWhenList);}
 | case_when                {YY(OnCaseWhen);}
 ;

case_when
 : XX_WHEN conditional_expr ':'
 ;

%import(%else-then(%import_path%,../src)%/cdtparse-expression.y)%
%%%%
