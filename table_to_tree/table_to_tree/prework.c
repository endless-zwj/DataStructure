#define _CRT_SECURE_NO_WARNINGS

#include "prework.h"

/*  ��1����ʼ����   */

// 1. ��װ���Ľڵ�
Node* Get_tree_Node( TreeDataType  val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->lchild = NULL; 
	newNode->rchild = NULL;

	return newNode;
}

// 2. ����һ����
BSTree* GetTree()
{
	BSTree* tree = (BSTree*)malloc(sizeof(BSTree));
	tree->root = NULL ;
	tree->length = 0;

	return tree;
}

// 3.�����������Ļ�������

//3_1 ����������

//3_1_1ǰ�����
Node* pre_order_Node(Node* root)
{
	if (root == NULL) return root;

	printf("%c",root->data);
	root->lchild = pre_order_Node(root->lchild);
	root->rchild = pre_order_Node(root->rchild);
	return root ; 
}

void pre_order_tree(BSTree* tree)
{
	if (tree == NULL) return ;
	printf("pre_order[%d] ",tree->length );
	tree->root = pre_order_Node(tree->root); 
	printf("\n");
}

//3_1_2�������
Node* in_order_Node(Node* root)
{
	if (root == NULL) return root;

	root->lchild = in_order_Node(root->lchild);
	printf("%c", root->data);
	root->rchild = in_order_Node(root->rchild);
	return root;
}

void in_order_tree(BSTree* tree)
{
	if (tree == NULL) return;
	printf("in_order[%d] ", tree->length);
	tree->root = in_order_Node(tree->root);
	printf("\n");
}

//3_1_3�������
Node* post_order_Node(Node* root)
{
	if (root == NULL) return root;

	root->lchild = post_order_Node(root->lchild);
	root->rchild = post_order_Node(root->rchild);
	printf("%c", root->data);
	return root;
}

void post_order_tree(BSTree* tree)
{
	if (tree == NULL) return;
	printf("post_order[%d] ", tree->length);
	tree->root = post_order_Node(tree->root);
	printf("\n");
}


/*   ��2����ʼ��ջ */

//1.����һ������Ϊn��ջ
Stack* Get_Stack(int n)
{
	//��̬��ȡһ��ջ
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	//Ϊջ���鿪�ٿռ�
	stack->array = (Node**)malloc(sizeof(Node*)* n);
	stack->Top = 0 ;

	return stack;
}

//2.ջ�Ļ�������


//2_1 ��ջ
void PushStack(Stack* stack, Node* node)
{
	assert(stack);

	stack->array[stack->Top++] = node ;
}

//2_2 ��ջ
void PopStack(Stack* stack)
{
	assert(stack);

	if (stack->Top == 0) return;
	stack->Top--;
}

//2_3 ȡջ��Ԫ��
Node* TopStack(Stack* stack)
{
	assert(stack);

	if (stack->Top == 0) return NULL ;
	else return stack->array[stack->Top - 1];
}

//2_4�ж�ջ��
int IsEmpty(Stack* stack)
{
	assert(stack);

	return stack->Top == 0;
}

/*  ��3�����콫�����ת���ɶ������ĺ���  */
 
void BuildTree(const char* str, Node** root, int* tree_size)
{
	Stack* stack = Get_Stack(strlen(str));
	Node* temp = NULL, *p = NULL; //temp���ڷ�װ�ڵ㣬p���ڽ���ջ�׽ڵ㣬��������������ӽڵ�
	int flag = 0;//���ڱ�� ',', �Ӷ��жϸ��ڵ�����lchild����rchild ��flag�ı䣬˵������{,},
				 //��һ�ڵ�Ӧ���ӵ����ڵ����������
	while (str[0])
	{
		switch (str[0])
		{
		//'(' �ж���ջ ��flag��ǹ���
		case '(' :
			PushStack(stack,temp);
			flag = 0; 
			break;
		//��Ƕ���
		case ',' :
			flag = 1 ;
			break;
		//�жϳ�ջ
		case ')' :
			PopStack(stack);
			break;
		//�����ո�
		case ' ':
			break; 
		default:
			/*��װ�ڵ��ʱ��˳���������*/

			temp = Get_tree_Node(str[0]) ;
			*tree_size = *tree_size + 1;   //��¼���ڽڵ����
			if (IsEmpty(stack))            //ջ�գ�˵����һ���룬��Ϊ���ڵ�
				*root = temp;
			else if (flag == 1)            //����" ," ,Ϊ������,���ӵ����ڵ����������
			{
				p = TopStack(stack);
				p->rchild = temp;
			}
			else
			{
				p = TopStack(stack);
				p->lchild = temp;
			}
			break;
		}
		str++;
	}
}

