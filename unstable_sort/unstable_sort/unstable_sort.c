#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//【*】为数组生成随机数
void randInt(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
}

//【*】交换函数
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}

//【*】打印数组
void output(int* arr, int n)
{
	printf("[");
	for (int i = 0; i < n; i++)
	{
		i&&printf(" ");
		printf("%d",arr[i]);
	}
	printf("]\n");
}


//【1】选择排序--排升序--时间复杂度:O(N^2)
void Elect_Sort(int* arr, int n)
{
	for (int i = 0; i < n ; i++)
	{
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[index] > arr[j])
				index = j;
		}
		swap(&arr[i], &arr[index]);
	}
}

//【2】快速排序--排升序--时间复杂度O(N*LogN)
//    【左右指针法】:
//将左值设置为标准值，右指针开始，先找到一个比std_val小的值，放入标准值的位置
//再从左指针出发，找到一个比std_val大的值，放入原右指针的位置
void Quick_Sort(int* arr, int leftPos, int RightPos)
{
	if (leftPos > RightPos)
		return;
	int std_val = arr[leftPos];
	int start_Pos = leftPos;
	int end_Pos = RightPos; //原始左右指针不能改，因为后面要进行递归操作
	while (start_Pos < end_Pos)
	{
		while (start_Pos < end_Pos && arr[end_Pos] > std_val) end_Pos--;//找到第一个比std_val小的值放前面
		arr[start_Pos++] = arr[end_Pos];
		while (start_Pos < end_Pos && arr[start_Pos] < std_val) start_Pos++;//找到第一个比std_val大的值放后面
		arr[end_Pos--] = arr[start_Pos];
	}
	arr[start_Pos] = std_val;
	Quick_Sort(arr, leftPos, start_Pos);//start_Pos成为了下一次递归的右指针
	Quick_Sort(arr, start_Pos + 1, RightPos);
	return; 
}

int main()
{
	srand((unsigned int)time(0));
#define Max_Size 20
	int arr_elect[Max_Size];
	randInt(arr_elect, Max_Size);
	printf("Elect_Sort:> \n");
	output(arr_elect, Max_Size);
	Elect_Sort(arr_elect, Max_Size);
	output(arr_elect, Max_Size);

	int arr_Quick[Max_Size];
	randInt(arr_Quick, Max_Size);
	printf("\nQuick_Sort:> \n");
	output(arr_Quick, Max_Size);
	Elect_Sort(arr_Quick, Max_Size);
	output(arr_Quick, Max_Size);

	return 0;
}