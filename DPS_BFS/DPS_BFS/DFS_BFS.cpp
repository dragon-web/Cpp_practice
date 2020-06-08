#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stack>
#include<queue>
/*
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
*/


#include<stdio.h>
#include<malloc.h>

#define MAXV 7					//��󶥵����
#define INF 32767				//���� �� 
//�� == INF ,int �͵����Χ��2λ��= 2^(2*8-1)��TC��������intռ��2���ֽڣ���VC��LGCC��������intռ��4���ֽ�
//ͼ��Graph
//���㣺Vertex
//�ڽӣ�Adjacency
//����Matrix
//��List
//�ߣ�Edge 
//������ȱ�����Depth First Search ��DFS�� 
//������ȱ�����Breadth First Search ��BFS�� 
typedef struct eNode {
	int adjVer;					//�ñߵ��ڽӵ��� 
	int weight;					//�ñߵĵ���Ϣ����Ȩֵ 
	struct eNode* nextEdge;		//ָ����һ���ߵ�ָ�� 
}EdgeNode; 						//�������߽������� 

typedef struct vNode {
	EdgeNode* firstEdge;		//ָ���һ���߽�� 
}VNode; 						//�������ڽӱ��ͷ������� 

typedef struct list {
	int n;						//�������
	int e;						//����
	VNode adjList[MAXV];		//�ڽӱ��ͷ�������    
}ListGraph;						//������������ͼ�ڽӱ�����    

typedef struct queue {				//����˳��� 
	int front;						//��ͷָ�� 
	char data[MAXV];				//��Ŷ���Ԫ�� 
	int rear;						//��βָ�� 
}SqQueue; 							//struct Queue �ı���

//��ʼ������ 
void initQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));	//����һ���ռ� 
	q->front = q->rear = -1;				//�� -1 
}

//�ж϶����Ƿ�Ϊ��
bool emptyQueue(SqQueue*& q) {
	if (q->front == q->rear) {				//��ָ���βָ����ȣ�˵��Ϊ�� 
		return true;						//������ 
	}
	else {
		return false;						//���ؼ� 
	}
}

//������
int enQueue(SqQueue*& q, char c) {
	if (q->rear == MAXV - 1) {				//�ж϶����Ƿ����� 
		return -1;							//���� -1
	}
	q->rear++;								//ͷָ��� 1 
	q->data[q->rear] = c;					//��ֵ 
	return c;								//���� c
}

//������ 
int deQueue(SqQueue*& q, char ch) {
	if (q->front == q->rear) {				//�ж��Ƿ���� 
		return -1;							//���ؼ� -1
	}
	q->front++;								//βָ��� 1 
	ch = q->data[q->front];					//ȡֵ 
	return ch;								//���� ch
}

//����ͼ���ڽӱ� 
void createAdjListGraph(ListGraph* &LG, int A[MAXV][MAXV], int n, int e) {
	int i, j;
	EdgeNode* p;
	LG = (ListGraph*)malloc(sizeof(ListGraph));
	for (i = 0; i < n; i++) {
		LG->adjList[i].firstEdge = NULL;						//���ڽӱ�������ͷ���ָ�����ó�ֵ 
	}
	for (i = 0; i < n; i++) {									//����ڽӾ����е�ÿ��Ԫ�� 
		for (j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0) {									//����һ���� 
				p = (EdgeNode*)malloc(sizeof(EdgeNode));		//����һ������ڴ�
				p->adjVer = j;									//����ڽӵ� 
				p->weight = A[i][j];							//���Ȩֵ
				p->nextEdge = NULL;

				p->nextEdge = LG->adjList[i].firstEdge;			//ͷ�巨 
				LG->adjList[i].firstEdge = p;
			}
		}
	}
	LG->n = n;
	LG->e = e;
}

//����ڽӱ� 
void displayAdjList(ListGraph* LG) {
	int i;
	EdgeNode* p;
	for (i = 0; i < MAXV; i++) {
		p = LG->adjList[i].firstEdge;
		printf("%d:", i);
		while (p != NULL) {
			if (p->weight != INF) {
				printf("%2d[%d]->", p->adjVer, p->weight);
			}
			p = p->nextEdge;
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
	p = LG->adjList[v].firstEdge;								//p ָ�򶥵� v �ĵ�һ���ڽӵ�
	while (p != NULL) {
		if (visitedDFS[p->adjVer] == 0 && p->weight != INF) {	//��� p->adjVer û�����ʣ��ݹ������
			DFS(LG, p->adjVer);
		}
		p = p->nextEdge;										//p ָ�򶥵� v ����һ���ڽӵ�
	}
}

//������ȱ���
void BFS(ListGraph* LG, int v) {
	int ver;														//������Ӷ���
	EdgeNode* p;
	SqQueue* sq;													//����ָ��
	initQueue(sq);													//��ʼ������
	int visitedBFS[MAXV] = { 0 };									//��ʼ�����ʱ������
	enQueue(sq, v);													//��ʼ�����
	printf("%2d", v);
	visitedBFS[v] = 1;												//��ӡ�����Ҫ���Ӷ���													
	while (!emptyQueue(sq)) {										//��Ϊ�ս���ѭ��
		ver = deQueue(sq, v);										//���ӣ����õ�������Ϣ
		p = LG->adjList[ver].firstEdge;								//ָ����ӵĵ�һ���ڽӵ�
		while (p != NULL) {											//���� ver �������ڽӵ�
			if (visitedBFS[p->adjVer] == 0 && p->weight != INF) {	//���û������
				printf("%2d", p->adjVer);							//��ӡ�ö�����Ϣ
				visitedBFS[p->adjVer] = 1;							//���ѷ���״̬
				enQueue(sq, p->adjVer);								//�ö������
			}
			p = p->nextEdge;										//����һ���ڽӵ�
		}
	}
	printf("\n");
}

int main() {
	ListGraph* LG;
	int array[MAXV][MAXV] = {
		{  0,  4,  6,  6,INF,INF,INF},
		{INF,  0,  1,INF,  7,INF,INF},
		{INF,INF,  0,INF,  6,  4,INF},
		{INF,INF,  2,  0,INF,  5,INF},
		{INF,INF,INF,INF,  0,INF,  6},
		{INF,INF,INF,INF,  1,  0,  8},
		{INF,INF,INF,INF,INF,INF,  0}
	};

	int e = 12;
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