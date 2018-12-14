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
 *   File: cdxparse.y
 *
 * Author: $author$
 *   Date: 4/16/2004
 *
 *    $Id$
 **********************************************************************
 */

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
 *   File: cdtparse-token.y
 *
 * Author: $author$
 *   Date: 2/16/2004
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
#include "cdxparser.hxx"
%}

%%

parsed
 : expr { return OnParsed();}
 ;

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
 *   File: cdtparse-expression.y
 *
 * Author: $author$
 *   Date: 2/16/2004
 *
 *    $Id$
 **********************************************************************
 */

/*
 **********************************************************************
 * variables
 **********************************************************************
 */

variable_declaration
 : type_specification class_name ';' {if ((m_error=OnVariableDeclaration())) return m_error;}
 ;

/*
 **********************************************************************
 * types
 **********************************************************************
 */

type_specification
 : type_definition {if ((m_error=OnTypeDefinition())) return m_error;}
 | type_reference
 ;

type_definition
 : void_type
   of_dimentions       {if ((m_error=OnDimentionedTypeReference())) return m_error;}
 | type_reference 
   of_dimentions       {if ((m_error=OnDimentionedTypeReference())) return m_error;}
 | new_type_definition 
   of_dimentions       {if ((m_error=OnDimentionedTypeDefinition())) return m_error;}
 | new_type_definition
 ;

new_type_definition
 : struct_definition
 ;

struct_definition
 : struct_designator '{' struct_member_definitions '}'
 ;

struct_designator
 : STRUCT {if ((m_error=OnStruct())) return m_error;}
 | UNION {if ((m_error=OnUnion())) return m_error;}
 ;

struct_member_definitions
 : struct_member_definitions struct_member_definition
 | struct_member_definition
 ;

struct_member_definition
 : variable_declaration {if ((m_error=OnMember())) return m_error;}
 ;

of_dimentions
 : of_dimentions 
   dimentions {if ((m_error=OnOfDimentions())) return m_error;}
 | dimentions {if ((m_error=OnDimentions())) return m_error;}
 ;

dimentions
 : '[' dimention_list ']'
 | '['']' {if ((m_error=OnUnboundDimentions())) return m_error;}
 ;

dimention_list
 : dimention_list 
   ',' dimention_expr {if ((m_error=OnDimentionList())) return m_error;}
 | ',' dimention_expr {if ((m_error=OnUnboundDimention())) return m_error;}
 | dimention_expr     {if ((m_error=OnDimention())) return m_error;}
 ;

dimention_expr
 : conditional_expr {if ((m_error=OnDimentionExpr())) return m_error;}
 ;

type_reference
 : CLASS uri_qualified_class_name
   {if ((m_error=OnTypeReference())) return m_error;}
 | intrinsic_type
 ;

void_type
 : VOID {if ((m_error=OnFunction("void"))) return m_error;}
 ;

intrinsic_type
 : UNSIGNED {if ((m_error=OnIntrinsicType("unsigned"))) return m_error;}
 | SIGNED {if ((m_error=OnIntrinsicType("signed"))) return m_error;}
 | SHORT {if ((m_error=OnIntrinsicType("short"))) return m_error;}
 | LONG {if ((m_error=OnIntrinsicType("long"))) return m_error;}
 | INT {if ((m_error=OnIntrinsicType("int"))) return m_error;}
 | FLOAT {if ((m_error=OnIntrinsicType("float"))) return m_error;}
 | DOUBLE {if ((m_error=OnIntrinsicType("double"))) return m_error;}
 | STRING {if ((m_error=OnIntrinsicType("string"))) return m_error;}
 | CHAR {if ((m_error=OnIntrinsicType("char"))) return m_error;}
 | BOOL {if ((m_error=OnIntrinsicType("bool"))) return m_error;}
 ;

/*
 **********************************************************************
 * names
 **********************************************************************
 */

uri_qualified_class_name
 : uri_identifier 
   document_qualified_class_name {if ((m_error=OnURIQualifiedName())) return m_error;}
 | document_qualified_class_name
 ;

document_qualified_class_name
 : COLONCOLON class_name 
   COLONCOLON qualified_class_name {if ((m_error=OnDocumentQualifiedName())) return m_error;}
 | COLONCOLON class_name           {if ((m_error=OnDocumentLevelName())) return m_error;}
 | qualified_class_name
 ;

