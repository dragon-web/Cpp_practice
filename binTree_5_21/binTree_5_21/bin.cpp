#define _CRT_SECURE_NO_WARNINGS 
// BinaryTreeAction.cpp : 定义控制台应用程序的入口点。
//
// 使用的库定义
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<Windows.h>

#define TRUE  1
#define FALSE 0
#define NULL_BITREE_TOKEN '#' // 创建二叉树时的空树符号( 可根据需要修改 )
#define MAX_STACK_LEVEL   100 // 栈的最大层次
#define MAX_QUEUE_SIZE    128 // 队列的最大长度

// 下面是二叉树中节点的结构体类型定义( 三叉链表 ) ...
typedef struct BiTreeNode
{
	char   Data;               // 节点数据( 字符型, 可根据应用需要修改 ) ...
	struct BiTreeNode *Parent; // 指向父结点的指针 ...
	struct BiTreeNode *LChild; // 指向左孩子的指针 ...
	struct BiTreeNode *RChild; // 指向右孩子的指针 ...
}BiTreeNode, *BiTreePtr;

// 二叉树中孩子结点类型 ...
enum BiTreeChildType
{
	btLeftChild,   // 左孩子 ...
	btRightChild,  // 右孩子 ...
	btNull         // 空孩子 ...
};

// 顺序栈( 二叉树节点指针类型 )的结构体类型定义 ...
typedef struct
{
	BiTreePtr Elem[MAX_STACK_LEVEL];
	int       Top;
}SeqBiTreePtrStack;

// 循环队列( 二叉树节点指针类型 )的结构体类型定义 ...
typedef struct
{
	BiTreePtr Elem[MAX_QUEUE_SIZE];
	int       Front, Rear;
}SeqBiTreePtrQueue;

int TotalNodeNum = 0; // 二叉树中结点总数 ...

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                            下面是各个函数定义                               // 
//                                                                          // 
// ######################################################################## //

// 顺序栈( 二叉树节点指针类型 )的操作及实现 ...
void InitStack(SeqBiTreePtrStack *S);
int  IsStackEmpty(SeqBiTreePtrStack *S);
int  IsStackFull(SeqBiTreePtrStack *S);
int  PushStack(SeqBiTreePtrStack *S, BiTreePtr x);
int  PopStack(SeqBiTreePtrStack *S, BiTreePtr *x);
int  GetStackTopElem(SeqBiTreePtrStack *S, BiTreePtr *x);

// 循环队列( 二叉树节点指针类型 )的操作及实现 ...
void InitQueue(SeqBiTreePtrQueue *Q);
int  IsQueueEmpty(SeqBiTreePtrQueue *Q);
int  IsQueueFull(SeqBiTreePtrQueue *Q);
int  EnterQueue(SeqBiTreePtrQueue *Q, BiTreePtr x);
int  LeaveQueue(SeqBiTreePtrQueue *Q, BiTreePtr *x);
int  GetQueueFrontElem(SeqBiTreePtrQueue *Q, BiTreePtr *x);

// 二叉树的建立和销毁 ...
BiTreePtr CreateBinaryTree(void);
void DestroyBinaryTree(BiTreePtr Root);

// 二叉树的遍历 ...
void RE_PreOrderBinaryTree(BiTreePtr Root);
void PreOrderBinaryTree(BiTreePtr Root);
void RE_InOrderBinaryTree(BiTreePtr Root);
void InOrderBinaryTree(BiTreePtr Root);
void RE_PostOrderBinaryTree(BiTreePtr Root);
void PostOrderBinaryTree(BiTreePtr Root);
void LevelOrderBinaryTree(BiTreePtr Root);

// 二叉树的操作 ...
BiTreePtr FindBinaryTreeNode(BiTreePtr Root, char NodeData);
BiTreePtr FindBinaryTreeNodeFather(BiTreePtr Root, char NodeData, BiTreeChildType *ChildType);
void SetBinaryTreeParent(BiTreePtr Root);
void VisitBinaryTree(BiTreePtr Root);
void CountBinaryTreeNodeNum(BiTreePtr Root);
void DisplayBinaryTreeLeafNode(BiTreePtr Root);
int  CountBinaryTreeLeafNodeNum(BiTreePtr Root);
int  CalcBinaryTreeHeight(BiTreePtr Root);
int  CalcBinaryTreeDegree(BiTreePtr Root);
void DisplayBinaryTreePath(BiTreePtr Root);
void DisplayBinaryTreeFather(BiTreePtr Root, char NodeData);
int  AddBinaryTreeNodeChild(BiTreePtr Root, char NodeData, char ChildData);
int  DeleteBinaryTreeNode(BiTreePtr Root, char NodeData);
int  UpdateBinaryTreeNode(BiTreePtr Root, char NodeData, char NewData);
void DisplayBinaryTreeNodeBrothers(BiTreePtr Root, char NodeData);
void DisplayBinaryTreeNodeAncestors(BiTreePtr Root, char NodeData);

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//              下面是顺序栈( 二叉树节点指针类型 )的操作及实现                      // 
//                                                                          // 
// ######################################################################## //

