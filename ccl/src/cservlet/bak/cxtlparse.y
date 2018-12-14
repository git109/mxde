/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cxtlparse.y
 *
 * Author: $author$
 *   Date: 12/21/2004
 *
 *    $Id$
 **********************************************************************
 */

/*
 * tokens
 */

%token XX_INCLUDE XX_USING
%token XX_TRANSFORM XX_TEMPLATE
%token XX_VARIABLE XX_PARAMETER XX_WITH XX_TO
%token XX_OUTPUT XX_METHOD XX_FILE XX_LOCATION XX_NAME XX_TEST XX_SELECT XX_MATCH
%token XX_APPLY XX_DO XX_WHILE XX_UNTIL XX_REPEAT XX_FOR XX_FOR_EACH
%token XX_SWITCH XX_CASE XX_DEFAULT XX_IF XX_THEN XX_ELSE_IF XX_ELSE
%token XX_BEGIN XX_END XX_BEGIN_ATTR XX_END_ATTR
%token XX_XMLNS_ATTR XX_VARIABLE_ATTR
%token XX_ELEMENT_LITERAL XX_ATTR_LITERAL XX_TEXT_LITERAL
%token XX_INVALID

/*
 * defines and includes
 */
%{
#include "cxtlparser.hxx"
%}

/*
 * rules
 */
%%

transform_declaration
: XX_TRANSFORM transform_attr_body transform_body
| XX_TRANSFORM transform_body
;

transform_body
: XX_BEGIN transform_block XX_END
| XX_BEGIN XX_END
;

transform_attr_body
: XX_BEGIN_ATTR transform_attr_list XX_END_ATTR
| XX_BEGIN_ATTR XX_END_ATTR
;

transform_attr_list
: transform_attr transform_attr_list
| transform_attr
;

transform_attr
: XX_XMLNS_ATTR { OnXmlnsAttr(); }
;

transform_block
: transform_output transform_block_list
| transform_block_list
;

transform_output
: XX_OUTPUT transform_output_attr XX_BEGIN XX_END
;

transform_output_attr
: XX_BEGIN_ATTR method_value XX_END_ATTR
;

transform_block_list
: transform_block_item transform_block_list
| transform_block_item
;

transform_block_item
: transform_block_declaration
| statement
;

transform_block_declaration
: include_declaration
| template_declaration
| parameter_declaration
| variable_declaration
;

include_declaration
: XX_INCLUDE include_declaration_body
;

include_declaration_body
: include_location include_body
;

include_location
: location_expr {if ((m_error = OnIncludeLocation())) return m_error;}
;

include_body
: transform_declaration XX_BEGIN XX_END
| XX_BEGIN XX_END
;

template_declaration
: XX_TEMPLATE name_match_expr template_body
| XX_TEMPLATE name_expr template_body
| XX_TEMPLATE match_expr template_body
;

template_body
: XX_BEGIN template_block XX_END
| XX_BEGIN XX_END
;

template_block
: template_block_item template_block
| template_block_item
;

template_block_item
: template_block_declaration
| statement
;

template_block_declaration
: template_declaration
| parameter_declaration
| variable_declaration
;

statement
: apply_statement
| select_statement
| for_each_statement
| while_statement
| until_statement
| do_test_statement
| if_statement
| literal_statement
;

literal_statement
: XX_ELEMENT_LITERAL literal_statement_body
| XX_TEXT_LITERAL
;

literal_statement_body
: literal_expr statement_body
| statement_body
;

apply_statement
: XX_APPLY apply_statement_body
;

apply_statement_body
: name_expr apply_select_with_body
| name_select_expr apply_with_body
| name_expr apply_with_body
| select_expr apply_with_body
| apply_select_with_body
;

apply_select_with_body
: XX_BEGIN select_statement apply_with_list XX_END
| XX_BEGIN select_statement XX_END
;

apply_with_body
: XX_BEGIN apply_with_list XX_END
| XX_BEGIN XX_END
;

apply_with_list
: apply_with apply_with_list
| apply_with
;

apply_with
: XX_WITH name_select_statement_body
;

select_statement
: XX_SELECT name_statement_body
| XX_SELECT match_statement_body
;

match_statement_body
: match_expr statement_body
| XX_BEGIN match_statement_list XX_END
;

match_statement_list
: match_statement match_statement_list
| match_statement
;

match_statement
: XX_MATCH match_expr XX_BEGIN XX_END
;

name_statement_body
: name_expr XX_BEGIN XX_END
| statement_body
;

for_each_statement
: XX_FOR_EACH for_each_statement_body
;

for_each_statement_body
: select_expr statement_body
| XX_BEGIN select_statement do_statement XX_END
;

while_statement
: XX_WHILE test_do_statement
;

