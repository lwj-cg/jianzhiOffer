#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> v;
        unordered_set<string> set;
        permutationCore(s, v, set);
        return v;
    }

    void permutationCore(string s, vector<string>& v, unordered_set<string>& set)
    {
        if (!s.empty())
        {
            if (s.size() == 1)
            {
                v = { s };
                return;
            }
            else
            {
                string ch = string(s.begin(), s.begin() + 1);
                string left_str = string(s.begin() + 1, s.end());
                vector<string> tmp_v;
                permutationCore(left_str, tmp_v, set);
                for (int i = 0; i < s.size(); i++)
                {
                    for (auto& ss : tmp_v)
                    {
                        string tmp_s = ch + ss;
                        std::swap(tmp_s[0], tmp_s[i]);
                        if (set.find(tmp_s) == set.end())
                        {
                            v.push_back(tmp_s);
                            set.insert(tmp_s);
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    string test = "aab";
    Solution sol;
    vector<string> v = sol.permutation(test);
}