uri_identifier
 : URI_LITERAL {if ((m_error=OnURIdentifier())) return m_error;}
 ;

qualified_class_name
 : qualified_class_name COLONCOLON
   class_name {if ((m_error=OnElementQualifiedName())) return m_error;}
 | class_name {if ((m_error=OnElementLevelName())) return m_error;}
 ;

class_name
 : class_identifier {if ((m_error=OnIdentifier())) return m_error;}
 ;

class_identifier
 : IDENTIFIER
 | TEXT_LITERAL
 ;

/*
 **********************************************************************
 * expressions
 **********************************************************************
 */

expr
 : typed_assignment_expr
 ;

typed_assignment_expr
 : CLASS variable_expr assignment_op assignment_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | assignment_expr
 ;

assignment_expr
 : variable_expr assignment_op assignment_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | conditional_expr
 ;

conditional_expr
 : logical_or_expr '?' conditional_expr ':' conditional_expr {if ((m_error=OnConditionalExpr())) return m_error;}
 | logical_or_expr '!' conditional_expr                      {if ((m_error=OnElseConditionalExpr())) return m_error;}
 | logical_or_expr
 ;

logical_or_expr
 : logical_or_expr logical_or_op logical_and_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | logical_and_expr
 ;

logical_and_expr
 : logical_and_expr logical_and_op logical_not_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | logical_not_expr
 ;

logical_not_expr
 : logical_not_op equality_expr {if ((m_error=OnUnaryExpr())) return m_error;}
 | equality_expr
 ;

equality_expr
 : equality_expr equality_op relational_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | relational_expr
 ;

relational_expr
 : relational_expr relational_op or_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | or_expr
 ;

or_expr
 : or_expr or_op xor_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | xor_expr
 ;

xor_expr
 : xor_expr xor_op and_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | and_expr
 ;

and_expr
 : and_expr and_op shift_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | shift_expr
 ;

shift_expr
 : shift_expr shift_op add_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | add_expr
 ;

add_expr
 : add_expr add_op mul_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | mul_expr
 ;

mul_expr
 : mul_expr mul_op pow_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | pow_expr
 ;

pow_expr
 : pow_expr pow_op cast_expr {if ((m_error=OnBinaryExpr())) return m_error;}
 | cast_expr
 ;

cast_expr
 : '(' type_specification ')' cast_expr {if ((m_error=OnCastExpr())) return m_error;}
 | unary_expr
 ;

unary_expr
 : unary_op select_expr {if ((m_error=OnUnaryExpr())) return m_error;}
 | select_expr
 ;

