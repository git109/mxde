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
