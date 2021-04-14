#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int BinarySearch(int* nums,int std_val ,int LeftPos, int RightPos)
{
	if (LeftPos > RightPos)
		return -1;//表示没有该下标
	int mid = (LeftPos + RightPos) >> 1 ;
	if (nums[mid] > std_val) RightPos = mid - 1;
	else if (nums[mid] < std_val) LeftPos = mid + 1;
	else return mid ;
	return BinarySearch(nums, std_val, LeftPos, RightPos);
}

int main()
{
	int num[6] = { 1, 3, 5, 7, 8, 11, };
	for (int i = 0; i < 6; i++)
	{
		i&&printf(" ");
		printf("%d",num[i]);
	}
	printf("\n%d\n", BinarySearch(num, 11, 0, 5) );
	return 0;
}