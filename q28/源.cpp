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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        else if (!root->left) return false;
        else if (!root->right) return false;
        return isSymmtricCore(root->left, root->right);
    }

    bool isSymmtricCore(TreeNode* leftNode, TreeNode* rightNode)
    {
        if (!leftNode && !rightNode) return true;
        else if (!leftNode) return false;
        else if (!rightNode) return false;
        if (leftNode->val != rightNode->val) return false;
        return isSymmtricCore(leftNode->left, rightNode->right) && isSymmtricCore(leftNode->right, rightNode->left);
    }
};