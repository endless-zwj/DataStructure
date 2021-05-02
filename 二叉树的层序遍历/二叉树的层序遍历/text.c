#define _CRT_SECURE_NO_WARNINGS

#define BTDataType char

#include"Queue.h"
#include<stdio.h>

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType val;
}BTNode;


BTNode* CreateTreeNode(BTDataType x) {
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));

	newNode->left = NULL; 
	newNode->right = NULL;
	newNode->val = x ;

	return newNode;
}

//练习一: 写一个函数实现二叉树的层序遍历

void BT_LayerTraversal(BTNode* root) {
	Queue Q;
	QueueInit(&Q);
    
	if (!root) {
		printf("该二叉树为空!\n");
		return;
	}

	QueuePush(&Q , root);

	while ( !QueueEmpty(&Q) ) {
		BTNode* cur = QueueFront(&Q);
		printf("%c ",cur->val);
		QueuePop(&Q);

		//如果左子树不为空,入左树
		if (cur->left) 
			QueuePush(&Q ,cur->left); 
		if (cur->right)
			QueuePush(&Q, cur->right);
	}
}


int main()  {

	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');
	BTNode* G = CreateTreeNode('G');

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = G;
	C->left = E;
	C->right = F;

	BT_LayerTraversal(A);

	system("pause");

	return 0;
}
