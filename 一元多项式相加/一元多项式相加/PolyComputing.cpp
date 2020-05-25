#define _CRT_SECURE_NO_WARNINGS 


// 使用的库定义
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<Windows.h>

#define TRUE  1
#define FALSE 0

// 一元多项式采用单链表表示, 下面是链表中节点的结构体类型定义 ...
typedef struct PolyNode
{
	int Coef;              // 多项式系数 ...
	int Exp;               // 多项式指数 ...
	struct PolyNode *next; // 链接指针 ...
}PolyNode, *PolyList;

PolyList PolyA_HeadPtr; // 多项式 A( x ) 的链表头指针 ...
PolyList PolyB_HeadPtr; // 多项式 B( x ) 的链表头指针 ...


PolyList CreateEmptyPoly(PolyList Head_Ptr);
void     ClearPoly(PolyList HeadPtr);
void     DestroyPoly(PolyList HeadPtr);
void     PrintPoly(PolyList HeadPtr);
void     CreatePolyByKeyboard(PolyList HeadPtr);
void     AddPoly(PolyList PolyA_Head, PolyList PolyB_Head);


// 创建一个空多项式链表( 仅包含一个头结点 ) ...
PolyList CreateEmptyPoly(PolyList Head_Ptr)
{
	Head_Ptr = (PolyList)malloc(sizeof(PolyNode));
	Head_Ptr->next = NULL;

	return Head_Ptr;
}

// 清除链表中的所有节点信息( 但保留头结点 ) ...
// ( 本函数要求同学实现 )
void ClearPoly(PolyList HeadPtr)//即将所有的除头结点的节点的值清零
{
	PolyNode *p = HeadPtr;
	PolyNode* temp = p->next;
	while (temp != NULL)
	{
		temp->Coef = 0;
		temp->Exp = 0;
		temp = temp->next;
	}
}

// 释放整个链表 ...
void DestroyPoly(PolyList HeadPtr)//实际上就是销毁头结点让其找不到
{
	// 清除链表中的所有节点信息( 但保留头结点 ) ...
	ClearPoly(HeadPtr);

	// 清除头结点空间 ...
	if (HeadPtr != NULL)
		free(HeadPtr);
}

// 打印输出一元多项式 ...
void PrintPoly(PolyList HeadPtr)
{
	PolyNode *p;

	// 多项式为空时输出 '0' ...
	if (HeadPtr->next == NULL)
	{
		printf("0");
		return;
	}
	// 指向链表
	p = HeadPtr->next;
	while (p != NULL)
	{
		// 打印输出的结果形如 : 
		// 9x - 2x ^ 2 + 11x ^ 5
		// 1 + 3x ^ 2 - 4x ^ 7
		// -5 - x ^ 3 + 5x ^ 10
		// 1 - x - x ^ 6 + 10x ^ 9

		// 第一项符号的处理 ...
		if (p == HeadPtr->next)
		{
			if (p->Coef < 0)
				printf("-");
		}

		// 打印系数值 ...
		if (p->Exp == 0) // 处理常数项 ...
		{
			printf("%d", p->Coef);
		}
		else
		{
			if (p->Exp == 1) // 处理一次项 ...
			{
				if (abs(p->Coef) == 1)
					printf("x");
				else
					printf("%dx", abs(p->Coef));
			}
			else // 处理其他次项 ...
			{
				if (abs(p->Coef) == 1)
					printf("x ^ %d", p->Exp);
				else
					printf("%dx ^ %d", abs(p->Coef), p->Exp);
			}
		}

		// 最后一项不输出分隔符 ...
		if (p->next != NULL)
		{
			if (p->next->Coef > 0)
				printf(" + ");
			else
				printf(" - ");
		}

		// 处理下一项 ...
		p = p->next;
	}
}

// 根据用户从键盘输入的一元多项式的系数值和指数值构建链表( 指数项输入时必须由小到大 ) ...
// 多项式 'A' 和 'B' 相加( 多项式链表中指数必须由小到大排列 ) ...
// ( 本函数要求同学实现 )
void CreatePolyByKeyboard(PolyList HeadPtr)
{
	PolyNode *r, *s;
	char     str[50];
	int      Coef; // 多项式系数 ...
	int      Exp;  // 多项式指数 ...
	int      IsStop;

	// 清除链表中的原有数据 ...
	ClearPoly(HeadPtr);

	// 头节点指针 ...
	r = HeadPtr;

	IsStop = FALSE;
	while (!IsStop)
	{
		printf("\t请输入 < 多项式系数 - 整数值 > ( q 或 Q 退出 ): ");
		scanf("%s", str);

		IsStop = ((str[0] == 'q') || (str[0] == 'Q'));
		if (!IsStop)
		{
			Coef = atoi(str); // 字符串转换为整数 ...

			printf("\t请输入 < 多项式指数 - 整数值 > ( q 或 Q 退出 ): ");
			scanf("%s", str);

			IsStop = ((str[0] == 'q') || (str[0] == 'Q'));
			if (!IsStop)
			{
				Exp = atoi(str); // 字符串转换为整数 ...

				// 使用 '尾插法' 创建多项式 ...
				s = (PolyNode *)malloc(sizeof(PolyNode));
				s->Coef = Coef;
				s->Exp = Exp;
				r->next = s;
				r = s;
			}

			printf("\t\n");
		}
	}

	// 整个链表创建结束( 尾插法 ) ...
	r->next = NULL;
}

