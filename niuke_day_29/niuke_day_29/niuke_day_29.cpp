#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
3.���溯����ʵ�����������Ĺ����Ƿ������⣿
�еĻ���ȷ��ʽ��ʲô���� ��ʲô��������ʵ�ִ˹��ܣ�    
void swap(int* a, int* b)
{ int *p;  
p = a;     
a = b;     
b = p; }

����  Swap
*/



/*void Swap(int* a, int* b)  //a b �β�  
{
	int *p;//�����˸�ָ��
	p = a;
	a = b;
	b = p;  //����   ��������������

}*/
//3��д��
/*
void Swap(int* a, int* b)  //a b �β�  ��ȷ��д��
{
	int p = *a;
	*a = *b;
	*b = p;  //����   ��������������
}*/

//����Ϊ1 ��ͬΪ0  
/*void Swap(int* a, int* b)  //a b �β�  ��ȷ��д��
{
	*a = *a^*b;
	*b = *b^*a;
	*a = *b^*a;
}
//��ʹ����ʱ�����Ľ���

void Swap(int *a, int *b)
{
	*a = *a + *b;  //*b =  *b  ���
	*b = *a - *b;//���
	*a = *a - *b;//���
}


int main()
{
	int a1 = 1;
	int b1 = 2;
	Swap(&a1, &b1);//a b ʵ��  �β��Ƕ�ʵ�ε���ʱ��������ʱ�������������ڣ�û����������ֻ�Ǵ����ں����ڲ�
	printf("a = %d b = %d\n", a1, b1);
	system("pause");
	return 0;
}

*/



/*
struct S1
{
	char c1;
	int i;
	short s2;
};
*/
//λ  64λ  32λ  struct  

//����  2^n -1 n����

// 1  
//ɾ��5��  ѭ�� 
// 5 4 6 2 3
//�ݹ�  ѭ��

/*int main()
{
	int arr[] = {6,7,8,9,10};
	int *ptr = arr;
	*(ptr++)+=123;  
	printf("%d %d\n", *ptr, *(++ptr));//printf ���õ���˳��
	//����ָ��
	system("pause");
	return 0;
}
*/
//����ɾ��Ԫ��  ��ɾ���   
// length  6 
// 1 2 3 5 6 6
//  1 2 3 4 5  0 ~ 3  4%3  
void Rosef(int *arr,int target,int sz)
{
	while (sz != 1)//��һ����
	{
		for (int i = 0; i < sz; ++i)
		{
			if (i == target - 1)//�±��0��ʼ��
			{
				for (int j = target; j % target; ++j)
				{
					arr[j] = arr[j + 1];
				}
				sz - 1;
			}

		}


	}

}


int main()
{
	
	int arr[] = { 1,5,4,9,8,7,6 };
	int target;
	int size = sizeof(arr) / sizeof(arr[0]);//������Ԫ�ظ���
	printf("������һ��Ŀ��ֵ:\n");
	scanf("%d", target);
	Rosef(arr,target,size);
	system("pause");
	return 0;
}