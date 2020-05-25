#define _CRT_SECURE_NO_WARNINGS 
// BinaryTreeAction.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ʹ�õĿⶨ��
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<Windows.h>

#define TRUE  1
#define FALSE 0
#define NULL_BITREE_TOKEN '#' // ����������ʱ�Ŀ�������( �ɸ�����Ҫ�޸� )
#define MAX_STACK_LEVEL   100 // ջ�������
#define MAX_QUEUE_SIZE    128 // ���е���󳤶�

// �����Ƕ������нڵ�Ľṹ�����Ͷ���( �������� ) ...
typedef struct BiTreeNode
{
	char   Data;               // �ڵ�����( �ַ���, �ɸ���Ӧ����Ҫ�޸� ) ...
	struct BiTreeNode *Parent; // ָ�򸸽���ָ�� ...
	struct BiTreeNode *LChild; // ָ�����ӵ�ָ�� ...
	struct BiTreeNode *RChild; // ָ���Һ��ӵ�ָ�� ...
}BiTreeNode, *BiTreePtr;

// �������к��ӽ������ ...
enum BiTreeChildType
{
	btLeftChild,   // ���� ...
	btRightChild,  // �Һ��� ...
	btNull         // �պ��� ...
};

// ˳��ջ( �������ڵ�ָ������ )�Ľṹ�����Ͷ��� ...
typedef struct
{
	BiTreePtr Elem[MAX_STACK_LEVEL];
	int       Top;
}SeqBiTreePtrStack;

// ѭ������( �������ڵ�ָ������ )�Ľṹ�����Ͷ��� ...
typedef struct
{
	BiTreePtr Elem[MAX_QUEUE_SIZE];
	int       Front, Rear;
}SeqBiTreePtrQueue;

int TotalNodeNum = 0; // �������н������ ...

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                            �����Ǹ�����������                               // 
//                                                                          // 
// ######################################################################## //

// ˳��ջ( �������ڵ�ָ������ )�Ĳ�����ʵ�� ...
void InitStack(SeqBiTreePtrStack *S);
int  IsStackEmpty(SeqBiTreePtrStack *S);
int  IsStackFull(SeqBiTreePtrStack *S);
int  PushStack(SeqBiTreePtrStack *S, BiTreePtr x);
int  PopStack(SeqBiTreePtrStack *S, BiTreePtr *x);
int  GetStackTopElem(SeqBiTreePtrStack *S, BiTreePtr *x);

// ѭ������( �������ڵ�ָ������ )�Ĳ�����ʵ�� ...
void InitQueue(SeqBiTreePtrQueue *Q);
int  IsQueueEmpty(SeqBiTreePtrQueue *Q);
int  IsQueueFull(SeqBiTreePtrQueue *Q);
int  EnterQueue(SeqBiTreePtrQueue *Q, BiTreePtr x);
int  LeaveQueue(SeqBiTreePtrQueue *Q, BiTreePtr *x);
int  GetQueueFrontElem(SeqBiTreePtrQueue *Q, BiTreePtr *x);

// �������Ľ��������� ...
BiTreePtr CreateBinaryTree(void);
void DestroyBinaryTree(BiTreePtr Root);

// �������ı��� ...
void RE_PreOrderBinaryTree(BiTreePtr Root);
void PreOrderBinaryTree(BiTreePtr Root);
void RE_InOrderBinaryTree(BiTreePtr Root);
void InOrderBinaryTree(BiTreePtr Root);
void RE_PostOrderBinaryTree(BiTreePtr Root);
void PostOrderBinaryTree(BiTreePtr Root);
void LevelOrderBinaryTree(BiTreePtr Root);

// �������Ĳ��� ...
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
//              ������˳��ջ( �������ڵ�ָ������ )�Ĳ�����ʵ��                      // 
//                                                                          // 
// ######################################################################## //

// ջ��ʼ�� ...
void InitStack(SeqBiTreePtrStack *S)
{
	S->Top = -1;
}

// ջ�Ƿ�Ϊ�� ...
int IsStackEmpty(SeqBiTreePtrStack *S)
{
	return (S->Top == -1);
}

// ջ�Ƿ�Ϊ�� ...
int IsStackFull(SeqBiTreePtrStack *S)
{
	return (S->Top == (MAX_STACK_LEVEL - 1));
}

// ��ջ ...
int PushStack(SeqBiTreePtrStack *S, BiTreePtr x)
{
	if (IsStackFull(S))
		return FALSE;

	S->Top++;
	S->Elem[S->Top] = x;
	return TRUE;
}

