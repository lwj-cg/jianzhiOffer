#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int begin = 0;
        int end = arr.size() - 1;
        int kthPositive = -1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (arr[mid] - mid - 1 >= k)
            {
                if (mid > 0)
                {
                    if (arr[mid - 1] - mid < k)
                    {
                        kthPositive = k+mid;
                        break;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
                else
                {
                    kthPositive = k + mid;
                    break;
                }
            }
            else
            {
                begin = mid + 1;
            }
        }
        if (begin <= end)
            return kthPositive;
        else
        {
            end = arr.size() - 1;
            return k+end+1;
        }
    }
};

int main()
{
    vector<int> v = { 3, 7, 11, 12, 21, 29, 34, 35, 36, 37, 40, 45, 50, 59, 77, 78 };
    int k = 2;
    Solution sol;
    int num = sol.findKthPositive(v, k);
}