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
*/

/*
A 2 3 4 4
B 1 1 3 3

D 3 3 4 4
*/

//printf�ķ���ֵ,��������˳�� 
//VS gcc    C99 C11(��������)
//ǰ�üӼӺͺ��üӼ�����
//���أ����÷��ص�����ʱ����  ǰ��ֱ�ӷ��ص�ǰ����  *this &��
/*
class test
{
private:
	int t1, t2;
public:
	test(int num1,int num2)
	{
		t1 = num1;
		t2 = num2;
	}

	test operator++()//ǰ��++
	{
		++t1;
		++t2;
		return *this;
	}
	test operator++(int)//����++
	{
		int temp1 = t1;
		int temp2 = t2;
		t1++;
		t2++;
		return test(temp1, temp2);
	}

};
//C 3 3 5 3
//������ֵ����ַ��������Ӧ�Ļ���������������˳����ջ����ӡʱ���ε������ջ
int main()
{
	int i = 1;
	printf("%d,%d\n", ++i, ++i); 
	printf("%d,%d\n", ++i, i++); //3    5 
	system("pause");
	return 0;
} 
*/
/*int main()
{
	//10  16 4 
	long a = (long)(((double*)0) + 4);
	//long a = (long)(((int*)0) + 4);
	//
	//ǿת �ض� ��ȫ
	//int* 4 4   char* 000 
	printf("%d\n", a);
	system("pause");
	return 0;
	//0000
	//0
}

int main()
{
	double* pa = NULL;
	pa = pa + 4;
	printf("%ld", pa);//����ȼ�
	system("pause");
	return 0;
}
*/


//CPU �в�ͬλ�� 16 32 64 �ֳ� ����ͬһʱ��CPU��������Ƶ�λ�����ֳ�  �����ֳ�Ϊ 8 8λCPU 32 
//�ֳ���Ӧ�����������ľ���  cpu Ѱַ 
// �ֽ� ���ڴ���СѰַ��λ��  һ��ָ��ĵ�ֵַ��Ӧ�ڴ���һ���ֽڿռ� 32 
//Ѱַ�ռ�CPU�����ڴ�Ѱַ������ 32 λCPU 2^32 4G��ַ
//Ѱַλ�����ɵ�ַ����λ�������� 32ѰַCPU ��ַ����һ��32λ�������� ��4Byte�� 8���ֽ�ָ��
//ָ���С����CPUѰַλ�������������ֳ�

//����������ģʽ 32 64  CLion 