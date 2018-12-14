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

%token XX_INCLUDE XX_USING XX_EXTERN XX_FOREIGN XX_NATIVE
%token XX_FRIEND XX_PUBLIC XX_PRIVATE XX_PROTECTED
%token XX_CONST XX_STATIC XX_AUTO XX_REGISTER XX_VOLITILE XX_INTERRUPT
%token XX_CDECL XX_PASCAL XX_PACKED XX_PARALLEL XX_REMOTE XX_SHARED
%token XX_PURE XX_VIRTUAL XX_OPERATOR XX_ABSOLUTE XX_IO
%token XX_PROCESS XX_MODULE XX_MAIN XX_THREAD XX_SIGNAL XX_CLASS XX_NAMESPACE
%token XX_STRUCT XX_UNION XX_ARRAY XX_SET XX_STRING
%token XX_SIGNED XX_UNSIGNED XX_FLOAT XX_VOID XX_ENUM
%token XX_DOUBLE XX_SHORT XX_LONG XX_INT XX_CHAR XX_BOOL XX_TRUE XX_FALSE
%token XX_WHAT XX_AT XX_IS XX_SUPER XX_THIS XX_NEW XX_DELETE
%token XX_POSITIONOF XX_SIZEOF XX_TYPEOF XX_TEXTOF XX_NAMESPACEOF XX_NAMEOF XX_PREFIXOF
%token XX_POSITIONIS XX_SIZEIS XX_TYPEIS XX_TEXTIS XX_NAMESPACEIS XX_NAMEIS XX_PREFIXIS
%token XX_TEMPLATE XX_VARIABLE

%token XX_DO XX_WHILE XX_UNTIL XX_REPEAT XX_FOR XX_EACH XX_OF
%token XX_SWITCH XX_CASE XX_DEFAULT XX_IF XX_ELSE
%token XX_BEFORE XX_AFTER XX_WHEN
%token XX_GOTO XX_BREAK XX_CONTINUE XX_RETURN
%token XX_TRY XX_CATCH XX_THROW XX_WITH

%token XX_COLONCOLON_AND XX_COLONCOLON_STAR XX_COLONCOLON XX_DOTDOT XX_ELIPSIS
%token XX_BSLASHBSLASH_SHR XX_BSLASHBSLASH_SHL
%token XX_BSLASHBSLASH XX_BSLASHQUESTION
%token XX_DOTBSLASHQUESTION XX_DOTQUESTION XX_ATQUESTION
%token XX_PERCENT_LESS XX_GREATER_PERCENT
%token XX_LESS_PERCENT XX_PERCENT_GREATER

%token XX_ASSIGN XX_LAND_ASSIGN XX_LOR_ASSIGN XX_LXOR_ASSIGN
%token XX_POW_ASSIGN XX_ROO_ASSIGN XX_LOG_ASSIGN XX_SHR_ASSIGN XX_SHL_ASSIGN
%token XX_ADD_ASSIGN XX_SUB_ASSIGN XX_MUL_ASSIGN XX_DIV_ASSIGN XX_MOD_ASSIGN
%token XX_QUO_ASSIGN XX_AND_ASSIGN XX_OR_ASSIGN XX_XOR_ASSIGN
%token XX_RIGHT_OP XX_LEFT_OP XX_INC_OP XX_DEC_OP XX_COM_OP XX_LCOM_OP
%token XX_LE_OP XX_GE_OP XX_NE_OP XX_EQ_OP
%token XX_SHR_OP XX_SHL_OP XX_POW_OP XX_ROO_OP XX_LOG_OP
%token XX_LNOT_OP XX_LAND_OP XX_LOR_OP

%token XX_DEC_LITERAL XX_BIN_LITERAL XX_HEX_LITERAL XX_OCT_LITERAL
%token XX_FLOAT_LITERAL XX_CHAR_LITERAL XX_TEXT_LITERAL XX_URI_LITERAL
%token XX_TEMPLATE_LITERAL XX_ELEMENT_LITERAL
%token XX_IDENTIFIER
