#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        uint32_t un = (uint32_t)n;
        if (n < 0)
        {
            int64_t n64 = (int64_t)n;
            un = (uint32_t)-n64;
            return 1 / myPowWithUint(x, un);
        }
        else
        {
            return myPowWithUint(x, un);
        }
    }
    double myPowWithUint(double x, uint32_t n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double halfResult = myPowWithUint(x, n >> 1);
        if (n & 1)
            return x * halfResult * halfResult;
        else
            return halfResult * halfResult;
    }
};

int main()
{
    double x = 2.1;
    int n = 3;
    Solution sol;
    sol.myPow(x, n);
}