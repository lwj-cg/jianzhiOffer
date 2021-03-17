#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        vector<int> vNum = toVector(n);
        int sum = 0;
        for (int digit = 0; digit < vNum.size(); digit++)
        {
            // fix current digit to 1
            for (int mostLargestDigit = vNum.size()-1; mostLargestDigit > digit; --mostLargestDigit)
            {
                sum += vNum[mostLargestDigit] * pow(10, mostLargestDigit - 1);
            }
            if (1 < vNum[digit])
            {
                sum += pow(10, digit);
            }
            else if (1 == vNum[digit])
            {
                for (int mostLargestDigit = digit-1; mostLargestDigit >= 0; --mostLargestDigit)
                {
                    sum += vNum[mostLargestDigit] * pow(10, mostLargestDigit);
                }
                sum += 1;
            }
        }
        return sum;
    }

    vector<int> toVector(int n)
    {
        vector<int> v;
        while (n)
        {
            v.push_back(n % 10);
            n /= 10;
        }
        return v;
    }
};

int main()
{
    int n = 11;
    Solution sol;
    int numOfOne = sol.countDigitOne(n);
}