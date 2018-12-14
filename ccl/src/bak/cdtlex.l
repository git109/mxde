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

"do"                  { return DO; }
"while"               { return WHILE; }
"until"               { return UNTIL; }
"for"                 { return FOR; }
"each"                { return EACH; }
"of"                  { return OF; }
"switch"              { return SWITCH; }
"case"                { return CASE; }
"when"                { return WHEN; }
"default"             { return DEFAULT; }
"if"                  { return IF; }
"else"                { return ELSE; }
"with"                { return WITH; }
"try"                 { return TRY; }
"catch"               { return CATCH; }
"throw"               { return THROW; }
"break"               { return BREAK; }
"continue"            { return CONTINUE; }
"return"              { return RETURN; }
"positionof"          { return POSITIONOF; }
"sizeof"              { return SIZEOF; }
"textof"              { return TEXTOF; }
"typeof"              { return TYPEOF; }
"positionis"          { return POSITIONIS; }
"sizeis"              { return SIZEIS; }
"textis"              { return TEXTIS; }
"typeis"              { return TYPEIS; }
"using"               { return USING; }
"namespace"           { return NAMESPACE; }
"template"            { return TEMPLATE; }
"virtual"             { return VIRTUAL; }
"public"              { return PUBLIC; }
"private"             { return PRIVATE; }
"protected"           { return PROTECTED; }
"class"               { return CLASS; }
"struct"              { return STRUCT; }
"union"               { return UNION; }
"void"                { return VOID; }
"bool"                { return BOOL; }
"char"                { return CHAR; }
"float"               { return FLOAT; }
"double"              { return DOUBLE; }
"string"              { return STRING; }
"int"                 { return INT; }
"short"               { return SHORT; }
"long"                { return LONG; }
"signed"              { return SIGNED; }
"unsigned"            { return UNSIGNED; }
"include"             { return INCLUDE; }
"extern"              { return EXTERN; }
"native"              { return NATIVE; }
"foreign"             { return FOREIGN; }

"not"                 {return LNOT_OP;}
"and"                 {return LAND_OP;}
"or"                  {return LOR_OP;}

"not="                { return LCOM_OP;}
"and="                { return LAND_ASSIGN;}
"or="                 { return LOR_ASSIGN;}

"::&"                 { return COLONCOLON_AND;}
"::*"                 { return COLONCOLON_STAR;}
"::"                  { return COLONCOLON;}
".."                  { return DOTDOT;}
"..."                 { return ELIPSIS;}

"\\\\>>"              { return BSLASHBSLASH_SHR;}
"\\\\<<"              { return BSLASHBSLASH_SHL;}
"\\\\"                { return BSLASHBSLASH;}
".\\?"                { return DOTBSLASHQUESTION;}
"\\?"                 { return BSLASHQUESTION;}
"@?"                  { return ATQUESTION;}
".?"                  { return DOTQUESTION;}

">>="                 { return SHR_ASSIGN;}
"<<="                 { return SHL_ASSIGN;}
"&&="                 { return LAND_ASSIGN;}
"||="                 { return LOR_ASSIGN;}

"+="                  { return ADD_ASSIGN;}
"-="                  { return SUB_ASSIGN;}
"*="                  { return MUL_ASSIGN;}
"/="                  { return DIV_ASSIGN;}
"%="                  { return MOD_ASSIGN;}
"&="                  { return AND_ASSIGN;}
"|="                  { return OR_ASSIGN;}
"^="                  { return XOR_ASSIGN;}
":="                  { return ASSIGN;}

">>>"                 { return RIGHT_OP;}
"<<<"                 { return LEFT_OP;}
"++"                  { return INC_OP;}
"--"                  { return DEC_OP;}
"~~"                  { return COM_OP;}
"!!"                  { return LCOM_OP;}

"<="                  { return LE_OP;}
">="                  { return GE_OP;}
"<>"                  { return NE_OP;}
"!="                  { return NE_OP;}
"=="                  { return EQ_OP;}
">>"                  { return SHR_OP;}
"<<"                  { return SHL_OP;}
"&&"                  { return LAND_OP;}
"||"                  { return LOR_OP;}
"**"                  { return POW_OP;}
"//"                  { return ROO_OP;}
"%%"                  { return LOG_OP;}

0|({N}{D}*){U}?{S}?   { if (OnToken(yytext)) return -1; else return DEC_LITERAL; }
0[Xx]{H}+{U}?{S}?     { if (OnToken(&yytext[2])) return -1; else return HEX_LITERAL; }
0[Yy]{B}+{U}?{S}?     { if (OnToken(&yytext[2])) return -1; else return BIN_LITERAL; }
0{O}+{U}?{S}?         { if (OnToken(&yytext[1])) return -1; else return OCT_LITERAL; }

0|({N}{D}*){F}{S}?    { if (OnToken(yytext)) return -1; return FLOAT_LITERAL; }
{D}+"."{D}+{E}?{S}?   { if (OnToken(yytext)) return -1; return FLOAT_LITERAL; }
{D}+{E}{S}?           { if (OnToken(yytext)) return -1; return FLOAT_LITERAL; }

{L}({L}|{D})*         { if (OnToken(yytext)) return -1; return IDENTIFIER; }

"*/"(\n|[^\/]|\/[^*])*"/*" { if (OnToken(yytext,2)) return -1; return TEMPLATE_LITERAL; }
"%/"(\n|[^\/]|\/[^%])*"/%" { if (OnToken(yytext,2)) return -1; return TEMPLATE_LITERAL; }

\"(\\.|[^\\"])*\"     { if (OnStringToken(yytext)) return -1; return TEXT_LITERAL; }
\'(\\.|[^\\'])*\'     { if (OnStringToken(yytext)) return -1; return TEXT_LITERAL; }
\\\\\'(\\.|[^\\'])*\' { if (OnStringToken(yytext+2)) return -1; return URI_LITERAL; }
\\\\\"(\\.|[^\\"])*\" { if (OnStringToken(yytext+2)) return -1; return URI_LITERAL; }
\\\\\`(\\.|[^\\`])*\` { if (OnStringToken(yytext+2)) return -1; return ELEMENT_LITERAL; }

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
