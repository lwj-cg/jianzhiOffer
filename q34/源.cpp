#include<iostream>
#include<vector>
#include<unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> nodeMap;
        Node* copyHead = createMainLink(head, nodeMap);
        copyHead = addSiblingLink(head, copyHead, nodeMap);
        return copyHead;
    }
    Node* createMainLink(Node* node, std::unordered_map<Node*, Node*>& nodeMap)
    {
        if (!node) return nullptr;       
        Node* copyNode = new Node(node->val);
        copyNode->next = createMainLink(node->next, nodeMap);
        nodeMap[node] = copyNode;
        return copyNode;
    }

    Node* addSiblingLink(Node* head, Node* copyHead, std::unordered_map<Node*, Node*>& nodeMap)
    {
        Node* node = head;
        Node* copyNode = copyHead;
        while (node)
        {
            if (node->random)
            {
                copyNode->random = nodeMap[node->random];
            }
            node = node->next;
            copyNode = copyNode->next;
        }
        return copyHead;
    }
};