select_expr
 : select_expr '.' 
   call_identifier arguments             {if ((m_error=OnMethodOfCall())) return m_error;}
 | select_expr '.' call_identifier       {if ((m_error=OnGetMemberOf())) return m_error;}
 | select_expr DOTQUESTION '[' expr ']'  {if ((m_error=OnGetMembersOfWhere())) return m_error;}
 | '.' call_identifier arguments         {if ((m_error=OnMethodCall())) return m_error;}
 | '.' call_identifier                   {if ((m_error=OnGetMember())) return m_error;}
 | DOTQUESTION '[' expr ']'              {if ((m_error=OnGetMembersWhere())) return m_error;}

 | select_expr '@''[' expr ']'             {if ((m_error=OnAttributeOfAt())) return m_error;}
 | select_expr '@''[' expr ELIPSIS expr']' {if ((m_error=OnAttributesOfRange())) return m_error;}
 | select_expr '@''[' '?' expr ']'         {if ((m_error=OnAttributesOfWhere())) return m_error;}
 | select_expr '@''[' '<' ELIPSIS ']'      {if ((m_error=OnFirstAttributeOf())) return m_error;}
 | select_expr '@''[' ELIPSIS '>' ']'      {if ((m_error=OnLastAttributeOf())) return m_error;}
 | select_expr '@''[' ELIPSIS ']'          {if ((m_error=OnAllAttributesOf())) return m_error;}
 | select_expr '@' primary_expr            {if ((m_error=OnAttributeOf())) return m_error;}
 
 | select_expr '\\' '[' expr ']'                {if ((m_error=OnElementAtExpr())) return m_error;}
 | select_expr '\\' '[' expr  ELIPSIS expr']'   {if ((m_error=OnElementRangeExpr())) return m_error;}
 | select_expr '\\' '[' '?' expr ']'            {if ((m_error=OnElementWhereExpr())) return m_error;}
 | select_expr '\\' '[' '<' ELIPSIS ']'         {if ((m_error=OnFirstElementExpr())) return m_error;}
 | select_expr '\\' '[' ELIPSIS '>' ']'         {if ((m_error=OnLastElementExpr())) return m_error;}
 | select_expr '\\' '[' ELIPSIS ']'             {if ((m_error=OnAllElementsExpr())) return m_error;}
 | select_expr '\\' primary_expr           {if ((m_error=OnElementExpr())) return m_error;}
 | select_expr '\\' DOTDOT                 {if ((m_error=OnParentElementExpr())) return m_error;}

 | select_expr '[' expr ']'                {if ((m_error=OnElementAtSetExpr())) return m_error;}
 | select_expr '[' expr  ELIPSIS expr']'   {if ((m_error=OnElementRangeSetExpr())) return m_error;}
 | select_expr '[' '?' expr ']'            {if ((m_error=OnElementWhereSetExpr())) return m_error;}
 | select_expr '[' '<' ELIPSIS ']'         {if ((m_error=OnFirstElementSetExpr())) return m_error;}
 | select_expr '[' ELIPSIS '>' ']'         {if ((m_error=OnLastElementSetExpr())) return m_error;}
 | select_expr '[' ELIPSIS ']'             {if ((m_error=OnAllElementsSetExpr())) return m_error;}

 | '\\' '[' expr ']'                     {if ((m_error=OnRootElementAt())) return m_error;}
 | '\\' '[' expr ELIPSIS expr ']'        {if ((m_error=OnRootElementRange())) return m_error;}
 | '\\' '[' '?' expr ']'                 {if ((m_error=OnRootElementWhere())) return m_error;}
 | '\\' '[' '<' ELIPSIS ']'              {if ((m_error=OnFirstRootElement())) return m_error;}
 | '\\' '[' ELIPSIS '>' ']'              {if ((m_error=OnLastRootElement())) return m_error;}
 | '\\' '[' ELIPSIS ']'                  {if ((m_error=OnAllRootElements())) return m_error;}
 | '\\' primary_expr                     {if ((m_error=OnRootElementExpr())) return m_error;}

 | '@' '[' expr ']'                      {if ((m_error=OnAttributeAt())) return m_error;}
 | '@' '[' expr ELIPSIS expr ']'         {if ((m_error=OnAttributeRange())) return m_error;}
 | '@' '[' '?' expr ']'                  {if ((m_error=OnAttributeWhere())) return m_error;}
 | '@' '[' '<' ELIPSIS ']'               {if ((m_error=OnFirstAttribute())) return m_error;}
 | '@' '[' ELIPSIS '>' ']'               {if ((m_error=OnLastAttribute())) return m_error;}
 | '@' '[' ELIPSIS ']'                   {if ((m_error=OnAllAttributes())) return m_error;}
 | '@' primary_expr                      {if ((m_error=OnAttribute())) return m_error;}

 | '[' expr ']'                          {if ((m_error=OnElementAt())) return m_error;}
 | '[' expr ELIPSIS expr ']'             {if ((m_error=OnElementRange())) return m_error;}
 | '[' '?' expr ']'                      {if ((m_error=OnElementWhere())) return m_error;}
 | '[' '<' ELIPSIS ']'                   {if ((m_error=OnFirstElement())) return m_error;}
 | '[' ELIPSIS '>' ']'                   {if ((m_error=OnLastElement())) return m_error;}
 | '[' ELIPSIS ']'                       {if ((m_error=OnAllElements())) return m_error;}

 | DOTDOT                                {if ((m_error=OnParentElement())) return m_error;}
 | '.'                                   {if ((m_error=OnElementIs())) return m_error;}
 | '@' '.'                               {if ((m_error=OnAttributeIs())) return m_error;}
 | primary_expr
 ;

