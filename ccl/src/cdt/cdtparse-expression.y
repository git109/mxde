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
 : variable_definition ';'
 ;

variable_definition
 : variable_designator 
   '=' variable_initializer {YY(OnVariableInitializer);}
 | variable_designator
 ;

variable_initializer
 : conditional_expr
 ;

variable_designator
 : typed_designator   {YY(OnTypedVariableName);}
 | untyped_variable_designator {YY(OnVariableName);}
 ; 

untyped_variable_designator
 : XX_VARIABLE variable_name
 | XX_VOID variable_name
 ;

variable_name
 : variable_name_identifier {YY(OnVariableIdentifier);}
 ;

variable_name_identifier
 : XX_IDENTIFIER
 | XX_TEXT_LITERAL
 ;

/*
 **********************************************************************
 * types
 **********************************************************************
 */

type_specification
 : type_definition {YY(OnTypeDefinition);}
 | type_reference
 ;

type_definition
 : void_type
   of_dimentions       {YY(OnDimentionedTypeReference);}
 | type_reference 
   of_dimentions       {YY(OnDimentionedTypeReference);}
 | new_type_definition 
   of_dimentions       {YY(OnDimentionedTypeDefinition);}
 | new_type_definition
 ;

new_type_definition
 : struct_definition
 ;

struct_definition
 : struct_designator '{' struct_member_definitions '}'
 ;

struct_designator
 : XX_STRUCT {YY(OnStruct);}
 | XX_UNION {YY(OnUnion);}
 ;

struct_member_definitions
 : struct_member_definitions struct_member_definition
 | struct_member_definition
 ;

struct_member_definition
 : variable_declaration {YY(OnMember);}
 ;

of_dimentions
 : of_dimentions 
   dimentions {YY(OnOfDimentions);}
 | dimentions {YY(OnDimentions);}
 ;

dimentions
 : '[' dimention_list ']'
 | '['']' {YY(OnUnboundDimentions);}
 ;

dimention_list
 : dimention_list 
   ',' dimention_expr {YY(OnDimentionList);}
 | ',' dimention_expr {YY(OnUnboundDimention);}
 | dimention_expr     {YY(OnDimention);}
 ;

dimention_expr
 : conditional_expr {YY(OnDimentionExpr);}
 ;

type_reference
 : XX_CLASS uri_qualified_class_name
   {YY(OnTypeReference);}
 | intrinsic_type
 ;

void_type
 : XX_VOID {YY2(OnFunction,"void");}
 ;

intrinsic_type
 : XX_UNSIGNED {YY2(OnIntrinsicType,"unsigned");}
 | XX_SIGNED {YY2(OnIntrinsicType,"signed");}
 | XX_SHORT {YY2(OnIntrinsicType,"short");}
 | XX_LONG {YY2(OnIntrinsicType,"long");}
 | XX_INT {YY2(OnIntrinsicType,"int");}
 | XX_FLOAT {YY2(OnIntrinsicType,"float");}
 | XX_DOUBLE {YY2(OnIntrinsicType,"double");}
 | XX_STRING {YY2(OnIntrinsicType,"string");}
 | XX_CHAR {YY2(OnIntrinsicType,"char");}
 | XX_BOOL {YY2(OnIntrinsicType,"bool");}
 ;

/*
 **********************************************************************
 * names
 **********************************************************************
 */

uri_qualified_class_name
 : uri_identifier 
   document_qualified_class_name {YY(OnURIQualifiedName);}
 | document_qualified_class_name
 ;

document_qualified_class_name
 : XX_COLONCOLON class_name 
   XX_COLONCOLON qualified_class_name {YY(OnDocumentQualifiedName);}
 | XX_COLONCOLON class_name           {YY(OnDocumentLevelName);}
 | qualified_class_name
 ;

uri_identifier
 : XX_URI_LITERAL {YY(OnURIdentifier);}
 ;

qualified_class_name
 : qualified_class_name XX_COLONCOLON
   class_name {YY(OnElementQualifiedName);}
 | class_name {YY(OnElementLevelName);}
 ;

class_name
 : class_identifier {YY(OnIdentifier);}
 ;

