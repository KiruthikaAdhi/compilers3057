#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"foc.h"

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
void backpatch(LIST* l,int num,QUAD instrArr[500]){
	char label[5];
	LIST* temp = l;
	sprintf(label,"  %d",num);
	while(temp != NULL){
		//printf("In bp ----> %d\n",temp->label);
		printf("Before : %s\n",instrArr[temp->label].result);	
		strcat(instrArr[temp->label].result,label);
		printf("After : %s\n",instrArr[temp->label].result);	
		temp = temp->next;
	}
}
QUAD createQuad(char* op,char* result,char* arg1,char* arg2){
	QUAD instr ;
	instr.op = op;
	instr.result=result;
	instr.arg1 = arg1;
	instr.arg2 = arg2;
	return instr;
}


