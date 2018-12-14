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
 *   Date: 8/25/2003
 *
 *    $Id$
 **********************************************************************
 */

%token INCLUDE USING EXTERN FOREIGN NATIVE
%token FRIEND PUBLIC PRIVATE PROTECTED
%token CONST STATIC AUTO REGISTER VOLITILE INTERRUPT
%token CDECL PASCAL PACKED PARALLEL REMOTE SHARED
%token PURE VIRTUAL OPERATOR ABSOLUTE IO
%token PROCESS MODULE MAIN THREAD SIGNAL CLASS NAMESPACE
%token STRUCT UNION ARRAY SET STRING SIGNED UNSIGNED FLOAT VOID ENUM
%token DOUBLE SHORT LONG INT CHAR BOOL TRUE FALSE
%token WHAT AT IS SUPER THIS NEW DELETE
%token POSITIONOF SIZEOF TYPEOF TEXTOF
%token POSITIONIS SIZEIS TYPEIS TEXTIS
%token TEMPLATE

%token DO WHILE UNTIL REPEAT FOR EACH OF SWITCH CASE DEFAULT IF ELSE
%token BEFORE AFTER WHEN GOTO BREAK CONTINUE RETURN
%token THROW TRY CATCH WITH

%token COLONCOLON_AND COLONCOLON_STAR COLONCOLON DOTDOT ELIPSIS
%token BSLASHBSLASH_SHR BSLASHBSLASH_SHL
%token BSLASHBSLASH BSLASHQUESTION
%token DOTBSLASHQUESTION DOTQUESTION ATQUESTION

%token ASSIGN LAND_ASSIGN LOR_ASSIGN LXOR_ASSIGN
%token POW_ASSIGN ROO_ASSIGN LOG_ASSIGN SHR_ASSIGN SHL_ASSIGN
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN QUO_ASSIGN
%token AND_ASSIGN OR_ASSIGN XOR_ASSIGN
%token RIGHT_OP LEFT_OP INC_OP DEC_OP COM_OP LCOM_OP
%token LE_OP GE_OP NE_OP EQ_OP
%token SHR_OP SHL_OP POW_OP ROO_OP LOG_OP
%token LNOT_OP LAND_OP LOR_OP

%token DEC_LITERAL BIN_LITERAL HEX_LITERAL OCT_LITERAL FLOAT_LITERAL
%token CHAR_LITERAL URI_LITERAL TEXT_LITERAL TEMPLATE_LITERAL ELEMENT_LITERAL
%token IDENTIFIER

%{
#undef NULL
#include "cdtparse.h"
#include "cdtparser.hxx"
%}

%%

/*
 **********************************************************************
 **********************************************************************
 */

file
 : file_definitions { return OnParsed();}
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
 | statement_expr
 ;

using
 : USING using_identifier ';'
 ;

using_identifier
 : uri_identifier document_qualified_class_name
 | uri_identifier
 ;

include
 : include_designator include_definitions
 ;

include_designator
 : INCLUDE URI_LITERAL { if ((m_error=OnInclude())) return m_error;}
 ;

include_definitions
 : file_definitions ';'
 | ';'
 ;

file_interface_definition
 : file_interface_designator interface_body
 ;

file_interface_designator
 : VIRTUAL CLASS uri_qualified_class_name  {if ((m_error=OnInterfaceName())) return m_error;}
 ;

interface_definition
 : interface_designator interface_body
 ;

interface_designator
 : VIRTUAL CLASS qualified_class_name  {if ((m_error=OnInterfaceName())) return m_error;}
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
 : interface_definition         {if ((m_error=OnMember())) return m_error;}
 | class_definition             {if ((m_error=OnMember())) return m_error;}
 | interface_template_prototype {if ((m_error=OnMember())) return m_error;}
 ;

interface_template_prototype
 : VIRTUAL template_prototype ';'
 ;

file_namespace_definition
 : file_namespace_designator namespace_body
 ;

file_namespace_designator
 : NAMESPACE uri_qualified_class_name  {if ((m_error=OnNamespaceName())) return m_error;}
 ;

namespace_definition
 : namespace_designator namespace_body
 ;

namespace_designator
 : NAMESPACE qualified_class_name  {if ((m_error=OnNamespaceName())) return m_error;}
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
 : namespace_definition    {if ((m_error=OnMember())) return m_error;}
 | class_definition    {if ((m_error=OnMember())) return m_error;}
 | template_definition {if ((m_error=OnMember())) return m_error;}
 ;

file_class_definition
 : file_class_designator ':' class_is_list class_body
 | file_class_designator class_body
 ;

file_class_designator
 : CLASS uri_qualified_class_name  {if ((m_error=OnClassName())) return m_error;}
 ;

class_definition
 : class_designator ':' class_is_list class_body
 | class_designator class_body
 ;

class_designator
 : CLASS qualified_class_name  {if ((m_error=OnClassName())) return m_error;}
 ;

class_is_list
 : class_is_list ',' class_is
 | class_is
 ;

class_is
 : uri_qualified_class_name {if ((m_error=OnClassIs())) return m_error;}
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
 : class_definition     {if ((m_error=OnMember())) return m_error;}
 | class_template_definition  {if ((m_error=OnMember())) return m_error;}
 | variable_declaration {if ((m_error=OnMember())) return m_error;}
 ;

class_template_definition
 : VIRTUAL template_definition
 | template_definition
 ;

template_definition
 : template_prototype compond_statement {if ((m_error=OnTemplate())) return m_error;}
 ;

