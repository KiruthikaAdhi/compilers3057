%{
	#include<stdio.h>
	#include"arith.c"
	void yyerror(const char* s);	
	int yylex(void);
%}
%token PLUS MINUS LP RP ASSIGN ID SC NUM MUL MOD DIV
%left MINUS PLUS 
%left MOD MUL DIV
%start S
%union{
	char* str;
	char* num;
	NODE* nodep;
}
%type<num> NUM
%type<str> ID
%type<nodep> E
%type<nodep> S
%%
S :
	E SC			   { 	printf("\nPost Order  : \n");
						postOrder($1);
					   }	
	|ID ASSIGN E SC    {	$$ = createNode("=",createNode($1,NULL,NULL),$3);
						printf("\nPost Order  : \n");
						postOrder($$);  							
					    }
	;
E : 
	E PLUS E		{ $$ = createNode("+",$1,$3);}
	| E MINUS E		{ $$ = createNode("-",$1,$3);}
	| E MUL E		{ $$ = createNode("*",$1,$3);}
	| E DIV E		{ $$ = createNode("/",$1,$3);}
	| E MOD E		{ $$ = createNode("%",$1,$3);}
	| LP E RP		{ $$ = $2;}
	| ID			        {$$ = createNode($1,NULL,NULL);}
	| NUM			{$$ = createNode($1,NULL,NULL);}
%%
void yyerror(const char* s){
	printf("Error oocurred : %s",s);
}
int main(){
	while(1){
		yyparse();
	}
}
