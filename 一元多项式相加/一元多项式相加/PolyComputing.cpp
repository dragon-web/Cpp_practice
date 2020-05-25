#define _CRT_SECURE_NO_WARNINGS 


// ʹ�õĿⶨ��
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<Windows.h>

#define TRUE  1
#define FALSE 0

// һԪ����ʽ���õ������ʾ, �����������нڵ�Ľṹ�����Ͷ��� ...
typedef struct PolyNode
{
	int Coef;              // ����ʽϵ�� ...
	int Exp;               // ����ʽָ�� ...
	struct PolyNode *next; // ����ָ�� ...
}PolyNode, *PolyList;

PolyList PolyA_HeadPtr; // ����ʽ A( x ) ������ͷָ�� ...
PolyList PolyB_HeadPtr; // ����ʽ B( x ) ������ͷָ�� ...


PolyList CreateEmptyPoly(PolyList Head_Ptr);
void     ClearPoly(PolyList HeadPtr);
void     DestroyPoly(PolyList HeadPtr);
void     PrintPoly(PolyList HeadPtr);
void     CreatePolyByKeyboard(PolyList HeadPtr);
void     AddPoly(PolyList PolyA_Head, PolyList PolyB_Head);


// ����һ���ն���ʽ����( ������һ��ͷ��� ) ...
PolyList CreateEmptyPoly(PolyList Head_Ptr)
{
	Head_Ptr = (PolyList)malloc(sizeof(PolyNode));
	Head_Ptr->next = NULL;

	return Head_Ptr;
}

// ��������е����нڵ���Ϣ( ������ͷ��� ) ...
// ( ������Ҫ��ͬѧʵ�� )
void ClearPoly(PolyList HeadPtr)//�������еĳ�ͷ���Ľڵ��ֵ����
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

// �ͷ��������� ...
void DestroyPoly(PolyList HeadPtr)//ʵ���Ͼ�������ͷ��������Ҳ���
{
	// ��������е����нڵ���Ϣ( ������ͷ��� ) ...
	ClearPoly(HeadPtr);

	// ���ͷ���ռ� ...
	if (HeadPtr != NULL)
		free(HeadPtr);
}

// ��ӡ���һԪ����ʽ ...
void PrintPoly(PolyList HeadPtr)
{
	PolyNode *p;

	// ����ʽΪ��ʱ��� '0' ...
	if (HeadPtr->next == NULL)
	{
		printf("0");
		return;
	}
	// ָ������
	p = HeadPtr->next;
	while (p != NULL)
	{
		// ��ӡ����Ľ������ : 
		// 9x - 2x ^ 2 + 11x ^ 5
		// 1 + 3x ^ 2 - 4x ^ 7
		// -5 - x ^ 3 + 5x ^ 10
		// 1 - x - x ^ 6 + 10x ^ 9

		// ��һ����ŵĴ��� ...
		if (p == HeadPtr->next)
		{
			if (p->Coef < 0)
				printf("-");
		}

		// ��ӡϵ��ֵ ...
		if (p->Exp == 0) // �������� ...
		{
			printf("%d", p->Coef);
		}
		else
		{
			if (p->Exp == 1) // ����һ���� ...
			{
				if (abs(p->Coef) == 1)
					printf("x");
				else
					printf("%dx", abs(p->Coef));
			}
			else // ������������ ...
			{
				if (abs(p->Coef) == 1)
					printf("x ^ %d", p->Exp);
				else
					printf("%dx ^ %d", abs(p->Coef), p->Exp);
			}
		}

		// ���һ�����ָ��� ...
		if (p->next != NULL)
		{
			if (p->next->Coef > 0)
				printf(" + ");
			else
				printf(" - ");
		}

		// ������һ�� ...
		p = p->next;
	}
}

// �����û��Ӽ��������һԪ����ʽ��ϵ��ֵ��ָ��ֵ��������( ָ��������ʱ������С���� ) ...
// ����ʽ 'A' �� 'B' ���( ����ʽ������ָ��������С�������� ) ...
// ( ������Ҫ��ͬѧʵ�� )
void CreatePolyByKeyboard(PolyList HeadPtr)
{
	PolyNode *r, *s;
	char     str[50];
	int      Coef; // ����ʽϵ�� ...
	int      Exp;  // ����ʽָ�� ...
	int      IsStop;

	// ��������е�ԭ������ ...
	ClearPoly(HeadPtr);

	// ͷ�ڵ�ָ�� ...
	r = HeadPtr;

	IsStop = FALSE;
	while (!IsStop)
	{
		printf("\t������ < ����ʽϵ�� - ����ֵ > ( q �� Q �˳� ): ");
		scanf("%s", str);

		IsStop = ((str[0] == 'q') || (str[0] == 'Q'));
		if (!IsStop)
		{
			Coef = atoi(str); // �ַ���ת��Ϊ���� ...

			printf("\t������ < ����ʽָ�� - ����ֵ > ( q �� Q �˳� ): ");
			scanf("%s", str);

			IsStop = ((str[0] == 'q') || (str[0] == 'Q'));
			if (!IsStop)
			{
				Exp = atoi(str); // �ַ���ת��Ϊ���� ...

				// ʹ�� 'β�巨' ��������ʽ ...
				s = (PolyNode *)malloc(sizeof(PolyNode));
				s->Coef = Coef;
				s->Exp = Exp;
				r->next = s;
				r = s;
			}

			printf("\t\n");
		}
	}

	// ��������������( β�巨 ) ...
	r->next = NULL;
}

