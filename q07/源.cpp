#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* recursiveBuildTree(vector<int>& preorder, vector<int>& inorder, int begin, int end, int beginOfPreOrder)
	{
		if (begin == end) return nullptr;
		if (end == begin + 1) return new TreeNode(inorder[begin]);
		int rootVal = preorder[beginOfPreOrder];
		int rootIdx = begin;
		for (int i = begin; i < end; i++)
		{
			if (inorder[i] == rootVal) rootIdx = i;
		}
		TreeNode* root = new TreeNode(rootVal);
		int leftTreeLength = rootIdx - begin;
		int rightTreeLength = end - rootIdx - 1;
		root->left = recursiveBuildTree(preorder, inorder, begin, rootIdx, beginOfPreOrder + 1);
		root->right = recursiveBuildTree(preorder, inorder, rootIdx + 1, end, beginOfPreOrder + leftTreeLength + 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return nullptr;
		if (preorder.size() == 1) return new TreeNode(preorder[0]);
		return recursiveBuildTree(preorder, inorder, 0, inorder.size(), 0);
	}
};

int main()
{
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	Solution sol;
	TreeNode* myTree = sol.buildTree(preorder, inorder);
}