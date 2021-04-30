#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include"BinaryTree.h"

BTnode* CreateTreeNode(BTDataType x) {
	BTnode* newNode = (BTnode*)malloc(sizeof(BTnode));
	newNode->val = x;
	newNode->_left = NULL;
	newNode->_right = NULL;

	return newNode;
}


//k����ݹ����
int TreeLevelSize(BTnode* root, int k) {
	//����ݹ鵽�սڵ�,�򷵻�0;
	if (root == NULL) {
		return 0;
	}
	//����ݹ鵽��k��,�򷵻�1
	if (k == 1) {
		return 1;
	}
	//���εݹ�ò����������
	return TreeLevelSize(root->_left, k - 1) +
		TreeLevelSize(root->_right, k - 1);

}

int main() {

	BTnode* A = CreateTreeNode('A');
	BTnode* B = CreateTreeNode('B');
	BTnode* C = CreateTreeNode('C');
	BTnode* D = CreateTreeNode('D');
	BTnode* E = CreateTreeNode('E');
	BTnode* F = CreateTreeNode('F');
	BTnode* G = CreateTreeNode('G');


	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = G;
	C->_left = E;
	C->_right = F;

	

	printf("%d\n", TreeLevelSize(A, 3));
	printf("3\n");
	printf("3\n");

	return 0;
}