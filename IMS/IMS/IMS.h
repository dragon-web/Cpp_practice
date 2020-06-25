#include"student.h"

int people;
Stu *temp = NULL;//����������ɾ��Ԫ��
void keep() 
{
	printf("(�������������)\n");
	getchar();
}
void menu()//�˵�
{
	system("color 5");
	printf("     ***********************************************************************        |\n");
	printf("  ***************************��ӭʹ��ѧ������ϵͳ*******************************    |\n");
	printf("|\t1.--ѧ����Ϣ��ע��                                                               |\n");
	printf("|\t2.--ѧ���ɼ���¼��                                                               |\n");
	printf("|\t3.--ѧ����Ϣ�޸�                                                                 |\n");
	printf("|\t4.--ѧ����Ϣ���                                                                 |\n");
	printf("|\t5.--ѧ����Ϣɾ��                                                                 |\n");
	printf("|\t6.--ɾ����Ϣ�ָ�(ֻ�ָܻ����һ����ɾ������)                                     |\n");
	printf("|\t7.--ѧ����Ϣ��ʾ                                                                 |\n");
	printf("|\t8.--ѧ����Ϣ¼���ļ�                                                             |\n");
	printf("|\t9.--�ļ���ȡѧ����Ϣ                                                             |\n");
	printf("|\t10.--ѧ����Ϣ��ѯ                                                                 |\n");
	printf("|*******************************************************************************    |\n");
	printf("|*******************************************************************************    |\n\n");
}
Stu* stu;
int n;

int isEmpey() {    //�ж��ļ��Ƿ�Ϊ��
	FILE *fp = fopen("input.CSV", "r");
	if (fp == NULL) {
		printf("�ļ���ʧ��");
		exit(0);
	}
	char ch = fgetc(fp);
	if (ch == EOF) {
		return 1;
	}
	return 0;
}

Stu* Register_Student_Information()
{
	Stu *head = (Stu*)malloc(sizeof(Stu)), *tail = NULL, *p = NULL;
	printf("��������Ҫ¼���ѧ��������\n");
	int n, i;
	scanf("%d", &n);
	people = n;
	getchar();//����һ���س�
	tail = head;
	for (i = 1; i <= n; i++) {
		p = (Stu*)malloc(sizeof(Stu));
		printf("�������%d��ѧ����ѧ�ţ�\n", i);
		scanf("%s", p->id);
		getchar();
		printf("�������%d��ѧ����������\n", i);
		scanf("%s", p->name);
		head->next = p;
		getchar();
		head = head->next;
	}
	head->next = NULL;
		printf("ע��ɹ�\n");
		return tail;
}
//��һ���ڵ�head�������κ�����
//����ѧ������ɼ�
void build_score(Stu *stu,int p) {   
		int i = 1;
		Stu * tail = stu->next;
		Stu * temp = tail;
		char arr[20];
		while (i <= people)
		{
			printf("ѧ���ɼ���û��¼�����\n");
			printf("������ѧ�ţ�\n");
			scanf("%s", arr);
			keep();
			while (temp != NULL)
			{
				if (strcmp(arr, temp->id) == 0)
				{
					printf("��ѧ�ŵ�ѧ����%s\n", temp->name);
					printf("�������ѧ����ѡ�޿�\n");
					scanf("%s", temp->course);
					keep();
					printf("��ֱ������ѧ����ѧ����ѡ�޿γɼ���ƽʱ�ɼ�,ʵ��ɼ�,���Գɼ�,�����ɼ���\n");
					scanf("%d%d%d%d", &temp->average, &temp->experiment, &temp->test, &temp->sum);
					keep();
				}
				temp = temp->next;
			}
			temp = tail;
			i++;
		}
		printf("¼��ɹ�");
		keep();
}

