#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    
    void convertToDLL(Node* root, Node* &prev, Node* &head) {
        if (root == nullptr) return;

        // Step 1: Recurse completely into the Left Subtree
        convertToDLL(root->left, prev, head);

        // Step 2: Process the current Root Node
        if (prev == nullptr) {
            // If prev is null, we have reached the leftmost node (Head of our DLL)
            head = root;
        } else {
            // Establish the bidirectional link between prev and current node
            root->left = prev;
            prev->right = root;
        }
        
        // Move the prev pointer forward to the current node
        prev = root;

        // Step 3: Recurse into the Right Subtree
        convertToDLL(root->right, prev, head);
    }

    Node* bToDLL(Node* root) {
        if (root == nullptr) return nullptr;

        Node* prev = nullptr;
        Node* head = nullptr;

        // Start the inorder conversion
        convertToDLL(root, prev, head);

        return head;
    }
};