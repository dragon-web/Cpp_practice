#include "AboutOperator.h"

#include <iostream>

using namespace std;


AboutOperator::AboutOperator(int spend, int money, int pocket)
{
	_spend = spend;
	_money = money;
	_pocket = pocket;
	ptr = nullptr;
	//}
	//AboutOperator AboutOperator::operator+(const AboutOperator &another)
	//{
	//	int r = this->_spend + another._spend;
	//	int q = this->_money + another._money;
	//	int p = this->_pocket + another._pocket;
	//	return AboutOperator(r, q, p);
	//	/*	AboutOperator sum;
	//		sum._spend = this->_spend + another._spend;
	//		sum._money = this->_money + another._money;
	//		sum._pocket = this->_pocket + another._pocket;
	//		return sum;
	//	*/
	//}
	//

}

/*
AboutOperator AboutOperator::operator+(const AboutOperator &another)
{
	int a = this->_month + another._month;
	int b = this->_money + another._money;
	int c = this->_pocket + another._pocket;
	return AboutOperator(a, b, c);
}
*/
/*
AboutOperator AboutOperator::operator+(const AboutOperator &another)
{
	AboutOperator sum =  AboutOperator(0,0,0);
	sum._spend = this->_spend + another._spend;
	sum._money = this->_money + another._money;
	sum._pocket = this->_pocket + another._pocket;
	return sum;
}
*/
AboutOperator AboutOperator::operator+(const AboutOperator &another)
{
	AboutOperator* sum = new AboutOperator(0, 0, 0);
	sum->_spend = this->_spend + another._spend;
	sum->_money = this->_money + another._money;
	sum->_pocket = this->_pocket + another._pocket;
	ptr = sum;
	return *sum;//ÄÚ´æÐ¹Â©
}
/*
AboutOperator AboutOperator::operator-(AboutOperator &another)
{

}

AboutOperator::~AboutOperator()
{
	cout << "Îö¹¹º¯Êý" << endl;
}
*/