// 栈初始化 ...
void InitStack(SeqBiTreePtrStack *S)
{
	S->Top = -1;
}

// 栈是否为空 ...
int IsStackEmpty(SeqBiTreePtrStack *S)
{
	return (S->Top == -1);
}

// 栈是否为满 ...
int IsStackFull(SeqBiTreePtrStack *S)
{
	return (S->Top == (MAX_STACK_LEVEL - 1));
}

// 入栈 ...
int PushStack(SeqBiTreePtrStack *S, BiTreePtr x)
{
	if (IsStackFull(S))
		return FALSE;

	S->Top++;
	S->Elem[S->Top] = x;
	return TRUE;
}

// 出栈 ...
int PopStack(SeqBiTreePtrStack *S, BiTreePtr *x)
{
	if (IsStackEmpty(S))
		return FALSE;

	*x = S->Elem[S->Top];
	S->Top--;
	return TRUE;
}

// 取栈顶元素 ...
int GetStackTopElem(SeqBiTreePtrStack *S, BiTreePtr *x)
{
	if (IsStackEmpty(S))
		return FALSE;

	*x = S->Elem[S->Top];
	return TRUE;
}

// ######################################################################## //
//                                                                          // 
//              下面是循环队列( 二叉树节点指针类型 )的操作及实现                    // 
//                                                                          // 
// ######################################################################## //

// 队列初始化 ...
void InitQueue(SeqBiTreePtrQueue *Q)
{
	Q->Front = 0;
	Q->Rear = 0;
}

// 队列是否为空 ...
int IsQueueEmpty(SeqBiTreePtrQueue *Q)
{
	if (Q->Front == Q->Rear)
		return TRUE;

	return FALSE;
}

// 队列是否为满 ...
int IsQueueFull(SeqBiTreePtrQueue *Q)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return TRUE;

	return FALSE;
}

// 入队 ...
int EnterQueue(SeqBiTreePtrQueue *Q, BiTreePtr x)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return FALSE;

	Q->Elem[Q->Rear] = x;
	Q->Rear = (Q->Rear + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// 出队 ...
int LeaveQueue(SeqBiTreePtrQueue *Q, BiTreePtr *x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	Q->Front = (Q->Front + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// 取队头元素 ...
int GetQueueFrontElem(SeqBiTreePtrQueue *Q, BiTreePtr *x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	return TRUE;
}

// ######################################################################## //
//                                                                          // 
//                           下面是各个函数的实现                               // 
//                                                                          // 
// ######################################################################## //

// < 递归版本 > : 先序法创建二叉树（从键盘输入） ...
// ( 注意键盘输入值的顺序及空子树的输入 )
BiTreePtr CreateBinaryTree(void)
{
	BiTreePtr p;
	char ch;

	ch = getchar(); // 从键盘上输入一个字符 ...

	if (ch == NULL_BITREE_TOKEN) // 输入空子树标记 ...
		p = NULL;
	else
	{
		p = (BiTreePtr)malloc(sizeof(BiTreeNode));
		p->Data = ch;
		p->Parent = NULL; // 父结点指针初始化为空 ...
		p->LChild = CreateBinaryTree();
		p->RChild = CreateBinaryTree();
	}

	return p;
}

// < 递归版本 > : 释放二叉树（必须以后序遍历方式） ...
void DestroyBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		DestroyBinaryTree(Root->LChild);
		DestroyBinaryTree(Root->RChild);
		free(Root); // 释放树根节点空间 ...
	}
}

// < 递归版本 > : 二叉树前序遍历 ...
void RE_PreOrderBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		printf("%c ", Root->Data);
		RE_PreOrderBinaryTree(Root->LChild);
		RE_PreOrderBinaryTree(Root->RChild);
	}
}