class_identifier
 : XX_IDENTIFIER
 | XX_TEXT_LITERAL
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
 : XX_CLASS variable_expr assignment_op assignment_expr {YY(OnBinaryExpr);}
 | assignment_expr
 ;

assignment_expr
 : variable_expr assignment_op assignment_expr {YY(OnBinaryExpr);}
 | conditional_expr
 ;

conditional_expr
 : logical_or_expr '?' conditional_expr ':' conditional_expr {YY(OnConditionalExpr);}
 | logical_or_expr '!' conditional_expr                      {YY(OnElseConditionalExpr);}
 | logical_or_expr
 ;

logical_or_expr
 : logical_or_expr logical_or_op logical_and_expr {YY(OnBinaryExpr);}
 | logical_and_expr
 ;

logical_and_expr
 : logical_and_expr logical_and_op logical_not_expr {YY(OnBinaryExpr);}
 | logical_not_expr
 ;

logical_not_expr
 : logical_not_op equality_expr {YY(OnUnaryExpr);}
 | equality_expr
 ;

equality_expr
 : equality_expr equality_op relational_expr {YY(OnBinaryExpr);}
 | relational_expr
 ;

relational_expr
 : relational_expr relational_op or_expr {YY(OnBinaryExpr);}
 | or_expr
 ;

or_expr
 : or_expr or_op xor_expr {YY(OnBinaryExpr);}
 | xor_expr
 ;

xor_expr
 : xor_expr xor_op and_expr {YY(OnBinaryExpr);}
 | and_expr
 ;

and_expr
 : and_expr and_op shift_expr {YY(OnBinaryExpr);}
 | shift_expr
 ;

shift_expr
 : shift_expr shift_op add_expr {YY(OnBinaryExpr);}
 | add_expr
 ;

add_expr
 : add_expr add_op mul_expr {YY(OnBinaryExpr);}
 | mul_expr
 ;

mul_expr
 : mul_expr mul_op pow_expr {YY(OnBinaryExpr);}
 | pow_expr
 ;

pow_expr
 : pow_expr pow_op cast_expr {YY(OnBinaryExpr);}
 | cast_expr
 ;

cast_expr
 : '(' type_specification ')' cast_expr {YY(OnCastExpr);}
 | unary_expr
 ;

unary_expr
 : unary_op select_expr {YY(OnUnaryExpr);}
 | select_expr
 ;