// ��ջ ...
int PopStack(SeqBiTreePtrStack *S, BiTreePtr *x)
{
	if (IsStackEmpty(S))
		return FALSE;

	*x = S->Elem[S->Top];
	S->Top--;
	return TRUE;
}

// ȡջ��Ԫ�� ...
int GetStackTopElem(SeqBiTreePtrStack *S, BiTreePtr *x)
{
	if (IsStackEmpty(S))
		return FALSE;

	*x = S->Elem[S->Top];
	return TRUE;
}

// ######################################################################## //
//                                                                          // 
//              ������ѭ������( �������ڵ�ָ������ )�Ĳ�����ʵ��                    // 
//                                                                          // 
// ######################################################################## //

// ���г�ʼ�� ...
void InitQueue(SeqBiTreePtrQueue *Q)
{
	Q->Front = 0;
	Q->Rear = 0;
}

// �����Ƿ�Ϊ�� ...
int IsQueueEmpty(SeqBiTreePtrQueue *Q)
{
	if (Q->Front == Q->Rear)
		return TRUE;

	return FALSE;
}

// �����Ƿ�Ϊ�� ...
int IsQueueFull(SeqBiTreePtrQueue *Q)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return TRUE;

	return FALSE;
}

// ��� ...
int EnterQueue(SeqBiTreePtrQueue *Q, BiTreePtr x)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return FALSE;

	Q->Elem[Q->Rear] = x;
	Q->Rear = (Q->Rear + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// ���� ...
int LeaveQueue(SeqBiTreePtrQueue *Q, BiTreePtr *x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	Q->Front = (Q->Front + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// ȡ��ͷԪ�� ...
int GetQueueFrontElem(SeqBiTreePtrQueue *Q, BiTreePtr *x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	return TRUE;
}

// ######################################################################## //
//                                                                          // 
//                           �����Ǹ���������ʵ��                               // 
//                                                                          // 
// ######################################################################## //

// < �ݹ�汾 > : ���򷨴������������Ӽ������룩 ...
// ( ע���������ֵ��˳�򼰿����������� )
BiTreePtr CreateBinaryTree(void)
{
	BiTreePtr p;
	char ch;

	ch = getchar(); // �Ӽ���������һ���ַ� ...

	if (ch == NULL_BITREE_TOKEN) // ������������ ...
		p = NULL;
	else
	{
		p = (BiTreePtr)malloc(sizeof(BiTreeNode));
		p->Data = ch;
		p->Parent = NULL; // �����ָ���ʼ��Ϊ�� ...
		p->LChild = CreateBinaryTree();
		p->RChild = CreateBinaryTree();
	}

	return p;
}

// < �ݹ�汾 > : �ͷŶ������������Ժ��������ʽ�� ...
void DestroyBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		DestroyBinaryTree(Root->LChild);
		DestroyBinaryTree(Root->RChild);
		free(Root); // �ͷ������ڵ�ռ� ...
	}
}

// < �ݹ�汾 > : ������ǰ����� ...
void RE_PreOrderBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		printf("%c ", Root->Data);
		RE_PreOrderBinaryTree(Root->LChild);
		RE_PreOrderBinaryTree(Root->RChild);
	}
}

// < �ǵݹ�汾 > : ������ǰ����� ...
void PreOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// ջ��ʼ�� ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			printf("%c ", p->Data);

			// һֱ����ݹ� ...
			if (!IsStackFull(&BiTreeStack)) // �ж�ջ�Ƿ����� ...
			{
				PushStack(&BiTreeStack, p); // ע�� : ѹ��ջ����ָ��������нڵ��ָ�� ...
				p = p->LChild;
			}
			else // ջ��, �쳣�˳� ...
			{
				printf("Stack overflow !\n");
				IsStop = TRUE;
			}
		}

		// �˳�����ѭ�����������Ϊ��, ��ջ��ʼ�����Һ��� ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // �ж�ջ�Ƿ�Ϊ�� ...
			{
				PopStack(&BiTreeStack, &p);
				p = p->RChild;
			}
			else // ջΪ��, �������������, �˳� ...
				IsStop = TRUE;
		}
	}
}

// < �ݹ�汾 > : ������������� ...
void RE_InOrderBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		RE_InOrderBinaryTree(Root->LChild);
		printf("%c ", Root->Data);
		RE_InOrderBinaryTree(Root->RChild);
	}
}

