#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		if (!head) return nullptr;
		ListNode* p1 = head;
		ListNode* p2 = head;
		int dist = 0;
		while (p1)
		{
			p1 = p1->next;
			++dist;
			if (p2&&dist > k)
			{
				p2 = p2->next;
			}
		}
		return p2;
    }
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

int main()
{
	ListNode* myList = createList({1,2,3,4,5,6});
	Solution sol;
	ListNode* ele = sol.getKthFromEnd(myList,3);
}