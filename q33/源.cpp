#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        return verifyPostorderCore(postorder, 0, postorder.size());
    }

    bool verifyPostorderCore(vector<int>& postorder, int subTreeBegin, int subTreeEnd) {
        if (subTreeBegin == subTreeEnd - 1) return true;
        int root = postorder[subTreeEnd - 1];
        // find range of leftTree
        int leftTreeBegin = subTreeBegin;
        int leftTreeEnd = subTreeBegin;
        while (leftTreeEnd < subTreeEnd && postorder[leftTreeEnd] < root)
        {
            ++leftTreeEnd;
        }
        int rightTreeBegin = leftTreeEnd;
        int rightTreeEnd = subTreeEnd - 1;
        for (int i = rightTreeBegin; i < rightTreeEnd; i++)
        {
            if (postorder[i] < root) return false;
        }
        bool flag = true;
        if (leftTreeEnd > leftTreeBegin)
            flag &= verifyPostorderCore(postorder, leftTreeBegin, leftTreeEnd);
        if (rightTreeEnd > rightTreeBegin)
            flag &= verifyPostorderCore(postorder, rightTreeBegin, rightTreeEnd);
        return flag;
    }
};

int main()
{
    vector<int> postorder = {4, 8, 6, 12, 16, 14, 10};
    Solution sol;
    bool isValis = sol.verifyPostorder(postorder);
}