#ifndef lint
static char yysccsid[] = "@(#)yaccpar 1.8++ (Berkeley) 01/20/90, (Boyd) 1998";
#endif
#define YYBYACC 1
#define YYCPLUSPLUS 1
#include "cxtlparser.hxx"

#define YY(on) if ((m_error = on())) return m_error
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
#define XX_NAME 267
#define XX_TEST 268
#define XX_SELECT 269
#define XX_MATCH 270
#define XX_FILE 271
#define XX_FTP 272
#define XX_HTTP 273
#define XX_SMTP 274
#define XX_LOCATION 275
#define XX_APPLY 276
#define XX_DO 277
#define XX_IS 278
#define XX_WHILE 279
#define XX_UNTIL 280
#define XX_REPEAT 281
#define XX_FOR 282
#define XX_FOR_EACH 283
#define XX_SWITCH 284
#define XX_CASE 285
#define XX_DEFAULT 286
#define XX_IF 287
#define XX_THEN 288
#define XX_ELSE_IF 289
#define XX_ELSE 290
#define XX_BEGIN 291
#define XX_END 292
#define XX_BEGIN_ATTR 293
#define XX_END_ATTR 294
#define XX_XMLNS_ATTR 295
#define XX_XMLNS_PREFIX_ATTR 296
#define XX_VARIABLE_ATTR 297
#define XX_EXPRESSION_ATTR 298
#define XX_ELEMENT_LITERAL 299
#define XX_ATTR_LITERAL 300
#define XX_COMMENT_LITERAL 301
#define XX_TEXT_LITERAL 302
#define XX_INVALID 303
#define YYERRCODE 256
short yyIsParser::yylhs[] = {                                        -1,
    0,    0,    2,    2,    1,    1,    4,    4,    5,    5,
    3,    3,    6,    8,    7,    7,   10,   10,   11,   11,
   11,   11,   13,   17,   18,   18,   18,   18,   19,   19,
   14,   14,   14,   25,   25,   28,   28,   29,   29,   30,
   30,   30,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   40,   40,   42,   41,   41,   31,   45,   45,
   45,   45,   45,   46,   46,   48,   48,   50,   50,   51,
   32,   32,   54,   54,   55,   55,   56,   53,   53,   34,
   57,   57,   35,   36,   33,   60,   60,   62,   63,   64,
   64,   64,   66,   67,   59,   59,   68,   58,   39,   37,
   37,   69,   69,   72,   70,   70,   75,   73,   73,   38,
   38,   38,   38,   38,   38,   80,   65,   81,   81,   79,
   79,   82,   78,   78,   83,   83,   84,   44,   44,   85,
   85,   86,   86,   87,   87,   15,   16,   52,   52,   20,
   21,   22,   23,   24,   26,   27,   76,   77,   74,   71,
   61,   47,   49,   43,  100,  102,  101,  101,  103,  103,
  103,  103,  103,   88,   89,   90,   91,    9,   92,   93,
   98,   97,   94,   99,   95,   96,  104,  105,  106,  107,
  108,
};
short yyIsParser::yylen[] = {                                         2,
    3,    2,    3,    2,    3,    2,    2,    1,    1,    1,
    2,    1,    4,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    2,    2,    1,    1,    1,    1,    3,    2,
    3,    3,    3,    3,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    1,    1,    2,    1,    2,    2,    2,
    2,    2,    1,    4,    3,    3,    2,    2,    1,    2,
    2,    2,    2,    3,    2,    1,    4,    3,    1,    2,
    2,    4,    2,    2,    2,    2,    1,    3,    4,    2,
    1,    1,    2,    2,    2,    1,    4,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    3,    1,    4,
    5,    4,    5,    4,    3,    2,    2,    3,    1,    2,
    1,    2,    3,    2,    2,    1,    4,    3,    2,    2,
    1,    1,    1,    1,    1,    2,    2,    3,    2,    3,
    3,    3,    3,    4,    3,    3,    5,    4,    3,    3,
    3,    4,    3,    3,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
short yyIsParser::yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,   55,    0,    0,   12,    0,   17,   18,   19,
   20,   21,   22,   43,   44,   45,   46,   47,   48,   49,
   50,   51,   52,   54,    6,    9,   10,    0,    0,    1,
    0,   23,    0,   25,   26,   27,   28,    0,    0,    0,
    0,    0,    0,    0,  137,  136,    0,    0,    0,    0,
    0,    0,   79,   71,   72,    0,    0,    0,   58,   63,
    0,    0,    0,    0,    0,  100,  101,    0,    0,   99,
    0,    0,   83,    0,   96,   84,    0,    0,    0,   80,
    0,   85,    0,   87,    0,    0,    0,    0,    0,  155,
   53,    0,   57,    0,    3,   11,   15,    5,    7,  165,
  166,  167,  164,    0,    0,    0,    0,    0,    0,   24,
  169,  170,    0,    0,    0,   31,   32,   33,    0,  139,
    0,  168,    0,    0,    0,  129,  133,  134,  135,    0,
    0,    0,    0,  132,    0,    0,   73,    0,  174,    0,
    0,   59,   61,    0,   60,   62,  171,  172,    0,    0,
    0,    0,  103,  106,  102,  105,    0,    0,  173,    0,
   95,    0,   81,    0,    0,   86,    0,    0,    0,    0,
  115,    0,    0,   56,  180,  181,  178,  177,  179,    0,
    0,  159,  160,  161,  162,  163,  140,  141,  142,  143,
   30,    0,  145,    0,  146,   35,   39,   40,   41,   42,
    0,    0,   38,    0,  138,   14,   13,    0,    0,   74,
   75,  128,  130,   78,    0,   65,    0,    0,  153,   67,
    0,  149,  150,  109,    0,  104,  107,  119,    0,  117,
    0,    0,  151,    0,    0,    0,    0,    0,   92,    0,
    0,  116,    0,  114,  175,    0,    0,  110,    0,    0,
  112,    0,    0,    0,  156,  154,  157,   29,  144,   34,
   36,  152,    0,   70,   64,   68,   66,    0,    0,   98,
   97,   82,   93,   94,   89,   90,   88,  122,  120,  176,
  148,    0,  113,    0,  124,  111,    0,  125,   77,  108,
  118,  147,    0,  123,  127,
};
short yyIsParser::yydgoto[] = {                                       2,
    5,    6,   24,   48,   49,   25,   26,   68,  143,   27,
   28,  147,   30,  148,   32,  149,   52,   53,  130,   54,
   55,   56,   57,   59,  136,   63,   61,  221,  222,  223,
   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,
  111,   44,  112,  244,   79,   80,   64,  163,   82,  241,
  238,   65,   74,   75,  150,  151,  100,  252,   93,  102,
   94,  186,  104,  257,  178,  258,  259,   95,   86,   87,
   88,  173,  246,   89,  174,  108,  109,  272,  262,  188,
  250,  263,  273,  274,  152,  153,  154,  124,  125,  126,
  127,  139,  134,  180,  266,  302,  169,  170,  160,  114,
  200,  276,  201,  202,  203,  204,  205,  206,
};
short yyIsParser::yysindex[] = {                                   -237,
 -168,    0, -213, -204, -259,    0, -231, -224, -220, -220,
 -175, -148, -143, -140, -236, -131, -131, -130, -127, -122,
    0, -107,    0, -250, -163,    0, -163,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -172, -211,    0,
 -214,    0, -241,    0,    0,    0,    0, -192, -156, -156,
 -156, -120, -236, -151,    0,    0,  -83, -103, -102, -192,
  -93, -236,    0,    0,    0,  -64,  -80,  -85,    0,    0,
  -84,  -84,  -14, -171, -125,    0,    0, -236, -236,    0,
  -60,  -59,    0, -236,    0,    0,  -64,  -53, -236,    0,
  -60,    0,  -81,    0,  -60,  -59,  -74,  -71,  -70,    0,
    0, -236,    0, -193,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -62,  -61,  -58,  -56,  -63,  -67,    0,
    0,    0, -251,  -54, -150,    0,    0,    0, -249,    0,
  -57,    0,  -52,  -51,  -50,    0,    0,    0,    0,  -44,
  -40,  -42,   42,    0,  -43,  -39,    0, -239,    0,  -38,
 -246,    0,    0, -238,    0,    0,    0,    0,  -37,  -35,
 -100, -100,    0,    0,    0,    0,  -99,  -25,    0,  -34,
    0,  -25,    0, -154, -154,    0,  -27,  -24, -267,  -65,
    0,  -21, -209,    0,    0,    0,    0,    0,    0,  -22,
 -193,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -13,    0,  -17,    0,    0,    0,    0,    0,    0,
  -11,   14,    0,   -8,    0,    0,    0,   -3,   -4,    0,
    0,    0,    0,    0, -220,    0,    4,   17,    0,    0,
    7,    0,    0,    0,   -2,    0,    0,    0,   13,    0,
 -236,    8,    0,   15, -131, -236,   16, -154,    0,   18,
 -236,    0, -117,    0,    0, -253,   20,    0,   12, -236,
    0,   22,   -6,   26,    0,    0,    0,    0,    0,    0,
    0,    0,   25,    0,    0,    0,    0,   31,   32,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   33,    0,   37,    0,    0, -236,    0,    0,    0,
    0,    0,   38,    0,    0,
};
short yyIsParser::yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   41,    0,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,    0,    0,
    0,    0,   50,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