// ����ʽ 'A' �� 'B' ���( ����ʽ������ָ��������С�������� ) ...
// ( ������Ҫ��ͬѧʵ�� )


void AddPoly(PolyList PolyA_Head, PolyList PolyB_Head)
{
	PolyNode *p, *q, *r, *t;
	int sum;

	// �㷨˼· : �� 'A' ����ʽΪ��׼, �� 'B' ����ʽ�ӵ� 'A' ����ʽ��, ���ս���� 'A' ����ʽ���� ...
	//
	// ( 1 ) �� 'p' ָ��ָ�� 'A' ����ʽ, 'q' ָ��ָ�� 'B' ����ʽ;
	//
	// ( 2 ) ��� 'p -> Exp < q -> Exp', ���� p ��ָ�Ľ��Ӧ�� '�Ͷ���ʽ' �е�һ��, ��ָ�� p ����;
	//
	// ( 3 ) ��� 'p -> Exp = q -> Exp', ��������е�ϵ�����, ���Ͳ�Ϊ��ʱ�޸Ľ�� p ��ϵ����, �ͷ� q ���;
	//       ����Ϊ��, ��Ͷ���ʽ���޴���, ɾȥ p ���, ͬʱ�ͷ� p �� q ���;
	//
	// ( 4 ) ��� 'p -> Exp > q -> Exp', ���� q ��ָ�Ľ��Ӧ�� '�Ͷ���ʽ' �е�һ��, ����� q �����ڽ�� p ֮
	//       ǰ, ����ָ�� q ��ԭ���������Ϻ���;
	//
	// ( 5 ) ע��� 'B' ����ʽ�����нڵ�Ĵ���, Ҫô�ͷŵ�, Ҫô���� 'A' ����ʽ����.
	p = PolyA_Head->next;
	q = PolyB_Head->next;
	r = PolyA_Head; // 'r' ָ������ָ�� 'p' ��ǰһ���ڵ� ...

	// �� 'B' ����ʽ�����нڵ�Ĵ���, Ҫô�ͷŵ�, Ҫô���� 'A' ����ʽ����, ����ֱ�ӽ����ÿ� ...
	PolyB_Head->next = NULL;
	//��������Ǹ���С�������ʽ���
	while ((p != NULL) && (q != NULL)) 
	{
		if ((p->Exp) < (q->Exp))
		{
			r = p; // 'r' ָ������ָ�� 'p' ��ǰһ���ڵ� ...
			p = p->next;//�൱����ʵ�������ָ���������ϵ��ƶ�
		}
		else if (p->Exp == q->Exp)
		{
			// ϵ����� ...
			sum = p->Coef + q->Coef;
			if (sum == 0)
			{
				t = p;
				r->next = p->next;//ʵ��������ĶϿ�
				free(t);
			}
			else
			{
				p->Coef = sum; // �޸Ľ�� p ��ϵ���� ...

				// �ͷ� q ��� ...
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
			q = t;//������q���ƶ�
			r = r->next;
		}
	} // end 'while ( ( p != NULL ) && ( q != NULL ) )' ...

	// �� 'B' ����Ϊ��, ��ʣ�µĽڵ��������� ...
	if (p != NULL)
		r->next = p;

	// �� 'A' ����Ϊ��, ��ʣ�µĽڵ��������� ...
	if (q != NULL)
		r->next = q;
}

int main()
{
	int  IsStop;
	char UserInput[20];

	// ��ʼ��һԪ����ʽ 'A' �� 'B'( ����ͷ��� ) ...
	PolyA_HeadPtr = CreateEmptyPoly(PolyA_HeadPtr);
	PolyB_HeadPtr = CreateEmptyPoly(PolyB_HeadPtr);

	IsStop = FALSE;
	while (!IsStop)
	{
		// �������ʽ 'A' ...
		printf("\n\n\t������һԪ����ʽ A( x )�� ����Ķ���ʽָ��ֵ������С���� ...\n\n");
		CreatePolyByKeyboard(PolyA_HeadPtr);
		printf("\n\t����ʽ A( x ) = ");
		PrintPoly(PolyA_HeadPtr);
		printf("\n\n");

		// �������ʽ 'B' ...
		printf("\n\n\t������һԪ����ʽ B( x )�� ����Ķ���ʽָ��ֵ������С���� ...\n\n");
		CreatePolyByKeyboard(PolyB_HeadPtr);
		printf("\n\t����ʽ B( x ) = ");
		PrintPoly(PolyB_HeadPtr);
		printf("\n\n");

		// ����ʽ��� ...
		AddPoly(PolyA_HeadPtr, PolyB_HeadPtr);
		printf("\n\t����ʽ A( x ) + B( x ) = ");
		PrintPoly(PolyA_HeadPtr);
		printf("\n\n");

		printf("\n\n");
		printf("\n\t��������[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// �ͷſռ� ...
	DestroyPoly(PolyA_HeadPtr);
	DestroyPoly(PolyB_HeadPtr);

	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}


