#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char data[300];
	struct node* left;
	struct node* right;
}NODE;
NODE* createNode(char* data,NODE* left,NODE* right){
	NODE* N = (NODE*)malloc(sizeof(NODE));
	strcpy(N->data,data);
	N->left = left;
	N->right = right;
	return N;
}
void postOrder(NODE* N){
	if(N==NULL) return;
	postOrder(N->left);
	postOrder(N->right);
	printf("%s\n",N->data);
}
/*int main(){
	NODE *n1,*n2,*n3,*n4,*n5;
	n1 = createNode("a",NULL,NULL);
	n2 = createNode("b",NULL,NULL);
	n3 = createNode("+",n1,n2);
	n4 = createNode("c",NULL,NULL);
	n5 = createNode("-",n3,n4);
	postOrder(n5);
}*/

