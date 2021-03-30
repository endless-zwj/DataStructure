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

//向下调整算法
void AdjustDown(HpDataType* array, int size, int root);

//向上调整算法
void AdjustUp(HpDataType* array, int child);

//初始化堆
void InitHeap(Heap* pheap, int* array, int size);

//销毁堆
void DestoryHeap(Heap* pheap);

//堆尾插一个元素
void PushHeap(Heap* pheap, HpDataType x);

//堆头删一个元素
void PopHeap(Heap* pheap);

//取堆顶的一个元素
HpDataType TopHeap(HpDataType* x);
