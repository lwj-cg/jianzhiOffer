#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (dp[i - 1] > 0) dp[i] = dp[i - 1] + nums[i];
			else dp[i] = nums[i];
		}
		int max = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			max = std::max(max, dp[i]);
		}
		return max;
	}
};

int main()
{
	vector<int> v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution sol;
	int mx = sol.maxSubArray(v);
}