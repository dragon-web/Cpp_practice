#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
using namespace std;
const int MaxSize = 12;
int visited[MaxSize];
struct ArcNode                   //定义边表结点
{
	int adjvex;                    //邻接点域
	ArcNode *next;                 //指向下一个边结点的指针
};
template <class T>
struct VertexNode               //定义顶点表结点
{
	T vertex;                     //顶点的名称
	ArcNode *firstedge;           //边表的头指针
};
template <class T>
class ALGraph
{
public:
	ALGraph(T a[], int n, int e);   //构造函数，初始化一个有n个顶点e条边的图
	~ALGraph();                      //析构函数，释放邻接表中各边表结点的存储空间
	T GetVex(int i);                 //取图中第i个顶点数据信息
	void PutVex(int i, T value);     //将图中第i个顶点的数据域置为value
	void InsertVex(int i, T value);  //在图中插入一个顶点，其编号为i，值为value
	void DeleteVex(int i);           //删除图中第i个顶点
	void InsertArc(int i, int j);    //在图中插入一条边，其依附的两个顶点的编号为i和j
	void DeleteArc(int i, int j);    //在图中删除一条边，其依附的两个顶点的编号为i和j
	void DFSTraverse(int v);         //深度优先遍历图
	void BFSTraverse(int v);         //广度优先遍历图
private:
	VertexNode<T> adjlist[MaxSize];  //存放顶点表的数组
	int vertexNum, arcNum;           //图的顶点数和边数
};


/*
 *前置条件：图不存在
 *输    入：无
 *功    能：图的初始化
 *输    出：无
 *后置条件：得到一个有向图
 */
template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	arcNum = e;                             //边数
	vertexNum = n;                            //顶点数
	int i, j;
	for (i = 0; i < vertexNum; i++)
	{
		VertexNode<T> tempvertex;
		tempvertex.vertex = a[i];
		tempvertex.firstedge = NULL;
		adjlist[i] = tempvertex;
	}
	for (int k = 0; k < arcNum; k++)           //依次输入每一条边，并在相应边表中插入结点
	{
		cout << "请输入边所依附的两个顶点的序号";
		cin >> i >> j;                         //输入边所依附的两个顶点的序号
		ArcNode *s = new ArcNode; s->adjvex = j;  //生成一个边表结点s
		s->next = adjlist[i].firstedge;      //将结点s插入到结点i的边表的表头  
		adjlist[i].firstedge = s;
	}
	//InsertArc(0, 1);                   //插入边
	//InsertArc(1, 0);                   //插入边
	//InsertArc(0, 2);
	//InsertArc(2,0);
	//InsertArc(0, 3);
	//InsertArc(1, 3);
	//InsertArc(3, 1);

	//InsertArc(1, 4);
	//InsertArc(4,1);
	//InsertArc(2, 0);
	//InsertArc(2, 4);
	//InsertArc(3, 1);
	//InsertArc(3, 4);
	//InsertArc(4, 3);

	//InsertArc(4, 2);
	//InsertArc(4, 3);
}
/*   前置条件：图已存在
 *   输    入：无
 *   功    能：销毁图
 *   输    出：无
 *   后置条件：释放图所占用的存储空间
 */
template <class T>
ALGraph<T>::~ALGraph()
{
	for (int i = 0; i < vertexNum; i++)
	{
		ArcNode * p = adjlist[i].firstedge;
		while (p != NULL)                                              //循环删除
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //释放结点空间
			p = adjlist[i].firstedge;
		}
	}
}
/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：输出图中顶点i的数据信息
 *输    出：图中顶点i的数据信息
 *后置条件：图保持不变
 */
template <class T>
T ALGraph<T>::GetVex(int i)
{
	if (i > vertexNum || i < 0) throw "输入顶点的位置不正确"; //顶点i不存在则抛出异常
	return adjlist[i].vertex;                               //返回第i个顶点的数据域  
}

/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：将图中顶点i的数据域置为value
 *输    出：无
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::PutVex(int i, T value)
{
	if (i > vertexNum || i < 0) 
		throw "输入顶点的位置不正确"; //顶点i不存在则抛出异常
	adjlist[i].vertex = value;                              //第i个顶点的数据域置为value
}
/*
 *前置条件：图已存在
 *输    入：顶点value,位置i
 *功    能：在图中i位置插入一个顶点name
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T>
void ALGraph<T>::InsertVex(int i, T value)
{
	if (i > vertexNum || i<0 || i>MaxSize) throw "输入顶点的位置不正确"; //顶点i不存在则抛出异常
	vertexNum++;                                            //顶点数加1
	VertexNode<T> tempvertex;
	tempvertex.vertex = value;
	tempvertex.firstedge = NULL;
	adjlist[i] = tempvertex;  	                    //第i个顶点的数据域置为value	
}
/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：在图中删除顶点i
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一个顶点,相应顶点所建立的边也消去
 */
