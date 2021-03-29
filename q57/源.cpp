#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		set<int> mySet;
		int j = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			while ((i<=j)&&(nums[i] + nums[j-1] > target))
			{
				--j;
			}
			if (nums[i] + nums[j - 1] == target)
			{
				return { nums[i],nums[j - 1] };
			}
		}
		return {};
    }
};

