#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        vector<int> dp(grid[0].size() + 1,0);
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <=m ; j++)
            {
                dp[j] = max(dp[j - 1] + grid[i - 1][j - 1], dp[j] + grid[i - 1][j - 1]);
            }
        }
        return dp[m];
    }
};

int main()
{
    vector<vector<int>> grid =
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution sol;
    int max = sol.maxValue(grid);
}