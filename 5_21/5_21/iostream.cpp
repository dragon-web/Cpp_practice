#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

#include "AboutOperator.h"

using namespace std;

int main()
{
	AboutOperator* q = new AboutOperator(10, 20, 30);
	AboutOperator* b = new  AboutOperator(10, 20, 30);
	AboutOperator c = (*q) + (*b);
	cout << c.getMoney() << endl;


	/*AboutOperator a =  AboutOperator(10, 20, 30);
	AboutOperator b =  AboutOperator(10, 20, 30);
	AboutOperator c = a + b;
	*/
	system("pause");
	return 0;
}