// < 非递归版本 > : 二叉树前序遍历 ...
void PreOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// 栈初始化 ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			printf("%c ", p->Data);

			// 一直向左递归 ...
			if (!IsStackFull(&BiTreeStack)) // 判断栈是否已满 ...
			{
				PushStack(&BiTreeStack, p); // 注意 : 压入栈的是指向二叉树中节点的指针 ...
				p = p->LChild;
			}
			else // 栈满, 异常退出 ...
			{
				printf("Stack overflow !\n");
				IsStop = TRUE;
			}
		}

		// 退出上述循环则表明左孩子为空, 弹栈开始访问右孩子 ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // 判断栈是否为空 ...
			{
				PopStack(&BiTreeStack, &p);
				p = p->RChild;
			}
			else // 栈为空, 则表明遍历结束, 退出 ...
				IsStop = TRUE;
		}
	}
}

// < 递归版本 > : 二叉树中序遍历 ...
void RE_InOrderBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		RE_InOrderBinaryTree(Root->LChild);
		printf("%c ", Root->Data);
		RE_InOrderBinaryTree(Root->RChild);
	}
}

// < 非递归版本 > : 二叉树中序遍历 ...
void InOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// 栈初始化 ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			// 一直向左递归 ...
			if (!IsStackFull(&BiTreeStack)) // 判断栈是否已满 ...
			{
				PushStack(&BiTreeStack, p); // 注意 : 压入栈的是指向二叉树中节点的指针 ...
				p = p->LChild;
			}
			else // 栈满, 异常退出 ...
			{
				printf("Stack overflow !\n");
				IsStop = TRUE;
			}
		}

		// 退出上述循环则表明左孩子为空, 弹栈开始访问右孩子 ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // 判断栈是否为空 ...
			{
				PopStack(&BiTreeStack, &p);

				// 访问数据 ...
				printf("%c ", p->Data);

				p = p->RChild;
			}
			else // 栈为空, 则表明遍历结束, 退出 ...
				IsStop = TRUE;
		}
	}
}

// < 递归版本 > : 二叉树后序遍历 ...
void RE_PostOrderBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		RE_PostOrderBinaryTree(Root->LChild);
		RE_PostOrderBinaryTree(Root->RChild);
		printf("%c ", Root->Data);
	}
}

// < 非递归版本 > : 二叉树后序遍历 ...
// ( 1 ) 先找到最左边的叶子并把路上遇到的节点依次压栈;
// ( 2 ) 然后取栈顶的元素( 该元素为最左边的叶子 ), 并判断 : 
//      ( A ) 它有没有右节点 ?
//      ( B ) 右节点是否被访问过 ?
//      如果 ( A ) 为有右节点同时 ( B ) 为没有访问过, 则压入它的右子树. 否则, 就访问该节点,
//      并设置 pre 为该节点, 并且出栈.
void PostOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p, pre = NULL;

	// 栈初始化 ...
	InitStack(&BiTreeStack);

	p = Root;
	while (!IsStackEmpty(&BiTreeStack) || (p != NULL)) // 栈不空, 或者 'p' 不空 ...
	{
		while (p != NULL) // 先找到最左边的叶子并把路上遇到的节点依次压栈 ...
		{
			// 一直向左递归 ...
			if (!IsStackFull(&BiTreeStack)) // 判断栈是否已满 ...
			{
				PushStack(&BiTreeStack, p); // 注意 : 压入栈的是指向二叉树中节点的指针 ...
				p = p->LChild;
			}
			else // 栈满, 异常退出 ...
			{
				printf("Stack overflow !\n");
				return;
			}
		}

		if (!IsStackEmpty(&BiTreeStack)) // 如果栈不空 ...
		{
			// 取栈顶元素 ...
			GetStackTopElem(&BiTreeStack, &p);
			// 无右孩子( 针对是左孩子的叶子节点 )或者右孩子已经访问过( 这时应该访问根节点 ) ...
			if ((p->RChild == NULL) || (p->RChild == pre))
			{
				// 访问数据 ...
				printf("%c ", p->Data);

				// 记录 'p' 指针 ...
				pre = p;

				// 出栈( 主要目的是修改栈顶指针, 'p' 中的值没有使用即赋以 NULL 值 ) ...
				PopStack(&BiTreeStack, &p);
				p = NULL; // 防止 'p' 再次入栈( 很重要 ) ...
			}
			else // 有右孩子且右孩子未访问过 ...
			{
				p = p->RChild;
			}
		}
	}
}

