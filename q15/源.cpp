#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t x = 1;
        int c = 0;
        while (x)
        {
            if (n & x) ++c;
            x <<= 1;
        }
        return c;
    }
};

int main()
{
    uint32_t n = 0b1011;
    Solution sol;
    int c = sol.hammingWeight(n);
}