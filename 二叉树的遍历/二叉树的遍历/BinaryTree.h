#define _CRT_SECURE_NO_WARNINGS

typedef char DataType;

typedef struct BTnode {
	DataType val;
	struct BTnode* _left;
	struct BTnode* _right;
}BTnode;
