#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return vector<int>();
		if (matrix[0].empty()) return vector<int>();
		int n = matrix.size();
		int m = matrix[0].size();
		if (n == 0 || m == 0) return vector<int>();
		int layer = 0;
		vector<int> v;
		while (layer <= n - 1 - layer && layer <= m - 1 - layer)
		{
			// Spiral print
			// right
			for (int i = layer, j = layer; j <= m - 1 - layer; ++j)
			{
				v.push_back(matrix[i][j]);
			}
			// down
			for (int j = m - 1 - layer, i = layer + 1; i <= n - 1 - layer; ++i)
			{
				v.push_back(matrix[i][j]);
			}
			// left
			if (layer != n - 1 - layer)
			{
				for (int i = n - 1 - layer, j = m - 2 - layer; j >= layer; --j)
				{
					v.push_back(matrix[i][j]);
				}
			}
			// up
			if (layer != m - 1 - layer)
			{
				for (int j = layer, i = n - 2 - layer; i >= layer + 1; --i)
				{
					v.push_back(matrix[i][j]);
				}
			}
			// next layer
			++layer;
		}
		return v;
	}
};

int main()
{
	vector<vector<int>> matrix =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	Solution sol;
	const auto& v = sol.spiralOrder(matrix);
}