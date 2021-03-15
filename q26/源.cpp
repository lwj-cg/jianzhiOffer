#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return false;
        return isSubStructureCore(A, B);
    }

    bool isSubStructureCore(TreeNode* subA, TreeNode* B)
    {
        bool flag = false;
        if (!subA) return false;
        if (subA->val == B->val)
        {
            flag = isSame(subA,B);
        }
        if (flag) return true;
        else
        {
            return isSubStructureCore(subA->left, B) || isSubStructureCore(subA->right, B);
        }
    }

    bool isSame(TreeNode* subA, TreeNode* B)
    {
        if (!B) return true;
        if (!subA || subA->val != B->val) return false;
        return isSame(subA->left, B->left) && isSame(subA->right, B->right);
    }
};