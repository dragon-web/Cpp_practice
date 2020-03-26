#include"common.h"


void print(int (*arr)[3], int col, int row)
{
	int i = 0;
	int j = 0;

	for ( i = 0; i < col; i++)
	{
		for ( j = 0; j < row; j++)
		{
			printf("%d  ", arr[i][j]);
		}
	}
}

int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	//编写函数将为二维数组打印出来
	print(arr, 2, 3);







	/*char* Strcpy(char* dest, const char* src);
	char* Strcpy(char* dest, const char* src)
	{
		assert(src != NULL);
		int sz = sizeof(*src);
		for (int i = 0; i < sz; ++i)
		{
			dest[i] = src[i];
		}
		return dest;
	}


	char str[] = "asdffgg";
	Strcpy(str,"hello");
	printf("%s", str);*/

	/*int arr[10] = { 0 }; 
	printf("%p\n", arr); 
	printf("%p\n", &arr); */
	

	
	/*
	char* a[] = { "work","at","alibaba" };
	char ** p = a;
	p++;
	printf("%s", *p);*/


	/*int arr[2][5] = { 0,1,2,3,4,5,6,7,8,9 };
	int* ptr1 =(int *) (&arr + 1);
	int* ptr2 = (int *)(*(arr + 1));
	printf("%d    ",*(ptr1 - 1));
	printf("%d",*(ptr2 - 1));*/
	system("pause");
	return 0;
}