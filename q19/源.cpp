#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int n, m;
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        return isMatchCore(s, p, 0, 0);
    }

    bool isMatchCore(const string& s, const string& p, const int& pString, const int& pPattern)
    {
        if (pString == n && pPattern == m) return true;
        if (pPattern == m) return false;
        bool flag = false;
        auto& string_ch = s[pString];
        auto& pattern_ch = p[pPattern];
        if (pPattern < m - 1 && p[pPattern + 1] == '*')
        {
            flag = isMatchCore(s, p, pString, pPattern + 2);
            if (!flag&&pString < n&&(string_ch == pattern_ch || pattern_ch == '.'))
            {
                flag = isMatchCore(s, p, pString + 1, pPattern);
            }
        }
        else
        {
            if (pString < n&&(string_ch == pattern_ch || pattern_ch == '.'))
            {
                flag = isMatchCore(s, p, pString + 1, pPattern + 1);
            }
        }
        return flag;
    }
};

class Solution2 {
public:
    int n, m;
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        return backtrack(s, p, 0, 0);
    }

    bool backtrack(string& str, string& pattern, int str_loc, int p_loc) {
        if (str_loc == n && p_loc == m) {
            return true;
        }
        // 如果串还有剩余，模式空了，那么必定返回 false
        // 但反之不一定，因为模式后面可能是 a* 这样的不需要匹配字符
        if (str_loc < n && p_loc == m) {
            return false;
        }

        bool flag = false;
        char pattern_ch = pattern[p_loc]; // 模式肯定还有剩余
        // 有 * 的情况
        if (p_loc < m - 1 && pattern[p_loc + 1] == '*') {
            // 可以直接跳过 pattern 中这两个字符
            flag = backtrack(str, pattern, str_loc, p_loc + 2);
            if (!flag && str_loc < n && (str[str_loc] == pattern_ch || pattern_ch == '.')) { // 如果不能直接跳过，那么进行匹配
                flag = backtrack(str, pattern, str_loc + 1, p_loc);
            }
        }
        else { // 没有 * 的情况，只需要看当前位置的字符是否相等
            if (str_loc < n) {
                // 如果这种情况下串没有剩余，模式有剩余，那就是错误的
                char str_ch = str[str_loc];
                char pattern_ch = pattern[p_loc];
                if (str_ch == pattern_ch || pattern_ch == '.') {
                    flag = backtrack(str, pattern, str_loc + 1, p_loc + 1);
                }
            }
        }
        return flag;
    }
};

int main()
{
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    Solution sol;
    bool isMatch = sol.isMatch(s, p);
}