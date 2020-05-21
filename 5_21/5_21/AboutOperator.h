#pragma once


class AboutOperator
{
public:
	//AboutOperator();
	AboutOperator(int spend, int money, int pocket);

	int getSpend() { return _spend; }
	int setSpend(int val) { _spend = val; }
	int getMoney() { return _money; }
	int setMoney(int val) { _money = val; }
	~AboutOperator()
	{
		if (ptr != nullptr)
			delete ptr;
	}

	AboutOperator operator+( const AboutOperator &another);
	AboutOperator operator-( const AboutOperator &another);

private:
	char _month; // 月份
	int _spend; // 花销
	int _money; // 工资
	int _pocket; // 月余额
	AboutOperator* ptr;
};
