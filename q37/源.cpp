#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serialize(root, str);
        string noEndStr = string(str.begin(), str.end() - 1);
        return noEndStr;
    }

    void serialize(TreeNode* node, string& str)
    {
        if (!node)
        {
            str += "null,";
            return;
        }
        str += std::to_string(node->val);
        str += ",";
        serialize(node->left, str);
        serialize(node->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        std::string::iterator iter = data.begin();
        return deserializeCore(data, iter);
    }

    TreeNode* deserializeCore(const string& str, string::iterator& iter)
    {
        if (iter < str.end())
        {
            string::iterator segment_end = iter;
            while (segment_end < str.end() && *segment_end != ',')
                ++segment_end;
            string segment = string(iter, segment_end);
            if (segment_end < str.end())
                iter = segment_end + 1;
            else
                iter = segment_end;
            if (segment != "null")
            {
                TreeNode* node = new TreeNode(stoi(segment));
                node->left = deserializeCore(str, iter);
                node->right = deserializeCore(str, iter);
                return node;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    std::string str = "1,2,4,null,null,null,3,5,null,null,6,null,null";
    Codec codec;
    TreeNode* root = codec.deserialize(str);
}