primary_expr
 : uri_expr_request_method_identifier_list
   arguments                  {if ((m_error=OnURIMethodIdentifierCall())) return m_error;}
 | uri_literal_request_method_identifier_list
   arguments                  {if ((m_error=OnURIMethodIdentifierCall())) return m_error;}
 | uri_request_method_identifier_list
   arguments                  {if ((m_error=OnURIMethodIdentifierCall())) return m_error;}

 | uri_expr COLONCOLON_STAR value_expr
   {if ((m_error=OnURIRequestMethodCall())) return m_error;}
 | uri_literal COLONCOLON_STAR value_expr
   {if ((m_error=OnURIRequestMethodCall())) return m_error;}

 | uri_expr_method_identifier_list
   arguments                  {if ((m_error=OnURIMethodCall())) return m_error;}
 | uri_expr BSLASHBSLASH_SHR uri_literal
   arguments                  {if ((m_error=OnURIURITransform())) return m_error;}
 | uri_expr BSLASHBSLASH_SHR uri_expr
   arguments                  {if ((m_error=OnURIURITransform())) return m_error;}
 | uri_expr arguments
   call_identifier BSLASHBSLASH
   parenthetic_expr           {if ((m_error=OnIdentifierURIContent())) return m_error;}
 | uri_expr arguments BSLASHBSLASH
   parenthetic_expr           {if ((m_error=OnURIContent())) return m_error;}
 | uri_expr arguments         {if ((m_error=OnURIArguments())) return m_error;}
 | uri_expr

 | uri_literal_method_identifier_list
   arguments                  {if ((m_error=OnURIMethodCall())) return m_error;}
 | uri_literal BSLASHBSLASH_SHR uri_literal
   arguments                  {if ((m_error=OnURIURITransform())) return m_error;}
 | uri_literal BSLASHBSLASH_SHR uri_expr
   arguments                  {if ((m_error=OnURIURITransform())) return m_error;}
 | uri_literal arguments
   call_identifier BSLASHBSLASH 
   parenthetic_expr           {if ((m_error=OnIdentifierURIContent())) return m_error;}
 | uri_literal arguments BSLASHBSLASH 
   parenthetic_expr           {if ((m_error=OnURIContent())) return m_error;}
 | uri_literal arguments      {if ((m_error=OnURIArguments())) return m_error;}

 | FOREIGN uri_expr_method_identifier_list
   arguments                  {if ((m_error=OnURIForeignCall())) return m_error;}
 | FOREIGN uri_literal_method_identifier_list
   arguments                  {if ((m_error=OnURIForeignCall())) return m_error;}

 | NATIVE uri_expr_method_identifier_list
   arguments                  {if ((m_error=OnURINativeCall())) return m_error;}
 | NATIVE uri_literal_method_identifier_list
   arguments                  {if ((m_error=OnURINativeCall())) return m_error;}

 | NATIVE call_identifier arguments  {if ((m_error=OnNativeCall())) return m_error;}
 | call_identifier arguments  {if ((m_error=OnCall())) return m_error;}
 | COLONCOLON method_identifier_list
   arguments                  {if ((m_error=OnDocumentMethodIdentifierCall())) return m_error;}
 | method_identifier_list
   arguments                  {if ((m_error=OnMethodIdentifierCall())) return m_error;}
 | root_expr
 ;

value_expr
 : variable_expr {if ((m_error=OnVariable())) return m_error;}
 | parenthetic_expr
 ;

root_expr
 : prefix_op variable_expr  {if ((m_error=OnUnaryExpr())) return m_error;}
 | variable_expr postfix_op {if ((m_error=OnPostfixExpr())) return m_error;}
 | variable_expr            {if ((m_error=OnVariable())) return m_error;}
 | POSITIONIS               {if ((m_error=OnElementPosition())) return m_error;}
 | TYPEIS                   {if ((m_error=OnElementType())) return m_error;}
 | TEXTIS                   {if ((m_error=OnElementText())) return m_error;}
 | reference_expr
 | parenthetic_expr
 | literal
 ;

uri_request_method_identifier_list
 : BSLASHBSLASH COLONCOLON_AND method_identifier_list
   {if ((m_error=OnRequestMethodIdentifierList())) return m_error;}
 | BSLASHBSLASH COLONCOLON_AND call_identifier
   {if ((m_error=OnRequestURIObjectIdentifier())) return m_error;}
 ;

