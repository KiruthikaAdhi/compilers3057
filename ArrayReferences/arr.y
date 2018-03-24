%{
	#include<stdio.h>
	#include"arr.c"
	NODE* t;
	int counter;
	void yyerror(const char* s);	
	int yylex(void);
%}
%token PLUS MINUS LB RB ASSIGN ID SC NUM MUL MOD DIV
%left MINUS PLUS 
%left MOD MUL DIV
%start S
%union{
	char* str;
	struct{
		char* addr;
		char* base;
		NODE* w;
		} array;
	char* addr;
}
%type<str> ID
%type<addr> E
%type<array> L
%%
S :
	ID ASSIGN E SC    {								
						printf("\n%s = %s\n" , $1,$3);
						return 1;
					    }
	|L ASSIGN E SC {
						printf("\n%s [ %s ] = %s\n",$1.base,$1.addr,$3);
						return 1;
					}
	;
E : 
	E PLUS E		{
						$$ = newTemp();
						printf("\n%s = %s + %s",$$,$1,$3);	
					}
	| ID				{ 
						$$ = $1;
					}
	| L				{ 
						$$ = newTemp();
						printf("\n%s = %s [ %s ] ",$$,$1.base,$1.addr);
					}				
	;
L :
	ID LB E RB		{
						$$.base = $1;
						$$.addr = newTemp();
						$$.w = t;
						printf("\n%s = %s * %d",$$.addr,$3,$$.w->width);
					}
	| L LB E RB		{
						$$.base = $1.base;				
						$$.w = $1.w->next;
						char* temp = newTemp();
						$$.addr = newTemp();
						printf("\n%s = %s * %d ",temp,$3,$$.w->width);
						printf("\n%s = %s + %s ",$$.addr,$1.addr,temp);
					}
	;

%%
void yyerror(const char* s){
	printf("Error oocurred : %s",s);
}
int main(){
	while(1){
		counter = 1;
		t = createArray(2);
		yyparse();
	}
}
