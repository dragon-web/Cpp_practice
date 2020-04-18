#define _CRT_SECURE_NO_WARNINGS 


/*//前提是你写的得是个正方形的矩形
void Print(int** arr, int Row, int Line)
{
	for (int i = 0; i < Line; ++i)
	{
		for (int j = 0; j < Row; ++j)
		{
			printf("%d", arr[i][j]);
			if ((i + j) % (Row - 1) == 0 && (i + j) != 0)
			{
				printf("\n");
			}
		}
	}
}
int main()
{
	int line, row;
	printf("请输入line row");
	scanf("%d%d", &line, &row);
	int**p = (int**)malloc(sizeof(int)*line*row);
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			scanf("%d",&p[i][j]);
		}
	}
	Print( p, line, row);
	system("pause");
	return 0;
}
*/
#include<stdio.h>
#include<Windows.h>
#include<time.h>

int main()
{ 
	//A>B所以A不能为1
	int A, B, C, D, E;
	for (A = 2; A <= 9; A++)
	{
		for (B = 1; B < A; ++B)
		{
			for (C = 1; C <= 9; ++C)
			{
				for (D = 1; D <= 9; ++D)
				{
					for (E = 1; E <= 9; ++E)
					{
						for (int F = 1;  F <=9;  F++)
						{
							if ((((10 * A + D)*(B * 10 + D) == (C * 10 + D) + (E * 100 + D * 10))) && ((10 * A + D)*(B * 10 + D) == (D * 100 + F * 10 + D)) && ((C * 10 + D) + (E * 100 + D * 10)) == (D * 100 + F * 10 + D) && (A != C) && (B != C) && (C != D) && (C != E) && (B != D) && (B != E))
							{
								printf("%d %d %d %d %d %d", A, B, C, D, E,F);
							}
						}
						
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}





























