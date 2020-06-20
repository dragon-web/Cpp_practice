#include"student.h"

Stu *temp = NULL;//用来保存误删的元素
void keep() 
{
	printf("(按下任意键继续)\n");
	getchar();
}
void menu()
{
	system("color 5");
	printf("     ***********************************************************************        |\n");
	printf("  ***************************欢迎使用学生管理系统*******************************    |\n");
	printf("|\t1.--学生信息的录入                                                               |\n");
	printf("|\t2.--学生信息修改                                                                 |\n");
	printf("|\t3.--学生信息添加                                                                 |\n");
	printf("|\t4.--学生信息删除                                                                 |\n");
	printf("|\t5.--删除信息恢复(只能恢复最后一次误删的数据)                                     |\n");
	printf("|\t6.--学生信息显示                                                                 |\n");
	printf("|\t7.--学生信息录入文件                                                             |\n");
	printf("|\t8.--学生按成绩排序                                                              |\n");
	printf("|\t9.--文件读取学生信息                                                             |\n");
	printf("|\t10.--学生信息查询                                                                |\n");
	printf("|*******************************************************************************    |\n");
	printf("|*******************************************************************************    |\n\n");
}
Stu* stu;
int n;
int people = 0;

int isEmpey() {
	FILE *fp = fopen("input.CSV", "r");
	if (fp == NULL) {
		printf("文件打开失败");
		exit(0);
	}
	char ch = fgetc(fp);
	if (ch == EOF) {
		return 1;
	}
	return 0;
}

