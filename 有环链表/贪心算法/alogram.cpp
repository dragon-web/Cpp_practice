#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
//»·ÐÎÁ´±í

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)  return false;
		ListNode *fast = head->next;
		ListNode *slow = head;
		while (fast != slow) {
			if (fast->next == NULL || fast->next->next == NULL)
				return false;
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
	}
};
int main()
{
	ListNode mylist(3);
	ListNode mylist1(5);
	ListNode mylist2(5);
	mylist.next =&mylist1;
	mylist1.next = &mylist2;
	mylist2.next = &mylist1;
	Solution a;
	cout << a.hasCycle(&mylist) << endl;



	system("pause");
	return 0;
}