uri_expr_request_method_identifier_list
 : uri_request_method_expr COLONCOLON_AND method_identifier_list
 | uri_request_method_expr COLONCOLON_AND call_identifier
   {if ((m_error=OnURIObjectIdentifier())) return m_error;}
 ;

uri_request_method_expr
 : uri_expr {if ((m_error=OnRequestMethodURI())) return m_error;}
 ;

uri_expr_method_identifier_list
 : uri_expr COLONCOLON method_identifier_list
 | uri_expr_object_identifier
 ;

uri_expr_object_identifier
 : uri_expr COLONCOLON call_identifier
   {if ((m_error=OnURIObjectIdentifier())) return m_error;}
 ;

uri_expr
 : call_identifier BSLASHBSLASH root_expr {if ((m_error=OnIdentifierURIExpr())) return m_error;}
 | BSLASHBSLASH root_expr {if ((m_error=OnURIExpr())) return m_error;}
 ;

uri_literal_request_method_identifier_list
 : uri_literal_request_method_uri COLONCOLON_AND method_identifier_list
 | uri_literal_request_method_uri COLONCOLON_AND call_identifier
   {if ((m_error=OnURIObjectIdentifier())) return m_error;}
 ;

uri_literal_request_method_uri
 : uri_literal {if ((m_error=OnRequestMethodURI())) return m_error;}
 ;

uri_literal_method_identifier_list
 : uri_literal COLONCOLON method_identifier_list
 | uri_literal_object_identifier
 ;

uri_literal_object_identifier
 : uri_literal COLONCOLON call_identifier
   {if ((m_error=OnURIObjectIdentifier())) return m_error;}
 ;

method_identifier_list
 : method_identifier_list COLONCOLON call_identifier
   {if ((m_error=OnMethodIdentifierList())) return m_error;}

 | call_identifier COLONCOLON call_identifier
   {if ((m_error=OnObjectMethodIdentifierPair())) return m_error;}
 ;

call_identifier
 : parenthetic_expr
 | literal_identifier
 | identifier
 ;

parenthetic_expr
 : '(' expr_list ')'
 ;

expr_list
 : expr ',' expr_list {if ((m_error=OnBinaryOperator(','))) return m_error;}
 | expr
 ;

variable_expr
 : indirection_expr
 | identifier
 ;

indirection_expr
 : variable_indirection_expr {if ((m_error=OnVariable())) return m_error;}
 | parenthetic_indirection_expr
 | literal_indirection_expr
 ;

parenthetic_indirection_expr
 : POW_OP parenthetic_expr {if ((m_error=OnVariable())) return m_error;}
 | '*' parenthetic_expr
 ;

literal_indirection_expr
 : POW_OP literal_identifier {if ((m_error=OnVariable())) return m_error;}
 | literal_indirection_identifier
 ;

literal_indirection_identifier
 : '*' literal_identifier
 ;

literal_identifier
 : TEXT_LITERAL {if ((m_error=OnIdentifierExpr())) return m_error;}
 ;

variable_indirection_expr
 : variable_double_indirection_expr {if ((m_error=OnVariable())) return m_error;}
 | '*' variable_expr
 ;

variable_double_indirection_expr
 : POW_OP variable_expr
 ;

reference_expr
 : '&' identifier
 ;

arguments
 : '(' argument_expr_list ')'
 | '(' ')'  {if ((m_error=OnEmptyArguments())) return m_error;}
 ;

argument_expr_list
 : argument_expr_list ',' 
   argument_expr {if ((m_error=OnNextArgument())) return m_error;}
 | argument_expr {if ((m_error=OnFirstArgument())) return m_error;}
 ;

argument_expr
 : type_specification 
   call_identifier '=' expr {if ((m_error=OnTypedArgument())) return m_error;}
 | type_specification 
   '=' expr            {if ((m_error=OnTypeArgument())) return m_error;}
 | call_identifier '=' expr {if ((m_error=OnArgument())) return m_error;}
 ;

identifier
 : IDENTIFIER {if ((m_error=OnIdentifierExpr())) return m_error;}
 ;

