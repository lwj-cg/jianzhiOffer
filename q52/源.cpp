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

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (!headA || !headB) return nullptr;
		ListNode* nodeA = headA;
		ListNode* nodeB = headB;
		int lengthA = 0;
		int lengthB = 0;
		while (nodeA)
		{
			nodeA = nodeA->next;
			++lengthA;
		}
		while (nodeB)
		{
			nodeB = nodeB->next;
			++lengthB;
		}
		nodeA = headA;
		nodeB = headB;
		if (lengthA > lengthB)
		{
			int dl = lengthA - lengthB;
			while (dl--)
			{
				nodeA = nodeA->next;
			}
		}
		else if (lengthB > lengthA)
		{
			int dl = lengthB - lengthA;
			while (dl--)
			{
				nodeB = nodeB->next;
			}
		}
		while (nodeA&&nodeB&&nodeA!=nodeB)
		{
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
		return nodeA;
	}
};