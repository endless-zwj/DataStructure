#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

int main()
{
	HpDataType a[] = { 23, 534, 24, 55, 66, 63, 87, 83, 12, 94 };
	Heap heap;
	InitHeap(&heap, a, sizeof(a) / sizeof (a[0]));
	for (int i = 0; i <heap._size; i++)
	{
		printf("%d ", heap._array[i]);
	}
	printf("\n");
	PushHeap(&heap, 10); 
	for (int i = 0; i <heap._size; i++)
	{
		printf("%d ", heap._array[i]);
	}
	printf("\n");
	PopHeap(&heap);
	for (int i = 0; i <heap._size; i++)
	{
		printf("%d ", heap._array[i]);
	}
	printf("\n");
	PopHeap(&heap);
	for (int i = 0; i <heap._size; i++)
	{
		printf("%d ", heap._array[i]);
	}
	printf("\n");
	return 0;
}