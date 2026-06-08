#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};


class Solution {
  public:
  
    // Helper function for serialization (Preorder)
    void helpSerialize(Node *root, vector<int>& res) {
        if (root == NULL) {
            res.push_back(-1); // Using -1 as a distinct NULL marker
            return;
        }
        
        res.push_back(root->data);
        helpSerialize(root->left, res);
        helpSerialize(root->right, res);
    }
    
    vector<int> serialize(Node *root) {
        //  code here
        vector<int>res;
        helpSerialize(root,res);
        return res;
    }
    
    // Helper function for deserialization
    Node* helpDeSerialize(vector<int> &arr, int &i) {
        
        // Base case: If we have consumed all elements or hit the NULL marker
        if (i >= arr.size() || arr[i] == -1) {
            i++; // Consume the NULL marker
            return NULL;
        }
        
        // Create the current root node
        Node* root = new Node(arr[i]);
        i++; // Move pointer to the next element for the left subtree
        
        // Recursively construct the left and right subtrees
        root->left = helpDeSerialize(arr, i);
        root->right = helpDeSerialize(arr, i);
        
        return root;
    }

    Node *deSerialize(vector<int> &arr) {
        
        int i = 0; // Initialize global index tracker
        return helpDeSerialize(arr, i);
    }
};