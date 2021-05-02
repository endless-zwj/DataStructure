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

	printf("%c->",root->val);

	prevOrderTree(root->left);
	prevOrderTree(root->right);
}

void BT_TreeDelete(BTNode* root) {
	if (!root) return;

	BT_TreeDelete(root->left);
	BT_TreeDelete(root->right);

	printf("ÒÑÉ¾³ý%c\n", root->val);
	free(root);
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
	BT_TreeDelete(A);
	A == NULL;

	system("pause");

	return 0;
}
