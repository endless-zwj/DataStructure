#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>

#define MAX INT_MAX
#define MAXLEAVE 30//定义最大的哈夫曼树叶子节点为30
#define MAXTREE MAXLEAVE*2-1//定义一棵哈夫曼树的大小为59;(2*n-1)
#define MAXBIT 20 //定义哈夫曼树最大编码为10

typedef struct {
	char character;//定义每一个字符
	int weigth;//定义权值
	int parent, Lcild, Rchild;//定义父节点,左右孩子节点.
}HTNode;

typedef struct {
	int code[MAXBIT];
	int start; //哈夫曼树编码从后开始计数
}HTCode;

void HuffmanTree(HTNode HuffTree[], int n) {
	int min1, min2;
	int index1,index2;
	int i, j;

	//初始化哈夫曼树
	for ( i = 0; i < 2 * n - 1; i++) {
		HuffTree[i].weigth = 0;
		HuffTree[i].Lcild = -1;
		HuffTree[i].Rchild = -1;
		HuffTree[i].parent = -1;
	}

	printf("********************************\n\n");
	//输入n个叶子节点
	for (i = 0; i < n; i++) {
		printf("请输入第%d个字符及概率:>",i+1);
		scanf(" %c%d", &HuffTree[i].character, &HuffTree[i].weigth);
	}

	//构造一颗哈夫曼树
	//n个叶子节点的哈夫曼树需要查找n-1最小值
	for (i = 0; i < n-1; i++) {
		
		min1 = min2 = MAX;
		index1 = index2 = -1;

		//每次从n+i个数中找出最小的两个值
		for (j = 0; j < n + i; j++) { 
			if (HuffTree[j].weigth < min1 && HuffTree[j].parent == -1) {
				min2 = min1;
			    index2 = index1;
				min1 = HuffTree[j].weigth;
			    index1 = j;
			}
			else if (HuffTree[j].weigth < min2 && HuffTree[j].parent == -1) {
				min2 = HuffTree[j].weigth;
				index2 = j;
			}
		}
		//将最小的两个节点进行构造出父节点
		HuffTree[n + i].weigth = min1 + min2;
		HuffTree[n + i].Lcild = index1;
		HuffTree[n + i].Rchild = index2;
		HuffTree[index1].parent = n + i;
		HuffTree[index2].parent = n + i;
	}
}

int main()  {
	int i, j;
	int curIndex , parentIndex ,n;
	HTCode HuffCode[MAXLEAVE], cd; //定义一个哈夫曼编码结构体,和临时变量
	HTNode HuffTree[MAXTREE]; //定义一棵哈夫曼树
	printf("请输入树的大小:> ");
	scanf("%d", &n);
	HuffmanTree(HuffTree, n);

	for (i = 0; i < n; i++) {
		curIndex = i;
		parentIndex = HuffTree[curIndex].parent;
		cd.start = n - 1;

		//往上找父母节点,并将编码信息拷贝到cd这个HuffCode结构体中
		while (parentIndex != -1) {
			if (HuffTree[parentIndex].Lcild == curIndex)
				cd.code[cd.start] = 0;
			else
				cd.code[cd.start] = 1;
			//往下迭代
			cd.start--;
			curIndex = parentIndex;
			parentIndex = HuffTree[curIndex].parent;
		}

		//将cd结构体数据放入HuffCode[curIndex]下的code数组之中
		for ( j = cd.start + 1; j < n; j++)
			HuffCode[i].code[j] = cd.code[j];
		
		//记录每一个HuffCode的起始地点
		HuffCode[i].start = cd.start + 1;

	}

	//打印出HuffNode的编码
	for (i = 0; i < n; i++) {
		printf("%c的哈夫曼编码为:> ", HuffTree[i].character);
		for (j = HuffCode[i].start; j < n; j++) {
			printf("%d", HuffCode[i].code[j]);
		}
		printf("\n");
	}
	return 0;
}
