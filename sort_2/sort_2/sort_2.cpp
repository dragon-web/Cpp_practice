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