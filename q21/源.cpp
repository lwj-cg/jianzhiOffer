#include<iostream>
#include<vector>
#include<functional>
using namespace std;

bool myCondition(int x)
{
	// if odd return true
	if (x & 0x1) return true;
	else return false;
}

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
		auto condition = [](int x)->bool {
			if (x & 0x1) return true;
			else return false;
		};
		return exchange(nums, condition);
    }
	vector<int> exchange(vector<int>& nums, function<bool(int)> condition) {
	//vector<int> exchange(vector<int>& nums, bool (*condition)(int)) {
		if (nums.empty()) return nums;
		size_t i = 0;
		size_t j = nums.size();
		while (i < j)
		{
			if (condition(nums[i])) ++i;
			else
			{
				--j;
				swap(nums[i], nums[j]);
			}
		}
		return nums;
	}
	void swap(int& x, int& y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
};

int main()
{
	vector<int> nums = { 1,11,14 };
	Solution sol;
	nums = sol.exchange(nums);
}