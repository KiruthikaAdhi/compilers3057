#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define YYPREFIX "yy"
#line 2 "foc.y"
	#include<stdio.h>
	#include"foc.c"
	#include"arr.c"
	NODE* t;
	int counter;
	void yyerror(const char* str);
	int yylex(void);
	int nextInstr;
	int w;
	SYMTAB *st;
	QUAD instrArr[500];
#line 15 "foc.y"
typedef union{
	char* str;
	struct{
		LIST* truelist;
		LIST* falselist;
	} list;
	int instr;
	struct{
		char* addr;
		char* base;
		NODE* w;
		} array;
	char* addr;
	int width;
} YYSTYPE;
#line 45 "y.tab.c"
#define YYERRCODE 256
#define RELOP 257
#define ID 258
#define NUM 259
#define TRUE 260
#define FALSE 261
#define NEG 262
#define LAND 263
#define LOR 264
#define IF 265
#define ELSE 266
#define PLUS 267
#define MINUS 268
#define LB 269
#define RB 270
#define ASSIGN 271
#define SC 272
#define MUL 273
#define MOD 274
#define DIV 275
#define INT 276
#define FLOAT 277
const short yylhs[] = {                                        -1,
    0,    6,    6,    6,    7,    9,    9,   10,   10,   10,
   10,    4,    4,    4,    4,    5,    5,    2,    2,    2,
    2,    2,    2,    2,    3,    8,   11,   11,   12,   12,
    2,    2,    1,    1,
};
const short yylen[] = {                                         2,
    2,   10,    6,    1,    3,    2,    1,    2,    1,    4,
    4,    3,    1,    1,    1,    4,    4,    4,    4,    2,
    3,    3,    1,    1,    0,    0,    3,    2,    3,    1,
    1,    1,    4,    3,
};
const short yydefred[] = {                                      0,
    0,    0,    0,    0,    4,    0,    0,   14,   23,   24,
    0,   31,   32,    0,    0,    0,    0,    9,    0,    0,
    0,    1,    0,    0,    0,    0,    0,   20,    0,    0,
   25,   25,   28,    0,    0,    0,    0,    5,    6,    8,
   25,    0,    0,   21,    0,    0,   27,    0,    0,    0,
   12,    0,    0,    0,   16,   10,    0,    0,   29,   19,
    0,   17,   11,    0,    0,    0,   33,   25,    0,    2,
};
const short yydgoto[] = {                                       3,
   47,   15,   48,   16,   25,   18,    5,   66,   19,   20,
   21,   33,
};
const short yysindex[] = {                                   -122,
  -12,  -27,    0,    5,    0,  -16, -257,    0,    0,    0,
  -16,    0,    0,  -16, -225, -241, -215,    0,  -96,  -27,
 -228,    0, -212,   -9, -211, -206, -206,    0,    8,  -42,
    0,    0,    0, -206, -206, -206, -206,    0,    0,    0,
    0, -240, -224,    0, -200, -198,    0,  -16,  -16, -205,
    0, -230, -217,  -62,    0,    0, -207,   20,    0,    0,
 -197,    0,    0,    0, -204, -199,    0,    0,  -62,    0,
};
const short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0, -236,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -232,    0,    0,  -57,
    0,    0,   -5,    0,    6,    0,    0,    0,    0, -203,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -7,
    0,    0,    0,    0,    0,    0,    0, -203,    0,    0,
   10,    0,    0,  -36, -202,    0,    0,    0,    0,    0,
};
const short yygindex[] = {                                      0,
    7,   -3,  -26,  -17,    3,   71,  -47,    0,   53,    0,
    0,   28,
};
#define YYTABLESIZE 278
const short yytable[] = {                                       3,
    2,   46,   24,    3,   17,   49,   64,   28,   42,   43,
   29,   26,   14,   27,   54,   34,   50,   51,   52,   53,
   13,   70,   17,   14,   15,   35,   35,    6,   38,   55,
   13,   41,   30,   22,   15,   13,   35,   31,   32,   62,
   22,   69,   35,   40,   60,   61,   15,   56,   44,   35,
   18,   23,    8,   36,   63,   37,   26,   36,   57,   58,
    2,   35,   65,   46,   45,   31,   68,    7,   30,   34,
    4,   67,   39,   59,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    3,    0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    3,    3,    3,    3,   45,    0,    3,   26,
    7,    8,    9,   10,   11,    0,    0,    1,    0,    3,
    3,   23,    8,    9,   10,   11,    0,    0,   12,   13,
   22,   13,   13,   31,   32,   22,   22,   13,   13,   12,
   13,   13,   15,   15,   13,    0,   13,   18,   15,   15,
   31,   32,   15,   18,    0,   15,    0,   15,
};
const short yycheck[] = {                                      36,
  123,   44,    6,   40,    2,   32,   54,   11,   26,   27,
   14,  269,   40,  271,   41,  257,   34,   35,   36,   37,
  257,   69,   20,   40,  257,  267,  267,   40,  125,  270,
  267,   41,  258,   41,  267,   41,  267,  263,  264,  270,
   36,   68,  267,  272,   48,   49,   41,  272,   41,  267,
   41,  258,  259,  269,  272,  271,  269,  269,  259,  258,
  123,  267,  270,   44,  269,  263,  266,  125,  272,  272,
    0,   65,   20,   46,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,  260,  261,  262,  269,   -1,  265,  266,
  258,  259,  260,  261,  262,   -1,   -1,  265,   -1,  276,
  277,  258,  259,  260,  261,  262,   -1,   -1,  276,  277,
  258,  257,  258,  263,  264,  263,  264,  263,  264,  276,
  277,  267,  257,  258,  270,   -1,  272,  258,  263,  264,
  263,  264,  267,  264,   -1,  270,   -1,  272,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 277
#if YYDEBUG
const char * const yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'$'",0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"RELOP",
"ID","NUM","TRUE","FALSE","NEG","LAND","LOR","IF","ELSE","PLUS","MINUS","LB",
"RB","ASSIGN","SC","MUL","MOD","DIV","INT","FLOAT",
};
const char * const yyrule[] = {
"$accept : start",
"start : S '$'",
"S : IF '(' B ')' M BLOCK N ELSE M BLOCK",
"S : IF '(' B ')' M BLOCK",
"S : BLOCK",
"BLOCK : '{' LSTMT '}'",
"LSTMT : STMT LSTMT",
"LSTMT : STMT",
"STMT : T SC",
"STMT : S",
"STMT : ID ASSIGN E SC",
"STMT : L ASSIGN E SC",
"E : E PLUS E",
"E : ID",
"E : NUM",
"E : L",
"L : ID LB E RB",
"L : L LB E RB",
"B : B LOR M B",
"B : B LAND M B",
"B : NEG B",
"B : '(' B ')'",
"B : E RELOP E",
"B : TRUE",
"B : FALSE",
"M :",
"N :",
"T : B ID C",
"T : B IDLIST",
"IDLIST : ID ',' IDLIST",
"IDLIST : ID",
"B : INT",
"B : FLOAT",
"C : LB NUM RB C",
"C : LB NUM RB",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 318 "foc.y"

void yyerror(const char* s){
	printf("Error occur : %s",s);
	//return 0;
}
int main(){
	
	while(1){
		counter = 1;
		st = NULL;
		//t = createArray(10);
		nextInstr = 100;
		yyparse();
		int i = 100;
		printf("Label : op\targ1\targ2\tresult\n");
		for( ; i < nextInstr ; i++){
			printf("%d : %s\t%s\t%s\t%s\n",i,instrArr[i].op,instrArr[i].arg1,instrArr[i].arg2,instrArr[i].result);
		}
		printf("\n\n\n\n");
		//printSym(st);
	}

}
#line 282 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
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
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
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
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
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
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
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
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 47 "foc.y"
{return 1;}
break;
case 2:
#line 50 "foc.y"
{
	 				printf("In backpatch 1T %d\n",yyvsp[-5].instr);
	 				printf("In backpatch 1F %d\n",yyvsp[-1].instr);
	 				/*printf("%");*/
					/*backpatch($3.truelist,$5,instrArr);*/
					/*backpatch($3.falselist,$9,instrArr);*/
				}
break;
case 3:
#line 58 "foc.y"
{ 
	 				printf("In backpatch 2T %d\n",yyvsp[-1].instr);	    
					/*backpatch($3.truelist , $5,instrArr);			*/
				}
break;
case 10:
#line 74 "foc.y"
{	if(search(st,yyvsp[-3].str)==0){ 	
							char error[500];
							sprintf(error,"Undefined Identifier '%s'",yyvsp[-3].str);
							yyerror(error);
							exit(0);
						}								
						/*sprintf(instrArr[nextInstr],"%s = %s" , $1,$3);*/
						instrArr[nextInstr]=createQuad("=",yyvsp[-3].str,"\t",yyvsp[-1].addr);	
						nextInstr += 1;
			
					    }
break;
case 11:
#line 85 "foc.y"
{
						/*sprintf(instrArr[nextInstr],"%s [ %s ] = %s",$1.base,$1.addr,$3);*/
						char* temp = newTemp();
						instrArr[nextInstr]=createQuad("[]=",temp,yyvsp[-3].array.base,yyvsp[-3].array.addr);						
						nextInstr += 1;
						instrArr[nextInstr]=createQuad("=",temp,yyvsp[-1].addr,"  ");						
						nextInstr += 1;


					}
break;
case 12:
#line 97 "foc.y"
{
						yyval.addr = newTemp();
						/*sprintf(instrArr[nextInstr],"%s = %s + %s",$$,$1,$3);	*/
						instrArr[nextInstr]=createQuad("+",yyval.addr,yyvsp[-2].addr,yyvsp[0].addr);
						nextInstr += 1;
					}
break;
case 13:
#line 103 "foc.y"
{ 	/*printf("%s --->id\n",$1);*/
						/*SYMTAB* temp = getEntry(st,$1);*/
						/*printf("Inside Get Entry:\n ");*/
						if(search(st,yyvsp[0].str)==0){ 	
							char error[500];
							sprintf(error,"Undefined Identifier '%s'",yyvsp[0].str);
							yyerror(error);
							exit(0);
						}	
						yyval.addr = yyvsp[0].str;
					}
break;
case 14:
#line 114 "foc.y"
{
						yyval.addr = yyvsp[0].str;

					}
break;
case 15:
#line 118 "foc.y"
{ 	/*printf("In L");*/
						yyval.addr = newTemp();
						/*sprintf(instrArr[nextInstr],"%s = %s [ %s ] ",$$,$1.base,$1.addr);*/
						char* temp = newTemp();
						instrArr[nextInstr]=createQuad("=[]",temp,yyvsp[0].array.base,yyvsp[0].array.addr);
						nextInstr += 1;
						instrArr[nextInstr]=createQuad("=",yyval.addr,temp,"");
						nextInstr += 1;
					}
break;
case 16:
#line 129 "foc.y"
{
						yyval.array.base = yyvsp[-3].str;
						yyval.array.addr = newTemp();
						yyval.array.w = getEntry(st,yyvsp[-3].str);
						/*printf("Inside Get Entry:\n ");*/
						if(yyval.array.w == NULL){ 	
							char error[500];
							sprintf(error,"Undefined Identifier '%s'",yyvsp[-3].str);
							yyerror(error);
							exit(0);
						}
						/*printf("Outside Get Entry:\n ");*/
						yyval.array.w = yyval.array.w->next;
						/*printf("In L %s",$1);printDim($$.w);*/
						/*sprintf(instrArr[nextInstr],"%s = %s * %d",$$.addr,$3,$$.w->width);*/
						char width[50];sprintf(width,"%d",yyval.array.w->width);
						instrArr[nextInstr]=createQuad("*",yyval.array.addr,yyvsp[-1].addr,width);	

						nextInstr += 1;
					}
break;
case 17:
#line 149 "foc.y"
{
						yyval.array.base = yyvsp[-3].array.base;				
						yyval.array.w = yyvsp[-3].array.w->next;
						char* temp = newTemp();
						yyval.array.addr = newTemp();
						/*sprintf(instrArr[nextInstr],"%s = %s * %d ",temp,$3,$$.w->width);*/
						char width[50];sprintf(width,"%d",yyval.array.w->width);
						instrArr[nextInstr]=createQuad("*",temp,yyvsp[-1].addr,width);
						nextInstr += 1;
						/*sprintf(instrArr[nextInstr],"%s = %s + %s ",$$.addr,$1.addr,temp);*/
						instrArr[nextInstr] = createQuad("+",yyval.array.addr,yyvsp[-3].array.addr,temp);				
						nextInstr += 1;
					}
break;
case 18:
#line 166 "foc.y"
{
						/*backpatch($1.falselist , $3 , instrArr);*/
						/*printf("Before merge for or \n");	*/
						yyval.list.truelist = merge(yyvsp[-3].list.truelist,yyvsp[0].list.truelist);
						/*printf("After merge for or \n");*/
						yyval.list.falselist = yyvsp[0].list.falselist;
					}
break;
case 19:
#line 173 "foc.y"
{
				/*backpatch($1.truelist,$3,instrArr);*/
				yyval.list.truelist = yyvsp[0].list.truelist;
				yyval.list.falselist = merge(yyvsp[-3].list.falselist,yyvsp[0].list.falselist);

			}
break;
case 20:
#line 179 "foc.y"
{
				yyval.list.truelist = yyvsp[0].list.falselist;
				yyval.list.falselist = yyvsp[0].list.truelist;			
			}
break;
case 21:
#line 183 "foc.y"
{
				/*printf("In b paran \n");*/
				yyval.list.truelist = yyvsp[-1].list.truelist;
				yyval.list.falselist = yyvsp[-1].list.falselist;	
			}
break;
case 22:
#line 188 "foc.y"
{	/*char text[500];*/
				/*printf("ni ---> %d\n",nextInstr);*/
				/*printf("before : In relational op %s \n",instrArr[nextInstr]);*/
				
				/*sprintf(instrArr[nextInstr],"if %s %s %s goto ",$1,$2,$3);*/
				/*printf("if %s %s %s goto__\n",$1,$2,$3);*/
				char* temp = newTemp();
				instrArr[nextInstr] = createQuad(yyvsp[-1].str,temp,yyvsp[-2].addr,yyvsp[0].addr);
				nextInstr += 1;
				instrArr[nextInstr] = createQuad("if","\t",temp,"\t");
				
				yyval.list.truelist = makelist(nextInstr);
				/*$$.truelist->text = text;*/
				/*printf("After : In relational op %s \n",instrArr[nextInstr]);*/
				nextInstr += 1;
				
					
				/*sprintf(instrArr[nextInstr],"goto ");*/
				instrArr[nextInstr] = createQuad("goto","\t","\t","\t");
				/*printf("goto __\n");*/
				yyval.list.falselist = makelist(nextInstr);
				/*$$.falselist->text = text;*/
				nextInstr += 1;

			   }
break;
case 23:
#line 213 "foc.y"
{
				/*char text[500];*/
				/*sprintf(instrArr[nextInstr],"goto ");*/
				instrArr[nextInstr] = createQuad("goto","\t","\t","");	
				/*printf("goto__\n");*/
				yyval.list.truelist = makelist(nextInstr);
				/*$$.truelist->text = text;*/
				nextInstr += 1;
			   }
break;
case 24:
#line 222 "foc.y"
{
				/*char text[500];*/
				/*sprintf(instrArr[nextInstr],"goto ");*/
				instrArr[nextInstr] = createQuad("goto","\t","\t","");					
				/*printf("goto__\n");*/
				yyval.list.falselist = makelist(nextInstr);
				/*$$.falselist->text = text;*/
				nextInstr += 1;
			   
			   }
break;
case 25:
#line 234 "foc.y"
{yyval.instr = nextInstr ;}
break;
case 26:
#line 238 "foc.y"
{ 
			/*sprintf(instrArr[nextInstr],"goto ");*/
			instrArr[nextInstr] = createQuad("goto","\t","\t","");	
			nextInstr = nextInstr+1 ; 
		}
break;
case 27:
#line 245 "foc.y"
{ 	
				SYMTAB* temp = insertEntry(st,t,yyvsp[-1].str);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",yyvsp[-1].str);
							yyerror(error);
							exit(0);
				}
				st = temp;
				/*printDim(t);		*/
			}
