
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
typedef struct dag{
	char* op;
	struct dag* arg1;
	struct dag* arg2;
}DAGNODE;

typedef struct varpointer{
	char* id;
	struct dag* dp;
	struct varpointer* next; 
}VARP;


