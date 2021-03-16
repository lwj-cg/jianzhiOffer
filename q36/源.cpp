#include<iostream>
#include<vector>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node* headToDoublyList = nullptr;
        Node* beginNode = nullptr;
        Node* endNode = nullptr;
        treeToDoublyListCore(root, &beginNode, &endNode, &headToDoublyList);
        endNode->right = beginNode;
        beginNode->left = endNode;
        return headToDoublyList->right;
    }
    void treeToDoublyListCore(Node* node, Node** beginNode, Node** endNode, Node** pHeadToDoublyList)
    {
        if (!node)
        {
            return;
        }
        if (!node->left && !(*pHeadToDoublyList))
        {
            *pHeadToDoublyList = new Node(0);
            (*pHeadToDoublyList)->right = node;
        }
        Node* leftBeginNode = nullptr;
        Node* leftEndNode = nullptr;
        Node* rightBeginNode = nullptr;
        Node* rightEndNode = nullptr;
        if (node->left)
        {
            treeToDoublyListCore(node->left, &leftBeginNode, &leftEndNode, pHeadToDoublyList);
            leftEndNode->right = node;
            node->left = leftEndNode;
        }
        else
        {
            leftBeginNode = node;
        }
        if (node->right)
        {
            treeToDoublyListCore(node->right, &rightBeginNode, &rightEndNode, pHeadToDoublyList);
            node->right = rightBeginNode;
            rightBeginNode->left = node;
        }
        else
        {
            rightEndNode = node;
        }
        *beginNode = leftBeginNode;
        *endNode = rightEndNode;
    }
};

int main()
{
    Node* root = new Node(4);
    {
        Node* left = new Node(2);
        left->left = new Node(1);
        left->right = new Node(3);
        root->left = left;

    }
    {
        Node* right = new Node(5);
        root->right = right;
    }

    Solution sol;
    Node* pHead = sol.treeToDoublyList(root);
}