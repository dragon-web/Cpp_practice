#define _CRT_SECURE_NO_WARNINGS 
#define MAXV 9
#define INF INT_MAX
#include<iostream>
#include<stack>
#include<queue>

using namespace std;
typedef struct EdgeNode
{
	int AdjVex; // �ڽӵ���ͼ�еı��
	int RelationShip; // ͼ�ж���֮��Ĺ�ϵ������1��
	struct EdgeNode *Next; // ָ����һ�����ӵ�ָ��
} EdgeNode;

typedef struct VexNode
{
	char Name[50]; // ����������ͼ1��δ�������������������������
	int Infected; // �Ƿ�ȷ�0-δȷ� 1-��ȷ�
	struct EdgeNode *FirstEdge; // ָ�������ߵ�ָ��
} VexNode;

typedef struct ListGraph
{
	
	int n; //�ڵ����
	int e;// �ߵĸ���
	VexNode adjList[MAXV];  
}ListGraph;

void createAdjListGraph(ListGraph* &LG, int A[MAXV][MAXV], int n, int e) 
{
	int i, j;
	EdgeNode* p;
	LG = (ListGraph*)malloc(sizeof(ListGraph));
	for (i = 0; i < n; i++) {
		LG->adjList[i].FirstEdge = NULL;						//���ڽӱ�������ͷ���ָ�����ó�ֵ 
	}
	for (i = 0; i < n; i++) {									//����ڽӾ����е�ÿ��Ԫ�� 
		for (j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0) {									//����һ���� 
				p = (EdgeNode*)malloc(sizeof(EdgeNode));		//����һ������ڴ�
				p->AdjVex = j;									//����ڽӵ� 
				p->RelationShip = A[i][j];							//���Ȩֵ
				p->Next = NULL;

				p->Next = LG->adjList[i].FirstEdge;			//ͷ�巨 
				LG->adjList[i].FirstEdge = p;
			}
		}
	}
	LG->n = n;
	LG->e = e;
}
void JudgeName(int x)
{
	switch (x)
	{
	case 0:
		printf("����˽������");
		break;
	case 1:
		printf("����        ");
	case 2:
		printf("������        ");
		break;
	case 3:
		printf("�������������");
	case 4:
		printf("��˹          ");
		break;
	case 5:
		printf("ʷ�ٷ� ����   ");
	case 6:
		printf("���� ����     ");
		break;
	case 7:
		printf("�˵�  ���    ");
	case 8:
		printf("����  �Ͷ�    ");
		break;
	}

}
void displayAdjList(ListGraph* LG) {
	int i;
	EdgeNode* p;
	for (i = 0; i < MAXV; i++) {
		p = LG->adjList[i].FirstEdge;
		printf("%d:", i);
		while (p != NULL) {
			if (p->RelationShip != INF) {
				JudgeName(p->AdjVex);
				printf("%2d[%d]->", p->AdjVex, p->RelationShip);
			}
			p = p->Next;
		}
		printf(" NULL\n");
	}
}
//������ȱ���
int visitedDFS[MAXV] = { 0 };									//ȫ�����飬��¼�Ƿ����
void DFS(ListGraph* LG, int v) {
	EdgeNode* p;
	visitedDFS[v] = 1;											//��¼�ѷ��ʣ��� 1
	printf("%2d", v);											//���������
	p = LG->adjList[v].FirstEdge;								//p ָ�򶥵� v �ĵ�һ���ڽӵ�
	while (p != NULL) {
		if (visitedDFS[p->AdjVex] == 0 && p->RelationShip != INF) {	//��� p->adjVer û�����ʣ��ݹ������
			DFS(LG, p->AdjVex);
		}
		p = p->Next;										//p ָ�򶥵� v ����һ���ڽӵ�
	}
}

//������ȱ���
void BFS(ListGraph* LG, int v) {
	int ver;														//������Ӷ���
	EdgeNode* p;
	int visitedBFS[MAXV] = { 0 };									//��ʼ�����ʱ������
	queue<int>sp;	
	sp.push(v);//��ʼ�����
	printf("%2d", v);
	visitedBFS[v] = 1;												//��ӡ�����Ҫ���Ӷ���													
	while (!sp.empty()) {										//��Ϊ�ս���ѭ��
		ver = sp.front();										//���ӣ����õ�������Ϣ
		p = LG->adjList[ver].FirstEdge;								//ָ����ӵĵ�һ���ڽӵ�
		while (p != NULL) {											//���� ver �������ڽӵ�
			if (visitedBFS[p->AdjVex] == 0 && p->RelationShip != INF) {	//���û������
				printf("%2d", p->AdjVex);							//��ӡ�ö�����Ϣ
				visitedBFS[p->AdjVex] = 1;							//���ѷ���״̬
				sp.push( p->AdjVex);								//�ö������
			}
			p = p->Next;										//����һ���ڽӵ�
		}
	}
	printf("\n");
}


int main()
{
	ListGraph* LG;
	int array[MAXV][MAXV] =
	{
		{0,2,INF,INF,INF,INF,INF,INF,INF},
		{2,0,2,INF,INF,INF,INF,3,INF},
		{INF,1,0,2,2,INF,2,INF,INF},
		{INF,INF,2,0,INF,INF,INF,INF,INF},
		{INF,INF,2,INF,INF,0,1,INF,INF},
		{INF,INF,2,INF,INF,0,1,INF,INF},
		{INF,INF,INF,INF,2,1,0,INF,INF},
		{INF,3,INF,INF,INF,INF,INF,0,3},
		{INF,3,INF,INF,INF,INF,INF,3,0}
	};
	int e = 16;
	createAdjListGraph(LG, array, MAXV, e);

	printf("�ڽӱ�Ϊ��\n");
	displayAdjList(LG);
	printf("\n");

	printf("������ȱ���Ϊ��");
	DFS(LG, 0);
	printf("\n");

	printf("������ȱ���Ϊ��");
	BFS(LG, 0);
	printf("\n");
	system("pause");
	return 0;
}