// < 非递归版本 > : 二叉树层序遍历 ...
// ( 层次遍历就是按二叉树的每一层的顺序来遍历, 也就是先访问根结点, 然后访问第一层, 接着访问第二层. 同一层从左到右访问 )
void LevelOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrQueue BiTreeQueue;
	BiTreePtr p;
	int IsStop;

	// 队列初始化 ...
	InitQueue(&BiTreeQueue);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		if (p != NULL)
		{
			printf("%c ", p->Data);

			// 左孩子入队列 ...
			if (p->LChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // 队列已满 ...
				{
					printf("Queue full !\n");
					IsStop = TRUE;
				}
				else
				{
					EnterQueue(&BiTreeQueue, p->LChild);
				}
			}

			// 右孩子入队列 ...
			if (p->RChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // 队列已满 ...
				{
					printf("Queue full !\n");
					IsStop = TRUE;
				}
				else
				{
					EnterQueue(&BiTreeQueue, p->RChild);
				}
			}
		}

		// 各个节点依次出队列 ...
		if (!IsQueueEmpty(&BiTreeQueue)) // 队列非空 ...
		{
			// 出队 ...
			LeaveQueue(&BiTreeQueue, &p);
		}
		else
			IsStop = TRUE; // 队列为空, 遍历结束 ...
	}
}

// 返回指向包含特定值的结点指针 ...
// ( 1 ) 假定二叉树中各个结点中的值都不相同;
// ( 2 ) 采用二叉树的前序遍历非递归算法实现.
BiTreePtr FindBinaryTreeNode(BiTreePtr Root, char NodeData)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// 栈初始化 ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			// 是否找到结点 ...
			IsStop = (p->Data == NodeData);

			if (!IsStop)
			{
				// 一直向左递归 ...
				if (!IsStackFull(&BiTreeStack)) // 判断栈是否已满 ...
				{
					PushStack(&BiTreeStack, p); // 注意 : 压入栈的是指向二叉树中节点的指针 ...
					p = p->LChild;
				}
				else // 栈满, 异常退出 ...
				{
					IsStop = TRUE;
					p = NULL;
				}
			}
		}

		// 退出上述循环则表明左孩子为空( 或者已经找到数据 ), 弹栈开始访问右孩子 ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // 判断栈是否为空 ...
			{
				PopStack(&BiTreeStack, &p);
				p = p->RChild;
			}
			else // 栈为空, 则表明遍历结束, 退出 ...
			{
				IsStop = TRUE;
				p = NULL;
			}
		}
	}

	// 返回结果 ...
	return p;
}

// 返回指向包含特定值的结点的父结点指针 ...
// ( 1 ) 假定二叉树中各个结点中的值都不相同;
// ( 2 ) 采用二叉树的前序遍历非递归算法实现.
BiTreePtr FindBinaryTreeNodeFather(BiTreePtr Root, char NodeData, BiTreeChildType *ChildType)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// 栈初始化 ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			// 是否找到父结点 ...
			if (p->LChild != NULL)
			{
				if ((p->LChild->Data == NodeData))
				{
					IsStop = TRUE;
					*ChildType = btLeftChild; // 结点 'NodeData' 是其父结点的左孩子 ...
				}
			}

			if (!IsStop)
			{
				if (p->RChild != NULL)
				{
					if ((p->RChild->Data == NodeData))
					{
						IsStop = TRUE;
						*ChildType = btRightChild; // 结点 'NodeData' 是其父结点的右孩子 ...
					}
				}
			}

			if (!IsStop)
			{
				// 一直向左递归 ...
				if (!IsStackFull(&BiTreeStack)) // 判断栈是否已满 ...
				{
					PushStack(&BiTreeStack, p); // 注意 : 压入栈的是指向二叉树中节点的指针 ...
					p = p->LChild;
				}
				else // 栈满, 异常退出 ...
				{
					IsStop = TRUE;
					p = NULL;
				}
			}
		}

		// 退出上述循环则表明左孩子为空( 或者已经找到数据 ), 弹栈开始访问右孩子 ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // 判断栈是否为空 ...
			{
				PopStack(&BiTreeStack, &p);
				p = p->RChild;
			}
			else // 栈为空, 则表明遍历结束, 退出 ...
			{
				IsStop = TRUE;
				p = NULL;
			}
		}
	}

	// 返回结果 ...
	return p;
}

// 遍历二叉树, 设置每个结点指向其父结点的指针域 ...
void SetBinaryTreeParent(BiTreePtr Root)
{
	SeqBiTreePtrQueue BiTreeQueue;
	BiTreePtr p;
	int IsStop;

	// 使用二叉树的层序遍历实现 ...

	// 队列初始化 ...
	InitQueue(&BiTreeQueue);

	p = Root;
	p->Parent = NULL; // 根结点没有父结点, 'Parent' 指针域为空 ...
	IsStop = FALSE;
	while (!IsStop)
	{
		if (p != NULL)
		{
			// 左孩子入队列 ...
			if (p->LChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // 队列已满 ...
					IsStop = TRUE;
				else
				{
					p->LChild->Parent = p; // 设置 'p' 的左孩子的 'Parent' 指针域 ...
					EnterQueue(&BiTreeQueue, p->LChild);
				}
			}

			// 右孩子入队列 ...
			if (p->RChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // 队列已满 ...
					IsStop = TRUE;
				else
				{
					p->RChild->Parent = p; // 设置 'p' 的右孩子的 'Parent' 指针域 ...
					EnterQueue(&BiTreeQueue, p->RChild);
				}
			}
		}

		// 各个节点依次出队列 ...
		if (!IsQueueEmpty(&BiTreeQueue)) // 队列非空 ...
			LeaveQueue(&BiTreeQueue, &p); // 出队 ...
		else
			IsStop = TRUE; // 队列为空, 遍历结束 ...
	}
}

