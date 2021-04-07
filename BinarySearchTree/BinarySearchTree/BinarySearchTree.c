#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
	int data ;
	struct Node* lchild ;
	struct Node* rchild ;
}Node;

typedef struct BSTree
{
	Node* root ;
	int length ;
}BSTree;

Node* GetNewNode(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val ;
	newNode->lchild = NULL ;
	newNode->rchild = NULL ;
	return newNode;
}

BSTree* GetNewTree()
{
	BSTree* Tree = (BSTree*)malloc(sizeof(BSTree));
	Tree->length = 0  ;
	Tree->root = NULL ;

	return Tree;
}

//��1������Ԫ��
Node* Insert_Node(Node* root, int val , int* flag)//return root �������ڷ�����һ��ݹ�
{
	if (root == NULL) {
		root = GetNewNode(val);
		*flag = 1 ; //���ڼ�¼����Ԫ���Ƿ�ɹ�
		return root;
	}
	//�ж���β��룬�ݹ�ʵ��
	if (root->data == val) {
		return root; 
	}
	//��root�������ӽڵ���Ϊ�²�ĸ��ڵ���еݹ�
    if (root->data > val){
		root->lchild = Insert_Node(root->lchild, val, flag);
	} 
	else {
		root->rchild = Insert_Node(root->rchild, val, flag); 
	}
	return root ;
}

void Insert_Tree(BSTree* Tree, int val)
{
	int flag = 0 ;
	Tree->root = Insert_Node(Tree->root, val ,&flag );
	if (flag == 1){
		Tree->length++; 
	}
}


//��2����ն�����
void  Clear_Node(Node* root)
{
	if (root == NULL) return ;
	Clear_Node(root->lchild);
	Clear_Node(root->rchild);
	//����root->rchild ˵����������ײ�Ľڵ㣬��˴��¿�ʼ�����ͷ�
	free(root);
	return;
}

void Clear_Tree(BSTree* Tree)
{
	if (Tree->root == NULL) return ;
	Clear_Node(Tree->root);
	free(Tree);
}


//��3������������

//1.ǰ�����������-�������ң�
void pre_order_node(Node* root)
{
	if (root == NULL) return ;
	printf("%d ",root->data);
	pre_order_node(root->lchild);
	pre_order_node(root->rchild);
}

void pre_order_tree(BSTree* Tree)
{
	if (Tree == NULL) return;
	printf("pre_order: ");
	pre_order_node(Tree->root);
	printf("\n");
}

//2.�������������-����
void mid_order_node(Node* root)
{
	if (root == NULL) return ;
	mid_order_node(root->lchild);
	printf("%d ", root->data);
	mid_order_node(root->rchild);
}

void mid_order_tree(BSTree* Tree)
{
	if (Tree == NULL) return;
	printf("mid_order: ");
	mid_order_node(Tree->root);
	printf("\n");
}
//3.�������������
void post_order_node(Node* root)
{
	if (root == NULL) return;
	post_order_node(root->lchild);
	post_order_node(root->rchild);
	printf("%d ", root->data);
} 

void post_order_tree(BSTree* Tree)
{
	if (Tree == NULL) return;
	printf("post_orderr: ");
	post_order_node(Tree->root);
	printf("\n");
}


//��4���Թ�������ʽ���������
void output_node(Node* root)
{
	if (root == NULL) return ;
	printf("%d ",root->data);
	if (root->lchild == NULL && root->rchild == NULL) return;
	printf("(");
	output_node(root->lchild);
	printf(",");
	output_node(root->rchild);
	printf(")");
}

void output_Tree(BSTree* Tree)
{
	if (Tree == NULL) return;
	printf("Tree[%d]: " , Tree->length);
	output_node(Tree->root);
	printf("\n");
}

int main()
{
	srand((size_t)time(0));
	BSTree* Tree = GetNewTree();
#define MAX_OP 10 
	for (int i = 0; i < MAX_OP; i++)
	{
		Insert_Tree(Tree, rand() % 20);
	}
	output_Tree(Tree);

	pre_order_tree(Tree);
	mid_order_tree(Tree);
	post_order_tree(Tree);
#undef MAX_OP
	return 0;
}