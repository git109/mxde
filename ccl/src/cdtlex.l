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
 *   File: cdtlex.l
 *
 * Author: $author$
 *   Date: 8/25/2003
 *
 *    $Id$
 **********************************************************************
 */

B                     [0-1]
O                     [0-7]
D                     [0-9]
N                     [1-9]
H                     [0-9a-fA-F]
L                     [a-zA-Z_]
E                     [Ee][+-]?{D}+
F                     (f|F)
U                     (u|U)
S                     (l|L)

%{
#include "cdtparse.h"
#include "cdtlexer.hxx"
%}

%option yylineno
%x COMMENT COMMENT2 COMMENTEOL

%%

<INITIAL>{
"/*"                  { yy_push_state(COMMENT); }
"/%"                  { yy_push_state(COMMENT2); }
"///"                 { yy_push_state(COMMENTEOL); }

"do"                  { return XX_DO; }
"while"               { return XX_WHILE; }
"until"               { return XX_UNTIL; }
"for"                 { return XX_FOR; }
"each"                { return XX_EACH; }
"of"                  { return XX_OF; }
"switch"              { return XX_SWITCH; }
"case"                { return XX_CASE; }
"when"                { return XX_WHEN; }
"default"             { return XX_DEFAULT; }
"if"                  { return XX_IF; }
"else"                { return XX_ELSE; }
"with"                { return XX_WITH; }
"try"                 { return XX_TRY; }
"catch"               { return XX_CATCH; }
"throw"               { return XX_THROW; }
"break"               { return XX_BREAK; }
"continue"            { return XX_CONTINUE; }
"return"              { return XX_RETURN; }
"positionof"          { return XX_POSITIONOF; }
"sizeof"              { return XX_SIZEOF; }
"textof"              { return XX_TEXTOF; }
"typeof"              { return XX_TYPEOF; }
"positionis"          { return XX_POSITIONIS; }
"sizeis"              { return XX_SIZEIS; }
"textis"              { return XX_TEXTIS; }
"typeis"              { return XX_TYPEIS; }
"using"               { return XX_USING; }
"namespace"           { return XX_NAMESPACE; }
"template"            { return XX_TEMPLATE; }
"virtual"             { return XX_VIRTUAL; }
"public"              { return XX_PUBLIC; }
"private"             { return XX_PRIVATE; }
"protected"           { return XX_PROTECTED; }
"class"               { return XX_CLASS; }
"struct"              { return XX_STRUCT; }
"union"               { return XX_UNION; }
"void"                { return XX_VOID; }
"bool"                { return XX_BOOL; }
"char"                { return XX_CHAR; }
"float"               { return XX_FLOAT; }
"double"              { return XX_DOUBLE; }
"string"              { return XX_STRING; }
"int"                 { return XX_INT; }
"short"               { return XX_SHORT; }
"long"                { return XX_LONG; }
"signed"              { return XX_SIGNED; }
"unsigned"            { return XX_UNSIGNED; }
"include"             { return XX_INCLUDE; }
"extern"              { return XX_EXTERN; }
"native"              { return XX_NATIVE; }
"foreign"             { return XX_FOREIGN; }

"not"                 {return XX_LNOT_OP;}
"and"                 {return XX_LAND_OP;}
"or"                  {return XX_LOR_OP;}

"not="                { return XX_LCOM_OP;}
"and="                { return XX_LAND_ASSIGN;}
"or="                 { return XX_LOR_ASSIGN;}

"::&"                 { return XX_COLONCOLON_AND;}
"::*"                 { return XX_COLONCOLON_STAR;}
"::"                  { return XX_COLONCOLON;}
".."                  { return XX_DOTDOT;}
"..."                 { return XX_ELIPSIS;}

"\\\\>>"              { return XX_BSLASHBSLASH_SHR;}
"\\\\<<"              { return XX_BSLASHBSLASH_SHL;}
"\\\\"                { return XX_BSLASHBSLASH;}
".\\?"                { return XX_DOTBSLASHQUESTION;}
"\\?"                 { return XX_BSLASHQUESTION;}
"@?"                  { return XX_ATQUESTION;}
".?"                  { return XX_DOTQUESTION;}

">>="                 { return XX_SHR_ASSIGN;}
"<<="                 { return XX_SHL_ASSIGN;}
"&&="                 { return XX_LAND_ASSIGN;}
"||="                 { return XX_LOR_ASSIGN;}

"+="                  { return XX_ADD_ASSIGN;}
"-="                  { return XX_SUB_ASSIGN;}
"*="                  { return XX_MUL_ASSIGN;}
"/="                  { return XX_DIV_ASSIGN;}
"%="                  { return XX_MOD_ASSIGN;}
"&="                  { return XX_AND_ASSIGN;}
"|="                  { return XX_OR_ASSIGN;}
"^="                  { return XX_XOR_ASSIGN;}
":="                  { return XX_ASSIGN;}

">>>"                 { return XX_RIGHT_OP;}
"<<<"                 { return XX_LEFT_OP;}
"++"                  { return XX_INC_OP;}
"--"                  { return XX_DEC_OP;}
"~~"                  { return XX_COM_OP;}
"!!"                  { return XX_LCOM_OP;}

"<="                  { return XX_LE_OP;}
">="                  { return XX_GE_OP;}
"<>"                  { return XX_NE_OP;}
"!="                  { return XX_NE_OP;}
"=="                  { return XX_EQ_OP;}
">>"                  { return XX_SHR_OP;}
"<<"                  { return XX_SHL_OP;}
"&&"                  { return XX_LAND_OP;}
"||"                  { return XX_LOR_OP;}
"**"                  { return XX_POW_OP;}
"//"                  { return XX_ROO_OP;}
"%%"                  { return XX_LOG_OP;}

0|({N}{D}*){U}?{S}?   { if (OnToken(yytext)) return -1; else return XX_DEC_LITERAL; }
0[Xx]{H}+{U}?{S}?     { if (OnToken(&yytext[2])) return -1; else return XX_HEX_LITERAL; }
0[Yy]{B}+{U}?{S}?     { if (OnToken(&yytext[2])) return -1; else return XX_BIN_LITERAL; }
0{O}+{U}?{S}?         { if (OnToken(&yytext[1])) return -1; else return XX_OCT_LITERAL; }

0|({N}{D}*){F}{S}?    { if (OnToken(yytext)) return -1; return XX_FLOAT_LITERAL; }
{D}+"."{D}+{E}?{S}?   { if (OnToken(yytext)) return -1; return XX_FLOAT_LITERAL; }
{D}+{E}{S}?           { if (OnToken(yytext)) return -1; return XX_FLOAT_LITERAL; }

{L}({L}|{D})*         { if (OnToken(yytext)) return -1; return XX_IDENTIFIER; }

"*/"(\n|[^\/]|\/[^*])*"/*" { if (OnToken(yytext,2)) return -1; return XX_TEMPLATE_LITERAL; }
"%/"(\n|[^\/]|\/[^%])*"/%" { if (OnToken(yytext,2)) return -1; return XX_TEMPLATE_LITERAL; }

\"(\\.|[^\\"])*\"     { if (OnStringToken(yytext)) return -1; return XX_TEXT_LITERAL; }
\'(\\.|[^\\'])*\'     { if (OnStringToken(yytext)) return -1; return XX_TEXT_LITERAL; }
\\\\\'(\\.|[^\\'])*\' { if (OnStringToken(yytext+2)) return -1; return XX_URI_LITERAL; }
\\\\\"(\\.|[^\\"])*\" { if (OnStringToken(yytext+2)) return -1; return XX_URI_LITERAL; }
\\\\\`(\\.|[^\\`])*\` { if (OnStringToken(yytext+2)) return -1; return XX_ELEMENT_LITERAL; }

[ \t\r\n]             { }
.                     { return yytext[0];}
}

<COMMENT>{
"*/"                  { yy_pop_state();}
\n                    { }
.                     { }
}

<COMMENT2>{
"%/"                  { yy_pop_state();}
\n                    { }
.                     { }
}

<COMMENTEOL>{
\n                    { yy_pop_state();}
.                     { }
}

%%
