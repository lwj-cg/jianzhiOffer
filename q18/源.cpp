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
	ListNode* deleteNode(ListNode* head, int val) {
		if (!head) return head;
		ListNode* prev = head;
		ListNode* curr = head;
		while (curr->val != val && curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr->val == val)
		{
			//delete
			if (curr == head)
			{
				auto tmp = head;
				head = head->next;
				delete tmp;
			}
			else
			{
				prev->next = curr->next;
				delete curr;
			}
		}
		return head;
	}
};

int main()
{
	ListNode* myList = createList({-3,5,-99});
	int val = -3;
	Solution sol;
	auto head = sol.deleteNode(myList,val);
}