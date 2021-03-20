#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int begin = 0;
        int end = nums.size() - 1;
        int leftBorder = -1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] == target)
            {
                if (mid > 0)
                {
                    if (nums[mid - 1] < target)
                    {
                        leftBorder = mid;
                        break;
                    }
                    else end = mid - 1;
                }
                else
                {
                    leftBorder = 0;
                    break;
                }
            }
            else if (nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        int rightBorder = -1;
        begin = 0;
        end = nums.size() - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] == target)
            {
                if (mid < nums.size()-1)
                {
                    if (nums[mid + 1] > target)
                    {
                        rightBorder = mid;
                        break;
                    }
                    else begin = mid + 1;
                }
                else
                {
                    rightBorder = nums.size()-1;
                    break;
                }
            }
            else if (nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        if (begin<=end)
            return rightBorder - leftBorder + 1;
        else return 0;
    }
};

int main()
{
    vector<int> v = { 5,7,7,8,8,10 };
    int target = 6;
    Solution sol;
    int num = sol.search(v, target);
}