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
		//printf("After : %s\n",instrArr[temp->label].result);	
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

BB* insertBB(BB* head,int first){
	BB* temp = head;
	BB* new=(BB*)malloc(sizeof(BB));
	new->first = first;
	if(temp == NULL){
		return new;
	}
	if(temp->first > first){
		new->next = temp;
		return new;
	}
	if(temp->first == first){
		return head;
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
	int i = 1;
	while(temp!=NULL){
		printf("BB #%d : \n",i);
		printf("Label : op\targ1\targ2\tresult\n");
		
		int j = temp->first;
		//printf("i=%d   j=%d   last=%d\n",i,j,temp->last);
		for(;j<= temp->last ; j++){
			QUAD q = instrArr[j];
			printf("%d : [%s]\t[%s]\t[%s]\t[%s]\n",j,q.op,q.arg1,q.arg2,q.result);
		}
		temp = temp->next;
		i++;
	}		
}
int findBB(BB* bb,int label){
	BB* temp=bb;
	int i=1;
	while(temp){
		if(temp->first <=  label && temp->last >= label){
			return i;
		}
		i++;
		temp = temp->next;
	}
}
BB* constructBB(int first,int last){
	BB* bb = NULL;
	int i = first;
	for( ; i<= last ; i++){
		QUAD Q=instrArr[i];
		if(strcmp(Q.op,"if")==0 || strcmp(Q.op,"goto")==0){
			bb=insertBB(bb, atoi(Q.result) );
		}
		if(i == first){bb=insertBB(bb, i); continue;}
		QUAD Q2 = instrArr[i-1];
		if(strcmp(Q2.op,"if")==0 || strcmp(Q2.op,"goto")==0){
			bb=insertBB(bb, i );
		}	
	}
	BB* temp=bb;
	while(temp->next != NULL){
		temp->last = (temp->next->first) -1;
		temp = temp->next;
	}
	temp->last = last;
	printBB(bb);
	return bb;
}
GRAPH constructFlowGraph(BB* bb){
	BB* temp = bb;
	int size=0;
	while(temp){
		temp=temp->next;
		size++;
	}
	LIST** g=(LIST**)malloc(sizeof(LIST*)*size+1);
	temp=bb;
	int u=1;
	while(temp){
		g[u]=NULL;
		QUAD Q=instrArr[temp->last];
		if(Q.op=="if"){
			int label = findBB(bb,atoi(Q.result));
			LIST* temp1=makelist(label);
			if(temp->next){
					LIST* temp2=makelist(findBB(bb,temp->next->first));
					temp1->next = temp2;
			}
			g[u]=temp1;
		}
		if(Q.op=="goto"){
			int label = findBB(bb,atoi(Q.result));
			LIST* temp3=makelist(label);
			g[u]=temp3;
		}
		u++;
		temp=temp->next;
	}
	GRAPH fg;
	fg.size=size;
	fg.graph=g;
	return fg;
}
void print(GRAPH fg){
	int size = fg.size;
	LIST** g = fg.graph;
	for(int u=1;u<=size;u++){
		printf("u=%d\n",u);
		LIST* temp=g[u];
		while(temp){
			printf("v=%d\n",temp->label);
			temp=temp->next;
		}
	}

}