/*
 **********************************************************************
 * operators
 **********************************************************************
 */

logical_or_op
 : LOR_OP {if ((m_error=OnOperator(LOR_OP))) return m_error;}
 ;

logical_and_op
 : LAND_OP {if ((m_error=OnOperator(LAND_OP))) return m_error;}
 ;

or_op
 : '|' {if ((m_error=OnOperator('|'))) return m_error;}
 ;

xor_op
 : '~' {if ((m_error=OnOperator('~'))) return m_error;}
 ;

and_op
 : '&' {if ((m_error=OnOperator('&'))) return m_error;}
 ;

unary_op
 : SIZEOF {if ((m_error=OnOperator(SIZEOF))) return m_error;}
 | TYPEOF {if ((m_error=OnOperator(TYPEOF))) return m_error;}
 | TEXTOF {if ((m_error=OnOperator(TEXTOF))) return m_error;}
 | '~'    {if ((m_error=OnOperator('~'))) return m_error;}
 ;

assignment_op
 : '=' {if ((m_error=OnOperator('='))) return m_error;}
 | ASSIGN {if ((m_error=OnOperator(ASSIGN))) return m_error;}
 | LAND_ASSIGN {if ((m_error=OnOperator(LAND_ASSIGN))) return m_error;}
 | LOR_ASSIGN {if ((m_error=OnOperator(LOR_ASSIGN))) return m_error;}
 | AND_ASSIGN  {if ((m_error=OnOperator(AND_ASSIGN))) return m_error;}
 | OR_ASSIGN {if ((m_error=OnOperator(OR_ASSIGN))) return m_error;}
 | XOR_ASSIGN {if ((m_error=OnOperator(XOR_ASSIGN))) return m_error;}
 | ADD_ASSIGN {if ((m_error=OnOperator(ADD_ASSIGN))) return m_error;}
 | SHR_ASSIGN {if ((m_error=OnOperator(SHR_ASSIGN))) return m_error;}
 | SHL_ASSIGN {if ((m_error=OnOperator(SHL_ASSIGN))) return m_error;}
 | SUB_ASSIGN {if ((m_error=OnOperator(SUB_ASSIGN))) return m_error;}
 | MUL_ASSIGN {if ((m_error=OnOperator(MUL_ASSIGN))) return m_error;}
 | DIV_ASSIGN {if ((m_error=OnOperator(DIV_ASSIGN))) return m_error;}
 | MOD_ASSIGN {if ((m_error=OnOperator(MOD_ASSIGN))) return m_error;}
 | POW_ASSIGN {if ((m_error=OnOperator(POW_ASSIGN))) return m_error;}
 | ROO_ASSIGN {if ((m_error=OnOperator(ROO_ASSIGN))) return m_error;}
 | LOG_ASSIGN {if ((m_error=OnOperator(LOG_ASSIGN))) return m_error;}
 ;

logical_not_op
 : LNOT_OP {if ((m_error=OnOperator(LNOT_OP))) return m_error;}
 | '!' {if ((m_error=OnOperator('!'))) return m_error;}
 ;

equality_op
 : NE_OP {if ((m_error=OnOperator(NE_OP))) return m_error;}
 | EQ_OP {if ((m_error=OnOperator(EQ_OP))) return m_error;}
 ;

relational_op
 : LE_OP {if ((m_error=OnOperator(LE_OP))) return m_error;}
 | GE_OP {if ((m_error=OnOperator(GE_OP))) return m_error;}
 | '<' {if ((m_error=OnOperator('<'))) return m_error;}
 | '>' {if ((m_error=OnOperator('>'))) return m_error;}
 ;

shift_op
 : SHR_OP {if ((m_error=OnOperator(SHR_OP))) return m_error;}
 | SHL_OP {if ((m_error=OnOperator(SHL_OP))) return m_error;}
 ;

add_op
 : '+' {if ((m_error=OnOperator('+'))) return m_error;}
 | '-' {if ((m_error=OnOperator('-'))) return m_error;}
 ;

mul_op
 : '*' {if ((m_error=OnOperator('*'))) return m_error;}
 | '/' {if ((m_error=OnOperator('/'))) return m_error;}
 | '$' {if ((m_error=OnOperator('$'))) return m_error;}
 | '%' {if ((m_error=OnOperator('%'))) return m_error;}
 ;

