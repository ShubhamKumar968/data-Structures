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
  
    
    // Keeps track of the node that was flattened right before the current one
    Node* prev = nullptr;

    void solve(Node* root) {
        if (root == nullptr) {
            return;
        }

        // 1. Traverse Right first, then Left (Reverse Pre-order)
        solve(root->right);
        solve(root->left);

        // 2. Attach the flattened chain to the current node's right pointer
        root->right = prev;
        
        // 3. Set the left pointer to NULL as per requirements
        root->left = nullptr;

        // 4. Update the prev tracker to the current node
        prev = root;
    }

    void flatten(Node* root) {
        prev = nullptr; // Reset the tracker for fresh test case executions
        solve(root);
    }
    
};