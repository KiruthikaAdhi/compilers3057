#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern int counter;
typedef struct node{
	int width;
	struct node* next;
}NODE;
NODE* createArray(int dim){
	int r = 4;
	NODE *head = NULL;
	for(int i=0 ; i<dim ; i++){
		NODE* n = (NODE*)malloc(sizeof(NODE));
		n->width = r;
		r = rand()%4;
		printf("dim->%d\n",r);		
		r = r*n->width;	
		n->next = head;
		head = n;	
	}
	return head;
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
