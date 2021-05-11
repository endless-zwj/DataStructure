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
				��������˼��:
	    ������ĵڶ���λ����,���ν���λ���ϵ�ÿ��Ԫ��
	��ǰ������������к��ʵ�λ�ò���.
	    �ò���Ĺ�������Ҫʵ�����ݵ��ƶ�,�����������
	ʱ��,����Ҫ�����������д��ڴ�����ֵ����������
	��,Ϊ����������ճ�λ��,������в���.
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
		//�����ߵ���һ��,���������,arr[end]>tmp 
		//����endС��0,�������������,end+1λ�ö���
		//��������,�����轫tmp��������
		arr[end + 1] = tmp;
	}
}


void ShellSort(int* arr, int n) {
	int grap = n;
	//�ȶ��������Ԥ����,�������������
	//����������������ں���,С������������ǰ��
	while (grap > 1) {
		//ÿ����Сgrapʱ,Ҫ��֤grap�������1
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

//ѡ�������Ż���--����һ��,ͬʱ�ҳ������Сֵ���±�
void ElectSort(int* arr, int n) {
	for (int count = 0; count < n/2; ++count) {
		int i = count ;
		int max_index = i;
		int min_index = i;
		for ( ; i < n-count ; ++i) {
			if (arr[max_index] < arr[i]) max_index = i;
			if (arr[min_index] > arr[i]) min_index = i;
		}
		//����Ҫ�������β���,���������п��ܻ�ı����ֵ
		//���±������Сֵ���±�,��˽���һ�ν�����Ҫ��
		//�±�ĺϷ��Խ��м��
		swap(&arr[count], &arr[min_index]);
		//�ڰ����ֵ�±���������һ��Ԫ�ؽ���֮ǰ,Ҫ�ж�
		//���ֵ���±��Ƿ�ı�
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
		if (child + 1 < n && arr[child + 1] > arr[child]) child += 1; //���ӱ�Ϊ�Һ���
		if (arr[child] > arr[father]) {
			swap(&arr[child], &arr[father]);
			father = child; //���ڵ�������,���ӽڵ�Ҳ������
			child = father * 2 + 1;
		}
		else {
			break;
		}
	}
}

//�ݹ�ʵ�����µ����㷨
void pro_adjustDown(int* arr, int father, int n) {
	int child = father * 2 + 1;
	if (child >= n) return;

	if (child + 1 < n && arr[child + 1] > arr[child]) child += 1; //���ӱ�Ϊ�Һ���
	if (arr[child] > arr[father]) {
		swap(&arr[child], &arr[father]);
		pro_adjustDown(arr, child, n);
	}
}

void HeapSort(int* arr, int n) {
	//����һ�����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		pro_adjustDown(arr, i, n);
	}
	//������Ѷ���Ԫ�����½���,��������Ŀ��
	while (n--) {
		swap(&arr[0], &arr[n]);
		pro_adjustDown(arr, 0 , n);
	}
}

