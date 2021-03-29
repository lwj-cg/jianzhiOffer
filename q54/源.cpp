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
    int kthLargest(TreeNode* root, int k) {
        int val = -1;
        reverseMidorderTraversal(root, k, val);
        return val;
    }

    bool reverseMidorderTraversal(TreeNode* node, int& k, int& val)
    {
        bool isFind = false;
        if (!node) return false;
        isFind = reverseMidorderTraversal(node->right, k, val);
        if (--k == 0)
        {
            val = node->val;
            return true;
        }
        isFind = reverseMidorderTraversal(node->left, k, val) | isFind;
        return isFind;
    }
};