// 多项式 'A' 和 'B' 相加( 多项式链表中指数必须由小到大排列 ) ...
// ( 本函数要求同学实现 )


void AddPoly(PolyList PolyA_Head, PolyList PolyB_Head)
{
	PolyNode *p, *q, *r, *t;
	int sum;

	// 算法思路 : 以 'A' 多项式为基准, 将 'B' 多项式加到 'A' 多项式上, 最终结果以 'A' 多项式返回 ...
	//
	// ( 1 ) 令 'p' 指针指向 'A' 多项式, 'q' 指针指向 'B' 多项式;
	//
	// ( 2 ) 如果 'p -> Exp < q -> Exp', 则结点 p 所指的结点应是 '和多项式' 中的一项, 令指针 p 后移;
	//
	// ( 3 ) 如果 'p -> Exp = q -> Exp', 则将两结点中的系数相加, 当和不为零时修改结点 p 的系数域, 释放 q 结点;
	//       当和为零, 则和多项式中无此项, 删去 p 结点, 同时释放 p 和 q 结点;
	//
	// ( 4 ) 如果 'p -> Exp > q -> Exp', 则结点 q 所指的结点应是 '和多项式' 中的一项, 将结点 q 插入在结点 p 之
	//       前, 且令指针 q 在原来的链表上后移;
	//
	// ( 5 ) 注意对 'B' 多项式链表中节点的处理, 要么释放掉, 要么加入 'A' 多项式链表.
	p = PolyA_Head->next;
	q = PolyB_Head->next;
	r = PolyA_Head; // 'r' 指针总是指向 'p' 的前一个节点 ...

	// 对 'B' 多项式链表中节点的处理, 要么释放掉, 要么加入 'A' 多项式链表, 所以直接将其置空 ...
	PolyB_Head->next = NULL;
	//这个处理是个从小到大多项式相加
	while ((p != NULL) && (q != NULL)) 
	{
		if ((p->Exp) < (q->Exp))
		{
			r = p; // 'r' 指针总是指向 'p' 的前一个节点 ...
			p = p->next;//相当于是实现了这个指针在链表上的移动
		}
		else if (p->Exp == q->Exp)
		{
			// 系数相加 ...
			sum = p->Coef + q->Coef;
			if (sum == 0)
			{
				t = p;
				r->next = p->next;//实现了链表的断开
				free(t);
			}
			else
			{
				p->Coef = sum; // 修改结点 p 的系数域 ...

				// 释放 q 结点 ...
				t = q;
				q = q->next;
				free(t);
			}
		}
		else // 'p -> Exp > q -> Exp' ...
		{
			t = q->next;
			q->next = p;
			r->next = q;
			q = t;//链表在q上移动
			r = r->next;
		}
	} // end 'while ( ( p != NULL ) && ( q != NULL ) )' ...

	// 若 'B' 链表为空, 将剩下的节点链接起来 ...
	if (p != NULL)
		r->next = p;

	// 若 'A' 链表为空, 将剩下的节点链接起来 ...
	if (q != NULL)
		r->next = q;
}

int main()
{
	int  IsStop;
	char UserInput[20];

	// 初始化一元多项式 'A' 和 'B'( 创建头结点 ) ...
	PolyA_HeadPtr = CreateEmptyPoly(PolyA_HeadPtr);
	PolyB_HeadPtr = CreateEmptyPoly(PolyB_HeadPtr);

	IsStop = FALSE;
	while (!IsStop)
	{
		// 输入多项式 'A' ...
		printf("\n\n\t请输入一元多项式 A( x )， 输入的多项式指数值必须由小到大 ...\n\n");
		CreatePolyByKeyboard(PolyA_HeadPtr);
		printf("\n\t多项式 A( x ) = ");
		PrintPoly(PolyA_HeadPtr);
		printf("\n\n");

		// 输入多项式 'B' ...
		printf("\n\n\t请输入一元多项式 B( x )， 输入的多项式指数值必须由小到大 ...\n\n");
		CreatePolyByKeyboard(PolyB_HeadPtr);
		printf("\n\t多项式 B( x ) = ");
		PrintPoly(PolyB_HeadPtr);
		printf("\n\n");

		// 多项式相加 ...
		AddPoly(PolyA_HeadPtr, PolyB_HeadPtr);
		printf("\n\t多项式 A( x ) + B( x ) = ");
		PrintPoly(PolyA_HeadPtr);
		printf("\n\n");

		printf("\n\n");
		printf("\n\t继续处理[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// 释放空间 ...
	DestroyPoly(PolyA_HeadPtr);
	DestroyPoly(PolyB_HeadPtr);

	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}


