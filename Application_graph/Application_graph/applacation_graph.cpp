#define _CRT_SECURE_NO_WARNINGS 
#define MAXV 9
#define INF INT_MAX
#include<iostream>
#include<stack>
#include<queue>

using namespace std;
typedef struct EdgeNode
{
	int AdjVex; // 邻接点在图中的编号
	int RelationShip; // 图中顶点之间的关系（见表1）
	struct EdgeNode *Next; // 指向下一个孩子的指针
} EdgeNode;

typedef struct VexNode
{
	char Name[50]; // 人物姓名（图1中未给出姓名的人物可自行命名）
	int Infected; // 是否确诊（0-未确诊； 1-已确诊）
	struct EdgeNode *FirstEdge; // 指向首条边的指针
} VexNode;

typedef struct ListGraph
{
	
	int n; //节点个数
	int e;// 边的个数
	VexNode adjList[MAXV];  
}ListGraph;

void createAdjListGraph(ListGraph* &LG, int A[MAXV][MAXV], int n, int e) 
{
	int i, j;
	EdgeNode* p;
	LG = (ListGraph*)malloc(sizeof(ListGraph));
	for (i = 0; i < n; i++) {
		LG->adjList[i].FirstEdge = NULL;						//给邻接表中所有头结点指针域置初值 
	}
	for (i = 0; i < n; i++) {									//检查邻接矩阵中的每个元素 
		for (j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0) {									//存在一条边 
				p = (EdgeNode*)malloc(sizeof(EdgeNode));		//申请一个结点内存
				p->AdjVex = j;									//存放邻接点 
				p->RelationShip = A[i][j];							//存放权值
				p->Next = NULL;

				p->Next = LG->adjList[i].FirstEdge;			//头插法 
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
		printf("伊万卡私人助理");
		break;
	case 1:
		printf("伊万卡        ");
	case 2:
		printf("特朗普        ");
		break;
	case 3:
		printf("特朗普贴身随从");
	case 4:
		printf("彭斯          ");
		break;
	case 5:
		printf("史蒂夫 米勒   ");
	case 6:
		printf("凯迪 米勒     ");
		break;
	case 7:
		printf("彼得  达顿    ");
	case 8:
		printf("威廉  巴顿    ");
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
//深度优先遍历
int visitedDFS[MAXV] = { 0 };									//全局数组，记录是否遍历
void DFS(ListGraph* LG, int v) {
	EdgeNode* p;
	visitedDFS[v] = 1;											//记录已访问，置 1
	printf("%2d", v);											//输出顶点编号
	p = LG->adjList[v].FirstEdge;								//p 指向顶点 v 的第一个邻接点
	while (p != NULL) {
		if (visitedDFS[p->AdjVex] == 0 && p->RelationShip != INF) {	//如果 p->adjVer 没被访问，递归访问它
			DFS(LG, p->AdjVex);
		}
		p = p->Next;										//p 指向顶点 v 的下一个邻接点
	}
}

//广度优先遍历
void BFS(ListGraph* LG, int v) {
	int ver;														//定义出队顶点
	EdgeNode* p;
	int visitedBFS[MAXV] = { 0 };									//初始化访问标记数组
	queue<int>sp;	
	sp.push(v);//初始点进队
	printf("%2d", v);
	visitedBFS[v] = 1;												//打印并标记要出队顶点													
	while (!sp.empty()) {										//队为空结束循环
		ver = sp.front();										//出队，并得到出队信息
		p = LG->adjList[ver].FirstEdge;								//指向出队的第一个邻接点
		while (p != NULL) {											//查找 ver 的所有邻接点
			if (visitedBFS[p->AdjVex] == 0 && p->RelationShip != INF) {	//如果没被访问
				printf("%2d", p->AdjVex);							//打印该顶点信息
				visitedBFS[p->AdjVex] = 1;							//置已访问状态
				sp.push( p->AdjVex);								//该顶点进队
			}
			p = p->Next;										//找下一个邻接点
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

	printf("邻接表为：\n");
	displayAdjList(LG);
	printf("\n");

	printf("深度优先遍历为：");
	DFS(LG, 0);
	printf("\n");

	printf("广度优先遍历为：");
	BFS(LG, 0);
	printf("\n");
	system("pause");
	return 0;
}