//第一个节点head不储存任何数据
Stu* build() {
	Stu *head = (Stu*)malloc(sizeof(Stu)), *tail = NULL, *p = NULL;
	printf("请输入你要录入的学生个数：\n");
	int n, i;
	scanf("%d", &n);
	people = n;
	getchar();
	tail = head;
	for (i = 1; i <= n; i++) {
		p = (Stu*)malloc(sizeof(Stu));
		printf("请输入第%d个学生的学号：\n", i);
		scanf("%s", p->id);
		getchar();
		printf("请输入第%d个学生的姓名：\n", i);
		scanf("%s", p->name);
		getchar();
		printf("请输入第%d个学生选修的课程名字：\n", i);
		scanf("%s", p->course);
		printf("请分别输入第%d个学生的平时成绩,实验成绩,考试成绩,总评成绩：\n", i);
		scanf("%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	printf("录入成功");
	keep();
	return head;
}

Stu* buildbyfile() {
	Stu *head = (Stu*)malloc(sizeof(Stu)), *tail = NULL, *p = NULL;
	FILE *fp = fopen("input.csv", "r");
	if (fp == NULL) {
		printf("文件打开失败");
		exit(0);
	}
	tail = head;
	while (!feof(fp)) {
		p = (Stu*)malloc(sizeof(Stu));
		fscanf(fp, "%s", p->id);
		fscanf(fp, "%s", p->name);
		fscanf(fp, "%s", p->course);
		fscanf(fp, "%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
		tail->next = p;
		tail = p;
		tail->next = NULL;
		people++;
	}
	printf("录入成功");
	keep();
	return head;
}
void save(Stu *stu) {
	FILE *fp = fopen("input.CSV", "w");
	if (fp == NULL) {
		printf("文件打开失败");
		exit(0);
	}
	stu = stu->next;
	while (stu != NULL) {
		fprintf(fp, "%s %s %s %d %d %d %d", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
		stu = stu->next;
		if (stu != NULL) {
			fprintf(fp, "\n");
		}
	}

}

void out(Stu*stu) {
	stu = stu->next;
	printf("学号\t姓名\t选修课程\t\t平时成绩\t实验成绩\t考试成绩\t总评成绩\n");
	while (stu != NULL) {
		printf("%-8s%-8s%-25s%-15d%-18d%-15d%-15d\n", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
		stu = stu->next;
	}
	keep();
}

void mydelete(Stu* stu) {
	int  flag = 0;
	char tid[20];
	Stu *tail = stu;
	printf("请输入你要删除的学生学号：\n");
	scanf("%s", tid);
	getchar();
	stu = stu->next;
	while (stu != NULL) {
		if (strcmp(stu->id, tid) == 0) {
			if (stu->next != NULL) {
				stu = stu->next;
				tail->next = stu;
			}
			//删除尾元素
			else {
				tail->next = NULL;
			}
			flag = 1;
			people--;
			printf("删除成功\n");
			keep();
			return;
		}
		tail = stu;
		temp = stu;
		stu = stu->next;
	}
	if (flag == 0) {
		printf("删除失败，id为%s的学生不存在\n", tid);
		keep();
	}
	return;

}
void myinsert(Stu *stu) {
	stu = stu->next;
	Stu *p = (Stu*)malloc(sizeof(Stu));

	while (stu->next != NULL) {
		stu = stu->next;
	}
	printf("请输入你要插入的学生的学号：\n");
	scanf("%s", p->id);
	getchar();
	printf("请输入你要插入的学生的姓名：\n");
	scanf("%s", p->name);
	getchar();
	printf("请输入你要插入的学生的课程名字：\n");
	scanf("%s", p->course);
	printf("请分别输入你要插入的学生的平时成绩,实验成绩,考试成绩,总成绩：\n");
	scanf("%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
	stu->next = p;
	p->next = NULL;
	people++;
	printf("数据增加完成\n");
	keep();
	return;

}
void change(Stu*stu) {
	stu = stu->next;
	char tid[20];
	int choose, flag = 0;
	printf("请输入你要修改的学生学号:\n");
	scanf("%s", tid);
	while (stu->next != NULL) {
		if (strcmp(stu->id, tid) == 0) {
			flag = 1;
			break;
		}
		stu = stu->next;
	}
	printf("该学生学号:%s,姓名:%s,选修课程:%s,平时成绩:%d,实验成绩:%d,考试成绩:%d,总评成绩:%d\n", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
	printf("\n1.学号\n2.姓名\n3.选修课程\n4.平时成绩\n5.实验成绩\n6.考试成绩\n7.总评成绩\n0.不修改\n");
	printf("请输入要修改的信息序号:");
	scanf("%d", &choose);
	switch (choose) {
	case 1:
		printf("请输入修改的学号：\n");
		scanf("%s", stu->id);
		break;
	case 2:
		printf("请输入修改的姓名：\n");
		scanf("%s", stu->name);
		break;
	case 3:
		printf("请输入修改的选修课程：\n");
		scanf("%s", stu->course);
		break;
	case 4:
		printf("请输入修改的平时成绩：\n");
		scanf("%d", &stu->average);
		break;
	case 5:
		printf("请输入修改的实验成绩：\n");
		scanf("%d", &stu->experiment);
		break;
	case 6:
		printf("请输入修改的考试成绩：\n");
		scanf("%d", &stu->test);
		break;
	case 7:
		printf("请输入要修改的总评成绩：\n");
		scanf("%d", &stu->sum);
		break;
	case 0:
		break;
	}
	if (flag == 0) {
		printf("删除失败，id为%s的学生不存在\n", tid);
		keep();

	}
	return;
}
void search_id(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的学号:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->id, temp) == 0) {

			printf("学号为%s的学生姓名为%s,选修课程名为%s,平时成绩为%d,实验成绩为%d,考试成绩为%d,总评成绩为%d\n",
				stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在学号为%s的学生\n", temp);
	}
	keep();
	return;
}
void search_name(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的姓名:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->name, temp) == 0) {

			printf("学生姓名为%s的学生学号为%s,选修课程名为%s,平时成绩为%d,实验成绩为%d,考试成绩为%d,总评成绩为%d\n",
				stu->name, stu->id, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在姓名为%s的学生\n", temp);
	}
	keep();
	return;
}
void search_course(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的选修课程名:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {

			printf("学生选修课程名为%s的学生学号为%s,姓名为%s,平时成绩为%d,实验成绩为%d,考试成绩为%d,总评成绩为%d\n",
				stu->course, stu->id, stu->name, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在选修课程名为%s的学生\n", temp);
	}
	keep();
	return;
}
void search_average(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的平时成绩:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->average == temp) {

			printf("平时成绩为%d的学生学号为%s,姓名为%s,选修课程名为%s,实验成绩为%d,考试成绩为%d,总评成绩为%d\n",
				stu->average, stu->id, stu->name, stu->course, stu->experiment, stu->test, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在平时成绩为%d的学生\n", temp);
	}
	keep();
	return;
}
void search_experiment(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的实验成绩:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->experiment == temp) {

			printf("实验成绩为%d的学生学号为%s,姓名为%s,选修课程名为%s,平时成绩为%d,考试成绩为%d,总评成绩为%d\n",
				stu->experiment, stu->id, stu->name, stu->course, stu->average, stu->test, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在实验成绩为%d的学生\n", temp);
	}
	keep();
	return;
}
void search_test(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的考试成绩:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->test == temp) {

			printf("考试成绩为%d的学生学号为%s,姓名为%s,选修课程名为%s,平时成绩为%d,实验成绩为%d,总评成绩为%d\n",
				stu->test, stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在考试成绩为%d的学生\n", temp);
	}
	keep();
	return;
}
void search_sum(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("请输入你要查询的学生的总评成绩:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->sum == temp) {

			printf("总评成绩为%d的学生学号为%s,姓名为%s,选修课程名为%s,平时成绩为%d,实验成绩为%d,考试成绩为%d\n",
				stu->sum, stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("对不起,不存在总评成绩为%d的学生\n", temp);
	}
	keep();
	return;
}
void mysearch(Stu *stu) {
	printf("请输入你需要查询的功能序号:\n");
	printf("1.学生学号\n");
	printf("2.学生姓名\n");
	printf("3.学生选修课程\n");
	printf("4.学生平时成绩\n");
	printf("5.学生实验成绩\n");
	printf("6.学生考试成绩\n");
	printf("7.学生总评成绩\n");
	int t;
	scanf("%d", &t);
	switch (t) {
	case 1:
		system("cls");
		search_id(stu);
		system("cls");
		break;
	case 2:
		system("cls");
		search_name(stu);
		system("cls");
		break;
	case 3:
		system("cls");
		search_course(stu);
		system("cls");
		break;
	case 4:
		system("cls");
		search_average(stu);
		system("cls");
		break;
	case 5:
		system("cls");
		search_experiment(stu);
		system("cls");
		break;
	case 6:
		system("cls");
		search_test(stu);
		system("cls");
		break;
	case 7:
		system("cls");
		search_sum(stu);
		system("cls");
		break;
	}
}

void myswap(Stu *p, Stu *q) {
	Stu buf = *p;
	*p = *q;
	*q = buf;
	return;
}
void quicksortbytest(Stu *p, int low, int high) {
	int i = low;//low,high储存下来,递归需要用到。
	int j = high;
	Stu st = p[low];
	int key = p[low].test;//快排比较基准数
	if (low > high) {
		return;
	}
	while (low < high)//顺序很重要 先从右边开始找
	{
		while (low < high && key >= p[high].test) {
			high--;
		}
		while (low < high && key <= p[low].test) {
			low++;
		}
		myswap(&p[low], &p[high]);
	}
	//哨兵low已经等于哨兵high , 处于中间
	p[i] = p[low];
	p[low] = st;
	quicksortbytest(p, i, low - 1);//继续处理左边的，这是一个递归的过程
	quicksortbytest(p, low + 1, j);//继续处理右边的，这是一个递归的过程
}

//快排同理
void quicksortbysum(Stu *p, int low, int high) {
	int i = low;//low,high储存下来,递归需要用到。
	int j = high;
	Stu st = p[low];
	int key = p[low].sum;//快排比较基准数
	if (low > high) {
		return;
	}
	while (low < high)//顺序很重要 先从右边开始找
	{
		while (low < high && key >= p[high].sum) {
			high--;
		}
		while (low < high && key <= p[low].sum) {
			low++;
		}
		myswap(&p[low], &p[high]);
	}
	//哨兵low已经等于哨兵high , 处于中间
	p[i] = p[low];
	p[low] = st;
	quicksortbysum(p, i, low - 1);//继续处理左边的，这是一个递归的过程
	quicksortbysum(p, low + 1, j);//继续处理右边的，这是一个递归的过程
}

void sortbyscore(Stu *stu) {
	int k;
	stu = stu->next;
	Stu* temp = stu;
	int  i;
	Stu *p = (Stu*)malloc(sizeof(Stu)*people);
	stu = temp;
	for (i = 0; i < people; i++) {
		p[i].average = stu->average;
		p[i].test = stu->test;
		p[i].experiment = stu->experiment;
		p[i].sum = stu->sum;
		strcpy(p[i].id, stu->id);
		strcpy(p[i].name, stu->name);
		strcpy(p[i].course, stu->course);
		stu = stu->next;
	}
	printf("请输入排序（从高到低）标准的序号:\n");
	printf("1.考试成绩:\n");
	printf("2.总评成绩:\n");
	scanf("%d", &k);
	switch (k) {
	case 1:
		quicksortbytest(p, 0, people - 1);
		break;
	case 2:
		quicksortbysum(p, 0, people - 1);
		break;
	default:
		printf("对不起，不存在这个排序选项。\n");
		keep();
		return;
	}
	stu = temp;
	for (i = 0; i < people; i++) {
		stu->average = p[i].average;
		stu->test = p[i].test;
		stu->experiment = p[i].experiment;
		stu->sum = p[i].sum;
		strcpy(stu->id, p[i].id);
		strcpy(stu->name, p[i].name);
		strcpy(stu->course, p[i].course);
		stu = stu->next;
	}
	printf("排序完成，排序后的结果请使用主界面的2：浏览学生信息功能进行查看。\n");
	keep();
	return;
}

void Recover_mis_delete(Stu *head)
{
	Stu *p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;//将数据恢复在末尾
}