// ( 以特定方式 )访问二叉树中的各个结点 ...
void VisitBinaryTree(BiTreePtr Root)
{
	// 本函数可根据用户的需要自行 '定制', 即处理各个结点中的数据 ...
	// 当前功能 : 将各个结点中的小写字母转换为大写字母 ...
	if (Root != NULL)
	{
		if ((Root->Data >= 'a') && (Root->Data <= 'z'))
		{
			// 转换字符( 大写字母和小写字母的 ASCII 码值相差 32 ) ...
			Root->Data -= 32;
		}

		// 前序遍历算法 ...
		printf("%c ", Root->Data);
		VisitBinaryTree(Root->LChild);
		VisitBinaryTree(Root->RChild);
	}
}

// 统计二叉树中的结点数目( 使用全局量 'TotalNodeNum' 实现 ) ...
void CountBinaryTreeNodeNum(BiTreePtr Root)
{
	if (Root != NULL)
	{
		// 累加结点数目 ...
		TotalNodeNum++;

		// 前序遍历算法 ...
		CountBinaryTreeNodeNum(Root->LChild);
		CountBinaryTreeNodeNum(Root->RChild);
	}
}

// 显示二叉树中的叶子结点 ...
void DisplayBinaryTreeLeafNode(BiTreePtr Root)
{
	if (Root != NULL)
	{
		// 判断是否为叶子结点 ...
		if ((Root->LChild == NULL) && (Root->RChild == NULL))
			printf("%c ", Root->Data);

		// 前序遍历算法 ...
		DisplayBinaryTreeLeafNode(Root->LChild);
		DisplayBinaryTreeLeafNode(Root->RChild);
	}
}

// 统计二叉树叶子结点个数 ...
int CountBinaryTreeLeafNodeNum(BiTreePtr Root)
{
	int LNum, RNum; // 左子树和右子树中的叶子结点数目 ...

	// 空树 ...
	if (Root == NULL)
		return 0;

	// 找到叶子结点 ...
	if ((Root->LChild == NULL) && (Root->RChild == NULL))
		return 1;

	// 统计左子树的叶子结点数目( 递归求解 ) ...
	LNum = CountBinaryTreeLeafNodeNum(Root->LChild);

	// 统计右子树的叶子结点数目( 递归求解 ) ...
	RNum = CountBinaryTreeLeafNodeNum(Root->RChild);

	return (LNum + RNum);
}

// 计算二叉树的高度( 深度 ) ...
int CalcBinaryTreeHeight(BiTreePtr Root)
{
	int LHeight, RHeight; // 左子树和右子树的高度( 深度 ) ...

	// 空树 ...
	if (Root == NULL)
		return 0;

	// 计算左子树的高度( 深度 ) ...
	LHeight = CalcBinaryTreeHeight(Root->LChild);

	// 计算右子树的高度( 深度 ) ...
	RHeight = CalcBinaryTreeHeight(Root->RChild);

	// 返回值 ...
	if (LHeight > RHeight)
		return (LHeight + 1);
	else
		return (RHeight + 1);
}

// 计算二叉树的度 ...
// ( 本函数要求同学实现 )
//计算出叶子节点的个数
int leaf(BiTreePtr T, int &count)//count 起计数作用 
{
	if (T == NULL) //跳出递归条件 
		return 0;
	if (T->LChild == NULL && T->RChild == NULL)//关系运算优先级== 大于逻辑运算&& 
		count++;
	leaf(T->RChild, count);//可以与下式调换位置 
	leaf(T->LChild, count);
	return count;
}
int degree1(BiTreePtr T, int &count)
{
	if (T == NULL)
		return;
	if ((T->LChild== NULL && T->RChild != NULL) || (T->LChild == NULL && T->RChild != NULL))
		count++;
	degree1(T->LChild, count);
	degree1(T->RChild, count);
	return count;
}

