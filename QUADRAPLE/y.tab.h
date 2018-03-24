#ifndef YYERRCODE
#define YYERRCODE 256
#endif

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
extern YYSTYPE yylval;
