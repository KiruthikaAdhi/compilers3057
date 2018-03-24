#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct sym{
	char name[100];
	char type[100];
	struct sym* next;
}SYMBOL;
typedef struct{
	SYMBOL** symTab[10] ;
	int top;
}STACK;
STACK* initialise(){
	STACK* stk = (STACK*)malloc(sizeof(STACK));
	stk->top=-1;
	return stk;	
}
bool push(STACK* stk){
	if(stk->top >= 10) return false;
	stk->top++;
	SYMBOL** ST = (SYMBOL**)malloc(sizeof(SYMBOL*)*100);
	//printf("\naddr = %d\n",ST);
	int i = 0;	
	for( ;i < 100 ; i++) ST[i]=NULL;
	stk->symTab[stk->top] = ST;
	return true;
}
bool pop(STACK* stk){
	if(stk->top==-1) return false;
	stk->top--;
	return true;	
}
int hashFunc(char s[]){
	int n = strlen(s);
	//printf("%s length = %d",s,n);
	int i = 0;
	int hashVal = 0;
	for( ; i < n ; i++ ){
		hashVal += (s[i]-'0');
	}
	//printf("%s == %d",s,hashVal);
	return hashVal;
}
bool find(SYMBOL* head,char name[]){
	while(head!= NULL){
		printf("%s",head->name);
		if(strcmp(head->name,name)==0){
			return true;
		}
		head = head->next;
	}
	return false;
}
bool insert(SYMBOL* ST[],SYMBOL* newSym){
	int hash = hashFunc(newSym->name)%100;
	//printf("In insert : \t id = %s\n",newSym->name);
	if(find(ST[hash],newSym->name) != true){
		SYMBOL* head = ST[hash] ;
		newSym->next = head;
		ST[hash] = newSym;
		return true;
	}
	return false;
}
void print(SYMBOL* ST[]){
	for(int i = 0 ; i< 100 ; i++){
		SYMBOL* head = ST[i];
		//printf("%d\n",i);		
		while(head!= NULL){
			//printf("**%d\n",i);
			printf("%s -> %s\n",head->name,head->type);	
			head = head->next;		
		}
		//printf(" hash = %d\n",i);
	}

}

/*int main(){
	STACK *stk = initialise();
	SYMBOL* ST[100]={NULL};
	push(stk,ST);
	SYMBOL *s = (SYMBOL*)malloc(sizeof(SYMBOL));
	strcpy(s->name , "a");
	strcpy(s->type,"int");
	s->next = NULL;	
	if(insert(stk->symTab[stk->top],s)==true) print(stk->symTab[stk->top]);
	else printf("Redeclaration\n");	
	s = (SYMBOL*)malloc(sizeof(SYMBOL));
	strcpy(s->name , "b");
	strcpy(s->type,"int");
	s->next = NULL;	
	if(insert(stk->symTab[stk->top],s)==true) print(stk->symTab[stk->top]);
	else printf("Redeclaration\n");

	SYMBOL* ST1[100]={NULL};	
	push(stk,ST1);
	s = (SYMBOL*)malloc(sizeof(SYMBOL));
	strcpy(s->name , "c");
	strcpy(s->type,"int");
	s->next = NULL;	
	if(insert(stk->symTab[stk->top],s)==true) print(stk->symTab[stk->top]);
	else printf("Redeclaration\n")	;
	s = (SYMBOL*)malloc(sizeof(SYMBOL));
	strcpy(s->name , "d");
	strcpy(s->type,"int");
	s->next = NULL;	
	if(insert(stk->symTab[stk->top],s)==true) print(stk->symTab[stk->top]);
	else printf("Redeclaration\n");

	pop(stk);

	s = (SYMBOL*)malloc(sizeof(SYMBOL));
	strcpy(s->name , "f");
	strcpy(s->type,"int");
	s->next = NULL;	
	if(insert(stk->symTab[stk->top],s)==true) print(stk->symTab[stk->top]);
	else printf("Redeclaration\n")	;
	s = (SYMBOL*)malloc(sizeof(SYMBOL));
	strcpy(s->name , "g");
	strcpy(s->type,"int");
	s->next = NULL;	
	if(insert(stk->symTab[stk->top],s)==true) print(stk->symTab[stk->top]);
	else printf("Redeclaration\n");
	
}*/
