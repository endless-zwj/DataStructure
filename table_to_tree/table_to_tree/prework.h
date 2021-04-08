#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define TreeDataType char //���ڵ�����Ϊchar���ɴ����ĸ

//����һ������㣬���ڽ�������е����ݷ�װ�������
typedef struct Node
{
	TreeDataType data ;
	struct Node* lchild;
	struct Node* rchild;
}Node;

//����һ�Ŷ����������������������ݴ�������
typedef struct BSTree
{
	Node* root ;
	int length ;
}BSTree;

//����һ��ջ�����ڽڵ����ջ���ջ
typedef struct Stack
{
	Node** array;
	int Top ;
}Stack;

// 1. ��װ���Ľڵ�
Node* Get_tree_Node(TreeDataType  val);
// 2. ����һ����
BSTree* GetTree();
//3_1_1ǰ�����
Node* pre_order_Node(Node* root);
void pre_order_tree(BSTree* tree);
//3_1_2�������
Node* in_order_Node(Node* root);
void in_order_tree(BSTree* tree);
//3_1_3�������
Node* post_order_Node(Node* root);
void post_order_tree(BSTree* tree);
//1.����һ������Ϊn��ջ
Stack* Get_Stack(int n);
//2_1 ��ջ
void PushStack(Stack* stack, Node* node);
//2_2 ��ջ
void PopStack(Stack* stack);
//2_3 ȡջ��Ԫ��
Node* TopStack(Stack* stack);
//2_4�ж�ջ��
int IsEmpty(Stack* stack);
/*  ��3�����콫�����ת���ɶ������ĺ���  */
void BuildTree(const char* str, Node** root, int* tree_size);