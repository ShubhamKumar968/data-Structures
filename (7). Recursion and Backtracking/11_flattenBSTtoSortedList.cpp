#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
//Method-01: Brute force {TC=SC=O(n)}

    // Helper function to perform in-order and store nodes
    void storeInorder(Node* root, vector<Node*>& nodes) {
        if (!root) return;
        
        storeInorder(root->left, nodes);
        nodes.push_back(root);
        storeInorder(root->right, nodes);
    }

    Node* flattenBST(Node* root) {
        if (!root) return nullptr;

        // 1. Get all nodes in sorted order
        vector<Node*> nodes;
        storeInorder(root, nodes);

        // 2. Start with the first element as our 'current' head
        Node* head = nodes[0];
        Node* curr = head;

        // 3. Iterate and re-link
        for (int i = 1; i < nodes.size(); i++) {
            // As per your requirement: Left is NULL, Right is the next node
            curr->left = nullptr;
            curr->right = nodes[i];
            
            // Move current to the next node in the sequence
            curr = nodes[i];
        }

        // 4. Important: Terminate the last node
        curr->left = nullptr;
        curr->right = nullptr;

        return head;
    }

//Method-01: Optimal   {TC=O(N); SC=O(height of recursion only)}
    Node* prev = nullptr; 
    Node* flattenBST(Node* root) {
        
        if (!root) return nullptr;

        // 1. Recurse to the leftmost node (this will be our new head)
        Node* head = flattenBST(root->left);

        // 2. Process Current Node
        if (prev != nullptr) {
            prev->right = root;
        }
        root->left = nullptr; // Essential: Break the left link
        prev = root;          // Update prev to current

        // 3. Recurse to the right
        flattenBST(root->right);

        // Logic: If 'head' is null, it means there was no left subtree, 
        // so 'root' itself is the smallest element (the head).
        return (head != nullptr) ? head : root;
    }
    
};