// < �ǵݹ�汾 > : ������������� ...
void InOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// ջ��ʼ�� ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			// һֱ����ݹ� ...
			if (!IsStackFull(&BiTreeStack)) // �ж�ջ�Ƿ����� ...
			{
				PushStack(&BiTreeStack, p); // ע�� : ѹ��ջ����ָ��������нڵ��ָ�� ...
				p = p->LChild;
			}
			else // ջ��, �쳣�˳� ...
			{
				printf("Stack overflow !\n");
				IsStop = TRUE;
			}
		}

		// �˳�����ѭ�����������Ϊ��, ��ջ��ʼ�����Һ��� ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // �ж�ջ�Ƿ�Ϊ�� ...
			{
				PopStack(&BiTreeStack, &p);

				// �������� ...
				printf("%c ", p->Data);

				p = p->RChild;
			}
			else // ջΪ��, �������������, �˳� ...
				IsStop = TRUE;
		}
	}
}

// < �ݹ�汾 > : ������������� ...
void RE_PostOrderBinaryTree(BiTreePtr Root)
{
	if (Root != NULL)
	{
		RE_PostOrderBinaryTree(Root->LChild);
		RE_PostOrderBinaryTree(Root->RChild);
		printf("%c ", Root->Data);
	}
}

// < �ǵݹ�汾 > : ������������� ...
// ( 1 ) ���ҵ�����ߵ�Ҷ�Ӳ���·�������Ľڵ�����ѹջ;
// ( 2 ) Ȼ��ȡջ����Ԫ��( ��Ԫ��Ϊ����ߵ�Ҷ�� ), ���ж� : 
//      ( A ) ����û���ҽڵ� ?
//      ( B ) �ҽڵ��Ƿ񱻷��ʹ� ?
//      ��� ( A ) Ϊ���ҽڵ�ͬʱ ( B ) Ϊû�з��ʹ�, ��ѹ������������. ����, �ͷ��ʸýڵ�,
//      ������ pre Ϊ�ýڵ�, ���ҳ�ջ.
void PostOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p, pre = NULL;

	// ջ��ʼ�� ...
	InitStack(&BiTreeStack);

	p = Root;
	while (!IsStackEmpty(&BiTreeStack) || (p != NULL)) // ջ����, ���� 'p' ���� ...
	{
		while (p != NULL) // ���ҵ�����ߵ�Ҷ�Ӳ���·�������Ľڵ�����ѹջ ...
		{
			// һֱ����ݹ� ...
			if (!IsStackFull(&BiTreeStack)) // �ж�ջ�Ƿ����� ...
			{
				PushStack(&BiTreeStack, p); // ע�� : ѹ��ջ����ָ��������нڵ��ָ�� ...
				p = p->LChild;
			}
			else // ջ��, �쳣�˳� ...
			{
				printf("Stack overflow !\n");
				return;
			}
		}

		if (!IsStackEmpty(&BiTreeStack)) // ���ջ���� ...
		{
			// ȡջ��Ԫ�� ...
			GetStackTopElem(&BiTreeStack, &p);
			// ���Һ���( ��������ӵ�Ҷ�ӽڵ� )�����Һ����Ѿ����ʹ�( ��ʱӦ�÷��ʸ��ڵ� ) ...
			if ((p->RChild == NULL) || (p->RChild == pre))
			{
				// �������� ...
				printf("%c ", p->Data);

				// ��¼ 'p' ָ�� ...
				pre = p;

				// ��ջ( ��ҪĿ�����޸�ջ��ָ��, 'p' �е�ֵû��ʹ�ü����� NULL ֵ ) ...
				PopStack(&BiTreeStack, &p);
				p = NULL; // ��ֹ 'p' �ٴ���ջ( ����Ҫ ) ...
			}
			else // ���Һ������Һ���δ���ʹ� ...
			{
				p = p->RChild;
			}
		}
	}
}

