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

//��ϰһ: дһ������ʵ�ֶ������Ĳ������

void BT_LayerTraversal(BTNode* root) {
	Queue Q;
	QueueInit(&Q);
    
	if (!root) {
		printf("�ö�����Ϊ��!\n");
		return;
	}

	QueuePush(&Q , root);

	while ( !QueueEmpty(&Q) ) {
		BTNode* cur = QueueFront(&Q);
		printf("%c ",cur->val);
		QueuePop(&Q);

		//�����������Ϊ��,������
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
