#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dp(s.size());
        string subStr = "";
        for (int i = 0; i < s.size(); i++)
        {
            updateString(s[i],subStr);
            dp[i] = subStr.size();
        }
        int maxVal = 0;
        for (int i = 0; i < s.size(); i++)
        {
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
    void updateString(char ch, string& subStr)
    {
        if (subStr.empty())
        {
            subStr.push_back(ch);
        }
        auto iter = subStr.begin();
        for (; iter != subStr.end(); ++iter)
        {
            if (*iter == ch) break;
        }
        if (iter < subStr.end()-1)
        {
            subStr = string(iter+1, subStr.end());
        }
        else if (iter == subStr.end() - 1)
        {
            subStr = "";
        }
        subStr.push_back(ch);
    }
};

int main()
{
    string str = "abcabcbb";
    Solution sol;
    int maxLength = sol.lengthOfLongestSubstring(str);
}