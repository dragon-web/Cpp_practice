#define _CRT_SECURE_NO_WARNINGS 
//ż��������ż��λ�ϣ���������������λ��

/*void oddInOddEvenInEven(vector<int>& arr, int len) {
	sort(arr.begin(),arr.end());
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (i % 2 == 0)
		{
			if (arr[i] % 2 != 0)
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}
class Solution {
public:
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		while (i < len && j < len) {
			//ż��λ��Ѱ�ҷ�ż��
			if ((arr[i] % 2) == 0) {
				i += 2;
				continue;
			}
			//����λ��Ѱ�ҷ�����
			if ((arr[j] % 2) != 0) {
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);
		}
	}
};
int main()
{
	Solution a;
	int arr[] = { 7,7,2,1,5,6,8,9};
	vector<int> dp(arr, arr + 8);
	a.oddInOddEvenInEven(dp, dp.size());
	vector<int>::iterator it = dp.begin();
	while (it != dp.end())
	{
		cout << *it;
		++it;
	}
	system("pause");
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

	system("pause");
	return 0;
}
*/