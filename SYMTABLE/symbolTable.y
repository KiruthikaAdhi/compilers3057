%{
	#include<stdio.h>
	#include<string.h>
	#include "symtab.c"
	int yylex(void);
	void yyerror(char*);
	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
	typedef struct{
		char* arr[10];
		int size;
	}VAR;
	VAR v;
	SYMBOL* ST[100]={NULL};
	STACK* stk;
%}
%token ID  DTYPE SBEGIN SEND
%start s
%union {
        long int4;              
        float fp;               
        char *str;            
    };
%type <str> DTYPE
%type <str> ID
%%
s :
	SBEGIN	{
					//SYMBOL* symTab[100]={NULL};
					//printf("symbol table address %d",symTab);
					push(stk);
					//printf("Push a symbol Table\n");
					return 1;	
				}
	
	|SEND	     {
					//printf("Pop a symbol Table");
					//printf("Before pop : %d \n",stk->top);
					printf("Symbol table:\n");
					print(stk->symTab[stk->top]);
					pop(stk);
					//printf("After pop : %d \n",stk->top);
					//print(stk->symTab[stk->top]);						
					return 1;		
				}
	|vardecl	{	
					//printf("Insert a var decl");
					return 1;
				}
	|funcdecl   {
					//printf("Insert a func decl");
					return 1;
				}
	;
vardecl:
	DTYPE idlist ';' {	int i = 0;
					for(;i<v.size;i++){				
						SYMBOL *s = (SYMBOL*)malloc(sizeof(SYMBOL));
						strcpy(s->type,$1);
						strcpy(s->name,v.arr[i]);
						s->next = NULL;
						//printf("top index -> %d",stk->top);							
						if(insert(stk->symTab[stk->top],s)==false) {printf("Redeclaration of %s",v.arr[i]);}
						//else print(stk->symTab[stk->top]);	
					}
				}
	;
idlist:
	ID','idlist	{v.arr[v.size] = $1 ;v.size++;}
	|ID			{v.arr[v.size] = $1 ;v.size++;}
	;

funcdecl:
	DTYPE ID op pardecl cl';' {
									SYMBOL *s = (SYMBOL*)malloc(sizeof(SYMBOL));
									strcpy(s->type,$1);
									strcpy(s->name,$2);
									s->next = NULL;
									//printf("Before func insert %d\n",stk->top);	
									//print(stk->symTab[stk->top]);			
									if(insert(stk->symTab[stk->top],s)==false) {printf("Redeclaration of %s",$2);}
									//printf("After func insert \n%d\n",stk->top);
									//print(stk->symTab[stk->top]);
							}
	|DTYPE ID '(' ')' ';'		 {
									SYMBOL *s = (SYMBOL*)malloc(sizeof(SYMBOL));
									strcpy(s->type,$1);
									strcpy(s->name,$2);
									s->next = NULL;
									//printf("Before func insert %d\n",stk->top);	
									//print(stk->symTab[stk->top]);								
									if(insert(stk->symTab[stk->top],s)==false) {printf("Redeclaration of %s",$2);}
									//printf("After func insert %d\n",stk->top);
									//print(stk->symTab[stk->top]);
							}
	;
op:
	'(' { 
				SYMBOL* symTab[100]={NULL};
				//printf("symbol table address %d",symTab);				
				push(stk);
				//printf("Push 0f a symbol Table\n");
									
		}
	;
cl:
	')' {
					//printf("Pop 0f a symbol Table\n");
					printf("Symbol table:\n");	
					print(stk->symTab[stk->top]);					
					//printf("Before pop %d\n",stk->top);				
					pop(stk);
					//printf("After pop %d\n",stk->top);
		}
	;
pardecl:
	par ',' pardecl  {
					//printf("Insert a par decl\n");
				     }
	|par		    {
					//printf("Insert a par decl\n");
				    }
	;
par:
	DTYPE ID	{
						SYMBOL *s = (SYMBOL*)malloc(sizeof(SYMBOL));
						strcpy(s->type,$1);
						strcpy(s->name,$2);
						s->next = NULL;
						//printf("Before par insert %d \n",stk->top);
						if(insert(stk->symTab[stk->top],s)==false) {printf("Redeclaration of %s",$2);}
						//printf("After par insert %d \n",stk->top);
						//print(stk->symTab[stk->top]);	
						
				}
	;
	
%%

void yyerror(char *s){
	printf("%s %d\n",s,yylineno);

}
int main(void){
	yyin = fopen("decl.txt", "r");
	stk = initialise();
	while(1){
		v.size = 0;
		yyparse();
		//printf("Hi\n");
	}
	return 0;
} 