select_expr
 : select_expr '.' 
   call_identifier arguments             {YY(OnMethodOfCall);}
 | select_expr '.' call_identifier       {YY(OnGetMemberOf);}
 | select_expr XX_DOTQUESTION '[' expr ']'  {YY(OnGetMembersOfWhere);}
 | '.' call_identifier arguments         {YY(OnMethodCall);}
 | '.' call_identifier                   {YY(OnGetMember);}
 | XX_DOTQUESTION '[' expr ']'              {YY(OnGetMembersWhere);}

 | select_expr '@''[' expr ']'             {YY(OnAttributeOfSetAt);}
 | select_expr '@''[' expr XX_ELIPSIS expr']' {YY(OnAttributesOfSetRange);}
 | select_expr '@''[' '?' expr ']'         {YY(OnAttributesOfSetWhere);}
 | select_expr '@''[' '<' XX_ELIPSIS ']'      {YY(OnFirstAttributeOfSet);}
 | select_expr '@''[' XX_ELIPSIS '>' ']'      {YY(OnLastAttributeOfSet);}
 | select_expr '@''[' XX_ELIPSIS ']'          {YY(OnAllAttributesOfSet);}
 | select_expr '@' primary_expr            {YY(OnAttributeOfSet);}

 | select_expr '\\' '@''[' expr ']'             {YY(OnAttributeOfAt);}
 | select_expr '\\' '@''[' expr XX_ELIPSIS expr']' {YY(OnAttributesOfRange);}
 | select_expr '\\' '@''[' '?' expr ']'         {YY(OnAttributesOfWhere);}
 | select_expr '\\' '@''[' '<' XX_ELIPSIS ']'      {YY(OnFirstAttributeOf);}
 | select_expr '\\' '@''[' XX_ELIPSIS '>' ']'      {YY(OnLastAttributeOf);}
 | select_expr '\\' '@''[' XX_ELIPSIS ']'          {YY(OnAllAttributesOf);}
 | select_expr '\\' '@' primary_expr            {YY(OnAttributeOf);}
 
 | select_expr '\\' '[' expr ']'                {YY(OnElementAtExpr);}
 | select_expr '\\' '[' expr  XX_ELIPSIS expr']'   {YY(OnElementRangeExpr);}
 | select_expr '\\' '[' '?' expr ']'            {YY(OnElementWhereExpr);}
 | select_expr '\\' '[' '<' XX_ELIPSIS ']'         {YY(OnFirstElementExpr);}
 | select_expr '\\' '[' XX_ELIPSIS '>' ']'         {YY(OnLastElementExpr);}
 | select_expr '\\' '[' XX_ELIPSIS ']'             {YY(OnAllElementsExpr);}
 | select_expr '\\' primary_expr           {YY(OnElementExpr);}
 | select_expr '\\' XX_DOTDOT                 {YY(OnParentElementExpr);}

 | select_expr '[' expr ']'                {YY(OnElementAtSetExpr);}
 | select_expr '[' expr  XX_ELIPSIS expr']'   {YY(OnElementRangeSetExpr);}
 | select_expr '[' '?' expr ']'            {YY(OnElementWhereSetExpr);}
 | select_expr '[' '<' XX_ELIPSIS ']'         {YY(OnFirstElementSetExpr);}
 | select_expr '[' XX_ELIPSIS '>' ']'         {YY(OnLastElementSetExpr);}
 | select_expr '[' XX_ELIPSIS ']'             {YY(OnAllElementsSetExpr);}

 | '\\' '[' expr ']'                     {YY(OnRootElementAt);}
 | '\\' '[' expr XX_ELIPSIS expr ']'        {YY(OnRootElementRange);}
 | '\\' '[' '?' expr ']'                 {YY(OnRootElementWhere);}
 | '\\' '[' '<' XX_ELIPSIS ']'              {YY(OnFirstRootElement);}
 | '\\' '[' XX_ELIPSIS '>' ']'              {YY(OnLastRootElement);}
 | '\\' '[' XX_ELIPSIS ']'                  {YY(OnAllRootElements);}
 | '\\' primary_expr                     {YY(OnRootElementExpr);}

 | '@' '[' expr ']'                      {YY(OnAttributeAt);}
 | '@' '[' expr XX_ELIPSIS expr ']'         {YY(OnAttributeRange);}
 | '@' '[' '?' expr ']'                  {YY(OnAttributeWhere);}
 | '@' '[' '<' XX_ELIPSIS ']'               {YY(OnFirstAttribute);}
 | '@' '[' XX_ELIPSIS '>' ']'               {YY(OnLastAttribute);}
 | '@' '[' XX_ELIPSIS ']'                   {YY(OnAllAttributes);}
 | '@' primary_expr                      {YY(OnAttribute);}

 | '[' expr ']'                          {YY(OnElementAt);}
 | '[' expr XX_ELIPSIS expr ']'             {YY(OnElementRange);}
 | '[' '?' expr ']'                      {YY(OnElementWhere);}
 | '[' '<' XX_ELIPSIS ']'                   {YY(OnFirstElement);}
 | '[' XX_ELIPSIS '>' ']'                   {YY(OnLastElement);}
 | '[' XX_ELIPSIS ']'                       {YY(OnAllElements);}

 | XX_DOTDOT                                {YY(OnParentElement);}
 | '.'                                   {YY(OnElementIs);}
 | '@' '.'                               {YY(OnAttributeIs);}
 | primary_expr
 ;

