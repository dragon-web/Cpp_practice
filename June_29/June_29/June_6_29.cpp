#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
/*
A B C D E

A:我和E都没有扶老奶奶
B：老奶奶是被C和E其中一个扶过大街的
C：老奶奶是被我和其中一个扶过大街的
D：B和C没有扶老奶奶过街
E：我没有扶老奶奶
//只有两个说的是真话

A为真 E就为真
B为假那么C句为假

C为真 D为假

D为真

*/
int main()
{
	int arr[5] = { 0 };
	for (int i = 0; i < 6; ++i)
	{
		arr[i] = 1;
		for (int j = 0; j < 6; ++j)
		{
			if (j != i)
			{
				arr[j] = 1;
			}
		}
		arr[i] = 0;
	}

	system("pause");
	return 0;
}