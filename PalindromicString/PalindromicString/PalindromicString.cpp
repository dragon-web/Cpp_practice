#define _CRT_SECURE_NO_WARNINGS 

#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<Windows.h>



#define STACK_SIZE 100
#define TRUE       1
#define FALSE      0

// ˳��ջ( �ַ��� )�Ľṹ�����Ͷ��� ...
typedef struct
{
	char Elem[STACK_SIZE];
	int  Top;
} SeqCharStack;



// ˳��ջ( �ַ��� )�Ĳ�����ʵ�� ...
void InitStack(SeqCharStack *S);
int  IsStackEmpty(SeqCharStack *S);
int  IsStackFull(SeqCharStack *S);
void  PushStack(SeqCharStack *S, char x);
void  PopStack(SeqCharStack *S);
char TopStack(SeqCharStack *S);//ȡջ��Ԫ��
int IsPalindromicString(char *s);

// ջ��ʼ�� ...
void InitStack(SeqCharStack *S)
{
	S->Top = -1;
}

// ջ�Ƿ�Ϊ�� ...
int IsStackEmpty(SeqCharStack *S)
{
	return (S->Top == -1);
}

// ջ�Ƿ�Ϊ�� ...
int IsStackFull(SeqCharStack *S)
{
	return (S->Top == (STACK_SIZE - 1));
}
char TopStack(SeqCharStack *S)//ȡջ��Ԫ��
{
	if (!IsStackEmpty(S))
	{
		return S->Elem[S->Top];
	}
	else
	{
		printf("ջ�գ���ջ��\n");
		return false;
	}
}
// ��ջ ...
// ( ������Ҫ��ͬѧʵ�� )
void PushStack(SeqCharStack *S, char x)
{
	if (IsStackFull(S))
	{
		printf("ջ�Ѿ����˲��ܼ�������");
	}
	S->Elem[S->Top+1] = x;
	S->Top++;
}

// ��ջ ...
// ( ������Ҫ��ͬѧʵ�� )

int a = 0;
void PopStack(SeqCharStack *S) //������ջ��Ԫ��
{
	if (IsStackEmpty(S))
	{
		printf("ջ�Ѿ����˲��ܼ�����ջ");
	}
	S->Top--;
	a++;
}
// ����ջ�ж��ַ����Ƿ�Ϊ�����ַ��� ...
// ( ������Ҫ��ͬѧʵ�� )
int IsPalindromicString(char *s)
{
	SeqCharStack PStrStack;
	size_t length = strlen(s);
	char* vec1 = (char*)malloc(length +1);
	vec1[length] = '\0';
	int       OK = TRUE;
	// '����' ��ָ�����ͷ�������ͬ���ַ�����. �� 'abba' �� 'abcba' ���ǻ����ַ���.
	// ���ݻ��ĵ��ص�, ��֪����ջ���Է�����ж��Ƿ�Ϊ����. ���巽���ǽ����ж����ַ���
	// ��ÿ���ַ�����ѹ��ջ, ��ջʱ( ����Ϊ��β��ͷ )���κʹ��ж��ַ�����ͷ��β��ÿ��
	// �ַ����бȽ�, ���������ǻ���.
	//
	// ʾ�� :
	//
	// ( 1 ) �ж��ַ��� 'abta' �Ƿ�Ϊ����.
	// ��ջ���� : a b t a ( ���ж��ַ�����ͷ��β�Ĵ��� ) 
	// ��ջ���� : a t b a
	// ��   �� : �����, ���Բ��ǻ���
	//
	// ( 2 ) �ж��ַ��� 'adcda' �Ƿ�Ϊ����.
	// ��ջ���� : a d c d a ( ���ж��ַ�����ͷ��β�Ĵ��� ) 
	// ��ջ���� : a d c d a
	// ��   �� : ���, �����ǻ���

	// ջ��ʼ�� ...
	InitStack(&PStrStack);

	// �ַ�ѹջ ...
	for (int i = 0; i < length; ++i)
	{
		PushStack(&PStrStack, s[i]);
	}
	// �ַ���ջ ...  ��ʱ���s�������������ջ��Ԫ��
	for (int j = 0; j < length; ++j)
	{
		vec1[j] = TopStack(&PStrStack);
		PopStack(&PStrStack);
	}
	for (int i = 0; i < length; ++i)
	{
		if (vec1[i] != s[i])
		{
			return false;
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             �������������ʵ��                              // 
//                                                                          // 
// ######################################################################## //

int main()
{
	char Str[50];
	int  IsStop;

	IsStop = FALSE;
	while (!IsStop)
	{
		printf("\n\n\t������ < ���б��ַ��� > �� ���� < q / Q > ��ʾ���� : ");
		scanf("%s", Str);

		if (strlen(Str))
		{
			IsStop = ((Str[0] == 'q') || (Str[0] == 'Q'));
			if (!IsStop)
			{
				// �ж��Ƿ�Ϊ�����ַ��� ...
				if (IsPalindromicString(Str))
					printf("\n\t�ַ��� %s �ǻ����ַ�����\n", Str);
				else
					printf("\n\t�ַ��� %s ���ǻ����ַ�����\n", Str);
			}
		}
		else
			printf("������ַ�������Ϊ�� !\n\n");
	}
	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}


