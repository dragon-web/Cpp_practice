#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

//�����㷨���ȶ��ԣ���ͬ�����ݵ����λ��������ǰ�󱣳ֲ����˵��������㷨���ȶ���
//ԭ���㷨�� �������������Դ�������������Ķ�����Դ�������������������

//ѡ������
//ԭ�����������ҳ�Ԫ��ͬ��ĩβ��Ԫ�ؽ��н���
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
		int temp = FindMaxValue_Index(arr, k);//�ҵ�ֵ���Ԫ�ص��±�
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
//ѡ�������Ż�  ��findmax_index��ɶ�

//��������
/*int _Partition_1(int *ar,int left,int right)
{
	int key = ar[left];
	while (left < right)
	{
		while (left < right && ar[right] >= key)
			right--;
		Swap(&ar[left], &ar[right]);
		while (left < right && ar[left] < key)
			left++;
		Swap(&ar[left], &ar[right]);
	}
	return left;
}
*/
//�����ϣ��������O��nƽ�������������в����ʣ����ڵ�2��Ԫ��û�����ڹ����ӣ���
/*void shell_sort(int *arr, int length)
{
	int gap;
	for (gap = 3; gap > 0; gap--)
	{

	}


}*/

//��������
//1,5,6,8, 3, 4, 2, 15, 96, 7, 85, 9, 82
void InsertSort_1(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tmp = ar[i];
		int j = i;
		while (j > left && tmp < ar[j - 1])//�������ֶ�
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = tmp;
	}
}
/*void Insert_sort_1(int *arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	for (int i = left + 1; i < right; ++i)//���ò���������ѭ��
	{
		int temp = arr[i];
		int j = i;
		while (j > left&&temp < arr[j - 1]);
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}
*/
void InsertSort_2(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		ar[0] = ar[i];
		int j = i;
		while (ar[0] < ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = ar[0];
	}
}


int main()
{
	int arr[] = { 1,5,6,8,3,4,2,15,96,7,85,9,82};
//	int arr[] = { 2,15,96,7 };

	int sz = sizeof(arr) / sizeof(arr[0]);
//	int p = FindMaxValue_Index(arr, sz);
	InsertSort_1(arr,0, sz-1);
	Print(arr, sz);
	system("pause");
	return 0;
}