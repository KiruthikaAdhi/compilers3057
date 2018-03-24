#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"foc.h"
char instrArr[500][500];
LIST* makelist(int label){
	LIST* node = (LIST*)malloc(sizeof(LIST));
	node->label = label;
	node->next = NULL;
	return node;
}

LIST* merge(LIST* l1,LIST* l2){
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	LIST* temp=l1;
	while(temp->next != NULL){
		//printf("In loop merge %d\n",l1->label);
		temp = temp->next;
	}
	//printf("In outside l1 loop merge %d\n",l1->label);	
	//printf("In outside  l2 loop merge %d\n",l2->label);	
	temp->next = l2 ;
	return l1;
}
void backpatch(LIST* l,int num){
	char label[5];
	LIST* temp = l;
	sprintf(label,"  %d",num);
	while(temp != NULL){
		//printf("In bp ----> %d\n",temp->label);	
		strcat(instrArr[temp->label],label);
		temp = temp->next;
	}
}