// < �ǵݹ�汾 > : ������������� ...
// ( ��α������ǰ���������ÿһ���˳��������, Ҳ�����ȷ��ʸ����, Ȼ����ʵ�һ��, ���ŷ��ʵڶ���. ͬһ������ҷ��� )
void LevelOrderBinaryTree(BiTreePtr Root)
{
	SeqBiTreePtrQueue BiTreeQueue;
	BiTreePtr p;
	int IsStop;

	// ���г�ʼ�� ...
	InitQueue(&BiTreeQueue);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		if (p != NULL)
		{
			printf("%c ", p->Data);

			// ��������� ...
			if (p->LChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // �������� ...
				{
					printf("Queue full !\n");
					IsStop = TRUE;
				}
				else
				{
					EnterQueue(&BiTreeQueue, p->LChild);
				}
			}

			// �Һ�������� ...
			if (p->RChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // �������� ...
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

		// �����ڵ����γ����� ...
		if (!IsQueueEmpty(&BiTreeQueue)) // ���зǿ� ...
		{
			// ���� ...
			LeaveQueue(&BiTreeQueue, &p);
		}
		else
			IsStop = TRUE; // ����Ϊ��, �������� ...
	}
}

// ����ָ������ض�ֵ�Ľ��ָ�� ...
// ( 1 ) �ٶ��������и�������е�ֵ������ͬ;
// ( 2 ) ���ö�������ǰ������ǵݹ��㷨ʵ��.
BiTreePtr FindBinaryTreeNode(BiTreePtr Root, char NodeData)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// ջ��ʼ�� ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			// �Ƿ��ҵ���� ...
			IsStop = (p->Data == NodeData);

			if (!IsStop)
			{
				// һֱ����ݹ� ...
				if (!IsStackFull(&BiTreeStack)) // �ж�ջ�Ƿ����� ...
				{
					PushStack(&BiTreeStack, p); // ע�� : ѹ��ջ����ָ��������нڵ��ָ�� ...
					p = p->LChild;
				}
				else // ջ��, �쳣�˳� ...
				{
					IsStop = TRUE;
					p = NULL;
				}
			}
		}

		// �˳�����ѭ�����������Ϊ��( �����Ѿ��ҵ����� ), ��ջ��ʼ�����Һ��� ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // �ж�ջ�Ƿ�Ϊ�� ...
			{
				PopStack(&BiTreeStack, &p);
				p = p->RChild;
			}
			else // ջΪ��, �������������, �˳� ...
			{
				IsStop = TRUE;
				p = NULL;
			}
		}
	}

	// ���ؽ�� ...
	return p;
}

// ����ָ������ض�ֵ�Ľ��ĸ����ָ�� ...
// ( 1 ) �ٶ��������и�������е�ֵ������ͬ;
// ( 2 ) ���ö�������ǰ������ǵݹ��㷨ʵ��.
BiTreePtr FindBinaryTreeNodeFather(BiTreePtr Root, char NodeData, BiTreeChildType *ChildType)
{
	SeqBiTreePtrStack BiTreeStack;
	BiTreePtr p;
	int IsStop;

	// ջ��ʼ�� ...
	InitStack(&BiTreeStack);

	p = Root;
	IsStop = FALSE;
	while (!IsStop)
	{
		while ((p != NULL) && (!IsStop))
		{
			// �Ƿ��ҵ������ ...
			if (p->LChild != NULL)
			{
				if ((p->LChild->Data == NodeData))
				{
					IsStop = TRUE;
					*ChildType = btLeftChild; // ��� 'NodeData' ���丸�������� ...
				}
			}

			if (!IsStop)
			{
				if (p->RChild != NULL)
				{
					if ((p->RChild->Data == NodeData))
					{
						IsStop = TRUE;
						*ChildType = btRightChild; // ��� 'NodeData' ���丸�����Һ��� ...
					}
				}
			}

			if (!IsStop)
			{
				// һֱ����ݹ� ...
				if (!IsStackFull(&BiTreeStack)) // �ж�ջ�Ƿ����� ...
				{
					PushStack(&BiTreeStack, p); // ע�� : ѹ��ջ����ָ��������нڵ��ָ�� ...
					p = p->LChild;
				}
				else // ջ��, �쳣�˳� ...
				{
					IsStop = TRUE;
					p = NULL;
				}
			}
		}

		// �˳�����ѭ�����������Ϊ��( �����Ѿ��ҵ����� ), ��ջ��ʼ�����Һ��� ...
		if (!IsStop)
		{
			if (!IsStackEmpty(&BiTreeStack)) // �ж�ջ�Ƿ�Ϊ�� ...
			{
				PopStack(&BiTreeStack, &p);
				p = p->RChild;
			}
			else // ջΪ��, �������������, �˳� ...
			{
				IsStop = TRUE;
				p = NULL;
			}
		}
	}

	// ���ؽ�� ...
	return p;
}

