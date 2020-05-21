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
	char _month; // �·�
	int _spend; // ����
	int _money; // ����
	int _pocket; // �����
	AboutOperator* ptr;
};
