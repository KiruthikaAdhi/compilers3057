#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"foc.h"
QUAD instrArr[500];
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
	char* label = (char*)malloc(sizeof(char)*5);
	LIST* temp = l;
	sprintf(label,"  %d",num);
	while(temp != NULL){
		//printf("In bp ----> %d\n",temp->label);
		//printf("Before : %s\n",instrArr[temp->label].result);	
		instrArr[temp->label].result=label;
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
int isLeader(int f,int l,int label){
	QUAD Q=instrArr[label];
	if(strcmp(Q.op,"if")==0 || strcmp(Q.op,"goto")==0){
		return atoi(Q.result);
	}
	if(label == f){return label;}
	QUAD Q2 = instrArr[label-1];
	if(strcmp(Q2.op,"if")==0 || strcmp(Q2.op,"goto")==0){
		return label;
	}
	return 0;
}
BB* insertBB(BB* head,int first){
	BB* temp = head;
	BB* new=(BB*)malloc(sizeof(BB));
	new->first = first;
	if(temp == NULL){
		return new;
	}
	if(temp->first > first){
		new->next = temp;
		return temp;
	}
	while(temp->next != NULL && temp->next->first < first){
		temp = temp->next;
	}
	//BB* onext =temp->next;
	if(temp->next != NULL && temp->next->first == first){
		return head;
	}
	new->next = temp->next;
	temp->next = new;
	return head;
}

void printBB(BB* bb){
	BB* temp = bb;
	while(temp!=NULL){
		printf("%d\n",temp->first);
		temp = temp->next;
	}	
}

BB* constructBB(int first,int last){
	BB* bb = NULL;
	int i = first;
	for( ; i<= last ; i++){
		int leader = isLeader(first,last,i) ;
		if( leader != 0){
			bb = insertBB(bb,leader);
		}
	}
	printBB(bb);
}


