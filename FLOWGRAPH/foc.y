%{
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

%}
%token RELOP ID NUM TRUE FALSE NEG LAND LOR IF ELSE  PLUS MINUS LB RB ASSIGN  SC MUL MOD DIV INT FLOAT WHILE
%union{
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
	LIST* nextlist;
}
%type<width> C
%type<str> RELOP
%type<str> ID
%type<str> NUM
%type<list> B
%type<instr> M
%type<addr> E
%type<array> L
%type<nextlist> N
%type<nextlist> STMT
%type<nextlist> LSTMT
%type<nextlist> BLOCK
%type<nextlist> S
%left MINUS PLUS 
%left MOD MUL DIV
%left LOR
%left LAND
%right NEG
%start start

%%
start:
	S '$'	{return 1;}
	;
S:
	 IF '(' B ')' M BLOCK N ELSE M BLOCK {
	 				//printf("In backpatch 1T %d\n",$5);
	 				//printf("In backpatch 1F %d\n",$9);
	 				//printf("%");
					backpatch($3.truelist,$5);
					backpatch($3.falselist,$9);
					LIST* temp=merge($6,$7);
					$$=merge(temp,$10);
				}

	| IF '(' B ')' M BLOCK { 
	 				//printf("In backpatch 2T %d\n",$5);	    
					backpatch($3.truelist , $5);		
					$$=merge($3.falselist,$6);	
				}
	| WHILE M '(' B ')' M BLOCK{
					backpatch($7,$2);
					backpatch($4.truelist,$6);
					$$ = $4.falselist;
					char* label = (char*)malloc(sizeof(char)*5);
					sprintf(label,"%d",$2);
					instrArr[nextInstr]=createQuad("goto",label," "," ");						
					nextInstr += 1;								
				}
	|BLOCK		{$$=$1;}
	;
BLOCK:
	 '{' LSTMT '}'  { $$=$2;}
	;	
LSTMT: 
	LSTMT M STMT {
						backpatch($1,$2);
						$$=$3;			
					}
	| STMT			{
						$$=$1;
					}
	;
STMT :
	T SC				{$$=NULL;}
	|S 					{$$=$1;}	
	| ID ASSIGN E SC    {	if(search(st,$1)==0){ 	
							char error[500];
							sprintf(error,"Undefined Identifier '%s'",$1);
							yyerror(error);
							exit(0);
						}								
						//sprintf(instrArr[nextInstr],"%s = %s" , $1,$3);
						instrArr[nextInstr]=createQuad("=",$1,"",$3);	
						nextInstr += 1;
						$$=NULL;
					    }
	|L ASSIGN E SC {
						//sprintf(instrArr[nextInstr],"%s [ %s ] = %s",$1.base,$1.addr,$3);
						char* temp = newTemp();
						instrArr[nextInstr]=createQuad("[]=",temp,$1.base,$1.addr);						
						nextInstr += 1;
						instrArr[nextInstr]=createQuad("=",temp,$3,"  ");						
						nextInstr += 1;
						$$=NULL;

					}
	;
E : 
	E PLUS E		{
						$$ = newTemp();
						//sprintf(instrArr[nextInstr],"%s = %s + %s",$$,$1,$3);	
						instrArr[nextInstr]=createQuad("+",$$,$1,$3);
						nextInstr += 1;
					}
	|E MINUS E		{
						$$ = newTemp();
						//sprintf(instrArr[nextInstr],"%s = %s + %s",$$,$1,$3);	
						instrArr[nextInstr]=createQuad("-",$$,$1,$3);
						nextInstr += 1;
					}
	| ID				{ 	//printf("%s --->id\n",$1);
						//SYMTAB* temp = getEntry(st,$1);
						//printf("Inside Get Entry:\n ");
						if(search(st,$1)==0){ 	
							char error[500];
							sprintf(error,"Undefined Identifier '%s'",$1);
							yyerror(error);
							exit(0);
						}	
						$$ = $1;
					}
	|NUM 			{
						$$ = $1;

					}
	| L				{ 	//printf("In L");
						$$ = newTemp();
						//sprintf(instrArr[nextInstr],"%s = %s [ %s ] ",$$,$1.base,$1.addr);
						char* temp = newTemp();
						instrArr[nextInstr]=createQuad("=[]",temp,$1.base,$1.addr);
						nextInstr += 1;
						instrArr[nextInstr]=createQuad("=",$$,temp,"");
						nextInstr += 1;
					}				
	;
L :
	ID LB E RB		{
						$$.base = $1;
						$$.addr = newTemp();
						$$.w = getEntry(st,$1);
						//printf("Inside Get Entry:\n ");
						if($$.w == NULL){ 	
							char error[500];
							sprintf(error,"Undefined Identifier '%s'",$1);
							yyerror(error);
							exit(0);
						}
						//printf("Outside Get Entry:\n ");
						$$.w = $$.w->next;
						//printf("In L %s",$1);printDim($$.w);
						//sprintf(instrArr[nextInstr],"%s = %s * %d",$$.addr,$3,$$.w->width);
						char* width = (char*)malloc(sizeof(char)*5);
						sprintf(width,"%d",$$.w->width);
						printf("width-->%s\n",width);	
						instrArr[nextInstr]=createQuad("*",$$.addr,$3,width);	

						nextInstr += 1;
					}
	| L LB E RB		{
						$$.base = $1.base;				
						$$.w = $1.w->next;
						char* temp = newTemp();
						$$.addr = newTemp();
						//sprintf(instrArr[nextInstr],"%s = %s * %d ",temp,$3,$$.w->width);
						char width[50];sprintf(width,"%d",$$.w->width);
						instrArr[nextInstr]=createQuad("*",temp,$3,width);
						nextInstr += 1;
						//sprintf(instrArr[nextInstr],"%s = %s + %s ",$$.addr,$1.addr,temp);
						instrArr[nextInstr] = createQuad("+",$$.addr,$1.addr,temp);				
						nextInstr += 1;
					}
	;

	
