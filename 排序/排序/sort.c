#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/***************************************************
				插入排序思想:
	    从数组的第二个位置起,依次将该位置上的每个元素
	往前面的有序数组中合适的位置插入.
	    该插入的过程中需要实现数据的移动,例如排升序的
	时候,我们要将有序数组中大于待插入值的数往后移
	动,为待插入的数空出位置,让其进行插入.
****************************************************/
void InsertSort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int tmp = arr[i];
		int end = i - 1;
		while (end >= 0) {
			if (arr[end] > tmp) {
				swap(&arr[end], &arr[end + 1]);
				--end;
			}
			else {
				break;
			}
		}
		//程序走到这一步,有两种情况,arr[end]>tmp 
		//或者end小于0,但无论哪种情况,end+1位置都被
		//空置下来,我们需将tmp插入至此
		arr[end + 1] = tmp;
	}
}


void ShellSort(int* arr, int n) {
	int grap = n;
	//先对数组进行预排序,将数组近似有序
	//即将大的数集中排在后面,小的数集中排在前面
	while (grap > 1) {
		//每次缩小grap时,要保证grap必须大于1
		grap = (grap / 3 + 1 ); 
		for (int i = grap; i < n; i++) {
			int tmp = arr[i];
			int end = i - grap;
			while (end >= 0) {
				if (arr[end] > tmp) {
					swap(&arr[end], &arr[end + grap]);
					end -= grap;
				}
				else {
					break;
				}
			}
			arr[end + grap] = tmp;
		}
	}
}

//选择排序优化版--遍历一遍,同时找出最大最小值的下标
void ElectSort(int* arr, int n) {
	for (int count = 0; count < n/2; ++count) {
		int i = count ;
		int max_index = i;
		int min_index = i;
		for ( ; i < n-count ; ++i) {
			if (arr[max_index] < arr[i]) max_index = i;
			if (arr[min_index] > arr[i]) min_index = i;
		}
		//下面要进行两次操作,操作过程中可能会改变最大值
		//的下标或者最小值的下标,因此进行一次交换后要对
		//下标的合法性进行检查
		swap(&arr[count], &arr[min_index]);
		//在把最大值下标的数与最后一个元素交换之前,要判断
		//最大值的下标是否改变
		if (max_index == i)  max_index = min_index;
		swap(&arr[max_index], &arr[n-count-1]);
	}
}

void BubbleSort(int* arr, int n) {
	int flag = 1;
	for (int i = 0; i<(n-1)&& flag ; i++) {
		flag = 0;
		for (int j = 0; j < (n - 1 - i); j++) {
			if (arr[j + 1] < arr[j]) {
				swap(&arr[j], &arr[j + 1]);
				flag = 1;;
			} 
		}
	}
}

void adjustDown(int* arr, int father, int n) {
	int child = father * 2 + 1;
	while (child < n) {
		if (child + 1 < n && arr[child + 1] > arr[child]) child += 1; //左孩子变为右孩子
		if (arr[child] > arr[father]) {
			swap(&arr[child], &arr[father]);
			father = child; //父节点往下走,孩子节点也往下走
			child = father * 2 + 1;
		}
		else {
			break;
		}
	}
}

//递归实现向下调整算法
void pro_adjustDown(int* arr, int father, int n) {
	int child = father * 2 + 1;
	if (child >= n) return;

	if (child + 1 < n && arr[child + 1] > arr[child]) child += 1; //左孩子变为右孩子
	if (arr[child] > arr[father]) {
		swap(&arr[child], &arr[father]);
		pro_adjustDown(arr, child, n);
	}
}

void HeapSort(int* arr, int n) {
	//构建一个大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		pro_adjustDown(arr, i, n);
	}
	//逐个将堆顶的元素往下交换,达成升序的目的
	while (n--) {
		swap(&arr[0], &arr[n]);
		pro_adjustDown(arr, 0 , n);
	}
}

