#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 3;
        if (n == 4) return 4;
        if (n == 5) return 5;
        vector<int64_t> uglyNumber(n);
        uglyNumber[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int m2;
            int m3;
            int m5;
            for (int j = i-1; j >= 0; j--)
            {
                if (2 * uglyNumber[j] <= uglyNumber[i - 1])
                {
                    break;
                }
                m2 = 2 * uglyNumber[j];
            }
            for (int j = i - 1; j >= 0; j--)
            {
                if (3 * uglyNumber[j] <= uglyNumber[i - 1])
                {
                    break;
                }
                m3 = 3 * uglyNumber[j];
            }
            for (int j = i - 1; j >= 0; j--)
            {
                if (5 * uglyNumber[j] <= uglyNumber[i - 1])
                {
                    break;
                }
                m5 = 5 * uglyNumber[j];
            }
            uglyNumber[i] = min(min(m2, m3), m5);
        }
        return (int)uglyNumber[n - 1];
    }
};

int main()
{
    int n = 10;
    Solution sol;
    int uglyNumber = sol.nthUglyNumber(n);
}

