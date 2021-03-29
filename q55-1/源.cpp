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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            ++depth;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }
};