#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
//start 是传进来的位置
/*void Swap(int &a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
//大顶堆
void AdjustDown(int *arr,int length,int start)
{
	while (2*start+1 < length)
	{
		int child = 2 * start + 1;
		if (arr[child] < arr[child + 1])
			child++;
		if (arr[start] < arr[child])
		{
			Swap(arr[start], arr[child]);
		}
		start = child;
	}
}
/* void HeapSort(int *arr,int n)
{
	int i = 0;
	while (i <= n)
	{
		AdjustDown(arr, n, i);
		Swap(arr[n], arr[0]);
		--n;
	}
}
void AdjustDown(int *arr, int length, int i)
{
	int nChild;
	for (; 2 * i + 1 < length; i = nChild)
	{
		nChild = 2 * i + 1;
		if (nChild <length - 1 && arr[nChild + 1] > arr[nChild])
			++nChild;
		if (arr[i] < arr[nChild])
		{
			Swap(arr[i], arr[nChild]);
		}
		else
			break;
	}
}
void HeapSort(int *arr, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; --i)
	{
		AdjustDown(arr, i, n);
	}
	for (i = n - 1; i > 0; --i)
	{
		Swap(arr[0], arr[i]);
		AdjustDown(arr, 0, i);
	}
}

int main()
{
	int arr[] = { 2,65,7,1,6,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//AdjustDown(arr, n, 0);
	HeapSort(arr, n);
	for (auto& e : arr)
	{
		cout << e<<" ";
	}
	system("pause");
	return 0;
}*/

#include<stdio.h>

int a[100];
void Exchange(int i, int n)//将最大叶子结点与根结点交换 
{
	int temp;
	temp = a[i];
	a[i] = a[n];
	a[n] = temp;

}
//递归创建的堆排
void Created(int n)
{
	if (n == 2) {//当只剩两个的时候，直接比较大小 先输出最大的 然后输出最小的 
		if (a[0] > a[1]) {
			printf("%d %d\n", a[0], a[1]);
		}
		else
			printf("%d %d\n", a[1], a[0]);
		return;
	}
	int i;
	for (i = n / 2 - 1; i >= 0; i--) //比较每一个根结点与其叶子结点的大小   并且将大于根结点的叶子结点与根结点交换 
	{//最后一个根结点是第n/2个 但是第一个数下标为0  所以最后一个根结点下标为n/2-1 
		if (a[2 * i + 1] > a[i] && 2 * i + 1 < n)//与左孩子进行比较 
			Exchange(i, 2 * i + 1);
		if (a[2 * i + 2] > a[i] && 2 * i + 2 < n)//与右孩子进行比较    
			Exchange(i, 2 * i + 2);
	}
	int t;
	t = a[0];//将第一个根结点与最后一个叶子结点互换 
	a[0] = a[n - 1];
	a[n - 1] = t;
	printf("%d ", a[n - 1]);//输出最大的结点 
	Created(n - 1);//将是输出的结点弹出 
}

int main()
{
	int  n;
	printf("请输入需要排序的元素的个数：");
	scanf("%d", &n);
	printf("请输入%d个元素:", n);
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &a[j]);
	}
	Created(n);
	system("pause");
	return 0;
}