#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
//start �Ǵ�������λ��
/*void Swap(int &a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
//�󶥶�
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
void Exchange(int i, int n)//�����Ҷ�ӽ�������㽻�� 
{
	int temp;
	temp = a[i];
	a[i] = a[n];
	a[n] = temp;

}
//�ݹ鴴���Ķ���
void Created(int n)
{
	if (n == 2) {//��ֻʣ������ʱ��ֱ�ӱȽϴ�С ��������� Ȼ�������С�� 
		if (a[0] > a[1]) {
			printf("%d %d\n", a[0], a[1]);
		}
		else
			printf("%d %d\n", a[1], a[0]);
		return;
	}
	int i;
	for (i = n / 2 - 1; i >= 0; i--) //�Ƚ�ÿһ�����������Ҷ�ӽ��Ĵ�С   ���ҽ����ڸ�����Ҷ�ӽ�������㽻�� 
	{//���һ��������ǵ�n/2�� ���ǵ�һ�����±�Ϊ0  �������һ��������±�Ϊn/2-1 
		if (a[2 * i + 1] > a[i] && 2 * i + 1 < n)//�����ӽ��бȽ� 
			Exchange(i, 2 * i + 1);
		if (a[2 * i + 2] > a[i] && 2 * i + 2 < n)//���Һ��ӽ��бȽ�    
			Exchange(i, 2 * i + 2);
	}
	int t;
	t = a[0];//����һ������������һ��Ҷ�ӽ�㻥�� 
	a[0] = a[n - 1];
	a[n - 1] = t;
	printf("%d ", a[n - 1]);//������Ľ�� 
	Created(n - 1);//��������Ľ�㵯�� 
}

int main()
{
	int  n;
	printf("��������Ҫ�����Ԫ�صĸ�����");
	scanf("%d", &n);
	printf("������%d��Ԫ��:", n);
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &a[j]);
	}
	Created(n);
	system("pause");
	return 0;
}