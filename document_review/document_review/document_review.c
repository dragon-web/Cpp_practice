#include"common.h"

struct Student
{
	char name[20];
	size_t age;
};

int main()
{
	struct Student s = {"уехЩ",20};
	FILE* pf = fopen("Test.txt", "wb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
/*	fwrite(&s, sizeof(struct Student), 1, pf);*/
	fread(&s, sizeof(struct Student), 1, pf);
	printf("%s%d", s.name, s.age);
	fclose(pf);
	pf = NULL;
	system("pause");
	return 0;
}