int degree2(BiTreePtr T, int &count)
{
	if (T == NULL)
		return;
	if (T->LChild!= NULL && T->RChild != NULL)
		count++;
	degree2(T->LChild, count);
	degree2(T->RChild, count);
	return count;
}
int CalcBinaryTreeDegree(BiTreePtr Root)
{
	//算法统计度为1或者度为2的节点个数
	if (Root == NULL)
		return false;
	else
	{
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		count1 = leaf(Root,count1);
		count2 = degree1(Root, count2);
		count3 = degree2(Root, count3);
	if (count3 != 0)
		return count3;
	if (count2 != 0)
		return count2;
	if (count1 != 0)
		return count1;
	}
}

// 输出叶子结点到根结点的路径 ...
void DisplayBinaryTreePath(BiTreePtr Root)
{
	BiTreePtr p;

	if (Root != NULL)
	{
		// 找到叶子结点 ...
		if ((Root->LChild == NULL) && (Root->RChild == NULL))
		{
			p = Root;

			// 输出叶子结点到根结点的路径( 即输出叶子结点的祖先, 含叶子结点 ) ...
			printf("\n\t");
			printf("%c ", p->Data); // 输出叶子结点的值 ...

			// 从叶子结点开始回溯到根节点 ...
			while (p->Parent != NULL)
			{
				p = p->Parent; // 得到指向父结点的指针 ...
				printf("%c ", p->Data); // 输出父结点的值 ...
			}
			printf("\n");
		}

		// 处理左子树 ...
		DisplayBinaryTreePath(Root->LChild);
		// 处理右子树 ...
		DisplayBinaryTreePath(Root->RChild);
	}
}

// 显示值为 'NodeData' 的结点的父结点的值 ...
void DisplayBinaryTreeFather(BiTreePtr Root, char NodeData)
{
	BiTreePtr p;
	BiTreeChildType ChildType;

	// 查找父结点指针 ...
	p = FindBinaryTreeNodeFather(Root, NodeData, &ChildType);
	if (p != NULL)
		printf("\n\t父结点数据 -> %c ", p->Data); // 打印父结点数据 ...
	else
		printf("\n\t未找到父结点 !\n\n");
}

// 在二叉树中增加结点 ...
int AddBinaryTreeNodeChild(BiTreePtr Root, char NodeData, char ChildData)
{
	BiTreePtr p, q;
	int OK = TRUE;

	// 查找二叉树中是否存在值为 'NodeData' 的结点 ...
	p = FindBinaryTreeNode(Root, NodeData);
	if (p != NULL)
	{
		// 插入新结点的算法为 :
		// ( 1 ) 如果指针 'p' 指向结点左孩子和右孩子都存在, 则插入新结点失败;
		// ( 2 ) 如果指针 'p' 指向结点是叶子结点, 则将新结点插入为左孩子;
		// ( 3 ) 如果指针 'p' 指向结点有左孩子或者右孩子, 则将新结点插入为右孩子或左孩子;
		if ((p->LChild != NULL) && (p->RChild != NULL))
			OK = FALSE;
		else
		{
			// 一定会插入结点, 所以先创建结点( 创建的结点为叶子结点 ) ...
			q = (BiTreePtr)malloc(sizeof(BiTreeNode));
			q->Data = ChildData;
			q->Parent = p; // 设置指向父结点的指针 ...
			q->LChild = NULL;
			q->RChild = NULL;

			// 优先作为左孩子插入 ...
			if (p->LChild == NULL)
				p->LChild = q;
			else
				p->RChild = q;
		}
	}
	else
		OK = FALSE;

	return OK;
}

// 在二叉树中删除结点( 同时删除该结点对应的所有子结点 ) ...
// ( 本函数要求同学实现 )
int DeleteBinaryTreeNode(BiTreePtr Root, char NodeData) //
{
	if (Root == NULL)
	{
		return false;
	}
	else if (NodeData < (*Root).Data)
		DeleteBinaryTreeNode(((Root)->LChild), NodeData);
	else if (NodeData > (*Root).Data)
		DeleteBinaryTreeNode(((Root)->RChild), NodeData);
	else
	{
		BiTreePtr p= Root;
		if (p->LChild == NULL && p->RChild == NULL)
		{
			free(p);
			Root = NULL;
		}
		else if (p->LChild != NULL && p->RChild == NULL)
		{
			p = Root;
			Root = p->LChild;
			free(p);
		}
		else if (p->LChild == NULL && p->RChild != NULL)
		{
			p = Root;
			Root = p->RChild;
			free(p);
		}
		else
		{
			p = Root->LChild;
			while (p->RChild != NULL)
				p = p->RChild;
			Root->Data = p->Data;
			DeleteBinaryTreeNode(((Root)->LChild),p->Data);
		}
		return true;
	}
}

