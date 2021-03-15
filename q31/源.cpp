#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.empty() && popped.empty()) return true;
		if (pushed.empty()) return false;
		if (popped.empty()) return false;
		if (pushed.size() != popped.size()) return false;
		stack<int> s;
		int n = pushed.size();
		bool isValid = false;
		int pPush = 0;
		int pPop = 0;
		while (pPop < n)
		{
			while (s.empty() || s.top() != popped[pPop])
			{
				if (pPush < n)
				{
					s.push(pushed[pPush++]);
				}
				else
				{
					return false;
				}
			}
			s.pop();
			if(++pPop>n-1) isValid = true;
		}
		return isValid;
	}
};

int main()
{
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,5,3,2,1 };
	Solution sol;
	bool isValid = sol.validateStackSequences(pushed, popped);
}