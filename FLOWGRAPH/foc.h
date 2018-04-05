
typedef struct list{
	//char text[500];
	int label;
	struct list* next;
}LIST;
typedef struct quad{
	char* op;
	char* arg1;
	char* arg2;
	char* result;
}QUAD;
typedef struct bb{
	int first;
	int last;
	struct bb* next;
}BB;
typedef struct graph{
	int size;
	LIST** graph;
}GRAPH;

