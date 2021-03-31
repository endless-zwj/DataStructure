#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void Swap(int* a, int*b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整算法
void AdjustDown(int* array, int numsSize, int root)
{
	int father = root ;
	int child = father * 2 + 1;

	while (child < numsSize)
	{
		//建小堆
		if (child + 1 < numsSize && array[child +1] < array[child ])
		{
			child = child + 1;
		}

		//迭代
		if (array[child] < array[father])
		{
			Swap(&array[child] , &array[father]);

			father = child;
			child = father * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

//堆排序---升序建大堆，降序建小堆
void HeapSort(int* array, int numsSize)
{
	int i = numsSize - 1;

	//构造一个堆
	for ( i; i >= 0; i--)
	{
		AdjustDown(array ,numsSize ,i);
	}

	int total = numsSize - 1;
	for (total; total > 0; --total )
	{
		Swap(&array[0], &array[total]) ; //将首元素(这里即最小的元素）与最后一个元素交换
										 //并让堆的大小减一。因为父节点的两棵子树任然为小堆，因此
										 //对根节点向下调整，得到一个小堆，第二小的元素又到了堆顶
		AdjustDown(array, total, 0); 
	}

}

int main()
{
	int i = 0;
	int flag = 0;  //记录层数,用来判断每层的元素个数
	int count = 1; //记录每层元素的个数，用来判断打印是否要换行
	int array[] = {11 ,22 ,33,44,55,66,77,88,99,111};
	int numsSize = sizeof(array) / sizeof(array[0]);

	printf("堆:\n");
	for (; i < numsSize; i++)
	{
		printf("%d " , array[i]);
		//按层打印每个节点
		if (count == pow(2.0, flag))// pow()用于计算每行的元素个数
		{
			count = 0 ; //换行时，第二行的元素为零
			flag++;     //换行后层数++;
			printf("\n");
		}
		count++;
	}
	printf("\n");

	printf("排序后\n");
	HeapSort(array, numsSize);
	for ( i = 0  ; i < numsSize; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}