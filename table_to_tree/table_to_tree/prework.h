#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define TreeDataType char //树内的数据为char，可存放字母

//定义一个树结点，用于将广义表中的数据封装成树结点
typedef struct Node
{
	TreeDataType data ;
	struct Node* lchild;
	struct Node* rchild;
}Node;

//定义一颗二叉搜索树，将广义表的数据存入树中
typedef struct BSTree
{
	Node* root ;
	int length ;
}BSTree;

//定义一个栈，用于节点的入栈与出栈
typedef struct Stack
{
	Node** array;
	int Top ;
}Stack;

// 1. 封装树的节点
Node* Get_tree_Node(TreeDataType  val);
// 2. 建立一颗树
BSTree* GetTree();
//3_1_1前序遍历
Node* pre_order_Node(Node* root);
void pre_order_tree(BSTree* tree);
//3_1_2中序遍历
Node* in_order_Node(Node* root);
void in_order_tree(BSTree* tree);
//3_1_3后序遍历
Node* post_order_Node(Node* root);
void post_order_tree(BSTree* tree);
//1.建立一个长度为n的栈
Stack* Get_Stack(int n);
//2_1 入栈
void PushStack(Stack* stack, Node* node);
//2_2 出栈
void PopStack(Stack* stack);
//2_3 取栈顶元素
Node* TopStack(Stack* stack);
//2_4判断栈空
int IsEmpty(Stack* stack);
/*  【3】构造将广义表转化成二叉树的函数  */
void BuildTree(const char* str, Node** root, int* tree_size);