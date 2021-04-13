#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//��*��Ϊ�������������
void randInt(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
}

//��*����������
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}

//��*����ӡ����
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


//��1��ѡ������--������--ʱ�临�Ӷ�:O(N^2)
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

//��2����������--������--ʱ�临�Ӷ�O(N*LogN)
//    ������ָ�뷨��:
//����ֵ����Ϊ��׼ֵ����ָ�뿪ʼ�����ҵ�һ����std_valС��ֵ�������׼ֵ��λ��
//�ٴ���ָ��������ҵ�һ����std_val���ֵ������ԭ��ָ���λ��
void Quick_Sort(int* arr, int leftPos, int RightPos)
{
	if (leftPos > RightPos)
		return;
	int std_val = arr[leftPos];
	int start_Pos = leftPos;
	int end_Pos = RightPos; //ԭʼ����ָ�벻�ܸģ���Ϊ����Ҫ���еݹ����
	while (start_Pos < end_Pos)
	{
		while (start_Pos < end_Pos && arr[end_Pos] > std_val) end_Pos--;//�ҵ���һ����std_valС��ֵ��ǰ��
		arr[start_Pos++] = arr[end_Pos];
		while (start_Pos < end_Pos && arr[start_Pos] < std_val) start_Pos++;//�ҵ���һ����std_val���ֵ�ź���
		arr[end_Pos--] = arr[start_Pos];
	}
	arr[start_Pos] = std_val;
	Quick_Sort(arr, leftPos, start_Pos);//start_Pos��Ϊ����һ�εݹ����ָ��
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