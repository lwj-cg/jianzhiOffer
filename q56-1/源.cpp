#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        if (nums.size() == 1) return nums;
        int xorSum = 0x0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorSum ^= nums[i];
        }
        uint32_t tmp = 0x1;
        int condition = 0x1;
        while (tmp)
        {
            if (tmp & xorSum)
                condition = tmp;
            tmp <<= 1;
        }
        int idx;
        int single1 = 0x0;
        int single2 = 0x0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(condition&nums[i])
                single1 ^= nums[i];
            else 
                single2 ^= nums[i];
        }
        return { single1, single2 };
    }


};

int main()
{
    vector<int> v = {6,2,3,3};
    Solution sol;
    auto singles = sol.singleNumbers(v);
}