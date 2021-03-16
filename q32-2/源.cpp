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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        std::queue<TreeNode*> q;
        vector<vector<int>> v;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp_v;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                tmp_v.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            v.push_back(tmp_v);
        }
        return v;
    }
};