until_statement
: XX_UNTIL test_do_statement
;

test_do_statement
: test_expr statement_body
| test_do_body
;

test_do_body
: XX_BEGIN test_statement do_statement XX_END
;

do_statement
: XX_DO statement_body
;

do_test_statement
: XX_DO do_while_statement
| XX_DO do_until_statement
;

do_while_statement
: while_expr statement_body
| statement_body do_while_test
;

do_while_test
: XX_WHILE do_test
;

do_until_statement
: until_expr statement_body
| statement_body do_until_test
;

do_until_test
: XX_UNTIL do_test
;

do_test
: test_expr XX_BEGIN XX_END
| statement_body
;

if_statement
: XX_IF test_then_else_expr XX_BEGIN XX_END
| XX_IF test_then_expr XX_BEGIN else_statement_list XX_END
| XX_IF test_then_expr XX_BEGIN XX_END
| XX_IF test_expr XX_BEGIN then_statement_list XX_END
| XX_IF XX_BEGIN test_then_statement_list XX_END
| XX_IF test_expr statement_body
;

test_then_statement_list
: test_statement then_statement_list
;

test_statement
: XX_TEST test_statement_body
;

test_statement_body
: select_expr XX_BEGIN XX_END
| statement_body
;

then_statement_list
: then_statement else_statement_list
| then_statement
;

then_statement
: XX_THEN statement_body
;

else_statement_list
: else_if_statement_list XX_ELSE statement_body
| XX_ELSE statement_body
;

else_if_statement_list
: else_if_statement else_if_statement_list
| else_if_statement
;

else_if_statement
: XX_ELSE_IF test_expr XX_BEGIN XX_END
;

statement_body
: XX_BEGIN statement_block XX_END
| XX_BEGIN XX_END
;

statement_block
: statement_block_item statement_block
| statement_block_item
;

statement_block_item
: statement_block_declaration
| statement
;

statement_block_declaration
: template_declaration
| variable_declaration
;

parameter_declaration
: XX_PARAMETER name_select_statement_body
;

variable_declaration
: XX_VARIABLE name_select_statement_body
;

name_select_statement_body
: name_select_expr XX_BEGIN XX_END
| name_expr statement_body
;

location_expr
: XX_BEGIN_ATTR location_value XX_END_ATTR
;

name_match_expr
: XX_BEGIN_ATTR name_value match_value XX_END_ATTR
;

name_expr
: XX_BEGIN_ATTR name_value XX_END_ATTR
;

match_expr
: XX_BEGIN_ATTR match_value XX_END_ATTR
;

test_then_else_expr
: XX_BEGIN_ATTR test_value then_value else_value XX_END_ATTR
;

test_then_expr
: XX_BEGIN_ATTR test_value then_value XX_END_ATTR
;

until_expr
: XX_BEGIN_ATTR until_value XX_END_ATTR
;

while_expr
: XX_BEGIN_ATTR while_value XX_END_ATTR
;

test_expr
: XX_BEGIN_ATTR test_value XX_END_ATTR
;

name_select_expr
: XX_BEGIN_ATTR name_value select_value XX_END_ATTR
;

select_expr
: XX_BEGIN_ATTR select_value XX_END_ATTR
;

literal_expr
: begin_attr literal_value_list end_attr
;

begin_attr
: XX_BEGIN_ATTR {OnBeginAttr();}
;

end_attr
: XX_END_ATTR {OnEndAttr();}
;

literal_value_list
: literal_value_item literal_value_list
| literal_value_item
;

literal_value_item
: variable_value
| literal_value
;

location_value
: XX_LOCATION {if ((m_error = OnLocationValue())) return m_error;}
;

method_value
: XX_METHOD { if ((m_error = OnMethodValue())) return m_error; }
;

name_value
: XX_NAME { if ((m_error = OnNameValue())) return m_error; }
;

match_value
: XX_MATCH { if ((m_error = OnMatchValue())) return m_error; }
;

while_value
: XX_WHILE { if ((m_error = OnExpression())) return m_error; }
;

until_value
: XX_UNTIL { if ((m_error = OnExpression())) return m_error; }
;

test_value
: XX_TEST { if ((m_error = OnExpression())) return m_error; }
;

select_value
: XX_SELECT { if ((m_error = OnExpression())) return m_error; }
;

then_value
: XX_THEN { if ((m_error = OnExpression())) return m_error; }
;

else_value
: XX_ELSE { if ((m_error = OnExpression())) return m_error; }
;

variable_value
: XX_VARIABLE_ATTR { if ((m_error = OnVariableExpression())) return m_error; }
;

literal_value
: XX_ATTR_LITERAL { if ((m_error = OnLiteralExpression())) return m_error; }
;

%%
