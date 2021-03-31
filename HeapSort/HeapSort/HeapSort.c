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

//���µ����㷨
void AdjustDown(int* array, int numsSize, int root)
{
	int father = root ;
	int child = father * 2 + 1;

	while (child < numsSize)
	{
		//��С��
		if (child + 1 < numsSize && array[child +1] < array[child ])
		{
			child = child + 1;
		}

		//����
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

//������---���򽨴�ѣ�����С��
void HeapSort(int* array, int numsSize)
{
	int i = numsSize - 1;

	//����һ����
	for ( i; i >= 0; i--)
	{
		AdjustDown(array ,numsSize ,i);
	}

	int total = numsSize - 1;
	for (total; total > 0; --total )
	{
		Swap(&array[0], &array[total]) ; //����Ԫ��(���Ｔ��С��Ԫ�أ������һ��Ԫ�ؽ���
										 //���öѵĴ�С��һ����Ϊ���ڵ������������ȻΪС�ѣ����
										 //�Ը��ڵ����µ������õ�һ��С�ѣ��ڶ�С��Ԫ���ֵ��˶Ѷ�
		AdjustDown(array, total, 0); 
	}

}

int main()
{
	int i = 0;
	int flag = 0;  //��¼����,�����ж�ÿ���Ԫ�ظ���
	int count = 1; //��¼ÿ��Ԫ�صĸ����������жϴ�ӡ�Ƿ�Ҫ����
	int array[] = {11 ,22 ,33,44,55,66,77,88,99,111};
	int numsSize = sizeof(array) / sizeof(array[0]);

	printf("��:\n");
	for (; i < numsSize; i++)
	{
		printf("%d " , array[i]);
		//�����ӡÿ���ڵ�
		if (count == pow(2.0, flag))// pow()���ڼ���ÿ�е�Ԫ�ظ���
		{
			count = 0 ; //����ʱ���ڶ��е�Ԫ��Ϊ��
			flag++;     //���к����++;
			printf("\n");
		}
		count++;
	}
	printf("\n");

	printf("�����\n");
	HeapSort(array, numsSize);
	for ( i = 0  ; i < numsSize; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}