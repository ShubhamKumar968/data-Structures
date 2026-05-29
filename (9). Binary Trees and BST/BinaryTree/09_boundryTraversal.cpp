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
        left = right = nullptr;
    }
};

class Solution {
  public:
    
    void traverseLeft(Node *root, vector<int>& res) {
        if (root == NULL) return;
        
        // Leaf is not included
        if (root->left == NULL && root->right == NULL) return;
        
        res.push_back(root->data); // Preorder style
        
        if (root->left) {
            traverseLeft(root->left, res);
        } else {
            traverseLeft(root->right, res);
        }
    }
    
    void traverseLeaf(Node *root, vector<int>& res) {
        if (root == NULL) return;
        
        // Leaf is included
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->data);
            return;
        }
        
        // FIX: Traversal must explore BOTH sides independently to find all leaves
        traverseLeaf(root->left, res);
        traverseLeaf(root->right, res);
    }
    
    void traverseRight(Node *root, vector<int>& res) {
        if (root == NULL) return;
        
        // Leaf is not included
        if (root->left == NULL && root->right == NULL) return;
        
        if (root->right) {
            traverseRight(root->right, res);
        } else {
            traverseRight(root->left, res);
        }
        
        res.push_back(root->data); // Postorder style handles bottom-to-top reversal
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (root == NULL) return res;
        
        // Push the root node first
        res.push_back(root->data);
        
        // If the tree only has one node, return immediately to prevent duplicate tracking
        if (root->left == NULL && root->right == NULL) return res;
        
        // 1. Process Left Boundary
        traverseLeft(root->left, res);
        
        // 2. Process All Leaves (starting from root keeps it clean)
        traverseLeaf(root, res);
        
        // 3. Process Right Boundary
        traverseRight(root->right, res);
        
        return res;
    }
};