B:
	B LOR M B 		{
						backpatch($1.falselist , $3 );
						//printf("Before merge for or \n");	
						$$.truelist = merge($1.truelist,$4.truelist);
						//printf("After merge for or \n");
						$$.falselist = $4.falselist;
					}
	| B LAND M B {
				backpatch($1.truelist,$3);
				$$.truelist = $4.truelist;
				$$.falselist = merge($1.falselist,$4.falselist);

			}
	| NEG B	  {
				$$.truelist = $2.falselist;
				$$.falselist = $2.truelist;			
			}
	| '(' B ')' {
				//printf("In b paran \n");
				$$.truelist = $2.truelist;
				$$.falselist = $2.falselist;	
			}	 
	| E RELOP E {	//char text[500];
				//printf("ni ---> %d\n",nextInstr);
				//printf("before : In relational op %s \n",instrArr[nextInstr]);
				
				//sprintf(instrArr[nextInstr],"if %s %s %s goto ",$1,$2,$3);
				//printf("if %s %s %s goto__\n",$1,$2,$3);
				char* temp = newTemp();
				instrArr[nextInstr] = createQuad($2,temp,$1,$3);
				nextInstr += 1;
				instrArr[nextInstr] = createQuad("if","",temp,"  ");
				
				$$.truelist = makelist(nextInstr);
				//$$.truelist->text = text;
				//printf("After : In relational op %s \n",instrArr[nextInstr]);
				nextInstr += 1;
				
					
				//sprintf(instrArr[nextInstr],"goto ");
				instrArr[nextInstr] = createQuad("goto","  "," "," ");
				//printf("goto __\n");
				$$.falselist = makelist(nextInstr);
				//$$.falselist->text = text;
				nextInstr += 1;

			   }
	|TRUE 	   {
				//char text[500];
				//sprintf(instrArr[nextInstr],"goto ");
				instrArr[nextInstr] = createQuad("goto"," "," ","");	
				//printf("goto__\n");
				$$.truelist = makelist(nextInstr);
				//$$.truelist->text = text;
				nextInstr += 1;
			   }
	|FALSE  	   {
				//char text[500];
				//sprintf(instrArr[nextInstr],"goto ");
				instrArr[nextInstr] = createQuad("goto"," ","","");					
				//printf("goto__\n");
				$$.falselist = makelist(nextInstr);
				//$$.falselist->text = text;
				nextInstr += 1;
			   
			   }
	;
M:
		{$$ = nextInstr ;}
	;

N:
		{ 
			//sprintf(instrArr[nextInstr],"goto ");
			instrArr[nextInstr] = createQuad("goto"," "," ","");	
			$$ = makelist(nextInstr);
			nextInstr = nextInstr+1 ; 
		}
	;
T:
	B ID C	{ 	
				SYMTAB* temp = insertEntry(st,t,$2);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",$2);
							yyerror(error);
							exit(0);
				}
				st = temp;
				//printDim(t);		
			}
	|B IDLIST  	{
				/*SYMTAB* temp = insertEntry(st,NULL,$2);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",$2);
							yyerror(error);
							exit(0);
				}
				st = temp;*/
			}
	;
IDLIST:
	ID ',' IDLIST {
				SYMTAB* temp = insertEntry(st,NULL,$1);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",$1);
							yyerror(error);
							exit(0);
				}
				st = temp;
			}
	|ID 	{
				SYMTAB* temp = insertEntry(st,NULL,$1);
				if(temp == NULL){
							char error[500];
							sprintf(error,"Redeclared Identifier : '%s' ",$1);
							yyerror(error);
							exit(0);
				}
				st = temp;
			}
	;
B:
	INT {w=4;}
	| FLOAT{w=8;}
	;
C:
	LB NUM RB C {
					 $$ = atoi($2)*$4;
					//printf("dim->%d",$$);
					t = insert(t,$$);		
				   }
	|LB NUM RB   {	t = NULL;
					t = insert(t,w);
					//printf("dim->%d",$$);
					$$ = atoi($2)*w;
					t = insert(t,$$);
				}	
	;

/*E:
	ID	{
			$$ =$1;

		}
	|NUM {
			$$ = $1;

		}
	;*/
%%

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
			printf("%d : [%s]\t[%s]\t[%s]\t[%s]\n",i,instrArr[i].op,instrArr[i].arg1,instrArr[i].arg2,instrArr[i].result);
		}
		BB* bb=constructBB(100,nextInstr-1);
		GRAPH fg = constructFlowGraph(bb);
		print(fg);
		printf("\n\n\n\n");
		//printSym(st);
	}

}
