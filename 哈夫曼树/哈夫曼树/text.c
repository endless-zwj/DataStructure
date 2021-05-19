#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>

#define MAX INT_MAX
#define MAXLEAVE 30//�������Ĺ�������Ҷ�ӽڵ�Ϊ30
#define MAXTREE MAXLEAVE*2-1//����һ�ù��������Ĵ�СΪ59;(2*n-1)
#define MAXBIT 20 //�����������������Ϊ10

typedef struct {
	char character;//����ÿһ���ַ�
	int weigth;//����Ȩֵ
	int parent, Lcild, Rchild;//���常�ڵ�,���Һ��ӽڵ�.
}HTNode;

typedef struct {
	int code[MAXBIT];
	int start; //������������Ӻ�ʼ����
}HTCode;

void HuffmanTree(HTNode HuffTree[], int n) {
	int min1, min2;
	int index1,index2;
	int i, j;

	//��ʼ����������
	for ( i = 0; i < 2 * n - 1; i++) {
		HuffTree[i].weigth = 0;
		HuffTree[i].Lcild = -1;
		HuffTree[i].Rchild = -1;
		HuffTree[i].parent = -1;
	}

	printf("********************************\n\n");
	//����n��Ҷ�ӽڵ�
	for (i = 0; i < n; i++) {
		printf("�������%d���ַ�������:>",i+1);
		scanf(" %c%d", &HuffTree[i].character, &HuffTree[i].weigth);
	}

	//����һ�Ź�������
	//n��Ҷ�ӽڵ�Ĺ���������Ҫ����n-1��Сֵ
	for (i = 0; i < n-1; i++) {
		
		min1 = min2 = MAX;
		index1 = index2 = -1;

		//ÿ�δ�n+i�������ҳ���С������ֵ
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
		//����С�������ڵ���й�������ڵ�
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
	HTCode HuffCode[MAXLEAVE], cd; //����һ������������ṹ��,����ʱ����
	HTNode HuffTree[MAXTREE]; //����һ�ù�������
	printf("���������Ĵ�С:> ");
	scanf("%d", &n);
	HuffmanTree(HuffTree, n);

	for (i = 0; i < n; i++) {
		curIndex = i;
		parentIndex = HuffTree[curIndex].parent;
		cd.start = n - 1;

		//�����Ҹ�ĸ�ڵ�,����������Ϣ������cd���HuffCode�ṹ����
		while (parentIndex != -1) {
			if (HuffTree[parentIndex].Lcild == curIndex)
				cd.code[cd.start] = 0;
			else
				cd.code[cd.start] = 1;
			//���µ���
			cd.start--;
			curIndex = parentIndex;
			parentIndex = HuffTree[curIndex].parent;
		}

		//��cd�ṹ�����ݷ���HuffCode[curIndex]�µ�code����֮��
		for ( j = cd.start + 1; j < n; j++)
			HuffCode[i].code[j] = cd.code[j];
		
		//��¼ÿһ��HuffCode����ʼ�ص�
		HuffCode[i].start = cd.start + 1;

	}

	//��ӡ��HuffNode�ı���
	for (i = 0; i < n; i++) {
		printf("%c�Ĺ���������Ϊ:> ", HuffTree[i].character);
		for (j = HuffCode[i].start; j < n; j++) {
			printf("%d", HuffCode[i].code[j]);
		}
		printf("\n");
	}
	return 0;
}
