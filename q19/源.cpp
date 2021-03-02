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
        // ���������ʣ�࣬ģʽ���ˣ���ô�ض����� false
        // ����֮��һ������Ϊģʽ��������� a* �����Ĳ���Ҫƥ���ַ�
        if (str_loc < n && p_loc == m) {
            return false;
        }

        bool flag = false;
        char pattern_ch = pattern[p_loc]; // ģʽ�϶�����ʣ��
        // �� * �����
        if (p_loc < m - 1 && pattern[p_loc + 1] == '*') {
            // ����ֱ������ pattern ���������ַ�
            flag = backtrack(str, pattern, str_loc, p_loc + 2);
            if (!flag && str_loc < n && (str[str_loc] == pattern_ch || pattern_ch == '.')) { // �������ֱ����������ô����ƥ��
                flag = backtrack(str, pattern, str_loc + 1, p_loc);
            }
        }
        else { // û�� * �������ֻ��Ҫ����ǰλ�õ��ַ��Ƿ����
            if (str_loc < n) {
                // �����������´�û��ʣ�࣬ģʽ��ʣ�࣬�Ǿ��Ǵ����
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