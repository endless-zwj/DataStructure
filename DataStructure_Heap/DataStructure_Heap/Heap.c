#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

//向下调整算法(时间复杂度为 log N ) [前提: 父亲下面的 子树 都是小堆或者大堆]
void AdjustDown(HpDataType* array, int numsSize, int root) //[向下调整这里的numsSize 相当于给了一个调整的终止条件]
														   //[向上调整可直接根据下标0来判断终止，因此参数要少一个]
{
	int father = root ;         //定义父节点
	int child = father * 2 + 1; //定义左孩子 

	while (child < numsSize)    //一直向下调整到[父节点达到最下一层,即孩子节点下标越界]
	{
		//小堆[取两个孩子节点的更小值]
		if (child != numsSize - 1 && array[child] > array[child + 1])
		//定义一个小堆 注【child != numsSize -1】是防止只有左孩子的情况
		{
			child = child + 1; 
		}
		if (array[father] > array[child])
		{
			HpDataType tmp = array[child]; 
			array[child] = array[father];
			array[father] = tmp;

			//迭代，孩子父亲都往下走
			father = child ;
			child = father * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//向上调整算法[用于插入元素,保持插入后的堆结构]
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

			//迭代，让父亲和孩子都往上走
			child = father;
			father = (child - 1) / 2 ;     //这里father的值永远不会小于0，所以不要father做控制循环的条件
		}
		else
		{
			break ;
		}
	}
}

//初始化堆
void InitHeap(Heap* pheap, int* array, int numsSize) //numsSize: 数组大小(完全二叉树的节点个数)
{
	assert(pheap);

	pheap->_array = (HpDataType*)malloc(numsSize * sizeof(HpDataType));
	pheap->_capacity = numsSize;
	pheap->_size = numsSize;
	memcpy(pheap->_array, array, numsSize* sizeof(HpDataType));

	//构造一个堆[时间复杂度: O(N)]
	int i = numsSize - 1;
	i = (i - 1) / 2 ;           //直接从倒数第二层开始调整
	for ( i ; i >= 0; i--)      //从 底层遍历到顶层，使每个节点都向下调整 建一个小堆
	{
		AdjustDown(pheap->_array, numsSize, i);
	}
	
}

//销毁堆
void DestoryHeap(Heap* pheap)
{
	assert(pheap);

	free(pheap->_array);
	pheap->_array = NULL;
	pheap->_capacity = 0;
	pheap->_size = 0;
}

//堆尾插一个元素
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

//堆头删一个元素
void PopHeap(Heap* pheap)
{
	assert(pheap);

	//将第一个元素与最后一个交换
	HpDataType tmp = pheap->_array[0];
	pheap->_array[0] = pheap->_array[pheap->_size - 1];
	pheap->_array[pheap->_size - 1] = tmp ;

	--pheap->_size;

	//对第一个元素向下调整，因为交换后后面的小堆性质没发生改变
	AdjustDown(pheap->_array, pheap->_size, 0);     //将根节点传入，实现向下调整
}

//取堆顶的一个元素
HpDataType TopHeap(HpDataType* array)
{
	assert(array);
	return array[0] ;
}