break;
case 28:
#line 256 "foc.y"
{
				/*SYMTAB* temp = insertEntry(st,NULL,$2);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",$2);
							yyerror(error);
							exit(0);
				}
				st = temp;*/
			}
break;
case 29:
#line 268 "foc.y"
{
				SYMTAB* temp = insertEntry(st,NULL,yyvsp[-2].str);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",yyvsp[-2].str);
							yyerror(error);
							exit(0);
				}
				st = temp;
			}
break;
case 30:
#line 278 "foc.y"
{
				SYMTAB* temp = insertEntry(st,NULL,yyvsp[0].str);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",yyvsp[0].str);
							yyerror(error);
							exit(0);
				}
				st = temp;
			}
break;
case 31:
#line 290 "foc.y"
{w=4;}
break;
case 32:
#line 291 "foc.y"
{w=8;}
break;
case 33:
#line 294 "foc.y"
{
					 yyval.width = atoi(yyvsp[-2].str)*yyvsp[0].width;
					/*printf("dim->%d",$$);*/
					t = insert(t,yyval.width);		
				   }
break;
case 34:
#line 299 "foc.y"
{	t = NULL;
					t = insert(t,w);
					/*printf("dim->%d",$$);*/
					yyval.width = atoi(yyvsp[-1].str)*w;
					t = insert(t,yyval.width);
				}
break;
#line 783 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
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
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
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
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
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
