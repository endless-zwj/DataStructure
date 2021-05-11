#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

int main() {
	int arr[] = { 1, 4, 2, 54, 43, -1, 42, 2543, 53 };
	int len = sizeof(arr) / sizeof(arr[0]);

	Print(arr, len);
	HeapSort(arr, len);
	Print(arr, len);

	system("pause");
	return 0;
}
