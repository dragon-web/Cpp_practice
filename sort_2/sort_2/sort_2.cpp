#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

//排序算法的稳定性：相同的数据的相对位置在排序前后保持不变就说这个排序算法是稳定的
//原地算法： 不依赖额外的资源或者依赖少数的额外资源，仅靠输出来覆盖输入

//选择排序：
//原理：从序列中找出元素同最末尾的元素进行交换
void Swap(int *a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int FindMaxValue_Index(int* arr,int length)
{
	int max = arr[0];
	int index = 0;
	if (length == 1)
	{
		return index;
	}
	for (int i = 0; i < length; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

void Selection_sort(int* arr,int length)
{
	int k = length;
	for (int i = 0; i < length; ++i)
	{
		int temp = FindMaxValue_Index(arr, k);//找到值最大元素的下标
		Swap(&arr[temp], &arr[k-1]);
		k--;
	}
}

void Print(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i]<<"  ";
	}
}
//选择排序优化  将findmax_index变成堆
int main()
{
	int arr[] = { 1,5,6,8,3,4,2,15,96,7,85,9,82};
//	int arr[] = { 2,15,96,7 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	int p = FindMaxValue_Index(arr, sz);
	Selection_sort(arr, sz);
	Print(arr, sz);
	system("pause");
	return 0;
}