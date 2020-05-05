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
	//mciSendString("open 苦瓜 - 听说 (原唱_丛铭君).wav alias A", 0, 0, 0);//打开文件
	//mciSendString("play A repeat", 0, 0, 0);
	//PlaySound("C:\\Users\\飞龙\\Desktop\\Cpp_practice\\项目\\项目\\苦瓜 - 听说 (原唱_丛铭君).wav", NULL, SND_FILENAME | SND_ASYNC);
	system("C:\\Users\\飞龙\\Desktop\\Cpp_practice\\项目\\项目\\苦瓜 - 听说 (原唱_丛铭君).wav");
	cin.get();
	system("pause");
	return 0;
}