short yyIsParser::yygindex[] = {                                    229,
    0,  301,    0,  283,    0,    0,  174,    0,    0,    0,
    0,    3,    0,    6, -121,    9,    0,    0,    0,    0,
    0,    0,    0,    0,  119,   27,    1,  114,    0,    0,
    0,  -68,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -12,    0,  265,  332,  121,   -7, -142,
    0,   -9,    0,    0,  195,    0,    0,  165,  -10,    0,
  -15,    0,    0, -170,  -33,    0,    0,    0,    0,    0,
    0,    0,  176,    0,    0,    0,    0,   86,  160,    0,
    0,    0,   77,    0,  199,    0,    0,    0,    0,    0,
    0,  -32,  220,  248,    0,    0,    0,    0,  216,    0,
  155,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 356
short yyIsParser::yytable[] = {                                      73,
   66,   85,   90,  103,  107,   29,   96,  158,   31,  113,
   99,   33,   72,  219,  260,  237,  235,    1,  132,  159,
  265,    1,   12,  235,  235,  133,  253,   29,  182,   29,
   31,    3,   31,   33,   60,   33,  300,  155,   71,   78,
  301,  115,  213,    7,  213,  240,    8,    9,   10,  128,
  140,   11,  236,  240,   83,   12,  120,  121,  122,  157,
  123,   51,   13,   14,   15,   16,   17,  184,   58,   18,
   19,  187,   62,   20,  131,  175,  176,  132,   21,  269,
  270,  181,  271,   46,   47,   22,  183,  296,   23,   45,
   46,   47,  158,    7,  191,  286,    8,    9,   10,  194,
  219,  195,  196,  197,  198,   12,  199,  167,  168,    8,
    9,   10,   13,   14,   15,   16,   17,   67,   12,   18,
   19,  118,    3,   20,    4,   13,   14,   15,   16,   17,
  255,  256,   18,   19,  135,   22,   20,  217,   23,  141,
  218,  216,   69,  220,   70,  229,  131,   76,   22,   77,
   83,   23,   84,  171,  172,  245,  245,    8,    9,   91,
   97,   92,   98,  101,  248,   92,   12,  145,  105,  249,
  106,  269,  270,   13,   14,   15,   16,   17,  137,  138,
   18,   19,  142,   83,   20,  110,  131,  144,  159,  146,
   83,   83,   92,   98,    8,    9,   22,  156,  116,   23,
  117,  165,  166,   12,   12,  161,  164,  177,  179,  185,
   13,   14,   15,   16,   17,  159,  190,   18,   19,  192,
  193,   20,  261,  212,  217,  284,  146,  218,  211,  145,
  220,  207,  208,   22,  225,  209,   23,  210,  290,  215,
  227,  226,  228,  294,  293,    8,    9,  230,  298,  232,
  213,  251,  234,  304,   12,  239,  242,  305,  243,  253,
  261,   13,   14,   15,   16,   17,  132,  264,   18,   19,
  268,  275,   20,    8,    9,   10,  279,  146,  278,  235,
  280,  129,   12,  307,   22,  282,  283,   23,  288,   13,
   14,   15,   16,   17,  314,  285,   18,   19,  287,  291,
   20,    8,    9,  289,   92,   50,  292,  295,  126,  297,
   12,  303,   22,  306,  269,   23,  309,   13,   14,   15,
   16,   17,  310,  311,   18,   19,  312,  313,   20,  315,
   16,  119,   76,    8,  131,  281,   37,  158,   69,   91,
   22,  121,  162,   23,   81,  231,  254,  247,  299,  267,
  308,  233,  214,  189,  224,  277,
};
short yyIsParser::yycheck[] = {                                      12,
   10,   14,   15,   19,   20,    3,   17,   76,    3,   22,
   18,    3,   12,  135,  185,  158,  263,  259,  270,  269,
  288,  259,  269,  263,  263,   58,  294,   25,   97,   27,
   25,  291,   27,   25,    8,   27,  290,   70,   12,   13,
  294,  292,  294,  257,  294,  292,  260,  261,  262,  291,
   63,  265,  292,  292,  291,  269,  271,  272,  273,   72,
  275,  293,  276,  277,  278,  279,  280,  101,  293,  283,
  284,  105,  293,  287,  267,   88,   89,  270,  292,  289,
  290,   94,  292,  295,  296,  299,   99,  258,  302,  294,
  295,  296,  161,  257,  107,  238,  260,  261,  262,  112,
  222,  295,  296,  297,  298,  269,  300,  279,  280,  260,
  261,  262,  276,  277,  278,  279,  280,  293,  269,  283,
  284,  294,  291,  287,  293,  276,  277,  278,  279,  280,
  285,  286,  283,  284,  291,  299,  287,  135,  302,  291,
  135,  292,  291,  135,  293,  145,  267,  291,  299,  293,
  291,  302,  293,  279,  280,  171,  172,  260,  261,  291,
  291,  293,  293,  291,  177,  293,  269,  270,  291,  177,
  293,  289,  290,  276,  277,  278,  279,  280,   60,   61,
  283,  284,  266,  291,  287,  293,  267,  291,  269,  292,
  291,  291,  293,  293,  260,  261,  299,  291,   25,  302,
   27,   81,   82,  269,  269,  291,  291,  268,  268,  291,
  276,  277,  278,  279,  280,  269,  291,  283,  284,  291,
  291,  287,  288,  291,  222,  235,  292,  222,  292,  270,
  222,  294,  294,  299,  292,  294,  302,  294,  251,  294,
  292,  294,  293,  256,  255,  260,  261,  292,  261,  292,
  294,  277,  292,  269,  269,  294,  294,  270,  294,  294,
  288,  276,  277,  278,  279,  280,  270,  292,  283,  284,
  292,  294,  287,  260,  261,  262,  294,  292,  292,  263,
  292,   53,  269,  290,  299,  294,  291,  302,  291,  276,
  277,  278,  279,  280,  307,  292,  283,  284,  292,  292,
  287,  260,  261,  291,  293,    5,  292,  292,  290,  292,
  269,  292,  299,  292,  289,  302,  292,  276,  277,  278,
  279,  280,  292,  292,  283,  284,  294,  291,  287,  292,
  292,   49,  292,  294,  292,  222,  292,  294,  292,  292,
  299,  292,   78,  302,   13,  151,  182,  172,  263,  190,
  274,  153,  133,  106,  139,  201,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
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
"XX_OUTPUT","XX_METHOD","XX_NAME","XX_TEST","XX_SELECT","XX_MATCH","XX_FILE",
"XX_FTP","XX_HTTP","XX_SMTP","XX_LOCATION","XX_APPLY","XX_DO","XX_IS",
"XX_WHILE","XX_UNTIL","XX_REPEAT","XX_FOR","XX_FOR_EACH","XX_SWITCH","XX_CASE",
"XX_DEFAULT","XX_IF","XX_THEN","XX_ELSE_IF","XX_ELSE","XX_BEGIN","XX_END",
"XX_BEGIN_ATTR","XX_END_ATTR","XX_XMLNS_ATTR","XX_XMLNS_PREFIX_ATTR",
"XX_VARIABLE_ATTR","XX_EXPRESSION_ATTR","XX_ELEMENT_LITERAL","XX_ATTR_LITERAL",
"XX_COMMENT_LITERAL","XX_TEXT_LITERAL","XX_INVALID",
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
"transform_attr : XX_XMLNS_PREFIX_ATTR",
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
"include_location : file_expr",
"include_location : ftp_expr",
"include_location : http_expr",
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
"file_expr : XX_BEGIN_ATTR file_value XX_END_ATTR",
"ftp_expr : XX_BEGIN_ATTR ftp_value XX_END_ATTR",
"http_expr : XX_BEGIN_ATTR http_value XX_END_ATTR",
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
"literal_value_item : xmlns_value",
"literal_value_item : xmlns_prefix_value",
"location_value : XX_LOCATION",
"file_value : XX_FILE",
"ftp_value : XX_FTP",
"http_value : XX_HTTP",
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
"xmlns_value : XX_XMLNS_ATTR",
"xmlns_prefix_value : XX_XMLNS_PREFIX_ATTR",
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
{ YY(OnXmlnsAttr); }
break;
case 10:
{ YY(OnXmlnsPrefixAttr); }
break;
case 25:
{YY(OnIncludeLocation);}
break;
case 26:
{YY(OnIncludeFile);}
break;
case 27:
{YY(OnIncludeFTP);}
break;
case 28:
{YY(OnIncludeHTTP);}
break;
case 55:
{ YY(OnTextLiteral); }
break;
case 155:
{OnBeginAttr();}
break;
case 156:
{OnEndAttr();}
break;
case 164:
{YY(OnLocationValue);}
break;
case 165:
{YY(OnFileValue);}
break;
case 166:
{YY(OnFTPValue);}
break;
case 167:
{YY(OnHTTPValue);}
break;
case 168:
{ YY(OnMethodValue); }
break;
case 169:
{ YY(OnNameValue); }
break;
case 170:
{ YY(OnMatchValue); }
break;
case 171:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 172:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 173:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 174:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 175:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 176:
{ if ((m_error = OnExpression())) return m_error; }
break;
case 177:
{ if ((m_error = OnVariableExpression())) return m_error; }
break;
case 178:
{ if ((m_error = OnVariableExpression())) return m_error; }
break;
case 179:
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
