#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<windows.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<mmsystem.h>
#include<Windows.h>
#include<fstream>
#pragma comment(lib,"winmm.lib")
using namespace std;
int main()
{
	//mciSendString("open ��� - ��˵ (ԭ��_������).wav alias A", 0, 0, 0);//���ļ�
	//mciSendString("play A repeat", 0, 0, 0);
	//PlaySound("C:\\Users\\����\\Desktop\\Cpp_practice\\��Ŀ\\��Ŀ\\��� - ��˵ (ԭ��_������).wav", NULL, SND_FILENAME | SND_ASYNC);
	system("C:\\Users\\����\\Desktop\\Cpp_practice\\��Ŀ\\��Ŀ\\��� - ��˵ (ԭ��_������).wav");
	cin.get();
	system("pause");
	return 0;
}
