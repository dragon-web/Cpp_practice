#define _CRT_SECURE_NO_WARNINGS 
#define K 3
#define RADIX 10
#include<iostream>
#include<list>

/*using namespace std;

 list<int> list1(RADIX); // 0 1 2 3 4 5 6 7 8 9

//278
int GetKey(int value, int k)
{
	int key;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void Distribute(int *ar, int left, int right, int k)
{
	for (int i = left; i <= right; ++i)
	{
		int key = GetKey(ar[i], k);
		list1.push_back(&list1[key], ar[i]);
	}
}

void Collect(int *ar)
{
	int k = 0;
	for (int i = 0; i < RADIX; ++i)
	{
		if (!list1.empty()(&list[i]))
		{
			SListNode *p = list[i].first->next;
			while (p != NULL)
			{
				ar[k++] = p->data;
				p = p->next;
			}
		}
	}

	for (int i = 0; i < RADIX; ++i)
		SListClear(&list[i]);
}
void RadixSort(int *ar, int left, int right)
{
	for (int i = 0; i < RADIX; ++i)
	{
		SListInit(&list[i]);
	}
	for (int i = 0; i < K; ++i)
	{
		//1 分发
		Distribute(ar, left, right, i);
		//2 回收
		Collect(ar);
	}
}

int main()
{

	system("pause");
	return 0;
}
*/


void RadixSort(int *arr, int length)
{
	int* p = (int*)malloc(sizeof(int)*length);//申请桶空间
	memset(p, 0,length*sizeof(int));//将这个桶空间初始化为不可能出现的值
	for (int i = 0; i < length; ++i)
	{
		p[arr[i] - 1] += 1;
	}
	for (int j = 0; j < length; ++j)
	{
		if (p[j] == 0)
			continue;
		else
			while (p[j])
			{
				printf("%d ", j + 1);
				p[j]--;
			}
	}

}
int main()
{
	int arr[] = { 4,8,6,9,7,2,2,1,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	RadixSort(arr, sz);
	system("pause");
	return 0;
}


















/*int GetKey(int value, int k)
{
	int key;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void Distribute(int *ar, int left, int right, int k)
{
	for (int i = left; i <= right; ++i)
	{
		int key = GetKey(ar[i], k);
		SListPushBack(&list[key], ar[i]);
	}
}
int main()
{
	list<int> list1;


	//278
	


	void Collect(int *ar)
	{
		int k = 0;
		for (int i = 0; i < RADIX; ++i)
		{
			if (!SListEmpty(&list[i]))
			{
				SListNode *p = list[i].first->next;
				while (p != NULL)
				{
					ar[k++] = p->data;
					p = p->next;
				}
			}
		}

		for (int i = 0; i < RADIX; ++i)
			SListClear(&list[i]);
	}
	void RadixSort(int *ar, int left, int right)
	{
		for (int i = 0; i < RADIX; ++i)
		{
			SListInit(&list[i]);
		}
		for (int i = 0; i < K; ++i)
		{
			//1 分发
			Distribute(ar, left, right, i);
			//2 回收
			Collect(ar);
		}
	}
	system("pasue");
	return 0;
}
*/

