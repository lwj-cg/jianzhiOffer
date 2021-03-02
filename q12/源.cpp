#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty()) return false;
		if (board[0].empty()) return false;
		if (word.empty()) return false;
		int n = board.size();
		int m = board[0].size();
		int l = word.size();
		vector<vector<int>> visited(n, vector<int>(m));
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (board[i][j] == word[0])
				{
					if (findPath(board, visited, word, i, j, 0, n, m, l)) return true;
				}
			}
		}
		return false;
	}

	bool findPath(vector<vector<char>>& board, vector<vector<int>>& visited, const string& word,
		int i, int j, int depth, int n, int m, int l)
	{
		visited[i][j] = 1;
		if (depth == l - 1) return true;
		// left
		if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[depth + 1])
			if (findPath(board, visited, word, i, j - 1, depth + 1, n, m, l))
				return true;
		// right
		if (j < m - 1 && !visited[i][j + 1] && board[i][j + 1] == word[depth + 1])
			if (findPath(board, visited, word, i, j + 1, depth + 1, n, m, l))
				return true;
		// up
		if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[depth + 1])
			if (findPath(board, visited, word, i - 1, j, depth + 1, n, m, l))
				return true;
		// down
		if (i < n - 1 && !visited[i + 1][j] && board[i + 1][j] == word[depth + 1])
			if (findPath(board, visited, word, i + 1, j, depth + 1, n, m, l))
				return true;

		visited[i][j] = 0;
		return false;
	}
};

int main()
{
	vector<vector<char>> board = {
		{'a','b','t','g'},
		{'c','f','c','s'},
		{'j','d','e','h'}
	};
	string word = "abfb";
	Solution sol;
	bool is_exist = sol.exist(board, word);
}