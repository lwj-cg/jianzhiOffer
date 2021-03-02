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
	for (int i = v.size()-1; i >=0; --i)
	{
		ListNode* curr = new ListNode(v[i]);
		curr->next = head->next;
		head->next = curr;
	}
	return head->next;
}

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head)
		{
			return nullptr;
		}
		if (head->next == nullptr)
		{
			return head;
		}
		ListNode* prev, * curr, * next;
		for (prev = head, curr = head->next; curr != nullptr; curr = next)
		{
			next = curr->next;
			if (prev == head) prev->next = nullptr;
			curr->next = prev;
			prev = curr;
		}
		return prev;
	}
};

int main()
{
	ListNode* myList = createList({1,2,3,4,5});
	Solution sol;
	ListNode* reverseList = sol.reverseList(myList);
}