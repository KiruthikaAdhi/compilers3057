typedef struct node{
	int width;
	struct node* next;
}NODE;
typedef struct symtab{
	char* id;
	NODE* t;
	struct node* next;
}SYMTAB;