Stu* buildbyfile() {
	Stu *head = (Stu*)malloc(sizeof(Stu)), *tail = NULL, *p = NULL;
	FILE *fp = fopen("input.csv", "r");
	if (fp == NULL) {
		printf("�ļ���ʧ��");
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
	printf("¼��ɹ�");
	keep();
	return head;
}
void save(Stu *stu) {   
	FILE *fp = fopen("input.CSV", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ��");
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
	printf("ѧ��\t����\tѡ�޿γ�\t\tƽʱ�ɼ�\tʵ��ɼ�\t���Գɼ�\t�����ɼ�\n");
	while (stu != NULL) {
		printf("%-8s%-8s%-25s%-15d%-18d%-15d%-15d\n", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
		stu = stu->next;
	}
	keep();
}

void mydelete(Stu* stu)
{
	int  flag = 0;
	char tid[20];
	Stu *tail = stu;
	printf("��������Ҫɾ����ѧ��ѧ�ţ�\n");
	scanf("%s", tid);
	getchar();
	stu = stu->next;
	while (stu != NULL) {
		if (strcmp(stu->id, tid) == 0) {
			temp = stu;
			if (stu->next != NULL) {
				stu = stu->next;
				tail->next = stu;
			}//ɾ������βԪ��
			
			else {
				tail->next = NULL;
			}//ɾ��βԪ��
			flag = 1;
			people--;
			printf("ɾ���ɹ�\n");
			keep();
			return;
		}
		tail = stu;
		stu = stu->next;
	}
	if (flag == 0) {
		printf("ɾ��ʧ�ܣ�idΪ%s��ѧ��������\n", tid);  //��Ϣ��
		keep();
	}
	return;
}
void myinsert(Stu *stu)  //����������� 
{
	stu = stu->next;
	Stu *p = (Stu*)malloc(sizeof(Stu));

	while (stu->next != NULL) {
		stu = stu->next;
	}
	printf("��������Ҫ�����ѧ����ѧ�ţ�\n");
	scanf("%s", p->id);
	getchar();//����һ���س�
	printf("��������Ҫ�����ѧ����������\n");
	scanf("%s", p->name);
	getchar();
	printf("��������Ҫ�����ѧ���Ŀγ����֣�\n");
	scanf("%s", p->course);
	printf("��ֱ�������Ҫ�����ѧ����ƽʱ�ɼ�,ʵ��ɼ�,���Գɼ�,�ܳɼ���\n");
	scanf("%d%d%d%d", &p->average, &p->experiment, &p->test, &p->sum);
	stu->next = p;
	p->next = NULL;
	people++;
	printf("�����������\n");
	keep();
	return;

}
void change(Stu*stu) {
	stu = stu->next;
	char tid[20];
	int choose, flag = 0;
	printf("��������Ҫ�޸ĵ�ѧ��ѧ��:\n");
	scanf("%s", tid);
	while (stu->next != NULL) {
		if (strcmp(stu->id, tid) == 0) {
			flag = 1;
			break;
		}
		stu = stu->next;
	}
	printf("��ѧ��ѧ��:%s,����:%s,ѡ�޿γ�:%s,ƽʱ�ɼ�:%d,ʵ��ɼ�:%d,���Գɼ�:%d,�����ɼ�:%d\n", stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
	printf("\n1.ѧ��\n2.����\n3.ѡ�޿γ�\n4.ƽʱ�ɼ�\n5.ʵ��ɼ�\n6.���Գɼ�\n7.�����ɼ�\n0.���޸�\n");
	printf("������Ҫ�޸ĵ���Ϣ���:");
	scanf("%d", &choose);
	switch (choose) {
	case 1:
		printf("�������޸ĵ�ѧ�ţ�\n");
		scanf("%s", stu->id);
		break;
	case 2:
		printf("�������޸ĵ�������\n");
		scanf("%s", stu->name);
		break;
	case 3:
		printf("�������޸ĵ�ѡ�޿γ̣�\n");
		scanf("%s", stu->course);
		break;
	case 4:
		printf("�������޸ĵ�ƽʱ�ɼ���\n");
		scanf("%d", &stu->average);
		break;
	case 5:
		printf("�������޸ĵ�ʵ��ɼ���\n");
		scanf("%d", &stu->experiment);
		break;
	case 6:
		printf("�������޸ĵĿ��Գɼ���\n");
		scanf("%d", &stu->test);
		break;
	case 7:
		printf("������Ҫ�޸ĵ������ɼ���\n");
		scanf("%d", &stu->sum);
		break;
	case 0:
		break;
	}
	if (flag == 0) {
		printf("ɾ��ʧ�ܣ�idΪ%s��ѧ��������\n", tid);
		keep();

	}
	return;
}
void search_id(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ѧ��:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->id, temp) == 0) {

			printf("ѧ��Ϊ%s��ѧ������Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ѧ��Ϊ%s��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_name(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ��������:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->name, temp) == 0) {

			printf("ѧ������Ϊ%s��ѧ��ѧ��Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->name, stu->id, stu->course, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,����������Ϊ%s��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_course(Stu * stu) {
	char temp[20];
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ѡ�޿γ���:\n");
	scanf("%s", temp);
	while (stu != NULL) {
		if (strcmp(stu->course, temp) == 0) {

			printf("ѧ��ѡ�޿γ���Ϊ%s��ѧ��ѧ��Ϊ%s,����Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->course, stu->id, stu->name, stu->average, stu->experiment, stu->test, stu->sum);
			flag = 1;

		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ѡ�޿γ���Ϊ%s��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_average(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ƽʱ�ɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->average == temp) {

			printf("ƽʱ�ɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->average, stu->id, stu->name, stu->course, stu->experiment, stu->test, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ƽʱ�ɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_experiment(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ����ʵ��ɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->experiment == temp) {

			printf("ʵ��ɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,���Գɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->experiment, stu->id, stu->name, stu->course, stu->average, stu->test, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,������ʵ��ɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_test(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ���Ŀ��Գɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->test == temp) {

			printf("���Գɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,�����ɼ�Ϊ%d\n",
				stu->test, stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->sum);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,�����ڿ��Գɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void search_sum(Stu * stu) {
	int temp;
	int flag = 0;
	stu = stu->next;
	printf("��������Ҫ��ѯ��ѧ���������ɼ�:\n");
	scanf("%d", &temp);
	while (stu != NULL) {
		if (stu->sum == temp) {

			printf("�����ɼ�Ϊ%d��ѧ��ѧ��Ϊ%s,����Ϊ%s,ѡ�޿γ���Ϊ%s,ƽʱ�ɼ�Ϊ%d,ʵ��ɼ�Ϊ%d,���Գɼ�Ϊ%d\n",
				stu->sum, stu->id, stu->name, stu->course, stu->average, stu->experiment, stu->test);
			flag = 1;
		}
		stu = stu->next;

	}
	if (flag == 0) {
		printf("�Բ���,�����������ɼ�Ϊ%d��ѧ��\n", temp);
	}
	keep();
	return;
}
void mysearch(Stu *stu) {
	printf("����������Ҫ��ѯ�Ĺ������:\n");
	printf("1.ѧ��ѧ��\n");
	printf("2.ѧ������\n");
	printf("3.ѧ��ѡ�޿γ�\n");
	printf("4.ѧ��ƽʱ�ɼ�\n");
	printf("5.ѧ��ʵ��ɼ�\n");
	printf("6.ѧ�����Գɼ�\n");
	printf("7.ѧ�������ɼ�\n");
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
void Recover_mis_delete(Stu *head)
{
	Stu *p = head;
	temp->next = p->next;
	p->next = temp;//�����ݻָ���ͷ��
}