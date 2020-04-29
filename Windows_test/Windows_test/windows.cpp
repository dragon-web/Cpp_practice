#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<Windows.h>

#pragma comment(lib,"WinMM.Lib")
int main()
{
	PlayMp3();
	PlaySound("C:\\Users\\·ÉÁú\\Desktop", NULL, SND_FILENAME | SND_ASYNC);
	system("pause");
	return 0;
}