primary_expr
 : uri_expr_request_method_identifier_list
   arguments                  {YY(OnURIMethodIdentifierCall);}
 | uri_literal_request_method_identifier_list
   arguments                  {YY(OnURIMethodIdentifierCall);}
 | uri_request_method_identifier_list
   arguments                  {YY(OnURIMethodIdentifierCall);}

 | uri_expr XX_COLONCOLON_STAR value_expr
   {YY(OnURIRequestMethodCall);}
 | uri_literal XX_COLONCOLON_STAR value_expr
   {YY(OnURIRequestMethodCall);}

 | uri_expr_method_identifier_list
   arguments                  {YY(OnURIMethodCall);}
 | uri_expr XX_BSLASHBSLASH_SHR uri_literal
   arguments                  {YY(OnURIURITransform);}
 | uri_expr XX_BSLASHBSLASH_SHR uri_expr
   arguments                  {YY(OnURIURITransform);}
 | uri_expr arguments
   call_identifier XX_BSLASHBSLASH
   parenthetic_expr           {YY(OnIdentifierURIContent);}
 | uri_expr arguments XX_BSLASHBSLASH
   parenthetic_expr           {YY(OnURIContent);}
 | uri_expr arguments         {YY(OnURIArguments);}
 | uri_expr

 | uri_literal_method_identifier_list
   arguments                  {YY(OnURIMethodCall);}
 | uri_literal XX_BSLASHBSLASH_SHR uri_literal
   arguments                  {YY(OnURIURITransform);}
 | uri_literal XX_BSLASHBSLASH_SHR uri_expr
   arguments                  {YY(OnURIURITransform);}
 | uri_literal arguments
   call_identifier XX_BSLASHBSLASH 
   parenthetic_expr           {YY(OnIdentifierURIContent);}
 | uri_literal arguments XX_BSLASHBSLASH 
   parenthetic_expr           {YY(OnURIContent);}
 | uri_literal arguments      {YY(OnURIArguments);}

 | XX_FOREIGN uri_expr_method_identifier_list
   arguments                  {YY(OnURIForeignCall);}
 | XX_FOREIGN uri_literal_method_identifier_list
   arguments                  {YY(OnURIForeignCall);}

 | XX_NATIVE uri_expr_method_identifier_list
   arguments                  {YY(OnURINativeCall);}
 | XX_NATIVE uri_literal_method_identifier_list
   arguments                  {YY(OnURINativeCall);}

 | XX_NATIVE call_identifier arguments  {YY(OnNativeCall);}
 | call_identifier arguments  {YY(OnCall);}
 | XX_COLONCOLON method_identifier_list
   arguments                  {YY(OnDocumentMethodIdentifierCall);}
 | method_identifier_list
   arguments                  {YY(OnMethodIdentifierCall);}
 | root_expr
 ;

value_expr
 : variable_expr {YY(OnVariable);}
 | parenthetic_expr
 ;

root_expr
 : prefix_op variable_expr  {YY(OnUnaryExpr);}
 | variable_expr postfix_op {YY(OnPostfixExpr);}
 | variable_expr            {YY(OnVariable);}
 | XX_POSITIONIS               {YY(OnElementPosition);}
 | XX_TYPEIS                   {YY(OnElementType);}
 | XX_TEXTIS                   {YY(OnElementText);}
 | XX_NAMEIS                   {YY(OnElementName);}
 | XX_NAMESPACEIS              {YY(OnElementNamespace);}
 | XX_PREFIXIS                 {YY(OnElementPrefix);}
 | reference_expr
 | parenthetic_expr
 | element_expr
 | literal
 ;

element_expr
 : compound_element_expr
 | begin_element_expr    {YY(OnBeginElementExpr);}
 | end_element_expr      {YY(OnEndElementExpr);}
 | atomic_element_expr
 ;

atomic_element_expr
 : simple_element_expr {YY(OnSimpleElementExpr);}
 | comment_expr        {YY(OnCommentExpr);}
 | simple_comment_expr {YY(OnSimpleCommentExpr);}
 ;

compound_element_expr
 : begin_compound_element_expr compound_element_body end_compound_element_expr
 | begin_compound_element_expr end_compound_element_expr
 ;

compound_element_body
 : compound_element_body 
   compound_element_body_item
 | compound_element_body_item
 ;

compound_element_body_item
 : compound_element_body_expr {YY(OnCompoundElementExpr);}
 ;

compound_element_body_expr
 : compound_element_expr
 | atomic_element_expr
 | XX_PERCENT_GREATER 
   conditional_expr 
   XX_LESS_PERCENT
 ;

begin_compound_element_expr
 : begin_element_expr {YY(OnBeginCompoundElementExpr);}
 ;

end_compound_element_expr
 : XX_PERCENT_LESS '/' XX_GREATER_PERCENT
 ;

