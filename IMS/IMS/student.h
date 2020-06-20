#pragma once
#include"common.h"

struct student {
	char id[20];
	char name[10];
	char course[30];
	int  average;
	int  experiment;
	int  test;
	int  sum;
	struct student *next;
};
typedef struct student Stu;

typedef struct StuList
{
	struct StuNode *first;
	struct StuNode *last;
	size_t sapce;
}StuList;

