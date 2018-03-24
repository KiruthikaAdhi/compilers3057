%{
#include <stdlib.h>
#include<string.h>
#include "y.tab.h"
void yyerror(char*);
%}

IDENTIFIER [a-zA-Z][a-zA-Z0-9_]* 
TYPE int|float|double|char|void

%%
{TYPE}(\*)?		 {	yylval.str = strdup(yytext);
					//printf(" type %s\n",yytext);
					return DTYPE;
				} 
{IDENTIFIER}	 {
					yylval.str = strdup(yytext);
					//printf(" id %s\n",yytext);
					return ID;
				}
[{] 				{
					//printf(" sop %s\n",yytext);
					return SBEGIN;
				} 
[}] 				{
					//printf(" scl %s\n",yytext);
					return SEND;
				}
[()] 				{
					//printf(" p %s\n",yytext);
					return *yytext;
				}
[,] 				{
					//printf(" c %s\n",yytext);
					return *yytext;
				}
[;] 				{
					//printf(" sc %s\n",yytext);
					return *yytext;
				}
[ \t\n]				
.				{
					printf("Invalid character %s",yytext);
				}  
%%
int yywrap(void){
	return 0;
}
/*int main(void){
	while(1){
		yylex();
	}
	return 0;
}*/
