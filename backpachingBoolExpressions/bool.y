%{
	#include<stdio.h>
	void yyerror(const char* str);
	int yylex(void);
	int nextInstr;
%}
%token RELOP ID NUM TRUE FALSE NEG LAND LOR
%union{
	char* str;
	struct{
		LIST* truelist;
		LIST* falselist;
	} list;
	int instr;
}
%type<str> RELOP
%type<str> ID
%type<str> NUM
%type<str> E
%type<list> B
%type<instr> M
%left AND
%left OR
%right NEG
%start S

%%
S:
	B '$'	{return 1;}
	;
B:
	B LOR M B 
	| B LAND M B {
				backpatch($1.truelist,$3.instr);
				$$.truelist = $3.truelist;


			}
	| NEG B	  {
				$$.truelist = $1.falselist;
				$$.falselist = $1.truelist;			
			}
	| '(' B ')' {
				$$.truelist = $1.truelist;
				$$.falselist = $1.falselist;	
			}	 
	| E RELOP E {	char text[500];
				sprintf(text,"if %s %s %s goto__\n",$1,$2,$3);
				printf("if %s %s %s goto__\n",$1,$2,$3);
				$$.truelist = makelist(nextInstr);
				$$.truelist->text = text;
				nextInstr += 1;

				sprintf(text,"goto __\n");
				printf("goto __\n");
				$$.falselist = makelist(nextInstr);
				$$.falselist->text = text;
				nextInstr += 1;

			   }
	|TRUE 	   {
				char text[500];
				sprintf(text,"goto __\n");
				printf("goto__\n");
				$$.truelist = makelist(nextInstr);
				$$.truelist->text = text;
				nextInstr += 1;
			   }
	|FALSE  	   {
				char text[500];
				sprintf(text,"goto __\n");
				printf("goto__\n");
				$$.falselist = makelist(nextInstr);
				$$.falselist->text = text;
				nextInstr += 1;
			   
			   }
	;
M:
		{$$.instr = nextInstr ;}
	;

E:
	ID	{
			$$ =$1;

		}
	|NUM {
			$$ = $1;

		}
	;
%%

void yyerror(const char* s){
	printf("Error occur : %s",s);

}
int main(){
	while(1){
		nextInstr = 100;
		yyparse();
	}

}
