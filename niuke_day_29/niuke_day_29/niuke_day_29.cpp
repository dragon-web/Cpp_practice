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
*/

/*
A 2 3 4 4
B 1 1 3 3

D 3 3 4 4
*/

//printf的返回值,参数调用顺序 
//VS gcc    C99 C11(从右往左)
//前置加加和后置加加区别
//重载（后置返回的是临时对象  前置直接返回当前对象  *this &）
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

	test operator++()//前置++
	{
		++t1;
		++t2;
		return *this;
	}
	test operator++(int)//后置++
	{
		int temp1 = t1;
		int temp2 = t2;
		t1++;
		t2++;
		return test(temp1, temp2);
	}

};
//C 3 3 5 3
//将返回值（地址）存入相应的缓冲区，将缓冲区顺序入栈，打印时依次弹出这个栈
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
	//强转 截断 补全
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
	printf("%ld", pa);//代码等价
	system("pause");
	return 0;
}
*/


//CPU 有不同位数 16 32 64 字长 ：在同一时间CPU处理二进制的位数叫字长  处理字长为 8 8位CPU 32 
//字长反应了这个计算机的精度  cpu 寻址 
// 字节 （内存最小寻址单位）  一个指针的地址值对应内存中一个字节空间 32 
//寻址空间CPU对于内存寻址的能力 32 位CPU 2^32 4G地址
//寻址位数是由地址总线位数决定的 32寻址CPU 地址就是一个32位二进制数 （4Byte） 8个字节指针
//指针大小是由CPU寻址位数决定，不是字长

//编译器处理模式 32 64  CLion 