#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//��*���궨��һ����������
#define Swap( a , b ) { \
	a ^= b;\
	b ^= a;\
	a ^= b;\
} //б����Ϊ���ӷ�����#define�������ӳ�һ��


//��*�����һ������������ĺ���
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


//������1����������--������--ʱ�临�Ӷ�( O(N^2) )
void Insert_Sort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)//�������Ų��֣��Ѿ��������ֻҪ��һ��
														  //�����㽻������������Ƴ��ڲ�ѭ��(���㷨����)
			Swap(arr[j], arr[j - 1]);
	}
}

//������2��ð������--������
void bubble_sort(int* arr, int n)
{
	int flag = 1; //��Ǵ��������Ƿ��Ѿ�����,1��ʾ���ţ�0��ʾ������
	for (int i = 0; i < n && flag; i++)
	{
		flag = 0 ; //������һ��ѭ����δ������˵���Ѿ�����
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

//������3���鲢����--������
void merge_sort(int* arr, int leftPos, int rightPos)
{
	//��1���ָ�����׶�--����
	if (rightPos - leftPos <= 1)//�ָ��ֻʣ��һ��������Ԫ��,
	{
		if (rightPos - leftPos == 1 && arr[leftPos] > arr[rightPos])
			Swap(arr[leftPos], arr[rightPos]);
		return ;
	}

	//��2���ݹ�ָ�
	int mid = (rightPos + leftPos) >> 1 ;
	merge_sort(arr , leftPos , mid);
	merge_sort(arr , mid + 1, rightPos);

	//��3������
	int* temp = (int*)malloc(sizeof(int)* (rightPos - leftPos + 1));
	int pos1 = leftPos, pos2 = mid + 1, k = 0; //pos1,pos2���ӵ���ʼ�ص㣬k������ݵĵص�
	while (pos1 <= mid || pos2 <= rightPos)
	{
		//����벿�ֿ�����temp��:�Ұ벿�ֿ�����,����벿��С���Ұ벿�ֵ���
		if (pos2 > rightPos || (pos1 <= mid && arr[pos1] < arr[pos2]))
			temp[k++] = arr[pos1++];
		else
			temp[k++] = arr[pos2++];
	}
	memcpy(arr + leftPos, temp,(rightPos - leftPos + 1) * sizeof (int));//��temp����������������arr������
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