// ����������, ����ÿ�����ָ���丸����ָ���� ...
void SetBinaryTreeParent(BiTreePtr Root)
{
	SeqBiTreePtrQueue BiTreeQueue;
	BiTreePtr p;
	int IsStop;

	// ʹ�ö������Ĳ������ʵ�� ...

	// ���г�ʼ�� ...
	InitQueue(&BiTreeQueue);

	p = Root;
	p->Parent = NULL; // �����û�и����, 'Parent' ָ����Ϊ�� ...
	IsStop = FALSE;
	while (!IsStop)
	{
		if (p != NULL)
		{
			// ��������� ...
			if (p->LChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // �������� ...
					IsStop = TRUE;
				else
				{
					p->LChild->Parent = p; // ���� 'p' �����ӵ� 'Parent' ָ���� ...
					EnterQueue(&BiTreeQueue, p->LChild);
				}
			}

			// �Һ�������� ...
			if (p->RChild != NULL)
			{
				if (IsQueueFull(&BiTreeQueue)) // �������� ...
					IsStop = TRUE;
				else
				{
					p->RChild->Parent = p; // ���� 'p' ���Һ��ӵ� 'Parent' ָ���� ...
					EnterQueue(&BiTreeQueue, p->RChild);
				}
			}
		}

		// �����ڵ����γ����� ...
		if (!IsQueueEmpty(&BiTreeQueue)) // ���зǿ� ...
			LeaveQueue(&BiTreeQueue, &p); // ���� ...
		else
			IsStop = TRUE; // ����Ϊ��, �������� ...
	}
}

// ( ���ض���ʽ )���ʶ������еĸ������ ...
void VisitBinaryTree(BiTreePtr Root)
{
	// �������ɸ����û�����Ҫ���� '����', �������������е����� ...
	// ��ǰ���� : ����������е�Сд��ĸת��Ϊ��д��ĸ ...
	if (Root != NULL)
	{
		if ((Root->Data >= 'a') && (Root->Data <= 'z'))
		{
			// ת���ַ�( ��д��ĸ��Сд��ĸ�� ASCII ��ֵ��� 32 ) ...
			Root->Data -= 32;
		}

		// ǰ������㷨 ...
		printf("%c ", Root->Data);
		VisitBinaryTree(Root->LChild);
		VisitBinaryTree(Root->RChild);
	}
}

// ͳ�ƶ������еĽ����Ŀ( ʹ��ȫ���� 'TotalNodeNum' ʵ�� ) ...
void CountBinaryTreeNodeNum(BiTreePtr Root)
{
	if (Root != NULL)
	{
		// �ۼӽ����Ŀ ...
		TotalNodeNum++;

		// ǰ������㷨 ...
		CountBinaryTreeNodeNum(Root->LChild);
		CountBinaryTreeNodeNum(Root->RChild);
	}
}

// ��ʾ�������е�Ҷ�ӽ�� ...
void DisplayBinaryTreeLeafNode(BiTreePtr Root)
{
	if (Root != NULL)
	{
		// �ж��Ƿ�ΪҶ�ӽ�� ...
		if ((Root->LChild == NULL) && (Root->RChild == NULL))
			printf("%c ", Root->Data);

		// ǰ������㷨 ...
		DisplayBinaryTreeLeafNode(Root->LChild);
		DisplayBinaryTreeLeafNode(Root->RChild);
	}
}

// ͳ�ƶ�����Ҷ�ӽ����� ...
int CountBinaryTreeLeafNodeNum(BiTreePtr Root)
{
	int LNum, RNum; // ���������������е�Ҷ�ӽ����Ŀ ...

	// ���� ...
	if (Root == NULL)
		return 0;

	// �ҵ�Ҷ�ӽ�� ...
	if ((Root->LChild == NULL) && (Root->RChild == NULL))
		return 1;

	// ͳ����������Ҷ�ӽ����Ŀ( �ݹ���� ) ...
	LNum = CountBinaryTreeLeafNodeNum(Root->LChild);

	// ͳ����������Ҷ�ӽ����Ŀ( �ݹ���� ) ...
	RNum = CountBinaryTreeLeafNodeNum(Root->RChild);

	return (LNum + RNum);
}

