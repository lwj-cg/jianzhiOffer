#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        reverse(s.begin(), s.end());
        auto begin = s.begin();
        auto end = s.begin();
        string ret = "";
        while (end != s.end())
        {
            while (end!=s.end()&&*begin == ' ')
            {
                ++begin;
                ++end;
            }
            while (end != s.end() && *end != ' ')
            {
                ++end;
            }
            if (begin < end)
            {
                reverse(begin, end);
                ret += string(begin, end) + " ";
                begin = end;
            }
        }
        if (!ret.empty())
            ret.pop_back();
        return ret;
    }

    void reverse(string::iterator begin, string::iterator end)
    {
        while (begin < end-1)
        {
            std::swap(*begin, *(end-1));
            ++begin;
            --end;
        }
    }
};

int main()
{
    string s = " ";
    Solution sol;
    auto res = sol.reverseWords(s);
}