#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

//���µ����㷨(ʱ�临�Ӷ�Ϊ log N ) [ǰ��: ��������� ���� ����С�ѻ��ߴ��]
void AdjustDown(HpDataType* array, int numsSize, int root) //[���µ��������numsSize �൱�ڸ���һ����������ֹ����]
														   //[���ϵ�����ֱ�Ӹ����±�0���ж���ֹ����˲���Ҫ��һ��]
{
	int father = root ;         //���常�ڵ�
	int child = father * 2 + 1; //�������� 

	while (child < numsSize)    //һֱ���µ�����[���ڵ�ﵽ����һ��,�����ӽڵ��±�Խ��]
	{
		//С��[ȡ�������ӽڵ�ĸ�Сֵ]
		if (child != numsSize - 1 && array[child] > array[child + 1])
		//����һ��С�� ע��child != numsSize -1���Ƿ�ֹֻ�����ӵ����
		{
			child = child + 1; 
		}
		if (array[father] > array[child])
		{
			HpDataType tmp = array[child]; 
			array[child] = array[father];
			array[father] = tmp;

			//���������Ӹ��׶�������
			father = child ;
			child = father * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//���ϵ����㷨[���ڲ���Ԫ��,���ֲ����Ķѽṹ]
void AdjustUp(HpDataType* array, int child)
{
	int father = (child - 1) / 2;
	while (child > 0)
	{
		if (array[child] < array[father])
		{
			HpDataType tmp = array[child];
			array[child] = array[father]; 
			array[father] = tmp;

			//�������ø��׺ͺ��Ӷ�������
			child = father;
			father = (child - 1) / 2 ;     //����father��ֵ��Զ����С��0�����Բ�Ҫfather������ѭ��������
		}
		else
		{
			break ;
		}
	}
}

//��ʼ����
void InitHeap(Heap* pheap, int* array, int numsSize) //numsSize: �����С(��ȫ�������Ľڵ����)
{
	assert(pheap);

	pheap->_array = (HpDataType*)malloc(numsSize * sizeof(HpDataType));
	pheap->_capacity = numsSize;
	pheap->_size = numsSize;
	memcpy(pheap->_array, array, numsSize* sizeof(HpDataType));

	//����һ����[ʱ�临�Ӷ�: O(N)]
	int i = numsSize - 1;
	i = (i - 1) / 2 ;           //ֱ�Ӵӵ����ڶ��㿪ʼ����
	for ( i ; i >= 0; i--)      //�� �ײ���������㣬ʹÿ���ڵ㶼���µ��� ��һ��С��
	{
		AdjustDown(pheap->_array, numsSize, i);
	}
	
}

//���ٶ�
void DestoryHeap(Heap* pheap)
{
	assert(pheap);

	free(pheap->_array);
	pheap->_array = NULL;
	pheap->_capacity = 0;
	pheap->_size = 0;
}

//��β��һ��Ԫ��
void PushHeap(Heap* pheap, HpDataType x)
{
	assert(pheap);

	if (pheap->_size == pheap->_capacity)
	{
		pheap->_array = (HpDataType*)realloc(pheap->_array, sizeof(HpDataType)* pheap->_capacity * 2);
		pheap->_capacity *= 2 ;
	}
	pheap->_array[ pheap->_size++ ] = x ;
	AdjustUp(pheap->_array,  pheap->_size - 1);
}

//��ͷɾһ��Ԫ��
void PopHeap(Heap* pheap)
{
	assert(pheap);

	//����һ��Ԫ�������һ������
	HpDataType tmp = pheap->_array[0];
	pheap->_array[0] = pheap->_array[pheap->_size - 1];
	pheap->_array[pheap->_size - 1] = tmp ;

	--pheap->_size;

	//�Ե�һ��Ԫ�����µ�������Ϊ����������С������û�����ı�
	AdjustDown(pheap->_array, pheap->_size, 0);     //�����ڵ㴫�룬ʵ�����µ���
}

//ȡ�Ѷ���һ��Ԫ��
HpDataType TopHeap(HpDataType* array)
{
	assert(array);
	return array[0] ;
}