// 修改二叉树中结点的值 ...
int UpdateBinaryTreeNode(BiTreePtr Root, char NodeData, char NewData)
{
	BiTreePtr p;
	int OK = TRUE;

	// 查找二叉树中是否存在值为 'NodeData' 的结点 ...
	p = FindBinaryTreeNode(Root, NodeData);
	if (p != NULL)
		p->Data = NewData; // 替换结点的值 ...
	else
		OK = FALSE;

	return OK;
}

// 显示二叉树中给定结点的兄弟结点 ...
void DisplayBinaryTreeNodeBrothers(BiTreePtr Root, char NodeData)
{
	BiTreePtr p;
	BiTreeChildType ChildType;

	// 返回指向父结点的指针 ...
	p = FindBinaryTreeNodeFather(Root, NodeData, &ChildType);
	if (p != NULL)
	{
		// 根据结点 'NodeData' 是其父结点的不同孩子类型进行处理 ...
		switch (ChildType)
		{
		case btLeftChild: {
			// 结点 'NodeData' 是其父结点的左孩子 ...
			if (p->RChild != NULL)
				printf("\n\t兄弟结点数据 -> %c ", p->RChild->Data); // 打印兄弟结点数据 ...
			else
				printf("\n\t没有兄弟结点 !\n\n");

			break;
		}
		case btRightChild: {
			// 结点 'NodeData' 是其父结点的右孩子 ...
			if (p->LChild != NULL)
				printf("\n\t兄弟结点数据 -> %c ", p->LChild->Data); // 打印兄弟结点数据 ...
			else
				printf("\n\t没有兄弟结点 !\n\n");

			break;
		}
		}
	}
}

