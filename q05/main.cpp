#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.empty()) return string();
        int nBlanks = 0;
        for (auto b = s.begin(); b != s.end(); ++b)
        {
            if (*b == ' ') ++nBlanks;
        }
        string new_s(s.size() + 2 * nBlanks,' ');
        auto p1 = s.end();
        auto p2 = new_s.end();
        while (p1 != s.begin() && p2 != new_s.begin())
        {
            if (*(--p1) != ' ') *(--p2) = *p1;
            else
            {
                *(--p2) = '0';
                *(--p2) = '2';
                *(--p2) = '%';
            }
        }
        return new_s;
    }
};

int main()
{
    string s = "We are happy.";
    Solution sol;
    string new_s = sol.replaceSpace(s);
    //cout << new_s << endl;
}