begin_element_expr
 : XX_PERCENT_LESS begin_element_body XX_GREATER_PERCENT
 ;

end_element_expr
 : XX_PERCENT_LESS '/' end_element_body XX_GREATER_PERCENT
 ;

simple_element_expr
 : XX_PERCENT_LESS begin_element_body '/' XX_GREATER_PERCENT
 ;

comment_expr
 : begin_comment comment_body end_comment
 ;

simple_comment_expr
 : begin_comment end_comment
 ;

begin_comment
 : XX_PERCENT_LESS '!' XX_DEC_OP
 ;

end_comment
 : XX_DEC_OP XX_GREATER_PERCENT
 ;

comment_body
 : parenthetic_expr
 | text_literal
 ;

begin_element_body
 : begin_element_name_expr attribute_expr_list
 | begin_element_name_expr
 ;

begin_element_name_expr
 : element_name_expr {YY(OnBeginElementNameExpr);}
 ;

end_element_body
 : element_name_expr
 ;

element_name_expr
 : element_name_identifier_expr 
   ':' element_name_identifier_expr {YY(OnElementPrefixExpr);}
 | element_name_identifier_expr     {YY(OnElementNameExpr);}
 ;

element_name_identifier_expr
 : parenthetic_expr
 | identifier
 ;

attribute_expr_list
 : attribute_expr_list attribute_expr
 | attribute_expr
 ;

attribute_expr
 : element_name_expr 
   '=' attribute_value_expr {YY(OnAttributeValueExpr);}
 | element_name_expr        {YY(OnAttributeNameExpr);}
 ;

attribute_value_expr
 : parenthetic_expr
 | text_literal
 ;

uri_request_method_identifier_list
 : XX_BSLASHBSLASH XX_COLONCOLON_AND method_identifier_list
   {YY(OnRequestMethodIdentifierList);}
 | XX_BSLASHBSLASH XX_COLONCOLON_AND call_identifier
   {YY(OnRequestURIObjectIdentifier);}
 ;

uri_expr_request_method_identifier_list
 : uri_request_method_expr XX_COLONCOLON_AND method_identifier_list
 | uri_request_method_expr XX_COLONCOLON_AND call_identifier
   {YY(OnURIObjectIdentifier);}
 ;

uri_request_method_expr
 : uri_expr {YY(OnRequestMethodURI);}
 ;

uri_expr_method_identifier_list
 : uri_expr XX_COLONCOLON method_identifier_list
 | uri_expr_object_identifier
 ;

uri_expr_object_identifier
 : uri_expr XX_COLONCOLON call_identifier
   {YY(OnURIObjectIdentifier);}
 ;

uri_expr
 : call_identifier XX_BSLASHBSLASH root_expr {YY(OnIdentifierURIExpr);}
 | XX_BSLASHBSLASH root_expr {YY(OnURIExpr);}
 ;

uri_literal_request_method_identifier_list
 : uri_literal_request_method_uri XX_COLONCOLON_AND method_identifier_list
 | uri_literal_request_method_uri XX_COLONCOLON_AND call_identifier
   {YY(OnURIObjectIdentifier);}
 ;

uri_literal_request_method_uri
 : uri_literal {YY(OnRequestMethodURI);}
 ;

uri_literal_method_identifier_list
 : uri_literal XX_COLONCOLON method_identifier_list
 | uri_literal_object_identifier
 ;

uri_literal_object_identifier
 : uri_literal XX_COLONCOLON call_identifier
   {YY(OnURIObjectIdentifier);}
 ;

method_identifier_list
 : method_identifier_list XX_COLONCOLON call_identifier
   {YY(OnMethodIdentifierList);}

 | call_identifier XX_COLONCOLON call_identifier
   {YY(OnObjectMethodIdentifierPair);}
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
 : expr ',' expr_list {YY2(OnBinaryOperator,',');}
 | expr
 ;

variable_expr
 : indirection_expr
 | identifier
 ;

indirection_expr
 : variable_indirection_expr {YY(OnVariable);}
 | parenthetic_indirection_expr
 | literal_indirection_expr
 ;

parenthetic_indirection_expr
 : XX_POW_OP parenthetic_expr {YY(OnVariable);}
 | '*' parenthetic_expr
 ;

