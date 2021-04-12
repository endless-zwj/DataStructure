#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//【*】宏定义一个交换函数
#define Swap( a , b ) { \
	a ^= b;\
	b ^= a;\
	a ^= b;\
} //斜杠作为连接符，将#define部分链接成一行


//【*】设计一个生成随机数的函数
void randomNum(int* arr, int n)
{
		for (int i = 0; i < n; i++)
		arr[i] = rand( ) % 100;
}

void output(int* arr, int n)
{
	printf("[");
	for (int i = 0; i < n; i++)
	{
		i && printf(" ");
		printf("%d", arr[i]);
	}
	printf("]\n");
}


//【排序1】插入排序--排升序--时间复杂度( O(N^2) )
void Insert_Sort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)//对于已排部分，已经有序。因此只要有一次
														  //不满足交换条件，便可推出内部循环(该算法更优)
			Swap(arr[j], arr[j - 1]);
	}
}

//【排序2】冒泡排序--排升序
void bubble_sort(int* arr, int n)
{
	int flag = 1; //标记待排序数是否已经有序,1表示待排，0表示已有序
	for (int i = 0; i < n && flag; i++)
	{
		flag = 0 ; //若经过一层循环还未交换，说明已经有序
		for (int j = 0; j < n - i - 1 ; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				flag = 1 ;
			}

		}
	}
}

//【排序3】归并排序--排升序
void merge_sort(int* arr, int leftPos, int rightPos)
{
	//【1】分割结束阶段--排序
	if (rightPos - leftPos <= 1)//分割成只剩下一个或两个元素,
	{
		if (rightPos - leftPos == 1 && arr[leftPos] > arr[rightPos])
			Swap(arr[leftPos], arr[rightPos]);
		return ;
	}

	//【2】递归分割
	int mid = (rightPos + leftPos) >> 1 ;
	merge_sort(arr , leftPos , mid);
	merge_sort(arr , mid + 1, rightPos);

	//【3】链接
	int* temp = (int*)malloc(sizeof(int)* (rightPos - leftPos + 1));
	int pos1 = leftPos, pos2 = mid + 1, k = 0; //pos1,pos2链接的起始地点，k存放数据的地点
	while (pos1 <= mid || pos2 <= rightPos)
	{
		//将左半部分拷贝到temp内:右半部分拷贝完,或左半部分小于右半部分的数
		if (pos2 > rightPos || (pos1 <= mid && arr[pos1] < arr[pos2]))
			temp[k++] = arr[pos1++];
		else
			temp[k++] = arr[pos2++];
	}
	memcpy(arr + leftPos, temp,(rightPos - leftPos + 1) * sizeof (int));//将temp数组的数按序号排入arr数组内
	free(temp);
}


int main()
{
	srand((unsigned int)time(0));
#define Max_Size 20
	int array[Max_Size];
	randomNum(array , Max_Size);
	output(array, Max_Size);
	bubble_sort(array , Max_Size );
	output(array, Max_Size);
	
	return 0;
}