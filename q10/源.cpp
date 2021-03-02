#include<iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
		if (n==0)
		{
			return 0;
		}
		if (n==1)
		{
			return 1;
		}
		int fibs[2] = { 0,1 };
		int fibVal = 0;
		for (size_t i = 2; i <= n; i++)
		{
			fibVal = fibs[0] + fibs[1];
			fibs[0] = fibs[1];
			fibs[1] = fibVal % (1000000007);
		}
		return fibVal % (1000000007);
    }
};

int main()
{
	Solution sol;
	int fibVal = sol.fib(45);
}