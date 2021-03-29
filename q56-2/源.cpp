#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bitSum[32] = {0};
		for (int i = 0; i < nums.size(); i++)
		{
			for (int bit = 0; bit < 32; bit++)
			{
				if (nums[i] & (0x1 << (31-bit)))
				{
					++bitSum[bit];
				}
			}
		}
		int singleNumber = 0x0;
		for (int bit = 0; bit < 32; bit++)
		{
			singleNumber <<= 1;
			singleNumber += (bitSum[bit] % 3) ;
		}
		return singleNumber;
	}
};

int main()
{
	vector<int> v = { -1,2,2,2,-1,-1,-3 };
	Solution sol;
	int singleNumber = sol.singleNumber(v);
}