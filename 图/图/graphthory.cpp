#define _CRT_SECURE_NO_WARNINGS 
#define DataType char
#include<iostream>
#include<stack>
using namespace std;
//欧拉定理： 如果没有一个城区通奇数桥，那么无论从哪出发都能找到欧拉回路

//邻接表完成图的存储  适合稀疏图
//临接表存储有向如图更加方便一点   存储无相图的时候会出现一个边存储两次的情况
//如何判断顶点i到顶点是否存在边？
const int MAX_VERTEX = 10;//定义图最大节点是10
struct ArcNode//边表
{
	int adjvex; // 临界点编号  
	ArcNode*next;
};
struct VertexNode//顶点表
{
	DataType vertex;
	ArcNode* firstEdge;
};
class ALGraph
{
private:
	VertexNode adjList[MAX_VERTEX];
	int vertexNum, arcNum;
public:
	ALGraph(DataType v[], int n, int e);
	~ALGraph();
	void DFSTraverse(int v);
	void BFSTraverse(int v);
};
ALGraph::ALGraph(DataType v[], int n, int e)
{
	vertexNum = n;//初始化顶点个数
	arcNum = e;//初始化边的个数
	for (int i = 0; i < vertexNum; ++i)
	{
		adjList[i].vertex = v[i];
		adjList[i].firstEdge = NULL;
	}
	for (int i = 0; i < arcNum; ++i)
	{
		cout << "输入边的信息" << endl;
		int vi, vj;//vi代表起点 vj代表重点
		cin >> vi >> vj;
		auto s = new ArcNode;
		s->adjvex = vj;
		s->next = adjList[vi].firstEdge;
		adjList[i].firstEdge = s;
	}
}


//十字链表
//邻接表  逆邻接表 十字链表就是将邻接表和逆邻接表合二为一



int main()
{



	system("pause");
	return 0;
}
 