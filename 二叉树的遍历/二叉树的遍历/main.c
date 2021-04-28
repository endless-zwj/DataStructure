#define _CRT_SECURE_NO_WARNINGS

#include"BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>


BTnode* CreateTreeNode( DataType x) {
	BTnode* node = (BTnode*)malloc(sizeof(BTnode));
	node->val = x;
	node->_left = NULL;
	node->_right = NULL; 

	return node ;
}

void prevOrder(BTnode* root) {
	if (root == NULL){
		printf("NULL->");
		return;
	}

	printf("%c->",root->val);
	prevOrder(root->_left);
	prevOrder(root->_right); 
}

int LeafTreeSize(BTnode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	return  LeafTreeSize(root->_left) + LeafTreeSize(root->_right) ;
}

int main() {
	
	BTnode* A = CreateTreeNode('A');
	BTnode* B = CreateTreeNode('B');
	BTnode* C = CreateTreeNode('C');
	BTnode* D = CreateTreeNode('D');
	BTnode* E = CreateTreeNode('E');
	BTnode* F = CreateTreeNode('F');

	A->_left = B;
	A->_right = C;
	B->_left = D;
	C->_left = E;
	C->_right = F;

	prevOrder(A);

	int ret = LeafTreeSize(A); 
	printf("\n");
	printf("%d\n",ret);

	return 0;
}

