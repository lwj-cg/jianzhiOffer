#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size()==0)
        {
            throw new std::exception("Invalid input");
        }
        int start = 0;
        int end = numbers.size() - 1;
        while (1)
        {
            while (numbers[start] == numbers[end]&&start<end)
                ++start;
            if (start == end) break;
            if (numbers[start]<numbers[end])
            {
                break;
            }
            int mid = (start + end) / 2;
            if (numbers[mid] >= numbers[start])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return numbers[start];
    }
};

int main()
{
    Solution sol;
    vector<int> rotArray = {  };
    int min = sol.minArray(rotArray);
}