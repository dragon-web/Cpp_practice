#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
3.下面函数想实现两数交换的功能是否有问题？
有的话正确形式是什么？还 有什么方法可以实现此功能？    
void swap(int* a, int* b)
{ int *p;  
p = a;     
a = b;     
b = p; }

调试  Swap
*/



/*void Swap(int* a, int* b)  //a b 形参  
{
	int *p;//定义了个指针
	p = a;
	a = b;
	b = p;  //交换   变量的生命周期

}*/
//3种写法
/*
void Swap(int* a, int* b)  //a b 形参  正确的写法
{
	int p = *a;
	*a = *b;
	*b = p;  //交换   变量的生命周期
}*/

//相异为1 相同为0  
/*void Swap(int* a, int* b)  //a b 形参  正确的写法
{
	*a = *a^*b;
	*b = *b^*a;
	*a = *b^*a;
}
//不使用临时变量的交换

void Swap(int *a, int *b)
{
	*a = *a + *b;  //*b =  *b  求和
	*b = *a - *b;//相减
	*a = *a - *b;//相减
}


int main()
{
	int a1 = 1;
	int b1 = 2;
	Swap(&a1, &b1);//a b 实参  形参是对实参的临时拷贝，临时拷贝的生命周期（没特殊声明）只是存在于函数内部
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
//位  64位  32位  struct  

//次数  2^n -1 n层塔

// 1  
//删第5个  循环 
// 5 4 6 2 3
//递归  循环

/*int main()
{
	int arr[] = {6,7,8,9,10};
	int *ptr = arr;
	*(ptr++)+=123;  
	printf("%d %d\n", *ptr, *(++ptr));//printf 调用调用顺序
	//数组指针
	system("pause");
	return 0;
}
*/
//数组删除元素  增删查改   
// length  6 
// 1 2 3 5 6 6
//  1 2 3 4 5  0 ~ 3  4%3  
void Rosef(int *arr,int target,int sz)
{
	while (sz != 1)//活一个人
	{
		for (int i = 0; i < sz; ++i)
		{
			if (i == target - 1)//下标从0开始的
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
	int size = sizeof(arr) / sizeof(arr[0]);//看数组元素个数
	printf("请输入一个目标值:\n");
	scanf("%d", target);
	Rosef(arr,target,size);
	system("pause");
	return 0;
}