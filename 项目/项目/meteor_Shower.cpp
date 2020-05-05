#include"common.h"

struct Star
{
	int x, y;
	int speed;
	int color;
}star[MAXSTAR];

struct Meteor
{
	int x, y;
	int step;
	int style;
}meteor[MAXMETEOR];

IMAGE img1, img2, img3, img4;
void initStar(int i);
void MoveStar(int i);
void initData(int i);
void initMeteor(int i);
void moveMeteor(int i);
void drawMeteor(int i);
int main()
{
	mciSendString("open 苦瓜 - 听说 (原唱_丛铭君).wav alias A", 0, 0, 0);//打开文件
	mciSendString("play A repeat", 0, 0,0);
	initgraph(1000, 600);
	int i = 0;
	initData(i);
	while (1)
	{
		cleardevice();
		for (i = 0; i < MAXSTAR; i++)
		{
			MoveStar(i);
		}
		drawMeteor(i);
		moveMeteor(i);
		Sleep(200);
	}
	_getch();
	closegraph();
	system("pause");
	return 0;
}
void initData(int i)
{
	//加载资源
	loadimage(&img1, "five-pointed_star.jpg", 40, 40);
	loadimage(&img2,"meteor_star.jpg", 40, 40);
	loadimage(&img3, "puple_star.jpg", 40, 40);
	loadimage(&img4, "star.jpg", 40, 40);
	srand((unsigned int)time(NULL));
	for (i = 0; i < MAXSTAR; ++i)
	{
		initStar(i);
	}
	for ( i = 0; i < MAXMETEOR; i++)
	{
		initMeteor(i);
	}
}

//初始化星星

void initStar(int i)
{
	star[i].x = rand() % 1000;
	star[i].y = rand() % 600;
	star[i].speed = rand()%6;
	star[i].color = RGB(star[i].speed * 51, star[i].speed * 51, star[i].speed * 51);
}

void MoveStar(int i)
{
	putpixel(star[i].x, star[i].y, star[i].color);
	star[i].x += star[i].speed;
	if (star[i].x > 1000)
	{
		putpixel(star[i].x, star[i].y, star[i].color);
	}
}

void initMeteor(int i)
{
	meteor[i].x = rand() % 2000 - 1000;
	meteor[i].y = -300;
	meteor[i].step = rand()%30 + 3;
	meteor[i].style = rand()%3 + 1;
}

void drawMeteor(int i)
{
	for (i = 0; i < MAXMETEOR; i++)
	{
		switch (meteor[i].style)
		{
		case 1:
			putimage(meteor[i].x, meteor[i].y, &img1, SRCPAINT);
			break;
		case 2:
			putimage(meteor[i].x, meteor[i].y, &img2, SRCPAINT);
			break;
		case 3:
			putimage(meteor[i].x, meteor[i].y, &img3, SRCPAINT);
			break;
		case 4:
			putimage(meteor[i].x, meteor[i].y, &img4, SRCPAINT);
			break;
		default:
			break;
		}
	}
}

void moveMeteor(int i)
{
	for (i = 0; i < MAXMETEOR; i++)
	{
		meteor[i].x += meteor[i].step;
		meteor[i].y += meteor[i].step*0.7;
	}
}