template <class T>
void ALGraph<T>::DeleteVex(int i)
{
	if (i<0 || i>MaxSize)
		throw "位置";       //顶点输入错误则抛出异常
	int k;
	for (k = 0; k < vertexNum; k++)               //删掉入度边
		if (k != i)	 DeleteArc(k, i);
	ArcNode *s;                                //生成一个边表结点s
	if (adjlist[i].firstedge != NULL)
	{
		ArcNode *s;
		s = adjlist[i].firstedge->next;
		while (s != NULL)
		{
			ArcNode *p;
			p = s;
			adjlist[i].firstedge->next = s->next;
			s = s->next;
			delete p;                        //删除p结点
		}
		s = adjlist[i].firstedge;
		adjlist[i].firstedge = NULL;
		delete s;
	}
	for (k = i; k < vertexNum; k++)
	{
		adjlist[k] = adjlist[k + 1];             //存储顶点信息       
	}
	vertexNum--;                             //顶点数减1
	for (k = 0; k < vertexNum; k++)
		if (adjlist[k].firstedge != NULL)
		{
			s = adjlist[k].firstedge;                //将结点s插入到结点i的边表的表头
			while (s != NULL)
			{
				if (s->adjvex > i)                  //搜索i结点
					s->adjvex--;
				s = s->next;
			}
		}
}
/*
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中插入顶点i、j及其所依附的边
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一条边
 */
template <class T>
void ALGraph<T>::InsertArc(int i, int j)
{
	if (i > MaxSize || j > MaxSize) throw "位置";   //顶点输入错误则抛出异常
	ArcNode *s = new ArcNode; s->adjvex = j;      //生成一个边表结点s
	s->next = adjlist[i].firstedge;             //将结点s插入到结点i的边表的表头
	adjlist[i].firstedge = s;
}
/*
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中删除顶点i、j 依附的边
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一条边
*/
template <class T>
void ALGraph<T>::DeleteArc(int i, int j)
{
	if (i > MaxSize || j > MaxSize) throw "位置";  //顶点输入错误则抛出异常
	ArcNode *s;
	ArcNode *tempnode;
	s = adjlist[i].firstedge;
	tempnode = adjlist[i].firstedge;
	while (s != NULL && s->adjvex != j)
	{
		tempnode = s;
		s = s->next;
	}
	if (s != NULL)
	{
		tempnode->next = s->next;
		delete s;
	}
}
/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发深度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
	if (v > vertexNum) throw "位置";                          //顶点输入错误则抛出异常
	ArcNode * p;
	int j;
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p)                                                //依次搜索顶点v的邻接点j
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);
		p = p->next;
	}
}
/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发广度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
	if (v > vertexNum) throw "位置";                           //顶点输入错误则抛出异常
	int front, rear, j;
	ArcNode * p;                                              //生成一个边表结点p
	int Q[MaxSize];
	front = rear = -1;                                            //初始化队列, 假设队列采用顺序存储且不会发生溢出
	cout << adjlist[v].vertex << " ";  visited[v] = 1; Q[++rear] = v; //被访问顶点入队
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) {
				cout << adjlist[j].vertex << " "; visited[j] = 1; Q[++rear] = j;
			}
			p = p->next;
		}
	}
}


int main()
{
	int which;
	int j;
	string name;
	int choose = 1;
	//string a[5] = { "北大","清华","复旦","吉林大学","长春工大" };
	string a[5] = { "A","B","C","D","E" };

	ALGraph<string> algraphTest(a, 5, 5);        //构造图
	while (choose == 1)                                      //控制
	{
		cout << "需要输出顶点信息请按0" << endl;		         //输入所要进行的操作的序号
		cout << "需要输出任意一个顶点信息请按1" << endl;
		cout << "需要插入顶点请按2" << endl;
		cout << "需要修改顶点请按3" << endl;
		cout << "需要删除顶点请按4" << endl;
		cout << "需要深度优先遍历请按5" << endl;
		cout << "需要广度优先遍历请按6" << endl;
		cout << "需要退出请按7" << endl;
		cin >> which;
		switch (which)                                        //功能选择
		{
		case 0:
			for (j = 0; j < 5; j++)
				cout << algraphTest.GetVex(j) << " ";              //输出顶点
			cout << endl;
			break;
		case 1:
			int i;
			cout << "请输入顶点：" << endl;
			cin >> i;
			try
			{
				cout << algraphTest.GetVex(i) << endl;              //输出i顶点的数据域
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 2:                                               //在图中的i位置插入一顶点值为name
			cout << "请输入顶点及名字：" << endl;
			cin >> i >> name;
			try
			{
				algraphTest.InsertVex(i, name);

			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 3:                                               //修改图中一顶点的值
			cout << "请输入顶点及名字：" << endl;
			cin >> i >> name;
			try
			{
				algraphTest.PutVex(i, name);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 4:                                               //删除图中一顶点的值
			cout << "请输入顶点：" << endl;
			cin >> i;
			try
			{
				algraphTest.DeleteVex(i);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 5:                                               //图的深度优先搜索
			cout << "请输入顶点：" << endl;
			cin >> i;
			cout << endl << "从第" << i << "个顶点深度优先遍历图" << endl;
			try
			{
				for (int ii = 0; ii < MaxSize; ii++) visited[ii] = 0;
				algraphTest.DFSTraverse(i);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 6:                                               //图的广度优先搜索
			cout << "请输入顶点：" << endl;
			cin >> i;
			cout << endl << "从第" << i << "个顶点广度优先遍历图" << endl;
			try
			{
				for (int ii = 0; ii < MaxSize; ii++) visited[ii] = 0;
				algraphTest.BFSTraverse(i);
			}
			catch (char*s)
			{
				cout << s << endl;
			}
			break;
		case 7:                                             //退出
			choose = 0;
			break;
		}
	}
}
/*
int main()
{
	string a[5] = { "A","B","C","D","E" };
	int edg = 5;
	ALGraph<string> gra(a, 5, 5);
	gra.DFSTraverse(0);
	system("pause");
	return 0;
}*/