template_prototype
 : template_designator parameters
 ;

template_designator
 : type_specification class_name {if ((m_error=OnTypedTemplateName())) return m_error;}
 | VOID call_name            {if ((m_error=OnTemplateName())) return m_error;}
 | TEMPLATE call_name            {if ((m_error=OnTemplateName())) return m_error;}
 ;

call_name
 : call_name_identifier {if ((m_error=OnCallIdentifier())) return m_error;}
 ;

call_name_identifier
 : IDENTIFIER
 | TEXT_LITERAL
 ;

parameters
 : '(' parameter_list ')' {if ((m_error=OnTemplateParameters())) return m_error;}
 | empty_parameters
 ;

empty_parameters
 : '(' ')'
 ;

parameter_list
 : parameter_list ',' 
   parameter_item {if ((m_error=OnTemplateParameter())) return m_error;}
 | parameter_item {if ((m_error=OnFirstTemplateParameter())) return m_error;}
 ;

parameter_item
 : type_specification 
   assignment_expr_item {if ((m_error=OnTypedTemplateParameterValue())) return m_error;}
 | assignment_expr_item {if ((m_error=OnTemplateParameterValue())) return m_error;}
 | type_specification 
   class_name           {if ((m_error=OnTypedTemplateParameterName())) return m_error;}
 | class_name           {if ((m_error=OnTemplateParameterName())) return m_error;}
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
 : '{' {if ((m_error=OnCompoundStatementBegin())) return m_error;}
 ;

compond_statement_list
 : compond_statement_list compond_statement_item
 | compond_statement_item
 ;
 
compond_statement_item
 : statement_expr {if ((m_error=OnCompoundStatementItem())) return m_error;}
 ;

if_statement
 : if_cond statement_expr ELSE statement_expr {if ((m_error=OnIfElse())) return m_error;}
 | if_cond statement_expr                     {if ((m_error=OnIfThen())) return m_error;}
 ;

if_cond
 : if_designator condition
 ;

if_designator
 : IF         {if ((m_error=OnIf())) return m_error;}
 | IF LNOT_OP {if ((m_error=OnIfNot())) return m_error;}
 ;

do_statement
 : DO statement_expr do_loop_condition ';'
 ;

do_loop_condition
 : WHILE condition {if ((m_error=OnDoWhile())) return m_error;}
 | UNTIL condition {if ((m_error=OnDoUntil())) return m_error;}
 ;

loop_statement
 : loop_type condition statement_expr {if ((m_error=OnLoop())) return m_error;}
 ;

loop_type
 : WHILE {if ((m_error=OnWhile())) return m_error;}
 | UNTIL {if ((m_error=OnUntil())) return m_error;}
 ;

condition
 : '(' expr ')'
 ;

null_condition
 : '(' ')'
 ;

with_statement
 : WITH condition statement_expr {if ((m_error=OnWith())) return m_error;}
 ;

for_each_statement
 : FOR EACH condition statement_expr {if ((m_error=OnForEachOf())) return m_error;}
 | FOR EACH null_condition statement_expr {if ((m_error=OnForEach())) return m_error;}
 | FOR EACH '@' condition statement_expr {if ((m_error=OnForEachAttributeOf())) return m_error;}
 | FOR EACH '@' null_condition statement_expr {if ((m_error=OnForEachAttribute())) return m_error;}
 ;

for_statement
 : FOR '(' expr ';' expr ';' expr ')' statement_expr {if ((m_error=OnFor())) return m_error;}
 ;

switch_statement
 : switch_condition '{' switch_cases '}'
 ;

switch_condition
 : SWITCH condition {if ((m_error=OnSwitchCondition())) return m_error;}
 ;

switch_cases
 : switch_case_list switch_default
 | switch_case_list
 | switch_default
 ;

switch_case_list
 : switch_case_statement_list {if ((m_error=OnSwitchCaseList())) return m_error;}
 ;

switch_default
 : default {if ((m_error=OnSwitchDefault())) return m_error;}
 ;

switch_case_statement_list
 : switch_case_statement_list switch_case_statement
 | switch_case_statement
 ;

switch_case_statement
 : switch_case_matches statement_expr {if ((m_error=OnSwitchCaseStatement())) return m_error;}
 ;

switch_case_matches
 : switch_case_matches switch_case_match {if ((m_error=OnSwitchCaseMatch())) return m_error;}
 | switch_case_match                     {if ((m_error=OnSwitchCase())) return m_error;}
 ;

switch_case_match
 : CASE conditional_expr ':'
 ;

default
 : DEFAULT ':' statement_expr
 ;

case_statement
 : case '{' cases '}'
 ;

case
 : CASE {if ((m_error=OnCase())) return m_error;}
 ;

cases
 : case_list case_default
 | case_list
 | case_default
 ;

case_list
 : case_statement_list {if ((m_error=OnCaseList())) return m_error;}
 ;

case_default
 : default {if ((m_error=OnCaseDefault())) return m_error;}
 ;

case_statement_list
 : case_statement_list case_when_statement
 | case_when_statement
 ;

case_when_statement
 : case_when_list statement_expr {if ((m_error=OnCaseWhenStatement())) return m_error;}
 ;

case_when_list
 : case_when_list case_when {if ((m_error=OnCaseWhenList())) return m_error;}
 | case_when                {if ((m_error=OnCaseWhen())) return m_error;}
 ;

case_when
 : WHEN conditional_expr ':'
 ;

/*
 **********************************************************************
 **********************************************************************
 */

/*
 **********************************************************************
 **********************************************************************
 */

%%
