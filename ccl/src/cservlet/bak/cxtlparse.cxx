#ifndef lint
static char yysccsid[] = "@(#)yaccpar 1.8++ (Berkeley) 01/20/90, (Boyd) 1998";
#endif
#define YYBYACC 1
#define YYCPLUSPLUS 1
#include "cxtlparser.hxx"
#define XX_INCLUDE 257
#define XX_USING 258
#define XX_TRANSFORM 259
#define XX_TEMPLATE 260
#define XX_VARIABLE 261
#define XX_PARAMETER 262
#define XX_WITH 263
#define XX_TO 264
#define XX_OUTPUT 265
#define XX_METHOD 266
#define XX_FILE 267
#define XX_LOCATION 268
#define XX_NAME 269
#define XX_TEST 270
#define XX_SELECT 271
#define XX_MATCH 272
#define XX_APPLY 273
#define XX_DO 274
#define XX_WHILE 275
#define XX_UNTIL 276
#define XX_REPEAT 277
#define XX_FOR 278
#define XX_FOR_EACH 279
#define XX_SWITCH 280
#define XX_CASE 281
#define XX_DEFAULT 282
#define XX_IF 283
#define XX_THEN 284
#define XX_ELSE_IF 285
#define XX_ELSE 286
#define XX_BEGIN 287
#define XX_END 288
#define XX_BEGIN_ATTR 289
#define XX_END_ATTR 290
#define XX_XMLNS_ATTR 291
#define XX_VARIABLE_ATTR 292
#define XX_ELEMENT_LITERAL 293
#define XX_ATTR_LITERAL 294
#define XX_TEXT_LITERAL 295
#define XX_INVALID 296
#define YYERRCODE 256
short yyIsParser::yylhs[] = {                                        -1,
    0,    0,    2,    2,    1,    1,    4,    4,    5,    3,
    3,    6,    8,    7,    7,   10,   10,   11,   11,   11,
   11,   13,   17,   18,   19,   19,   14,   14,   14,   22,
   22,   25,   25,   26,   26,   27,   27,   27,   12,   12,
   12,   12,   12,   12,   12,   12,   35,   35,   36,   36,
   28,   39,   39,   39,   39,   39,   40,   40,   42,   42,
   44,   44,   45,   29,   29,   48,   48,   49,   49,   50,
   47,   47,   30,   51,   51,   31,   32,   53,   53,   55,
   52,   33,   33,   57,   57,   60,   58,   58,   63,   61,
   61,   34,   34,   34,   34,   34,   34,   68,   56,   69,
   69,   67,   67,   70,   66,   66,   71,   71,   72,   38,
   38,   73,   73,   74,   74,   75,   75,   15,   16,   46,
   46,   20,   21,   23,   24,   64,   65,   62,   59,   54,
   41,   43,   37,   85,   87,   86,   86,   88,   88,   76,
    9,   77,   78,   83,   82,   79,   84,   80,   81,   89,
   90,
};
short yyIsParser::yylen[] = {                                         2,
    3,    2,    3,    2,    3,    2,    2,    1,    1,    2,
    1,    4,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    2,    2,    1,    3,    2,    3,    3,    3,    3,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    1,    2,    1,
    2,    2,    2,    2,    2,    1,    4,    3,    3,    2,
    2,    1,    2,    2,    2,    2,    3,    2,    1,    4,
    3,    1,    2,    2,    4,    2,    2,    2,    1,    4,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    1,    4,    5,    4,    5,    4,    3,    2,    2,    3,
    1,    2,    1,    2,    3,    2,    2,    1,    4,    3,
    2,    2,    1,    1,    1,    1,    1,    2,    2,    3,
    2,    3,    4,    3,    3,    5,    4,    3,    3,    3,
    4,    3,    3,    1,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
short yyIsParser::yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,    0,
   48,    0,    0,   11,    0,   16,   17,   18,   19,   20,
   21,   39,   40,   41,   42,   43,   44,   45,   46,    6,
    9,    0,    0,    1,    0,   22,    0,   24,    0,    0,
    0,    0,    0,    0,    0,  119,  118,    0,    0,    0,
    0,    0,    0,   72,   64,   65,    0,    0,    0,   51,
   56,    0,    0,    0,    0,    0,   82,   83,    0,    0,
    0,    0,   76,    0,   79,   77,    0,    0,    0,   73,
    0,    0,    0,    0,    0,  134,   47,    0,   50,    0,
    3,   10,   14,    5,    7,  140,    0,    0,    0,   23,
  142,  143,    0,    0,    0,   27,   28,   29,    0,  121,
    0,  141,    0,    0,    0,  111,  115,  116,  117,    0,
    0,    0,    0,  114,    0,    0,   66,    0,  147,    0,
    0,   52,   54,    0,   53,   55,  144,  145,    0,    0,
    0,    0,   85,   88,   84,   87,    0,    0,  146,    0,
   78,    0,   74,    0,    0,    0,    0,   97,    0,    0,
   49,  150,  151,    0,    0,  138,  139,  122,   26,    0,
  124,    0,  125,   31,   35,   36,   37,   38,    0,    0,
   34,    0,  120,   13,   12,    0,    0,   67,   68,  110,
  112,   71,    0,   58,    0,    0,  132,   60,    0,  128,
  129,   91,    0,   86,   89,  101,    0,   99,    0,    0,
  130,    0,    0,   98,    0,   96,  148,    0,    0,   92,
    0,    0,   94,    0,    0,    0,  135,  133,  136,   25,
  123,   30,   32,  131,    0,   63,   57,   61,   59,    0,
    0,   81,   80,   75,  104,  102,  149,  127,    0,   95,
    0,  106,   93,    0,  107,   70,   90,  100,  126,    0,
  105,  109,
};
short yyIsParser::yydgoto[] = {                                       2,
    5,    6,   22,   42,   43,   23,   24,   59,  123,   25,
   26,  127,   28,  128,   30,  129,   46,   47,  110,   48,
   50,  116,   54,   52,  189,  190,  191,   32,   33,   34,
   35,   36,   37,   38,   39,   97,   98,  212,   70,   71,
   55,  143,   73,  209,  206,   56,   65,   66,  130,  131,
   90,  220,   83,   84,   85,  158,   77,   78,   79,  153,
  214,   80,  154,   94,   95,  234,  224,  165,  218,  225,
  235,  236,  132,  133,  134,  107,  119,  114,  160,  228,
  259,  149,  150,  140,  100,  174,  238,  175,  176,  177,
};
short yyIsParser::yysindex[] = {                                   -223,
 -214,    0, -217, -272, -238,    0, -234, -224, -215, -215,
 -210, -194, -193, -190, -189, -189, -179, -175,    0, -168,
    0, -186, -170,    0, -170,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -183, -180,    0, -153,    0, -246,    0, -222, -169,
 -169, -169, -142, -150, -138,    0,    0, -114, -125, -132,
 -222, -122, -150,    0,    0,    0, -101, -145, -116,    0,
    0, -113, -113,  -45, -206, -187,    0,    0, -150, -150,
  -97,  -95,    0, -150,    0,    0, -101,  -94, -150,    0,
  -97,  -95, -109, -108, -105,    0,    0, -150,    0, -162,
    0,    0,    0,    0,    0,    0, -110, -104, -102,    0,
    0,    0, -255, -103, -107,    0,    0,    0, -256,    0,
  -93,    0,  -96,  -90,  -88,    0,    0,    0,    0,  -89,
  -79,  -82,    5,    0,  -81,  -78,    0, -242,    0,  -72,
 -249,    0,    0, -235,    0,    0,    0,    0,  -69,  -67,
 -156, -156,    0,    0,    0,    0, -151,  -91,    0,  -65,
    0,  -91,    0,  -57,  -55, -261,  -71,    0,  -53, -225,
    0,    0,    0,  -58, -162,    0,    0,    0,    0,  -52,
    0,  -51,    0,    0,    0,    0,    0,    0,  -44,  -20,
    0,  -43,    0,    0,    0,  -35,  -68,    0,    0,    0,
    0,    0, -215,    0,  -42,  -18,    0,    0,  -39,    0,
    0,    0,  -30,    0,    0,    0,  -29,    0, -150,  -28,
    0,  -27, -150,    0, -203,    0,    0, -270,  -26,    0,
  -25, -150,    0,  -21,  -16,  -14,    0,    0,    0,    0,
    0,    0,    0,    0,  -19,    0,    0,    0,    0,   -6,
   -3,    0,    0,    0,    0,    0,    0,    0,  -22,    0,
  -15,    0,    0, -150,    0,    0,    0,    0,    0,   -2,
    0,    0,
};
short yyIsParser::yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -13,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,    6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   14,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yyIsParser::yygindex[] = {                                    227,
    0,  278,    0,  246,    0,    0,  125,    0,    0,    0,
    0,    1,    0,    2, -106,    7,    0,    0,    0,    0,
    0,  106,   25,   -5,  100,    0,    0,    0,  -56,    0,
    0,    0,    0,    0,    0,    0,    0,  -12,    0,  222,
  280,   87,  -11, -126,    0,   -7,    0,    0,  164,    0,
    0,  141,  288,  -17,    0,  214,    0,    0,    0,    0,
  154,    0,    0,    0,    0,   82,  142,    0,    0,    0,
   72,    0,  177,    0,    0,    0,    3,  198,  220,    0,
    0,    0,    0,  194,    0,  139,    0,    0,    0,    0,
};
#define YYTABLESIZE 314
short yyIsParser::yytable[] = {                                      64,
   93,   76,   57,   27,   29,   89,   63,   99,  187,   31,
  138,  205,    1,  203,  139,  257,  112,   40,   41,  258,
  203,   12,  227,   27,   29,   27,   29,  203,  221,   31,
  162,   31,   51,  181,  181,    1,   62,   69,  208,    7,
  108,  120,    8,    9,   10,  204,  111,   11,    3,  112,
  137,  113,  208,   12,   45,   13,   14,   15,   16,  231,
  232,   17,  233,  135,   49,   18,  155,  156,  147,  148,
   19,  161,    3,   53,    4,   20,  163,   21,   58,  248,
  168,  231,  232,  187,  138,  171,    7,  151,  152,    8,
    9,   10,   60,   67,   61,   68,   74,   81,   75,   82,
   12,  101,   13,   14,   15,   16,  104,   87,   17,   88,
   41,   91,   18,   92,  106,  185,  186,  115,   74,  197,
   96,  188,   20,  111,   21,  139,  111,    8,    9,  172,
   74,  173,   82,  213,  213,   74,   74,   88,   12,  125,
   13,   14,   15,   16,  216,  217,   17,  102,  121,  103,
   18,  122,    8,    9,   10,  126,  117,  118,  145,  146,
   20,  124,   21,   12,  136,   13,   14,   15,   16,   12,
  141,   17,  157,  144,  159,   18,  139,  167,  169,  178,
  184,  170,  219,  179,  180,   20,  183,   21,    8,    9,
  185,  186,  125,  194,  193,  246,  188,  195,  198,   12,
  196,   13,   14,   15,   16,  200,  252,   17,  181,  202,
  255,   18,  223,  261,    8,    9,  126,  207,  245,  262,
  210,   20,  211,   21,  221,   12,  223,   13,   14,   15,
   16,  237,  226,   17,  230,  240,  112,   18,  241,    8,
    9,   10,  126,  242,  203,  247,  244,   20,  249,   21,
   12,  271,   13,   14,   15,   16,  250,  251,   17,  253,
  254,  260,   18,   82,    8,    9,  263,  269,  266,  264,
  231,  270,   20,  109,   21,   12,    8,   13,   14,   15,
   16,  267,   44,   17,  268,  272,   15,   18,  105,  243,
  142,   69,   72,  113,  199,   33,  108,   20,  137,   21,
   62,  103,  222,   86,  164,  215,  256,  265,  229,  201,
  182,  166,  192,  239,
};
short yyIsParser::yycheck[] = {                                      12,
   18,   14,   10,    3,    3,   17,   12,   20,  115,    3,
   67,  138,  259,  263,  271,  286,  272,  290,  291,  290,
  263,  271,  284,   23,   23,   25,   25,  263,  290,   23,
   87,   25,    8,  290,  290,  259,   12,   13,  288,  257,
  287,   54,  260,  261,  262,  288,  269,  265,  287,  272,
   63,   49,  288,  271,  289,  273,  274,  275,  276,  285,
  286,  279,  288,   61,  289,  283,   79,   80,  275,  276,
  288,   84,  287,  289,  289,  293,   89,  295,  289,  206,
   93,  285,  286,  190,  141,   98,  257,  275,  276,  260,
  261,  262,  287,  287,  289,  289,  287,  287,  289,  289,
  271,  288,  273,  274,  275,  276,  290,  287,  279,  289,
  291,  287,  283,  289,  268,  115,  115,  287,  287,  125,
  289,  115,  293,  269,  295,  271,  269,  260,  261,  292,
  287,  294,  289,  151,  152,  287,  287,  289,  271,  272,
  273,  274,  275,  276,  157,  157,  279,   23,  287,   25,
  283,  266,  260,  261,  262,  288,   51,   52,   72,   73,
  293,  287,  295,  271,  287,  273,  274,  275,  276,  271,
  287,  279,  270,  287,  270,  283,  271,  287,  287,  290,
  288,  287,  274,  288,  287,  293,  290,  295,  260,  261,
  190,  190,  272,  290,  288,  203,  190,  288,  288,  271,
  289,  273,  274,  275,  276,  288,  219,  279,  290,  288,
  223,  283,  284,  231,  260,  261,  288,  290,  287,  232,
  290,  293,  290,  295,  290,  271,  284,  273,  274,  275,
  276,  290,  288,  279,  288,  288,  272,  283,  290,  260,
  261,  262,  288,  288,  263,  288,  290,  293,  288,  295,
  271,  264,  273,  274,  275,  276,  287,  287,  279,  288,
  288,  288,  283,  289,  260,  261,  288,  290,  288,  286,
  285,  287,  293,   47,  295,  271,  290,  273,  274,  275,
  276,  288,    5,  279,  288,  288,  288,  283,   43,  190,
   69,  288,   13,  288,  131,  288,  286,  293,  290,  295,
  288,  288,  162,   16,   91,  152,  225,  236,  167,  133,
  113,   92,  119,  175,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#if YYDEBUG
char *yyIsParser::yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"XX_INCLUDE","XX_USING",
"XX_TRANSFORM","XX_TEMPLATE","XX_VARIABLE","XX_PARAMETER","XX_WITH","XX_TO",
"XX_OUTPUT","XX_METHOD","XX_FILE","XX_LOCATION","XX_NAME","XX_TEST","XX_SELECT",
"XX_MATCH","XX_APPLY","XX_DO","XX_WHILE","XX_UNTIL","XX_REPEAT","XX_FOR",
"XX_FOR_EACH","XX_SWITCH","XX_CASE","XX_DEFAULT","XX_IF","XX_THEN","XX_ELSE_IF",
"XX_ELSE","XX_BEGIN","XX_END","XX_BEGIN_ATTR","XX_END_ATTR","XX_XMLNS_ATTR",
"XX_VARIABLE_ATTR","XX_ELEMENT_LITERAL","XX_ATTR_LITERAL","XX_TEXT_LITERAL",
"XX_INVALID",
};
char *yyIsParser::yyrule[] = {
"$accept : transform_declaration",
"transform_declaration : XX_TRANSFORM transform_attr_body transform_body",
"transform_declaration : XX_TRANSFORM transform_body",
"transform_body : XX_BEGIN transform_block XX_END",
"transform_body : XX_BEGIN XX_END",
"transform_attr_body : XX_BEGIN_ATTR transform_attr_list XX_END_ATTR",
"transform_attr_body : XX_BEGIN_ATTR XX_END_ATTR",
"transform_attr_list : transform_attr transform_attr_list",
"transform_attr_list : transform_attr",
"transform_attr : XX_XMLNS_ATTR",
"transform_block : transform_output transform_block_list",
"transform_block : transform_block_list",
"transform_output : XX_OUTPUT transform_output_attr XX_BEGIN XX_END",
"transform_output_attr : XX_BEGIN_ATTR method_value XX_END_ATTR",
"transform_block_list : transform_block_item transform_block_list",
"transform_block_list : transform_block_item",
"transform_block_item : transform_block_declaration",
"transform_block_item : statement",
"transform_block_declaration : include_declaration",
"transform_block_declaration : template_declaration",
"transform_block_declaration : parameter_declaration",
"transform_block_declaration : variable_declaration",
"include_declaration : XX_INCLUDE include_declaration_body",
"include_declaration_body : include_location include_body",
"include_location : location_expr",
"include_body : transform_declaration XX_BEGIN XX_END",
"include_body : XX_BEGIN XX_END",
"template_declaration : XX_TEMPLATE name_match_expr template_body",
"template_declaration : XX_TEMPLATE name_expr template_body",
"template_declaration : XX_TEMPLATE match_expr template_body",
"template_body : XX_BEGIN template_block XX_END",
"template_body : XX_BEGIN XX_END",
"template_block : template_block_item template_block",
"template_block : template_block_item",
"template_block_item : template_block_declaration",
"template_block_item : statement",
"template_block_declaration : template_declaration",
"template_block_declaration : parameter_declaration",
"template_block_declaration : variable_declaration",
"statement : apply_statement",
"statement : select_statement",
"statement : for_each_statement",
"statement : while_statement",
"statement : until_statement",
"statement : do_test_statement",
"statement : if_statement",
"statement : literal_statement",
"literal_statement : XX_ELEMENT_LITERAL literal_statement_body",
"literal_statement : XX_TEXT_LITERAL",
"literal_statement_body : literal_expr statement_body",
"literal_statement_body : statement_body",
"apply_statement : XX_APPLY apply_statement_body",
"apply_statement_body : name_expr apply_select_with_body",
"apply_statement_body : name_select_expr apply_with_body",
"apply_statement_body : name_expr apply_with_body",
"apply_statement_body : select_expr apply_with_body",
"apply_statement_body : apply_select_with_body",
"apply_select_with_body : XX_BEGIN select_statement apply_with_list XX_END",
"apply_select_with_body : XX_BEGIN select_statement XX_END",
"apply_with_body : XX_BEGIN apply_with_list XX_END",
"apply_with_body : XX_BEGIN XX_END",
"apply_with_list : apply_with apply_with_list",
"apply_with_list : apply_with",
"apply_with : XX_WITH name_select_statement_body",
"select_statement : XX_SELECT name_statement_body",
"select_statement : XX_SELECT match_statement_body",
"match_statement_body : match_expr statement_body",
"match_statement_body : XX_BEGIN match_statement_list XX_END",
"match_statement_list : match_statement match_statement_list",
"match_statement_list : match_statement",
"match_statement : XX_MATCH match_expr XX_BEGIN XX_END",
"name_statement_body : name_expr XX_BEGIN XX_END",
"name_statement_body : statement_body",
"for_each_statement : XX_FOR_EACH for_each_statement_body",
"for_each_statement_body : select_expr statement_body",
"for_each_statement_body : XX_BEGIN select_statement do_statement XX_END",
"while_statement : XX_WHILE test_do_statement",
"until_statement : XX_UNTIL test_do_statement",
"test_do_statement : test_expr statement_body",
"test_do_statement : test_do_body",
"test_do_body : XX_BEGIN test_statement do_statement XX_END",
"do_statement : XX_DO statement_body",
"do_test_statement : XX_DO do_while_statement",
"do_test_statement : XX_DO do_until_statement",
"do_while_statement : while_expr statement_body",
"do_while_statement : statement_body do_while_test",
"do_while_test : XX_WHILE do_test",
"do_until_statement : until_expr statement_body",
"do_until_statement : statement_body do_until_test",
"do_until_test : XX_UNTIL do_test",
"do_test : test_expr XX_BEGIN XX_END",
"do_test : statement_body",
"if_statement : XX_IF test_then_else_expr XX_BEGIN XX_END",
"if_statement : XX_IF test_then_expr XX_BEGIN else_statement_list XX_END",
"if_statement : XX_IF test_then_expr XX_BEGIN XX_END",
"if_statement : XX_IF test_expr XX_BEGIN then_statement_list XX_END",
"if_statement : XX_IF XX_BEGIN test_then_statement_list XX_END",
"if_statement : XX_IF test_expr statement_body",
"test_then_statement_list : test_statement then_statement_list",
"test_statement : XX_TEST test_statement_body",
"test_statement_body : select_expr XX_BEGIN XX_END",
"test_statement_body : statement_body",
"then_statement_list : then_statement else_statement_list",
"then_statement_list : then_statement",
"then_statement : XX_THEN statement_body",
"else_statement_list : else_if_statement_list XX_ELSE statement_body",
"else_statement_list : XX_ELSE statement_body",
"else_if_statement_list : else_if_statement else_if_statement_list",
"else_if_statement_list : else_if_statement",
"else_if_statement : XX_ELSE_IF test_expr XX_BEGIN XX_END",
"statement_body : XX_BEGIN statement_block XX_END",
"statement_body : XX_BEGIN XX_END",
"statement_block : statement_block_item statement_block",
"statement_block : statement_block_item",
"statement_block_item : statement_block_declaration",
"statement_block_item : statement",
"statement_block_declaration : template_declaration",
"statement_block_declaration : variable_declaration",
"parameter_declaration : XX_PARAMETER name_select_statement_body",
"variable_declaration : XX_VARIABLE name_select_statement_body",
"name_select_statement_body : name_select_expr XX_BEGIN XX_END",
"name_select_statement_body : name_expr statement_body",
"location_expr : XX_BEGIN_ATTR location_value XX_END_ATTR",
"name_match_expr : XX_BEGIN_ATTR name_value match_value XX_END_ATTR",
"name_expr : XX_BEGIN_ATTR name_value XX_END_ATTR",
"match_expr : XX_BEGIN_ATTR match_value XX_END_ATTR",
"test_then_else_expr : XX_BEGIN_ATTR test_value then_value else_value XX_END_ATTR",
"test_then_expr : XX_BEGIN_ATTR test_value then_value XX_END_ATTR",
"until_expr : XX_BEGIN_ATTR until_value XX_END_ATTR",
"while_expr : XX_BEGIN_ATTR while_value XX_END_ATTR",
"test_expr : XX_BEGIN_ATTR test_value XX_END_ATTR",
"name_select_expr : XX_BEGIN_ATTR name_value select_value XX_END_ATTR",
"select_expr : XX_BEGIN_ATTR select_value XX_END_ATTR",
"literal_expr : begin_attr literal_value_list end_attr",
"begin_attr : XX_BEGIN_ATTR",
"end_attr : XX_END_ATTR",
"literal_value_list : literal_value_item literal_value_list",
"literal_value_list : literal_value_item",
"literal_value_item : variable_value",
"literal_value_item : literal_value",
"location_value : XX_LOCATION",
"method_value : XX_METHOD",
"name_value : XX_NAME",
"match_value : XX_MATCH",
"while_value : XX_WHILE",
"until_value : XX_UNTIL",
"test_value : XX_TEST",
"select_value : XX_SELECT",
"then_value : XX_THEN",
"else_value : XX_ELSE",
"variable_value : XX_VARIABLE_ATTR",
"literal_value : XX_ATTR_LITERAL",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

yyIsParser::yyIsParser()
{
    yyss = 0;
    yyvs = 0;
}

yyIsParser::~yyIsParser()
{
    yyfinish();
}

int yyIsParser::yyinit()
{
    while (!yyss)
        if ((yyss = new short[YYSTACKSIZE]) == 0)
        if (yyoutofmemory())
            return 0;

    while (!yyvs)
        if ((yyvs= new YYSTYPE[YYSTACKSIZE]) == 0)
        if (yyoutofmemory())
            return 0;

    return 1;
}

void yyIsParser::yyfinish()
{
    if (yyvs)
    {
        delete yyvs;
        yyvs = 0;
    }
    if (yyss)
    {
        delete yyss;
        yyss = 0;
    }
}

int yyIsParser::yyoutofmemory()
{
    yyerror("out of memory");
    return 1;
}

void yyIsParser::yyerror(const char *msg)
{
   yyprintf("%s\n",msg);
}

int yyIsParser::yyprintf( const char* format, ... )
{
   va_list arg;
   int result;

   va_start(arg,format);
   result=vprintf(format,arg);
   va_end(arg);
   return result;
}

int yyParser::yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (!yyinit())
        goto yyabort;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            yyprintf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            yyprintf("yydebug: state %d, shifting to state %d\n",
                    yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    yyprintf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    yyprintf("yydebug: error recovery discarding state %d\
",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            yyprintf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        yyprintf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 9:
{ OnXmlnsAttr(); }
break;
case 24:
{if ((m_error = OnIncludeLocation())) return m_error;}
break;
case 134:
{OnBeginAttr();}
break;
case 135:
{OnEndAttr();}
break;
case 140:
{if ((m_error = OnLocationValue())) return m_error;}
break;
case 141:
{ if ((m_error = OnMethodValue())) return m_error; }
break;
case 142:
{ if ((m_error = OnNameValue())) return m_error; }
break;
case 143:
{ if ((m_error = OnMatchValue())) return m_error; }
break;
case 144:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 145:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 146:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 147:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 148:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 149:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 150:
{ if ((m_error = OnVariableExpression())) return m_error; }
break;
case 151:
{ if ((m_error = OnLiteralExpression())) return m_error; }
break;
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            yyprintf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                yyprintf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        yyprintf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
