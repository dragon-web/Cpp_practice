#define _CRT_SECURE_NO_WARNINGS 

#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<Windows.h>



#define STACK_SIZE 100
#define TRUE       1
#define FALSE      0

// 顺序栈( 字符型 )的结构体类型定义 ...
typedef struct
{
	char Elem[STACK_SIZE];
	int  Top;
} SeqCharStack;



// 顺序栈( 字符型 )的操作及实现 ...
void InitStack(SeqCharStack *S);
int  IsStackEmpty(SeqCharStack *S);
int  IsStackFull(SeqCharStack *S);
void  PushStack(SeqCharStack *S, char x);
void  PopStack(SeqCharStack *S);
char TopStack(SeqCharStack *S);//取栈顶元素
int IsPalindromicString(char *s);

// 栈初始化 ...
void InitStack(SeqCharStack *S)
{
	S->Top = -1;
}

// 栈是否为空 ...
int IsStackEmpty(SeqCharStack *S)
{
	return (S->Top == -1);
}

// 栈是否为满 ...
int IsStackFull(SeqCharStack *S)
{
	return (S->Top == (STACK_SIZE - 1));
}
char TopStack(SeqCharStack *S)//取栈顶元素
{
	if (!IsStackEmpty(S))
	{
		return S->Elem[S->Top];
	}
	else
	{
		printf("栈空，无栈顶\n");
		return false;
	}
}
// 入栈 ...
// ( 本函数要求同学实现 )
void PushStack(SeqCharStack *S, char x)
{
	if (IsStackFull(S))
	{
		printf("栈已经满了不能继续插入");
	}
	S->Elem[S->Top+1] = x;
	S->Top++;
}

// 出栈 ...
// ( 本函数要求同学实现 )

int a = 0;
void PopStack(SeqCharStack *S) //将返回栈顶元素
{
	if (IsStackEmpty(S))
	{
		printf("栈已经空了不能继续出栈");
	}
	S->Top--;
	a++;
}
// 利用栈判定字符串是否为回文字符串 ...
// ( 本函数要求同学实现 )
int IsPalindromicString(char *s)
{
	SeqCharStack PStrStack;
	size_t length = strlen(s);
	char* vec1 = (char*)malloc(length +1);
	vec1[length] = '\0';
	int       OK = TRUE;
	// '回文' 是指正读和反读都相同的字符序列. 如 'abba' 和 'abcba' 都是回文字符串.
	// 根据回文的特点, 可知利用栈可以方便地判定是否为回文. 具体方法是将待判定的字符串
	// 的每个字符依次压入栈, 出栈时( 次序为从尾至头 )依次和待判定字符串从头至尾的每个
	// 字符进行比较, 相等则表明是回文.
	//
	// 示例 :
	//
	// ( 1 ) 判定字符串 'abta' 是否为回文.
	// 入栈次序 : a b t a ( 待判定字符串从头至尾的次序 ) 
	// 出栈次序 : a t b a
	// 结   论 : 不相等, 所以不是回文
	//
	// ( 2 ) 判定字符串 'adcda' 是否为回文.
	// 入栈次序 : a d c d a ( 待判定字符串从头至尾的次序 ) 
	// 出栈次序 : a d c d a
	// 结   论 : 相等, 所以是回文

	// 栈初始化 ...
	InitStack(&PStrStack);

	// 字符压栈 ...
	for (int i = 0; i < length; ++i)
	{
		PushStack(&PStrStack, s[i]);
	}
	// 字符弹栈 ...  此时这个s用来接收这个弹栈的元素
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
//                             下面是主程序的实现                              // 
//                                                                          // 
// ######################################################################## //

int main()
{
	char Str[50];
	int  IsStop;

	IsStop = FALSE;
	while (!IsStop)
	{
		printf("\n\n\t请输入 < 待判别字符串 > ， 输入 < q / Q > 表示结束 : ");
		scanf("%s", Str);

		if (strlen(Str))
		{
			IsStop = ((Str[0] == 'q') || (Str[0] == 'Q'));
			if (!IsStop)
			{
				// 判定是否为回文字符串 ...
				if (IsPalindromicString(Str))
					printf("\n\t字符串 %s 是回文字符串！\n", Str);
				else
					printf("\n\t字符串 %s 不是回文字符串！\n", Str);
			}
		}
		else
			printf("输入的字符串不能为空 !\n\n");
	}
	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}


