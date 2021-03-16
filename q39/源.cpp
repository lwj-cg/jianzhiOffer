#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int num = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                ++num;
            }
            else
            {
                --num;
                if (num == 0) {
                    val = nums[i];
                    num = 1;
                }
            }
        }
        return val;
    }
};

int main()
{
    std::vector<int> v = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    Solution sol;
    int x = sol.majorityElement(v);
}