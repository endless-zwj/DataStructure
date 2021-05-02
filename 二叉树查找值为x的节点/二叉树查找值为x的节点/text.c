#define _CRT_SECURE_NO_WARNINGS

#define BTDataType char

#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType val;
}BTNode;


BTNode* CreateTreeNode(BTDataType x) {
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = x;

	return newNode;
}

void prevOrderTree(BTNode* root) {
	if (!root)	return;

	printf("%c->", root->val);

	prevOrderTree(root->left);
	prevOrderTree(root->right);
}

//查找值为x的节点
BTNode* Find_XNode(BTNode* root, BTDataType x) {
	if (!root) return NULL;
	if (root->val == x) return root;

	if ( Find_XNode(root->left, x))
		return Find_XNode(root->left, x);
	else 
		return Find_XNode(root->right, x);
}

int main() {

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

	prevOrderTree(A);
	printf("\n");
	printf("%p\n", Find_XNode(A, 'C'));
	printf("%p\n", Find_XNode(A, 'A'));
	printf("%p\n", A);
	printf("%p\n", C);

	system("pause");

	return 0;
}
