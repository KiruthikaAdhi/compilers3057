# compilers3057
solution for compiler design lab exercises

Description:
Array References:
	It performs translation of statements with Array references into three address code.
BASIC BLOCK:
	Splits the list of quadraples into basic blocks by leader selection.
DAG:
	Constructs Directed Acyclic Graph for list of quadraples.
FlowOfControl:
	It translates a block of Array References,Assignment,If,If Else statements into three address code.
IFELSE:
	It corrects the code with dangling else by insertion of an else statement.
LabeledExprTree:
	It generates optimal code for expressions by construction of Labeled Expression trees.
QUADRAPLES:
	It generates quadraples as the intermediate code.
SYMTABLE:
	It constructs symbol table for a nested block of statements.
WHILE:
	It performs the conversion of do-while and for statements into while statements.
backpatchingBoolExpressions:
	It generates three address code for boolean expressions by applying backpatching.
syntaxTree:
	It constructs syntax tree for arithmetic expressions

Execution:
To compile:
	yacc -d <name>.y
	lex <name>.l
	cc lex.yy.c y.tab.c
To execute:
	./a.out
