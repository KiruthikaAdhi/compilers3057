#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"foc.h"
QUAD instrArr[500];
VARP* varp = NULL; 
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
	int i = 1;
	while(temp!=NULL){
		printf("BB #%d : \n",i);
		printf("Label : op\targ1\targ2\tresult\n");
		
		int j = temp->first;
		for(;j<= temp->last ; j++){
			QUAD q = instrArr[j];
			printf("%d : %s---%s---%s---%s\n",j,q.op,q.arg1,q.arg2,q.result);
		}
		temp = temp->next;
		i++;
	}	
}

BB* constructBB(int first,int last){
	BB* bb = NULL;
	int i = first;
	for( ; i<= last ; i++){
		int leader = isLeader(first,last,i) ;
		if( leader != 0){
			bb = insertBB(bb,leader);
			printf("Leader : %d\n",leader);
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
//DAG
DAGNODE* getVarDp(char *id){
	VARP* temp = varp;
	while(temp != NULL){
		if(strcmp(temp->id,id)==0){
			return temp->dp;
		}
		temp=temp->next;
	}
	return NULL;
	
}
VARP* getVarNode(char *id){
	VARP* temp = varp;
	while(temp != NULL){
		if(strcmp(temp->id,id)==0){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
	
}


VARP* makeVarNode(char* id){
	VARP* new = (VARP*)malloc(sizeof(VARP));
	new->id = id;
	new->dp = (DAGNODE*)malloc(sizeof(DAGNODE));
	new->dp->op = id;
	new->dp->arg1 = NULL ;
	new->dp->arg2 = NULL ;
	new->next = varp;
	return new;
}
DAGNODE* makeDAGnode(QUAD Q){
	DAGNODE* dn = (DAGNODE*)malloc(sizeof(DAGNODE));
	dn->op = Q.op;
	dn->arg1 = getVarDp(Q.arg1);
	dn->arg2 = getVarDp(Q.arg2);
 	return dn;

}
void makeVarEntry(QUAD Q,int first,int curr){
	if(getVarNode(Q.result) == NULL) varp = makeVarNode(Q.result);
	if(getVarNode(Q.arg1) == NULL) varp = makeVarNode(Q.arg1);
	if(getVarNode(Q.arg2) == NULL) varp = makeVarNode(Q.arg1);

	int i = first;
	for(;i<curr;i++){
		QUAD temp = instrArr[i];
		if(strcmp(Q.op,temp.op)==0 && strcmp(Q.arg1,temp.arg1)==0 && strcmp(Q.arg2,temp.arg2)==0){
			DAGNODE* tempDp = getVarDp(temp.result);
			VARP* t = (VARP*)malloc(sizeof(VARP));
			t->id = Q.result;
			t->dp = tempDp;  
			}				
	}	
	VARP* t = getVarNode(Q.result);
	t->dp = makeDAGnode(Q);
}
void printDAG(DAGNODE* dn){
	if(dn == NULL) return;
	printDAG(dn->arg1);
	printf("%s",dn->op);
	printDAG(dn->arg2);
}
DAGNODE* constructDAG(int first,int last){
	varp = NULL;
	int i = first;	
	for(;i<=last;i++){
		makeVarEntry(instrArr[i],first,i);
	}	
	VARP* temp = varp;
	while(temp != NULL){
		printDAG(temp->dp);
		printf("%s\n",temp->id);
		temp = temp->next;

	}
}

