#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // ����n�ҵ�i
        if (n < 10) return n;
        int64_t count = 0;
        int length = 1;  // i��λ��
        int64_t base = 9;  // pλ��������,����λ������Ϊ90(10~99) 
        while (count+length*base <= n)
        {
            count += length * base;
            ++length;
            base *= 10;
        }
        n -= count;
        int i = (n-1) / length + pow(10, length-1);
        int digit = (n-1) % length;
        int val = getDigitFromNum(i, digit, length);
        return val;
    }
    int getDigitFromNum(int num, int digit, int length)
    {
        int val = 0;
        for (int i = 0; i < length-digit; i++)
        {
            val = num % 10;
            num /= 10;
        }
        return val;
    }
};

int main()
{
    int n = 18;
    Solution sol;
    int val = sol.findNthDigit(n);
}