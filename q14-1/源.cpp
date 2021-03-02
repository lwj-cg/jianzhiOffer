#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int maxMul = 0;
            for (int j = 1; j <= i / 2; j++)
                maxMul = max(max(j,dp[j]) * max(i-j,dp[i - j]), maxMul);
            dp[i] = maxMul;
        }
        return dp[n];
    }
};

int main()
{
    int n = 2;
    Solution sol;
    int maxMul = sol.cuttingRope(n);
}