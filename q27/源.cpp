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
    TreeNode* mirrorTree(TreeNode* root) {
        return mirrorTreeCore(root);
    }

    TreeNode* mirrorTreeCore(TreeNode* node)
    {
        if (!node) return nullptr;
        // ตÝน้
        TreeNode* tmpLeft = mirrorTreeCore(node->left);
        node->left = mirrorTreeCore(node->right);
        node->right = tmpLeft;
        return node;
    }
};