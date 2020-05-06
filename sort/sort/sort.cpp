#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<time.h>
using namespace std;

//冒泡排序

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int* arr,int length)
{
	clock_t start, finish;
	start = clock();
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	finish = clock();
	double num = difftime(finish, start);
	cout << "运行时间是："<<num << endl;
}
void Cout(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << " ";
	}
}
//简单快速排序
void Quick_sort(int* arr, int sz)
{
	for (int i = 0; i < sz-1; ++i)
	{
		for (int j = i+1; j < sz; ++j)
		{
			if (arr[i] > arr[j])
			{
				Swap(&arr[i], &arr[j]);
			}
		}
	}
}

void bubble_sort_1(int *arr, int length)//冒泡排序优化1
{
	int flag = 0;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//说明有序
			break;
	}
}
void bubble_sort_2(int *arr, int length)//冒泡排序优化2  部分有序 找截止有序点（记录最后一次交换的数据）
{
	int flag = 0;//记录第几次寻找最长有序集
	int pos = 0;//用来记录最后一次交换的位置
	int k = length - 1;
	for (int i = 0; i < length-1; ++i)
	{
		pos = 0;
		flag = 0;
		for (int j = 0; j < k; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
				pos = j;// 记录最后一次交换的位置
			}
		}
		if (flag == 0)
			break;
		k = pos;
	}
}

/*void BubbleSort(int arr[], int len)
{
	int i = 0;
	int tmp = 0;
	int flag = 0;
	int pos = 0;//用来记录最后一次交换的位置
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//确定排序趟数
	{
		pos = 0;
		int j = 0;
		flag = 0;
		for (j = 0; j < k; j++)//确定比较次数
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//加入标记
				pos = j;//交换元素，记录最后一次交换的位置
			}
		}
		if (flag == 0)//如果没有交换过元素，则已经有序
		{
			return;
		}
		k = pos;//下一次比较到记录位置即可
	}
}

void BubbleSort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int n = 0;//同时找最大值的最小需要两个下标遍历
	int flag = 0;
	int pos = 0;//用来记录最后一次交换的位置
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//确定排序趟数
	{
		//正向寻找最大值
		for (j = n; j < k; j++)//确定比较次数
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//加入标记
				pos = j;//交换元素，记录最后一次交换的位置
			}
		}
		if (flag == 0)//如果没有交换过元素，则已经有序,直接结束
		{
			return;
		}
		k = pos;//下一次比较到记录位置即可
		//反向寻找最小值
		for (j = k; j > n; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
				flag = 1;
			}
		}
		n++;
		if (flag == 0)//如果没有交换过元素，则已经有序,直接结束
		{
			return;
		}
	}
}
*/


void bubble_sort_3(int *arr, int length)//正反交替进行扫描  正向放将最大值放在后面，反向将最小值放在后面
{
	int pos = 0;
	int k = length - 1;
	int flag = 0;
	int start = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < k; ++j) // 正向搜索到最大值
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
				pos = j;
			}
		}
		for (int j = pos; j > start; --j)//反向搜索最小值
		{
			if (arr[j] < arr[j-1])
			{
				Swap(&arr[j - 1], &arr[j]);
			}
		}
		start++;
		k--;
	}
}
int main()
{
	int arr[] = { 1,2,3,5,7};
	int arr1[] = {19,9,10,2,33,41,52,85,6,9,85,36,47,25};//部分有序
	//int arr1[] = { 19,9,10,2,33,41,52,85};//部分有序
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	//Quick_sort(arr, sz);
	//bubble_sort_1(arr, sz);
	//bubble_sort_2
	bubble_sort_3(arr1, sz);
	Cout(arr1,sz);
	system("pause");
	return 0;
}