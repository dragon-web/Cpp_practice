#define _CRT_SECURE_NO_WARNINGS 
#define N 10
#include <stdio.h>
#include<stdlib.h>
struct student
{
	int num; char name[11];
	float ma; float c;
}stu[N];
int main()
{
	FILE *fp;
	int i;
	if ((fp = fopen("D:\\tc\\students.txt", "wt+")) == NULL)
	{
		printf("���ļ�����!"); exit(0);
	}
	printf("������ֱ�����ѧ�ţ�������ѧ�ɼ���C���Գɼ�:\n");
	for (i = 0; i < N; i = i + 1)
	{
		scanf("%d%s%f%f", &stu[i].num, stu[i].name, &stu[i].ma, &stu[i].c);
	}
	fwrite(&stu[0], sizeof(struct student), N, fp);
	rewind(fp); for (i = 0; i < N; i = i + 1)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);
		printf("%d %s %.3f %.3f\n", stu[i].num, stu[i].name, stu[i].ma, stu[i].c);
	}
	fclose(fp);
	system("pause");
	return 0;
}
