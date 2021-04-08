#define _CRT_SECURE_NO_WARNINGS

#include"prework.h"

int main()
{
	int tree_size = 0 ;
	char str[1000] = {0};
	scanf("%[^\n]s", str);
	BSTree* tree = GetTree();
	BuildTree(str, &tree->root , &tree_size );
	tree->length = tree_size;
	pre_order_tree(tree);
	in_order_tree(tree);
	post_order_tree(tree);
}