literal_indirection_expr
 : XX_POW_OP literal_identifier {YY(OnVariable);}
 | literal_indirection_identifier
 ;

literal_indirection_identifier
 : '*' literal_identifier
 ;

literal_identifier
 : XX_TEXT_LITERAL {YY(OnIdentifierExpr);}
 ;

variable_indirection_expr
 : variable_double_indirection_expr {YY(OnVariable);}
 | '*' variable_expr
 ;

variable_double_indirection_expr
 : XX_POW_OP variable_expr
 ;

reference_expr
 : '&' identifier
 ;

arguments
 : '(' argument_expr_list ')'
 | '(' ')'  {YY(OnEmptyArguments);}
 ;

argument_expr_list
 : argument_expr_list ',' 
   argument_expr {YY(OnNextArgument);}
 | argument_expr {YY(OnFirstArgument);}
 ;

argument_expr
 : type_specification 
   call_identifier '=' expr {YY(OnTypedArgument);}
 | type_specification 
   '=' expr            {YY(OnTypeArgument);}
 | call_identifier '=' expr {YY(OnArgument);}
 ;

identifier
 : XX_IDENTIFIER {YY(OnIdentifierExpr);}
 ;

/*
 **********************************************************************
 * operators
 **********************************************************************
 */

logical_or_op
 : XX_LOR_OP {YY2(OnOperator,XX_LOR_OP);}
 ;

logical_and_op
 : XX_LAND_OP {YY2(OnOperator,XX_LAND_OP);}
 ;

or_op
 : '|' {YY2(OnOperator,'|');}
 ;

xor_op
 : '~' {YY2(OnOperator,'~');}
 ;

and_op
 : '&' {YY2(OnOperator,'&');}
 ;

unary_op
 : XX_SIZEOF {YY2(OnOperator,XX_SIZEOF);}
 | XX_TYPEOF {YY2(OnOperator,XX_TYPEOF);}
 | XX_TEXTOF {YY2(OnOperator,XX_TEXTOF);}
 | '~'    {YY2(OnOperator,'~');}
 ;

assignment_op
 : '=' {YY2(OnOperator,'=');}
 | XX_ASSIGN {YY2(OnOperator,XX_ASSIGN);}
 | XX_LAND_ASSIGN {YY2(OnOperator,XX_LAND_ASSIGN);}
 | XX_LOR_ASSIGN {YY2(OnOperator,XX_LOR_ASSIGN);}
 | XX_AND_ASSIGN  {YY2(OnOperator,XX_AND_ASSIGN);}
 | XX_OR_ASSIGN {YY2(OnOperator,XX_OR_ASSIGN);}
 | XX_XOR_ASSIGN {YY2(OnOperator,XX_XOR_ASSIGN);}
 | XX_ADD_ASSIGN {YY2(OnOperator,XX_ADD_ASSIGN);}
 | XX_SHR_ASSIGN {YY2(OnOperator,XX_SHR_ASSIGN);}
 | XX_SHL_ASSIGN {YY2(OnOperator,XX_SHL_ASSIGN);}
 | XX_SUB_ASSIGN {YY2(OnOperator,XX_SUB_ASSIGN);}
 | XX_MUL_ASSIGN {YY2(OnOperator,XX_MUL_ASSIGN);}
 | XX_DIV_ASSIGN {YY2(OnOperator,XX_DIV_ASSIGN);}
 | XX_MOD_ASSIGN {YY2(OnOperator,XX_MOD_ASSIGN);}
 | XX_POW_ASSIGN {YY2(OnOperator,XX_POW_ASSIGN);}
 | XX_ROO_ASSIGN {YY2(OnOperator,XX_ROO_ASSIGN);}
 | XX_LOG_ASSIGN {YY2(OnOperator,XX_LOG_ASSIGN);}
 ;

logical_not_op
 : XX_LNOT_OP {YY2(OnOperator,XX_LNOT_OP);}
 | '!' {YY2(OnOperator,'!');}
 ;

equality_op
 : XX_NE_OP {YY2(OnOperator,XX_NE_OP);}
 | XX_EQ_OP {YY2(OnOperator,XX_EQ_OP);}
 ;

