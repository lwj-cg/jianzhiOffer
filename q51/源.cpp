#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void combine(vector<int>& nums, vector<int>::iterator begin_iter1, vector<int>::iterator end_iter1, 
        vector<int>::iterator begin_iter2, vector<int>::iterator end_iter2, int& total)
    {
        if (begin_iter1 >= end_iter1) return;
        if (begin_iter2 >= end_iter2) return;
        vector<int> v(begin_iter1, end_iter2);
        auto p1 = end_iter1-1;
        auto p2 = end_iter2-1;
        auto p3 = v.end()-1;
        while (p1 >= begin_iter1 && p2 >= begin_iter2)
        {
            if (*p1 > *p2)
            {
                total += p2 - begin_iter2 + 1;
                *(p3--) = *p1;
                if (p1 != nums.begin()) 
                    --p1;
                else break;
            }
            else
            {
                *(p3--) = *(p2--);
            }
        }
        if (p1 != nums.begin() && p1 >= begin_iter1)
        {
            while (p1 != nums.begin()&&p1>=begin_iter1) 
                *(p3--) = *(p1--);
        }
        else if (p2 >= begin_iter2)
        {
            while (p2 >= begin_iter2)
            {
                *(p3) = *(p2--);
                if (p3 != v.begin()) --p3;
            }
        }
        for (auto iter = begin_iter1, viter = v.begin(); iter < end_iter2; iter++,viter++)
        {
            *(iter) = *(viter);
        }
        return;
    }

    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        int total = 0;
        sortCore(nums, nums.begin(), nums.end(), total);
        return total;
    }

    void sortCore(vector<int>& nums, vector<int>::iterator begin_iter, vector<int>::iterator end_iter, int& total)
    {
        if (end_iter - begin_iter <= 1)
            return;
        else if (end_iter - begin_iter == 2)
            combine(nums, begin_iter, begin_iter + 1, begin_iter + 1, begin_iter + 2,total);
        else
        {
            int length = end_iter - begin_iter;
            sortCore(nums, begin_iter, begin_iter + length / 2, total);
            sortCore(nums, begin_iter + length / 2, end_iter, total);
            combine(nums, begin_iter, begin_iter + length / 2, begin_iter + length / 2, end_iter, total);
        }
    }
};

int main()
{
    vector<int> nums = { 7,5,6,4 };
    Solution sol;
    int total = sol.reversePairs(nums);
}