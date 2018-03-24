#include<stdio.h>
#include"bool.h"
LIST* makelist(int label){
	LIST* node = (LIST*)malloc(sizeof(LIST));
	node->label = label;
	node->next = NULL;
	return NODE;
}

LIST* merge(LIST* l1,LIST* l2){
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	while(l1->next != NULL){
		l1 = l1->next;
	}
	l1->next = l2 ;
	return l1;
}
void backpatch(LIST* l,int num){
	char label[5];
	while(l != NULL){
		sprintf(label,"%d\n",num);
		strcat(l->text,label);
	}
}


