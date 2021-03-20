#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int index = -1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] - mid == 1)
            {
                if (mid > 0)
                {
                    if (mid - 1 == nums[mid - 1])
                    {
                        index = mid;
                        break;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
                else
                {
                    index = 0;
                    break;
                }
            }
            else begin = mid + 1;
        }
        if (begin <= end)
            return index;
        else
            return nums.size();
    }
};

int main()
{
    vector<int> v = { 0,1,3 };
    Solution sol;
    int index = sol.missingNumber(v);
}