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
		printf("1��¼��ɼ�2������ɼ� 0���˳�\n");
		printf("������Ҫִ�еĲ���");
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
			cout << "�˳�����" << endl;
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
	fp = fopen("student.txt", "a");//append ��׷�ӵķ�ʽ���ļ�
	if (fp == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);//���д�ķ�ʽ�˳�����
	}
	while (flag == 'y' || flag == 'Y')
	{
		printf("�����뿼�����ţ�\n");
		scanf("%s", stu.no);
		printf("�����뿼������\n");
		scanf("%s", stu.name);
		printf("������ѧ��������ɼ���\n");
		scanf("%lf", &stu.foreign);
		printf("�����뿼����רҵ��һ�ɼ���\n");
		scanf("%lf", &stu.spec1);
		printf("�����뿼����רҵ�ζ��ɼ���\n");
		scanf("%lf", &stu.spec2);
		stu.total = stu.foreign + stu.spec1 + stu.spec2;
		fprintf(fp, "%10s%10s%8.2f", stu.no, stu.name, stu.foreign);
		fprintf(fp, "%8.2f%8.2f%8.2f", stu.spec1, stu.spec2, stu.total);
		fputc('\n', fp);
		fflush(stdin);//�������������Ϣ���������е���Ϣ��ˢ��һ��
		printf("���������𣿼���������Y����y");
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
		printf("���ļ�ʧ��");
		exit(1);
	}
	printf("   ��������   �ܷ�\n");
	while (!feof(fp))//��û�������ļ���������ʱ��
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

//�ļ�ָ��һ��򿪷�ʽ�£�λ��ָ���������ļ�ͷ
//׷�Ӵ򿪷�ʽ�£�λ��ָ���������ļ�β
//ftell���� feof��������ļ��ĵ�ǰλ��ָ��
//�����ɹ�����filepointer�ļ��ĵ�ǰλ��ָ�룬��������ļ���ͷ��λ�������ֽ����������򷵻�-1L��L��ʾ�ó���Ϊ�����ͣ�
//feof�����ǲ������ļ�ĩβ
/*
struct _iobuf {
	char *ptr;  //�ļ���ǰλ��
	int _cnt;
	char* _base;//�������׵�ַ
	int _flag;
	int _file;//�ļ���
	int char_buf;
	int _bufsize;//����������
	char *_temfname;
}_iobuf;

typedef struct _iobuf FILE;

SEEK_CUR  1  �ļ���ǰλ��
SEEK_END  2  �ļ�ĩβ
SEEK_SET  0  �ļ���ͷ
FILE* fopen(char* filename,char* mode)//�ֱ���� ���ļ��� ���ļ���ʽ


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
//�ļ�����
void copy(char fileS[], char fileT[]);//�����������ļ�����

int main()
{
	char fileS[30], fileT[30];
	cout << "������Ҫ���Ƶ�Դ�ļ���" << endl;
	scanf("%s", fileS);
	printf("������Ҫ���Ƶ�Ŀ��Դ�ļ�\n");
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
		printf("��ʧ��\n");
		exit(1);
	}
	if ((fpTarget = fopen(fileT, "w")) == NULL)
	{
		printf("��ʧ��\n");
		exit(1);
	}
	while (!feof(fpSource))
	{
		ch = fgetc(fpSource);
		fputc(ch, fpTarget);
	}
	fclose(fpSource);
	fclose(fpTarget);
	printf("�ļ����Ƴɹ�");
}