%{
#include<stdio.h>
#include "y.tab.h"
%}
IDENTIFIER [a-zA-Z][a-zA-Z0-9_]* 
CONST [0-9]+
%%
"for"   {
		return FOR;	
	}
"do"	{

		return DO;
	}
"while"	{
		return WHILE;
	}
[{}()]	{

		return *yytext;
	}
[;]	{

		return *yytext;
	}
[+-*/%=]{
		yylval.str = strdup(yytext);				
		return *yytext;			
	}
{IDENTIFIER}{
		yylval.str = strdup(yytext);		
		return ID;
	}
CONST	{
		yylval.str = strdup(yytext);		
		return CONSTANT;	
	}
[ \n\t]	;
"$"	{
		return *yytext;
	}
.	{
		ECHO;		
		printf("Invalid character\n");
	}
%%
int yywrap(void){
	return 0;
}

