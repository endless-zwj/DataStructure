#define _CRT_SECURE_NO_WARNINGS

#define HpDataType int  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Heap
{
	HpDataType* _array; 
	int _size;
	int _capacity;
}Heap;

//���µ����㷨
void AdjustDown(HpDataType* array, int size, int root);

//���ϵ����㷨
void AdjustUp(HpDataType* array, int child);

//��ʼ����
void InitHeap(Heap* pheap, int* array, int size);

//���ٶ�
void DestoryHeap(Heap* pheap);

//��β��һ��Ԫ��
void PushHeap(Heap* pheap, HpDataType x);

//��ͷɾһ��Ԫ��
void PopHeap(Heap* pheap);

//ȡ�Ѷ���һ��Ԫ��
HpDataType TopHeap(HpDataType* x);
