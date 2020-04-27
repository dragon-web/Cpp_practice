#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
	short i, j;
	*returnSize = 0;
	for (i = 0; i < numsSize; i = i + 2) 
		*returnSize = *returnSize + nums[i];
	int* a = (int*)malloc(*returnSize * sizeof(int));//生成一条数组
	for (i = 0, j = 0; j < *returnSize; j++) {
		if (nums[i] > 0) {
			a[j] = nums[i + 1];
			nums[i]--;
		}
		else {
			i = i + 2;
			j--;
		}
	}
	return a;
}
int main()
{
	int arr[] = { 1,2,3,5,7 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int *p = (int *)malloc(100);
	decompressRLElist(arr, length, p);

	system("pause");
	return 0;
}