#define _CRT_SECURE_NO_WARNINGS

#include "prework.h"

/*  【1】初始化树   */

// 1. 封装树的节点
Node* Get_tree_Node( TreeDataType  val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->lchild = NULL; 
	newNode->rchild = NULL;

	return newNode;
}

// 2. 建立一颗树
BSTree* GetTree()
{
	BSTree* tree = (BSTree*)malloc(sizeof(BSTree));
	tree->root = NULL ;
	tree->length = 0;

	return tree;
}

// 3.二叉搜索树的基本操作

//3_1 遍历二叉树

//3_1_1前序遍历
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

//3_1_2中序遍历
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

//3_1_3后序遍历
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


/*   【2】初始化栈 */

//1.建立一个长度为n的栈
Stack* Get_Stack(int n)
{
	//动态获取一个栈
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	//为栈数组开辟空间
	stack->array = (Node**)malloc(sizeof(Node*)* n);
	stack->Top = 0 ;

	return stack;
}

//2.栈的基本操作


//2_1 入栈
void PushStack(Stack* stack, Node* node)
{
	assert(stack);

	stack->array[stack->Top++] = node ;
}

//2_2 出栈
void PopStack(Stack* stack)
{
	assert(stack);

	if (stack->Top == 0) return;
	stack->Top--;
}

//2_3 取栈顶元素
Node* TopStack(Stack* stack)
{
	assert(stack);

	if (stack->Top == 0) return NULL ;
	else return stack->array[stack->Top - 1];
}

//2_4判断栈空
int IsEmpty(Stack* stack)
{
	assert(stack);

	return stack->Top == 0;
}

/*  【3】构造将广义表转化成二叉树的函数  */
 
void BuildTree(const char* str, Node** root, int* tree_size)
{
	Stack* stack = Get_Stack(strlen(str));
	Node* temp = NULL, *p = NULL; //temp用于封装节点，p用于接收栈首节点，并完成链接左右子节点
	int flag = 0;//用于标记 ',', 从而判断父节点链接lchild还是rchild ，flag改变，说明遇到{,},
				 //下一节点应链接到父节点的右子树上
	while (str[0])
	{
		switch (str[0])
		{
		//'(' 判断入栈 ，flag标记归零
		case '(' :
			PushStack(stack,temp);
			flag = 0; 
			break;
		//标记逗号
		case ',' :
			flag = 1 ;
			break;
		//判断出栈
		case ')' :
			PopStack(stack);
			break;
		//跳过空格
		case ' ':
			break; 
		default:
			/*封装节点的时候顺便完成链接*/

			temp = Get_tree_Node(str[0]) ;
			*tree_size = *tree_size + 1;   //记录树内节点个数
			if (IsEmpty(stack))            //栈空，说明第一个入，是为根节点
				*root = temp;
			else if (flag == 1)            //遇上" ," ,为右子树,链接到父节点的右子树上
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

