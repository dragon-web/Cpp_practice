#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*typedef struct
{
	char no[10];
	char name[10];
	double foreign;
	double spec1;
	double spec2;
	double total;
}StudentType;
void WriteToFile();
void ReadFromFile();
int main()
{
	int select;
	do
	{
		printf("1：录入成绩2：输出成绩 0：退出\n");
		printf("请输入要执行的操作");
		cin >> select;
		switch (select)
		{
		case 1:
			WriteToFile();
			break;
		case 2:
			ReadFromFile();
			break;
		default:
			cout << "退出程序" << endl;
			break;
		}
	} while ((select == 1 || select == 2));

	system("pause");
	return 0;
}
void WriteToFile()
{
	FILE *fp = NULL;
	StudentType stu;
	char flag = 'y';
	fp = fopen("student.txt", "a");//append 以追加的方式打开文件
	if (fp == NULL)
	{
		printf("打开文件失败");
		exit(1);//以有错的方式退出程序
	}
	while (flag == 'y' || flag == 'Y')
	{
		printf("请输入考生考号：\n");
		scanf("%s", stu.no);
		printf("请输入考生姓名\n");
		scanf("%s", stu.name);
		printf("请输入学生的外语成绩：\n");
		scanf("%lf", &stu.foreign);
		printf("请输入考生的专业课一成绩：\n");
		scanf("%lf", &stu.spec1);
		printf("请输入考生的专业课二成绩：\n");
		scanf("%lf", &stu.spec2);
		stu.total = stu.foreign + stu.spec1 + stu.spec2;
		fprintf(fp, "%10s%10s%8.2f", stu.no, stu.name, stu.foreign);
		fprintf(fp, "%8.2f%8.2f%8.2f", stu.spec1, stu.spec2, stu.total);
		fputc('\n', fp);
		fflush(stdin);//将键盘输入的信息（缓冲区中的信息）刷新一下
		printf("继续输入吗？继续请输入Y或者y");
		scanf("%c", &flag);
	}
	fclose(fp);
	return;
}

void ReadFromFile()
{
	FILE* fp = NULL;
	StudentType stu;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		printf("打开文件失败");
		exit(1);
	}
	printf("   考试姓名   总分\n");
	while (!feof(fp))//当没有遇见文件结束符的时候
	{
		fscanf(fp, "%s %s", stu.no, stu.name);
		fscanf(fp, "%lf%lf%lf%lf", &stu.foreign, &stu.spec1, &stu.spec2, &stu.total);
		printf("%10s%8.2f\n", stu.name, stu.total);
		long int n;
		n = ftell(fp);
		cout << n << endl;
	}
	fclose(fp);
	return;
}

//文件指针一般打开方式下，位置指针设置在文件头
//追加打开方式下，位置指针设置在文件尾
//ftell函数 feof函数检测文件的当前位置指针
//操作成功返回filepointer文件的当前位置指针，即相对于文件开头的位移量（字节数）。否则返回-1L（L表示该常量为长整型）
//feof测试是不是在文件末尾
/*
struct _iobuf {
	char *ptr;  //文件当前位置
	int _cnt;
	char* _base;//缓冲区首地址
	int _flag;
	int _file;//文件号
	int char_buf;
	int _bufsize;//缓冲区长度
	char *_temfname;
}_iobuf;

typedef struct _iobuf FILE;

SEEK_CUR  1  文件当前位置
SEEK_END  2  文件末尾
SEEK_SET  0  文件开头
FILE* fopen(char* filename,char* mode)//分别代表 打开文件名 打开文件方式


int main()
{
	FILE* fp;
	//fp = fopen("f1.txt", "r");
	//fp = fopen("c:\\aaa\\fl.txt");
	char filename[] = "file\\f1.txt";
	fp = fopen(filename, "a+");

	system("pause");
	return 0;
}
char str[80];
fgets(str, 15, fp);
*/
//文件拷贝
void copy(char fileS[], char fileT[]);//函数声明，文件拷贝

int main()
{
	char fileS[30], fileT[30];
	cout << "请输入要复制的源文件：" << endl;
	scanf("%s", fileS);
	printf("请输入要复制的目标源文件\n");
	scanf("%s", fileT);
	copy(fileS, fileT);
	system("pause");
	return 0;
}
void copy(char fileS[], char fileT[])
{
	char ch;
	FILE *fpSource, *fpTarget;
	if ((fpSource = fopen(fileS, "r")) == NULL)
	{
		printf("打开失败\n");
		exit(1);
	}
	if ((fpTarget = fopen(fileT, "w")) == NULL)
	{
		printf("打开失败\n");
		exit(1);
	}
	while (!feof(fpSource))
	{
		ch = fgetc(fpSource);
		fputc(ch, fpTarget);
	}
	fclose(fpSource);
	fclose(fpTarget);
	printf("文件复制成功");
}