relational_op
 : XX_LE_OP {YY2(OnOperator,XX_LE_OP);}
 | XX_GE_OP {YY2(OnOperator,XX_GE_OP);}
 | '<' {YY2(OnOperator,'<');}
 | '>' {YY2(OnOperator,'>');}
 ;

shift_op
 : XX_SHR_OP {YY2(OnOperator,XX_SHR_OP);}
 | XX_SHL_OP {YY2(OnOperator,XX_SHL_OP);}
 ;

add_op
 : '+' {YY2(OnOperator,'+');}
 | '-' {YY2(OnOperator,'-');}
 ;

mul_op
 : '*' {YY2(OnOperator,'*');}
 | '/' {YY2(OnOperator,'/');}
 | '$' {YY2(OnOperator,'$');}
 | '%' {YY2(OnOperator,'%');}
 ;

pow_op
 : XX_POW_OP {YY2(OnOperator,XX_POW_OP);}
 | XX_ROO_OP {YY2(OnOperator,XX_ROO_OP);}
 | XX_LOG_OP {YY2(OnOperator,XX_LOG_OP);}
 ;

prefix_op
 : prefix_postfix_op
 ;

postfix_op
 : prefix_postfix_op  {YY(OnPostfixOperator);}
 ;

prefix_postfix_op
 : XX_INC_OP   {YY2(OnOperator,XX_INC_OP);}
 | XX_DEC_OP   {YY2(OnOperator,XX_DEC_OP);}
 | XX_COM_OP   {YY2(OnOperator,XX_COM_OP);}
 | XX_LCOM_OP  {YY2(OnOperator,XX_LCOM_OP);}
 | XX_RIGHT_OP {YY2(OnOperator,XX_RIGHT_OP);}
 | XX_LEFT_OP  {YY2(OnOperator,XX_LEFT_OP);}
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
 : XX_EXTERN XX_TEXT_LITERAL XX_URI_LITERAL {YY(OnExternIdentifierLiteral);}
 | XX_EXTERN XX_IDENTIFIER XX_URI_LITERAL {YY(OnExternIdentifierLiteral);}
 | XX_EXTERN XX_URI_LITERAL {YY(OnExternLiteral);}
 ;

uri_literal
 : XX_TEXT_LITERAL XX_URI_LITERAL {YY(OnIdentifierURILiteralExpr);}
 | XX_IDENTIFIER XX_URI_LITERAL {YY(OnIdentifierURILiteralExpr);}
 | XX_URI_LITERAL {YY(OnURILiteralExpr);}
 ;

template_literal
 : XX_TEXT_LITERAL XX_TEMPLATE_LITERAL {YY(OnIdentifierTemplateLiteral);}
 | XX_IDENTIFIER XX_TEMPLATE_LITERAL {YY(OnIdentifierTemplateLiteral);}
 | XX_TEMPLATE_LITERAL {YY(OnTemplateLiteral);}
 ;

element_literal
 : XX_TEXT_LITERAL element_literal_list {YY(OnIdentifierElementLiteral);}
 | XX_IDENTIFIER  element_literal_list {YY(OnIdentifierElementLiteral);}
 | element_literal_list {YY(OnElementLiteral);}
 ;

element_literal_list
 : element_literal_item 
   element_literal_list {YY(OnConcatTextLiteral);}
 | element_literal_item
 ;

element_literal_item
 : XX_ELEMENT_LITERAL
 ;

text_literal
 : text_literal_list {YY(OnTextLiteral);}
 ;

text_literal_list
 : text_literal_item 
   text_literal_list {YY(OnConcatTextLiteral);}
 | text_literal_item
 ;

text_literal_item
 : XX_TEXT_LITERAL
 ;

/*
 **********************************************************************
 * numeric literals
 **********************************************************************
 */

dec_literal
 : XX_DEC_LITERAL {YY(OnDecimalLiteral);}
 ;

bin_literal
 : XX_BIN_LITERAL {YY(OnBinaryLiteral);}
 ;

oct_literal
 : XX_OCT_LITERAL {YY(OnOctalLiteral);}
 ;

hex_literal
 : XX_HEX_LITERAL {YY(OnHexLiteral);}
 ;

float_literal
 : XX_FLOAT_LITERAL {YY(OnFloatLiteral);}
 ;

