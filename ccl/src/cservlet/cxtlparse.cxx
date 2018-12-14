#ifndef lint
static char yysccsid[] = "@(#)yaccpar 1.8++ (Berkeley) 01/20/90, (Boyd) 1998";
#endif
#define YYBYACC 1
#define YYCPLUSPLUS 1
#include "cxtlparser.hxx"

#define YY(on) if ((m_error = on())) return m_error;
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
#define XX_IS 275
#define XX_WHILE 276
#define XX_UNTIL 277
#define XX_REPEAT 278
#define XX_FOR 279
#define XX_FOR_EACH 280
#define XX_SWITCH 281
#define XX_CASE 282
#define XX_DEFAULT 283
#define XX_IF 284
#define XX_THEN 285
#define XX_ELSE_IF 286
#define XX_ELSE 287
#define XX_BEGIN 288
#define XX_END 289
#define XX_BEGIN_ATTR 290
#define XX_END_ATTR 291
#define XX_XMLNS_ATTR 292
#define XX_VARIABLE_ATTR 293
#define XX_EXPRESSION_ATTR 294
#define XX_ELEMENT_LITERAL 295
#define XX_ATTR_LITERAL 296
#define XX_TEXT_LITERAL 297
#define XX_INVALID 298
#define YYERRCODE 256
short yyIsParser::yylhs[] = {                                        -1,
    0,    0,    2,    2,    1,    1,    4,    4,    5,    3,
    3,    6,    8,    7,    7,   10,   10,   11,   11,   11,
   11,   13,   17,   18,   19,   19,   14,   14,   14,   22,
   22,   25,   25,   26,   26,   27,   27,   27,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   37,   37,
   39,   38,   38,   28,   42,   42,   42,   42,   42,   43,
   43,   45,   45,   47,   47,   48,   29,   29,   51,   51,
   52,   52,   53,   50,   50,   31,   54,   54,   32,   33,
   30,   57,   57,   59,   60,   61,   61,   61,   63,   64,
   56,   56,   65,   55,   36,   34,   34,   66,   66,   69,
   67,   67,   72,   70,   70,   35,   35,   35,   35,   35,
   35,   77,   62,   78,   78,   76,   76,   79,   75,   75,
   80,   80,   81,   41,   41,   82,   82,   83,   83,   84,
   84,   15,   16,   49,   49,   20,   21,   23,   24,   73,
   74,   71,   68,   58,   44,   46,   40,   94,   96,   95,
   95,   97,   97,   97,   85,    9,   86,   87,   92,   91,
   88,   93,   89,   90,   98,   99,  100,
};
short yyIsParser::yylen[] = {                                         2,
    3,    2,    3,    2,    3,    2,    2,    1,    1,    2,
    1,    4,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    2,    2,    1,    3,    2,    3,    3,    3,    3,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    1,
    1,    2,    1,    2,    2,    2,    2,    2,    1,    4,
    3,    3,    2,    2,    1,    2,    2,    2,    2,    3,
    2,    1,    4,    3,    1,    2,    2,    4,    2,    2,
    2,    2,    1,    3,    4,    2,    1,    1,    2,    2,
    2,    1,    4,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    1,    4,    5,    4,    5,    4,
    3,    2,    2,    3,    1,    2,    1,    2,    3,    2,
    2,    1,    4,    3,    2,    2,    1,    1,    1,    1,
    1,    2,    2,    3,    2,    3,    4,    3,    3,    5,
    4,    3,    3,    3,    4,    3,    3,    1,    1,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
short yyIsParser::yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,   51,    0,    0,   11,    0,   16,   17,   18,
   19,   20,   21,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   50,    6,    9,    0,    0,    1,    0,
   22,    0,   24,    0,    0,    0,    0,    0,    0,    0,
  133,  132,    0,    0,    0,    0,    0,    0,   75,   67,
   68,    0,    0,    0,   54,   59,    0,    0,    0,    0,
    0,   96,   97,    0,    0,   95,    0,    0,   79,    0,
   92,   80,    0,    0,    0,   76,    0,   81,    0,   83,
    0,    0,    0,    0,    0,  148,   49,    0,   53,    0,
    3,   10,   14,    5,    7,  155,    0,    0,    0,   23,
  157,  158,    0,    0,    0,   27,   28,   29,    0,  135,
    0,  156,    0,    0,    0,  125,  129,  130,  131,    0,
    0,    0,    0,  128,    0,    0,   69,    0,  162,    0,
    0,   55,   57,    0,   56,   58,  159,  160,    0,    0,
    0,    0,   99,  102,   98,  101,    0,    0,  161,    0,
   91,    0,   77,    0,    0,   82,    0,    0,    0,    0,
  111,    0,    0,   52,  166,  165,  167,    0,    0,  152,
  153,  154,  136,   26,    0,  138,    0,  139,   31,   35,
   36,   37,   38,    0,    0,   34,    0,  134,   13,   12,
    0,    0,   70,   71,  124,  126,   74,    0,   61,    0,
    0,  146,   63,    0,  142,  143,  105,    0,  100,  103,
  115,    0,  113,    0,    0,  144,    0,    0,    0,    0,
    0,   88,    0,    0,  112,    0,  110,  163,    0,    0,
  106,    0,    0,  108,    0,    0,    0,  149,  147,  150,
   25,  137,   30,   32,  145,    0,   66,   60,   64,   62,
    0,    0,   94,   93,   78,   89,   90,   85,   86,   84,
  118,  116,  164,  141,    0,  109,    0,  120,  107,    0,
  121,   73,  104,  114,  140,    0,  119,  123,
};
short yyIsParser::yydgoto[] = {                                       2,
    5,    6,   24,   47,   48,   25,   26,   64,  133,   27,
   28,  137,   30,  138,   32,  139,   51,   52,  120,   53,
   55,  126,   59,   57,  204,  205,  206,   34,   35,   36,
   37,   38,   39,   40,   41,   42,   43,  107,   44,  108,
  227,   75,   76,   60,  153,   78,  224,  221,   61,   70,
   71,  140,  141,   96,  235,   89,   98,   90,  176,  100,
  240,  168,  241,  242,   91,   82,   83,   84,  163,  229,
   85,  164,  104,  105,  255,  245,  178,  233,  246,  256,
  257,  142,  143,  144,  117,  129,  124,  170,  249,  285,
  159,  160,  150,  110,  188,  259,  189,  190,  191,  192,
};
short yyIsParser::yysindex[] = {                                   -235,
 -213,    0, -162, -223, -250,    0, -238, -214, -196, -196,
 -193, -208, -204, -198, -247, -183, -183, -182, -167, -164,
    0, -158,    0, -179, -112,    0, -112,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -171, -163,    0, -143,
    0, -242,    0, -240, -115, -115, -115, -111, -247, -114,
    0,    0,  -88, -109, -210, -240, -108, -247,    0,    0,
    0,  -90, -131, -106,    0,    0, -104, -104,   -4, -125,
 -123,    0,    0, -247, -247,    0,  -83,  -77,    0, -247,
    0,    0,  -90,  -74, -247,    0,  -83,    0,  -94,    0,
  -83,  -77,  -87,  -86,  -82,    0,    0, -247,    0, -236,
    0,    0,    0,    0,    0,    0,  -93,  -89,  -81,    0,
    0,    0, -249,  -78,  -85,    0,    0,    0, -251,    0,
  -84,    0,  -76,  -73,  -72,    0,    0,    0,    0,  -70,
  -69,  -68,   46,    0,  -71,  -66,    0, -244,    0,  -67,
 -245,    0,    0, -241,    0,    0,    0,    0,  -65,  -60,
 -151, -151,    0,    0,    0,    0, -147,  -57,    0,  -56,
    0,  -57,    0, -166, -166,    0,  -52,  -64, -264,  -31,
    0,  -55, -185,    0,    0,    0,    0,  -53, -236,    0,
    0,    0,    0,    0,  -50,    0,  -44,    0,    0,    0,
    0,    0,    0,  -41,   21,    0,  -40,    0,    0,    0,
  -36,  -33,    0,    0,    0,    0,    0, -196,    0,  -37,
   -3,    0,    0,  -30,    0,    0,    0,  -27,    0,    0,
    0,  -26,    0, -247,  -24,    0,  -21, -183, -247,  -14,
 -166,    0,   -5, -247,    0, -130,    0,    0, -248,   -2,
    0,  -16, -247,    0,   -1,   -8,  -23,    0,    0,    0,
    0,    0,    0,    0,    0,   10,    0,    0,    0,    0,
   11,   14,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   13,    0,    2,    0,    0, -247,
    0,    0,    0,    0,    0,   19,    0,    0,
};
short yyIsParser::yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   20,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   23,    0,   25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   24,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   39,    0,    0,    0,    0,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   44,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
short yyIsParser::yygindex[] = {                                    234,
    0,  284,    0,  262,    0,    0,  117,    0,    0,    0,
    0,    3,    0,    6, -117,    9,    0,    0,    0,    0,
    0,  110,   41,    1,  106,    0,    0,    0,  -58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -12,    0,  258,  320,   93,   -7, -132,    0,   -9,    0,
    0,  193,    0,    0,  163,  -10,    0,  -15,    0,    0,
 -160,  -42,    0,    0,    0,    0,    0,    0,    0,  174,
    0,    0,    0,    0,   91,  158,    0,    0,    0,   82,
    0,  197,    0,    0,    0,  -29,  219,  242,    0,    0,
    0,    0,  216,    0,  157,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 346
short yyIsParser::yytable[] = {                                      69,
   62,   81,   86,   99,  103,   29,   92,  202,   31,  109,
   95,   33,   68,  148,  243,  220,    1,  218,  218,  149,
  248,  218,  122,    1,  123,   12,  236,   29,  121,   29,
   31,  122,   31,   33,  172,   33,  145,    3,  283,  196,
   79,  196,  284,  223,  219,  118,  130,  223,   56,    8,
    9,   50,   67,   74,  174,  147,  185,  186,  177,  187,
   12,  135,   13,   14,   15,   16,   17,   45,   46,   18,
   19,  165,  166,   20,    3,   54,    4,  171,  136,   65,
  279,   66,  173,   72,   22,   73,   23,  202,  269,   79,
  181,   80,  148,   58,    7,  184,   63,    8,    9,   10,
  252,  253,   11,  254,   87,   93,   88,   94,   12,  111,
   13,   14,   15,   16,   17,  238,  239,   18,   19,  114,
   97,   20,   88,  101,  116,  102,   21,  200,   46,   79,
  201,  106,   22,  203,   23,  212,   79,  121,   88,  149,
   79,  112,   94,  113,    7,  228,  228,    8,    9,   10,
  157,  158,  161,  162,  231,  252,  253,  121,   12,  232,
   13,   14,   15,   16,   17,  127,  128,   18,   19,  155,
  156,   20,  125,  131,    8,    9,   10,  132,  134,  146,
   12,  151,   22,  154,   23,   12,  167,   13,   14,   15,
   16,   17,  169,  175,   18,   19,  149,  193,   20,  194,
  180,  182,  135,  199,  208,  183,  195,  200,  267,   22,
  201,   23,  198,  203,  209,  210,  234,  211,  213,  196,
  215,  273,  217,  222,  247,  225,  277,  276,    8,    9,
  226,  281,  244,  251,  236,  122,  287,  258,  261,   12,
  288,   13,   14,   15,   16,   17,  262,  263,   18,   19,
  265,  268,   20,  244,  266,    8,    9,  136,  270,  218,
  271,  272,  252,   22,  274,   23,   12,  275,   13,   14,
   15,   16,   17,   88,  278,   18,   19,  297,  290,   20,
    8,    9,   10,  280,  136,  119,  286,  289,   49,  296,
   22,   12,   23,   13,   14,   15,   16,   17,  292,  293,
   18,   19,  294,  295,   20,    8,    9,  298,   15,  115,
  264,   72,    8,  127,  151,   22,   12,   23,   13,   14,
   15,   16,   17,   33,   65,   18,   19,   87,  117,   20,
  122,  152,   77,  214,  237,  230,  282,  250,  291,  216,
   22,  197,   23,  179,  207,  260,
};
short yyIsParser::yycheck[] = {                                      12,
   10,   14,   15,   19,   20,    3,   17,  125,    3,   22,
   18,    3,   12,   72,  175,  148,  259,  263,  263,  271,
  285,  263,  272,  259,   54,  271,  291,   25,  269,   27,
   25,  272,   27,   25,   93,   27,   66,  288,  287,  291,
  288,  291,  291,  289,  289,  288,   59,  289,    8,  260,
  261,  290,   12,   13,   97,   68,  293,  294,  101,  296,
  271,  272,  273,  274,  275,  276,  277,  291,  292,  280,
  281,   84,   85,  284,  288,  290,  290,   90,  289,  288,
  241,  290,   95,  288,  295,  290,  297,  205,  221,  288,
  103,  290,  151,  290,  257,  108,  290,  260,  261,  262,
  286,  287,  265,  289,  288,  288,  290,  290,  271,  289,
  273,  274,  275,  276,  277,  282,  283,  280,  281,  291,
  288,  284,  290,  288,  268,  290,  289,  125,  292,  288,
  125,  290,  295,  125,  297,  135,  288,  269,  290,  271,
  288,   25,  290,   27,  257,  161,  162,  260,  261,  262,
  276,  277,  276,  277,  167,  286,  287,  269,  271,  167,
  273,  274,  275,  276,  277,   56,   57,  280,  281,   77,
   78,  284,  288,  288,  260,  261,  262,  266,  288,  288,
  271,  288,  295,  288,  297,  271,  270,  273,  274,  275,
  276,  277,  270,  288,  280,  281,  271,  291,  284,  289,
  288,  288,  272,  289,  289,  288,  288,  205,  218,  295,
  205,  297,  291,  205,  291,  289,  274,  290,  289,  291,
  289,  234,  289,  291,  289,  291,  239,  238,  260,  261,
  291,  244,  285,  289,  291,  272,  252,  291,  289,  271,
  253,  273,  274,  275,  276,  277,  291,  289,  280,  281,
  291,  289,  284,  285,  288,  260,  261,  289,  289,  263,
  288,  288,  286,  295,  289,  297,  271,  289,  273,  274,
  275,  276,  277,  290,  289,  280,  281,  290,  287,  284,
  260,  261,  262,  289,  289,   52,  289,  289,    5,  288,
  295,  271,  297,  273,  274,  275,  276,  277,  289,  289,
  280,  281,  289,  291,  284,  260,  261,  289,  289,   48,
  205,  289,  291,  289,  291,  295,  271,  297,  273,  274,
  275,  276,  277,  289,  289,  280,  281,  289,  289,  284,
  287,   74,   13,  141,  172,  162,  246,  180,  257,  143,
  295,  123,  297,  102,  129,  189,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
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
"XX_MATCH","XX_APPLY","XX_DO","XX_IS","XX_WHILE","XX_UNTIL","XX_REPEAT",
"XX_FOR","XX_FOR_EACH","XX_SWITCH","XX_CASE","XX_DEFAULT","XX_IF","XX_THEN",
"XX_ELSE_IF","XX_ELSE","XX_BEGIN","XX_END","XX_BEGIN_ATTR","XX_END_ATTR",
"XX_XMLNS_ATTR","XX_VARIABLE_ATTR","XX_EXPRESSION_ATTR","XX_ELEMENT_LITERAL",
"XX_ATTR_LITERAL","XX_TEXT_LITERAL","XX_INVALID",
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
"statement : switch_statement",
"statement : for_each_statement",
"statement : while_statement",
"statement : until_statement",
"statement : do_test_statement",
"statement : if_statement",
"statement : is_statement",
"statement : literal_statement",
"literal_statement : XX_ELEMENT_LITERAL literal_statement_body",
"literal_statement : text_literal",
"text_literal : XX_TEXT_LITERAL",
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
"switch_statement : XX_SWITCH test_case_statement",
"test_case_statement : test_expr case_statement_body",
"test_case_statement : test_case_body",
"case_statement_body : XX_BEGIN case_statement_list XX_END",
"test_case_body : XX_BEGIN test_statement case_statement_list XX_END",
"case_statement_list : case_statement case_statement_list",
"case_statement_list : case_statement",
"case_statement_list : default_statement",
"case_statement : XX_CASE test_do_statement",
"default_statement : XX_DEFAULT statement_body",
"test_do_statement : test_expr statement_body",
"test_do_statement : test_do_body",
"test_do_body : XX_BEGIN test_statement do_statement XX_END",
"do_statement : XX_DO statement_body",
"is_statement : XX_IS statement_body",
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
"literal_value_item : expression_value",
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
"expression_value : XX_EXPRESSION_ATTR",
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
case 51:
{ YY(OnTextLiteral) }
break;
case 148:
{OnBeginAttr();}
break;
case 149:
{OnEndAttr();}
break;
case 155:
{if ((m_error = OnLocationValue())) return m_error;}
break;
case 156:
{ if ((m_error = OnMethodValue())) return m_error; }
break;
case 157:
{ if ((m_error = OnNameValue())) return m_error; }
break;
case 158:
{ if ((m_error = OnMatchValue())) return m_error; }
break;
case 159:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 160:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 161:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 162:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 163:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 164:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 165:
{ if ((m_error = OnVariableExpression())) return m_error; }
break;
case 166:
{ if ((m_error = OnVariableExpression())) return m_error; }
break;
case 167:
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