// ����������ĸ߶�( ��� ) ...
int CalcBinaryTreeHeight(BiTreePtr Root)
{
	int LHeight, RHeight; // ���������������ĸ߶�( ��� ) ...

	// ���� ...
	if (Root == NULL)
		return 0;

	// �����������ĸ߶�( ��� ) ...
	LHeight = CalcBinaryTreeHeight(Root->LChild);

	// �����������ĸ߶�( ��� ) ...
	RHeight = CalcBinaryTreeHeight(Root->RChild);

	// ����ֵ ...
	if (LHeight > RHeight)
		return (LHeight + 1);
	else
		return (RHeight + 1);
}

// ����������Ķ� ...
// ( ������Ҫ��ͬѧʵ�� )
//�����Ҷ�ӽڵ�ĸ���
int leaf(BiTreePtr T, int &count)//count ��������� 
{
	if (T == NULL) //�����ݹ����� 
		return 0;
	if (T->LChild == NULL && T->RChild == NULL)//��ϵ�������ȼ�== �����߼�����&& 
		count++;
	leaf(T->RChild, count);//��������ʽ����λ�� 
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
	//�㷨ͳ�ƶ�Ϊ1���߶�Ϊ2�Ľڵ����
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

// ���Ҷ�ӽ�㵽������·�� ...
void DisplayBinaryTreePath(BiTreePtr Root)
{
	BiTreePtr p;

	if (Root != NULL)
	{
		// �ҵ�Ҷ�ӽ�� ...
		if ((Root->LChild == NULL) && (Root->RChild == NULL))
		{
			p = Root;

			// ���Ҷ�ӽ�㵽������·��( �����Ҷ�ӽ�������, ��Ҷ�ӽ�� ) ...
			printf("\n\t");
			printf("%c ", p->Data); // ���Ҷ�ӽ���ֵ ...

			// ��Ҷ�ӽ�㿪ʼ���ݵ����ڵ� ...
			while (p->Parent != NULL)
			{
				p = p->Parent; // �õ�ָ�򸸽���ָ�� ...
				printf("%c ", p->Data); // ���������ֵ ...
			}
			printf("\n");
		}

		// ���������� ...
		DisplayBinaryTreePath(Root->LChild);
		// ���������� ...
		DisplayBinaryTreePath(Root->RChild);
	}
}

// ��ʾֵΪ 'NodeData' �Ľ��ĸ�����ֵ ...
void DisplayBinaryTreeFather(BiTreePtr Root, char NodeData)
{
	BiTreePtr p;
	BiTreeChildType ChildType;

	// ���Ҹ����ָ�� ...
	p = FindBinaryTreeNodeFather(Root, NodeData, &ChildType);
	if (p != NULL)
		printf("\n\t��������� -> %c ", p->Data); // ��ӡ��������� ...
	else
		printf("\n\tδ�ҵ������ !\n\n");
}

// �ڶ����������ӽ�� ...
int AddBinaryTreeNodeChild(BiTreePtr Root, char NodeData, char ChildData)
{
	BiTreePtr p, q;
	int OK = TRUE;

	// ���Ҷ��������Ƿ����ֵΪ 'NodeData' �Ľ�� ...
	p = FindBinaryTreeNode(Root, NodeData);
	if (p != NULL)
	{
		// �����½����㷨Ϊ :
		// ( 1 ) ���ָ�� 'p' ָ�������Ӻ��Һ��Ӷ�����, ������½��ʧ��;
		// ( 2 ) ���ָ�� 'p' ָ������Ҷ�ӽ��, ���½�����Ϊ����;
		// ( 3 ) ���ָ�� 'p' ָ���������ӻ����Һ���, ���½�����Ϊ�Һ��ӻ�����;
		if ((p->LChild != NULL) && (p->RChild != NULL))
			OK = FALSE;
		else
		{
			// һ���������, �����ȴ������( �����Ľ��ΪҶ�ӽ�� ) ...
			q = (BiTreePtr)malloc(sizeof(BiTreeNode));
			q->Data = ChildData;
			q->Parent = p; // ����ָ�򸸽���ָ�� ...
			q->LChild = NULL;
			q->RChild = NULL;

			// ������Ϊ���Ӳ��� ...
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

// �ڶ�������ɾ�����( ͬʱɾ���ý���Ӧ�������ӽ�� ) ...
// ( ������Ҫ��ͬѧʵ�� )
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

// �޸Ķ������н���ֵ ...
int UpdateBinaryTreeNode(BiTreePtr Root, char NodeData, char NewData)
{
	BiTreePtr p;
	int OK = TRUE;

	// ���Ҷ��������Ƿ����ֵΪ 'NodeData' �Ľ�� ...
	p = FindBinaryTreeNode(Root, NodeData);
	if (p != NULL)
		p->Data = NewData; // �滻����ֵ ...
	else
		OK = FALSE;

	return OK;
}

// ��ʾ�������и��������ֵܽ�� ...
void DisplayBinaryTreeNodeBrothers(BiTreePtr Root, char NodeData)
{
	BiTreePtr p;
	BiTreeChildType ChildType;

	// ����ָ�򸸽���ָ�� ...
	p = FindBinaryTreeNodeFather(Root, NodeData, &ChildType);
	if (p != NULL)
	{
		// ���ݽ�� 'NodeData' ���丸���Ĳ�ͬ�������ͽ��д��� ...
		switch (ChildType)
		{
		case btLeftChild: {
			// ��� 'NodeData' ���丸�������� ...
			if (p->RChild != NULL)
				printf("\n\t�ֵܽ������ -> %c ", p->RChild->Data); // ��ӡ�ֵܽ������ ...
			else
				printf("\n\tû���ֵܽ�� !\n\n");

			break;
		}
		case btRightChild: {
			// ��� 'NodeData' ���丸�����Һ��� ...
			if (p->LChild != NULL)
				printf("\n\t�ֵܽ������ -> %c ", p->LChild->Data); // ��ӡ�ֵܽ������ ...
			else
				printf("\n\tû���ֵܽ�� !\n\n");

			break;
		}
		}
	}
}

// ��ʾ�������и����������Ƚ�� ...
// ( ������Ҫ��ͬѧʵ�� )
void DisplayBinaryTreeNodeAncestors(BiTreePtr Root, char NodeData)
{
		SeqBiTreePtrStack s;
		BiTreeNode q;
		BiTreePtr p = Root;
		char x;
		printf("������ҵĽڵ�:");
		scanf("%c", &x);
		InitStack(&s);
		while (p || !IsStackEmpty(&s))
		{
			if (p) {
				q.flag = 0;//û�з����Һ���
				q.Data = p;
				pushStack(s, q);//ѹջ
				p = p->lchild;
			}
			else {
				outStack(s, &q);
				p = q.data;
				if (q.flag == 0) {
					q.flag = 1;//�������Һ���
					pushStack(s, q);
					p = p->rchild;
				}
				else {
					if (p->data == x)break;
					p = NULL;//û�ҵ��ڵ㣬���ص���һ�ڵ�
				}
			}
		}
		if (emptyStack(s))printf("�Ҳ����ýڵ�����ȣ�");
		else {
			printf("%c������:", x);
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
//                             �������������ʵ��                              // 
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
		fflush(stdin); // ��ջ����� ...

		// ��������� ...
		printf("\n\t�������ݴ���������( ע���������ݵĴ�������� ) :\n\t");
		Root = CreateBinaryTree();

		// ����������, ����ÿ�����ָ�򸸽���ָ���� ...
		SetBinaryTreeParent(Root);

		// �������ı��� ...
		printf("\n\t��������ǰ�����( �ݹ鷽ʽ )Ϊ : ");
		RE_PreOrderBinaryTree(Root);
		printf("\n");
		printf("\n\t��������ǰ�����( �ǵݹ鷽ʽ )Ϊ : ");
		PreOrderBinaryTree(Root);
		printf("\n\n");

		printf("\n\t���������������( �ݹ鷽ʽ )Ϊ : ");
		RE_InOrderBinaryTree(Root);
		printf("\n");
		printf("\n\t���������������( �ǵݹ鷽ʽ )Ϊ : ");
		InOrderBinaryTree(Root);
		printf("\n\n");

		printf("\n\t�������ĺ������( �ݹ鷽ʽ )Ϊ : ");
		RE_PostOrderBinaryTree(Root);
		printf("\n");
		printf("\n\t�������ĺ������( �ǵݹ鷽ʽ )Ϊ : ");
		PostOrderBinaryTree(Root);
		printf("\n\n");

		printf("\n\t�������Ĳ������( �ǵݹ鷽ʽ )Ϊ : ");
		LevelOrderBinaryTree(Root);
		printf("\n\n");

		// ���ʶ������еĸ������ ...
		printf("\n\t���ʶ������ĸ������Ϊ : ");
		VisitBinaryTree(Root);
		printf("\n\n");

		// ͳ�ƶ������еĽ����Ŀ ...
		TotalNodeNum = 0; // �������н������ ...
		CountBinaryTreeNodeNum(Root);
		printf("\n\t�������н������Ϊ : %d\n\n", TotalNodeNum);

		// ��ʾ�������е�Ҷ�ӽ�� ...
		printf("\n\t�������е�Ҷ�ӽ��Ϊ : ");
		DisplayBinaryTreeLeafNode(Root);
		printf("\n\n");

		// ͳ�ƶ�����Ҷ�ӽ����� ...
		printf("\n\t��������Ҷ�ӽ����ĿΪ : %d\n\n", CountBinaryTreeLeafNodeNum(Root));

		// ����������ĸ߶�( ��� ) ...
		printf("\n\t�������ĸ߶�( ��� )Ϊ : %d\n\n", CalcBinaryTreeHeight(Root));

		// ����������Ķ� ...
		printf("\n\t�������Ķ�Ϊ : %d\n\n", CalcBinaryTreeDegree(Root));

		// ���Ҷ�ӽ�㵽������·�� ...
		printf("\n\t���Ҷ�ӽ�㵽������·�� :\n");
		DisplayBinaryTreePath(Root);
		printf("\n\n");

		// ��ʾ�����ض�ֵ�Ľ��ĵĸ�����ֵ ...
		printf("\n\t***** ���Ҹ������ĸ���� *****");
		printf("\n\t��ǰ������������Ϊ : ");
		RE_PreOrderBinaryTree(Root);
		printf("\n\t����������ҵĽ������ : ");
		scanf("%s", UserInput);
		DisplayBinaryTreeFather(Root, UserInput[0]);

		// �ڶ����������ӽ�� ...
		printf("\n\n\n\t***** �ڶ����������ӽ�� *****");
		printf("\n\t����������ҵĽ������ : ");
		scanf("%s", UserInput);
		NodeData = UserInput[0];
		printf("\n\t����������Ϊ�ӽ��Ľ������ : ");
		scanf("%s", UserInput);
		ChildData = UserInput[0];
		if (AddBinaryTreeNodeChild(Root, NodeData, ChildData))
		{
			printf("\n\t���ӽ��ɹ� ! ��ǰ������������Ϊ : ");
			RE_PreOrderBinaryTree(Root);
			printf("\n\n");
		}
		else
			printf("\n\t���ӽ��ʧ�� !\n");

		// �ڶ�������ɾ�����( ͬʱɾ���ý���Ӧ�������ӽ�� ) ...
		printf("\n\n\n\t***** �ڶ�������ɾ����� *****");
		printf("\n\t����������ҵĽ������ : ");
		scanf("%s", UserInput);
		NodeData = UserInput[0];
		if (DeleteBinaryTreeNode(Root, NodeData))
		{
			printf("\n\tɾ�����ɹ� ! ��ǰ������������Ϊ : ");
			RE_PreOrderBinaryTree(Root);
			printf("\n\n");
		}
		else
			printf("\n\tɾ�����ʧ�� !\n");

		// �޸Ķ������н���ֵ ...
		printf("\n\n\n\t***** �޸Ķ������н���ֵ *****");
		printf("\n\t����������ҵĽ������ : ");
		scanf("%s", UserInput);
		NodeData = UserInput[0];
		printf("\n\t�������޸ĺ�Ľ������ : ");
		scanf("%s", UserInput);
		NewData = UserInput[0];
		if (UpdateBinaryTreeNode(Root, NodeData, NewData))
		{
			printf("\n\t�޸Ľ��ɹ� ! ��ǰ������������Ϊ : ");
			RE_PreOrderBinaryTree(Root);
			printf("\n\n");
		}
		else
			printf("\n\t�޸Ľ��ʧ�� !\n");

		// ��ʾ�������и��������ֵܽ�� ...
		printf("\n\n\n\t***** ���Ҹ��������ֵܽ�� *****");
		printf("\n\n\t����������ҵĽ������ : ");
		scanf("%s", UserInput);
		DisplayBinaryTreeNodeBrothers(Root, UserInput[0]);

		// ��ʾ�������и����������Ƚ�� ...
		printf("\n\n\n\t***** ���Ҹ����������Ƚ�� *****");
		printf("\n\n\t����������ҵĽ������ : ");
		scanf("%s", UserInput);
		DisplayBinaryTreeNodeAncestors(Root, UserInput[0]);

		// �ͷŶ������ռ� ...
		DestroyBinaryTree(Root);

		printf("\n\n");
		printf("\n\t��������[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
