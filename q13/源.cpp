#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<int>> visited(m, vector<int>(n));
		int total = 0;
		visit(0, 0, m, n, k, total, visited);
		return total;
	}
	void visit(int i, int j, int m, int n, int k, int& total, vector<vector<int>>& visited) {
		++total;
		visited[i][j] = 1;
		// left
		if (j > 0 && !visited[i][j - 1] && digitSum(i) + digitSum(j - 1) <= k)
			visit(i, j - 1, m, n, k, total, visited);
		// right
		if (j < n - 1 && !visited[i][j + 1] && digitSum(i) + digitSum(j + 1) <= k)
			visit(i, j + 1, m, n, k, total, visited);
		// up
		if (i > 0 && !visited[i - 1][j] && digitSum(i - 1) + digitSum(j) <= k)
			visit(i - 1, j, m, n, k, total, visited);
		// down
		if (i < m-1 && !visited[i + 1][j] && digitSum(i + 1) + digitSum(j) <= k)
			visit(i + 1, j, m, n, k, total, visited);
	}

	int digitSum(int x)
	{
		int sum = 0;
		while (x)
		{
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}
};

int main()
{
	int m = 3;
	int n = 2;
	int k = 17;
	Solution sol;
	int total = sol.movingCount(m, n, k);
}