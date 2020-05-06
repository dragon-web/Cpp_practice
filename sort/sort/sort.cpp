#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<time.h>
using namespace std;

//ð������

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
	cout << "����ʱ���ǣ�"<<num << endl;
}
void Cout(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << " ";
	}
}
//�򵥿�������
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

void bubble_sort_1(int *arr, int length)//ð�������Ż�1
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
		if (flag == 0)//˵������
			break;
	}
}
void bubble_sort_2(int *arr, int length)//ð�������Ż�2  �������� �ҽ�ֹ����㣨��¼���һ�ν��������ݣ�
{
	int flag = 0;//��¼�ڼ���Ѱ�������
	int pos = 0;//������¼���һ�ν�����λ��
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
				pos = j;// ��¼���һ�ν�����λ��
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
	int pos = 0;//������¼���һ�ν�����λ��
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//ȷ����������
	{
		pos = 0;
		int j = 0;
		flag = 0;
		for (j = 0; j < k; j++)//ȷ���Ƚϴ���
		{
			if (arr[j] > arr[j + 1])
			{
				//����
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//������
				pos = j;//����Ԫ�أ���¼���һ�ν�����λ��
			}
		}
		if (flag == 0)//���û�н�����Ԫ�أ����Ѿ�����
		{
			return;
		}
		k = pos;//��һ�αȽϵ���¼λ�ü���
	}
}

void BubbleSort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int n = 0;//ͬʱ�����ֵ����С��Ҫ�����±����
	int flag = 0;
	int pos = 0;//������¼���һ�ν�����λ��
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//ȷ����������
	{
		//����Ѱ�����ֵ
		for (j = n; j < k; j++)//ȷ���Ƚϴ���
		{
			if (arr[j] > arr[j + 1])
			{
				//����
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//������
				pos = j;//����Ԫ�أ���¼���һ�ν�����λ��
			}
		}
		if (flag == 0)//���û�н�����Ԫ�أ����Ѿ�����,ֱ�ӽ���
		{
			return;
		}
		k = pos;//��һ�αȽϵ���¼λ�ü���
		//����Ѱ����Сֵ
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
		if (flag == 0)//���û�н�����Ԫ�أ����Ѿ�����,ֱ�ӽ���
		{
			return;
		}
	}
}
*/


void bubble_sort_3(int *arr, int length)//�����������ɨ��  ����Ž����ֵ���ں��棬������Сֵ���ں���
{
	int pos = 0;
	int k = length - 1;
	int flag = 0;
	int start = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < k; ++j) // �������������ֵ
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
				pos = j;
			}
		}
		for (int j = pos; j > start; --j)//����������Сֵ
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
	int arr1[] = {19,9,10,2,33,41,52,85,6,9,85,36,47,25};//��������
	//int arr1[] = { 19,9,10,2,33,41,52,85};//��������
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	//Quick_sort(arr, sz);
	//bubble_sort_1(arr, sz);
	//bubble_sort_2
	bubble_sort_3(arr1, sz);
	Cout(arr1,sz);
	system("pause");
	return 0;
}