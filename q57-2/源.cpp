#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> allSequences;
        int small = 1;
        int big = 1;
        int sum = 1;
        while (small <= target / 2)
        {
            if (sum < target)
            {
                ++big;
                sum += big;
            }
            else if (sum > target&&small<=big)
            {
                sum -= small;
                ++small;
            }
            else
            {
                allSequences.push_back(vectorBetweenSmallAndBig(small,big));
                ++big;
                sum += big;
            }
        }
        return allSequences;
    }

    vector<int> vectorBetweenSmallAndBig(int small, int big)
    {
        vector<int> v;
        for (int i = small; i <= big; i++)
        {
            v.push_back(i);
        }
        return v;
    }
};

int main()
{
    int target = 4;
    Solution sol;
    auto result = sol.findContinuousSequence(target);
}