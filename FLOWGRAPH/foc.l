%{
#include<stdio.h>
#include<string.h>
#include "arr.h"
#include"foc.h"
#include "y.tab.h"
int yywrap(void);
%}

%%
"int" {return INT;}
"float" {return FLOAT;}
[\[] {
		//ECHO;
		return LB;
	}
[\]] {		
		//ECHO;
		return RB;
	}
>|<|!=|== { 

            //printf("relop->%s\n",yytext);
			yylval.str = strdup(yytext);
			return RELOP;
		  }
[()]    { 
            //printf("para->%s\n",yytext);                
            return *yytext;
        }
[{}]    { 
            //printf("para->%s\n",yytext);                
            return *yytext;
        }

!       {
            //printf("logi->%s\n",yytext);
            return NEG;
        }
"||"    {
            return LOR;
        }
"&&"    {
            return LAND;
        }
        
"true"  {
            return TRUE;

        }
"false"  {
            return FALSE;

        }
"if"	{
		return IF;
	}
"else"	{
		return ELSE;
	}
"while" {
	return WHILE;
}
, {return *yytext;}
=  {	
		//ECHO; 
		return ASSIGN;
	}
;   {
		//ECHO;
		return SC;
	}
[+] {	
		//ECHO;
		return PLUS;
	}
[-] {	
		//ECHO;
		return MINUS;
	}
[%] {	
		//ECHO;
		return MOD;
	}
[/] {		//ECHO;
		return DIV;
	}
[*] {	//ECHO;
		return MUL;
	}

[0-9]+  {
                //printf("id->%s",yytext);
                yylval.str = strdup(yytext);
                return NUM;    

        }
[a-zA-Z][a-zA-Z]* {
               // printf("lex id->%s\n",yytext);
                yylval.str = strdup(yytext);
                return ID;    
            }
[$]     {
            //printf("end->%s\n",yytext);
            return *yytext;
        }
[\n\t ] {   }
.       {
            printf("Invalid character");
        }
%%
int yywrap(){
    return 0;
}
/*int main(){
    while(1){
        yylex();
    }

}*/
