#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        if (str.size() == 1) return 1;
        vector<int> dp(str.size()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        auto iter = str.begin();
        for (int i = 1; i < str.size(); ++i,++iter)
        {
            string clip = string(iter, iter + 2);
            if (stoi(clip) < 26 && stoi(clip)>9)
            {
                dp[i + 1] = dp[i] + dp[i - 1];
            }
            else
            {
                dp[i + 1] = dp[i];
            }
        }
        return dp[str.size()];
    }
};

int main()
{
    int num = 12258;
    Solution sol;
    int total = sol.translateNum(num);
}

