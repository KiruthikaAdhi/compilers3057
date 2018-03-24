#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern int counter;
typedef struct node{
	int width;
	struct node* next;
}NODE;
typedef struct symtab{
	char* id;
	NODE* t;
	struct symtab* next;
}SYMTAB;
NODE* createArray(int dim){
	int r = 4;
	NODE *head = NULL;
	int i;
	for(i=0 ; i<dim ; i++){
		NODE* n = (NODE*)malloc(sizeof(NODE));
		n->width = r;
		r = rand()%4 + 1;
		printf("dim->%d\nn->width->%d\n",r,n->width);		
		r = r*n->width;	
		n->next = head;
		head = n;	
	}
	return head;
}
NODE* insert(NODE* t , int dim){
	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->width = dim;
	n->next = t;
	return n;
}
SYMTAB* insertEntry(SYMTAB* st , NODE* t , char* id){
	SYMTAB* temp = st ;
	while(temp != NULL){
		if( strcmp(temp->id,id) == 0 ){
			return NULL ;		
		}
		temp = temp->next ;
	}
	SYMTAB* n = (SYMTAB*)malloc(sizeof(SYMTAB));
	n->id = id;
	n->t = t;
	n->next = st;
	return n;
}
void printDim(NODE* t){
	if(t==NULL) return;
	NODE* temp = t;
	while(temp!=NULL){
		printf("%d\n",temp->width);
		temp=temp->next;
	}
}
void printSym(SYMTAB* t){
	if(t==NULL) return;
	SYMTAB* temp = t;
	while(temp!=NULL){
		//printf("%s\n",temp->id);
		//printDim(temp->t);
		temp=temp->next;
	}
}
NODE* getEntry(SYMTAB* st,char* id){
	SYMTAB* temp = st ;
	while(temp != NULL){
		if(strcmp(temp->id,id) == 0 && temp->t != NULL){
			return temp->t;
		}
		temp = temp->next;
	}
	//printf("Temp is null");
	return NULL;
}
int search(SYMTAB* st,char* id){
	SYMTAB* temp = st ;
	while(temp != NULL){
		if(strcmp(temp->id,id) == 0 && temp->t == NULL){
			return 1;
		}
		temp = temp->next;
	}
	//printf("Temp is null");
	return 0;
}
char* newTemp(){
	//static int t = 1;
	char* str = (char*)malloc(sizeof(int)*3);	
	char i[5];
	sprintf(i,"%d",counter);
	counter++;
	strcpy(str ,"t");
	strcat(str,i);
	return str;
}
/*int main(){
	
	for(int i=0 ; i<5 ; i++){
		char* s=newTemp();
		printf("%s\n",s);
	}
	NODE* n = createArray(2);
	while(n!=NULL){
		printf("%d\n",n->width);
		n = n->next;
	}
}*/
