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
		if (*iter != '.')
		{
			bool isEmpty = scanInt(s, iter);
			if (isEmpty)
			{
				scanSpace(s, iter);
				if (*iter == '.')
				{
					++iter;
					if (scanUint(s, iter)) return false;
					else if (iter == s.end()) return true;
					else if (*iter == 'e' || *iter == 'E')
					{
						++iter;
						if (scanInt(s, iter)) return false;
						if (iter == s.end()) return true;
						else if (scanSpace(s, iter)) return true;
						else return false;
					}
					else if (scanSpace(s, iter)) return true;
					else return false;
				}
				else return false;
			}
			else if (iter == s.end()) return true;
			else if (*iter == '.')
			{
				++iter;
				scanUint(s, iter);
				if (iter == s.end()) return true;
				else if (*iter == 'e' || *iter == 'E')
				{
					++iter;
					if (scanInt(s, iter)) return false;
					if (iter == s.end()) return true;
					else if (scanSpace(s, iter)) return true;
					else return false;
				}
				else if (scanSpace(s, iter)) return true;
				else return false;
			}
			else if (*iter == 'e' || *iter == 'E')
			{
				++iter;
				if (scanInt(s, iter)) return false;
				if (iter == s.end()) return true;
				else if (scanSpace(s, iter)) return true;
				else return false;
			}
			else if (scanSpace(s, iter)) return true;
			else return false;
		}
		else
		{
			++iter;
			if (scanUint(s, iter)) return false;
			else if (iter == s.end()) return true;
			else if (*iter == 'e' || *iter == 'E')
			{
				++iter;
				if (scanInt(s, iter)) return false;
				if (iter == s.end()) return true;
				else if (scanSpace(s, iter)) return true;
				else return false;
			}
			else if (scanSpace(s, iter)) return true;
			else return false;
		}
		return false;
	}
	bool scanInt(const string& s, string::iterator& iter)
	{
		if (s.empty() || iter == s.end()) return true;
		if (*iter == '+' || *iter == '-') ++iter;
		bool isEmpty = true;
		while (iter != s.end() && *iter >= '0' && *iter <= '9')
		{
			++iter;
			isEmpty = false;
		}
		return isEmpty;
	}
	bool scanUint(const string& s, string::iterator& iter)
	{
		if (s.empty() || iter == s.end()) return true;
		bool isEmpty = true;
		while (iter != s.end() && *iter >= '0' && *iter <= '9')
		{
			++iter;
			isEmpty = false;
		}
		return isEmpty;
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