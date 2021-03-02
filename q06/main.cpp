#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> reversePrint(ListNode* head) {
		if (!head) { return vector<int>(); }
		stack<int> myStack;
		while(head != nullptr)
		{
			myStack.push(head->val);
			head = head->next;
		}
		vector<int> v;
		while (!myStack.empty())
		{
			v.push_back(myStack.top());
			myStack.pop();
		}
		return v;
	}
};

int main()
{
	ListNode* myList = createList({ 1,2,3,4,5 });
	Solution sol;
	vector<int> v = sol.reversePrint(myList);
}