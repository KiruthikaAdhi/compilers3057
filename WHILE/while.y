%{
#include<stdio.h>
void yyerror(char*);
//int yylex(void);
char* s = "";
char* c = "";
char* i = "";
char* u = "";
char* b = "";
%}
%token FOR WHILE DO STMT ID CONSTANT;
%union{
	long l;
	char* str;
	int i;
}
%type<str> FOR
%type<str> WHILE
%type<str> DO
%type<str> STMT
%type<str> ID
%type<str> CONSTANT
%left '+' '-'
%left '*' '/' '%'

%%
s:
	loop '$'	{

				printf("Valid loop stmt\n");
				return 1;
			}
	;
loop:
	forLoop		{
				printf("%s\nwhile(%s)\n{\n\t%s\n\t%s\n}\n",i,c,b,u);				
				printf("For loop stmt\n");
			}
	|dowhileLoop	{
				printf("{\n%s\n}\nwhile(%s)\n{\n\t%s\n}\n",b,c,b);
				printf("do while loop stmt\n");
			}
	;
dowhileLoop:
	DO block WHILE '(' condition ')'';'	
	;
forLoop:
	FOR '(' initiation ';' condition ';' updation ')' block {

								}
	;

initiation :
	iustmt {
		i = $$;		
		printf("initiation stmt : %s\n",i);
		//s = "";
	     }
		
	;
condition :
	cstmt {
		c = $$;		
		printf("condition stmt : %s\n",c);
		//s = "";
	     }
	;	
updation :
	iustmt {
		u = $$;
		printf("updation stmt : %s\n",u);
		//s = "";
	     }
		
	;

block :
	'{' bstmt '}' {
			b = $$;			
			printf("block stmt : %s\n" , b);
			//s ="";	
		      }
	| ';'
	;
cstmt:
	expr
	;
iustmt : 
	expr	
	;
bstmt:
	expr		
	;
expr:
	ID		{$$ = $1;}
	|CONSTANT	{$$ = $1;}
	|expr '+' expr  {	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	|expr '-' expr	{	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	|expr '*' expr	{	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	|expr '/' expr	{	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	|expr '/' expr 	{	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	;
/*assignExpr:
	ID '=' CONSTANT {	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	|ID '=' ID 	{	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	|ID = expr	{	$$ = strcat($$,$1);
				$$ = strcat($$,$2);
				$$ = strcat($$,$3);
			}
	;
*/
%%
void yyerror(char* s){	
	printf("%s\n",s);
}
int main(void){
	while(1){		
		yyparse();
		printf("\n");	
	}

}
