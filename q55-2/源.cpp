#include<iostream>
#include<vector>
#include<queue>
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
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        isBalancedCore(root, isBalanced, 0);
        return isBalanced;
    }

    int isBalancedCore(TreeNode* node, bool& isBalanced, int currDepth)
    {
        if (!isBalanced) return -1;
        if (!node) return currDepth;
        int depth = currDepth + 1;
        int leftDepth = isBalancedCore(node->left, isBalanced, depth);
        int rightDepth = isBalancedCore(node->right, isBalanced, depth);
        if (leftDepth > rightDepth + 1 || rightDepth > leftDepth + 1) isBalanced = false;
        return max(leftDepth, rightDepth);
    }
};