#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		// A[.[B]][e|E C] .B[e|E C]
		if (s.empty()) return false;
		auto iter = s.begin();
		scanSpace(s, iter);
		bool isNumeric = scanInt(s, iter);
		if (!isNumeric)
		{
			scanSpace(s, iter);
		}
		if (iter != s.end() && *iter == '.')
		{
			++iter;
			isNumeric = scanUint(s, iter) || isNumeric;
		}
		if (isNumeric && iter != s.end() && (*iter == 'e' || *iter == 'E'))
		{
			++iter;
			isNumeric = scanInt(s, iter) && isNumeric;
		}
		scanSpace(s, iter);
		return isNumeric && iter == s.end();
	}
	bool scanInt(const string& s, string::iterator& iter)
	{
		if (s.empty() || iter == s.end()) return false;
		if (*iter == '+' || *iter == '-') ++iter;
		return scanUint(s, iter);
	}
	bool scanUint(const string& s, string::iterator& iter)
	{
		if (s.empty() || iter == s.end()) return false;
		bool isNumeric = false;
		while (iter != s.end() && *iter >= '0' && *iter <= '9')
		{
			++iter;
			isNumeric = true;
		}
		return isNumeric;
	}
	bool scanSpace(const string& s, string::iterator& iter)
	{
		if (s.empty() || iter == s.end()) return true;
		while (iter != s.end())
		{
			if (*iter != ' ') return false;
			++iter;
		}
		return true;
	}
};

int main()
{
	string s = "+3. e04116";
	Solution sol;
	bool isNumber = sol.isNumber(s);
}