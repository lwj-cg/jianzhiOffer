#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(std::vector<int> v)
{
	if (v.empty()) return nullptr;
	ListNode* head = new ListNode(0);
	for (int i = v.size() - 1; i >= 0; --i)
	{
		ListNode* curr = new ListNode(v[i]);
		curr->next = head->next;
		head->next = curr;
	}
	return head->next;
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* ln = new ListNode(0);
		ListNode* pn = ln;
		while (p1 && p2)
		{
			if (p1->val <= p2->val)
			{
				ListNode* next = p1->next;
				p1->next = p2;
				pn->next = p1;
				pn = pn->next;
				p1 = next;
			}
			else
			{
				ListNode* next = p2->next;
				p2->next = p1;
				pn->next = p2;
				pn = pn->next;
				p2 = next;
			}
		}
		if (p1)
		{
			pn->next = p1;
		}
		else if (p2)
		{
			pn->next = p2;
		}
		return ln->next;
	}
};

int main()
{
	ListNode* l1 = createList({ 1,2,4 });
	ListNode* l2 = createList({ 1,3,4 });
	Solution sol;
	ListNode* ln = sol.mergeTwoLists(l1, l2);

}