// 显示二叉树中给定结点的祖先结点 ...
// ( 本函数要求同学实现 )
void DisplayBinaryTreeNodeAncestors(BiTreePtr Root, char NodeData)
{
		SeqBiTreePtrStack s;
		BiTreeNode q;
		BiTreePtr p = Root;
		char x;
		printf("输入查找的节点:");
		scanf("%c", &x);
		InitStack(&s);
		while (p || !IsStackEmpty(&s))
		{
			if (p) {
				q.flag = 0;//没有访问右孩子
				q.Data = p;
				pushStack(s, q);//压栈
				p = p->lchild;
			}
			else {
				outStack(s, &q);
				p = q.data;
				if (q.flag == 0) {
					q.flag = 1;//访问了右孩子
					pushStack(s, q);
					p = p->rchild;
				}
				else {
					if (p->data == x)break;
					p = NULL;//没找到节点，返回到上一节点
				}
			}
		}
		if (emptyStack(s))printf("找不到该节点的祖先！");
		else {
			printf("%c的祖先:", x);
			while (!emptyStack(s)) {
				outStack(s, &q);
				printf("%c", q.Data);
			}
			puts("");
		}
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             下面是主程序的实现                              // 
//                                                                          // 
// ######################################################################## //

int main()
{
	int  IsStop;
	char UserInput[20];
	char NodeData, ChildData, NewData;

	BiTreePtr Root;

	IsStop = FALSE;
	while (!IsStop)
	{
		fflush(stdin); // 清空缓冲区 ...

		// 输入二叉树 ...
		printf("\n\t输入数据创建二叉树( 注意输入数据的次序和内容 ) :\n\t");
		Root = CreateBinaryTree();

		// 遍历二叉树, 设置每个结点指向父结点的指针域 ...
		SetBinaryTreeParent(Root);

		// 二叉树的遍历 ...
		printf("\n\t二叉树的前序遍历( 递归方式 )为 : ");
		RE_PreOrderBinaryTree(Root);
		printf("\n");
		printf("\n\t二叉树的前序遍历( 非递归方式 )为 : ");
		PreOrderBinaryTree(Root);
		printf("\n\n");

		printf("\n\t二叉树的中序遍历( 递归方式 )为 : ");
		RE_InOrderBinaryTree(Root);
		printf("\n");
		printf("\n\t二叉树的中序遍历( 非递归方式 )为 : ");
		InOrderBinaryTree(Root);
		printf("\n\n");

		printf("\n\t二叉树的后序遍历( 递归方式 )为 : ");
		RE_PostOrderBinaryTree(Root);
		printf("\n");
		printf("\n\t二叉树的后序遍历( 非递归方式 )为 : ");
		PostOrderBinaryTree(Root);
		printf("\n\n");

		printf("\n\t二叉树的层序遍历( 非递归方式 )为 : ");
		LevelOrderBinaryTree(Root);
		printf("\n\n");

		// 访问二叉树中的各个结点 ...
		printf("\n\t访问二叉树的各个结点为 : ");
		VisitBinaryTree(Root);
		printf("\n\n");

		// 统计二叉树中的结点数目 ...
		TotalNodeNum = 0; // 二叉树中结点总数 ...
		CountBinaryTreeNodeNum(Root);
		printf("\n\t二叉树中结点总数为 : %d\n\n", TotalNodeNum);

		// 显示二叉树中的叶子结点 ...
		printf("\n\t二叉树中的叶子结点为 : ");
		DisplayBinaryTreeLeafNode(Root);
		printf("\n\n");

		// 统计二叉树叶子结点个数 ...
		printf("\n\t二叉树中叶子结点数目为 : %d\n\n", CountBinaryTreeLeafNodeNum(Root));

		// 计算二叉树的高度( 深度 ) ...
		printf("\n\t二叉树的高度( 深度 )为 : %d\n\n", CalcBinaryTreeHeight(Root));

		// 计算二叉树的度 ...
		printf("\n\t二叉树的度为 : %d\n\n", CalcBinaryTreeDegree(Root));

		// 输出叶子结点到根结点的路径 ...
		printf("\n\t输出叶子结点到根结点的路径 :\n");
		DisplayBinaryTreePath(Root);
		printf("\n\n");

		// 显示包含特定值的结点的的父结点的值 ...
		printf("\n\t***** 查找给定结点的父结点 *****");
		printf("\n\t当前二叉树的内容为 : ");
		RE_PreOrderBinaryTree(Root);
		printf("\n\t请输入待查找的结点数据 : ");
		scanf("%s", UserInput);
		DisplayBinaryTreeFather(Root, UserInput[0]);

		// 在二叉树中增加结点 ...
		printf("\n\n\n\t***** 在二叉树中增加结点 *****");
		printf("\n\t请输入待查找的结点数据 : ");
		scanf("%s", UserInput);
		NodeData = UserInput[0];
		printf("\n\t请输入增加为子结点的结点数据 : ");
		scanf("%s", UserInput);
		ChildData = UserInput[0];
		if (AddBinaryTreeNodeChild(Root, NodeData, ChildData))
		{
			printf("\n\t增加结点成功 ! 当前二叉树的内容为 : ");
			RE_PreOrderBinaryTree(Root);
			printf("\n\n");
		}
		else
			printf("\n\t增加结点失败 !\n");

		// 在二叉树中删除结点( 同时删除该结点对应的所有子结点 ) ...
		printf("\n\n\n\t***** 在二叉树中删除结点 *****");
		printf("\n\t请输入待查找的结点数据 : ");
		scanf("%s", UserInput);
		NodeData = UserInput[0];
		if (DeleteBinaryTreeNode(Root, NodeData))
		{
			printf("\n\t删除结点成功 ! 当前二叉树的内容为 : ");
			RE_PreOrderBinaryTree(Root);
			printf("\n\n");
		}
		else
			printf("\n\t删除结点失败 !\n");

		// 修改二叉树中结点的值 ...
		printf("\n\n\n\t***** 修改二叉树中结点的值 *****");
		printf("\n\t请输入待查找的结点数据 : ");
		scanf("%s", UserInput);
		NodeData = UserInput[0];
		printf("\n\t请输入修改后的结点数据 : ");
		scanf("%s", UserInput);
		NewData = UserInput[0];
		if (UpdateBinaryTreeNode(Root, NodeData, NewData))
		{
			printf("\n\t修改结点成功 ! 当前二叉树的内容为 : ");
			RE_PreOrderBinaryTree(Root);
			printf("\n\n");
		}
		else
			printf("\n\t修改结点失败 !\n");

		// 显示二叉树中给定结点的兄弟结点 ...
		printf("\n\n\n\t***** 查找给定结点的兄弟结点 *****");
		printf("\n\n\t请输入待查找的结点数据 : ");
		scanf("%s", UserInput);
		DisplayBinaryTreeNodeBrothers(Root, UserInput[0]);

		// 显示二叉树中给定结点的祖先结点 ...
		printf("\n\n\n\t***** 查找给定结点的祖先结点 *****");
		printf("\n\n\t请输入待查找的结点数据 : ");
		scanf("%s", UserInput);
		DisplayBinaryTreeNodeAncestors(Root, UserInput[0]);

		// 释放二叉树空间 ...
		DestroyBinaryTree(Root);

		printf("\n\n");
		printf("\n\t继续处理[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