pow_op
 : POW_OP {if ((m_error=OnOperator(POW_OP))) return m_error;}
 | ROO_OP {if ((m_error=OnOperator(ROO_OP))) return m_error;}
 | LOG_OP {if ((m_error=OnOperator(LOG_OP))) return m_error;}
 ;

prefix_op
 : prefix_postfix_op
 ;

postfix_op
 : prefix_postfix_op  {if ((m_error=OnPostfixOperator())) return m_error;}
 ;

prefix_postfix_op
 : INC_OP   {if ((m_error=OnOperator(INC_OP))) return m_error;}
 | DEC_OP   {if ((m_error=OnOperator(DEC_OP))) return m_error;}
 | COM_OP   {if ((m_error=OnOperator(COM_OP))) return m_error;}
 | LCOM_OP  {if ((m_error=OnOperator(LCOM_OP))) return m_error;}
 | RIGHT_OP {if ((m_error=OnOperator(RIGHT_OP))) return m_error;}
 | LEFT_OP  {if ((m_error=OnOperator(LEFT_OP))) return m_error;}
 ;

/*
 **********************************************************************
 * literals
 **********************************************************************
 */

literal
 : extern_literal
 | uri_literal
 | template_literal
 | element_literal
 | text_literal
 | dec_literal
 | bin_literal
 | oct_literal
 | hex_literal
 | float_literal
 ;

extern_literal
 : EXTERN IDENTIFIER URI_LITERAL {if ((m_error=OnExternIdentifierLiteral())) return m_error;}
 | EXTERN TEXT_LITERAL URI_LITERAL {if ((m_error=OnExternLiteral())) return m_error;}
 | EXTERN URI_LITERAL {if ((m_error=OnExternLiteral())) return m_error;}
 ;

uri_literal
 : IDENTIFIER URI_LITERAL {if ((m_error=OnIdentifierURILiteralExpr())) return m_error;}
 | TEXT_LITERAL URI_LITERAL {if ((m_error=OnIdentifierURILiteralExpr())) return m_error;}
 | URI_LITERAL {if ((m_error=OnURILiteralExpr())) return m_error;}
 ;

template_literal
 : IDENTIFIER TEMPLATE_LITERAL {if ((m_error=OnIdentifierTemplateLiteral())) return m_error;}
 | TEXT_LITERAL TEMPLATE_LITERAL {if ((m_error=OnIdentifierTemplateLiteral())) return m_error;}
 | TEMPLATE_LITERAL {if ((m_error=OnTemplateLiteral())) return m_error;}
 ;

element_literal
 : IDENTIFIER 
   element_literal_list {if ((m_error=OnIdentifierElementLiteral())) return m_error;}
 | TEXT_LITERAL
   element_literal_list {if ((m_error=OnIdentifierElementLiteral())) return m_error;}
 | element_literal_list {if ((m_error=OnElementLiteral())) return m_error;}
 ;

element_literal_list
 : element_literal_item 
   element_literal_list {if ((m_error=OnConcatTextLiteral())) return m_error;}
 | element_literal_item
 ;

element_literal_item
 : ELEMENT_LITERAL
 ;

text_literal
 : text_literal_list {if ((m_error=OnTextLiteral())) return m_error;}
 ;

text_literal_list
 : text_literal_item 
   text_literal_list {if ((m_error=OnConcatTextLiteral())) return m_error;}
 | text_literal_item
 ;

text_literal_item
 : TEXT_LITERAL
 ;

dec_literal
 : DEC_LITERAL {if ((m_error=OnDecimalLiteral())) return m_error;}
 ;

bin_literal
 : BIN_LITERAL {if ((m_error=OnBinaryLiteral())) return m_error;}
 ;

oct_literal
 : OCT_LITERAL {if ((m_error=OnOctalLiteral())) return m_error;}
 ;

hex_literal
 : HEX_LITERAL {if ((m_error=OnHexLiteral())) return m_error;}
 ;

float_literal
 : FLOAT_LITERAL {if ((m_error=OnFloatLiteral())) return m_error;}
 ;


%%
